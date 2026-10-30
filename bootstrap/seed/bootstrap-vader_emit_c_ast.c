#include "bootstrap.split.h"

static bool vader_emit_c_ast$any_mentions_local(void* l0, int32_t l1);
static void vader_emit_c_ast$collect_clause_labels(void* l0, void* l1);
static void vader_emit_c_ast$collect_goto_labels(void* l0, void* l1);
static bool vader_emit_c_ast$declares(void* l0);
static bool vader_emit_c_ast$end_is_reachable(void* l0);
static bool vader_emit_c_ast$ends_with_continue(void* l0);
static void* vader_emit_c_ast$exits_after(vader_string_t l0, void* l1, bool l2);
static bool vader_emit_c_ast$fits(vader_string_t l0, int64_t l1);
static void vader_emit_c_ast$fuse_temp_local_copies(void* l0, void* l1);
static vader_box_t vader_emit_c_ast$fused_copy(vader_box_t l0, vader_box_t l1, void* l2);
static vader_string_t vader_emit_c_ast$include_operand(void* l0);
static void vader_emit_c_ast$indent(void* l0, int32_t l1);
static vader_string_t vader_emit_c_ast$indentation(int32_t l0);
static bool vader_emit_c_ast$is_empty(void* l0);
static bool vader_emit_c_ast$is_table(void* l0);
static vader_string_t vader_emit_c_ast$labelled(vader_string_t l0, vader_string_t l1);
static int64_t vader_emit_c_ast$leading_directives(void* l0);
static vader_box_t vader_emit_c_ast$loop_of(void* l0);
static vader_box_t vader_emit_c_ast$negated(void* l0, vader_string_t l1);
static void* vader_emit_c_ast$order_by_first(void* l0);
static void vader_emit_c_ast$push_tail_labels(void* l0, void* l1);
static void vader_emit_c_ast$rewrite_block(void* l0, void* l1);
static bool vader_emit_c_ast$same_expressions(void* l0, void* l1);
static void vader_emit_c_ast$scan_block(void* l0, void* l1);
static void vader_emit_c_ast$scan_clause(void* l0, void* l1);
static void vader_emit_c_ast$scan_expression(vader_box_t l0, void* l1);
static void vader_emit_c_ast$scan_statements(void* l0, void* l1);
static void* vader_emit_c_ast$spliced(void* l0, int64_t l1, int64_t l2, void* l3);
static int64_t vader_emit_c_ast$statements_end(void* l0);
static vader_string_t vader_emit_c_ast$storage_keyword(uint8_t l0);
static void vader_emit_c_ast$substitute_jumps(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_emit_c_ast$tail_statement(void* l0);
static vader_string_t vader_emit_c_ast$text_of(vader_box_t l0);
static void vader_emit_c_ast$tidy_block(void* l0, void* l1);
static int64_t vader_emit_c_ast$trailing_directives(void* l0, int64_t l1);
static vader_string_t vader_emit_c_ast$used_label(vader_string_t l0, void* l1);
static void vader_emit_c_ast$write_assign(void* l0, void* l1);
static void vader_emit_c_ast$write_block(void* l0, void* l1, int32_t l2);
static void vader_emit_c_ast$write_case_body(void* l0, void* l1, bool l2);
static void vader_emit_c_ast$write_closer(void* l0, vader_string_t l1, int32_t l2);
static void vader_emit_c_ast$write_declaration(void* l0, void* l1, int32_t l2);
static void vader_emit_c_ast$write_declarator(void* l0, void* l1, int64_t l2, int32_t l3);
static void vader_emit_c_ast$write_declared(void* l0, vader_string_t l1, vader_box_t l2, int64_t l3, int32_t l4);
static void vader_emit_c_ast$write_directive(void* l0, vader_string_t l1);
static void vader_emit_c_ast$write_element(void* l0, vader_box_t l1, int32_t l2);
static void vader_emit_c_ast$write_else_chain(void* l0, void* l1, vader_string_t l2, int32_t l3);
static void vader_emit_c_ast$write_expression(void* l0, vader_box_t l1);
static void vader_emit_c_ast$write_filled(void* l0, void* l1, int32_t l2);
static void vader_emit_c_ast$write_function(void* l0, void* l1);
static void vader_emit_c_ast$write_goto(void* l0, void* l1);
static void vader_emit_c_ast$write_if(void* l0, void* l1, int32_t l2);
static void vader_emit_c_ast$write_if_head(void* l0, vader_string_t l1, vader_box_t l2, int32_t l3);
static void vader_emit_c_ast$write_initializer(void* l0, vader_box_t l1, int64_t l2, int32_t l3);
static void vader_emit_c_ast$write_initializer_line(void* l0, vader_box_t l1, int64_t l2, int32_t l3);
static void vader_emit_c_ast$write_integer_literal(void* l0, void* l1);
static void vader_emit_c_ast$write_jump(void* l0, vader_box_t l1, vader_string_t l2);
static void vader_emit_c_ast$write_laid_out(void* l0, vader_box_t l1, vader_string_t l2, int64_t l3, int32_t l4);
static void vader_emit_c_ast$write_line(void* l0, vader_string_t l1, int32_t l2);
static void vader_emit_c_ast$write_list(void* l0, void* l1);
static void vader_emit_c_ast$write_operand(void* l0, vader_box_t l1, int32_t l2);
static void vader_emit_c_ast$write_parameters(void* l0, void* l1);
static void vader_emit_c_ast$write_return(void* l0, void* l1, int32_t l2);
static void vader_emit_c_ast$write_return_text(void* l0, void* l1);
static void vader_emit_c_ast$write_signature(void* l0, void* l1);
static void vader_emit_c_ast$write_statements(void* l0, void* l1, int64_t l2, int64_t l3, int32_t l4);
static void vader_emit_c_ast$write_switch(void* l0, void* l1, int32_t l2);
static void vader_emit_c_ast$write_top_level(void* l0, vader_box_t l1);

vader_box_t vader_emit_c_ast$address_of(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CAddressOf_t* _a0_obj = (vader_struct_vader_emit_c_ast$CAddressOf_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAddressOf_t));
    vader_obj_header_init(_a0_obj, 1073u);
    _a0_obj->f_operand = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c_ast$any_mentions_local(void* l0, int32_t l1) {
    void* l2;
    int64_t l3, l4;
    vader_box_t t0;
    bool t1;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = vader_emit_c_ast$mentions_local(t0, l1);
        if (t1) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

vader_box_t vader_emit_c_ast$any_of(void* l0) {
    vader_box_t l1 = vader_box_null(), l4 = vader_box_null();
    int64_t l2, l3;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = INT64_C(1);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        vader_struct_vader_emit_c_ast$CBinary_t* _a2_obj = (vader_struct_vader_emit_c_ast$CBinary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBinary_t));
        vader_obj_header_init(_a2_obj, 1075u);
        _a2_obj->f_operator = (uint8_t) 17;
        _a2_obj->f_left = l1;
        _a2_obj->f_right = l4;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
        l2 = (l2 + INT64_C(1));
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_emit_c_ast$around(vader_string_t l0, vader_box_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l3, &l4 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_emit_c_ast$verbatim(l0);
    l4 = vader_emit_c_ast$verbatim(l2);
    vader_array_t* _a0_arr = vader_array_new(365u, 3u, 13u, 2047u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l3.payload.obj;
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CSequence_t* _a1_obj = (vader_struct_vader_emit_c_ast$CSequence_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSequence_t));
    vader_obj_header_init(_a1_obj, 1114u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_emit_c_ast$array_declaration(vader_string_t l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    int32_t l4;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CInitializerList_t* _a0_obj = (vader_struct_vader_emit_c_ast$CInitializerList_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInitializerList_t));
    vader_obj_header_init(_a0_obj, 1100u);
    _a0_obj->f_elements = l2;
    l3 = (void*) _a0_obj;
    t0 = ((vader_array_t*) l2)->length;
    l4 = ((int32_t) (int64_t) t0);
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a1_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a1_obj, 1086u);
    _a1_obj->f_name = l1;
    _a1_obj->f_length = vader_box_i32(450u, l4);
    _a1_obj->f_value = vader_ref_box(l3);
    t1 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(200u, 1u, 13u, 1086u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t1;
    l3 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CDeclaration_t* _a3_obj = (vader_struct_vader_emit_c_ast$CDeclaration_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclaration_t));
    vader_obj_header_init(_a3_obj, 1085u);
    _a3_obj->f_type = l0;
    _a3_obj->f_declarators = l3;
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_emit_c_ast$binary(uint8_t l0, vader_box_t l1, vader_box_t l2) {
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CBinary_t* _a0_obj = (vader_struct_vader_emit_c_ast$CBinary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBinary_t));
    vader_obj_header_init(_a0_obj, 1075u);
    _a0_obj->f_operator = l0;
    _a0_obj->f_left = l1;
    _a0_obj->f_right = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_emit_c_ast$call(vader_string_t l0, void* l1) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CCall_t* _a0_obj = (vader_struct_vader_emit_c_ast$CCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCall_t));
    vader_obj_header_init(_a0_obj, 1078u);
    _a0_obj->f_callee = l0;
    _a0_obj->f_arguments = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_emit_c_ast$cast(vader_string_t l0, vader_box_t l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 1u, 0u, 447u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(447u, l0);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CCast_t* _a1_obj = (vader_struct_vader_emit_c_ast$CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CCast_t));
    vader_obj_header_init(_a1_obj, 1080u);
    _a1_obj->f_types = t0;
    _a1_obj->f_value = l1;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_emit_c_ast$coalesce_temporaries(void* l0, void* l1) {
    int64_t l2, l7, l8, l11, l12;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    int32_t l10, l15, l16, l18, l19;
    uint8_t l13, l14, l17;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l3, &l4, &l5, &l6, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l1)->length;
    if (l2 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(25u, 0u, 1u, 452u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(23u, 1u, 7u, 450u);
    ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l5 = (void*) _a6_arr;
    vader_struct_vader_emit_c_ast$TemporaryUsage_t* _a7_obj = (vader_struct_vader_emit_c_ast$TemporaryUsage_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$TemporaryUsage_t));
    vader_obj_header_init(_a7_obj, 1126u);
    _a7_obj->f_uses = l3;
    _a7_obj->f_first = l4;
    _a7_obj->f_last = l5;
    _a7_obj->f_position = INT32_C(-1);
    l3 = (void*) _a7_obj;
    vader_emit_c_ast$scan_block(l0, l3);
    vader_emit_c_ast$fuse_temp_local_copies(l0, l3);
    vader_array_t* _a8_arr = vader_array_new(25u, 0u, 1u, 452u);
    l4 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(23u, 0u, 7u, 450u);
    l5 = (void*) _a9_arr;
    l6 = vader_emit_c_ast$order_by_first(((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l3)->f_first);
    l2 = ((vader_array_t*) l6)->length;
    l7 = INT64_C(0);
    while ((l7 < l2)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l8 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l7];
        vader_array_t* _a11_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l8)
        l9 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l8);
        l10 = INT32_C(-1);
        l11 = INT64_C(0);
        l12 = ((vader_array_t*) l4)->length;
        while ((l11 < l12)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            t1 = vader_array_read_u8(_a12_slotarr, _a12_slotarr->offset + (size_t) l11, 452u);
            l13 = ((uint8_t) t1.payload.i);
            l14 = ((vader_struct_vader_emit_c_ast$CTemporary_t*) l9)->f_val;
            if (l13 == l14) {
                vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l11)
                l15 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l11];
                vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l3)->f_first);
                VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l8)
                l16 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l8];
                if ((l15 < l16)) {
                    l10 = ((int32_t) (int64_t) l11);
                    break;
                }
            }
            l11 = (l11 + INT64_C(1));
        }
        if ((l10 < INT32_C(0))) {
            t2 = ((vader_array_t*) l4)->length;
            l10 = ((int32_t) (int64_t) t2);
            l17 = ((vader_struct_vader_emit_c_ast$CTemporary_t*) l9)->f_val;
            vader_array_push_u8((vader_array_t*) l4, (int32_t) (uint8_t) l17);
            vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l3)->f_last);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l8)
            l18 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l8];
            vader_array_push_i32((vader_array_t*) l5, l18);
        } else {
            vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l3)->f_last);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l8)
            l19 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l8];
            vader_array_t* _a17_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l10)
            ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l10] = (int32_t) l19;
        }
        ((vader_struct_vader_emit_c_ast$CTemporary_t*) l9)->f_slot = l10;
        l7 = (l7 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c_ast$collect_clause_labels(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 1096u) {
            t0 = l5.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CGoto_t*) t0)->f_label;
            std_collections$add__string(l1, l6);
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$collect_goto_labels(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    int64_t l3, l4, l9, l10;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null(), l11 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l5, &l7, &l11 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 1096u) {
            t0 = l5.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CGoto_t*) t0)->f_label;
            std_collections$add__string(l1, l6);
        } else if (l5.tag == 1097u) {
            t0 = l5.payload.obj;
            vader_emit_c_ast$collect_goto_labels(((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_then_block, l1);
            t0 = l5.payload.obj;
            l7 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_else_block;
            if (!(l7.tag == 0u)) {
                t0 = l7.payload.obj;
                vader_emit_c_ast$collect_goto_labels(t0, l1);
            }
        } else if ((l5.tag == 1092u || l5.tag == 1112u || l5.tag == 1125u)) {
            vader_emit_c_ast$collect_goto_labels(VADER_UNION_FIELD(void*, vader_struct_vader_emit_c_ast$CFor_t, f_body, l5.payload.obj), l1);
        } else if (l5.tag == 1120u) {
            t0 = l5.payload.obj;
            l8 = ((vader_struct_vader_emit_c_ast$CSwitch_t*) t0)->f_cases;
            l9 = ((vader_array_t*) l8)->length;
            l10 = INT64_C(0);
            while ((l10 < l9)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
                vader_emit_c_ast$collect_clause_labels(((vader_struct_vader_emit_c_ast$CCase_t*) t0)->f_body, l1);
                l10 = (l10 + INT64_C(1));
            }
            t0 = l5.payload.obj;
            l11 = ((vader_struct_vader_emit_c_ast$CSwitch_t*) t0)->f_default_body;
            if (!(l11.tag == 0u)) {
                t0 = l11.payload.obj;
                vader_emit_c_ast$collect_clause_labels(t0, l1);
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

vader_box_t vader_emit_c_ast$declaration(vader_string_t l0, vader_string_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CDeclarator_t* _a0_obj = (vader_struct_vader_emit_c_ast$CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclarator_t));
    vader_obj_header_init(_a0_obj, 1086u);
    _a0_obj->f_name = l1;
    _a0_obj->f_length = vader_box_obj(0u, NULL);
    _a0_obj->f_value = l2;
    t0 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(200u, 1u, 13u, 1086u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
    l3 = (void*) _a1_arr;
    vader_struct_vader_emit_c_ast$CDeclaration_t* _a2_obj = (vader_struct_vader_emit_c_ast$CDeclaration_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDeclaration_t));
    vader_obj_header_init(_a2_obj, 1085u);
    _a2_obj->f_type = l0;
    _a2_obj->f_declarators = l3;
    t0 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c_ast$declares(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t t0;
    l1 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (t0.tag == 1085u) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

vader_box_t vader_emit_c_ast$designated(vader_string_t l0, vader_box_t l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CDesignated_t* _a0_obj = (vader_struct_vader_emit_c_ast$CDesignated_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CDesignated_t));
    vader_obj_header_init(_a0_obj, 1088u);
    _a0_obj->f_designator = l0;
    _a0_obj->f_value = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c_ast$end_is_reachable(void* l0) {
    vader_box_t l1;
    bool l2;
    void* t0;
    l1 = vader_emit_c_ast$tail_statement(l0);
    if (l1.tag == 0u) {
        return true;
    }
    if ((l1.tag == 1077u || l1.tag == 1084u)) {
        l2 = !(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_emit_c_ast$CBreak_t, f_condition, l1.payload.obj).tag == 0u);
        return l2;
    }
    if (l1.tag == 1096u) {
        t0 = l1.payload.obj;
        l2 = !(((vader_struct_vader_emit_c_ast$CGoto_t*) t0)->f_condition.tag == 0u);
    } else if (l1.tag == 1111u) {
        l2 = false;
    } else {
        l2 = true;
    }
    return l2;
}

static bool vader_emit_c_ast$ends_with_continue(void* l0) {
    vader_box_t l1;
    void* t0;
    l1 = vader_emit_c_ast$tail_statement(((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body);
    if (l1.tag == 1084u) {
        t0 = l1.payload.obj;
        return ((vader_struct_vader_emit_c_ast$CContinue_t*) t0)->f_condition.tag == 0u;
    }
    return false;
}

bool vader_emit_c_ast$ends_with_return(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t t0;
    l1 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    l3 = vader_emit_c_ast$trailing_directives(l1, INT64_C(0));
    l2 = vader_chk_sub(i64, l2, l3);
    if ((l2 > INT64_C(0))) {
        l2 = vader_chk_sub(i64, l2, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        return t0.tag == 1111u;
    }
    return false;
}

static void* vader_emit_c_ast$exits_after(vader_string_t l0, void* l1, bool l2) {
    void* l3 = NULL;
    void** gc_raw_roots[2] = { &l1, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l3 = (void*) _a0_arr;
    if (l0 != 0u) {
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(447u, l0));
    }
    if (l2) {
        vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l1);
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c_ast$fits(vader_string_t l0, int64_t l1) {
    int64_t l2;
    int64_t t0, t1;
    l2 = vader_host_std_core$byte_len(l0);
    t0 = vader_chk_add(i64, l1, l2);
    t1 = vader_chk_add(i64, t0, INT64_C(1));
    return (t1 <= INT64_C(100));
}

static void vader_emit_c_ast$fuse_temp_local_copies(void* l0, void* l1) {
    void* l2 = NULL;
    void* l13 = NULL;
    int64_t l3, l4, l5, l9, l10, l11;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l12 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l6, &l7, &l8, &l12, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body;
    l3 = INT64_C(0);
    l4 = INT64_C(0);
    for (;;) {
        l5 = ((vader_array_t*) l2)->length;
        if ((l4 < l5)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            if (l6.tag == 1097u) {
                t0 = l6.payload.obj;
                vader_emit_c_ast$fuse_temp_local_copies(((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_then_block, l1);
                t0 = l6.payload.obj;
                l7 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_else_block;
                if (!(l7.tag == 0u)) {
                    t0 = l7.payload.obj;
                    vader_emit_c_ast$fuse_temp_local_copies(t0, l1);
                }
            } else if (l6.tag == 1112u) {
                t0 = l6.payload.obj;
                vader_emit_c_ast$fuse_temp_local_copies(((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_body, l1);
            }
            l9 = vader_chk_add(i64, l4, INT64_C(1));
            l10 = ((vader_array_t*) l2)->length;
            if ((l9 < l10)) {
                l11 = vader_chk_add(i64, l4, INT64_C(1));
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l11)
                l12 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
                l8 = vader_emit_c_ast$fused_copy(l6, l12, l1);
            } else {
                l8 = vader_box_obj(0u, NULL);
            }
            if (l8.tag == 0u) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3, l6.payload.obj);
                VADER_WRITE_BARRIER(_a2_slotarr->buf);
                l4 = vader_chk_add(i64, l4, INT64_C(1));
            } else {
                l13 = l8.payload.obj;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
                vader_array_ref_store(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3, l13);
                VADER_WRITE_BARRIER(_a3_slotarr->buf);
                l4 = vader_chk_add(i64, l4, INT64_C(2));
            }
            l3 = vader_chk_add(i64, l3, INT64_C(1));
            continue;
        }
        break;
    }
    for (;;) {
        t1 = ((vader_array_t*) l2)->length;
        if ((t1 > l3)) {
            t2 = vader_array_remove_last((vader_array_t*) l2);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c_ast$fused_copy(vader_box_t l0, vader_box_t l1, void* l2) {
    vader_box_t l3 = vader_box_null(), l6 = vader_box_null();
    void* l4 = NULL;
    int32_t l5, l7;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l0, &l1, &l3, &l6, &t2 };
    void** gc_raw_roots[3] = { &l2, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1074u) {
        if (l1.tag == 1074u) {
            t0 = l0.payload.obj;
            l3 = ((vader_struct_vader_emit_c_ast$CAssign_t*) t0)->f_target;
            if (l3.tag == 1121u) {
                l4 = ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l2)->f_uses;
                t0 = l3.payload.obj;
                l5 = ((vader_struct_vader_emit_c_ast$CTemporary_t*) t0)->f_id;
                vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
                t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5];
                if (t1 != INT32_C(2)) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                t0 = l1.payload.obj;
                l6 = ((vader_struct_vader_emit_c_ast$CAssign_t*) t0)->f_value;
                t0 = l1.payload.obj;
                if (((vader_struct_vader_emit_c_ast$CAssign_t*) t0)->f_target.tag == 1102u) {
                    if (l6.tag == 1121u) {
                        t0 = l6.payload.obj;
                        l5 = ((vader_struct_vader_emit_c_ast$CTemporary_t*) t0)->f_id;
                        t0 = l3.payload.obj;
                        l7 = ((vader_struct_vader_emit_c_ast$CTemporary_t*) t0)->f_id;
                        if (!(l5 != l7)) {
                            l4 = ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l2)->f_first;
                            t0 = l3.payload.obj;
                            l5 = ((vader_struct_vader_emit_c_ast$CTemporary_t*) t0)->f_id;
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
                            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
                            ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5] = (int32_t) INT32_C(-1);
                            t0 = l1.payload.obj;
                            t2 = ((vader_struct_vader_emit_c_ast$CAssign_t*) t0)->f_target;
                            l4 = t2.payload.obj;
                            t0 = l0.payload.obj;
                            l3 = ((vader_struct_vader_emit_c_ast$CAssign_t*) t0)->f_value;
                            vader_struct_vader_emit_c_ast$CAssign_t* _a2_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
                            vader_obj_header_init(_a2_obj, 1074u);
                            _a2_obj->f_target = vader_ref_box(l4);
                            _a2_obj->f_value = l3;
                            _a2_obj->f_operator = vader_box_obj(0u, NULL);
                            t0 = (void*) _a2_obj;
                            { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                    }
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
            }
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_string_t vader_emit_c_ast$include_operand(void* l0) {
    vader_string_t l1 = 0;
    bool t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_emit_c_ast$CInclude_t*) l0)->f_system;
    if (!(t0)) {
        l1 = ((vader_struct_vader_emit_c_ast$CInclude_t*) l0)->f_path;
        t1 = concat_3(250u, l1, 250u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_struct_vader_emit_c_ast$CInclude_t*) l0)->f_path;
    t1 = concat_3(505u, l1, 526u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c_ast$indent(void* l0, int32_t l1) {
    vader_string_t l2 = 0;
    int32_t l3;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l1 > INT32_C(8))) {
        l2 = vader_emit_c_ast$indentation(INT32_C(8));
        std_string__builder$append(l0, l2);
        l3 = vader_chk_sub(i32, l1, INT32_C(8));
        vader_emit_c_ast$indent(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if ((l1 > INT32_C(0))) {
        l2 = vader_emit_c_ast$indentation(l1);
        std_string__builder$append(l0, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_emit_c_ast$indentation(int32_t l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    int64_t l3, l4;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l2 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0 == INT32_C(1)) {
        l1 = 16u;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0 == INT32_C(2)) {
        l1 = 17u;
    } else if (l0 == INT32_C(3)) {
        l1 = 18u;
    } else if (l0 == INT32_C(4)) {
        l1 = 19u;
    } else if (l0 == INT32_C(5)) {
        l1 = 20u;
    } else if (l0 == INT32_C(6)) {
        l1 = 21u;
    } else if (l0 == INT32_C(7)) {
        l1 = 22u;
    } else {
        if (!(l0 == INT32_C(8))) {
            l2 = (void*) vader_buffer_new((size_t) INT64_C(76));
            l3 = INT64_C(0);
            l3 = std_core$write_string_at(l2, l3, 2157u);
            l4 = ((int64_t) (int32_t) l0);
            l3 = std_core$write_int(l2, l3, l4);
            l3 = std_core$write_string_at(l2, l3, 170u);
            l3 = std_core$write_int(l2, l3, INT64_C(8));
            t0 = std_core$finish_buffer(l2, l3);
            std_abort$unreachable(t0);
            vader_unreachable("a no-return call returned");
        }
        l1 = 23u;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_emit_c_ast$initializer_list(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CInitializerList_t* _a0_obj = (vader_struct_vader_emit_c_ast$CInitializerList_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CInitializerList_t));
    vader_obj_header_init(_a0_obj, 1100u);
    _a0_obj->f_elements = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_emit_c_ast$is_empty(void* l0) {
    int64_t l1, l2;
    l1 = vader_emit_c_ast$leading_directives(((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body);
    l2 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body)->length;
    return l1 == l2;
}

bool vader_emit_c_ast$is_most_negative(void* l0) {
    int64_t t0;
    if (((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) l0)->f_class == INT32_C(3)) {
        t0 = ((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) l0)->f_value;
        return t0 == INT64_MIN;
    }
    t0 = ((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) l0)->f_value;
    return t0 == INT64_C(-2147483648);
}

static bool vader_emit_c_ast$is_table(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t l4, l5;
    void* t0;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l4.tag == 1088u) {
            t0 = l4.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CDesignated_t*) t0)->f_value;
        } else {
            l5 = l4;
        }
        if (!(l5.tag == 1100u)) {
            return false;
        }
        l3 = (l3 + INT64_C(1));
    }
    return true;
}

static vader_string_t vader_emit_c_ast$labelled(vader_string_t l0, vader_string_t l1) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == 0u) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = concat_3(l0, 463u, l1);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_emit_c_ast$leading_directives(void* l0) {
    int64_t l1, l2;
    vader_box_t t0;
    l1 = INT64_C(0);
    for (;;) {
        l2 = ((vader_array_t*) l0)->length;
        if ((l1 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
            if (!(t0.tag == 1089u)) {
                break;
            }
            l1 = vader_chk_add(i64, l1, INT64_C(1));
            continue;
        }
        break;
    }
    return l1;
}

static vader_box_t vader_emit_c_ast$loop_of(void* l0) {
    void* l1 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int64_t l2, l3;
    vader_box_t l4 = vader_box_null(), l9 = vader_box_null();
    bool l5;
    vader_string_t l6 = 0;
    vader_string_t l8 = 0;
    int64_t t0, t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    bool t4;
    vader_box_t* gc_roots[2] = { &l4, &l9 };
    void** gc_raw_roots[5] = { &l0, &l1, &l7, &l10, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l8, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_emit_c_ast$CBlock_t*) ((vader_struct_vader_emit_c_ast$CScope_t*) l0)->f_body)->f_body;
    l2 = vader_emit_c_ast$leading_directives(l1);
    l3 = vader_emit_c_ast$trailing_directives(l1, l2);
    t0 = ((vader_array_t*) l1)->length;
    t1 = vader_chk_sub(i64, t0, l2);
    t0 = vader_chk_sub(i64, t1, l3);
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 1097u) {
            t2 = l4.payload.obj;
            t3 = ((vader_struct_vader_emit_c_ast$CIf_t*) t2)->f_end_label;
            if (t3 == 0u) {
                l5 = true;
            } else {
                t3 = ((vader_struct_vader_emit_c_ast$CScope_t*) l0)->f_end_label;
                l5 = t3 == 0u;
            }
        } else {
            l5 = false;
        }
        if (l5) {
            t2 = l4.payload.obj;
            t3 = ((vader_struct_vader_emit_c_ast$CIf_t*) t2)->f_end_label;
            if (t3 == 0u) {
                l6 = ((vader_struct_vader_emit_c_ast$CScope_t*) l0)->f_end_label;
            } else {
                t2 = l4.payload.obj;
                l6 = ((vader_struct_vader_emit_c_ast$CIf_t*) t2)->f_end_label;
            }
            l7 = l4.payload.obj;
            t2 = l4.payload.obj;
            l8 = ((vader_struct_vader_emit_c_ast$CIf_t*) t2)->f_end_label;
            l9 = vader_emit_c_ast$negated(l7, l8);
            if (l9.tag == 0u) {
                l7 = l4.payload.obj;
            } else {
                l7 = l9.payload.obj;
            }
            if (((vader_struct_vader_emit_c_ast$CIf_t*) l7)->f_else_block.tag == 0u) {
                t4 = vader_emit_c_ast$ends_with_continue(((vader_struct_vader_emit_c_ast$CIf_t*) l7)->f_then_block);
                if (t4) {
                    l8 = ((vader_struct_vader_emit_c_ast$CScope_t*) l0)->f_label;
                    l10 = ((vader_struct_vader_emit_c_ast$CIf_t*) l7)->f_then_block;
                    l10 = vader_emit_c_ast$spliced(l1, l2, l3, l10);
                    l4 = ((vader_struct_vader_emit_c_ast$CIf_t*) l7)->f_condition;
                    vader_struct_vader_emit_c_ast$CWhile_t* _a1_obj = (vader_struct_vader_emit_c_ast$CWhile_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CWhile_t));
                    vader_obj_header_init(_a1_obj, 1125u);
                    _a1_obj->f_label = l8;
                    _a1_obj->f_body = l10;
                    _a1_obj->f_condition = l4;
                    _a1_obj->f_end_label = l6;
                    t2 = (void*) _a1_obj;
                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
        }
    }
    vader_array_t* _a2_arr = vader_array_new(366u, 0u, 13u, 2051u);
    t2 = (void*) _a2_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a3_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a3_obj, 1076u);
    _a3_obj->f_body = t2;
    l7 = (void*) _a3_obj;
    vader_array_push_all((vader_array_t*) ((vader_struct_vader_emit_c_ast$CBlock_t*) l7)->f_body, (vader_array_t*) l1);
    t4 = vader_emit_c_ast$end_is_reachable(l1);
    if (t4) {
        l1 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l7)->f_body;
        vader_struct_vader_emit_c_ast$CBreak_t* _a4_obj = (vader_struct_vader_emit_c_ast$CBreak_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBreak_t));
        vader_obj_header_init(_a4_obj, 1077u);
        _a4_obj->f_condition = vader_box_obj(0u, NULL);
        l10 = (void*) _a4_obj;
        vader_array_push_ref((vader_array_t*) l1, l10);
    }
    l6 = ((vader_struct_vader_emit_c_ast$CScope_t*) l0)->f_label;
    l8 = ((vader_struct_vader_emit_c_ast$CScope_t*) l0)->f_end_label;
    vader_struct_vader_emit_c_ast$CFor_t* _a5_obj = (vader_struct_vader_emit_c_ast$CFor_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFor_t));
    vader_obj_header_init(_a5_obj, 1092u);
    _a5_obj->f_label = l6;
    _a5_obj->f_body = l7;
    _a5_obj->f_end_label = l8;
    t2 = (void*) _a5_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_emit_c_ast$mentions_local(vader_box_t l0, int32_t l1) {
    bool l2, l3;
    void* t0;
    int32_t t1;
    bool t2;
    if (l0.tag == 1102u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_emit_c_ast$CLocal_t*) t0)->f_slot;
        l2 = t1 == l1;
        return l2;
    }
    if ((l0.tag == 1101u || l0.tag == 1121u || l0.tag == 1124u)) {
        l2 = false;
    } else if (l0.tag == 1078u) {
        t0 = l0.payload.obj;
        l2 = vader_emit_c_ast$any_mentions_local(((vader_struct_vader_emit_c_ast$CCall_t*) t0)->f_arguments, l1);
    } else if (l0.tag == 1080u) {
        t0 = l0.payload.obj;
        l2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CCast_t*) t0)->f_value, l1);
    } else if (l0.tag == 1081u) {
        t0 = l0.payload.obj;
        l2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CCastToTypeOf_t*) t0)->f_value, l1);
    } else if (l0.tag == 1075u) {
        t0 = l0.payload.obj;
        t2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_left, l1);
        if (t2) {
            l2 = true;
        } else {
            t0 = l0.payload.obj;
            l2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_right, l1);
        }
    } else if (l0.tag == 1122u) {
        t0 = l0.payload.obj;
        l2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CUnary_t*) t0)->f_operand, l1);
    } else if (l0.tag == 1073u) {
        t0 = l0.payload.obj;
        l2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CAddressOf_t*) t0)->f_operand, l1);
    } else if (l0.tag == 1108u) {
        t0 = l0.payload.obj;
        l2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CParenthesized_t*) t0)->f_inner, l1);
    } else if (l0.tag == 1104u) {
        t0 = l0.payload.obj;
        l2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CMember_t*) t0)->f_base, l1);
    } else if (l0.tag == 1099u) {
        t0 = l0.payload.obj;
        t2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CIndex_t*) t0)->f_base, l1);
        if (t2) {
            l2 = true;
        } else {
            t0 = l0.payload.obj;
            l2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CIndex_t*) t0)->f_index, l1);
        }
    } else if (l0.tag == 1083u) {
        t0 = l0.payload.obj;
        t2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_condition, l1);
        if (t2) {
            l3 = true;
        } else {
            t0 = l0.payload.obj;
            l3 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_then_value, l1);
        }
        if (l3) {
            l2 = true;
        } else {
            t0 = l0.payload.obj;
            l2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_else_value, l1);
        }
    } else if (l0.tag == 1100u) {
        t0 = l0.payload.obj;
        l2 = vader_emit_c_ast$any_mentions_local(((vader_struct_vader_emit_c_ast$CInitializerList_t*) t0)->f_elements, l1);
    } else if (l0.tag == 1082u) {
        t0 = l0.payload.obj;
        l2 = vader_emit_c_ast$any_mentions_local(((vader_struct_vader_emit_c_ast$CCompoundLiteral_t*) t0)->f_elements, l1);
    } else if (l0.tag == 1088u) {
        t0 = l0.payload.obj;
        l2 = vader_emit_c_ast$mentions_local(((vader_struct_vader_emit_c_ast$CDesignated_t*) t0)->f_value, l1);
    } else if ((l0.tag == 1105u || l0.tag == 1117u)) {
        l2 = false;
    } else {
        if (!(l0.tag == 1114u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l2 = vader_emit_c_ast$any_mentions_local(((vader_struct_vader_emit_c_ast$CSequence_t*) t0)->f_parts, l1);
    }
    return l2;
}

static vader_box_t vader_emit_c_ast$negated(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_emit_c_ast$CIf_t*) l0)->f_else_block;
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.obj;
    t0 = vader_emit_c_ast$is_empty(((vader_struct_vader_emit_c_ast$CIf_t*) l0)->f_then_block);
    if (t0) {
        t0 = vader_emit_c_ast$is_empty(l2);
        if (!(t0)) {
            l3 = ((vader_struct_vader_emit_c_ast$CIf_t*) l0)->f_condition;
            vader_struct_vader_emit_c_ast$CUnary_t* _a0_obj = (vader_struct_vader_emit_c_ast$CUnary_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CUnary_t));
            vader_obj_header_init(_a0_obj, 1122u);
            _a0_obj->f_operator = 246u;
            _a0_obj->f_operand = l3;
            t1 = (void*) _a0_obj;
            vader_struct_vader_emit_c_ast$CIf_t* _a1_obj = (vader_struct_vader_emit_c_ast$CIf_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIf_t));
            vader_obj_header_init(_a1_obj, 1097u);
            _a1_obj->f_condition = vader_ref_box(t1);
            _a1_obj->f_then_block = l2;
            _a1_obj->f_else_block = vader_box_obj(0u, NULL);
            _a1_obj->f_end_label = l1;
            t1 = (void*) _a1_obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_box_t vader_emit_c_ast$number(int64_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CNumber_t* _a0_obj = (vader_struct_vader_emit_c_ast$CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CNumber_t));
    vader_obj_header_init(_a0_obj, 1105u);
    _a0_obj->f_value = l0;
    _a0_obj->f_unsigned = false;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_emit_c_ast$order_by_first(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int64_t l2, l3;
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 8u, 451u);
    l1 = (void*) _a0_arr;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    vader_array_t* _pc7_hdr = (vader_array_t*) l1;
    size_t _pc7_len = _pc7_hdr->length;
    size_t _pc7_cap = (_pc7_hdr->offset == 0 && !vader_array_is_borrowed(_pc7_hdr) && _pc7_hdr->length >= _pc7_hdr->buf->length) ? _pc7_hdr->capacity : (size_t) 0;
    void* _pc7_slots = _pc7_hdr->buf->slots;
    for (;;) {
        if ((l2 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l2];
            if ((t0 >= INT32_C(0))) {
                if (VADER_LIKELY(_pc7_len < _pc7_cap)) {
                    ((int64_t*) _pc7_slots)[_pc7_len] = (int64_t) (l2);
                    _pc7_len += 1;
                } else {
                    _pc7_hdr->length = _pc7_len;
                    if (_pc7_hdr->buf->length < _pc7_len) {
                        _pc7_hdr->buf->length = _pc7_len;
                    }
                    vader_array_push_i64((vader_array_t*) l1, l2);
                    _pc7_hdr = (vader_array_t*) l1;
                    _pc7_len = _pc7_hdr->length;
                    _pc7_cap = (_pc7_hdr->offset == 0 && !vader_array_is_borrowed(_pc7_hdr) && _pc7_hdr->length >= _pc7_hdr->buf->length) ? _pc7_hdr->capacity : (size_t) 0;
                    _pc7_slots = _pc7_hdr->buf->slots;
                }
            }
            l2 = (l2 + INT64_C(1));
            continue;
        }
        _pc7_hdr->length = _pc7_len;
        if (_pc7_hdr->buf->length < _pc7_len) {
            _pc7_hdr->buf->length = _pc7_len;
        }
        break;
    }
    vader_struct___lambda_env_vader_emit_c_ast_1_t* _a2_obj = (vader_struct___lambda_env_vader_emit_c_ast_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_emit_c_ast_1_t));
    vader_obj_header_init(_a2_obj, 486u);
    _a2_obj->f_cap_0 = l0;
    t1 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 423u);
    _a3_closure->code = (void*) &vader_fn_lift___lambda_vader_emit_c_ast_0;
    _a3_closure->env = t1;
    l4 = (void*) _a3_closure;
    t1 = std_sort$sort__i64(l1, l4);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_emit_c_ast$perform(vader_string_t l0, void* l1) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c_ast$call(l0, l1);
    vader_struct_vader_emit_c_ast$CExpressionStatement_t* _a0_obj = (vader_struct_vader_emit_c_ast$CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CExpressionStatement_t));
    vader_obj_header_init(_a0_obj, 1090u);
    _a0_obj->f_expression = t0;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_emit_c_ast$pointer_member(vader_string_t l0, vader_box_t l1, vader_string_t l2) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_emit_c_ast$cast(l0, l1);
    vader_struct_vader_emit_c_ast$CParenthesized_t* _a0_obj = (vader_struct_vader_emit_c_ast$CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CParenthesized_t));
    vader_obj_header_init(_a0_obj, 1108u);
    _a0_obj->f_inner = t0;
    t1 = (void*) _a0_obj;
    vader_struct_vader_emit_c_ast$CMember_t* _a1_obj = (vader_struct_vader_emit_c_ast$CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CMember_t));
    vader_obj_header_init(_a1_obj, 1104u);
    _a1_obj->f_base = vader_ref_box(t1);
    _a1_obj->f_member = l2;
    _a1_obj->f_arrow = true;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_emit_c_ast$print_item(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(367u, 1u, 13u, 2055u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l1.payload.obj;
    l3 = (void*) _a1_arr;
    vader_struct_vader_emit_c_ast$CSection_t* _a2_obj = (vader_struct_vader_emit_c_ast$CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CSection_t));
    vader_obj_header_init(_a2_obj, 1113u);
    _a2_obj->f_comment = l2;
    _a2_obj->f_items = l3;
    l2 = (void*) _a2_obj;
    vader_emit_c_ast$print_section(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_emit_c_ast$print_section(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    vader_string_t l3 = 0;
    int64_t l4, l5, l9;
    bool l6, l7;
    vader_box_t l10 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l10, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CSection_t*) l1)->f_items)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 741u);
    _a1_obj->f_parts = t1;
    l2 = (void*) _a1_obj;
    t2 = ((vader_struct_vader_emit_c_ast$CPrinter_t*) l0)->f_started;
    if (t2) {
        std_string__builder$append(l2, 1u);
    }
    ((vader_struct_vader_emit_c_ast$CPrinter_t*) l0)->f_started = true;
    t0 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CSection_t*) l1)->f_comment)->length;
    if ((t0 > INT64_C(0))) {
        l3 = std_string$join(((vader_struct_vader_emit_c_ast$CSection_t*) l1)->f_comment, 6u);
        l3 = concat_3(443u, l3, 60u);
        std_string__builder$append(l2, l3);
    }
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CSection_t*) l1)->f_items)->length;
    while ((l4 < l5)) {
        if ((l4 > INT64_C(0))) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CSection_t*) l1)->f_items);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
            t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            if (t3.tag == 1093u) {
                l7 = true;
            } else {
                l8 = ((vader_struct_vader_emit_c_ast$CSection_t*) l1)->f_items;
                l9 = vader_chk_sub(i64, l4, INT64_C(1));
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
                t3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
                l7 = t3.tag == 1093u;
            }
            l6 = l7;
        } else {
            l6 = false;
        }
        if (l6) {
            std_string__builder$append(l2, 1u);
        }
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CSection_t*) l1)->f_items);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
        l10 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
        vader_emit_c_ast$write_top_level(l2, l10);
        l4 = (l4 + INT64_C(1));
    }
    l8 = ((vader_struct_vader_emit_c_ast$CPrinter_t*) l0)->f_out;
    l3 = std_string__builder$StringBuilder$std_core$Display$to_string(l2);
    std_string__builder$append(l8, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

vader_string_t vader_emit_c_ast$printed_text(void* l0) {
    vader_string_t t0;
    t0 = std_string__builder$StringBuilder$std_core$Display$to_string(((vader_struct_vader_emit_c_ast$CPrinter_t*) l0)->f_out);
    return t0;
}

static void vader_emit_c_ast$push_tail_labels(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    vader_string_t l3 = 0;
    bool l5;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l2, &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c_ast$tail_statement(((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body);
    if (l2.tag == 1097u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_end_label;
        if (t1 != 0u) {
            t0 = l2.payload.obj;
            l3 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_end_label;
            vader_array_push_scalar((vader_array_t*) l1, vader_box_string(447u, l3));
        }
        t0 = l2.payload.obj;
        vader_emit_c_ast$push_tail_labels(((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_then_block, l1);
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_else_block;
        if (!(l4.tag == 0u)) {
            t0 = l4.payload.obj;
            vader_emit_c_ast$push_tail_labels(t0, l1);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 1112u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_end_label;
        if (t1 != 0u) {
            t0 = l2.payload.obj;
            l3 = ((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_end_label;
            vader_array_push_scalar((vader_array_t*) l1, vader_box_string(447u, l3));
        }
        t0 = l2.payload.obj;
        vader_emit_c_ast$push_tail_labels(((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_body, l1);
    } else {
        if (l2.tag == 1125u) {
            t0 = l2.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_end_label;
            l5 = t1 != 0u;
        } else {
            l5 = false;
        }
        if (l5) {
            t0 = l2.payload.obj;
            l3 = ((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_end_label;
            vader_array_push_scalar((vader_array_t*) l1, vader_box_string(447u, l3));
        } else if (l2.tag == 1092u) {
            t0 = l2.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CFor_t*) t0)->f_end_label;
            if (t1 != 0u) {
                t0 = l2.payload.obj;
                l3 = ((vader_struct_vader_emit_c_ast$CFor_t*) t0)->f_end_label;
                vader_array_push_scalar((vader_array_t*) l1, vader_box_string(447u, l3));
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

vader_box_t vader_emit_c_ast$returning(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(198u, 0u, 13u, 1074u);
    l2 = (void*) _a0_arr;
    l3 = vader_emit_c_ast$call(l0, l1);
    vader_struct_vader_emit_c_ast$CReturn_t* _a1_obj = (vader_struct_vader_emit_c_ast$CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CReturn_t));
    vader_obj_header_init(_a1_obj, 1111u);
    _a1_obj->f_stores = l2;
    _a1_obj->f_value = l3;
    _a1_obj->f_snapshot_type = 0u;
    _a1_obj->f_pops_frame = false;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c_ast$rewrite_block(void* l0, void* l1) {
    int64_t l2, l3, l4;
    vader_box_t l5 = vader_box_null(), l8 = vader_box_null(), l14 = vader_box_null();
    bool l6;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    vader_string_t l12 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[3] = { &l5, &l8, &l14 };
    void** gc_raw_roots[8] = { &l0, &l1, &l7, &l9, &l10, &l11, &l13, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l12, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c_ast$statements_end(((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body);
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = vader_chk_add(i64, l3, INT64_C(1));
        l6 = t0 == l2;
        if (l5.tag == 1097u) {
            t1 = l5.payload.obj;
            t2 = ((vader_struct_vader_emit_c_ast$CIf_t*) t1)->f_end_label;
            l7 = vader_emit_c_ast$exits_after(t2, l1, l6);
            t1 = l5.payload.obj;
            vader_emit_c_ast$rewrite_block(((vader_struct_vader_emit_c_ast$CIf_t*) t1)->f_then_block, l7);
            t1 = l5.payload.obj;
            l8 = ((vader_struct_vader_emit_c_ast$CIf_t*) t1)->f_else_block;
            if (!(l8.tag == 0u)) {
                t1 = l8.payload.obj;
                vader_emit_c_ast$rewrite_block(t1, l7);
            }
        } else if (l5.tag == 1112u) {
            t1 = l5.payload.obj;
            t2 = ((vader_struct_vader_emit_c_ast$CScope_t*) t1)->f_end_label;
            l9 = vader_emit_c_ast$exits_after(t2, l1, l6);
            t1 = l5.payload.obj;
            vader_emit_c_ast$rewrite_block(((vader_struct_vader_emit_c_ast$CScope_t*) t1)->f_body, l9);
            t1 = l5.payload.obj;
            t2 = ((vader_struct_vader_emit_c_ast$CScope_t*) t1)->f_label;
            if (t2 != 0u) {
                l10 = std_iter$clone__string(l9);
                t1 = l5.payload.obj;
                vader_emit_c_ast$push_tail_labels(((vader_struct_vader_emit_c_ast$CScope_t*) t1)->f_body, l10);
                t1 = l5.payload.obj;
                l11 = ((vader_struct_vader_emit_c_ast$CScope_t*) t1)->f_body;
                t1 = l5.payload.obj;
                l12 = ((vader_struct_vader_emit_c_ast$CScope_t*) t1)->f_label;
                vader_emit_c_ast$substitute_jumps(l11, l12, l10);
                l13 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body;
                t1 = l5.payload.obj;
                l14 = vader_emit_c_ast$loop_of(t1);
                vader_array_t* _a1_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
                vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3, l14.payload.obj);
                VADER_WRITE_BARRIER(_a1_slotarr->buf);
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

bool vader_emit_c_ast$same_expression(vader_box_t l0, vader_box_t l1) {
    bool l2, l7, l12, l17;
    int32_t l3, l4;
    vader_string_t l5, l6;
    uint8_t l8, l9;
    int64_t l10, l11;
    void* l13;
    void* l14;
    vader_box_t l15, l16;
    void* t0;
    if (l0.tag == 1121u) {
        if (l1.tag == 1121u) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_emit_c_ast$CTemporary_t*) t0)->f_id;
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_emit_c_ast$CTemporary_t*) t0)->f_id;
            l2 = l3 == l4;
        } else {
            l2 = false;
        }
        return l2;
    }
    if (l0.tag == 1102u) {
        if (l1.tag == 1102u) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_emit_c_ast$CLocal_t*) t0)->f_slot;
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_emit_c_ast$CLocal_t*) t0)->f_slot;
            l2 = l3 == l4;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1124u) {
        if (l1.tag == 1124u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CVerbatim_t*) t0)->f_text;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CVerbatim_t*) t0)->f_text;
            l2 = l5 == l6;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1101u) {
        if (l1.tag == 1101u) {
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) t0)->f_class;
            t0 = l0.payload.obj;
            l9 = ((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) t0)->f_class;
            l7 = l8 == l9;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l1.payload.obj;
            l10 = ((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) t0)->f_value;
            t0 = l0.payload.obj;
            l11 = ((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) t0)->f_value;
            l2 = l10 == l11;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1105u) {
        if (l1.tag == 1105u) {
            t0 = l1.payload.obj;
            l10 = ((vader_struct_vader_emit_c_ast$CNumber_t*) t0)->f_value;
            t0 = l0.payload.obj;
            l11 = ((vader_struct_vader_emit_c_ast$CNumber_t*) t0)->f_value;
            l7 = l10 == l11;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_emit_c_ast$CNumber_t*) t0)->f_unsigned;
            t0 = l0.payload.obj;
            l12 = ((vader_struct_vader_emit_c_ast$CNumber_t*) t0)->f_unsigned;
            l2 = l7 == l12;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1078u) {
        if (l1.tag == 1078u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CCall_t*) t0)->f_callee;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CCall_t*) t0)->f_callee;
            l7 = l5 == l6;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_emit_c_ast$CCall_t*) t0)->f_arguments;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_emit_c_ast$CCall_t*) t0)->f_arguments;
            l2 = vader_emit_c_ast$same_expressions(l13, l14);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1081u) {
        if (l1.tag == 1081u) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CCastToTypeOf_t*) t0)->f_model;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CCastToTypeOf_t*) t0)->f_model;
            l7 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CCastToTypeOf_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CCastToTypeOf_t*) t0)->f_value;
            l2 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1080u) {
        if (l1.tag == 1080u) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_emit_c_ast$CCast_t*) t0)->f_types;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_emit_c_ast$CCast_t*) t0)->f_types;
            l7 = std_core$content_equals__string(l13, l14);
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CCast_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CCast_t*) t0)->f_value;
            l2 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1075u) {
        if (l1.tag == 1075u) {
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_operator;
            t0 = l0.payload.obj;
            l9 = ((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_operator;
            l7 = l8 == l9;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_left;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_left;
            l7 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_right;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_right;
            l2 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1073u) {
        if (l1.tag == 1073u) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CAddressOf_t*) t0)->f_operand;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CAddressOf_t*) t0)->f_operand;
            l2 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1122u) {
        if (l1.tag == 1122u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CUnary_t*) t0)->f_operator;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CUnary_t*) t0)->f_operator;
            l7 = l5 == l6;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CUnary_t*) t0)->f_operand;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CUnary_t*) t0)->f_operand;
            l2 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1108u) {
        if (l1.tag == 1108u) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CParenthesized_t*) t0)->f_inner;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CParenthesized_t*) t0)->f_inner;
            l2 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1104u) {
        if (l1.tag == 1104u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CMember_t*) t0)->f_member;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CMember_t*) t0)->f_member;
            l7 = l5 == l6;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_emit_c_ast$CMember_t*) t0)->f_arrow;
            t0 = l0.payload.obj;
            l17 = ((vader_struct_vader_emit_c_ast$CMember_t*) t0)->f_arrow;
            l7 = l12 == l17;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CMember_t*) t0)->f_base;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CMember_t*) t0)->f_base;
            l2 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1099u) {
        if (l1.tag == 1099u) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CIndex_t*) t0)->f_base;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CIndex_t*) t0)->f_base;
            l7 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CIndex_t*) t0)->f_index;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CIndex_t*) t0)->f_index;
            l2 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1083u) {
        if (l1.tag == 1083u) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_condition;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_condition;
            l7 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_then_value;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_then_value;
            l7 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_else_value;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_else_value;
            l2 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1100u) {
        if (l1.tag == 1100u) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_emit_c_ast$CInitializerList_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_emit_c_ast$CInitializerList_t*) t0)->f_elements;
            l2 = vader_emit_c_ast$same_expressions(l13, l14);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1082u) {
        if (l1.tag == 1082u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CCompoundLiteral_t*) t0)->f_type;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CCompoundLiteral_t*) t0)->f_type;
            l7 = l5 == l6;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_emit_c_ast$CCompoundLiteral_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_emit_c_ast$CCompoundLiteral_t*) t0)->f_elements;
            l2 = vader_emit_c_ast$same_expressions(l13, l14);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1088u) {
        if (l1.tag == 1088u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CDesignated_t*) t0)->f_designator;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CDesignated_t*) t0)->f_designator;
            l7 = l5 == l6;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_emit_c_ast$CDesignated_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_emit_c_ast$CDesignated_t*) t0)->f_value;
            l2 = vader_emit_c_ast$same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 1117u) {
        if (l1.tag == 1117u) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_emit_c_ast$CStringLiterals_t*) t0)->f_literals;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_emit_c_ast$CStringLiterals_t*) t0)->f_literals;
            l2 = std_core$content_equals__string(l13, l14);
        } else {
            l2 = false;
        }
    } else {
        if (!(l0.tag == 1114u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        if (l1.tag == 1114u) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_emit_c_ast$CSequence_t*) t0)->f_parts;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_emit_c_ast$CSequence_t*) t0)->f_parts;
            l2 = vader_emit_c_ast$same_expressions(l13, l14);
        } else {
            l2 = false;
        }
    }
    return l2;
}

