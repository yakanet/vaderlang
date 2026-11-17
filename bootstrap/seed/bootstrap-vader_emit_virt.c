#include "bootstrap.split.h"

static vader_string_t vader_emit_virt$bounds_safe_word(bool l0);
static vader_string_t vader_emit_virt$convert_target_name(uint8_t l0);
static vader_string_t vader_emit_virt$f64_const_operands(double l0);
static void vader_emit_virt$printed(void* l0, void* l1, vader_string_t l2, void* l3);
static vader_string_t vader_emit_virt$quote_string(vader_string_t l0);
static vader_string_t vader_emit_virt$reason_word(vader_string_t l0);
static void* vader_emit_virt$refer(uint8_t l0, int32_t l1);
static void* vader_emit_virt$refer_field(int32_t l0, int32_t l1);
static void vader_emit_virt$write_op_refs(void* l0, void* l1, vader_box_t l2);
static void vader_emit_virt$write_results(void* l0, void* l1);

static vader_string_t vader_emit_virt$bounds_safe_word(bool l0) {
    if (l0) {
        return 243u;
    }
    return 0u;
}

static vader_string_t vader_emit_virt$convert_target_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2405u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2427u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2274u;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2045u;
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
    l2 = vader_host_std_core$Intrinsic$byte_len(l1);
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
    l5 = vader_array_length(((vader_array_t*) l4));
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l6);
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

