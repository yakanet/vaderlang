#include "bootstrap.split.h"

static void* vader_diagnostics_comptime_info(uint8_t l0);
static void* vader_diagnostics_dedup_diagnostics(void* l0);
static vader_string_t vader_diagnostics_diag_key(void* l0);
static void vader_diagnostics_format_diagnostic(void* l0, void* l1, bool l2, vader_string_t l3);
static void* vader_diagnostics_lexer_info(uint8_t l0);
static void* vader_diagnostics_lower_info(uint8_t l0);
static void* vader_diagnostics_new_diagnostic(int32_t l0, void* l1, void* l2, vader_string_t l3);
static void* vader_diagnostics_parser_info(uint8_t l0);
static vader_string_t vader_diagnostics_relative_to(vader_string_t l0, vader_string_t l1);
static vader_string_t vader_diagnostics_render_diagnostics(void* l0, bool l1, bool l2);
static void* vader_diagnostics_resolver_info(uint8_t l0);
static void* vader_diagnostics_typecheck_info(uint8_t l0);
static void* vader_diagnostics_warning_info(uint8_t l0);

void* vader_diagnostics_comptime_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_comptime_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(0), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_comptime_info(uint8_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 691u);
        _a0_obj->f_id = 544u;
        _a0_obj->f_message = 1469u;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a1_obj, 691u);
        _a1_obj->f_id = 545u;
        _a1_obj->f_message = 1331u;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a2_obj, 691u);
        _a2_obj->f_id = 546u;
        _a2_obj->f_message = 1554u;
        t0 = (void*) _a2_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a3_obj, 691u);
        _a3_obj->f_id = 547u;
        _a3_obj->f_message = 1327u;
        t0 = (void*) _a3_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(4)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a4_obj, 691u);
        _a4_obj->f_id = 548u;
        _a4_obj->f_message = 1328u;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(5)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a5_obj, 691u);
        _a5_obj->f_id = 549u;
        _a5_obj->f_message = 525u;
        t0 = (void*) _a5_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(6)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a6_obj, 691u);
        _a6_obj->f_id = 550u;
        _a6_obj->f_message = 1335u;
        t0 = (void*) _a6_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(7)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a7_obj, 691u);
        _a7_obj->f_id = 551u;
        _a7_obj->f_message = 579u;
        t0 = (void*) _a7_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(8)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a8_obj, 691u);
        _a8_obj->f_id = 552u;
        _a8_obj->f_message = 1329u;
        t0 = (void*) _a8_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(9)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a9_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a9_obj, 691u);
        _a9_obj->f_id = 553u;
        _a9_obj->f_message = 1333u;
        t0 = (void*) _a9_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(10)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a10_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a10_obj, 691u);
        _a10_obj->f_id = 554u;
        _a10_obj->f_message = 1332u;
        t0 = (void*) _a10_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(11)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a11_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a11_obj, 691u);
        _a11_obj->f_id = 555u;
        _a11_obj->f_message = 524u;
        t0 = (void*) _a11_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(12)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a12_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a12_obj, 691u);
        _a12_obj->f_id = 556u;
        _a12_obj->f_message = 1377u;
        t0 = (void*) _a12_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(13)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a13_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a13_obj, 691u);
        _a13_obj->f_id = 557u;
        _a13_obj->f_message = 1570u;
        t0 = (void*) _a13_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a14_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a14_obj, 691u);
        _a14_obj->f_id = 558u;
        _a14_obj->f_message = 1324u;
        t0 = (void*) _a14_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(15)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a15_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a15_obj, 691u);
        _a15_obj->f_id = 559u;
        _a15_obj->f_message = 1654u;
        t0 = (void*) _a15_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_diagnostics$comptime_info");
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_dedup_diagnostics(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4, l5;
    vader_string_t l7;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 162u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 160u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 164u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 356u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__string_t* _a4_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 376u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(50u, 0u, 13u, 692u);
    l2 = (void*) _a5_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_24: {
            if ((l5 < l4)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l5 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
                l7 = vader_diagnostics_diag_key(l6);
                t1 = std_collections_add__string(l1, l7);
                if (t1) {
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
                } else {
                }
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_24;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_diagnostics_diag_key(void* l0) {
    vader_string_t l1, l2, l3;
    size_t l4, l5;
    void* l6 = NULL;
    int64_t l7;
    uint64_t l8;
    int64_t t0;
    size_t t1;
    vader_string_t t2;
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_code)->f_id;
    l2 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_primary)->f_start)->f_file;
    l3 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_detail;
    l4 = vader_import_0(l1);
    l5 = vader_import_0(l2);
    t0 = (l4 + l5);
    l4 = (size_t) (int64_t) t0;
    l5 = vader_import_0(l3);
    t0 = (l4 + l5);
    l4 = (size_t) (int64_t) t0;
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(65) + l4));
    l4 = (size_t) (int64_t) INT64_C(0);
    l7 = ((int64_t) (int32_t) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_severity);
    l4 = std_core_write_int(l6, l4, l7);
    l4 = std_core_write_string_at(l6, l4, 2411u);
    l4 = std_core_write_string_at(l6, l4, l1);
    l4 = std_core_write_string_at(l6, l4, 2411u);
    l4 = std_core_write_string_at(l6, l4, l2);
    l4 = std_core_write_string_at(l6, l4, 2411u);
    t1 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_primary)->f_start)->f_offset;
    t0 = ((int64_t) (size_t) t1);
    l8 = (uint64_t) (int64_t) t0;
    l4 = std_core_write_unsigned(l6, l4, l8);
    l4 = std_core_write_string_at(l6, l4, 2411u);
    t1 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_primary)->f_end)->f_offset;
    t0 = ((int64_t) (size_t) t1);
    l8 = (uint64_t) (int64_t) t0;
    l4 = std_core_write_unsigned(l6, l4, l8);
    l4 = std_core_write_string_at(l6, l4, 2411u);
    l4 = std_core_write_string_at(l6, l4, l3);
    t2 = std_core_finish_buffer(l6, l4);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool vader_diagnostics_diag_less(void* l0, void* l1) {
    size_t l2, l3;
    vader_string_t l4, l5;
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_primary)->f_start)->f_offset;
    l3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start)->f_offset;
    if ((l2 < l3)) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l2 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_primary)->f_start)->f_offset;
    l3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start)->f_offset;
    if ((l2 > l3)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l4 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_code)->f_id;
    l5 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
    t0 = std_string_compare_ascending(l4, l5);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool vader_diagnostics_diag_less_with_file(void* l0, void* l1) {
    vader_string_t l2, l3;
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_primary)->f_start)->f_file;
    l3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start)->f_file;
    if (l2 != l3) {
        t0 = std_string_compare_ascending(l2, l3);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_diagnostics_diag_less(l0, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_diagnostics_dump_diagnostics_with_file(void* l0) {
    vader_string_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_diagnostics_render_diagnostics(l0, true, true);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_diagnostics_format_diagnostic(void* l0, void* l1, bool l2, vader_string_t l3) {
    vader_string_t l4, l6, l14, l15, l16, l17, l18, l23, l25, l30, l32, l33, l34, l35, l36, l37, l38;
    int32_t l5, l7, l8, l9, l10, l12;
    bool l11;
    void* l13 = NULL;
    void* l21 = NULL;
    void* l27 = NULL;
    size_t l19, l20, l22, l28;
    int64_t l24, l26, l29, l31;
    vader_string_t t0;
    bool t1;
    int32_t t2;
    void** gc_raw_roots[5] = { &l0, &l1, &l13, &l21, &l27 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_severity;
    if (l5 == INT32_C(0)) {
        l4 = 1427u;
        if (l2) {
            l7 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_severity;
            l8 = INT32_C(0);
            if (l7 == l8) {
                l6 = std_tty_red(l4);
                l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
                l14 = 0u;
                t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                t1 = std_string_is_empty(t0);
                if (!(t1)) {
                    l15 = 460u;
                    l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                    l14 = concat_2(l15, l16);
                } else {
                }
                if (l2) {
                    t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
                    l18 = vader_diagnostics_relative_to(t0, l3);
                    l19 = (size_t) (int64_t) INT64_C(42);
                    l20 = vader_import_0(l18);
                    l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
                    l22 = (size_t) (int64_t) INT64_C(0);
                    l22 = std_core_write_string_at(l21, l22, l18);
                    l23 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l23);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l24 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l24);
                    l25 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l25);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l26 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l26);
                    l17 = std_core_finish_buffer(l21, l22);
                } else {
                    l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
                    l28 = (size_t) (int64_t) INT64_C(0);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l29 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l29);
                    l30 = 459u;
                    l28 = std_core_write_string_at(l27, l28, l30);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l31 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l31);
                    l17 = std_core_finish_buffer(l27, l28);
                }
                l32 = 829u;
                l33 = 833u;
                l34 = 829u;
                l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
                l36 = 833u;
                l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
                l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
                std_string_builder_append(l0, l38);
                { vader_gc_top = gc_frame.prev; return; }
            }
            l9 = INT32_C(1);
            if (l7 == l9) {
                l6 = std_tty_yellow(l4);
                l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
                l14 = 0u;
                t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                t1 = std_string_is_empty(t0);
                if (!(t1)) {
                    l15 = 460u;
                    l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                    l14 = concat_2(l15, l16);
                } else {
                }
                if (l2) {
                    t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
                    l18 = vader_diagnostics_relative_to(t0, l3);
                    l19 = (size_t) (int64_t) INT64_C(42);
                    l20 = vader_import_0(l18);
                    l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
                    l22 = (size_t) (int64_t) INT64_C(0);
                    l22 = std_core_write_string_at(l21, l22, l18);
                    l23 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l23);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l24 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l24);
                    l25 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l25);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l26 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l26);
                    l17 = std_core_finish_buffer(l21, l22);
                } else {
                    l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
                    l28 = (size_t) (int64_t) INT64_C(0);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l29 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l29);
                    l30 = 459u;
                    l28 = std_core_write_string_at(l27, l28, l30);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l31 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l31);
                    l17 = std_core_finish_buffer(l27, l28);
                }
                l32 = 829u;
                l33 = 833u;
                l34 = 829u;
                l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
                l36 = 833u;
                l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
                l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
                std_string_builder_append(l0, l38);
                { vader_gc_top = gc_frame.prev; return; }
            }
            l10 = INT32_C(2);
            if (l7 == l10) {
                l11 = true;
            } else {
                l12 = INT32_C(3);
                l11 = l7 == l12;
            }
            if (l11) {
                l6 = l4;
                l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
                l14 = 0u;
                t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                t1 = std_string_is_empty(t0);
                if (!(t1)) {
                    l15 = 460u;
                    l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                    l14 = concat_2(l15, l16);
                } else {
                }
                if (l2) {
                    t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
                    l18 = vader_diagnostics_relative_to(t0, l3);
                    l19 = (size_t) (int64_t) INT64_C(42);
                    l20 = vader_import_0(l18);
                    l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
                    l22 = (size_t) (int64_t) INT64_C(0);
                    l22 = std_core_write_string_at(l21, l22, l18);
                    l23 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l23);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l24 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l24);
                    l25 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l25);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l26 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l26);
                    l17 = std_core_finish_buffer(l21, l22);
                } else {
                    l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
                    l28 = (size_t) (int64_t) INT64_C(0);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l29 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l29);
                    l30 = 459u;
                    l28 = std_core_write_string_at(l27, l28, l30);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l31 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l31);
                    l17 = std_core_finish_buffer(l27, l28);
                }
                l32 = 829u;
                l33 = 833u;
                l34 = 829u;
                l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
                l36 = 833u;
                l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
                l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
                std_string_builder_append(l0, l38);
                { vader_gc_top = gc_frame.prev; return; }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        l6 = l4;
        l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
        l14 = 0u;
        t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
        t1 = std_string_is_empty(t0);
        if (!(t1)) {
            l15 = 460u;
            l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
            l14 = concat_2(l15, l16);
        } else {
        }
        if (l2) {
            t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
            l18 = vader_diagnostics_relative_to(t0, l3);
            l19 = (size_t) (int64_t) INT64_C(42);
            l20 = vader_import_0(l18);
            l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
            l22 = (size_t) (int64_t) INT64_C(0);
            l22 = std_core_write_string_at(l21, l22, l18);
            l23 = 459u;
            l22 = std_core_write_string_at(l21, l22, l23);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
            l24 = ((int64_t) (int32_t) t2);
            l22 = std_core_write_int(l21, l22, l24);
            l25 = 459u;
            l22 = std_core_write_string_at(l21, l22, l25);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
            l26 = ((int64_t) (int32_t) t2);
            l22 = std_core_write_int(l21, l22, l26);
            l17 = std_core_finish_buffer(l21, l22);
        } else {
            l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
            l28 = (size_t) (int64_t) INT64_C(0);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
            l29 = ((int64_t) (int32_t) t2);
            l28 = std_core_write_int(l27, l28, l29);
            l30 = 459u;
            l28 = std_core_write_string_at(l27, l28, l30);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
            l31 = ((int64_t) (int32_t) t2);
            l28 = std_core_write_int(l27, l28, l31);
            l17 = std_core_finish_buffer(l27, l28);
        }
        l32 = 829u;
        l33 = 833u;
        l34 = 829u;
        l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
        l36 = 833u;
        l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
        l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
        std_string_builder_append(l0, l38);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l5 == INT32_C(1)) {
        l4 = 2379u;
        if (l2) {
            l7 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_severity;
            l8 = INT32_C(0);
            if (l7 == l8) {
                l6 = std_tty_red(l4);
                l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
                l14 = 0u;
                t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                t1 = std_string_is_empty(t0);
                if (!(t1)) {
                    l15 = 460u;
                    l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                    l14 = concat_2(l15, l16);
                } else {
                }
                if (l2) {
                    t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
                    l18 = vader_diagnostics_relative_to(t0, l3);
                    l19 = (size_t) (int64_t) INT64_C(42);
                    l20 = vader_import_0(l18);
                    l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
                    l22 = (size_t) (int64_t) INT64_C(0);
                    l22 = std_core_write_string_at(l21, l22, l18);
                    l23 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l23);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l24 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l24);
                    l25 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l25);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l26 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l26);
                    l17 = std_core_finish_buffer(l21, l22);
                } else {
                    l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
                    l28 = (size_t) (int64_t) INT64_C(0);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l29 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l29);
                    l30 = 459u;
                    l28 = std_core_write_string_at(l27, l28, l30);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l31 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l31);
                    l17 = std_core_finish_buffer(l27, l28);
                }
                l32 = 829u;
                l33 = 833u;
                l34 = 829u;
                l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
                l36 = 833u;
                l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
                l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
                std_string_builder_append(l0, l38);
                { vader_gc_top = gc_frame.prev; return; }
            }
            l9 = INT32_C(1);
            if (l7 == l9) {
                l6 = std_tty_yellow(l4);
                l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
                l14 = 0u;
                t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                t1 = std_string_is_empty(t0);
                if (!(t1)) {
                    l15 = 460u;
                    l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                    l14 = concat_2(l15, l16);
                } else {
                }
                if (l2) {
                    t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
                    l18 = vader_diagnostics_relative_to(t0, l3);
                    l19 = (size_t) (int64_t) INT64_C(42);
                    l20 = vader_import_0(l18);
                    l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
                    l22 = (size_t) (int64_t) INT64_C(0);
                    l22 = std_core_write_string_at(l21, l22, l18);
                    l23 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l23);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l24 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l24);
                    l25 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l25);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l26 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l26);
                    l17 = std_core_finish_buffer(l21, l22);
                } else {
                    l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
                    l28 = (size_t) (int64_t) INT64_C(0);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l29 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l29);
                    l30 = 459u;
                    l28 = std_core_write_string_at(l27, l28, l30);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l31 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l31);
                    l17 = std_core_finish_buffer(l27, l28);
                }
                l32 = 829u;
                l33 = 833u;
                l34 = 829u;
                l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
                l36 = 833u;
                l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
                l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
                std_string_builder_append(l0, l38);
                { vader_gc_top = gc_frame.prev; return; }
            }
            l10 = INT32_C(2);
            if (l7 == l10) {
                l11 = true;
            } else {
                l12 = INT32_C(3);
                l11 = l7 == l12;
            }
            if (l11) {
                l6 = l4;
                l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
                l14 = 0u;
                t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                t1 = std_string_is_empty(t0);
                if (!(t1)) {
                    l15 = 460u;
                    l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                    l14 = concat_2(l15, l16);
                } else {
                }
                if (l2) {
                    t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
                    l18 = vader_diagnostics_relative_to(t0, l3);
                    l19 = (size_t) (int64_t) INT64_C(42);
                    l20 = vader_import_0(l18);
                    l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
                    l22 = (size_t) (int64_t) INT64_C(0);
                    l22 = std_core_write_string_at(l21, l22, l18);
                    l23 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l23);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l24 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l24);
                    l25 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l25);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l26 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l26);
                    l17 = std_core_finish_buffer(l21, l22);
                } else {
                    l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
                    l28 = (size_t) (int64_t) INT64_C(0);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l29 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l29);
                    l30 = 459u;
                    l28 = std_core_write_string_at(l27, l28, l30);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l31 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l31);
                    l17 = std_core_finish_buffer(l27, l28);
                }
                l32 = 829u;
                l33 = 833u;
                l34 = 829u;
                l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
                l36 = 833u;
                l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
                l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
                std_string_builder_append(l0, l38);
                { vader_gc_top = gc_frame.prev; return; }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        l6 = l4;
        l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
        l14 = 0u;
        t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
        t1 = std_string_is_empty(t0);
        if (!(t1)) {
            l15 = 460u;
            l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
            l14 = concat_2(l15, l16);
        } else {
        }
        if (l2) {
            t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
            l18 = vader_diagnostics_relative_to(t0, l3);
            l19 = (size_t) (int64_t) INT64_C(42);
            l20 = vader_import_0(l18);
            l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
            l22 = (size_t) (int64_t) INT64_C(0);
            l22 = std_core_write_string_at(l21, l22, l18);
            l23 = 459u;
            l22 = std_core_write_string_at(l21, l22, l23);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
            l24 = ((int64_t) (int32_t) t2);
            l22 = std_core_write_int(l21, l22, l24);
            l25 = 459u;
            l22 = std_core_write_string_at(l21, l22, l25);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
            l26 = ((int64_t) (int32_t) t2);
            l22 = std_core_write_int(l21, l22, l26);
            l17 = std_core_finish_buffer(l21, l22);
        } else {
            l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
            l28 = (size_t) (int64_t) INT64_C(0);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
            l29 = ((int64_t) (int32_t) t2);
            l28 = std_core_write_int(l27, l28, l29);
            l30 = 459u;
            l28 = std_core_write_string_at(l27, l28, l30);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
            l31 = ((int64_t) (int32_t) t2);
            l28 = std_core_write_int(l27, l28, l31);
            l17 = std_core_finish_buffer(l27, l28);
        }
        l32 = 829u;
        l33 = 833u;
        l34 = 829u;
        l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
        l36 = 833u;
        l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
        l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
        std_string_builder_append(l0, l38);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l5 == INT32_C(2)) {
        l4 = 1661u;
        if (l2) {
            l7 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_severity;
            l8 = INT32_C(0);
            if (l7 == l8) {
                l6 = std_tty_red(l4);
                l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
                l14 = 0u;
                t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                t1 = std_string_is_empty(t0);
                if (!(t1)) {
                    l15 = 460u;
                    l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                    l14 = concat_2(l15, l16);
                } else {
                }
                if (l2) {
                    t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
                    l18 = vader_diagnostics_relative_to(t0, l3);
                    l19 = (size_t) (int64_t) INT64_C(42);
                    l20 = vader_import_0(l18);
                    l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
                    l22 = (size_t) (int64_t) INT64_C(0);
                    l22 = std_core_write_string_at(l21, l22, l18);
                    l23 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l23);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l24 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l24);
                    l25 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l25);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l26 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l26);
                    l17 = std_core_finish_buffer(l21, l22);
                } else {
                    l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
                    l28 = (size_t) (int64_t) INT64_C(0);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l29 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l29);
                    l30 = 459u;
                    l28 = std_core_write_string_at(l27, l28, l30);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l31 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l31);
                    l17 = std_core_finish_buffer(l27, l28);
                }
                l32 = 829u;
                l33 = 833u;
                l34 = 829u;
                l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
                l36 = 833u;
                l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
                l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
                std_string_builder_append(l0, l38);
                { vader_gc_top = gc_frame.prev; return; }
            }
            l9 = INT32_C(1);
            if (l7 == l9) {
                l6 = std_tty_yellow(l4);
                l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
                l14 = 0u;
                t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                t1 = std_string_is_empty(t0);
                if (!(t1)) {
                    l15 = 460u;
                    l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                    l14 = concat_2(l15, l16);
                } else {
                }
                if (l2) {
                    t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
                    l18 = vader_diagnostics_relative_to(t0, l3);
                    l19 = (size_t) (int64_t) INT64_C(42);
                    l20 = vader_import_0(l18);
                    l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
                    l22 = (size_t) (int64_t) INT64_C(0);
                    l22 = std_core_write_string_at(l21, l22, l18);
                    l23 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l23);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l24 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l24);
                    l25 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l25);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l26 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l26);
                    l17 = std_core_finish_buffer(l21, l22);
                } else {
                    l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
                    l28 = (size_t) (int64_t) INT64_C(0);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l29 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l29);
                    l30 = 459u;
                    l28 = std_core_write_string_at(l27, l28, l30);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l31 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l31);
                    l17 = std_core_finish_buffer(l27, l28);
                }
                l32 = 829u;
                l33 = 833u;
                l34 = 829u;
                l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
                l36 = 833u;
                l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
                l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
                std_string_builder_append(l0, l38);
                { vader_gc_top = gc_frame.prev; return; }
            }
            l10 = INT32_C(2);
            if (l7 == l10) {
                l11 = true;
            } else {
                l12 = INT32_C(3);
                l11 = l7 == l12;
            }
            if (l11) {
                l6 = l4;
                l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
                l14 = 0u;
                t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                t1 = std_string_is_empty(t0);
                if (!(t1)) {
                    l15 = 460u;
                    l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                    l14 = concat_2(l15, l16);
                } else {
                }
                if (l2) {
                    t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
                    l18 = vader_diagnostics_relative_to(t0, l3);
                    l19 = (size_t) (int64_t) INT64_C(42);
                    l20 = vader_import_0(l18);
                    l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
                    l22 = (size_t) (int64_t) INT64_C(0);
                    l22 = std_core_write_string_at(l21, l22, l18);
                    l23 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l23);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l24 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l24);
                    l25 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l25);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l26 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l26);
                    l17 = std_core_finish_buffer(l21, l22);
                } else {
                    l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
                    l28 = (size_t) (int64_t) INT64_C(0);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l29 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l29);
                    l30 = 459u;
                    l28 = std_core_write_string_at(l27, l28, l30);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l31 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l31);
                    l17 = std_core_finish_buffer(l27, l28);
                }
                l32 = 829u;
                l33 = 833u;
                l34 = 829u;
                l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
                l36 = 833u;
                l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
                l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
                std_string_builder_append(l0, l38);
                { vader_gc_top = gc_frame.prev; return; }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        l6 = l4;
        l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
        l14 = 0u;
        t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
        t1 = std_string_is_empty(t0);
        if (!(t1)) {
            l15 = 460u;
            l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
            l14 = concat_2(l15, l16);
        } else {
        }
        if (l2) {
            t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
            l18 = vader_diagnostics_relative_to(t0, l3);
            l19 = (size_t) (int64_t) INT64_C(42);
            l20 = vader_import_0(l18);
            l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
            l22 = (size_t) (int64_t) INT64_C(0);
            l22 = std_core_write_string_at(l21, l22, l18);
            l23 = 459u;
            l22 = std_core_write_string_at(l21, l22, l23);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
            l24 = ((int64_t) (int32_t) t2);
            l22 = std_core_write_int(l21, l22, l24);
            l25 = 459u;
            l22 = std_core_write_string_at(l21, l22, l25);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
            l26 = ((int64_t) (int32_t) t2);
            l22 = std_core_write_int(l21, l22, l26);
            l17 = std_core_finish_buffer(l21, l22);
        } else {
            l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
            l28 = (size_t) (int64_t) INT64_C(0);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
            l29 = ((int64_t) (int32_t) t2);
            l28 = std_core_write_int(l27, l28, l29);
            l30 = 459u;
            l28 = std_core_write_string_at(l27, l28, l30);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
            l31 = ((int64_t) (int32_t) t2);
            l28 = std_core_write_int(l27, l28, l31);
            l17 = std_core_finish_buffer(l27, l28);
        }
        l32 = 829u;
        l33 = 833u;
        l34 = 829u;
        l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
        l36 = 833u;
        l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
        l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
        std_string_builder_append(l0, l38);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l5 == INT32_C(3)) {
        l4 = 1581u;
        if (l2) {
            l7 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_severity;
            l8 = INT32_C(0);
            if (l7 == l8) {
                l6 = std_tty_red(l4);
                l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
                l14 = 0u;
                t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                t1 = std_string_is_empty(t0);
                if (!(t1)) {
                    l15 = 460u;
                    l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                    l14 = concat_2(l15, l16);
                } else {
                }
                if (l2) {
                    t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
                    l18 = vader_diagnostics_relative_to(t0, l3);
                    l19 = (size_t) (int64_t) INT64_C(42);
                    l20 = vader_import_0(l18);
                    l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
                    l22 = (size_t) (int64_t) INT64_C(0);
                    l22 = std_core_write_string_at(l21, l22, l18);
                    l23 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l23);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l24 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l24);
                    l25 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l25);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l26 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l26);
                    l17 = std_core_finish_buffer(l21, l22);
                } else {
                    l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
                    l28 = (size_t) (int64_t) INT64_C(0);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l29 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l29);
                    l30 = 459u;
                    l28 = std_core_write_string_at(l27, l28, l30);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l31 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l31);
                    l17 = std_core_finish_buffer(l27, l28);
                }
                l32 = 829u;
                l33 = 833u;
                l34 = 829u;
                l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
                l36 = 833u;
                l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
                l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
                std_string_builder_append(l0, l38);
                { vader_gc_top = gc_frame.prev; return; }
            }
            l9 = INT32_C(1);
            if (l7 == l9) {
                l6 = std_tty_yellow(l4);
                l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
                l14 = 0u;
                t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                t1 = std_string_is_empty(t0);
                if (!(t1)) {
                    l15 = 460u;
                    l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                    l14 = concat_2(l15, l16);
                } else {
                }
                if (l2) {
                    t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
                    l18 = vader_diagnostics_relative_to(t0, l3);
                    l19 = (size_t) (int64_t) INT64_C(42);
                    l20 = vader_import_0(l18);
                    l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
                    l22 = (size_t) (int64_t) INT64_C(0);
                    l22 = std_core_write_string_at(l21, l22, l18);
                    l23 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l23);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l24 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l24);
                    l25 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l25);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l26 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l26);
                    l17 = std_core_finish_buffer(l21, l22);
                } else {
                    l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
                    l28 = (size_t) (int64_t) INT64_C(0);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l29 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l29);
                    l30 = 459u;
                    l28 = std_core_write_string_at(l27, l28, l30);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l31 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l31);
                    l17 = std_core_finish_buffer(l27, l28);
                }
                l32 = 829u;
                l33 = 833u;
                l34 = 829u;
                l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
                l36 = 833u;
                l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
                l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
                std_string_builder_append(l0, l38);
                { vader_gc_top = gc_frame.prev; return; }
            }
            l10 = INT32_C(2);
            if (l7 == l10) {
                l11 = true;
            } else {
                l12 = INT32_C(3);
                l11 = l7 == l12;
            }
            if (l11) {
                l6 = l4;
                l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
                l14 = 0u;
                t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                t1 = std_string_is_empty(t0);
                if (!(t1)) {
                    l15 = 460u;
                    l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
                    l14 = concat_2(l15, l16);
                } else {
                }
                if (l2) {
                    t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
                    l18 = vader_diagnostics_relative_to(t0, l3);
                    l19 = (size_t) (int64_t) INT64_C(42);
                    l20 = vader_import_0(l18);
                    l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
                    l22 = (size_t) (int64_t) INT64_C(0);
                    l22 = std_core_write_string_at(l21, l22, l18);
                    l23 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l23);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l24 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l24);
                    l25 = 459u;
                    l22 = std_core_write_string_at(l21, l22, l25);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l26 = ((int64_t) (int32_t) t2);
                    l22 = std_core_write_int(l21, l22, l26);
                    l17 = std_core_finish_buffer(l21, l22);
                } else {
                    l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
                    l28 = (size_t) (int64_t) INT64_C(0);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
                    l29 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l29);
                    l30 = 459u;
                    l28 = std_core_write_string_at(l27, l28, l30);
                    t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
                    l31 = ((int64_t) (int32_t) t2);
                    l28 = std_core_write_int(l27, l28, l31);
                    l17 = std_core_finish_buffer(l27, l28);
                }
                l32 = 829u;
                l33 = 833u;
                l34 = 829u;
                l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
                l36 = 833u;
                l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
                l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
                std_string_builder_append(l0, l38);
                { vader_gc_top = gc_frame.prev; return; }
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
        l6 = l4;
        l13 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
        l14 = 0u;
        t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
        t1 = std_string_is_empty(t0);
        if (!(t1)) {
            l15 = 460u;
            l16 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
            l14 = concat_2(l15, l16);
        } else {
        }
        if (l2) {
            t0 = ((vader_struct_toolchain_span_Position_t*) l13)->f_file;
            l18 = vader_diagnostics_relative_to(t0, l3);
            l19 = (size_t) (int64_t) INT64_C(42);
            l20 = vader_import_0(l18);
            l21 = std_core_new_byte_buffer((size_t) (int64_t) (l19 + l20));
            l22 = (size_t) (int64_t) INT64_C(0);
            l22 = std_core_write_string_at(l21, l22, l18);
            l23 = 459u;
            l22 = std_core_write_string_at(l21, l22, l23);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
            l24 = ((int64_t) (int32_t) t2);
            l22 = std_core_write_int(l21, l22, l24);
            l25 = 459u;
            l22 = std_core_write_string_at(l21, l22, l25);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
            l26 = ((int64_t) (int32_t) t2);
            l22 = std_core_write_int(l21, l22, l26);
            l17 = std_core_finish_buffer(l21, l22);
        } else {
            l27 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
            l28 = (size_t) (int64_t) INT64_C(0);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_line;
            l29 = ((int64_t) (int32_t) t2);
            l28 = std_core_write_int(l27, l28, l29);
            l30 = 459u;
            l28 = std_core_write_string_at(l27, l28, l30);
            t2 = ((vader_struct_toolchain_span_Position_t*) l13)->f_column;
            l31 = ((int64_t) (int32_t) t2);
            l28 = std_core_write_int(l27, l28, l31);
            l17 = std_core_finish_buffer(l27, l28);
        }
        l32 = 829u;
        l33 = 833u;
        l34 = 829u;
        l35 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
        l36 = 833u;
        l37 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
        l38 = concat_9(l32, l17, l33, l6, l34, l35, l36, l37, l14);
        std_string_builder_append(l0, l38);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void* vader_diagnostics_lexer_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_lexer_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(0), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_lexer_info(uint8_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 691u);
        _a0_obj->f_id = 613u;
        _a0_obj->f_message = 2244u;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a1_obj, 691u);
        _a1_obj->f_id = 614u;
        _a1_obj->f_message = 2270u;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a2_obj, 691u);
        _a2_obj->f_id = 615u;
        _a2_obj->f_message = 2265u;
        t0 = (void*) _a2_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a3_obj, 691u);
        _a3_obj->f_id = 616u;
        _a3_obj->f_message = 1695u;
        t0 = (void*) _a3_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(4)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a4_obj, 691u);
        _a4_obj->f_id = 617u;
        _a4_obj->f_message = 1693u;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(5)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a5_obj, 691u);
        _a5_obj->f_id = 618u;
        _a5_obj->f_message = 1779u;
        t0 = (void*) _a5_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(6)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a6_obj, 691u);
        _a6_obj->f_id = 619u;
        _a6_obj->f_message = 2071u;
        t0 = (void*) _a6_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(7)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a7_obj, 691u);
        _a7_obj->f_id = 620u;
        _a7_obj->f_message = 1939u;
        t0 = (void*) _a7_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(8)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a8_obj, 691u);
        _a8_obj->f_id = 621u;
        _a8_obj->f_message = 1688u;
        t0 = (void*) _a8_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(9)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a9_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a9_obj, 691u);
        _a9_obj->f_id = 622u;
        _a9_obj->f_message = 1680u;
        t0 = (void*) _a9_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(10)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a10_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a10_obj, 691u);
        _a10_obj->f_id = 623u;
        _a10_obj->f_message = 1676u;
        t0 = (void*) _a10_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_diagnostics$lexer_info");
    vader_gc_top = gc_frame.prev;
}

