#include "bootstrap.split.h"

static bool vader_c_emit_c_ast_any_mentions_local(void* l0, int32_t l1);
static void vader_c_emit_c_ast_collect_clause_labels(void* l0, void* l1);
static void vader_c_emit_c_ast_collect_goto_labels(void* l0, void* l1);
static bool vader_c_emit_c_ast_declares(void* l0);
static bool vader_c_emit_c_ast_end_is_reachable(void* l0);
static bool vader_c_emit_c_ast_ends_with_continue(void* l0);
static void* vader_c_emit_c_ast_exits_after(vader_string_t l0, void* l1, bool l2);
static bool vader_c_emit_c_ast_fits(vader_string_t l0, size_t l1);
static void vader_c_emit_c_ast_fuse_temp_local_copies(void* l0, void* l1);
static vader_box_t vader_c_emit_c_ast_fused_copy(vader_box_t l0, vader_box_t l1, void* l2);
static vader_string_t vader_c_emit_c_ast_include_operand(void* l0);
static void vader_c_emit_c_ast_indent(void* l0, int32_t l1);
static bool vader_c_emit_c_ast_is_empty(void* l0);
static bool vader_c_emit_c_ast_is_table(void* l0);
static vader_string_t vader_c_emit_c_ast_labelled(vader_string_t l0, vader_string_t l1);
static size_t vader_c_emit_c_ast_leading_directives(void* l0);
static vader_box_t vader_c_emit_c_ast_loop_of(void* l0);
static void* vader_c_emit_c_ast_order_by_first(void* l0);
static void vader_c_emit_c_ast_push_tail_labels(void* l0, void* l1);
static void vader_c_emit_c_ast_rewrite_block(void* l0, void* l1);
static bool vader_c_emit_c_ast_same_expressions(void* l0, void* l1);
static bool vader_c_emit_c_ast_same_strings(void* l0, void* l1);
static void vader_c_emit_c_ast_scan_block(void* l0, void* l1);
static void vader_c_emit_c_ast_scan_clause(void* l0, void* l1);
static void vader_c_emit_c_ast_scan_expression(vader_box_t l0, void* l1);
static void vader_c_emit_c_ast_scan_statements(void* l0, void* l1);
static void* vader_c_emit_c_ast_spliced(void* l0, size_t l1, size_t l2, void* l3);
static size_t vader_c_emit_c_ast_statements_end(void* l0);
static vader_string_t vader_c_emit_c_ast_storage_keyword(uint8_t l0);
static void vader_c_emit_c_ast_substitute_jumps(void* l0, vader_string_t l1, void* l2);
static vader_box_t vader_c_emit_c_ast_tail_statement(void* l0);
static vader_string_t vader_c_emit_c_ast_text_of(vader_box_t l0);
static void vader_c_emit_c_ast_tidy_block(void* l0, void* l1);
static size_t vader_c_emit_c_ast_trailing_directives(void* l0, size_t l1);
static vader_string_t vader_c_emit_c_ast_used_label(vader_string_t l0, void* l1);
static void vader_c_emit_c_ast_write_assign(void* l0, void* l1);
static void vader_c_emit_c_ast_write_block(void* l0, void* l1, int32_t l2);
static void vader_c_emit_c_ast_write_case_body(void* l0, void* l1, bool l2);
static void vader_c_emit_c_ast_write_closer(void* l0, vader_string_t l1, int32_t l2);
static void vader_c_emit_c_ast_write_declaration(void* l0, void* l1, int32_t l2);
static void vader_c_emit_c_ast_write_declarator(void* l0, void* l1, size_t l2, int32_t l3);
static void vader_c_emit_c_ast_write_declared(void* l0, vader_string_t l1, vader_box_t l2, size_t l3, int32_t l4);
static void vader_c_emit_c_ast_write_directive(void* l0, vader_string_t l1);
static void vader_c_emit_c_ast_write_element(void* l0, vader_box_t l1, int32_t l2);
static void vader_c_emit_c_ast_write_else_chain(void* l0, void* l1, vader_string_t l2, int32_t l3);
static void vader_c_emit_c_ast_write_expression(void* l0, vader_box_t l1);
static void vader_c_emit_c_ast_write_filled(void* l0, void* l1, int32_t l2);
static void vader_c_emit_c_ast_write_function(void* l0, void* l1);
static void vader_c_emit_c_ast_write_goto(void* l0, void* l1);
static void vader_c_emit_c_ast_write_if(void* l0, void* l1, int32_t l2);
static void vader_c_emit_c_ast_write_if_head(void* l0, vader_string_t l1, vader_box_t l2, int32_t l3);
static void vader_c_emit_c_ast_write_initializer(void* l0, vader_box_t l1, size_t l2, int32_t l3);
static void vader_c_emit_c_ast_write_initializer_line(void* l0, vader_box_t l1, size_t l2, int32_t l3);
static void vader_c_emit_c_ast_write_integer_literal(void* l0, void* l1);
static void vader_c_emit_c_ast_write_jump(void* l0, vader_box_t l1, vader_string_t l2);
static void vader_c_emit_c_ast_write_laid_out(void* l0, vader_box_t l1, vader_string_t l2, size_t l3, int32_t l4);
static void vader_c_emit_c_ast_write_line(void* l0, vader_string_t l1, int32_t l2);
static void vader_c_emit_c_ast_write_list(void* l0, void* l1);
static void vader_c_emit_c_ast_write_operand(void* l0, vader_box_t l1, int32_t l2);
static void vader_c_emit_c_ast_write_parameters(void* l0, void* l1);
static void vader_c_emit_c_ast_write_return(void* l0, void* l1, int32_t l2);
static void vader_c_emit_c_ast_write_return_text(void* l0, void* l1);
static void vader_c_emit_c_ast_write_signature(void* l0, void* l1);
static void vader_c_emit_c_ast_write_statements(void* l0, void* l1, size_t l2, size_t l3, int32_t l4);
static void vader_c_emit_c_ast_write_switch(void* l0, void* l1, int32_t l2);
static void vader_c_emit_c_ast_write_top_level(void* l0, vader_box_t l1);

