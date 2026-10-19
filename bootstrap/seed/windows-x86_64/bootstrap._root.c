#include "bootstrap.split.h"

static bool __lambda_vader_effects_23(void* l0, void* l1);
static bool __lambda_vader_fixpoint_3(void* l0, int32_t l1);
static bool __lambda_vader_typecheck_39(void* l0, void* l1);

void __defer_std_io_0(void* l0) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_host_system_windows_find_close(((vader_struct___defer_env_std_io_1_t*) l0)->f_cap_0);
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_std_numbers_0(uint32_t l0) {
    return l0 == 95u;
}

bool __lambda_std_path_0(uint32_t l0) {
    return l0 == 92u;
}

vader_box_t __lambda_vader_bytecode_0(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_bytecode_1_t*) l0)->f_cap_0;
    t0 = vader_bytecode_remap_type(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_bytecode_2(void* l0, void* l1) {
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
    l2 = ((vader_struct_vader_bytecode_BcGlobal_t*) l1)->f_name;
    l3 = ((vader_struct___lambda_env_vader_bytecode_3_t*) l0)->f_cap_0;
    l4 = ((vader_struct_vader_bytecode_BcGlobal_t*) l1)->f_type_id;
    l4 = vader_bytecode_remap_idx(l3, l4);
    vader_struct_vader_bytecode_BcGlobal_t* _a0_obj = (vader_struct_vader_bytecode_BcGlobal_t*) vader_gc_alloc(sizeof(vader_struct_vader_bytecode_BcGlobal_t));
    vader_obj_header_init(_a0_obj, 636u);
    _a0_obj->f_name = l2;
    _a0_obj->f_type_id = l4;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t __lambda_vader_bytecode_4(void* l0, int32_t l1) {
    int32_t t0;
    t0 = vader_bytecode_remap_idx(((vader_struct___lambda_env_vader_bytecode_5_t*) l0)->f_cap_0, l1);
    return t0;
}

bool __lambda_vader_c_emit_0(void* l0, int32_t l1, int32_t l2) {
    vader_string_t l3, l4;
    void* t0;
    bool t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_c_emit_1_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    l3 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_name;
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    l4 = ((vader_struct_vader_bytecode_BcFunction_t*) t0)->f_name;
    t1 = std_string_compare_ascending(l3, l4);
    return t1;
}

bool __lambda_vader_c_emit_2(vader_string_t l0, vader_string_t l1) {
    bool t0;
    t0 = std_string_compare_ascending(l0, l1);
    return t0;
}

bool __lambda_vader_c_emit_3(void* l0) {
    vader_string_t t0 = 0;
    uint8_t t1;
    bool t2;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_bytecode_BcImport_t*) l0)->f_mangled_name;
    t1 = vader_bytecode_intrinsic_id_for(t0);
    t2 = vader_bytecode_intrinsic_may_collect(t1);
    { bool __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_c_emit_4(void* l0, void* l1) {
    void* l2 = NULL;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_c_emit_5_t*) l0)->f_cap_0;
    t0 = vader_c_emit_fn_has_direct_alloc(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_c_emit_6(vader_box_t l0) {
    void* t0;
    bool t1;
    if (l0.tag == 779u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_bytecode_StructNew_t*) t0)->f_stack;
        return t1;
    }
    return false;
}

bool __lambda_vader_c_emit_7(void* l0, vader_box_t l1) {
    void* l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_c_emit_8_t*) l0)->f_cap_0;
    t0 = vader_c_emit_op_may_collect(l1, l2);
    return t0;
}

vader_box_t __lambda_vader_c_emit_9(vader_string_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_c_ast_verbatim(l0);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_c_emit_c_ast_0(void* l0, int64_t l1, int64_t l2) {
    int32_t l3, l4;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_c_emit_c_ast_1_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    return (l3 < l4);
}

bool __lambda_vader_comptime_0(void* l0, void* l1) {
    vader_string_t l2, l3;
    bool t0;
    l2 = ((vader_struct_vader_comptime_GenericInstance_t*) l0)->f_display_key;
    l3 = ((vader_struct_vader_comptime_GenericInstance_t*) l1)->f_display_key;
    t0 = std_string_compare_ascending(l2, l3);
    return t0;
}

bool __lambda_vader_comptime_1(vader_string_t l0, vader_string_t l1) {
    bool t0;
    t0 = std_string_compare_ascending(l0, l1);
    return t0;
}

void* __lambda_vader_effects_0(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(85u, 0u, 13u, 900u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 8u, 289u);
    l1 = (void*) _a1_arr;
    vader_struct_vader_effects_ParamEffects_t* _a2_obj = (vader_struct_vader_effects_ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_ParamEffects_t));
    vader_obj_header_init(_a2_obj, 921u);
    _a2_obj->f_accesses = l0;
    _a2_obj->f_origins = l1;
    _a2_obj->f_keys = vader_box_obj(0u, NULL);
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t __lambda_vader_effects_1(void) {
    return INT64_C(0);
}

void* __lambda_vader_effects_10(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(85u, 0u, 13u, 900u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 8u, 289u);
    l1 = (void*) _a1_arr;
    vader_struct_vader_effects_ParamEffects_t* _a2_obj = (vader_struct_vader_effects_ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_ParamEffects_t));
    vader_obj_header_init(_a2_obj, 921u);
    _a2_obj->f_accesses = l0;
    _a2_obj->f_origins = l1;
    _a2_obj->f_keys = vader_box_obj(0u, NULL);
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_effects_11(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_vader_effects_FaultHop_t*) l0)->f_callee;
    return t0;
}

