#include "bootstrap.split.h"

bool __lambda_1360(void* l0, int32_t l1, int32_t l2) {
    void* l3 = NULL;
    size_t l4;
    vader_string_t l5, l6;
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    void** gc_raw_roots[3] = { &l0, &l3, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct__Cell_Array_Struct_vader_bytecode_BcFunction____t*) ((vader_struct___lambda_env_1361_t*) l0)->f_cap_0.payload.obj)->f_value;
    t0 = ((int64_t) (int32_t) l1);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l5 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_name;
    l3 = ((vader_struct__Cell_Array_Struct_vader_bytecode_BcFunction____t*) ((vader_struct___lambda_env_1361_t*) l0)->f_cap_0.payload.obj)->f_value;
    t0 = ((int64_t) (int32_t) l2);
    l4 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
    l6 = ((vader_struct_vader_bytecode_BcFunction_t*) t1)->f_name;
    t2 = std_string_compare_ascending(l5, l6);
    { bool __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool __lambda_1370(void* l0, vader_string_t l1, vader_string_t l2) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_string_compare_ascending(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void __lambda_1646(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct__Cell_Array_Struct_vader_types_StructType____t*) ((vader_struct___lambda_env_1647_t*) l0)->f_cap_0.payload.obj)->f_value;
    l3 = ((vader_struct__Cell_Struct_std_collections_MutableSet_string__t*) ((vader_struct___lambda_env_1647_t*) l0)->f_cap_1.payload.obj)->f_value;
    vader_lower_push_struct_shape(l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

bool __lambda_174(void* l0, uint32_t l1) {
    return l1 == 92u;
}

void __lambda_1771(void* l0, int32_t l1) {
    size_t l2, l3;
    void* l4;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_struct__Cell_usize_t*) ((vader_struct___lambda_env_1772_t*) l0)->f_cap_0.payload.obj)->f_value;
    if ((l2 < l3)) {
        l4 = ((vader_struct__Cell_Array_bool__t*) ((vader_struct___lambda_env_1772_t*) l0)->f_cap_1.payload.obj)->f_value;
        t0 = ((int64_t) (int32_t) l1);
        l2 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2] = (uint8_t) true;
    } else {
    }
    return;
}

void __lambda_1774(void* l0, int32_t l1) {
    size_t l2, l3;
    void* l4;
    int64_t t0;
    t0 = ((int64_t) (int32_t) l1);
    l2 = (size_t) (int64_t) t0;
    l3 = ((vader_struct__Cell_usize_t*) ((vader_struct___lambda_env_1775_t*) l0)->f_cap_0.payload.obj)->f_value;
    if ((l2 < l3)) {
        l4 = ((vader_struct__Cell_Array_bool__t*) ((vader_struct___lambda_env_1775_t*) l0)->f_cap_1.payload.obj)->f_value;
        t0 = ((int64_t) (int32_t) l1);
        l2 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2] = (uint8_t) true;
    } else {
    }
    return;
}