void* vader_diagnostics_lower_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_lower_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(0), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_lower_info(uint8_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 691u);
        _a0_obj->f_id = 627u;
        _a0_obj->f_message = 1544u;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a1_obj, 691u);
        _a1_obj->f_id = 628u;
        _a1_obj->f_message = 1738u;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a2_obj, 691u);
        _a2_obj->f_id = 629u;
        _a2_obj->f_message = 1781u;
        t0 = (void*) _a2_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a3_obj, 691u);
        _a3_obj->f_id = 630u;
        _a3_obj->f_message = 1062u;
        t0 = (void*) _a3_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(4)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a4_obj, 691u);
        _a4_obj->f_id = 631u;
        _a4_obj->f_message = 1684u;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(5)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a5_obj, 691u);
        _a5_obj->f_id = 632u;
        _a5_obj->f_message = 1794u;
        t0 = (void*) _a5_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(6)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a6_obj, 691u);
        _a6_obj->f_id = 633u;
        _a6_obj->f_message = 1071u;
        t0 = (void*) _a6_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(7)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a7_obj, 691u);
        _a7_obj->f_id = 634u;
        _a7_obj->f_message = 1047u;
        t0 = (void*) _a7_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_diagnostics$lower_info");
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_new_diagnostic(int32_t l0, void* l1, void* l2, vader_string_t l3) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_diagnostics_Diagnostic_t* _a0_obj = (vader_struct_vader_diagnostics_Diagnostic_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_Diagnostic_t));
    vader_obj_header_init(_a0_obj, 692u);
    _a0_obj->f_severity = l0;
    _a0_obj->f_code = l1;
    _a0_obj->f_detail = l3;
    _a0_obj->f_primary = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_diagnostics_parser_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_parser_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(0), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_parser_info(uint8_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 691u);
        _a0_obj->f_id = 648u;
        _a0_obj->f_message = 2246u;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a1_obj, 691u);
        _a1_obj->f_id = 649u;
        _a1_obj->f_message = 1457u;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a2_obj, 691u);
        _a2_obj->f_id = 650u;
        _a2_obj->f_message = 1448u;
        t0 = (void*) _a2_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a3_obj, 691u);
        _a3_obj->f_id = 651u;
        _a3_obj->f_message = 1445u;
        t0 = (void*) _a3_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(4)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a4_obj, 691u);
        _a4_obj->f_id = 652u;
        _a4_obj->f_message = 1447u;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(5)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a5_obj, 691u);
        _a5_obj->f_id = 653u;
        _a5_obj->f_message = 1442u;
        t0 = (void*) _a5_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(6)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a6_obj, 691u);
        _a6_obj->f_id = 654u;
        _a6_obj->f_message = 1444u;
        t0 = (void*) _a6_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(7)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a7_obj, 691u);
        _a7_obj->f_id = 655u;
        _a7_obj->f_message = 1450u;
        t0 = (void*) _a7_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(8)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a8_obj, 691u);
        _a8_obj->f_id = 656u;
        _a8_obj->f_message = 2138u;
        t0 = (void*) _a8_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(9)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a9_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a9_obj, 691u);
        _a9_obj->f_id = 657u;
        _a9_obj->f_message = 1840u;
        t0 = (void*) _a9_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(10)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a10_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a10_obj, 691u);
        _a10_obj->f_id = 658u;
        _a10_obj->f_message = 2093u;
        t0 = (void*) _a10_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(11)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a11_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a11_obj, 691u);
        _a11_obj->f_id = 659u;
        _a11_obj->f_message = 1805u;
        t0 = (void*) _a11_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(12)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a12_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a12_obj, 691u);
        _a12_obj->f_id = 660u;
        _a12_obj->f_message = 1433u;
        t0 = (void*) _a12_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(13)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a13_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a13_obj, 691u);
        _a13_obj->f_id = 661u;
        _a13_obj->f_message = 2249u;
        t0 = (void*) _a13_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a14_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a14_obj, 691u);
        _a14_obj->f_id = 662u;
        _a14_obj->f_message = 1399u;
        t0 = (void*) _a14_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(15)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a15_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a15_obj, 691u);
        _a15_obj->f_id = 663u;
        _a15_obj->f_message = 1443u;
        t0 = (void*) _a15_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(16)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a16_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a16_obj, 691u);
        _a16_obj->f_id = 664u;
        _a16_obj->f_message = 1806u;
        t0 = (void*) _a16_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(17)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a17_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a17_obj, 691u);
        _a17_obj->f_id = 665u;
        _a17_obj->f_message = 2154u;
        t0 = (void*) _a17_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(18)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a18_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a18_obj, 691u);
        _a18_obj->f_id = 666u;
        _a18_obj->f_message = 1032u;
        t0 = (void*) _a18_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(19)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a19_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a19_obj, 691u);
        _a19_obj->f_id = 667u;
        _a19_obj->f_message = 1473u;
        t0 = (void*) _a19_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(20)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a20_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a20_obj, 691u);
        _a20_obj->f_id = 668u;
        _a20_obj->f_message = 448u;
        t0 = (void*) _a20_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(21)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a21_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a21_obj, 691u);
        _a21_obj->f_id = 669u;
        _a21_obj->f_message = 2148u;
        t0 = (void*) _a21_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(22)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a22_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a22_obj, 691u);
        _a22_obj->f_id = 670u;
        _a22_obj->f_message = 1744u;
        t0 = (void*) _a22_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(23)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a23_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a23_obj, 691u);
        _a23_obj->f_id = 671u;
        _a23_obj->f_message = 1075u;
        t0 = (void*) _a23_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(24)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a24_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a24_obj, 691u);
        _a24_obj->f_id = 672u;
        _a24_obj->f_message = 1697u;
        t0 = (void*) _a24_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(25)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a25_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a25_obj, 691u);
        _a25_obj->f_id = 673u;
        _a25_obj->f_message = 1472u;
        t0 = (void*) _a25_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(26)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a26_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a26_obj, 691u);
        _a26_obj->f_id = 674u;
        _a26_obj->f_message = 1908u;
        t0 = (void*) _a26_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(27)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a27_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a27_obj, 691u);
        _a27_obj->f_id = 675u;
        _a27_obj->f_message = 1005u;
        t0 = (void*) _a27_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_diagnostics$parser_info");
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_diagnostics_relative_to(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2;
    size_t l3, l4;
    bool t0;
    vader_string_t t1;
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_string_is_empty(l1);
    if (t0) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_string_ends_with(l1, 432u);
    if (t0) {
        l2 = l1;
    } else {
        l2 = concat_2(l1, 432u);
    }
    t0 = std_string_starts_with(l0, l2);
    if (!(t0)) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = std_core_len(l2);
    l4 = std_core_len(l0);
    t1 = vader_string_slice_codepoints(l0, l3, l4);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_diagnostics_render_diagnostics(void* l0, bool l1, bool l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    size_t l5, l8, l9;
    vader_string_t l6;
    uint64_t l11;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3;
    void** gc_raw_roots[6] = { &l0, &l3, &l4, &l7, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1) {
        l3 = (void*) &vader_fn_static_235;
        l3 = std_sort_sort__Diagnostic(l0, l3);
    } else {
        l4 = (void*) &vader_fn_static_236;
        l3 = std_sort_sort__Diagnostic(l0, l4);
    }
    l3 = vader_diagnostics_dedup_diagnostics(l3);
    if (l2) {
        t0 = ((vader_array_t*) l3)->length;
        l5 = std_math_min_2(t0, (size_t) (int64_t) INT64_C(100));
    } else {
        l5 = ((vader_array_t*) l3)->length;
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 162u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 385u);
    _a1_obj->f_parts = t1;
    l4 = (void*) _a1_obj;
    std_string_builder_append(l4, 2u);
    if (l1) {
        l6 = vader_import_14();
    } else {
        l6 = 0u;
    }
    vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l3, (size_t) INT64_C(0), (size_t) l5);
    l7 = (void*) _a2_arr;
    l8 = ((vader_array_t*) l7)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_54: {
            if ((l9 < l8)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l7);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l9 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
                std_string_builder_append_char(l4, 10u);
                vader_diagnostics_format_diagnostic(l4, l10, l1, l6);
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
                goto loop_54;
            } else {
            }
        }
    }
    t0 = ((vader_array_t*) l3)->length;
    if ((t0 > l5)) {
        std_string_builder_append_char(l4, 10u);
        l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(47));
        l8 = (size_t) (int64_t) INT64_C(0);
        l8 = std_core_write_string_at(l7, l8, 2420u);
        t0 = ((vader_array_t*) l3)->length;
        t2 = (t0 - l5);
        l11 = (uint64_t) (int64_t) t2;
        l8 = std_core_write_unsigned(l7, l8, l11);
        l8 = std_core_write_string_at(l7, l8, 128u);
        l6 = std_core_finish_buffer(l7, l8);
        std_string_builder_append(l4, l6);
    } else {
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l4);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_diagnostics_resolver_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_resolver_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(0), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_resolver_info(uint8_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 691u);
        _a0_obj->f_id = 677u;
        _a0_obj->f_message = 1819u;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a1_obj, 691u);
        _a1_obj->f_id = 678u;
        _a1_obj->f_message = 1649u;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a2_obj, 691u);
        _a2_obj->f_id = 679u;
        _a2_obj->f_message = 1652u;
        t0 = (void*) _a2_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a3_obj, 691u);
        _a3_obj->f_id = 680u;
        _a3_obj->f_message = 1402u;
        t0 = (void*) _a3_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(4)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a4_obj, 691u);
        _a4_obj->f_id = 681u;
        _a4_obj->f_message = 1647u;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(5)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a5_obj, 691u);
        _a5_obj->f_id = 682u;
        _a5_obj->f_message = 2261u;
        t0 = (void*) _a5_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(6)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a6_obj, 691u);
        _a6_obj->f_id = 683u;
        _a6_obj->f_message = 2262u;
        t0 = (void*) _a6_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(7)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a7_obj, 691u);
        _a7_obj->f_id = 684u;
        _a7_obj->f_message = 2107u;
        t0 = (void*) _a7_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(8)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a8_obj, 691u);
        _a8_obj->f_id = 685u;
        _a8_obj->f_message = 2142u;
        t0 = (void*) _a8_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(9)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a9_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a9_obj, 691u);
        _a9_obj->f_id = 686u;
        _a9_obj->f_message = 1379u;
        t0 = (void*) _a9_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(10)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a10_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a10_obj, 691u);
        _a10_obj->f_id = 687u;
        _a10_obj->f_message = 1400u;
        t0 = (void*) _a10_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(11)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a11_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a11_obj, 691u);
        _a11_obj->f_id = 688u;
        _a11_obj->f_message = 1653u;
        t0 = (void*) _a11_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(12)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a12_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a12_obj, 691u);
        _a12_obj->f_id = 689u;
        _a12_obj->f_message = 1936u;
        t0 = (void*) _a12_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(13)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a13_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a13_obj, 691u);
        _a13_obj->f_id = 690u;
        _a13_obj->f_message = 2277u;
        t0 = (void*) _a13_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a14_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a14_obj, 691u);
        _a14_obj->f_id = 691u;
        _a14_obj->f_message = 1817u;
        t0 = (void*) _a14_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(15)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a15_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a15_obj, 691u);
        _a15_obj->f_id = 692u;
        _a15_obj->f_message = 1942u;
        t0 = (void*) _a15_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(16)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a16_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a16_obj, 691u);
        _a16_obj->f_id = 693u;
        _a16_obj->f_message = 1500u;
        t0 = (void*) _a16_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(17)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a17_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a17_obj, 691u);
        _a17_obj->f_id = 694u;
        _a17_obj->f_message = 1861u;
        t0 = (void*) _a17_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(18)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a18_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a18_obj, 691u);
        _a18_obj->f_id = 695u;
        _a18_obj->f_message = 1085u;
        t0 = (void*) _a18_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(19)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a19_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a19_obj, 691u);
        _a19_obj->f_id = 696u;
        _a19_obj->f_message = 1816u;
        t0 = (void*) _a19_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(20)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a20_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a20_obj, 691u);
        _a20_obj->f_id = 697u;
        _a20_obj->f_message = 1820u;
        t0 = (void*) _a20_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(21)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a21_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a21_obj, 691u);
        _a21_obj->f_id = 698u;
        _a21_obj->f_message = 1531u;
        t0 = (void*) _a21_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(22)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a22_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a22_obj, 691u);
        _a22_obj->f_id = 699u;
        _a22_obj->f_message = 2150u;
        t0 = (void*) _a22_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(23)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a23_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a23_obj, 691u);
        _a23_obj->f_id = 700u;
        _a23_obj->f_message = 1937u;
        t0 = (void*) _a23_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(24)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a24_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a24_obj, 691u);
        _a24_obj->f_id = 701u;
        _a24_obj->f_message = 1904u;
        t0 = (void*) _a24_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(25)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a25_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a25_obj, 691u);
        _a25_obj->f_id = 702u;
        _a25_obj->f_message = 1401u;
        t0 = (void*) _a25_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(26)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a26_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a26_obj, 691u);
        _a26_obj->f_id = 703u;
        _a26_obj->f_message = 1464u;
        t0 = (void*) _a26_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(27)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a27_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a27_obj, 691u);
        _a27_obj->f_id = 704u;
        _a27_obj->f_message = 1458u;
        t0 = (void*) _a27_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(28)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a28_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a28_obj, 691u);
        _a28_obj->f_id = 705u;
        _a28_obj->f_message = 1070u;
        t0 = (void*) _a28_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(29)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a29_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a29_obj, 691u);
        _a29_obj->f_id = 706u;
        _a29_obj->f_message = 1341u;
        t0 = (void*) _a29_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(30)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a30_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a30_obj, 691u);
        _a30_obj->f_id = 707u;
        _a30_obj->f_message = 1824u;
        t0 = (void*) _a30_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(31)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a31_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a31_obj, 691u);
        _a31_obj->f_id = 708u;
        _a31_obj->f_message = 2124u;
        t0 = (void*) _a31_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(32)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a32_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a32_obj, 691u);
        _a32_obj->f_id = 709u;
        _a32_obj->f_message = 1112u;
        t0 = (void*) _a32_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(33)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a33_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a33_obj, 691u);
        _a33_obj->f_id = 710u;
        _a33_obj->f_message = 1114u;
        t0 = (void*) _a33_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(34)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a34_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a34_obj, 691u);
        _a34_obj->f_id = 711u;
        _a34_obj->f_message = 2254u;
        t0 = (void*) _a34_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(35)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a35_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a35_obj, 691u);
        _a35_obj->f_id = 712u;
        _a35_obj->f_message = 1059u;
        t0 = (void*) _a35_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(36)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a36_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a36_obj, 691u);
        _a36_obj->f_id = 713u;
        _a36_obj->f_message = 1057u;
        t0 = (void*) _a36_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(37)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a37_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a37_obj, 691u);
        _a37_obj->f_id = 714u;
        _a37_obj->f_message = 2149u;
        t0 = (void*) _a37_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(38)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a38_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a38_obj, 691u);
        _a38_obj->f_id = 715u;
        _a38_obj->f_message = 1397u;
        t0 = (void*) _a38_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(39)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a39_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a39_obj, 691u);
        _a39_obj->f_id = 716u;
        _a39_obj->f_message = 1058u;
        t0 = (void*) _a39_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(40)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a40_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a40_obj, 691u);
        _a40_obj->f_id = 717u;
        _a40_obj->f_message = 1836u;
        t0 = (void*) _a40_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_diagnostics$resolver_info");
    vader_gc_top = gc_frame.prev;
}

