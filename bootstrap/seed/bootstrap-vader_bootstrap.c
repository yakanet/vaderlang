#include "bootstrap.split.h"

static void* vader_bootstrap_assemble_typed_project(void* l0);
static void* vader_bootstrap_cfg_bytecode_from(void* l0, vader_string_t l1);
static void* vader_bootstrap_collect_body_diags(void* l0);
static vader_box_t vader_bootstrap_emit_c_program(vader_string_t l0, vader_string_t l1);
static vader_string_t vader_bootstrap_entry_main_name(void* l0, vader_string_t l1);
static bool vader_bootstrap_flush_build_diags(void* l0, void* l1);
static void* vader_bootstrap_gather_pipeline_diags(void* l0);
static void* vader_bootstrap_lower_to_entry(vader_string_t l0);
static void* vader_bootstrap_merge_diagnostics(void* l0, void* l1);
static vader_string_t vader_bootstrap_module_name_from_file(vader_string_t l0);
static void* vader_bootstrap_prepare_evaluated_project(vader_string_t l0);
static int32_t vader_bootstrap_write_out(vader_string_t l0, vader_string_t l1);
static int32_t vader_bootstrap_write_split_files(vader_string_t l0, void* l1);

static void* vader_bootstrap_assemble_typed_project(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    vader_string_t l3 = 0;
    size_t l5, l6;
    vader_box_t l7 = vader_box_null();
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l7, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_typecheck_new_typed_project();
    l2 = ((vader_struct_vader_typecheck_TypedProject_t*) l1)->f_modules;
    l3 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_typecheck_CheckResult_t*) l0)->f_typed)->f_resolved)->f_path;
    l4 = ((vader_struct_vader_typecheck_CheckResult_t*) l0)->f_typed;
    std_collections_put__string__Any(l2, l3, vader_ref_box(l4));
    t0 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) ((vader_struct_vader_typecheck_CheckResult_t*) l0)->f_all_modules)->f_size;
    if (!(t0 == INT64_C(0))) {
        l2 = std_collections_keys__string__TypedProgram(((vader_struct_vader_typecheck_CheckResult_t*) l0)->f_all_modules);
        l5 = ((vader_array_t*) l2)->length;
        l6 = (size_t) (int64_t) INT64_C(0);
        {
            loop_30: {
                if ((l6 < l5)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
                    l3 = t1.payload.s;
                    l7 = std_collections_get__string__Any(((vader_struct_vader_typecheck_CheckResult_t*) l0)->f_all_modules, l3);
                    if (l7.tag == 0u) {
                        t2 = (l6 + INT64_C(1));
                        l6 = (size_t) (int64_t) t2;
                        goto loop_30;
                    }
                    l4 = l7.payload.obj;
                    std_collections_put__string__Any(((vader_struct_vader_typecheck_TypedProject_t*) l1)->f_modules, l3, vader_ref_box(l4));
                    t2 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    goto loop_30;
                } else {
                }
            }
        }
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_typecheck_CheckResult_t*) l0)->f_others;
    l5 = ((vader_array_t*) l2)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_78: {
            if ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                l8 = ((vader_struct_vader_typecheck_TypedProject_t*) l1)->f_modules;
                l3 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l4)->f_resolved)->f_path;
                std_collections_put__string__Any(l8, l3, vader_ref_box(l4));
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_78;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_bootstrap_cfg_bytecode_from(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l3 = 0;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[6] = { &l0, &l2, &l4, &l5, &t0, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_lower_prune_unreachable_fns(((vader_struct_vader_bootstrap_LoweredEntry_t*) l0)->f_lowered, false);
    t1 = vader_midir_build_cfg_project(t0);
    t0 = vader_midir_eliminate_dead_cfg(t1);
    t1 = vader_midir_annotate_escape(t0);
    l2 = ((vader_struct_vader_midir_AnnotatedProject_t*) t1)->f_project;
    l3 = vader_bootstrap_module_name_from_file(l1);
    l4 = vader_bytecode_default_emit_options();
    l2 = vader_midir_emit_bytecode_from_cfg(l2, l3, l4);
    l3 = ((vader_struct_vader_bootstrap_LoweredEntry_t*) l0)->f_entry;
    l4 = ((vader_struct_vader_bootstrap_LoweredEntry_t*) l0)->f_pre_diags;
    l5 = ((vader_struct_vader_bootstrap_LoweredEntry_t*) l0)->f_lower_diags;
    vader_struct_vader_bootstrap_CfgBytecode_t* _a0_obj = (vader_struct_vader_bootstrap_CfgBytecode_t*) vader_gc_alloc(sizeof(vader_struct_vader_bootstrap_CfgBytecode_t));
    vader_obj_header_init(_a0_obj, 483u);
    _a0_obj->f_entry = l3;
    _a0_obj->f_pre_diags = l4;
    _a0_obj->f_lower_diags = l5;
    _a0_obj->f_module = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_bootstrap_collect_body_diags(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    size_t l3, l4, l10, l11;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_box_t l8 = vader_box_null();
    size_t t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l8, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l7, &l9, &l12 };
    vader_string_t* gc_atom_roots[2] = { &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(51u, 0u, 13u, 700u);
    l1 = (void*) _a0_arr;
    t0 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) ((vader_struct_vader_typecheck_CheckResult_t*) l0)->f_all_modules)->f_size;
    if (t0 == INT64_C(0)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = std_collections_keys__string__TypedProgram(((vader_struct_vader_typecheck_CheckResult_t*) l0)->f_all_modules);
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_19: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                l5 = t1.payload.s;
                l6 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_typecheck_CheckResult_t*) l0)->f_typed)->f_resolved)->f_path;
                if (l5 == l6) {
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_19;
                }
                l8 = std_collections_get__string__Any(((vader_struct_vader_typecheck_CheckResult_t*) l0)->f_all_modules, l5);
                if (l8.tag == 0u) {
                    t2 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t2;
                    goto loop_19;
                }
                l7 = l8.payload.obj;
                l9 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l7)->f_resolved)->f_diags;
                l10 = ((vader_array_t*) l9)->length;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_67: {
                        if ((l11 < l10)) {
                            vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
                            if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                            if ((size_t) l11 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                            l12 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
                            vader_array_push((vader_array_t*) l1, vader_ref_box(l12));
                            t2 = (l11 + INT64_C(1));
                            l11 = (size_t) (int64_t) t2;
                            goto loop_67;
                        } else {
                        }
                    }
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_19;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_bootstrap_emit_c_program(vader_string_t l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_string_t l5 = 0;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l2, &l3, &l4, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_bootstrap_lower_to_entry(l0);
    l3 = ((vader_struct_vader_bootstrap_LoweredEntry_t*) l2)->f_pre_diags;
    l4 = ((vader_struct_vader_bootstrap_LoweredEntry_t*) l2)->f_lower_diags;
    t0 = vader_bootstrap_flush_build_diags(l3, l4);
    if (!(t0)) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_bootstrap_cfg_bytecode_from(l2, l0);
    l3 = ((vader_struct_vader_bootstrap_CfgBytecode_t*) l2)->f_module;
    l5 = ((vader_struct_vader_bootstrap_CfgBytecode_t*) l2)->f_entry;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l2 = (void*) _a0_arr;
    vader_struct_vader_c_emit_EmitOptions_t* _a1_obj = (vader_struct_vader_c_emit_EmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_EmitOptions_t));
    vader_obj_header_init(_a1_obj, 666u);
    _a1_obj->f_release = false;
    _a1_obj->f_entry_mangled = l5;
    _a1_obj->f_split = false;
    _a1_obj->f_atom_universe = l2;
    l2 = (void*) _a1_obj;
    t2 = vader_c_emit_emit_c_split(l3, l2, l1);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_bootstrap_entry_main_name(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[3] = { &l1, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = std_collections_get__string__Any(((vader_struct_vader_typecheck_TypedProject_t*) l0)->f_modules, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    l2 = l3.payload.obj;
    t0 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_resolved)->f_display_path;
    t1 = vader_lower_mangle_module_id(t0);
    t0 = concat_2(t1, 254u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_bootstrap_flush_build_diags(void* l0, void* l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    size_t l4, l5;
    size_t t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    int64_t t3;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_bootstrap_merge_diagnostics(l0, l1);
    t0 = ((vader_array_t*) l2)->length;
    if ((t0 > INT64_C(0))) {
        t1 = vader_diagnostics_dump_diagnostics_with_file(l2);
        l3 = concat_2(t1, 1u);
        std_io_write(INT32_C(1), l3);
    } else {
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_24: {
            if ((l5 < l4)) {
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                if (((vader_struct_vader_diagnostics_Diagnostic_t*) t2)->f_severity == INT32_C(0)) {
                    { vader_gc_top = gc_frame.prev; return false; }
                }
                t3 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t3;
                goto loop_24;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return true; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_bootstrap_gather_pipeline_diags(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4;
    int64_t t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(51u, 0u, 13u, 700u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_vader_resolver_LoadedProject_t*) ((vader_struct_vader_bootstrap_EvaluatedPipeline_t*) l0)->f_loaded)->f_diags;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_10: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
                vader_array_push((vader_array_t*) l1, vader_ref_box(l5));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_10;
            } else {
            }
        }
    }
    l2 = ((vader_struct_vader_bootstrap_EvaluatedPipeline_t*) l0)->f_resolver_diags;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_38: {
            if ((l4 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l4 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                vader_array_push((vader_array_t*) l1, vader_ref_box(l5));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_38;
            } else {
            }
        }
    }
    l2 = ((vader_struct_vader_bootstrap_EvaluatedPipeline_t*) l0)->f_typecheck_diags;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_66: {
            if ((l4 < l3)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l4 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l4);
                vader_array_push((vader_array_t*) l1, vader_ref_box(l5));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_66;
            } else {
            }
        }
    }
    l2 = ((vader_struct_vader_bootstrap_EvaluatedPipeline_t*) l0)->f_comptime_diags;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_94: {
            if ((l4 < l3)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l4 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                l5 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
                vader_array_push((vader_array_t*) l1, vader_ref_box(l5));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_94;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_bootstrap_lower_to_entry(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_bootstrap_prepare_evaluated_project(l0);
    vader_array_t* _a0_arr = vader_array_new(51u, 0u, 13u, 700u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_bootstrap_EvaluatedPipeline_t*) l1)->f_loaded;
    l4 = ((vader_struct_vader_bootstrap_EvaluatedPipeline_t*) l1)->f_typed;
    l5 = ((vader_struct_vader_bootstrap_EvaluatedPipeline_t*) l1)->f_evaluated;
    l3 = vader_lower_lower_project(l3, l4, l5, l2);
    l4 = ((vader_struct_vader_bootstrap_EvaluatedPipeline_t*) l1)->f_typed;
    l6 = ((vader_struct_vader_resolver_LoadedProject_t*) ((vader_struct_vader_bootstrap_EvaluatedPipeline_t*) l1)->f_loaded)->f_entry;
    l6 = vader_bootstrap_entry_main_name(l4, l6);
    l1 = vader_bootstrap_gather_pipeline_diags(l1);
    vader_struct_vader_bootstrap_LoweredEntry_t* _a1_obj = (vader_struct_vader_bootstrap_LoweredEntry_t*) vader_gc_alloc(sizeof(vader_struct_vader_bootstrap_LoweredEntry_t));
    vader_obj_header_init(_a1_obj, 485u);
    _a1_obj->f_lowered = l3;
    _a1_obj->f_entry = l6;
    _a1_obj->f_pre_diags = l1;
    _a1_obj->f_lower_diags = l2;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

int32_t vader_bootstrap_main(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    size_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    int32_t t4;
    vader_box_t* gc_roots[2] = { &l5, &t1 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l2, &l3, &t2, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if ((t0 < INT64_C(3))) {
        l1 = concat_2(2292u, 1u);
        std_io_write(INT32_C(1), l1);
        { vader_gc_top = gc_frame.prev; return INT32_C(1); }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(1) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) INT32_C(1)];
    l1 = t1.payload.s;
    if ((size_t) INT32_C(2) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) INT32_C(2)];
    l2 = t1.payload.s;
    t2 = std_path_to_posix(l2);
    t3 = std_path_to_path(t2);
    t2 = std_path_filename(t3);
    l3 = concat_2(t2, 429u);
    l5 = vader_bootstrap_emit_c_program(l1, l3);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return INT32_C(1); }
    }
    l4 = l5.payload.obj;
    t4 = vader_bootstrap_write_split_files(l2, l4);
    { int32_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_bootstrap_merge_diagnostics(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4, l5;
    int64_t t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(51u, 0u, 13u, 700u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_9;
            } else {
            }
        }
    }
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_37: {
            if ((l5 < l4)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                vader_array_push((vader_array_t*) l2, vader_ref_box(l6));
                t0 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t0;
                goto loop_37;
            } else {
            }
        }
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_bootstrap_module_name_from_file(vader_string_t l0) {
    vader_string_t t0 = 0;
    vader_string_t t1 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_path_to_posix(l0);
    t1 = std_path_to_path(t0);
    t0 = std_path_filename(t1);
    t1 = std_string_trim_suffix(t0, 432u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_bootstrap_prepare_evaluated_project(vader_string_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[7] = { &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l1 = (void*) _a0_arr;
    l1 = vader_resolver_load_project(l0, l1, vader_box_obj(0u, NULL));
    vader_array_t* _a1_arr = vader_array_new(51u, 0u, 13u, 700u);
    l2 = (void*) _a1_arr;
    l3 = vader_typecheck_check_project_with_bodies(l1, l2, false);
    l4 = vader_bootstrap_collect_body_diags(l3);
    l3 = vader_bootstrap_assemble_typed_project(l3);
    vader_array_t* _a2_arr = vader_array_new(51u, 0u, 13u, 700u);
    l5 = (void*) _a2_arr;
    l6 = vader_comptime_evaluate_project(l1, l3, l5);
    vader_comptime_vm_resolve_vm_required_decls(l1, l3, l6, l5);
    vader_struct_vader_bootstrap_EvaluatedPipeline_t* _a3_obj = (vader_struct_vader_bootstrap_EvaluatedPipeline_t*) vader_gc_alloc(sizeof(vader_struct_vader_bootstrap_EvaluatedPipeline_t));
    vader_obj_header_init(_a3_obj, 484u);
    _a3_obj->f_loaded = l1;
    _a3_obj->f_typed = l3;
    _a3_obj->f_evaluated = l6;
    _a3_obj->f_resolver_diags = l4;
    _a3_obj->f_typecheck_diags = l2;
    _a3_obj->f_comptime_diags = l5;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_bootstrap_write_out(vader_string_t l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = std_io_write_file_string(l0, l1);
    if (l2.tag == 388u) {
        t0 = l2.payload.obj;
        l3 = ((vader_struct_std_io_IOError_t*) t0)->f_msg;
        t1 = concat_4(1273u, l0, 1070u, l3);
        l3 = concat_2(t1, 1u);
        std_io_write(INT32_C(1), l3);
        { vader_gc_top = gc_frame.prev; return INT32_C(1); }
    }
    { vader_gc_top = gc_frame.prev; return INT32_C(0); }
    vader_gc_top = gc_frame.prev;
}

static int32_t vader_bootstrap_write_split_files(vader_string_t l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_string_t l6 = 0;
    size_t l4, l5;
    int32_t t0;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = concat_2(l0, 429u);
    l3 = ((vader_struct_vader_c_emit_CProgram_t*) l1)->f_header;
    t0 = vader_bootstrap_write_out(l2, l3);
    if (t0 != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(1); }
    }
    l2 = concat_2(l0, 419u);
    l3 = ((vader_struct_vader_c_emit_CProgram_t*) l1)->f_imports;
    t0 = vader_bootstrap_write_out(l2, l3);
    if (t0 != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(1); }
    }
    l2 = concat_2(l0, 428u);
    l3 = ((vader_struct_vader_c_emit_CProgram_t*) l1)->f_globals;
    t0 = vader_bootstrap_write_out(l2, l3);
    if (t0 != INT32_C(0)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(1); }
    }
    l4 = ((vader_array_t*) ((vader_struct_vader_c_emit_CProgram_t*) l1)->f_units)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_51: {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_CProgram_t*) l1)->f_unit_names);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l5];
                l2 = t1.payload.s;
                l3 = concat_4(l0, 385u, l2, 418u);
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_CProgram_t*) l1)->f_units);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l5];
                l6 = t1.payload.s;
                t0 = vader_bootstrap_write_out(l3, l6);
                if (t0 != INT32_C(0)) {
                    { vader_gc_top = gc_frame.prev; return INT32_C(1); }
                }
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_51;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return INT32_C(0); }
    vader_gc_top = gc_frame.prev;
}

