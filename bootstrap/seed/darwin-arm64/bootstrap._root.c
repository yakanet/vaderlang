#include "bootstrap.split.h"

static bool __lambda_vader_front_effects_142(void* l0, void* l1);
static bool __lambda_vader_front_effects_58(void* l0, void* l1);
static bool __lambda_vader_front_resolver_15(vader_box_t l0);
static bool __lambda_vader_front_typecheck_55(void* l0, void* l1);
static bool __lambda_vader_front_typecheck_75(void* l0, void* l1);
static bool __lambda_vader_midir_2(void* l0, int32_t l1);
static bool __lambda_vader_support_fixpoint_3(void* l0, int32_t l1);

void __defer_std_fs_0(void* l0) {
    void* t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct___defer_env_std_fs_1_t*) l0)->f_cap_0;
    vader_host_system_posix$sys_closedir(t0);
    { vader_gc_top = gc_frame.prev; return; }
}

void __defer_std_fs_2(void* l0) {
    std_fs$close(((vader_struct___defer_env_std_fs_3_t*) l0)->f_cap_0);
    return;
}

void __defer_std_runtime_scheduler_0(void* l0) {
    vader_host_std_core$Intrinsic$monitor_exit();
    return;
}

void __defer_std_runtime_scheduler_2(void* l0) {
    std_runtime_scheduler$let_go(((vader_struct___defer_env_std_runtime_scheduler_3_t*) l0)->f_cap_0);
    return;
}

void __defer_std_runtime_scheduler_4(void* l0) {
    void* l1;
    int64_t l2;
    l1 = ((vader_struct_std_runtime_scheduler$InitGate_t*) ((vader_struct___defer_env_std_runtime_scheduler_5_t*) l0)->f_cap_0)->f_waiters;
    l2 = ((vader_struct___defer_env_std_runtime_scheduler_5_t*) l0)->f_cap_1;
    std_core$remove_value__i64(l1, l2);
    return;
}

void __defer_std_task_10(void* l0) {
    vader_host_std_core$Intrinsic$monitor_exit();
    return;
}

void __defer_std_task_12(void* l0) {
    vader_host_std_core$Intrinsic$monitor_exit();
    return;
}

void __defer_std_task_14(void* l0) {
    void* l1;
    int64_t l2;
    l1 = ((vader_struct___defer_env_std_task_15_t*) l0)->f_cap_0;
    l2 = ((vader_struct___defer_env_std_task_15_t*) l0)->f_cap_1;
    std_task$stop_waiting__Any(l1, l2);
    return;
}

void __defer_std_task_2(void* l0) {
    vader_host_std_core$Intrinsic$monitor_exit();
    return;
}

void __defer_std_task_4(void* l0) {
    std_task$cancel_and_wait__vader_front_resolver_ParsedFile____(((vader_struct___defer_env_std_task_5_t*) l0)->f_cap_0);
    return;
}

void __defer_std_task_6(void* l0) {
    std_task$stop_waiting_all__vader_front_resolver_ParsedFile____(((vader_struct___defer_env_std_task_7_t*) l0)->f_cap_0);
    return;
}

void __defer_std_task_8(void* l0) {
    std_task$end__Any(((vader_struct___defer_env_std_task_9_t*) l0)->f_cap_0);
    return;
}

void __defer_vader_vm_22(void* l0) {
    void* l1;
    int64_t l2;
    l1 = ((vader_struct___defer_env_vader_vm_23_t*) l0)->f_cap_0;
    l2 = ((vader_struct___defer_env_vader_vm_23_t*) l0)->f_cap_1;
    vader_vm$forget(l1, l2);
    return;
}

void __defer_vader_vm_24(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    bool l4;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___defer_env_vader_vm_25_t*) l0)->f_cap_0;
    l2 = ((vader_struct_vader_vm$VmState_t*) ((vader_struct___defer_env_vader_vm_25_t*) l0)->f_cap_0)->f_reg;
    l3 = ((vader_struct___defer_env_vader_vm_25_t*) l0)->f_cap_1;
    l4 = ((vader_struct___defer_env_vader_vm_25_t*) l0)->f_cap_2;
    vader_vm$unwind(l1, l2, l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_std_numbers_0(uint32_t l0) {
    return l0 == 95u;
}

bool __lambda_std_path_0(uint32_t l0) {
    return l0 == 47u;
}

bool __lambda_std_path_1(uint32_t l0) {
    return l0 == 92u;
}

void __lambda_std_task_0(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_std_task_1_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_std_task_1_t*) l0)->f_cap_1;
    std_task$run__Any(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_toolchain_ast_0(void* l0, void* l1) {
    uint8_t l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_toolchain_ast_1_t*) l0)->f_cap_0;
    t0 = toolchain_ast$is_compiler(l1, l2);
    return t0;
}

uint8_t __lambda_toolchain_ast_2(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_toolchain_ast_3_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_toolchain_ast_3_t*) l0)->f_cap_1;
    t0 = toolchain_ast$take_first(l1, l2, l3);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_toolchain_parser_0(void* l0, vader_string_t l1) {
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = toolchain_parser$is_binding_hint(((vader_struct_$Cell_1d5a2f94ab0d39fa_t*) ((vader_struct___lambda_env_toolchain_parser_1_t*) l0)->f_cap_0.payload.obj)->f_value, l1, true);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_toolchain_parser_2(void* l0, vader_string_t l1) {
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = toolchain_parser$is_binding_hint(((vader_struct_$Cell_1d5a2f94ab0d39fa_t*) ((vader_struct___lambda_env_toolchain_parser_3_t*) l0)->f_cap_0.payload.obj)->f_value, l1, false);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_toolchain_parser_4(uint32_t l0) {
    bool t0;
    t0 = std_char$is_alphanumeric(l0);
    return !(t0);
}

vader_string_t __lambda_toolchain_parser_5(vader_string_t l0) {
    vader_string_t t0;
    t0 = concat_3(2944u, l0, 93u);
    return t0;
}

vader_string_t __lambda_toolchain_parser_6(vader_string_t l0) {
    vader_string_t t0;
    t0 = concat_3(2945u, l0, 93u);
    return t0;
}

bool __lambda_toolchain_project_0(uint32_t l0) {
    bool l1;
    bool t0;
    t0 = std_char$is_alphanumeric(l0);
    if (t0) {
        l1 = true;
    } else {
        l1 = l0 == 95u;
    }
    if (l1) {
        return true;
    }
    return l0 == 45u;
}

bool __lambda_toolchain_project_1(uint32_t l0) {
    return l0 == 92u;
}

vader_string_t __lambda_toolchain_protocol_0(void* l0, vader_string_t l1) {
    vader_box_t l2;
    vader_string_t t0;
    l2 = std_collections$Map$std_core$Index$at__string__string(((vader_struct___lambda_env_toolchain_protocol_1_t*) l0)->f_cap_0, l1);
    if (l2.tag == 0u) {
        return l1;
    }
    t0 = l2.payload.s;
    return t0;
}

bool __lambda_toolchain_protocol_2(void* l0) {
    bool t0;
    t0 = toolchain_ast$is_compiler_made(l0);
    return !(t0);
}

void* __lambda_toolchain_stage_0(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 8u, 633u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_toolchain_stage_1(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 629u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_toolchain_stage_2(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 8u, 633u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_toolchain_stage_3(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 629u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_toolchain_stage_4(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 8u, 633u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_toolchain_stage_5(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 629u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_toolchain_stage_6(void* l0, int64_t l1) {
    bool t0, t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_toolchain_stage_7_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
    t1 = t0;
    return t1;
}

bool __lambda_toolchain_stage_8(void* l0, vader_box_t l1) {
    bool t0;
    t0 = toolchain_stage$same_given(((vader_struct___lambda_env_toolchain_stage_9_t*) l0)->f_cap_0, l1);
    return t0;
}

bool __lambda_vader_core_types_0(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_toolchain_ast$Decorator_t*) l0)->f_name;
    return t0 == 3293u;
}

bool __lambda_vader_core_types_1(vader_box_t l0) {
    return l0.tag == 1491u;
}

bool __lambda_vader_core_types_2(vader_box_t l0) {
    bool t0;
    t0 = vader_core_types$is_c_library(l0);
    if (t0) {
        return true;
    }
    t0 = vader_core_types$is_wasm_interface(l0);
    return t0;
}

bool __lambda_vader_core_types_3(void* l0, int64_t l1, int64_t l2) {
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l4 = 0;
    vader_string_t l6 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[3] = { &l3, &l5, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_core_types_4_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_core_types_4_t*) l0)->f_cap_1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l1];
    l4 = t0.payload.s;
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[vader_array_offset(_a1_slotarr) + (size_t) l2];
    l6 = t0.payload.s;
    t1 = vader_core_types$comes_before(l3, l4, l5, l6);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_core_types_5(int64_t l0, int64_t l1) {
    return (l0 < l1);
}

bool __lambda_vader_core_types_6(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) l1)->f_symbol)->f_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) ((vader_struct___lambda_env_vader_core_types_7_t*) l0)->f_cap_0)->f_symbol)->f_id;
    return l2 == l3;
}

bool __lambda_vader_core_types_8(void) {
    return false;
}

bool __lambda_vader_core_types_9(void* l0, vader_box_t l1) {
    vader_box_t l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_core_types_10_t*) l0)->f_cap_0;
    t0 = vader_core_types$equals_type(l1, l2);
    return t0;
}

void* __lambda_vader_core_wit_0(void* l0) {
    vader_string_t l1 = 0;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_wit$WitParam_t*) l0)->f_name;
    l2 = vader_core_wit$alias_free(((vader_struct_vader_core_wit$WitParam_t*) l0)->f_type);
    vader_struct_vader_core_wit$WitParam_t* _a0_obj = (vader_struct_vader_core_wit$WitParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_wit$WitParam_t));
    vader_obj_header_init(_a0_obj, 1526u);
    _a0_obj->f_name = l1;
    _a0_obj->f_type = l2;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_core_wit_1(void* l0) {
    return ((vader_struct_vader_core_wit$WitCase_t*) l0)->f_type;
}

vader_string_t __lambda_vader_core_wit_10(vader_string_t l0) {
    vader_string_t t0;
    t0 = concat_3(21u, l0, 443u);
    return t0;
}

bool __lambda_vader_core_wit_11(void* l0) {
    bool t0;
    t0 = vader_core_wit$is_stable(((vader_struct_vader_core_wit$WitUseDecl_t*) l0)->f_gate);
    return t0;
}

bool __lambda_vader_core_wit_12(void* l0) {
    bool t0;
    t0 = vader_core_wit$is_stable(((vader_struct_vader_core_wit$WitTypeDecl_t*) l0)->f_gate);
    return t0;
}

bool __lambda_vader_core_wit_13(void* l0) {
    bool t0;
    t0 = vader_core_wit$is_stable(((vader_struct_vader_core_wit$WitFunctionDecl_t*) l0)->f_gate);
    return t0;
}

vader_string_t __lambda_vader_core_wit_14(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_core_wit$snake_name(l0);
    t0 = concat_3(21u, l1, 577u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_core_wit_15(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_core_wit$pascal_name(l0);
    t0 = concat_3(21u, l1, 443u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_core_wit_16(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = vader_core_wit$pascal_name(l0);
    t0 = concat_5(29u, l1, 84u, l0, 320u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_core_wit_17(void* l0) {
    bool t0;
    t0 = vader_core_wit$is_stable(((vader_struct_vader_core_wit$WitFunctionDecl_t*) l0)->f_gate);
    return t0;
}

vader_string_t __lambda_vader_core_wit_18(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_core_wit$WitParam_t*) l0)->f_name;
    l2 = vader_core_wit$wit_type_text(((vader_struct_vader_core_wit$WitParam_t*) l0)->f_type);
    t0 = concat_3(l1, 565u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_core_wit_19(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_core_wit$WitMemberDecl_t*) l0)->f_name;
    return t0;
}

vader_box_t __lambda_vader_core_wit_2(void* l0) {
    return ((vader_struct_vader_core_wit$WitParam_t*) l0)->f_type;
}

vader_string_t __lambda_vader_core_wit_20(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_core_wit$WitMemberDecl_t*) l0)->f_name;
    return t0;
}

bool __lambda_vader_core_wit_21(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_vader_core_wit$WitOwner_t*) ((vader_struct_vader_core_wit$WitInterface_t*) l1)->f_owner)->f_interface;
    l3 = ((vader_struct_vader_core_wit$WitUsePath_t*) ((vader_struct_vader_core_wit$UsedName_t*) ((vader_struct___lambda_env_vader_core_wit_22_t*) l0)->f_cap_0)->f_path)->f_interface;
    return l2 == l3;
}

bool __lambda_vader_core_wit_23(void* l0, vader_box_t l1) {
    vader_string_t l2, l3;
    l2 = vader_core_wit$wit_type_name(l1);
    l3 = ((vader_struct_vader_core_wit$UsedName_t*) ((vader_struct___lambda_env_vader_core_wit_24_t*) l0)->f_cap_0)->f_name;
    return l2 == l3;
}

bool __lambda_vader_core_wit_3(void* l0) {
    return ((vader_struct_vader_core_wit$WitCase_t*) l0)->f_type.tag == 0u;
}

bool __lambda_vader_core_wit_4(void* l0, vader_string_t l1) {
    bool t0;
    t0 = std_core$$array$Contains$contains__string(((vader_struct___lambda_env_vader_core_wit_5_t*) l0)->f_cap_0, l1);
    return t0;
}

bool __lambda_vader_core_wit_6(void* l0) {
    return ((vader_struct_vader_core_wit$WitCase_t*) l0)->f_type.tag == 0u;
}

vader_string_t __lambda_vader_core_wit_7(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_core_wit$WitCase_t*) l0)->f_name;
    return t0;
}

bool __lambda_vader_core_wit_8(void* l0) {
    return !(((vader_struct_vader_core_wit$WitCase_t*) l0)->f_type.tag == 0u);
}

bool __lambda_vader_core_wit_9(void* l0) {
    bool t0;
    t0 = vader_core_wit$is_stable(((vader_struct_vader_core_wit$WitInterfaceDecl_t*) l0)->f_gate);
    return t0;
}

bool __lambda_vader_emit_bytecode_0(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_emit_bytecode_1_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) ((vader_struct___lambda_env_vader_emit_bytecode_1_t*) l0)->f_cap_1)->f_method_name;
    l3 = vader_core_mangle$vtable_key(l1, l3);
    t0 = std_collections$Map$std_core$Index$at__string__bool(l2, l3);
    { bool __vret = t0.tag == 627u; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t __lambda_vader_emit_bytecode_11(void* l0, int32_t l1) {
    int32_t t0;
    t0 = vader_emit_bytecode$remap_idx(((vader_struct___lambda_env_vader_emit_bytecode_12_t*) l0)->f_cap_0, l1);
    return t0;
}

vader_box_t __lambda_vader_emit_bytecode_13(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_emit_bytecode_14_t*) l0)->f_cap_0;
    t0 = vader_emit_bytecode$remap_data_value(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_emit_bytecode_15(void* l0, int32_t l1) {
    bool t0;
    t0 = vader_emit_bytecode$is_boxed_row(((vader_struct___lambda_env_vader_emit_bytecode_16_t*) l0)->f_cap_0, l1);
    return t0;
}

bool __lambda_vader_emit_bytecode_17(void* l0, void* l1) {
    void* l2;
    int32_t l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_emit_bytecode_18_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_core_bytecode$BcField_t*) l1)->f_type_index;
    t0 = vader_emit_bytecode$is_boxed_row(l2, l3);
    return t0;
}

void* __lambda_vader_emit_bytecode_19(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_bytecode$SlotRange_t* _a0_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
    vader_obj_header_init(_a0_obj, 1562u);
    _a0_obj->f_first = INT32_C(-1);
    _a0_obj->f_last = INT32_C(-1);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t __lambda_vader_emit_bytecode_2(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_emit_bytecode_3_t*) l0)->f_cap_0;
    t0 = vader_emit_bytecode$interned_or_none(l1, l2);
    { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_emit_bytecode_20(void* l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = toolchain_stage$Stage$describe$$dispatch(l1);
    l2 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) t0.payload.obj)->f_name;
    l3 = ((vader_struct_vader_emit_bytecode$BytecodeSpec_t*) ((vader_struct___lambda_env_vader_emit_bytecode_21_t*) l0)->f_cap_0)->f_name;
    { bool __vret = l2 == l3; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_emit_bytecode_4(int32_t l0) {
    return (l0 >= INT32_C(0));
}

vader_box_t __lambda_vader_emit_bytecode_5(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_emit_bytecode_6_t*) l0)->f_cap_0;
    t0 = vader_emit_bytecode$remap_type(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_emit_bytecode_7(void* l0, void* l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    int32_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BcGlobal_t*) l1)->f_name;
    l3 = ((vader_struct___lambda_env_vader_emit_bytecode_8_t*) l0)->f_cap_0;
    l4 = ((vader_struct_vader_core_bytecode$BcGlobal_t*) l1)->f_type_id;
    l4 = vader_emit_bytecode$remap_idx(l3, l4);
    vader_struct_vader_core_bytecode$BcGlobal_t* _a0_obj = (vader_struct_vader_core_bytecode$BcGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcGlobal_t));
    vader_obj_header_init(_a0_obj, 1298u);
    _a0_obj->f_name = l2;
    _a0_obj->f_type_id = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_emit_bytecode_9(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_emit_bytecode_10_t*) l0)->f_cap_0;
    t0 = vader_emit_bytecode$remap_data_entry(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_emit_c_0(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 632u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_emit_c_1(void* l0, int64_t l1) {
    void* l2 = NULL;
    int32_t l3;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct___lambda_env_vader_emit_c_2_t*) l0)->f_cap_0)->f_types;
    l3 = ((int32_t) (int64_t) l1);
    t0 = vader_emit_c$find_layout_siblings(l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_emit_c_11(void* l0, vader_box_t l1) {
    void* l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_emit_c_12_t*) l0)->f_cap_0;
    t0 = vader_emit_c$op_may_collect(l1, l2);
    return t0;
}

