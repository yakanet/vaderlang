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
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_comptime_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(0), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_comptime_info(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 700u);
        _a0_obj->f_id = 556u;
        _a0_obj->f_message = 1532u;
        l1 = (void*) _a0_obj;
    } else {
        if (l0 == INT32_C(1)) {
            vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
            vader_obj_header_init(_a1_obj, 700u);
            _a1_obj->f_id = 557u;
            _a1_obj->f_message = 1394u;
            l1 = (void*) _a1_obj;
        } else {
            if (l0 == INT32_C(2)) {
                vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                vader_obj_header_init(_a2_obj, 700u);
                _a2_obj->f_id = 558u;
                _a2_obj->f_message = 1620u;
                l1 = (void*) _a2_obj;
            } else {
                if (l0 == INT32_C(3)) {
                    vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                    vader_obj_header_init(_a3_obj, 700u);
                    _a3_obj->f_id = 559u;
                    _a3_obj->f_message = 1390u;
                    l1 = (void*) _a3_obj;
                } else {
                    if (l0 == INT32_C(4)) {
                        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                        vader_obj_header_init(_a4_obj, 700u);
                        _a4_obj->f_id = 560u;
                        _a4_obj->f_message = 1391u;
                        l1 = (void*) _a4_obj;
                    } else {
                        if (l0 == INT32_C(5)) {
                            vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                            vader_obj_header_init(_a5_obj, 700u);
                            _a5_obj->f_id = 561u;
                            _a5_obj->f_message = 537u;
                            l1 = (void*) _a5_obj;
                        } else {
                            if (l0 == INT32_C(6)) {
                                vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                vader_obj_header_init(_a6_obj, 700u);
                                _a6_obj->f_id = 562u;
                                _a6_obj->f_message = 1398u;
                                l1 = (void*) _a6_obj;
                            } else {
                                if (l0 == INT32_C(7)) {
                                    vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                    vader_obj_header_init(_a7_obj, 700u);
                                    _a7_obj->f_id = 563u;
                                    _a7_obj->f_message = 591u;
                                    l1 = (void*) _a7_obj;
                                } else {
                                    if (l0 == INT32_C(8)) {
                                        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                        vader_obj_header_init(_a8_obj, 700u);
                                        _a8_obj->f_id = 564u;
                                        _a8_obj->f_message = 1392u;
                                        l1 = (void*) _a8_obj;
                                    } else {
                                        if (l0 == INT32_C(9)) {
                                            vader_struct_vader_diagnostics_CodeInfo_t* _a9_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                            vader_obj_header_init(_a9_obj, 700u);
                                            _a9_obj->f_id = 565u;
                                            _a9_obj->f_message = 1396u;
                                            l1 = (void*) _a9_obj;
                                        } else {
                                            if (l0 == INT32_C(10)) {
                                                vader_struct_vader_diagnostics_CodeInfo_t* _a10_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                vader_obj_header_init(_a10_obj, 700u);
                                                _a10_obj->f_id = 566u;
                                                _a10_obj->f_message = 1395u;
                                                l1 = (void*) _a10_obj;
                                            } else {
                                                if (l0 == INT32_C(11)) {
                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a11_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                    vader_obj_header_init(_a11_obj, 700u);
                                                    _a11_obj->f_id = 567u;
                                                    _a11_obj->f_message = 536u;
                                                    l1 = (void*) _a11_obj;
                                                } else {
                                                    if (l0 == INT32_C(12)) {
                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a12_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                        vader_obj_header_init(_a12_obj, 700u);
                                                        _a12_obj->f_id = 568u;
                                                        _a12_obj->f_message = 1440u;
                                                        l1 = (void*) _a12_obj;
                                                    } else {
                                                        if (l0 == INT32_C(13)) {
                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a13_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                            vader_obj_header_init(_a13_obj, 700u);
                                                            _a13_obj->f_id = 569u;
                                                            _a13_obj->f_message = 1637u;
                                                            l1 = (void*) _a13_obj;
                                                        } else {
                                                            if (l0 == INT32_C(14)) {
                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a14_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                vader_obj_header_init(_a14_obj, 700u);
                                                                _a14_obj->f_id = 570u;
                                                                _a14_obj->f_message = 1387u;
                                                                l1 = (void*) _a14_obj;
                                                            } else {
                                                                if (l0 == INT32_C(15)) {
                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a15_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                    vader_obj_header_init(_a15_obj, 700u);
                                                                    _a15_obj->f_id = 571u;
                                                                    _a15_obj->f_message = 1720u;
                                                                    l1 = (void*) _a15_obj;
                                                                } else {
                                                                    vader_unreachable("unreachable return in vader_diagnostics$comptime_info");
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
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_dedup_diagnostics(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4, l5;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 167u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 172u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 359u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__string_t* _a4_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 381u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    vader_array_t* _a5_arr = vader_array_new(51u, 0u, 13u, 701u);
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
                }
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_24;
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_diagnostics_diag_key(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    size_t l4, l5;
    void* l6 = NULL;
    int64_t l7;
    uint64_t l8;
    int64_t t0;
    size_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l3, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_code)->f_id;
    l2 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_primary)->f_start)->f_file;
    l3 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_detail;
    l4 = vader_host_std_core_byte_len(l1);
    l5 = vader_host_std_core_byte_len(l2);
    t0 = (l4 + l5);
    l4 = (size_t) (int64_t) t0;
    l5 = vader_host_std_core_byte_len(l3);
    t0 = (l4 + l5);
    l4 = (size_t) (int64_t) t0;
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(65) + l4));
    l4 = (size_t) (int64_t) INT64_C(0);
    l7 = ((int64_t) (int32_t) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_severity);
    l4 = std_core_write_int(l6, l4, l7);
    l4 = std_core_write_string_at(l6, l4, 2434u);
    l4 = std_core_write_string_at(l6, l4, l1);
    l4 = std_core_write_string_at(l6, l4, 2434u);
    l4 = std_core_write_string_at(l6, l4, l2);
    l4 = std_core_write_string_at(l6, l4, 2434u);
    t1 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_primary)->f_start)->f_offset;
    t0 = ((int64_t) (size_t) t1);
    l8 = (uint64_t) (int64_t) t0;
    l4 = std_core_write_unsigned(l6, l4, l8);
    l4 = std_core_write_string_at(l6, l4, 2434u);
    t1 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l0)->f_primary)->f_end)->f_offset;
    t0 = ((int64_t) (size_t) t1);
    l8 = (uint64_t) (int64_t) t0;
    l4 = std_core_write_unsigned(l6, l4, l8);
    l4 = std_core_write_string_at(l6, l4, 2434u);
    l4 = std_core_write_string_at(l6, l4, l3);
    t2 = std_core_finish_buffer(l6, l4);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool vader_diagnostics_diag_less(void* l0, void* l1) {
    size_t l2, l3;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
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
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
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
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_diagnostics_render_diagnostics(l0, true, true);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_diagnostics_format_diagnostic(void* l0, void* l1, bool l2, vader_string_t l3) {
    vader_string_t l4 = 0;
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l14 = 0;
    int32_t l5;
    bool l7;
    void* l8 = NULL;
    void* l12 = NULL;
    size_t l11;
    int64_t l13;
    vader_string_t t0 = 0;
    bool t1;
    int32_t t2;
    void** gc_raw_roots[4] = { &l0, &l1, &l8, &l12 };
    vader_string_t* gc_atom_roots[7] = { &l3, &l4, &l6, &l9, &l10, &l14, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_severity;
    if (l5 == INT32_C(0)) {
        l4 = 1491u;
    } else {
        if (l5 == INT32_C(1)) {
            l4 = 2402u;
        } else {
            if (l5 == INT32_C(2)) {
                l4 = 1727u;
            } else {
                if (l5 == INT32_C(3)) {
                    l4 = 1647u;
                } else {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
        }
    }
    if (l2) {
        l5 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_severity;
        if (l5 == INT32_C(0)) {
            l6 = std_tty_red(l4);
        } else {
            if (l5 == INT32_C(1)) {
                l6 = std_tty_yellow(l4);
            } else {
                if (l5 == INT32_C(2)) {
                    l7 = true;
                } else {
                    l7 = l5 == INT32_C(3);
                }
                if (l7) {
                    l6 = l4;
                } else {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
        }
    } else {
        l6 = l4;
    }
    l8 = ((vader_struct_toolchain_span_Span_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_primary)->f_start;
    l4 = 0u;
    t0 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
    t1 = std_string_is_empty(t0);
    if (!(t1)) {
        l9 = ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_detail;
        l4 = concat_2(470u, l9);
    }
    if (l2) {
        t0 = ((vader_struct_toolchain_span_Position_t*) l8)->f_file;
        l10 = vader_diagnostics_relative_to(t0, l3);
        l11 = vader_host_std_core_byte_len(l10);
        l12 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(42) + l11));
        l11 = (size_t) (int64_t) INT64_C(0);
        l11 = std_core_write_string_at(l12, l11, l10);
        l11 = std_core_write_string_at(l12, l11, 469u);
        t2 = ((vader_struct_toolchain_span_Position_t*) l8)->f_line;
        l13 = ((int64_t) (int32_t) t2);
        l11 = std_core_write_int(l12, l11, l13);
        l11 = std_core_write_string_at(l12, l11, 469u);
        t2 = ((vader_struct_toolchain_span_Position_t*) l8)->f_column;
        l13 = ((int64_t) (int32_t) t2);
        l11 = std_core_write_int(l12, l11, l13);
        l9 = std_core_finish_buffer(l12, l11);
    } else {
        l12 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(41));
        l11 = (size_t) (int64_t) INT64_C(0);
        t2 = ((vader_struct_toolchain_span_Position_t*) l8)->f_line;
        l13 = ((int64_t) (int32_t) t2);
        l11 = std_core_write_int(l12, l11, l13);
        l11 = std_core_write_string_at(l12, l11, 469u);
        t2 = ((vader_struct_toolchain_span_Position_t*) l8)->f_column;
        l13 = ((int64_t) (int32_t) t2);
        l11 = std_core_write_int(l12, l11, l13);
        l9 = std_core_finish_buffer(l12, l11);
    }
    l10 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_id;
    l14 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l1)->f_code)->f_message;
    l4 = concat_9(851u, l9, 856u, l6, 851u, l10, 856u, l14, l4);
    std_string_builder_append(l0, l4);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void* vader_diagnostics_lexer_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_lexer_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(0), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_lexer_info(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 700u);
        _a0_obj->f_id = 627u;
        _a0_obj->f_message = 2272u;
        l1 = (void*) _a0_obj;
    } else {
        if (l0 == INT32_C(1)) {
            vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
            vader_obj_header_init(_a1_obj, 700u);
            _a1_obj->f_id = 628u;
            _a1_obj->f_message = 2298u;
            l1 = (void*) _a1_obj;
        } else {
            if (l0 == INT32_C(2)) {
                vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                vader_obj_header_init(_a2_obj, 700u);
                _a2_obj->f_id = 629u;
                _a2_obj->f_message = 2293u;
                l1 = (void*) _a2_obj;
            } else {
                if (l0 == INT32_C(3)) {
                    vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                    vader_obj_header_init(_a3_obj, 700u);
                    _a3_obj->f_id = 630u;
                    _a3_obj->f_message = 1763u;
                    l1 = (void*) _a3_obj;
                } else {
                    if (l0 == INT32_C(4)) {
                        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                        vader_obj_header_init(_a4_obj, 700u);
                        _a4_obj->f_id = 631u;
                        _a4_obj->f_message = 1761u;
                        l1 = (void*) _a4_obj;
                    } else {
                        if (l0 == INT32_C(5)) {
                            vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                            vader_obj_header_init(_a5_obj, 700u);
                            _a5_obj->f_id = 632u;
                            _a5_obj->f_message = 1848u;
                            l1 = (void*) _a5_obj;
                        } else {
                            if (l0 == INT32_C(6)) {
                                vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                vader_obj_header_init(_a6_obj, 700u);
                                _a6_obj->f_id = 633u;
                                _a6_obj->f_message = 2101u;
                                l1 = (void*) _a6_obj;
                            } else {
                                if (l0 == INT32_C(7)) {
                                    vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                    vader_obj_header_init(_a7_obj, 700u);
                                    _a7_obj->f_id = 634u;
                                    _a7_obj->f_message = 2013u;
                                    l1 = (void*) _a7_obj;
                                } else {
                                    if (l0 == INT32_C(8)) {
                                        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                        vader_obj_header_init(_a8_obj, 700u);
                                        _a8_obj->f_id = 635u;
                                        _a8_obj->f_message = 1755u;
                                        l1 = (void*) _a8_obj;
                                    } else {
                                        if (l0 == INT32_C(9)) {
                                            vader_struct_vader_diagnostics_CodeInfo_t* _a9_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                            vader_obj_header_init(_a9_obj, 700u);
                                            _a9_obj->f_id = 636u;
                                            _a9_obj->f_message = 1746u;
                                            l1 = (void*) _a9_obj;
                                        } else {
                                            if (l0 == INT32_C(10)) {
                                                vader_struct_vader_diagnostics_CodeInfo_t* _a10_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                vader_obj_header_init(_a10_obj, 700u);
                                                _a10_obj->f_id = 637u;
                                                _a10_obj->f_message = 1742u;
                                                l1 = (void*) _a10_obj;
                                            } else {
                                                vader_unreachable("unreachable return in vader_diagnostics$lexer_info");
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
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_diagnostics_lower_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_lower_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(0), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_lower_info(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 700u);
        _a0_obj->f_id = 641u;
        _a0_obj->f_message = 1610u;
        l1 = (void*) _a0_obj;
    } else {
        if (l0 == INT32_C(1)) {
            vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
            vader_obj_header_init(_a1_obj, 700u);
            _a1_obj->f_id = 642u;
            _a1_obj->f_message = 1805u;
            l1 = (void*) _a1_obj;
        } else {
            if (l0 == INT32_C(2)) {
                vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                vader_obj_header_init(_a2_obj, 700u);
                _a2_obj->f_id = 643u;
                _a2_obj->f_message = 1850u;
                l1 = (void*) _a2_obj;
            } else {
                if (l0 == INT32_C(3)) {
                    vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                    vader_obj_header_init(_a3_obj, 700u);
                    _a3_obj->f_id = 644u;
                    _a3_obj->f_message = 1113u;
                    l1 = (void*) _a3_obj;
                } else {
                    if (l0 == INT32_C(4)) {
                        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                        vader_obj_header_init(_a4_obj, 700u);
                        _a4_obj->f_id = 645u;
                        _a4_obj->f_message = 1751u;
                        l1 = (void*) _a4_obj;
                    } else {
                        if (l0 == INT32_C(5)) {
                            vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                            vader_obj_header_init(_a5_obj, 700u);
                            _a5_obj->f_id = 646u;
                            _a5_obj->f_message = 1863u;
                            l1 = (void*) _a5_obj;
                        } else {
                            if (l0 == INT32_C(6)) {
                                vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                vader_obj_header_init(_a6_obj, 700u);
                                _a6_obj->f_id = 647u;
                                _a6_obj->f_message = 1698u;
                                l1 = (void*) _a6_obj;
                            } else {
                                if (l0 == INT32_C(7)) {
                                    vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                    vader_obj_header_init(_a7_obj, 700u);
                                    _a7_obj->f_id = 648u;
                                    _a7_obj->f_message = 1122u;
                                    l1 = (void*) _a7_obj;
                                } else {
                                    if (l0 == INT32_C(8)) {
                                        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                        vader_obj_header_init(_a8_obj, 700u);
                                        _a8_obj->f_id = 649u;
                                        _a8_obj->f_message = 1098u;
                                        l1 = (void*) _a8_obj;
                                    } else {
                                        vader_unreachable("unreachable return in vader_diagnostics$lower_info");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_new_diagnostic(int32_t l0, void* l1, void* l2, vader_string_t l3) {
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_diagnostics_Diagnostic_t* _a0_obj = (vader_struct_vader_diagnostics_Diagnostic_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_Diagnostic_t));
    vader_obj_header_init(_a0_obj, 701u);
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
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_parser_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(0), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_parser_info(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 700u);
        _a0_obj->f_id = 663u;
        _a0_obj->f_message = 2274u;
        l1 = (void*) _a0_obj;
    } else {
        if (l0 == INT32_C(1)) {
            vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
            vader_obj_header_init(_a1_obj, 700u);
            _a1_obj->f_id = 664u;
            _a1_obj->f_message = 1520u;
            l1 = (void*) _a1_obj;
        } else {
            if (l0 == INT32_C(2)) {
                vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                vader_obj_header_init(_a2_obj, 700u);
                _a2_obj->f_id = 665u;
                _a2_obj->f_message = 1511u;
                l1 = (void*) _a2_obj;
            } else {
                if (l0 == INT32_C(3)) {
                    vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                    vader_obj_header_init(_a3_obj, 700u);
                    _a3_obj->f_id = 666u;
                    _a3_obj->f_message = 1508u;
                    l1 = (void*) _a3_obj;
                } else {
                    if (l0 == INT32_C(4)) {
                        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                        vader_obj_header_init(_a4_obj, 700u);
                        _a4_obj->f_id = 667u;
                        _a4_obj->f_message = 1510u;
                        l1 = (void*) _a4_obj;
                    } else {
                        if (l0 == INT32_C(5)) {
                            vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                            vader_obj_header_init(_a5_obj, 700u);
                            _a5_obj->f_id = 668u;
                            _a5_obj->f_message = 1505u;
                            l1 = (void*) _a5_obj;
                        } else {
                            if (l0 == INT32_C(6)) {
                                vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                vader_obj_header_init(_a6_obj, 700u);
                                _a6_obj->f_id = 669u;
                                _a6_obj->f_message = 1507u;
                                l1 = (void*) _a6_obj;
                            } else {
                                if (l0 == INT32_C(7)) {
                                    vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                    vader_obj_header_init(_a7_obj, 700u);
                                    _a7_obj->f_id = 670u;
                                    _a7_obj->f_message = 1513u;
                                    l1 = (void*) _a7_obj;
                                } else {
                                    if (l0 == INT32_C(8)) {
                                        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                        vader_obj_header_init(_a8_obj, 700u);
                                        _a8_obj->f_id = 671u;
                                        _a8_obj->f_message = 2168u;
                                        l1 = (void*) _a8_obj;
                                    } else {
                                        if (l0 == INT32_C(9)) {
                                            vader_struct_vader_diagnostics_CodeInfo_t* _a9_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                            vader_obj_header_init(_a9_obj, 700u);
                                            _a9_obj->f_id = 672u;
                                            _a9_obj->f_message = 1913u;
                                            l1 = (void*) _a9_obj;
                                        } else {
                                            if (l0 == INT32_C(10)) {
                                                vader_struct_vader_diagnostics_CodeInfo_t* _a10_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                vader_obj_header_init(_a10_obj, 700u);
                                                _a10_obj->f_id = 673u;
                                                _a10_obj->f_message = 2123u;
                                                l1 = (void*) _a10_obj;
                                            } else {
                                                if (l0 == INT32_C(11)) {
                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a11_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                    vader_obj_header_init(_a11_obj, 700u);
                                                    _a11_obj->f_id = 674u;
                                                    _a11_obj->f_message = 1877u;
                                                    l1 = (void*) _a11_obj;
                                                } else {
                                                    if (l0 == INT32_C(12)) {
                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a12_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                        vader_obj_header_init(_a12_obj, 700u);
                                                        _a12_obj->f_id = 675u;
                                                        _a12_obj->f_message = 1497u;
                                                        l1 = (void*) _a12_obj;
                                                    } else {
                                                        if (l0 == INT32_C(13)) {
                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a13_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                            vader_obj_header_init(_a13_obj, 700u);
                                                            _a13_obj->f_id = 676u;
                                                            _a13_obj->f_message = 2277u;
                                                            l1 = (void*) _a13_obj;
                                                        } else {
                                                            if (l0 == INT32_C(28)) {
                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a14_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                vader_obj_header_init(_a14_obj, 700u);
                                                                _a14_obj->f_id = 691u;
                                                                _a14_obj->f_message = 2421u;
                                                                l1 = (void*) _a14_obj;
                                                            } else {
                                                                if (l0 == INT32_C(29)) {
                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a15_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                    vader_obj_header_init(_a15_obj, 700u);
                                                                    _a15_obj->f_id = 692u;
                                                                    _a15_obj->f_message = 1439u;
                                                                    l1 = (void*) _a15_obj;
                                                                } else {
                                                                    if (l0 == INT32_C(14)) {
                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a16_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                        vader_obj_header_init(_a16_obj, 700u);
                                                                        _a16_obj->f_id = 677u;
                                                                        _a16_obj->f_message = 1464u;
                                                                        l1 = (void*) _a16_obj;
                                                                    } else {
                                                                        if (l0 == INT32_C(15)) {
                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a17_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                            vader_obj_header_init(_a17_obj, 700u);
                                                                            _a17_obj->f_id = 678u;
                                                                            _a17_obj->f_message = 1506u;
                                                                            l1 = (void*) _a17_obj;
                                                                        } else {
                                                                            if (l0 == INT32_C(16)) {
                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a18_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                vader_obj_header_init(_a18_obj, 700u);
                                                                                _a18_obj->f_id = 679u;
                                                                                _a18_obj->f_message = 1878u;
                                                                                l1 = (void*) _a18_obj;
                                                                            } else {
                                                                                if (l0 == INT32_C(17)) {
                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a19_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                    vader_obj_header_init(_a19_obj, 700u);
                                                                                    _a19_obj->f_id = 680u;
                                                                                    _a19_obj->f_message = 2184u;
                                                                                    l1 = (void*) _a19_obj;
                                                                                } else {
                                                                                    if (l0 == INT32_C(18)) {
                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a20_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                        vader_obj_header_init(_a20_obj, 700u);
                                                                                        _a20_obj->f_id = 681u;
                                                                                        _a20_obj->f_message = 1077u;
                                                                                        l1 = (void*) _a20_obj;
                                                                                    } else {
                                                                                        if (l0 == INT32_C(19)) {
                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a21_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                            vader_obj_header_init(_a21_obj, 700u);
                                                                                            _a21_obj->f_id = 682u;
                                                                                            _a21_obj->f_message = 1536u;
                                                                                            l1 = (void*) _a21_obj;
                                                                                        } else {
                                                                                            if (l0 == INT32_C(20)) {
                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a22_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                vader_obj_header_init(_a22_obj, 700u);
                                                                                                _a22_obj->f_id = 683u;
                                                                                                _a22_obj->f_message = 458u;
                                                                                                l1 = (void*) _a22_obj;
                                                                                            } else {
                                                                                                if (l0 == INT32_C(21)) {
                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a23_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                    vader_obj_header_init(_a23_obj, 700u);
                                                                                                    _a23_obj->f_id = 684u;
                                                                                                    _a23_obj->f_message = 2178u;
                                                                                                    l1 = (void*) _a23_obj;
                                                                                                } else {
                                                                                                    if (l0 == INT32_C(22)) {
                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a24_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                        vader_obj_header_init(_a24_obj, 700u);
                                                                                                        _a24_obj->f_id = 685u;
                                                                                                        _a24_obj->f_message = 1811u;
                                                                                                        l1 = (void*) _a24_obj;
                                                                                                    } else {
                                                                                                        if (l0 == INT32_C(23)) {
                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a25_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                            vader_obj_header_init(_a25_obj, 700u);
                                                                                                            _a25_obj->f_id = 686u;
                                                                                                            _a25_obj->f_message = 1126u;
                                                                                                            l1 = (void*) _a25_obj;
                                                                                                        } else {
                                                                                                            if (l0 == INT32_C(24)) {
                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a26_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                vader_obj_header_init(_a26_obj, 700u);
                                                                                                                _a26_obj->f_id = 687u;
                                                                                                                _a26_obj->f_message = 1765u;
                                                                                                                l1 = (void*) _a26_obj;
                                                                                                            } else {
                                                                                                                if (l0 == INT32_C(25)) {
                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a27_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                    vader_obj_header_init(_a27_obj, 700u);
                                                                                                                    _a27_obj->f_id = 688u;
                                                                                                                    _a27_obj->f_message = 1535u;
                                                                                                                    l1 = (void*) _a27_obj;
                                                                                                                } else {
                                                                                                                    if (l0 == INT32_C(26)) {
                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a28_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                        vader_obj_header_init(_a28_obj, 700u);
                                                                                                                        _a28_obj->f_id = 689u;
                                                                                                                        _a28_obj->f_message = 1983u;
                                                                                                                        l1 = (void*) _a28_obj;
                                                                                                                    } else {
                                                                                                                        if (l0 == INT32_C(27)) {
                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a29_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                            vader_obj_header_init(_a29_obj, 700u);
                                                                                                                            _a29_obj->f_id = 690u;
                                                                                                                            _a29_obj->f_message = 1048u;
                                                                                                                            l1 = (void*) _a29_obj;
                                                                                                                        } else {
                                                                                                                            vader_unreachable("unreachable return in vader_diagnostics$parser_info");
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
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_diagnostics_relative_to(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    size_t l3, l4;
    bool t0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_is_empty(l1);
    if (t0) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = std_string_ends_with(l1, 437u);
    if (t0) {
        l2 = l1;
    } else {
        l2 = concat_2(l1, 437u);
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
    vader_string_t l6 = 0;
    uint64_t l11;
    size_t t0;
    void* t1 = NULL;
    int64_t t2;
    vader_string_t t3 = 0;
    void** gc_raw_roots[6] = { &l0, &l3, &l4, &l7, &l10, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1) {
        l3 = (void*) &vader_fn_static_vader_diagnostics_diag_less_with_file;
        l3 = std_sort_sort__Diagnostic(l0, l3);
    } else {
        l4 = (void*) &vader_fn_static_vader_diagnostics_diag_less;
        l3 = std_sort_sort__Diagnostic(l0, l4);
    }
    l3 = vader_diagnostics_dedup_diagnostics(l3);
    if (l2) {
        t0 = ((vader_array_t*) l3)->length;
        l5 = std_math_min_2(t0, (size_t) (int64_t) INT64_C(100));
    } else {
        l5 = ((vader_array_t*) l3)->length;
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 392u);
    _a1_obj->f_parts = t1;
    l4 = (void*) _a1_obj;
    std_string_builder_append(l4, 2u);
    if (l1) {
        l6 = std_io_current_working_directory();
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
            }
        }
    }
    t0 = ((vader_array_t*) l3)->length;
    if ((t0 > l5)) {
        std_string_builder_append_char(l4, 10u);
        l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(47));
        l8 = (size_t) (int64_t) INT64_C(0);
        l8 = std_core_write_string_at(l7, l8, 2443u);
        t0 = ((vader_array_t*) l3)->length;
        t2 = (t0 - l5);
        l11 = (uint64_t) (int64_t) t2;
        l8 = std_core_write_unsigned(l7, l8, l11);
        l8 = std_core_write_string_at(l7, l8, 139u);
        l6 = std_core_finish_buffer(l7, l8);
        std_string_builder_append(l4, l6);
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l4);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_diagnostics_resolver_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_resolver_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(0), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_resolver_info(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 700u);
        _a0_obj->f_id = 694u;
        _a0_obj->f_message = 1891u;
        l1 = (void*) _a0_obj;
    } else {
        if (l0 == INT32_C(1)) {
            vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
            vader_obj_header_init(_a1_obj, 700u);
            _a1_obj->f_id = 695u;
            _a1_obj->f_message = 1715u;
            l1 = (void*) _a1_obj;
        } else {
            if (l0 == INT32_C(2)) {
                vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                vader_obj_header_init(_a2_obj, 700u);
                _a2_obj->f_id = 696u;
                _a2_obj->f_message = 1718u;
                l1 = (void*) _a2_obj;
            } else {
                if (l0 == INT32_C(3)) {
                    vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                    vader_obj_header_init(_a3_obj, 700u);
                    _a3_obj->f_id = 697u;
                    _a3_obj->f_message = 1467u;
                    l1 = (void*) _a3_obj;
                } else {
                    if (l0 == INT32_C(4)) {
                        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                        vader_obj_header_init(_a4_obj, 700u);
                        _a4_obj->f_id = 698u;
                        _a4_obj->f_message = 1713u;
                        l1 = (void*) _a4_obj;
                    } else {
                        if (l0 == INT32_C(5)) {
                            vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                            vader_obj_header_init(_a5_obj, 700u);
                            _a5_obj->f_id = 699u;
                            _a5_obj->f_message = 2289u;
                            l1 = (void*) _a5_obj;
                        } else {
                            if (l0 == INT32_C(6)) {
                                vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                vader_obj_header_init(_a6_obj, 700u);
                                _a6_obj->f_id = 700u;
                                _a6_obj->f_message = 2290u;
                                l1 = (void*) _a6_obj;
                            } else {
                                if (l0 == INT32_C(7)) {
                                    vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                    vader_obj_header_init(_a7_obj, 700u);
                                    _a7_obj->f_id = 701u;
                                    _a7_obj->f_message = 2137u;
                                    l1 = (void*) _a7_obj;
                                } else {
                                    if (l0 == INT32_C(8)) {
                                        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                        vader_obj_header_init(_a8_obj, 700u);
                                        _a8_obj->f_id = 702u;
                                        _a8_obj->f_message = 2172u;
                                        l1 = (void*) _a8_obj;
                                    } else {
                                        if (l0 == INT32_C(9)) {
                                            vader_struct_vader_diagnostics_CodeInfo_t* _a9_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                            vader_obj_header_init(_a9_obj, 700u);
                                            _a9_obj->f_id = 703u;
                                            _a9_obj->f_message = 1443u;
                                            l1 = (void*) _a9_obj;
                                        } else {
                                            if (l0 == INT32_C(10)) {
                                                vader_struct_vader_diagnostics_CodeInfo_t* _a10_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                vader_obj_header_init(_a10_obj, 700u);
                                                _a10_obj->f_id = 704u;
                                                _a10_obj->f_message = 1465u;
                                                l1 = (void*) _a10_obj;
                                            } else {
                                                if (l0 == INT32_C(11)) {
                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a11_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                    vader_obj_header_init(_a11_obj, 700u);
                                                    _a11_obj->f_id = 705u;
                                                    _a11_obj->f_message = 1719u;
                                                    l1 = (void*) _a11_obj;
                                                } else {
                                                    if (l0 == INT32_C(12)) {
                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a12_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                        vader_obj_header_init(_a12_obj, 700u);
                                                        _a12_obj->f_id = 706u;
                                                        _a12_obj->f_message = 2010u;
                                                        l1 = (void*) _a12_obj;
                                                    } else {
                                                        if (l0 == INT32_C(13)) {
                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a13_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                            vader_obj_header_init(_a13_obj, 700u);
                                                            _a13_obj->f_id = 707u;
                                                            _a13_obj->f_message = 2305u;
                                                            l1 = (void*) _a13_obj;
                                                        } else {
                                                            if (l0 == INT32_C(14)) {
                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a14_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                vader_obj_header_init(_a14_obj, 700u);
                                                                _a14_obj->f_id = 708u;
                                                                _a14_obj->f_message = 1889u;
                                                                l1 = (void*) _a14_obj;
                                                            } else {
                                                                if (l0 == INT32_C(15)) {
                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a15_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                    vader_obj_header_init(_a15_obj, 700u);
                                                                    _a15_obj->f_id = 709u;
                                                                    _a15_obj->f_message = 2016u;
                                                                    l1 = (void*) _a15_obj;
                                                                } else {
                                                                    if (l0 == INT32_C(16)) {
                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a16_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                        vader_obj_header_init(_a16_obj, 700u);
                                                                        _a16_obj->f_id = 710u;
                                                                        _a16_obj->f_message = 1567u;
                                                                        l1 = (void*) _a16_obj;
                                                                    } else {
                                                                        if (l0 == INT32_C(17)) {
                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a17_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                            vader_obj_header_init(_a17_obj, 700u);
                                                                            _a17_obj->f_id = 711u;
                                                                            _a17_obj->f_message = 1936u;
                                                                            l1 = (void*) _a17_obj;
                                                                        } else {
                                                                            if (l0 == INT32_C(18)) {
                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a18_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                vader_obj_header_init(_a18_obj, 700u);
                                                                                _a18_obj->f_id = 712u;
                                                                                _a18_obj->f_message = 1136u;
                                                                                l1 = (void*) _a18_obj;
                                                                            } else {
                                                                                if (l0 == INT32_C(19)) {
                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a19_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                    vader_obj_header_init(_a19_obj, 700u);
                                                                                    _a19_obj->f_id = 713u;
                                                                                    _a19_obj->f_message = 1888u;
                                                                                    l1 = (void*) _a19_obj;
                                                                                } else {
                                                                                    if (l0 == INT32_C(20)) {
                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a20_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                        vader_obj_header_init(_a20_obj, 700u);
                                                                                        _a20_obj->f_id = 714u;
                                                                                        _a20_obj->f_message = 1892u;
                                                                                        l1 = (void*) _a20_obj;
                                                                                    } else {
                                                                                        if (l0 == INT32_C(21)) {
                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a21_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                            vader_obj_header_init(_a21_obj, 700u);
                                                                                            _a21_obj->f_id = 715u;
                                                                                            _a21_obj->f_message = 1596u;
                                                                                            l1 = (void*) _a21_obj;
                                                                                        } else {
                                                                                            if (l0 == INT32_C(22)) {
                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a22_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                vader_obj_header_init(_a22_obj, 700u);
                                                                                                _a22_obj->f_id = 716u;
                                                                                                _a22_obj->f_message = 2180u;
                                                                                                l1 = (void*) _a22_obj;
                                                                                            } else {
                                                                                                if (l0 == INT32_C(23)) {
                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a23_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                    vader_obj_header_init(_a23_obj, 700u);
                                                                                                    _a23_obj->f_id = 717u;
                                                                                                    _a23_obj->f_message = 2011u;
                                                                                                    l1 = (void*) _a23_obj;
                                                                                                } else {
                                                                                                    if (l0 == INT32_C(24)) {
                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a24_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                        vader_obj_header_init(_a24_obj, 700u);
                                                                                                        _a24_obj->f_id = 718u;
                                                                                                        _a24_obj->f_message = 1980u;
                                                                                                        l1 = (void*) _a24_obj;
                                                                                                    } else {
                                                                                                        if (l0 == INT32_C(25)) {
                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a25_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                            vader_obj_header_init(_a25_obj, 700u);
                                                                                                            _a25_obj->f_id = 719u;
                                                                                                            _a25_obj->f_message = 1466u;
                                                                                                            l1 = (void*) _a25_obj;
                                                                                                        } else {
                                                                                                            if (l0 == INT32_C(26)) {
                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a26_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                vader_obj_header_init(_a26_obj, 700u);
                                                                                                                _a26_obj->f_id = 720u;
                                                                                                                _a26_obj->f_message = 1527u;
                                                                                                                l1 = (void*) _a26_obj;
                                                                                                            } else {
                                                                                                                if (l0 == INT32_C(27)) {
                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a27_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                    vader_obj_header_init(_a27_obj, 700u);
                                                                                                                    _a27_obj->f_id = 721u;
                                                                                                                    _a27_obj->f_message = 1521u;
                                                                                                                    l1 = (void*) _a27_obj;
                                                                                                                } else {
                                                                                                                    if (l0 == INT32_C(28)) {
                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a28_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                        vader_obj_header_init(_a28_obj, 700u);
                                                                                                                        _a28_obj->f_id = 722u;
                                                                                                                        _a28_obj->f_message = 1121u;
                                                                                                                        l1 = (void*) _a28_obj;
                                                                                                                    } else {
                                                                                                                        if (l0 == INT32_C(29)) {
                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a29_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                            vader_obj_header_init(_a29_obj, 700u);
                                                                                                                            _a29_obj->f_id = 723u;
                                                                                                                            _a29_obj->f_message = 1404u;
                                                                                                                            l1 = (void*) _a29_obj;
                                                                                                                        } else {
                                                                                                                            if (l0 == INT32_C(30)) {
                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a30_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                vader_obj_header_init(_a30_obj, 700u);
                                                                                                                                _a30_obj->f_id = 724u;
                                                                                                                                _a30_obj->f_message = 1896u;
                                                                                                                                l1 = (void*) _a30_obj;
                                                                                                                            } else {
                                                                                                                                if (l0 == INT32_C(31)) {
                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a31_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                    vader_obj_header_init(_a31_obj, 700u);
                                                                                                                                    _a31_obj->f_id = 725u;
                                                                                                                                    _a31_obj->f_message = 2154u;
                                                                                                                                    l1 = (void*) _a31_obj;
                                                                                                                                } else {
                                                                                                                                    if (l0 == INT32_C(32)) {
                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a32_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                        vader_obj_header_init(_a32_obj, 700u);
                                                                                                                                        _a32_obj->f_id = 726u;
                                                                                                                                        _a32_obj->f_message = 1164u;
                                                                                                                                        l1 = (void*) _a32_obj;
                                                                                                                                    } else {
                                                                                                                                        if (l0 == INT32_C(33)) {
                                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a33_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                            vader_obj_header_init(_a33_obj, 700u);
                                                                                                                                            _a33_obj->f_id = 727u;
                                                                                                                                            _a33_obj->f_message = 1166u;
                                                                                                                                            l1 = (void*) _a33_obj;
                                                                                                                                        } else {
                                                                                                                                            if (l0 == INT32_C(34)) {
                                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a34_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                vader_obj_header_init(_a34_obj, 700u);
                                                                                                                                                _a34_obj->f_id = 728u;
                                                                                                                                                _a34_obj->f_message = 2282u;
                                                                                                                                                l1 = (void*) _a34_obj;
                                                                                                                                            } else {
                                                                                                                                                if (l0 == INT32_C(35)) {
                                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a35_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                    vader_obj_header_init(_a35_obj, 700u);
                                                                                                                                                    _a35_obj->f_id = 729u;
                                                                                                                                                    _a35_obj->f_message = 1110u;
                                                                                                                                                    l1 = (void*) _a35_obj;
                                                                                                                                                } else {
                                                                                                                                                    if (l0 == INT32_C(36)) {
                                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a36_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                        vader_obj_header_init(_a36_obj, 700u);
                                                                                                                                                        _a36_obj->f_id = 730u;
                                                                                                                                                        _a36_obj->f_message = 1108u;
                                                                                                                                                        l1 = (void*) _a36_obj;
                                                                                                                                                    } else {
                                                                                                                                                        if (l0 == INT32_C(37)) {
                                                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a37_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                            vader_obj_header_init(_a37_obj, 700u);
                                                                                                                                                            _a37_obj->f_id = 731u;
                                                                                                                                                            _a37_obj->f_message = 2179u;
                                                                                                                                                            l1 = (void*) _a37_obj;
                                                                                                                                                        } else {
                                                                                                                                                            if (l0 == INT32_C(38)) {
                                                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a38_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                vader_obj_header_init(_a38_obj, 700u);
                                                                                                                                                                _a38_obj->f_id = 732u;
                                                                                                                                                                _a38_obj->f_message = 1462u;
                                                                                                                                                                l1 = (void*) _a38_obj;
                                                                                                                                                            } else {
                                                                                                                                                                if (l0 == INT32_C(39)) {
                                                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a39_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                    vader_obj_header_init(_a39_obj, 700u);
                                                                                                                                                                    _a39_obj->f_id = 733u;
                                                                                                                                                                    _a39_obj->f_message = 1109u;
                                                                                                                                                                    l1 = (void*) _a39_obj;
                                                                                                                                                                } else {
                                                                                                                                                                    if (l0 == INT32_C(40)) {
                                                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a40_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                        vader_obj_header_init(_a40_obj, 700u);
                                                                                                                                                                        _a40_obj->f_id = 734u;
                                                                                                                                                                        _a40_obj->f_message = 1908u;
                                                                                                                                                                        l1 = (void*) _a40_obj;
                                                                                                                                                                    } else {
                                                                                                                                                                        vader_unreachable("unreachable return in vader_diagnostics$resolver_info");
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
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_diagnostics_typecheck_error(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_typecheck_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(0), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_typecheck_info(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 700u);
        _a0_obj->f_id = 748u;
        _a0_obj->f_message = 2183u;
        l1 = (void*) _a0_obj;
    } else {
        if (l0 == INT32_C(1)) {
            vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
            vader_obj_header_init(_a1_obj, 700u);
            _a1_obj->f_id = 749u;
            _a1_obj->f_message = 1512u;
            l1 = (void*) _a1_obj;
        } else {
            if (l0 == INT32_C(2)) {
                vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                vader_obj_header_init(_a2_obj, 700u);
                _a2_obj->f_id = 750u;
                _a2_obj->f_message = 2420u;
                l1 = (void*) _a2_obj;
            } else {
                if (l0 == INT32_C(3)) {
                    vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                    vader_obj_header_init(_a3_obj, 700u);
                    _a3_obj->f_id = 751u;
                    _a3_obj->f_message = 2281u;
                    l1 = (void*) _a3_obj;
                } else {
                    if (l0 == INT32_C(4)) {
                        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                        vader_obj_header_init(_a4_obj, 700u);
                        _a4_obj->f_id = 752u;
                        _a4_obj->f_message = 1880u;
                        l1 = (void*) _a4_obj;
                    } else {
                        if (l0 == INT32_C(5)) {
                            vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                            vader_obj_header_init(_a5_obj, 700u);
                            _a5_obj->f_id = 753u;
                            _a5_obj->f_message = 2173u;
                            l1 = (void*) _a5_obj;
                        } else {
                            if (l0 == INT32_C(6)) {
                                vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                vader_obj_header_init(_a6_obj, 700u);
                                _a6_obj->f_id = 754u;
                                _a6_obj->f_message = 1533u;
                                l1 = (void*) _a6_obj;
                            } else {
                                if (l0 == INT32_C(7)) {
                                    vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                    vader_obj_header_init(_a7_obj, 700u);
                                    _a7_obj->f_id = 755u;
                                    _a7_obj->f_message = 1534u;
                                    l1 = (void*) _a7_obj;
                                } else {
                                    if (l0 == INT32_C(8)) {
                                        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                        vader_obj_header_init(_a8_obj, 700u);
                                        _a8_obj->f_id = 756u;
                                        _a8_obj->f_message = 1579u;
                                        l1 = (void*) _a8_obj;
                                    } else {
                                        if (l0 == INT32_C(9)) {
                                            vader_struct_vader_diagnostics_CodeInfo_t* _a9_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                            vader_obj_header_init(_a9_obj, 700u);
                                            _a9_obj->f_id = 757u;
                                            _a9_obj->f_message = 1760u;
                                            l1 = (void*) _a9_obj;
                                        } else {
                                            if (l0 == INT32_C(10)) {
                                                vader_struct_vader_diagnostics_CodeInfo_t* _a10_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                vader_obj_header_init(_a10_obj, 700u);
                                                _a10_obj->f_id = 758u;
                                                _a10_obj->f_message = 1914u;
                                                l1 = (void*) _a10_obj;
                                            } else {
                                                if (l0 == INT32_C(11)) {
                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a11_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                    vader_obj_header_init(_a11_obj, 700u);
                                                    _a11_obj->f_id = 759u;
                                                    _a11_obj->f_message = 2287u;
                                                    l1 = (void*) _a11_obj;
                                                } else {
                                                    if (l0 == INT32_C(12)) {
                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a12_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                        vader_obj_header_init(_a12_obj, 700u);
                                                        _a12_obj->f_id = 760u;
                                                        _a12_obj->f_message = 1124u;
                                                        l1 = (void*) _a12_obj;
                                                    } else {
                                                        if (l0 == INT32_C(13)) {
                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a13_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                            vader_obj_header_init(_a13_obj, 700u);
                                                            _a13_obj->f_id = 761u;
                                                            _a13_obj->f_message = 1132u;
                                                            l1 = (void*) _a13_obj;
                                                        } else {
                                                            if (l0 == INT32_C(14)) {
                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a14_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                vader_obj_header_init(_a14_obj, 700u);
                                                                _a14_obj->f_id = 762u;
                                                                _a14_obj->f_message = 1932u;
                                                                l1 = (void*) _a14_obj;
                                                            } else {
                                                                if (l0 == INT32_C(15)) {
                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a15_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                    vader_obj_header_init(_a15_obj, 700u);
                                                                    _a15_obj->f_id = 763u;
                                                                    _a15_obj->f_message = 2106u;
                                                                    l1 = (void*) _a15_obj;
                                                                } else {
                                                                    if (l0 == INT32_C(16)) {
                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a16_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                        vader_obj_header_init(_a16_obj, 700u);
                                                                        _a16_obj->f_id = 764u;
                                                                        _a16_obj->f_message = 1403u;
                                                                        l1 = (void*) _a16_obj;
                                                                    } else {
                                                                        if (l0 == INT32_C(17)) {
                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a17_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                            vader_obj_header_init(_a17_obj, 700u);
                                                                            _a17_obj->f_id = 765u;
                                                                            _a17_obj->f_message = 1618u;
                                                                            l1 = (void*) _a17_obj;
                                                                        } else {
                                                                            if (l0 == INT32_C(18)) {
                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a18_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                vader_obj_header_init(_a18_obj, 700u);
                                                                                _a18_obj->f_id = 766u;
                                                                                _a18_obj->f_message = 1636u;
                                                                                l1 = (void*) _a18_obj;
                                                                            } else {
                                                                                if (l0 == INT32_C(19)) {
                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a19_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                    vader_obj_header_init(_a19_obj, 700u);
                                                                                    _a19_obj->f_id = 767u;
                                                                                    _a19_obj->f_message = 1431u;
                                                                                    l1 = (void*) _a19_obj;
                                                                                } else {
                                                                                    if (l0 == INT32_C(20)) {
                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a20_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                        vader_obj_header_init(_a20_obj, 700u);
                                                                                        _a20_obj->f_id = 768u;
                                                                                        _a20_obj->f_message = 2300u;
                                                                                        l1 = (void*) _a20_obj;
                                                                                    } else {
                                                                                        if (l0 == INT32_C(21)) {
                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a21_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                            vader_obj_header_init(_a21_obj, 700u);
                                                                                            _a21_obj->f_id = 769u;
                                                                                            _a21_obj->f_message = 1622u;
                                                                                            l1 = (void*) _a21_obj;
                                                                                        } else {
                                                                                            if (l0 == INT32_C(22)) {
                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a22_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                vader_obj_header_init(_a22_obj, 700u);
                                                                                                _a22_obj->f_id = 770u;
                                                                                                _a22_obj->f_message = 1897u;
                                                                                                l1 = (void*) _a22_obj;
                                                                                            } else {
                                                                                                if (l0 == INT32_C(23)) {
                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a23_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                    vader_obj_header_init(_a23_obj, 700u);
                                                                                                    _a23_obj->f_id = 771u;
                                                                                                    _a23_obj->f_message = 2182u;
                                                                                                    l1 = (void*) _a23_obj;
                                                                                                } else {
                                                                                                    if (l0 == INT32_C(24)) {
                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a24_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                        vader_obj_header_init(_a24_obj, 700u);
                                                                                                        _a24_obj->f_id = 772u;
                                                                                                        _a24_obj->f_message = 2278u;
                                                                                                        l1 = (void*) _a24_obj;
                                                                                                    } else {
                                                                                                        if (l0 == INT32_C(25)) {
                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a25_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                            vader_obj_header_init(_a25_obj, 700u);
                                                                                                            _a25_obj->f_id = 773u;
                                                                                                            _a25_obj->f_message = 1351u;
                                                                                                            l1 = (void*) _a25_obj;
                                                                                                        } else {
                                                                                                            if (l0 == INT32_C(26)) {
                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a26_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                vader_obj_header_init(_a26_obj, 700u);
                                                                                                                _a26_obj->f_id = 774u;
                                                                                                                _a26_obj->f_message = 1485u;
                                                                                                                l1 = (void*) _a26_obj;
                                                                                                            } else {
                                                                                                                if (l0 == INT32_C(27)) {
                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a27_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                    vader_obj_header_init(_a27_obj, 700u);
                                                                                                                    _a27_obj->f_id = 775u;
                                                                                                                    _a27_obj->f_message = 1486u;
                                                                                                                    l1 = (void*) _a27_obj;
                                                                                                                } else {
                                                                                                                    if (l0 == INT32_C(28)) {
                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a28_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                        vader_obj_header_init(_a28_obj, 700u);
                                                                                                                        _a28_obj->f_id = 776u;
                                                                                                                        _a28_obj->f_message = 1463u;
                                                                                                                        l1 = (void*) _a28_obj;
                                                                                                                    } else {
                                                                                                                        if (l0 == INT32_C(29)) {
                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a29_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                            vader_obj_header_init(_a29_obj, 700u);
                                                                                                                            _a29_obj->f_id = 777u;
                                                                                                                            _a29_obj->f_message = 1184u;
                                                                                                                            l1 = (void*) _a29_obj;
                                                                                                                        } else {
                                                                                                                            if (l0 == INT32_C(30)) {
                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a30_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                vader_obj_header_init(_a30_obj, 700u);
                                                                                                                                _a30_obj->f_id = 778u;
                                                                                                                                _a30_obj->f_message = 1758u;
                                                                                                                                l1 = (void*) _a30_obj;
                                                                                                                            } else {
                                                                                                                                if (l0 == INT32_C(31)) {
                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a31_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                    vader_obj_header_init(_a31_obj, 700u);
                                                                                                                                    _a31_obj->f_id = 779u;
                                                                                                                                    _a31_obj->f_message = 1971u;
                                                                                                                                    l1 = (void*) _a31_obj;
                                                                                                                                } else {
                                                                                                                                    if (l0 == INT32_C(32)) {
                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a32_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                        vader_obj_header_init(_a32_obj, 700u);
                                                                                                                                        _a32_obj->f_id = 780u;
                                                                                                                                        _a32_obj->f_message = 2191u;
                                                                                                                                        l1 = (void*) _a32_obj;
                                                                                                                                    } else {
                                                                                                                                        if (l0 == INT32_C(33)) {
                                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a33_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                            vader_obj_header_init(_a33_obj, 700u);
                                                                                                                                            _a33_obj->f_id = 781u;
                                                                                                                                            _a33_obj->f_message = 1709u;
                                                                                                                                            l1 = (void*) _a33_obj;
                                                                                                                                        } else {
                                                                                                                                            if (l0 == INT32_C(34)) {
                                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a34_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                vader_obj_header_init(_a34_obj, 700u);
                                                                                                                                                _a34_obj->f_id = 782u;
                                                                                                                                                _a34_obj->f_message = 1882u;
                                                                                                                                                l1 = (void*) _a34_obj;
                                                                                                                                            } else {
                                                                                                                                                if (l0 == INT32_C(35)) {
                                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a35_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                    vader_obj_header_init(_a35_obj, 700u);
                                                                                                                                                    _a35_obj->f_id = 783u;
                                                                                                                                                    _a35_obj->f_message = 1578u;
                                                                                                                                                    l1 = (void*) _a35_obj;
                                                                                                                                                } else {
                                                                                                                                                    if (l0 == INT32_C(36)) {
                                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a36_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                        vader_obj_header_init(_a36_obj, 700u);
                                                                                                                                                        _a36_obj->f_id = 784u;
                                                                                                                                                        _a36_obj->f_message = 1112u;
                                                                                                                                                        l1 = (void*) _a36_obj;
                                                                                                                                                    } else {
                                                                                                                                                        if (l0 == INT32_C(37)) {
                                                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a37_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                            vader_obj_header_init(_a37_obj, 700u);
                                                                                                                                                            _a37_obj->f_id = 785u;
                                                                                                                                                            _a37_obj->f_message = 2149u;
                                                                                                                                                            l1 = (void*) _a37_obj;
                                                                                                                                                        } else {
                                                                                                                                                            if (l0 == INT32_C(38)) {
                                                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a38_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                vader_obj_header_init(_a38_obj, 700u);
                                                                                                                                                                _a38_obj->f_id = 786u;
                                                                                                                                                                _a38_obj->f_message = 1357u;
                                                                                                                                                                l1 = (void*) _a38_obj;
                                                                                                                                                            } else {
                                                                                                                                                                if (l0 == INT32_C(39)) {
                                                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a39_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                    vader_obj_header_init(_a39_obj, 700u);
                                                                                                                                                                    _a39_obj->f_id = 787u;
                                                                                                                                                                    _a39_obj->f_message = 1354u;
                                                                                                                                                                    l1 = (void*) _a39_obj;
                                                                                                                                                                } else {
                                                                                                                                                                    if (l0 == INT32_C(40)) {
                                                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a40_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                        vader_obj_header_init(_a40_obj, 700u);
                                                                                                                                                                        _a40_obj->f_id = 789u;
                                                                                                                                                                        _a40_obj->f_message = 1757u;
                                                                                                                                                                        l1 = (void*) _a40_obj;
                                                                                                                                                                    } else {
                                                                                                                                                                        if (l0 == INT32_C(41)) {
                                                                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a41_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                            vader_obj_header_init(_a41_obj, 700u);
                                                                                                                                                                            _a41_obj->f_id = 790u;
                                                                                                                                                                            _a41_obj->f_message = 1104u;
                                                                                                                                                                            l1 = (void*) _a41_obj;
                                                                                                                                                                        } else {
                                                                                                                                                                            if (l0 == INT32_C(42)) {
                                                                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a42_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                vader_obj_header_init(_a42_obj, 700u);
                                                                                                                                                                                _a42_obj->f_id = 791u;
                                                                                                                                                                                _a42_obj->f_message = 1528u;
                                                                                                                                                                                l1 = (void*) _a42_obj;
                                                                                                                                                                            } else {
                                                                                                                                                                                if (l0 == INT32_C(43)) {
                                                                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a43_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                    vader_obj_header_init(_a43_obj, 700u);
                                                                                                                                                                                    _a43_obj->f_id = 792u;
                                                                                                                                                                                    _a43_obj->f_message = 1619u;
                                                                                                                                                                                    l1 = (void*) _a43_obj;
                                                                                                                                                                                } else {
                                                                                                                                                                                    if (l0 == INT32_C(44)) {
                                                                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a44_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                        vader_obj_header_init(_a44_obj, 700u);
                                                                                                                                                                                        _a44_obj->f_id = 793u;
                                                                                                                                                                                        _a44_obj->f_message = 1174u;
                                                                                                                                                                                        l1 = (void*) _a44_obj;
                                                                                                                                                                                    } else {
                                                                                                                                                                                        if (l0 == INT32_C(45)) {
                                                                                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a45_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                            vader_obj_header_init(_a45_obj, 700u);
                                                                                                                                                                                            _a45_obj->f_id = 794u;
                                                                                                                                                                                            _a45_obj->f_message = 1372u;
                                                                                                                                                                                            l1 = (void*) _a45_obj;
                                                                                                                                                                                        } else {
                                                                                                                                                                                            if (l0 == INT32_C(46)) {
                                                                                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a46_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                vader_obj_header_init(_a46_obj, 700u);
                                                                                                                                                                                                _a46_obj->f_id = 788u;
                                                                                                                                                                                                _a46_obj->f_message = 1928u;
                                                                                                                                                                                                l1 = (void*) _a46_obj;
                                                                                                                                                                                            } else {
                                                                                                                                                                                                if (l0 == INT32_C(47)) {
                                                                                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a47_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                    vader_obj_header_init(_a47_obj, 700u);
                                                                                                                                                                                                    _a47_obj->f_id = 795u;
                                                                                                                                                                                                    _a47_obj->f_message = 1161u;
                                                                                                                                                                                                    l1 = (void*) _a47_obj;
                                                                                                                                                                                                } else {
                                                                                                                                                                                                    if (l0 == INT32_C(48)) {
                                                                                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a48_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                        vader_obj_header_init(_a48_obj, 700u);
                                                                                                                                                                                                        _a48_obj->f_id = 803u;
                                                                                                                                                                                                        _a48_obj->f_message = 1741u;
                                                                                                                                                                                                        l1 = (void*) _a48_obj;
                                                                                                                                                                                                    } else {
                                                                                                                                                                                                        if (l0 == INT32_C(49)) {
                                                                                                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a49_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                            vader_obj_header_init(_a49_obj, 700u);
                                                                                                                                                                                                            _a49_obj->f_id = 796u;
                                                                                                                                                                                                            _a49_obj->f_message = 1162u;
                                                                                                                                                                                                            l1 = (void*) _a49_obj;
                                                                                                                                                                                                        } else {
                                                                                                                                                                                                            if (l0 == INT32_C(50)) {
                                                                                                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a50_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                vader_obj_header_init(_a50_obj, 700u);
                                                                                                                                                                                                                _a50_obj->f_id = 797u;
                                                                                                                                                                                                                _a50_obj->f_message = 1137u;
                                                                                                                                                                                                                l1 = (void*) _a50_obj;
                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                if (l0 == INT32_C(51)) {
                                                                                                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a51_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                    vader_obj_header_init(_a51_obj, 700u);
                                                                                                                                                                                                                    _a51_obj->f_id = 798u;
                                                                                                                                                                                                                    _a51_obj->f_message = 1127u;
                                                                                                                                                                                                                    l1 = (void*) _a51_obj;
                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                    if (l0 == INT32_C(52)) {
                                                                                                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a52_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                        vader_obj_header_init(_a52_obj, 700u);
                                                                                                                                                                                                                        _a52_obj->f_id = 799u;
                                                                                                                                                                                                                        _a52_obj->f_message = 2426u;
                                                                                                                                                                                                                        l1 = (void*) _a52_obj;
                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                        if (l0 == INT32_C(53)) {
                                                                                                                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a53_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                            vader_obj_header_init(_a53_obj, 700u);
                                                                                                                                                                                                                            _a53_obj->f_id = 800u;
                                                                                                                                                                                                                            _a53_obj->f_message = 1157u;
                                                                                                                                                                                                                            l1 = (void*) _a53_obj;
                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                            if (l0 == INT32_C(54)) {
                                                                                                                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a54_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                vader_obj_header_init(_a54_obj, 700u);
                                                                                                                                                                                                                                _a54_obj->f_id = 801u;
                                                                                                                                                                                                                                _a54_obj->f_message = 1248u;
                                                                                                                                                                                                                                l1 = (void*) _a54_obj;
                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                if (l0 == INT32_C(55)) {
                                                                                                                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a55_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                    vader_obj_header_init(_a55_obj, 700u);
                                                                                                                                                                                                                                    _a55_obj->f_id = 802u;
                                                                                                                                                                                                                                    _a55_obj->f_message = 1123u;
                                                                                                                                                                                                                                    l1 = (void*) _a55_obj;
                                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                                    if (l0 == INT32_C(56)) {
                                                                                                                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a56_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                        vader_obj_header_init(_a56_obj, 700u);
                                                                                                                                                                                                                                        _a56_obj->f_id = 804u;
                                                                                                                                                                                                                                        _a56_obj->f_message = 1125u;
                                                                                                                                                                                                                                        l1 = (void*) _a56_obj;
                                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                        if (l0 == INT32_C(57)) {
                                                                                                                                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a57_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                            vader_obj_header_init(_a57_obj, 700u);
                                                                                                                                                                                                                                            _a57_obj->f_id = 805u;
                                                                                                                                                                                                                                            _a57_obj->f_message = 1087u;
                                                                                                                                                                                                                                            l1 = (void*) _a57_obj;
                                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                                            if (l0 == INT32_C(58)) {
                                                                                                                                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a58_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                                vader_obj_header_init(_a58_obj, 700u);
                                                                                                                                                                                                                                                _a58_obj->f_id = 806u;
                                                                                                                                                                                                                                                _a58_obj->f_message = 1352u;
                                                                                                                                                                                                                                                l1 = (void*) _a58_obj;
                                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                                if (l0 == INT32_C(59)) {
                                                                                                                                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a59_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                                    vader_obj_header_init(_a59_obj, 700u);
                                                                                                                                                                                                                                                    _a59_obj->f_id = 807u;
                                                                                                                                                                                                                                                    _a59_obj->f_message = 1355u;
                                                                                                                                                                                                                                                    l1 = (void*) _a59_obj;
                                                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                                                    if (l0 == INT32_C(60)) {
                                                                                                                                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a60_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                                        vader_obj_header_init(_a60_obj, 700u);
                                                                                                                                                                                                                                                        _a60_obj->f_id = 808u;
                                                                                                                                                                                                                                                        _a60_obj->f_message = 2162u;
                                                                                                                                                                                                                                                        l1 = (void*) _a60_obj;
                                                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                                        if (l0 == INT32_C(61)) {
                                                                                                                                                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a61_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                                            vader_obj_header_init(_a61_obj, 700u);
                                                                                                                                                                                                                                                            _a61_obj->f_id = 809u;
                                                                                                                                                                                                                                                            _a61_obj->f_message = 2156u;
                                                                                                                                                                                                                                                            l1 = (void*) _a61_obj;
                                                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                                                            if (l0 == INT32_C(62)) {
                                                                                                                                                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a62_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                                                vader_obj_header_init(_a62_obj, 700u);
                                                                                                                                                                                                                                                                _a62_obj->f_id = 810u;
                                                                                                                                                                                                                                                                _a62_obj->f_message = 2161u;
                                                                                                                                                                                                                                                                l1 = (void*) _a62_obj;
                                                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                                                if (l0 == INT32_C(63)) {
                                                                                                                                                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a63_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                                                    vader_obj_header_init(_a63_obj, 700u);
                                                                                                                                                                                                                                                                    _a63_obj->f_id = 811u;
                                                                                                                                                                                                                                                                    _a63_obj->f_message = 1169u;
                                                                                                                                                                                                                                                                    l1 = (void*) _a63_obj;
                                                                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                                                                    if (l0 == INT32_C(64)) {
                                                                                                                                                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a64_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                                                        vader_obj_header_init(_a64_obj, 700u);
                                                                                                                                                                                                                                                                        _a64_obj->f_id = 812u;
                                                                                                                                                                                                                                                                        _a64_obj->f_message = 1155u;
                                                                                                                                                                                                                                                                        l1 = (void*) _a64_obj;
                                                                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                                                        if (l0 == INT32_C(65)) {
                                                                                                                                                                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a65_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                                                            vader_obj_header_init(_a65_obj, 700u);
                                                                                                                                                                                                                                                                            _a65_obj->f_id = 813u;
                                                                                                                                                                                                                                                                            _a65_obj->f_message = 1163u;
                                                                                                                                                                                                                                                                            l1 = (void*) _a65_obj;
                                                                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                                                                            if (l0 == INT32_C(66)) {
                                                                                                                                                                                                                                                                                vader_struct_vader_diagnostics_CodeInfo_t* _a66_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                                                                vader_obj_header_init(_a66_obj, 700u);
                                                                                                                                                                                                                                                                                _a66_obj->f_id = 814u;
                                                                                                                                                                                                                                                                                _a66_obj->f_message = 1165u;
                                                                                                                                                                                                                                                                                l1 = (void*) _a66_obj;
                                                                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                                                                if (l0 == INT32_C(67)) {
                                                                                                                                                                                                                                                                                    vader_struct_vader_diagnostics_CodeInfo_t* _a67_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                                                                    vader_obj_header_init(_a67_obj, 700u);
                                                                                                                                                                                                                                                                                    _a67_obj->f_id = 815u;
                                                                                                                                                                                                                                                                                    _a67_obj->f_message = 2160u;
                                                                                                                                                                                                                                                                                    l1 = (void*) _a67_obj;
                                                                                                                                                                                                                                                                                } else {
                                                                                                                                                                                                                                                                                    if (l0 == INT32_C(68)) {
                                                                                                                                                                                                                                                                                        vader_struct_vader_diagnostics_CodeInfo_t* _a68_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                                                                        vader_obj_header_init(_a68_obj, 700u);
                                                                                                                                                                                                                                                                                        _a68_obj->f_id = 816u;
                                                                                                                                                                                                                                                                                        _a68_obj->f_message = 1442u;
                                                                                                                                                                                                                                                                                        l1 = (void*) _a68_obj;
                                                                                                                                                                                                                                                                                    } else {
                                                                                                                                                                                                                                                                                        if (l0 == INT32_C(69)) {
                                                                                                                                                                                                                                                                                            vader_struct_vader_diagnostics_CodeInfo_t* _a69_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                                                                                                                                                                                                                                                                            vader_obj_header_init(_a69_obj, 700u);
                                                                                                                                                                                                                                                                                            _a69_obj->f_id = 817u;
                                                                                                                                                                                                                                                                                            _a69_obj->f_message = 1344u;
                                                                                                                                                                                                                                                                                            l1 = (void*) _a69_obj;
                                                                                                                                                                                                                                                                                        } else {
                                                                                                                                                                                                                                                                                            vader_unreachable("unreachable return in vader_diagnostics$typecheck_info");
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
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_diagnostics_warning(uint8_t l0, void* l1, vader_string_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_diagnostics_warning_info(l0);
    t0 = vader_diagnostics_new_diagnostic(INT32_C(1), l3, l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_diagnostics_warning_info(uint8_t l0) {
    void* l1 = NULL;
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(0)) {
        vader_struct_vader_diagnostics_CodeInfo_t* _a0_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
        vader_obj_header_init(_a0_obj, 700u);
        _a0_obj->f_id = 833u;
        _a0_obj->f_message = 2301u;
        l1 = (void*) _a0_obj;
    } else {
        if (l0 == INT32_C(1)) {
            vader_struct_vader_diagnostics_CodeInfo_t* _a1_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
            vader_obj_header_init(_a1_obj, 700u);
            _a1_obj->f_id = 834u;
            _a1_obj->f_message = 2286u;
            l1 = (void*) _a1_obj;
        } else {
            if (l0 == INT32_C(2)) {
                vader_struct_vader_diagnostics_CodeInfo_t* _a2_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                vader_obj_header_init(_a2_obj, 700u);
                _a2_obj->f_id = 835u;
                _a2_obj->f_message = 2408u;
                l1 = (void*) _a2_obj;
            } else {
                if (l0 == INT32_C(3)) {
                    vader_struct_vader_diagnostics_CodeInfo_t* _a3_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                    vader_obj_header_init(_a3_obj, 700u);
                    _a3_obj->f_id = 836u;
                    _a3_obj->f_message = 1438u;
                    l1 = (void*) _a3_obj;
                } else {
                    if (l0 == INT32_C(4)) {
                        vader_struct_vader_diagnostics_CodeInfo_t* _a4_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                        vader_obj_header_init(_a4_obj, 700u);
                        _a4_obj->f_id = 837u;
                        _a4_obj->f_message = 1824u;
                        l1 = (void*) _a4_obj;
                    } else {
                        if (l0 == INT32_C(5)) {
                            vader_struct_vader_diagnostics_CodeInfo_t* _a5_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                            vader_obj_header_init(_a5_obj, 700u);
                            _a5_obj->f_id = 838u;
                            _a5_obj->f_message = 1973u;
                            l1 = (void*) _a5_obj;
                        } else {
                            if (l0 == INT32_C(6)) {
                                vader_struct_vader_diagnostics_CodeInfo_t* _a6_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                vader_obj_header_init(_a6_obj, 700u);
                                _a6_obj->f_id = 839u;
                                _a6_obj->f_message = 1955u;
                                l1 = (void*) _a6_obj;
                            } else {
                                if (l0 == INT32_C(7)) {
                                    vader_struct_vader_diagnostics_CodeInfo_t* _a7_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                    vader_obj_header_init(_a7_obj, 700u);
                                    _a7_obj->f_id = 840u;
                                    _a7_obj->f_message = 1478u;
                                    l1 = (void*) _a7_obj;
                                } else {
                                    if (l0 == INT32_C(8)) {
                                        vader_struct_vader_diagnostics_CodeInfo_t* _a8_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                        vader_obj_header_init(_a8_obj, 700u);
                                        _a8_obj->f_id = 841u;
                                        _a8_obj->f_message = 1529u;
                                        l1 = (void*) _a8_obj;
                                    } else {
                                        if (l0 == INT32_C(9)) {
                                            vader_struct_vader_diagnostics_CodeInfo_t* _a9_obj = (vader_struct_vader_diagnostics_CodeInfo_t*) vader_gc_alloc(sizeof(vader_struct_vader_diagnostics_CodeInfo_t));
                                            vader_obj_header_init(_a9_obj, 700u);
                                            _a9_obj->f_id = 842u;
                                            _a9_obj->f_message = 1114u;
                                            l1 = (void*) _a9_obj;
                                        } else {
                                            vader_unreachable("unreachable return in vader_diagnostics$warning_info");
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
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

