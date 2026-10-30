#include "bootstrap.split.h"

static bool __lambda_vader_front_effects_24(void* l0, void* l1);
static bool __lambda_vader_front_typecheck_62(void* l0, void* l1);
static bool __lambda_vader_midir_2(void* l0, int32_t l1);
static bool __lambda_vader_support_fixpoint_3(void* l0, int32_t l1);

void __defer_std_io_0(void* l0) {
    void* t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct___defer_env_std_io_1_t*) l0)->f_cap_0;
    vader_host_system_posix$sys_closedir(t0);
    { vader_gc_top = gc_frame.prev; return; }
}

void __defer_std_io_2(void* l0) {
    void* t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct___defer_env_std_io_3_t*) l0)->f_cap_0;
    vader_host_system_posix$sys_fclose(t0);
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_std_numbers_0(uint32_t l0) {
    return l0 == 95u;
}

bool __lambda_std_path_0(uint32_t l0) {
    return l0 == 92u;
}

bool __lambda_vader_core_types_0(void* l0, int64_t l1, int64_t l2) {
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_core_types_1_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_core_types_1_t*) l0)->f_cap_1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
    l4 = t0.payload.s;
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l2];
    l6 = t0.payload.s;
    t1 = vader_core_types$comes_before(l3, l4, l5, l6);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_core_types_2(int64_t l0, int64_t l1) {
    return (l0 < l1);
}

bool __lambda_vader_core_types_3(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) l1)->f_symbol)->f_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) ((vader_struct___lambda_env_vader_core_types_4_t*) l0)->f_cap_0)->f_symbol)->f_id;
    return l2 == l3;
}

bool __lambda_vader_core_types_5(void) {
    return false;
}

bool __lambda_vader_core_types_6(void* l0, vader_box_t l1) {
    vader_box_t l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_core_types_7_t*) l0)->f_cap_0;
    t0 = vader_core_types$equals_type(l1, l2);
    return t0;
}

void* __lambda_vader_emit_bytecode_0(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_bytecode$SlotRange_t* _a0_obj = (vader_struct_vader_emit_bytecode$SlotRange_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_bytecode$SlotRange_t));
    vader_obj_header_init(_a0_obj, 1051u);
    _a0_obj->f_first = INT32_C(-1);
    _a0_obj->f_last = INT32_C(-1);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_emit_bytecode_1(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_emit_bytecode_2_t*) l0)->f_cap_0;
    t0 = vader_emit_bytecode$remap_type(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_emit_bytecode_11(void* l0, int32_t l1) {
    bool t0;
    t0 = vader_emit_bytecode$is_boxed_row(((vader_struct___lambda_env_vader_emit_bytecode_12_t*) l0)->f_cap_0, l1);
    return t0;
}

bool __lambda_vader_emit_bytecode_13(void* l0, void* l1) {
    void* l2;
    int32_t l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_emit_bytecode_14_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_core_bytecode$BcField_t*) l1)->f_type_index;
    t0 = vader_emit_bytecode$is_boxed_row(l2, l3);
    return t0;
}

void* __lambda_vader_emit_bytecode_3(void* l0, void* l1) {
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
    l3 = ((vader_struct___lambda_env_vader_emit_bytecode_4_t*) l0)->f_cap_0;
    l4 = ((vader_struct_vader_core_bytecode$BcGlobal_t*) l1)->f_type_id;
    l4 = vader_emit_bytecode$remap_idx(l3, l4);
    vader_struct_vader_core_bytecode$BcGlobal_t* _a0_obj = (vader_struct_vader_core_bytecode$BcGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcGlobal_t));
    vader_obj_header_init(_a0_obj, 853u);
    _a0_obj->f_name = l2;
    _a0_obj->f_type_id = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_emit_bytecode_5(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_emit_bytecode_6_t*) l0)->f_cap_0;
    t0 = vader_emit_bytecode$remap_data_entry(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t __lambda_vader_emit_bytecode_7(void* l0, int32_t l1) {
    int32_t t0;
    t0 = vader_emit_bytecode$remap_idx(((vader_struct___lambda_env_vader_emit_bytecode_8_t*) l0)->f_cap_0, l1);
    return t0;
}

vader_box_t __lambda_vader_emit_bytecode_9(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_emit_bytecode_10_t*) l0)->f_cap_0;
    t0 = vader_emit_bytecode$remap_data_value(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_emit_c_0(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
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
    if (l0.tag == 991u) {
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
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l3 = ((vader_struct_vader_core_bytecode$BcFunction_t*) t0)->f_name;
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
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
    vader_string_t t0 = 0;
    uint8_t t1;
    bool t2;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_core_bytecode$BcImport_t*) l0)->f_mangled_name;
    t1 = vader_core_bytecode$intrinsic_id_for(t0);
    t2 = vader_core_bytecode$intrinsic_may_collect(t1);
    { bool __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_string_t l2, l3;
    l2 = vader_core_bytecode$library_name(l1);
    l3 = ((vader_struct___lambda_env_vader_emit_c_10_t*) l0)->f_cap_0;
    return l2 == l3;
}

bool __lambda_vader_emit_c_ast_0(void* l0, int64_t l1, int64_t l2) {
    int32_t l3, l4;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_emit_c_ast_1_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    return (l3 < l4);
}

uint8_t __lambda_vader_front_comptime_0(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_comptime_1_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_comptime_1_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_comptime_1_t*) l0)->f_cap_2;
    l5 = ((vader_struct___lambda_env_vader_front_comptime_1_t*) l0)->f_cap_3;
    t0 = vader_front_comptime$dependency_step(l1, l2, l3, l4, l5);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_comptime_2(vader_string_t l0, vader_string_t l1) {
    bool t0;
    t0 = std_string$compare_ascending(l0, l1);
    return t0;
}

