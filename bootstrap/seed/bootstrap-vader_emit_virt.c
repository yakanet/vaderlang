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
        return 255u;
    }
    return 0u;
}

static vader_string_t vader_emit_virt$convert_target_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2521u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2543u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2379u;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2139u;
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
    l2 = std_core$write_string_at(l3, l2, 16u);
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
        l9 = std_core$write_string_at(l8, l9, 16u);
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
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 576u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1010u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string__builder$append(l1, 303u);
    l2 = vader_host_std_core$Intrinsic$byte_len(l0);
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        l4 = vader_host_std_core$Intrinsic$byte_at(l0, l3);
        if (l4 == INT32_C(92)) {
            std_string__builder$append(l1, 1187u);
        } else if (l4 == INT32_C(34)) {
            std_string__builder$append(l1, 1184u);
        } else if (l4 == INT32_C(10)) {
            std_string__builder$append(l1, 1188u);
        } else if (l4 == INT32_C(13)) {
            std_string__builder$append(l1, 1189u);
        } else if (l4 == INT32_C(9)) {
            std_string__builder$append(l1, 1190u);
        } else if (l4 == INT32_C(0)) {
            std_string__builder$append(l1, 1186u);
        } else {
            l5 = vader_chk_add(i64, l3, INT64_C(1));
            l6 = vader_host_std_core$Intrinsic$byte_slice(l0, l3, l5);
            std_string__builder$append(l1, l6);
        }
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append(l1, 303u);
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
    t0 = concat_2(16u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_virt$refer(uint8_t l0, int32_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_virt$OperandRef_t* _a0_obj = (vader_struct_vader_emit_virt$OperandRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_virt$OperandRef_t));
    vader_obj_header_init(_a0_obj, 1465u);
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
    vader_obj_header_init(_a0_obj, 1465u);
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
    vader_array_t* _a0_arr = vader_array_new(428u, 0u, 13u, 2052u);
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
    if (l2.tag == 1248u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2527u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 1268u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2549u);
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1227u) {
        t0 = l2.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        l6 = vader_emit_virt$f64_const_operands(t2);
        l6 = concat_2(2381u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1199u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(16));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2004u);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        l4 = std_core$write_bool(l3, l4, l7);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1214u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2141u);
        t0 = l2.payload.obj;
        t3 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        t4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        l8 = (uint64_t) (int64_t) t4;
        l4 = std_core$write_unsigned(l3, l4, l8);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1300u) {
        std_string__builder$append(l0, 2881u);
    } else if (l2.tag == 1316u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StringConst_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 3, l9);
        vader_array_t* _a0_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0;
        l3 = (void*) _a0_arr;
        vader_emit_virt$printed(l0, l1, 3095u, l3);
    } else if (l2.tag == 1293u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a1_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0;
        l3 = (void*) _a1_arr;
        vader_emit_virt$printed(l0, l1, 2730u, l3);
    } else if (l2.tag == 1294u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a2_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0;
        l3 = (void*) _a2_arr;
        vader_emit_virt$printed(l0, l1, 2731u, l3);
    } else if (l2.tag == 1295u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a3_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = t0;
        l3 = (void*) _a3_arr;
        vader_emit_virt$printed(l0, l1, 2732u, l3);
    } else if (l2.tag == 1292u) {
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
        vader_array_t* _a4_arr = vader_array_new(249u, 3u, 13u, 1465u);
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 2u] = l12;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l10;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l3;
        l3 = (void*) _a4_arr;
        vader_emit_virt$printed(l0, l1, 2729u, l3);
    } else if (l2.tag == 1305u) {
        std_string__builder$append(l0, 3001u);
    } else if (l2.tag == 1306u) {
        std_string__builder$append(l0, 3005u);
        vader_array_push_ref((vader_array_t*) l1, vader_box_obj(0u, NULL).payload.obj);
        t0 = l2.payload.obj;
        l13 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value;
        vader_emit_virt$write_op_refs(l0, l1, l13);
    } else if (l2.tag == 1222u) {
        std_string__builder$append(l0, 2258u);
    } else if (l2.tag == 1211u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a5_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = t0;
        l3 = (void*) _a5_arr;
        vader_emit_virt$printed(l0, l1, 2091u, l3);
    } else if (l2.tag == 1212u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 4, l9);
        vader_array_t* _a6_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = t0;
        l3 = (void*) _a6_arr;
        vader_emit_virt$printed(l0, l1, 2094u, l3);
    } else if (l2.tag == 1213u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a7_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t0;
        l3 = (void*) _a7_arr;
        vader_emit_virt$printed(l0, l1, 2095u, l3);
    } else if (l2.tag == 1339u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_parameter_count;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_vtable_key;
        l4 = vader_host_std_core$Intrinsic$byte_len(l6);
        l3 = (void*) vader_buffer_new((size_t) (INT64_C(38) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 3534u);
        l5 = ((int64_t) (int32_t) l9);
        l4 = std_core$write_int(l3, l4, l5);
        l4 = std_core$write_string_at(l3, l4, 16u);
        l4 = std_core$write_string_at(l3, l4, l6);
        l4 = std_core$write_string_at(l3, l4, 79u);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
        t0 = l2.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_results;
        vader_emit_virt$write_results(l0, l3);
    } else if (l2.tag == 1240u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a8_arr = vader_array_new(249u, 2u, 13u, 1465u);
        ((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 1u] = l10;
        ((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = l3;
        l3 = (void*) _a8_arr;
        vader_emit_virt$printed(l0, l1, 2440u, l3);
    } else if (l2.tag == 1239u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a9_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a9_arr->buf->slots)[vader_array_offset(_a9_arr) + 0u] = t0;
        l3 = (void*) _a9_arr;
        vader_emit_virt$printed(l0, l1, 2438u, l3);
    } else if (l2.tag == 1215u) {
        t0 = l2.payload.obj;
        l6 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        t0 = l2.payload.obj;
        l14 = vader_core_bytecode$checked_op_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_op);
        l6 = concat_3(l6, 483u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1216u) {
        t0 = l2.payload.obj;
        t5 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
        l6 = concat_2(t5, 484u);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1297u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a10_arr = vader_array_new(249u, 2u, 13u, 1465u);
        ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 1u] = l10;
        ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_emit_virt$printed(l0, l1, 2758u, l3);
    } else if (l2.tag == 1283u) {
        std_string__builder$append(l0, 2571u);
    } else if (l2.tag == 1223u) {
        std_string__builder$append(l0, 2274u);
    } else if (l2.tag == 1224u) {
        std_string__builder$append(l0, 2293u);
    } else if (l2.tag == 1197u) {
        std_string__builder$append(l0, 1998u);
    } else if (l2.tag == 1296u) {
        std_string__builder$append(l0, 2735u);
    } else if (l2.tag == 1204u) {
        std_string__builder$append(l0, 2012u);
    } else if (l2.tag == 1205u) {
        std_string__builder$append(l0, 2014u);
    } else if (l2.tag == 1202u) {
        std_string__builder$append(l0, 2007u);
    } else if (l2.tag == 1320u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_stack;
        if (t6) {
            l6 = 3117u;
        } else {
            l6 = 3114u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a11_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = t0;
        l3 = (void*) _a11_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 1319u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a12_arr = vader_array_new(249u, 2u, 13u, 1465u);
        ((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 1u] = l10;
        ((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 0u] = l3;
        l3 = (void*) _a12_arr;
        vader_emit_virt$printed(l0, l1, 3113u, l3);
    } else if (l2.tag == 1321u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_stack;
        if (t6) {
            l6 = 3122u;
        } else {
            l6 = 3118u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a13_arr = vader_array_new(249u, 2u, 13u, 1465u);
        ((void**) _a13_arr->buf->slots)[vader_array_offset(_a13_arr) + 1u] = l10;
        ((void**) _a13_arr->buf->slots)[vader_array_offset(_a13_arr) + 0u] = l3;
        l3 = (void*) _a13_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 1336u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a14_arr = vader_array_new(249u, 2u, 13u, 1465u);
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 1u] = l10;
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = l3;
        l3 = (void*) _a14_arr;
        vader_emit_virt$printed(l0, l1, 3309u, l3);
    } else if (l2.tag == 1337u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a15_arr = vader_array_new(249u, 2u, 13u, 1465u);
        ((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 1u] = l10;
        ((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 0u] = l3;
        l3 = (void*) _a15_arr;
        vader_emit_virt$printed(l0, l1, 3310u, l3);
    } else if (l2.tag == 1167u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a16_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a16_arr->buf->slots)[vader_array_offset(_a16_arr) + 0u] = t0;
        l3 = (void*) _a16_arr;
        vader_emit_virt$printed(l0, l1, 1944u, l3);
        l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 16u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1166u) {
        std_string__builder$append(l0, 1943u);
    } else if (l2.tag == 1168u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            l3 = vader_emit_virt$refer((uint8_t) 1, l9);
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
            l10 = vader_emit_virt$refer((uint8_t) 6, l9);
            vader_array_t* _a17_arr = vader_array_new(249u, 2u, 13u, 1465u);
            ((void**) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 1u] = l10;
            ((void**) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 0u] = l3;
            l3 = (void*) _a17_arr;
            vader_emit_virt$printed(l0, l1, 1946u, l3);
        } else {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            t0 = vader_emit_virt$refer((uint8_t) 1, l9);
            vader_array_t* _a18_arr = vader_array_new(249u, 1u, 13u, 1465u);
            ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 0u] = t0;
            l3 = (void*) _a18_arr;
            vader_emit_virt$printed(l0, l1, 1946u, l3);
        }
    } else if (l2.tag == 1165u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a19_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 0u] = t0;
        l3 = (void*) _a19_arr;
        vader_emit_virt$printed(l0, l1, 1942u, l3);
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1173u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a20_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a20_arr->buf->slots)[vader_array_offset(_a20_arr) + 0u] = t0;
        l3 = (void*) _a20_arr;
        vader_emit_virt$printed(l0, l1, 1957u, l3);
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1174u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a21_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a21_arr->buf->slots)[vader_array_offset(_a21_arr) + 0u] = t0;
        l3 = (void*) _a21_arr;
        vader_emit_virt$printed(l0, l1, 1958u, l3);
    } else if (l2.tag == 1172u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a22_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a22_arr->buf->slots)[vader_array_offset(_a22_arr) + 0u] = t0;
        l3 = (void*) _a22_arr;
        vader_emit_virt$printed(l0, l1, 1955u, l3);
    } else if (l2.tag == 1171u) {
        std_string__builder$append(l0, 1952u);
    } else if (l2.tag == 1169u) {
        std_string__builder$append(l0, 1947u);
    } else if (l2.tag == 1164u) {
        std_string__builder$append(l0, 1934u);
    } else if (l2.tag == 1170u) {
        std_string__builder$append(l0, 1950u);
    } else if (l2.tag == 1163u) {
        std_string__builder$append(l0, 1932u);
    } else if (l2.tag == 1218u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        l3 = vader_emit_virt$refer((uint8_t) 5, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a23_arr = vader_array_new(249u, 2u, 13u, 1465u);
        ((void**) _a23_arr->buf->slots)[vader_array_offset(_a23_arr) + 1u] = l10;
        ((void**) _a23_arr->buf->slots)[vader_array_offset(_a23_arr) + 0u] = l3;
        l3 = (void*) _a23_arr;
        vader_emit_virt$printed(l0, l1, 2219u, l3);
    } else if (l2.tag == 1241u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a24_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a24_arr->buf->slots)[vader_array_offset(_a24_arr) + 0u] = t0;
        l3 = (void*) _a24_arr;
        vader_emit_virt$printed(l0, l1, 2498u, l3);
    } else if (l2.tag == 1242u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a25_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a25_arr->buf->slots)[vader_array_offset(_a25_arr) + 0u] = t0;
        l3 = (void*) _a25_arr;
        vader_emit_virt$printed(l0, l1, 2499u, l3);
    } else if (l2.tag == 1323u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a26_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a26_arr->buf->slots)[vader_array_offset(_a26_arr) + 0u] = t0;
        l3 = (void*) _a26_arr;
        vader_emit_virt$printed(l0, l1, 3250u, l3);
    } else if (l2.tag == 1322u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a27_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a27_arr->buf->slots)[vader_array_offset(_a27_arr) + 0u] = t0;
        l3 = (void*) _a27_arr;
        vader_emit_virt$printed(l0, l1, 3253u, l3);
    } else if (l2.tag == 1301u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a28_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a28_arr->buf->slots)[vader_array_offset(_a28_arr) + 0u] = t0;
        l3 = (void*) _a28_arr;
        vader_emit_virt$printed(l0, l1, 2975u, l3);
    } else if (l2.tag == 1304u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a29_arr = vader_array_new(249u, 1u, 13u, 1465u);
        ((void**) _a29_arr->buf->slots)[vader_array_offset(_a29_arr) + 0u] = t0;
        l3 = (void*) _a29_arr;
        vader_emit_virt$printed(l0, l1, 2998u, l3);
    } else if (l2.tag == 1338u) {
        t0 = l2.payload.obj;
        t5 = ((vader_struct_vader_core_bytecode$Unreachable_t*) t0)->f_reason;
        l6 = vader_emit_virt$reason_word(t5);
        l6 = concat_2(3324u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1217u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        t0 = l2.payload.obj;
        l14 = vader_emit_virt$convert_target_name(((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target);
        l6 = concat_3(l6, 510u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1307u) {
        std_string__builder$append(l0, 2636u);
    } else if (l2.tag == 1243u) {
        std_string__builder$append(l0, 2522u);
    } else if (l2.tag == 1262u) {
        std_string__builder$append(l0, 2542u);
    } else if (l2.tag == 1256u) {
        std_string__builder$append(l0, 2536u);
    } else if (l2.tag == 1249u) {
        std_string__builder$append(l0, 2528u);
    } else if (l2.tag == 1255u) {
        std_string__builder$append(l0, 2539u);
    } else if (l2.tag == 1258u) {
        std_string__builder$append(l0, 2538u);
    } else if (l2.tag == 1245u) {
        std_string__builder$append(l0, 2524u);
    } else if (l2.tag == 1244u) {
        std_string__builder$append(l0, 2523u);
    } else if (l2.tag == 1246u) {
        std_string__builder$append(l0, 2525u);
    } else if (l2.tag == 1247u) {
        std_string__builder$append(l0, 2526u);
    } else if (l2.tag == 1259u) {
        std_string__builder$append(l0, 2540u);
    } else if (l2.tag == 1260u) {
        std_string__builder$append(l0, 2541u);
    } else if (l2.tag == 1261u) {
        std_string__builder$append(l0, 3282u);
    } else if (l2.tag == 1250u) {
        std_string__builder$append(l0, 2530u);
    } else if (l2.tag == 1257u) {
        std_string__builder$append(l0, 2537u);
    } else if (l2.tag == 1254u) {
        std_string__builder$append(l0, 2534u);
    } else if (l2.tag == 1253u) {
        std_string__builder$append(l0, 2533u);
    } else if (l2.tag == 1252u) {
        std_string__builder$append(l0, 2532u);
    } else if (l2.tag == 1251u) {
        std_string__builder$append(l0, 2531u);
    } else if (l2.tag == 1263u) {
        std_string__builder$append(l0, 2544u);
    } else if (l2.tag == 1282u) {
        std_string__builder$append(l0, 2564u);
    } else if (l2.tag == 1276u) {
        std_string__builder$append(l0, 2557u);
    } else if (l2.tag == 1269u) {
        std_string__builder$append(l0, 2550u);
    } else if (l2.tag == 1275u) {
        std_string__builder$append(l0, 2560u);
    } else if (l2.tag == 1278u) {
        std_string__builder$append(l0, 2559u);
    } else if (l2.tag == 1264u) {
        std_string__builder$append(l0, 2545u);
    } else if (l2.tag == 1266u) {
        std_string__builder$append(l0, 2547u);
    } else if (l2.tag == 1267u) {
        std_string__builder$append(l0, 2548u);
    } else if (l2.tag == 1265u) {
        std_string__builder$append(l0, 2546u);
    } else if (l2.tag == 1279u) {
        std_string__builder$append(l0, 2562u);
    } else if (l2.tag == 1280u) {
        std_string__builder$append(l0, 2563u);
    } else if (l2.tag == 1281u) {
        std_string__builder$append(l0, 3292u);
    } else if (l2.tag == 1270u) {
        std_string__builder$append(l0, 2552u);
    } else if (l2.tag == 1277u) {
        std_string__builder$append(l0, 2558u);
    } else if (l2.tag == 1274u) {
        std_string__builder$append(l0, 2556u);
    } else if (l2.tag == 1273u) {
        std_string__builder$append(l0, 2555u);
    } else if (l2.tag == 1272u) {
        std_string__builder$append(l0, 2554u);
    } else if (l2.tag == 1271u) {
        std_string__builder$append(l0, 2553u);
    } else if (l2.tag == 1324u) {
        std_string__builder$append(l0, 3274u);
    } else if (l2.tag == 1329u) {
        std_string__builder$append(l0, 3280u);
    } else if (l2.tag == 1328u) {
        std_string__builder$append(l0, 3279u);
    } else if (l2.tag == 1327u) {
        std_string__builder$append(l0, 3278u);
    } else if (l2.tag == 1326u) {
        std_string__builder$append(l0, 3277u);
    } else if (l2.tag == 1325u) {
        std_string__builder$append(l0, 3276u);
    } else if (l2.tag == 1330u) {
        std_string__builder$append(l0, 3284u);
    } else if (l2.tag == 1335u) {
        std_string__builder$append(l0, 3290u);
    } else if (l2.tag == 1334u) {
        std_string__builder$append(l0, 3289u);
    } else if (l2.tag == 1333u) {
        std_string__builder$append(l0, 3288u);
    } else if (l2.tag == 1332u) {
        std_string__builder$append(l0, 3287u);
    } else if (l2.tag == 1331u) {
        std_string__builder$append(l0, 3286u);
    } else if (l2.tag == 1226u) {
        std_string__builder$append(l0, 2380u);
    } else if (l2.tag == 1237u) {
        std_string__builder$append(l0, 2391u);
    } else if (l2.tag == 1234u) {
        std_string__builder$append(l0, 2388u);
    } else if (l2.tag == 1228u) {
        std_string__builder$append(l0, 2382u);
    } else if (l2.tag == 1236u) {
        std_string__builder$append(l0, 2390u);
    } else if (l2.tag == 1229u) {
        std_string__builder$append(l0, 2383u);
    } else if (l2.tag == 1235u) {
        std_string__builder$append(l0, 2389u);
    } else if (l2.tag == 1233u) {
        std_string__builder$append(l0, 2387u);
    } else if (l2.tag == 1232u) {
        std_string__builder$append(l0, 2386u);
    } else if (l2.tag == 1231u) {
        std_string__builder$append(l0, 2385u);
    } else if (l2.tag == 1230u) {
        std_string__builder$append(l0, 2384u);
    } else if (l2.tag == 1200u) {
        std_string__builder$append(l0, 2005u);
    } else if (l2.tag == 1201u) {
        std_string__builder$append(l0, 2006u);
    } else if (l2.tag == 1198u) {
        std_string__builder$append(l0, 2003u);
    } else if (l2.tag == 1203u) {
        std_string__builder$append(l0, 2008u);
    } else if (l2.tag == 1317u) {
        std_string__builder$append(l0, 3096u);
    } else if (l2.tag == 1318u) {
        std_string__builder$append(l0, 3098u);
    } else if (l2.tag == 1315u) {
        std_string__builder$append(l0, 3094u);
    } else if (l2.tag == 1302u) {
        std_string__builder$append(l0, 2976u);
    } else if (l2.tag == 1303u) {
        std_string__builder$append(l0, 2977u);
    } else if (l2.tag == 1221u) {
        std_string__builder$append(l0, 2240u);
    } else if (l2.tag == 1220u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(35));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2238u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$DeferPopExec_t*) t0)->f_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1206u) {
        std_string__builder$append(l0, 2024u);
    } else if (l2.tag == 1291u) {
        std_string__builder$append(l0, 2724u);
    } else if (l2.tag == 1286u) {
        std_string__builder$append(l0, 2718u);
    } else if (l2.tag == 1287u) {
        std_string__builder$append(l0, 2719u);
    } else if (l2.tag == 1285u) {
        std_string__builder$append(l0, 2717u);
    } else if (l2.tag == 1314u) {
        std_string__builder$append(l0, 3089u);
    } else if (l2.tag == 1309u) {
        std_string__builder$append(l0, 3082u);
    } else if (l2.tag == 1310u) {
        std_string__builder$append(l0, 3083u);
    } else if (l2.tag == 1308u) {
        std_string__builder$append(l0, 3080u);
    } else if (l2.tag == 1289u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$LoadSlotI32_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(2722u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1290u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$LoadSlotI64_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(2723u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1288u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$LoadSlotF64_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(2721u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1312u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StoreSlotI32_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(3087u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1313u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StoreSlotI64_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(3088u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1311u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StoreSlotF64_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(3086u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1299u) {
        std_string__builder$append(l0, 2780u);
    } else if (l2.tag == 1207u) {
        std_string__builder$append(l0, 2031u);
    } else if (l2.tag == 1208u) {
        std_string__builder$append(l0, 2034u);
    } else if (l2.tag == 1238u) {
        std_string__builder$append(l0, 2392u);
    } else if (l2.tag == 1196u) {
        std_string__builder$append(l0, 1996u);
    } else if (l2.tag == 1225u) {
        std_string__builder$append(l0, 2378u);
    } else {
        if (!(l2.tag == 1195u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string__builder$append(l0, 1995u);
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
        t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0), 581u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string__builder$append_char(l0, 40u);
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l1));
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            std_string__builder$append(l0, 421u);
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l3, 581u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append_char(l0, 41u);
    { vader_gc_top = gc_frame.prev; return; }
}