vader_box_t __lambda_vader_emit_c_13(vader_string_t l0) {
    vader_box_t t0;
    t0 = vader_emit_c_ast$verbatim(l0);
    return t0;
}

bool __lambda_vader_emit_c_14(vader_box_t l0) {
    void* t0;
    bool t1;
    if (l0.tag == 1438u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_stack;
        return t1;
    }
    return false;
}

bool __lambda_vader_emit_c_3(void* l0, int32_t l1, int32_t l2) {
    vader_string_t l3, l4;
    void* t0;
    bool t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_emit_c_4_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l2);
    l4 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
    t1 = std_string$compare_ascending(l3, l4);
    return t1;
}

bool __lambda_vader_emit_c_5(vader_string_t l0, vader_string_t l1) {
    bool t0;
    t0 = std_string$compare_ascending(l0, l1);
    return t0;
}

bool __lambda_vader_emit_c_6(void* l0) {
    bool t0;
    t0 = vader_core_bytecode$intrinsic_may_collect(((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_intrinsic);
    return t0;
}

bool __lambda_vader_emit_c_7(void* l0, void* l1) {
    void* l2 = NULL;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_emit_c_8_t*) l0)->f_cap_0;
    t0 = vader_emit_c$fn_has_direct_alloc(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_emit_c_9(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c$foreign_unit_of(l1);
    l3 = ((vader_struct___lambda_env_vader_emit_c_10_t*) l0)->f_cap_0;
    { bool __vret = l2 == l3; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_emit_c_ast_0(void* l0, int64_t l1, int64_t l2) {
    int32_t l3, l4;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_emit_c_ast_1_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l2];
    return (l3 < l4);
}

vader_box_t __lambda_vader_front_comptime_0(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_comptime_1_t*) l0)->f_cap_0;
    vader_struct___lambda_env_vader_front_comptime_3_t* _a0_obj = (vader_struct___lambda_env_vader_front_comptime_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_comptime_3_t));
    vader_obj_header_init(_a0_obj, 708u);
    _a0_obj->f_cap_0 = l1;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 622u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_front_comptime_2;
    _a1_closure->env = t0;
    l3 = (void*) _a1_closure;
    l4 = ((vader_struct___lambda_env_vader_front_comptime_1_t*) l0)->f_cap_1;
    l5 = vader_front_comptime$evaluate_constant_as__std_core_CLibrary(l1, l2, 711u, l3, l4);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l5.payload.obj;
    l3 = ((vader_struct___lambda_env_vader_front_comptime_1_t*) l0)->f_cap_2;
    l4 = ((vader_struct___lambda_env_vader_front_comptime_1_t*) l0)->f_cap_1;
    vader_front_comptime$check_one_binary_per_name(l1, l2, l3, l4);
    { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t __lambda_vader_front_comptime_10(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_comptime_11_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_comptime_11_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_comptime_11_t*) l0)->f_cap_2;
    l5 = ((vader_struct___lambda_env_vader_front_comptime_11_t*) l0)->f_cap_3;
    t0 = vader_front_comptime$dependency_step(l1, l2, l3, l4, l5);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_front_comptime_2(void* l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct___lambda_env_vader_front_comptime_3_t*) l0)->f_cap_0)->f_module;
    t0 = vader_front_comptime$resolved_library(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_comptime_4(void* l0) {
    return ((vader_struct_vader_front_typecheck$TypedProgram_t*) l0)->f_extern_libraries;
}

vader_box_t __lambda_vader_front_comptime_5(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_comptime_6_t*) l0)->f_cap_0;
    l3 = (void*) &vader_fn_static_vader_front_comptime$resolved_interface;
    l4 = ((vader_struct___lambda_env_vader_front_comptime_6_t*) l0)->f_cap_1;
    t0 = vader_front_comptime$evaluate_constant_as__std_core_CLibrary(l1, l2, 1216u, l3, l4);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_comptime_7(void* l0) {
    return ((vader_struct_vader_front_typecheck$TypedProgram_t*) l0)->f_extern_interfaces;
}

bool __lambda_vader_front_comptime_8(void* l0, void* l1) {
    vader_box_t l2;
    void* l3;
    bool t0;
    if (!(((vader_struct_toolchain_ast$CallArg_t*) l1)->f_comptime_body.tag == 0u)) {
        l2 = ((vader_struct_toolchain_ast$CallArg_t*) l1)->f_value;
        l3 = ((vader_struct___lambda_env_vader_front_comptime_9_t*) l0)->f_cap_0;
        t0 = vader_front_comptime$is_computed(l2, l3);
        return !(t0);
    }
    return false;
}

bool __lambda_vader_front_dead__code_0(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (l0.tag == 1158u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
        return t1 == 2871u;
    }
    return false;
}

void* __lambda_vader_front_dead__code_1(void* l0, uint8_t l1) {
    void* t0;
    void* t1;
    t0 = ((vader_struct___lambda_env_vader_front_dead__code_2_t*) l0)->f_cap_0.payload.obj;
    t1 = vader_front_typecheck$sites_of(((vader_struct_vader_front_typecheck$TypedProgram_t*) t0)->f_call_sites, l1);
    return t1;
}

bool __lambda_vader_front_dead__code_11(void* l0) {
    bool t0;
    t0 = vader_front_resolver$has_impl_decl(((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_program)->f_decls);
    return t0;
}

uint8_t __lambda_vader_front_dead__code_3(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_dead__code_4_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_dead__code_4_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_dead__code_4_t*) l0)->f_cap_2;
    t0 = vader_front_dead__code$note_site(l1, l2, l3, l4);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_dead__code_5(void* l0, vader_string_t l1) {
    bool t0;
    t0 = vader_front_dead__code$may_run_an_impl_of(((vader_struct___lambda_env_vader_front_dead__code_6_t*) l0)->f_cap_0, l1);
    return t0;
}

bool __lambda_vader_front_dead__code_7(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_vader_front_resolver$ImportPath_t*) l1)->f_path;
    l3 = ((vader_struct___lambda_env_vader_front_dead__code_8_t*) l0)->f_cap_0;
    return l2 == l3;
}

bool __lambda_vader_front_dead__code_9(void* l0, vader_string_t l1) {
    vader_string_t l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_dead__code_10_t*) l0)->f_cap_0;
    t0 = std_string$ends_with(l1, l2);
    return t0;
}

void* __lambda_vader_front_effects_0(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(287u, 0u, 13u, 1670u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(30u, 0u, 8u, 633u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(30u, 0u, 8u, 633u);
    l2 = (void*) _a2_arr;
    vader_struct_vader_front_effects$ParamEffects_t* _a3_obj = (vader_struct_vader_front_effects$ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_effects$ParamEffects_t));
    vader_obj_header_init(_a3_obj, 1710u);
    _a3_obj->f_accesses = l0;
    _a3_obj->f_origins = l1;
    _a3_obj->f_keys = vader_box_obj(0u, NULL);
    _a3_obj->f_unders = l2;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t __lambda_vader_front_effects_1(void) {
    return INT64_C(0);
}

void* __lambda_vader_front_effects_10(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(287u, 0u, 13u, 1670u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(30u, 0u, 8u, 633u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(30u, 0u, 8u, 633u);
    l2 = (void*) _a2_arr;
    vader_struct_vader_front_effects$ParamEffects_t* _a3_obj = (vader_struct_vader_front_effects$ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_effects$ParamEffects_t));
    vader_obj_header_init(_a3_obj, 1710u);
    _a3_obj->f_accesses = l0;
    _a3_obj->f_origins = l1;
    _a3_obj->f_keys = vader_box_obj(0u, NULL);
    _a3_obj->f_unders = l2;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_101(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_vader_front_effects$TaskFault_t*) ((vader_struct_vader_front_effects$Candidate_t*) ((vader_struct_vader_front_effects$Folded_t*) l1)->f_first)->f_fault)->f_detail;
    l3 = ((vader_struct_vader_front_effects$TaskFault_t*) ((vader_struct_vader_front_effects$Candidate_t*) ((vader_struct___lambda_env_vader_front_effects_102_t*) l0)->f_cap_0)->f_fault)->f_detail;
    return l2 == l3;
}

void* __lambda_vader_front_effects_103(void* l0) {
    return ((vader_struct_vader_front_effects$Reach_t*) l0)->f_parks;
}

bool __lambda_vader_front_effects_104(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_name;
    return t0 == 2961u;
}

bool __lambda_vader_front_effects_105(vader_box_t l0) {
    return !(l0.tag == 0u);
}

bool __lambda_vader_front_effects_106(void* l0, void* l1) {
    int64_t l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_107_t*) l0)->f_cap_0;
    t0 = vader_front_effects$handed_to_param(l1, l2);
    return t0;
}

bool __lambda_vader_front_effects_108(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_effects$ParamEffects_t*) l1)->f_accesses;
    l3 = ((vader_struct___lambda_env_vader_front_effects_109_t*) l0)->f_cap_0;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
        vader_fn_t* _a1_fnobj = (vader_fn_t*) l3;
        t1 = ((vader_fn_erased_sig_1_t) _a1_fnobj->code)(_a1_fnobj->env, vader_ref_box(t0));
        t2 = t1.payload.b;
        if (t2) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

void* __lambda_vader_front_effects_11(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(287u, 0u, 13u, 1670u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(30u, 0u, 8u, 633u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(30u, 0u, 8u, 633u);
    l2 = (void*) _a2_arr;
    vader_struct_vader_front_effects$ParamEffects_t* _a3_obj = (vader_struct_vader_front_effects$ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_effects$ParamEffects_t));
    vader_obj_header_init(_a3_obj, 1710u);
    _a3_obj->f_accesses = l0;
    _a3_obj->f_origins = l1;
    _a3_obj->f_keys = vader_box_obj(0u, NULL);
    _a3_obj->f_unders = l2;
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_110(void* l0, void* l1) {
    int64_t l2, l3;
    l2 = ((vader_struct_vader_front_effects$KeptInto_t*) l1)->f_value;
    l3 = ((vader_struct___lambda_env_vader_front_effects_111_t*) l0)->f_cap_0;
    return l2 == l3;
}

bool __lambda_vader_front_effects_112(void* l0, void* l1) {
    void* l2;
    void* l3;
    bool t0;
    l2 = ((vader_struct_toolchain_ast$LambdaExpr_t*) ((vader_struct_vader_front_effects$LambdaCalls_t*) l1)->f_lambda)->f_span;
    l3 = ((vader_struct_toolchain_ast$LambdaExpr_t*) ((vader_struct___lambda_env_vader_front_effects_113_t*) l0)->f_cap_0)->f_span;
    t0 = vader_front_effects$same_span(l2, l3);
    return t0;
}

bool __lambda_vader_front_effects_114(void* l0, void* l1) {
    void* l2;
    void* l3;
    bool t0;
    l2 = ((vader_struct_toolchain_ast$FnParam_t*) l1)->f_span;
    l3 = ((vader_struct___lambda_env_vader_front_effects_115_t*) l0)->f_cap_0;
    t0 = vader_front_effects$same_span(l2, l3);
    return t0;
}

bool __lambda_vader_front_effects_116(void* l0, void* l1) {
    void* l2;
    int64_t l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_117_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_front_effects$Root_t*) l1)->f_param;
    t0 = std_collections$Set$std_core$Contains$contains__i64(l2, l3);
    return t0;
}

bool __lambda_vader_front_effects_118(void* l0, void* l1) {
    void* l2;
    void* l4;
    int64_t l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_119_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_front_effects$Root_t*) l1)->f_param;
    t0 = std_collections$Set$std_core$Contains$contains__i64(l2, l3);
    if (!(t0)) {
        l2 = ((vader_struct___lambda_env_vader_front_effects_119_t*) l0)->f_cap_1;
        l3 = ((vader_struct_vader_front_effects$Root_t*) l1)->f_param;
        l4 = ((vader_struct_toolchain_ast$LambdaExpr_t*) ((vader_struct___lambda_env_vader_front_effects_119_t*) l0)->f_cap_2)->f_span;
        t0 = vader_front_effects$bound_inside(l2, l3, l4);
        return !(t0);
    }
    return false;
}

void* __lambda_vader_front_effects_12(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(310u, 0u, 13u, 1716u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_120(void* l0, void* l1) {
    int64_t l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_121_t*) l0)->f_cap_0;
    t0 = vader_front_effects$ended_by(l1, l2);
    return t0;
}

bool __lambda_vader_front_effects_122(void* l0) {
    bool t0;
    if (((vader_struct_vader_front_effects$Access_t*) l0)->f_effect == INT32_C(3)) {
        return true;
    }
    t0 = vader_front_effects$is_unknown(l0);
    return t0;
}

bool __lambda_vader_front_effects_123(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    int32_t l3;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 1677u)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = ((vader_struct_vader_front_effects$CalleeIndex_t*) ((vader_struct_vader_front_effects$TaskCtx_t*) ((vader_struct___lambda_env_vader_front_effects_124_t*) l0)->f_cap_0)->f_index)->f_functions;
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_front_effects$CalleeNode_t*) t0)->f_node;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
    l4 = ((vader_struct_vader_front_effects$Function_t*) l2)->f_typed;
    l2 = ((vader_struct_vader_front_effects$Function_t*) l2)->f_decl;
    t1 = vader_front_typecheck$fn_is_generator(l4, l2);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_125(void* l0, vader_box_t l1) {
    int64_t l2;
    l2 = ((vader_struct_vader_front_effects$Site_t*) ((vader_struct___lambda_env_vader_front_effects_126_t*) l0)->f_cap_0)->f_result;
    return vader_box_eq(l1, vader_box_i64(633u, l2));
}

bool __lambda_vader_front_effects_127(void* l0, void* l1) {
    void* l2;
    void* l3;
    bool t0;
    l2 = ((vader_struct_toolchain_ast$CallExpr_t*) l1)->f_span;
    l3 = ((vader_struct_vader_front_effects$Site_t*) ((vader_struct___lambda_env_vader_front_effects_128_t*) l0)->f_cap_0)->f_at;
    t0 = vader_front_effects$same_span(l2, l3);
    return t0;
}

bool __lambda_vader_front_effects_129(void* l0, void* l1) {
    void* l2;
    int64_t l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_130_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_front_effects$Root_t*) l1)->f_param;
    t0 = std_collections$Set$std_core$Contains$contains__i64(l2, l3);
    return t0;
}

bool __lambda_vader_front_effects_13(void* l0, void* l1) {
    void* l2;
    vader_box_t l3;
    bool t0;
    l2 = ((vader_struct_vader_front_effects$TaskCtx_t*) ((vader_struct___lambda_env_vader_front_effects_14_t*) l0)->f_cap_0)->f_index;
    l3 = ((vader_struct_vader_front_effects$Site_t*) l1)->f_callee;
    t0 = vader_front_effects$opens_door(l2, l3);
    return t0;
}

bool __lambda_vader_front_effects_131(void* l0, void* l1) {
    void* l2;
    void* l4;
    int64_t l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_132_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_front_effects$Root_t*) l1)->f_param;
    l4 = ((vader_struct_toolchain_ast$LambdaExpr_t*) ((vader_struct___lambda_env_vader_front_effects_132_t*) l0)->f_cap_1)->f_span;
    t0 = vader_front_effects$bound_inside(l2, l3, l4);
    return !(t0);
}

bool __lambda_vader_front_effects_133(vader_box_t l0) {
    bool t0;
    if ((l0.tag == 1470u || l0.tag == 1484u)) {
        return true;
    }
    t0 = vader_core_types$is_null_type(l0);
    return t0;
}

bool __lambda_vader_front_effects_134(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_135_t*) l0)->f_cap_0;
    t0 = vader_front_effects$may_hold_view(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_136(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_137_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_effects_137_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_effects_137_t*) l0)->f_cap_2;
    t0 = vader_front_effects$may_be_written(l2, l1, l3, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_138(void* l0, void* l1) {
    void* l2;
    void* l3;
    void* t0;
    bool t1;
    l2 = ((vader_struct_vader_front_effects$Site_t*) l1)->f_at;
    t0 = ((vader_struct___lambda_env_vader_front_effects_139_t*) l0)->f_cap_0.payload.obj;
    l3 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_span;
    t1 = vader_front_effects$same_span(l2, l3);
    return t1;
}

bool __lambda_vader_front_effects_140(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    bool t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_141_t*) l0)->f_cap_0;
    vader_struct___lambda_env_vader_front_effects_143_t* _a0_obj = (vader_struct___lambda_env_vader_front_effects_143_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_effects_143_t));
    vader_obj_header_init(_a0_obj, 736u);
    _a0_obj->f_cap_0 = l1;
    l3 = (void*) _a0_obj;
    l4 = vader_array_length(((vader_array_t*) l2));
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l5);
        t0 = __lambda_vader_front_effects_142(l3, l6);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool __lambda_vader_front_effects_142(void* l0, void* l1) {
    void* l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_143_t*) l0)->f_cap_0;
    t0 = vader_front_effects$same_root(l1, l2);
    return t0;
}