uint8_t __lambda_vader_front_dead__code_0(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_dead__code_1_t*) l0)->f_cap_0;
    t0 = vader_front_dead__code$referenced_name(l1, l2);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_effects_0(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(215u, 0u, 13u, 1151u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 8u, 451u);
    l1 = (void*) _a1_arr;
    vader_struct_vader_front_effects$ParamEffects_t* _a2_obj = (vader_struct_vader_front_effects$ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_effects$ParamEffects_t));
    vader_obj_header_init(_a2_obj, 1172u);
    _a2_obj->f_accesses = l0;
    _a2_obj->f_origins = l1;
    _a2_obj->f_keys = vader_box_obj(0u, NULL);
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t __lambda_vader_front_effects_1(void) {
    return INT64_C(0);
}

void* __lambda_vader_front_effects_10(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(215u, 0u, 13u, 1151u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 8u, 451u);
    l1 = (void*) _a1_arr;
    vader_struct_vader_front_effects$ParamEffects_t* _a2_obj = (vader_struct_vader_front_effects$ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_effects$ParamEffects_t));
    vader_obj_header_init(_a2_obj, 1172u);
    _a2_obj->f_accesses = l0;
    _a2_obj->f_origins = l1;
    _a2_obj->f_keys = vader_box_obj(0u, NULL);
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_effects_11(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(229u, 0u, 13u, 1176u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_front_effects_12(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_front_effects$FaultHop_t*) l0)->f_callee;
    return t0;
}

bool __lambda_vader_front_effects_13(vader_box_t l0) {
    bool t0;
    t0 = vader_front_effects$holds_references(l0);
    return t0;
}

void* __lambda_vader_front_effects_14(void* l0) {
    void* t0;
    t0 = vader_front_effects$none();
    return t0;
}

bool __lambda_vader_front_effects_15(void* l0, void* l1) {
    void* l2;
    int64_t l3;
    void* t0;
    bool t1;
    l2 = ((vader_struct___lambda_env_vader_front_effects_16_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_front_effects$Root_t*) l1)->f_param;
    t0 = vader_front_effects$root_record(l2, l3);
    t1 = vader_front_effects$is_view(t0);
    if (!(t1)) {
        return true;
    }
    t1 = vader_front_effects$reaches(((vader_struct___lambda_env_vader_front_effects_16_t*) l0)->f_cap_1, l1);
    return t1;
}

bool __lambda_vader_front_effects_17(void* l0, void* l1) {
    void* l2;
    int64_t l3;
    void* t0;
    bool t1;
    l2 = ((vader_struct_vader_front_effects$RootCase_t*) ((vader_struct___lambda_env_vader_front_effects_18_t*) l0)->f_cap_0)->f_body;
    l3 = ((vader_struct_vader_front_effects$Root_t*) l1)->f_param;
    t0 = vader_front_effects$root_record(l2, l3);
    t1 = vader_front_effects$is_view(t0);
    return t1;
}

bool __lambda_vader_front_effects_19(void* l0) {
    bool t0;
    if (((vader_struct_vader_front_effects$Access_t*) l0)->f_effect == INT32_C(4)) {
        t0 = vader_front_effects$is_the_view(l0);
        return t0;
    }
    return false;
}

int64_t __lambda_vader_front_effects_2(void) {
    return INT64_C(0);
}

void* __lambda_vader_front_effects_20(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(217u, 0u, 13u, 1156u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_21(vader_box_t l0) {
    return !(l0.tag == 0u);
}

bool __lambda_vader_front_effects_22(void* l0, void* l1) {
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
    l2 = ((vader_struct___lambda_env_vader_front_effects_23_t*) l0)->f_cap_0;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_ref_box(l1));
    t1 = t0.payload.b;
    if (t1) {
        l2 = ((vader_struct_vader_front_effects$RootCase_t*) ((vader_struct___lambda_env_vader_front_effects_23_t*) l0)->f_cap_1)->f_held;
        l3 = ((vader_struct___lambda_env_vader_front_effects_23_t*) l0)->f_cap_2;
        l4 = ((vader_struct___lambda_env_vader_front_effects_23_t*) l0)->f_cap_1;
        vader_struct___lambda_env_vader_front_effects_25_t* _a1_obj = (vader_struct___lambda_env_vader_front_effects_25_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_effects_25_t));
        vader_obj_header_init(_a1_obj, 492u);
        _a1_obj->f_cap_0 = l3;
        _a1_obj->f_cap_1 = l4;
        _a1_obj->f_cap_2 = l1;
        l3 = (void*) _a1_obj;
        l5 = false;
        l6 = ((vader_array_t*) l2)->length;
        l7 = INT64_C(0);
        {
            while ((l7 < l6)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
                l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
                t1 = __lambda_vader_front_effects_24(l3, l4);
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

static bool __lambda_vader_front_effects_24(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_25_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_effects_25_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_effects_25_t*) l0)->f_cap_2;
    t0 = vader_front_effects$written_at(l2, l3, l1, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_26(void* l0, void* l1) {
    bool t0;
    t0 = vader_front_effects$writes_view(((vader_struct_vader_front_effects$RootCase_t*) ((vader_struct___lambda_env_vader_front_effects_27_t*) l0)->f_cap_0)->f_paths, l1);
    return t0;
}

bool __lambda_vader_front_effects_28(void* l0) {
    bool t0;
    t0 = vader_front_effects$is_the_view(l0);
    if (t0) {
        t0 = vader_front_effects$keeps(l0);
        return t0;
    }
    return false;
}

bool __lambda_vader_front_effects_29(void* l0, vader_box_t l1) {
    void* l2;
    int32_t l3;
    void* t0;
    bool t1;
    if (l1.tag == 1154u) {
        l2 = ((vader_struct_vader_front_effects$CalleeIndex_t*) ((vader_struct___lambda_env_vader_front_effects_30_t*) l0)->f_cap_0)->f_view_nodes;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_front_effects$CalleeNode_t*) t0)->f_node;
        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l2, l3);
        return t1;
    }
    return false;
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
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
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
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    l5 = vader_front_effects$settle(t1, l2);
    t0 = vader_front_effects$noted(l3, l1, l5);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_31(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_32_t*) l0)->f_cap_0;
    t0 = vader_front_effects$may_hold_view(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_33(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_34_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_effects_34_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_effects_34_t*) l0)->f_cap_2;
    t0 = vader_front_effects$may_be_written(l2, l1, l3, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_effects_35(void* l0, vader_box_t l1) {
    void* t0;
    t0 = vader_front_effects$targets_of(((vader_struct___lambda_env_vader_front_effects_36_t*) l0)->f_cap_0, l1);
    return t0;
}

bool __lambda_vader_front_effects_37(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_toolchain_ast$FnDecl_t*) l1)->f_name;
    l3 = ((vader_struct___lambda_env_vader_front_effects_38_t*) l0)->f_cap_0;
    return l2 == l3;
}