static bool vader_emit_c_ast$same_expressions(void* l0, void* l1) {
    int64_t l2, l3;
    vader_box_t l4, l5;
    bool t0;
    l2 = ((vader_array_t*) l0)->length;
    l3 = ((vader_array_t*) l1)->length;
    if (l2 != l3) {
        return false;
    }
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
        t0 = vader_emit_c_ast$same_expression(l4, l5);
        if (!(t0)) {
            return false;
        }
        l2 = (l2 + INT64_C(1));
    }
    return true;
}

static void vader_emit_c_ast$scan_block(void* l0, void* l1) {
    vader_emit_c_ast$scan_statements(((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body, l1);
    return;
}

static void vader_emit_c_ast$scan_clause(void* l0, void* l1) {
    void* l2;
    void* l6;
    void* l9;
    int64_t l3, l4, l7, l8;
    vader_box_t l5, l10, l11;
    void* t0;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 1090u) {
            t0 = l5.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CExpressionStatement_t*) t0)->f_expression, l1);
        } else if (l5.tag == 1111u) {
            t0 = l5.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CReturn_t*) t0)->f_stores;
            l7 = ((vader_array_t*) l6)->length;
            l8 = INT64_C(0);
            while ((l8 < l7)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l9 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CAssign_t*) l9)->f_target, l1);
                vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CAssign_t*) l9)->f_value, l1);
                l8 = (l8 + INT64_C(1));
            }
            t0 = l5.payload.obj;
            l10 = ((vader_struct_vader_emit_c_ast$CReturn_t*) t0)->f_value;
            if (!(l10.tag == 0u)) {
                vader_emit_c_ast$scan_expression(l10, l1);
            }
        } else {
            if (!(l5.tag == 1096u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l5.payload.obj;
            l11 = ((vader_struct_vader_emit_c_ast$CGoto_t*) t0)->f_condition;
            if (!(l11.tag == 0u)) {
                vader_emit_c_ast$scan_expression(l11, l1);
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    return;
}

static void vader_emit_c_ast$scan_expression(vader_box_t l0, void* l1) {
    int64_t l2, l5;
    void* l3;
    int32_t l4;
    void* t0;
    int32_t t1;
    vader_box_t t2;
    if (l0.tag == 1121u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_emit_c_ast$CTemporary_t*) t0)->f_id;
        l2 = ((int64_t) (int32_t) t1);
        l3 = ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l1)->f_uses;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l1)->f_uses);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
        l4 = vader_chk_add(i32, t1, INT32_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l2] = (int32_t) l4;
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l1)->f_first);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l2];
        if ((t1 < INT32_C(0))) {
            l3 = ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l1)->f_first;
            l4 = ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l1)->f_position;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
            ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l2] = (int32_t) l4;
        }
        l3 = ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l1)->f_last;
        l4 = ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l1)->f_position;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l2)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l2] = (int32_t) l4;
        return;
    }
    if (!((l0.tag == 1101u || l0.tag == 1102u || l0.tag == 1124u))) {
        if (l0.tag == 1078u) {
            t0 = l0.payload.obj;
            l3 = ((vader_struct_vader_emit_c_ast$CCall_t*) t0)->f_arguments;
            l2 = ((vader_array_t*) l3)->length;
            l5 = INT64_C(0);
            while ((l5 < l2)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                t2 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
                vader_emit_c_ast$scan_expression(t2, l1);
                l5 = (l5 + INT64_C(1));
            }
        } else if (l0.tag == 1080u) {
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CCast_t*) t0)->f_value, l1);
        } else if (l0.tag == 1081u) {
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CCastToTypeOf_t*) t0)->f_value, l1);
        } else if (l0.tag == 1075u) {
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_left, l1);
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_right, l1);
        } else if (l0.tag == 1122u) {
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CUnary_t*) t0)->f_operand, l1);
        } else if (l0.tag == 1073u) {
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CAddressOf_t*) t0)->f_operand, l1);
        } else if (l0.tag == 1108u) {
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CParenthesized_t*) t0)->f_inner, l1);
        } else if (l0.tag == 1104u) {
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CMember_t*) t0)->f_base, l1);
        } else if (l0.tag == 1099u) {
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CIndex_t*) t0)->f_base, l1);
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CIndex_t*) t0)->f_index, l1);
        } else if (l0.tag == 1083u) {
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_condition, l1);
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_then_value, l1);
            t0 = l0.payload.obj;
            vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_else_value, l1);
        } else if (!((l0.tag == 1105u || l0.tag == 1117u))) {
            if (l0.tag == 1088u) {
                t0 = l0.payload.obj;
                vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CDesignated_t*) t0)->f_value, l1);
            } else if (l0.tag == 1082u) {
                t0 = l0.payload.obj;
                l3 = ((vader_struct_vader_emit_c_ast$CCompoundLiteral_t*) t0)->f_elements;
                l2 = ((vader_array_t*) l3)->length;
                l5 = INT64_C(0);
                while ((l5 < l2)) {
                    vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                    t2 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
                    vader_emit_c_ast$scan_expression(t2, l1);
                    l5 = (l5 + INT64_C(1));
                }
            } else if (l0.tag == 1100u) {
                t0 = l0.payload.obj;
                l3 = ((vader_struct_vader_emit_c_ast$CInitializerList_t*) t0)->f_elements;
                l2 = ((vader_array_t*) l3)->length;
                l5 = INT64_C(0);
                while ((l5 < l2)) {
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    t2 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
                    vader_emit_c_ast$scan_expression(t2, l1);
                    l5 = (l5 + INT64_C(1));
                }
            } else {
                if (!(l0.tag == 1114u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l0.payload.obj;
                l3 = ((vader_struct_vader_emit_c_ast$CSequence_t*) t0)->f_parts;
                l2 = ((vader_array_t*) l3)->length;
                l5 = INT64_C(0);
                while ((l5 < l2)) {
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                    t2 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l5);
                    vader_emit_c_ast$scan_expression(t2, l1);
                    l5 = (l5 + INT64_C(1));
                }
            }
        }
    }
    return;
}