void* vader_diagnostics_typecheck_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_typecheck_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(0), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_typecheck_info(uint8_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 691u);
        _a0_obj->f_id = 731u;
        _a0_obj->f_message = 2153u;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a1_obj, 691u);
        _a1_obj->f_id = 732u;
        _a1_obj->f_message = 1449u;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a2_obj, 691u);
        _a2_obj->f_id = 733u;
        _a2_obj->f_message = 2398u;
        t0 = (void*) _a2_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a3_obj, 691u);
        _a3_obj->f_id = 734u;
        _a3_obj->f_message = 2253u;
        t0 = (void*) _a3_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(4)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a4_obj, 691u);
        _a4_obj->f_id = 735u;
        _a4_obj->f_message = 1808u;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(5)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a5_obj, 691u);
        _a5_obj->f_id = 736u;
        _a5_obj->f_message = 2143u;
        t0 = (void*) _a5_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(6)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a6_obj, 691u);
        _a6_obj->f_id = 737u;
        _a6_obj->f_message = 1470u;
        t0 = (void*) _a6_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(7)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a7_obj, 691u);
        _a7_obj->f_id = 738u;
        _a7_obj->f_message = 1471u;
        t0 = (void*) _a7_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(8)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a8_obj, 691u);
        _a8_obj->f_id = 739u;
        _a8_obj->f_message = 1516u;
        t0 = (void*) _a8_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(9)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a9_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a9_obj, 691u);
        _a9_obj->f_id = 740u;
        _a9_obj->f_message = 1692u;
        t0 = (void*) _a9_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(10)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a10_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a10_obj, 691u);
        _a10_obj->f_id = 741u;
        _a10_obj->f_message = 1841u;
        t0 = (void*) _a10_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(11)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a11_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a11_obj, 691u);
        _a11_obj->f_id = 742u;
        _a11_obj->f_message = 2259u;
        t0 = (void*) _a11_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(12)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a12_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a12_obj, 691u);
        _a12_obj->f_id = 743u;
        _a12_obj->f_message = 1073u;
        t0 = (void*) _a12_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(13)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a13_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a13_obj, 691u);
        _a13_obj->f_id = 744u;
        _a13_obj->f_message = 1081u;
        t0 = (void*) _a13_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(14)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a14_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a14_obj, 691u);
        _a14_obj->f_id = 745u;
        _a14_obj->f_message = 1857u;
        t0 = (void*) _a14_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(15)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a15_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a15_obj, 691u);
        _a15_obj->f_id = 746u;
        _a15_obj->f_message = 2076u;
        t0 = (void*) _a15_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(16)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a16_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a16_obj, 691u);
        _a16_obj->f_id = 747u;
        _a16_obj->f_message = 1340u;
        t0 = (void*) _a16_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(17)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a17_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a17_obj, 691u);
        _a17_obj->f_id = 748u;
        _a17_obj->f_message = 1552u;
        t0 = (void*) _a17_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(18)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a18_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a18_obj, 691u);
        _a18_obj->f_id = 749u;
        _a18_obj->f_message = 1569u;
        t0 = (void*) _a18_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(19)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a19_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a19_obj, 691u);
        _a19_obj->f_id = 750u;
        _a19_obj->f_message = 1369u;
        t0 = (void*) _a19_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(20)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a20_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a20_obj, 691u);
        _a20_obj->f_id = 751u;
        _a20_obj->f_message = 2272u;
        t0 = (void*) _a20_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(21)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a21_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a21_obj, 691u);
        _a21_obj->f_id = 752u;
        _a21_obj->f_message = 1556u;
        t0 = (void*) _a21_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(22)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a22_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a22_obj, 691u);
        _a22_obj->f_id = 753u;
        _a22_obj->f_message = 1825u;
        t0 = (void*) _a22_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(23)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a23_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a23_obj, 691u);
        _a23_obj->f_id = 754u;
        _a23_obj->f_message = 2152u;
        t0 = (void*) _a23_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(24)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a24_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a24_obj, 691u);
        _a24_obj->f_id = 755u;
        _a24_obj->f_message = 2250u;
        t0 = (void*) _a24_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(25)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a25_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a25_obj, 691u);
        _a25_obj->f_id = 756u;
        _a25_obj->f_message = 1289u;
        t0 = (void*) _a25_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(26)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a26_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a26_obj, 691u);
        _a26_obj->f_id = 757u;
        _a26_obj->f_message = 1421u;
        t0 = (void*) _a26_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(27)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a27_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a27_obj, 691u);
        _a27_obj->f_id = 758u;
        _a27_obj->f_message = 1422u;
        t0 = (void*) _a27_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(28)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a28_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a28_obj, 691u);
        _a28_obj->f_id = 759u;
        _a28_obj->f_message = 1398u;
        t0 = (void*) _a28_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(29)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a29_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a29_obj, 691u);
        _a29_obj->f_id = 760u;
        _a29_obj->f_message = 1131u;
        t0 = (void*) _a29_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(30)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a30_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a30_obj, 691u);
        _a30_obj->f_id = 761u;
        _a30_obj->f_message = 1691u;
        t0 = (void*) _a30_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(31)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a31_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a31_obj, 691u);
        _a31_obj->f_id = 762u;
        _a31_obj->f_message = 1895u;
        t0 = (void*) _a31_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(32)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a32_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a32_obj, 691u);
        _a32_obj->f_id = 763u;
        _a32_obj->f_message = 2161u;
        t0 = (void*) _a32_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(33)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a33_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a33_obj, 691u);
        _a33_obj->f_id = 764u;
        _a33_obj->f_message = 1643u;
        t0 = (void*) _a33_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(34)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a34_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a34_obj, 691u);
        _a34_obj->f_id = 765u;
        _a34_obj->f_message = 1810u;
        t0 = (void*) _a34_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(35)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a35_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a35_obj, 691u);
        _a35_obj->f_id = 766u;
        _a35_obj->f_message = 1515u;
        t0 = (void*) _a35_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(36)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a36_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a36_obj, 691u);
        _a36_obj->f_id = 767u;
        _a36_obj->f_message = 1061u;
        t0 = (void*) _a36_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(37)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a37_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a37_obj, 691u);
        _a37_obj->f_id = 768u;
        _a37_obj->f_message = 2120u;
        t0 = (void*) _a37_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(38)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a38_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a38_obj, 691u);
        _a38_obj->f_id = 769u;
        _a38_obj->f_message = 1294u;
        t0 = (void*) _a38_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(39)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a39_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a39_obj, 691u);
        _a39_obj->f_id = 770u;
        _a39_obj->f_message = 1292u;
        t0 = (void*) _a39_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(40)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a40_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a40_obj, 691u);
        _a40_obj->f_id = 772u;
        _a40_obj->f_message = 1690u;
        t0 = (void*) _a40_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(41)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a41_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a41_obj, 691u);
        _a41_obj->f_id = 773u;
        _a41_obj->f_message = 1053u;
        t0 = (void*) _a41_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(42)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a42_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a42_obj, 691u);
        _a42_obj->f_id = 774u;
        _a42_obj->f_message = 1465u;
        t0 = (void*) _a42_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(43)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a43_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a43_obj, 691u);
        _a43_obj->f_id = 775u;
        _a43_obj->f_message = 1553u;
        t0 = (void*) _a43_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(44)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a44_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a44_obj, 691u);
        _a44_obj->f_id = 776u;
        _a44_obj->f_message = 1122u;
        t0 = (void*) _a44_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(45)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a45_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a45_obj, 691u);
        _a45_obj->f_id = 777u;
        _a45_obj->f_message = 1310u;
        t0 = (void*) _a45_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(46)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a46_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a46_obj, 691u);
        _a46_obj->f_id = 771u;
        _a46_obj->f_message = 1853u;
        t0 = (void*) _a46_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(47)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a47_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a47_obj, 691u);
        _a47_obj->f_id = 778u;
        _a47_obj->f_message = 1109u;
        t0 = (void*) _a47_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(48)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a48_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a48_obj, 691u);
        _a48_obj->f_id = 786u;
        _a48_obj->f_message = 1675u;
        t0 = (void*) _a48_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(49)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a49_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a49_obj, 691u);
        _a49_obj->f_id = 779u;
        _a49_obj->f_message = 1110u;
        t0 = (void*) _a49_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(50)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a50_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a50_obj, 691u);
        _a50_obj->f_id = 780u;
        _a50_obj->f_message = 1086u;
        t0 = (void*) _a50_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(51)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a51_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a51_obj, 691u);
        _a51_obj->f_id = 781u;
        _a51_obj->f_message = 1076u;
        t0 = (void*) _a51_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(52)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a52_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a52_obj, 691u);
        _a52_obj->f_id = 782u;
        _a52_obj->f_message = 2403u;
        t0 = (void*) _a52_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(53)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a53_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a53_obj, 691u);
        _a53_obj->f_id = 783u;
        _a53_obj->f_message = 1106u;
        t0 = (void*) _a53_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(54)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a54_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a54_obj, 691u);
        _a54_obj->f_id = 784u;
        _a54_obj->f_message = 1194u;
        t0 = (void*) _a54_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(55)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a55_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a55_obj, 691u);
        _a55_obj->f_id = 785u;
        _a55_obj->f_message = 1072u;
        t0 = (void*) _a55_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(56)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a56_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a56_obj, 691u);
        _a56_obj->f_id = 787u;
        _a56_obj->f_message = 1074u;
        t0 = (void*) _a56_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(57)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a57_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a57_obj, 691u);
        _a57_obj->f_id = 788u;
        _a57_obj->f_message = 1042u;
        t0 = (void*) _a57_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(58)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a58_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a58_obj, 691u);
        _a58_obj->f_id = 789u;
        _a58_obj->f_message = 1290u;
        t0 = (void*) _a58_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(59)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a59_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a59_obj, 691u);
        _a59_obj->f_id = 790u;
        _a59_obj->f_message = 1293u;
        t0 = (void*) _a59_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(60)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a60_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a60_obj, 691u);
        _a60_obj->f_id = 791u;
        _a60_obj->f_message = 2132u;
        t0 = (void*) _a60_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(61)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a61_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a61_obj, 691u);
        _a61_obj->f_id = 792u;
        _a61_obj->f_message = 2126u;
        t0 = (void*) _a61_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(62)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a62_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a62_obj, 691u);
        _a62_obj->f_id = 793u;
        _a62_obj->f_message = 2131u;
        t0 = (void*) _a62_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(63)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a63_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a63_obj, 691u);
        _a63_obj->f_id = 794u;
        _a63_obj->f_message = 1117u;
        t0 = (void*) _a63_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(64)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a64_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a64_obj, 691u);
        _a64_obj->f_id = 795u;
        _a64_obj->f_message = 1104u;
        t0 = (void*) _a64_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(65)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a65_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a65_obj, 691u);
        _a65_obj->f_id = 796u;
        _a65_obj->f_message = 1111u;
        t0 = (void*) _a65_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(66)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a66_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a66_obj, 691u);
        _a66_obj->f_id = 797u;
        _a66_obj->f_message = 1113u;
        t0 = (void*) _a66_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(67)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a67_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a67_obj, 691u);
        _a67_obj->f_id = 798u;
        _a67_obj->f_message = 2130u;
        t0 = (void*) _a67_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_diagnostics$typecheck_info");
    vader_gc_top = gc_frame.prev;
}