bool __lambda_vader_front_effects_39(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_effects_40_t*) l0)->f_cap_0;
    t0 = vader_front_effects$may_be_element(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_effects_5(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_front_effects$Clock_t*) ((vader_struct___lambda_env_vader_front_effects_6_t*) l0)->f_cap_0)->f_grew_at);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    l3 = ((vader_struct___lambda_env_vader_front_effects_6_t*) l0)->f_cap_1;
    return (l2 > l3);
}

bool __lambda_vader_front_effects_7(void* l0, int32_t l1) {
    bool t0;
    t0 = std_collections$MutableSet$std_core$Contains$contains__i32(((vader_struct___lambda_env_vader_front_effects_8_t*) l0)->f_cap_0, l1);
    return t0;
}

void* __lambda_vader_front_effects_9(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(215u, 0u, 13u, 1151u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 8u, 451u);
    l1 = (void*) _a1_arr;
    vader_struct_vader_front_effects$ParamEffects_t* _a2_obj = (vader_struct_vader_front_effects$ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_effects$ParamEffects_t));
    vader_obj_header_init(_a2_obj, 1172u);
    _a2_obj->f_accesses = l0;
    _a2_obj->f_origins = l1;
    _a2_obj->f_keys = vader_box_obj(0u, NULL);
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_front_parser_0(void* l0, vader_string_t l1) {
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_parser$is_binding_hint(((vader_struct_$Cell_f3a01222880a8b1f_t*) ((vader_struct___lambda_env_vader_front_parser_1_t*) l0)->f_cap_0.payload.obj)->f_value, l1, true);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_front_parser_2(void* l0, vader_string_t l1) {
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_parser$is_binding_hint(((vader_struct_$Cell_f3a01222880a8b1f_t*) ((vader_struct___lambda_env_vader_front_parser_3_t*) l0)->f_cap_0.payload.obj)->f_value, l1, false);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_front_parser_4(vader_string_t l0) {
    vader_string_t t0;
    t0 = concat_3(2366u, l0, 69u);
    return t0;
}

vader_string_t __lambda_vader_front_parser_5(vader_string_t l0) {
    vader_string_t t0;
    t0 = concat_3(2367u, l0, 69u);
    return t0;
}

void* __lambda_vader_front_resolver_0(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_resolver_1(void* l0, void* l1) {
    vader_string_t l2, l3;
    bool t0;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_name;
    t0 = std_string$compare_ascending(l2, l3);
    return t0;
}

void* __lambda_vader_front_resolver_2(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_resolver_3_t*) l0)->f_cap_0;
    t0 = vader_front_resolver$substitute_param(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_4(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_resolver_5_t*) l0)->f_cap_0;
    t0 = vader_front_resolver$unplaced_param(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_resolver_6(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(172u, 0u, 13u, 1015u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_0(void* l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_front_typecheck_1_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_1_t*) l0)->f_cap_1;
    t0 = vader_front_typecheck$build_namespace_private_names(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_10(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 458u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_____t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_____t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_____t));
    vader_obj_header_init(_a3_obj, 658u);
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

void* __lambda_vader_front_typecheck_11(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(18u, 0u, 13u, 363u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_12(void* l0) {
    return !(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_body.tag == 0u);
}

bool __lambda_vader_front_typecheck_13(void* l0) {
    return !(((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_inherits.tag == 0u);
}

uint8_t __lambda_vader_front_typecheck_14(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_15_t*) l0)->f_cap_0;
    t0 = vader_front_typecheck$collect_tested_type(l1, l2);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_16(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(263u, 0u, 13u, 1269u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_front_typecheck_17(void* l0, vader_box_t l1) {
    vader_array_push_ref((vader_array_t*) ((vader_struct___lambda_env_vader_front_typecheck_18_t*) l0)->f_cap_0, l1.payload.obj);
    return;
}

void* __lambda_vader_front_typecheck_19(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(258u, 0u, 13u, 1259u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_2(void* l0) {
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
    l1 = ((vader_struct___lambda_env_vader_front_typecheck_3_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_3_t*) l0)->f_cap_1;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_3_t*) l0)->f_cap_2;
    t0 = vader_front_typecheck$build_namespace_type_members(l1, l2, l3);
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
    vader_array_t* _a0_arr = vader_array_new(265u, 0u, 13u, 1272u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_23(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) l1)->f_symbol)->f_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct___lambda_env_vader_front_typecheck_24_t*) l0)->f_cap_0)->f_id;
    return l2 == l3;
}

void __lambda_vader_front_typecheck_25(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1038u) {
        l2 = ((vader_struct___lambda_env_vader_front_typecheck_26_t*) l0)->f_cap_0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_types$TypeParamType_t*) t0)->f_symbol;
        vader_array_push_ref((vader_array_t*) l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

uint8_t __lambda_vader_front_typecheck_27(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_28_t*) l0)->f_cap_0;
    t0 = vader_front_typecheck$probe_step(l1, l2);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t __lambda_vader_front_typecheck_29(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_30_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_30_t*) l0)->f_cap_1;
    t0 = vader_front_typecheck$copy_node_resolutions(l1, l2, l3);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_31(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(249u, 0u, 13u, 1240u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_32(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(264u, 0u, 13u, 1270u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_front_typecheck_33(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_front_typecheck_34_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_34_t*) l0)->f_cap_1;
    t0 = vader_front_typecheck$contract_of(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = vader_front_typecheck$ensures_of(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_front_typecheck_37(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_core_types$display_type(l0);
    t0 = concat_3(1033u, l1, 1033u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_38(void* l0, vader_box_t l1) {
    bool t0;
    t0 = vader_front_typecheck$keeps_concrete(((vader_struct___lambda_env_vader_front_typecheck_39_t*) l0)->f_cap_0, l1);
    return t0;
}

void* __lambda_vader_front_typecheck_4(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 458u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any___t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any___t));
    vader_obj_header_init(_a3_obj, 657u);
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

uint8_t __lambda_vader_front_typecheck_40(void* l0, vader_box_t l1) {
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
    if (l1.tag == 791u) {
        { vader_gc_top = gc_frame.prev; return (uint8_t) 1; }
    }
    if (l1.tag == 751u) {
        l2 = ((vader_struct___lambda_env_vader_front_typecheck_41_t*) l0)->f_cap_0;
        l3 = l1.payload.obj;
        l4 = vader_front_typecheck$recorded_decl(l2, l3);
        if (!(l4.tag == 0u)) {
            t0 = l4.payload.obj;
            t1 = toolchain_ast$decorators_have(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators, 2560u);
            if (t1) {
                l5 = ((vader_struct_toolchain_ast$ConstDecl_t*) ((vader_struct___lambda_env_vader_front_typecheck_41_t*) l0)->f_cap_1)->f_name;
                t0 = l4.payload.obj;
                l6 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_name;
                l5 = concat_5(1033u, l5, 1068u, l6, 1033u);
                l2 = ((vader_struct___lambda_env_vader_front_typecheck_41_t*) l0)->f_cap_2;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_span;
                l3 = vader_support_diagnostics$typecheck_error((uint8_t) 98, l3, l5);
                vader_array_push_ref((vader_array_t*) l2, l3);
            }
        }
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
}

vader_box_t __lambda_vader_front_typecheck_42(vader_box_t l0) {
    vader_box_t t0;
    t0 = vader_core_types$default_if_free(l0);
    return t0;
}

uint8_t __lambda_vader_front_typecheck_43(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_44_t*) l0)->f_cap_0;
    t0 = vader_front_typecheck$probe_step(l1, l2);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_front_typecheck_45(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_46_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_46_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_typecheck_46_t*) l0)->f_cap_2;
    vader_front_typecheck$check_guard_return(l2, l1, l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_front_typecheck_47(void* l0, vader_box_t l1) {
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
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_48_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_48_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_front_typecheck_48_t*) l0)->f_cap_2;
    l5 = ((vader_struct___lambda_env_vader_front_typecheck_48_t*) l0)->f_cap_3;
    vader_front_typecheck$check_ensured_value(l2, l1, l3, l4, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_vader_front_typecheck_49(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) ((vader_struct___lambda_env_vader_front_typecheck_50_t*) l0)->f_cap_0)->f_symbol)->f_id;
    return l2 == l3;
}

void* __lambda_vader_front_typecheck_5(void* l0) {
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
    l1 = ((vader_struct___lambda_env_vader_front_typecheck_6_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_6_t*) l0)->f_cap_1;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_6_t*) l0)->f_cap_2;
    t0 = vader_front_typecheck$build_namespace_exports(l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_51(void* l0) {
    return !(((vader_struct_vader_front_typecheck$ImplMethod_t*) l0)->f_return_of.tag == 0u);
}

void* __lambda_vader_front_typecheck_52(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_53_t*) l0)->f_cap_0;
    t0 = vader_front_typecheck$settled_member(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_54(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TraitType_t*) l1)->f_symbol)->f_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct___lambda_env_vader_front_typecheck_55_t*) l0)->f_cap_0)->f_id;
    return l2 == l3;
}