static void vader_emit_c_ast$scan_statements(void* l0, void* l1) {
    void* l2;
    void* l7;
    void* l11;
    void* l18;
    void* l21;
    int64_t l3, l4, l8, l9, l12, l13, l19, l20;
    vader_box_t l5, l10, l14, l15, l16, l17, l22;
    int32_t l6;
    int32_t t0;
    void* t1;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l1)->f_position;
        l6 = vader_chk_add(i32, t0, INT32_C(1));
        ((vader_struct_vader_emit_c_ast$TemporaryUsage_t*) l1)->f_position = l6;
        if (!(l5.tag == 1089u)) {
            if (l5.tag == 1074u) {
                t1 = l5.payload.obj;
                vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CAssign_t*) t1)->f_target, l1);
                t1 = l5.payload.obj;
                vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CAssign_t*) t1)->f_value, l1);
            } else if (l5.tag == 1090u) {
                t1 = l5.payload.obj;
                vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CExpressionStatement_t*) t1)->f_expression, l1);
            } else if (l5.tag == 1103u) {
                t1 = l5.payload.obj;
                vader_emit_c_ast$scan_expression(vader_ref_box(((vader_struct_vader_emit_c_ast$CMacroStatement_t*) t1)->f_call), l1);
            } else if (l5.tag == 1085u) {
                t1 = l5.payload.obj;
                l7 = ((vader_struct_vader_emit_c_ast$CDeclaration_t*) t1)->f_declarators;
                l8 = ((vader_array_t*) l7)->length;
                l9 = INT64_C(0);
                while ((l9 < l8)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                    l10 = ((vader_struct_vader_emit_c_ast$CDeclarator_t*) t1)->f_value;
                    if (!(l10.tag == 0u)) {
                        vader_emit_c_ast$scan_expression(l10, l1);
                    }
                    l9 = (l9 + INT64_C(1));
                }
            } else if (l5.tag == 1120u) {
                t1 = l5.payload.obj;
                vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CSwitch_t*) t1)->f_subject, l1);
                t1 = l5.payload.obj;
                l11 = ((vader_struct_vader_emit_c_ast$CSwitch_t*) t1)->f_cases;
                l12 = ((vader_array_t*) l11)->length;
                l13 = INT64_C(0);
                while ((l13 < l12)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l13);
                    vader_emit_c_ast$scan_clause(((vader_struct_vader_emit_c_ast$CCase_t*) t1)->f_body, l1);
                    l13 = (l13 + INT64_C(1));
                }
                t1 = l5.payload.obj;
                l14 = ((vader_struct_vader_emit_c_ast$CSwitch_t*) t1)->f_default_body;
                if (!(l14.tag == 0u)) {
                    t1 = l14.payload.obj;
                    vader_emit_c_ast$scan_clause(t1, l1);
                }
            } else if (l5.tag == 1096u) {
                t1 = l5.payload.obj;
                l15 = ((vader_struct_vader_emit_c_ast$CGoto_t*) t1)->f_condition;
                if (!(l15.tag == 0u)) {
                    vader_emit_c_ast$scan_expression(l15, l1);
                }
            } else if (l5.tag == 1097u) {
                t1 = l5.payload.obj;
                vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CIf_t*) t1)->f_condition, l1);
                t1 = l5.payload.obj;
                vader_emit_c_ast$scan_block(((vader_struct_vader_emit_c_ast$CIf_t*) t1)->f_then_block, l1);
                t1 = l5.payload.obj;
                l16 = ((vader_struct_vader_emit_c_ast$CIf_t*) t1)->f_else_block;
                if (!(l16.tag == 0u)) {
                    t1 = l16.payload.obj;
                    vader_emit_c_ast$scan_block(t1, l1);
                }
            } else if (l5.tag == 1112u) {
                t1 = l5.payload.obj;
                vader_emit_c_ast$scan_block(((vader_struct_vader_emit_c_ast$CScope_t*) t1)->f_body, l1);
            } else if (l5.tag == 1125u) {
                t1 = l5.payload.obj;
                vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CWhile_t*) t1)->f_condition, l1);
                t1 = l5.payload.obj;
                vader_emit_c_ast$scan_block(((vader_struct_vader_emit_c_ast$CWhile_t*) t1)->f_body, l1);
            } else if (l5.tag == 1092u) {
                t1 = l5.payload.obj;
                vader_emit_c_ast$scan_block(((vader_struct_vader_emit_c_ast$CFor_t*) t1)->f_body, l1);
            } else if ((l5.tag == 1077u || l5.tag == 1084u)) {
                l17 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_emit_c_ast$CBreak_t, f_condition, l5.payload.obj);
                if (!(l17.tag == 0u)) {
                    vader_emit_c_ast$scan_expression(l17, l1);
                }
            } else {
                if (!(l5.tag == 1111u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t1 = l5.payload.obj;
                l18 = ((vader_struct_vader_emit_c_ast$CReturn_t*) t1)->f_stores;
                l19 = ((vader_array_t*) l18)->length;
                l20 = INT64_C(0);
                while ((l20 < l19)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l18);
                    VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                    l21 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l20);
                    vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CAssign_t*) l21)->f_target, l1);
                    vader_emit_c_ast$scan_expression(((vader_struct_vader_emit_c_ast$CAssign_t*) l21)->f_value, l1);
                    l20 = (l20 + INT64_C(1));
                }
                t1 = l5.payload.obj;
                l22 = ((vader_struct_vader_emit_c_ast$CReturn_t*) t1)->f_value;
                if (!(l22.tag == 0u)) {
                    vader_emit_c_ast$scan_expression(l22, l1);
                }
            }
        }
        l4 = (l4 + INT64_C(1));
    }
    return;
}

