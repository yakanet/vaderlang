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
        l1 = 2221u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2243u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2094u;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1872u;
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
    vader_obj_header_init(_a0_obj, 1264u);
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
    vader_obj_header_init(_a0_obj, 1264u);
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
    vader_array_t* _a0_arr = vader_array_new(379u, 0u, 13u, 1822u);
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
    if (l2.tag == 1056u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2227u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 1076u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2249u);
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1035u) {
        t0 = l2.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        l6 = vader_emit_virt$f64_const_operands(t2);
        l6 = concat_2(2096u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1007u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(16));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1747u);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        l4 = std_core$write_bool(l3, l4, l7);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1022u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1874u);
        t0 = l2.payload.obj;
        t3 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        t4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        l8 = (uint64_t) (int64_t) t4;
        l4 = std_core$write_unsigned(l3, l4, l8);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1107u) {
        std_string__builder$append(l0, 2578u);
    } else if (l2.tag == 1123u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StringConst_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 3, l9);
        vader_array_t* _a0_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = t0;
        l3 = (void*) _a0_arr;
        vader_emit_virt$printed(l0, l1, 2851u, l3);
    } else if (l2.tag == 1101u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a1_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
        l3 = (void*) _a1_arr;
        vader_emit_virt$printed(l0, l1, 2437u, l3);
    } else if (l2.tag == 1102u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a2_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t0;
        l3 = (void*) _a2_arr;
        vader_emit_virt$printed(l0, l1, 2438u, l3);
    } else if (l2.tag == 1103u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a3_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = t0;
        l3 = (void*) _a3_arr;
        vader_emit_virt$printed(l0, l1, 2439u, l3);
    } else if (l2.tag == 1100u) {
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
        vader_array_t* _a4_arr = vader_array_new(221u, 3u, 13u, 1264u);
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 2u] = l12;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 1u] = l10;
        ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l3;
        l3 = (void*) _a4_arr;
        vader_emit_virt$printed(l0, l1, 2436u, l3);
    } else if (l2.tag == 1112u) {
        std_string__builder$append(l0, 2692u);
    } else if (l2.tag == 1113u) {
        std_string__builder$append(l0, 2696u);
        vader_array_push_ref((vader_array_t*) l1, vader_box_obj(0u, NULL).payload.obj);
        t0 = l2.payload.obj;
        l13 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value;
        vader_emit_virt$write_op_refs(l0, l1, l13);
    } else if (l2.tag == 1030u) {
        std_string__builder$append(l0, 1977u);
    } else if (l2.tag == 1019u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a5_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = t0;
        l3 = (void*) _a5_arr;
        vader_emit_virt$printed(l0, l1, 1824u, l3);
    } else if (l2.tag == 1020u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 4, l9);
        vader_array_t* _a6_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a6_arr->buf->slots)[_a6_arr->offset + 0u] = t0;
        l3 = (void*) _a6_arr;
        vader_emit_virt$printed(l0, l1, 1827u, l3);
    } else if (l2.tag == 1021u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a7_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a7_arr->buf->slots)[_a7_arr->offset + 0u] = t0;
        l3 = (void*) _a7_arr;
        vader_emit_virt$printed(l0, l1, 1828u, l3);
    } else if (l2.tag == 1146u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_parameter_count;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_vtable_key;
        l4 = vader_host_std_core$byte_len(l6);
        l3 = (void*) vader_buffer_new((size_t) (INT64_C(38) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 3239u);
        l5 = ((int64_t) (int32_t) l9);
        l4 = std_core$write_int(l3, l4, l5);
        l4 = std_core$write_string_at(l3, l4, 14u);
        l4 = std_core$write_string_at(l3, l4, l6);
        l4 = std_core$write_string_at(l3, l4, 64u);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
        t0 = l2.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_results;
        vader_emit_virt$write_results(l0, l3);
    } else if (l2.tag == 1048u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a8_arr = vader_array_new(221u, 2u, 13u, 1264u);
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 1u] = l10;
        ((void**) _a8_arr->buf->slots)[_a8_arr->offset + 0u] = l3;
        l3 = (void*) _a8_arr;
        vader_emit_virt$printed(l0, l1, 2153u, l3);
    } else if (l2.tag == 1047u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a9_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a9_arr->buf->slots)[_a9_arr->offset + 0u] = t0;
        l3 = (void*) _a9_arr;
        vader_emit_virt$printed(l0, l1, 2151u, l3);
    } else if (l2.tag == 1023u) {
        t0 = l2.payload.obj;
        l6 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        t0 = l2.payload.obj;
        l14 = vader_core_bytecode$checked_op_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_op);
        l6 = concat_3(l6, 444u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1024u) {
        t0 = l2.payload.obj;
        t5 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
        l6 = concat_2(t5, 445u);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1105u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a10_arr = vader_array_new(221u, 2u, 13u, 1264u);
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 1u] = l10;
        ((void**) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_emit_virt$printed(l0, l1, 2465u, l3);
    } else if (l2.tag == 1091u) {
        std_string__builder$append(l0, 2271u);
    } else if (l2.tag == 1031u) {
        std_string__builder$append(l0, 1991u);
    } else if (l2.tag == 1032u) {
        std_string__builder$append(l0, 2009u);
    } else if (l2.tag == 1005u) {
        std_string__builder$append(l0, 1744u);
    } else if (l2.tag == 1104u) {
        std_string__builder$append(l0, 2442u);
    } else if (l2.tag == 1012u) {
        std_string__builder$append(l0, 1755u);
    } else if (l2.tag == 1013u) {
        std_string__builder$append(l0, 1757u);
    } else if (l2.tag == 1010u) {
        std_string__builder$append(l0, 1750u);
    } else if (l2.tag == 1127u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_stack;
        if (t6) {
            l6 = 2873u;
        } else {
            l6 = 2870u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a11_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a11_arr->buf->slots)[_a11_arr->offset + 0u] = t0;
        l3 = (void*) _a11_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 1126u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a12_arr = vader_array_new(221u, 2u, 13u, 1264u);
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 1u] = l10;
        ((void**) _a12_arr->buf->slots)[_a12_arr->offset + 0u] = l3;
        l3 = (void*) _a12_arr;
        vader_emit_virt$printed(l0, l1, 2869u, l3);
    } else if (l2.tag == 1128u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_stack;
        if (t6) {
            l6 = 2878u;
        } else {
            l6 = 2874u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a13_arr = vader_array_new(221u, 2u, 13u, 1264u);
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 1u] = l10;
        ((void**) _a13_arr->buf->slots)[_a13_arr->offset + 0u] = l3;
        l3 = (void*) _a13_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 1143u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a14_arr = vader_array_new(221u, 2u, 13u, 1264u);
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 1u] = l10;
        ((void**) _a14_arr->buf->slots)[_a14_arr->offset + 0u] = l3;
        l3 = (void*) _a14_arr;
        vader_emit_virt$printed(l0, l1, 3029u, l3);
    } else if (l2.tag == 1144u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a15_arr = vader_array_new(221u, 2u, 13u, 1264u);
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 1u] = l10;
        ((void**) _a15_arr->buf->slots)[_a15_arr->offset + 0u] = l3;
        l3 = (void*) _a15_arr;
        vader_emit_virt$printed(l0, l1, 3030u, l3);
    } else if (l2.tag == 975u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a16_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a16_arr->buf->slots)[_a16_arr->offset + 0u] = t0;
        l3 = (void*) _a16_arr;
        vader_emit_virt$printed(l0, l1, 1696u, l3);
        l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 14u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 974u) {
        std_string__builder$append(l0, 1695u);
    } else if (l2.tag == 976u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            l3 = vader_emit_virt$refer((uint8_t) 1, l9);
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
            l10 = vader_emit_virt$refer((uint8_t) 6, l9);
            vader_array_t* _a17_arr = vader_array_new(221u, 2u, 13u, 1264u);
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 1u] = l10;
            ((void**) _a17_arr->buf->slots)[_a17_arr->offset + 0u] = l3;
            l3 = (void*) _a17_arr;
            vader_emit_virt$printed(l0, l1, 1698u, l3);
        } else {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            t0 = vader_emit_virt$refer((uint8_t) 1, l9);
            vader_array_t* _a18_arr = vader_array_new(221u, 1u, 13u, 1264u);
            ((void**) _a18_arr->buf->slots)[_a18_arr->offset + 0u] = t0;
            l3 = (void*) _a18_arr;
            vader_emit_virt$printed(l0, l1, 1698u, l3);
        }
    } else if (l2.tag == 973u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a19_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a19_arr->buf->slots)[_a19_arr->offset + 0u] = t0;
        l3 = (void*) _a19_arr;
        vader_emit_virt$printed(l0, l1, 1694u, l3);
    } else if (l2.tag == 981u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a20_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a20_arr->buf->slots)[_a20_arr->offset + 0u] = t0;
        l3 = (void*) _a20_arr;
        vader_emit_virt$printed(l0, l1, 1709u, l3);
    } else if (l2.tag == 982u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a21_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a21_arr->buf->slots)[_a21_arr->offset + 0u] = t0;
        l3 = (void*) _a21_arr;
        vader_emit_virt$printed(l0, l1, 1710u, l3);
    } else if (l2.tag == 980u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a22_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a22_arr->buf->slots)[_a22_arr->offset + 0u] = t0;
        l3 = (void*) _a22_arr;
        vader_emit_virt$printed(l0, l1, 1707u, l3);
    } else if (l2.tag == 979u) {
        std_string__builder$append(l0, 1704u);
    } else if (l2.tag == 977u) {
        std_string__builder$append(l0, 1699u);
    } else if (l2.tag == 972u) {
        std_string__builder$append(l0, 1686u);
    } else if (l2.tag == 978u) {
        std_string__builder$append(l0, 1702u);
    } else if (l2.tag == 971u) {
        std_string__builder$append(l0, 1684u);
    } else if (l2.tag == 1026u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        l3 = vader_emit_virt$refer((uint8_t) 5, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a23_arr = vader_array_new(221u, 2u, 13u, 1264u);
        ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 1u] = l10;
        ((void**) _a23_arr->buf->slots)[_a23_arr->offset + 0u] = l3;
        l3 = (void*) _a23_arr;
        vader_emit_virt$printed(l0, l1, 1943u, l3);
    } else if (l2.tag == 1049u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a24_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a24_arr->buf->slots)[_a24_arr->offset + 0u] = t0;
        l3 = (void*) _a24_arr;
        vader_emit_virt$printed(l0, l1, 2202u, l3);
    } else if (l2.tag == 1050u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a25_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a25_arr->buf->slots)[_a25_arr->offset + 0u] = t0;
        l3 = (void*) _a25_arr;
        vader_emit_virt$printed(l0, l1, 2203u, l3);
    } else if (l2.tag == 1130u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a26_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a26_arr->buf->slots)[_a26_arr->offset + 0u] = t0;
        l3 = (void*) _a26_arr;
        vader_emit_virt$printed(l0, l1, 2972u, l3);
    } else if (l2.tag == 1129u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a27_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a27_arr->buf->slots)[_a27_arr->offset + 0u] = t0;
        l3 = (void*) _a27_arr;
        vader_emit_virt$printed(l0, l1, 2975u, l3);
    } else if (l2.tag == 1108u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a28_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a28_arr->buf->slots)[_a28_arr->offset + 0u] = t0;
        l3 = (void*) _a28_arr;
        vader_emit_virt$printed(l0, l1, 2671u, l3);
    } else if (l2.tag == 1111u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a29_arr = vader_array_new(221u, 1u, 13u, 1264u);
        ((void**) _a29_arr->buf->slots)[_a29_arr->offset + 0u] = t0;
        l3 = (void*) _a29_arr;
        vader_emit_virt$printed(l0, l1, 2691u, l3);
    } else if (l2.tag == 1145u) {
        std_string__builder$append(l0, 3044u);
    } else if (l2.tag == 1025u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        t0 = l2.payload.obj;
        l14 = vader_emit_virt$convert_target_name(((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target);
        l6 = concat_3(l6, 480u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1114u) {
        std_string__builder$append(l0, 2335u);
    } else if (l2.tag == 1051u) {
        std_string__builder$append(l0, 2222u);
    } else if (l2.tag == 1070u) {
        std_string__builder$append(l0, 2242u);
    } else if (l2.tag == 1064u) {
        std_string__builder$append(l0, 2236u);
    } else if (l2.tag == 1057u) {
        std_string__builder$append(l0, 2228u);
    } else if (l2.tag == 1063u) {
        std_string__builder$append(l0, 2239u);
    } else if (l2.tag == 1066u) {
        std_string__builder$append(l0, 2238u);
    } else if (l2.tag == 1053u) {
        std_string__builder$append(l0, 2224u);
    } else if (l2.tag == 1052u) {
        std_string__builder$append(l0, 2223u);
    } else if (l2.tag == 1054u) {
        std_string__builder$append(l0, 2225u);
    } else if (l2.tag == 1055u) {
        std_string__builder$append(l0, 2226u);
    } else if (l2.tag == 1067u) {
        std_string__builder$append(l0, 2240u);
    } else if (l2.tag == 1068u) {
        std_string__builder$append(l0, 2241u);
    } else if (l2.tag == 1069u) {
        std_string__builder$append(l0, 3003u);
    } else if (l2.tag == 1058u) {
        std_string__builder$append(l0, 2230u);
    } else if (l2.tag == 1065u) {
        std_string__builder$append(l0, 2237u);
    } else if (l2.tag == 1062u) {
        std_string__builder$append(l0, 2234u);
    } else if (l2.tag == 1061u) {
        std_string__builder$append(l0, 2233u);
    } else if (l2.tag == 1060u) {
        std_string__builder$append(l0, 2232u);
    } else if (l2.tag == 1059u) {
        std_string__builder$append(l0, 2231u);
    } else if (l2.tag == 1071u) {
        std_string__builder$append(l0, 2244u);
    } else if (l2.tag == 1090u) {
        std_string__builder$append(l0, 2264u);
    } else if (l2.tag == 1084u) {
        std_string__builder$append(l0, 2257u);
    } else if (l2.tag == 1077u) {
        std_string__builder$append(l0, 2250u);
    } else if (l2.tag == 1083u) {
        std_string__builder$append(l0, 2260u);
    } else if (l2.tag == 1086u) {
        std_string__builder$append(l0, 2259u);
    } else if (l2.tag == 1072u) {
        std_string__builder$append(l0, 2245u);
    } else if (l2.tag == 1074u) {
        std_string__builder$append(l0, 2247u);
    } else if (l2.tag == 1075u) {
        std_string__builder$append(l0, 2248u);
    } else if (l2.tag == 1073u) {
        std_string__builder$append(l0, 2246u);
    } else if (l2.tag == 1087u) {
        std_string__builder$append(l0, 2262u);
    } else if (l2.tag == 1088u) {
        std_string__builder$append(l0, 2263u);
    } else if (l2.tag == 1089u) {
        std_string__builder$append(l0, 3013u);
    } else if (l2.tag == 1078u) {
        std_string__builder$append(l0, 2252u);
    } else if (l2.tag == 1085u) {
        std_string__builder$append(l0, 2258u);
    } else if (l2.tag == 1082u) {
        std_string__builder$append(l0, 2256u);
    } else if (l2.tag == 1081u) {
        std_string__builder$append(l0, 2255u);
    } else if (l2.tag == 1080u) {
        std_string__builder$append(l0, 2254u);
    } else if (l2.tag == 1079u) {
        std_string__builder$append(l0, 2253u);
    } else if (l2.tag == 1131u) {
        std_string__builder$append(l0, 2995u);
    } else if (l2.tag == 1136u) {
        std_string__builder$append(l0, 3001u);
    } else if (l2.tag == 1135u) {
        std_string__builder$append(l0, 3000u);
    } else if (l2.tag == 1134u) {
        std_string__builder$append(l0, 2999u);
    } else if (l2.tag == 1133u) {
        std_string__builder$append(l0, 2998u);
    } else if (l2.tag == 1132u) {
        std_string__builder$append(l0, 2997u);
    } else if (l2.tag == 1137u) {
        std_string__builder$append(l0, 3005u);
    } else if (l2.tag == 1142u) {
        std_string__builder$append(l0, 3011u);
    } else if (l2.tag == 1141u) {
        std_string__builder$append(l0, 3010u);
    } else if (l2.tag == 1140u) {
        std_string__builder$append(l0, 3009u);
    } else if (l2.tag == 1139u) {
        std_string__builder$append(l0, 3008u);
    } else if (l2.tag == 1138u) {
        std_string__builder$append(l0, 3007u);
    } else if (l2.tag == 1034u) {
        std_string__builder$append(l0, 2095u);
    } else if (l2.tag == 1045u) {
        std_string__builder$append(l0, 2106u);
    } else if (l2.tag == 1042u) {
        std_string__builder$append(l0, 2103u);
    } else if (l2.tag == 1036u) {
        std_string__builder$append(l0, 2097u);
    } else if (l2.tag == 1044u) {
        std_string__builder$append(l0, 2105u);
    } else if (l2.tag == 1037u) {
        std_string__builder$append(l0, 2098u);
    } else if (l2.tag == 1043u) {
        std_string__builder$append(l0, 2104u);
    } else if (l2.tag == 1041u) {
        std_string__builder$append(l0, 2102u);
    } else if (l2.tag == 1040u) {
        std_string__builder$append(l0, 2101u);
    } else if (l2.tag == 1039u) {
        std_string__builder$append(l0, 2100u);
    } else if (l2.tag == 1038u) {
        std_string__builder$append(l0, 2099u);
    } else if (l2.tag == 1008u) {
        std_string__builder$append(l0, 1748u);
    } else if (l2.tag == 1009u) {
        std_string__builder$append(l0, 1749u);
    } else if (l2.tag == 1006u) {
        std_string__builder$append(l0, 1746u);
    } else if (l2.tag == 1011u) {
        std_string__builder$append(l0, 1751u);
    } else if (l2.tag == 1124u) {
        std_string__builder$append(l0, 2852u);
    } else if (l2.tag == 1125u) {
        std_string__builder$append(l0, 2854u);
    } else if (l2.tag == 1122u) {
        std_string__builder$append(l0, 2850u);
    } else if (l2.tag == 1109u) {
        std_string__builder$append(l0, 2672u);
    } else if (l2.tag == 1110u) {
        std_string__builder$append(l0, 2673u);
    } else if (l2.tag == 1029u) {
        std_string__builder$append(l0, 1961u);
    } else if (l2.tag == 1028u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(35));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1959u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$DeferPopExec_t*) t0)->f_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1014u) {
        std_string__builder$append(l0, 1767u);
    } else if (l2.tag == 1099u) {
        std_string__builder$append(l0, 2431u);
    } else if (l2.tag == 1094u) {
        std_string__builder$append(l0, 2425u);
    } else if (l2.tag == 1095u) {
        std_string__builder$append(l0, 2426u);
    } else if (l2.tag == 1093u) {
        std_string__builder$append(l0, 2424u);
    } else if (l2.tag == 1121u) {
        std_string__builder$append(l0, 2845u);
    } else if (l2.tag == 1116u) {
        std_string__builder$append(l0, 2838u);
    } else if (l2.tag == 1117u) {
        std_string__builder$append(l0, 2839u);
    } else if (l2.tag == 1115u) {
        std_string__builder$append(l0, 2836u);
    } else if (l2.tag == 1097u) {
        std_string__builder$append(l0, 2429u);
    } else if (l2.tag == 1098u) {
        std_string__builder$append(l0, 2430u);
    } else if (l2.tag == 1096u) {
        std_string__builder$append(l0, 2428u);
    } else if (l2.tag == 1119u) {
        std_string__builder$append(l0, 2843u);
    } else if (l2.tag == 1120u) {
        std_string__builder$append(l0, 2844u);
    } else if (l2.tag == 1118u) {
        std_string__builder$append(l0, 2842u);
    } else if (l2.tag == 1106u) {
        std_string__builder$append(l0, 2487u);
    } else if (l2.tag == 1015u) {
        std_string__builder$append(l0, 1770u);
    } else if (l2.tag == 1016u) {
        std_string__builder$append(l0, 1773u);
    } else if (l2.tag == 1046u) {
        std_string__builder$append(l0, 2107u);
    } else if (l2.tag == 1004u) {
        std_string__builder$append(l0, 1742u);
    } else if (l2.tag == 1033u) {
        std_string__builder$append(l0, 2093u);
    } else {
        if (!(l2.tag == 1003u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string__builder$append(l0, 1741u);
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
        t1 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) INT32_C(0), 504u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string__builder$append_char(l0, 40u);
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l1)->length;
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            std_string__builder$append(l0, 384u);
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l3, 504u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append_char(l0, 41u);
    { vader_gc_top = gc_frame.prev; return; }
}