bool __lambda_vader_front_effects_144(void* l0, vader_box_t l1) {
    void* l2;
    void* l3;
    vader_box_t l4;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_145_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_effects_145_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_effects_145_t*) l0)->f_cap_2;
    t0 = vader_front_effects$is_door_task(l2, l3, l4, l1);
    return t0;
}

uint8_t __lambda_vader_front_effects_146(void* l0, vader_box_t l1) {
    vader_box_t l2;
    int32_t l3;
    void* l4;
    void* l5;
    bool l6;
    bool t0;
    void* t1;
    if (l1.tag == 1177u) {
        return (uint8_t) 1;
    }
    if (l1.tag == 1161u) {
        l2 = ((vader_struct___lambda_env_vader_front_effects_147_t*) l0)->f_cap_0;
        l3 = vader_chk_add(i32, ((vader_struct_$Cell_i32_2af2b319_t*) ((vader_struct___lambda_env_vader_front_effects_147_t*) l0)->f_cap_0.payload.obj)->f_value, INT32_C(1));
        ((vader_struct_$Cell_i32_2af2b319_t*) l2.payload.obj)->f_value = l3;
    }
    l2 = l1;
    l4 = ((vader_struct___lambda_env_vader_front_effects_147_t*) l0)->f_cap_1;
    t0 = vader_front_effects$starts_past(l2, l4);
    if (t0) {
        return (uint8_t) 1;
    }
    if (l1.tag == 1195u) {
        t1 = l1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$ReturnStmt_t*) t1)->f_span;
        l5 = ((vader_struct___lambda_env_vader_front_effects_147_t*) l0)->f_cap_1;
        t0 = vader_front_effects$contains(l4, l5);
        if (t0) {
            return (uint8_t) 0;
        }
    }
    l2 = l1;
    l3 = ((vader_struct_$Cell_i32_2af2b319_t*) ((vader_struct___lambda_env_vader_front_effects_147_t*) l0)->f_cap_0.payload.obj)->f_value;
    t0 = vader_front_effects$escapes_1(l2, l3);
    if (t0) {
        return (uint8_t) 2;
    }
    if (l1.tag == 1129u) {
        l2 = ((vader_struct___lambda_env_vader_front_effects_147_t*) l0)->f_cap_2;
        if (((vader_struct_$Cell_bool_cd2fd49b_t*) ((vader_struct___lambda_env_vader_front_effects_147_t*) l0)->f_cap_2.payload.obj)->f_value) {
            l6 = true;
        } else {
            l6 = ((vader_struct_$Cell_i32_2af2b319_t*) ((vader_struct___lambda_env_vader_front_effects_147_t*) l0)->f_cap_0.payload.obj)->f_value == INT32_C(0);
        }
        ((vader_struct_$Cell_bool_cd2fd49b_t*) l2.payload.obj)->f_value = l6;
        return (uint8_t) 0;
    }
    return (uint8_t) 0;
}

void __lambda_vader_front_effects_148(void* l0, vader_box_t l1) {
    vader_box_t l2;
    int32_t l3;
    if (l1.tag == 1161u) {
        l2 = ((vader_struct___lambda_env_vader_front_effects_149_t*) l0)->f_cap_0;
        l3 = vader_chk_sub(i32, ((vader_struct_$Cell_i32_2af2b319_t*) ((vader_struct___lambda_env_vader_front_effects_149_t*) l0)->f_cap_0.payload.obj)->f_value, INT32_C(1));
        ((vader_struct_$Cell_i32_2af2b319_t*) l2.payload.obj)->f_value = l3;
        return;
    }
    return;
}

void* __lambda_vader_front_effects_15(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 632u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_150(int32_t l0, int32_t l1) {
    return (l0 < l1);
}

vader_string_t __lambda_vader_front_effects_151(int32_t l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(20));
    l2 = INT64_C(0);
    l3 = ((int64_t) (int32_t) l0);
    l2 = std_core$write_int(l1, l2, l3);
    t0 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_152(void* l0) {
    if (((vader_struct_vader_front_effects$Access_t*) l0)->f_effect == INT32_C(1)) {
        return ((vader_struct_vader_front_effects$Access_t*) l0)->f_path == INT64_C(0);
    }
    return false;
}

bool __lambda_vader_front_effects_153(void* l0, vader_box_t l1) {
    void* l2;
    int32_t l3;
    void* t0;
    bool t1;
    if (l1.tag == 1677u) {
        l2 = ((vader_struct___lambda_env_vader_front_effects_154_t*) l0)->f_cap_0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_front_effects$CalleeNode_t*) t0)->f_node;
        t1 = std_collections$Set$std_core$Contains$contains__i32(l2, l3);
        return t1;
    }
    return false;
}

bool __lambda_vader_front_effects_155(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_156_t*) l0)->f_cap_0;
    t0 = vader_front_effects$may_be_element(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_157(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$CallArg_t*) l1)->f_value;
    l3 = ((vader_struct___lambda_env_vader_front_effects_158_t*) l0)->f_cap_0;
    t0 = vader_front_effects$expr_reaches(l2, l3);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_effects_159(void* l0, vader_box_t l1) {
    void* t0;
    t0 = vader_front_effects$targets_of(((vader_struct___lambda_env_vader_front_effects_160_t*) l0)->f_cap_0, l1);
    return t0;
}

void* __lambda_vader_front_effects_16(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 8u, 633u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_161(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
    l3 = ((vader_struct___lambda_env_vader_front_effects_162_t*) l0)->f_cap_0;
    return l2 == l3;
}

vader_string_t __lambda_vader_front_effects_163(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_front_effects$FaultHop_t*) l0)->f_callee;
    return t0;
}

void* __lambda_vader_front_effects_17(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(302u, 0u, 13u, 1699u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_effects_18(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 629u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 629u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(315u, 0u, 13u, 1723u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 629u);
    l3 = (void*) _a3_arr;
    vader_struct_vader_front_effects$Reach_t* _a4_obj = (vader_struct_vader_front_effects$Reach_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_effects$Reach_t));
    vader_obj_header_init(_a4_obj, 1714u);
    _a4_obj->f_main_thread = l0;
    _a4_obj->f_parks = l1;
    _a4_obj->f_singletons = l2;
    _a4_obj->f_unknown = l3;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_effects_19(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 632u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t __lambda_vader_front_effects_2(void) {
    return INT64_C(0);
}

bool __lambda_vader_front_effects_20(void* l0, void* l1) {
    vader_box_t t0;
    t0 = vader_front_effects$singleton_of(((vader_struct___lambda_env_vader_front_effects_21_t*) l0)->f_cap_0, l1);
    return !(t0.tag == 0u);
}

void* __lambda_vader_front_effects_22(void* l0, int64_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_23_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_effects_23_t*) l0)->f_cap_1;
    t0 = vader_front_effects$lent_effects(l2, l3, l1);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_24(vader_box_t l0) {
    bool t0;
    t0 = vader_front_effects$holds_references(l0);
    return t0;
}

void* __lambda_vader_front_effects_25(void* l0) {
    void* t0;
    t0 = vader_front_effects$none();
    return t0;
}

bool __lambda_vader_front_effects_26(void* l0, void* l1) {
    void* l2;
    int64_t l3;
    void* t0;
    bool t1;
    l2 = ((vader_struct___lambda_env_vader_front_effects_27_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_front_effects$Root_t*) l1)->f_param;
    t0 = vader_front_effects$root_record(l2, l3);
    t1 = vader_front_effects$is_view(t0);
    if (!(t1)) {
        return true;
    }
    t1 = vader_front_effects$reaches(((vader_struct___lambda_env_vader_front_effects_27_t*) l0)->f_cap_1, l1);
    return t1;
}

bool __lambda_vader_front_effects_28(void* l0, void* l1) {
    void* l2;
    int64_t l3;
    void* t0;
    bool t1;
    l2 = ((vader_struct_vader_front_effects$RootCase_t*) ((vader_struct___lambda_env_vader_front_effects_29_t*) l0)->f_cap_0)->f_body;
    l3 = ((vader_struct_vader_front_effects$Root_t*) l1)->f_param;
    t0 = vader_front_effects$root_record(l2, l3);
    t1 = vader_front_effects$is_view(t0);
    return t1;
}

bool __lambda_vader_front_effects_3(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool l5;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_4_t*) l0)->f_cap_0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_front_effects_4_t*) l0)->f_cap_1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    t0 = vader_front_effects$has_news(l2, l1, l3);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = ((vader_struct___lambda_env_vader_front_effects_4_t*) l0)->f_cap_2;
    l3 = ((vader_struct___lambda_env_vader_front_effects_4_t*) l0)->f_cap_3;
    l4 = ((vader_struct___lambda_env_vader_front_effects_4_t*) l0)->f_cap_4;
    l2 = vader_front_effects$node_ctx(l2, l3, l4, l1);
    l3 = ((vader_struct___lambda_env_vader_front_effects_4_t*) l0)->f_cap_0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_front_effects_4_t*) l0)->f_cap_5);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l1);
    l5 = vader_front_effects$settle(t1, l2);
    t0 = vader_front_effects$noted(l3, l1, l5);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_30(void* l0) {
    bool l1;
    if (((vader_struct_vader_front_effects$Access_t*) l0)->f_effect == INT32_C(4)) {
        l1 = vader_front_effects$is_the_view(l0);
    } else {
        l1 = false;
    }
    if (l1) {
        return ((vader_struct_vader_front_effects$Access_t*) l0)->f_under == INT64_C(0);
    }
    return false;
}

bool __lambda_vader_front_effects_31(void* l0, void* l1) {
    bool l2;
    int64_t l3, l4;
    if (((vader_struct_vader_front_effects$Access_t*) l1)->f_effect == INT32_C(4)) {
        l2 = vader_front_effects$is_the_view(l1);
    } else {
        l2 = false;
    }
    if (l2) {
        l3 = ((vader_struct_vader_front_effects$Access_t*) l1)->f_under;
        l4 = ((vader_struct___lambda_env_vader_front_effects_32_t*) l0)->f_cap_0;
        return l3 == l4;
    }
    return false;
}

bool __lambda_vader_front_effects_33(void* l0, int32_t l1) {
    bool t0;
    t0 = std_collections$Set$std_core$Contains$contains__i32(((vader_struct___lambda_env_vader_front_effects_34_t*) l0)->f_cap_0, l1);
    return t0;
}

void* __lambda_vader_front_effects_35(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(291u, 0u, 13u, 1681u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_36(void* l0, vader_box_t l1) {
    int32_t l2, l3;
    void* t0;
    if (l1.tag == 1677u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_front_effects$CalleeNode_t*) t0)->f_node;
        l3 = ((vader_struct___lambda_env_vader_front_effects_37_t*) l0)->f_cap_0;
        return l2 == l3;
    }
    return false;
}

bool __lambda_vader_front_effects_38(void* l0, void* l1) {
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_front_effects$runs_unknown_value(l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = vader_front_effects$hands_a_value(((vader_struct___lambda_env_vader_front_effects_39_t*) l0)->f_cap_0, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t __lambda_vader_front_effects_40(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1161u) {
        l2 = ((vader_struct_vader_front_effects$BodyShape_t*) ((vader_struct___lambda_env_vader_front_effects_41_t*) l0)->f_cap_0)->f_repeats;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$ForStmt_t*) t0)->f_span;
        vader_array_push_ref((vader_array_t*) l2, l3);
        l2 = ((vader_struct_vader_front_effects$BodyShape_t*) ((vader_struct___lambda_env_vader_front_effects_41_t*) l0)->f_cap_0)->f_loops;
        l3 = l1.payload.obj;
        vader_array_push_ref((vader_array_t*) l2, l3);
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    if (l1.tag == 1177u) {
        l2 = ((vader_struct_vader_front_effects$BodyShape_t*) ((vader_struct___lambda_env_vader_front_effects_41_t*) l0)->f_cap_0)->f_repeats;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_toolchain_ast$LambdaExpr_t*) t0)->f_span;
        vader_array_push_ref((vader_array_t*) l2, l3);
        l2 = ((vader_struct_vader_front_effects$BodyShape_t*) ((vader_struct___lambda_env_vader_front_effects_41_t*) l0)->f_cap_0)->f_lambdas;
        l3 = l1.payload.obj;
        vader_array_push_ref((vader_array_t*) l2, l3);
    } else if (l1.tag == 1127u) {
        l2 = ((vader_struct_vader_front_effects$BodyShape_t*) ((vader_struct___lambda_env_vader_front_effects_41_t*) l0)->f_cap_0)->f_blocks;
        l3 = l1.payload.obj;
        vader_array_push_ref((vader_array_t*) l2, l3);
    } else if (l1.tag == 1178u) {
        l2 = ((vader_struct_vader_front_effects$BodyShape_t*) ((vader_struct___lambda_env_vader_front_effects_41_t*) l0)->f_cap_0)->f_lets;
        l3 = l1.payload.obj;
        vader_array_push_ref((vader_array_t*) l2, l3);
    } else if (l1.tag == 1131u) {
        l2 = ((vader_struct_vader_front_effects$BodyShape_t*) ((vader_struct___lambda_env_vader_front_effects_41_t*) l0)->f_cap_0)->f_calls;
        l3 = l1.payload.obj;
        vader_array_push_ref((vader_array_t*) l2, l3);
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
}

bool __lambda_vader_front_effects_42(void* l0, void* l1) {
    int64_t l2, l3;
    l2 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$LambdaExpr_t*) ((vader_struct_vader_front_effects$LambdaCalls_t*) l0)->f_lambda)->f_span)->f_end)->f_offset;
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$LambdaExpr_t*) ((vader_struct_vader_front_effects$LambdaCalls_t*) l1)->f_lambda)->f_span)->f_end)->f_offset;
    return (l2 < l3);
}

bool __lambda_vader_front_effects_43(void* l0, void* l1) {
    void* l2;
    void* l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_44_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_front_effects$Touch_t*) l1)->f_at;
    t0 = vader_front_effects$inside(l2, l3);
    return t0;
}

bool __lambda_vader_front_effects_45(void* l0, void* l1) {
    void* l2;
    void* l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_46_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_front_effects$Touch_t*) l1)->f_at;
    t0 = vader_front_effects$inside(l2, l3);
    return !(t0);
}

bool __lambda_vader_front_effects_47(void* l0, void* l1) {
    int64_t l2, l3;
    bool l4;
    uint8_t l5, l6;
    l2 = ((vader_struct_vader_front_effects$SingletonTouch_t*) l1)->f_singleton;
    l3 = ((vader_struct_vader_front_effects$SingletonTouch_t*) ((vader_struct___lambda_env_vader_front_effects_48_t*) l0)->f_cap_0)->f_singleton;
    if (l2 == l3) {
        l2 = ((vader_struct_vader_front_effects$SingletonTouch_t*) l1)->f_path;
        l3 = ((vader_struct_vader_front_effects$SingletonTouch_t*) ((vader_struct___lambda_env_vader_front_effects_48_t*) l0)->f_cap_0)->f_path;
        l4 = l2 == l3;
    } else {
        l4 = false;
    }
    if (l4) {
        l5 = ((vader_struct_vader_front_effects$SingletonTouch_t*) l1)->f_kind;
        l6 = ((vader_struct_vader_front_effects$SingletonTouch_t*) ((vader_struct___lambda_env_vader_front_effects_48_t*) l0)->f_cap_0)->f_kind;
        return l5 == l6;
    }
    return false;
}

bool __lambda_vader_front_effects_49(void* l0, void* l1) {
    void* l2 = NULL;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_50_t*) l0)->f_cap_0;
    t0 = vader_front_effects$holds(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_5(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_effects$Clock_t*) ((vader_struct___lambda_env_vader_front_effects_6_t*) l0)->f_cap_0)->f_grew_at);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
    l3 = ((vader_struct___lambda_env_vader_front_effects_6_t*) l0)->f_cap_1;
    return (l2 > l3);
}

void* __lambda_vader_front_effects_51(void* l0) {
    return ((vader_struct_vader_front_effects$Reach_t*) l0)->f_main_thread;
}

void* __lambda_vader_front_effects_52(void* l0) {
    return ((vader_struct_vader_front_effects$Reach_t*) l0)->f_unknown;
}

bool __lambda_vader_front_effects_53(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_vader_front_typecheck$ImplEntry_t*) l1)->f_trait_key;
    l3 = ((vader_struct___lambda_env_vader_front_effects_54_t*) l0)->f_cap_0;
    if (l2 == l3) {
        return !(((vader_struct_vader_front_typecheck$ImplEntry_t*) l1)->f_for_type.tag == 1484u);
    }
    return false;
}

bool __lambda_vader_front_effects_55(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_toolchain_ast$Decorator_t*) l0)->f_name;
    return t0 == 3292u;
}