static void* vader_emit_c_ast$spliced(void* l0, int64_t l1, int64_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t l7, l8, l9;
    vader_box_t l10 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[6] = { &l0, &l3, &l4, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(366u, 0u, 13u, 2051u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_emit_c_ast$CBlock_t* _a1_obj = (vader_struct_vader_emit_c_ast$CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBlock_t));
    vader_obj_header_init(_a1_obj, 1076u);
    _a1_obj->f_body = t0;
    l4 = (void*) _a1_obj;
    l5 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l4)->f_body;
    vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l0, (int64_t) INT64_C(0), (int64_t) l1);
    l6 = (void*) _a2_arr;
    vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l6);
    t1 = vader_emit_c_ast$statements_end(((vader_struct_vader_emit_c_ast$CBlock_t*) l3)->f_body);
    l7 = vader_chk_sub(i64, t1, INT64_C(1));
    l8 = INT64_C(0);
    l9 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CBlock_t*) l3)->f_body)->length;
    while ((l8 < l9)) {
        if (l8 != l7) {
            l5 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l4)->f_body;
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CBlock_t*) l3)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l8)
            l10 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
            vader_array_push_ref((vader_array_t*) l5, l10.payload.obj);
        }
        l8 = (l8 + INT64_C(1));
    }
    l5 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l4)->f_body;
    t1 = ((vader_array_t*) l0)->length;
    l7 = vader_chk_sub(i64, t1, l2);
    l8 = ((vader_array_t*) l0)->length;
    vader_array_t* _a4_arr = vader_array_slice((vader_array_t*) l0, (int64_t) l7, (int64_t) l8);
    l6 = (void*) _a4_arr;
    vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l6);
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_emit_c_ast$statements_end(void* l0) {
    int64_t l1, l2;
    int64_t t0;
    l1 = ((vader_array_t*) l0)->length;
    l2 = vader_emit_c_ast$trailing_directives(l0, INT64_C(0));
    t0 = vader_chk_sub(i64, l1, l2);
    return t0;
}