void* vader_diagnostics_warning(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_warning_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(1), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_warning_info(uint8_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 691u);
        _a0_obj->f_id = 812u;
        _a0_obj->f_message = 2273u;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(1)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a1_obj, 691u);
        _a1_obj->f_id = 813u;
        _a1_obj->f_message = 2258u;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a2_obj, 691u);
        _a2_obj->f_id = 814u;
        _a2_obj->f_message = 2384u;
        t0 = (void*) _a2_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(3)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a3_obj, 691u);
        _a3_obj->f_id = 815u;
        _a3_obj->f_message = 1376u;
        t0 = (void*) _a3_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(4)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a4_obj, 691u);
        _a4_obj->f_id = 816u;
        _a4_obj->f_message = 1757u;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(5)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a5_obj, 691u);
        _a5_obj->f_id = 817u;
        _a5_obj->f_message = 1897u;
        t0 = (void*) _a5_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(6)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a6_obj, 691u);
        _a6_obj->f_id = 818u;
        _a6_obj->f_message = 1879u;
        t0 = (void*) _a6_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(7)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a7_obj, 691u);
        _a7_obj->f_id = 819u;
        _a7_obj->f_message = 1414u;
        t0 = (void*) _a7_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(8)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a8_obj, 691u);
        _a8_obj->f_id = 820u;
        _a8_obj->f_message = 1466u;
        t0 = (void*) _a8_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(9)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a9_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a9_obj, 691u);
        _a9_obj->f_id = 821u;
        _a9_obj->f_message = 1063u;
        t0 = (void*) _a9_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_diagnostics$warning_info");
    vader_gc_top = gc_frame.prev;
}