bool __lambda_vader_front_effects_56(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool l5;
    int64_t l6, l7;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_57_t*) l0)->f_cap_0;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_ref_box(l1));
    t1 = t0.payload.b;
    if (t1) {
        l2 = ((vader_struct_vader_front_effects$RootCase_t*) ((vader_struct___lambda_env_vader_front_effects_57_t*) l0)->f_cap_1)->f_held;
        l3 = ((vader_struct___lambda_env_vader_front_effects_57_t*) l0)->f_cap_2;
        l4 = ((vader_struct___lambda_env_vader_front_effects_57_t*) l0)->f_cap_1;
        vader_struct___lambda_env_vader_front_effects_59_t* _a1_obj = (vader_struct___lambda_env_vader_front_effects_59_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_effects_59_t));
        vader_obj_header_init(_a1_obj, 761u);
        _a1_obj->f_cap_0 = l3;
        _a1_obj->f_cap_1 = l4;
        _a1_obj->f_cap_2 = l1;
        l3 = (void*) _a1_obj;
        l5 = false;
        l6 = vader_array_length(((vader_array_t*) l2));
        l7 = INT64_C(0);
        {
            while ((l7 < l6)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
                l4 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l7);
                t1 = __lambda_vader_front_effects_58(l3, l4);
                if (t1) {
                    l5 = true;
                    goto end_25;
                }
                l7 = (l7 + INT64_C(1));
            }
            l5 = false;
        } end_25: ;
        { bool __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool __lambda_vader_front_effects_58(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_59_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_effects_59_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_effects_59_t*) l0)->f_cap_2;
    t0 = vader_front_effects$written_at(l2, l3, l1, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_60(void* l0, void* l1) {
    bool t0;
    t0 = vader_front_effects$writes_view(((vader_struct_vader_front_effects$RootCase_t*) ((vader_struct___lambda_env_vader_front_effects_61_t*) l0)->f_cap_0)->f_paths, l1);
    return t0;
}

bool __lambda_vader_front_effects_62(void* l0) {
    bool t0;
    t0 = vader_front_effects$is_the_view(l0);
    if (t0) {
        t0 = vader_front_effects$keeps(l0);
        return t0;
    }
    return false;
}

bool __lambda_vader_front_effects_63(void* l0, void* l1) {
    int64_t l2, l3;
    bool l4;
    l2 = ((vader_struct_vader_front_effects$KeptInto_t*) l1)->f_value;
    l3 = ((vader_struct_vader_front_effects$KeptInto_t*) ((vader_struct___lambda_env_vader_front_effects_64_t*) l0)->f_cap_0)->f_value;
    if (l2 == l3) {
        l2 = ((vader_struct_vader_front_effects$KeptInto_t*) l1)->f_holder;
        l3 = ((vader_struct_vader_front_effects$KeptInto_t*) ((vader_struct___lambda_env_vader_front_effects_64_t*) l0)->f_cap_0)->f_holder;
        l4 = l2 == l3;
    } else {
        l4 = false;
    }
    if (l4) {
        l2 = ((vader_struct_vader_front_effects$KeptInto_t*) l1)->f_path;
        l3 = ((vader_struct_vader_front_effects$KeptInto_t*) ((vader_struct___lambda_env_vader_front_effects_64_t*) l0)->f_cap_0)->f_path;
        return l2 == l3;
    }
    return false;
}

bool __lambda_vader_front_effects_65(vader_box_t l0) {
    return l0.tag == 1674u;
}

bool __lambda_vader_front_effects_66(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t t0;
    l2 = vader_array_length(((vader_array_t*) ((vader_struct_vader_front_effects$Site_t*) ((vader_struct___lambda_env_vader_front_effects_67_t*) l0)->f_cap_0)->f_fn_args));
    if ((l1 >= l2)) {
        return true;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_effects$Site_t*) ((vader_struct___lambda_env_vader_front_effects_67_t*) l0)->f_cap_0)->f_fn_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    return t0.tag == 0u;
}

bool __lambda_vader_front_effects_68(void* l0, void* l1) {
    void* l2;
    void* l3;
    bool t0;
    l2 = ((vader_struct_toolchain_ast$CallExpr_t*) l1)->f_span;
    l3 = ((vader_struct_vader_front_effects$Site_t*) ((vader_struct___lambda_env_vader_front_effects_69_t*) l0)->f_cap_0)->f_at;
    t0 = vader_front_effects$same_span(l2, l3);
    return t0;
}

void* __lambda_vader_front_effects_7(void* l0) {
    int64_t l1;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_front_effects$Skeleton_t*) l0)->f_params;
    l2 = (void*) &vader_fn_static___lambda_vader_front_effects_8;
    t0 = std_core$filled__vader_front_effects_Sending(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_70(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    int64_t l3;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_71_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_effects_71_t*) l0)->f_cap_1;
    t0 = vader_front_effects$target_hands_to(l2, l1, l3);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_72(void* l0, void* l1) {
    int64_t l2, l3;
    l2 = ((vader_struct_vader_front_effects$Mark_t*) l1)->f_slot;
    l3 = ((vader_struct___lambda_env_vader_front_effects_73_t*) l0)->f_cap_0;
    return l2 == l3;
}

bool __lambda_vader_front_effects_74(void* l0, void* l1) {
    void* l2;
    void* l3;
    bool l4;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_75_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_front_effects$JoinPoint_t*) l1)->f_block;
    t0 = vader_front_effects$contains(l2, l3);
    if (t0) {
        l4 = ((vader_struct___lambda_env_vader_front_effects_75_t*) l0)->f_cap_1;
        t0 = vader_front_effects$stays_until_joined(l1, l4);
        return t0;
    }
    return false;
}

bool __lambda_vader_front_effects_76(void* l0, vader_box_t l1) {
    void* l2;
    void* l3;
    bool t0;
    l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$AssignStmt_t, f_span, l1.payload.obj);
    l3 = ((vader_struct_toolchain_ast$ForStmt_t*) ((vader_struct___lambda_env_vader_front_effects_77_t*) l0)->f_cap_0)->f_span;
    t0 = vader_front_effects$same_span(l2, l3);
    return t0;
}

bool __lambda_vader_front_effects_78(void* l0, void* l1) {
    void* l2;
    bool t0;
    l2 = ((vader_struct_toolchain_ast$LambdaExpr_t*) ((vader_struct_vader_front_effects$LambdaCalls_t*) ((vader_struct___lambda_env_vader_front_effects_79_t*) l0)->f_cap_0)->f_lambda)->f_span;
    t0 = vader_front_effects$same_span(l1, l2);
    return t0;
}

void* __lambda_vader_front_effects_8(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 8u, 633u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(30u, 0u, 8u, 633u);
    l1 = (void*) _a1_arr;
    vader_struct_vader_front_effects$Sending_t* _a2_obj = (vader_struct_vader_front_effects$Sending_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_effects$Sending_t));
    vader_obj_header_init(_a2_obj, 1720u);
    _a2_obj->f_runs = false;
    _a2_obj->f_given = l0;
    _a2_obj->f_written = l1;
    _a2_obj->f_launcher = 0u;
    _a2_obj->f_many = false;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_80(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    bool t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_81_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_front_effects$LambdaRun_t*) l1)->f_at;
    t0 = vader_front_effects$runs_in(l2, l3);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_82(void* l0, void* l1) {
    void* l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_83_t*) l0)->f_cap_0;
    t0 = vader_front_effects$inside(l1, l2);
    return t0;
}

bool __lambda_vader_front_effects_84(void* l0, void* l1) {
    void* l2;
    void* l3;
    bool t0;
    l2 = ((vader_struct_toolchain_ast$CallExpr_t*) l1)->f_span;
    l3 = ((vader_struct_vader_front_effects$Site_t*) ((vader_struct___lambda_env_vader_front_effects_85_t*) l0)->f_cap_0)->f_at;
    t0 = vader_front_effects$same_span(l2, l3);
    return t0;
}

bool __lambda_vader_front_effects_86(void* l0, void* l1) {
    void* l2;
    void* l3;
    bool t0;
    l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast$CallExpr_t*) l1)->f_callee.payload.obj);
    l3 = ((vader_struct_toolchain_ast$LambdaExpr_t*) ((vader_struct___lambda_env_vader_front_effects_87_t*) l0)->f_cap_0)->f_span;
    t0 = vader_front_effects$same_span(l2, l3);
    return t0;
}

bool __lambda_vader_front_effects_88(void* l0, vader_box_t l1) {
    void* l2;
    int64_t l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_effects_89_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_effects_89_t*) l0)->f_cap_1;
    t0 = vader_front_effects$keeps_param(l2, l1, l3);
    return t0;
}

void* __lambda_vader_front_effects_9(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(315u, 0u, 13u, 1723u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_90(vader_box_t l0) {
    bool t0;
    t0 = vader_front_effects$may_be_function(l0);
    return t0;
}

bool __lambda_vader_front_effects_91(void* l0, void* l1) {
    int64_t l2, l3;
    bool t0;
    if (((vader_struct_vader_front_effects$Touch_t*) l1)->f_kind != INT32_C(1)) {
        return false;
    }
    l2 = ((vader_struct_vader_front_effects$Touch_t*) l1)->f_root;
    l3 = ((vader_struct_vader_front_effects$Touch_t*) ((vader_struct___lambda_env_vader_front_effects_92_t*) l0)->f_cap_0)->f_root;
    if (l2 != l3) {
        return false;
    }
    l2 = ((vader_struct_vader_front_effects$Touch_t*) l1)->f_path;
    l3 = ((vader_struct_vader_front_effects$Touch_t*) ((vader_struct___lambda_env_vader_front_effects_92_t*) l0)->f_cap_0)->f_path;
    if (!(l2 == l3)) {
        l2 = ((vader_struct_vader_front_effects$Touch_t*) ((vader_struct___lambda_env_vader_front_effects_92_t*) l0)->f_cap_0)->f_path;
        l3 = ((vader_struct_vader_front_effects$Touch_t*) l1)->f_path;
        t0 = vader_front_effects$extends(l2, l3);
        return t0;
    }
    return false;
}

bool __lambda_vader_front_effects_93(void* l0, void* l1) {
    int64_t l2, l3;
    l2 = ((vader_struct_vader_front_effects$Touch_t*) l1)->f_root;
    l3 = ((vader_struct_vader_front_effects$Touch_t*) ((vader_struct___lambda_env_vader_front_effects_94_t*) l0)->f_cap_0)->f_root;
    if (l2 == l3) {
        l2 = ((vader_struct_vader_front_effects$Touch_t*) l1)->f_path;
        l3 = ((vader_struct_vader_front_effects$Touch_t*) ((vader_struct___lambda_env_vader_front_effects_94_t*) l0)->f_cap_0)->f_path;
        return l2 == l3;
    }
    return false;
}

bool __lambda_vader_front_effects_95(void* l0, void* l1) {
    int64_t l2, l3;
    vader_string_t l4, l5;
    void* t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
    l2 = ((vader_struct_vader_front_effects$Touch_t*) t0)->f_root;
    l3 = ((vader_struct_vader_front_effects$Touch_t*) ((vader_struct___lambda_env_vader_front_effects_96_t*) l0)->f_cap_0)->f_root;
    if (l2 == l3) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
        l4 = ((vader_struct_vader_front_effects$Touch_t*) t0)->f_by;
        l5 = ((vader_struct_vader_front_effects$Touch_t*) ((vader_struct___lambda_env_vader_front_effects_96_t*) l0)->f_cap_0)->f_by;
        return l4 == l5;
    }
    return false;
}

bool __lambda_vader_front_effects_97(void* l0, void* l1) {
    int64_t l2, l3;
    bool t0;
    l2 = ((vader_struct_vader_front_effects$Touch_t*) l1)->f_root;
    l3 = ((vader_struct_vader_front_effects$Touch_t*) ((vader_struct___lambda_env_vader_front_effects_98_t*) l0)->f_cap_0)->f_root;
    if (l2 == l3) {
        l2 = ((vader_struct_vader_front_effects$Touch_t*) l1)->f_path;
        l3 = ((vader_struct_vader_front_effects$Touch_t*) ((vader_struct___lambda_env_vader_front_effects_98_t*) l0)->f_cap_0)->f_path;
        t0 = vader_front_effects$overlaps(l2, l3);
        return t0;
    }
    return false;
}

bool __lambda_vader_front_effects_99(void* l0, void* l1) {
    int64_t l2, l3;
    void* l4;
    void* l5;
    bool t0;
    l2 = ((vader_struct_vader_front_effects$Candidate_t*) l1)->f_root;
    l3 = ((vader_struct_vader_front_effects$Candidate_t*) ((vader_struct___lambda_env_vader_front_effects_100_t*) l0)->f_cap_0)->f_root;
    if (l2 == l3) {
        l4 = ((vader_struct_vader_front_effects$Candidate_t*) l1)->f_at;
        l5 = ((vader_struct_vader_front_effects$Candidate_t*) ((vader_struct___lambda_env_vader_front_effects_100_t*) l0)->f_cap_0)->f_at;
        t0 = vader_front_effects$holds_strictly(l4, l5);
        return t0;
    }
    return false;
}

uint8_t __lambda_vader_front_reach_0(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_reach_1_t*) l0)->f_cap_0;
    t0 = vader_front_reach$referenced_name(l1, l2);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_resolver_0(void* l0, void* l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_resolver$GeneratedCode_t*) ((vader_struct___lambda_env_vader_front_resolver_1_t*) l0)->f_cap_0)->f_shipped_interfaces;
    l3 = ((vader_struct_vader_front_resolver$GeneratedSource_t*) l1)->f_file;
    t0 = std_collections$Set$std_core$Contains$contains__string(l2, l3);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    l2 = ((vader_struct___lambda_env_vader_front_resolver_1_t*) l0)->f_cap_1;
    t1 = ((vader_struct_vader_front_resolver$GeneratedSource_t*) l1)->f_file;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    t2 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_string(629u, t1));
    t0 = t2.payload.b;
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_resolver_10(void* l0, vader_box_t l1) {
    uint8_t l2;
    vader_string_t l3 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = toolchain_stage$Stage$describe$$dispatch(l1);
    l2 = ((vader_struct_toolchain_stage$ModuleSpec_t*) t0.payload.obj)->f_form;
    l3 = ((vader_struct___lambda_env_vader_front_resolver_11_t*) l0)->f_cap_0;
    t1 = toolchain_stage$serves_path(l2, l3);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_12(void* l0, void* l1) {
    void* l2 = NULL;
    bool l3;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_resolver_13_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_resolver_13_t*) l0)->f_cap_1;
    t0 = vader_front_resolver$read_and_parse(l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_resolver_14(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t t0;
    bool t1;
    l1 = ((vader_struct_toolchain_stage$SourceSpec_t*) l0)->f_given;
    l2 = vader_array_length(((vader_array_t*) l1));
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
        t1 = __lambda_vader_front_resolver_15(t0);
        if (t1) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static bool __lambda_vader_front_resolver_15(vader_box_t l0) {
    return l0.tag == 1271u;
}

bool __lambda_vader_front_resolver_16(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l3 = 0;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_resolver_17_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_resolver_17_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_resolver_17_t*) l0)->f_cap_2;
    l5 = ((vader_struct___lambda_env_vader_front_resolver_17_t*) l0)->f_cap_3;
    t0 = vader_front_resolver$names_given(l2, l3, l4, l1, l5);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_front_resolver_18(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    bool t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l6 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_body.tag == 0u) {
        t0 = toolchain_ast$has_compiler_decorator(((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_decorators, (uint8_t) 14);
        if (t0) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l3 = ((vader_struct___lambda_env_vader_front_resolver_19_t*) l0)->f_cap_0;
        l4 = ((vader_struct___lambda_env_vader_front_resolver_19_t*) l0)->f_cap_1;
        l5 = ((vader_struct___lambda_env_vader_front_resolver_19_t*) l0)->f_cap_2;
        vader_struct_vader_front_resolver$LateFn_t* _a0_obj = (vader_struct_vader_front_resolver$LateFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_resolver$LateFn_t));
        vader_obj_header_init(_a0_obj, 1758u);
        _a0_obj->f_module = l4;
        _a0_obj->f_decl = l1;
        _a0_obj->f_owner = l2;
        _a0_obj->f_stage = l5;
        l6 = (void*) _a0_obj;
        vader_array_push_ref((vader_array_t*) l3, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_vader_front_resolver_2(void* l0) {
    vader_string_t t0;
    bool t1;
    t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_diagnostics$Diagnostic_t*) l0)->f_primary)->f_start)->f_file;
    t1 = vader_front_resolver$is_generated_file(t0);
    return t1;
}

bool __lambda_vader_front_resolver_20(void* l0, void* l1) {
    vader_string_t l2, l3;
    bool t0;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_name;
    t0 = std_string$compare_ascending(l2, l3);
    return t0;
}

void* __lambda_vader_front_resolver_21(void* l0) {
    void* t0;
    t0 = toolchain_ast$module_decorators(((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_program);
    return t0;
}

bool __lambda_vader_front_resolver_22(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_toolchain_ast$Program_t*) ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_program)->f_decls;
    l2 = vader_array_length(((vader_array_t*) l1));
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
        t1 = vader_front_resolver$is_test(t0);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

vader_string_t __lambda_vader_front_resolver_23(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_toolchain_ast$FnParam_t*) l0)->f_name;
    return t0;
}