static vader_string_t vader_emit_c_ast$storage_keyword(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 2586u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 0u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1952u;
    }
    return l1;
}

void vader_emit_c_ast$structure_loops(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    l1 = (void*) _a0_arr;
    vader_emit_c_ast$rewrite_block(l0, l1);
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 0u, 447u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(20u, 0u, 12u, 445u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(23u, 0u, 7u, 450u);
    l3 = (void*) _a3_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a4_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a4_obj, 662u);
    _a4_obj->f_ekeys = l1;
    _a4_obj->f_evals = l2;
    _a4_obj->f_index = l3;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_grow_at = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a4_obj;
    vader_struct_std_collections$MutableSet__string_t* _a5_obj = (vader_struct_std_collections$MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__string_t));
    vader_obj_header_init(_a5_obj, 730u);
    _a5_obj->f_inner = t0;
    l1 = (void*) _a5_obj;
    vader_emit_c_ast$collect_goto_labels(l0, l1);
    vader_emit_c_ast$tidy_block(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$substitute_jumps(void* l0, vader_string_t l1, void* l2) {
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l11 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[2] = { &l5, &l11 };
    void** gc_raw_roots[7] = { &l0, &l2, &l6, &l7, &l9, &l10, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l8, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body)->length;
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l5.tag == 1096u) {
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CGoto_t*) t0)->f_label;
            if (t1 == l1) {
                l6 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body;
                t0 = l5.payload.obj;
                vader_struct_vader_emit_c_ast$CContinue_t* _a1_obj = (vader_struct_vader_emit_c_ast$CContinue_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CContinue_t));
                vader_obj_header_init(_a1_obj, 1084u);
                _a1_obj->f_condition = ((vader_struct_vader_emit_c_ast$CGoto_t*) t0)->f_condition;
                l7 = (void*) _a1_obj;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3, l7);
                VADER_WRITE_BARRIER(_a2_slotarr->buf);
            } else {
                t0 = l5.payload.obj;
                l8 = ((vader_struct_vader_emit_c_ast$CGoto_t*) t0)->f_label;
                t2 = std_core$$array$Contains$contains__string(l2, l8);
                if (t2) {
                    l9 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body;
                    t0 = l5.payload.obj;
                    vader_struct_vader_emit_c_ast$CBreak_t* _a3_obj = (vader_struct_vader_emit_c_ast$CBreak_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CBreak_t));
                    vader_obj_header_init(_a3_obj, 1077u);
                    _a3_obj->f_condition = ((vader_struct_vader_emit_c_ast$CGoto_t*) t0)->f_condition;
                    l10 = (void*) _a3_obj;
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l9);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l3)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l3, l10);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                }
            }
        } else if (l5.tag == 1097u) {
            t0 = l5.payload.obj;
            vader_emit_c_ast$substitute_jumps(((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_then_block, l1, l2);
            t0 = l5.payload.obj;
            l11 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_else_block;
            if (!(l11.tag == 0u)) {
                t0 = l11.payload.obj;
                vader_emit_c_ast$substitute_jumps(t0, l1, l2);
            }
        } else if (l5.tag == 1112u) {
            t0 = l5.payload.obj;
            vader_emit_c_ast$substitute_jumps(((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_body, l1, l2);
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_emit_c_ast$tail_statement(void* l0) {
    int64_t l1;
    vader_box_t t0;
    l1 = vader_emit_c_ast$statements_end(l0);
    if (!(l1 == INT64_C(0))) {
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        return t0;
    }
    return vader_box_obj(0u, NULL);
}

static vader_string_t vader_emit_c_ast$text_of(vader_box_t l0) {
    void* l1 = NULL;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 447u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 741u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    vader_emit_c_ast$write_expression(l1, l0);
    t1 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c_ast$tidy_block(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l19 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l25 = NULL;
    void* l28 = NULL;
    void* l32 = NULL;
    void* l36 = NULL;
    void* l40 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l9 = vader_box_null(), l12 = vader_box_null(), l14 = vader_box_null(), l33 = vader_box_null(), l41 = vader_box_null();
    vader_string_t l8 = 0;
    vader_string_t l11 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    vader_string_t l20 = 0;
    vader_string_t l22 = 0;
    vader_string_t l26 = 0;
    vader_string_t l27 = 0;
    vader_string_t l29 = 0;
    vader_string_t l31 = 0;
    vader_string_t l34 = 0;
    vader_string_t l35 = 0;
    vader_string_t l37 = 0;
    vader_string_t l39 = 0;
    bool l17, l18, l21, l30, l38;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[7] = { &l6, &l7, &l9, &l12, &l14, &l33, &l41 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l2, &l3, &l10, &l13, &l19, &l23, &l24, &l25, &l28, &l32, &l36, &l40, &t0,
    };
    vader_string_t* gc_atom_roots[15] = {
        &l8, &l11, &l15, &l16, &l20, &l22, &l26, &l27, &l29, &l31, &l34, &l35, &l37, &l39, &t1,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 15u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(366u, 0u, 13u, 2051u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        if (l6.tag == 1097u) {
            t0 = l6.payload.obj;
            vader_emit_c_ast$tidy_block(((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_then_block, l1);
            t0 = l6.payload.obj;
            l7 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_else_block;
            if (!(l7.tag == 0u)) {
                t0 = l7.payload.obj;
                vader_emit_c_ast$tidy_block(t0, l1);
            }
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_end_label;
            l8 = vader_emit_c_ast$used_label(t1, l1);
            t0 = l6.payload.obj;
            l9 = vader_emit_c_ast$negated(t0, l8);
            if (l9.tag == 0u) {
                t0 = l6.payload.obj;
                l11 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_end_label;
                if (l8 == l11) {
                    l10 = l6.payload.obj;
                } else {
                    t0 = l6.payload.obj;
                    l12 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_condition;
                    t0 = l6.payload.obj;
                    l13 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_then_block;
                    t0 = l6.payload.obj;
                    l14 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_else_block;
                    vader_struct_vader_emit_c_ast$CIf_t* _a2_obj = (vader_struct_vader_emit_c_ast$CIf_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CIf_t));
                    vader_obj_header_init(_a2_obj, 1097u);
                    _a2_obj->f_condition = l12;
                    _a2_obj->f_then_block = l13;
                    _a2_obj->f_else_block = l14;
                    _a2_obj->f_end_label = 0u;
                    l10 = (void*) _a2_obj;
                }
            } else {
                l10 = l9.payload.obj;
            }
            vader_array_push_ref((vader_array_t*) l2, l10);
        } else if (l6.tag == 1112u) {
            t0 = l6.payload.obj;
            vader_emit_c_ast$tidy_block(((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_body, l1);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_label;
            l15 = vader_emit_c_ast$used_label(t1, l1);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_end_label;
            l16 = vader_emit_c_ast$used_label(t1, l1);
            if (l15 == 0u) {
                l17 = l16 == 0u;
            } else {
                l17 = false;
            }
            if (l17) {
                t0 = l6.payload.obj;
                t2 = vader_emit_c_ast$declares(((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_body);
                l18 = !(t2);
            } else {
                l18 = false;
            }
            if (l18) {
                t0 = l6.payload.obj;
                l19 = ((vader_struct_vader_emit_c_ast$CBlock_t*) ((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_body)->f_body;
                vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l19);
            } else {
                t0 = l6.payload.obj;
                l20 = ((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_label;
                if (l15 == l20) {
                    t0 = l6.payload.obj;
                    l22 = ((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_end_label;
                    l21 = l16 == l22;
                } else {
                    l21 = false;
                }
                if (l21) {
                    l23 = l6.payload.obj;
                    vader_array_push_ref((vader_array_t*) l2, l23);
                } else {
                    t0 = l6.payload.obj;
                    l24 = ((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_body;
                    vader_struct_vader_emit_c_ast$CScope_t* _a3_obj = (vader_struct_vader_emit_c_ast$CScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CScope_t));
                    vader_obj_header_init(_a3_obj, 1112u);
                    _a3_obj->f_label = l15;
                    _a3_obj->f_body = l24;
                    _a3_obj->f_end_label = l16;
                    l25 = (void*) _a3_obj;
                    vader_array_push_ref((vader_array_t*) l2, l25);
                }
            }
        } else if (l6.tag == 1125u) {
            t0 = l6.payload.obj;
            vader_emit_c_ast$tidy_block(((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_body, l1);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_label;
            l26 = vader_emit_c_ast$used_label(t1, l1);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_end_label;
            l27 = vader_emit_c_ast$used_label(t1, l1);
            t0 = l6.payload.obj;
            l29 = ((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_label;
            if (l26 == l29) {
                t0 = l6.payload.obj;
                l31 = ((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_end_label;
                l30 = l27 == l31;
            } else {
                l30 = false;
            }
            if (l30) {
                l28 = l6.payload.obj;
            } else {
                t0 = l6.payload.obj;
                l32 = ((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_body;
                t0 = l6.payload.obj;
                l33 = ((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_condition;
                vader_struct_vader_emit_c_ast$CWhile_t* _a4_obj = (vader_struct_vader_emit_c_ast$CWhile_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CWhile_t));
                vader_obj_header_init(_a4_obj, 1125u);
                _a4_obj->f_label = l26;
                _a4_obj->f_body = l32;
                _a4_obj->f_condition = l33;
                _a4_obj->f_end_label = l27;
                l28 = (void*) _a4_obj;
            }
            vader_array_push_ref((vader_array_t*) l2, l28);
        } else if (l6.tag == 1092u) {
            t0 = l6.payload.obj;
            vader_emit_c_ast$tidy_block(((vader_struct_vader_emit_c_ast$CFor_t*) t0)->f_body, l1);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CFor_t*) t0)->f_label;
            l34 = vader_emit_c_ast$used_label(t1, l1);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CFor_t*) t0)->f_end_label;
            l35 = vader_emit_c_ast$used_label(t1, l1);
            t0 = l6.payload.obj;
            l37 = ((vader_struct_vader_emit_c_ast$CFor_t*) t0)->f_label;
            if (l34 == l37) {
                t0 = l6.payload.obj;
                l39 = ((vader_struct_vader_emit_c_ast$CFor_t*) t0)->f_end_label;
                l38 = l35 == l39;
            } else {
                l38 = false;
            }
            if (l38) {
                l36 = l6.payload.obj;
            } else {
                t0 = l6.payload.obj;
                l40 = ((vader_struct_vader_emit_c_ast$CFor_t*) t0)->f_body;
                vader_struct_vader_emit_c_ast$CFor_t* _a5_obj = (vader_struct_vader_emit_c_ast$CFor_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CFor_t));
                vader_obj_header_init(_a5_obj, 1092u);
                _a5_obj->f_label = l34;
                _a5_obj->f_body = l40;
                _a5_obj->f_end_label = l35;
                l36 = (void*) _a5_obj;
            }
            vader_array_push_ref((vader_array_t*) l2, l36);
        } else {
            l41 = l6;
            vader_array_push_ref((vader_array_t*) l2, l41.payload.obj);
        }
        l5 = (l5 + INT64_C(1));
    }
    vader_array_clear((vader_array_t*) ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body);
    vader_array_push_all((vader_array_t*) ((vader_struct_vader_emit_c_ast$CBlock_t*) l0)->f_body, (vader_array_t*) l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static int64_t vader_emit_c_ast$trailing_directives(void* l0, int64_t l1) {
    int64_t l2, l3;
    int64_t t0, t1;
    vader_box_t t2;
    l2 = INT64_C(0);
    for (;;) {
        t0 = ((vader_array_t*) l0)->length;
        t1 = vader_chk_sub(i64, t0, l2);
        if ((t1 > l1)) {
            t0 = ((vader_array_t*) l0)->length;
            t1 = vader_chk_sub(i64, t0, INT64_C(1));
            l3 = vader_chk_sub(i64, t1, l2);
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
            if (!(t2.tag == 1089u)) {
                break;
            }
            l2 = vader_chk_add(i64, l2, INT64_C(1));
            continue;
        }
        break;
    }
    return l2;
}

vader_box_t vader_emit_c_ast$unsigned(int64_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CNumber_t* _a0_obj = (vader_struct_vader_emit_c_ast$CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CNumber_t));
    vader_obj_header_init(_a0_obj, 1105u);
    _a0_obj->f_value = l0;
    _a0_obj->f_unsigned = true;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_emit_c_ast$used_label(vader_string_t l0, void* l1) {
    bool t0;
    t0 = std_collections$MutableSet$std_core$Contains$contains__string(l1, l0);
    if (!(t0)) {
        return 0u;
    }
    return l0;
}

vader_box_t vader_emit_c_ast$verbatim(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_emit_c_ast$CVerbatim_t* _a0_obj = (vader_struct_vader_emit_c_ast$CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CVerbatim_t));
    vader_obj_header_init(_a0_obj, 1124u);
    _a0_obj->f_text = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_emit_c_ast$write_assign(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int64_t l4;
    vader_string_t l5 = 0;
    uint8_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c_ast$CAssign_t*) l1)->f_target;
    vader_emit_c_ast$write_expression(l0, l2);
    l2 = ((vader_struct_vader_emit_c_ast$CAssign_t*) l1)->f_operator;
    if (l2.tag == 0u) {
        std_string__builder$append(l0, 81u);
    } else {
        std_string__builder$append(l0, 14u);
        l3 = (void*) &vader_data_54;
        t0 = ((uint8_t) l2.payload.i);
        l4 = ((int64_t) (uint8_t) t0);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_emit_c_ast$COperatorInfo_t*) t1)->f_spelling;
        std_string__builder$append(l0, l5);
        std_string__builder$append(l0, 522u);
    }
    l2 = ((vader_struct_vader_emit_c_ast$CAssign_t*) l1)->f_value;
    vader_emit_c_ast$write_expression(l0, l2);
    std_string__builder$append(l0, 501u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_block(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    int64_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_emit_c_ast$CBlock_t*) l1)->f_body;
    l4 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CBlock_t*) l1)->f_body)->length;
    vader_emit_c_ast$write_statements(l0, l3, INT64_C(0), l4, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_case_body(void* l0, void* l1, bool l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    bool l10;
    vader_string_t l11 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l6, &l7, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l8, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        std_string__builder$append(l0, 14u);
        if (l6.tag == 1090u) {
            t0 = l6.payload.obj;
            l7 = ((vader_struct_vader_emit_c_ast$CExpressionStatement_t*) t0)->f_expression;
            vader_emit_c_ast$write_expression(l0, l7);
            std_string__builder$append(l0, 501u);
        } else if (l6.tag == 1111u) {
            l8 = l6.payload.obj;
            vader_emit_c_ast$write_return_text(l0, l8);
        } else {
            if (!(l6.tag == 1096u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l9 = l6.payload.obj;
            vader_emit_c_ast$write_goto(l0, l9);
        }
        l5 = (l5 + INT64_C(1));
    }
    t1 = ((vader_array_t*) l1)->length;
    if ((t1 > INT64_C(0))) {
        t1 = ((vader_array_t*) l1)->length;
        l4 = vader_chk_sub(i64, t1, INT64_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l10 = (t2.tag == 1096u || t2.tag == 1111u);
    } else {
        l10 = false;
    }
    if (l2) {
        l11 = 1u;
        std_string__builder$append(l0, l11);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l10) {
        l11 = 1u;
        std_string__builder$append(l0, l11);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string__builder$append(l0, 100u);
    l11 = 1u;
    std_string__builder$append(l0, l11);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_closer(void* l0, vader_string_t l1, int32_t l2) {
    vader_string_t l3 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1 == 0u) {
        l3 = 3065u;
        vader_emit_c_ast$write_line(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = concat_3(3066u, l1, 464u);
    vader_emit_c_ast$write_line(l0, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_declaration(void* l0, void* l1, int32_t l2) {
    vader_string_t l3 = 0;
    int64_t l4, l5, l6;
    void* l7 = NULL;
    vader_string_t t0 = 0;
    int64_t t1;
    void** gc_raw_roots[3] = { &l0, &l1, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_emit_c_ast$CDeclaration_t*) l1)->f_type;
    std_string__builder$append(l0, l3);
    std_string__builder$append(l0, 14u);
    l4 = vader_chk_mul(i64, ((int64_t) (int32_t) l2), INT64_C(4));
    t0 = ((vader_struct_vader_emit_c_ast$CDeclaration_t*) l1)->f_type;
    l5 = vader_host_std_core$byte_len(t0);
    t1 = vader_chk_add(i64, l4, l5);
    l4 = vader_chk_add(i64, t1, INT64_C(1));
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CDeclaration_t*) l1)->f_declarators)->length;
    while ((l5 < l6)) {
        if ((l5 > INT64_C(0))) {
            std_string__builder$append(l0, 363u);
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CDeclaration_t*) l1)->f_declarators);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        vader_emit_c_ast$write_declarator(l0, l7, l4, l2);
        l5 = (l5 + INT64_C(1));
    }
    std_string__builder$append(l0, 501u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_declarator(void* l0, void* l1, int64_t l2, int32_t l3) {
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    void* l6 = NULL;
    int64_t l7, l8;
    int32_t t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_emit_c_ast$CDeclarator_t*) l1)->f_length;
    if (l4.tag == 450u) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(22));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, 964u);
        t0 = ((int32_t) l4.payload.i);
        l8 = ((int64_t) (int32_t) t0);
        l7 = std_core$write_int(l6, l7, l8);
        l7 = std_core$write_string_at(l6, l7, 967u);
        l5 = std_core$finish_buffer(l6, l7);
    } else if (l4.tag == 1123u) {
        l5 = 965u;
    } else {
        l5 = 0u;
    }
    t1 = ((vader_struct_vader_emit_c_ast$CDeclarator_t*) l1)->f_name;
    l5 = concat_2(t1, l5);
    l4 = ((vader_struct_vader_emit_c_ast$CDeclarator_t*) l1)->f_value;
    vader_emit_c_ast$write_declared(l0, l5, l4, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_declared(void* l0, vader_string_t l1, vader_box_t l2, int64_t l3, int32_t l4) {
    vader_box_t l5 = vader_box_null();
    int64_t l6;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_string__builder$append(l0, l1);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string__builder$append(l0, 80u);
    l5 = l2;
    l6 = vader_host_std_core$byte_len(l1);
    t0 = vader_chk_add(i64, l3, l6);
    l6 = vader_chk_add(i64, t0, INT64_C(2));
    vader_emit_c_ast$write_initializer(l0, l5, l6, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_directive(void* l0, vader_string_t l1) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_string__builder$append(l0, l1);
    std_string__builder$append(l0, 1u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_element(void* l0, vader_box_t l1, int32_t l2) {
    int64_t l3;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_chk_mul(i64, ((int64_t) (int32_t) l2), INT64_C(4));
    if (l1.tag == 1088u) {
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_emit_c_ast$CDesignated_t*) t0)->f_designator;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_emit_c_ast$CDesignated_t*) t0)->f_value;
        vader_emit_c_ast$write_declared(l0, l4, l5, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l1;
    vader_emit_c_ast$write_initializer_line(l0, l5, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_else_chain(void* l0, void* l1, vader_string_t l2, int32_t l3) {
    vader_box_t l4 = vader_box_null(), l10 = vader_box_null();
    void* l5 = NULL;
    void* l11 = NULL;
    int64_t l6, l7, l8;
    bool l9;
    int32_t l12;
    vader_string_t l13 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l4, &l10 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l11, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l13, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_emit_c_ast$CIf_t*) l1)->f_else_block;
    if (l4.tag == 0u) {
        vader_emit_c_ast$write_closer(l0, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l4.payload.obj;
    l5 = ((vader_struct_vader_emit_c_ast$CBlock_t*) t0)->f_body;
    l6 = vader_emit_c_ast$leading_directives(l5);
    l7 = ((vader_array_t*) l5)->length;
    l8 = vader_emit_c_ast$trailing_directives(l5, l6);
    l7 = vader_chk_sub(i64, l7, l8);
    vader_emit_c_ast$write_statements(l0, l5, INT64_C(0), l6, l3);
    l8 = vader_chk_add(i64, l6, INT64_C(1));
    if (l7 == l8) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    } else {
        l4 = vader_box_obj(0u, NULL);
    }
    if (l4.tag == 1097u) {
        if (l2 == 0u) {
            l9 = true;
        } else {
            t0 = l4.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_end_label;
            l9 = t1 == 0u;
        }
    } else {
        l9 = false;
    }
    if (!(l9)) {
        vader_emit_c_ast$write_line(l0, 3068u, l3);
        l8 = ((vader_array_t*) l5)->length;
        l12 = vader_chk_add(i32, l3, INT32_C(1));
        vader_emit_c_ast$write_statements(l0, l5, l6, l8, l12);
        vader_emit_c_ast$write_closer(l0, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l4.payload.obj;
    l10 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_condition;
    vader_emit_c_ast$write_if_head(l0, 3067u, l10, l3);
    t0 = l4.payload.obj;
    l11 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_then_block;
    l12 = vader_chk_add(i32, l3, INT32_C(1));
    vader_emit_c_ast$write_block(l0, l11, l12);
    l11 = l4.payload.obj;
    if (l2 != 0u) {
        l13 = l2;
    } else {
        t0 = l4.payload.obj;
        l13 = ((vader_struct_vader_emit_c_ast$CIf_t*) t0)->f_end_label;
    }
    vader_emit_c_ast$write_else_chain(l0, l11, l13, l3);
    l6 = ((vader_array_t*) l5)->length;
    vader_emit_c_ast$write_statements(l0, l5, l7, l6, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_expression(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null();
    int32_t l7;
    void* t0 = NULL;
    int32_t t1;
    vader_string_t t2 = 0;
    bool t3;
    vader_box_t t4 = vader_box_null();
    int64_t t5;
    vader_box_t* gc_roots[3] = { &l1, &l6, &t4 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1121u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_emit_c_ast$CTemporary_t*) t0)->f_slot;
        if ((t1 < INT32_C(0))) {
            l2 = (void*) vader_buffer_new((size_t) INT64_C(85));
            l3 = INT64_C(0);
            l3 = std_core$write_string_at(l2, l3, 1694u);
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CTemporary_t*) t0)->f_id;
            l4 = ((int64_t) (int32_t) t1);
            l3 = std_core$write_int(l2, l3, l4);
            l3 = std_core$write_string_at(l2, l3, 204u);
            t2 = std_core$finish_buffer(l2, l3);
            vader_host_std_abort$panic(t2);
            vader_unreachable("a no-return call returned");
        } else {
            std_string__builder$append(l0, 2690u);
            l2 = (void*) vader_buffer_new((size_t) INT64_C(20));
            l3 = INT64_C(0);
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CTemporary_t*) t0)->f_slot;
            l4 = ((int64_t) (int32_t) t1);
            l3 = std_core$write_int(l2, l3, l4);
            l5 = std_core$finish_buffer(l2, l3);
            std_string__builder$append(l0, l5);
            { vader_gc_top = gc_frame.prev; return; }
        }
    } else {
        if (l1.tag == 1102u) {
            std_string__builder$append(l0, 2262u);
            l2 = (void*) vader_buffer_new((size_t) INT64_C(20));
            l3 = INT64_C(0);
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CLocal_t*) t0)->f_slot;
            l4 = ((int64_t) (int32_t) t1);
            l3 = std_core$write_int(l2, l3, l4);
            l5 = std_core$finish_buffer(l2, l3);
            std_string__builder$append(l0, l5);
        } else if (l1.tag == 1124u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CVerbatim_t*) t0)->f_text;
            std_string__builder$append(l0, l5);
        } else if (l1.tag == 1101u) {
            l2 = l1.payload.obj;
            vader_emit_c_ast$write_integer_literal(l0, l2);
        } else if (l1.tag == 1105u) {
            l2 = (void*) vader_buffer_new((size_t) INT64_C(20));
            l3 = INT64_C(0);
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_emit_c_ast$CNumber_t*) t0)->f_value;
            l3 = std_core$write_int(l2, l3, l4);
            l5 = std_core$finish_buffer(l2, l3);
            std_string__builder$append(l0, l5);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_emit_c_ast$CNumber_t*) t0)->f_unsigned;
            if (t3) {
                std_string__builder$append(l0, 2774u);
            }
        } else if (l1.tag == 1078u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CCall_t*) t0)->f_callee;
            std_string__builder$append(l0, l5);
            std_string__builder$append(l0, 307u);
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_emit_c_ast$CCall_t*) t0)->f_arguments;
            vader_emit_c_ast$write_list(l0, l2);
            std_string__builder$append(l0, 324u);
        } else if (l1.tag == 1081u) {
            std_string__builder$append(l0, 315u);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CCastToTypeOf_t*) t0)->f_model;
            vader_emit_c_ast$write_expression(l0, l6);
            std_string__builder$append(l0, 344u);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CCastToTypeOf_t*) t0)->f_value;
            vader_emit_c_ast$write_operand(l0, l6, INT32_C(11));
        } else if (l1.tag == 1080u) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_emit_c_ast$CCast_t*) t0)->f_types;
            l3 = ((vader_array_t*) l2)->length;
            l4 = INT64_C(0);
            while ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                t4 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l4];
                l5 = t4.payload.s;
                std_string__builder$append(l0, 307u);
                std_string__builder$append(l0, l5);
                std_string__builder$append(l0, 324u);
                l4 = (l4 + INT64_C(1));
            }
            std_string__builder$append(l0, 14u);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CCast_t*) t0)->f_value;
            vader_emit_c_ast$write_operand(l0, l6, INT32_C(11));
        } else if (l1.tag == 1075u) {
            l2 = (void*) &vader_data_54;
            t0 = l1.payload.obj;
            l3 = ((int64_t) (uint8_t) ((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_operator);
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
            l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_left;
            l7 = ((vader_struct_vader_emit_c_ast$COperatorInfo_t*) l2)->f_precedence;
            vader_emit_c_ast$write_operand(l0, l6, l7);
            std_string__builder$append(l0, 14u);
            l5 = ((vader_struct_vader_emit_c_ast$COperatorInfo_t*) l2)->f_spelling;
            std_string__builder$append(l0, l5);
            std_string__builder$append(l0, 14u);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_right;
            t1 = ((vader_struct_vader_emit_c_ast$COperatorInfo_t*) l2)->f_precedence;
            l7 = vader_chk_add(i32, t1, INT32_C(1));
            vader_emit_c_ast$write_operand(l0, l6, l7);
        } else if (l1.tag == 1073u) {
            std_string__builder$append(l0, 287u);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CAddressOf_t*) t0)->f_operand;
            vader_emit_c_ast$write_operand(l0, l6, INT32_C(11));
        } else if (l1.tag == 1122u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CUnary_t*) t0)->f_operator;
            std_string__builder$append(l0, l5);
            std_string__builder$append(l0, 307u);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CUnary_t*) t0)->f_operand;
            vader_emit_c_ast$write_expression(l0, l6);
            std_string__builder$append(l0, 324u);
        } else if (l1.tag == 1108u) {
            std_string__builder$append(l0, 307u);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CParenthesized_t*) t0)->f_inner;
            vader_emit_c_ast$write_expression(l0, l6);
            std_string__builder$append(l0, 324u);
        } else if (l1.tag == 1104u) {
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CMember_t*) t0)->f_base;
            vader_emit_c_ast$write_expression(l0, l6);
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_emit_c_ast$CMember_t*) t0)->f_arrow;
            if (t3) {
                l5 = 391u;
            } else {
                l5 = 400u;
            }
            std_string__builder$append(l0, l5);
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CMember_t*) t0)->f_member;
            std_string__builder$append(l0, l5);
        } else if (l1.tag == 1099u) {
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CIndex_t*) t0)->f_base;
            vader_emit_c_ast$write_expression(l0, l6);
            std_string__builder$append(l0, 964u);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CIndex_t*) t0)->f_index;
            vader_emit_c_ast$write_expression(l0, l6);
            std_string__builder$append(l0, 967u);
        } else if (l1.tag == 1083u) {
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_condition;
            vader_emit_c_ast$write_expression(l0, l6);
            std_string__builder$append(l0, 82u);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_then_value;
            vader_emit_c_ast$write_expression(l0, l6);
            std_string__builder$append(l0, 67u);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CConditional_t*) t0)->f_else_value;
            vader_emit_c_ast$write_expression(l0, l6);
        } else if (l1.tag == 1088u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CDesignated_t*) t0)->f_designator;
            std_string__builder$append(l0, l5);
            std_string__builder$append(l0, 81u);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CDesignated_t*) t0)->f_value;
            vader_emit_c_ast$write_expression(l0, l6);
        } else if (l1.tag == 1082u) {
            std_string__builder$append(l0, 307u);
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_emit_c_ast$CCompoundLiteral_t*) t0)->f_type;
            std_string__builder$append(l0, l5);
            std_string__builder$append(l0, 351u);
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_emit_c_ast$CCompoundLiteral_t*) t0)->f_elements;
            vader_emit_c_ast$write_list(l0, l2);
            std_string__builder$append(l0, 241u);
        } else if (l1.tag == 1117u) {
            t0 = l1.payload.obj;
            l5 = std_string$join(((vader_struct_vader_emit_c_ast$CStringLiterals_t*) t0)->f_literals, 14u);
            std_string__builder$append(l0, l5);
        } else if (l1.tag == 1100u) {
            t0 = l1.payload.obj;
            t5 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CInitializerList_t*) t0)->f_elements)->length;
            if (t5 == INT64_C(0)) {
                std_string__builder$append(l0, 3058u);
            } else {
                std_string__builder$append(l0, 3057u);
                t0 = l1.payload.obj;
                l2 = ((vader_struct_vader_emit_c_ast$CInitializerList_t*) t0)->f_elements;
                vader_emit_c_ast$write_list(l0, l2);
                std_string__builder$append(l0, 241u);
            }
        } else {
            if (!(l1.tag == 1114u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_emit_c_ast$CSequence_t*) t0)->f_parts;
            l3 = ((vader_array_t*) l2)->length;
            l4 = INT64_C(0);
            while ((l4 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
                vader_emit_c_ast$write_expression(l0, l6);
                l4 = (l4 + INT64_C(1));
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_gc_top = gc_frame.prev;
}

static void vader_emit_c_ast$write_filled(void* l0, void* l1, int32_t l2) {
    int64_t l3, l4, l6, l7, l10;
    void* l5 = NULL;
    vader_box_t l8 = vader_box_null();
    vader_string_t l9 = 0;
    int64_t t0, t1;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_chk_mul(i64, ((int64_t) (int32_t) l2), INT64_C(4));
    l4 = l3;
    l5 = l1;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l9 = vader_emit_c_ast$text_of(l8);
        t0 = vader_host_std_core$byte_len(l9);
        l10 = vader_chk_add(i64, t0, INT64_C(1));
        if ((l4 > l3)) {
            t0 = vader_chk_add(i64, l4, INT64_C(1));
            t1 = vader_chk_add(i64, t0, l10);
            if ((t1 > INT64_C(100))) {
                std_string__builder$append(l0, 1u);
                l4 = l3;
            }
        }
        if (l4 == l3) {
            vader_emit_c_ast$indent(l0, l2);
        } else {
            std_string__builder$append(l0, 14u);
            l4 = vader_chk_add(i64, l4, INT64_C(1));
        }
        t0 = vader_chk_add(i64, l4, l10);
        if ((t0 > INT64_C(100))) {
            vader_emit_c_ast$write_element(l0, l8, l2);
            std_string__builder$append(l0, 362u);
            l4 = l3;
        } else {
            std_string__builder$append(l0, l9);
            std_string__builder$append(l0, 361u);
            l4 = vader_chk_add(i64, l4, l10);
        }
        l7 = (l7 + INT64_C(1));
    }
    if ((l4 > l3)) {
        std_string__builder$append(l0, 1u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_function(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c_ast$CFunction_t*) l1)->f_signature;
    vader_emit_c_ast$write_signature(l0, l2);
    std_string__builder$append(l0, 237u);
    l2 = ((vader_struct_vader_emit_c_ast$CFunction_t*) l1)->f_prologue;
    l3 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CFunction_t*) l1)->f_prologue)->length;
    vader_emit_c_ast$write_statements(l0, l2, INT64_C(0), l3, INT32_C(1));
    l2 = ((vader_struct_vader_emit_c_ast$CFunction_t*) l1)->f_body;
    vader_emit_c_ast$write_block(l0, l2, INT32_C(1));
    vader_emit_c_ast$write_line(l0, 3065u, INT32_C(0));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_goto(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c_ast$CGoto_t*) l1)->f_condition;
    l3 = ((vader_struct_vader_emit_c_ast$CGoto_t*) l1)->f_label;
    l3 = concat_3(2067u, l3, 501u);
    vader_emit_c_ast$write_jump(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_if(void* l0, void* l1, int32_t l2) {
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int32_t l5;
    vader_string_t l6 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_emit_c_ast$CIf_t*) l1)->f_condition;
    vader_emit_c_ast$write_if_head(l0, 2130u, l3, l2);
    l4 = ((vader_struct_vader_emit_c_ast$CIf_t*) l1)->f_then_block;
    l5 = vader_chk_add(i32, l2, INT32_C(1));
    vader_emit_c_ast$write_block(l0, l4, l5);
    l6 = ((vader_struct_vader_emit_c_ast$CIf_t*) l1)->f_end_label;
    vader_emit_c_ast$write_else_chain(l0, l1, l6, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_if_head(void* l0, vader_string_t l1, vader_box_t l2, int32_t l3) {
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_emit_c_ast$indent(l0, l3);
    std_string__builder$append(l0, l1);
    vader_emit_c_ast$write_expression(l0, l2);
    std_string__builder$append(l0, 340u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_initializer(void* l0, vader_box_t l1, int64_t l2, int32_t l3) {
    vader_string_t l4 = 0;
    vader_string_t l8 = 0;
    int64_t l5, l7;
    void* l6 = NULL;
    int32_t l9;
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    void** gc_raw_roots[3] = { &l0, &l6, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c_ast$text_of(l1);
    if (l1.tag == 1117u) {
        l5 = vader_chk_add(i64, l2, INT64_C(1));
        t0 = vader_emit_c_ast$fits(l4, l5);
        if (!(t0)) {
            t1 = l1.payload.obj;
            l6 = ((vader_struct_vader_emit_c_ast$CStringLiterals_t*) t1)->f_literals;
            l5 = ((vader_array_t*) l6)->length;
            l7 = INT64_C(0);
            while ((l7 < l5)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                t2 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l7];
                l8 = t2.payload.s;
                std_string__builder$append(l0, 1u);
                l9 = vader_chk_add(i32, l3, INT32_C(1));
                vader_emit_c_ast$indent(l0, l9);
                std_string__builder$append(l0, l8);
                l7 = (l7 + INT64_C(1));
            }
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    std_string__builder$append(l0, 14u);
    l5 = vader_chk_add(i64, l2, INT64_C(1));
    vader_emit_c_ast$write_laid_out(l0, l1, l4, l5, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_initializer_line(void* l0, vader_box_t l1, int64_t l2, int32_t l3) {
    vader_string_t l4 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_emit_c_ast$text_of(l1);
    vader_emit_c_ast$write_laid_out(l0, l1, l4, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_integer_literal(void* l0, void* l1) {
    bool l2;
    vader_string_t l3 = 0;
    void* l4 = NULL;
    int64_t l5, l6;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) l1)->f_class == INT32_C(3);
    t0 = vader_emit_c_ast$is_most_negative(l1);
    if (t0) {
        if (l2) {
            l3 = 675u;
        } else {
            l3 = 673u;
        }
        std_string__builder$append(l0, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2) {
        l3 = 674u;
    } else {
        l3 = 672u;
    }
    std_string__builder$append(l0, l3);
    l4 = (void*) vader_buffer_new((size_t) INT64_C(20));
    l5 = INT64_C(0);
    l6 = ((vader_struct_vader_emit_c_ast$CIntegerLiteral_t*) l1)->f_value;
    l5 = std_core$write_int(l4, l5, l6);
    l3 = std_core$finish_buffer(l4, l5);
    std_string__builder$append(l0, l3);
    std_string__builder$append(l0, 324u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_jump(void* l0, vader_box_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        std_string__builder$append(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string__builder$append(l0, 2130u);
    l3 = l1;
    vader_emit_c_ast$write_expression(l0, l3);
    std_string__builder$append(l0, 327u);
    std_string__builder$append(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_laid_out(void* l0, vader_box_t l1, vader_string_t l2, int64_t l3, int32_t l4) {
    bool l5;
    void* l6 = NULL;
    int64_t l7, l8;
    vader_box_t l9 = vader_box_null();
    int32_t l10, l11;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l9 };
    void** gc_raw_roots[3] = { &l0, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 1100u)) {
        l5 = true;
    } else {
        l5 = vader_emit_c_ast$fits(l2, l3);
    }
    if (l5) {
        std_string__builder$append(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string__builder$append(l0, 3056u);
    t0 = l1.payload.obj;
    t1 = vader_emit_c_ast$is_table(((vader_struct_vader_emit_c_ast$CInitializerList_t*) t0)->f_elements);
    if (t1) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_emit_c_ast$CInitializerList_t*) t0)->f_elements;
        l7 = ((vader_array_t*) l6)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
            l10 = vader_chk_add(i32, l4, INT32_C(1));
            vader_emit_c_ast$indent(l0, l10);
            l11 = vader_chk_add(i32, l4, INT32_C(1));
            vader_emit_c_ast$write_element(l0, l9, l11);
            std_string__builder$append(l0, 362u);
            l8 = (l8 + INT64_C(1));
        }
    } else {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_emit_c_ast$CInitializerList_t*) t0)->f_elements;
        l10 = vader_chk_add(i32, l4, INT32_C(1));
        vader_emit_c_ast$write_filled(l0, l6, l10);
    }
    vader_emit_c_ast$indent(l0, l4);
    std_string__builder$append(l0, 3065u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_line(void* l0, vader_string_t l1, int32_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_emit_c_ast$indent(l0, l2);
    std_string__builder$append(l0, l1);
    std_string__builder$append(l0, 1u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_list(void* l0, void* l1) {
    int64_t l2, l3;
    vader_box_t l4 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l1)->length;
    while ((l2 < l3)) {
        if ((l2 > INT64_C(0))) {
            std_string__builder$append(l0, 363u);
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        vader_emit_c_ast$write_expression(l0, l4);
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_operand(void* l0, vader_box_t l1, int32_t l2) {
    void* l3 = NULL;
    int64_t l4;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1075u) {
        l3 = (void*) &vader_data_54;
        t0 = l1.payload.obj;
        l4 = ((int64_t) (uint8_t) ((vader_struct_vader_emit_c_ast$CBinary_t*) t0)->f_operator);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = ((vader_struct_vader_emit_c_ast$COperatorInfo_t*) t0)->f_precedence;
        if ((t1 < l2)) {
            std_string__builder$append(l0, 307u);
            l3 = l1.payload.obj;
            vader_emit_c_ast$write_expression(l0, vader_ref_box(l3));
            std_string__builder$append(l0, 324u);
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_emit_c_ast$write_expression(l0, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_emit_c_ast$write_expression(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_parameters(void* l0, void* l1) {
    int64_t l2, l3;
    void* l4 = NULL;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[4] = { &l5, &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        std_string__builder$append(l0, 3010u);
    }
    l2 = INT64_C(0);
    l3 = ((vader_array_t*) l1)->length;
    while ((l2 < l3)) {
        if ((l2 > INT64_C(0))) {
            std_string__builder$append(l0, 363u);
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        t1 = ((vader_struct_vader_emit_c_ast$CParameter_t*) l4)->f_name;
        if (t1 == 0u) {
            l5 = ((vader_struct_vader_emit_c_ast$CParameter_t*) l4)->f_type;
        } else {
            l6 = ((vader_struct_vader_emit_c_ast$CParameter_t*) l4)->f_type;
            l7 = ((vader_struct_vader_emit_c_ast$CParameter_t*) l4)->f_name;
            l5 = concat_3(l6, 14u, l7);
        }
        std_string__builder$append(l0, l5);
        l2 = (l2 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_return(void* l0, void* l1, int32_t l2) {
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_emit_c_ast$indent(l0, l2);
    vader_emit_c_ast$write_return_text(l0, l1);
    std_string__builder$append(l0, 1u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_return_text(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4;
    bool l6;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null();
    vader_string_t l8 = 0;
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l7, &l9 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l8, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_emit_c_ast$CReturn_t*) l1)->f_pops_frame;
    if (t0) {
        std_string__builder$append(l0, 3057u);
    }
    l2 = ((vader_struct_vader_emit_c_ast$CReturn_t*) l1)->f_stores;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_emit_c_ast$write_assign(l0, l5);
        std_string__builder$append(l0, 14u);
        l4 = (l4 + INT64_C(1));
    }
    t0 = ((vader_struct_vader_emit_c_ast$CReturn_t*) l1)->f_pops_frame;
    if (t0) {
        t1 = ((vader_struct_vader_emit_c_ast$CReturn_t*) l1)->f_snapshot_type;
        l6 = t1 != 0u;
    } else {
        l6 = false;
    }
    l7 = ((vader_struct_vader_emit_c_ast$CReturn_t*) l1)->f_value;
    if (l6) {
        if (!(l7.tag == 0u)) {
            l8 = ((vader_struct_vader_emit_c_ast$CReturn_t*) l1)->f_snapshot_type;
            std_string__builder$append(l0, l8);
            std_string__builder$append(l0, 84u);
            l9 = l7;
            vader_emit_c_ast$write_expression(l0, l9);
            std_string__builder$append(l0, 503u);
        }
    }
    t0 = ((vader_struct_vader_emit_c_ast$CReturn_t*) l1)->f_pops_frame;
    if (t0) {
        vader_struct_vader_emit_c_ast$CVerbatim_t* _a1_obj = (vader_struct_vader_emit_c_ast$CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CVerbatim_t));
        vader_obj_header_init(_a1_obj, 1124u);
        _a1_obj->f_text = 2940u;
        l2 = (void*) _a1_obj;
        vader_struct_vader_emit_c_ast$CVerbatim_t* _a2_obj = (vader_struct_vader_emit_c_ast$CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CVerbatim_t));
        vader_obj_header_init(_a2_obj, 1124u);
        _a2_obj->f_text = 2051u;
        l5 = (void*) _a2_obj;
        vader_struct_vader_emit_c_ast$CAssign_t* _a3_obj = (vader_struct_vader_emit_c_ast$CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_emit_c_ast$CAssign_t));
        vader_obj_header_init(_a3_obj, 1074u);
        _a3_obj->f_target = vader_ref_box(l2);
        _a3_obj->f_value = vader_ref_box(l5);
        _a3_obj->f_operator = vader_box_obj(0u, NULL);
        l2 = (void*) _a3_obj;
        vader_emit_c_ast$write_assign(l0, l2);
        std_string__builder$append(l0, 14u);
    }
    if (l7.tag == 0u) {
        std_string__builder$append(l0, 2530u);
    } else {
        std_string__builder$append(l0, 2525u);
        if (l6) {
            std_string__builder$append(l0, 1011u);
        } else {
            vader_emit_c_ast$write_expression(l0, l7);
        }
        std_string__builder$append(l0, 501u);
    }
    t0 = ((vader_struct_vader_emit_c_ast$CReturn_t*) l1)->f_pops_frame;
    if (t0) {
        std_string__builder$append(l0, 241u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_signature(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void* l4 = NULL;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_emit_c_ast$storage_keyword(((vader_struct_vader_emit_c_ast$CSignature_t*) l1)->f_storage);
    std_string__builder$append(l0, l2);
    t0 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l1)->f_inline;
    if (t0) {
        std_string__builder$append(l0, 2165u);
    }
    l2 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l1)->f_result;
    l3 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l1)->f_name;
    l2 = concat_4(l2, 14u, l3, 307u);
    std_string__builder$append(l0, l2);
    l4 = ((vader_struct_vader_emit_c_ast$CSignature_t*) l1)->f_parameters;
    vader_emit_c_ast$write_parameters(l0, l4);
    std_string__builder$append(l0, 324u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_statements(void* l0, void* l1, int64_t l2, int64_t l3, int32_t l4) {
    int64_t l5;
    vader_box_t l6 = vader_box_null(), l9 = vader_box_null(), l21 = vader_box_null(), l29 = vader_box_null(), l30 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t l16 = 0;
    vader_string_t l19 = 0;
    vader_string_t l20 = 0;
    vader_string_t l24 = 0;
    vader_string_t l25 = 0;
    vader_string_t l28 = 0;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l22 = NULL;
    void* l26 = NULL;
    int32_t l18, l23, l27;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[5] = { &l6, &l9, &l21, &l29, &l30 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l8, &l10, &l11, &l12, &l13, &l14, &l15, &l17, &l22, &l26, &t0,
    };
    vader_string_t* gc_atom_roots[8] = { &l7, &l16, &l19, &l20, &l24, &l25, &l28, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = l2;
    while ((l5 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (l6.tag == 1089u) {
            t0 = l6.payload.obj;
            l7 = ((vader_struct_vader_emit_c_ast$CDirective_t*) t0)->f_text;
            vader_emit_c_ast$write_directive(l0, l7);
        } else if (l6.tag == 1074u) {
            vader_emit_c_ast$indent(l0, l4);
            l8 = l6.payload.obj;
            vader_emit_c_ast$write_assign(l0, l8);
            std_string__builder$append(l0, 1u);
        } else if (l6.tag == 1090u) {
            vader_emit_c_ast$indent(l0, l4);
            t0 = l6.payload.obj;
            l9 = ((vader_struct_vader_emit_c_ast$CExpressionStatement_t*) t0)->f_expression;
            vader_emit_c_ast$write_expression(l0, l9);
            std_string__builder$append(l0, 502u);
        } else if (l6.tag == 1103u) {
            vader_emit_c_ast$indent(l0, l4);
            t0 = l6.payload.obj;
            l10 = ((vader_struct_vader_emit_c_ast$CMacroStatement_t*) t0)->f_call;
            vader_emit_c_ast$write_expression(l0, vader_ref_box(l10));
            std_string__builder$append(l0, 1u);
        } else if (l6.tag == 1085u) {
            vader_emit_c_ast$indent(l0, l4);
            l11 = l6.payload.obj;
            vader_emit_c_ast$write_declaration(l0, l11, l4);
            std_string__builder$append(l0, 1u);
        } else if (l6.tag == 1097u) {
            l12 = l6.payload.obj;
            vader_emit_c_ast$write_if(l0, l12, l4);
        } else if (l6.tag == 1111u) {
            l13 = l6.payload.obj;
            vader_emit_c_ast$write_return(l0, l13, l4);
        } else if (l6.tag == 1096u) {
            vader_emit_c_ast$indent(l0, l4);
            l14 = l6.payload.obj;
            vader_emit_c_ast$write_goto(l0, l14);
            std_string__builder$append(l0, 1u);
        } else if (l6.tag == 1120u) {
            l15 = l6.payload.obj;
            vader_emit_c_ast$write_switch(l0, l15, l4);
        } else if (l6.tag == 1112u) {
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_label;
            l16 = vader_emit_c_ast$labelled(t1, 3055u);
            vader_emit_c_ast$write_line(l0, l16, l4);
            t0 = l6.payload.obj;
            l17 = ((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_body;
            l18 = vader_chk_add(i32, l4, INT32_C(1));
            vader_emit_c_ast$write_block(l0, l17, l18);
            t0 = l6.payload.obj;
            l19 = ((vader_struct_vader_emit_c_ast$CScope_t*) t0)->f_end_label;
            vader_emit_c_ast$write_closer(l0, l19, l4);
        } else if (l6.tag == 1125u) {
            vader_emit_c_ast$indent(l0, l4);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_label;
            l20 = vader_emit_c_ast$labelled(t1, 3025u);
            std_string__builder$append(l0, l20);
            t0 = l6.payload.obj;
            l21 = ((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_condition;
            vader_emit_c_ast$write_expression(l0, l21);
            std_string__builder$append(l0, 340u);
            t0 = l6.payload.obj;
            l22 = ((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_body;
            l23 = vader_chk_add(i32, l4, INT32_C(1));
            vader_emit_c_ast$write_block(l0, l22, l23);
            t0 = l6.payload.obj;
            l24 = ((vader_struct_vader_emit_c_ast$CWhile_t*) t0)->f_end_label;
            vader_emit_c_ast$write_closer(l0, l24, l4);
        } else if (l6.tag == 1092u) {
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_emit_c_ast$CFor_t*) t0)->f_label;
            l25 = vader_emit_c_ast$labelled(t1, 2021u);
            vader_emit_c_ast$write_line(l0, l25, l4);
            t0 = l6.payload.obj;
            l26 = ((vader_struct_vader_emit_c_ast$CFor_t*) t0)->f_body;
            l27 = vader_chk_add(i32, l4, INT32_C(1));
            vader_emit_c_ast$write_block(l0, l26, l27);
            t0 = l6.payload.obj;
            l28 = ((vader_struct_vader_emit_c_ast$CFor_t*) t0)->f_end_label;
            vader_emit_c_ast$write_closer(l0, l28, l4);
        } else if (l6.tag == 1084u) {
            vader_emit_c_ast$indent(l0, l4);
            t0 = l6.payload.obj;
            l29 = ((vader_struct_vader_emit_c_ast$CContinue_t*) t0)->f_condition;
            vader_emit_c_ast$write_jump(l0, l29, 1804u);
            std_string__builder$append(l0, 1u);
        } else {
            if (!(l6.tag == 1077u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_emit_c_ast$indent(l0, l4);
            t0 = l6.payload.obj;
            l30 = ((vader_struct_vader_emit_c_ast$CBreak_t*) t0)->f_condition;
            vader_emit_c_ast$write_jump(l0, l30, 1647u);
            std_string__builder$append(l0, 1u);
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_switch(void* l0, void* l1, int32_t l2) {
    vader_box_t l3 = vader_box_null(), l8 = vader_box_null();
    int64_t l4, l5, l11, l12;
    void* l6 = NULL;
    void* l9 = NULL;
    int32_t l7;
    bool l10;
    vader_string_t l13 = 0;
    vader_box_t* gc_roots[2] = { &l3, &l8 };
    void** gc_raw_roots[4] = { &l0, &l1, &l6, &l9 };
    vader_string_t* gc_atom_roots[1] = { &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_emit_c_ast$indent(l0, l2);
    std_string__builder$append(l0, 2681u);
    l3 = ((vader_struct_vader_emit_c_ast$CSwitch_t*) l1)->f_subject;
    vader_emit_c_ast$write_expression(l0, l3);
    std_string__builder$append(l0, 340u);
    l3 = ((vader_struct_vader_emit_c_ast$CSwitch_t*) l1)->f_default_body;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CSwitch_t*) l1)->f_cases)->length;
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CSwitch_t*) l1)->f_cases);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l7 = vader_chk_add(i32, l2, INT32_C(1));
        vader_emit_c_ast$indent(l0, l7);
        std_string__builder$append(l0, 1743u);
        l8 = ((vader_struct_vader_emit_c_ast$CCase_t*) l6)->f_value;
        vader_emit_c_ast$write_expression(l0, l8);
        std_string__builder$append(l0, 462u);
        l9 = ((vader_struct_vader_emit_c_ast$CCase_t*) l6)->f_body;
        if (l3.tag == 0u) {
            l11 = vader_chk_add(i64, l4, INT64_C(1));
            l12 = ((vader_array_t*) ((vader_struct_vader_emit_c_ast$CSwitch_t*) l1)->f_cases)->length;
            l10 = l11 == l12;
        } else {
            l10 = false;
        }
        vader_emit_c_ast$write_case_body(l0, l9, l10);
        l4 = (l4 + INT64_C(1));
    }
    if (l3.tag == 0u) {
        l13 = 3065u;
        vader_emit_c_ast$write_line(l0, l13, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = vader_chk_add(i32, l2, INT32_C(1));
    vader_emit_c_ast$indent(l0, l7);
    std_string__builder$append(l0, 1826u);
    l6 = l3.payload.obj;
    vader_emit_c_ast$write_case_body(l0, l6, true);
    l13 = 3065u;
    vader_emit_c_ast$write_line(l0, l13, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_emit_c_ast$write_top_level(void* l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l4 = 0;
    vader_string_t l9 = 0;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l6, l7;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l4, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1098u) {
        t0 = l1.payload.obj;
        l2 = vader_emit_c_ast$include_operand(t0);
        l2 = concat_3(258u, l2, 1u);
        std_string__builder$append(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1087u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_emit_c_ast$CDefine_t*) t0)->f_name;
        l2 = concat_3(257u, l2, 14u);
        std_string__builder$append(l0, l2);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_emit_c_ast$CDefine_t*) t0)->f_value;
        vader_emit_c_ast$write_expression(l0, l3);
        std_string__builder$append(l0, 1u);
    } else if (l1.tag == 1119u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_emit_c_ast$CStructForward_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_emit_c_ast$CStructForward_t*) t0)->f_name;
        l2 = concat_5(2773u, l2, 14u, l4, 502u);
        std_string__builder$append(l0, l2);
    } else if (l1.tag == 1118u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_emit_c_ast$CStructDefinition_t*) t0)->f_name;
        l2 = concat_3(2656u, l2, 237u);
        std_string__builder$append(l0, l2);
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_emit_c_ast$CStructDefinition_t*) t0)->f_fields;
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
            l2 = ((vader_struct_vader_emit_c_ast$CField_t*) l8)->f_type;
            l4 = ((vader_struct_vader_emit_c_ast$CField_t*) l8)->f_name;
            l9 = concat_4(l2, 14u, l4, 501u);
            vader_emit_c_ast$write_line(l0, l9, INT32_C(1));
            l7 = (l7 + INT64_C(1));
        }
        std_string__builder$append(l0, 3069u);
    } else if (l1.tag == 1095u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_emit_c_ast$CGlobal_t*) t0)->f_constant;
        if (t1) {
            l2 = 1795u;
        } else {
            l2 = 0u;
        }
        t0 = l1.payload.obj;
        l4 = vader_emit_c_ast$storage_keyword(((vader_struct_vader_emit_c_ast$CGlobal_t*) t0)->f_storage);
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_emit_c_ast$CGlobal_t*) t0)->f_type;
        l2 = concat_4(l4, l2, l9, 14u);
        std_string__builder$append(l0, l2);
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_emit_c_ast$CGlobal_t*) t0)->f_declarator;
        l6 = vader_host_std_core$byte_len(l2);
        vader_emit_c_ast$write_declarator(l0, l5, l6, INT32_C(0));
        std_string__builder$append(l0, 502u);
    } else if (l1.tag == 1110u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_emit_c_ast$CPrototype_t*) t0)->f_signature;
        vader_emit_c_ast$write_signature(l0, l5);
        std_string__builder$append(l0, 502u);
    } else if (l1.tag == 1094u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_emit_c_ast$CFunctionPointerTypedef_t*) t0)->f_result;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_emit_c_ast$CFunctionPointerTypedef_t*) t0)->f_name;
        l2 = concat_5(2772u, l2, 46u, l4, 343u);
        std_string__builder$append(l0, l2);
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_emit_c_ast$CFunctionPointerTypedef_t*) t0)->f_parameters;
        vader_emit_c_ast$write_parameters(l0, l5);
        std_string__builder$append(l0, 348u);
    } else if (l1.tag == 1093u) {
        l5 = l1.payload.obj;
        vader_emit_c_ast$write_function(l0, l5);
    } else {
        if (!(l1.tag == 1116u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        std_string__builder$append(l0, 986u);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_emit_c_ast$CStaticAssert_t*) t0)->f_condition;
        vader_emit_c_ast$write_expression(l0, l3);
        std_string__builder$append(l0, 363u);
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_emit_c_ast$CStaticAssert_t*) t0)->f_message;
        vader_emit_c_ast$write_expression(l0, vader_ref_box(l5));
        std_string__builder$append(l0, 348u);
    }
    { vader_gc_top = gc_frame.prev; return; }
}