void* __lambda_1867(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 166u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* __lambda_1885(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 166u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool __lambda_1995(void* l0, void* l1, void* l2) {
    vader_string_t l3, l4;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_name;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l2)->f_name;
    t0 = std_string_compare_ascending(l3, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t __lambda_2045(void* l0, void* l1, void* l2) {
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_types_mk_struct(l1, l2, false);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void __lambda_209(void* l0, int32_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = std_collections_get__string__Any(((vader_struct__Cell_Struct_std_collections_MutableMap_string_Union_Struct_vader_lower_LoweredConstDecl___Struct_vader_lower_LoweredFnDecl___Struct_vader_lower_LoweredStructDecl_____t*) ((vader_struct___lambda_env_210_t*) l0)->f_cap_0.payload.obj)->f_value, l2);
    if (!(l3.tag == 0u)) {
        t0 = std_collections_get__string__bool(((vader_struct__Cell_Struct_std_collections_MutableMap_string_bool__t*) ((vader_struct___lambda_env_210_t*) l0)->f_cap_1.payload.obj)->f_value, l2);
        if (t0.tag == 0u) {
            std_collections_put__string__bool(((vader_struct__Cell_Struct_std_collections_MutableMap_string_bool__t*) ((vader_struct___lambda_env_210_t*) l0)->f_cap_1.payload.obj)->f_value, l2, true);
            l4 = ((vader_struct__Cell_Array_Union_Struct_vader_lower_LoweredConstDecl___Struct_vader_lower_LoweredFnDecl___Struct_vader_lower_LoweredStructDecl_____t*) ((vader_struct___lambda_env_210_t*) l0)->f_cap_2.payload.obj)->f_value;
            vader_array_push((vader_array_t*) l4, l3);
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = std_collections_get__i32__Any(((vader_struct__Cell_Struct_std_collections_MutableMap_i32_Union_Struct_vader_lower_LoweredConstDecl___Struct_vader_lower_LoweredFnDecl___Struct_vader_lower_LoweredStructDecl_____t*) ((vader_struct___lambda_env_210_t*) l0)->f_cap_3.payload.obj)->f_value, l1);
    if (!(l3.tag == 0u)) {
        t0 = std_collections_get__i32__bool(((vader_struct__Cell_Struct_std_collections_MutableMap_i32_bool__t*) ((vader_struct___lambda_env_210_t*) l0)->f_cap_4.payload.obj)->f_value, l1);
        if (t0.tag == 0u) {
            std_collections_put__i32__bool(((vader_struct__Cell_Struct_std_collections_MutableMap_i32_bool__t*) ((vader_struct___lambda_env_210_t*) l0)->f_cap_4.payload.obj)->f_value, l1, true);
            l4 = ((vader_struct__Cell_Array_Union_Struct_vader_lower_LoweredConstDecl___Struct_vader_lower_LoweredFnDecl___Struct_vader_lower_LoweredStructDecl_____t*) ((vader_struct___lambda_env_210_t*) l0)->f_cap_2.payload.obj)->f_value;
            vader_array_push((vader_array_t*) l4, l3);
        } else {
        }
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void __lambda_212(void* l0, vader_string_t l1, vader_string_t l2) {
    vader_string_t l3;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = concat_3(l1, 2441u, l2);
    t0 = std_collections_get__string__bool(((vader_struct__Cell_Struct_std_collections_MutableMap_string_bool__t*) ((vader_struct___lambda_env_213_t*) l0)->f_cap_0.payload.obj)->f_value, l3);
    if (t0.tag == 0u) {
        std_collections_put__string__bool(((vader_struct__Cell_Struct_std_collections_MutableMap_string_bool__t*) ((vader_struct___lambda_env_213_t*) l0)->f_cap_0.payload.obj)->f_value, l3, true);
        vader_array_push((vader_array_t*) ((vader_struct__Cell_Array_string__t*) ((vader_struct___lambda_env_213_t*) l0)->f_cap_1.payload.obj)->f_value, vader_box_string(163u, l3));
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

bool __lambda_2246(void* l0, void* l1, void* l2) {
    vader_string_t l3, l4;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_comptime_GenericInstance_t*) l1)->f_display_key;
    l4 = ((vader_struct_vader_comptime_GenericInstance_t*) l2)->f_display_key;
    t0 = std_string_compare_ascending(l3, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool __lambda_2731(void* l0, size_t l1, size_t l2) {
    int32_t l3, l4;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct__Cell_Array_i32__t*) ((vader_struct___lambda_env_2732_t*) l0)->f_cap_0.payload.obj)->f_value);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) l1 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
    if ((size_t) l2 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    l4 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
    return (l3 < l4);
}

void __lambda_2877(void* l0, int32_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int32_t l4;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = std_collections_get__i32__i32(((vader_struct__Cell_Struct_std_collections_MutableMap_i32_i32__t*) ((vader_struct___lambda_env_2878_t*) l0)->f_cap_0.payload.obj)->f_value, l1);
    if (l2.tag == 0u) {
        std_collections_put__i32__i32(((vader_struct__Cell_Struct_std_collections_MutableMap_i32_i32__t*) ((vader_struct___lambda_env_2878_t*) l0)->f_cap_0.payload.obj)->f_value, l1, INT32_C(1));
    } else {
        l3 = ((vader_struct__Cell_Struct_std_collections_MutableMap_i32_i32__t*) ((vader_struct___lambda_env_2878_t*) l0)->f_cap_0.payload.obj)->f_value;
        t0 = ((int32_t) l2.payload.i);
        l4 = (t0 + INT32_C(1));
        std_collections_put__i32__i32(l3, l1, l4);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void __lambda_2886(void* l0, int32_t l1) {
    int32_t l2, l3;
    l2 = l1;
    l3 = ((vader_struct__Cell_i32_t*) ((vader_struct___lambda_env_2887_t*) l0)->f_cap_0.payload.obj)->f_value;
    if (l2 == l3) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct__Cell_Array_bool__t*) ((vader_struct___lambda_env_2887_t*) l0)->f_cap_1.payload.obj)->f_value);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)] = (uint8_t) true;
    } else {
    }
    return;
}

void __lambda_2893(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) ((vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) ((vader_struct___lambda_env_2894_t*) l0)->f_cap_0.payload.obj)->f_value)->f_inner, l1);
    if (!(t0)) {
        std_collections_add__i32(((vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) ((vader_struct___lambda_env_2894_t*) l0)->f_cap_1.payload.obj)->f_value, l1);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void __lambda_2896(void* l0, int32_t l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_contains_key__i32__bool(((vader_struct_std_collections_MutableSet__i32_t*) ((vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) ((vader_struct___lambda_env_2897_t*) l0)->f_cap_0.payload.obj)->f_value)->f_inner, l1);
    if (!(t0)) {
        std_collections_add__i32(((vader_struct__Cell_Struct_std_collections_MutableSet_i32__t*) ((vader_struct___lambda_env_2897_t*) l0)->f_cap_1.payload.obj)->f_value, l1);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void* __lambda_2902(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 166u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 161u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 166u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 376u);
    _a4_obj->f_inner = t0;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* __lambda_2905(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 166u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(6u, 0u, 12u, 161u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 166u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 309u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a4_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 376u);
    _a4_obj->f_inner = t0;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void __lambda_2926(void* l0, int32_t l1) {
    size_t l2, l3;
    int64_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct__Cell_Array_bool__t*) ((vader_struct___lambda_env_2927_t*) l0)->f_cap_0.payload.obj)->f_value)->length;
    {
        loop_5: {
            t0 = ((int64_t) (int32_t) l1);
            l3 = (size_t) (int64_t) t0;
            if ((l2 <= l3)) {
                vader_array_push_bool((vader_array_t*) ((vader_struct__Cell_Array_bool__t*) ((vader_struct___lambda_env_2927_t*) l0)->f_cap_0.payload.obj)->f_value, false);
                t0 = (l2 + INT64_C(1));
                l2 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void __lambda_2934(void* l0, int32_t l1) {
    void* l2 = NULL;
    size_t l3;
    int64_t t0;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct__Cell_Fn_i32___void_t*) ((vader_struct___lambda_env_2935_t*) l0)->f_cap_0.payload.obj)->f_value;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(166u, l1));
    l2 = ((vader_struct__Cell_Array_bool__t*) ((vader_struct___lambda_env_2935_t*) l0)->f_cap_1.payload.obj)->f_value;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) true;
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void __lambda_2937(void* l0, int32_t l1) {
    void* l2 = NULL;
    size_t l3;
    int64_t t0;
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct__Cell_Fn_i32___void_t*) ((vader_struct___lambda_env_2938_t*) l0)->f_cap_0.payload.obj)->f_value;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(166u, l1));
    l2 = ((vader_struct__Cell_Array_bool__t*) ((vader_struct___lambda_env_2938_t*) l0)->f_cap_1.payload.obj)->f_value;
    t0 = ((int64_t) (int32_t) l1);
    l3 = (size_t) (int64_t) t0;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) l3 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l3] = (uint8_t) true;
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