bool __lambda_vader_front_typecheck_56(vader_box_t l0) {
    return l0.tag == 1033u;
}

bool __lambda_vader_front_typecheck_57(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) l1)->f_symbol)->f_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$InferVar_t*) ((vader_struct___lambda_env_vader_front_typecheck_58_t*) l0)->f_cap_0)->f_origin)->f_id;
    return l2 == l3;
}

bool __lambda_vader_front_typecheck_59(vader_box_t l0) {
    bool t0;
    t0 = vader_core_types$type_contains_unresolved(l0);
    return t0;
}

bool __lambda_vader_front_typecheck_60(void* l0, vader_box_t l1) {
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
    if (l1.tag == 1038u) {
        l2 = ((vader_struct___lambda_env_vader_front_typecheck_61_t*) l0)->f_cap_0;
        vader_struct___lambda_env_vader_front_typecheck_63_t* _a0_obj = (vader_struct___lambda_env_vader_front_typecheck_63_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_typecheck_63_t));
        vader_obj_header_init(_a0_obj, 529u);
        _a0_obj->f_cap_0 = l1;
        l3 = (void*) _a0_obj;
        l4 = false;
        l5 = ((vader_array_t*) l2)->length;
        l6 = INT64_C(0);
        {
            while ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                t0 = __lambda_vader_front_typecheck_62(l3, l7);
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

static bool __lambda_vader_front_typecheck_62(void* l0, void* l1) {
    int32_t l2, l3;
    void* t0;
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
    t0 = ((vader_struct___lambda_env_vader_front_typecheck_63_t*) l0)->f_cap_0.payload.obj;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$TypeParamType_t*) t0)->f_symbol)->f_id;
    return l2 == l3;
}

bool __lambda_vader_front_typecheck_64(void* l0, vader_string_t l1) {
    vader_string_t l2;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_65_t*) l0)->f_cap_0;
    return l1 == l2;
}