vader_box_t vader_c_emit_c_ast_address_of(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CAddressOf_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CAddressOf_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAddressOf_t));
    vader_obj_header_init(_a0_obj, 660u);
    _a0_obj->f_operand = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_c_ast_any_mentions_local(void* l0, int32_t l1) {
    void* l2;
    size_t l3, l4;
    vader_box_t t0;
    bool t1;
    int64_t t2;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t1 = vader_c_emit_c_ast_mentions_local(t0, l1);
        if (t1) {
            return true;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    return false;
}

vader_box_t vader_c_emit_c_ast_any_of(void* l0) {
    vader_box_t l1 = vader_box_null(), l4 = vader_box_null();
    size_t l2, l3;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    l1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 1;
    while ((l3 < l2)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        l4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        vader_struct_vader_c_emit_c_ast_CBinary_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CBinary_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBinary_t));
        vader_obj_header_init(_a2_obj, 662u);
        _a2_obj->f_operator = (uint8_t) 17;
        _a2_obj->f_left = l1;
        _a2_obj->f_right = l4;
        t0 = (void*) _a2_obj;
        l1 = vader_ref_box(t0);
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    { vader_box_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_c_emit_c_ast_around(vader_string_t l0, vader_box_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l3, &l4 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_c_emit_c_ast_verbatim(l0);
    l4 = vader_c_emit_c_ast_verbatim(l2);
    vader_array_t* _a0_arr = vader_array_new(145u, 3u, 13u, 1205u);
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 2u] = l4.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 1u] = l1.payload.obj;
    ((void**) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = l3.payload.obj;
    t0 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CSequence_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CSequence_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSequence_t));
    vader_obj_header_init(_a1_obj, 701u);
    _a1_obj->f_parts = t0;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_c_emit_c_ast_array_declaration(vader_string_t l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    int32_t l4;
    size_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CInitializerList_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CInitializerList_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInitializerList_t));
    vader_obj_header_init(_a0_obj, 687u);
    _a0_obj->f_elements = l2;
    l3 = (void*) _a0_obj;
    t0 = ((vader_array_t*) l2)->length;
    l4 = ((int32_t) (size_t) t0);
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a1_obj, 673u);
    _a1_obj->f_name = l1;
    _a1_obj->f_length = vader_box_i32(193u, l4);
    _a1_obj->f_value = vader_ref_box(l3);
    t1 = (void*) _a1_obj;
    vader_array_t* _a2_arr = vader_array_new(51u, 1u, 13u, 673u);
    ((void**) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = t1;
    l3 = (void*) _a2_arr;
    vader_struct_vader_c_emit_c_ast_CDeclaration_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CDeclaration_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclaration_t));
    vader_obj_header_init(_a3_obj, 672u);
    _a3_obj->f_type = l0;
    _a3_obj->f_declarators = l3;
    t1 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_c_emit_c_ast_binary(uint8_t l0, vader_box_t l1, vader_box_t l2) {
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CBinary_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CBinary_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBinary_t));
    vader_obj_header_init(_a0_obj, 662u);
    _a0_obj->f_operator = l0;
    _a0_obj->f_left = l1;
    _a0_obj->f_right = l2;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_c_emit_c_ast_call(vader_string_t l0, void* l1) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CCall_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCall_t));
    vader_obj_header_init(_a0_obj, 665u);
    _a0_obj->f_callee = l0;
    _a0_obj->f_arguments = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_c_emit_c_ast_cast(vader_string_t l0, vader_box_t l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 1u, 0u, 190u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(190u, l0);
    t0 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CCast_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CCast_t));
    vader_obj_header_init(_a1_obj, 667u);
    _a1_obj->f_types = t0;
    _a1_obj->f_value = l1;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_c_emit_c_ast_coalesce_temporaries(void* l0, void* l1) {
    size_t l2, l8, l9, l11, l12, l20;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    int32_t l6, l16, l17, l19, l21;
    uint8_t l13, l14, l18;
    bool l15;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    size_t t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l3, &l4, &l5, &l7, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l1)->length;
    if (l2 == INT64_C(0)) {
        vader_array_t* _a0_arr = vader_array_new(11u, 0u, 1u, 196u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(9u, 1u, 7u, 193u);
    ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) INT32_C(0);
    t0 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 1u, 7u, 193u);
    ((int32_t*) _a3_arr->buf->slots)[_a3_arr->offset + 0u] = (int32_t) -(INT32_C(1));
    t0 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(9u, 1u, 7u, 193u);
    ((int32_t*) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = (int32_t) -(INT32_C(1));
    t0 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) t0, (size_t) l2);
    l5 = (void*) _a6_arr;
    l6 = -(INT32_C(1));
    vader_struct_vader_c_emit_c_ast_TemporaryUsage_t* _a7_obj = (vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_TemporaryUsage_t));
    vader_obj_header_init(_a7_obj, 713u);
    _a7_obj->f_uses = l3;
    _a7_obj->f_first = l4;
    _a7_obj->f_last = l5;
    _a7_obj->f_position = l6;
    l3 = (void*) _a7_obj;
    vader_c_emit_c_ast_scan_block(l0, l3);
    vader_c_emit_c_ast_fuse_temp_local_copies(l0, l3);
    vader_array_t* _a8_arr = vader_array_new(11u, 0u, 1u, 196u);
    l4 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(9u, 0u, 7u, 193u);
    l5 = (void*) _a9_arr;
    l7 = vader_c_emit_c_ast_order_by_first(((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l3)->f_first);
    l2 = ((vader_array_t*) l7)->length;
    l8 = (size_t) 0;
    while ((l8 < l2)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l8)
        t1 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l8];
        l9 = (size_t) (int64_t) t1;
        vader_array_t* _a11_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l9)
        l10 = vader_array_ref_load_obj(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l9);
        l6 = -(INT32_C(1));
        vader_array_t* _a12_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        l11 = ((vader_array_t*) l4)->length;
        l12 = (size_t) 0;
        for (;;) {
            if ((l12 < l11)) {
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l12)
                t2 = vader_array_read_u8(_a12_slotarr, _a12_slotarr->offset + (size_t) l12, 196u);
                l13 = ((uint8_t) t2.payload.i);
                l14 = ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) l10)->f_val;
                if (l13 == l14) {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l5);
                    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l12)
                    l16 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l12];
                    vader_array_t* _a14_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l3)->f_first);
                    VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l9)
                    l17 = ((int32_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l9];
                    l15 = (l16 < l17);
                } else {
                    l15 = false;
                }
                if (l15) {
                    l6 = ((int32_t) (size_t) l12);
                } else {
                    t1 = (l12 + INT64_C(1));
                    l12 = (size_t) (int64_t) t1;
                    continue;
                }
            }
            break;
        }
        if ((l6 < INT32_C(0))) {
            t3 = ((vader_array_t*) l4)->length;
            l6 = ((int32_t) (size_t) t3);
            l18 = ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) l10)->f_val;
            vader_array_push_u8((vader_array_t*) l4, (int32_t) (uint8_t) l18);
            vader_array_t* _a15_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l3)->f_last);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l9)
            l19 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l9];
            vader_array_push_i32((vader_array_t*) l5, l19);
        } else {
            t1 = ((int64_t) (int32_t) l6);
            l20 = (size_t) (int64_t) t1;
            vader_array_t* _a16_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l3)->f_last);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l9)
            l21 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l9];
            vader_array_t* _a17_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l20)
            ((int32_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l20] = (int32_t) l21;
        }
        ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) l10)->f_slot = l6;
        t1 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t1;
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_c_ast_collect_clause_labels(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 683u) {
            t0 = l5.payload.obj;
            l6 = ((vader_struct_vader_c_emit_c_ast_CGoto_t*) t0)->f_label;
            std_collections_add__string(l1, l6);
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_collect_goto_labels(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    size_t l3, l4, l9, l10;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null(), l11 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l5, &l7, &l11 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 683u) {
            t0 = l5.payload.obj;
            l6 = ((vader_struct_vader_c_emit_c_ast_CGoto_t*) t0)->f_label;
            std_collections_add__string(l1, l6);
        } else if (l5.tag == 684u) {
            t0 = l5.payload.obj;
            vader_c_emit_c_ast_collect_goto_labels(((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_then_block, l1);
            t0 = l5.payload.obj;
            l7 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_else_block;
            if (!(l7.tag == 0u)) {
                t0 = l7.payload.obj;
                vader_c_emit_c_ast_collect_goto_labels(t0, l1);
            }
        } else if ((l5.tag == 679u || l5.tag == 699u || l5.tag == 712u)) {
            t0 = l5.payload.obj;
            vader_c_emit_c_ast_collect_goto_labels(((vader_struct_vader_c_emit_c_ast_CFor_t*) t0)->f_body, l1);
        } else if (l5.tag == 707u) {
            t0 = l5.payload.obj;
            l8 = ((vader_struct_vader_c_emit_c_ast_CSwitch_t*) t0)->f_cases;
            l9 = ((vader_array_t*) l8)->length;
            l10 = (size_t) 0;
            while ((l10 < l9)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
                vader_c_emit_c_ast_collect_clause_labels(((vader_struct_vader_c_emit_c_ast_CCase_t*) t0)->f_body, l1);
                t1 = (l10 + INT64_C(1));
                l10 = (size_t) (int64_t) t1;
            }
            t0 = l5.payload.obj;
            l11 = ((vader_struct_vader_c_emit_c_ast_CSwitch_t*) t0)->f_default_body;
            if (!(l11.tag == 0u)) {
                t0 = l11.payload.obj;
                vader_c_emit_c_ast_collect_clause_labels(t0, l1);
            }
        } else {
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

vader_box_t vader_c_emit_c_ast_declaration(vader_string_t l0, vader_string_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CDeclarator_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CDeclarator_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclarator_t));
    vader_obj_header_init(_a0_obj, 673u);
    _a0_obj->f_name = l1;
    _a0_obj->f_length = vader_box_obj(0u, NULL);
    _a0_obj->f_value = l2;
    t0 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(51u, 1u, 13u, 673u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = t0;
    l3 = (void*) _a1_arr;
    vader_struct_vader_c_emit_c_ast_CDeclaration_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CDeclaration_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDeclaration_t));
    vader_obj_header_init(_a2_obj, 672u);
    _a2_obj->f_type = l0;
    _a2_obj->f_declarators = l3;
    t0 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_c_ast_declares(void* l0) {
    void* l1;
    size_t l2, l3;
    vader_box_t t0;
    int64_t t1;
    l1 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (t0.tag == 672u) {
            return true;
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    return false;
}

vader_box_t vader_c_emit_c_ast_designated(vader_string_t l0, vader_box_t l1) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CDesignated_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CDesignated_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CDesignated_t));
    vader_obj_header_init(_a0_obj, 675u);
    _a0_obj->f_designator = l0;
    _a0_obj->f_value = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_c_ast_end_is_reachable(void* l0) {
    vader_box_t l1, l2;
    bool l3;
    void* t0;
    l1 = vader_c_emit_c_ast_tail_statement(l0);
    if (l1.tag == 0u) {
        return true;
    }
    l2 = l1;
    if ((l2.tag == 664u || l2.tag == 671u)) {
        t0 = l1.payload.obj;
        l3 = !(((vader_struct_vader_c_emit_c_ast_CBreak_t*) t0)->f_condition.tag == 0u);
    } else if (l2.tag == 683u) {
        t0 = l1.payload.obj;
        l3 = !(((vader_struct_vader_c_emit_c_ast_CGoto_t*) t0)->f_condition.tag == 0u);
    } else if (l2.tag == 698u) {
        l3 = false;
    } else {
        l3 = true;
    }
    return l3;
}

static bool vader_c_emit_c_ast_ends_with_continue(void* l0) {
    vader_box_t l1;
    bool l2;
    void* t0;
    l1 = vader_c_emit_c_ast_tail_statement(((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body);
    if (l1.tag == 671u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_c_emit_c_ast_CContinue_t*) t0)->f_condition.tag == 0u;
    } else {
        l2 = false;
    }
    return l2;
}

bool vader_c_emit_c_ast_ends_with_return(void* l0) {
    void* l1;
    size_t l2, l3;
    bool l4;
    int64_t t0;
    vader_box_t t1;
    l1 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body;
    l2 = ((vader_array_t*) l1)->length;
    l3 = vader_c_emit_c_ast_trailing_directives(l1, (size_t) 0);
    t0 = (l2 - l3);
    l2 = (size_t) (int64_t) t0;
    if ((l2 > INT64_C(0))) {
        t0 = (l2 - INT64_C(1));
        l2 = (size_t) (int64_t) t0;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        l4 = t1.tag == 698u;
    } else {
        l4 = false;
    }
    return l4;
}

static void* vader_c_emit_c_ast_exits_after(vader_string_t l0, void* l1, bool l2) {
    void* l3 = NULL;
    void** gc_raw_roots[2] = { &l1, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    l3 = (void*) _a0_arr;
    if (l0 != 0u) {
        vader_array_push((vader_array_t*) l3, vader_box_string(190u, l0));
    }
    if (l2) {
        vader_array_push_all((vader_array_t*) l3, (vader_array_t*) l1);
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_c_ast_fits(vader_string_t l0, size_t l1) {
    size_t l2;
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_core_byte_len(l0);
    { bool __vret = (((l1 + l2) + INT64_C(1)) <= INT64_C(100)); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_c_ast_fuse_temp_local_copies(void* l0, void* l1) {
    void* l2 = NULL;
    void* l13 = NULL;
    size_t l3, l4, l5, l9, l10, l11;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null(), l12 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    size_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[5] = { &l6, &l7, &l8, &l12, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body;
    l3 = (size_t) 0;
    l4 = (size_t) 0;
    for (;;) {
        l5 = ((vader_array_t*) l2)->length;
        if ((l4 < l5)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            if (l6.tag == 684u) {
                t0 = l6.payload.obj;
                vader_c_emit_c_ast_fuse_temp_local_copies(((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_then_block, l1);
                t0 = l6.payload.obj;
                l7 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_else_block;
                if (!(l7.tag == 0u)) {
                    t0 = l7.payload.obj;
                    vader_c_emit_c_ast_fuse_temp_local_copies(t0, l1);
                }
            } else if (l6.tag == 699u) {
                t0 = l6.payload.obj;
                vader_c_emit_c_ast_fuse_temp_local_copies(((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_body, l1);
            }
            t1 = (l4 + INT64_C(1));
            l9 = (size_t) (int64_t) t1;
            l10 = ((vader_array_t*) l2)->length;
            if ((l9 < l10)) {
                t1 = (l4 + INT64_C(1));
                l11 = (size_t) (int64_t) t1;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l11)
                l12 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
                l8 = vader_c_emit_c_ast_fused_copy(l6, l12, l1);
            } else {
                l8 = vader_box_obj(0u, NULL);
            }
            if (!(l8.tag == 0u)) {
                l13 = l8.payload.obj;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l3)
                vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l3, l13);
                VADER_WRITE_BARRIER(_a2_slotarr->buf);
                t1 = (l4 + INT64_C(2));
                l4 = (size_t) (int64_t) t1;
            } else {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l3)
                vader_array_ref_store(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l3, l6.payload.obj);
                VADER_WRITE_BARRIER(_a3_slotarr->buf);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
            }
            t1 = (l3 + INT64_C(1));
            l3 = (size_t) (int64_t) t1;
            continue;
        }
        break;
    }
    for (;;) {
        t2 = ((vader_array_t*) l2)->length;
        if ((t2 > l3)) {
            t3 = vader_array_remove_last((vader_array_t*) l2);
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_c_ast_fused_copy(vader_box_t l0, vader_box_t l1, void* l2) {
    bool l3;
    vader_box_t l4 = vader_box_null(), l7 = vader_box_null();
    void* l5 = NULL;
    size_t l6;
    int32_t l8, l9;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int32_t t2;
    int64_t t3;
    vader_box_t* gc_roots[5] = { &l0, &l1, &l4, &l7, &t0 };
    void** gc_raw_roots[3] = { &l2, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 661u)) {
        l3 = true;
    } else {
        l3 = !(l1.tag == 661u);
    }
    if (l3) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l0.payload.obj;
    l4 = ((vader_struct_vader_c_emit_c_ast_CAssign_t*) t1)->f_target;
    if (!(l4.tag == 708u)) {
        l3 = true;
    } else {
        l5 = ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l2)->f_uses;
        t1 = l4.payload.obj;
        t2 = ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) t1)->f_id;
        t3 = ((int64_t) (int32_t) t2);
        l6 = (size_t) (int64_t) t3;
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t2 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l6];
        l3 = t2 != INT32_C(2);
    }
    if (l3) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l1.payload.obj;
    l7 = ((vader_struct_vader_c_emit_c_ast_CAssign_t*) t1)->f_value;
    t1 = l1.payload.obj;
    if (!(((vader_struct_vader_c_emit_c_ast_CAssign_t*) t1)->f_target.tag == 689u)) {
        l3 = true;
    } else {
        l3 = !(l7.tag == 708u);
    }
    if (l3) {
        l3 = true;
    } else {
        t1 = l7.payload.obj;
        l8 = ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) t1)->f_id;
        t1 = l4.payload.obj;
        l9 = ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) t1)->f_id;
        l3 = l8 != l9;
    }
    if (l3) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l2)->f_first;
    t1 = l4.payload.obj;
    t2 = ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) t1)->f_id;
    t3 = ((int64_t) (int32_t) t2);
    l6 = (size_t) (int64_t) t3;
    l8 = -(INT32_C(1));
    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
    ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6] = (int32_t) l8;
    t1 = l1.payload.obj;
    t0 = ((vader_struct_vader_c_emit_c_ast_CAssign_t*) t1)->f_target;
    l5 = t0.payload.obj;
    t1 = l0.payload.obj;
    l4 = ((vader_struct_vader_c_emit_c_ast_CAssign_t*) t1)->f_value;
    vader_struct_vader_c_emit_c_ast_CAssign_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
    vader_obj_header_init(_a2_obj, 661u);
    _a2_obj->f_target = vader_ref_box(l5);
    _a2_obj->f_value = l4;
    _a2_obj->f_operator = vader_box_obj(0u, NULL);
    t1 = (void*) _a2_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_c_ast_include_operand(void* l0) {
    vader_string_t l1 = 0;
    bool t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_c_emit_c_ast_CInclude_t*) l0)->f_system;
    if (t0) {
        l1 = ((vader_struct_vader_c_emit_c_ast_CInclude_t*) l0)->f_path;
        t1 = concat_3(328u, l1, 348u);
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_struct_vader_c_emit_c_ast_CInclude_t*) l0)->f_path;
    t1 = concat_3(147u, l1, 147u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_c_ast_indent(void* l0, int32_t l1) {
    int32_t l2;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((int32_t) 4);
    l2 = (l1 * l2);
    std_string_builder_append_repeated(l0, 32u, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

vader_box_t vader_c_emit_c_ast_initializer_list(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CInitializerList_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CInitializerList_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CInitializerList_t));
    vader_obj_header_init(_a0_obj, 687u);
    _a0_obj->f_elements = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_c_emit_c_ast_is_empty(void* l0) {
    size_t l1, l2;
    l1 = vader_c_emit_c_ast_leading_directives(((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body);
    l2 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body)->length;
    return l1 == l2;
}

bool vader_c_emit_c_ast_is_most_negative(void* l0) {
    bool l1;
    int64_t t0;
    if (((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) l0)->f_class == INT32_C(3)) {
        t0 = ((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) l0)->f_value;
        l1 = t0 == INT64_MIN;
    } else {
        t0 = ((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) l0)->f_value;
        l1 = t0 == INT64_C(-2147483648);
    }
    return l1;
}

static bool vader_c_emit_c_ast_is_table(void* l0) {
    void* l1;
    size_t l2, l3;
    vader_box_t l4, l5;
    void* t0;
    int64_t t1;
    l1 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        if (l4.tag == 675u) {
            t0 = l4.payload.obj;
            l5 = ((vader_struct_vader_c_emit_c_ast_CDesignated_t*) t0)->f_value;
        } else {
            l5 = l4;
        }
        if (!(l5.tag == 687u)) {
            return false;
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    return true;
}

static vader_string_t vader_c_emit_c_ast_labelled(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0 == 0u) {
        l2 = l1;
    } else {
        l2 = concat_3(l0, 295u, l1);
    }
    { vader_string_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static size_t vader_c_emit_c_ast_leading_directives(void* l0) {
    size_t l1, l2;
    bool l3;
    vader_box_t t0;
    int64_t t1;
    l1 = (size_t) 0;
    for (;;) {
        l2 = ((vader_array_t*) l0)->length;
        if ((l1 < l2)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
            t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
            l3 = t0.tag == 676u;
        } else {
            l3 = false;
        }
        if (l3) {
            t1 = (l1 + INT64_C(1));
            l1 = (size_t) (int64_t) t1;
            continue;
        }
        break;
    }
    return l1;
}

static vader_box_t vader_c_emit_c_ast_loop_of(void* l0) {
    void* l1 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    size_t l2, l3;
    vader_box_t l4 = vader_box_null(), l7 = vader_box_null(), l8 = vader_box_null();
    bool l5;
    vader_string_t l6 = 0;
    vader_string_t l9 = 0;
    size_t t0;
    void* t1 = NULL;
    void* t3 = NULL;
    vader_string_t t2 = 0;
    bool t4;
    vader_box_t* gc_roots[3] = { &l4, &l7, &l8 };
    void** gc_raw_roots[6] = { &l0, &l1, &l10, &l11, &t1, &t3 };
    vader_string_t* gc_atom_roots[3] = { &l6, &l9, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) ((vader_struct_vader_c_emit_c_ast_CScope_t*) l0)->f_body)->f_body;
    l2 = vader_c_emit_c_ast_leading_directives(l1);
    l3 = vader_c_emit_c_ast_trailing_directives(l1, l2);
    t0 = ((vader_array_t*) l1)->length;
    if (((t0 - l2) - l3) == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        if (l4.tag == 684u) {
            t1 = l4.payload.obj;
            t2 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t1)->f_end_label;
            if (t2 == 0u) {
                l5 = true;
            } else {
                t2 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) l0)->f_end_label;
                l5 = t2 == 0u;
            }
        } else {
            l5 = false;
        }
        if (l5) {
            t1 = l4.payload.obj;
            t2 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t1)->f_end_label;
            if (t2 == 0u) {
                l6 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) l0)->f_end_label;
            } else {
                t1 = l4.payload.obj;
                l6 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t1)->f_end_label;
            }
            t1 = l4.payload.obj;
            l7 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t1)->f_else_block;
            if (l7.tag == 0u) {
                t1 = l4.payload.obj;
                l5 = vader_c_emit_c_ast_ends_with_continue(((vader_struct_vader_c_emit_c_ast_CIf_t*) t1)->f_then_block);
            } else {
                l5 = false;
            }
            if (l5) {
                t1 = l4.payload.obj;
                t3 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t1)->f_then_block;
                l8 = vader_ref_box(t3);
            } else {
                if (!(l7.tag == 0u)) {
                    t1 = l4.payload.obj;
                    l5 = vader_c_emit_c_ast_is_empty(((vader_struct_vader_c_emit_c_ast_CIf_t*) t1)->f_then_block);
                } else {
                    l5 = false;
                }
                if (l5) {
                    t1 = l7.payload.obj;
                    l5 = vader_c_emit_c_ast_ends_with_continue(t1);
                } else {
                    l5 = false;
                }
                if (l5) {
                    t1 = l7.payload.obj;
                    l8 = vader_ref_box(t1);
                } else {
                    l8 = vader_box_obj(0u, NULL);
                }
            }
            if (!(l8.tag == 0u)) {
                if (l7.tag == 0u) {
                    t1 = l4.payload.obj;
                    l7 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t1)->f_condition;
                } else {
                    t1 = l4.payload.obj;
                    l4 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t1)->f_condition;
                    vader_struct_vader_c_emit_c_ast_CUnary_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CUnary_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CUnary_t));
                    vader_obj_header_init(_a1_obj, 709u);
                    _a1_obj->f_operator = 143u;
                    _a1_obj->f_operand = l4;
                    t1 = (void*) _a1_obj;
                    l7 = vader_ref_box(t1);
                }
                l9 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) l0)->f_label;
                l10 = l8.payload.obj;
                l10 = vader_c_emit_c_ast_spliced(l1, l2, l3, l10);
                vader_struct_vader_c_emit_c_ast_CWhile_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CWhile_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CWhile_t));
                vader_obj_header_init(_a2_obj, 712u);
                _a2_obj->f_label = l9;
                _a2_obj->f_body = l10;
                _a2_obj->f_condition = l7;
                _a2_obj->f_end_label = l6;
                t1 = (void*) _a2_obj;
                { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    vader_array_t* _a3_arr = vader_array_new(146u, 0u, 13u, 1209u);
    t1 = (void*) _a3_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a4_obj, 663u);
    _a4_obj->f_body = t1;
    l10 = (void*) _a4_obj;
    vader_array_push_all((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l10)->f_body, (vader_array_t*) l1);
    t4 = vader_c_emit_c_ast_end_is_reachable(l1);
    if (t4) {
        l1 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l10)->f_body;
        vader_struct_vader_c_emit_c_ast_CBreak_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CBreak_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBreak_t));
        vader_obj_header_init(_a5_obj, 664u);
        _a5_obj->f_condition = vader_box_obj(0u, NULL);
        l11 = (void*) _a5_obj;
        vader_array_push((vader_array_t*) l1, vader_ref_box(l11));
    }
    l6 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) l0)->f_label;
    l9 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) l0)->f_end_label;
    vader_struct_vader_c_emit_c_ast_CFor_t* _a6_obj = (vader_struct_vader_c_emit_c_ast_CFor_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFor_t));
    vader_obj_header_init(_a6_obj, 679u);
    _a6_obj->f_label = l6;
    _a6_obj->f_body = l10;
    _a6_obj->f_end_label = l9;
    t1 = (void*) _a6_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_c_emit_c_ast_mentions_local(vader_box_t l0, int32_t l1) {
    bool l2, l3;
    void* t0;
    int32_t t1;
    bool t2;
    if (l0.tag == 689u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_c_emit_c_ast_CLocal_t*) t0)->f_slot;
        l2 = t1 == l1;
    } else if ((l0.tag == 688u || l0.tag == 708u || l0.tag == 711u)) {
        l2 = false;
    } else if (l0.tag == 665u) {
        t0 = l0.payload.obj;
        l2 = vader_c_emit_c_ast_any_mentions_local(((vader_struct_vader_c_emit_c_ast_CCall_t*) t0)->f_arguments, l1);
    } else if (l0.tag == 667u) {
        t0 = l0.payload.obj;
        l2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CCast_t*) t0)->f_value, l1);
    } else if (l0.tag == 668u) {
        t0 = l0.payload.obj;
        l2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t*) t0)->f_value, l1);
    } else if (l0.tag == 662u) {
        t0 = l0.payload.obj;
        t2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_left, l1);
        if (t2) {
            l2 = true;
        } else {
            t0 = l0.payload.obj;
            l2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_right, l1);
        }
    } else if (l0.tag == 709u) {
        t0 = l0.payload.obj;
        l2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CUnary_t*) t0)->f_operand, l1);
    } else if (l0.tag == 660u) {
        t0 = l0.payload.obj;
        l2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CAddressOf_t*) t0)->f_operand, l1);
    } else if (l0.tag == 695u) {
        t0 = l0.payload.obj;
        l2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CParenthesized_t*) t0)->f_inner, l1);
    } else if (l0.tag == 691u) {
        t0 = l0.payload.obj;
        l2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CMember_t*) t0)->f_base, l1);
    } else if (l0.tag == 686u) {
        t0 = l0.payload.obj;
        t2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CIndex_t*) t0)->f_base, l1);
        if (t2) {
            l2 = true;
        } else {
            t0 = l0.payload.obj;
            l2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CIndex_t*) t0)->f_index, l1);
        }
    } else if (l0.tag == 670u) {
        t0 = l0.payload.obj;
        t2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_condition, l1);
        if (t2) {
            l3 = true;
        } else {
            t0 = l0.payload.obj;
            l3 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_then_value, l1);
        }
        if (l3) {
            l2 = true;
        } else {
            t0 = l0.payload.obj;
            l2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_else_value, l1);
        }
    } else if (l0.tag == 687u) {
        t0 = l0.payload.obj;
        l2 = vader_c_emit_c_ast_any_mentions_local(((vader_struct_vader_c_emit_c_ast_CInitializerList_t*) t0)->f_elements, l1);
    } else if (l0.tag == 669u) {
        t0 = l0.payload.obj;
        l2 = vader_c_emit_c_ast_any_mentions_local(((vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t*) t0)->f_elements, l1);
    } else if (l0.tag == 675u) {
        t0 = l0.payload.obj;
        l2 = vader_c_emit_c_ast_mentions_local(((vader_struct_vader_c_emit_c_ast_CDesignated_t*) t0)->f_value, l1);
    } else if ((l0.tag == 692u || l0.tag == 704u)) {
        l2 = false;
    } else if (l0.tag == 701u) {
        t0 = l0.payload.obj;
        l2 = vader_c_emit_c_ast_any_mentions_local(((vader_struct_vader_c_emit_c_ast_CSequence_t*) t0)->f_parts, l1);
    } else {
        vader_unreachable("unreachable return in vader_c_emit_c_ast$mentions_local");
    }
    return l2;
}

