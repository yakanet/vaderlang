#include "bootstrap.split.h"

void __defer_std_io_0(void* l0) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_host_system_posix_sys_closedir(((vader_struct__Cell_CPointer_t*) ((vader_struct___defer_env_std_io_1_t*) l0)->f_cap_0.payload.obj)->f_value);
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_std_numbers_0(void* l0, uint32_t l1) {
    return l1 == 95u;
}

bool __lambda_std_path_0(void* l0, uint32_t l1) {
    return l1 == 92u;
}

bool __lambda_vader_c_emit_0(void* l0, int32_t l1, int32_t l2) {
    void* l3 = NULL;
    size_t l4;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    void** gc_raw_roots[3] = { &l0, &l3, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l5, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct__Cell_Array_Struct_vader_bytecode_BcFunction____t*) ((vader_struct___lambda_env_vader_c_emit_1_t*) l0)->f_cap_0.payload.obj)->f_value;
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_name;
    l3 = ((vader_struct__Cell_Array_Struct_vader_bytecode_BcFunction____t*) ((vader_struct___lambda_env_vader_c_emit_1_t*) l0)->f_cap_0.payload.obj)->f_value;
    t0 = ((int64_t) (int32_t) l2);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_name;
    t2 = std_string_compare_ascending(l5, l6);
    { bool __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_c_emit_2(void* l0, vader_string_t l1, vader_string_t l2) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_compare_ascending(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_c_emit_4(void* l0, vader_string_t l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_c_ast_verbatim(l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_c_emit_c_ast_0(void* l0, size_t l1, size_t l2) {
    int32_t l3, l4;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct__Cell_Array_i32__t*) ((vader_struct___lambda_env_vader_c_emit_c_ast_1_t*) l0)->f_cap_0.payload.obj)->f_value);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    l3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    l4 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    return (l3 < l4);
}

bool __lambda_vader_comptime_0(void* l0, void* l1, void* l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_comptime_GenericInstance_t*) l1)->f_display_key;
    l4 = ((vader_struct_vader_comptime_GenericInstance_t*) l2)->f_display_key;
    t0 = std_string_compare_ascending(l3, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_comptime_2(void* l0, vader_string_t l1, vader_string_t l2) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_compare_ascending(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_lower_0(void* l0, int32_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = std_collections_MutableMap_Index_at__string__Any(((vader_struct__Cell_Struct_std_collections_MutableMap_string_Union_Struct_vader_lower_LoweredConstDecl___Struct_vader_lower_LoweredFnDecl___Struct_vader_lower_LoweredStructDecl_____t*) ((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_0.payload.obj)->f_value, l2);
    if (!(l3.tag == 0u)) {
        t0 = std_collections_MutableMap_Index_at__string__bool(((vader_struct__Cell_Struct_std_collections_MutableMap_string_bool__t*) ((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_1.payload.obj)->f_value, l2);
        if (t0.tag == 0u) {
            std_collections_MutableMap_IndexSet_set_at__string__bool(((vader_struct__Cell_Struct_std_collections_MutableMap_string_bool__t*) ((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_1.payload.obj)->f_value, l2, true);
            l4 = ((vader_struct__Cell_Array_Union_Struct_vader_lower_LoweredConstDecl___Struct_vader_lower_LoweredFnDecl___Struct_vader_lower_LoweredStructDecl_____t*) ((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_2.payload.obj)->f_value;
            vader_array_push((vader_array_t*) l4, l3);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = std_collections_MutableMap_Index_at__i32__Any(((vader_struct__Cell_Struct_std_collections_MutableMap_i32_Union_Struct_vader_lower_LoweredConstDecl___Struct_vader_lower_LoweredFnDecl___Struct_vader_lower_LoweredStructDecl_____t*) ((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_3.payload.obj)->f_value, l1);
    if (!(l3.tag == 0u)) {
        t0 = std_collections_MutableMap_Index_at__i32__bool(((vader_struct__Cell_Struct_std_collections_MutableMap_i32_bool__t*) ((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_4.payload.obj)->f_value, l1);
        if (t0.tag == 0u) {
            std_collections_MutableMap_IndexSet_set_at__i32__bool(((vader_struct__Cell_Struct_std_collections_MutableMap_i32_bool__t*) ((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_4.payload.obj)->f_value, l1, true);
            l4 = ((vader_struct__Cell_Array_Union_Struct_vader_lower_LoweredConstDecl___Struct_vader_lower_LoweredFnDecl___Struct_vader_lower_LoweredStructDecl_____t*) ((vader_struct___lambda_env_vader_lower_1_t*) l0)->f_cap_2.payload.obj)->f_value;
            vader_array_push((vader_array_t*) l4, l3);
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
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
    l3 = concat_3(l1, 2378u, l2);
    t0 = std_collections_MutableMap_Index_at__string__bool(((vader_struct__Cell_Struct_std_collections_MutableMap_string_bool__t*) ((vader_struct___lambda_env_vader_lower_3_t*) l0)->f_cap_0.payload.obj)->f_value, l3);
    if (t0.tag == 0u) {
        std_collections_MutableMap_IndexSet_set_at__string__bool(((vader_struct__Cell_Struct_std_collections_MutableMap_string_bool__t*) ((vader_struct___lambda_env_vader_lower_3_t*) l0)->f_cap_0.payload.obj)->f_value, l3, true);
        vader_array_push((vader_array_t*) ((vader_struct__Cell_Array_string__t*) ((vader_struct___lambda_env_vader_lower_3_t*) l0)->f_cap_1.payload.obj)->f_value, vader_box_string(190u, l3));
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
    l2 = ((vader_struct__Cell_Array_Struct_vader_types_StructType____t*) ((vader_struct___lambda_env_vader_lower_5_t*) l0)->f_cap_0.payload.obj)->f_value;
    l3 = ((vader_struct__Cell_Struct_std_collections_MutableMap_i32_Array_Struct_vader_types_StructType_____t*) ((vader_struct___lambda_env_vader_lower_5_t*) l0)->f_cap_1.payload.obj)->f_value;
    vader_lower_push_struct_shape(l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_vader_lower_6(void* l0, vader_string_t l1, vader_string_t l2) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_compare_ascending(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_midir_0(void* l0, int32_t l1) {
    size_t l2, l3;
    void* l4;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_struct__Cell_usize_t*) ((vader_struct___lambda_env_vader_midir_1_t*) l0)->f_cap_0.payload.obj)->f_value;
    if ((l2 < l3)) {
        l4 = ((vader_struct__Cell_Array_bool__t*) ((vader_struct___lambda_env_vader_midir_1_t*) l0)->f_cap_1.payload.obj)->f_value;
        t0 = ((int64_t) (int32_t) l1);
        l2 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2] = (uint8_t) true;
    }
    return;
}

void __lambda_vader_midir_10(void* l0, int32_t l1) {
    int32_t l2;
    bool t0;
    l2 = ((vader_struct__Cell_i32_t*) ((vader_struct___lambda_env_vader_midir_11_t*) l0)->f_cap_0.payload.obj)->f_value;
    t0 = vader_midir_LocalId_Equals_equals(l1, l2);
    if (t0) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct__Cell_Array_bool__t*) ((vader_struct___lambda_env_vader_midir_11_t*) l0)->f_cap_1.payload.obj)->f_value);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)] = (uint8_t) true;
    }
    return;
}

void __lambda_vader_midir_12(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_Contains_contains__i32(((vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) ((vader_struct___lambda_env_vader_midir_13_t*) l0)->f_cap_0.payload.obj)->f_value, l1);
    if (!(t0)) {
        std_collections_add__i32(((vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) ((vader_struct___lambda_env_vader_midir_13_t*) l0)->f_cap_1.payload.obj)->f_value, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void __lambda_vader_midir_14(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_Contains_contains__i32(((vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) ((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_0.payload.obj)->f_value, l1);
    if (!(t0)) {
        std_collections_add__i32(((vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) ((vader_struct___lambda_env_vader_midir_15_t*) l0)->f_cap_1.payload.obj)->f_value, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void* __lambda_vader_midir_16(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 188u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 294u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 362u);
    _a4_obj->f_inner = t0;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_midir_18(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 188u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 294u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 362u);
    _a4_obj->f_inner = t0;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_midir_2(void* l0, int32_t l1) {
    size_t l2, l3;
    void* l4;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_struct__Cell_usize_t*) ((vader_struct___lambda_env_vader_midir_3_t*) l0)->f_cap_0.payload.obj)->f_value;
    if ((l2 < l3)) {
        l4 = ((vader_struct__Cell_Array_bool__t*) ((vader_struct___lambda_env_vader_midir_3_t*) l0)->f_cap_1.payload.obj)->f_value;
        t0 = ((int64_t) (int32_t) l1);
        l2 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2] = (uint8_t) true;
    }
    return;
}

void* __lambda_vader_midir_4(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* __lambda_vader_midir_6(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 193u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void __lambda_vader_midir_8(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int32_t l4;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_Index_at__i32__i32(((vader_struct__Cell_Struct_std_collections_MutableMap_i32_i32__t*) ((vader_struct___lambda_env_vader_midir_9_t*) l0)->f_cap_0.payload.obj)->f_value, l1);
    if (l2.tag == 0u) {
        std_collections_MutableMap_IndexSet_set_at__i32__i32(((vader_struct__Cell_Struct_std_collections_MutableMap_i32_i32__t*) ((vader_struct___lambda_env_vader_midir_9_t*) l0)->f_cap_0.payload.obj)->f_value, l1, INT32_C(1));
    } else {
        l3 = ((vader_struct__Cell_Struct_std_collections_MutableMap_i32_i32__t*) ((vader_struct___lambda_env_vader_midir_9_t*) l0)->f_cap_0.payload.obj)->f_value;
        t0 = ((int32_t) l2.payload.i);
        l4 = (t0 + INT32_C(1));
        std_collections_MutableMap_IndexSet_set_at__i32__i32(l3, l1, l4);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

bool __lambda_vader_resolver_0(void* l0, void* l1, void* l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_name;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_name;
    t0 = std_string_compare_ascending(l3, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_resolver_2(void* l0, vader_string_t l1, vader_string_t l2) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_compare_ascending(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_typecheck_0(void* l0, void* l1, void* l2) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_types_mk_struct(l1, l2, false);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_typecheck_2(void* l0, size_t l1, size_t l2) {
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct__Cell_Array_string__t*) ((vader_struct___lambda_env_vader_typecheck_3_t*) l0)->f_cap_0.payload.obj)->f_value);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l1];
    l3 = t0.payload.s;
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
    t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l2];
    l4 = t0.payload.s;
    t1 = std_string_compare_ascending_ci(l3, l4);
    { bool __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_typecheck_4(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l3, &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct__Cell_Fn_Union_Struct_toolchain_ast_ArrayTypeExpr___Struct_toolchain_ast_AwaitExpr___Struct_toolchain_ast_BinaryExpr___Struct_toolchain_ast_BlockExpr___Struct_toolchain_ast_BoolLitExpr___Struct_toolchain_ast_CallExpr___Struct_toolchain_ast_CastExpr___Struct_toolchain_ast_CharLitExpr___Struct_toolchain_ast_DotVariantExpr___Struct_toolchain_ast_FieldExpr___Struct_toolchain_ast_FloatLitExpr___Struct_toolchain_ast_FnTypeExpr___Struct_toolchain_ast_GenericInstExpr___Struct_toolchain_ast_IdentExpr___Struct_toolchain_ast_IfExpr___Struct_toolchain_ast_IndexExpr___Struct_toolchain_ast_IntLitExpr___Struct_toolchain_ast_IntrinsicCallExpr___Struct_toolchain_ast_LambdaExpr___Struct_toolchain_ast_MatchExpr___Struct_toolchain_ast_MutableTypeExpr___Struct_toolchain_ast_NullCoalesceExpr___Struct_toolchain_ast_NullLitExpr___Struct_toolchain_ast_RangeExpr___Struct_toolchain_ast_SeqLitExpr___Struct_toolchain_ast_StringLitExpr___Struct_toolchain_ast_StructLitExpr___Struct_toolchain_ast_UnaryExpr____Union_Struct_vader_types_AnyType___Struct_vader_types_ArrayType___Struct_vader_types_DistinctType___Struct_vader_types_EnumType___Struct_vader_types_FnType___Struct_vader_types_FreeCharType___Struct_vader_types_FreeFloatType___Struct_vader_types_FreeIntType___Struct_vader_types_NeverType___null_Struct_vader_types_PrimitiveType___Struct_vader_types_SelfType___Struct_vader_types_StructType___Struct_vader_types_TraitType___Struct_vader_types_TupleType___Struct_vader_types_TypeMetaType___Struct_vader_types_TypeParamType___Struct_vader_types_UnionType___Struct_vader_types_UnresolvedType____Struct_vader_typecheck_TypedProgram___Array_Struct_vader_diagnostics_Diagnostic______Union_Struct_vader_types_AnyType___Struct_vader_types_ArrayType___Struct_vader_types_DistinctType___Struct_vader_types_EnumType___Struct_vader_types_FnType___Struct_vader_types_FreeCharType___Struct_vader_types_FreeFloatType___Struct_vader_types_FreeIntType___Struct_vader_types_NeverType___Struct_vader_types_PrimitiveType___Struct_vader_types_SelfType___Struct_vader_types_StructType___Struct_vader_types_TraitType___Struct_vader_types_TupleType___Struct_vader_types_TypeMetaType___Struct_vader_types_TypeParamType___Struct_vader_types_UnionType___Struct_vader_types_UnresolvedType____t*) ((vader_struct___lambda_env_vader_typecheck_5_t*) l0)->f_cap_0.payload.obj)->f_value;
    l3 = ((vader_struct__Cell_Union_Struct_vader_types_AnyType___Struct_vader_types_ArrayType___Struct_vader_types_DistinctType___Struct_vader_types_EnumType___Struct_vader_types_FnType___Struct_vader_types_FreeCharType___Struct_vader_types_FreeFloatType___Struct_vader_types_FreeIntType___Struct_vader_types_NeverType___null_Struct_vader_types_PrimitiveType___Struct_vader_types_SelfType___Struct_vader_types_StructType___Struct_vader_types_TraitType___Struct_vader_types_TupleType___Struct_vader_types_TypeMetaType___Struct_vader_types_TypeParamType___Struct_vader_types_UnionType___Struct_vader_types_UnresolvedType____t*) ((vader_struct___lambda_env_vader_typecheck_5_t*) l0)->f_cap_1.payload.obj)->f_value;
    l4 = ((vader_struct__Cell_Struct_vader_typecheck_TypedProgram___t*) ((vader_struct___lambda_env_vader_typecheck_5_t*) l0)->f_cap_2.payload.obj)->f_value;
    l5 = ((vader_struct__Cell_Array_Struct_vader_diagnostics_Diagnostic____t*) ((vader_struct___lambda_env_vader_typecheck_5_t*) l0)->f_cap_3.payload.obj)->f_value;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_4_t) _a0_fnobj->code)(_a0_fnobj->env, l1, l3, vader_ref_box(l4), vader_ref_box(l5));
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t __lambda_vader_typecheck_6(void* l0, vader_box_t l1) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_typecheck_default_if_free(l1);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

bool __lambda_vader_vm_0(void* l0, int64_t l1, int64_t l2) {
    return l1 != l2;
}

bool __lambda_vader_vm_2(void* l0, int64_t l1, int64_t l2) {
    return l1 == l2;
}

bool __lambda_vader_vm_4(void* l0, vader_string_t l1, vader_string_t l2) {
    return l1 != l2;
}

bool __lambda_vader_vm_6(void* l0, vader_string_t l1, vader_string_t l2) {
    return l1 == l2;
}

vader_string_t concat_11(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8, vader_string_t l9, vader_string_t l10) {
    size_t l11, l12, l13, l14, l15, l16, l17, l18, l19, l20, l21;
    void* l22 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l22 };
    vader_string_t* gc_atom_roots[12] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &t1,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 12u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l11 = vader_host_std_core_byte_len(l0);
    l12 = vader_host_std_core_byte_len(l1);
    t0 = (l11 + l12);
    l12 = (size_t) (int64_t) t0;
    l13 = vader_host_std_core_byte_len(l2);
    t0 = (l12 + l13);
    l13 = (size_t) (int64_t) t0;
    l14 = vader_host_std_core_byte_len(l3);
    t0 = (l13 + l14);
    l14 = (size_t) (int64_t) t0;
    l15 = vader_host_std_core_byte_len(l4);
    t0 = (l14 + l15);
    l15 = (size_t) (int64_t) t0;
    l16 = vader_host_std_core_byte_len(l5);
    t0 = (l15 + l16);
    l16 = (size_t) (int64_t) t0;
    l17 = vader_host_std_core_byte_len(l6);
    t0 = (l16 + l17);
    l17 = (size_t) (int64_t) t0;
    l18 = vader_host_std_core_byte_len(l7);
    t0 = (l17 + l18);
    l18 = (size_t) (int64_t) t0;
    l19 = vader_host_std_core_byte_len(l8);
    t0 = (l18 + l19);
    l19 = (size_t) (int64_t) t0;
    l20 = vader_host_std_core_byte_len(l9);
    t0 = (l19 + l20);
    l20 = (size_t) (int64_t) t0;
    l21 = vader_host_std_core_byte_len(l10);
    t0 = (l20 + l21);
    l21 = (size_t) (int64_t) t0;
    l22 = std_core_usize_BufferAlloc_new_buffer_vt(l21);
    std_core_Buffer_ByteAccess_write_string_vt(l22, (size_t) 0, l0);
    std_core_Buffer_ByteAccess_write_string_vt(l22, l11, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l22, l12, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l22, l13, l3);
    std_core_Buffer_ByteAccess_write_string_vt(l22, l14, l4);
    std_core_Buffer_ByteAccess_write_string_vt(l22, l15, l5);
    std_core_Buffer_ByteAccess_write_string_vt(l22, l16, l6);
    std_core_Buffer_ByteAccess_write_string_vt(l22, l17, l7);
    std_core_Buffer_ByteAccess_write_string_vt(l22, l18, l8);
    std_core_Buffer_ByteAccess_write_string_vt(l22, l19, l9);
    std_core_Buffer_ByteAccess_write_string_vt(l22, l20, l10);
    t1 = std_core_Buffer_ByteAccess_intern_string_vt(l22, l21);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_2(vader_string_t l0, vader_string_t l1) {
    size_t l2, l3;
    void* l4 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l4 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = vader_host_std_core_byte_len(l1);
    t0 = (l2 + l3);
    l3 = (size_t) (int64_t) t0;
    l4 = std_core_usize_BufferAlloc_new_buffer_vt(l3);
    std_core_Buffer_ByteAccess_write_string_vt(l4, (size_t) 0, l0);
    std_core_Buffer_ByteAccess_write_string_vt(l4, l2, l1);
    t1 = std_core_Buffer_ByteAccess_intern_string_vt(l4, l3);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_3(vader_string_t l0, vader_string_t l1, vader_string_t l2) {
    size_t l3, l4, l5;
    void* l6 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l6 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_core_byte_len(l0);
    l4 = vader_host_std_core_byte_len(l1);
    t0 = (l3 + l4);
    l4 = (size_t) (int64_t) t0;
    l5 = vader_host_std_core_byte_len(l2);
    t0 = (l4 + l5);
    l5 = (size_t) (int64_t) t0;
    l6 = std_core_usize_BufferAlloc_new_buffer_vt(l5);
    std_core_Buffer_ByteAccess_write_string_vt(l6, (size_t) 0, l0);
    std_core_Buffer_ByteAccess_write_string_vt(l6, l3, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l6, l4, l2);
    t1 = std_core_Buffer_ByteAccess_intern_string_vt(l6, l5);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_4(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3) {
    size_t l4, l5, l6, l7;
    void* l8 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l8 };
    vader_string_t* gc_atom_roots[5] = { &l0, &l1, &l2, &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_host_std_core_byte_len(l0);
    l5 = vader_host_std_core_byte_len(l1);
    t0 = (l4 + l5);
    l5 = (size_t) (int64_t) t0;
    l6 = vader_host_std_core_byte_len(l2);
    t0 = (l5 + l6);
    l6 = (size_t) (int64_t) t0;
    l7 = vader_host_std_core_byte_len(l3);
    t0 = (l6 + l7);
    l7 = (size_t) (int64_t) t0;
    l8 = std_core_usize_BufferAlloc_new_buffer_vt(l7);
    std_core_Buffer_ByteAccess_write_string_vt(l8, (size_t) 0, l0);
    std_core_Buffer_ByteAccess_write_string_vt(l8, l4, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l8, l5, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l8, l6, l3);
    t1 = std_core_Buffer_ByteAccess_intern_string_vt(l8, l7);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_5(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4) {
    size_t l5, l6, l7, l8, l9;
    void* l10 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l10 };
    vader_string_t* gc_atom_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_host_std_core_byte_len(l0);
    l6 = vader_host_std_core_byte_len(l1);
    t0 = (l5 + l6);
    l6 = (size_t) (int64_t) t0;
    l7 = vader_host_std_core_byte_len(l2);
    t0 = (l6 + l7);
    l7 = (size_t) (int64_t) t0;
    l8 = vader_host_std_core_byte_len(l3);
    t0 = (l7 + l8);
    l8 = (size_t) (int64_t) t0;
    l9 = vader_host_std_core_byte_len(l4);
    t0 = (l8 + l9);
    l9 = (size_t) (int64_t) t0;
    l10 = std_core_usize_BufferAlloc_new_buffer_vt(l9);
    std_core_Buffer_ByteAccess_write_string_vt(l10, (size_t) 0, l0);
    std_core_Buffer_ByteAccess_write_string_vt(l10, l5, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l10, l6, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l10, l7, l3);
    std_core_Buffer_ByteAccess_write_string_vt(l10, l8, l4);
    t1 = std_core_Buffer_ByteAccess_intern_string_vt(l10, l9);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_6(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5) {
    size_t l6, l7, l8, l9, l10, l11;
    void* l12 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l12 };
    vader_string_t* gc_atom_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 7u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = vader_host_std_core_byte_len(l0);
    l7 = vader_host_std_core_byte_len(l1);
    t0 = (l6 + l7);
    l7 = (size_t) (int64_t) t0;
    l8 = vader_host_std_core_byte_len(l2);
    t0 = (l7 + l8);
    l8 = (size_t) (int64_t) t0;
    l9 = vader_host_std_core_byte_len(l3);
    t0 = (l8 + l9);
    l9 = (size_t) (int64_t) t0;
    l10 = vader_host_std_core_byte_len(l4);
    t0 = (l9 + l10);
    l10 = (size_t) (int64_t) t0;
    l11 = vader_host_std_core_byte_len(l5);
    t0 = (l10 + l11);
    l11 = (size_t) (int64_t) t0;
    l12 = std_core_usize_BufferAlloc_new_buffer_vt(l11);
    std_core_Buffer_ByteAccess_write_string_vt(l12, (size_t) 0, l0);
    std_core_Buffer_ByteAccess_write_string_vt(l12, l6, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l12, l7, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l12, l8, l3);
    std_core_Buffer_ByteAccess_write_string_vt(l12, l9, l4);
    std_core_Buffer_ByteAccess_write_string_vt(l12, l10, l5);
    t1 = std_core_Buffer_ByteAccess_intern_string_vt(l12, l11);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_7(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6) {
    size_t l7, l8, l9, l10, l11, l12, l13;
    void* l14 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l14 };
    vader_string_t* gc_atom_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = vader_host_std_core_byte_len(l0);
    l8 = vader_host_std_core_byte_len(l1);
    t0 = (l7 + l8);
    l8 = (size_t) (int64_t) t0;
    l9 = vader_host_std_core_byte_len(l2);
    t0 = (l8 + l9);
    l9 = (size_t) (int64_t) t0;
    l10 = vader_host_std_core_byte_len(l3);
    t0 = (l9 + l10);
    l10 = (size_t) (int64_t) t0;
    l11 = vader_host_std_core_byte_len(l4);
    t0 = (l10 + l11);
    l11 = (size_t) (int64_t) t0;
    l12 = vader_host_std_core_byte_len(l5);
    t0 = (l11 + l12);
    l12 = (size_t) (int64_t) t0;
    l13 = vader_host_std_core_byte_len(l6);
    t0 = (l12 + l13);
    l13 = (size_t) (int64_t) t0;
    l14 = std_core_usize_BufferAlloc_new_buffer_vt(l13);
    std_core_Buffer_ByteAccess_write_string_vt(l14, (size_t) 0, l0);
    std_core_Buffer_ByteAccess_write_string_vt(l14, l7, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l14, l8, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l14, l9, l3);
    std_core_Buffer_ByteAccess_write_string_vt(l14, l10, l4);
    std_core_Buffer_ByteAccess_write_string_vt(l14, l11, l5);
    std_core_Buffer_ByteAccess_write_string_vt(l14, l12, l6);
    t1 = std_core_Buffer_ByteAccess_intern_string_vt(l14, l13);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_8(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7) {
    size_t l8, l9, l10, l11, l12, l13, l14, l15;
    void* l16 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l16 };
    vader_string_t* gc_atom_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 9u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l8 = vader_host_std_core_byte_len(l0);
    l9 = vader_host_std_core_byte_len(l1);
    t0 = (l8 + l9);
    l9 = (size_t) (int64_t) t0;
    l10 = vader_host_std_core_byte_len(l2);
    t0 = (l9 + l10);
    l10 = (size_t) (int64_t) t0;
    l11 = vader_host_std_core_byte_len(l3);
    t0 = (l10 + l11);
    l11 = (size_t) (int64_t) t0;
    l12 = vader_host_std_core_byte_len(l4);
    t0 = (l11 + l12);
    l12 = (size_t) (int64_t) t0;
    l13 = vader_host_std_core_byte_len(l5);
    t0 = (l12 + l13);
    l13 = (size_t) (int64_t) t0;
    l14 = vader_host_std_core_byte_len(l6);
    t0 = (l13 + l14);
    l14 = (size_t) (int64_t) t0;
    l15 = vader_host_std_core_byte_len(l7);
    t0 = (l14 + l15);
    l15 = (size_t) (int64_t) t0;
    l16 = std_core_usize_BufferAlloc_new_buffer_vt(l15);
    std_core_Buffer_ByteAccess_write_string_vt(l16, (size_t) 0, l0);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l8, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l9, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l10, l3);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l11, l4);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l12, l5);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l13, l6);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l14, l7);
    t1 = std_core_Buffer_ByteAccess_intern_string_vt(l16, l15);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t concat_9(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8) {
    size_t l9, l10, l11, l12, l13, l14, l15, l16, l17;
    void* l18 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l18 };
    vader_string_t* gc_atom_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 10u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l9 = vader_host_std_core_byte_len(l0);
    l10 = vader_host_std_core_byte_len(l1);
    t0 = (l9 + l10);
    l10 = (size_t) (int64_t) t0;
    l11 = vader_host_std_core_byte_len(l2);
    t0 = (l10 + l11);
    l11 = (size_t) (int64_t) t0;
    l12 = vader_host_std_core_byte_len(l3);
    t0 = (l11 + l12);
    l12 = (size_t) (int64_t) t0;
    l13 = vader_host_std_core_byte_len(l4);
    t0 = (l12 + l13);
    l13 = (size_t) (int64_t) t0;
    l14 = vader_host_std_core_byte_len(l5);
    t0 = (l13 + l14);
    l14 = (size_t) (int64_t) t0;
    l15 = vader_host_std_core_byte_len(l6);
    t0 = (l14 + l15);
    l15 = (size_t) (int64_t) t0;
    l16 = vader_host_std_core_byte_len(l7);
    t0 = (l15 + l16);
    l16 = (size_t) (int64_t) t0;
    l17 = vader_host_std_core_byte_len(l8);
    t0 = (l16 + l17);
    l17 = (size_t) (int64_t) t0;
    l18 = std_core_usize_BufferAlloc_new_buffer_vt(l17);
    std_core_Buffer_ByteAccess_write_string_vt(l18, (size_t) 0, l0);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l9, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l10, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l11, l3);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l12, l4);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l13, l5);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l14, l6);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l15, l7);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l16, l8);
    t1 = std_core_Buffer_ByteAccess_intern_string_vt(l18, l17);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}