bool __lambda_vader_front_typecheck_66(void* l0, vader_box_t l1) {
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
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_67_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_67_t*) l0)->f_cap_1;
    t0 = vader_front_typecheck$struct_implements_trait(l1, l2, l3);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_68(vader_box_t l0) {
    void* l1 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = (void*) &vader_fn_static___lambda_vader_front_typecheck_69;
    t0 = vader_core_types$any_type(l0, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_69(vader_box_t l0) {
    return l0.tag == 1032u;
}

void* __lambda_vader_front_typecheck_7(void* l0) {
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
    l1 = ((vader_struct___lambda_env_vader_front_typecheck_8_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_front_typecheck_8_t*) l0)->f_cap_1;
    l3 = ((vader_struct___lambda_env_vader_front_typecheck_8_t*) l0)->f_cap_2;
    t0 = vader_front_typecheck$namespace_fn_overloads_of(l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_front_typecheck_70(vader_box_t l0) {
    bool t0;
    t0 = vader_front_typecheck$nests_self(l0);
    return t0;
}

bool __lambda_vader_front_typecheck_71(vader_box_t l0) {
    return l0.tag == 1032u;
}

void* __lambda_vader_front_typecheck_72(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_73(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_front_typecheck_9(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(47u, 0u, 13u, 773u);
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

void __lambda_vader_lower_11(void* l0, vader_box_t l1) {
    if (l1.tag == 1371u) {
        ((vader_struct_$Cell_bool_cd2fd49b_t*) ((vader_struct___lambda_env_vader_lower_12_t*) l0)->f_cap_0.payload.obj)->f_value = true;
        return;
    }
    return;
}

bool __lambda_vader_lower_13(void* l0, vader_box_t l1) {
    void* l2;
    void* l3;
    bool t0;
    l2 = ((vader_struct_vader_lower$CallTarget_t*) ((vader_struct___lambda_env_vader_lower_14_t*) l0)->f_cap_0)->f_owner;
    l3 = ((vader_struct___lambda_env_vader_lower_14_t*) l0)->f_cap_1;
    t0 = vader_lower$loops_over(l1, l2, l3);
    return t0;
}

void* __lambda_vader_lower_15(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(172u, 0u, 13u, 1015u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct___lambda_env_vader_lower_16_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct___lambda_env_vader_lower_16_t*) l0)->f_cap_1)->f_resolved;
    l2 = vader_lower$ensure_local_symbol_index(l2, l3);
    l3 = ((vader_struct_std_collections$MutableMap__u64__vader_core_symbol_Symbol_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections$MutableMap__u64__vader_core_symbol_Symbol_t*) l2)->f_evals;
    l5 = INT64_C(0);
    l6 = ((vader_struct_std_collections$MutableMap__u64__vader_core_symbol_Symbol_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        t1 = vader_core_symbol$is_local_binding(((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_kind);
        if (t1) {
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_defined_at;
            if (!(l8.tag == 0u)) {
                l7 = l8.payload.obj;
                t1 = vader_lower$starts_within(((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct___lambda_env_vader_lower_16_t*) l0)->f_cap_2)->f_span, l7);
                if (t1) {
                    vader_array_push_ref((vader_array_t*) l1, l2);
                }
            }
        }
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_lower_17(void* l0) {
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
    l1 = ((vader_struct___lambda_env_vader_lower_18_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_lower_18_t*) l0)->f_cap_1;
    l3 = ((vader_struct___lambda_env_vader_lower_18_t*) l0)->f_cap_2;
    vader_struct_vader_lower$ObservedFn_t* _a0_obj = (vader_struct_vader_lower$ObservedFn_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower$ObservedFn_t));
    vader_obj_header_init(_a0_obj, 1344u);
    _a0_obj->f_decl = vader_ref_box(l1);
    _a0_obj->f_trait_key = l2;
    _a0_obj->f_name = l3;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_lower_2(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 458u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 656u);
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

bool __lambda_vader_lower_3(vader_box_t l0) {
    bool t0;
    if (l0.tag == 1020u) {
        return true;
    }
    t0 = vader_core_types$is_refinement(l0);
    return t0;
}

vader_box_t __lambda_vader_lower_4(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_lower_5_t*) l0)->f_cap_0;
    t0 = vader_core_types$substitute(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_lower_6(vader_box_t l0) {
    bool t0;
    t0 = vader_core_types$contains_distinct(l0);
    return t0;
}

vader_string_t __lambda_vader_lower_7(void* l0) {
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
    l3 = std_core$write_string_at(l2, l3, 2535u);
    l4 = ((vader_array_t*) ((vader_struct_vader_lower$GenBuild_t*) ((vader_struct___lambda_env_vader_lower_8_t*) l0)->f_cap_0)->f_fields)->length;
    l3 = std_core$write_int(l2, l3, l4);
    l1 = std_core$finish_buffer(l2, l3);
    l2 = ((vader_struct___lambda_env_vader_lower_8_t*) l0)->f_cap_0;
    l6 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct___lambda_env_vader_lower_8_t*) l0)->f_cap_1)->f_id;
    t0 = vader_lower$gb_is_cell(l2, l6);
    if (t0) {
        t1 = (void*) &vader_data_22;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        l5 = vader_ref_box(t1);
    } else {
        l5 = ((vader_struct___lambda_env_vader_lower_8_t*) l0)->f_cap_2;
    }
    l2 = ((vader_struct_vader_lower$GenBuild_t*) ((vader_struct___lambda_env_vader_lower_8_t*) l0)->f_cap_0)->f_fields;
    vader_struct_vader_lower_ir$LoweredStructField_t* _a1_obj = (vader_struct_vader_lower_ir$LoweredStructField_t*) vader_gc_alloc(sizeof(vader_struct_vader_lower_ir$LoweredStructField_t));
    vader_obj_header_init(_a1_obj, 1409u);
    _a1_obj->f_name = l1;
    _a1_obj->f_type = l5;
    l7 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l2, l7);
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t __lambda_vader_lower_9(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_lower_10_t*) l0)->f_cap_0;
    t0 = vader_lower$enter_node(l1, l2);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(305u, 0u, 13u, 1418u);
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
    l3 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct___lambda_env_vader_lower_dce_4_t*) l0)->f_cap_0, l2);
    if (l3.tag == 0u) {
        l5 = std_collections$MutableMap$std_core$Index$at__i32__Any(((vader_struct___lambda_env_vader_lower_dce_4_t*) l0)->f_cap_3, l1);
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
    l3 = concat_3(l1, 3063u, l2);
    t0 = std_collections$add__string(((vader_struct___lambda_env_vader_lower_dce_6_t*) l0)->f_cap_0, l3);
    if (t0) {
        vader_array_push_scalar((vader_array_t*) ((vader_struct___lambda_env_vader_lower_dce_6_t*) l0)->f_cap_1, vader_box_string(447u, l3));
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
    if (l1.tag == 1419u) {
        l2 = ((vader_struct___lambda_env_vader_lower_ir_1_t*) l0)->f_cap_0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredYield_t*) t0)->f_span;
        l4 = ((vader_struct___lambda_env_vader_lower_ir_1_t*) l0)->f_cap_1;
        l5 = ((vader_struct___lambda_env_vader_lower_ir_1_t*) l0)->f_cap_2;
        l4 = concat_5(1512u, l4, 1311u, l5, 1294u);
        l3 = vader_support_diagnostics$internal_error((uint8_t) 0, l3, l4);
        vader_array_push_ref((vader_array_t*) l2, l3);
    }
    if (l1.tag == 1371u) {
        l2 = ((vader_struct___lambda_env_vader_lower_ir_1_t*) l0)->f_cap_0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredAwait_t*) t0)->f_span;
        l4 = ((vader_struct___lambda_env_vader_lower_ir_1_t*) l0)->f_cap_1;
        l5 = ((vader_struct___lambda_env_vader_lower_ir_1_t*) l0)->f_cap_2;
        l4 = concat_5(1512u, l4, 1312u, l5, 1293u);
        l3 = vader_support_diagnostics$internal_error((uint8_t) 0, l3, l4);
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
    if (l1.tag == 1399u) {
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
    if (l1.tag == 1375u) {
        l2 = true;
    } else {
        l2 = l1.tag == 1383u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1.tag == 1406u;
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
    if (l1.tag == 1459u) {
        l3 = ((vader_struct_vader_midir$CallGraph_t*) ((vader_struct_vader_midir$ShrinkSummary_t*) ((vader_struct___lambda_env_vader_midir_1_t*) l0)->f_cap_0)->f_calls)->f_index;
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrCall_t*) t1)->f_callee;
        l5 = vader_midir$callee_node(l3, l4);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
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
    vader_obj_header_init(_a1_obj, 556u);
    _a1_obj->f_cap_0 = l2;
    l2 = (void*) _a1_obj;
    l7 = false;
    l8 = ((vader_array_t*) l3)->length;
    l9 = INT64_C(0);
    {
        while ((l9 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l9];
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
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_midir_11(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_midir_12(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int32_t l4;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = std_collections$MutableMap$std_core$Index$at__i32__i32(((vader_struct___lambda_env_vader_midir_13_t*) l0)->f_cap_0, l1);
    if (l2.tag == 0u) {
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(((vader_struct___lambda_env_vader_midir_13_t*) l0)->f_cap_0, l1, INT32_C(1));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct___lambda_env_vader_midir_13_t*) l0)->f_cap_0;
    t0 = ((int32_t) l2.payload.i);
    l4 = vader_chk_add(i32, t0, INT32_C(1));
    std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l3, l1, l4);
    { vader_gc_top = gc_frame.prev; return; }
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
        l10 = vader_host_std_core$byte_len(l8);
        l11 = vader_host_std_core$byte_len(l9);
        l10 = (l10 + l11);
        l12 = (void*) vader_buffer_new((size_t) (INT64_C(79) + l10));
        l10 = INT64_C(0);
        l10 = std_core$write_string_at(l12, l10, l8);
        l10 = std_core$write_string_at(l12, l10, 463u);
        l10 = std_core$write_string_at(l12, l10, l9);
        l10 = std_core$write_string_at(l12, l10, 179u);
        l11 = ((int64_t) (int32_t) l1);
        l10 = std_core$write_int(l12, l10, l11);
        l10 = std_core$write_string_at(l12, l10, 371u);
        t1 = ((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_0;
        l11 = ((int64_t) (int32_t) t1);
        l10 = std_core$write_int(l12, l10, l11);
        l10 = std_core$write_string_at(l12, l10, 171u);
        l8 = std_core$finish_buffer(l12, l10);
        l12 = vader_support_diagnostics$internal_error((uint8_t) 4, l2, l8);
        vader_array_push_ref((vader_array_t*) l7, l12);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = std_collections$MutableSet$std_core$Contains$contains__i32(((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_4, l1);
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
    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l9 = ((vader_struct_vader_midir$CFGLocal_t*) t2)->f_name;
    l13 = l3;
    l10 = vader_host_std_core$byte_len(l8);
    l11 = vader_host_std_core$byte_len(l9);
    l10 = (l10 + l11);
    l11 = vader_host_std_core$byte_len(l13);
    l10 = (l10 + l11);
    l12 = (void*) vader_buffer_new((size_t) (INT64_C(61) + l10));
    l10 = INT64_C(0);
    l10 = std_core$write_string_at(l12, l10, l8);
    l10 = std_core$write_string_at(l12, l10, 491u);
    l11 = ((int64_t) (int32_t) l1);
    l10 = std_core$write_int(l12, l10, l11);
    l10 = std_core$write_string_at(l12, l10, 85u);
    l10 = std_core$write_string_at(l12, l10, l9);
    l10 = std_core$write_string_at(l12, l10, 1179u);
    l10 = std_core$write_string_at(l12, l10, l13);
    l10 = std_core$write_string_at(l12, l10, 102u);
    l8 = std_core$finish_buffer(l12, l10);
    l12 = vader_support_diagnostics$internal_error((uint8_t) 5, l2, l8);
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
    l5 = std_core$write_string_at(l4, l5, 1618u);
    l6 = ((int64_t) (int32_t) ((vader_struct_vader_midir$BasicBlock_t*) ((vader_struct___lambda_env_vader_midir_17_t*) l0)->f_cap_2)->f_id);
    l5 = std_core$write_int(l4, l5, l6);
    l7 = std_core$finish_buffer(l4, l5);
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    ((vader_fn_erased_sig_3_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(450u, l1), vader_ref_box(l3), vader_box_string(447u, l7));
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
    l5 = std_core$write_string_at(l4, l5, 1618u);
    l6 = ((int64_t) (int32_t) ((vader_struct_vader_midir$BasicBlock_t*) ((vader_struct___lambda_env_vader_midir_19_t*) l0)->f_cap_1)->f_id);
    l5 = std_core$write_int(l4, l5, l6);
    l5 = std_core$write_string_at(l4, l5, 306u);
    l7 = std_core$finish_buffer(l4, l5);
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    ((vader_fn_erased_sig_3_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(450u, l1), vader_ref_box(l3), vader_box_string(447u, l7));
    { vader_gc_top = gc_frame.prev; return; }
}

static bool __lambda_vader_midir_2(void* l0, int32_t l1) {
    bool t0, t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_midir_3_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    t1 = t0;
    return t1;
}

void __lambda_vader_midir_20(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections$MutableSet$std_core$Contains$contains__i32(((vader_struct___lambda_env_vader_midir_21_t*) l0)->f_cap_0, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_collections$add__vader_midir$LocalId(((vader_struct___lambda_env_vader_midir_21_t*) l0)->f_cap_1, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_midir_22(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections$MutableSet$std_core$Contains$contains__i32(((vader_struct___lambda_env_vader_midir_23_t*) l0)->f_cap_0, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_collections$add__vader_midir$LocalId(((vader_struct___lambda_env_vader_midir_23_t*) l0)->f_cap_1, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

void* __lambda_vader_midir_24(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 585u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 728u);
    _a4_obj->f_inner = t0;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_midir_25(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 450u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 445u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 450u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 585u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 728u);
    _a4_obj->f_inner = t0;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_midir_26(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t t0;
    bool t1;
    l1 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_instructions;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = vader_midir$is_shrinking_intrinsic(t0);
        if (t1) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

bool __lambda_vader_midir_4(void* l0, int64_t l1) {
    vader_box_t t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_midir_5_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    return t0.tag == 1430u;
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
    t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(451u, l1));
    t1 = t0.payload.b;
    if (t1) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$ShrinkSummary_t*) ((vader_struct___lambda_env_vader_midir_7_t*) l0)->f_cap_1)->f_may_shrink);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t1 = ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l1];
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
    t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(451u, l1));
    t1 = t0.payload.b;
    if (t1) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_midir_9_t*) l0)->f_cap_1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
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
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)] = (uint8_t) true;
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

bool __lambda_vader_pipeline_comptime__vm_0(void* l0, void* l1) {
    vader_string_t l2, l3;
    void* l4;
    bool t0;
    l2 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l1)->f_callee;
    l3 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) ((vader_struct___lambda_env_vader_pipeline_comptime__vm_1_t*) l0)->f_cap_0)->f_callee;
    if (l2 != l3) {
        l4 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) ((vader_struct___lambda_env_vader_pipeline_comptime__vm_1_t*) l0)->f_cap_0)->f_reached;
        l2 = ((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) l1)->f_callee;
        t0 = std_collections$MutableSet$std_core$Contains$contains__string(l4, l2);
        return t0;
    }
    return false;
}

bool __lambda_vader_pipeline_comptime__vm_2(void* l0, vader_string_t l1) {
    bool t0;
    t0 = std_collections$MutableSet$std_core$Contains$contains__string(((vader_struct_vader_pipeline_comptime__vm$StagedDecl_t*) ((vader_struct___lambda_env_vader_pipeline_comptime__vm_3_t*) l0)->f_cap_0)->f_reached, l1);
    return t0;
}

bool __lambda_vader_pipeline_comptime__vm_4(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_vader_core_bytecode$BcFunction_t*) l1)->f_name;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct___lambda_env_vader_pipeline_comptime__vm_5_t*) l0)->f_cap_0)->f_mangled;
    return l2 == l3;
}