vader_box_t vader_c_emit_c_ast_number(int64_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a0_obj, 692u);
    _a0_obj->f_value = l0;
    _a0_obj->f_unsigned_v = false;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_c_emit_c_ast_order_by_first(void* l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4;
    void* t0 = NULL;
    int32_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct__Cell_Array_i32__t* _a0_obj = (vader_struct__Cell_Array_i32__t*) vader_gc_alloc(sizeof(vader_struct__Cell_Array_i32__t));
    vader_obj_header_init(_a0_obj, 207u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    l1 = vader_ref_box(t0);
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 4u, 200u);
    l2 = (void*) _a1_arr;
    l3 = ((vader_array_t*) ((vader_struct__Cell_Array_i32__t*) l1.payload.obj)->f_value)->length;
    l4 = (size_t) 0;
    {
        vader_array_t* _pc11_hdr = (vader_array_t*) l2;
        size_t _pc11_len = _pc11_hdr->length;
        size_t _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
        void* _pc11_slots = _pc11_hdr->buf->slots;
        for (;;) {
            if ((l4 < l3)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct__Cell_Array_i32__t*) l1.payload.obj)->f_value);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4];
                if ((t1 >= INT32_C(0))) {
                    if (VADER_LIKELY(_pc11_len < _pc11_cap)) {
                        ((int64_t*) _pc11_slots)[_pc11_len] = (int64_t) ((int64_t) (size_t) l4);
                        _pc11_len += 1;
                    } else {
                        _pc11_hdr->length = _pc11_len;
                        if (_pc11_hdr->buf->length < _pc11_len) {
                            _pc11_hdr->buf->length = _pc11_len;
                        }
                        vader_array_push_i64((vader_array_t*) l2, (int64_t) (size_t) l4);
                        _pc11_hdr = (vader_array_t*) l2;
                        _pc11_len = _pc11_hdr->length;
                        _pc11_cap = (_pc11_hdr->offset == 0 && !vader_array_is_borrowed(_pc11_hdr) && _pc11_hdr->length >= _pc11_hdr->buf->length) ? _pc11_hdr->capacity : (size_t) 0;
                        _pc11_slots = _pc11_hdr->buf->slots;
                    }
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                continue;
            }
            _pc11_hdr->length = _pc11_len;
            if (_pc11_hdr->buf->length < _pc11_len) {
                _pc11_hdr->buf->length = _pc11_len;
            }
            break;
        }
    }
    vader_struct___lambda_env_vader_c_emit_c_ast_1_t* _a3_obj = (vader_struct___lambda_env_vader_c_emit_c_ast_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_c_emit_c_ast_1_t));
    vader_obj_header_init(_a3_obj, 230u);
    _a3_obj->f_cap_0 = l1;
    t0 = (void*) _a3_obj;
    vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a4_closure, 170u);
    _a4_closure->code = (void*) &vader_fn_lift___lambda_vader_c_emit_c_ast_0;
    _a4_closure->env = t0;
    l5 = (void*) _a4_closure;
    t0 = std_sort_sort__usize(l2, l5);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_c_emit_c_ast_perform(vader_string_t l0, void* l1) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_c_ast_call(l0, l1);
    vader_struct_vader_c_emit_c_ast_CExpressionStatement_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CExpressionStatement_t));
    vader_obj_header_init(_a0_obj, 677u);
    _a0_obj->f_expression = t0;
    t1 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_c_emit_c_ast_pointer_member(vader_string_t l0, vader_box_t l1, vader_string_t l2) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &t0 };
    void** gc_raw_roots[1] = { &t1 };
    vader_string_t* gc_atom_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_c_emit_c_ast_cast(l0, l1);
    vader_struct_vader_c_emit_c_ast_CParenthesized_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CParenthesized_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CParenthesized_t));
    vader_obj_header_init(_a0_obj, 695u);
    _a0_obj->f_inner = t0;
    t1 = (void*) _a0_obj;
    vader_struct_vader_c_emit_c_ast_CMember_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CMember_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CMember_t));
    vader_obj_header_init(_a1_obj, 691u);
    _a1_obj->f_base = vader_ref_box(t1);
    _a1_obj->f_member = l2;
    _a1_obj->f_arrow = true;
    t1 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_c_emit_c_ast_print_item(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(147u, 1u, 13u, 1214u);
    ((void**) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = l1.payload.obj;
    l3 = (void*) _a1_arr;
    vader_struct_vader_c_emit_c_ast_CSection_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CSection_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CSection_t));
    vader_obj_header_init(_a2_obj, 700u);
    _a2_obj->f_comment = l2;
    _a2_obj->f_items = l3;
    l2 = (void*) _a2_obj;
    vader_c_emit_c_ast_print_section(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_c_emit_c_ast_print_section(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    vader_string_t l3 = 0;
    size_t l4, l5, l9;
    bool l6, l7;
    vader_box_t l10 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t t3 = vader_box_null();
    int64_t t4;
    vader_box_t* gc_roots[2] = { &l10, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CSection_t*) l1)->f_items)->length;
    if (t0 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    t1 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 374u);
    _a1_obj->f_parts = t1;
    l2 = (void*) _a1_obj;
    t2 = ((vader_struct_vader_c_emit_c_ast_CPrinter_t*) l0)->f_started;
    if (t2) {
        std_string_builder_append(l2, 1u);
    }
    ((vader_struct_vader_c_emit_c_ast_CPrinter_t*) l0)->f_started = true;
    t0 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CSection_t*) l1)->f_comment)->length;
    if ((t0 > INT64_C(0))) {
        l3 = std_string_join(((vader_struct_vader_c_emit_c_ast_CSection_t*) l1)->f_comment, 3u);
        l3 = concat_3(279u, l3, 29u);
        std_string_builder_append(l2, l3);
    }
    l4 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CSection_t*) l1)->f_items)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        if ((l5 > INT64_C(0))) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CSection_t*) l1)->f_items);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
            t3 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
            if (t3.tag == 680u) {
                l7 = true;
            } else {
                l8 = ((vader_struct_vader_c_emit_c_ast_CSection_t*) l1)->f_items;
                t4 = (l5 - INT64_C(1));
                l9 = (size_t) (int64_t) t4;
                vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
                t3 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
                l7 = t3.tag == 680u;
            }
            l6 = l7;
        } else {
            l6 = false;
        }
        if (l6) {
            std_string_builder_append(l2, 1u);
        }
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CSection_t*) l1)->f_items);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l5)
        l10 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
        vader_c_emit_c_ast_write_top_level(l2, l10);
        t4 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t4;
    }
    l8 = ((vader_struct_vader_c_emit_c_ast_CPrinter_t*) l0)->f_out;
    l3 = std_string_builder_StringBuilder_Display_to_string(l2);
    std_string_builder_append(l8, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

vader_string_t vader_c_emit_c_ast_printed_text(void* l0) {
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_builder_StringBuilder_Display_to_string(((vader_struct_vader_c_emit_c_ast_CPrinter_t*) l0)->f_out);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_c_ast_push_tail_labels(void* l0, void* l1) {
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
    l2 = vader_c_emit_c_ast_tail_statement(((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body);
    if (l2.tag == 684u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_end_label;
        if (t1 != 0u) {
            t0 = l2.payload.obj;
            l3 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_end_label;
            vader_array_push((vader_array_t*) l1, vader_box_string(190u, l3));
        }
        t0 = l2.payload.obj;
        vader_c_emit_c_ast_push_tail_labels(((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_then_block, l1);
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_else_block;
        if (!(l4.tag == 0u)) {
            t0 = l4.payload.obj;
            vader_c_emit_c_ast_push_tail_labels(t0, l1);
        }
    } else if (l2.tag == 699u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_end_label;
        if (t1 != 0u) {
            t0 = l2.payload.obj;
            l3 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_end_label;
            vader_array_push((vader_array_t*) l1, vader_box_string(190u, l3));
        }
        t0 = l2.payload.obj;
        vader_c_emit_c_ast_push_tail_labels(((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_body, l1);
    } else {
        if (l2.tag == 712u) {
            t0 = l2.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_end_label;
            l5 = t1 != 0u;
        } else {
            l5 = false;
        }
        if (l5) {
            t0 = l2.payload.obj;
            l3 = ((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_end_label;
            vader_array_push((vader_array_t*) l1, vader_box_string(190u, l3));
        } else {
            if (l2.tag == 679u) {
                t0 = l2.payload.obj;
                t1 = ((vader_struct_vader_c_emit_c_ast_CFor_t*) t0)->f_end_label;
                l5 = t1 != 0u;
            } else {
                l5 = false;
            }
            if (l5) {
                t0 = l2.payload.obj;
                l3 = ((vader_struct_vader_c_emit_c_ast_CFor_t*) t0)->f_end_label;
                vader_array_push((vader_array_t*) l1, vader_box_string(190u, l3));
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

vader_box_t vader_c_emit_c_ast_returning(vader_string_t l0, void* l1) {
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
    vader_array_t* _a0_arr = vader_array_new(49u, 0u, 13u, 661u);
    l2 = (void*) _a0_arr;
    l3 = vader_c_emit_c_ast_call(l0, l1);
    vader_struct_vader_c_emit_c_ast_CReturn_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CReturn_t));
    vader_obj_header_init(_a1_obj, 698u);
    _a1_obj->f_stores = l2;
    _a1_obj->f_value = l3;
    _a1_obj->f_snapshot_type = 0u;
    _a1_obj->f_pops_frame = false;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_c_ast_rewrite_block(void* l0, void* l1) {
    size_t l2, l3, l4;
    vader_box_t l5 = vader_box_null(), l8 = vader_box_null(), l14 = vader_box_null();
    bool l6;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    vader_string_t l12 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l5, &l8, &l14 };
    void** gc_raw_roots[8] = { &l0, &l1, &l7, &l9, &l10, &l11, &l13, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l12, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_c_emit_c_ast_statements_end(((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body);
    l3 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = (l4 + INT64_C(1)) == l2;
        if (l5.tag == 684u) {
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_end_label;
            l7 = vader_c_emit_c_ast_exits_after(t1, l1, l6);
            t0 = l5.payload.obj;
            vader_c_emit_c_ast_rewrite_block(((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_then_block, l7);
            t0 = l5.payload.obj;
            l8 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_else_block;
            if (!(l8.tag == 0u)) {
                t0 = l8.payload.obj;
                vader_c_emit_c_ast_rewrite_block(t0, l7);
            }
        } else if (l5.tag == 699u) {
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_end_label;
            l9 = vader_c_emit_c_ast_exits_after(t1, l1, l6);
            t0 = l5.payload.obj;
            vader_c_emit_c_ast_rewrite_block(((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_body, l9);
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_label;
            if (t1 != 0u) {
                l10 = std_iter_clone__string(l9);
                t0 = l5.payload.obj;
                vader_c_emit_c_ast_push_tail_labels(((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_body, l10);
                t0 = l5.payload.obj;
                l11 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_body;
                t0 = l5.payload.obj;
                l12 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_label;
                vader_c_emit_c_ast_substitute_jumps(l11, l12, l10);
                l13 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body;
                t0 = l5.payload.obj;
                l14 = vader_c_emit_c_ast_loop_of(t0);
                vader_array_t* _a1_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
                vader_array_ref_store(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4, l14.payload.obj);
                VADER_WRITE_BARRIER(_a1_slotarr->buf);
            }
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

bool vader_c_emit_c_ast_same_expression(vader_box_t l0, vader_box_t l1) {
    bool l2, l7, l12, l17;
    int32_t l3, l4;
    vader_string_t l5, l6;
    uint8_t l8, l9;
    int64_t l10, l11;
    void* l13;
    void* l14;
    vader_box_t l15, l16;
    void* t0;
    if (l0.tag == 708u) {
        if (l1.tag == 708u) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) t0)->f_id;
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) t0)->f_id;
            l2 = l3 == l4;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 689u) {
        if (l1.tag == 689u) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_c_emit_c_ast_CLocal_t*) t0)->f_slot;
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_c_emit_c_ast_CLocal_t*) t0)->f_slot;
            l2 = l3 == l4;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 711u) {
        if (l1.tag == 711u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_c_emit_c_ast_CVerbatim_t*) t0)->f_text;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_c_emit_c_ast_CVerbatim_t*) t0)->f_text;
            l2 = l5 == l6;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 688u) {
        if (l1.tag == 688u) {
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) t0)->f_class;
            t0 = l0.payload.obj;
            l9 = ((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) t0)->f_class;
            l7 = l8 == l9;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l1.payload.obj;
            l10 = ((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) t0)->f_value;
            t0 = l0.payload.obj;
            l11 = ((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) t0)->f_value;
            l2 = l10 == l11;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 692u) {
        if (l1.tag == 692u) {
            t0 = l1.payload.obj;
            l10 = ((vader_struct_vader_c_emit_c_ast_CNumber_t*) t0)->f_value;
            t0 = l0.payload.obj;
            l11 = ((vader_struct_vader_c_emit_c_ast_CNumber_t*) t0)->f_value;
            l7 = l10 == l11;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_c_emit_c_ast_CNumber_t*) t0)->f_unsigned_v;
            t0 = l0.payload.obj;
            l12 = ((vader_struct_vader_c_emit_c_ast_CNumber_t*) t0)->f_unsigned_v;
            l2 = l7 == l12;
        } else {
            l2 = false;
        }
    } else if (l0.tag == 665u) {
        if (l1.tag == 665u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_c_emit_c_ast_CCall_t*) t0)->f_callee;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_c_emit_c_ast_CCall_t*) t0)->f_callee;
            l7 = l5 == l6;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_c_emit_c_ast_CCall_t*) t0)->f_arguments;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_c_emit_c_ast_CCall_t*) t0)->f_arguments;
            l2 = vader_c_emit_c_ast_same_expressions(l13, l14);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 668u) {
        if (l1.tag == 668u) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t*) t0)->f_model;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t*) t0)->f_model;
            l7 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t*) t0)->f_value;
            l2 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 667u) {
        if (l1.tag == 667u) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_c_emit_c_ast_CCast_t*) t0)->f_types;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_c_emit_c_ast_CCast_t*) t0)->f_types;
            l7 = vader_c_emit_c_ast_same_strings(l13, l14);
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CCast_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CCast_t*) t0)->f_value;
            l2 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 662u) {
        if (l1.tag == 662u) {
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_operator;
            t0 = l0.payload.obj;
            l9 = ((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_operator;
            l7 = l8 == l9;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_left;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_left;
            l7 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_right;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_right;
            l2 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 660u) {
        if (l1.tag == 660u) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CAddressOf_t*) t0)->f_operand;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CAddressOf_t*) t0)->f_operand;
            l2 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 709u) {
        if (l1.tag == 709u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_c_emit_c_ast_CUnary_t*) t0)->f_operator;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_c_emit_c_ast_CUnary_t*) t0)->f_operator;
            l7 = l5 == l6;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CUnary_t*) t0)->f_operand;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CUnary_t*) t0)->f_operand;
            l2 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 695u) {
        if (l1.tag == 695u) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CParenthesized_t*) t0)->f_inner;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CParenthesized_t*) t0)->f_inner;
            l2 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 691u) {
        if (l1.tag == 691u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_c_emit_c_ast_CMember_t*) t0)->f_member;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_c_emit_c_ast_CMember_t*) t0)->f_member;
            l7 = l5 == l6;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l1.payload.obj;
            l12 = ((vader_struct_vader_c_emit_c_ast_CMember_t*) t0)->f_arrow;
            t0 = l0.payload.obj;
            l17 = ((vader_struct_vader_c_emit_c_ast_CMember_t*) t0)->f_arrow;
            l7 = l12 == l17;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CMember_t*) t0)->f_base;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CMember_t*) t0)->f_base;
            l2 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 686u) {
        if (l1.tag == 686u) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CIndex_t*) t0)->f_base;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CIndex_t*) t0)->f_base;
            l7 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CIndex_t*) t0)->f_index;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CIndex_t*) t0)->f_index;
            l2 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 670u) {
        if (l1.tag == 670u) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_condition;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_condition;
            l7 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_then_value;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_then_value;
            l7 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_else_value;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_else_value;
            l2 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 687u) {
        if (l1.tag == 687u) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_c_emit_c_ast_CInitializerList_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_c_emit_c_ast_CInitializerList_t*) t0)->f_elements;
            l2 = vader_c_emit_c_ast_same_expressions(l13, l14);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 669u) {
        if (l1.tag == 669u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t*) t0)->f_type;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t*) t0)->f_type;
            l7 = l5 == l6;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t*) t0)->f_elements;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t*) t0)->f_elements;
            l2 = vader_c_emit_c_ast_same_expressions(l13, l14);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 675u) {
        if (l1.tag == 675u) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_c_emit_c_ast_CDesignated_t*) t0)->f_designator;
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_c_emit_c_ast_CDesignated_t*) t0)->f_designator;
            l7 = l5 == l6;
        } else {
            l7 = false;
        }
        if (l7) {
            t0 = l0.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CDesignated_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CDesignated_t*) t0)->f_value;
            l2 = vader_c_emit_c_ast_same_expression(l15, l16);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 704u) {
        if (l1.tag == 704u) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_c_emit_c_ast_CStringLiterals_t*) t0)->f_literals;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_c_emit_c_ast_CStringLiterals_t*) t0)->f_literals;
            l2 = vader_c_emit_c_ast_same_strings(l13, l14);
        } else {
            l2 = false;
        }
    } else if (l0.tag == 701u) {
        if (l1.tag == 701u) {
            t0 = l0.payload.obj;
            l13 = ((vader_struct_vader_c_emit_c_ast_CSequence_t*) t0)->f_parts;
            t0 = l1.payload.obj;
            l14 = ((vader_struct_vader_c_emit_c_ast_CSequence_t*) t0)->f_parts;
            l2 = vader_c_emit_c_ast_same_expressions(l13, l14);
        } else {
            l2 = false;
        }
    } else {
        vader_unreachable("unreachable return in vader_c_emit_c_ast$same_expression");
    }
    return l2;
}