vader_box_t __lambda_vader_front_resolver_24(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_resolver_25_t*) l0)->f_cap_0;
    t0 = vader_front_resolver$substitute_type_expr(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_26(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_resolver_27_t*) l0)->f_cap_0;
    t0 = vader_front_resolver$unplaced_param(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_28(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 629u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_front_resolver_29(int64_t l0) {
    void* l1 = NULL;
    int64_t l2;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(25));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 2008u);
    l2 = std_core$write_int(l1, l2, l0);
    t0 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_3(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    bool l3;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_front_resolver_4_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_front_resolver_4_t*) l0)->f_cap_1;
    l3 = ((vader_struct___lambda_env_vader_front_resolver_4_t*) l0)->f_cap_2;
    t0 = vader_front_resolver$parse_lot(l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_30(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(218u, 0u, 13u, 1463u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_resolver_31(void* l0) {
    vader_string_t t0 = 0;
    bool t1;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_span)->f_start)->f_file;
    t1 = vader_front_resolver$is_generated_by(t0, 2347u);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_resolver_32(void* l0, void* l1) {
    vader_box_t l2;
    vader_string_t l3;
    l2 = ((vader_struct_toolchain_ast$ImportName_t*) l1)->f_alias;
    l3 = ((vader_struct___lambda_env_vader_front_resolver_33_t*) l0)->f_cap_0;
    return vader_box_eq(l2, vader_box_string(629u, l3));
}

bool __lambda_vader_front_resolver_34(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_toolchain_ast$ImportName_t*) l1)->f_name;
    l3 = ((vader_struct___lambda_env_vader_front_resolver_35_t*) l0)->f_cap_0;
    if (l2 == l3) {
        return !(((vader_struct_toolchain_ast$ImportName_t*) l1)->f_alias.tag == 0u);
    }
    return false;
}

void* __lambda_vader_front_resolver_36(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l3 = 0;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = ((vader_struct_toolchain_protocol$ReportFrame_t*) l2)->f_code;
    l4 = ((vader_struct_toolchain_protocol$ReportFrame_t*) l1)->f_span;
    l5 = ((vader_struct_vader_front_resolver$DriverNames_t*) ((vader_struct___lambda_env_vader_front_resolver_37_t*) l0)->f_cap_0)->f_read;
    l4 = toolchain_protocol$renamed_span(l4, l5);
    l6 = ((vader_struct_toolchain_protocol$ReportFrame_t*) l2)->f_detail;
    vader_struct_toolchain_protocol$ReportFrame_t* _a0_obj = (vader_struct_toolchain_protocol$ReportFrame_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_protocol$ReportFrame_t));
    vader_obj_header_init(_a0_obj, 1260u);
    _a0_obj->f_code = l3;
    _a0_obj->f_span = l4;
    _a0_obj->f_detail = l6;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_front_resolver_38(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_toolchain_ast$Program_t*) l0)->f_file;
    return t0;
}

void* __lambda_vader_front_resolver_39(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_resolver$DriverNames_t*) ((vader_struct___lambda_env_vader_front_resolver_40_t*) l0)->f_cap_0)->f_read;
    t0 = toolchain_protocol$renamed_span(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_resolver_41(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_vader_core_wit$WitOwner_t*) ((vader_struct_vader_core_wit$WitInterface_t*) l1)->f_owner)->f_interface;
    l3 = ((vader_struct___lambda_env_vader_front_resolver_42_t*) l0)->f_cap_0;
    return l2 == l3;
}

bool __lambda_vader_front_resolver_43(vader_string_t l0) {
    bool t0;
    t0 = std_string$ends_with(l0, 535u);
    return t0;
}

vader_box_t __lambda_vader_front_resolver_44(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_resolver_45_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_resolver_45_t*) l0)->f_cap_1;
    t0 = vader_front_resolver$dependency_of(l2, l3, l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_5(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_core$Intrinsic$deep_copy__string__(((vader_struct_vader_front_resolver$DiscoveredModule_t*) l0)->f_files);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_6(void* l0) {
    return l0;
}

bool __lambda_vader_front_resolver_7(void* l0) {
    bool t0;
    t0 = std_collections$is_empty__string__string(((vader_struct_vader_front_resolver$DiscoveredModule_t*) l0)->f_texts);
    return t0;
}

void* __lambda_vader_front_resolver_8(vader_box_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_stage$Stage$describe$$dispatch(l0);
    { void* __vret = t0.payload.obj; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_resolver_9(void* l0) {
    vader_string_t t0;
    bool t1;
    t0 = ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_path;
    t1 = vader_front_resolver$is_generated_file(t0);
    return t1;
}

bool __lambda_vader_front_typecheck_0(void* l0, void* l1) {
    void* l2;
    vader_string_t l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_1_t*) l0)->f_cap_0;
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_diagnostics$Diagnostic_t*) l1)->f_primary)->f_start)->f_file;
    t0 = std_collections$Set$std_core$Contains$contains__string(l2, l3);
    return t0;
}

void* __lambda_vader_front_typecheck_10(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 629u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 640u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 632u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__Any___t* _a3_obj = (vader_struct_std_collections$Map__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any___t));
    vader_obj_header_init(_a3_obj, 983u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_front_typecheck_11(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_12_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_12_t*) l0)->f_cap_1;
    vader_front_typecheck$register_named(l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

void* __lambda_vader_front_typecheck_13(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(72u, 0u, 13u, 1158u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_14(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 629u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 640u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 632u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__Any_____t* _a3_obj = (vader_struct_std_collections$Map__string__Any_____t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_____t));
    vader_obj_header_init(_a3_obj, 984u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_15(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 13u, 484u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_16(void* l0) {
    return !(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_body.tag == 0u);
}

bool __lambda_vader_front_typecheck_17(void* l0) {
    return !(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_inherits.tag == 0u);
}

uint8_t __lambda_vader_front_typecheck_18(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_19_t*) l0)->f_cap_0;
    t0 = vader_front_typecheck$collect_tested_type(l1, l2);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_2(void* l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_front_typecheck_3_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_3_t*) l0)->f_cap_1;
    t0 = vader_front_typecheck$build_namespace_private_names(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_20(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct___lambda_env_vader_front_typecheck_21_t*) l0)->f_cap_0)->f_id;
    return l2 == l3;
}

void* __lambda_vader_front_typecheck_22(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(356u, 0u, 13u, 1811u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_23(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(363u, 0u, 13u, 1827u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_24(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) l1)->f_symbol)->f_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct___lambda_env_vader_front_typecheck_25_t*) l0)->f_cap_0)->f_id;
    return l2 == l3;
}

void __lambda_vader_front_typecheck_26(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1487u) {
        l2 = ((vader_struct___lambda_env_vader_front_typecheck_27_t*) l0)->f_cap_0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_types$TypeParamType_t*) t0)->f_symbol;
        vader_array_push_ref((vader_array_t*) l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void* __lambda_vader_front_typecheck_28(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(361u, 0u, 13u, 1824u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_front_typecheck_29(void* l0, vader_box_t l1) {
    vader_array_push_ref((vader_array_t*) ((vader_struct___lambda_env_vader_front_typecheck_30_t*) l0)->f_cap_0, l1.payload.obj);
    return;
}

void* __lambda_vader_front_typecheck_31(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(346u, 0u, 13u, 1791u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_32(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(362u, 0u, 13u, 1825u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t __lambda_vader_front_typecheck_33(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_34_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_34_t*) l0)->f_cap_1;
    t0 = vader_front_typecheck$copy_node_resolutions(l1, l2, l3);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_front_typecheck_35(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_front_typecheck_36_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_36_t*) l0)->f_cap_1;
    t0 = vader_front_typecheck$contract_of(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_front_typecheck_37(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_front_typecheck_38_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_38_t*) l0)->f_cap_1;
    t0 = vader_front_typecheck$ensures_of(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_front_typecheck_39(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_core_types$display_type(l0);
    t0 = concat_3(1312u, l1, 1312u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_4(void* l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_front_typecheck_5_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_5_t*) l0)->f_cap_1;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_5_t*) l0)->f_cap_2;
    t0 = vader_front_typecheck$build_namespace_type_members(l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t __lambda_vader_front_typecheck_40(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_41_t*) l0)->f_cap_0;
    t0 = vader_front_typecheck$probe_step(l1, l2);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t __lambda_vader_front_typecheck_42(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l5, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1177u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 1; }
    }
    if (l1.tag == 1131u) {
        l2 = ((vader_struct___lambda_env_vader_front_typecheck_43_t*) l0)->f_cap_0;
        l3 = l1.payload.obj;
        l4 = vader_front_typecheck$recorded_decl(l2, l3);
        if (!(l4.tag == 0u)) {
            t0 = l4.payload.obj;
            t1 = toolchain_ast$has_compiler_decorator(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators, (uint8_t) 21);
            if (t1) {
                l5 = ((vader_struct_toolchain_ast$ConstDecl_t*) ((vader_struct___lambda_env_vader_front_typecheck_43_t*) l0)->f_cap_1)->f_name;
                t0 = l4.payload.obj;
                l6 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                l5 = concat_5(1312u, l5, 1358u, l6, 1312u);
                l2 = ((vader_struct___lambda_env_vader_front_typecheck_43_t*) l0)->f_cap_2;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_span;
                l3 = toolchain_diagnostics$typecheck_error((uint8_t) 95, l3, l5);
                vader_array_push_ref((vader_array_t*) l2, l3);
            }
        }
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
}

bool __lambda_vader_front_typecheck_44(void* l0, vader_box_t l1) {
    bool t0;
    t0 = vader_front_typecheck$keeps_concrete(((vader_struct___lambda_env_vader_front_typecheck_45_t*) l0)->f_cap_0, l1);
    return t0;
}

vader_box_t __lambda_vader_front_typecheck_46(vader_box_t l0) {
    vader_box_t t0;
    t0 = vader_core_types$default_if_free(l0);
    return t0;
}

bool __lambda_vader_front_typecheck_47(void* l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_toolchain_ast$FieldExpr_t*) ((vader_struct___lambda_env_vader_front_typecheck_48_t*) l0)->f_cap_0)->f_span)->f_start)->f_file;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_48_t*) l0)->f_cap_1;
    t0 = vader_front_typecheck$sees_trait_key(l1, l2, l3);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_49(void* l0, void* l1) {
    void* l2;
    void* l4;
    vader_string_t l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_50_t*) l0)->f_cap_0;
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct___lambda_env_vader_front_typecheck_50_t*) l0)->f_cap_1)->f_start)->f_file;
    l4 = ((vader_struct_vader_core_types$TraitType_t*) l1)->f_symbol;
    t0 = vader_front_typecheck$sees_trait(l2, l3, l4);
    return t0;
}

bool __lambda_vader_front_typecheck_51(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_types$trait_key_of(((vader_struct_vader_core_types$TraitType_t*) l1)->f_symbol);
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_52_t*) l0)->f_cap_0;
    { bool __vret = l2 == l3; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_front_typecheck_53(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    vader_box_t l3 = vader_box_null();
    bool l5;
    int64_t l6, l7, l10, l11;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[3] = { &l1, &l3, &t0 };
    void** gc_raw_roots[6] = { &l0, &l2, &l4, &l8, &l9, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_core_types$union_variants(l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l3.payload.obj;
    l4 = l2;
    l5 = false;
    l6 = vader_array_length(((vader_array_t*) l4));
    l7 = INT64_C(0);
    {
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l7);
            t1 = vader_core_types$is_null_type(t0);
            if (t1) {
                l5 = true;
                goto end_18;
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = false;
    } end_18: ;
    if (!(l5)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = vader_array_length(((vader_array_t*) l2));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l7);
        l3 = vader_front_typecheck$written_param(t0);
        if (l3.tag == 0u) {
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l4 = l3.payload.obj;
        l8 = ((vader_struct___lambda_env_vader_front_typecheck_54_t*) l0)->f_cap_0;
        vader_struct___lambda_env_vader_front_typecheck_56_t* _a2_obj = (vader_struct___lambda_env_vader_front_typecheck_56_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_typecheck_56_t));
        vader_obj_header_init(_a2_obj, 815u);
        _a2_obj->f_cap_0 = l4;
        l9 = (void*) _a2_obj;
        l5 = false;
        l10 = vader_array_length(((vader_array_t*) l8));
        l11 = INT64_C(0);
        {
            while ((l11 < l10)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                l12 = vader_array_ref_load_obj(_a3_slotarr->buf, vader_array_offset(_a3_slotarr) + (size_t) l11);
                t1 = __lambda_vader_front_typecheck_55(l9, l12);
                if (t1) {
                    l5 = true;
                    goto end_86;
                }
                l11 = (l11 + INT64_C(1));
            }
            l5 = false;
        } end_86: ;
        if (!(l5)) {
            vader_array_push_ref((vader_array_t*) ((vader_struct___lambda_env_vader_front_typecheck_54_t*) l0)->f_cap_0, l4);
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static bool __lambda_vader_front_typecheck_55(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct___lambda_env_vader_front_typecheck_56_t*) l0)->f_cap_0)->f_id;
    return l2 == l3;
}

void __lambda_vader_front_typecheck_57(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_58_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_58_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_typecheck_58_t*) l0)->f_cap_2;
    vader_front_typecheck$check_guard_return(l2, l1, l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_front_typecheck_59(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l3 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_60_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_60_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_typecheck_60_t*) l0)->f_cap_2;
    l5 = ((vader_struct___lambda_env_vader_front_typecheck_60_t*) l0)->f_cap_3;
    vader_front_typecheck$check_ensured_value(l2, l1, l3, l4, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

void* __lambda_vader_front_typecheck_6(void* l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_front_typecheck_7_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_7_t*) l0)->f_cap_1;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_7_t*) l0)->f_cap_2;
    t0 = vader_front_typecheck$build_namespace_exports(l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_61(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) ((vader_struct___lambda_env_vader_front_typecheck_62_t*) l0)->f_cap_0)->f_symbol)->f_id;
    return l2 == l3;
}

bool __lambda_vader_front_typecheck_63(void* l0, void* l1) {
    vader_string_t l2;
    void* l3;
    vader_box_t t0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_64_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_64_t*) l0)->f_cap_1;
    t0 = vader_front_typecheck$trait_member_decl(l1, l2, l3);
    return !(t0.tag == 0u);
}

bool __lambda_vader_front_typecheck_65(void* l0) {
    return !(((vader_struct_vader_front_typecheck$ImplMethod_t*) l0)->f_return_of.tag == 0u);
}

void* __lambda_vader_front_typecheck_66(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_67_t*) l0)->f_cap_0;
    t0 = vader_front_typecheck$settled_member(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_68(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TraitType_t*) l1)->f_symbol)->f_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct___lambda_env_vader_front_typecheck_69_t*) l0)->f_cap_0)->f_id;
    return l2 == l3;
}

bool __lambda_vader_front_typecheck_70(vader_box_t l0) {
    return l0.tag == 1481u;
}

bool __lambda_vader_front_typecheck_71(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) l1)->f_symbol)->f_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$InferVar_t*) ((vader_struct___lambda_env_vader_front_typecheck_72_t*) l0)->f_cap_0)->f_origin)->f_id;
    return l2 == l3;
}

bool __lambda_vader_front_typecheck_73(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    bool l4;
    int64_t l5, l6;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1487u) {
        l2 = ((vader_struct___lambda_env_vader_front_typecheck_74_t*) l0)->f_cap_0;
        vader_struct___lambda_env_vader_front_typecheck_76_t* _a0_obj = (vader_struct___lambda_env_vader_front_typecheck_76_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_typecheck_76_t));
        vader_obj_header_init(_a0_obj, 825u);
        _a0_obj->f_cap_0 = l1;
        l3 = (void*) _a0_obj;
        l4 = false;
        l5 = vader_array_length(((vader_array_t*) l2));
        l6 = INT64_C(0);
        {
            while ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l7 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l6);
                t0 = __lambda_vader_front_typecheck_75(l3, l7);
                if (t0) {
                    l4 = true;
                    goto end_15;
                }
                l6 = (l6 + INT64_C(1));
            }
            l4 = false;
        } end_15: ;
        { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static bool __lambda_vader_front_typecheck_75(void* l0, void* l1) {
    int32_t l2, l3;
    void* t0;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
    t0 = ((vader_struct___lambda_env_vader_front_typecheck_76_t*) l0)->f_cap_0.payload.obj;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) t0)->f_symbol)->f_id;
    return l2 == l3;
}

bool __lambda_vader_front_typecheck_77(void* l0, vader_string_t l1) {
    vader_string_t l2;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_78_t*) l0)->f_cap_0;
    return l1 == l2;
}