bool __lambda_vader_effects_12(void* l0, void* l1) {
    void* l2;
    uint64_t l3;
    vader_box_t t0;
    bool t1;
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct___lambda_env_vader_effects_13_t*) l0)->f_cap_0)->f_param_types;
    l3 = toolchain_span_Span_std_core_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l1)->f_span);
    t0 = std_collections_MutableMap_std_core_Index_at__u64__Any(l2, l3);
    t1 = vader_effects_holds_references(t0);
    return !(t1);
}

void* __lambda_vader_effects_14(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_effects_none();
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_effects_15(void* l0, void* l1) {
    void* l2;
    int64_t l3;
    void* t0;
    bool t1;
    l2 = ((vader_struct___lambda_env_vader_effects_16_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_effects_Root_t*) l1)->f_param;
    t0 = vader_effects_root_record(l2, l3);
    t1 = vader_effects_is_view(t0);
    if (!(t1)) {
        return true;
    }
    t1 = vader_effects_reaches(((vader_struct___lambda_env_vader_effects_16_t*) l0)->f_cap_1, l1);
    return t1;
}

bool __lambda_vader_effects_17(void* l0, void* l1) {
    void* l2;
    int64_t l3;
    void* t0;
    bool t1;
    l2 = ((vader_struct_vader_effects_RootCase_t*) ((vader_struct___lambda_env_vader_effects_18_t*) l0)->f_cap_0)->f_body;
    l3 = ((vader_struct_vader_effects_Root_t*) l1)->f_param;
    t0 = vader_effects_root_record(l2, l3);
    t1 = vader_effects_is_view(t0);
    return t1;
}

bool __lambda_vader_effects_19(void* l0) {
    bool t0;
    if (((vader_struct_vader_effects_Access_t*) l0)->f_effect == INT32_C(4)) {
        t0 = vader_effects_is_the_view(l0);
        return t0;
    }
    return false;
}

int64_t __lambda_vader_effects_2(void) {
    return INT64_C(0);
}

bool __lambda_vader_effects_20(vader_box_t l0) {
    return !(l0.tag == 0u);
}

bool __lambda_vader_effects_21(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool l5;
    int64_t l6, l7;
    vader_box_t t0 = vader_box_null();
    bool t1;
    size_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_effects_22_t*) l0)->f_cap_0;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_ref_box(l1));
    t1 = t0.payload.b;
    if (t1) {
        l2 = ((vader_struct_vader_effects_RootCase_t*) ((vader_struct___lambda_env_vader_effects_22_t*) l0)->f_cap_1)->f_held;
        l3 = ((vader_struct___lambda_env_vader_effects_22_t*) l0)->f_cap_2;
        l4 = ((vader_struct___lambda_env_vader_effects_22_t*) l0)->f_cap_1;
        vader_struct___lambda_env_vader_effects_24_t* _a1_obj = (vader_struct___lambda_env_vader_effects_24_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_effects_24_t));
        vader_obj_header_init(_a1_obj, 316u);
        _a1_obj->f_cap_0 = l3;
        _a1_obj->f_cap_1 = l4;
        _a1_obj->f_cap_2 = l1;
        l3 = (void*) _a1_obj;
        l5 = false;
        t2 = ((vader_array_t*) l2)->length;
        l6 = (int64_t) (size_t) t2;
        l7 = INT64_C(0);
        {
            while ((l7 < l6)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
                l4 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
                t1 = __lambda_vader_effects_23(l3, l4);
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

static bool __lambda_vader_effects_23(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_effects_24_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_effects_24_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_effects_24_t*) l0)->f_cap_2;
    t0 = vader_effects_written_at(l2, l3, l1, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_effects_25(void* l0, void* l1) {
    bool t0;
    t0 = vader_effects_writes_view(((vader_struct_vader_effects_RootCase_t*) ((vader_struct___lambda_env_vader_effects_26_t*) l0)->f_cap_0)->f_paths, l1);
    return t0;
}

bool __lambda_vader_effects_27(void* l0) {
    bool t0;
    t0 = vader_effects_is_the_view(l0);
    if (t0) {
        t0 = vader_effects_keeps(l0);
        return t0;
    }
    return false;
}

bool __lambda_vader_effects_28(void* l0, vader_box_t l1) {
    int32_t l2;
    void* t0;
    bool t1;
    if (l1.tag == 903u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_effects_CalleeNode_t*) t0)->f_node;
        t1 = std_collections_MutableSet_std_core_Contains_contains__i32(((vader_struct_vader_effects_CalleeIndex_t*) ((vader_struct___lambda_env_vader_effects_29_t*) l0)->f_cap_0)->f_view_nodes, l2);
        return t1;
    }
    return false;
}

