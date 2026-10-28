#include "bootstrap.split.h"

static vader_box_t vader_pipeline_comptime__vm$array_element_type(vader_box_t l0);
static vader_box_t vader_pipeline_comptime__vm$array_to_comptime(void* l0, void* l1, vader_box_t l2, void* l3);
static bool vader_pipeline_comptime__vm$bake_decl(void* l0, vader_string_t l1, void* l2, vader_string_t l3, void* l4, void* l5);
static vader_box_t vader_pipeline_comptime__vm$baked_value(void* l0, void* l1);
static bool vader_pipeline_comptime__vm$enter_source_folder(vader_string_t l0, vader_string_t l1);
static void* vader_pipeline_comptime__vm$evaluate_layer(void* l0, void* l1, void* l2, void* l3, vader_string_t l4, void* l5);
static void* vader_pipeline_comptime__vm$field_at(vader_box_t l0, void* l1, int64_t l2, void* l3);
static void vader_pipeline_comptime__vm$inject(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_pipeline_comptime__vm$instance_type(vader_box_t l0, void* l1, int64_t l2);
static vader_box_t vader_pipeline_comptime__vm$int_scalar(int64_t l0, vader_string_t l1);
static bool vader_pipeline_comptime__vm$lays_out_as(vader_box_t l0, void* l1, int64_t l2);
static void vader_pipeline_comptime__vm$leave_source_folder(vader_string_t l0);
static vader_string_t vader_pipeline_comptime__vm$prim_name(vader_box_t l0, vader_string_t l1);
static void* vader_pipeline_comptime__vm$stage_to_cfg(void* l0, void* l1, void* l2, void* l3, void* l4);
static vader_box_t vader_pipeline_comptime__vm$staged_callee(void* l0, void* l1, int64_t l2);
static vader_box_t vader_pipeline_comptime__vm$struct_to_comptime(void* l0, void* l1, vader_box_t l2, void* l3);
static void* vader_pipeline_comptime__vm$unsupported(void* l0, vader_string_t l1);
static vader_box_t vader_pipeline_comptime__vm$value_to_comptime(void* l0, vader_box_t l1, vader_box_t l2, void* l3);

static vader_box_t vader_pipeline_comptime__vm$array_element_type(vader_box_t l0) {
    void* t0;
    if (!(l0.tag == 896u)) {
        return l0;
    }
    t0 = l0.payload.obj;
    return ((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element;
}

static vader_box_t vader_pipeline_comptime__vm$array_to_comptime(void* l0, void* l1, vader_box_t l2, void* l3) {
    vader_box_t l4 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    void* l5 = NULL;
    int64_t l6, l7, l8;
    vader_string_t l12 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[5] = { &l2, &l4, &l9, &l10, &l11 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_pipeline_comptime__vm$array_element_type(l2);
    vader_array_t* _a0_arr = vader_array_new(259u, 0u, 13u, 1935u);
    l5 = (void*) _a0_arr;
    l6 = INT64_C(0);
    l7 = ((vader_struct_vader_vm$ArrayVal_t*) l1)->f_length;
    while ((l6 < l7)) {
        t0 = ((vader_struct_vader_vm$ArrayVal_t*) l1)->f_offset;
        l8 = vader_chk_add(i64, t0, l6);
        l9 = vader_vm$element_at(l1, l8);
        l10 = vader_pipeline_comptime__vm$value_to_comptime(l0, l9, l4, l3);
        if (l10.tag == 1400u) {
            t1 = l10.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l11 = l10;
        vader_array_push_ref((vader_array_t*) l5, l11.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    l12 = vader_core_types$display_type(l4);
    vader_struct_vader_front_comptime$ArrayValue_t* _a1_obj = (vader_struct_vader_front_comptime$ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ArrayValue_t));
    vader_obj_header_init(_a1_obj, 1005u);
    _a1_obj->f_elements = l5;
    _a1_obj->f_element_type_name = l12;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_pipeline_comptime__vm$bake_decl(void* l0, vader_string_t l1, void* l2, vader_string_t l3, void* l4, void* l5) {
    vader_string_t l6 = 0;
    bool l7;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null();
    void* l9 = NULL;
    void* l11 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[2] = { &l8, &l10 };
    void** gc_raw_roots[7] = { &l0, &l2, &l4, &l5, &l9, &l11, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l3, &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span)->f_start)->f_file;
    l7 = vader_pipeline_comptime__vm$enter_source_folder(l3, l6);
    l8 = vader_vm$exec_comptime_value(l0, l1);
    if (l7) {
        vader_pipeline_comptime__vm$leave_source_folder(l3);
    }
    if (l8.tag == 1436u) {
        t0 = l8.payload.obj;
        t1 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
        t2 = vader_vm$is_comptime_refusal_message(t1);
        if (t2) {
            l9 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span;
            t0 = l8.payload.obj;
            l6 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
            l9 = vader_support_diagnostics$comptime_error((uint8_t) 8, l9, l6);
            vader_array_push_ref((vader_array_t*) l5, l9);
            { vader_gc_top = gc_frame.prev; return false; }
        }
        t0 = l8.payload.obj;
        t1 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
        t2 = vader_vm$is_singleton_comptime_trap_message(t1);
        if (t2) {
            l9 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span;
            t0 = l8.payload.obj;
            l6 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
            l9 = vader_support_diagnostics$comptime_error((uint8_t) 10, l9, l6);
            vader_array_push_ref((vader_array_t*) l5, l9);
        } else {
            l9 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span;
            t0 = l8.payload.obj;
            l6 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
            l9 = vader_support_diagnostics$comptime_error((uint8_t) 1, l9, l6);
            vader_array_push_ref((vader_array_t*) l5, l9);
        }
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (l8.tag == 1438u) {
        l9 = ((vader_struct_vader_front_typecheck$TypedProject_t*) ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l4)->f_typed)->f_modules;
        l6 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_module_id;
        l10 = std_collections$MutableMap$std_core$Index$at__string__Any(l9, l6);
        if (l10.tag == 0u) {
            l9 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span;
            l9 = vader_support_diagnostics$comptime_error((uint8_t) 0, l9, 2720u);
            vader_array_push_ref((vader_array_t*) l5, l9);
            { vader_gc_top = gc_frame.prev; return false; }
        }
        l9 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
        l11 = l10.payload.obj;
        vader_struct_vader_pipeline_comptime__vm$BakeScope_t* _a0_obj = (vader_struct_vader_pipeline_comptime__vm$BakeScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_comptime__vm$BakeScope_t));
        vader_obj_header_init(_a0_obj, 1397u);
        _a0_obj->f_layouts = l9;
        _a0_obj->f_program = l11;
        l9 = (void*) _a0_obj;
        t0 = l8.payload.obj;
        l8 = ((vader_struct_vader_vm$ValueOk_t*) t0)->f_value;
        l10 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_decl_type;
        l11 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span;
        l8 = vader_pipeline_comptime__vm$value_to_comptime(l9, l8, l10, l11);
        if (l8.tag == 1400u) {
            l9 = l8.payload.obj;
            vader_array_push_ref((vader_array_t*) l5, l9);
            { vader_gc_top = gc_frame.prev; return false; }
        }
        vader_pipeline_comptime__vm$inject(l4, l2, l8);
        { vader_gc_top = gc_frame.prev; return true; }
    }
    { vader_gc_top = gc_frame.prev; return true; }
}

static vader_box_t vader_pipeline_comptime__vm$baked_value(void* l0, void* l1) {
    void* l2;
    vader_string_t l3;
    vader_box_t l4;
    int32_t l5;
    vader_box_t t0;
    l2 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l0)->f_modules;
    l3 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l1)->f_module_id;
    l4 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l3);
    if (l4.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l2 = l4.payload.obj;
    l2 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l2)->f_comptime_decls;
    l5 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l1)->f_symbol_id;
    t0 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l5);
    return t0;
}