static bool vader_c_emit_c_ast_same_expressions(void* l0, void* l1) {
    size_t l2, l3;
    vader_box_t l4, l5;
    bool t0;
    int64_t t1;
    l2 = ((vader_array_t*) l0)->length;
    l3 = ((vader_array_t*) l1)->length;
    if (l2 != l3) {
        return false;
    }
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l3);
        t0 = vader_c_emit_c_ast_same_expression(l4, l5);
        if (!(t0)) {
            return false;
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    return true;
}

static bool vader_c_emit_c_ast_same_strings(void* l0, void* l1) {
    size_t l2, l3;
    vader_string_t l4, l5;
    vader_box_t t0;
    int64_t t1;
    l2 = ((vader_array_t*) l0)->length;
    l3 = ((vader_array_t*) l1)->length;
    if (l2 != l3) {
        return false;
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l3];
        l4 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l3];
        l5 = t0.payload.s;
        if (l4 != l5) {
            return false;
        }
        t1 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t1;
    }
    return true;
}

static void vader_c_emit_c_ast_scan_block(void* l0, void* l1) {
    vader_c_emit_c_ast_scan_statements(((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body, l1);
    return;
}

static void vader_c_emit_c_ast_scan_clause(void* l0, void* l1) {
    void* l2;
    void* l6;
    void* l9;
    size_t l3, l4, l7, l8;
    vader_box_t l5, l10, l11;
    void* t0;
    int64_t t1;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 677u) {
            t0 = l5.payload.obj;
            vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) t0)->f_expression, l1);
        } else if (l5.tag == 698u) {
            t0 = l5.payload.obj;
            l6 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) t0)->f_stores;
            l7 = ((vader_array_t*) l6)->length;
            l8 = (size_t) 0;
            while ((l8 < l7)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
                l9 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CAssign_t*) l9)->f_target, l1);
                vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CAssign_t*) l9)->f_value, l1);
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
            }
            t0 = l5.payload.obj;
            l10 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) t0)->f_value;
            if (!(l10.tag == 0u)) {
                vader_c_emit_c_ast_scan_expression(l10, l1);
            }
        } else if (l5.tag == 683u) {
            t0 = l5.payload.obj;
            l11 = ((vader_struct_vader_c_emit_c_ast_CGoto_t*) t0)->f_condition;
            if (!(l11.tag == 0u)) {
                vader_c_emit_c_ast_scan_expression(l11, l1);
            }
        } else {
            return;
        }
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    return;
}

static void vader_c_emit_c_ast_scan_expression(vader_box_t l0, void* l1) {
    size_t l2, l5;
    void* l3;
    int32_t l4;
    void* t0;
    int32_t t1;
    int64_t t2;
    vader_box_t t3;
    if (l0.tag == 708u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) t0)->f_id;
        t2 = ((int64_t) (int32_t) t1);
        l2 = (size_t) (int64_t) t2;
        l3 = ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l1)->f_uses;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l1)->f_uses);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
        l4 = (t1 + INT32_C(1));
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
        ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l2] = (int32_t) l4;
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l1)->f_first);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
        t1 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l2];
        if ((t1 < INT32_C(0))) {
            l3 = ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l1)->f_first;
            l4 = ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l1)->f_position;
            vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l2)
            ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l2] = (int32_t) l4;
        }
        l3 = ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l1)->f_last;
        l4 = ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l1)->f_position;
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l2)
        ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l2] = (int32_t) l4;
    } else if ((l0.tag == 688u || l0.tag == 689u || l0.tag == 711u)) {
    } else if (l0.tag == 665u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_c_emit_c_ast_CCall_t*) t0)->f_arguments;
        l2 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l2)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l5)
            t3 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
            vader_c_emit_c_ast_scan_expression(t3, l1);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 667u) {
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CCast_t*) t0)->f_value, l1);
    } else if (l0.tag == 668u) {
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t*) t0)->f_value, l1);
    } else if (l0.tag == 662u) {
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_right, l1);
    } else if (l0.tag == 709u) {
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CUnary_t*) t0)->f_operand, l1);
    } else if (l0.tag == 660u) {
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CAddressOf_t*) t0)->f_operand, l1);
    } else if (l0.tag == 695u) {
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CParenthesized_t*) t0)->f_inner, l1);
    } else if (l0.tag == 691u) {
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CMember_t*) t0)->f_base, l1);
    } else if (l0.tag == 686u) {
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CIndex_t*) t0)->f_base, l1);
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CIndex_t*) t0)->f_index, l1);
    } else if (l0.tag == 670u) {
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_condition, l1);
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_then_value, l1);
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_else_value, l1);
    } else if ((l0.tag == 692u || l0.tag == 704u)) {
    } else if (l0.tag == 675u) {
        t0 = l0.payload.obj;
        vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CDesignated_t*) t0)->f_value, l1);
    } else if (l0.tag == 669u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t*) t0)->f_elements;
        l2 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l2)) {
            vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
            t3 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
            vader_c_emit_c_ast_scan_expression(t3, l1);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 687u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_c_emit_c_ast_CInitializerList_t*) t0)->f_elements;
        l2 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l2)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
            t3 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
            vader_c_emit_c_ast_scan_expression(t3, l1);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 701u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_c_emit_c_ast_CSequence_t*) t0)->f_parts;
        l2 = ((vader_array_t*) l3)->length;
        l5 = (size_t) 0;
        while ((l5 < l2)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l5)
            t3 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l5);
            vader_c_emit_c_ast_scan_expression(t3, l1);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
    } else {
        return;
    }
    return;
}