bool __lambda_vader_effects_3(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool l5;
    bool t0;
    void* t1 = NULL;
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_effects_4_t*) l0)->f_cap_0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_effects_4_t*) l0)->f_cap_1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    t0 = vader_effects_has_news(l2, l1, l3);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = ((vader_struct___lambda_env_vader_effects_4_t*) l0)->f_cap_2;
    l3 = ((vader_struct___lambda_env_vader_effects_4_t*) l0)->f_cap_3;
    l4 = ((vader_struct___lambda_env_vader_effects_4_t*) l0)->f_cap_4;
    l2 = vader_effects_node_ctx(l2, l3, l4, l1);
    l3 = ((vader_struct___lambda_env_vader_effects_4_t*) l0)->f_cap_0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_effects_4_t*) l0)->f_cap_5);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    l5 = vader_effects_settle(t1, l2);
    t0 = vader_effects_noted(l3, l1, l5);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_effects_30(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_effects_31_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_effects_31_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_effects_31_t*) l0)->f_cap_2;
    t0 = vader_effects_may_be_written(l2, l1, l3, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_effects_32(void* l0, vader_box_t l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_effects_targets_of(((vader_struct___lambda_env_vader_effects_33_t*) l0)->f_cap_0, l1);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_effects_34(void* l0, void* l1) {
    vader_string_t l2, l3;
    l2 = ((vader_struct_toolchain_ast_FnDecl_t*) l1)->f_name;
    l3 = ((vader_struct___lambda_env_vader_effects_35_t*) l0)->f_cap_0;
    return l2 == l3;
}

bool __lambda_vader_effects_5(void* l0, int32_t l1) {
    int64_t l2, l3;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_effects_Clock_t*) ((vader_struct___lambda_env_vader_effects_6_t*) l0)->f_cap_0)->f_grew_at);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l2 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    l3 = ((vader_struct___lambda_env_vader_effects_6_t*) l0)->f_cap_1;
    return (l2 > l3);
}

bool __lambda_vader_effects_7(void* l0, int32_t l1) {
    bool t0;
    t0 = std_collections_MutableSet_std_core_Contains_contains__i32(((vader_struct___lambda_env_vader_effects_8_t*) l0)->f_cap_0, l1);
    return t0;
}

