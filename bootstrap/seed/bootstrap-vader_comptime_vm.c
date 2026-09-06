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
    if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
    }
    return l0;
}

static vader_box_t vader_comptime_vm_array_to_comptime(void* l0, vader_box_t l1, void* l2) {
    vader_box_t l3 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null();
    void* l4 = NULL;
    void* l7 = NULL;
    size_t l5, l6, l8;
    vader_string_t l11 = 0;
    size_t t0;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[5] = { &l1, &l3, &l9, &l10, &t2 };
    void** gc_raw_roots[5] = { &l0, &l2, &l4, &l7, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_comptime_vm_array_element_type(l1);
    vader_array_t* _a0_arr = vader_array_new(128u, 0u, 13u, 1133u);
    l4 = (void*) _a0_arr;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            l6 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_length;
            if ((l5 < l6)) {
                l7 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_elements;
                t0 = ((vader_struct_vader_vm_ArrayVal_t*) l0)->f_offset;
                t1 = (t0 + l5);
                l8 = (size_t) (int64_t) t1;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                l9 = vader_comptime_vm_value_to_comptime(t2, l3, l2);
                if (l9.tag == 700u) {
                    t3 = l9.payload.obj;
                    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
                }
                l10 = l9;
                vader_array_push((vader_array_t*) l4, l10);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_8;
            } else {
            }
        }
    }
    l11 = vader_types_display_type_key(l3);
    vader_struct_vader_comptime_ArrayValue_t* _a2_obj = (vader_struct_vader_comptime_ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ArrayValue_t));
    vader_obj_header_init(_a2_obj, 678u);
    _a2_obj->f_elements = l4;
    _a2_obj->f_element_type_name = l11;
    t3 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t3); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_vm_find_callee_mangle(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4, l5;
    vader_string_t t0 = 0;
    bool t1;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l3, &l6 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = concat_2(241u, l1);
    l3 = ((vader_struct_vader_bytecode_BytecodeModule_t*) l0)->f_functions;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                t0 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_name;
                t1 = std_string_ends_with(t0, l2);
                if (t1) {
                    t0 = ((vader_struct_vader_bytecode_BcFunction_t*) l6)->f_name;
                    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_11;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
    vader_gc_top = gc_frame.prev;
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
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l1)->f_module_id;
    l5 = std_collections_get__string__Any(l3, l4);
    if (l5.tag == 684u) {
        t0 = l5.payload.obj;
        l3 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) t0)->f_comptime_decls;
        l6 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l1)->f_symbol_id;
        std_collections_put__i32__Any(l3, l6, l2);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_vm_int_scalar(int64_t l0, vader_string_t l1) {
    int64_t l2;
    bool l3;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1 == 2251u) {
        l3 = true;
    } else {
        l3 = l1 == 2232u;
    }
    if (l3) {
        l3 = true;
    } else {
        l3 = l1 == 2233u;
    }
    if (l3) {
        l2 = ((int64_t) (uint32_t) ((int32_t) (int64_t) l0));
    } else {
        l2 = l0;
    }
    t0 = vader_comptime_int_val_typed(l2, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_vm_prim_name(vader_box_t l0, vader_string_t l1) {
    void* l2;
    void* t0;
    vader_string_t t1;
    if (l0.tag == 925u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        return t1;
    }
    if (l0.tag == 917u) {
        l2 = l0.payload.obj;
        if (((vader_struct_vader_types_DistinctType_t*) l2)->f_backing.tag == 925u) {
            t0 = ((vader_struct_vader_types_DistinctType_t*) l2)->f_backing.payload.obj;
            t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
            return t1;
        }
        return l1;
    }
    return l1;
}

void vader_comptime_vm_resolve_vm_required_decls(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    size_t l7, l8, l26;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l15 = 0;
    vader_string_t l18 = 0;
    vader_box_t l12 = vader_box_null(), l20 = vader_box_null(), l21 = vader_box_null(), l23 = vader_box_null(), l25 = vader_box_null();
    size_t t0;
    int64_t t1;
    vader_string_t t2 = 0;
    bool t3;
    void* t4 = NULL;
    vader_box_t* gc_roots[5] = { &l12, &l20, &l21, &l23, &l25 };
    void** gc_raw_roots[16] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l9, &l13, &l14, &l16, &l17, &l19, &l22, &l24, &t4 };
    vader_string_t* gc_atom_roots[5] = { &l10, &l11, &l15, &l18, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_comptime_EvaluatedProject_t*) l2)->f_vm_required)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_arr = vader_array_new(51u, 0u, 13u, 700u);
    l4 = (void*) _a0_arr;
    l4 = vader_comptime_vm_stage_to_bytecode(l0, l1, l2, l4);
    l5 = vader_vm_prepare(l4);
    l6 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l2)->f_vm_required;
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_24: {
            if ((l8 < l7)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                l10 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l9)->f_callee_name;
                l11 = vader_comptime_vm_find_callee_mangle(l4, l10);
                if (l11 == 0u) {
                    t1 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t1;
                    goto loop_24;
                }
                l12 = vader_vm_exec_fn_value(l5, l11);
                if (l12.tag == 959u) {
                    l13 = l12.payload.obj;
                    t2 = ((vader_struct_vader_vm_Trap_t*) l13)->f_message;
                    t3 = vader_vm_is_impure_comptime_trap_message(t2);
                    if (t3) {
                        l14 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l9)->f_span;
                        l15 = ((vader_struct_vader_vm_Trap_t*) l13)->f_message;
                        l16 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(15), l14, l15);
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l16));
                    } else {
                        l17 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l9)->f_span;
                        l18 = ((vader_struct_vader_vm_Trap_t*) l13)->f_message;
                        l19 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(1), l17, l18);
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l19));
                    }
                    t1 = (l8 + INT64_C(1));
                    l8 = (size_t) (int64_t) t1;
                    goto loop_24;
                }
                if (l12.tag == 961u) {
                    t4 = l12.payload.obj;
                    l20 = ((vader_struct_vader_vm_ValueOk_t*) t4)->f_value;
                    l21 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l9)->f_decl_type;
                    l22 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l9)->f_span;
                    l23 = vader_comptime_vm_value_to_comptime(l20, l21, l22);
                    if (l23.tag == 700u) {
                        l24 = l23.payload.obj;
                        vader_array_push((vader_array_t*) l3, vader_ref_box(l24));
                        t1 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t1;
                        goto loop_24;
                    }
                    l25 = l23;
                    vader_comptime_vm_inject(l2, l9, l25);
                    l26 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l8 + l26);
                    l8 = (size_t) (int64_t) t1;
                    goto loop_24;
                }
                l26 = (size_t) (int64_t) INT64_C(1);
                t1 = (l8 + l26);
                l8 = (size_t) (int64_t) t1;
                goto loop_24;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_vm_stage_to_bytecode(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    size_t l6, l7;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    void* t3 = NULL;
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l8, &t2, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 9u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 169u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l2)->f_vm_required;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l7 < l6)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l7 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                l9 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l8)->f_module_id;
                t0 = std_core____Contains_contains__string(l4, l9);
                if (!(t0)) {
                    l10 = ((vader_struct_vader_comptime_VmRequiredDecl_t*) l8)->f_module_id;
                    vader_array_push((vader_array_t*) l4, vader_box_string(169u, l10));
                } else {
                }
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_9;
            } else {
            }
        }
    }
    t2 = vader_lower_lower_project_staged(l0, l1, l2, l4, l3);
    t3 = vader_lower_prune_unreachable_fns(t2, false);
    t2 = vader_midir_build_cfg_project(t3);
    t3 = vader_midir_eliminate_dead_cfg(t2);
    t2 = vader_midir_annotate_escape(t3);
    l4 = ((vader_struct_vader_midir_AnnotatedProject_t*) t2)->f_project;
    l5 = vader_bytecode_default_emit_options();
    t2 = vader_midir_emit_bytecode_from_cfg(l4, 1381u, l5);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_vm_unsupported(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = concat_3(1382u, l1, 174u);
    t0 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(0), l0, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_vm_value_to_comptime(vader_box_t l0, vader_box_t l1, void* l2) {
    int64_t l3;
    vader_string_t l4 = 0;
    double l5;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    uint32_t t4;
    vader_string_t t5 = 0;
    vader_box_t* gc_roots[3] = { &l0, &l1, &t2 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 946u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_vm_I32Val_t*) t0)->f_value;
        l3 = ((int64_t) (int32_t) t1);
        l4 = vader_comptime_vm_prim_name(l1, 1644u);
        t2 = vader_comptime_vm_int_scalar(l3, l4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 947u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_vm_I64Val_t*) t0)->f_value;
        l4 = vader_comptime_vm_prim_name(l1, 1666u);
        t2 = vader_comptime_vm_int_scalar(l3, l4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 939u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_vm_F64Val_t*) t0)->f_value;
        l4 = vader_comptime_vm_prim_name(l1, 1543u);
        t2 = vader_comptime_float_val_typed(l5, l4);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 935u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_vm_BoolVal_t*) t0)->f_value;
        vader_struct_vader_comptime_BoolValue_t* _a0_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
        vader_obj_header_init(_a0_obj, 679u);
        _a0_obj->f_value = t3;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 936u) {
        t0 = l0.payload.obj;
        t4 = ((vader_struct_vader_vm_CharVal_t*) t0)->f_value;
        vader_struct_vader_comptime_CharValue_t* _a1_obj = (vader_struct_vader_comptime_CharValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_CharValue_t));
        vader_obj_header_init(_a1_obj, 680u);
        _a1_obj->f_value = (uint32_t) (int32_t) ((int32_t) (uint32_t) t4);
        t0 = (void*) _a1_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 957u) {
        t0 = l0.payload.obj;
        t5 = ((vader_struct_vader_vm_StringVal_t*) t0)->f_value;
        t2 = vader_comptime_string_val(t5);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 950u) {
        vader_struct_vader_comptime_NullValue_t* _a2_obj = (vader_struct_vader_comptime_NullValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_NullValue_t));
        vader_obj_header_init(_a2_obj, 693u);
        t0 = (void*) _a2_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 934u) {
        t0 = l0.payload.obj;
        t2 = vader_comptime_vm_array_to_comptime(t0, l1, l2);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 958u) {
        t0 = vader_comptime_vm_unsupported(l2, 2111u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 940u) {
        t0 = vader_comptime_vm_unsupported(l2, 1614u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 960u) {
        t0 = vader_comptime_vm_unsupported(l2, 2179u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 938u) {
        t0 = vader_comptime_vm_unsupported(l2, 1485u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 951u) {
        t0 = vader_comptime_vm_unsupported(l2, 1639u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_comptime_vm$value_to_comptime");
    vader_gc_top = gc_frame.prev;
}