static void vader_c_emit_c_ast_scan_statements(void* l0, void* l1) {
    void* l2;
    void* l7;
    void* l11;
    void* l18;
    void* l21;
    size_t l3, l4, l8, l9, l12, l13, l19, l20;
    vader_box_t l5, l10, l14, l15, l16, l17, l22;
    int32_t l6;
    int32_t t0;
    void* t1;
    int64_t t2;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        t0 = ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l1)->f_position;
        l6 = (t0 + INT32_C(1));
        ((vader_struct_vader_c_emit_c_ast_TemporaryUsage_t*) l1)->f_position = l6;
        if (l5.tag == 676u) {
        } else if (l5.tag == 661u) {
            t1 = l5.payload.obj;
            vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CAssign_t*) t1)->f_target, l1);
            t1 = l5.payload.obj;
            vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CAssign_t*) t1)->f_value, l1);
        } else if (l5.tag == 677u) {
            t1 = l5.payload.obj;
            vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) t1)->f_expression, l1);
        } else if (l5.tag == 690u) {
            t1 = l5.payload.obj;
            vader_c_emit_c_ast_scan_expression(vader_ref_box(((vader_struct_vader_c_emit_c_ast_CMacroStatement_t*) t1)->f_call), l1);
        } else if (l5.tag == 672u) {
            t1 = l5.payload.obj;
            l7 = ((vader_struct_vader_c_emit_c_ast_CDeclaration_t*) t1)->f_declarators;
            l8 = ((vader_array_t*) l7)->length;
            l9 = (size_t) 0;
            while ((l9 < l8)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l9)
                t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l9);
                l10 = ((vader_struct_vader_c_emit_c_ast_CDeclarator_t*) t1)->f_value;
                if (!(l10.tag == 0u)) {
                    vader_c_emit_c_ast_scan_expression(l10, l1);
                }
                t2 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t2;
            }
        } else if (l5.tag == 707u) {
            t1 = l5.payload.obj;
            vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CSwitch_t*) t1)->f_subject, l1);
            t1 = l5.payload.obj;
            l11 = ((vader_struct_vader_c_emit_c_ast_CSwitch_t*) t1)->f_cases;
            l12 = ((vader_array_t*) l11)->length;
            l13 = (size_t) 0;
            while ((l13 < l12)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l11);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l13)
                t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l13);
                vader_c_emit_c_ast_scan_clause(((vader_struct_vader_c_emit_c_ast_CCase_t*) t1)->f_body, l1);
                t2 = (l13 + INT64_C(1));
                l13 = (size_t) (int64_t) t2;
            }
            t1 = l5.payload.obj;
            l14 = ((vader_struct_vader_c_emit_c_ast_CSwitch_t*) t1)->f_default_body;
            if (!(l14.tag == 0u)) {
                t1 = l14.payload.obj;
                vader_c_emit_c_ast_scan_clause(t1, l1);
            }
        } else if (l5.tag == 683u) {
            t1 = l5.payload.obj;
            l15 = ((vader_struct_vader_c_emit_c_ast_CGoto_t*) t1)->f_condition;
            if (!(l15.tag == 0u)) {
                vader_c_emit_c_ast_scan_expression(l15, l1);
            }
        } else if (l5.tag == 684u) {
            t1 = l5.payload.obj;
            vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CIf_t*) t1)->f_condition, l1);
            t1 = l5.payload.obj;
            vader_c_emit_c_ast_scan_block(((vader_struct_vader_c_emit_c_ast_CIf_t*) t1)->f_then_block, l1);
            t1 = l5.payload.obj;
            l16 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t1)->f_else_block;
            if (!(l16.tag == 0u)) {
                t1 = l16.payload.obj;
                vader_c_emit_c_ast_scan_block(t1, l1);
            }
        } else if (l5.tag == 699u) {
            t1 = l5.payload.obj;
            vader_c_emit_c_ast_scan_block(((vader_struct_vader_c_emit_c_ast_CScope_t*) t1)->f_body, l1);
        } else if (l5.tag == 712u) {
            t1 = l5.payload.obj;
            vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CWhile_t*) t1)->f_condition, l1);
            t1 = l5.payload.obj;
            vader_c_emit_c_ast_scan_block(((vader_struct_vader_c_emit_c_ast_CWhile_t*) t1)->f_body, l1);
        } else if (l5.tag == 679u) {
            t1 = l5.payload.obj;
            vader_c_emit_c_ast_scan_block(((vader_struct_vader_c_emit_c_ast_CFor_t*) t1)->f_body, l1);
        } else if ((l5.tag == 664u || l5.tag == 671u)) {
            t1 = l5.payload.obj;
            l17 = ((vader_struct_vader_c_emit_c_ast_CBreak_t*) t1)->f_condition;
            if (!(l17.tag == 0u)) {
                vader_c_emit_c_ast_scan_expression(l17, l1);
            }
        } else if (l5.tag == 698u) {
            t1 = l5.payload.obj;
            l18 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) t1)->f_stores;
            l19 = ((vader_array_t*) l18)->length;
            l20 = (size_t) 0;
            while ((l20 < l19)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l18);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l20)
                l21 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l20);
                vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CAssign_t*) l21)->f_target, l1);
                vader_c_emit_c_ast_scan_expression(((vader_struct_vader_c_emit_c_ast_CAssign_t*) l21)->f_value, l1);
                t2 = (l20 + INT64_C(1));
                l20 = (size_t) (int64_t) t2;
            }
            t1 = l5.payload.obj;
            l22 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) t1)->f_value;
            if (!(l22.tag == 0u)) {
                vader_c_emit_c_ast_scan_expression(l22, l1);
            }
        } else {
            return;
        }
        t2 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    return;
}

static void* vader_c_emit_c_ast_spliced(void* l0, size_t l1, size_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    size_t l7, l8, l9;
    vader_box_t l10 = vader_box_null();
    void* t0 = NULL;
    size_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[6] = { &l0, &l3, &l4, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(146u, 0u, 13u, 1209u);
    t0 = (void*) _a0_arr;
    vader_struct_vader_c_emit_c_ast_CBlock_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBlock_t));
    vader_obj_header_init(_a1_obj, 663u);
    _a1_obj->f_body = t0;
    l4 = (void*) _a1_obj;
    l5 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l4)->f_body;
    vader_array_t* _a2_arr = vader_array_slice((vader_array_t*) l0, (size_t) INT64_C(0), (size_t) l1);
    l6 = (void*) _a2_arr;
    vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l6);
    t1 = vader_c_emit_c_ast_statements_end(((vader_struct_vader_c_emit_c_ast_CBlock_t*) l3)->f_body);
    t2 = (t1 - INT64_C(1));
    l7 = (size_t) (int64_t) t2;
    l8 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l3)->f_body)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        if (l9 != l7) {
            l5 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l4)->f_body;
            vader_array_t* _a3_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l3)->f_body);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
            l10 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
            vader_array_push((vader_array_t*) l5, l10);
        }
        t2 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t2;
    }
    l5 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l4)->f_body;
    t1 = ((vader_array_t*) l0)->length;
    t2 = (t1 - l2);
    l7 = (size_t) (int64_t) t2;
    l8 = ((vader_array_t*) l0)->length;
    vader_array_t* _a4_arr = vader_array_slice((vader_array_t*) l0, (size_t) l7, (size_t) l8);
    l6 = (void*) _a4_arr;
    vader_array_push_all((vader_array_t*) l5, (vader_array_t*) l6);
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static size_t vader_c_emit_c_ast_statements_end(void* l0) {
    size_t l1, l2;
    l1 = ((vader_array_t*) l0)->length;
    l2 = vader_c_emit_c_ast_trailing_directives(l0, (size_t) 0);
    return (size_t) (int64_t) (l1 - l2);
}

static vader_string_t vader_c_emit_c_ast_storage_keyword(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 1948u;
    } else if (l0 == INT32_C(1)) {
        l1 = 0u;
    } else if (l0 == INT32_C(2)) {
        l1 = 1422u;
    } else {
        vader_unreachable("unreachable return in vader_c_emit_c_ast$storage_keyword");
    }
    return l1;
}