void vader_pipeline_comptime__vm$copy_baked_values(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int64_t l6, l7;
    uint64_t l8, l12;
    vader_box_t l9 = vader_box_null(), l13 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l9, &l13 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 4u, 343u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__u64__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__u64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__u64__Any_t));
    vader_obj_header_init(_a3_obj, 589u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    l4 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l0)->f_vm_required;
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l5 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
        l8 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l5)->f_span);
        l9 = vader_pipeline_comptime__vm$baked_value(l0, l5);
        std_collections$MutableMap$std_core$IndexSet$set_at__u64__Any(l3, l8, l9);
        l7 = (l7 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l1)->f_vm_required;
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        l8 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l5)->f_span);
        t0 = std_collections$MutableMap$std_core$Contains$contains__u64__Any(l3, l8);
        if (t0) {
            l12 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l5)->f_span);
            l13 = std_collections$MutableMap$std_core$Index$at__u64__Any(l3, l12);
            if (l13.tag == 0u) {
                l7 = (l7 + INT64_C(1));
                continue;
            }
            l9 = l13;
            vader_pipeline_comptime__vm$inject(l1, l5, l9);
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l10 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l5)->f_span;
        l11 = vader_support_diagnostics$comptime_error((uint8_t) 0, l10, 2709u);
        vader_array_push_ref((vader_array_t*) l2, l11);
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_pipeline_comptime__vm$enter_source_folder(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_front_resolver$dir_of(l1);
    if (l0 == 397u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (!(l2 == 0u)) {
        t0 = std_io$set_current_working_directory(l2);
        { bool __vret = t0.tag == 0u; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void* vader_pipeline_comptime__vm$evaluate_layer(void* l0, void* l1, void* l2, void* l3, vader_string_t l4, void* l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    vader_box_t l8 = vader_box_null(), l17 = vader_box_null();
    int64_t l10, l11, l16, l20;
    vader_string_t l14 = 0;
    vader_string_t l22 = 0;
    bool l19;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[3] = { &l8, &l17, &t1 };
    void** gc_raw_roots[14] = {
        &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l9, &l12, &l13, &l15, &l18, &l21, &t0,
    };
    vader_string_t* gc_atom_roots[3] = { &l4, &l14, &l22 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 14u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(217u, 0u, 13u, 1400u);
    l6 = (void*) _a0_arr;
    l6 = vader_pipeline_comptime__vm$stage_to_cfg(l0, l1, l2, l3, l6);
    l7 = vader_emit_bytecode$default_emit_options();
    l7 = vader_emit_bytecode$emit_bytecode_from_cfg(l6, 1781u, l7);
    l8 = vader_vm$prepare(l7);
    if (l8.tag == 1439u) {
        l9 = l3;
        l10 = ((vader_array_t*) l9)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l12 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
            l13 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l12)->f_span;
            t0 = l8.payload.obj;
            l14 = vader_vm$display_verify_error(t0);
            l15 = vader_support_diagnostics$comptime_error((uint8_t) 1, l13, l14);
            vader_array_push_ref((vader_array_t*) l5, l15);
            l11 = (l11 + INT64_C(1));
        }
        vader_array_t* _a2_arr = vader_array_new(111u, 0u, 13u, 1026u);
        t0 = (void*) _a2_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a3_arr = vader_array_new(111u, 0u, 13u, 1026u);
    l9 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(21u, 0u, 0u, 335u);
    l12 = (void*) _a4_arr;
    l13 = l3;
    l10 = ((vader_array_t*) l13)->length;
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l13);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l15 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
        l16 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l15)->f_callee_decl_id;
        l17 = vader_pipeline_comptime__vm$staged_callee(l6, l7, l16);
        if (l17.tag == 0u) {
            l11 = (l11 + INT64_C(1));
            continue;
        }
        l14 = l17.payload.s;
        vader_array_push_ref((vader_array_t*) l9, l15);
        vader_array_push_scalar((vader_array_t*) l12, vader_box_string(335u, l14));
        l11 = (l11 + INT64_C(1));
    }
    l6 = vader_midir$functions_run_from(l6, l12);
    vader_array_t* _a6_arr = vader_array_new(215u, 0u, 13u, 1398u);
    l7 = (void*) _a6_arr;
    l10 = ((vader_array_t*) l9)->length;
    vader_array_t* _a7_arr = vader_array_repeat((vader_array_t*) l7, (int64_t) l10);
    l7 = (void*) _a7_arr;
    l10 = INT64_C(0);
    l11 = ((vader_array_t*) l9)->length;
    while ((l10 < l11)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l13 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l10);
        vader_array_t* _a9_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l10)
        t1 = vader_array_box_slots(_a9_slotarr->buf)[_a9_slotarr->offset + (size_t) l10];
        l14 = t1.payload.s;
        vader_array_t* _a10_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l10)
        l15 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l10);
        vader_struct_vader_pipeline_comptime__vm$StagedDecl_t* _a11_obj = (vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_comptime__vm$StagedDecl_t));
        vader_obj_header_init(_a11_obj, 1398u);
        _a11_obj->f_decl = l13;
        _a11_obj->f_callee = l14;
        _a11_obj->f_reached = l15;
        l18 = (void*) _a11_obj;
        vader_array_push_ref((vader_array_t*) l7, l18);
        l10 = (l10 + INT64_C(1));
    }
    vader_array_t* _a12_arr = vader_array_new(215u, 0u, 13u, 1398u);
    l6 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(215u, 0u, 13u, 1398u);
    l9 = (void*) _a13_arr;
    l12 = l7;
    l10 = ((vader_array_t*) l12)->length;
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        l13 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l11);
        l15 = l7;
        vader_struct___lambda_env_vader_pipeline_comptime__vm_1_t* _a15_obj = (vader_struct___lambda_env_vader_pipeline_comptime__vm_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_comptime__vm_1_t));
        vader_obj_header_init(_a15_obj, 442u);
        _a15_obj->f_cap_0 = l13;
        l18 = (void*) _a15_obj;
        l19 = false;
        l16 = ((vader_array_t*) l15)->length;
        l20 = INT64_C(0);
        {
            while ((l20 < l16)) {
                vader_array_t* _a16_slotarr = ((vader_array_t*) l15);
                VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                l21 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l20);
                t2 = __lambda_vader_pipeline_comptime__vm_0(l18, l21);
                if (t2) {
                    l19 = true;
                    goto end_192;
                }
                l20 = (l20 + INT64_C(1));
            }
            l19 = false;
        } end_192: ;
        if (l19) {
            vader_array_push_ref((vader_array_t*) l9, l13);
        } else {
            vader_array_push_ref((vader_array_t*) l6, l13);
        }
        l11 = (l11 + INT64_C(1));
    }
    t3 = ((vader_array_t*) l6)->length;
    if (t3 == INT64_C(0)) {
        l6 = l9;
        vader_array_t* _a17_arr = vader_array_new(215u, 0u, 13u, 1398u);
        l9 = (void*) _a17_arr;
    }
    vader_array_t* _a18_arr = vader_array_new(21u, 0u, 0u, 335u);
    l7 = (void*) _a18_arr;
    l10 = ((vader_array_t*) l6)->length;
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a19_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l11)
        l12 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l11);
        l13 = l8.payload.obj;
        l14 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l12)->f_callee;
        l15 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l12)->f_decl;
        t2 = vader_pipeline_comptime__vm$bake_decl(l13, l14, l15, l4, l2, l5);
        if (!(t2)) {
            l22 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l12)->f_callee;
            vader_array_push_scalar((vader_array_t*) l7, vader_box_string(335u, l22));
        }
        l11 = (l11 + INT64_C(1));
    }
    vader_array_t* _a20_arr = vader_array_new(111u, 0u, 13u, 1026u);
    l6 = (void*) _a20_arr;
    l10 = ((vader_array_t*) l9)->length;
    l11 = INT64_C(0);
    while ((l11 < l10)) {
        vader_array_t* _a21_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        l12 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l11);
        l13 = l7;
        vader_struct___lambda_env_vader_pipeline_comptime__vm_3_t* _a22_obj = (vader_struct___lambda_env_vader_pipeline_comptime__vm_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_comptime__vm_3_t));
        vader_obj_header_init(_a22_obj, 443u);
        _a22_obj->f_cap_0 = l12;
        l15 = (void*) _a22_obj;
        l19 = false;
        l16 = ((vader_array_t*) l13)->length;
        l20 = INT64_C(0);
        {
            while ((l20 < l16)) {
                vader_array_t* _a23_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
                t1 = vader_array_box_slots(_a23_slotarr->buf)[_a23_slotarr->offset + (size_t) l20];
                l14 = t1.payload.s;
                t2 = __lambda_vader_pipeline_comptime__vm_2(l15, l14);
                if (t2) {
                    l19 = true;
                    goto end_322;
                }
                l20 = (l20 + INT64_C(1));
            }
            l19 = false;
        } end_322: ;
        if (!(l19)) {
            l18 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l12)->f_decl;
            vader_array_push_ref((vader_array_t*) l6, l18);
        }
        l11 = (l11 + INT64_C(1));
    }
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_comptime__vm$field_at(vader_box_t l0, void* l1, int64_t l2, void* l3) {
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null();
    void* l5 = NULL;
    int64_t l6;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l4, &l8 };
    void** gc_raw_roots[4] = { &l1, &l3, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_core_types$tuple_backing(l0);
    if (!(l4.tag == 0u)) {
        l5 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l6 = INT64_C(0);
        l6 = std_core$write_string_at(l5, l6, 977u);
        l6 = std_core$write_int(l5, l6, l2);
        l7 = std_core$finish_buffer(l5, l6);
        t0 = l4.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        vader_struct___Tuple_2_864b311187fca879_t* _a1_obj = (vader_struct___Tuple_2_864b311187fca879_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_864b311187fca879_t));
        vader_obj_header_init(_a1_obj, 351u);
        _a1_obj->f__0 = l7;
        _a1_obj->f__1 = l4;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l2);
    l7 = ((vader_struct_vader_core_bytecode$BcField_t*) t0)->f_name;
    l4 = vader_front_typecheck$declared_struct_field_type(l0, l7, l3);
    if (l4.tag == 0u) {
        t0 = (void*) &vader_data_22;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        l8 = vader_ref_box(t0);
        vader_struct___Tuple_2_864b311187fca879_t* _a4_obj = (vader_struct___Tuple_2_864b311187fca879_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_864b311187fca879_t));
        vader_obj_header_init(_a4_obj, 351u);
        _a4_obj->f__0 = l7;
        _a4_obj->f__1 = l8;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l4;
    vader_struct___Tuple_2_864b311187fca879_t* _a5_obj = (vader_struct___Tuple_2_864b311187fca879_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_864b311187fca879_t));
    vader_obj_header_init(_a5_obj, 351u);
    _a5_obj->f__0 = l7;
    _a5_obj->f__1 = l8;
    t0 = (void*) _a5_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_pipeline_comptime__vm$inject(void* l0, void* l1, vader_box_t l2) {
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
    l3 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l1)->f_module_id;
    l5 = std_collections$MutableMap$std_core$Index$at__string__Any(l3, l4);
    if (l5.tag == 1013u) {
        t0 = l5.payload.obj;
        l3 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) t0)->f_comptime_decls;
        l6 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l1)->f_symbol_id;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l3, l6, l2);
        t0 = l5.payload.obj;
        l3 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) t0)->f_routes;
        l6 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l1)->f_symbol_id;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__vader_front_comptime_ComptimeRoute(l3, l6, (uint8_t) 1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_pipeline_comptime__vm$instance_type(vader_box_t l0, void* l1, int64_t l2) {
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    void* l4 = NULL;
    int64_t l6, l7;
    bool t0;
    vader_box_t* gc_roots[3] = { &l0, &l3, &l5 };
    void** gc_raw_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_box_obj(0u, NULL);
    l5 = vader_core_types$union_variants(l0);
    if (l5.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(252u, 1u, 13u, 1776u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l0.payload.obj;
        l4 = (void*) _a0_arr;
    } else {
        l4 = l5.payload.obj;
    }
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        t0 = vader_pipeline_comptime__vm$lays_out_as(l5, l1, l2);
        if (t0) {
            if (!(l3.tag == 0u)) {
                { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
            }
            l3 = l5;
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_pipeline_comptime__vm$int_scalar(int64_t l0, vader_string_t l1) {
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_comptime$wrap_to_width(l0, l1);
    t1 = vader_front_comptime$int_val_typed(t0, l1);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_pipeline_comptime__vm$lays_out_as(vader_box_t l0, void* l1, int64_t l2) {
    int32_t l3, l4;
    void* l5;
    vader_box_t l6;
    void* t0;
    int32_t t1;
    int64_t t2;
    if (l0.tag == 910u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
        l4 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_symbol_id;
        return l3 == l4;
    }
    l6 = vader_core_types$tuple_backing(l0);
    if (l6.tag == 0u) {
        return false;
    }
    l5 = l6.payload.obj;
    t1 = ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_symbol_id;
    if ((t1 < INT32_C(0))) {
        t2 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) l5)->f_elements)->length;
        return t2 == l2;
    }
    return false;
}

static void vader_pipeline_comptime__vm$leave_source_folder(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    vader_string_t l2 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_io$set_current_working_directory(l0);
    if (!(l1.tag == 616u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = std_io$IOError$std_core$Error$message(t0);
    t1 = concat_4(1740u, l0, 1319u, l2);
    vader_host_std_abort$panic(t1);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_pipeline_comptime__vm$prim_name(vader_box_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$strip_distinct(l0);
    l2 = vader_core_types$primitive_name(t0);
    if (!(l2 == 0u)) {
        { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_pipeline_comptime__vm$resolve_vm_required_decls(void* l0, void* l1, void* l2, void* l3) {
    vader_string_t l4 = 0;
    void* l5 = NULL;
    int64_t t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = std_io$current_working_directory();
    l5 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l2)->f_vm_required;
    for (;;) {
        t0 = ((vader_array_t*) l5)->length;
        if ((t0 > INT64_C(0))) {
            l5 = vader_pipeline_comptime__vm$evaluate_layer(l0, l1, l2, l5, l4, l3);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_pipeline_comptime__vm$stage_to_cfg(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    int64_t l7, l8;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l9, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l10, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 9u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l5 = (void*) _a0_arr;
    l6 = l3;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l9 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        l10 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l9)->f_module_id;
        t0 = std_core$$array$Contains$contains__string(l5, l10);
        if (!(t0)) {
            l11 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l9)->f_module_id;
            vader_array_push_scalar((vader_array_t*) l5, vader_box_string(335u, l11));
        }
        l8 = (l8 + INT64_C(1));
    }
    t1 = vader_lower$lower_project_staged(l0, l1, l2, l5, l4);
    l5 = vader_lower_dce$prune_unreachable_fns(t1, false);
    vader_struct_vader_midir_pipeline$CfgPassOptions_t* _a2_obj = (vader_struct_vader_midir_pipeline$CfgPassOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_pipeline$CfgPassOptions_t));
    vader_obj_header_init(_a2_obj, 1380u);
    _a2_obj->f_verify = false;
    _a2_obj->f_prove_bounds = false;
    _a2_obj->f_instrumented = false;
    _a2_obj->f_plain_returns = true;
    l6 = (void*) _a2_obj;
    t1 = vader_midir_pipeline$build_optimised_cfg(l5, l6, l4);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_pipeline_comptime__vm$staged_callee(void* l0, void* l1, int64_t l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    int64_t l6, l7, l8, l9, l14, l15;
    bool l13;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    int64_t t3;
    bool t4;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l3, &l4, &l5, &l10, &l11, &l12, &l16, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
        t1 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l3 = ((vader_struct_vader_midir$CFGModule_t*) t2)->f_functions;
        l8 = ((vader_array_t*) l3)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            t3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$AssertDecl_t, f_id, ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l10)->f_origin)->f_decl.payload.obj);
            if (t3 == l2) {
                l11 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_functions;
                vader_struct___lambda_env_vader_pipeline_comptime__vm_5_t* _a3_obj = (vader_struct___lambda_env_vader_pipeline_comptime__vm_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_comptime__vm_5_t));
                vader_obj_header_init(_a3_obj, 444u);
                _a3_obj->f_cap_0 = l10;
                l12 = (void*) _a3_obj;
                l13 = false;
                l14 = ((vader_array_t*) l11)->length;
                l15 = INT64_C(0);
                {
                    while ((l15 < l14)) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        l16 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l15);
                        t4 = __lambda_vader_pipeline_comptime__vm_4(l12, l16);
                        if (t4) {
                            l13 = true;
                            goto end_58;
                        }
                        l15 = (l15 + INT64_C(1));
                    }
                    l13 = false;
                } end_58: ;
                if (l13) {
                    t1 = ((vader_struct_vader_midir$CFGFunction_t*) l10)->f_mangled;
                    { vader_box_t __vret = vader_box_string(335u, t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            l9 = (l9 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_pipeline_comptime__vm$struct_to_comptime(void* l0, void* l1, vader_box_t l2, void* l3) {
    void* l4 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    int32_t l5;
    vader_box_t l6 = vader_box_null(), l8 = vader_box_null(), l14 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null();
    int64_t l7, l12;
    vader_string_t l13 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[6] = { &l2, &l6, &l8, &l14, &l15, &l16 };
    void** gc_raw_roots[8] = { &l0, &l1, &l3, &l4, &l9, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_pipeline_comptime__vm$BakeScope_t*) l0)->f_layouts;
    l5 = ((vader_struct_vader_vm$StructVal_t*) l1)->f_type_id;
    l6 = vader_core_bytecode$struct_at(l4, l5);
    if (l6.tag == 0u) {
        t0 = vader_pipeline_comptime__vm$unsupported(l3, 2658u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l6.payload.obj;
    l7 = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l1)->f_fields)->length;
    l8 = vader_pipeline_comptime__vm$instance_type(l2, l4, l7);
    if (l8.tag == 0u) {
        t0 = vader_pipeline_comptime__vm$unsupported(l3, 2658u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l8;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 335u);
    l9 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 346u);
    l10 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 338u);
    l11 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 533u);
    _a3_obj->f_ekeys = l9;
    _a3_obj->f_evals = l10;
    _a3_obj->f_index = l11;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l9 = (void*) _a3_obj;
    l12 = INT64_C(0);
    while ((l12 < l7)) {
        l10 = ((vader_struct_vader_pipeline_comptime__vm$BakeScope_t*) l0)->f_program;
        l11 = vader_pipeline_comptime__vm$field_at(l6, l4, l12, l10);
        l13 = ((vader_struct___Tuple_2_864b311187fca879_t*) l11)->f__0;
        l8 = ((vader_struct___Tuple_2_864b311187fca879_t*) l11)->f__1;
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l12)
        l14 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l12];
        l15 = vader_pipeline_comptime__vm$value_to_comptime(l0, l14, l8, l3);
        if (l15.tag == 1400u) {
            t0 = l15.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l16 = l15;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l9, l13, l16);
        l12 = (l12 + INT64_C(1));
    }
    vader_struct_vader_front_comptime$StructValue_t* _a5_obj = (vader_struct_vader_front_comptime$StructValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$StructValue_t));
    vader_obj_header_init(_a5_obj, 1024u);
    _a5_obj->f_type = l6;
    _a5_obj->f_fields = l9;
    t0 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_comptime__vm$unsupported(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = concat_3(1782u, l1, 229u);
    t0 = vader_support_diagnostics$comptime_error((uint8_t) 0, l0, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_pipeline_comptime__vm$value_to_comptime(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    vader_box_t l4 = vader_box_null();
    int64_t l5;
    vader_string_t l6 = 0;
    double l7;
    void* l8 = NULL;
    int32_t t0;
    bool t1;
    void* t2 = NULL;
    uint32_t t3;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[3] = { &l1, &l2, &l4 };
    void** gc_raw_roots[4] = { &l0, &l3, &l8, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 338u) {
        t0 = ((int32_t) l1.payload.i);
        l5 = ((int64_t) (int32_t) t0);
        l6 = vader_pipeline_comptime__vm$prim_name(l2, 2085u);
        l4 = vader_pipeline_comptime__vm$int_scalar(l5, l6);
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 339u) {
        l5 = ((int64_t) l1.payload.i);
        l6 = vader_pipeline_comptime__vm$prim_name(l2, 2107u);
        l4 = vader_pipeline_comptime__vm$int_scalar(l5, l6);
    } else if ((l1.tag == 344u || l1.tag == 345u)) {
        l7 = ((double) l1.payload.f);
        l6 = vader_pipeline_comptime__vm$prim_name(l2, 1961u);
        l4 = vader_front_comptime$float_val_typed(l7, l6);
    } else if (l1.tag == 333u) {
        t1 = l1.payload.b;
        vader_struct_vader_front_comptime$BoolValue_t* _a0_obj = (vader_struct_vader_front_comptime$BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$BoolValue_t));
        vader_obj_header_init(_a0_obj, 1007u);
        _a0_obj->f_value = t1;
        t2 = (void*) _a0_obj;
        l4 = vader_ref_box(t2);
    } else if (l1.tag == 334u) {
        t3 = ((uint32_t) l1.payload.i);
        vader_struct_vader_front_comptime$CharValue_t* _a1_obj = (vader_struct_vader_front_comptime$CharValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$CharValue_t));
        vader_obj_header_init(_a1_obj, 1008u);
        _a1_obj->f_value = (uint32_t) (int32_t) ((int32_t) (uint32_t) t3);
        t2 = (void*) _a1_obj;
        l4 = vader_ref_box(t2);
    } else if (l1.tag == 335u) {
        t4 = l1.payload.s;
        l4 = vader_front_comptime$string_val(t4);
    } else if (l1.tag == 1420u) {
        t2 = (void*) &vader_data_42;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        l4 = vader_ref_box(t2);
    } else if (l1.tag == 1408u) {
        l8 = l1.payload.obj;
        l4 = vader_pipeline_comptime__vm$array_to_comptime(l0, l8, l2, l3);
    } else if (l1.tag == 1433u) {
        l8 = l1.payload.obj;
        l4 = vader_pipeline_comptime__vm$struct_to_comptime(l0, l8, l2, l3);
    } else if (l1.tag == 1413u) {
        t2 = vader_pipeline_comptime__vm$unsupported(l3, 2041u);
        l4 = vader_ref_box(t2);
    } else if (l1.tag == 1437u) {
        t2 = vader_pipeline_comptime__vm$unsupported(l3, 2758u);
        l4 = vader_ref_box(t2);
    } else if (l1.tag == 1412u) {
        t2 = vader_pipeline_comptime__vm$unsupported(l3, 1911u);
        l4 = vader_ref_box(t2);
    } else {
        if (!(l1.tag == 1421u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t2 = vader_pipeline_comptime__vm$unsupported(l3, 2080u);
        l4 = vader_ref_box(t2);
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}