void* __lambda_vader_effects_9(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(85u, 0u, 13u, 900u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 8u, 289u);
    l1 = (void*) _a1_arr;
    vader_struct_vader_effects_ParamEffects_t* _a2_obj = (vader_struct_vader_effects_ParamEffects_t*) vader_gc_alloc(sizeof(vader_struct_vader_effects_ParamEffects_t));
    vader_obj_header_init(_a2_obj, 921u);
    _a2_obj->f_accesses = l0;
    _a2_obj->f_origins = l1;
    _a2_obj->f_keys = vader_box_obj(0u, NULL);
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int32_t __lambda_vader_fixpoint_0(void) {
    return INT32_C(0);
}

bool __lambda_vader_fixpoint_1(void* l0, int32_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    bool l5;
    int64_t l6, l7;
    int32_t l8;
    vader_box_t t0 = vader_box_null();
    bool t1;
    size_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_fixpoint_2_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_box_bool(283u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
    t1 = t0.payload.b;
    if (t1) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    l2 = ((vader_struct___lambda_env_vader_fixpoint_2_t*) l0)->f_cap_0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_fixpoint_Graph_t*) ((vader_struct___lambda_env_vader_fixpoint_2_t*) l0)->f_cap_1)->f_successors);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l1);
    vader_struct___lambda_env_vader_fixpoint_4_t* _a2_obj = (vader_struct___lambda_env_vader_fixpoint_4_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_fixpoint_4_t));
    vader_obj_header_init(_a2_obj, 326u);
    _a2_obj->f_cap_0 = ((vader_struct___lambda_env_vader_fixpoint_2_t*) l0)->f_cap_0;
    l4 = (void*) _a2_obj;
    l5 = false;
    t2 = ((vader_array_t*) l3)->length;
    l6 = (int64_t) (size_t) t2;
    l7 = INT64_C(0);
    {
        while ((l7 < l6)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l8 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
            t1 = __lambda_vader_fixpoint_3(l4, l8);
            if (t1) {
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
    vader_array_t* _a5_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_fixpoint_2_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l1)
    t0 = vader_box_bool(283u, ((uint8_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l1]);
    t1 = t0.payload.b;
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool __lambda_vader_fixpoint_3(void* l0, int32_t l1) {
    vader_box_t t0;
    bool t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_fixpoint_4_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_box_bool(283u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1]);
    t1 = t0.payload.b;
    return t1;
}

void __lambda_vader_lower_0(void* l0, int32_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null(), l5 = vader_box_null();
    void* l4 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l3, &l5, &t0 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = std_collections_MutableMap_std_core_Index_at__string__Any(((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_0, l2);
    if (l3.tag == 0u) {
        l5 = std_collections_MutableMap_std_core_Index_at__i32__Any(((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_3, l1);
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        t0 = std_collections_MutableMap_std_core_Index_at__i32__bool(((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_4, l1);
        if (t0.tag == 0u) {
            std_collections_MutableMap_std_core_IndexSet_set_at__i32__bool(((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_4, l1, true);
            l4 = ((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_2;
            vader_array_push((vader_array_t*) l4, l5);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = std_collections_MutableMap_std_core_Index_at__string__bool(((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_1, l2);
    if (t0.tag == 0u) {
        std_collections_MutableMap_std_core_IndexSet_set_at__string__bool(((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_1, l2, true);
        l4 = ((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_2;
        vader_array_push((vader_array_t*) l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_lower_10(void* l0, vader_box_t l1) {
    bool l2;
    if (l1.tag == 994u) {
        l2 = true;
    } else {
        l2 = l1.tag == 1002u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1.tag == 1025u;
    }
    if (l2) {
        ((vader_struct__Cell_bool_t*) ((vader_struct___lambda_env_vader_lower_11_t*) l0)->f_cap_0.payload.obj)->f_value = true;
        return;
    }
    return;
}

void __lambda_vader_lower_12(void* l0, vader_box_t l1) {
    bool t0;
    t0 = vader_lower_pc_stmt_exits(l1);
    if (t0) {
        ((vader_struct__Cell_bool_t*) ((vader_struct___lambda_env_vader_lower_13_t*) l0)->f_cap_0.payload.obj)->f_value = true;
        return;
    }
    return;
}

void __lambda_vader_lower_14(void* l0, vader_box_t l1) {
    if (l1.tag == 990u) {
        ((vader_struct__Cell_bool_t*) ((vader_struct___lambda_env_vader_lower_15_t*) l0)->f_cap_0.payload.obj)->f_value = true;
        return;
    }
    return;
}

bool __lambda_vader_lower_16(vader_box_t l0) {
    bool t0;
    t0 = vader_types_contains_distinct(l0);
    return t0;
}

bool __lambda_vader_lower_17(void* l0, vader_box_t l1) {
    void* l2;
    void* l3;
    bool t0;
    l2 = ((vader_struct_vader_lower_CallTarget_t*) ((vader_struct___lambda_env_vader_lower_18_t*) l0)->f_cap_0)->f_owner;
    l3 = ((vader_struct___lambda_env_vader_lower_18_t*) l0)->f_cap_1;
    t0 = vader_lower_loops_over(l1, l2, l3);
    return t0;
}

void __lambda_vader_lower_2(void* l0, vader_string_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = concat_3(l1, 2797u, l2);
    t0 = std_collections_MutableMap_std_core_Index_at__string__bool(((vader_struct___lambda_env_vader_lower_3_t*) l0)->f_cap_0, l3);
    if (t0.tag == 0u) {
        std_collections_MutableMap_std_core_IndexSet_set_at__string__bool(((vader_struct___lambda_env_vader_lower_3_t*) l0)->f_cap_0, l3, true);
        vader_array_push((vader_array_t*) ((vader_struct___lambda_env_vader_lower_3_t*) l0)->f_cap_1, vader_box_string(285u, l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_lower_4(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_lower_5_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_lower_5_t*) l0)->f_cap_1;
    vader_lower_push_struct_shape(l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_lower_6(void* l0, vader_box_t l1) {
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
    if (l1.tag == 1018u) {
        l2 = ((vader_struct___lambda_env_vader_lower_7_t*) l0)->f_cap_0;
        l3 = l1.payload.obj;
        t0 = vader_lower_binds_bare_capture(l2, l3);
        if (t0) {
            l2 = ((vader_struct___lambda_env_vader_lower_7_t*) l0)->f_cap_1;
            l3 = l1.payload.obj;
            l4 = ((vader_struct___lambda_env_vader_lower_7_t*) l0)->f_cap_2;
            l3 = vader_lower_bare_capture_error(l3, l4);
            vader_array_push((vader_array_t*) l2, vader_ref_box(l3));
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_vader_lower_8(vader_box_t l0) {
    bool t0;
    t0 = vader_types_boxes_as_representation(l0);
    return t0;
}

bool __lambda_vader_lower_9(vader_string_t l0, vader_string_t l1) {
    bool t0;
    t0 = std_string_compare_ascending(l0, l1);
    return t0;
}

void __lambda_vader_midir_0(void* l0, int32_t l1) {
    vader_midir_mark_referenced(((vader_struct___lambda_env_vader_midir_1_t*) l0)->f_cap_0, l1);
    return;
}

void* __lambda_vader_midir_11(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 376u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 510u);
    _a4_obj->f_inner = t0;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_midir_12(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    l0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(12u, 0u, 12u, 283u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 7u, 288u);
    l2 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 376u);
    _a3_obj->f_ekeys = l0;
    _a3_obj->f_evals = l1;
    _a3_obj->f_index = l2;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 510u);
    _a4_obj->f_inner = t0;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_midir_13(void* l0, int32_t l1) {
    bool t0;
    t0 = vader_midir_is_union_row(((vader_struct___lambda_env_vader_midir_14_t*) l0)->f_cap_0, l1);
    return t0;
}

bool __lambda_vader_midir_15(vader_box_t l0) {
    bool t0;
    t0 = vader_midir_is_union_slot(l0);
    return t0;
}

bool __lambda_vader_midir_16(void* l0, void* l1) {
    void* l2;
    int32_t l3;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_midir_17_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_bytecode_BcField_t*) l1)->f_type_index;
    t0 = vader_midir_is_union_row(l2, l3);
    return t0;
}

void __lambda_vader_midir_2(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int32_t l4;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_std_core_Index_at__i32__i32(((vader_struct___lambda_env_vader_midir_3_t*) l0)->f_cap_0, l1);
    if (l2.tag == 0u) {
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__i32(((vader_struct___lambda_env_vader_midir_3_t*) l0)->f_cap_0, l1, INT32_C(1));
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((vader_struct___lambda_env_vader_midir_3_t*) l0)->f_cap_0;
    t0 = ((int32_t) l2.payload.i);
    l4 = vader_chk_add(i32, t0, INT32_C(1));
    std_collections_MutableMap_std_core_IndexSet_set_at__i32__i32(l3, l1, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_midir_4(void* l0, int32_t l1) {
    int32_t l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_midir_5_t*) l0)->f_cap_0;
    t0 = vader_midir_LocalId_std_core_Equals_equals(l1, l2);
    if (t0) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_midir_5_t*) l0)->f_cap_1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)] = (uint8_t) true;
        return;
    }
    return;
}

void* __lambda_vader_midir_6(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 7u, 288u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_midir_7(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_std_core_Contains_contains__i32(((vader_struct___lambda_env_vader_midir_8_t*) l0)->f_cap_0, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_collections_add__i32(((vader_struct___lambda_env_vader_midir_8_t*) l0)->f_cap_1, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_midir_9(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_std_core_Contains_contains__i32(((vader_struct___lambda_env_vader_midir_10_t*) l0)->f_cap_0, l1);
    if (t0) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_collections_add__i32(((vader_struct___lambda_env_vader_midir_10_t*) l0)->f_cap_1, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_vader_resolver_0(vader_string_t l0, vader_string_t l1) {
    bool t0;
    t0 = std_string_compare_ascending(l0, l1);
    return t0;
}

bool __lambda_vader_resolver_1(void* l0, void* l1) {
    vader_string_t l2, l3;
    bool t0;
    l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_name;
    t0 = std_string_compare_ascending(l2, l3);
    return t0;
}

bool __lambda_vader_resolver_2(void* l0) {
    vader_string_t t0;
    t0 = ((vader_struct_toolchain_ast_Decorator_t*) l0)->f_name;
    return t0 == 1626u;
}

void __lambda_vader_typecheck_0(void* l0, vader_box_t l1) {
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push((vader_array_t*) ((vader_struct___lambda_env_vader_typecheck_1_t*) l0)->f_cap_0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

uint8_t __lambda_vader_typecheck_10(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_typecheck_11_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_typecheck_11_t*) l0)->f_cap_1;
    t0 = vader_typecheck_copy_node_resolutions(l1, l2, l3);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_typecheck_12(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_typecheck_13_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_typecheck_13_t*) l0)->f_cap_1;
    t0 = vader_typecheck_contract_of(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_typecheck_14(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct___lambda_env_vader_typecheck_15_t*) l0)->f_cap_0;
    l2 = ((vader_struct___lambda_env_vader_typecheck_15_t*) l0)->f_cap_1;
    t0 = vader_typecheck_ensures_of(l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t __lambda_vader_typecheck_16(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_types_display_type(l0);
    t0 = concat_3(896u, l1, 896u);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_typecheck_17(int64_t l0, int64_t l1) {
    return (l0 < l1);
}

bool __lambda_vader_typecheck_18(void* l0, vader_box_t l1) {
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_typecheck_keeps_concrete(((vader_struct___lambda_env_vader_typecheck_19_t*) l0)->f_cap_0, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t __lambda_vader_typecheck_2(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_typecheck_3_t*) l0)->f_cap_0;
    t0 = vader_typecheck_probe_step(l1, l2);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t __lambda_vader_typecheck_20(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    uint8_t t0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_typecheck_21_t*) l0)->f_cap_0;
    t0 = vader_typecheck_probe_step(l1, l2);
    { uint8_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_typecheck_22(void) {
    return false;
}

bool __lambda_vader_typecheck_23(void* l0, void* l1) {
    void* l2;
    int32_t l3;
    vader_box_t t0;
    l2 = ((vader_struct___lambda_env_vader_typecheck_24_t*) l0)->f_cap_0;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) l1)->f_symbol)->f_id;
    t0 = std_collections_MutableMap_std_core_Index_at__i32__Any(l2, l3);
    return !(t0.tag == 0u);
}

vader_box_t __lambda_vader_typecheck_25(vader_box_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_typecheck_default_if_free(l0);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_typecheck_26(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct___lambda_env_vader_typecheck_27_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_typecheck_27_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_typecheck_27_t*) l0)->f_cap_2;
    vader_typecheck_check_guard_return(l2, l1, l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_typecheck_28(void* l0, vader_box_t l1) {
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
    l2 = ((vader_struct___lambda_env_vader_typecheck_29_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_typecheck_29_t*) l0)->f_cap_1;
    l4 = ((vader_struct___lambda_env_vader_typecheck_29_t*) l0)->f_cap_2;
    l5 = ((vader_struct___lambda_env_vader_typecheck_29_t*) l0)->f_cap_3;
    vader_typecheck_check_ensured_value(l2, l1, l3, l4, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_vader_typecheck_30(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) ((vader_struct___lambda_env_vader_typecheck_31_t*) l0)->f_cap_0)->f_symbol)->f_id;
    return l2 == l3;
}

bool __lambda_vader_typecheck_32(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) l1)->f_symbol)->f_id;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct___lambda_env_vader_typecheck_33_t*) l0)->f_cap_0)->f_id;
    return l2 == l3;
}

bool __lambda_vader_typecheck_34(vader_box_t l0) {
    return l0.tag == 1256u;
}

bool __lambda_vader_typecheck_35(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) l1)->f_symbol)->f_id;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_InferVar_t*) ((vader_struct___lambda_env_vader_typecheck_36_t*) l0)->f_cap_0)->f_origin)->f_id;
    return l2 == l3;
}

bool __lambda_vader_typecheck_37(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    bool l4;
    int64_t l5, l6;
    size_t t0;
    bool t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1260u) {
        l2 = ((vader_struct___lambda_env_vader_typecheck_38_t*) l0)->f_cap_0;
        vader_struct___lambda_env_vader_typecheck_40_t* _a0_obj = (vader_struct___lambda_env_vader_typecheck_40_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_typecheck_40_t));
        vader_obj_header_init(_a0_obj, 356u);
        _a0_obj->f_cap_0 = l1;
        l3 = (void*) _a0_obj;
        l4 = false;
        t0 = ((vader_array_t*) l2)->length;
        l5 = (int64_t) (size_t) t0;
        l6 = INT64_C(0);
        {
            while ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l7 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                t1 = __lambda_vader_typecheck_39(l3, l7);
                if (t1) {
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

static bool __lambda_vader_typecheck_39(void* l0, void* l1) {
    int32_t l2, l3;
    void* t0;
    l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
    t0 = ((vader_struct___lambda_env_vader_typecheck_40_t*) l0)->f_cap_0.payload.obj;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_id;
    return l2 == l3;
}

bool __lambda_vader_typecheck_4(void* l0, void* l1) {
    int32_t l2, l3;
    l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) l1)->f_symbol)->f_id;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct___lambda_env_vader_typecheck_5_t*) l0)->f_cap_0)->f_id;
    return l2 == l3;
}

bool __lambda_vader_typecheck_41(void* l0, vader_box_t l1) {
    vader_box_t l2;
    bool t0;
    l2 = ((vader_struct___lambda_env_vader_typecheck_42_t*) l0)->f_cap_0;
    t0 = vader_typecheck_equals_type(l1, l2);
    return t0;
}

bool __lambda_vader_typecheck_43(void* l0, vader_string_t l1) {
    vader_string_t l2;
    l2 = ((vader_struct___lambda_env_vader_typecheck_44_t*) l0)->f_cap_0;
    return l1 == l2;
}

bool __lambda_vader_typecheck_45(void* l0, vader_box_t l1) {
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
    l2 = ((vader_struct___lambda_env_vader_typecheck_46_t*) l0)->f_cap_0;
    l3 = ((vader_struct___lambda_env_vader_typecheck_46_t*) l0)->f_cap_1;
    t0 = vader_typecheck_struct_implements_trait(l1, l2, l3);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_typecheck_47(vader_box_t l0) {
    void* l1 = NULL;
    bool t0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = (void*) &vader_fn_static___lambda_vader_typecheck_48;
    t0 = vader_types_any_type(l0, l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_typecheck_48(vader_box_t l0) {
    return l0.tag == 1255u;
}

bool __lambda_vader_typecheck_49(vader_box_t l0) {
    bool t0;
    vader_box_t* gc_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_typecheck_nests_self(l0);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_typecheck_50(vader_box_t l0) {
    return l0.tag == 1255u;
}

void __lambda_vader_typecheck_6(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1260u) {
        l2 = ((vader_struct___lambda_env_vader_typecheck_7_t*) l0)->f_cap_0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol;
        vader_array_push((vader_array_t*) l2, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_vader_typecheck_8(void* l0, int64_t l1, int64_t l2) {
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
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_typecheck_9_t*) l0)->f_cap_0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct___lambda_env_vader_typecheck_9_t*) l0)->f_cap_1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l1)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l1];
    l4 = t0.payload.s;
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
    t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l2];
    l6 = t0.payload.s;
    t1 = vader_typecheck_comes_before(l3, l4, l5, l6);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_vm_0(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    uint8_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_bytecode_BytecodeModule_t*) ((vader_struct___lambda_env_vader_vm_1_t*) l0)->f_cap_0)->f_types;
    l3 = ((vader_struct_vader_bytecode_BcGlobal_t*) l1)->f_type_id;
    t0 = vader_vm_field_valtype(l2, l3);
    t1 = vader_vm_global_zero(t0);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_vm_2(void) {
    return false;
}

bool __lambda_vader_vm_3(void* l0, vader_box_t l1) {
    void* l2;
    int32_t l3;
    void* t0;
    vader_box_t t1;
    bool t2;
    if (l1.tag == 667u) {
        l2 = ((vader_struct___lambda_env_vader_vm_4_t*) l0)->f_cap_0;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_bytecode_Call_t*) t0)->f_function_index;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t1 = vader_box_bool(283u, ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3]);
        t2 = t1.payload.b;
        return t2;
    }
    return false;
}

vader_box_t __lambda_vader_vm_5(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_vm_NullVal_t* _a0_obj = (vader_struct_vader_vm_NullVal_t*) vader_gc_alloc(sizeof(vader_struct_vader_vm_NullVal_t));
    vader_obj_header_init(_a0_obj, 1275u);
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    l10 = vader_host_std_core_byte_len(l0);
    l11 = vader_host_std_core_byte_len(l1);
    l11 = (l10 + l11);
    l12 = vader_host_std_core_byte_len(l2);
    l12 = (l11 + l12);
    l13 = vader_host_std_core_byte_len(l3);
    l13 = (l12 + l13);
    l14 = vader_host_std_core_byte_len(l4);
    l14 = (l13 + l14);
    l15 = vader_host_std_core_byte_len(l5);
    l15 = (l14 + l15);
    l16 = vader_host_std_core_byte_len(l6);
    l16 = (l15 + l16);
    l17 = vader_host_std_core_byte_len(l7);
    l17 = (l16 + l17);
    l18 = vader_host_std_core_byte_len(l8);
    l18 = (l17 + l18);
    l19 = vader_host_std_core_byte_len(l9);
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
    l11 = vader_host_std_core_byte_len(l0);
    l12 = vader_host_std_core_byte_len(l1);
    l12 = (l11 + l12);
    l13 = vader_host_std_core_byte_len(l2);
    l13 = (l12 + l13);
    l14 = vader_host_std_core_byte_len(l3);
    l14 = (l13 + l14);
    l15 = vader_host_std_core_byte_len(l4);
    l15 = (l14 + l15);
    l16 = vader_host_std_core_byte_len(l5);
    l16 = (l15 + l16);
    l17 = vader_host_std_core_byte_len(l6);
    l17 = (l16 + l17);
    l18 = vader_host_std_core_byte_len(l7);
    l18 = (l17 + l18);
    l19 = vader_host_std_core_byte_len(l8);
    l19 = (l18 + l19);
    l20 = vader_host_std_core_byte_len(l9);
    l20 = (l19 + l20);
    l21 = vader_host_std_core_byte_len(l10);
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
    l2 = vader_host_std_core_byte_len(l0);
    l3 = vader_host_std_core_byte_len(l1);
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
    l3 = vader_host_std_core_byte_len(l0);
    l4 = vader_host_std_core_byte_len(l1);
    l4 = (l3 + l4);
    l5 = vader_host_std_core_byte_len(l2);
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
    l4 = vader_host_std_core_byte_len(l0);
    l5 = vader_host_std_core_byte_len(l1);
    l5 = (l4 + l5);
    l6 = vader_host_std_core_byte_len(l2);
    l6 = (l5 + l6);
    l7 = vader_host_std_core_byte_len(l3);
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
    l5 = vader_host_std_core_byte_len(l0);
    l6 = vader_host_std_core_byte_len(l1);
    l6 = (l5 + l6);
    l7 = vader_host_std_core_byte_len(l2);
    l7 = (l6 + l7);
    l8 = vader_host_std_core_byte_len(l3);
    l8 = (l7 + l8);
    l9 = vader_host_std_core_byte_len(l4);
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
    l6 = vader_host_std_core_byte_len(l0);
    l7 = vader_host_std_core_byte_len(l1);
    l7 = (l6 + l7);
    l8 = vader_host_std_core_byte_len(l2);
    l8 = (l7 + l8);
    l9 = vader_host_std_core_byte_len(l3);
    l9 = (l8 + l9);
    l10 = vader_host_std_core_byte_len(l4);
    l10 = (l9 + l10);
    l11 = vader_host_std_core_byte_len(l5);
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
    l7 = vader_host_std_core_byte_len(l0);
    l8 = vader_host_std_core_byte_len(l1);
    l8 = (l7 + l8);
    l9 = vader_host_std_core_byte_len(l2);
    l9 = (l8 + l9);
    l10 = vader_host_std_core_byte_len(l3);
    l10 = (l9 + l10);
    l11 = vader_host_std_core_byte_len(l4);
    l11 = (l10 + l11);
    l12 = vader_host_std_core_byte_len(l5);
    l12 = (l11 + l12);
    l13 = vader_host_std_core_byte_len(l6);
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
    l8 = vader_host_std_core_byte_len(l0);
    l9 = vader_host_std_core_byte_len(l1);
    l9 = (l8 + l9);
    l10 = vader_host_std_core_byte_len(l2);
    l10 = (l9 + l10);
    l11 = vader_host_std_core_byte_len(l3);
    l11 = (l10 + l11);
    l12 = vader_host_std_core_byte_len(l4);
    l12 = (l11 + l12);
    l13 = vader_host_std_core_byte_len(l5);
    l13 = (l12 + l13);
    l14 = vader_host_std_core_byte_len(l6);
    l14 = (l13 + l14);
    l15 = vader_host_std_core_byte_len(l7);
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
    l9 = vader_host_std_core_byte_len(l0);
    l10 = vader_host_std_core_byte_len(l1);
    l10 = (l9 + l10);
    l11 = vader_host_std_core_byte_len(l2);
    l11 = (l10 + l11);
    l12 = vader_host_std_core_byte_len(l3);
    l12 = (l11 + l12);
    l13 = vader_host_std_core_byte_len(l4);
    l13 = (l12 + l13);
    l14 = vader_host_std_core_byte_len(l5);
    l14 = (l13 + l14);
    l15 = vader_host_std_core_byte_len(l6);
    l15 = (l14 + l15);
    l16 = vader_host_std_core_byte_len(l7);
    l16 = (l15 + l16);
    l17 = vader_host_std_core_byte_len(l8);
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
