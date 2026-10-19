#include "bootstrap.split.h"

static vader_box_t vader_comptime_vm_array_element_type(vader_box_t l0);
static vader_box_t vader_comptime_vm_array_to_comptime(void* l0, vader_box_t l1, void* l2);
static vader_string_t vader_comptime_vm_find_callee_mangle(void* l0, vader_string_t l1);
static void vader_comptime_vm_inject(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_comptime_vm_int_scalar(int64_t l0, vader_string_t l1);
static vader_string_t vader_comptime_vm_prim_name(vader_box_t l0, vader_string_t l1);
static void* vader_comptime_vm_stage_to_bytecode(void* l0, void* l1, void* l2, void* l3);
static void* vader_comptime_vm_unsupported(void* l0, vader_string_t l1);
static vader_box_t vader_comptime_vm_value_to_comptime(vader_box_t l0, vader_box_t l1, void* l2);

static vader_box_t vader_comptime_vm_array_element_type(vader_box_t l0) {
    void* t0;
    if (!(l0.tag == 1243u)) {
        return l0;
    }
    t0 = l0.payload.obj;
    return ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
}

static vader_box_t vader_comptime_vm_array_to_comptime(void* l0, vader_box_t l1, void* l2) {
    vader_box_t l3 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    void* l4 = NULL;
    int64_t l5, l6, l7;
    vader_string_t l10 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[5] = { &l1, &l3, &l8, &l9, &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_comptime_vm_array_element_type(l1);
    vader_array_t* _a0_arr = vader_array_new(234u, 0u, 13u, 1631u);
    l4 = (void*) _a0_arr;
    l5 = INT64_C(0);
    l6 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_length;
    while ((l5 < l6)) {
        t0 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
        l7 = vader_chk_add(i64, t0, l5);
        t1 = vader_vm_element_at(l0, l7);
        l8 = vader_comptime_vm_value_to_comptime(t1, l3, l2);
        if (l8.tag == 899u) {
            t2 = l8.payload.obj;
            { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = l8;
        vader_array_push((vader_array_t*) l4, l9);
        l5 = (l5 + INT64_C(1));
    }
    l10 = vader_types_display_type(l3);
    vader_struct_vader_comptime_ArrayValue_t* _a1_obj = (vader_struct_vader_comptime_ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ArrayValue_t));
    vader_obj_header_init(_a1_obj, 874u);
    _a1_obj->f_elements = l4;
    _a1_obj->f_element_type_name = l10;
    t2 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_comptime_vm_find_callee_mangle(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    size_t t0;
    vader_string_t t1 = 0;
    bool t2;
    void** gc_raw_roots[3] = { &l0, &l3, &l6 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = concat_2(205u, l1);
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
    t0 = ((vader_array_t*) l3)->length;
    l4 = (int64_t) (size_t) t0;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t1 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_name;
        t2 = std_string_ends_with(t1, l2);
        if (t2) {
            t1 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_name;
            { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

static void vader_comptime_vm_inject(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l1)->f_module_id;
    l5 = std_collections_MutableMap_std_core_Index_at__string__Any(l3, l4);
    if (l5.tag == 881u) {
        t0 = l5.payload.obj;
        l3 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) t0)->f_comptime_decls;
        l6 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l1)->f_symbol_id;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l3, l6, l2);
        t0 = l5.payload.obj;
        l3 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) t0)->f_routes;
        l6 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l1)->f_symbol_id;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l3, l6, vader_box_i32(288u, INT32_C(1)));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_comptime_vm_int_scalar(int64_t l0, vader_string_t l1) {
    bool l2;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1 == 2548u) {
        l2 = true;
    } else {
        l2 = l1 == 2527u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 2528u;
    }
    if (l2) {
        t0 = vader_comptime_int_val_typed(((int64_t) (uint32_t) ((int32_t) (int64_t) l0)), l1);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_int_val_typed(l0, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_comptime_vm_prim_name(vader_box_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_types_strip_distinct(l0);
    l2 = vader_types_primitive_name(t0);
    if (!(l2 == 0u)) {
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_comptime_vm_resolve_vm_required_decls(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    vader_box_t l5 = vader_box_null(), l14 = vader_box_null(), l22 = vader_box_null(), l23 = vader_box_null(), l25 = vader_box_null(), l27 = vader_box_null();
    int64_t l7, l8;
    vader_string_t l11 = 0;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    vader_string_t l17 = 0;
    vader_string_t l20 = 0;
    size_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    bool t3;
    vader_box_t* gc_roots[6] = { &l5, &l14, &l22, &l23, &l25, &l27 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l3, &l4, &l6, &l9, &l10, &l12, &l16, &l18, &l19, &l21, &l24, &l26, &t1,
    };
    vader_string_t* gc_atom_roots[6] = { &l11, &l13, &l15, &l17, &l20, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_comptime_EvaluatedProject_t*) l2)->f_vm_required)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_arr = vader_array_new(84u, 0u, 13u, 899u);
    l4 = (void*) _a0_arr;
    l4 = vader_comptime_vm_stage_to_bytecode(l0, l1, l2, l4);
    l5 = vader_vm_prepare(l4);
    if (l5.tag == 1294u) {
        l6 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l2)->f_vm_required;
        t0 = ((vader_array_t*) l6)->length;
        l7 = (int64_t) (size_t) t0;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l9 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
            l10 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l9)->f_span;
            t1 = l5.payload.obj;
            l11 = vader_vm_display_verify_error(t1);
            l12 = vader_diagnostics_comptime_error((uint8_t) 1, l10, l11);
            vader_array_push((vader_array_t*) l3, vader_ref_box(l12));
            l8 = (l8 + INT64_C(1));
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l2)->f_vm_required;
    t0 = ((vader_array_t*) l6)->length;
    l7 = (int64_t) (size_t) t0;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
        l9 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
        l11 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l9)->f_callee_name;
        l13 = vader_comptime_vm_find_callee_mangle(l4, l11);
        if (l13 == 0u) {
            l8 = (l8 + INT64_C(1));
            continue;
        }
        t1 = l5.payload.obj;
        l14 = vader_vm_exec_fn_value(t1, l13);
        if (l14.tag == 1291u) {
            t1 = l14.payload.obj;
            t2 = ((vader_struct_vader_vm_Trap_t*) t1)->f_message;
            t3 = vader_vm_is_impure_comptime_trap_message(t2);
            if (t3) {
                l10 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l9)->f_span;
                t1 = l14.payload.obj;
                l15 = ((vader_struct_vader_vm_Trap_t*) t1)->f_message;
                l12 = vader_diagnostics_comptime_error((uint8_t) 15, l10, l15);
                vader_array_push((vader_array_t*) l3, vader_ref_box(l12));
            } else {
                t1 = l14.payload.obj;
                t2 = ((vader_struct_vader_vm_Trap_t*) t1)->f_message;
                t3 = vader_vm_is_singleton_comptime_trap_message(t2);
                if (t3) {
                    l16 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l9)->f_span;
                    t1 = l14.payload.obj;
                    l17 = ((vader_struct_vader_vm_Trap_t*) t1)->f_message;
                    l18 = vader_diagnostics_comptime_error((uint8_t) 17, l16, l17);
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l18));
                } else {
                    l19 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l9)->f_span;
                    t1 = l14.payload.obj;
                    l20 = ((vader_struct_vader_vm_Trap_t*) t1)->f_message;
                    l21 = vader_diagnostics_comptime_error((uint8_t) 1, l19, l20);
                    vader_array_push((vader_array_t*) l3, vader_ref_box(l21));
                }
            }
            l8 = (l8 + INT64_C(1));
            continue;
        }
        if (l14.tag == 1293u) {
            t1 = l14.payload.obj;
            l22 = ((vader_struct_vader_vm_ValueOk_t*) t1)->f_value;
            l23 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l9)->f_decl_type;
            l24 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l9)->f_span;
            l25 = vader_comptime_vm_value_to_comptime(l22, l23, l24);
            if (l25.tag == 899u) {
                l26 = l25.payload.obj;
                vader_array_push((vader_array_t*) l3, vader_ref_box(l26));
                l8 = (l8 + INT64_C(1));
                continue;
            }
            l27 = l25;
            vader_comptime_vm_inject(l2, l9, l27);
        }
        l8 = (l8 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_comptime_vm_stage_to_bytecode(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l6, l7;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    size_t t0;
    bool t1;
    void* t2 = NULL;
    void* t3 = NULL;
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &t2, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 9u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 0u, 285u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l2)->f_vm_required;
    t0 = ((vader_array_t*) l5)->length;
    l6 = (int64_t) (size_t) t0;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l8)->f_module_id;
        t1 = std_core____Contains_contains__string(l4, l9);
        if (!(t1)) {
            l10 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l8)->f_module_id;
            vader_array_push((vader_array_t*) l4, vader_box_string(285u, l10));
        }
        l7 = (l7 + INT64_C(1));
    }
    t2 = vader_lower_lower_project_staged(l0, l1, l2, l4, l3);
    t3 = vader_lower_prune_unreachable_fns(t2, false);
    t2 = vader_midir_build_cfg_project(t3, l3);
    t3 = vader_midir_eliminate_dead_cfg(t2);
    t2 = vader_midir_annotate_escape(t3);
    l4 = ((vader_struct_vader_midir_AnnotatedProject_t*) t2)->f_project;
    l5 = vader_bytecode_default_emit_options();
    t2 = vader_midir_emit_bytecode_from_cfg(l4, 1561u, l5);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_vm_unsupported(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = concat_3(1562u, l1, 168u);
    t0 = vader_diagnostics_comptime_error((uint8_t) 0, l0, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_vm_value_to_comptime(vader_box_t l0, vader_box_t l1, void* l2) {
    vader_box_t l3 = vader_box_null();
    int64_t l4;
    vader_string_t l5 = 0;
    double l6;
    int32_t t0;
    bool t1;
    void* t2 = NULL;
    uint32_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[3] = { &l0, &l1, &l3 };
    void** gc_raw_roots[2] = { &l2, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 288u) {
        t0 = ((int32_t) l0.payload.i);
        l4 = ((int64_t) (int32_t) t0);
        l5 = vader_comptime_vm_prim_name(l1, 1856u);
        l3 = vader_comptime_vm_int_scalar(l4, l5);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 289u) {
        l4 = ((int64_t) l0.payload.i);
        l5 = vader_comptime_vm_prim_name(l1, 1878u);
        l3 = vader_comptime_vm_int_scalar(l4, l5);
    } else if ((l0.tag == 281u || l0.tag == 282u)) {
        l6 = ((double) l0.payload.f);
        l5 = vader_comptime_vm_prim_name(l1, 1731u);
        l3 = vader_comptime_float_val_typed(l6, l5);
    } else if (l0.tag == 283u) {
        t1 = l0.payload.b;
        vader_struct_vader_comptime_BoolValue_t* _a0_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
        vader_obj_header_init(_a0_obj, 876u);
        _a0_obj->f_value = t1;
        t2 = (void*) _a0_obj;
        l3 = vader_ref_box(t2);
    } else if (l0.tag == 284u) {
        t3 = ((uint32_t) l0.payload.i);
        vader_struct_vader_comptime_CharValue_t* _a1_obj = (vader_struct_vader_comptime_CharValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_CharValue_t));
        vader_obj_header_init(_a1_obj, 877u);
        _a1_obj->f_value = (uint32_t) (int32_t) ((int32_t) (uint32_t) t3);
        t2 = (void*) _a1_obj;
        l3 = vader_ref_box(t2);
    } else if (l0.tag == 285u) {
        t4 = l0.payload.s;
        l3 = vader_comptime_string_val(t4);
    } else if (l0.tag == 1275u) {
        t2 = (void*) &vader_data_40;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        l3 = vader_ref_box(t2);
    } else if (l0.tag == 1263u) {
        t2 = l0.payload.obj;
        l3 = vader_comptime_vm_array_to_comptime(t2, l1, l2);
    } else if (l0.tag == 1288u) {
        t2 = vader_comptime_vm_unsupported(l2, 2411u);
        l3 = vader_ref_box(t2);
    } else if (l0.tag == 1268u) {
        t2 = vader_comptime_vm_unsupported(l2, 1812u);
        l3 = vader_ref_box(t2);
    } else if (l0.tag == 1292u) {
        t2 = vader_comptime_vm_unsupported(l2, 2501u);
        l3 = vader_ref_box(t2);
    } else if (l0.tag == 1267u) {
        t2 = vader_comptime_vm_unsupported(l2, 1675u);
        l3 = vader_ref_box(t2);
    } else {
        if (!(l0.tag == 1276u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t2 = vader_comptime_vm_unsupported(l2, 1851u);
        l3 = vader_ref_box(t2);
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}