bool __lambda_vader_pipeline_comptime__vm_6(void* l0, vader_string_t l1) {
    bool t0;
    t0 = std_collections$MutableMap$std_core$Contains$contains__string__Any(((vader_struct___lambda_env_vader_pipeline_comptime__vm_7_t*) l0)->f_cap_0, l1);
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
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    t1 = t0;
    if (t1) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = ((vader_struct___lambda_env_vader_support_fixpoint_2_t*) l0)->f_cap_0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_support_fixpoint$Graph_t*) ((vader_struct___lambda_env_vader_support_fixpoint_2_t*) l0)->f_cap_1)->f_successors);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    vader_struct___lambda_env_vader_support_fixpoint_4_t* _a2_obj = (vader_struct___lambda_env_vader_support_fixpoint_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_support_fixpoint_4_t));
    vader_obj_header_init(_a2_obj, 569u);
    _a2_obj->f_cap_0 = ((vader_struct___lambda_env_vader_support_fixpoint_2_t*) l0)->f_cap_0;
    l4 = (void*) _a2_obj;
    l5 = false;
    l6 = ((vader_array_t*) l3)->length;
    l7 = INT64_C(0);
    {
        while ((l7 < l6)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l8 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
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
    ((uint8_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l1] = (uint8_t) l5;
    vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_support_fixpoint_2_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
    t0 = ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1];
    t1 = t0;
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool __lambda_vader_support_fixpoint_3(void* l0, int32_t l1) {
    bool t0, t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_support_fixpoint_4_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    t1 = t0;
    return t1;
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

bool __lambda_vader_vm_2(void) {
    return false;
}

bool __lambda_vader_vm_3(void* l0, vader_box_t l1) {
    void* l2;
    int32_t l3;
    void* t0;
    bool t1, t2;
    if (l1.tag == 883u) {
        l2 = ((vader_struct___lambda_env_vader_vm_4_t*) l0)->f_cap_0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        t2 = t1;
        return t2;
    }
    return false;
}

vader_box_t __lambda_vader_vm_5(void) {
    void* t0;
    t0 = (void*) &vader_data_168;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t0);
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
    l10 = vader_host_std_core$byte_len(l0);
    l11 = vader_host_std_core$byte_len(l1);
    l11 = (l10 + l11);
    l12 = vader_host_std_core$byte_len(l2);
    l12 = (l11 + l12);
    l13 = vader_host_std_core$byte_len(l3);
    l13 = (l12 + l13);
    l14 = vader_host_std_core$byte_len(l4);
    l14 = (l13 + l14);
    l15 = vader_host_std_core$byte_len(l5);
    l15 = (l14 + l15);
    l16 = vader_host_std_core$byte_len(l6);
    l16 = (l15 + l16);
    l17 = vader_host_std_core$byte_len(l7);
    l17 = (l16 + l17);
    l18 = vader_host_std_core$byte_len(l8);
    l18 = (l17 + l18);
    l19 = vader_host_std_core$byte_len(l9);
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
    l11 = vader_host_std_core$byte_len(l0);
    l12 = vader_host_std_core$byte_len(l1);
    l12 = (l11 + l12);
    l13 = vader_host_std_core$byte_len(l2);
    l13 = (l12 + l13);
    l14 = vader_host_std_core$byte_len(l3);
    l14 = (l13 + l14);
    l15 = vader_host_std_core$byte_len(l4);
    l15 = (l14 + l15);
    l16 = vader_host_std_core$byte_len(l5);
    l16 = (l15 + l16);
    l17 = vader_host_std_core$byte_len(l6);
    l17 = (l16 + l17);
    l18 = vader_host_std_core$byte_len(l7);
    l18 = (l17 + l18);
    l19 = vader_host_std_core$byte_len(l8);
    l19 = (l18 + l19);
    l20 = vader_host_std_core$byte_len(l9);
    l20 = (l19 + l20);
    l21 = vader_host_std_core$byte_len(l10);
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
    l2 = vader_host_std_core$byte_len(l0);
    l3 = vader_host_std_core$byte_len(l1);
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
    l3 = vader_host_std_core$byte_len(l0);
    l4 = vader_host_std_core$byte_len(l1);
    l4 = (l3 + l4);
    l5 = vader_host_std_core$byte_len(l2);
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
    l4 = vader_host_std_core$byte_len(l0);
    l5 = vader_host_std_core$byte_len(l1);
    l5 = (l4 + l5);
    l6 = vader_host_std_core$byte_len(l2);
    l6 = (l5 + l6);
    l7 = vader_host_std_core$byte_len(l3);
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
    l5 = vader_host_std_core$byte_len(l0);
    l6 = vader_host_std_core$byte_len(l1);
    l6 = (l5 + l6);
    l7 = vader_host_std_core$byte_len(l2);
    l7 = (l6 + l7);
    l8 = vader_host_std_core$byte_len(l3);
    l8 = (l7 + l8);
    l9 = vader_host_std_core$byte_len(l4);
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
    l6 = vader_host_std_core$byte_len(l0);
    l7 = vader_host_std_core$byte_len(l1);
    l7 = (l6 + l7);
    l8 = vader_host_std_core$byte_len(l2);
    l8 = (l7 + l8);
    l9 = vader_host_std_core$byte_len(l3);
    l9 = (l8 + l9);
    l10 = vader_host_std_core$byte_len(l4);
    l10 = (l9 + l10);
    l11 = vader_host_std_core$byte_len(l5);
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
    l7 = vader_host_std_core$byte_len(l0);
    l8 = vader_host_std_core$byte_len(l1);
    l8 = (l7 + l8);
    l9 = vader_host_std_core$byte_len(l2);
    l9 = (l8 + l9);
    l10 = vader_host_std_core$byte_len(l3);
    l10 = (l9 + l10);
    l11 = vader_host_std_core$byte_len(l4);
    l11 = (l10 + l11);
    l12 = vader_host_std_core$byte_len(l5);
    l12 = (l11 + l12);
    l13 = vader_host_std_core$byte_len(l6);
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
    l8 = vader_host_std_core$byte_len(l0);
    l9 = vader_host_std_core$byte_len(l1);
    l9 = (l8 + l9);
    l10 = vader_host_std_core$byte_len(l2);
    l10 = (l9 + l10);
    l11 = vader_host_std_core$byte_len(l3);
    l11 = (l10 + l11);
    l12 = vader_host_std_core$byte_len(l4);
    l12 = (l11 + l12);
    l13 = vader_host_std_core$byte_len(l5);
    l13 = (l12 + l13);
    l14 = vader_host_std_core$byte_len(l6);
    l14 = (l13 + l14);
    l15 = vader_host_std_core$byte_len(l7);
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
    l9 = vader_host_std_core$byte_len(l0);
    l10 = vader_host_std_core$byte_len(l1);
    l10 = (l9 + l10);
    l11 = vader_host_std_core$byte_len(l2);
    l11 = (l10 + l11);
    l12 = vader_host_std_core$byte_len(l3);
    l12 = (l11 + l12);
    l13 = vader_host_std_core$byte_len(l4);
    l13 = (l12 + l13);
    l14 = vader_host_std_core$byte_len(l5);
    l14 = (l13 + l14);
    l15 = vader_host_std_core$byte_len(l6);
    l15 = (l14 + l15);
    l16 = vader_host_std_core$byte_len(l7);
    l16 = (l15 + l16);
    l17 = vader_host_std_core$byte_len(l8);
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
