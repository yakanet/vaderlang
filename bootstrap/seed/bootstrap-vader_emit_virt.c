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
        l1 = 2079u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2101u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1958u;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1750u;
    }
    return l1;
}

static vader_string_t vader_emit_virt$f64_const_operands(double l0) {
    uint64_t l1;
    vader_string_t l2 = 0;
    int64_t l3;
    void* l4 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l4 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = l0 }).__vu);
    l1 = (uint64_t) (int64_t) t0;
    if (!(((l1 >> INT64_C(52)) & INT64_C(2047)) == INT64_C(2047))) {
        l2 = std_core$f64$Display$to_string(l0);
        l3 = vader_host_std_core$byte_len(l2);
        l4 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l3));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l4, l3, l2);
        l3 = std_core$write_string_at(l4, l3, 14u);
        l3 = std_core$write_unsigned(l4, l3, l1);
        t1 = std_core$finish_buffer(l4, l3);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = std_core$f64$Display$to_string(l0);
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
    vader_obj_header_init(_a0_obj, 1127u);
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
    vader_obj_header_init(_a0_obj, 1127u);
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
    vader_array_t* _a0_arr = vader_array_new(344u, 0u, 13u, 1631u);
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
    if (l2.tag == 920u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2085u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 940u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2107u);
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 899u) {
        t0 = l2.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        l6 = vader_emit_virt$f64_const_operands(t2);
        l6 = concat_2(1960u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 871u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(16));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1634u);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        l4 = std_core$write_bool(l3, l4, l7);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 886u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1752u);
        t0 = l2.payload.obj;
        t3 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        t4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        l8 = (uint64_t) (int64_t) t4;
        l4 = std_core$write_unsigned(l3, l4, l8);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 971u) {
        std_string__builder$append(l0, 2414u);
    } else if (l2.tag == 987u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StringConst_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 3, l9);
        vader_array_t* _a0_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0;
        l3 = (void*) _a0_arr;
        vader_emit_virt$printed(l0, l1, 2647u, l3);
    } else if (l2.tag == 965u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a1_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
        l3 = (void*) _a1_arr;
        vader_emit_virt$printed(l0, l1, 2286u, l3);
    } else if (l2.tag == 966u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a2_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
        l3 = (void*) _a2_arr;
        vader_emit_virt$printed(l0, l1, 2287u, l3);
    } else if (l2.tag == 967u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a3_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t0;
        l3 = (void*) _a3_arr;
        vader_emit_virt$printed(l0, l1, 2288u, l3);
    } else if (l2.tag == 964u) {
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
        vader_array_t* _a4_arr = vader_array_new(208u, 3u, 13u, 1127u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l12;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l10;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l3;
        l3 = (void*) _a4_arr;
        vader_emit_virt$printed(l0, l1, 2285u, l3);
    } else if (l2.tag == 976u) {
        std_string__builder$append(l0, 2524u);
    } else if (l2.tag == 977u) {
        std_string__builder$append(l0, 2528u);
        vader_array_push_ref((vader_array_t*) l1, vader_box_obj(0u, NULL).payload.obj);
        t0 = l2.payload.obj;
        l13 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value;
        vader_emit_virt$write_op_refs(l0, l1, l13);
    } else if (l2.tag == 894u) {
        std_string__builder$append(l0, 1847u);
    } else if (l2.tag == 883u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a5_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t0;
        l3 = (void*) _a5_arr;
        vader_emit_virt$printed(l0, l1, 1709u, l3);
    } else if (l2.tag == 884u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 4, l9);
        vader_array_t* _a6_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = t0;
        l3 = (void*) _a6_arr;
        vader_emit_virt$printed(l0, l1, 1711u, l3);
    } else if (l2.tag == 885u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a7_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0;
        l3 = (void*) _a7_arr;
        vader_emit_virt$printed(l0, l1, 1712u, l3);
    } else if (l2.tag == 1010u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_parameter_count;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_vtable_key;
        l4 = vader_host_std_core$byte_len(l6);
        l3 = (void*) vader_buffer_new((size_t) (INT64_C(38) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 3008u);
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
    } else if (l2.tag == 912u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a8_arr = vader_array_new(208u, 2u, 13u, 1127u);
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 1u] = l10;
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = l3;
        l3 = (void*) _a8_arr;
        vader_emit_virt$printed(l0, l1, 2016u, l3);
    } else if (l2.tag == 911u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a9_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t0;
        l3 = (void*) _a9_arr;
        vader_emit_virt$printed(l0, l1, 2014u, l3);
    } else if (l2.tag == 887u) {
        t0 = l2.payload.obj;
        l6 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        t0 = l2.payload.obj;
        l14 = vader_core_bytecode$checked_op_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_op);
        l6 = concat_3(l6, 410u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 888u) {
        t0 = l2.payload.obj;
        t5 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
        l6 = concat_2(t5, 411u);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 969u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a10_arr = vader_array_new(208u, 2u, 13u, 1127u);
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 1u] = l10;
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_emit_virt$printed(l0, l1, 2307u, l3);
    } else if (l2.tag == 955u) {
        std_string__builder$append(l0, 2129u);
    } else if (l2.tag == 895u) {
        std_string__builder$append(l0, 1859u);
    } else if (l2.tag == 896u) {
        std_string__builder$append(l0, 1877u);
    } else if (l2.tag == 869u) {
        std_string__builder$append(l0, 1631u);
    } else if (l2.tag == 968u) {
        std_string__builder$append(l0, 2291u);
    } else if (l2.tag == 876u) {
        std_string__builder$append(l0, 1642u);
    } else if (l2.tag == 877u) {
        std_string__builder$append(l0, 1644u);
    } else if (l2.tag == 874u) {
        std_string__builder$append(l0, 1637u);
    } else if (l2.tag == 991u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_stack;
        if (t6) {
            l6 = 2670u;
        } else {
            l6 = 2667u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a11_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = t0;
        l3 = (void*) _a11_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 990u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a12_arr = vader_array_new(208u, 2u, 13u, 1127u);
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 1u] = l10;
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l3;
        l3 = (void*) _a12_arr;
        vader_emit_virt$printed(l0, l1, 2666u, l3);
    } else if (l2.tag == 992u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_stack;
        if (t6) {
            l6 = 2675u;
        } else {
            l6 = 2671u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a13_arr = vader_array_new(208u, 2u, 13u, 1127u);
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 1u] = l10;
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = l3;
        l3 = (void*) _a13_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 1007u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a14_arr = vader_array_new(208u, 2u, 13u, 1127u);
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 1u] = l10;
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = l3;
        l3 = (void*) _a14_arr;
        vader_emit_virt$printed(l0, l1, 2814u, l3);
    } else if (l2.tag == 1008u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a15_arr = vader_array_new(208u, 2u, 13u, 1127u);
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 1u] = l10;
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = l3;
        l3 = (void*) _a15_arr;
        vader_emit_virt$printed(l0, l1, 2815u, l3);
    } else if (l2.tag == 840u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a16_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = t0;
        l3 = (void*) _a16_arr;
        vader_emit_virt$printed(l0, l1, 1577u, l3);
        l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 14u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 839u) {
        std_string__builder$append(l0, 1576u);
    } else if (l2.tag == 841u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            l3 = vader_emit_virt$refer((uint8_t) 1, l9);
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
            l10 = vader_emit_virt$refer((uint8_t) 6, l9);
            vader_array_t* _a17_arr = vader_array_new(208u, 2u, 13u, 1127u);
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 1u] = l10;
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = l3;
            l3 = (void*) _a17_arr;
            vader_emit_virt$printed(l0, l1, 1579u, l3);
        } else {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            t0 = vader_emit_virt$refer((uint8_t) 1, l9);
            vader_array_t* _a18_arr = vader_array_new(208u, 1u, 13u, 1127u);
            ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 0u] = t0;
            l3 = (void*) _a18_arr;
            vader_emit_virt$printed(l0, l1, 1579u, l3);
        }
    } else if (l2.tag == 838u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a19_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = t0;
        l3 = (void*) _a19_arr;
        vader_emit_virt$printed(l0, l1, 1575u, l3);
    } else if (l2.tag == 845u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a20_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = t0;
        l3 = (void*) _a20_arr;
        vader_emit_virt$printed(l0, l1, 1588u, l3);
    } else if (l2.tag == 846u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a21_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = t0;
        l3 = (void*) _a21_arr;
        vader_emit_virt$printed(l0, l1, 1589u, l3);
    } else if (l2.tag == 844u) {
        std_string__builder$append(l0, 1585u);
    } else if (l2.tag == 842u) {
        std_string__builder$append(l0, 1580u);
    } else if (l2.tag == 837u) {
        std_string__builder$append(l0, 1567u);
    } else if (l2.tag == 843u) {
        std_string__builder$append(l0, 1583u);
    } else if (l2.tag == 836u) {
        std_string__builder$append(l0, 1565u);
    } else if (l2.tag == 890u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        l3 = vader_emit_virt$refer((uint8_t) 5, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a22_arr = vader_array_new(208u, 2u, 13u, 1127u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 1u] = l10;
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = l3;
        l3 = (void*) _a22_arr;
        vader_emit_virt$printed(l0, l1, 1816u, l3);
    } else if (l2.tag == 913u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a23_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 0u] = t0;
        l3 = (void*) _a23_arr;
        vader_emit_virt$printed(l0, l1, 2062u, l3);
    } else if (l2.tag == 914u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a24_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = t0;
        l3 = (void*) _a24_arr;
        vader_emit_virt$printed(l0, l1, 2063u, l3);
    } else if (l2.tag == 994u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a25_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 0u] = t0;
        l3 = (void*) _a25_arr;
        vader_emit_virt$printed(l0, l1, 2758u, l3);
    } else if (l2.tag == 993u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a26_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a26_arr->buf->slots)[_a26_arr->offset + 0u] = t0;
        l3 = (void*) _a26_arr;
        vader_emit_virt$printed(l0, l1, 2761u, l3);
    } else if (l2.tag == 972u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a27_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a27_arr->buf->slots)[_a27_arr->offset + 0u] = t0;
        l3 = (void*) _a27_arr;
        vader_emit_virt$printed(l0, l1, 2503u, l3);
    } else if (l2.tag == 975u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a28_arr = vader_array_new(208u, 1u, 13u, 1127u);
        ((void**) _a28_arr->buf->slots)[_a28_arr->offset + 0u] = t0;
        l3 = (void*) _a28_arr;
        vader_emit_virt$printed(l0, l1, 2523u, l3);
    } else if (l2.tag == 1009u) {
        std_string__builder$append(l0, 2828u);
    } else if (l2.tag == 889u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        t0 = l2.payload.obj;
        l14 = vader_emit_virt$convert_target_name(((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target);
        l6 = concat_3(l6, 438u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 978u) {
        std_string__builder$append(l0, 2192u);
    } else if (l2.tag == 915u) {
        std_string__builder$append(l0, 2080u);
    } else if (l2.tag == 934u) {
        std_string__builder$append(l0, 2100u);
    } else if (l2.tag == 928u) {
        std_string__builder$append(l0, 2094u);
    } else if (l2.tag == 921u) {
        std_string__builder$append(l0, 2086u);
    } else if (l2.tag == 927u) {
        std_string__builder$append(l0, 2097u);
    } else if (l2.tag == 930u) {
        std_string__builder$append(l0, 2096u);
    } else if (l2.tag == 917u) {
        std_string__builder$append(l0, 2082u);
    } else if (l2.tag == 916u) {
        std_string__builder$append(l0, 2081u);
    } else if (l2.tag == 918u) {
        std_string__builder$append(l0, 2083u);
    } else if (l2.tag == 919u) {
        std_string__builder$append(l0, 2084u);
    } else if (l2.tag == 931u) {
        std_string__builder$append(l0, 2098u);
    } else if (l2.tag == 932u) {
        std_string__builder$append(l0, 2099u);
    } else if (l2.tag == 933u) {
        std_string__builder$append(l0, 2788u);
    } else if (l2.tag == 922u) {
        std_string__builder$append(l0, 2088u);
    } else if (l2.tag == 929u) {
        std_string__builder$append(l0, 2095u);
    } else if (l2.tag == 926u) {
        std_string__builder$append(l0, 2092u);
    } else if (l2.tag == 925u) {
        std_string__builder$append(l0, 2091u);
    } else if (l2.tag == 924u) {
        std_string__builder$append(l0, 2090u);
    } else if (l2.tag == 923u) {
        std_string__builder$append(l0, 2089u);
    } else if (l2.tag == 935u) {
        std_string__builder$append(l0, 2102u);
    } else if (l2.tag == 954u) {
        std_string__builder$append(l0, 2122u);
    } else if (l2.tag == 948u) {
        std_string__builder$append(l0, 2115u);
    } else if (l2.tag == 941u) {
        std_string__builder$append(l0, 2108u);
    } else if (l2.tag == 947u) {
        std_string__builder$append(l0, 2118u);
    } else if (l2.tag == 950u) {
        std_string__builder$append(l0, 2117u);
    } else if (l2.tag == 936u) {
        std_string__builder$append(l0, 2103u);
    } else if (l2.tag == 938u) {
        std_string__builder$append(l0, 2105u);
    } else if (l2.tag == 939u) {
        std_string__builder$append(l0, 2106u);
    } else if (l2.tag == 937u) {
        std_string__builder$append(l0, 2104u);
    } else if (l2.tag == 951u) {
        std_string__builder$append(l0, 2120u);
    } else if (l2.tag == 952u) {
        std_string__builder$append(l0, 2121u);
    } else if (l2.tag == 953u) {
        std_string__builder$append(l0, 2798u);
    } else if (l2.tag == 942u) {
        std_string__builder$append(l0, 2110u);
    } else if (l2.tag == 949u) {
        std_string__builder$append(l0, 2116u);
    } else if (l2.tag == 946u) {
        std_string__builder$append(l0, 2114u);
    } else if (l2.tag == 945u) {
        std_string__builder$append(l0, 2113u);
    } else if (l2.tag == 944u) {
        std_string__builder$append(l0, 2112u);
    } else if (l2.tag == 943u) {
        std_string__builder$append(l0, 2111u);
    } else if (l2.tag == 995u) {
        std_string__builder$append(l0, 2780u);
    } else if (l2.tag == 1000u) {
        std_string__builder$append(l0, 2786u);
    } else if (l2.tag == 999u) {
        std_string__builder$append(l0, 2785u);
    } else if (l2.tag == 998u) {
        std_string__builder$append(l0, 2784u);
    } else if (l2.tag == 997u) {
        std_string__builder$append(l0, 2783u);
    } else if (l2.tag == 996u) {
        std_string__builder$append(l0, 2782u);
    } else if (l2.tag == 1001u) {
        std_string__builder$append(l0, 2790u);
    } else if (l2.tag == 1006u) {
        std_string__builder$append(l0, 2796u);
    } else if (l2.tag == 1005u) {
        std_string__builder$append(l0, 2795u);
    } else if (l2.tag == 1004u) {
        std_string__builder$append(l0, 2794u);
    } else if (l2.tag == 1003u) {
        std_string__builder$append(l0, 2793u);
    } else if (l2.tag == 1002u) {
        std_string__builder$append(l0, 2792u);
    } else if (l2.tag == 898u) {
        std_string__builder$append(l0, 1959u);
    } else if (l2.tag == 909u) {
        std_string__builder$append(l0, 1970u);
    } else if (l2.tag == 906u) {
        std_string__builder$append(l0, 1967u);
    } else if (l2.tag == 900u) {
        std_string__builder$append(l0, 1961u);
    } else if (l2.tag == 908u) {
        std_string__builder$append(l0, 1969u);
    } else if (l2.tag == 901u) {
        std_string__builder$append(l0, 1962u);
    } else if (l2.tag == 907u) {
        std_string__builder$append(l0, 1968u);
    } else if (l2.tag == 905u) {
        std_string__builder$append(l0, 1966u);
    } else if (l2.tag == 904u) {
        std_string__builder$append(l0, 1965u);
    } else if (l2.tag == 903u) {
        std_string__builder$append(l0, 1964u);
    } else if (l2.tag == 902u) {
        std_string__builder$append(l0, 1963u);
    } else if (l2.tag == 872u) {
        std_string__builder$append(l0, 1635u);
    } else if (l2.tag == 873u) {
        std_string__builder$append(l0, 1636u);
    } else if (l2.tag == 870u) {
        std_string__builder$append(l0, 1633u);
    } else if (l2.tag == 875u) {
        std_string__builder$append(l0, 1638u);
    } else if (l2.tag == 988u) {
        std_string__builder$append(l0, 2648u);
    } else if (l2.tag == 989u) {
        std_string__builder$append(l0, 2650u);
    } else if (l2.tag == 986u) {
        std_string__builder$append(l0, 2646u);
    } else if (l2.tag == 973u) {
        std_string__builder$append(l0, 2504u);
    } else if (l2.tag == 974u) {
        std_string__builder$append(l0, 2505u);
    } else if (l2.tag == 893u) {
        std_string__builder$append(l0, 1832u);
    } else if (l2.tag == 892u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(35));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1830u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$DeferPopExec_t*) t0)->f_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 878u) {
        std_string__builder$append(l0, 1654u);
    } else if (l2.tag == 963u) {
        std_string__builder$append(l0, 2280u);
    } else if (l2.tag == 958u) {
        std_string__builder$append(l0, 2274u);
    } else if (l2.tag == 959u) {
        std_string__builder$append(l0, 2275u);
    } else if (l2.tag == 957u) {
        std_string__builder$append(l0, 2273u);
    } else if (l2.tag == 985u) {
        std_string__builder$append(l0, 2641u);
    } else if (l2.tag == 980u) {
        std_string__builder$append(l0, 2634u);
    } else if (l2.tag == 981u) {
        std_string__builder$append(l0, 2635u);
    } else if (l2.tag == 979u) {
        std_string__builder$append(l0, 2632u);
    } else if (l2.tag == 961u) {
        std_string__builder$append(l0, 2278u);
    } else if (l2.tag == 962u) {
        std_string__builder$append(l0, 2279u);
    } else if (l2.tag == 960u) {
        std_string__builder$append(l0, 2277u);
    } else if (l2.tag == 983u) {
        std_string__builder$append(l0, 2639u);
    } else if (l2.tag == 984u) {
        std_string__builder$append(l0, 2640u);
    } else if (l2.tag == 982u) {
        std_string__builder$append(l0, 2638u);
    } else if (l2.tag == 970u) {
        std_string__builder$append(l0, 2328u);
    } else if (l2.tag == 879u) {
        std_string__builder$append(l0, 1657u);
    } else if (l2.tag == 880u) {
        std_string__builder$append(l0, 1660u);
    } else if (l2.tag == 910u) {
        std_string__builder$append(l0, 1971u);
    } else if (l2.tag == 868u) {
        std_string__builder$append(l0, 1629u);
    } else if (l2.tag == 897u) {
        std_string__builder$append(l0, 1957u);
    } else {
        if (!(l2.tag == 867u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string__builder$append(l0, 1628u);
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
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 452u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string__builder$append_char(l0, 40u);
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l1)->length;
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            std_string__builder$append(l0, 361u);
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 452u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append_char(l0, 41u);
    { vader_gc_top = gc_frame.prev; return; }
}
