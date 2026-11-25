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
        return 269u;
    }
    return 0u;
}

static vader_string_t vader_emit_virt$convert_target_name(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2636u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 2658u;
    } else if (l0 == INT32_C(2)) {
        l1 = 2486u;
    } else {
        if (!(l0 == INT32_C(3))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 2232u;
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
    l2 = std_core$write_string_at(l3, l2, 19u);
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
        l9 = std_core$write_string_at(l8, l9, 19u);
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
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 629u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1116u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string__builder$append(l1, 319u);
    l2 = vader_host_std_core$Intrinsic$byte_len(l0);
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        l4 = vader_host_std_core$Intrinsic$byte_at(l0, l3);
        if (l4 == INT32_C(92)) {
            std_string__builder$append(l1, 1234u);
        } else if (l4 == INT32_C(34)) {
            std_string__builder$append(l1, 1231u);
        } else if (l4 == INT32_C(10)) {
            std_string__builder$append(l1, 1235u);
        } else if (l4 == INT32_C(13)) {
            std_string__builder$append(l1, 1236u);
        } else if (l4 == INT32_C(9)) {
            std_string__builder$append(l1, 1237u);
        } else if (l4 == INT32_C(0)) {
            std_string__builder$append(l1, 1233u);
        } else {
            l5 = vader_chk_add(i64, l3, INT64_C(1));
            l6 = vader_host_std_core$Intrinsic$byte_slice(l0, l3, l5);
            std_string__builder$append(l1, l6);
        }
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append(l1, 319u);
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
    t0 = concat_2(19u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_virt$refer(uint8_t l0, int32_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_virt$OperandRef_t* _a0_obj = (vader_struct_vader_emit_virt$OperandRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_virt$OperandRef_t));
    vader_obj_header_init(_a0_obj, 1640u);
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
    vader_obj_header_init(_a0_obj, 1640u);
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
    vader_array_t* _a0_arr = vader_array_new(462u, 0u, 13u, 2261u);
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
    if (l2.tag == 1365u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2642u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$I32Const_t*) t0)->f_value;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 1385u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(30));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2664u);
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_core_bytecode$I64Const_t*) t0)->f_value;
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1344u) {
        t0 = l2.payload.obj;
        t2 = ((vader_struct_vader_core_bytecode$F64Const_t*) t0)->f_value;
        l6 = vader_emit_virt$f64_const_operands(t2);
        l6 = concat_2(2488u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1316u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(16));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2093u);
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_core_bytecode$BoolConst_t*) t0)->f_value;
        l4 = std_core$write_bool(l3, l4, l7);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1331u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(31));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2234u);
        t0 = l2.payload.obj;
        t3 = ((vader_struct_vader_core_bytecode$CharConst_t*) t0)->f_value;
        t4 = ((int64_t) (uint32_t) ((int32_t) (uint32_t) t3));
        l8 = (uint64_t) (int64_t) t4;
        l4 = std_core$write_unsigned(l3, l4, l8);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1417u) {
        std_string__builder$append(l0, 3005u);
    } else if (l2.tag == 1458u) {
        std_string__builder$append(l0, 3703u);
    } else if (l2.tag == 1434u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StringConst_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 3, l9);
        vader_array_t* _a0_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a0_arr->buf->slots)[vader_array_offset(_a0_arr) + 0u] = t0;
        l3 = (void*) _a0_arr;
        vader_emit_virt$printed(l0, l1, 3240u, l3);
    } else if (l2.tag == 1410u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalGet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a1_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a1_arr->buf->slots)[vader_array_offset(_a1_arr) + 0u] = t0;
        l3 = (void*) _a1_arr;
        vader_emit_virt$printed(l0, l1, 2849u, l3);
    } else if (l2.tag == 1411u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalSet_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a2_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a2_arr->buf->slots)[vader_array_offset(_a2_arr) + 0u] = t0;
        l3 = (void*) _a2_arr;
        vader_emit_virt$printed(l0, l1, 2850u, l3);
    } else if (l2.tag == 1412u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$LocalTee_t*) t0)->f_slot;
        t0 = vader_emit_virt$refer((uint8_t) 6, l9);
        vader_array_t* _a3_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a3_arr->buf->slots)[vader_array_offset(_a3_arr) + 0u] = t0;
        l3 = (void*) _a3_arr;
        vader_emit_virt$printed(l0, l1, 2851u, l3);
    } else if (l2.tag == 1409u) {
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
        vader_array_t* _a4_arr = vader_array_new(277u, 3u, 13u, 1640u);
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 2u] = l12;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 1u] = l10;
        ((void**) _a4_arr->buf->slots)[vader_array_offset(_a4_arr) + 0u] = l3;
        l3 = (void*) _a4_arr;
        vader_emit_virt$printed(l0, l1, 2848u, l3);
    } else if (l2.tag == 1422u) {
        std_string__builder$append(l0, 3137u);
    } else if (l2.tag == 1423u) {
        std_string__builder$append(l0, 3141u);
        vader_array_push_ref((vader_array_t*) l1, vader_box_obj(0u, NULL).payload.obj);
        t0 = l2.payload.obj;
        l13 = ((vader_struct_vader_core_bytecode$ReturnLit_t*) t0)->f_value;
        vader_emit_virt$write_op_refs(l0, l1, l13);
    } else if (l2.tag == 1339u) {
        std_string__builder$append(l0, 2353u);
    } else if (l2.tag == 1328u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Call_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a5_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a5_arr->buf->slots)[vader_array_offset(_a5_arr) + 0u] = t0;
        l3 = (void*) _a5_arr;
        vader_emit_virt$printed(l0, l1, 2182u, l3);
    } else if (l2.tag == 1329u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallImport_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 4, l9);
        vader_array_t* _a6_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a6_arr->buf->slots)[vader_array_offset(_a6_arr) + 0u] = t0;
        l3 = (void*) _a6_arr;
        vader_emit_virt$printed(l0, l1, 2185u, l3);
    } else if (l2.tag == 1330u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$CallIndirect_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a7_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a7_arr->buf->slots)[vader_array_offset(_a7_arr) + 0u] = t0;
        l3 = (void*) _a7_arr;
        vader_emit_virt$printed(l0, l1, 2186u, l3);
    } else if (l2.tag == 1457u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_parameter_count;
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_vtable_key;
        l4 = vader_host_std_core$Intrinsic$byte_len(l6);
        l3 = (void*) vader_buffer_new((size_t) (INT64_C(38) + l4));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 3697u);
        l5 = ((int64_t) (int32_t) l9);
        l4 = std_core$write_int(l3, l4, l5);
        l4 = std_core$write_string_at(l3, l4, 19u);
        l4 = std_core$write_string_at(l3, l4, l6);
        l4 = std_core$write_string_at(l3, l4, 83u);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
        t0 = l2.payload.obj;
        l3 = ((vader_struct_vader_core_bytecode$VirtualCall_t*) t0)->f_results;
        vader_emit_virt$write_results(l0, l3);
    } else if (l2.tag == 1357u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnRef_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a8_arr = vader_array_new(277u, 2u, 13u, 1640u);
        ((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 1u] = l10;
        ((void**) _a8_arr->buf->slots)[vader_array_offset(_a8_arr) + 0u] = l3;
        l3 = (void*) _a8_arr;
        vader_emit_virt$printed(l0, l1, 2550u, l3);
    } else if (l2.tag == 1356u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$FnAddr_t*) t0)->f_function_index;
        t0 = vader_emit_virt$refer((uint8_t) 0, l9);
        vader_array_t* _a9_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a9_arr->buf->slots)[vader_array_offset(_a9_arr) + 0u] = t0;
        l3 = (void*) _a9_arr;
        vader_emit_virt$printed(l0, l1, 2548u, l3);
    } else if (l2.tag == 1332u) {
        t0 = l2.payload.obj;
        l6 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_kind);
        t0 = l2.payload.obj;
        l14 = vader_core_bytecode$checked_op_name(((vader_struct_vader_core_bytecode$CheckedArith_t*) t0)->f_op);
        l6 = concat_3(l6, 505u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1333u) {
        t0 = l2.payload.obj;
        t5 = vader_core_bytecode$val_type_name(((vader_struct_vader_core_bytecode$CheckedNeg_t*) t0)->f_kind);
        l6 = concat_2(t5, 506u);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1414u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_function_index;
        l3 = vader_emit_virt$refer((uint8_t) 0, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$MakeClosure_t*) t0)->f_env_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a10_arr = vader_array_new(277u, 2u, 13u, 1640u);
        ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 1u] = l10;
        ((void**) _a10_arr->buf->slots)[vader_array_offset(_a10_arr) + 0u] = l3;
        l3 = (void*) _a10_arr;
        vader_emit_virt$printed(l0, l1, 2877u, l3);
    } else if (l2.tag == 1400u) {
        std_string__builder$append(l0, 2686u);
    } else if (l2.tag == 1340u) {
        std_string__builder$append(l0, 2370u);
    } else if (l2.tag == 1341u) {
        std_string__builder$append(l0, 2389u);
    } else if (l2.tag == 1314u) {
        std_string__builder$append(l0, 2087u);
    } else if (l2.tag == 1413u) {
        std_string__builder$append(l0, 2854u);
    } else if (l2.tag == 1321u) {
        std_string__builder$append(l0, 2102u);
    } else if (l2.tag == 1322u) {
        std_string__builder$append(l0, 2104u);
    } else if (l2.tag == 1319u) {
        std_string__builder$append(l0, 2096u);
    } else if (l2.tag == 1438u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_stack;
        if (t6) {
            l6 = 3262u;
        } else {
            l6 = 3259u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a11_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a11_arr->buf->slots)[vader_array_offset(_a11_arr) + 0u] = t0;
        l3 = (void*) _a11_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 1437u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a12_arr = vader_array_new(277u, 2u, 13u, 1640u);
        ((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 1u] = l10;
        ((void**) _a12_arr->buf->slots)[vader_array_offset(_a12_arr) + 0u] = l3;
        l3 = (void*) _a12_arr;
        vader_emit_virt$printed(l0, l1, 3258u, l3);
    } else if (l2.tag == 1439u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_stack;
        if (t6) {
            l6 = 3267u;
        } else {
            l6 = 3263u;
        }
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$StructSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a13_arr = vader_array_new(277u, 2u, 13u, 1640u);
        ((void**) _a13_arr->buf->slots)[vader_array_offset(_a13_arr) + 1u] = l10;
        ((void**) _a13_arr->buf->slots)[vader_array_offset(_a13_arr) + 0u] = l3;
        l3 = (void*) _a13_arr;
        vader_emit_virt$printed(l0, l1, l6, l3);
    } else if (l2.tag == 1454u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldGet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a14_arr = vader_array_new(277u, 2u, 13u, 1640u);
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 1u] = l10;
        ((void**) _a14_arr->buf->slots)[vader_array_offset(_a14_arr) + 0u] = l3;
        l3 = (void*) _a14_arr;
        vader_emit_virt$printed(l0, l1, 3464u, l3);
    } else if (l2.tag == 1455u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        l3 = vader_emit_virt$refer((uint8_t) 1, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_type_id;
        t0 = l2.payload.obj;
        l11 = ((vader_struct_vader_core_bytecode$UnionFieldSet_t*) t0)->f_field_index;
        l10 = vader_emit_virt$refer_field(l9, l11);
        vader_array_t* _a15_arr = vader_array_new(277u, 2u, 13u, 1640u);
        ((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 1u] = l10;
        ((void**) _a15_arr->buf->slots)[vader_array_offset(_a15_arr) + 0u] = l3;
        l3 = (void*) _a15_arr;
        vader_emit_virt$printed(l0, l1, 3465u, l3);
    } else if (l2.tag == 1284u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a16_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a16_arr->buf->slots)[vader_array_offset(_a16_arr) + 0u] = t0;
        l3 = (void*) _a16_arr;
        vader_emit_virt$printed(l0, l1, 2031u, l3);
        l3 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 19u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayNew_t*) t0)->f_length;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1283u) {
        std_string__builder$append(l0, 2030u);
    } else if (l2.tag == 1285u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
        if ((t1 >= INT32_C(0))) {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            l3 = vader_emit_virt$refer((uint8_t) 1, l9);
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_cache_slot;
            l10 = vader_emit_virt$refer((uint8_t) 6, l9);
            vader_array_t* _a17_arr = vader_array_new(277u, 2u, 13u, 1640u);
            ((void**) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 1u] = l10;
            ((void**) _a17_arr->buf->slots)[vader_array_offset(_a17_arr) + 0u] = l3;
            l3 = (void*) _a17_arr;
            vader_emit_virt$printed(l0, l1, 2033u, l3);
        } else {
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_core_bytecode$ArrayPush_t*) t0)->f_type_id;
            t0 = vader_emit_virt$refer((uint8_t) 1, l9);
            vader_array_t* _a18_arr = vader_array_new(277u, 1u, 13u, 1640u);
            ((void**) _a18_arr->buf->slots)[vader_array_offset(_a18_arr) + 0u] = t0;
            l3 = (void*) _a18_arr;
            vader_emit_virt$printed(l0, l1, 2033u, l3);
        }
    } else if (l2.tag == 1282u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a19_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a19_arr->buf->slots)[vader_array_offset(_a19_arr) + 0u] = t0;
        l3 = (void*) _a19_arr;
        vader_emit_virt$printed(l0, l1, 2029u, l3);
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$ArrayGet_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1290u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a20_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a20_arr->buf->slots)[vader_array_offset(_a20_arr) + 0u] = t0;
        l3 = (void*) _a20_arr;
        vader_emit_virt$printed(l0, l1, 2044u, l3);
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$ArraySet_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1291u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArraySlice_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a21_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a21_arr->buf->slots)[vader_array_offset(_a21_arr) + 0u] = t0;
        l3 = (void*) _a21_arr;
        vader_emit_virt$printed(l0, l1, 2045u, l3);
    } else if (l2.tag == 1289u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$ArrayReserve_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a22_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a22_arr->buf->slots)[vader_array_offset(_a22_arr) + 0u] = t0;
        l3 = (void*) _a22_arr;
        vader_emit_virt$printed(l0, l1, 2042u, l3);
    } else if (l2.tag == 1288u) {
        std_string__builder$append(l0, 2039u);
    } else if (l2.tag == 1286u) {
        std_string__builder$append(l0, 2034u);
    } else if (l2.tag == 1281u) {
        std_string__builder$append(l0, 2021u);
    } else if (l2.tag == 1287u) {
        std_string__builder$append(l0, 2037u);
    } else if (l2.tag == 1280u) {
        std_string__builder$append(l0, 2019u);
    } else if (l2.tag == 1335u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_pool_index;
        l3 = vader_emit_virt$refer((uint8_t) 5, l9);
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$DataConst_t*) t0)->f_type_id;
        l10 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a23_arr = vader_array_new(277u, 2u, 13u, 1640u);
        ((void**) _a23_arr->buf->slots)[vader_array_offset(_a23_arr) + 1u] = l10;
        ((void**) _a23_arr->buf->slots)[vader_array_offset(_a23_arr) + 0u] = l3;
        l3 = (void*) _a23_arr;
        vader_emit_virt$printed(l0, l1, 2314u, l3);
    } else if (l2.tag == 1358u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalGet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a24_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a24_arr->buf->slots)[vader_array_offset(_a24_arr) + 0u] = t0;
        l3 = (void*) _a24_arr;
        vader_emit_virt$printed(l0, l1, 2612u, l3);
    } else if (l2.tag == 1359u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$GlobalSet_t*) t0)->f_index;
        t0 = vader_emit_virt$refer((uint8_t) 7, l9);
        vader_array_t* _a25_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a25_arr->buf->slots)[vader_array_offset(_a25_arr) + 0u] = t0;
        l3 = (void*) _a25_arr;
        vader_emit_virt$printed(l0, l1, 2613u, l3);
    } else if (l2.tag == 1441u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeConst_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a26_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a26_arr->buf->slots)[vader_array_offset(_a26_arr) + 0u] = t0;
        l3 = (void*) _a26_arr;
        vader_emit_virt$printed(l0, l1, 3404u, l3);
    } else if (l2.tag == 1440u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$TypeCheck_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a27_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a27_arr->buf->slots)[vader_array_offset(_a27_arr) + 0u] = t0;
        l3 = (void*) _a27_arr;
        vader_emit_virt$printed(l0, l1, 3408u, l3);
    } else if (l2.tag == 1418u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$RefCast_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a28_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a28_arr->buf->slots)[vader_array_offset(_a28_arr) + 0u] = t0;
        l3 = (void*) _a28_arr;
        vader_emit_virt$printed(l0, l1, 3108u, l3);
    } else if (l2.tag == 1421u) {
        t0 = l2.payload.obj;
        l9 = ((vader_struct_vader_core_bytecode$Retag_t*) t0)->f_type_id;
        t0 = vader_emit_virt$refer((uint8_t) 1, l9);
        vader_array_t* _a29_arr = vader_array_new(277u, 1u, 13u, 1640u);
        ((void**) _a29_arr->buf->slots)[vader_array_offset(_a29_arr) + 0u] = t0;
        l3 = (void*) _a29_arr;
        vader_emit_virt$printed(l0, l1, 3134u, l3);
    } else if (l2.tag == 1456u) {
        t0 = l2.payload.obj;
        t5 = ((vader_struct_vader_core_bytecode$Unreachable_t*) t0)->f_reason;
        l6 = vader_emit_virt$reason_word(t5);
        l6 = concat_2(3481u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1334u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_from_name;
        t0 = l2.payload.obj;
        l14 = vader_emit_virt$convert_target_name(((vader_struct_vader_core_bytecode$Convert_t*) t0)->f_target);
        l6 = concat_3(l6, 532u, l14);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1424u) {
        std_string__builder$append(l0, 2753u);
    } else if (l2.tag == 1360u) {
        std_string__builder$append(l0, 2637u);
    } else if (l2.tag == 1379u) {
        std_string__builder$append(l0, 2657u);
    } else if (l2.tag == 1373u) {
        std_string__builder$append(l0, 2651u);
    } else if (l2.tag == 1366u) {
        std_string__builder$append(l0, 2643u);
    } else if (l2.tag == 1372u) {
        std_string__builder$append(l0, 2654u);
    } else if (l2.tag == 1375u) {
        std_string__builder$append(l0, 2653u);
    } else if (l2.tag == 1362u) {
        std_string__builder$append(l0, 2639u);
    } else if (l2.tag == 1361u) {
        std_string__builder$append(l0, 2638u);
    } else if (l2.tag == 1363u) {
        std_string__builder$append(l0, 2640u);
    } else if (l2.tag == 1364u) {
        std_string__builder$append(l0, 2641u);
    } else if (l2.tag == 1376u) {
        std_string__builder$append(l0, 2655u);
    } else if (l2.tag == 1377u) {
        std_string__builder$append(l0, 2656u);
    } else if (l2.tag == 1378u) {
        std_string__builder$append(l0, 3437u);
    } else if (l2.tag == 1367u) {
        std_string__builder$append(l0, 2645u);
    } else if (l2.tag == 1374u) {
        std_string__builder$append(l0, 2652u);
    } else if (l2.tag == 1371u) {
        std_string__builder$append(l0, 2649u);
    } else if (l2.tag == 1370u) {
        std_string__builder$append(l0, 2648u);
    } else if (l2.tag == 1369u) {
        std_string__builder$append(l0, 2647u);
    } else if (l2.tag == 1368u) {
        std_string__builder$append(l0, 2646u);
    } else if (l2.tag == 1380u) {
        std_string__builder$append(l0, 2659u);
    } else if (l2.tag == 1399u) {
        std_string__builder$append(l0, 2679u);
    } else if (l2.tag == 1393u) {
        std_string__builder$append(l0, 2672u);
    } else if (l2.tag == 1386u) {
        std_string__builder$append(l0, 2665u);
    } else if (l2.tag == 1392u) {
        std_string__builder$append(l0, 2675u);
    } else if (l2.tag == 1395u) {
        std_string__builder$append(l0, 2674u);
    } else if (l2.tag == 1381u) {
        std_string__builder$append(l0, 2660u);
    } else if (l2.tag == 1383u) {
        std_string__builder$append(l0, 2662u);
    } else if (l2.tag == 1384u) {
        std_string__builder$append(l0, 2663u);
    } else if (l2.tag == 1382u) {
        std_string__builder$append(l0, 2661u);
    } else if (l2.tag == 1396u) {
        std_string__builder$append(l0, 2677u);
    } else if (l2.tag == 1397u) {
        std_string__builder$append(l0, 2678u);
    } else if (l2.tag == 1398u) {
        std_string__builder$append(l0, 3447u);
    } else if (l2.tag == 1387u) {
        std_string__builder$append(l0, 2667u);
    } else if (l2.tag == 1394u) {
        std_string__builder$append(l0, 2673u);
    } else if (l2.tag == 1391u) {
        std_string__builder$append(l0, 2671u);
    } else if (l2.tag == 1390u) {
        std_string__builder$append(l0, 2670u);
    } else if (l2.tag == 1389u) {
        std_string__builder$append(l0, 2669u);
    } else if (l2.tag == 1388u) {
        std_string__builder$append(l0, 2668u);
    } else if (l2.tag == 1442u) {
        std_string__builder$append(l0, 3429u);
    } else if (l2.tag == 1447u) {
        std_string__builder$append(l0, 3435u);
    } else if (l2.tag == 1446u) {
        std_string__builder$append(l0, 3434u);
    } else if (l2.tag == 1445u) {
        std_string__builder$append(l0, 3433u);
    } else if (l2.tag == 1444u) {
        std_string__builder$append(l0, 3432u);
    } else if (l2.tag == 1443u) {
        std_string__builder$append(l0, 3431u);
    } else if (l2.tag == 1448u) {
        std_string__builder$append(l0, 3439u);
    } else if (l2.tag == 1453u) {
        std_string__builder$append(l0, 3445u);
    } else if (l2.tag == 1452u) {
        std_string__builder$append(l0, 3444u);
    } else if (l2.tag == 1451u) {
        std_string__builder$append(l0, 3443u);
    } else if (l2.tag == 1450u) {
        std_string__builder$append(l0, 3442u);
    } else if (l2.tag == 1449u) {
        std_string__builder$append(l0, 3441u);
    } else if (l2.tag == 1343u) {
        std_string__builder$append(l0, 2487u);
    } else if (l2.tag == 1354u) {
        std_string__builder$append(l0, 2498u);
    } else if (l2.tag == 1351u) {
        std_string__builder$append(l0, 2495u);
    } else if (l2.tag == 1345u) {
        std_string__builder$append(l0, 2489u);
    } else if (l2.tag == 1353u) {
        std_string__builder$append(l0, 2497u);
    } else if (l2.tag == 1346u) {
        std_string__builder$append(l0, 2490u);
    } else if (l2.tag == 1352u) {
        std_string__builder$append(l0, 2496u);
    } else if (l2.tag == 1350u) {
        std_string__builder$append(l0, 2494u);
    } else if (l2.tag == 1349u) {
        std_string__builder$append(l0, 2493u);
    } else if (l2.tag == 1348u) {
        std_string__builder$append(l0, 2492u);
    } else if (l2.tag == 1347u) {
        std_string__builder$append(l0, 2491u);
    } else if (l2.tag == 1317u) {
        std_string__builder$append(l0, 2094u);
    } else if (l2.tag == 1318u) {
        std_string__builder$append(l0, 2095u);
    } else if (l2.tag == 1315u) {
        std_string__builder$append(l0, 2092u);
    } else if (l2.tag == 1320u) {
        std_string__builder$append(l0, 2097u);
    } else if (l2.tag == 1435u) {
        std_string__builder$append(l0, 3241u);
    } else if (l2.tag == 1436u) {
        std_string__builder$append(l0, 3243u);
    } else if (l2.tag == 1433u) {
        std_string__builder$append(l0, 3239u);
    } else if (l2.tag == 1419u) {
        std_string__builder$append(l0, 3109u);
    } else if (l2.tag == 1420u) {
        std_string__builder$append(l0, 3110u);
    } else if (l2.tag == 1338u) {
        std_string__builder$append(l0, 2335u);
    } else if (l2.tag == 1337u) {
        l3 = (void*) vader_buffer_new((size_t) INT64_C(35));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 2333u);
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_core_bytecode$DeferPopExec_t*) t0)->f_count;
        l5 = ((int64_t) (int32_t) t1);
        l4 = std_core$write_int(l3, l4, l5);
        l6 = std_core$finish_buffer(l3, l4);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1323u) {
        std_string__builder$append(l0, 2114u);
    } else if (l2.tag == 1408u) {
        std_string__builder$append(l0, 2842u);
    } else if (l2.tag == 1403u) {
        std_string__builder$append(l0, 2836u);
    } else if (l2.tag == 1404u) {
        std_string__builder$append(l0, 2837u);
    } else if (l2.tag == 1402u) {
        std_string__builder$append(l0, 2835u);
    } else if (l2.tag == 1432u) {
        std_string__builder$append(l0, 3232u);
    } else if (l2.tag == 1427u) {
        std_string__builder$append(l0, 3225u);
    } else if (l2.tag == 1428u) {
        std_string__builder$append(l0, 3226u);
    } else if (l2.tag == 1426u) {
        std_string__builder$append(l0, 3223u);
    } else if (l2.tag == 1406u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$LoadSlotI32_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(2840u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1407u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$LoadSlotI64_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(2841u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1405u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$LoadSlotF64_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(2839u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1430u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StoreSlotI32_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(3230u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1431u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StoreSlotI64_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(3231u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1429u) {
        t0 = l2.payload.obj;
        t6 = ((vader_struct_vader_core_bytecode$StoreSlotF64_t*) t0)->f_bounds_safe;
        l6 = vader_emit_virt$bounds_safe_word(t6);
        l6 = concat_2(3229u, l6);
        std_string__builder$append(l0, l6);
    } else if (l2.tag == 1416u) {
        std_string__builder$append(l0, 2900u);
    } else if (l2.tag == 1324u) {
        std_string__builder$append(l0, 2121u);
    } else if (l2.tag == 1325u) {
        std_string__builder$append(l0, 2124u);
    } else if (l2.tag == 1355u) {
        std_string__builder$append(l0, 2499u);
    } else if (l2.tag == 1313u) {
        std_string__builder$append(l0, 2085u);
    } else if (l2.tag == 1342u) {
        std_string__builder$append(l0, 2485u);
    } else {
        if (!(l2.tag == 1312u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string__builder$append(l0, 2084u);
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
        t1 = vader_array_read_u8(_a0_slotarr, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0), 634u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string__builder$append_char(l0, 40u);
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l1));
    while ((l3 < l4)) {
        if ((l3 > INT64_C(0))) {
            std_string__builder$append(l0, 442u);
        }
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t1 = vader_array_read_u8(_a1_slotarr, vader_array_offset(_a1_slotarr) + (size_t) l3, 634u);
        l2 = vader_core_bytecode$val_type_name(((uint8_t) t1.payload.i));
        std_string__builder$append(l0, l2);
        l3 = (l3 + INT64_C(1));
    }
    std_string__builder$append_char(l0, 41u);
    { vader_gc_top = gc_frame.prev; return; }
}