static vader_string_t vader_emit_virt$quote_string(vader_string_t l0) {
    void* l1 = NULL;
    int64_t l2, l3, l5;
    uint8_t l4;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 536u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 952u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string__builder$append(l1, 290u);
    l2 = vader_host_std_core$Intrinsic$byte_len(l0);
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        l4 = vader_host_std_core$Intrinsic$byte_at(l0, l3);
        if (l4 == INT32_C(92)) {
            std_string__builder$append(l1, 1142u);
        } else if (l4 == INT32_C(34)) {
            std_string__builder$append(l1, 1139u);
        } else if (l4 == INT32_C(10)) {
            std_string__builder$append(l1, 1143u);
        } else if (l4 == INT32_C(13)) {
            std_string__builder$append(l1, 1144u);
        } else if (l4 == INT32_C(9)) {
            std_string__builder$append(l1, 1145u);
        } else if (l4 == INT32_C(0)) {
            std_string__builder$append(l1, 1141u);
        } else {
            l5 = vader_chk_add(i64, l3, INT64_C(1));
            l6 = vader_host_std_core$Intrinsic$byte_slice(l0, l3, l5);
            std_string__builder$append(l1, l6);
        }
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append(l1, 290u);
    t1 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_virt$reason_word(vader_string_t l0) {
    vader_string_t l1 = 0;
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == 0u) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    l1 = vader_emit_virt$quote_string(l0);
    t0 = concat_2(14u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_virt$refer(uint8_t l0, int32_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_virt$OperandRef_t* _a0_obj = (vader_struct_vader_emit_virt$OperandRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_virt$OperandRef_t));
    vader_obj_header_init(_a0_obj, 1379u);
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
    vader_obj_header_init(_a0_obj, 1379u);
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
    vader_array_t* _a0_arr = vader_array_new(414u, 0u, 13u, 1948u);
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
    if (l2.tag == 1163u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2411u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 1183u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2433u);
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1142u) {
        t0 = l2.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        l6 = vader_emit_virt$f64_const_operands(t2);
        l6 = concat_2(2276u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1114u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(16));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1914u);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        l4 = std_core$write_bool(l3, l4, l7);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1129u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2047u);
        t0 = l2.payload.obj;
        t3 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        t4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        l8 = (uint64_t) (int64_t) t4;
        l4 = std_core$write_unsigned(l3, l4, l8);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1215u) {
        std_string__builder$append(l0, 2739u);
    } else if (l2.tag == 1231u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StringConst_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 3, l9);
        vader_array_t* _a0_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0;
        l3 = (void*) _a0_arr;
        vader_emit_virt$printed(l0, l1, 2957u, l3);
    } else if (l2.tag == 1208u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a1_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0;
        l3 = (void*) _a1_arr;
        vader_emit_virt$printed(l0, l1, 2597u, l3);
    } else if (l2.tag == 1209u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a2_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0;
        l3 = (void*) _a2_arr;
        vader_emit_virt$printed(l0, l1, 2598u, l3);
    } else if (l2.tag == 1210u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a3_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = t0;
        l3 = (void*) _a3_arr;
        vader_emit_virt$printed(l0, l1, 2599u, l3);
    } else if (l2.tag == 1207u) {
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
        vader_array_t* _a4_arr = vader_array_new(242u, 3u, 13u, 1379u);
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 2u] = l12;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l10;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l3;
        l3 = (void*) _a4_arr;
        vader_emit_virt$printed(l0, l1, 2596u, l3);
    } else if (l2.tag == 1220u) {
        std_string__builder$append(l0, 2847u);
    } else if (l2.tag == 1221u) {
        std_string__builder$append(l0, 2851u);
        vader_array_push_ref((vader_array_t*) l1, vader_box_obj(0u, NULL).payload.obj);
        t0 = l2.payload.obj;
        l13 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value;
        vader_emit_virt$write_op_refs(l0, l1, l13);
    } else if (l2.tag == 1137u) {
        std_string__builder$append(l0, 2156u);
    } else if (l2.tag == 1126u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a5_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = t0;
        l3 = (void*) _a5_arr;
        vader_emit_virt$printed(l0, l1, 1999u, l3);
    } else if (l2.tag == 1127u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 4, l9);
        vader_array_t* _a6_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = t0;
        l3 = (void*) _a6_arr;
        vader_emit_virt$printed(l0, l1, 2002u, l3);
    } else if (l2.tag == 1128u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a7_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t0;
        l3 = (void*) _a7_arr;
        vader_emit_virt$printed(l0, l1, 2003u, l3);
    } else if (l2.tag == 1254u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_parameter_count;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_vtable_key;
        l4 = vader_host_std_core$Intrinsic$byte_len(l6);
        l3 = (void*) vader_buffer_new((size_t) (INT64_C(38) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 3361u);
        l5 = ((int64_t) (int32_t) l9);
        l4 = std_core$write_int(l3, l4, l5);
        l4 = std_core$write_string_at(l3, l4, 14u);
        l4 = std_core$write_string_at(l3, l4, l6);
        l4 = std_core$write_string_at(l3, l4, 75u);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
        t0 = l2.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_results;
        vader_emit_virt$write_results(l0, l3);
    } else if (l2.tag == 1155u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a8_arr = vader_array_new(242u, 2u, 13u, 1379u);
        ((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 1u] = l10;
        ((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = l3;
        l3 = (void*) _a8_arr;
        vader_emit_virt$printed(l0, l1, 2335u, l3);
    } else if (l2.tag == 1154u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a9_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a9_arr->buf->slots)[vader_array_offset(_a9_arr) + 0u] = t0;
        l3 = (void*) _a9_arr;
        vader_emit_virt$printed(l0, l1, 2333u, l3);
    } else if (l2.tag == 1130u) {
        t0 = l2.payload.obj;
        l6 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        t0 = l2.payload.obj;
        l14 = vader_core_bytecode$checked_op_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_op);
        l6 = concat_3(l6, 466u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1131u) {
        t0 = l2.payload.obj;
        t5 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
        l6 = concat_2(t5, 467u);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1212u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a10_arr = vader_array_new(242u, 2u, 13u, 1379u);
        ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 1u] = l10;
        ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_emit_virt$printed(l0, l1, 2624u, l3);
    } else if (l2.tag == 1198u) {
        std_string__builder$append(l0, 2454u);
    } else if (l2.tag == 1138u) {
        std_string__builder$append(l0, 2171u);
    } else if (l2.tag == 1139u) {
        std_string__builder$append(l0, 2189u);
    } else if (l2.tag == 1112u) {
        std_string__builder$append(l0, 1911u);
    } else if (l2.tag == 1211u) {
        std_string__builder$append(l0, 2602u);
    } else if (l2.tag == 1119u) {
        std_string__builder$append(l0, 1922u);
    } else if (l2.tag == 1120u) {
        std_string__builder$append(l0, 1924u);
    } else if (l2.tag == 1117u) {
        std_string__builder$append(l0, 1917u);
    } else if (l2.tag == 1235u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_stack;
        if (t6) {
            l6 = 2979u;
        } else {
            l6 = 2976u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a11_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = t0;
        l3 = (void*) _a11_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 1234u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a12_arr = vader_array_new(242u, 2u, 13u, 1379u);
        ((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 1u] = l10;
        ((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 0u] = l3;
        l3 = (void*) _a12_arr;
        vader_emit_virt$printed(l0, l1, 2975u, l3);
    } else if (l2.tag == 1236u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_stack;
        if (t6) {
            l6 = 2984u;
        } else {
            l6 = 2980u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a13_arr = vader_array_new(242u, 2u, 13u, 1379u);
        ((void**) _a13_arr->buf->slots)[vader_array_offset(_a13_arr) + 1u] = l10;
        ((void**) _a13_arr->buf->slots)[vader_array_offset(_a13_arr) + 0u] = l3;
        l3 = (void*) _a13_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 1251u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a14_arr = vader_array_new(242u, 2u, 13u, 1379u);
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 1u] = l10;
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = l3;
        l3 = (void*) _a14_arr;
        vader_emit_virt$printed(l0, l1, 3149u, l3);
    } else if (l2.tag == 1252u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a15_arr = vader_array_new(242u, 2u, 13u, 1379u);
        ((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 1u] = l10;
        ((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 0u] = l3;
        l3 = (void*) _a15_arr;
        vader_emit_virt$printed(l0, l1, 3150u, l3);
    } else if (l2.tag == 1082u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a16_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a16_arr->buf->slots)[vader_array_offset(_a16_arr) + 0u] = t0;
        l3 = (void*) _a16_arr;
        vader_emit_virt$printed(l0, l1, 1860u, l3);
        l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 14u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1081u) {
        std_string__builder$append(l0, 1859u);
    } else if (l2.tag == 1083u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            l3 = vader_emit_virt$refer((uint8_t) 1, l9);
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
            l10 = vader_emit_virt$refer((uint8_t) 6, l9);
            vader_array_t* _a17_arr = vader_array_new(242u, 2u, 13u, 1379u);
            ((void**) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 1u] = l10;
            ((void**) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 0u] = l3;
            l3 = (void*) _a17_arr;
            vader_emit_virt$printed(l0, l1, 1862u, l3);
        } else {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            t0 = vader_emit_virt$refer((uint8_t) 1, l9);
            vader_array_t* _a18_arr = vader_array_new(242u, 1u, 13u, 1379u);
            ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 0u] = t0;
            l3 = (void*) _a18_arr;
            vader_emit_virt$printed(l0, l1, 1862u, l3);
        }
    } else if (l2.tag == 1080u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a19_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 0u] = t0;
        l3 = (void*) _a19_arr;
        vader_emit_virt$printed(l0, l1, 1858u, l3);
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1088u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a20_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a20_arr->buf->slots)[vader_array_offset(_a20_arr) + 0u] = t0;
        l3 = (void*) _a20_arr;
        vader_emit_virt$printed(l0, l1, 1873u, l3);
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1089u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a21_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a21_arr->buf->slots)[vader_array_offset(_a21_arr) + 0u] = t0;
        l3 = (void*) _a21_arr;
        vader_emit_virt$printed(l0, l1, 1874u, l3);
    } else if (l2.tag == 1087u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a22_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a22_arr->buf->slots)[vader_array_offset(_a22_arr) + 0u] = t0;
        l3 = (void*) _a22_arr;
        vader_emit_virt$printed(l0, l1, 1871u, l3);
    } else if (l2.tag == 1086u) {
        std_string__builder$append(l0, 1868u);
    } else if (l2.tag == 1084u) {
        std_string__builder$append(l0, 1863u);
    } else if (l2.tag == 1079u) {
        std_string__builder$append(l0, 1850u);
    } else if (l2.tag == 1085u) {
        std_string__builder$append(l0, 1866u);
    } else if (l2.tag == 1078u) {
        std_string__builder$append(l0, 1848u);
    } else if (l2.tag == 1133u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        l3 = vader_emit_virt$refer((uint8_t) 5, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a23_arr = vader_array_new(242u, 2u, 13u, 1379u);
        ((void**) _a23_arr->buf->slots)[vader_array_offset(_a23_arr) + 1u] = l10;
        ((void**) _a23_arr->buf->slots)[vader_array_offset(_a23_arr) + 0u] = l3;
        l3 = (void*) _a23_arr;
        vader_emit_virt$printed(l0, l1, 2122u, l3);
    } else if (l2.tag == 1156u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a24_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a24_arr->buf->slots)[vader_array_offset(_a24_arr) + 0u] = t0;
        l3 = (void*) _a24_arr;
        vader_emit_virt$printed(l0, l1, 2386u, l3);
    } else if (l2.tag == 1157u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a25_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a25_arr->buf->slots)[vader_array_offset(_a25_arr) + 0u] = t0;
        l3 = (void*) _a25_arr;
        vader_emit_virt$printed(l0, l1, 2387u, l3);
    } else if (l2.tag == 1238u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a26_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a26_arr->buf->slots)[vader_array_offset(_a26_arr) + 0u] = t0;
        l3 = (void*) _a26_arr;
        vader_emit_virt$printed(l0, l1, 3092u, l3);
    } else if (l2.tag == 1237u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a27_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a27_arr->buf->slots)[vader_array_offset(_a27_arr) + 0u] = t0;
        l3 = (void*) _a27_arr;
        vader_emit_virt$printed(l0, l1, 3095u, l3);
    } else if (l2.tag == 1216u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a28_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a28_arr->buf->slots)[vader_array_offset(_a28_arr) + 0u] = t0;
        l3 = (void*) _a28_arr;
        vader_emit_virt$printed(l0, l1, 2824u, l3);
    } else if (l2.tag == 1219u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a29_arr = vader_array_new(242u, 1u, 13u, 1379u);
        ((void**) _a29_arr->buf->slots)[vader_array_offset(_a29_arr) + 0u] = t0;
        l3 = (void*) _a29_arr;
        vader_emit_virt$printed(l0, l1, 2844u, l3);
    } else if (l2.tag == 1253u) {
        t0 = l2.payload.obj;
        t5 = ((vader_struct_vader_core_bytecode$Unreachable_t*) t0)->f_reason;
        l6 = vader_emit_virt$reason_word(t5);
        l6 = concat_2(3164u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1132u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        t0 = l2.payload.obj;
        l14 = vader_emit_virt$convert_target_name(((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target);
        l6 = concat_3(l6, 492u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1222u) {
        std_string__builder$append(l0, 2518u);
    } else if (l2.tag == 1158u) {
        std_string__builder$append(l0, 2406u);
    } else if (l2.tag == 1177u) {
        std_string__builder$append(l0, 2426u);
    } else if (l2.tag == 1171u) {
        std_string__builder$append(l0, 2420u);
    } else if (l2.tag == 1164u) {
        std_string__builder$append(l0, 2412u);
    } else if (l2.tag == 1170u) {
        std_string__builder$append(l0, 2423u);
    } else if (l2.tag == 1173u) {
        std_string__builder$append(l0, 2422u);
    } else if (l2.tag == 1160u) {
        std_string__builder$append(l0, 2408u);
    } else if (l2.tag == 1159u) {
        std_string__builder$append(l0, 2407u);
    } else if (l2.tag == 1161u) {
        std_string__builder$append(l0, 2409u);
    } else if (l2.tag == 1162u) {
        std_string__builder$append(l0, 2410u);
    } else if (l2.tag == 1174u) {
        std_string__builder$append(l0, 2424u);
    } else if (l2.tag == 1175u) {
        std_string__builder$append(l0, 2425u);
    } else if (l2.tag == 1176u) {
        std_string__builder$append(l0, 3123u);
    } else if (l2.tag == 1165u) {
        std_string__builder$append(l0, 2414u);
    } else if (l2.tag == 1172u) {
        std_string__builder$append(l0, 2421u);
    } else if (l2.tag == 1169u) {
        std_string__builder$append(l0, 2418u);
    } else if (l2.tag == 1168u) {
        std_string__builder$append(l0, 2417u);
    } else if (l2.tag == 1167u) {
        std_string__builder$append(l0, 2416u);
    } else if (l2.tag == 1166u) {
        std_string__builder$append(l0, 2415u);
    } else if (l2.tag == 1178u) {
        std_string__builder$append(l0, 2428u);
    } else if (l2.tag == 1197u) {
        std_string__builder$append(l0, 2448u);
    } else if (l2.tag == 1191u) {
        std_string__builder$append(l0, 2441u);
    } else if (l2.tag == 1184u) {
        std_string__builder$append(l0, 2434u);
    } else if (l2.tag == 1190u) {
        std_string__builder$append(l0, 2444u);
    } else if (l2.tag == 1193u) {
        std_string__builder$append(l0, 2443u);
    } else if (l2.tag == 1179u) {
        std_string__builder$append(l0, 2429u);
    } else if (l2.tag == 1181u) {
        std_string__builder$append(l0, 2431u);
    } else if (l2.tag == 1182u) {
        std_string__builder$append(l0, 2432u);
    } else if (l2.tag == 1180u) {
        std_string__builder$append(l0, 2430u);
    } else if (l2.tag == 1194u) {
        std_string__builder$append(l0, 2446u);
    } else if (l2.tag == 1195u) {
        std_string__builder$append(l0, 2447u);
    } else if (l2.tag == 1196u) {
        std_string__builder$append(l0, 3133u);
    } else if (l2.tag == 1185u) {
        std_string__builder$append(l0, 2436u);
    } else if (l2.tag == 1192u) {
        std_string__builder$append(l0, 2442u);
    } else if (l2.tag == 1189u) {
        std_string__builder$append(l0, 2440u);
    } else if (l2.tag == 1188u) {
        std_string__builder$append(l0, 2439u);
    } else if (l2.tag == 1187u) {
        std_string__builder$append(l0, 2438u);
    } else if (l2.tag == 1186u) {
        std_string__builder$append(l0, 2437u);
    } else if (l2.tag == 1239u) {
        std_string__builder$append(l0, 3115u);
    } else if (l2.tag == 1244u) {
        std_string__builder$append(l0, 3121u);
    } else if (l2.tag == 1243u) {
        std_string__builder$append(l0, 3120u);
    } else if (l2.tag == 1242u) {
        std_string__builder$append(l0, 3119u);
    } else if (l2.tag == 1241u) {
        std_string__builder$append(l0, 3118u);
    } else if (l2.tag == 1240u) {
        std_string__builder$append(l0, 3117u);
    } else if (l2.tag == 1245u) {
        std_string__builder$append(l0, 3125u);
    } else if (l2.tag == 1250u) {
        std_string__builder$append(l0, 3131u);
    } else if (l2.tag == 1249u) {
        std_string__builder$append(l0, 3130u);
    } else if (l2.tag == 1248u) {
        std_string__builder$append(l0, 3129u);
    } else if (l2.tag == 1247u) {
        std_string__builder$append(l0, 3128u);
    } else if (l2.tag == 1246u) {
        std_string__builder$append(l0, 3127u);
    } else if (l2.tag == 1141u) {
        std_string__builder$append(l0, 2275u);
    } else if (l2.tag == 1152u) {
        std_string__builder$append(l0, 2286u);
    } else if (l2.tag == 1149u) {
        std_string__builder$append(l0, 2283u);
    } else if (l2.tag == 1143u) {
        std_string__builder$append(l0, 2277u);
    } else if (l2.tag == 1151u) {
        std_string__builder$append(l0, 2285u);
    } else if (l2.tag == 1144u) {
        std_string__builder$append(l0, 2278u);
    } else if (l2.tag == 1150u) {
        std_string__builder$append(l0, 2284u);
    } else if (l2.tag == 1148u) {
        std_string__builder$append(l0, 2282u);
    } else if (l2.tag == 1147u) {
        std_string__builder$append(l0, 2281u);
    } else if (l2.tag == 1146u) {
        std_string__builder$append(l0, 2280u);
    } else if (l2.tag == 1145u) {
        std_string__builder$append(l0, 2279u);
    } else if (l2.tag == 1115u) {
        std_string__builder$append(l0, 1915u);
    } else if (l2.tag == 1116u) {
        std_string__builder$append(l0, 1916u);
    } else if (l2.tag == 1113u) {
        std_string__builder$append(l0, 1913u);
    } else if (l2.tag == 1118u) {
        std_string__builder$append(l0, 1918u);
    } else if (l2.tag == 1232u) {
        std_string__builder$append(l0, 2958u);
    } else if (l2.tag == 1233u) {
        std_string__builder$append(l0, 2960u);
    } else if (l2.tag == 1230u) {
        std_string__builder$append(l0, 2956u);
    } else if (l2.tag == 1217u) {
        std_string__builder$append(l0, 2825u);
    } else if (l2.tag == 1218u) {
        std_string__builder$append(l0, 2826u);
    } else if (l2.tag == 1136u) {
        std_string__builder$append(l0, 2142u);
    } else if (l2.tag == 1135u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(35));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2140u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$DeferPopExec_t*) t0)->f_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1121u) {
        std_string__builder$append(l0, 1934u);
    } else if (l2.tag == 1206u) {
        std_string__builder$append(l0, 2591u);
    } else if (l2.tag == 1201u) {
        std_string__builder$append(l0, 2585u);
    } else if (l2.tag == 1202u) {
        std_string__builder$append(l0, 2586u);
    } else if (l2.tag == 1200u) {
        std_string__builder$append(l0, 2584u);
    } else if (l2.tag == 1229u) {
        std_string__builder$append(l0, 2951u);
    } else if (l2.tag == 1224u) {
        std_string__builder$append(l0, 2944u);
    } else if (l2.tag == 1225u) {
        std_string__builder$append(l0, 2945u);
    } else if (l2.tag == 1223u) {
        std_string__builder$append(l0, 2942u);
    } else if (l2.tag == 1204u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$LoadSlotI32_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(2589u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1205u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$LoadSlotI64_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(2590u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1203u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$LoadSlotF64_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(2588u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1227u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StoreSlotI32_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(2949u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1228u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StoreSlotI64_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(2950u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1226u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StoreSlotF64_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(2948u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1214u) {
        std_string__builder$append(l0, 2646u);
    } else if (l2.tag == 1122u) {
        std_string__builder$append(l0, 1941u);
    } else if (l2.tag == 1123u) {
        std_string__builder$append(l0, 1944u);
    } else if (l2.tag == 1153u) {
        std_string__builder$append(l0, 2287u);
    } else if (l2.tag == 1111u) {
        std_string__builder$append(l0, 1909u);
    } else if (l2.tag == 1140u) {
        std_string__builder$append(l0, 2273u);
    } else {
        if (!(l2.tag == 1110u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string__builder$append(l0, 1908u);
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
    t0 = vader_array_length(((vader_array_t*) l1));
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0), 541u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string__builder$append_char(l0, 40u);
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l1));
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            std_string__builder$append(l0, 405u);
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l3, 541u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append_char(l0, 41u);
    { vader_gc_top = gc_frame.prev; return; }
}
