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
        l1 = 2075u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2097u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1952u;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1745u;
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
    vader_obj_header_init(_a0_obj, 1012u);
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
    vader_obj_header_init(_a0_obj, 1012u);
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
    vader_array_t* _a0_arr = vader_array_new(232u, 0u, 13u, 1517u);
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
    if (l2.tag == 805u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2081u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 825u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2103u);
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 784u) {
        t0 = l2.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        l6 = vader_emit_virt$f64_const_operands(t2);
        l6 = concat_2(1954u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 756u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(16));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1629u);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        l4 = std_core$write_bool(l3, l4, l7);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 771u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1747u);
        t0 = l2.payload.obj;
        t3 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        t4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        l8 = (uint64_t) (int64_t) t4;
        l4 = std_core$write_unsigned(l3, l4, l8);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 856u) {
        std_string__builder$append(l0, 2409u);
    } else if (l2.tag == 872u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StringConst_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 3, l9);
        vader_array_t* _a0_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0;
        l3 = (void*) _a0_arr;
        vader_emit_virt$printed(l0, l1, 2642u, l3);
    } else if (l2.tag == 850u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a1_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
        l3 = (void*) _a1_arr;
        vader_emit_virt$printed(l0, l1, 2281u, l3);
    } else if (l2.tag == 851u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a2_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
        l3 = (void*) _a2_arr;
        vader_emit_virt$printed(l0, l1, 2282u, l3);
    } else if (l2.tag == 852u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a3_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t0;
        l3 = (void*) _a3_arr;
        vader_emit_virt$printed(l0, l1, 2283u, l3);
    } else if (l2.tag == 849u) {
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
        vader_array_t* _a4_arr = vader_array_new(105u, 3u, 13u, 1012u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l12;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l10;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l3;
        l3 = (void*) _a4_arr;
        vader_emit_virt$printed(l0, l1, 2280u, l3);
    } else if (l2.tag == 861u) {
        std_string__builder$append(l0, 2519u);
    } else if (l2.tag == 862u) {
        std_string__builder$append(l0, 2523u);
        vader_array_push_ref((vader_array_t*) l1, vader_box_obj(0u, NULL).payload.obj);
        t0 = l2.payload.obj;
        l13 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value;
        vader_emit_virt$write_op_refs(l0, l1, l13);
    } else if (l2.tag == 779u) {
        std_string__builder$append(l0, 1842u);
    } else if (l2.tag == 768u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a5_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t0;
        l3 = (void*) _a5_arr;
        vader_emit_virt$printed(l0, l1, 1704u, l3);
    } else if (l2.tag == 769u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 4, l9);
        vader_array_t* _a6_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = t0;
        l3 = (void*) _a6_arr;
        vader_emit_virt$printed(l0, l1, 1706u, l3);
    } else if (l2.tag == 770u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a7_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0;
        l3 = (void*) _a7_arr;
        vader_emit_virt$printed(l0, l1, 1707u, l3);
    } else if (l2.tag == 895u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_parameter_count;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_vtable_key;
        l4 = vader_host_std_core$byte_len(l6);
        l3 = (void*) vader_buffer_new((size_t) (INT64_C(38) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 3003u);
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
    } else if (l2.tag == 797u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a8_arr = vader_array_new(105u, 2u, 13u, 1012u);
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 1u] = l10;
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = l3;
        l3 = (void*) _a8_arr;
        vader_emit_virt$printed(l0, l1, 2010u, l3);
    } else if (l2.tag == 796u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a9_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t0;
        l3 = (void*) _a9_arr;
        vader_emit_virt$printed(l0, l1, 2008u, l3);
    } else if (l2.tag == 772u) {
        t0 = l2.payload.obj;
        l6 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        t0 = l2.payload.obj;
        l14 = vader_core_bytecode$checked_op_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_op);
        l6 = concat_3(l6, 409u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 773u) {
        t0 = l2.payload.obj;
        t5 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
        l6 = concat_2(t5, 410u);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 854u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a10_arr = vader_array_new(105u, 2u, 13u, 1012u);
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 1u] = l10;
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_emit_virt$printed(l0, l1, 2302u, l3);
    } else if (l2.tag == 840u) {
        std_string__builder$append(l0, 2124u);
    } else if (l2.tag == 780u) {
        std_string__builder$append(l0, 1854u);
    } else if (l2.tag == 781u) {
        std_string__builder$append(l0, 1871u);
    } else if (l2.tag == 754u) {
        std_string__builder$append(l0, 1626u);
    } else if (l2.tag == 853u) {
        std_string__builder$append(l0, 2286u);
    } else if (l2.tag == 761u) {
        std_string__builder$append(l0, 1637u);
    } else if (l2.tag == 762u) {
        std_string__builder$append(l0, 1639u);
    } else if (l2.tag == 759u) {
        std_string__builder$append(l0, 1632u);
    } else if (l2.tag == 876u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_stack;
        if (t6) {
            l6 = 2665u;
        } else {
            l6 = 2662u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a11_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = t0;
        l3 = (void*) _a11_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 875u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a12_arr = vader_array_new(105u, 2u, 13u, 1012u);
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 1u] = l10;
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l3;
        l3 = (void*) _a12_arr;
        vader_emit_virt$printed(l0, l1, 2661u, l3);
    } else if (l2.tag == 877u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_stack;
        if (t6) {
            l6 = 2670u;
        } else {
            l6 = 2666u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a13_arr = vader_array_new(105u, 2u, 13u, 1012u);
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 1u] = l10;
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = l3;
        l3 = (void*) _a13_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 892u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a14_arr = vader_array_new(105u, 2u, 13u, 1012u);
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 1u] = l10;
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = l3;
        l3 = (void*) _a14_arr;
        vader_emit_virt$printed(l0, l1, 2809u, l3);
    } else if (l2.tag == 893u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a15_arr = vader_array_new(105u, 2u, 13u, 1012u);
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 1u] = l10;
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = l3;
        l3 = (void*) _a15_arr;
        vader_emit_virt$printed(l0, l1, 2810u, l3);
    } else if (l2.tag == 725u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a16_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = t0;
        l3 = (void*) _a16_arr;
        vader_emit_virt$printed(l0, l1, 1572u, l3);
        l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 14u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 724u) {
        std_string__builder$append(l0, 1571u);
    } else if (l2.tag == 726u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            l3 = vader_emit_virt$refer((uint8_t) 1, l9);
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
            l10 = vader_emit_virt$refer((uint8_t) 6, l9);
            vader_array_t* _a17_arr = vader_array_new(105u, 2u, 13u, 1012u);
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 1u] = l10;
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = l3;
            l3 = (void*) _a17_arr;
            vader_emit_virt$printed(l0, l1, 1574u, l3);
        } else {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            t0 = vader_emit_virt$refer((uint8_t) 1, l9);
            vader_array_t* _a18_arr = vader_array_new(105u, 1u, 13u, 1012u);
            ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 0u] = t0;
            l3 = (void*) _a18_arr;
            vader_emit_virt$printed(l0, l1, 1574u, l3);
        }
    } else if (l2.tag == 723u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a19_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = t0;
        l3 = (void*) _a19_arr;
        vader_emit_virt$printed(l0, l1, 1570u, l3);
    } else if (l2.tag == 730u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a20_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = t0;
        l3 = (void*) _a20_arr;
        vader_emit_virt$printed(l0, l1, 1583u, l3);
    } else if (l2.tag == 731u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a21_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = t0;
        l3 = (void*) _a21_arr;
        vader_emit_virt$printed(l0, l1, 1584u, l3);
    } else if (l2.tag == 729u) {
        std_string__builder$append(l0, 1580u);
    } else if (l2.tag == 727u) {
        std_string__builder$append(l0, 1575u);
    } else if (l2.tag == 722u) {
        std_string__builder$append(l0, 1562u);
    } else if (l2.tag == 728u) {
        std_string__builder$append(l0, 1578u);
    } else if (l2.tag == 721u) {
        std_string__builder$append(l0, 1560u);
    } else if (l2.tag == 775u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        l3 = vader_emit_virt$refer((uint8_t) 5, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a22_arr = vader_array_new(105u, 2u, 13u, 1012u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 1u] = l10;
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = l3;
        l3 = (void*) _a22_arr;
        vader_emit_virt$printed(l0, l1, 1811u, l3);
    } else if (l2.tag == 798u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a23_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 0u] = t0;
        l3 = (void*) _a23_arr;
        vader_emit_virt$printed(l0, l1, 2057u, l3);
    } else if (l2.tag == 799u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a24_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = t0;
        l3 = (void*) _a24_arr;
        vader_emit_virt$printed(l0, l1, 2058u, l3);
    } else if (l2.tag == 879u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a25_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 0u] = t0;
        l3 = (void*) _a25_arr;
        vader_emit_virt$printed(l0, l1, 2753u, l3);
    } else if (l2.tag == 878u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a26_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a26_arr->buf->slots)[_a26_arr->offset + 0u] = t0;
        l3 = (void*) _a26_arr;
        vader_emit_virt$printed(l0, l1, 2756u, l3);
    } else if (l2.tag == 857u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a27_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a27_arr->buf->slots)[_a27_arr->offset + 0u] = t0;
        l3 = (void*) _a27_arr;
        vader_emit_virt$printed(l0, l1, 2498u, l3);
    } else if (l2.tag == 860u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a28_arr = vader_array_new(105u, 1u, 13u, 1012u);
        ((void**) _a28_arr->buf->slots)[_a28_arr->offset + 0u] = t0;
        l3 = (void*) _a28_arr;
        vader_emit_virt$printed(l0, l1, 2518u, l3);
    } else if (l2.tag == 894u) {
        std_string__builder$append(l0, 2823u);
    } else if (l2.tag == 774u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        t0 = l2.payload.obj;
        l14 = vader_emit_virt$convert_target_name(((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target);
        l6 = concat_3(l6, 437u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 863u) {
        std_string__builder$append(l0, 2187u);
    } else if (l2.tag == 800u) {
        std_string__builder$append(l0, 2076u);
    } else if (l2.tag == 819u) {
        std_string__builder$append(l0, 2096u);
    } else if (l2.tag == 813u) {
        std_string__builder$append(l0, 2090u);
    } else if (l2.tag == 806u) {
        std_string__builder$append(l0, 2082u);
    } else if (l2.tag == 812u) {
        std_string__builder$append(l0, 2093u);
    } else if (l2.tag == 815u) {
        std_string__builder$append(l0, 2092u);
    } else if (l2.tag == 802u) {
        std_string__builder$append(l0, 2078u);
    } else if (l2.tag == 801u) {
        std_string__builder$append(l0, 2077u);
    } else if (l2.tag == 803u) {
        std_string__builder$append(l0, 2079u);
    } else if (l2.tag == 804u) {
        std_string__builder$append(l0, 2080u);
    } else if (l2.tag == 816u) {
        std_string__builder$append(l0, 2094u);
    } else if (l2.tag == 817u) {
        std_string__builder$append(l0, 2095u);
    } else if (l2.tag == 818u) {
        std_string__builder$append(l0, 2783u);
    } else if (l2.tag == 807u) {
        std_string__builder$append(l0, 2084u);
    } else if (l2.tag == 814u) {
        std_string__builder$append(l0, 2091u);
    } else if (l2.tag == 811u) {
        std_string__builder$append(l0, 2088u);
    } else if (l2.tag == 810u) {
        std_string__builder$append(l0, 2087u);
    } else if (l2.tag == 809u) {
        std_string__builder$append(l0, 2086u);
    } else if (l2.tag == 808u) {
        std_string__builder$append(l0, 2085u);
    } else if (l2.tag == 820u) {
        std_string__builder$append(l0, 2098u);
    } else if (l2.tag == 839u) {
        std_string__builder$append(l0, 2118u);
    } else if (l2.tag == 833u) {
        std_string__builder$append(l0, 2111u);
    } else if (l2.tag == 826u) {
        std_string__builder$append(l0, 2104u);
    } else if (l2.tag == 832u) {
        std_string__builder$append(l0, 2114u);
    } else if (l2.tag == 835u) {
        std_string__builder$append(l0, 2113u);
    } else if (l2.tag == 821u) {
        std_string__builder$append(l0, 2099u);
    } else if (l2.tag == 823u) {
        std_string__builder$append(l0, 2101u);
    } else if (l2.tag == 824u) {
        std_string__builder$append(l0, 2102u);
    } else if (l2.tag == 822u) {
        std_string__builder$append(l0, 2100u);
    } else if (l2.tag == 836u) {
        std_string__builder$append(l0, 2116u);
    } else if (l2.tag == 837u) {
        std_string__builder$append(l0, 2117u);
    } else if (l2.tag == 838u) {
        std_string__builder$append(l0, 2793u);
    } else if (l2.tag == 827u) {
        std_string__builder$append(l0, 2106u);
    } else if (l2.tag == 834u) {
        std_string__builder$append(l0, 2112u);
    } else if (l2.tag == 831u) {
        std_string__builder$append(l0, 2110u);
    } else if (l2.tag == 830u) {
        std_string__builder$append(l0, 2109u);
    } else if (l2.tag == 829u) {
        std_string__builder$append(l0, 2108u);
    } else if (l2.tag == 828u) {
        std_string__builder$append(l0, 2107u);
    } else if (l2.tag == 880u) {
        std_string__builder$append(l0, 2775u);
    } else if (l2.tag == 885u) {
        std_string__builder$append(l0, 2781u);
    } else if (l2.tag == 884u) {
        std_string__builder$append(l0, 2780u);
    } else if (l2.tag == 883u) {
        std_string__builder$append(l0, 2779u);
    } else if (l2.tag == 882u) {
        std_string__builder$append(l0, 2778u);
    } else if (l2.tag == 881u) {
        std_string__builder$append(l0, 2777u);
    } else if (l2.tag == 886u) {
        std_string__builder$append(l0, 2785u);
    } else if (l2.tag == 891u) {
        std_string__builder$append(l0, 2791u);
    } else if (l2.tag == 890u) {
        std_string__builder$append(l0, 2790u);
    } else if (l2.tag == 889u) {
        std_string__builder$append(l0, 2789u);
    } else if (l2.tag == 888u) {
        std_string__builder$append(l0, 2788u);
    } else if (l2.tag == 887u) {
        std_string__builder$append(l0, 2787u);
    } else if (l2.tag == 783u) {
        std_string__builder$append(l0, 1953u);
    } else if (l2.tag == 794u) {
        std_string__builder$append(l0, 1964u);
    } else if (l2.tag == 791u) {
        std_string__builder$append(l0, 1961u);
    } else if (l2.tag == 785u) {
        std_string__builder$append(l0, 1955u);
    } else if (l2.tag == 793u) {
        std_string__builder$append(l0, 1963u);
    } else if (l2.tag == 786u) {
        std_string__builder$append(l0, 1956u);
    } else if (l2.tag == 792u) {
        std_string__builder$append(l0, 1962u);
    } else if (l2.tag == 790u) {
        std_string__builder$append(l0, 1960u);
    } else if (l2.tag == 789u) {
        std_string__builder$append(l0, 1959u);
    } else if (l2.tag == 788u) {
        std_string__builder$append(l0, 1958u);
    } else if (l2.tag == 787u) {
        std_string__builder$append(l0, 1957u);
    } else if (l2.tag == 757u) {
        std_string__builder$append(l0, 1630u);
    } else if (l2.tag == 758u) {
        std_string__builder$append(l0, 1631u);
    } else if (l2.tag == 755u) {
        std_string__builder$append(l0, 1628u);
    } else if (l2.tag == 760u) {
        std_string__builder$append(l0, 1633u);
    } else if (l2.tag == 873u) {
        std_string__builder$append(l0, 2643u);
    } else if (l2.tag == 874u) {
        std_string__builder$append(l0, 2645u);
    } else if (l2.tag == 871u) {
        std_string__builder$append(l0, 2641u);
    } else if (l2.tag == 858u) {
        std_string__builder$append(l0, 2499u);
    } else if (l2.tag == 859u) {
        std_string__builder$append(l0, 2500u);
    } else if (l2.tag == 778u) {
        std_string__builder$append(l0, 1827u);
    } else if (l2.tag == 777u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(35));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1825u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$DeferPopExec_t*) t0)->f_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 763u) {
        std_string__builder$append(l0, 1649u);
    } else if (l2.tag == 848u) {
        std_string__builder$append(l0, 2275u);
    } else if (l2.tag == 843u) {
        std_string__builder$append(l0, 2269u);
    } else if (l2.tag == 844u) {
        std_string__builder$append(l0, 2270u);
    } else if (l2.tag == 842u) {
        std_string__builder$append(l0, 2268u);
    } else if (l2.tag == 870u) {
        std_string__builder$append(l0, 2636u);
    } else if (l2.tag == 865u) {
        std_string__builder$append(l0, 2629u);
    } else if (l2.tag == 866u) {
        std_string__builder$append(l0, 2630u);
    } else if (l2.tag == 864u) {
        std_string__builder$append(l0, 2627u);
    } else if (l2.tag == 846u) {
        std_string__builder$append(l0, 2273u);
    } else if (l2.tag == 847u) {
        std_string__builder$append(l0, 2274u);
    } else if (l2.tag == 845u) {
        std_string__builder$append(l0, 2272u);
    } else if (l2.tag == 868u) {
        std_string__builder$append(l0, 2634u);
    } else if (l2.tag == 869u) {
        std_string__builder$append(l0, 2635u);
    } else if (l2.tag == 867u) {
        std_string__builder$append(l0, 2633u);
    } else if (l2.tag == 855u) {
        std_string__builder$append(l0, 2323u);
    } else if (l2.tag == 764u) {
        std_string__builder$append(l0, 1652u);
    } else if (l2.tag == 765u) {
        std_string__builder$append(l0, 1655u);
    } else if (l2.tag == 795u) {
        std_string__builder$append(l0, 1965u);
    } else if (l2.tag == 753u) {
        std_string__builder$append(l0, 1624u);
    } else if (l2.tag == 782u) {
        std_string__builder$append(l0, 1951u);
    } else {
        if (!(l2.tag == 752u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string__builder$append(l0, 1623u);
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
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 340u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string__builder$append_char(l0, 40u);
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l1)->length;
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            std_string__builder$append(l0, 360u);
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 340u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append_char(l0, 41u);
    { vader_gc_top = gc_frame.prev; return; }
}