bool __lambda_2996(void* l0, vader_string_t l1, vader_string_t l2) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_string_compare_ascending(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

double __lambda_3367(void* l0, double l1, double l2) {
    double t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_math_pow(l1, l2);
    { double __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

double __lambda_3370(void* l0, double l1) {
    double t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_math_round(l1);
    { double __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

double __lambda_3373(void* l0, double l1) {
    double t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_math_ceil(l1);
    { double __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

double __lambda_3376(void* l0, double l1) {
    double t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_math_floor(l1);
    { double __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

double __lambda_3379(void* l0, double l1) {
    double t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_math_tan(l1);
    { double __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

double __lambda_3382(void* l0, double l1) {
    double t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_math_cos(l1);
    { double __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

double __lambda_3385(void* l0, double l1) {
    double t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_math_sin(l1);
    { double __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

double __lambda_3388(void* l0, double l1) {
    double t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_host_std_math_sqrt(l1);
    { double __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool __lambda_3396(void* l0, int64_t l1, int64_t l2) {
    return l1 != l2;
}

bool __lambda_3399(void* l0, int64_t l1, int64_t l2) {
    return l1 == l2;
}

bool __lambda_3402(void* l0, vader_string_t l1, vader_string_t l2) {
    return l1 != l2;
}

bool __lambda_3405(void* l0, vader_string_t l1, vader_string_t l2) {
    return l1 == l2;
}

bool __lambda_3897(void* l0, vader_box_t l1, vader_box_t l2) {
    vader_string_t l3, l4;
    bool t0;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_types_display_type_key(l1);
    l4 = vader_types_display_type_key(l2);
    t0 = std_string_compare_ascending_ci(l3, l4);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool __lambda_4381(void* l0, vader_string_t l1, vader_string_t l2) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_string_compare_ascending(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool __lambda_5417(void* l0, vader_string_t l1, vader_string_t l2) {
    bool t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_string_compare_ascending(l1, l2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

bool __lambda_5991(void* l0, uint32_t l1) {
    return l1 == 95u;
}

vader_string_t concat_10(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8, vader_string_t l9) {
    size_t l10, l11, l12, l13, l14, l15, l16, l17, l18, l19;
    void* l20 = NULL;
    int64_t t0;
    vader_string_t t1;
    void** gc_raw_roots[1] = { &l20 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l10 = vader_host_std_core_byte_len(l0);
    l11 = vader_host_std_core_byte_len(l1);
    t0 = (l10 + l11);
    l11 = (size_t) (int64_t) t0;
    l12 = vader_host_std_core_byte_len(l2);
    t0 = (l11 + l12);
    l12 = (size_t) (int64_t) t0;
    l13 = vader_host_std_core_byte_len(l3);
    t0 = (l12 + l13);
    l13 = (size_t) (int64_t) t0;
    l14 = vader_host_std_core_byte_len(l4);
    t0 = (l13 + l14);
    l14 = (size_t) (int64_t) t0;
    l15 = vader_host_std_core_byte_len(l5);
    t0 = (l14 + l15);
    l15 = (size_t) (int64_t) t0;
    l16 = vader_host_std_core_byte_len(l6);
    t0 = (l15 + l16);
    l16 = (size_t) (int64_t) t0;
    l17 = vader_host_std_core_byte_len(l7);
    t0 = (l16 + l17);
    l17 = (size_t) (int64_t) t0;
    l18 = vader_host_std_core_byte_len(l8);
    t0 = (l17 + l18);
    l18 = (size_t) (int64_t) t0;
    l19 = vader_host_std_core_byte_len(l9);
    t0 = (l18 + l19);
    l19 = (size_t) (int64_t) t0;
    l20 = std_core_new_byte_buffer(l19);
    std_core_Buffer_ByteAccess_write_string_vt(l20, (size_t) (int64_t) INT64_C(0), l0);
    std_core_Buffer_ByteAccess_write_string_vt(l20, l10, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l20, l11, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l20, l12, l3);
    std_core_Buffer_ByteAccess_write_string_vt(l20, l13, l4);
    std_core_Buffer_ByteAccess_write_string_vt(l20, l14, l5);
    std_core_Buffer_ByteAccess_write_string_vt(l20, l15, l6);
    std_core_Buffer_ByteAccess_write_string_vt(l20, l16, l7);
    std_core_Buffer_ByteAccess_write_string_vt(l20, l17, l8);
    std_core_Buffer_ByteAccess_write_string_vt(l20, l18, l9);
    t1 = std_core_finish_buffer(l20, l19);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t concat_11(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8, vader_string_t l9, vader_string_t l10) {
    size_t l11, l12, l13, l14, l15, l16, l17, l18, l19, l20, l21;
    void* l22 = NULL;
    int64_t t0;
    vader_string_t t1;
    void** gc_raw_roots[1] = { &l22 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
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
    l22 = std_core_new_byte_buffer(l21);
    std_core_Buffer_ByteAccess_write_string_vt(l22, (size_t) (int64_t) INT64_C(0), l0);
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
    t1 = std_core_finish_buffer(l22, l21);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t concat_2(vader_string_t l0, vader_string_t l1) {
    size_t l2, l3;
    void* l4 = NULL;
    int64_t t0;
    vader_string_t t1;
    void** gc_raw_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = vader_host_std_core_byte_len(l1);
    t0 = (l2 + l3);
    l3 = (size_t) (int64_t) t0;
    l4 = std_core_new_byte_buffer(l3);
    std_core_Buffer_ByteAccess_write_string_vt(l4, (size_t) (int64_t) INT64_C(0), l0);
    std_core_Buffer_ByteAccess_write_string_vt(l4, l2, l1);
    t1 = std_core_finish_buffer(l4, l3);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t concat_3(vader_string_t l0, vader_string_t l1, vader_string_t l2) {
    size_t l3, l4, l5;
    void* l6 = NULL;
    int64_t t0;
    vader_string_t t1;
    void** gc_raw_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_host_std_core_byte_len(l0);
    l4 = vader_host_std_core_byte_len(l1);
    t0 = (l3 + l4);
    l4 = (size_t) (int64_t) t0;
    l5 = vader_host_std_core_byte_len(l2);
    t0 = (l4 + l5);
    l5 = (size_t) (int64_t) t0;
    l6 = std_core_new_byte_buffer(l5);
    std_core_Buffer_ByteAccess_write_string_vt(l6, (size_t) (int64_t) INT64_C(0), l0);
    std_core_Buffer_ByteAccess_write_string_vt(l6, l3, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l6, l4, l2);
    t1 = std_core_finish_buffer(l6, l5);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t concat_4(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3) {
    size_t l4, l5, l6, l7;
    void* l8 = NULL;
    int64_t t0;
    vader_string_t t1;
    void** gc_raw_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
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
    l8 = std_core_new_byte_buffer(l7);
    std_core_Buffer_ByteAccess_write_string_vt(l8, (size_t) (int64_t) INT64_C(0), l0);
    std_core_Buffer_ByteAccess_write_string_vt(l8, l4, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l8, l5, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l8, l6, l3);
    t1 = std_core_finish_buffer(l8, l7);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t concat_5(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4) {
    size_t l5, l6, l7, l8, l9;
    void* l10 = NULL;
    int64_t t0;
    vader_string_t t1;
    void** gc_raw_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
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
    l10 = std_core_new_byte_buffer(l9);
    std_core_Buffer_ByteAccess_write_string_vt(l10, (size_t) (int64_t) INT64_C(0), l0);
    std_core_Buffer_ByteAccess_write_string_vt(l10, l5, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l10, l6, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l10, l7, l3);
    std_core_Buffer_ByteAccess_write_string_vt(l10, l8, l4);
    t1 = std_core_finish_buffer(l10, l9);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t concat_6(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5) {
    size_t l6, l7, l8, l9, l10, l11;
    void* l12 = NULL;
    int64_t t0;
    vader_string_t t1;
    void** gc_raw_roots[1] = { &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
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
    l12 = std_core_new_byte_buffer(l11);
    std_core_Buffer_ByteAccess_write_string_vt(l12, (size_t) (int64_t) INT64_C(0), l0);
    std_core_Buffer_ByteAccess_write_string_vt(l12, l6, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l12, l7, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l12, l8, l3);
    std_core_Buffer_ByteAccess_write_string_vt(l12, l9, l4);
    std_core_Buffer_ByteAccess_write_string_vt(l12, l10, l5);
    t1 = std_core_finish_buffer(l12, l11);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t concat_7(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6) {
    size_t l7, l8, l9, l10, l11, l12, l13;
    void* l14 = NULL;
    int64_t t0;
    vader_string_t t1;
    void** gc_raw_roots[1] = { &l14 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
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
    l14 = std_core_new_byte_buffer(l13);
    std_core_Buffer_ByteAccess_write_string_vt(l14, (size_t) (int64_t) INT64_C(0), l0);
    std_core_Buffer_ByteAccess_write_string_vt(l14, l7, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l14, l8, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l14, l9, l3);
    std_core_Buffer_ByteAccess_write_string_vt(l14, l10, l4);
    std_core_Buffer_ByteAccess_write_string_vt(l14, l11, l5);
    std_core_Buffer_ByteAccess_write_string_vt(l14, l12, l6);
    t1 = std_core_finish_buffer(l14, l13);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t concat_8(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7) {
    size_t l8, l9, l10, l11, l12, l13, l14, l15;
    void* l16 = NULL;
    int64_t t0;
    vader_string_t t1;
    void** gc_raw_roots[1] = { &l16 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
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
    l16 = std_core_new_byte_buffer(l15);
    std_core_Buffer_ByteAccess_write_string_vt(l16, (size_t) (int64_t) INT64_C(0), l0);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l8, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l9, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l10, l3);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l11, l4);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l12, l5);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l13, l6);
    std_core_Buffer_ByteAccess_write_string_vt(l16, l14, l7);
    t1 = std_core_finish_buffer(l16, l15);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t concat_9(vader_string_t l0, vader_string_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, vader_string_t l5, vader_string_t l6, vader_string_t l7, vader_string_t l8) {
    size_t l9, l10, l11, l12, l13, l14, l15, l16, l17;
    void* l18 = NULL;
    int64_t t0;
    vader_string_t t1;
    void** gc_raw_roots[1] = { &l18 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
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
    l18 = std_core_new_byte_buffer(l17);
    std_core_Buffer_ByteAccess_write_string_vt(l18, (size_t) (int64_t) INT64_C(0), l0);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l9, l1);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l10, l2);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l11, l3);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l12, l4);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l13, l5);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l14, l6);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l15, l7);
    std_core_Buffer_ByteAccess_write_string_vt(l18, l16, l8);
    t1 = std_core_finish_buffer(l18, l17);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