bool __lambda_vader_front_typecheck_79(void* l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    void* l3 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_80_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_80_t*) l0)->f_cap_1;
    t0 = vader_front_typecheck$struct_implements_trait(l1, l2, l3);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_8(void* l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_front_typecheck_9_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_9_t*) l0)->f_cap_1;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_9_t*) l0)->f_cap_2;
    t0 = vader_front_typecheck$namespace_fn_overloads_of(l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_81(vader_box_t l0) {
    void* l1 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = (void*) &vader_fn_static___lambda_vader_front_typecheck_82;
    t0 = vader_core_types$any_type(l0, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_82(vader_box_t l0) {
    return l0.tag == 1480u;
}

bool __lambda_vader_front_typecheck_83(vader_box_t l0) {
    bool t0;
    t0 = vader_front_typecheck$nests_self(l0);
    return t0;
}

bool __lambda_vader_front_typecheck_84(vader_box_t l0) {
    return l0.tag == 1480u;
}

void* __lambda_vader_front_typecheck_85(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 629u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_86(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 629u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_lower_0(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_1;
    vader_lower$push_struct_shape(l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

vader_box_t __lambda_vader_lower_10(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_lower_11_t*) l0)->f_cap_0;
    t0 = vader_core_types$substitute(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_lower_12(void* l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    void* l7 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l2, &l7, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = (void*) vader_buffer_new((size_t) INT64_C(21));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l2, l3, 3152u);
    l4 = vader_array_length(((vader_array_t*) ((vader_struct_vader_lower$GenBuild_t*) ((vader_struct___lambda_env_vader_lower_13_t*) l0)->f_cap_0)->f_fields));
    l3 = std_core$write_int(l2, l3, l4);
    l1 = std_core$finish_buffer(l2, l3);
    l2 = ((vader_struct___lambda_env_vader_lower_13_t*) l0)->f_cap_0;
    l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct___lambda_env_vader_lower_13_t*) l0)->f_cap_1)->f_id;
    t0 = vader_lower$gb_is_cell(l2, l6);
    if (t0) {
        t1 = (void*) &vader_data_45;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
        l5 = vader_ref_box(t1);
    } else {
        l5 = ((vader_struct___lambda_env_vader_lower_13_t*) l0)->f_cap_2;
    }
    l2 = ((vader_struct_vader_lower$GenBuild_t*) ((vader_struct___lambda_env_vader_lower_13_t*) l0)->f_cap_0)->f_fields;
    vader_struct_vader_lower_ir$LoweredStructField_t* _a1_obj = (vader_struct_vader_lower_ir$LoweredStructField_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredStructField_t));
    vader_obj_header_init(_a1_obj, 1975u);
    _a1_obj->f_name = l1;
    _a1_obj->f_type = l5;
    l7 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l2, l7);
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_lower_14(void* l0, vader_box_t l1) {
    void* l2;
    void* l3;
    void* l4;
    bool t0;
    if (l1.tag == 1163u) {
        l2 = ((vader_struct___lambda_env_vader_lower_15_t*) l0)->f_cap_0;
        l3 = l1.payload.obj;
        l4 = ((vader_struct___lambda_env_vader_lower_15_t*) l0)->f_cap_1;
        t0 = vader_lower$names_symbol(l2, l3, l4);
        return t0;
    }
    return false;
}

uint8_t __lambda_vader_lower_16(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_lower_17_t*) l0)->f_cap_0;
    t0 = vader_lower$enter_node(l1, l2);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_lower_18(void* l0, vader_box_t l1) {
    if (l1.tag == 1985u) {
        ((vader_struct_$Cell_bool_cd2fd49b_t*) ((vader_struct___lambda_env_vader_lower_19_t*) l0)->f_cap_0.payload.obj)->f_value = true;
        return;
    }
    return;
}

void* __lambda_vader_lower_2(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 629u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(35u, 0u, 0u, 640u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(29u, 0u, 7u, 632u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__Any_t* _a3_obj = (vader_struct_std_collections$Map__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__Any_t));
    vader_obj_header_init(_a3_obj, 982u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_lower_20(vader_box_t l0) {
    bool t0;
    t0 = vader_core_types$contains_distinct(l0);
    return t0;
}

bool __lambda_vader_lower_21(void* l0, vader_box_t l1) {
    void* l2;
    void* l3;
    bool t0;
    l2 = ((vader_struct_vader_lower$CallTarget_t*) ((vader_struct___lambda_env_vader_lower_22_t*) l0)->f_cap_0)->f_owner;
    l3 = ((vader_struct___lambda_env_vader_lower_22_t*) l0)->f_cap_1;
    t0 = vader_lower$loops_over(l1, l2, l3);
    return t0;
}

void* __lambda_vader_lower_23(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    int64_t l5, l6;
    vader_box_t l8 = vader_box_null();
    int64_t t0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(218u, 0u, 13u, 1463u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct___lambda_env_vader_lower_24_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct___lambda_env_vader_lower_24_t*) l0)->f_cap_1)->f_resolved;
    l2 = vader_lower$ensure_local_symbol_index(l2, l3);
    l3 = ((vader_struct_std_collections$Map__u64__vader_core_symbol_Symbol_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$Map__u64__vader_core_symbol_Symbol_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$Map__u64__vader_core_symbol_Symbol_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = ((int64_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l5];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l5);
        t1 = vader_core_symbol$is_local_binding(((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_kind);
        if (t1) {
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_defined_at;
            if (!(l8.tag == 0u)) {
                l7 = l8.payload.obj;
                t1 = vader_lower$starts_within(((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct___lambda_env_vader_lower_24_t*) l0)->f_cap_2)->f_span, l7);
                if (t1) {
                    vader_array_push_ref((vader_array_t*) l1, l2);
                }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_lower_25(void* l0, void* l1) {
    void* l2;
    int32_t l3;
    vader_box_t l4;
    void* t0;
    l2 = ((vader_struct___lambda_env_vader_lower_26_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) l1)->f_symbol)->f_id;
    l4 = std_collections$Map$std_core$Index$at__i32__Any(l2, l3);
    if (l4.tag == 0u) {
        t0 = (void*) &vader_data_45;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    return l4;
}

void* __lambda_vader_lower_27(void* l0) {
    void* l1 = NULL;
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_lower_28_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_lower_28_t*) l0)->f_cap_1;
    l3 = ((vader_struct___lambda_env_vader_lower_28_t*) l0)->f_cap_2;
    vader_struct_vader_lower$ObservedFn_t* _a0_obj = (vader_struct_vader_lower$ObservedFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower$ObservedFn_t));
    vader_obj_header_init(_a0_obj, 1906u);
    _a0_obj->f_decl = vader_ref_box(l1);
    _a0_obj->f_trait_key = l2;
    _a0_obj->f_name = l3;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_lower_3(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_vader_core_wit$WitNamedFunction_t*) l1)->f_name;
    l3 = ((vader_struct___lambda_env_vader_lower_4_t*) l0)->f_cap_0;
    return l2 == l3;
}

bool __lambda_vader_lower_5(vader_box_t l0) {
    bool t0;
    if (l0.tag == 1468u) {
        return true;
    }
    t0 = vader_core_types$is_refinement(l0);
    return t0;
}

vader_box_t __lambda_vader_lower_6(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_lower_7_t*) l0)->f_cap_0;
    t0 = vader_core_types$substitute(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_lower_8(void* l0, vader_box_t l1) {
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_lower$kept_argument(((vader_struct___lambda_env_vader_lower_9_t*) l0)->f_cap_0, l1);
    t1 = vader_lower$kept_suffix(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_lower_dce_0(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int32_t l4;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_core_types$struct_backing(l1);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct___lambda_env_vader_lower_dce_1_t*) l0)->f_cap_0;
    t0 = l2.payload.obj;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
    std_collections$add__i32(l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

void* __lambda_vader_lower_dce_2(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(407u, 0u, 13u, 1984u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_lower_dce_3(void* l0, int32_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    void* l4 = NULL;
    bool t0;
    vader_box_t* gc_roots[2] = { &l3, &l5 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = std_collections$Map$std_core$Index$at__string__Any(((vader_struct___lambda_env_vader_lower_dce_4_t*) l0)->f_cap_0, l2);
    if (l3.tag == 0u) {
        l5 = std_collections$Map$std_core$Index$at__i32__Any(((vader_struct___lambda_env_vader_lower_dce_4_t*) l0)->f_cap_3, l1);
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        t0 = std_collections$add__i32(((vader_struct___lambda_env_vader_lower_dce_4_t*) l0)->f_cap_4, l1);
        if (t0) {
            l4 = ((vader_struct___lambda_env_vader_lower_dce_4_t*) l0)->f_cap_2;
            vader_array_push_ref((vader_array_t*) l4, l5.payload.obj);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = std_collections$add__string(((vader_struct___lambda_env_vader_lower_dce_4_t*) l0)->f_cap_1, l2);
    if (t0) {
        l4 = ((vader_struct___lambda_env_vader_lower_dce_4_t*) l0)->f_cap_2;
        vader_array_push_ref((vader_array_t*) l4, l3.payload.obj);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_lower_dce_5(void* l0, vader_string_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_3(l1, 3792u, l2);
    t0 = std_collections$add__string(((vader_struct___lambda_env_vader_lower_dce_6_t*) l0)->f_cap_0, l3);
    if (t0) {
        vader_array_push_scalar((vader_array_t*) ((vader_struct___lambda_env_vader_lower_dce_6_t*) l0)->f_cap_1, vader_box_string(629u, l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_lower_dce_7(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_lower_dce_8_t*) l0)->f_cap_0;
    vader_core_types$for_each_type(l1, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_lower_ir_0(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1985u) {
        l2 = ((vader_struct___lambda_env_vader_lower_ir_1_t*) l0)->f_cap_0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredYield_t*) t0)->f_span;
        l4 = ((vader_struct___lambda_env_vader_lower_ir_1_t*) l0)->f_cap_1;
        l5 = ((vader_struct___lambda_env_vader_lower_ir_1_t*) l0)->f_cap_2;
        l4 = concat_5(1951u, l4, 1691u, l5, 1664u);
        l3 = toolchain_diagnostics$internal_error((uint8_t) 0, l3, l4);
        vader_array_push_ref((vader_array_t*) l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_lower_ir_2(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_string_t l4 = 0;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1965u) {
        l2 = ((vader_struct___lambda_env_vader_lower_ir_3_t*) l0)->f_cap_0;
        l3 = l1.payload.obj;
        t0 = vader_lower_ir$binds_bare_capture(l2, l3);
        if (t0) {
            l2 = ((vader_struct___lambda_env_vader_lower_ir_3_t*) l0)->f_cap_1;
            l3 = l1.payload.obj;
            l4 = ((vader_struct___lambda_env_vader_lower_ir_3_t*) l0)->f_cap_2;
            l3 = vader_lower_ir$bare_capture_error(l3, l4);
            vader_array_push_ref((vader_array_t*) l2, l3);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_vader_lower_ir_4(void* l0) {
    bool t0;
    t0 = vader_lower_ir$expr_runs_code(((vader_struct_vader_lower_ir$LoweredStructLitField_t*) l0)->f_value);
    return t0;
}

void __lambda_vader_lower_optimise_0(void* l0, vader_box_t l1) {
    bool t0;
    t0 = vader_lower_optimise$pc_stmt_exits(l1);
    if (t0) {
        ((vader_struct_$Cell_bool_cd2fd49b_t*) ((vader_struct___lambda_env_vader_lower_optimise_1_t*) l0)->f_cap_0.payload.obj)->f_value = true;
        return;
    }
    return;
}

void __lambda_vader_lower_optimise_2(void* l0, vader_box_t l1) {
    bool l2;
    if (l1.tag == 1941u) {
        l2 = true;
    } else {
        l2 = l1.tag == 1949u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1.tag == 1972u;
    }
    if (l2) {
        ((vader_struct_$Cell_bool_cd2fd49b_t*) ((vader_struct___lambda_env_vader_lower_optimise_3_t*) l0)->f_cap_0.payload.obj)->f_value = true;
        return;
    }
    return;
}

bool __lambda_vader_midir_0(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int32_t l5;
    vader_box_t l6 = vader_box_null();
    bool l7;
    int64_t l8, l9;
    bool t0, t2;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_midir$instruction_runs_code(l1);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = ((vader_struct_vader_midir$ShrinkSummary_t*) ((vader_struct___lambda_env_vader_midir_1_t*) l0)->f_cap_0)->f_may_shrink;
    if (l1.tag == 2026u) {
        l3 = ((vader_struct_vader_midir$CallGraph_t*) ((vader_struct_vader_midir$ShrinkSummary_t*) ((vader_struct___lambda_env_vader_midir_1_t*) l0)->f_cap_0)->f_calls)->f_index;
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrCall_t*) t1)->f_callee;
        l5 = vader_midir$callee_node(l3, l4);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l5];
        t2 = t0;
        { bool __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_midir$CallGraph_t*) ((vader_struct_vader_midir$ShrinkSummary_t*) ((vader_struct___lambda_env_vader_midir_1_t*) l0)->f_cap_0)->f_calls)->f_index;
    l6 = l1;
    l3 = vader_midir$instruction_callees(l3, l6);
    t0 = vader_midir$is_shrinking_intrinsic(l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    vader_struct___lambda_env_vader_midir_3_t* _a1_obj = (vader_struct___lambda_env_vader_midir_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_3_t));
    vader_obj_header_init(_a1_obj, 857u);
    _a1_obj->f_cap_0 = l2;
    l2 = (void*) _a1_obj;
    l7 = false;
    l8 = vader_array_length(((vader_array_t*) l3));
    l9 = INT64_C(0);
    {
        while ((l9 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l5 = ((int32_t*) _a2_slotarr->buf->slots)[vader_array_offset(_a2_slotarr) + (size_t) l9];
            t0 = __lambda_vader_midir_2(l2, l5);
            if (t0) {
                l7 = true;
                goto end_55;
            }
            l9 = (l9 + INT64_C(1));
        }
        l7 = false;
    } end_55: ;
    { bool __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_midir_10(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 632u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_midir_11(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(29u, 0u, 7u, 632u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_midir_12(void* l0, int32_t l1) {
    int64_t l2;
    void* l3;
    int32_t l4;
    int32_t t0;
    l2 = ((int64_t) (int32_t) l1);
    l3 = ((vader_struct___lambda_env_vader_midir_13_t*) l0)->f_cap_0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_midir_13_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = ((int32_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l2];
    l4 = vader_chk_add(i32, t0, INT32_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    ((int32_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l2] = (int32_t) l4;
    return;
}

void __lambda_vader_midir_14(void* l0, int32_t l1, void* l2, vader_string_t l3) {
    bool l4;
    int32_t l5, l6;
    void* l7 = NULL;
    void* l12 = NULL;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l13 = 0;
    int64_t l10, l11;
    bool t0;
    int32_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[5] = { &l0, &l2, &l7, &l12, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l8, &l9, &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 < INT32_C(0))) {
        l4 = true;
    } else {
        l5 = l1;
        l6 = ((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_0;
        l4 = (l5 >= l6);
    }
    if (l4) {
        t0 = std_collections$add__vader_midir$LocalId(((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_1, l1);
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l7 = ((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_2;
        l8 = ((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_3;
        l9 = l3;
        l10 = vader_host_std_core$Intrinsic$byte_len(l8);
        l11 = vader_host_std_core$Intrinsic$byte_len(l9);
        l10 = (l10 + l11);
        l12 = (void*) vader_buffer_new((size_t) (INT64_C(79) + l10));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l12, l10, l8);
        l10 = std_core$write_string_at(l12, l10, 566u);
        l10 = std_core$write_string_at(l12, l10, l9);
        l10 = std_core$write_string_at(l12, l10, 230u);
        l11 = ((int64_t) (int32_t) l1);
        l10 = std_core$write_int(l12, l10, l11);
        l10 = std_core$write_string_at(l12, l10, 456u);
        t1 = ((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_0;
        l11 = ((int64_t) (int32_t) t1);
        l10 = std_core$write_int(l12, l10, l11);
        l10 = std_core$write_string_at(l12, l10, 221u);
        l8 = std_core$finish_buffer(l12, l10);
        l12 = toolchain_diagnostics$internal_error((uint8_t) 4, l2, l8);
        vader_array_push_ref((vader_array_t*) l7, l12);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = std_collections$Set$std_core$Contains$contains__i32(((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_4, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = std_collections$add__vader_midir$LocalId(((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_5, l1);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = ((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_2;
    l8 = ((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_3;
    l12 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_6)->f_locals;
    l5 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l12);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
    l9 = ((vader_struct_vader_midir$CFGLocal_t*) t2)->f_name;
    l13 = l3;
    l10 = vader_host_std_core$Intrinsic$byte_len(l8);
    l11 = vader_host_std_core$Intrinsic$byte_len(l9);
    l10 = (l10 + l11);
    l11 = vader_host_std_core$Intrinsic$byte_len(l13);
    l10 = (l10 + l11);
    l12 = (void*) vader_buffer_new((size_t) (INT64_C(61) + l10));
    l10 = INT64_C(0);
    l10 = std_core$write_string_at(l12, l10, l8);
    l10 = std_core$write_string_at(l12, l10, 596u);
    l11 = ((int64_t) (int32_t) l1);
    l10 = std_core$write_int(l12, l10, l11);
    l10 = std_core$write_string_at(l12, l10, 116u);
    l10 = std_core$write_string_at(l12, l10, l9);
    l10 = std_core$write_string_at(l12, l10, 1514u);
    l10 = std_core$write_string_at(l12, l10, l13);
    l10 = std_core$write_string_at(l12, l10, 136u);
    l8 = std_core$finish_buffer(l12, l10);
    l12 = toolchain_diagnostics$internal_error((uint8_t) 5, l2, l8);
    vader_array_push_ref((vader_array_t*) l7, l12);
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_midir_16(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_string_t l7 = 0;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_midir_17_t*) l0)->f_cap_0;
    l3 = VADER_UNION_FIELD(void*, vader_struct_vader_midir$InstrArrayGet_t, f_span, ((vader_struct___lambda_env_vader_midir_17_t*) l0)->f_cap_1.payload.obj);
    l4 = (void*) vader_buffer_new((size_t) INT64_C(22));
    l5 = INT64_C(0);
    l5 = std_core$write_string_at(l4, l5, 2072u);
    l6 = ((int64_t) (int32_t) ((vader_struct_vader_midir$BasicBlock_t*) ((vader_struct___lambda_env_vader_midir_17_t*) l0)->f_cap_2)->f_id);
    l5 = std_core$write_int(l4, l5, l6);
    l7 = std_core$finish_buffer(l4, l5);
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    ((vader_fn_erased_sig_3_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(632u, l1), vader_ref_box(l3), vader_box_string(629u, l7));
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_midir_18(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_string_t l7 = 0;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_midir_19_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_midir$BasicBlock_t*) ((vader_struct___lambda_env_vader_midir_19_t*) l0)->f_cap_1)->f_span;
    l4 = (void*) vader_buffer_new((size_t) INT64_C(35));
    l5 = INT64_C(0);
    l5 = std_core$write_string_at(l4, l5, 2072u);
    l6 = ((int64_t) (int32_t) ((vader_struct_vader_midir$BasicBlock_t*) ((vader_struct___lambda_env_vader_midir_19_t*) l0)->f_cap_1)->f_id);
    l5 = std_core$write_int(l4, l5, l6);
    l5 = std_core$write_string_at(l4, l5, 380u);
    l7 = std_core$finish_buffer(l4, l5);
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    ((vader_fn_erased_sig_3_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(632u, l1), vader_ref_box(l3), vader_box_string(629u, l7));
    { vader_gc_top = gc_frame.prev; return; }
}

static bool __lambda_vader_midir_2(void* l0, int32_t l1) {
    bool t0, t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_midir_3_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
    t1 = t0;
    return t1;
}

bool __lambda_vader_midir_20(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions;
    l2 = vader_array_length(((vader_array_t*) l1));
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
        t1 = vader_midir$is_shrinking_intrinsic(t0);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

void __lambda_vader_midir_21(void* l0, int32_t l1) {
    void* l2;
    int64_t l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_midir_22_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_midir_22_t*) l0)->f_cap_1;
    t0 = vader_midir$has_bit(l2, l3, l1);
    if (t0) {
        return;
    }
    l2 = ((vader_struct___lambda_env_vader_midir_22_t*) l0)->f_cap_2;
    l3 = ((vader_struct___lambda_env_vader_midir_22_t*) l0)->f_cap_1;
    vader_midir$set_bit(l2, l3, l1);
    return;
}

void __lambda_vader_midir_23(void* l0, vader_box_t l1) {
    vader_box_t l2;
    int32_t l3;
    void* t0;
    bool t1;
    if (l1.tag == 1937u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredAssign_t*) t0)->f_target;
        l3 = ((vader_struct___lambda_env_vader_midir_24_t*) l0)->f_cap_0;
        t1 = vader_midir$names_variable(l2, l3);
        if (t1) {
            ((vader_struct_$Cell_bool_cd2fd49b_t*) ((vader_struct___lambda_env_vader_midir_24_t*) l0)->f_cap_1.payload.obj)->f_value = true;
            return;
        }
        return;
    }
    return;
}

bool __lambda_vader_midir_4(void* l0, int64_t l1) {
    vader_box_t t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_midir_5_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l1);
    return t0.tag == 1996u;
}

bool __lambda_vader_midir_6(void* l0, int64_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    bool t1, t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_midir_7_t*) l0)->f_cap_0;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(633u, l1));
    t1 = t0.payload.b;
    if (t1) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$ShrinkSummary_t*) ((vader_struct___lambda_env_vader_midir_7_t*) l0)->f_cap_1)->f_may_shrink);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t1 = ((uint8_t*) _a1_slotarr->buf->slots)[vader_array_offset(_a1_slotarr) + (size_t) l1];
        t2 = t1;
        { bool __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

bool __lambda_vader_midir_8(void* l0, int64_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_midir_9_t*) l0)->f_cap_0;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(633u, l1));
    t1 = t0.payload.b;
    if (t1) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_midir_9_t*) l0)->f_cap_1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l1);
        t1 = vader_midir$node_shrinks_by_itself(t0);
        { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

void __lambda_vader_midir_optimise_0(void* l0, int32_t l1) {
    vader_midir_optimise$mark_referenced(((vader_struct___lambda_env_vader_midir_optimise_1_t*) l0)->f_cap_0, l1);
    return;
}

void __lambda_vader_midir_optimise_2(void* l0, int32_t l1) {
    int32_t l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_midir_optimise_3_t*) l0)->f_cap_0;
    t0 = vader_midir$LocalId$std_core$Equals$equals(l1, l2);
    if (t0) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_midir_optimise_3_t*) l0)->f_cap_1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0)] = (uint8_t) true;
        return;
    }
    return;
}

bool __lambda_vader_midir_ranges_0(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct___Tuple_2_471c43984d8ea035_t*) l0)->f__0;
    l3 = ((vader_struct___Tuple_2_471c43984d8ea035_t*) l1)->f__0;
    return (vader_string_compare(l2, l3) < INT32_C(0));
}

void* __lambda_vader_midir_ranges_1(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_midir_ranges_2_t*) l0)->f_cap_0;
    t0 = vader_midir_ranges$mark_in_function(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_midir_ranges_3(void* l0, void* l1) {
    int64_t l2, l3;
    l2 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_midir_ranges$RangeSite_t*) l0)->f_span)->f_start)->f_offset;
    l3 = ((vader_struct_toolchain_span$Position_t*) ((vader_struct_toolchain_span$Span_t*) ((vader_struct_vader_midir_ranges$RangeSite_t*) l1)->f_span)->f_start)->f_offset;
    return (l2 < l3);
}

void* __lambda_vader_midir_ranges_4(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_midir_ranges_5_t*) l0)->f_cap_0;
    t0 = vader_midir_ranges$mark_block(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_midir_ranges_6(int64_t l0, int64_t l1) {
    return (l0 < l1);
}

bool __lambda_vader_pipeline_0(void* l0, vader_string_t l1) {
    bool t0;
    t0 = vader_pipeline$holds_a_function(((vader_struct___lambda_env_vader_pipeline_1_t*) l0)->f_cap_0, l1);
    return t0;
}

bool __lambda_vader_pipeline_2(vader_box_t l0) {
    return l0.tag == 1956u;
}

vader_string_t __lambda_vader_pipeline_3(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module;
    return t0;
}

vader_string_t __lambda_vader_pipeline_check_0(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_front_resolver$LateFn_t*) l0)->f_module;
    return t0;
}

bool __lambda_vader_pipeline_check_1(void* l0, vader_box_t l1) {
    uint8_t l2, l3;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_stage$Stage$describe$$dispatch(l1);
    l2 = ((vader_struct_vader_pipeline_check$CheckSpec_t*) t0.payload.obj)->f_purpose;
    l3 = ((vader_struct___lambda_env_vader_pipeline_check_2_t*) l0)->f_cap_0;
    { bool __vret = l2 == l3; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_pipeline_check_3(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_front_resolver$SourceFile_t*) l0)->f_path;
    return t0;
}

bool __lambda_vader_pipeline_check_4(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_vader_front_resolver$LateFn_t*) l1)->f_module;
    l3 = ((vader_struct_vader_pipeline_check$ModuleBodies_t*) ((vader_struct___lambda_env_vader_pipeline_check_5_t*) l0)->f_cap_0)->f_module_id;
    return l2 == l3;
}

bool __lambda_vader_pipeline_check_6(void* l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = toolchain_stage$Stage$describe$$dispatch(l1);
    l2 = ((vader_struct_toolchain_stage$BodySpec_t*) t0.payload.obj)->f_name;
    l3 = ((vader_struct_vader_front_resolver$LateFn_t*) ((vader_struct___lambda_env_vader_pipeline_check_7_t*) l0)->f_cap_0)->f_stage;
    { bool __vret = l2 == l3; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_pipeline_check_8(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_pipeline_check$StageKey_t* _a0_obj = (vader_struct_vader_pipeline_check$StageKey_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline_check$StageKey_t));
    vader_obj_header_init(_a0_obj, 2096u);
    _a0_obj->f_module = l0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_pipeline_comptime__vm_0(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_pipeline_comptime__vm_1_t*) l0)->f_cap_0;
    t0 = vader_pipeline_comptime__vm$retargeted(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_pipeline_comptime__vm_10(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_name;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct___lambda_env_vader_pipeline_comptime__vm_11_t*) l0)->f_cap_0)->f_mangled;
    return l2 == l3;
}

vader_box_t __lambda_vader_pipeline_comptime__vm_12(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_pipeline_comptime__vm_13_t*) l0)->f_cap_0;
    t0 = vader_pipeline_comptime__vm$retargeted_type(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_pipeline_comptime__vm_14(void* l0, vader_string_t l1) {
    bool t0;
    t0 = std_collections$Map$std_core$Contains$contains__string__Any(((vader_struct___lambda_env_vader_pipeline_comptime__vm_15_t*) l0)->f_cap_0, l1);
    return t0;
}

bool __lambda_vader_pipeline_comptime__vm_2(void* l0, void* l1) {
    void* l2;
    vader_string_t l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_pipeline_comptime__vm_3_t*) l0)->f_cap_0.payload.obj;
    l3 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l1)->f_module_id;
    t0 = std_core$$array$Contains$contains__string(l2, l3);
    return t0;
}

bool __lambda_vader_pipeline_comptime__vm_4(void* l0, void* l1) {
    vader_string_t l2, l3;
    void* l4;
    bool t0;
    l2 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l1)->f_callee;
    l3 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) ((vader_struct___lambda_env_vader_pipeline_comptime__vm_5_t*) l0)->f_cap_0)->f_callee;
    if (l2 != l3) {
        l4 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) ((vader_struct___lambda_env_vader_pipeline_comptime__vm_5_t*) l0)->f_cap_0)->f_reached;
        l2 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l1)->f_callee;
        t0 = std_collections$Set$std_core$Contains$contains__string(l4, l2);
        return t0;
    }
    return false;
}

bool __lambda_vader_pipeline_comptime__vm_6(void* l0, vader_string_t l1) {
    bool t0;
    t0 = std_collections$Set$std_core$Contains$contains__string(((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) ((vader_struct___lambda_env_vader_pipeline_comptime__vm_7_t*) l0)->f_cap_0)->f_reached, l1);
    return t0;
}

bool __lambda_vader_pipeline_comptime__vm_8(void* l0) {
    bool t0;
    t0 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l0)->f_read_at_compile_time;
    return t0;
}

int64_t __lambda_vader_pipeline_comptime__vm_9(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_vader_front_comptime$VmRequiredDecl_t*) l0)->f_callee_decl_id;
    return t0;
}

