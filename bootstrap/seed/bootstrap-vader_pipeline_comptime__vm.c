#include "bootstrap.split.h"

static vader_box_t vader_pipeline_comptime__vm$array_instance_type(vader_box_t l0);
static vader_box_t vader_pipeline_comptime__vm$array_to_comptime(void* l0, void* l1, vader_box_t l2, void* l3);
static void* vader_pipeline_comptime__vm$bake_decl(void* l0, vader_string_t l1, void* l2, vader_string_t l3, void* l4, void* l5, void* l6);
static vader_box_t vader_pipeline_comptime__vm$baked_value(void* l0, void* l1);
static void* vader_pipeline_comptime__vm$counterpart(void* l0, void* l1);
static void* vader_pipeline_comptime__vm$decls_of(void* l0, vader_box_t l1);
static bool vader_pipeline_comptime__vm$enter_source_folder(vader_string_t l0, vader_string_t l1);
static void* vader_pipeline_comptime__vm$evaluate_layer(void* l0, void* l1, void* l2, void* l3, vader_string_t l4, void* l5);
static void* vader_pipeline_comptime__vm$field_at(vader_box_t l0, void* l1, int64_t l2, void* l3);
static void vader_pipeline_comptime__vm$inject(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_pipeline_comptime__vm$instance_type(vader_box_t l0, void* l1, int64_t l2);
static vader_box_t vader_pipeline_comptime__vm$int_scalar(int64_t l0, vader_string_t l1);
static bool vader_pipeline_comptime__vm$lays_out_as(vader_box_t l0, void* l1, int64_t l2);
static void vader_pipeline_comptime__vm$leave_source_folder(vader_string_t l0);
static void* vader_pipeline_comptime__vm$mangles_of(void* l0, void* l1);
static vader_string_t vader_pipeline_comptime__vm$prim_name(vader_box_t l0, vader_string_t l1);
static void* vader_pipeline_comptime__vm$read_at_compile_time(void* l0);
static vader_box_t vader_pipeline_comptime__vm$reentered_callees(void* l0, void* l1);
static void vader_pipeline_comptime__vm$report_cycle(void* l0, void* l1, void* l2);
static void* vader_pipeline_comptime__vm$retargeted_enum(void* l0, void* l1);
static void* vader_pipeline_comptime__vm$retargeted_fields(void* l0, void* l1);
static void* vader_pipeline_comptime__vm$retargeted_struct(void* l0, void* l1);
static void* vader_pipeline_comptime__vm$retargeted_types(void* l0, void* l1);
static void* vader_pipeline_comptime__vm$stage_to_cfg(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5);
static vader_box_t vader_pipeline_comptime__vm$staged_callee(void* l0, void* l1, int64_t l2);
static vader_box_t vader_pipeline_comptime__vm$struct_to_comptime(void* l0, void* l1, vader_box_t l2, void* l3);
static void* vader_pipeline_comptime__vm$unsupported(void* l0, vader_string_t l1);
static vader_box_t vader_pipeline_comptime__vm$value_to_comptime(void* l0, vader_box_t l1, vader_box_t l2, void* l3);

static vader_box_t vader_pipeline_comptime__vm$array_instance_type(vader_box_t l0) {
    vader_box_t l1 = vader_box_null(), l3 = vader_box_null();
    void* l2 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l1, &l3, &t0 };
    void** gc_raw_roots[2] = { &l2, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_box_obj(0u, NULL);
    l3 = vader_core_types$union_variants(l0);
    if (l3.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(449u, 1u, 13u, 2395u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l0.payload.obj;
        l2 = (void*) _a0_arr;
    } else {
        l2 = l3.payload.obj;
    }
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        l3 = vader_core_types$array_backing(t0);
        if (l3.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l6 = l3.payload.obj;
        if (!(l1.tag == 0u)) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l1 = vader_ref_box(l6);
        l5 = (l5 + INT64_C(1));
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_pipeline_comptime__vm$array_to_comptime(void* l0, void* l1, vader_box_t l2, void* l3) {
    void* l4 = NULL;
    void* l6 = NULL;
    vader_box_t l5 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null();
    int64_t l7, l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[5] = { &l2, &l5, &l9, &l10, &l11 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = vader_pipeline_comptime__vm$array_instance_type(l2);
    if (l5.tag == 0u) {
        t0 = vader_pipeline_comptime__vm$unsupported(l3, 1891u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l5.payload.obj;
    vader_array_t* _a0_arr = vader_array_new(456u, 0u, 13u, 2568u);
    l6 = (void*) _a0_arr;
    l7 = INT64_C(0);
    l8 = vader_vm$element_count(l1);
    while ((l7 < l8)) {
        l5 = vader_vm$element_at(l1, l7);
        l9 = ((vader_struct_vader_core_types$ArrayType_t*) l4)->f_element;
        l10 = vader_pipeline_comptime__vm$value_to_comptime(l0, l5, l9, l3);
        if (l10.tag == 1111u) {
            t0 = l10.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l11 = l10;
        vader_array_push_ref((vader_array_t*) l6, l11.payload.obj);
        l7 = (l7 + INT64_C(1));
    }
    vader_struct_vader_front_comptime$ArrayValue_t* _a1_obj = (vader_struct_vader_front_comptime$ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ArrayValue_t));
    vader_obj_header_init(_a1_obj, 1467u);
    _a1_obj->f_elements = l6;
    _a1_obj->f_type = vader_ref_box(l4);
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_comptime__vm$bake_decl(void* l0, vader_string_t l1, void* l2, vader_string_t l3, void* l4, void* l5, void* l6) {
    vader_string_t l7 = 0;
    bool l8;
    vader_box_t l9 = vader_box_null(), l10 = vader_box_null();
    void* l11 = NULL;
    void* l12 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[2] = { &l9, &l10 };
    void** gc_raw_roots[8] = { &l0, &l2, &l4, &l5, &l6, &l11, &l12, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l3, &l7, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span)->f_start)->f_file;
    l8 = vader_pipeline_comptime__vm$enter_source_folder(l3, l7);
    l9 = vader_vm$exec_comptime_value(l0, l1);
    if (l8) {
        vader_pipeline_comptime__vm$leave_source_folder(l3);
    }
    if (l9.tag == 1960u) {
        t0 = l9.payload.obj;
        l10 = vader_pipeline_comptime__vm$reentered_callees(((vader_struct_vader_vm$StackOverflow_t*) t0)->f_frames, l5);
        if (!(l10.tag == 0u)) {
            t0 = l10.payload.obj;
            vader_pipeline_comptime__vm$report_cycle(t0, l5, l6);
            vader_array_t* _a0_arr = vader_array_new(26u, 1u, 0u, 576u);
            vader_array_box_slots(_a0_arr->buf)[vader_array_offset(_a0_arr) + 0u] = vader_box_string(576u, l1);
            l11 = (void*) _a0_arr;
            l12 = l10.payload.obj;
            t0 = std_core$$array$Add$add__string(l11, l12);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l11 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span;
        t0 = l9.payload.obj;
        l7 = ((vader_struct_vader_vm$Trap_t*) ((vader_struct_vader_vm$StackOverflow_t*) t0)->f_trap)->f_message;
        l11 = toolchain_diagnostics$comptime_error((uint8_t) 1, l11, l7);
        vader_array_push_ref((vader_array_t*) l6, l11);
        vader_array_t* _a1_arr = vader_array_new(26u, 1u, 0u, 576u);
        vader_array_box_slots(_a1_arr->buf)[vader_array_offset(_a1_arr) + 0u] = vader_box_string(576u, l1);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l9.tag == 1965u) {
        t0 = l9.payload.obj;
        t1 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
        t2 = vader_vm$is_comptime_refusal_message(t1);
        if (t2) {
            l11 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span;
            t0 = l9.payload.obj;
            l7 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
            l11 = toolchain_diagnostics$comptime_error((uint8_t) 7, l11, l7);
            vader_array_push_ref((vader_array_t*) l6, l11);
            vader_array_t* _a2_arr = vader_array_new(26u, 1u, 0u, 576u);
            vader_array_box_slots(_a2_arr->buf)[vader_array_offset(_a2_arr) + 0u] = vader_box_string(576u, l1);
            t0 = (void*) _a2_arr;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l9.payload.obj;
        t1 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
        t2 = vader_vm$is_singleton_comptime_trap_message(t1);
        if (t2) {
            l11 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span;
            t0 = l9.payload.obj;
            l7 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
            l11 = toolchain_diagnostics$comptime_error((uint8_t) 9, l11, l7);
            vader_array_push_ref((vader_array_t*) l6, l11);
        } else {
            l11 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span;
            t0 = l9.payload.obj;
            l7 = ((vader_struct_vader_vm$Trap_t*) t0)->f_message;
            l11 = toolchain_diagnostics$comptime_error((uint8_t) 1, l11, l7);
            vader_array_push_ref((vader_array_t*) l6, l11);
        }
        vader_array_t* _a3_arr = vader_array_new(26u, 1u, 0u, 576u);
        vader_array_box_slots(_a3_arr->buf)[vader_array_offset(_a3_arr) + 0u] = vader_box_string(576u, l1);
        t0 = (void*) _a3_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l12 = ((vader_struct_vader_front_typecheck$TypedProject_t*) ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l4)->f_typed)->f_modules;
    l7 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_module_id;
    l10 = std_collections$Map$std_core$Index$at__string__Any(l12, l7);
    if (l10.tag == 0u) {
        l12 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span;
        l12 = toolchain_diagnostics$comptime_error((uint8_t) 0, l12, 3197u);
        vader_array_push_ref((vader_array_t*) l6, l12);
        vader_array_t* _a4_arr = vader_array_new(26u, 1u, 0u, 576u);
        vader_array_box_slots(_a4_arr->buf)[vader_array_offset(_a4_arr) + 0u] = vader_box_string(576u, l1);
        t0 = (void*) _a4_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = l10.payload.obj;
    vader_struct_vader_pipeline_comptime__vm$BakeScope_t* _a5_obj = (vader_struct_vader_pipeline_comptime__vm$BakeScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_comptime__vm$BakeScope_t));
    vader_obj_header_init(_a5_obj, 1914u);
    _a5_obj->f_layouts = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct_vader_vm$VmState_t*) l0)->f_bc)->f_types;
    _a5_obj->f_program = l11;
    l11 = (void*) _a5_obj;
    t0 = l9.payload.obj;
    l9 = ((vader_struct_vader_vm$ValueOk_t*) t0)->f_value;
    l10 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_decl_type;
    l12 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l2)->f_span;
    l9 = vader_pipeline_comptime__vm$value_to_comptime(l11, l9, l10, l12);
    if (!(l9.tag == 1111u)) {
        l10 = l9;
        vader_pipeline_comptime__vm$inject(l4, l2, l10);
        vader_array_t* _a6_arr = vader_array_new(26u, 0u, 0u, 576u);
        t0 = (void*) _a6_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l11 = l9.payload.obj;
    vader_array_push_ref((vader_array_t*) l6, l11);
    vader_array_t* _a7_arr = vader_array_new(26u, 1u, 0u, 576u);
    vader_array_box_slots(_a7_arr->buf)[vader_array_offset(_a7_arr) + 0u] = vader_box_string(576u, l1);
    t0 = (void*) _a7_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_pipeline_comptime__vm$baked_value(void* l0, void* l1) {
    void* l2;
    vader_string_t l3;
    vader_box_t l4;
    int32_t l5;
    vader_box_t t0;
    l2 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l0)->f_modules;
    l3 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l1)->f_module_id;
    l4 = std_collections$Map$std_core$Index$at__string__Any(l2, l3);
    if (l4.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l2 = l4.payload.obj;
    l2 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l2)->f_comptime_decls;
    l5 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l1)->f_symbol_id;
    t0 = std_collections$Map$std_core$Index$at__i32__Any(l2, l5);
    return t0;
}

void vader_pipeline_comptime__vm$copy_baked_values(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l14 = NULL;
    int64_t l6, l7;
    uint64_t l8, l12;
    vader_box_t l9 = vader_box_null(), l13 = vader_box_null(), l15 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[3] = { &l9, &l13, &l15 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l11, &l14 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(32u, 0u, 4u, 584u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 0u, 587u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 579u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$Map__u64__Any_t* _a3_obj = (vader_struct_std_collections$Map__u64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__u64__Any_t));
    vader_obj_header_init(_a3_obj, 963u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    l4 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l0)->f_vm_required;
    l6 = vader_array_length(((vader_array_t*) l4));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l5 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l7);
        l8 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l5)->f_span);
        l9 = vader_pipeline_comptime__vm$baked_value(l0, l5);
        std_collections$Map$std_core$IndexSet$set_at__u64__Any(l3, l8, l9);
        l7 = (l7 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l1)->f_vm_required;
    l6 = vader_array_length(((vader_array_t*) l4));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        l5 = vader_array_ref_load_obj(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l7);
        l8 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l5)->f_span);
        t0 = std_collections$Map$std_core$Contains$contains__u64__Any(l3, l8);
        if (t0) {
            l12 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l5)->f_span);
            l13 = std_collections$Map$std_core$Index$at__u64__Any(l3, l12);
            if (l13.tag == 0u) {
                l7 = (l7 + INT64_C(1));
                continue;
            }
            l9 = l13;
            l14 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l1)->f_typed;
            l15 = vader_pipeline_comptime__vm$retargeted(l9, l14);
            vader_pipeline_comptime__vm$inject(l1, l5, l15);
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l10 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l5)->f_span;
        l11 = toolchain_diagnostics$comptime_error((uint8_t) 0, l10, 3179u);
        vader_array_push_ref((vader_array_t*) l2, l11);
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_pipeline_comptime__vm$counterpart(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_defined_at;
    if (l3.tag == 0u) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l4 = ((vader_struct_vader_front_typecheck$TypedProject_t*) l1)->f_modules;
    l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module;
    l3 = std_collections$Map$std_core$Index$at__string__Any(l4, l5);
    if (l3.tag == 0u) {
        l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module_name;
        l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
        t0 = concat_5(3014u, l5, 1497u, l6, 1494u);
        vader_host_std_core$Intrinsic$panic(t0);
        vader_unreachable("a no-return call returned");
    } else {
        l4 = l3.payload.obj;
        l3 = vader_front_resolver$symbol_declared_at(((vader_struct_vader_front_typecheck$TypedProgram_t*) l4)->f_resolved, l2);
        if (l3.tag == 0u) {
            l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
            l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module_name;
            t0 = concat_5(3015u, l5, 1385u, l6, 1267u);
            vader_host_std_core$Intrinsic$panic(t0);
            vader_unreachable("a no-return call returned");
        } else {
            t1 = l3.payload.obj;
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_gc_top = gc_frame.prev;
}

static void* vader_pipeline_comptime__vm$decls_of(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l5, l6;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l4, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l0;
    vader_struct___lambda_env_vader_pipeline_comptime__vm_3_t* _a0_obj = (vader_struct___lambda_env_vader_pipeline_comptime__vm_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_comptime__vm_3_t));
    vader_obj_header_init(_a0_obj, 788u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(256u, 0u, 13u, 1489u);
    l4 = (void*) _a1_arr;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        t0 = __lambda_vader_pipeline_comptime__vm_2(l3, l7);
        if (t0) {
            l8 = l7;
            vader_array_push_ref((vader_array_t*) l4, l8);
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l0 == 471u) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    if (!(l2 == 0u)) {
        t0 = std_env$set_current_working_directory(l2);
        { bool __vret = t0.tag == 0u; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void* vader_pipeline_comptime__vm$evaluate_layer(void* l0, void* l1, void* l2, void* l3, vader_string_t l4, void* l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    bool l9, l11;
    vader_box_t l12 = vader_box_null(), l13 = vader_box_null();
    int64_t l14, l15, l20, l22;
    vader_string_t l18 = 0;
    vader_string_t l24 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[3] = { &l12, &l13, &t2 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l8, &l10, &l16, &l17, &l19, &l21, &l23, &t0,
    };
    vader_string_t* gc_atom_roots[3] = { &l4, &l18, &l24 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(82u, 0u, 13u, 1111u);
    l6 = (void*) _a0_arr;
    l7 = vader_pipeline_comptime__vm$read_at_compile_time(l3);
    l6 = vader_pipeline_comptime__vm$stage_to_cfg(l0, l1, l2, l3, l7, l6);
    l8 = vader_emit_bytecode$default_emit_options();
    l9 = ((vader_struct_vader_emit_bytecode$EmitOptions_t*) l8)->f_optimize;
    l10 = vader_pipeline_comptime__vm$mangles_of(l6, l7);
    l11 = ((vader_struct_vader_emit_bytecode$EmitOptions_t*) l8)->f_want_debug;
    vader_struct_vader_emit_bytecode$EmitOptions_t* _a1_obj = (vader_struct_vader_emit_bytecode$EmitOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$EmitOptions_t));
    vader_obj_header_init(_a1_obj, 1379u);
    _a1_obj->f_optimize = l9;
    _a1_obj->f_keep_mangles = l10;
    _a1_obj->f_want_debug = l11;
    l7 = (void*) _a1_obj;
    l7 = vader_emit_bytecode$emit_bytecode_from_cfg(l6, 2179u, l7);
    l12 = vader_vm$prepare(l7);
    l13 = l12;
    if (l12.tag == 1968u) {
        l10 = l3;
        l14 = vader_array_length(((vader_array_t*) l10));
        l15 = INT64_C(0);
        while ((l15 < l14)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l16 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l15);
            l17 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l16)->f_span;
            t0 = l13.payload.obj;
            l18 = vader_vm$display_verify_error(t0);
            l19 = toolchain_diagnostics$comptime_error((uint8_t) 1, l17, l18);
            vader_array_push_ref((vader_array_t*) l5, l19);
            l15 = (l15 + INT64_C(1));
        }
        vader_array_t* _a3_arr = vader_array_new(256u, 0u, 13u, 1489u);
        t0 = (void*) _a3_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l12.payload.obj;
    vader_array_t* _a4_arr = vader_array_new(256u, 0u, 13u, 1489u);
    l10 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(26u, 0u, 0u, 576u);
    l16 = (void*) _a5_arr;
    l17 = l3;
    l14 = vader_array_length(((vader_array_t*) l17));
    l15 = INT64_C(0);
    while ((l15 < l14)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l17);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        l19 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l15);
        l20 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l19)->f_callee_decl_id;
        l12 = vader_pipeline_comptime__vm$staged_callee(l6, l7, l20);
        if (l12.tag == 0u) {
            l15 = (l15 + INT64_C(1));
            continue;
        }
        l18 = l12.payload.s;
        vader_array_push_ref((vader_array_t*) l10, l19);
        vader_array_push_scalar((vader_array_t*) l16, vader_box_string(576u, l18));
        l15 = (l15 + INT64_C(1));
    }
    l6 = vader_midir$functions_run_from(l6, l16);
    t1 = vader_array_length(((vader_array_t*) l10));
    vader_array_t* _a7_arr = vader_array_reserve(407u, (int64_t) t1, 13u, 1915u);
    l7 = (void*) _a7_arr;
    l14 = INT64_C(0);
    l15 = vader_array_length(((vader_array_t*) l10));
    while ((l14 < l15)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l17 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l14);
        vader_array_t* _a9_slotarr = ((vader_array_t*) l16);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l14)
        t2 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l14];
        l18 = t2.payload.s;
        vader_array_t* _a10_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l14)
        l19 = vader_array_ref_load_obj(_a10_slotarr->buf, vader_array_offset(_a10_slotarr) + (size_t) l14);
        vader_struct_vader_pipeline_comptime__vm$StagedDecl_t* _a11_obj = (vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_comptime__vm$StagedDecl_t));
        vader_obj_header_init(_a11_obj, 1915u);
        _a11_obj->f_decl = l17;
        _a11_obj->f_callee = l18;
        _a11_obj->f_reached = l19;
        l21 = (void*) _a11_obj;
        vader_array_push_ref((vader_array_t*) l7, l21);
        l14 = (l14 + INT64_C(1));
    }
    vader_array_t* _a12_arr = vader_array_new(407u, 0u, 13u, 1915u);
    l6 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(407u, 0u, 13u, 1915u);
    l10 = (void*) _a13_arr;
    l16 = l7;
    l14 = vader_array_length(((vader_array_t*) l16));
    l15 = INT64_C(0);
    while ((l15 < l14)) {
        vader_array_t* _a14_slotarr = ((vader_array_t*) l16);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        l17 = vader_array_ref_load_obj(_a14_slotarr->buf, vader_array_offset(_a14_slotarr) + (size_t) l15);
        l19 = l7;
        vader_struct___lambda_env_vader_pipeline_comptime__vm_5_t* _a15_obj = (vader_struct___lambda_env_vader_pipeline_comptime__vm_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_comptime__vm_5_t));
        vader_obj_header_init(_a15_obj, 789u);
        _a15_obj->f_cap_0 = l17;
        l21 = (void*) _a15_obj;
        l9 = false;
        l20 = vader_array_length(((vader_array_t*) l19));
        l22 = INT64_C(0);
        {
            while ((l22 < l20)) {
                vader_array_t* _a16_slotarr = ((vader_array_t*) l19);
                VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
                l23 = vader_array_ref_load_obj(_a16_slotarr->buf, vader_array_offset(_a16_slotarr) + (size_t) l22);
                t3 = __lambda_vader_pipeline_comptime__vm_4(l21, l23);
                if (t3) {
                    l9 = true;
                    goto end_211;
                }
                l22 = (l22 + INT64_C(1));
            }
            l9 = false;
        } end_211: ;
        if (l9) {
            vader_array_push_ref((vader_array_t*) l10, l17);
        } else {
            vader_array_push_ref((vader_array_t*) l6, l17);
        }
        l15 = (l15 + INT64_C(1));
    }
    t1 = vader_array_length(((vader_array_t*) l6));
    if (t1 == INT64_C(0)) {
        l6 = l10;
        vader_array_t* _a17_arr = vader_array_new(407u, 0u, 13u, 1915u);
        l10 = (void*) _a17_arr;
    }
    vader_array_t* _a18_arr = vader_array_new(26u, 0u, 0u, 576u);
    l16 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(33u, 0u, 0u, 587u);
    l17 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(27u, 0u, 7u, 579u);
    l19 = (void*) _a20_arr;
    vader_struct_std_collections$Map__string__Any_t* _a21_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a21_obj, 894u);
    _a21_obj->f_ekeys = l16;
    _a21_obj->f_evals = l17;
    _a21_obj->f_index = l19;
    _a21_obj->f_mask = INT64_C(0);
    _a21_obj->f_grow_at = INT64_C(0);
    _a21_obj->f_size = INT64_C(0);
    _a21_obj->f_tombs = INT64_C(0);
    l16 = (void*) _a21_obj;
    l14 = vader_array_length(((vader_array_t*) l7));
    l15 = INT64_C(0);
    while ((l15 < l14)) {
        vader_array_t* _a22_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
        l17 = vader_array_ref_load_obj(_a22_slotarr->buf, vader_array_offset(_a22_slotarr) + (size_t) l15);
        l18 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l17)->f_callee;
        l19 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l17)->f_decl;
        std_collections$Map$std_core$IndexSet$set_at__string__Any(l16, l18, vader_ref_box(l19));
        l15 = (l15 + INT64_C(1));
    }
    vader_array_t* _a23_arr = vader_array_new(26u, 0u, 0u, 576u);
    l7 = (void*) _a23_arr;
    l14 = vader_array_length(((vader_array_t*) l6));
    l15 = INT64_C(0);
    while ((l15 < l14)) {
        vader_array_t* _a24_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l15)
        l17 = vader_array_ref_load_obj(_a24_slotarr->buf, vader_array_offset(_a24_slotarr) + (size_t) l15);
        l18 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l17)->f_callee;
        t3 = std_core$$array$Contains$contains__string(l7, l18);
        if (t3) {
            l15 = (l15 + INT64_C(1));
            continue;
        }
        l24 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l17)->f_callee;
        l19 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l17)->f_decl;
        l21 = vader_pipeline_comptime__vm$bake_decl(l8, l24, l19, l4, l2, l16, l5);
        vader_array_push_all((vader_array_t*) l7, (vader_array_t*) l21);
        l15 = (l15 + INT64_C(1));
    }
    vader_array_t* _a25_arr = vader_array_new(256u, 0u, 13u, 1489u);
    l6 = (void*) _a25_arr;
    l8 = l10;
    l14 = vader_array_length(((vader_array_t*) l8));
    l15 = INT64_C(0);
    while ((l15 < l14)) {
        vader_array_t* _a26_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
        l10 = vader_array_ref_load_obj(_a26_slotarr->buf, vader_array_offset(_a26_slotarr) + (size_t) l15);
        l16 = l7;
        vader_struct___lambda_env_vader_pipeline_comptime__vm_7_t* _a27_obj = (vader_struct___lambda_env_vader_pipeline_comptime__vm_7_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_comptime__vm_7_t));
        vader_obj_header_init(_a27_obj, 790u);
        _a27_obj->f_cap_0 = l10;
        l17 = (void*) _a27_obj;
        l9 = false;
        l20 = vader_array_length(((vader_array_t*) l16));
        l22 = INT64_C(0);
        {
            while ((l22 < l20)) {
                vader_array_t* _a28_slotarr = ((vader_array_t*) l16);
                VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                t2 = vader_array_box_slots(_a28_slotarr->buf)[vader_array_offset(_a28_slotarr) + (size_t) l22];
                l18 = t2.payload.s;
                t3 = __lambda_vader_pipeline_comptime__vm_6(l17, l18);
                if (t3) {
                    l9 = true;
                    goto end_393;
                }
                l22 = (l22 + INT64_C(1));
            }
            l9 = false;
        } end_393: ;
        if (!(l9)) {
            l19 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l10)->f_decl;
            vader_array_push_ref((vader_array_t*) l6, l19);
        }
        l15 = (l15 + INT64_C(1));
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
        l6 = std_core$write_string_at(l5, l6, 1202u);
        l6 = std_core$write_int(l5, l6, l2);
        l7 = std_core$finish_buffer(l5, l6);
        t0 = l4.payload.obj;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
        vader_struct___Tuple_2_864b311187fca879_t* _a1_obj = (vader_struct___Tuple_2_864b311187fca879_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_864b311187fca879_t));
        vader_obj_header_init(_a1_obj, 596u);
        _a1_obj->f__0 = l7;
        _a1_obj->f__1 = l4;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_core_bytecode$BcStruct_t*) l1)->f_fields);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l2);
    l7 = ((vader_struct_vader_core_bytecode$BcField_t*) t0)->f_name;
    l4 = vader_front_typecheck$declared_struct_field_type(l0, l7, l3);
    if (l4.tag == 0u) {
        t0 = (void*) &vader_data_45;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) INT64_C(0));
        l8 = vader_ref_box(t0);
        vader_struct___Tuple_2_864b311187fca879_t* _a4_obj = (vader_struct___Tuple_2_864b311187fca879_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_864b311187fca879_t));
        vader_obj_header_init(_a4_obj, 596u);
        _a4_obj->f__0 = l7;
        _a4_obj->f__1 = l8;
        t0 = (void*) _a4_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l4;
    vader_struct___Tuple_2_864b311187fca879_t* _a5_obj = (vader_struct___Tuple_2_864b311187fca879_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_2_864b311187fca879_t));
    vader_obj_header_init(_a5_obj, 596u);
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
    l5 = std_collections$Map$std_core$Index$at__string__Any(l3, l4);
    if (l5.tag == 1477u) {
        t0 = l5.payload.obj;
        l3 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) t0)->f_comptime_decls;
        l6 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l1)->f_symbol_id;
        std_collections$Map$std_core$IndexSet$set_at__i32__Any(l3, l6, l2);
        t0 = l5.payload.obj;
        l3 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) t0)->f_routes;
        l6 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l1)->f_symbol_id;
        std_collections$Map$std_core$IndexSet$set_at__i32__vader_front_comptime_ComptimeRoute(l3, l6, (uint8_t) 1);
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
        vader_array_t* _a0_arr = vader_array_new(449u, 1u, 13u, 2395u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = l0.payload.obj;
        l4 = (void*) _a0_arr;
    } else {
        l4 = l5.payload.obj;
    }
    l6 = vader_array_length(((vader_array_t*) l4));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
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
    if (l0.tag == 1363u) {
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
        t2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) l5)->f_elements));
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
    l1 = std_env$set_current_working_directory(l0);
    if (!(l1.tag == 1004u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l1.payload.obj;
    l2 = std_io$IOError$std_core$Error$message(t0);
    t1 = concat_4(2132u, l0, 1627u, l2);
    vader_host_std_core$Intrinsic$panic(t1);
    vader_unreachable("a no-return call returned");
    vader_gc_top = gc_frame.prev;
}

static void* vader_pipeline_comptime__vm$mangles_of(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    int64_t l6, l7, l8, l9, l11;
    vader_string_t l12 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    void* t3 = NULL;
    bool t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l12, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l2 = (void*) _a0_arr;
    t0 = vader_array_length(((vader_array_t*) l1));
    if (t0 == INT64_C(0)) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections$Map__string__vader_midir_CFGModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$Map__string__vader_midir_CFGModule_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__string__vader_midir_CFGModule_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t1 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l6];
        t2 = t1.payload.s;
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        t3 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        l3 = ((vader_struct_vader_midir$CFGModule_t*) t3)->f_functions;
        l8 = vader_array_length(((vader_array_t*) l3));
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l10 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l9);
            l11 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$AssertDecl_t, f_id, ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l10)->f_origin)->f_decl.payload.obj);
            t4 = std_core$$array$Contains$contains__i64(l1, l11);
            if (t4) {
                l12 = ((vader_struct_vader_midir$CFGFunction_t*) l10)->f_mangled;
                vader_array_push_scalar((vader_array_t*) l2, vader_box_string(576u, l12));
            }
            l9 = (l9 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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

static void* vader_pipeline_comptime__vm$read_at_compile_time(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4, l6;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = l0;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 8u, 580u);
    l2 = (void*) _a0_arr;
    l3 = vader_array_length(((vader_array_t*) l1));
    l4 = INT64_C(0);
    vader_array_t* _pc9_hdr = (vader_array_t*) l2;
    size_t _pc9_len = vader_array_length(_pc9_hdr);
    size_t _pc9_cap = vader_array_is_borrowed(_pc9_hdr) ? (size_t) 0 : vader_array_capacity(_pc9_hdr);
    void* _pc9_slots = _pc9_hdr->buf->slots;
    for (;;) {
        if ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l5 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l4);
            t0 = __lambda_vader_pipeline_comptime__vm_8(l5);
            if (t0) {
                l6 = __lambda_vader_pipeline_comptime__vm_9(l5);
                if (VADER_LIKELY(_pc9_len < _pc9_cap)) {
                    ((int64_t*) _pc9_slots)[_pc9_len] = (int64_t) (l6);
                    _pc9_len += 1;
                } else {
                    vader_array_set_length(_pc9_hdr, _pc9_len);
                    if (_pc9_hdr->buf->length < _pc9_len) {
                        _pc9_hdr->buf->length = _pc9_len;
                    }
                    vader_array_push_i64((vader_array_t*) l2, l6);
                    _pc9_hdr = (vader_array_t*) l2;
                    _pc9_len = vader_array_length(_pc9_hdr);
                    _pc9_cap = vader_array_is_borrowed(_pc9_hdr) ? (size_t) 0 : vader_array_capacity(_pc9_hdr);
                    _pc9_slots = _pc9_hdr->buf->slots;
                }
            }
            l4 = (l4 + INT64_C(1));
            continue;
        }
        vader_array_set_length(_pc9_hdr, _pc9_len);
        if (_pc9_hdr->buf->length < _pc9_len) {
            _pc9_hdr->buf->length = _pc9_len;
        }
        break;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_pipeline_comptime__vm$reentered_callees(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    int64_t l5, l6, l10, l11, l13, l14;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_box_t l9 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[2] = { &l9, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l12 };
    vader_string_t* gc_atom_roots[5] = { &l7, &l8, &l15, &l16, &l17 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 8u, 580u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 579u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__i64_t* _a3_obj = (vader_struct_std_collections$Map__string__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__i64_t));
    vader_obj_header_init(_a3_obj, 903u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    l5 = INT64_C(0);
    l6 = vader_array_length(((vader_array_t*) l0));
    while ((l5 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l5];
        l7 = t0.payload.s;
        t1 = std_collections$Map$std_core$Contains$contains__string__Any(l1, l7);
        if (t1) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            t0 = vader_array_box_slots(_a5_slotarr->buf)[vader_array_offset(_a5_slotarr) + (size_t) l5];
            l8 = t0.payload.s;
            l9 = std_collections$Map$std_core$Index$at__string__i64(l2, l8);
            if (l9.tag == 0u) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l0);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                t0 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l5];
                l17 = t0.payload.s;
                std_collections$Map$std_core$IndexSet$set_at__string__i64(l2, l17, l5);
                l5 = (l5 + INT64_C(1));
                continue;
            }
            l10 = ((int64_t) l9.payload.i);
            l11 = (l5 + INT64_C(1));
            vader_array_t* _a7_arr = vader_array_slice((vader_array_t*) l0, (int64_t) l10, (int64_t) l11);
            l3 = (void*) _a7_arr;
            vader_struct___lambda_env_vader_pipeline_comptime__vm_15_t* _a8_obj = (vader_struct___lambda_env_vader_pipeline_comptime__vm_15_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_comptime__vm_15_t));
            vader_obj_header_init(_a8_obj, 787u);
            _a8_obj->f_cap_0 = l1;
            l4 = (void*) _a8_obj;
            vader_array_t* _a9_arr = vader_array_new(26u, 0u, 0u, 576u);
            l12 = (void*) _a9_arr;
            l13 = vader_array_length(((vader_array_t*) l3));
            l14 = INT64_C(0);
            while ((l14 < l13)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                t0 = vader_array_box_slots(_a10_slotarr->buf)[vader_array_offset(_a10_slotarr) + (size_t) l14];
                l15 = t0.payload.s;
                t1 = __lambda_vader_pipeline_comptime__vm_14(l4, l15);
                if (t1) {
                    l16 = l15;
                    vader_array_push_scalar((vader_array_t*) l12, vader_box_string(576u, l16));
                }
                l14 = (l14 + INT64_C(1));
            }
            { vader_box_t __vret = vader_ref_box(l12); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_pipeline_comptime__vm$report_cycle(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    vader_string_t l4 = 0;
    vader_string_t l11 = 0;
    vader_box_t l5 = vader_box_null();
    int64_t l8, l9;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l6, &l7, &l10 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0)];
    l4 = t0.payload.s;
    l5 = std_collections$Map$std_core$Index$at__string__Any(l1, l4);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l5.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(26u, 0u, 0u, 576u);
    l6 = (void*) _a1_arr;
    l7 = l0;
    l8 = vader_array_length(((vader_array_t*) l7));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_box_slots(_a2_slotarr->buf)[vader_array_offset(_a2_slotarr) + (size_t) l9];
        l4 = t0.payload.s;
        l5 = std_collections$Map$std_core$Index$at__string__Any(l1, l4);
        if (l5.tag == 0u) {
            l9 = (l9 + INT64_C(1));
            continue;
        }
        l10 = l5.payload.obj;
        l11 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l10)->f_name;
        vader_array_push_scalar((vader_array_t*) l6, vader_box_string(576u, l11));
        l9 = (l9 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l3)->f_span;
    l4 = vader_front_comptime$display_cycle(l6);
    l3 = toolchain_diagnostics$comptime_error((uint8_t) 4, l3, l4);
    vader_array_push_ref((vader_array_t*) l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_pipeline_comptime__vm$resolve_vm_required_decls(void* l0, void* l1, void* l2, vader_box_t l3, void* l4) {
    vader_string_t l5 = 0;
    void* l6 = NULL;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = std_env$current_working_directory();
    l6 = vader_pipeline_comptime__vm$decls_of(((vader_struct_vader_front_comptime$EvaluatedProject_t*) l2)->f_vm_required, l3);
    for (;;) {
        t0 = vader_array_length(((vader_array_t*) l6));
        if ((t0 > INT64_C(0))) {
            l6 = vader_pipeline_comptime__vm$evaluate_layer(l0, l1, l2, l6, l5, l4);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

vader_box_t vader_pipeline_comptime__vm$retargeted(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l8 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l2, &l8, &t2 };
    void** gc_raw_roots[5] = { &l1, &l3, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1467u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_front_comptime$ArrayValue_t*) t0)->f_elements;
        vader_struct___lambda_env_vader_pipeline_comptime__vm_1_t* _a0_obj = (vader_struct___lambda_env_vader_pipeline_comptime__vm_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_comptime__vm_1_t));
        vader_obj_header_init(_a0_obj, 784u);
        _a0_obj->f_cap_0 = l1;
        l4 = (void*) _a0_obj;
        t1 = vader_array_length(((vader_array_t*) l3));
        vader_array_t* _a1_arr = vader_array_reserve(456u, (int64_t) t1, 13u, 2568u);
        l5 = (void*) _a1_arr;
        l6 = vader_array_length(((vader_array_t*) l3));
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
            l2 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
            l8 = __lambda_vader_pipeline_comptime__vm_0(l4, l2);
            vader_array_push_ref((vader_array_t*) l5, l8.payload.obj);
            l7 = (l7 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        l8 = vader_pipeline_comptime__vm$retargeted_type(((vader_struct_vader_front_comptime$ArrayValue_t*) t0)->f_type, l1);
        vader_struct_vader_front_comptime$ArrayValue_t* _a3_obj = (vader_struct_vader_front_comptime$ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ArrayValue_t));
        vader_obj_header_init(_a3_obj, 1467u);
        _a3_obj->f_elements = l5;
        _a3_obj->f_type = l8;
        t0 = (void*) _a3_obj;
        l2 = vader_ref_box(t0);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1487u) {
        t0 = l0.payload.obj;
        l8 = vader_pipeline_comptime__vm$retargeted_type(((vader_struct_vader_front_comptime$StructValue_t*) t0)->f_type, l1);
        t0 = l0.payload.obj;
        l3 = vader_pipeline_comptime__vm$retargeted_fields(((vader_struct_vader_front_comptime$StructValue_t*) t0)->f_fields, l1);
        vader_struct_vader_front_comptime$StructValue_t* _a4_obj = (vader_struct_vader_front_comptime$StructValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$StructValue_t));
        vader_obj_header_init(_a4_obj, 1487u);
        _a4_obj->f_type = l8;
        _a4_obj->f_fields = l3;
        t0 = (void*) _a4_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1488u) {
        t0 = l0.payload.obj;
        t2 = vader_pipeline_comptime__vm$retargeted_type(((vader_struct_vader_front_comptime$TypeValue_t*) t0)->f_value, l1);
        vader_struct_vader_front_comptime$TypeValue_t* _a5_obj = (vader_struct_vader_front_comptime$TypeValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$TypeValue_t));
        vader_obj_header_init(_a5_obj, 1488u);
        _a5_obj->f_value = t2;
        t0 = (void*) _a5_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1475u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = vader_pipeline_comptime__vm$retargeted_enum(((vader_struct_vader_front_comptime$EnumValue_t*) t0)->f_enum_type, l1);
        l9 = ((vader_struct_vader_front_comptime$EnumValue_t*) l3)->f_variant;
        l6 = ((vader_struct_vader_front_comptime$EnumValue_t*) l3)->f_value;
        vader_struct_vader_front_comptime$EnumValue_t* _a6_obj = (vader_struct_vader_front_comptime$EnumValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EnumValue_t));
        vader_obj_header_init(_a6_obj, 1475u);
        _a6_obj->f_enum_type = l4;
        _a6_obj->f_variant = l9;
        _a6_obj->f_value = l6;
        t0 = (void*) _a6_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 1469u || l0.tag == 1470u || l0.tag == 1479u || l0.tag == 1480u || l0.tag == 1484u || l0.tag == 1486u || l0.tag == 1490u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_comptime__vm$retargeted_enum(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null(), l9 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l3, &l7, &l9 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l5, &l6, &l8, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_types$EnumType_t*) l0)->f_data;
    if (l3.tag == 0u) {
        l2 = l0;
        l4 = vader_pipeline_comptime__vm$counterpart(((vader_struct_vader_core_types$EnumType_t*) l0)->f_symbol, l1);
        l5 = ((vader_struct_vader_core_types$EnumType_t*) l2)->f_repr;
        l6 = ((vader_struct_vader_core_types$EnumType_t*) l2)->f_indices;
        l7 = ((vader_struct_vader_core_types$EnumType_t*) l2)->f_data;
        l8 = ((vader_struct_vader_core_types$EnumType_t*) l2)->f_values;
        l9 = ((vader_struct_vader_core_types$EnumType_t*) l2)->f_written_width;
        vader_struct_vader_core_types$EnumType_t* _a0_obj = (vader_struct_vader_core_types$EnumType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$EnumType_t));
        vader_obj_header_init(_a0_obj, 1351u);
        _a0_obj->f_symbol = l4;
        _a0_obj->f_repr = l5;
        _a0_obj->f_indices = l6;
        _a0_obj->f_data = l7;
        _a0_obj->f_values = l8;
        _a0_obj->f_written_width = l9;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l4 = l0;
    l5 = vader_pipeline_comptime__vm$counterpart(((vader_struct_vader_core_types$EnumType_t*) l0)->f_symbol, l1);
    l6 = ((vader_struct_vader_core_types$EnumType_t*) l4)->f_repr;
    l8 = ((vader_struct_vader_core_types$EnumType_t*) l4)->f_indices;
    l2 = vader_pipeline_comptime__vm$retargeted_struct(l2, l1);
    l10 = ((vader_struct_vader_core_types$EnumType_t*) l4)->f_values;
    l3 = ((vader_struct_vader_core_types$EnumType_t*) l4)->f_written_width;
    vader_struct_vader_core_types$EnumType_t* _a1_obj = (vader_struct_vader_core_types$EnumType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$EnumType_t));
    vader_obj_header_init(_a1_obj, 1351u);
    _a1_obj->f_symbol = l5;
    _a1_obj->f_repr = l6;
    _a1_obj->f_indices = l8;
    _a1_obj->f_data = vader_ref_box(l2);
    _a1_obj->f_values = l10;
    _a1_obj->f_written_width = l3;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_comptime__vm$retargeted_fields(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7;
    vader_string_t l8 = 0;
    vader_string_t l10 = 0;
    vader_box_t l9 = vader_box_null(), l11 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l9, &l11, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 0u, 587u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 579u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a3_obj, 894u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = l0;
    l4 = ((vader_struct_std_collections$Map__string__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$Map__string__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__string__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l6];
        l8 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l9 = vader_array_ref_load_box(_a5_slotarr->buf, vader_array_offset(_a5_slotarr) + (size_t) l6);
        l10 = l8;
        l11 = vader_pipeline_comptime__vm$retargeted(l9, l1);
        std_collections$Map$std_core$IndexSet$set_at__string__Any(l2, l10, l11);
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_comptime__vm$retargeted_struct(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_pipeline_comptime__vm$counterpart(((vader_struct_vader_core_types$StructType_t*) l0)->f_symbol, l1);
    l3 = vader_pipeline_comptime__vm$retargeted_types(((vader_struct_vader_core_types$StructType_t*) l0)->f_args, l1);
    vader_struct_vader_core_types$StructType_t* _a0_obj = (vader_struct_vader_core_types$StructType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$StructType_t));
    vader_obj_header_init(_a0_obj, 1363u);
    _a0_obj->f_symbol = l2;
    _a0_obj->f_args = l3;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_pipeline_comptime__vm$retargeted_type(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l2, &l5, &t2 };
    void** gc_raw_roots[5] = { &l1, &l3, &l4, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1363u) {
        t0 = l0.payload.obj;
        t1 = vader_pipeline_comptime__vm$retargeted_struct(t0, l1);
        l2 = vader_ref_box(t1);
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1351u) {
        t0 = l0.payload.obj;
        t1 = vader_pipeline_comptime__vm$retargeted_enum(t0, l1);
        l2 = vader_ref_box(t1);
    } else if (l0.tag == 1366u) {
        t0 = l0.payload.obj;
        l3 = vader_pipeline_comptime__vm$counterpart(((vader_struct_vader_core_types$TraitType_t*) t0)->f_symbol, l1);
        t0 = l0.payload.obj;
        l4 = vader_pipeline_comptime__vm$retargeted_types(((vader_struct_vader_core_types$TraitType_t*) t0)->f_args, l1);
        vader_struct_vader_core_types$TraitType_t* _a0_obj = (vader_struct_vader_core_types$TraitType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$TraitType_t));
        vader_obj_header_init(_a0_obj, 1366u);
        _a0_obj->f_symbol = l3;
        _a0_obj->f_args = l4;
        t0 = (void*) _a0_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1350u) {
        t0 = l0.payload.obj;
        l3 = vader_pipeline_comptime__vm$counterpart(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_symbol, l1);
        t0 = l0.payload.obj;
        l5 = vader_pipeline_comptime__vm$retargeted_type(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing, l1);
        vader_struct_vader_core_types$DistinctType_t* _a1_obj = (vader_struct_vader_core_types$DistinctType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$DistinctType_t));
        vader_obj_header_init(_a1_obj, 1350u);
        _a1_obj->f_symbol = l3;
        _a1_obj->f_backing = l5;
        t0 = (void*) _a1_obj;
        l2 = vader_ref_box(t0);
    } else if (l0.tag == 1349u) {
        t0 = l0.payload.obj;
        t2 = vader_pipeline_comptime__vm$retargeted_type(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element, l1);
        l2 = vader_core_types$mk_array(t2);
    } else if (l0.tag == 1367u) {
        t0 = l0.payload.obj;
        t1 = vader_pipeline_comptime__vm$retargeted_types(((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements, l1);
        l2 = vader_core_types$mk_tuple(t1);
    } else if (l0.tag == 1372u) {
        t0 = l0.payload.obj;
        t1 = vader_pipeline_comptime__vm$retargeted_types(((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants, l1);
        l2 = vader_core_types$union_of(t1);
    } else if (l0.tag == 1352u) {
        l3 = l0.payload.obj;
        t0 = l0.payload.obj;
        l4 = vader_pipeline_comptime__vm$retargeted_types(((vader_struct_vader_core_types$FnType_t*) t0)->f_params, l1);
        t0 = l0.payload.obj;
        l5 = vader_pipeline_comptime__vm$retargeted_type(((vader_struct_vader_core_types$FnType_t*) t0)->f_return_type, l1);
        l3 = ((vader_struct_vader_core_types$FnType_t*) l3)->f_type_params;
        vader_struct_vader_core_types$FnType_t* _a2_obj = (vader_struct_vader_core_types$FnType_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_types$FnType_t));
        vader_obj_header_init(_a2_obj, 1352u);
        _a2_obj->f_params = l4;
        _a2_obj->f_return_type = l5;
        _a2_obj->f_type_params = l3;
        t0 = (void*) _a2_obj;
        l2 = vader_ref_box(t0);
    } else {
        if (!((l0.tag == 1348u || l0.tag == 1353u || l0.tag == 1354u || l0.tag == 1355u || l0.tag == 1356u || l0.tag == 1358u || l0.tag == 1360u || l0.tag == 1361u || l0.tag == 1362u || l0.tag == 1368u || l0.tag == 1369u || l0.tag == 1373u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l0;
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_comptime__vm$retargeted_types(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l7, &l8 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l0;
    vader_struct___lambda_env_vader_pipeline_comptime__vm_13_t* _a0_obj = (vader_struct___lambda_env_vader_pipeline_comptime__vm_13_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_comptime__vm_13_t));
    vader_obj_header_init(_a0_obj, 786u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    t0 = vader_array_length(((vader_array_t*) l2));
    vader_array_t* _a1_arr = vader_array_reserve(449u, (int64_t) t0, 13u, 2395u);
    l4 = (void*) _a1_arr;
    l5 = vader_array_length(((vader_array_t*) l2));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l6);
        l8 = __lambda_vader_pipeline_comptime__vm_12(l3, l7);
        vader_array_push_ref((vader_array_t*) l4, l8.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_pipeline_comptime__vm$stage_to_cfg(void* l0, void* l1, void* l2, void* l3, void* l4, void* l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int64_t l8, l9;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l10, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l11, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l6 = (void*) _a0_arr;
    l7 = l3;
    l8 = vader_array_length(((vader_array_t*) l7));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l10 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l9);
        l11 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l10)->f_module_id;
        t0 = std_core$$array$Contains$contains__string(l6, l11);
        if (!(t0)) {
            l12 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l10)->f_module_id;
            vader_array_push_scalar((vader_array_t*) l6, vader_box_string(576u, l12));
        }
        l9 = (l9 + INT64_C(1));
    }
    t1 = vader_lower$lower_project_staged(l0, l1, l2, l6, l5);
    l6 = vader_lower_dce$prune_unreachable_fns(t1, l4);
    vader_struct_vader_midir_pipeline$CfgPassOptions_t* _a2_obj = (vader_struct_vader_midir_pipeline$CfgPassOptions_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir_pipeline$CfgPassOptions_t));
    vader_obj_header_init(_a2_obj, 1884u);
    _a2_obj->f_verify = false;
    _a2_obj->f_prove_bounds = false;
    _a2_obj->f_instrumented = false;
    _a2_obj->f_plain_returns = true;
    l7 = (void*) _a2_obj;
    t1 = vader_midir_pipeline$build_optimised_cfg(l6, l7, l5);
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
    l4 = ((vader_struct_std_collections$Map__string__vader_midir_CFGModule_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections$Map__string__vader_midir_CFGModule_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$Map__string__vader_midir_CFGModule_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l6];
        t1 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
        l3 = ((vader_struct_vader_midir$CFGModule_t*) t2)->f_functions;
        l8 = vader_array_length(((vader_array_t*) l3));
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l10 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l9);
            t3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$AssertDecl_t, f_id, ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l10)->f_origin)->f_decl.payload.obj);
            if (t3 == l2) {
                l11 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) l1)->f_functions;
                vader_struct___lambda_env_vader_pipeline_comptime__vm_11_t* _a3_obj = (vader_struct___lambda_env_vader_pipeline_comptime__vm_11_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_pipeline_comptime__vm_11_t));
                vader_obj_header_init(_a3_obj, 785u);
                _a3_obj->f_cap_0 = l10;
                l12 = (void*) _a3_obj;
                l13 = false;
                l14 = vader_array_length(((vader_array_t*) l11));
                l15 = INT64_C(0);
                {
                    while ((l15 < l14)) {
                        vader_array_t* _a4_slotarr = ((vader_array_t*) l11);
                        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                        l16 = vader_array_ref_load_obj(_a4_slotarr->buf, vader_array_offset(_a4_slotarr) + (size_t) l15);
                        t4 = __lambda_vader_pipeline_comptime__vm_10(l12, l16);
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
                    { vader_box_t __vret = vader_box_string(576u, t1); vader_gc_top = gc_frame.prev; return __vret; }
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
        t0 = vader_pipeline_comptime__vm$unsupported(l3, 1830u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l6.payload.obj;
    l7 = vader_array_length(((vader_array_t*) ((vader_struct_vader_vm$StructVal_t*) l1)->f_fields));
    l8 = vader_pipeline_comptime__vm$instance_type(l2, l4, l7);
    if (l8.tag == 0u) {
        t0 = vader_pipeline_comptime__vm$unsupported(l3, 1830u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l8;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    l9 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(33u, 0u, 0u, 587u);
    l10 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 579u);
    l11 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a3_obj, 894u);
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
        l14 = vader_array_box_slots(_a4_slotarr->buf)[vader_array_offset(_a4_slotarr) + (size_t) l12];
        l15 = vader_pipeline_comptime__vm$value_to_comptime(l0, l14, l8, l3);
        if (l15.tag == 1111u) {
            t0 = l15.payload.obj;
            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
        }
        l16 = l15;
        std_collections$Map$std_core$IndexSet$set_at__string__Any(l9, l13, l16);
        l12 = (l12 + INT64_C(1));
    }
    vader_struct_vader_front_comptime$StructValue_t* _a5_obj = (vader_struct_vader_front_comptime$StructValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$StructValue_t));
    vader_obj_header_init(_a5_obj, 1487u);
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
    l2 = concat_3(2180u, l1, 279u);
    t0 = toolchain_diagnostics$comptime_error((uint8_t) 0, l0, l2);
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
    if (l1.tag == 579u) {
        t0 = ((int32_t) l1.payload.i);
        l5 = ((int64_t) (int32_t) t0);
        l6 = vader_pipeline_comptime__vm$prim_name(l2, 2535u);
        l4 = vader_pipeline_comptime__vm$int_scalar(l5, l6);
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 580u) {
        l5 = ((int64_t) l1.payload.i);
        l6 = vader_pipeline_comptime__vm$prim_name(l2, 2557u);
        l4 = vader_pipeline_comptime__vm$int_scalar(l5, l6);
    } else if ((l1.tag == 585u || l1.tag == 586u)) {
        l7 = ((double) l1.payload.f);
        l6 = vader_pipeline_comptime__vm$prim_name(l2, 2392u);
        l4 = vader_front_comptime$float_val_typed(l7, l6);
    } else if (l1.tag == 574u) {
        t1 = l1.payload.b;
        vader_struct_vader_front_comptime$BoolValue_t* _a0_obj = (vader_struct_vader_front_comptime$BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$BoolValue_t));
        vader_obj_header_init(_a0_obj, 1469u);
        _a0_obj->f_value = t1;
        t2 = (void*) _a0_obj;
        l4 = vader_ref_box(t2);
    } else if (l1.tag == 575u) {
        t3 = ((uint32_t) l1.payload.i);
        vader_struct_vader_front_comptime$CharValue_t* _a1_obj = (vader_struct_vader_front_comptime$CharValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$CharValue_t));
        vader_obj_header_init(_a1_obj, 1470u);
        _a1_obj->f_value = (uint32_t) (int32_t) ((int32_t) (uint32_t) t3);
        t2 = (void*) _a1_obj;
        l4 = vader_ref_box(t2);
    } else if (l1.tag == 576u) {
        t4 = l1.payload.s;
        l4 = vader_front_comptime$string_val(t4);
    } else if (l1.tag == 1944u) {
        t2 = (void*) &vader_data_33;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t2);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) INT64_C(0));
        l4 = vader_ref_box(t2);
    } else if (l1.tag == 1929u) {
        l8 = l1.payload.obj;
        l4 = vader_pipeline_comptime__vm$array_to_comptime(l0, l8, l2, l3);
    } else if (l1.tag == 1962u) {
        l8 = l1.payload.obj;
        l4 = vader_pipeline_comptime__vm$struct_to_comptime(l0, l8, l2, l3);
    } else if (l1.tag == 1934u) {
        t2 = vader_pipeline_comptime__vm$unsupported(l3, 1786u);
        l4 = vader_ref_box(t2);
    } else if (l1.tag == 1966u) {
        t2 = vader_pipeline_comptime__vm$unsupported(l3, 1849u);
        l4 = vader_ref_box(t2);
    } else {
        if (!(l1.tag == 1945u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t2 = vader_pipeline_comptime__vm$unsupported(l3, 1797u);
        l4 = vader_ref_box(t2);
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}