void vader_c_emit_c_ast_structure_loops(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    l1 = (void*) _a0_arr;
    vader_c_emit_c_ast_rewrite_block(l0, l1);
    vader_array_t* _a1_arr = vader_array_new(8u, 0u, 0u, 190u);
    l1 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(6u, 0u, 12u, 188u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 193u);
    l3 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__string__bool_t* _a4_obj = (vader_struct_std_collections_MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__bool_t));
    vader_obj_header_init(_a4_obj, 342u);
    _a4_obj->f_ekeys = l1;
    _a4_obj->f_evals = l2;
    _a4_obj->f_index = l3;
    _a4_obj->f_mask = (size_t) 0;
    _a4_obj->f_size = (size_t) 0;
    _a4_obj->f_tombs = (size_t) 0;
    t0 = (void*) _a4_obj;
    vader_struct_std_collections_MutableSet__string_t* _a5_obj = (vader_struct_std_collections_MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__string_t));
    vader_obj_header_init(_a5_obj, 364u);
    _a5_obj->f_inner = t0;
    l1 = (void*) _a5_obj;
    vader_c_emit_c_ast_collect_goto_labels(l0, l1);
    vader_c_emit_c_ast_tidy_block(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_substitute_jumps(void* l0, vader_string_t l1, void* l2) {
    size_t l3, l4;
    vader_box_t l5 = vader_box_null(), l11 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l5, &l11 };
    void** gc_raw_roots[7] = { &l0, &l2, &l6, &l7, &l9, &l10, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l8, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        if (l5.tag == 683u) {
            t0 = l5.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CGoto_t*) t0)->f_label;
            if (t1 == l1) {
                l6 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body;
                t0 = l5.payload.obj;
                vader_struct_vader_c_emit_c_ast_CContinue_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CContinue_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CContinue_t));
                vader_obj_header_init(_a1_obj, 671u);
                _a1_obj->f_condition = ((vader_struct_vader_c_emit_c_ast_CGoto_t*) t0)->f_condition;
                l7 = (void*) _a1_obj;
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
                vader_array_ref_store(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4, l7);
                VADER_WRITE_BARRIER(_a2_slotarr->buf);
            } else {
                t0 = l5.payload.obj;
                l8 = ((vader_struct_vader_c_emit_c_ast_CGoto_t*) t0)->f_label;
                t2 = std_core____Contains_contains__string(l2, l8);
                if (t2) {
                    l9 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body;
                    t0 = l5.payload.obj;
                    vader_struct_vader_c_emit_c_ast_CBreak_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CBreak_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CBreak_t));
                    vader_obj_header_init(_a3_obj, 664u);
                    _a3_obj->f_condition = ((vader_struct_vader_c_emit_c_ast_CGoto_t*) t0)->f_condition;
                    l10 = (void*) _a3_obj;
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l9);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    vader_array_ref_store(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4, l10);
                    VADER_WRITE_BARRIER(_a4_slotarr->buf);
                }
            }
        } else if (l5.tag == 684u) {
            t0 = l5.payload.obj;
            vader_c_emit_c_ast_substitute_jumps(((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_then_block, l1, l2);
            t0 = l5.payload.obj;
            l11 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_else_block;
            if (!(l11.tag == 0u)) {
                t0 = l11.payload.obj;
                vader_c_emit_c_ast_substitute_jumps(t0, l1, l2);
            }
        } else if (l5.tag == 699u) {
            t0 = l5.payload.obj;
            vader_c_emit_c_ast_substitute_jumps(((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_body, l1, l2);
        }
        t3 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t3;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_c_emit_c_ast_tail_statement(void* l0) {
    size_t l1;
    vader_box_t t0;
    int64_t t1;
    l1 = vader_c_emit_c_ast_statements_end(l0);
    if (l1 == INT64_C(0)) {
        t0 = vader_box_obj(0u, NULL);
        return t0;
    }
    t1 = (l1 - INT64_C(1));
    l1 = (size_t) (int64_t) t1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
    return t0;
}

static vader_string_t vader_c_emit_c_ast_text_of(vader_box_t l0) {
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 190u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 374u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    vader_c_emit_c_ast_write_expression(l1, l0);
    t1 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_c_ast_tidy_block(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l18 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l30 = NULL;
    void* l31 = NULL;
    void* l38 = NULL;
    void* l39 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null(), l11 = vader_box_null(), l13 = vader_box_null(), l32 = vader_box_null(), l40 = vader_box_null();
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_string_t l14 = 0;
    vader_string_t l15 = 0;
    vader_string_t l19 = 0;
    vader_string_t l21 = 0;
    vader_string_t l25 = 0;
    vader_string_t l26 = 0;
    vader_string_t l27 = 0;
    vader_string_t l29 = 0;
    vader_string_t l33 = 0;
    vader_string_t l34 = 0;
    vader_string_t l35 = 0;
    vader_string_t l37 = 0;
    bool l16, l17, l20, l28, l36;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[6] = { &l6, &l7, &l11, &l13, &l32, &l40 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l2, &l3, &l10, &l12, &l18, &l22, &l23, &l24, &l30, &l31, &l38, &l39, &t0,
    };
    vader_string_t* gc_atom_roots[15] = {
        &l8, &l9, &l14, &l15, &l19, &l21, &l25, &l26, &l27, &l29, &l33, &l34, &l35, &l37, &t1,
    };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 15u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(146u, 0u, 13u, 1209u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        if (l6.tag == 684u) {
            t0 = l6.payload.obj;
            vader_c_emit_c_ast_tidy_block(((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_then_block, l1);
            t0 = l6.payload.obj;
            l7 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_else_block;
            if (!(l7.tag == 0u)) {
                t0 = l7.payload.obj;
                vader_c_emit_c_ast_tidy_block(t0, l1);
            }
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_end_label;
            l8 = vader_c_emit_c_ast_used_label(t1, l1);
            t0 = l6.payload.obj;
            l9 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_end_label;
            if (l8 == l9) {
                l10 = l6.payload.obj;
            } else {
                t0 = l6.payload.obj;
                l11 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_condition;
                t0 = l6.payload.obj;
                l12 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_then_block;
                t0 = l6.payload.obj;
                l13 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_else_block;
                vader_struct_vader_c_emit_c_ast_CIf_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CIf_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CIf_t));
                vader_obj_header_init(_a2_obj, 684u);
                _a2_obj->f_condition = l11;
                _a2_obj->f_then_block = l12;
                _a2_obj->f_else_block = l13;
                _a2_obj->f_end_label = 0u;
                l10 = (void*) _a2_obj;
            }
            vader_array_push((vader_array_t*) l2, vader_ref_box(l10));
        } else if (l6.tag == 699u) {
            t0 = l6.payload.obj;
            vader_c_emit_c_ast_tidy_block(((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_body, l1);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_label;
            l14 = vader_c_emit_c_ast_used_label(t1, l1);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_end_label;
            l15 = vader_c_emit_c_ast_used_label(t1, l1);
            if (l14 == 0u) {
                l16 = l15 == 0u;
            } else {
                l16 = false;
            }
            if (l16) {
                t0 = l6.payload.obj;
                t2 = vader_c_emit_c_ast_declares(((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_body);
                l17 = !(t2);
            } else {
                l17 = false;
            }
            if (l17) {
                t0 = l6.payload.obj;
                l18 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_body)->f_body;
                vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l18);
            } else {
                t0 = l6.payload.obj;
                l19 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_label;
                if (l14 == l19) {
                    t0 = l6.payload.obj;
                    l21 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_end_label;
                    l20 = l15 == l21;
                } else {
                    l20 = false;
                }
                if (l20) {
                    l22 = l6.payload.obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l22));
                } else {
                    t0 = l6.payload.obj;
                    l23 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_body;
                    vader_struct_vader_c_emit_c_ast_CScope_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CScope_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CScope_t));
                    vader_obj_header_init(_a3_obj, 699u);
                    _a3_obj->f_label = l14;
                    _a3_obj->f_body = l23;
                    _a3_obj->f_end_label = l15;
                    l24 = (void*) _a3_obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l24));
                }
            }
        } else if (l6.tag == 712u) {
            t0 = l6.payload.obj;
            vader_c_emit_c_ast_tidy_block(((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_body, l1);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_label;
            l25 = vader_c_emit_c_ast_used_label(t1, l1);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_end_label;
            l26 = vader_c_emit_c_ast_used_label(t1, l1);
            t0 = l6.payload.obj;
            l27 = ((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_label;
            if (l25 == l27) {
                t0 = l6.payload.obj;
                l29 = ((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_end_label;
                l28 = l26 == l29;
            } else {
                l28 = false;
            }
            if (l28) {
                l30 = l6.payload.obj;
            } else {
                t0 = l6.payload.obj;
                l31 = ((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_body;
                t0 = l6.payload.obj;
                l32 = ((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_condition;
                vader_struct_vader_c_emit_c_ast_CWhile_t* _a4_obj = (vader_struct_vader_c_emit_c_ast_CWhile_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CWhile_t));
                vader_obj_header_init(_a4_obj, 712u);
                _a4_obj->f_label = l25;
                _a4_obj->f_body = l31;
                _a4_obj->f_condition = l32;
                _a4_obj->f_end_label = l26;
                l30 = (void*) _a4_obj;
            }
            vader_array_push((vader_array_t*) l2, vader_ref_box(l30));
        } else if (l6.tag == 679u) {
            t0 = l6.payload.obj;
            vader_c_emit_c_ast_tidy_block(((vader_struct_vader_c_emit_c_ast_CFor_t*) t0)->f_body, l1);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CFor_t*) t0)->f_label;
            l33 = vader_c_emit_c_ast_used_label(t1, l1);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CFor_t*) t0)->f_end_label;
            l34 = vader_c_emit_c_ast_used_label(t1, l1);
            t0 = l6.payload.obj;
            l35 = ((vader_struct_vader_c_emit_c_ast_CFor_t*) t0)->f_label;
            if (l33 == l35) {
                t0 = l6.payload.obj;
                l37 = ((vader_struct_vader_c_emit_c_ast_CFor_t*) t0)->f_end_label;
                l36 = l34 == l37;
            } else {
                l36 = false;
            }
            if (l36) {
                l38 = l6.payload.obj;
            } else {
                t0 = l6.payload.obj;
                l39 = ((vader_struct_vader_c_emit_c_ast_CFor_t*) t0)->f_body;
                vader_struct_vader_c_emit_c_ast_CFor_t* _a5_obj = (vader_struct_vader_c_emit_c_ast_CFor_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CFor_t));
                vader_obj_header_init(_a5_obj, 679u);
                _a5_obj->f_label = l33;
                _a5_obj->f_body = l39;
                _a5_obj->f_end_label = l34;
                l38 = (void*) _a5_obj;
            }
            vader_array_push((vader_array_t*) l2, vader_ref_box(l38));
        } else {
            l40 = l6;
            vader_array_push((vader_array_t*) l2, l40);
        }
        t3 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t3;
    }
    vader_array_clear((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body);
    vader_array_push_all((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l0)->f_body, (vader_array_t*) l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static size_t vader_c_emit_c_ast_trailing_directives(void* l0, size_t l1) {
    size_t l2, l4;
    bool l3;
    size_t t0;
    int64_t t1;
    vader_box_t t2;
    l2 = (size_t) 0;
    for (;;) {
        t0 = ((vader_array_t*) l0)->length;
        if (((t0 - l2) > l1)) {
            t0 = ((vader_array_t*) l0)->length;
            t1 = ((t0 - INT64_C(1)) - l2);
            l4 = (size_t) (int64_t) t1;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            l3 = t2.tag == 676u;
        } else {
            l3 = false;
        }
        if (l3) {
            t1 = (l2 + INT64_C(1));
            l2 = (size_t) (int64_t) t1;
            continue;
        }
        break;
    }
    return l2;
}

vader_box_t vader_c_emit_c_ast_unsigned(int64_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CNumber_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CNumber_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CNumber_t));
    vader_obj_header_init(_a0_obj, 692u);
    _a0_obj->f_value = l0;
    _a0_obj->f_unsigned_v = true;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_c_emit_c_ast_used_label(vader_string_t l0, void* l1) {
    bool t0;
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableSet_Contains_contains__string(l1, l0);
    if (t0) {
        { vader_string_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

vader_box_t vader_c_emit_c_ast_verbatim(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a0_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
    vader_obj_header_init(_a0_obj, 711u);
    _a0_obj->f_text = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_c_emit_c_ast_write_assign(void* l0, void* l1) {
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
    l2 = ((vader_struct_vader_c_emit_c_ast_CAssign_t*) l1)->f_target;
    vader_c_emit_c_ast_write_expression(l0, l2);
    l2 = ((vader_struct_vader_c_emit_c_ast_CAssign_t*) l1)->f_operator;
    if (!(l2.tag == 0u)) {
        std_string_builder_append(l0, 8u);
        l3 = (void*) &vader_data_18;
        t0 = ((uint8_t) l2.payload.i);
        l4 = ((int64_t) (uint8_t) t0);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) t1)->f_spelling;
        std_string_builder_append(l0, l5);
        std_string_builder_append(l0, 345u);
    } else {
        std_string_builder_append(l0, 37u);
    }
    l2 = ((vader_struct_vader_c_emit_c_ast_CAssign_t*) l1)->f_value;
    vader_c_emit_c_ast_write_expression(l0, l2);
    std_string_builder_append(l0, 325u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_block(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    size_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l1)->f_body;
    l4 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CBlock_t*) l1)->f_body)->length;
    vader_c_emit_c_ast_write_statements(l0, l3, (size_t) 0, l4, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_case_body(void* l0, void* l1, bool l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    bool l10;
    void* t0 = NULL;
    int64_t t1;
    size_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l6, &l7, &t3 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = l1;
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        std_string_builder_append(l0, 8u);
        if (l6.tag == 677u) {
            t0 = l6.payload.obj;
            l7 = ((vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) t0)->f_expression;
            vader_c_emit_c_ast_write_expression(l0, l7);
            std_string_builder_append(l0, 325u);
        } else if (l6.tag == 698u) {
            l8 = l6.payload.obj;
            vader_c_emit_c_ast_write_return_text(l0, l8);
        } else if (l6.tag == 683u) {
            l9 = l6.payload.obj;
            vader_c_emit_c_ast_write_goto(l0, l9);
        } else {
            { vader_gc_top = gc_frame.prev; return; }
        }
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    t2 = ((vader_array_t*) l1)->length;
    if ((t2 > INT64_C(0))) {
        t2 = ((vader_array_t*) l1)->length;
        t1 = (t2 - INT64_C(1));
        l4 = (size_t) (int64_t) t1;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        t3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l10 = (t3.tag == 683u || t3.tag == 698u);
    } else {
        l10 = false;
    }
    if (!(l2)) {
        l10 = !(l10);
    } else {
        l10 = false;
    }
    if (l10) {
        std_string_builder_append(l0, 51u);
    }
    std_string_builder_append(l0, 1u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_closer(void* l0, vader_string_t l1, int32_t l2) {
    vader_string_t l3 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1 == 0u) {
        l3 = 2380u;
    } else {
        l3 = concat_3(2381u, l1, 296u);
    }
    vader_c_emit_c_ast_write_line(l0, l3, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_declaration(void* l0, void* l1, int32_t l2) {
    vader_string_t l3 = 0;
    size_t l4, l5, l6;
    void* l7 = NULL;
    int64_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[3] = { &l0, &l1, &l7 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_c_emit_c_ast_CDeclaration_t*) l1)->f_type;
    std_string_builder_append(l0, l3);
    std_string_builder_append(l0, 8u);
    t0 = (((int64_t) (int32_t) l2) * INT64_C(4));
    l4 = (size_t) (int64_t) t0;
    t1 = ((vader_struct_vader_c_emit_c_ast_CDeclaration_t*) l1)->f_type;
    l5 = vader_host_std_core_byte_len(t1);
    t0 = ((l4 + l5) + INT64_C(1));
    l4 = (size_t) (int64_t) t0;
    l5 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CDeclaration_t*) l1)->f_declarators)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        if ((l6 > INT64_C(0))) {
            std_string_builder_append(l0, 236u);
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CDeclaration_t*) l1)->f_declarators);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        vader_c_emit_c_ast_write_declarator(l0, l7, l4, l2);
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    std_string_builder_append(l0, 325u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_declarator(void* l0, void* l1, size_t l2, int32_t l3) {
    vader_box_t l4 = vader_box_null();
    vader_string_t l5 = 0;
    void* l6 = NULL;
    size_t l7;
    int64_t l8;
    int32_t t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_c_emit_c_ast_CDeclarator_t*) l1)->f_length;
    if (l4.tag == 193u) {
        l6 = std_core_new_byte_buffer((size_t) 22);
        l7 = (size_t) 0;
        l7 = std_core_write_string_at(l6, l7, 706u);
        t0 = ((int32_t) l4.payload.i);
        l8 = ((int64_t) (int32_t) t0);
        l7 = std_core_write_int(l6, l7, l8);
        l7 = std_core_write_string_at(l6, l7, 710u);
        l5 = std_core_finish_buffer(l6, l7);
    } else if (l4.tag == 710u) {
        l5 = 707u;
    } else {
        l5 = 0u;
    }
    t1 = ((vader_struct_vader_c_emit_c_ast_CDeclarator_t*) l1)->f_name;
    l5 = concat_2(t1, l5);
    l4 = ((vader_struct_vader_c_emit_c_ast_CDeclarator_t*) l1)->f_value;
    vader_c_emit_c_ast_write_declared(l0, l5, l4, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_declared(void* l0, vader_string_t l1, vader_box_t l2, size_t l3, int32_t l4) {
    vader_box_t l5 = vader_box_null();
    size_t l6;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_string_builder_append(l0, l1);
    if (!(l2.tag == 0u)) {
        std_string_builder_append(l0, 36u);
        l5 = l2;
        l6 = vader_host_std_core_byte_len(l1);
        t0 = ((l3 + l6) + INT64_C(2));
        l6 = (size_t) (int64_t) t0;
        vader_c_emit_c_ast_write_initializer(l0, l5, l6, l4);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_directive(void* l0, vader_string_t l1) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_string_builder_append(l0, l1);
    std_string_builder_append(l0, 1u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_element(void* l0, vader_box_t l1, int32_t l2) {
    size_t l3;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = (((int64_t) (int32_t) l2) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    if (l1.tag == 675u) {
        t1 = l1.payload.obj;
        l4 = ((vader_struct_vader_c_emit_c_ast_CDesignated_t*) t1)->f_designator;
        t1 = l1.payload.obj;
        l5 = ((vader_struct_vader_c_emit_c_ast_CDesignated_t*) t1)->f_value;
        vader_c_emit_c_ast_write_declared(l0, l4, l5, l3, l2);
    } else {
        l5 = l1;
        vader_c_emit_c_ast_write_initializer_line(l0, l5, l3, l2);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_else_chain(void* l0, void* l1, vader_string_t l2, int32_t l3) {
    vader_box_t l4 = vader_box_null(), l10 = vader_box_null();
    void* l5 = NULL;
    void* l11 = NULL;
    size_t l6, l7, l8;
    bool l9;
    int32_t l12;
    vader_string_t l13 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l4, &l10 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l11, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l13, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) l1)->f_else_block;
    if (l4.tag == 0u) {
        vader_c_emit_c_ast_write_closer(l0, l2, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l4.payload.obj;
    l5 = ((vader_struct_vader_c_emit_c_ast_CBlock_t*) t0)->f_body;
    l6 = vader_c_emit_c_ast_leading_directives(l5);
    l7 = ((vader_array_t*) l5)->length;
    l8 = vader_c_emit_c_ast_trailing_directives(l5, l6);
    t1 = (l7 - l8);
    l7 = (size_t) (int64_t) t1;
    vader_c_emit_c_ast_write_statements(l0, l5, (size_t) 0, l6, l3);
    t1 = (l6 + INT64_C(1));
    l8 = (size_t) (int64_t) t1;
    if (l7 == l8) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    } else {
        l4 = vader_box_obj(0u, NULL);
    }
    if (l4.tag == 684u) {
        if (l2 == 0u) {
            l9 = true;
        } else {
            t0 = l4.payload.obj;
            t2 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_end_label;
            l9 = t2 == 0u;
        }
    } else {
        l9 = false;
    }
    if (l9) {
        t0 = l4.payload.obj;
        l10 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_condition;
        vader_c_emit_c_ast_write_if_head(l0, 2382u, l10, l3);
        t0 = l4.payload.obj;
        l11 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_then_block;
        l12 = (l3 + INT32_C(1));
        vader_c_emit_c_ast_write_block(l0, l11, l12);
        l11 = l4.payload.obj;
        if (l2 != 0u) {
            l13 = l2;
        } else {
            t0 = l4.payload.obj;
            l13 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) t0)->f_end_label;
        }
        vader_c_emit_c_ast_write_else_chain(l0, l11, l13, l3);
        l8 = ((vader_array_t*) l5)->length;
        vader_c_emit_c_ast_write_statements(l0, l5, l7, l8, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_c_emit_c_ast_write_line(l0, 2383u, l3);
    l7 = ((vader_array_t*) l5)->length;
    l12 = (l3 + INT32_C(1));
    vader_c_emit_c_ast_write_statements(l0, l5, l6, l7, l12);
    vader_c_emit_c_ast_write_closer(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_expression(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    size_t l3, l7;
    int64_t l4;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null();
    int32_t l8;
    void* t0 = NULL;
    int32_t t1;
    vader_string_t t2 = 0;
    bool t3;
    vader_box_t t4 = vader_box_null();
    int64_t t5;
    size_t t6;
    vader_box_t* gc_roots[3] = { &l1, &l6, &t4 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l5, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 708u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) t0)->f_slot;
        if ((t1 < INT32_C(0))) {
            l2 = std_core_new_byte_buffer((size_t) 85);
            l3 = (size_t) 0;
            l3 = std_core_write_string_at(l2, l3, 1206u);
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) t0)->f_id;
            l4 = ((int64_t) (int32_t) t1);
            l3 = std_core_write_int(l2, l3, l4);
            l3 = std_core_write_string_at(l2, l3, 109u);
            t2 = std_core_finish_buffer(l2, l3);
            vader_host_std_abort_panic(t2);
        }
        std_string_builder_append(l0, 2054u);
        l2 = std_core_new_byte_buffer((size_t) 20);
        l3 = (size_t) 0;
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_c_emit_c_ast_CTemporary_t*) t0)->f_slot;
        l4 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l2, l3, l4);
        l5 = std_core_finish_buffer(l2, l3);
        std_string_builder_append(l0, l5);
    } else if (l1.tag == 689u) {
        std_string_builder_append(l0, 1691u);
        l2 = std_core_new_byte_buffer((size_t) 20);
        l3 = (size_t) 0;
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_c_emit_c_ast_CLocal_t*) t0)->f_slot;
        l4 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l2, l3, l4);
        l5 = std_core_finish_buffer(l2, l3);
        std_string_builder_append(l0, l5);
    } else if (l1.tag == 711u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_c_emit_c_ast_CVerbatim_t*) t0)->f_text;
        std_string_builder_append(l0, l5);
    } else if (l1.tag == 688u) {
        l2 = l1.payload.obj;
        vader_c_emit_c_ast_write_integer_literal(l0, l2);
    } else if (l1.tag == 692u) {
        l2 = std_core_new_byte_buffer((size_t) 20);
        l3 = (size_t) 0;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_c_emit_c_ast_CNumber_t*) t0)->f_value;
        l3 = std_core_write_int(l2, l3, l4);
        l5 = std_core_finish_buffer(l2, l3);
        std_string_builder_append(l0, l5);
        t0 = l1.payload.obj;
        t3 = ((vader_struct_vader_c_emit_c_ast_CNumber_t*) t0)->f_unsigned_v;
        if (t3) {
            std_string_builder_append(l0, 2134u);
        }
    } else if (l1.tag == 665u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_c_emit_c_ast_CCall_t*) t0)->f_callee;
        std_string_builder_append(l0, l5);
        std_string_builder_append(l0, 192u);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_c_emit_c_ast_CCall_t*) t0)->f_arguments;
        vader_c_emit_c_ast_write_list(l0, l2);
        std_string_builder_append(l0, 206u);
    } else if (l1.tag == 668u) {
        std_string_builder_append(l0, 200u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t*) t0)->f_model;
        vader_c_emit_c_ast_write_expression(l0, l6);
        std_string_builder_append(l0, 224u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CCastToTypeOf_t*) t0)->f_value;
        vader_c_emit_c_ast_write_operand(l0, l6, INT32_C(11));
    } else if (l1.tag == 667u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_c_emit_c_ast_CCast_t*) t0)->f_types;
        l3 = ((vader_array_t*) l2)->length;
        l7 = (size_t) 0;
        while ((l7 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
            t4 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l7];
            l5 = t4.payload.s;
            std_string_builder_append(l0, 192u);
            std_string_builder_append(l0, l5);
            std_string_builder_append(l0, 206u);
            t5 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t5;
        }
        std_string_builder_append(l0, 8u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CCast_t*) t0)->f_value;
        vader_c_emit_c_ast_write_operand(l0, l6, INT32_C(11));
    } else if (l1.tag == 662u) {
        l2 = (void*) &vader_data_18;
        t0 = l1.payload.obj;
        l4 = ((int64_t) (uint8_t) ((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_operator);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_left;
        l8 = ((vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) l2)->f_precedence;
        vader_c_emit_c_ast_write_operand(l0, l6, l8);
        std_string_builder_append(l0, 8u);
        l5 = ((vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) l2)->f_spelling;
        std_string_builder_append(l0, l5);
        std_string_builder_append(l0, 8u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_right;
        t1 = ((vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) l2)->f_precedence;
        l8 = (t1 + INT32_C(1));
        vader_c_emit_c_ast_write_operand(l0, l6, l8);
    } else if (l1.tag == 660u) {
        std_string_builder_append(l0, 173u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CAddressOf_t*) t0)->f_operand;
        vader_c_emit_c_ast_write_operand(l0, l6, INT32_C(11));
    } else if (l1.tag == 709u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_c_emit_c_ast_CUnary_t*) t0)->f_operator;
        std_string_builder_append(l0, l5);
        std_string_builder_append(l0, 192u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CUnary_t*) t0)->f_operand;
        vader_c_emit_c_ast_write_expression(l0, l6);
        std_string_builder_append(l0, 206u);
    } else if (l1.tag == 695u) {
        std_string_builder_append(l0, 192u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CParenthesized_t*) t0)->f_inner;
        vader_c_emit_c_ast_write_expression(l0, l6);
        std_string_builder_append(l0, 206u);
    } else if (l1.tag == 691u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CMember_t*) t0)->f_base;
        vader_c_emit_c_ast_write_expression(l0, l6);
        t0 = l1.payload.obj;
        t3 = ((vader_struct_vader_c_emit_c_ast_CMember_t*) t0)->f_arrow;
        if (t3) {
            l5 = 248u;
        } else {
            l5 = 258u;
        }
        std_string_builder_append(l0, l5);
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_c_emit_c_ast_CMember_t*) t0)->f_member;
        std_string_builder_append(l0, l5);
    } else if (l1.tag == 686u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CIndex_t*) t0)->f_base;
        vader_c_emit_c_ast_write_expression(l0, l6);
        std_string_builder_append(l0, 706u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CIndex_t*) t0)->f_index;
        vader_c_emit_c_ast_write_expression(l0, l6);
        std_string_builder_append(l0, 710u);
    } else if (l1.tag == 670u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_condition;
        vader_c_emit_c_ast_write_expression(l0, l6);
        std_string_builder_append(l0, 38u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_then_value;
        vader_c_emit_c_ast_write_expression(l0, l6);
        std_string_builder_append(l0, 31u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CConditional_t*) t0)->f_else_value;
        vader_c_emit_c_ast_write_expression(l0, l6);
    } else if (l1.tag == 675u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_c_emit_c_ast_CDesignated_t*) t0)->f_designator;
        std_string_builder_append(l0, l5);
        std_string_builder_append(l0, 37u);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CDesignated_t*) t0)->f_value;
        vader_c_emit_c_ast_write_expression(l0, l6);
    } else if (l1.tag == 669u) {
        std_string_builder_append(l0, 192u);
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t*) t0)->f_type;
        std_string_builder_append(l0, l5);
        std_string_builder_append(l0, 228u);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_c_emit_c_ast_CCompoundLiteral_t*) t0)->f_elements;
        vader_c_emit_c_ast_write_list(l0, l2);
        std_string_builder_append(l0, 127u);
    } else if (l1.tag == 704u) {
        t0 = l1.payload.obj;
        l5 = std_string_join(((vader_struct_vader_c_emit_c_ast_CStringLiterals_t*) t0)->f_literals, 8u);
        std_string_builder_append(l0, l5);
    } else if (l1.tag == 687u) {
        t0 = l1.payload.obj;
        t6 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CInitializerList_t*) t0)->f_elements)->length;
        if (t6 == INT64_C(0)) {
            std_string_builder_append(l0, 2373u);
        } else {
            std_string_builder_append(l0, 2372u);
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_c_emit_c_ast_CInitializerList_t*) t0)->f_elements;
            vader_c_emit_c_ast_write_list(l0, l2);
            std_string_builder_append(l0, 127u);
        }
    } else if (l1.tag == 701u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_c_emit_c_ast_CSequence_t*) t0)->f_parts;
        l3 = ((vader_array_t*) l2)->length;
        l7 = (size_t) 0;
        while ((l7 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
            l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
            vader_c_emit_c_ast_write_expression(l0, l6);
            t5 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t5;
        }
    } else {
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_filled(void* l0, void* l1, int32_t l2) {
    size_t l3, l4, l6, l7, l10;
    void* l5 = NULL;
    vader_box_t l8 = vader_box_null();
    vader_string_t l9 = 0;
    bool l11;
    int64_t t0;
    size_t t1;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = (((int64_t) (int32_t) l2) * INT64_C(4));
    l3 = (size_t) (int64_t) t0;
    l4 = l3;
    l5 = l1;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l9 = vader_c_emit_c_ast_text_of(l8);
        t1 = vader_host_std_core_byte_len(l9);
        t0 = (t1 + INT64_C(1));
        l10 = (size_t) (int64_t) t0;
        if ((l4 > l3)) {
            l11 = (((l4 + INT64_C(1)) + l10) > INT64_C(100));
        } else {
            l11 = false;
        }
        if (l11) {
            std_string_builder_append(l0, 1u);
            l4 = l3;
        }
        if (l4 == l3) {
            vader_c_emit_c_ast_indent(l0, l2);
        } else {
            std_string_builder_append(l0, 8u);
            t0 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t0;
        }
        if (((l4 + l10) > INT64_C(100))) {
            vader_c_emit_c_ast_write_element(l0, l8, l2);
            std_string_builder_append(l0, 235u);
            l4 = l3;
        } else {
            std_string_builder_append(l0, l9);
            std_string_builder_append(l0, 234u);
            t0 = (l4 + l10);
            l4 = (size_t) (int64_t) t0;
        }
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    if ((l4 > l3)) {
        std_string_builder_append(l0, 1u);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_function(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_c_emit_c_ast_CFunction_t*) l1)->f_signature;
    vader_c_emit_c_ast_write_signature(l0, l2);
    std_string_builder_append(l0, 124u);
    l2 = ((vader_struct_vader_c_emit_c_ast_CFunction_t*) l1)->f_prologue;
    l3 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CFunction_t*) l1)->f_prologue)->length;
    vader_c_emit_c_ast_write_statements(l0, l2, (size_t) 0, l3, INT32_C(1));
    l2 = ((vader_struct_vader_c_emit_c_ast_CFunction_t*) l1)->f_body;
    vader_c_emit_c_ast_write_block(l0, l2, INT32_C(1));
    vader_c_emit_c_ast_write_line(l0, 2380u, INT32_C(0));
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_goto(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    vader_string_t l3 = 0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_c_emit_c_ast_CGoto_t*) l1)->f_condition;
    l3 = ((vader_struct_vader_c_emit_c_ast_CGoto_t*) l1)->f_label;
    l3 = concat_3(1525u, l3, 325u);
    vader_c_emit_c_ast_write_jump(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_if(void* l0, void* l1, int32_t l2) {
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
    l3 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) l1)->f_condition;
    vader_c_emit_c_ast_write_if_head(l0, 1587u, l3, l2);
    l4 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) l1)->f_then_block;
    l5 = (l2 + INT32_C(1));
    vader_c_emit_c_ast_write_block(l0, l4, l5);
    l6 = ((vader_struct_vader_c_emit_c_ast_CIf_t*) l1)->f_end_label;
    vader_c_emit_c_ast_write_else_chain(l0, l1, l6, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_if_head(void* l0, vader_string_t l1, vader_box_t l2, int32_t l3) {
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_c_emit_c_ast_indent(l0, l3);
    std_string_builder_append(l0, l1);
    vader_c_emit_c_ast_write_expression(l0, l2);
    std_string_builder_append(l0, 215u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_initializer(void* l0, vader_box_t l1, size_t l2, int32_t l3) {
    vader_string_t l4 = 0;
    vader_string_t l9 = 0;
    bool l5;
    size_t l6, l8;
    void* l7 = NULL;
    int32_t l10;
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t3 };
    void** gc_raw_roots[3] = { &l0, &l7, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l4, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_c_emit_c_ast_text_of(l1);
    if (l1.tag == 704u) {
        t0 = (l2 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
        t1 = vader_c_emit_c_ast_fits(l4, l6);
        l5 = !(t1);
    } else {
        l5 = false;
    }
    if (l5) {
        t2 = l1.payload.obj;
        l7 = ((vader_struct_vader_c_emit_c_ast_CStringLiterals_t*) t2)->f_literals;
        l6 = ((vader_array_t*) l7)->length;
        l8 = (size_t) 0;
        while ((l8 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
            t3 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
            l9 = t3.payload.s;
            std_string_builder_append(l0, 1u);
            l10 = (l3 + INT32_C(1));
            vader_c_emit_c_ast_indent(l0, l10);
            std_string_builder_append(l0, l9);
            t0 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t0;
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string_builder_append(l0, 8u);
    t0 = (l2 + INT64_C(1));
    l6 = (size_t) (int64_t) t0;
    vader_c_emit_c_ast_write_laid_out(l0, l1, l4, l6, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_initializer_line(void* l0, vader_box_t l1, size_t l2, int32_t l3) {
    vader_string_t l4 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_c_emit_c_ast_text_of(l1);
    vader_c_emit_c_ast_write_laid_out(l0, l1, l4, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_integer_literal(void* l0, void* l1) {
    bool l2;
    vader_string_t l3 = 0;
    void* l4 = NULL;
    size_t l5;
    int64_t l6;
    bool t0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) l1)->f_class == INT32_C(3);
    t0 = vader_c_emit_c_ast_is_most_negative(l1);
    if (t0) {
        if (l2) {
            l3 = 446u;
        } else {
            l3 = 444u;
        }
        std_string_builder_append(l0, l3);
    } else {
        if (l2) {
            l3 = 445u;
        } else {
            l3 = 443u;
        }
        std_string_builder_append(l0, l3);
        l4 = std_core_new_byte_buffer((size_t) 20);
        l5 = (size_t) 0;
        l6 = ((vader_struct_vader_c_emit_c_ast_CIntegerLiteral_t*) l1)->f_value;
        l5 = std_core_write_int(l4, l5, l6);
        l3 = std_core_finish_buffer(l4, l5);
        std_string_builder_append(l0, l3);
        std_string_builder_append(l0, 206u);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_jump(void* l0, vader_box_t l1, vader_string_t l2) {
    vader_box_t l3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 0u)) {
        std_string_builder_append(l0, 1587u);
        l3 = l1;
        vader_c_emit_c_ast_write_expression(l0, l3);
        std_string_builder_append(l0, 207u);
    }
    std_string_builder_append(l0, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_laid_out(void* l0, vader_box_t l1, vader_string_t l2, size_t l3, int32_t l4) {
    bool l5;
    void* l6 = NULL;
    size_t l7, l8;
    vader_box_t l9 = vader_box_null();
    int32_t l10, l11;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l1, &l9 };
    void** gc_raw_roots[3] = { &l0, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 687u)) {
        l5 = true;
    } else {
        l5 = vader_c_emit_c_ast_fits(l2, l3);
    }
    if (l5) {
        std_string_builder_append(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_string_builder_append(l0, 2371u);
    t0 = l1.payload.obj;
    t1 = vader_c_emit_c_ast_is_table(((vader_struct_vader_c_emit_c_ast_CInitializerList_t*) t0)->f_elements);
    if (t1) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CInitializerList_t*) t0)->f_elements;
        l7 = ((vader_array_t*) l6)->length;
        l8 = (size_t) 0;
        while ((l8 < l7)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
            l9 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
            l10 = (l4 + INT32_C(1));
            vader_c_emit_c_ast_indent(l0, l10);
            l11 = (l4 + INT32_C(1));
            vader_c_emit_c_ast_write_element(l0, l9, l11);
            std_string_builder_append(l0, 235u);
            t2 = (l8 + INT64_C(1));
            l8 = (size_t) (int64_t) t2;
        }
    } else {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_c_emit_c_ast_CInitializerList_t*) t0)->f_elements;
        l10 = (l4 + INT32_C(1));
        vader_c_emit_c_ast_write_filled(l0, l6, l10);
    }
    vader_c_emit_c_ast_indent(l0, l4);
    std_string_builder_append(l0, 2380u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_line(void* l0, vader_string_t l1, int32_t l2) {
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_c_emit_c_ast_indent(l0, l2);
    std_string_builder_append(l0, l1);
    std_string_builder_append(l0, 1u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_list(void* l0, void* l1) {
    size_t l2, l3;
    vader_box_t l4 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        if ((l3 > INT64_C(0))) {
            std_string_builder_append(l0, 236u);
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        vader_c_emit_c_ast_write_expression(l0, l4);
        t0 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_operand(void* l0, vader_box_t l1, int32_t l2) {
    bool l3;
    void* l4 = NULL;
    int64_t l5;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 662u) {
        l4 = (void*) &vader_data_18;
        t0 = l1.payload.obj;
        l5 = ((int64_t) (uint8_t) ((vader_struct_vader_c_emit_c_ast_CBinary_t*) t0)->f_operator);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        t1 = ((vader_struct_vader_c_emit_c_ast_COperatorInfo_t*) t0)->f_precedence;
        l3 = (t1 < l2);
    } else {
        l3 = false;
    }
    if (l3) {
        std_string_builder_append(l0, 192u);
        l4 = l1.payload.obj;
        vader_c_emit_c_ast_write_expression(l0, vader_ref_box(l4));
        std_string_builder_append(l0, 206u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_c_emit_c_ast_write_expression(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_parameters(void* l0, void* l1) {
    size_t l2, l3;
    void* l4 = NULL;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    size_t t0;
    vader_string_t t1 = 0;
    int64_t t2;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[4] = { &l5, &l6, &l7, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l1)->length;
    if (t0 == INT64_C(0)) {
        std_string_builder_append(l0, 2336u);
    }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        if ((l3 > INT64_C(0))) {
            std_string_builder_append(l0, 236u);
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = ((vader_struct_vader_c_emit_c_ast_CParameter_t*) l4)->f_name;
        if (t1 == 0u) {
            l5 = ((vader_struct_vader_c_emit_c_ast_CParameter_t*) l4)->f_type;
        } else {
            l6 = ((vader_struct_vader_c_emit_c_ast_CParameter_t*) l4)->f_type;
            l7 = ((vader_struct_vader_c_emit_c_ast_CParameter_t*) l4)->f_name;
            l5 = concat_3(l6, 8u, l7);
        }
        std_string_builder_append(l0, l5);
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_return(void* l0, void* l1, int32_t l2) {
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_c_emit_c_ast_indent(l0, l2);
    vader_c_emit_c_ast_write_return_text(l0, l1);
    std_string_builder_append(l0, 1u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_return_text(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    size_t l3, l4;
    bool l6, l8;
    vader_box_t l7 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l9 = 0;
    bool t0;
    int64_t t1;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l7, &l10 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l9, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l1)->f_pops_frame;
    if (t0) {
        std_string_builder_append(l0, 2372u);
    }
    l2 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l1)->f_stores;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_c_emit_c_ast_write_assign(l0, l5);
        std_string_builder_append(l0, 8u);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    t0 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l1)->f_pops_frame;
    if (t0) {
        t2 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l1)->f_snapshot_type;
        l6 = t2 != 0u;
    } else {
        l6 = false;
    }
    l7 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l1)->f_value;
    if (l6) {
        l8 = !(l7.tag == 0u);
    } else {
        l8 = false;
    }
    if (l8) {
        l9 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l1)->f_snapshot_type;
        std_string_builder_append(l0, l9);
        std_string_builder_append(l0, 40u);
        l10 = l7;
        vader_c_emit_c_ast_write_expression(l0, l10);
        std_string_builder_append(l0, 327u);
    }
    t0 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l1)->f_pops_frame;
    if (t0) {
        vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a1_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
        vader_obj_header_init(_a1_obj, 711u);
        _a1_obj->f_text = 2284u;
        l2 = (void*) _a1_obj;
        vader_struct_vader_c_emit_c_ast_CVerbatim_t* _a2_obj = (vader_struct_vader_c_emit_c_ast_CVerbatim_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CVerbatim_t));
        vader_obj_header_init(_a2_obj, 711u);
        _a2_obj->f_text = 1512u;
        l5 = (void*) _a2_obj;
        vader_struct_vader_c_emit_c_ast_CAssign_t* _a3_obj = (vader_struct_vader_c_emit_c_ast_CAssign_t*) vader_gc_alloc(sizeof(vader_struct_vader_c_emit_c_ast_CAssign_t));
        vader_obj_header_init(_a3_obj, 661u);
        _a3_obj->f_target = vader_ref_box(l2);
        _a3_obj->f_value = vader_ref_box(l5);
        _a3_obj->f_operator = vader_box_obj(0u, NULL);
        l2 = (void*) _a3_obj;
        vader_c_emit_c_ast_write_assign(l0, l2);
        std_string_builder_append(l0, 8u);
    }
    if (l7.tag == 0u) {
        std_string_builder_append(l0, 1903u);
    } else {
        std_string_builder_append(l0, 1897u);
        if (l6) {
            std_string_builder_append(l0, 750u);
        } else {
            vader_c_emit_c_ast_write_expression(l0, l7);
        }
        std_string_builder_append(l0, 325u);
    }
    t0 = ((vader_struct_vader_c_emit_c_ast_CReturn_t*) l1)->f_pops_frame;
    if (t0) {
        std_string_builder_append(l0, 127u);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_signature(void* l0, void* l1) {
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
    l2 = vader_c_emit_c_ast_storage_keyword(((vader_struct_vader_c_emit_c_ast_CSignature_t*) l1)->f_storage);
    std_string_builder_append(l0, l2);
    t0 = ((vader_struct_vader_c_emit_c_ast_CSignature_t*) l1)->f_inline_v;
    if (t0) {
        std_string_builder_append(l0, 1614u);
    }
    l2 = ((vader_struct_vader_c_emit_c_ast_CSignature_t*) l1)->f_result;
    l3 = ((vader_struct_vader_c_emit_c_ast_CSignature_t*) l1)->f_name;
    l2 = concat_4(l2, 8u, l3, 192u);
    std_string_builder_append(l0, l2);
    l4 = ((vader_struct_vader_c_emit_c_ast_CSignature_t*) l1)->f_parameters;
    vader_c_emit_c_ast_write_parameters(l0, l4);
    std_string_builder_append(l0, 206u);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_statements(void* l0, void* l1, size_t l2, size_t l3, int32_t l4) {
    size_t l5;
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
    int64_t t2;
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
        if (l6.tag == 676u) {
            t0 = l6.payload.obj;
            l7 = ((vader_struct_vader_c_emit_c_ast_CDirective_t*) t0)->f_text;
            vader_c_emit_c_ast_write_directive(l0, l7);
        } else if (l6.tag == 661u) {
            vader_c_emit_c_ast_indent(l0, l4);
            l8 = l6.payload.obj;
            vader_c_emit_c_ast_write_assign(l0, l8);
            std_string_builder_append(l0, 1u);
        } else if (l6.tag == 677u) {
            vader_c_emit_c_ast_indent(l0, l4);
            t0 = l6.payload.obj;
            l9 = ((vader_struct_vader_c_emit_c_ast_CExpressionStatement_t*) t0)->f_expression;
            vader_c_emit_c_ast_write_expression(l0, l9);
            std_string_builder_append(l0, 326u);
        } else if (l6.tag == 690u) {
            vader_c_emit_c_ast_indent(l0, l4);
            t0 = l6.payload.obj;
            l10 = ((vader_struct_vader_c_emit_c_ast_CMacroStatement_t*) t0)->f_call;
            vader_c_emit_c_ast_write_expression(l0, vader_ref_box(l10));
            std_string_builder_append(l0, 1u);
        } else if (l6.tag == 672u) {
            vader_c_emit_c_ast_indent(l0, l4);
            l11 = l6.payload.obj;
            vader_c_emit_c_ast_write_declaration(l0, l11, l4);
            std_string_builder_append(l0, 1u);
        } else if (l6.tag == 684u) {
            l12 = l6.payload.obj;
            vader_c_emit_c_ast_write_if(l0, l12, l4);
        } else if (l6.tag == 698u) {
            l13 = l6.payload.obj;
            vader_c_emit_c_ast_write_return(l0, l13, l4);
        } else if (l6.tag == 683u) {
            vader_c_emit_c_ast_indent(l0, l4);
            l14 = l6.payload.obj;
            vader_c_emit_c_ast_write_goto(l0, l14);
            std_string_builder_append(l0, 1u);
        } else if (l6.tag == 707u) {
            l15 = l6.payload.obj;
            vader_c_emit_c_ast_write_switch(l0, l15, l4);
        } else if (l6.tag == 699u) {
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_label;
            l16 = vader_c_emit_c_ast_labelled(t1, 2370u);
            vader_c_emit_c_ast_write_line(l0, l16, l4);
            t0 = l6.payload.obj;
            l17 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_body;
            l18 = (l4 + INT32_C(1));
            vader_c_emit_c_ast_write_block(l0, l17, l18);
            t0 = l6.payload.obj;
            l19 = ((vader_struct_vader_c_emit_c_ast_CScope_t*) t0)->f_end_label;
            vader_c_emit_c_ast_write_closer(l0, l19, l4);
        } else if (l6.tag == 712u) {
            vader_c_emit_c_ast_indent(l0, l4);
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_label;
            l20 = vader_c_emit_c_ast_labelled(t1, 2348u);
            std_string_builder_append(l0, l20);
            t0 = l6.payload.obj;
            l21 = ((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_condition;
            vader_c_emit_c_ast_write_expression(l0, l21);
            std_string_builder_append(l0, 215u);
            t0 = l6.payload.obj;
            l22 = ((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_body;
            l23 = (l4 + INT32_C(1));
            vader_c_emit_c_ast_write_block(l0, l22, l23);
            t0 = l6.payload.obj;
            l24 = ((vader_struct_vader_c_emit_c_ast_CWhile_t*) t0)->f_end_label;
            vader_c_emit_c_ast_write_closer(l0, l24, l4);
        } else if (l6.tag == 679u) {
            t0 = l6.payload.obj;
            t1 = ((vader_struct_vader_c_emit_c_ast_CFor_t*) t0)->f_label;
            l25 = vader_c_emit_c_ast_labelled(t1, 1489u);
            vader_c_emit_c_ast_write_line(l0, l25, l4);
            t0 = l6.payload.obj;
            l26 = ((vader_struct_vader_c_emit_c_ast_CFor_t*) t0)->f_body;
            l27 = (l4 + INT32_C(1));
            vader_c_emit_c_ast_write_block(l0, l26, l27);
            t0 = l6.payload.obj;
            l28 = ((vader_struct_vader_c_emit_c_ast_CFor_t*) t0)->f_end_label;
            vader_c_emit_c_ast_write_closer(l0, l28, l4);
        } else if (l6.tag == 671u) {
            vader_c_emit_c_ast_indent(l0, l4);
            t0 = l6.payload.obj;
            l29 = ((vader_struct_vader_c_emit_c_ast_CContinue_t*) t0)->f_condition;
            vader_c_emit_c_ast_write_jump(l0, l29, 1301u);
            std_string_builder_append(l0, 1u);
        } else if (l6.tag == 664u) {
            vader_c_emit_c_ast_indent(l0, l4);
            t0 = l6.payload.obj;
            l30 = ((vader_struct_vader_c_emit_c_ast_CBreak_t*) t0)->f_condition;
            vader_c_emit_c_ast_write_jump(l0, l30, 1158u);
            std_string_builder_append(l0, 1u);
        } else {
            { vader_gc_top = gc_frame.prev; return; }
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_switch(void* l0, void* l1, int32_t l2) {
    vader_box_t l3 = vader_box_null(), l8 = vader_box_null();
    size_t l4, l5, l11, l12;
    void* l6 = NULL;
    void* l9 = NULL;
    int32_t l7;
    bool l10;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l3, &l8 };
    void** gc_raw_roots[4] = { &l0, &l1, &l6, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_c_emit_c_ast_indent(l0, l2);
    std_string_builder_append(l0, 2046u);
    l3 = ((vader_struct_vader_c_emit_c_ast_CSwitch_t*) l1)->f_subject;
    vader_c_emit_c_ast_write_expression(l0, l3);
    std_string_builder_append(l0, 215u);
    l3 = ((vader_struct_vader_c_emit_c_ast_CSwitch_t*) l1)->f_default_body;
    l4 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CSwitch_t*) l1)->f_cases)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CSwitch_t*) l1)->f_cases);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l7 = (l2 + INT32_C(1));
        vader_c_emit_c_ast_indent(l0, l7);
        std_string_builder_append(l0, 1247u);
        l8 = ((vader_struct_vader_c_emit_c_ast_CCase_t*) l6)->f_value;
        vader_c_emit_c_ast_write_expression(l0, l8);
        std_string_builder_append(l0, 294u);
        l9 = ((vader_struct_vader_c_emit_c_ast_CCase_t*) l6)->f_body;
        if (l3.tag == 0u) {
            t0 = (l5 + INT64_C(1));
            l11 = (size_t) (int64_t) t0;
            l12 = ((vader_array_t*) ((vader_struct_vader_c_emit_c_ast_CSwitch_t*) l1)->f_cases)->length;
            l10 = l11 == l12;
        } else {
            l10 = false;
        }
        vader_c_emit_c_ast_write_case_body(l0, l9, l10);
        t0 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t0;
    }
    if (!(l3.tag == 0u)) {
        l7 = (l2 + INT32_C(1));
        vader_c_emit_c_ast_indent(l0, l7);
        std_string_builder_append(l0, 1323u);
        l6 = l3.payload.obj;
        vader_c_emit_c_ast_write_case_body(l0, l6, true);
    }
    vader_c_emit_c_ast_write_line(l0, 2380u, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_c_emit_c_ast_write_top_level(void* l0, vader_box_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l4 = 0;
    vader_string_t l9 = 0;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    void* l8 = NULL;
    size_t l6, l7;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t* gc_roots[2] = { &l1, &l3 };
    void** gc_raw_roots[4] = { &l0, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l4, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 685u) {
        t0 = l1.payload.obj;
        l2 = vader_c_emit_c_ast_include_operand(t0);
        l2 = concat_3(153u, l2, 1u);
        std_string_builder_append(l0, l2);
    } else if (l1.tag == 674u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_c_emit_c_ast_CDefine_t*) t0)->f_name;
        l2 = concat_3(152u, l2, 8u);
        std_string_builder_append(l0, l2);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_c_emit_c_ast_CDefine_t*) t0)->f_value;
        vader_c_emit_c_ast_write_expression(l0, l3);
        std_string_builder_append(l0, 1u);
    } else if (l1.tag == 706u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_c_emit_c_ast_CStructForward_t*) t0)->f_name;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_c_emit_c_ast_CStructForward_t*) t0)->f_name;
        l2 = concat_5(2133u, l2, 8u, l4, 326u);
        std_string_builder_append(l0, l2);
    } else if (l1.tag == 705u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_c_emit_c_ast_CStructDefinition_t*) t0)->f_name;
        l2 = concat_3(2030u, l2, 124u);
        std_string_builder_append(l0, l2);
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_c_emit_c_ast_CStructDefinition_t*) t0)->f_fields;
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
            l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
            l2 = ((vader_struct_vader_c_emit_c_ast_CField_t*) l8)->f_type;
            l4 = ((vader_struct_vader_c_emit_c_ast_CField_t*) l8)->f_name;
            l9 = concat_4(l2, 8u, l4, 325u);
            vader_c_emit_c_ast_write_line(l0, l9, INT32_C(1));
            t1 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t1;
        }
        std_string_builder_append(l0, 2384u);
    } else if (l1.tag == 682u) {
        t0 = l1.payload.obj;
        t2 = ((vader_struct_vader_c_emit_c_ast_CGlobal_t*) t0)->f_constant;
        if (t2) {
            l2 = 1295u;
        } else {
            l2 = 0u;
        }
        t0 = l1.payload.obj;
        l4 = vader_c_emit_c_ast_storage_keyword(((vader_struct_vader_c_emit_c_ast_CGlobal_t*) t0)->f_storage);
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_c_emit_c_ast_CGlobal_t*) t0)->f_type;
        l2 = concat_4(l4, l2, l9, 8u);
        std_string_builder_append(l0, l2);
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_c_emit_c_ast_CGlobal_t*) t0)->f_declarator;
        l6 = vader_host_std_core_byte_len(l2);
        vader_c_emit_c_ast_write_declarator(l0, l5, l6, INT32_C(0));
        std_string_builder_append(l0, 326u);
    } else if (l1.tag == 697u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_c_emit_c_ast_CPrototype_t*) t0)->f_signature;
        vader_c_emit_c_ast_write_signature(l0, l5);
        std_string_builder_append(l0, 326u);
    } else if (l1.tag == 681u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t*) t0)->f_result;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t*) t0)->f_name;
        l2 = concat_5(2132u, l2, 21u, l4, 223u);
        std_string_builder_append(l0, l2);
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_c_emit_c_ast_CFunctionPointerTypedef_t*) t0)->f_parameters;
        vader_c_emit_c_ast_write_parameters(l0, l5);
        std_string_builder_append(l0, 226u);
    } else if (l1.tag == 680u) {
        l5 = l1.payload.obj;
        vader_c_emit_c_ast_write_function(l0, l5);
    } else if (l1.tag == 703u) {
        std_string_builder_append(l0, 728u);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_c_emit_c_ast_CStaticAssert_t*) t0)->f_condition;
        vader_c_emit_c_ast_write_expression(l0, l3);
        std_string_builder_append(l0, 236u);
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_c_emit_c_ast_CStaticAssert_t*) t0)->f_message;
        vader_c_emit_c_ast_write_expression(l0, vader_ref_box(l5));
        std_string_builder_append(l0, 226u);
    } else {
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}