int32_t __lambda_vader_support_fixpoint_0(void) {
    return INT32_C(0);
}

bool __lambda_vader_support_fixpoint_1(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool l5;
    int64_t l6, l7;
    int32_t l8;
    bool t0, t1;
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_support_fixpoint_2_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
    t1 = t0;
    if (t1) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = ((vader_struct___lambda_env_vader_support_fixpoint_2_t*) l0)->f_cap_0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_support_fixpoint$Graph_t*) ((vader_struct___lambda_env_vader_support_fixpoint_2_t*) l0)->f_cap_1)->f_successors);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l3 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l1);
    vader_struct___lambda_env_vader_support_fixpoint_4_t* _a2_obj = (vader_struct___lambda_env_vader_support_fixpoint_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_support_fixpoint_4_t));
    vader_obj_header_init(_a2_obj, 877u);
    _a2_obj->f_cap_0 = ((vader_struct___lambda_env_vader_support_fixpoint_2_t*) l0)->f_cap_0;
    l4 = (void*) _a2_obj;
    l5 = false;
    l6 = vader_array_length(((vader_array_t*) l3));
    l7 = INT64_C(0);
    {
        while ((l7 < l6)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l8 = ((int32_t*) _a3_slotarr->buf->slots)[vader_array_offset(_a3_slotarr) + (size_t) l7];
            t0 = __lambda_vader_support_fixpoint_3(l4, l8);
            if (t0) {
                l5 = true;
                goto end_24;
            }
            l7 = (l7 + INT64_C(1));
        }
        l5 = false;
    } end_24: ;
    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l1)
    ((uint8_t*) _a4_slotarr->buf->slots)[vader_array_offset(_a4_slotarr) + (size_t) l1] = (uint8_t) l5;
    vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_support_fixpoint_2_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
    t0 = ((uint8_t*) _a5_slotarr->buf->slots)[vader_array_offset(_a5_slotarr) + (size_t) l1];
    t1 = t0;
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool __lambda_vader_support_fixpoint_3(void* l0, int32_t l1) {
    bool t0, t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_support_fixpoint_4_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
    t1 = t0;
    return t1;
}

void* __lambda_vader_support_profile_0(void) {
    void* l0 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_support_profile$Counters_t* _a0_obj = (vader_struct_vader_support_profile$Counters_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_profile$Counters_t));
    vader_obj_header_init(_a0_obj, 2108u);
    _a0_obj->f_peak_rss = INT64_C(0);
    _a0_obj->f_copied = INT64_C(0);
    _a0_obj->f_allocated = INT64_C(0);
    _a0_obj->f_allocations = INT64_C(0);
    _a0_obj->f_collections = INT64_C(0);
    l0 = (void*) _a0_obj;
    vader_struct_vader_support_profile$PassTotals_t* _a1_obj = (vader_struct_vader_support_profile$PassTotals_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_profile$PassTotals_t));
    vader_obj_header_init(_a1_obj, 2110u);
    _a1_obj->f_wall_ns = INT64_C(0);
    _a1_obj->f_calls = INT64_C(0);
    _a1_obj->f_change = l0;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_support_profile_1(void* l0) {
    int64_t t0;
    t0 = ((vader_struct_vader_support_profile$PassTime_t*) l0)->f_ns;
    return (t0 >= INT64_C(100000));
}

bool __lambda_vader_support_profile_2(void* l0) {
    int64_t l1, l2;
    int64_t t0;
    l1 = ((vader_struct_vader_support_profile$StageTime_t*) l0)->f_sources_ns;
    l2 = ((vader_struct_vader_support_profile$StageTime_t*) l0)->f_bodies_ns;
    t0 = vader_chk_add(i64, l1, l2);
    return (t0 >= INT64_C(100000));
}

bool __lambda_vader_support_profile_3(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_vader_support_profile$StageTime_t*) l1)->f_name;
    l3 = ((vader_struct___lambda_env_vader_support_profile_4_t*) l0)->f_cap_0;
    return l2 == l3;
}

vader_box_t __lambda_vader_vm_0(void* l0, void* l1) {
    void* l2;
    int32_t l3;
    uint8_t t0;
    vader_box_t t1;
    l2 = ((vader_struct_vader_core_bytecode$BytecodeModule_t*) ((vader_struct___lambda_env_vader_vm_1_t*) l0)->f_cap_0)->f_types;
    l3 = ((vader_struct_vader_core_bytecode$BcGlobal_t*) l1)->f_type_id;
    t0 = vader_vm$field_valtype(l2, l3);
    t1 = vader_vm$global_zero(t0);
    return t1;
}

bool __lambda_vader_vm_11(void* l0, void* l1) {
    int64_t l2, l3;
    l2 = ((vader_struct_vader_vm$GuestThread_t*) l0)->f_number;
    l3 = ((vader_struct_vader_vm$GuestThread_t*) l1)->f_number;
    return (l2 < l3);
}

