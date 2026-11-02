#include "bootstrap.split.h"

static vader_string_t vader_emit_virt$convert_target_name(uint8_t l0);
static vader_string_t vader_emit_virt$f64_const_operands(double l0);
static void vader_emit_virt$printed(void* l0, void* l1, vader_string_t l2, void* l3);
static void* vader_emit_virt$refer(uint8_t l0, int32_t l1);
static void* vader_emit_virt$refer_field(int32_t l0, int32_t l1);
static void vader_emit_virt$write_op_refs(void* l0, void* l1, vader_box_t l2);
static void vader_emit_virt$write_results(void* l0, void* l1);

static vader_string_t vader_emit_virt$convert_target_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2106u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2128u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1984u;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1775u;
    }
    return l1;
}

static vader_string_t vader_emit_virt$f64_const_operands(double l0) {
    vader_string_t l1 = 0;
    int64_t l2;
    void* l3 = NULL;
    uint64_t l4;
    bool t0;
    vader_string_t t1 = 0;
    int64_t t2;
    void** gc_raw_roots[1] = { &l3 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_math$is_finite(l0);
    if (!(t0)) {
        t1 = std_core$f64$Display$to_string(l0);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = std_core$f64$Display$to_string(l0);
    l2 = vader_host_std_core$byte_len(l1);
    l3 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l2));
    l2 = INT64_C(0);
    l2 = std_core$write_string_at(l3, l2, l1);
    l2 = std_core$write_string_at(l3, l2, 14u);
    t2 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = l0 }).__vu);
    l4 = (uint64_t) (int64_t) t2;
    l2 = std_core$write_unsigned(l3, l2, l4);
    t1 = std_core$finish_buffer(l3, l2);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_virt$printed(void* l0, void* l1, vader_string_t l2, void* l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l5, l6, l9, l10;
    vader_string_t l11 = 0;
    int32_t t0;
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l4, &l7, &l8 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_string__builder$append(l0, l2);
    l4 = l3;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l8 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l9 = INT64_C(0);
        l9 = std_core$write_string_at(l8, l9, 14u);
        t0 = ((vader_struct_vader_emit_virt$OperandRef_t*) l7)->f_index;
        l10 = ((int64_t) (int32_t) t0);
        l9 = std_core$write_int(l8, l9, l10);
        l11 = std_core$finish_buffer(l8, l9);
        std_string__builder$append(l0, l11);
        vader_array_push_ref((vader_array_t*) l1, l7);
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_emit_virt$refer(uint8_t l0, int32_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_virt$OperandRef_t* _a0_obj = (vader_struct_vader_emit_virt$OperandRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_virt$OperandRef_t));
    vader_obj_header_init(_a0_obj, 1144u);
    _a0_obj->f_kind = l0;
    _a0_obj->f_index = l1;
    _a0_obj->f_owner = INT32_C(-1);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_virt$refer_field(int32_t l0, int32_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_virt$OperandRef_t* _a0_obj = (vader_struct_vader_emit_virt$OperandRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_virt$OperandRef_t));
    vader_obj_header_init(_a0_obj, 1144u);
    _a0_obj->f_kind = (uint8_t) 2;
    _a0_obj->f_index = l1;
    _a0_obj->f_owner = l0;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_emit_virt$write_op(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(347u, 0u, 13u, 1661u);
    l2 = (void*) _a0_arr;
    vader_emit_virt$write_op_refs(l0, l2, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_virt$write_op_refs(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    int64_t l4, l5;
    vader_string_t l6 = 0;
    vader_string_t l14 = 0;
    bool l7;
    uint64_t l8;
    int32_t l9, l11;
    vader_box_t l13 = vader_box_null();
    void* t0 = NULL;
    int32_t t1;
    double t2;
    uint32_t t3;
    int64_t t4;
    vader_string_t t5 = 0;
    bool t6;
    vader_box_t* gc_roots[2] = { &l2, &l13 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l10, &l12, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l14, &t5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 937u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2112u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 957u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2134u);
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 916u) {
        t0 = l2.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        l6 = vader_emit_virt$f64_const_operands(t2);
        l6 = concat_2(1986u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 888u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(16));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1655u);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        l4 = std_core$write_bool(l3, l4, l7);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 903u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1777u);
        t0 = l2.payload.obj;
        t3 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        t4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        l8 = (uint64_t) (int64_t) t4;
        l4 = std_core$write_unsigned(l3, l4, l8);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 988u) {
        std_string__builder$append(l0, 2446u);
    } else if (l2.tag == 1004u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StringConst_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 3, l9);
        vader_array_t* _a0_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0;
        l3 = (void*) _a0_arr;
        vader_emit_virt$printed(l0, l1, 2679u, l3);
    } else if (l2.tag == 982u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a1_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
        l3 = (void*) _a1_arr;
        vader_emit_virt$printed(l0, l1, 2314u, l3);
    } else if (l2.tag == 983u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a2_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
        l3 = (void*) _a2_arr;
        vader_emit_virt$printed(l0, l1, 2315u, l3);
    } else if (l2.tag == 984u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a3_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t0;
        l3 = (void*) _a3_arr;
        vader_emit_virt$printed(l0, l1, 2316u, l3);
    } else if (l2.tag == 981u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_slot;
        l3 = vader_emit_virt$refer((uint8_t) 6, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$LocalField_t*) t0)->f_field_index;
        l12 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a4_arr = vader_array_new(210u, 3u, 13u, 1144u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l12;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l10;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l3;
        l3 = (void*) _a4_arr;
        vader_emit_virt$printed(l0, l1, 2313u, l3);
    } else if (l2.tag == 993u) {
        std_string__builder$append(l0, 2559u);
    } else if (l2.tag == 994u) {
        std_string__builder$append(l0, 2563u);
        vader_array_push_ref((vader_array_t*) l1, vader_box_obj(0u, NULL).payload.obj);
        t0 = l2.payload.obj;
        l13 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value;
        vader_emit_virt$write_op_refs(l0, l1, l13);
    } else if (l2.tag == 911u) {
        std_string__builder$append(l0, 1872u);
    } else if (l2.tag == 900u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a5_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t0;
        l3 = (void*) _a5_arr;
        vader_emit_virt$printed(l0, l1, 1732u, l3);
    } else if (l2.tag == 901u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 4, l9);
        vader_array_t* _a6_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = t0;
        l3 = (void*) _a6_arr;
        vader_emit_virt$printed(l0, l1, 1734u, l3);
    } else if (l2.tag == 902u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a7_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0;
        l3 = (void*) _a7_arr;
        vader_emit_virt$printed(l0, l1, 1735u, l3);
    } else if (l2.tag == 1027u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_parameter_count;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_vtable_key;
        l4 = vader_host_std_core$byte_len(l6);
        l3 = (void*) vader_buffer_new((size_t) (INT64_C(38) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 3038u);
        l5 = ((int64_t) (int32_t) l9);
        l4 = std_core$write_int(l3, l4, l5);
        l4 = std_core$write_string_at(l3, l4, 14u);
        l4 = std_core$write_string_at(l3, l4, l6);
        l4 = std_core$write_string_at(l3, l4, 63u);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
        t0 = l2.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_results;
        vader_emit_virt$write_results(l0, l3);
    } else if (l2.tag == 929u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a8_arr = vader_array_new(210u, 2u, 13u, 1144u);
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 1u] = l10;
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = l3;
        l3 = (void*) _a8_arr;
        vader_emit_virt$printed(l0, l1, 2042u, l3);
    } else if (l2.tag == 928u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a9_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t0;
        l3 = (void*) _a9_arr;
        vader_emit_virt$printed(l0, l1, 2040u, l3);
    } else if (l2.tag == 904u) {
        t0 = l2.payload.obj;
        l6 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        t0 = l2.payload.obj;
        l14 = vader_core_bytecode$checked_op_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_op);
        l6 = concat_3(l6, 413u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 905u) {
        t0 = l2.payload.obj;
        t5 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
        l6 = concat_2(t5, 414u);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 986u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a10_arr = vader_array_new(210u, 2u, 13u, 1144u);
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 1u] = l10;
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_emit_virt$printed(l0, l1, 2338u, l3);
    } else if (l2.tag == 972u) {
        std_string__builder$append(l0, 2156u);
    } else if (l2.tag == 912u) {
        std_string__builder$append(l0, 1884u);
    } else if (l2.tag == 913u) {
        std_string__builder$append(l0, 1902u);
    } else if (l2.tag == 886u) {
        std_string__builder$append(l0, 1652u);
    } else if (l2.tag == 985u) {
        std_string__builder$append(l0, 2319u);
    } else if (l2.tag == 893u) {
        std_string__builder$append(l0, 1663u);
    } else if (l2.tag == 894u) {
        std_string__builder$append(l0, 1665u);
    } else if (l2.tag == 891u) {
        std_string__builder$append(l0, 1658u);
    } else if (l2.tag == 1008u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_stack;
        if (t6) {
            l6 = 2701u;
        } else {
            l6 = 2698u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a11_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = t0;
        l3 = (void*) _a11_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 1007u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a12_arr = vader_array_new(210u, 2u, 13u, 1144u);
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 1u] = l10;
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l3;
        l3 = (void*) _a12_arr;
        vader_emit_virt$printed(l0, l1, 2697u, l3);
    } else if (l2.tag == 1009u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_stack;
        if (t6) {
            l6 = 2706u;
        } else {
            l6 = 2702u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a13_arr = vader_array_new(210u, 2u, 13u, 1144u);
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 1u] = l10;
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = l3;
        l3 = (void*) _a13_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 1024u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a14_arr = vader_array_new(210u, 2u, 13u, 1144u);
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 1u] = l10;
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = l3;
        l3 = (void*) _a14_arr;
        vader_emit_virt$printed(l0, l1, 2848u, l3);
    } else if (l2.tag == 1025u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a15_arr = vader_array_new(210u, 2u, 13u, 1144u);
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 1u] = l10;
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = l3;
        l3 = (void*) _a15_arr;
        vader_emit_virt$printed(l0, l1, 2849u, l3);
    } else if (l2.tag == 856u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a16_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = t0;
        l3 = (void*) _a16_arr;
        vader_emit_virt$printed(l0, l1, 1596u, l3);
        l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 14u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 855u) {
        std_string__builder$append(l0, 1595u);
    } else if (l2.tag == 857u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            l3 = vader_emit_virt$refer((uint8_t) 1, l9);
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
            l10 = vader_emit_virt$refer((uint8_t) 6, l9);
            vader_array_t* _a17_arr = vader_array_new(210u, 2u, 13u, 1144u);
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 1u] = l10;
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = l3;
            l3 = (void*) _a17_arr;
            vader_emit_virt$printed(l0, l1, 1598u, l3);
        } else {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            t0 = vader_emit_virt$refer((uint8_t) 1, l9);
            vader_array_t* _a18_arr = vader_array_new(210u, 1u, 13u, 1144u);
            ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 0u] = t0;
            l3 = (void*) _a18_arr;
            vader_emit_virt$printed(l0, l1, 1598u, l3);
        }
    } else if (l2.tag == 854u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a19_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = t0;
        l3 = (void*) _a19_arr;
        vader_emit_virt$printed(l0, l1, 1594u, l3);
    } else if (l2.tag == 862u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a20_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = t0;
        l3 = (void*) _a20_arr;
        vader_emit_virt$printed(l0, l1, 1609u, l3);
    } else if (l2.tag == 863u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a21_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = t0;
        l3 = (void*) _a21_arr;
        vader_emit_virt$printed(l0, l1, 1610u, l3);
    } else if (l2.tag == 861u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a22_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = t0;
        l3 = (void*) _a22_arr;
        vader_emit_virt$printed(l0, l1, 1607u, l3);
    } else if (l2.tag == 860u) {
        std_string__builder$append(l0, 1604u);
    } else if (l2.tag == 858u) {
        std_string__builder$append(l0, 1599u);
    } else if (l2.tag == 853u) {
        std_string__builder$append(l0, 1586u);
    } else if (l2.tag == 859u) {
        std_string__builder$append(l0, 1602u);
    } else if (l2.tag == 852u) {
        std_string__builder$append(l0, 1584u);
    } else if (l2.tag == 907u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        l3 = vader_emit_virt$refer((uint8_t) 5, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a23_arr = vader_array_new(210u, 2u, 13u, 1144u);
        ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 1u] = l10;
        ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 0u] = l3;
        l3 = (void*) _a23_arr;
        vader_emit_virt$printed(l0, l1, 1841u, l3);
    } else if (l2.tag == 930u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a24_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = t0;
        l3 = (void*) _a24_arr;
        vader_emit_virt$printed(l0, l1, 2089u, l3);
    } else if (l2.tag == 931u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a25_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 0u] = t0;
        l3 = (void*) _a25_arr;
        vader_emit_virt$printed(l0, l1, 2090u, l3);
    } else if (l2.tag == 1011u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a26_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a26_arr->buf->slots)[_a26_arr->offset + 0u] = t0;
        l3 = (void*) _a26_arr;
        vader_emit_virt$printed(l0, l1, 2791u, l3);
    } else if (l2.tag == 1010u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a27_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a27_arr->buf->slots)[_a27_arr->offset + 0u] = t0;
        l3 = (void*) _a27_arr;
        vader_emit_virt$printed(l0, l1, 2794u, l3);
    } else if (l2.tag == 989u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a28_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a28_arr->buf->slots)[_a28_arr->offset + 0u] = t0;
        l3 = (void*) _a28_arr;
        vader_emit_virt$printed(l0, l1, 2538u, l3);
    } else if (l2.tag == 992u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a29_arr = vader_array_new(210u, 1u, 13u, 1144u);
        ((void**) _a29_arr->buf->slots)[_a29_arr->offset + 0u] = t0;
        l3 = (void*) _a29_arr;
        vader_emit_virt$printed(l0, l1, 2558u, l3);
    } else if (l2.tag == 1026u) {
        std_string__builder$append(l0, 2862u);
    } else if (l2.tag == 906u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        t0 = l2.payload.obj;
        l14 = vader_emit_virt$convert_target_name(((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target);
        l6 = concat_3(l6, 442u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 995u) {
        std_string__builder$append(l0, 2219u);
    } else if (l2.tag == 932u) {
        std_string__builder$append(l0, 2107u);
    } else if (l2.tag == 951u) {
        std_string__builder$append(l0, 2127u);
    } else if (l2.tag == 945u) {
        std_string__builder$append(l0, 2121u);
    } else if (l2.tag == 938u) {
        std_string__builder$append(l0, 2113u);
    } else if (l2.tag == 944u) {
        std_string__builder$append(l0, 2124u);
    } else if (l2.tag == 947u) {
        std_string__builder$append(l0, 2123u);
    } else if (l2.tag == 934u) {
        std_string__builder$append(l0, 2109u);
    } else if (l2.tag == 933u) {
        std_string__builder$append(l0, 2108u);
    } else if (l2.tag == 935u) {
        std_string__builder$append(l0, 2110u);
    } else if (l2.tag == 936u) {
        std_string__builder$append(l0, 2111u);
    } else if (l2.tag == 948u) {
        std_string__builder$append(l0, 2125u);
    } else if (l2.tag == 949u) {
        std_string__builder$append(l0, 2126u);
    } else if (l2.tag == 950u) {
        std_string__builder$append(l0, 2822u);
    } else if (l2.tag == 939u) {
        std_string__builder$append(l0, 2115u);
    } else if (l2.tag == 946u) {
        std_string__builder$append(l0, 2122u);
    } else if (l2.tag == 943u) {
        std_string__builder$append(l0, 2119u);
    } else if (l2.tag == 942u) {
        std_string__builder$append(l0, 2118u);
    } else if (l2.tag == 941u) {
        std_string__builder$append(l0, 2117u);
    } else if (l2.tag == 940u) {
        std_string__builder$append(l0, 2116u);
    } else if (l2.tag == 952u) {
        std_string__builder$append(l0, 2129u);
    } else if (l2.tag == 971u) {
        std_string__builder$append(l0, 2149u);
    } else if (l2.tag == 965u) {
        std_string__builder$append(l0, 2142u);
    } else if (l2.tag == 958u) {
        std_string__builder$append(l0, 2135u);
    } else if (l2.tag == 964u) {
        std_string__builder$append(l0, 2145u);
    } else if (l2.tag == 967u) {
        std_string__builder$append(l0, 2144u);
    } else if (l2.tag == 953u) {
        std_string__builder$append(l0, 2130u);
    } else if (l2.tag == 955u) {
        std_string__builder$append(l0, 2132u);
    } else if (l2.tag == 956u) {
        std_string__builder$append(l0, 2133u);
    } else if (l2.tag == 954u) {
        std_string__builder$append(l0, 2131u);
    } else if (l2.tag == 968u) {
        std_string__builder$append(l0, 2147u);
    } else if (l2.tag == 969u) {
        std_string__builder$append(l0, 2148u);
    } else if (l2.tag == 970u) {
        std_string__builder$append(l0, 2832u);
    } else if (l2.tag == 959u) {
        std_string__builder$append(l0, 2137u);
    } else if (l2.tag == 966u) {
        std_string__builder$append(l0, 2143u);
    } else if (l2.tag == 963u) {
        std_string__builder$append(l0, 2141u);
    } else if (l2.tag == 962u) {
        std_string__builder$append(l0, 2140u);
    } else if (l2.tag == 961u) {
        std_string__builder$append(l0, 2139u);
    } else if (l2.tag == 960u) {
        std_string__builder$append(l0, 2138u);
    } else if (l2.tag == 1012u) {
        std_string__builder$append(l0, 2814u);
    } else if (l2.tag == 1017u) {
        std_string__builder$append(l0, 2820u);
    } else if (l2.tag == 1016u) {
        std_string__builder$append(l0, 2819u);
    } else if (l2.tag == 1015u) {
        std_string__builder$append(l0, 2818u);
    } else if (l2.tag == 1014u) {
        std_string__builder$append(l0, 2817u);
    } else if (l2.tag == 1013u) {
        std_string__builder$append(l0, 2816u);
    } else if (l2.tag == 1018u) {
        std_string__builder$append(l0, 2824u);
    } else if (l2.tag == 1023u) {
        std_string__builder$append(l0, 2830u);
    } else if (l2.tag == 1022u) {
        std_string__builder$append(l0, 2829u);
    } else if (l2.tag == 1021u) {
        std_string__builder$append(l0, 2828u);
    } else if (l2.tag == 1020u) {
        std_string__builder$append(l0, 2827u);
    } else if (l2.tag == 1019u) {
        std_string__builder$append(l0, 2826u);
    } else if (l2.tag == 915u) {
        std_string__builder$append(l0, 1985u);
    } else if (l2.tag == 926u) {
        std_string__builder$append(l0, 1996u);
    } else if (l2.tag == 923u) {
        std_string__builder$append(l0, 1993u);
    } else if (l2.tag == 917u) {
        std_string__builder$append(l0, 1987u);
    } else if (l2.tag == 925u) {
        std_string__builder$append(l0, 1995u);
    } else if (l2.tag == 918u) {
        std_string__builder$append(l0, 1988u);
    } else if (l2.tag == 924u) {
        std_string__builder$append(l0, 1994u);
    } else if (l2.tag == 922u) {
        std_string__builder$append(l0, 1992u);
    } else if (l2.tag == 921u) {
        std_string__builder$append(l0, 1991u);
    } else if (l2.tag == 920u) {
        std_string__builder$append(l0, 1990u);
    } else if (l2.tag == 919u) {
        std_string__builder$append(l0, 1989u);
    } else if (l2.tag == 889u) {
        std_string__builder$append(l0, 1656u);
    } else if (l2.tag == 890u) {
        std_string__builder$append(l0, 1657u);
    } else if (l2.tag == 887u) {
        std_string__builder$append(l0, 1654u);
    } else if (l2.tag == 892u) {
        std_string__builder$append(l0, 1659u);
    } else if (l2.tag == 1005u) {
        std_string__builder$append(l0, 2680u);
    } else if (l2.tag == 1006u) {
        std_string__builder$append(l0, 2682u);
    } else if (l2.tag == 1003u) {
        std_string__builder$append(l0, 2678u);
    } else if (l2.tag == 990u) {
        std_string__builder$append(l0, 2539u);
    } else if (l2.tag == 991u) {
        std_string__builder$append(l0, 2540u);
    } else if (l2.tag == 910u) {
        std_string__builder$append(l0, 1857u);
    } else if (l2.tag == 909u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(35));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1855u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$DeferPopExec_t*) t0)->f_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 895u) {
        std_string__builder$append(l0, 1675u);
    } else if (l2.tag == 980u) {
        std_string__builder$append(l0, 2308u);
    } else if (l2.tag == 975u) {
        std_string__builder$append(l0, 2302u);
    } else if (l2.tag == 976u) {
        std_string__builder$append(l0, 2303u);
    } else if (l2.tag == 974u) {
        std_string__builder$append(l0, 2301u);
    } else if (l2.tag == 1002u) {
        std_string__builder$append(l0, 2673u);
    } else if (l2.tag == 997u) {
        std_string__builder$append(l0, 2666u);
    } else if (l2.tag == 998u) {
        std_string__builder$append(l0, 2667u);
    } else if (l2.tag == 996u) {
        std_string__builder$append(l0, 2664u);
    } else if (l2.tag == 978u) {
        std_string__builder$append(l0, 2306u);
    } else if (l2.tag == 979u) {
        std_string__builder$append(l0, 2307u);
    } else if (l2.tag == 977u) {
        std_string__builder$append(l0, 2305u);
    } else if (l2.tag == 1000u) {
        std_string__builder$append(l0, 2671u);
    } else if (l2.tag == 1001u) {
        std_string__builder$append(l0, 2672u);
    } else if (l2.tag == 999u) {
        std_string__builder$append(l0, 2670u);
    } else if (l2.tag == 987u) {
        std_string__builder$append(l0, 2359u);
    } else if (l2.tag == 896u) {
        std_string__builder$append(l0, 1678u);
    } else if (l2.tag == 897u) {
        std_string__builder$append(l0, 1681u);
    } else if (l2.tag == 927u) {
        std_string__builder$append(l0, 1997u);
    } else if (l2.tag == 885u) {
        std_string__builder$append(l0, 1650u);
    } else if (l2.tag == 914u) {
        std_string__builder$append(l0, 1983u);
    } else {
        if (!(l2.tag == 884u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string__builder$append(l0, 1649u);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_virt$write_results(void* l0, void* l1) {
    vader_string_t l2 = 0;
    int64_t l3, l4;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 457u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string__builder$append_char(l0, 40u);
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l1)->length;
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            std_string__builder$append(l0, 363u);
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 457u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append_char(l0, 41u);
    { vader_gc_top = gc_frame.prev; return; }
}