void* __lambda_vader_vm_12(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_vm_13_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_vm_13_t*) l0)->f_cap_1;
    t0 = vader_vm$parked_stack(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_vm_14(int64_t l0) {
    vader_host_std_core$Intrinsic$stop_waiting(l0);
    return;
}

void __lambda_vader_vm_15(int64_t l0) {
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_host_std_core$Intrinsic$wait_writable(l0);
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_vm_16(int64_t l0) {
    vader_host_std_core$Intrinsic$watch_exit(l0);
    return;
}

void __lambda_vader_vm_17(int64_t l0) {
    vader_host_std_core$Intrinsic$watch_readable(l0);
    return;
}

void __lambda_vader_vm_18(int64_t l0) {
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_host_std_core$Intrinsic$sleep_for(l0);
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_vm_19(int64_t l0) {
    vader_host_std_core$Intrinsic$wake(l0);
    return;
}

bool __lambda_vader_vm_2(void) {
    return false;
}

void __lambda_vader_vm_20(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    bool l3;
    vader_box_t l4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_vm_21_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_vm_21_t*) l0)->f_cap_1.payload.obj;
    l3 = ((vader_struct___lambda_env_vader_vm_21_t*) l0)->f_cap_2;
    l4 = ((vader_struct___lambda_env_vader_vm_21_t*) l0)->f_cap_3;
    vader_vm$run_guest_thread(l1, l2, l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_vader_vm_3(void* l0, vader_box_t l1) {
    void* l2;
    int32_t l3;
    void* t0;
    bool t1, t2;
    if (l1.tag == 1328u) {
        l2 = ((vader_struct___lambda_env_vader_vm_4_t*) l0)->f_cap_0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((uint8_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l3];
        t2 = t1;
        return t2;
    }
    return false;
}

vader_string_t __lambda_vader_vm_5(int64_t l0) {
    void* l1 = NULL;
    int64_t l2;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(26));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l1, l2, 3288u);
    l2 = std_core$write_int(l1, l2, l0);
    t0 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_vm_6(void* l0, int64_t l1, int64_t l2) {
    int64_t l3, l4;
    l3 = vader_vm$number_of(((vader_struct___lambda_env_vader_vm_7_t*) l0)->f_cap_0, l1);
    l4 = vader_vm$number_of(((vader_struct___lambda_env_vader_vm_7_t*) l0)->f_cap_0, l2);
    return (l3 < l4);
}

vader_box_t __lambda_vader_vm_8(void) {
    void* t0;
    t0 = (void*) &vader_data_103;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    return vader_ref_box(t0);
}

void* __lambda_vader_vm_9(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_vm_10_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_vm_10_t*) l0)->f_cap_1;
    t0 = vader_vm$parked_stack(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_10(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8, vader_string_t l9) {
    int64_t l10, l11, l12, l13, l14, l15, l16, l17, l18, l19;
    void* l20 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l20 };
    vader_string_t* gc_atom_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 11u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l10 = vader_host_std_core$Intrinsic$byte_len(l0);
    l11 = vader_host_std_core$Intrinsic$byte_len(l1);
    l11 = (l10 + l11);
    l12 = vader_host_std_core$Intrinsic$byte_len(l2);
    l12 = (l11 + l12);
    l13 = vader_host_std_core$Intrinsic$byte_len(l3);
    l13 = (l12 + l13);
    l14 = vader_host_std_core$Intrinsic$byte_len(l4);
    l14 = (l13 + l14);
    l15 = vader_host_std_core$Intrinsic$byte_len(l5);
    l15 = (l14 + l15);
    l16 = vader_host_std_core$Intrinsic$byte_len(l6);
    l16 = (l15 + l16);
    l17 = vader_host_std_core$Intrinsic$byte_len(l7);
    l17 = (l16 + l17);
    l18 = vader_host_std_core$Intrinsic$byte_len(l8);
    l18 = (l17 + l18);
    l19 = vader_host_std_core$Intrinsic$byte_len(l9);
    l19 = (l18 + l19);
    l20 = (void*) vader_buffer_new((size_t) l19);
    vader_buffer_write_string((vader_buffer_t*) l20, (size_t) INT64_C(0), l0);
    vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l10, l1);
    vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l11, l2);
    vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l12, l3);
    vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l13, l4);
    vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l14, l5);
    vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l15, l6);
    vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l16, l7);
    vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l17, l8);
    vader_buffer_write_string((vader_buffer_t*) l20, (size_t) l18, l9);
    t0 = vader_buffer_intern_string((vader_buffer_t*) l20, (size_t) l19);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_11(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8, vader_string_t l9, vader_string_t l10) {
    int64_t l11, l12, l13, l14, l15, l16, l17, l18, l19, l20, l21;
    void* l22 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l22 };
    vader_string_t* gc_atom_roots[12] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &t0,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 12u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l11 = vader_host_std_core$Intrinsic$byte_len(l0);
    l12 = vader_host_std_core$Intrinsic$byte_len(l1);
    l12 = (l11 + l12);
    l13 = vader_host_std_core$Intrinsic$byte_len(l2);
    l13 = (l12 + l13);
    l14 = vader_host_std_core$Intrinsic$byte_len(l3);
    l14 = (l13 + l14);
    l15 = vader_host_std_core$Intrinsic$byte_len(l4);
    l15 = (l14 + l15);
    l16 = vader_host_std_core$Intrinsic$byte_len(l5);
    l16 = (l15 + l16);
    l17 = vader_host_std_core$Intrinsic$byte_len(l6);
    l17 = (l16 + l17);
    l18 = vader_host_std_core$Intrinsic$byte_len(l7);
    l18 = (l17 + l18);
    l19 = vader_host_std_core$Intrinsic$byte_len(l8);
    l19 = (l18 + l19);
    l20 = vader_host_std_core$Intrinsic$byte_len(l9);
    l20 = (l19 + l20);
    l21 = vader_host_std_core$Intrinsic$byte_len(l10);
    l21 = (l20 + l21);
    l22 = (void*) vader_buffer_new((size_t) l21);
    vader_buffer_write_string((vader_buffer_t*) l22, (size_t) INT64_C(0), l0);
    vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l11, l1);
    vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l12, l2);
    vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l13, l3);
    vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l14, l4);
    vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l15, l5);
    vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l16, l6);
    vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l17, l7);
    vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l18, l8);
    vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l19, l9);
    vader_buffer_write_string((vader_buffer_t*) l22, (size_t) l20, l10);
    t0 = vader_buffer_intern_string((vader_buffer_t*) l22, (size_t) l21);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_12(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8, vader_string_t l9, vader_string_t l10, vader_string_t l11) {
    int64_t l12, l13, l14, l15, l16, l17, l18, l19, l20, l21, l22, l23;
    void* l24 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l24 };
    vader_string_t* gc_atom_roots[13] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &t0,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 13u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l12 = vader_host_std_core$Intrinsic$byte_len(l0);
    l13 = vader_host_std_core$Intrinsic$byte_len(l1);
    l13 = (l12 + l13);
    l14 = vader_host_std_core$Intrinsic$byte_len(l2);
    l14 = (l13 + l14);
    l15 = vader_host_std_core$Intrinsic$byte_len(l3);
    l15 = (l14 + l15);
    l16 = vader_host_std_core$Intrinsic$byte_len(l4);
    l16 = (l15 + l16);
    l17 = vader_host_std_core$Intrinsic$byte_len(l5);
    l17 = (l16 + l17);
    l18 = vader_host_std_core$Intrinsic$byte_len(l6);
    l18 = (l17 + l18);
    l19 = vader_host_std_core$Intrinsic$byte_len(l7);
    l19 = (l18 + l19);
    l20 = vader_host_std_core$Intrinsic$byte_len(l8);
    l20 = (l19 + l20);
    l21 = vader_host_std_core$Intrinsic$byte_len(l9);
    l21 = (l20 + l21);
    l22 = vader_host_std_core$Intrinsic$byte_len(l10);
    l22 = (l21 + l22);
    l23 = vader_host_std_core$Intrinsic$byte_len(l11);
    l23 = (l22 + l23);
    l24 = (void*) vader_buffer_new((size_t) l23);
    vader_buffer_write_string((vader_buffer_t*) l24, (size_t) INT64_C(0), l0);
    vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l12, l1);
    vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l13, l2);
    vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l14, l3);
    vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l15, l4);
    vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l16, l5);
    vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l17, l6);
    vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l18, l7);
    vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l19, l8);
    vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l20, l9);
    vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l21, l10);
    vader_buffer_write_string((vader_buffer_t*) l24, (size_t) l22, l11);
    t0 = vader_buffer_intern_string((vader_buffer_t*) l24, (size_t) l23);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_2(vader_string_t l0, vader_string_t l1) {
    int64_t l2, l3;
    void* l4 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l4 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core$Intrinsic$byte_len(l0);
    l3 = vader_host_std_core$Intrinsic$byte_len(l1);
    l3 = (l2 + l3);
    l4 = (void*) vader_buffer_new((size_t) l3);
    vader_buffer_write_string((vader_buffer_t*) l4, (size_t) INT64_C(0), l0);
    vader_buffer_write_string((vader_buffer_t*) l4, (size_t) l2, l1);
    t0 = vader_buffer_intern_string((vader_buffer_t*) l4, (size_t) l3);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_3(vader_string_t l0, vader_string_t l1, vader_string_t l2) {
    int64_t l3, l4, l5;
    void* l6 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l6 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_core$Intrinsic$byte_len(l0);
    l4 = vader_host_std_core$Intrinsic$byte_len(l1);
    l4 = (l3 + l4);
    l5 = vader_host_std_core$Intrinsic$byte_len(l2);
    l5 = (l4 + l5);
    l6 = (void*) vader_buffer_new((size_t) l5);
    vader_buffer_write_string((vader_buffer_t*) l6, (size_t) INT64_C(0), l0);
    vader_buffer_write_string((vader_buffer_t*) l6, (size_t) l3, l1);
    vader_buffer_write_string((vader_buffer_t*) l6, (size_t) l4, l2);
    t0 = vader_buffer_intern_string((vader_buffer_t*) l6, (size_t) l5);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_4(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3) {
    int64_t l4, l5, l6, l7;
    void* l8 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l8 };
    vader_string_t* gc_atom_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_host_std_core$Intrinsic$byte_len(l0);
    l5 = vader_host_std_core$Intrinsic$byte_len(l1);
    l5 = (l4 + l5);
    l6 = vader_host_std_core$Intrinsic$byte_len(l2);
    l6 = (l5 + l6);
    l7 = vader_host_std_core$Intrinsic$byte_len(l3);
    l7 = (l6 + l7);
    l8 = (void*) vader_buffer_new((size_t) l7);
    vader_buffer_write_string((vader_buffer_t*) l8, (size_t) INT64_C(0), l0);
    vader_buffer_write_string((vader_buffer_t*) l8, (size_t) l4, l1);
    vader_buffer_write_string((vader_buffer_t*) l8, (size_t) l5, l2);
    vader_buffer_write_string((vader_buffer_t*) l8, (size_t) l6, l3);
    t0 = vader_buffer_intern_string((vader_buffer_t*) l8, (size_t) l7);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_5(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4) {
    int64_t l5, l6, l7, l8, l9;
    void* l10 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l10 };
    vader_string_t* gc_atom_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_host_std_core$Intrinsic$byte_len(l0);
    l6 = vader_host_std_core$Intrinsic$byte_len(l1);
    l6 = (l5 + l6);
    l7 = vader_host_std_core$Intrinsic$byte_len(l2);
    l7 = (l6 + l7);
    l8 = vader_host_std_core$Intrinsic$byte_len(l3);
    l8 = (l7 + l8);
    l9 = vader_host_std_core$Intrinsic$byte_len(l4);
    l9 = (l8 + l9);
    l10 = (void*) vader_buffer_new((size_t) l9);
    vader_buffer_write_string((vader_buffer_t*) l10, (size_t) INT64_C(0), l0);
    vader_buffer_write_string((vader_buffer_t*) l10, (size_t) l5, l1);
    vader_buffer_write_string((vader_buffer_t*) l10, (size_t) l6, l2);
    vader_buffer_write_string((vader_buffer_t*) l10, (size_t) l7, l3);
    vader_buffer_write_string((vader_buffer_t*) l10, (size_t) l8, l4);
    t0 = vader_buffer_intern_string((vader_buffer_t*) l10, (size_t) l9);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_6(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5) {
    int64_t l6, l7, l8, l9, l10, l11;
    void* l12 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l12 };
    vader_string_t* gc_atom_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = vader_host_std_core$Intrinsic$byte_len(l0);
    l7 = vader_host_std_core$Intrinsic$byte_len(l1);
    l7 = (l6 + l7);
    l8 = vader_host_std_core$Intrinsic$byte_len(l2);
    l8 = (l7 + l8);
    l9 = vader_host_std_core$Intrinsic$byte_len(l3);
    l9 = (l8 + l9);
    l10 = vader_host_std_core$Intrinsic$byte_len(l4);
    l10 = (l9 + l10);
    l11 = vader_host_std_core$Intrinsic$byte_len(l5);
    l11 = (l10 + l11);
    l12 = (void*) vader_buffer_new((size_t) l11);
    vader_buffer_write_string((vader_buffer_t*) l12, (size_t) INT64_C(0), l0);
    vader_buffer_write_string((vader_buffer_t*) l12, (size_t) l6, l1);
    vader_buffer_write_string((vader_buffer_t*) l12, (size_t) l7, l2);
    vader_buffer_write_string((vader_buffer_t*) l12, (size_t) l8, l3);
    vader_buffer_write_string((vader_buffer_t*) l12, (size_t) l9, l4);
    vader_buffer_write_string((vader_buffer_t*) l12, (size_t) l10, l5);
    t0 = vader_buffer_intern_string((vader_buffer_t*) l12, (size_t) l11);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_7(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6) {
    int64_t l7, l8, l9, l10, l11, l12, l13;
    void* l14 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l14 };
    vader_string_t* gc_atom_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = vader_host_std_core$Intrinsic$byte_len(l0);
    l8 = vader_host_std_core$Intrinsic$byte_len(l1);
    l8 = (l7 + l8);
    l9 = vader_host_std_core$Intrinsic$byte_len(l2);
    l9 = (l8 + l9);
    l10 = vader_host_std_core$Intrinsic$byte_len(l3);
    l10 = (l9 + l10);
    l11 = vader_host_std_core$Intrinsic$byte_len(l4);
    l11 = (l10 + l11);
    l12 = vader_host_std_core$Intrinsic$byte_len(l5);
    l12 = (l11 + l12);
    l13 = vader_host_std_core$Intrinsic$byte_len(l6);
    l13 = (l12 + l13);
    l14 = (void*) vader_buffer_new((size_t) l13);
    vader_buffer_write_string((vader_buffer_t*) l14, (size_t) INT64_C(0), l0);
    vader_buffer_write_string((vader_buffer_t*) l14, (size_t) l7, l1);
    vader_buffer_write_string((vader_buffer_t*) l14, (size_t) l8, l2);
    vader_buffer_write_string((vader_buffer_t*) l14, (size_t) l9, l3);
    vader_buffer_write_string((vader_buffer_t*) l14, (size_t) l10, l4);
    vader_buffer_write_string((vader_buffer_t*) l14, (size_t) l11, l5);
    vader_buffer_write_string((vader_buffer_t*) l14, (size_t) l12, l6);
    t0 = vader_buffer_intern_string((vader_buffer_t*) l14, (size_t) l13);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_8(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7) {
    int64_t l8, l9, l10, l11, l12, l13, l14, l15;
    void* l16 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l16 };
    vader_string_t* gc_atom_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l8 = vader_host_std_core$Intrinsic$byte_len(l0);
    l9 = vader_host_std_core$Intrinsic$byte_len(l1);
    l9 = (l8 + l9);
    l10 = vader_host_std_core$Intrinsic$byte_len(l2);
    l10 = (l9 + l10);
    l11 = vader_host_std_core$Intrinsic$byte_len(l3);
    l11 = (l10 + l11);
    l12 = vader_host_std_core$Intrinsic$byte_len(l4);
    l12 = (l11 + l12);
    l13 = vader_host_std_core$Intrinsic$byte_len(l5);
    l13 = (l12 + l13);
    l14 = vader_host_std_core$Intrinsic$byte_len(l6);
    l14 = (l13 + l14);
    l15 = vader_host_std_core$Intrinsic$byte_len(l7);
    l15 = (l14 + l15);
    l16 = (void*) vader_buffer_new((size_t) l15);
    vader_buffer_write_string((vader_buffer_t*) l16, (size_t) INT64_C(0), l0);
    vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l8, l1);
    vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l9, l2);
    vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l10, l3);
    vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l11, l4);
    vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l12, l5);
    vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l13, l6);
    vader_buffer_write_string((vader_buffer_t*) l16, (size_t) l14, l7);
    t0 = vader_buffer_intern_string((vader_buffer_t*) l16, (size_t) l15);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_9(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8) {
    int64_t l9, l10, l11, l12, l13, l14, l15, l16, l17;
    void* l18 = NULL;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l18 };
    vader_string_t* gc_atom_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 10u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l9 = vader_host_std_core$Intrinsic$byte_len(l0);
    l10 = vader_host_std_core$Intrinsic$byte_len(l1);
    l10 = (l9 + l10);
    l11 = vader_host_std_core$Intrinsic$byte_len(l2);
    l11 = (l10 + l11);
    l12 = vader_host_std_core$Intrinsic$byte_len(l3);
    l12 = (l11 + l12);
    l13 = vader_host_std_core$Intrinsic$byte_len(l4);
    l13 = (l12 + l13);
    l14 = vader_host_std_core$Intrinsic$byte_len(l5);
    l14 = (l13 + l14);
    l15 = vader_host_std_core$Intrinsic$byte_len(l6);
    l15 = (l14 + l15);
    l16 = vader_host_std_core$Intrinsic$byte_len(l7);
    l16 = (l15 + l16);
    l17 = vader_host_std_core$Intrinsic$byte_len(l8);
    l17 = (l16 + l17);
    l18 = (void*) vader_buffer_new((size_t) l17);
    vader_buffer_write_string((vader_buffer_t*) l18, (size_t) INT64_C(0), l0);
    vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l9, l1);
    vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l10, l2);
    vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l11, l3);
    vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l12, l4);
    vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l13, l5);
    vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l14, l6);
    vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l15, l7);
    vader_buffer_write_string((vader_buffer_t*) l18, (size_t) l16, l8);
    t0 = vader_buffer_intern_string((vader_buffer_t*) l18, (size_t) l17);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
