#include "bootstrap.split.h"

static void* vader_comptime_add(void* l0, void* l1, void* l2);
static bool vader_comptime_all_concrete_enough(void* l0);
static void* vader_comptime_arg_count_error(void* l0, vader_string_t l1, size_t l2);
static void* vader_comptime_arg_error(void* l0, vader_string_t l1);
static void* vader_comptime_arithmetic(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static void* vader_comptime_arithmetic_int(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static void* vader_comptime_arithmetic_or_concat(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static vader_string_t vader_comptime_assert_message(void* l0);
static void vader_comptime_bake_file_exprs(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_comptime_bake_one_file_expr(void* l0, void* l1, void* l2, void* l3, void* l4);
static int64_t vader_comptime_bit_not_i64(int64_t l0);
static void* vader_comptime_bool_op(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static vader_box_t vader_comptime_bool_value(bool l0);
static vader_string_t vader_comptime_build_display_key(void* l0, void* l1);
static vader_box_t vader_comptime_build_vm_required(void* l0, void* l1, void* l2, vader_string_t l3);
static vader_string_t vader_comptime_canonical_type_key(vader_box_t l0);
static void vader_comptime_collect_block_deps(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_comptime_collect_expr_deps(vader_box_t l0, void* l1, void* l2, void* l3, void* l4);
static void vader_comptime_collect_file_intrinsics(vader_box_t l0, void* l1);
static void vader_comptime_collect_in_block(void* l0, void* l1);
static void vader_comptime_collect_in_expr(vader_box_t l0, void* l1);
static void vader_comptime_collect_in_stmt(vader_box_t l0, void* l1);
static void* vader_comptime_collect_nodes(void* l0);
static void vader_comptime_collect_stmt_deps(vader_box_t l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_comptime_combine_binary(void* l0, vader_box_t l1, vader_box_t l2);
static void* vader_comptime_compare(void* l0, vader_box_t l1, vader_box_t l2, uint8_t l3);
static vader_string_t vader_comptime_cycle_names(size_t l0, size_t l1, void* l2, size_t l3, void* l4);
static void* vader_comptime_diag_sink(void);
static vader_string_t vader_comptime_display_value(vader_box_t l0);
static void* vader_comptime_division_by_zero(void* l0, vader_string_t l1);
static void vader_comptime_emit_cycle(size_t l0, void* l1, size_t l2, void* l3, void* l4, void* l5);
static void* vader_comptime_equality_only(void* l0, bool l1, uint8_t l2, vader_string_t l3);
static void vader_comptime_evaluate_assert_decls(void* l0, void* l1, void* l2, void* l3);
static void* vader_comptime_evaluate_binary_expr(void* l0, void* l1, void* l2);
static void* vader_comptime_evaluate_bool_lit(void* l0);
static void* vader_comptime_evaluate_call_expr(void* l0, void* l1);
static void* vader_comptime_evaluate_char_lit(void* l0);
static void* vader_comptime_evaluate_float_lit(void* l0);
static void* vader_comptime_evaluate_fn_body(void* l0, void* l1, void* l2);
static void* vader_comptime_evaluate_ident(void* l0, void* l1);
static void* vader_comptime_evaluate_int_lit(void* l0);
static void* vader_comptime_evaluate_intrinsic_call(void* l0, void* l1);
static void vader_comptime_evaluate_module_decls(void* l0, void* l1, void* l2, void* l3, vader_string_t l4, void* l5);
static void* vader_comptime_evaluate_null_lit(void* l0);
static void* vader_comptime_evaluate_seq_lit(void* l0, void* l1, void* l2);
static void* vader_comptime_evaluate_string_lit(void* l0, void* l1, void* l2);
static void* vader_comptime_evaluate_unary_expr(void* l0, void* l1, void* l2);
static vader_string_t vader_comptime_expr_kind_label(vader_box_t l0);
static void* vader_comptime_fail(void* l0);
static double vader_comptime_float_arith(uint8_t l0, double l1, double l2);
static bool vader_comptime_float_compare(double l0, double l1, uint8_t l2);
static vader_box_t vader_comptime_float_val(double l0);
static void* vader_comptime_harvest_instances(void* l0);
static bool vader_comptime_has_comptime_decorator(void* l0);
static vader_string_t vader_comptime_instance_args_key(void* l0);
static bool vader_comptime_int_compare(int64_t l0, int64_t l1, uint8_t l2);
static void* vader_comptime_int_div_check(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static void* vader_comptime_int_mod_check(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static vader_box_t vader_comptime_int_val(int64_t l0);
static vader_string_t vader_comptime_interp_value(vader_box_t l0);
static void* vader_comptime_intrinsic_align_of(void* l0, void* l1);
static void* vader_comptime_intrinsic_field_count(void* l0, void* l1);
static void* vader_comptime_intrinsic_field_index(void* l0, void* l1);
static void* vader_comptime_intrinsic_size_of(void* l0, void* l1);
static void* vader_comptime_intrinsic_type_kind(void* l0, void* l1);
static void* vader_comptime_intrinsic_type_name(void* l0, void* l1);
static void* vader_comptime_intrinsic_variant_count(void* l0, void* l1);
static bool vader_comptime_is_concrete_enough(vader_box_t l0);
static bool vader_comptime_is_primitive_int_name(vader_string_t l0);
static bool vader_comptime_is_resolved(vader_box_t l0);
static bool vader_comptime_is_type_symbol_kind(int32_t l0);
static vader_box_t vader_comptime_lookup_module_decls(void* l0, vader_string_t l1);
static vader_box_t vader_comptime_mask_shift_amount(vader_box_t l0, vader_string_t l1);
static void* vader_comptime_new_evaluated_program(void* l0);
static void* vader_comptime_new_evaluated_project(void* l0);
static void* vader_comptime_normalize_int_result(void* l0, vader_string_t l1);
static void vader_comptime_observe(void* l0, vader_box_t l1);
static void* vader_comptime_ok(vader_box_t l0);
static void vader_comptime_populate_deps(void* l0, void* l1);
static vader_box_t vader_comptime_read_relative_file(vader_string_t l0, vader_string_t l1);
static vader_string_t vader_comptime_render_array(void* l0);
static vader_string_t vader_comptime_render_struct(void* l0);
static vader_box_t vader_comptime_resolve_type_arg(vader_box_t l0, void* l1);
static vader_string_t vader_comptime_resolved_int_name(void* l0, size_t l1);
static vader_string_t vader_comptime_sanitise_ident(vader_string_t l0);
static int64_t vader_comptime_shift_amount_mask(vader_string_t l0);
static int64_t vader_comptime_sign_extend_32(int64_t l0);
static void* vader_comptime_sort_comptime_decls(void* l0, void* l1);
static void* vader_comptime_sorted_instances(void* l0);
static vader_box_t vader_comptime_static_string_arg(vader_box_t l0);
static bool vader_comptime_symbol_defines_span(void* l0, void* l1);
static vader_box_t vader_comptime_symbol_for_fn(void* l0, void* l1);
static vader_box_t vader_comptime_symbol_for_kind(vader_string_t l0, int32_t l1, void* l2);
static void* vader_comptime_topo_sort(void* l0);
static int64_t vader_comptime_type_field_count(vader_box_t l0, void* l1);
static vader_box_t vader_comptime_type_from_expr_safe(void* l0, void* l1);
static vader_string_t vader_comptime_type_kind_label(vader_box_t l0);
static void* vader_comptime_type_mismatch(void* l0, vader_string_t l1);
static vader_box_t vader_comptime_type_val(vader_box_t l0);
static int64_t vader_comptime_type_variant_count(vader_box_t l0);
static void* vader_comptime_unary_bit_not(void* l0, vader_box_t l1);
static void* vader_comptime_unary_neg(void* l0, vader_box_t l1);
static void* vader_comptime_unary_not(void* l0, vader_box_t l1);
static void* vader_comptime_unary_type_mismatch(void* l0, vader_string_t l1);
static void vader_comptime_visit(size_t l0, void* l1, void* l2, void* l3, void* l4, size_t l5, void* l6, void* l7);
static void* vader_comptime_vm_required(void* l0, vader_string_t l1);
static void vader_comptime_walk_type(void* l0, vader_box_t l1);
static int64_t vader_comptime_wrap_to_width(int64_t l0, vader_string_t l1);

static void* vader_comptime_add(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    vader_string_t l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_types_strip_distinct_each(l2);
    l4 = vader_comptime_build_display_key(l1, l3);
    l5 = std_collections_get__string__Any(((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_by_key, l4);
    if (l5.tag == 680u) {
        t0 = l5.payload.obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_comptime_GenericInstance_t* _a0_obj = (vader_struct_vader_comptime_GenericInstance_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_GenericInstance_t));
    vader_obj_header_init(_a0_obj, 680u);
    _a0_obj->f_symbol = l1;
    _a0_obj->f_args = l3;
    _a0_obj->f_display_key = l4;
    l3 = (void*) _a0_obj;
    std_collections_put__string__Any(((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_by_key, l4, vader_ref_box(l3));
    vader_array_push((vader_array_t*) ((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_order, vader_ref_box(l3));
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_comptime_all_concrete_enough(void* l0) {
    void* l1;
    size_t l2, l3;
    vader_box_t t0;
    bool t1;
    int64_t t2;
    l1 = l0;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t1 = vader_comptime_is_concrete_enough(t0);
                if (!(t1)) {
                    return false;
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_7;
            } else {
            }
        }
    }
    return true;
}

static void* vader_comptime_arg_count_error(void* l0, vader_string_t l1, size_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    vader_string_t l4;
    size_t l5;
    uint64_t l7;
    int64_t t0;
    size_t t1;
    void* t2 = NULL;
    void* t3 = NULL;
    void** gc_raw_roots[5] = { &l0, &l3, &l6, &t2, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
    l4 = l1;
    l5 = vader_host_std_core_byte_len(l4);
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(68) + l5));
    l5 = (size_t) (int64_t) INT64_C(0);
    l5 = std_core_write_string_at(l6, l5, 528u);
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 106u);
    t0 = ((int64_t) (size_t) l2);
    l7 = (uint64_t) (int64_t) t0;
    l5 = std_core_write_unsigned(l6, l5, l7);
    l5 = std_core_write_string_at(l6, l5, 95u);
    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    t0 = ((int64_t) (size_t) t1);
    l7 = (uint64_t) (int64_t) t0;
    l5 = std_core_write_unsigned(l6, l5, l7);
    l4 = std_core_finish_buffer(l6, l5);
    t2 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(10), l3, l4);
    t3 = vader_comptime_fail(t2);
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_arg_error(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
    t0 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(10), l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_arithmetic(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7;
    vader_string_t l8, l12;
    uint8_t l9;
    double l10, l11;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l2, &t0 };
    void** gc_raw_roots[5] = { &l0, &l3, &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 682u) {
        l4 = l1.payload.obj;
        if (l2.tag == 682u) {
            l5 = l2.payload.obj;
            l6 = ((vader_struct_vader_comptime_IntValue_t*) l4)->f_value;
            l7 = ((vader_struct_vader_comptime_IntValue_t*) l5)->f_value;
            vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
            t0 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(166u, l6), vader_box_i64(166u, l7));
            l6 = ((int64_t) t0.payload.i);
            l8 = ((vader_struct_vader_comptime_IntValue_t*) l4)->f_type_name;
            t0 = vader_comptime_int_val_typed(l6, l8);
            t1 = vader_comptime_ok(t0);
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l12 = 1868u;
        t1 = vader_comptime_type_mismatch(l0, l12);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 679u) {
        l4 = l1.payload.obj;
        if (l2.tag == 679u) {
            l5 = l2.payload.obj;
            l9 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op;
            l10 = ((vader_struct_vader_comptime_FloatValue_t*) l4)->f_value;
            l11 = ((vader_struct_vader_comptime_FloatValue_t*) l5)->f_value;
            l10 = vader_comptime_float_arith(l9, l10, l11);
            l8 = ((vader_struct_vader_comptime_FloatValue_t*) l4)->f_type_name;
            t0 = vader_comptime_float_val_typed(l10, l8);
            t1 = vader_comptime_ok(t0);
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l12 = 1868u;
        t1 = vader_comptime_type_mismatch(l0, l12);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l12 = 1868u;
    t1 = vader_comptime_type_mismatch(l0, l12);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_arithmetic_int(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7;
    vader_string_t l8;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l2, &t0 };
    void** gc_raw_roots[5] = { &l0, &l3, &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 682u) {
        l4 = l1.payload.obj;
        if (l2.tag == 682u) {
            l5 = l2.payload.obj;
            l6 = ((vader_struct_vader_comptime_IntValue_t*) l4)->f_value;
            l7 = ((vader_struct_vader_comptime_IntValue_t*) l5)->f_value;
            vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
            t0 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(166u, l6), vader_box_i64(166u, l7));
            l6 = ((int64_t) t0.payload.i);
            l8 = ((vader_struct_vader_comptime_IntValue_t*) l4)->f_type_name;
            t0 = vader_comptime_int_val_typed(l6, l8);
            t1 = vader_comptime_ok(t0);
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = 1869u;
        t1 = vader_comptime_type_mismatch(l0, l8);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = 1869u;
    t1 = vader_comptime_type_mismatch(l0, l8);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_arithmetic_or_concat(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    vader_string_t l6, l7;
    vader_box_t l8 = vader_box_null();
    vader_string_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l8, &t1 };
    void** gc_raw_roots[5] = { &l0, &l3, &l4, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 687u) {
        l4 = l1.payload.obj;
        if (l2.tag == 687u) {
            l5 = l2.payload.obj;
            l6 = ((vader_struct_vader_comptime_StringValue_t*) l4)->f_value;
            l7 = ((vader_struct_vader_comptime_StringValue_t*) l5)->f_value;
            t0 = concat_2(l6, l7);
            t1 = vader_comptime_string_val(t0);
            t2 = vader_comptime_ok(t1);
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = vader_comptime_type_mismatch(l0, 2090u);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l1;
    t2 = vader_comptime_arithmetic(l0, l8, l2, l3);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_assert_message(void* l0) {
    vader_box_t l1;
    vader_string_t t0;
    l1 = ((vader_struct_toolchain_ast_AssertDecl_t*) l0)->f_message;
    if (l1.tag == 0u) {
        return 0u;
    }
    if (l1.tag == 162u) {
        t0 = ((vader_struct_toolchain_ast_AssertDecl_t*) l0)->f_message.payload.s;
        return t0;
    }
    vader_unreachable("unreachable return in vader_comptime$assert_message");
}

static void vader_comptime_bake_file_exprs(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    size_t l7, l8, l12;
    vader_box_t l9 = vader_box_null(), l13 = vader_box_null(), l15 = vader_box_null(), l19 = vader_box_null();
    vader_string_t l14;
    int32_t l18;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_string_t t3;
    vader_box_t* gc_roots[5] = { &l9, &l13, &l15, &l19, &t0 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l10, &l11, &l16, &l17, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 12u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 13u, 432u);
    l5 = (void*) _a0_arr;
    l6 = l0;
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l8 < l7)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                vader_comptime_collect_file_intrinsics(t0, l5);
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                goto loop_9;
            } else {
            }
        }
    }
    l6 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l3)->f_comptime_decls;
    vader_struct_vader_comptime_ComptimeContext_t* _a2_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a2_obj, 674u);
    _a2_obj->f_typed = l1;
    _a2_obj->f_bindings = l6;
    _a2_obj->f_depth = INT64_C(0);
    l6 = (void*) _a2_obj;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_41: {
            if ((l8 < l7)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l8 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
                vader_comptime_bake_one_file_expr(t2, l6, l1, l2, l4);
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                goto loop_41;
            } else {
            }
        }
    }
    l5 = l0;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_70: {
            if ((l8 < l7)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l8 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l8);
                if (l9.tag == 400u) {
                    l6 = l9.payload.obj;
                    if (((vader_struct_toolchain_ast_ConstDecl_t*) l6)->f_value.tag == 432u) {
                        l10 = ((vader_struct_toolchain_ast_ConstDecl_t*) l6)->f_value.payload.obj;
                        t3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l10)->f_name;
                        if (t3 == 1547u) {
                            l11 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l2)->f_file_exprs;
                            l12 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l10)->f_id;
                            l13 = std_collections_get__usize__string(l11, l12);
                            if (l13.tag == 162u) {
                                l14 = l13.payload.s;
                                l15 = vader_typecheck_lookup_const_symbol(l6, l1);
                                if (l15.tag == 881u) {
                                    l16 = l15.payload.obj;
                                    l17 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l2)->f_file_baked_consts;
                                    l18 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l16)->f_id;
                                    l19 = vader_comptime_string_val(l14);
                                    std_collections_put__i32__Any(l17, l18, l19);
                                } else {
                                }
                            } else {
                            }
                        } else {
                        }
                    } else {
                    }
                } else {
                }
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                goto loop_70;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_bake_one_file_expr(void* l0, void* l1, void* l2, void* l3, void* l4) {
    vader_box_t l5 = vader_box_null();
    vader_string_t l6, l7;
    void* l8 = NULL;
    size_t l9;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    t1 = vader_comptime_evaluate_expr(t0, l1);
    l5 = ((vader_struct_vader_comptime_EvalResult_t*) t1)->f_value;
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l5.tag == 687u) {
        t1 = l5.payload.obj;
        l6 = ((vader_struct_vader_comptime_StringValue_t*) t1)->f_value;
        l7 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_resolved)->f_path;
        l5 = vader_comptime_read_relative_file(l6, l7);
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l5.tag == 162u) {
            l6 = l5.payload.s;
            l8 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_file_exprs;
            l9 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_id;
            std_collections_put__usize__string(l8, l9, l6);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static int64_t vader_comptime_bit_not_i64(int64_t l0) {
    int64_t l1;
    l1 = -(INT64_C(1));
    return (l0 ^ l1);
}

static void* vader_comptime_bool_op(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    bool l6, l7;
    vader_string_t l8;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    void* t3 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l2, &t0 };
    void** gc_raw_roots[6] = { &l0, &l3, &l4, &l5, &t2, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 672u) {
        l4 = l1.payload.obj;
        if (l2.tag == 672u) {
            l5 = l2.payload.obj;
            l6 = ((vader_struct_vader_comptime_BoolValue_t*) l4)->f_value;
            l7 = ((vader_struct_vader_comptime_BoolValue_t*) l5)->f_value;
            vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
            t0 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_bool(160u, l6), vader_box_bool(160u, l7));
            t1 = t0.payload.b;
            if (t1) {
                vader_struct_vader_comptime_BoolValue_t* _a1_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
                vader_obj_header_init(_a1_obj, 672u);
                _a1_obj->f_value = true;
                t2 = (void*) _a1_obj;
                t3 = vader_comptime_ok(vader_ref_box(t2));
                { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_struct_vader_comptime_BoolValue_t* _a2_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
            vader_obj_header_init(_a2_obj, 672u);
            _a2_obj->f_value = false;
            t2 = (void*) _a2_obj;
            t3 = vader_comptime_ok(vader_ref_box(t2));
            { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = 1782u;
        t2 = vader_comptime_type_mismatch(l0, l8);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = 1782u;
    t2 = vader_comptime_type_mismatch(l0, l8);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_bool_value(bool l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0) {
        vader_struct_vader_comptime_BoolValue_t* _a0_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
        vader_obj_header_init(_a0_obj, 672u);
        _a0_obj->f_value = true;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_comptime_BoolValue_t* _a1_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
    vader_obj_header_init(_a1_obj, 672u);
    _a1_obj->f_value = false;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_build_display_key(void* l0, void* l1) {
    vader_string_t l2;
    size_t l3;
    void* l4 = NULL;
    int64_t l5;
    int32_t t0;
    vader_string_t t1;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_comptime_instance_args_key(l1);
    l3 = vader_host_std_core_byte_len(l2);
    l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l3));
    l3 = (size_t) (int64_t) INT64_C(0);
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l5 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l4, l3, l5);
    l3 = std_core_write_string_at(l4, l3, 299u);
    l3 = std_core_write_string_at(l4, l3, l2);
    l3 = std_core_write_string_at(l4, l3, 337u);
    t1 = std_core_finish_buffer(l4, l3);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_build_vm_required(void* l0, void* l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    int32_t l6;
    vader_box_t l7 = vader_box_null();
    vader_string_t l8;
    size_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_value.tag == 397u) {
        l4 = ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_value.payload.obj;
        if (((vader_struct_toolchain_ast_CallExpr_t*) l4)->f_callee.tag == 421u) {
            l5 = ((vader_struct_toolchain_ast_CallExpr_t*) l4)->f_callee.payload.obj;
            t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l4)->f_args)->length;
            if (t0 == INT64_C(0)) {
                l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_decl_types;
                l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
                l7 = std_collections_get__i32__Any(l4, l6);
                if (!(l7.tag == 0u)) {
                    l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
                    l8 = ((vader_struct_toolchain_ast_IdentExpr_t*) l5)->f_name;
                    l4 = ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_span;
                    vader_struct_vader_comptime_VmRequiredDecl_t* _a0_obj = (vader_struct_vader_comptime_VmRequiredDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_VmRequiredDecl_t));
                    vader_obj_header_init(_a0_obj, 690u);
                    _a0_obj->f_symbol_id = l6;
                    _a0_obj->f_module_id = l3;
                    _a0_obj->f_callee_name = l8;
                    _a0_obj->f_decl_type = l7;
                    _a0_obj->f_span = l4;
                    t1 = (void*) _a0_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = vader_box_obj(0u, NULL);
                { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t2 = vader_box_obj(0u, NULL);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t2 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

int64_t vader_comptime_byte_align(vader_box_t l0) {
    int64_t l1;
    void* t0;
    vader_string_t t1;
    if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_types_primitive_align(t1);
    } else {
        if (l0.tag == 908u) {
            t0 = l0.payload.obj;
            l1 = vader_comptime_byte_align(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        } else {
            if ((l0.tag == 906u || l0.tag == 907u || l0.tag == 909u || l0.tag == 910u || l0.tag == 918u || l0.tag == 919u || l0.tag == 920u || l0.tag == 923u)) {
                l1 = INT64_C(8);
            } else {
                l1 = INT64_C(0);
            }
        }
    }
    return l1;
}

int64_t vader_comptime_byte_size(vader_box_t l0) {
    int64_t l1;
    void* t0;
    vader_string_t t1;
    if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = vader_types_primitive_size(t1);
    } else {
        if (l0.tag == 908u) {
            t0 = l0.payload.obj;
            l1 = vader_comptime_byte_size(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        } else {
            if ((l0.tag == 906u || l0.tag == 907u || l0.tag == 909u || l0.tag == 910u || l0.tag == 918u || l0.tag == 919u || l0.tag == 920u || l0.tag == 923u)) {
                l1 = INT64_C(16);
            } else {
                l1 = INT64_C(0);
            }
        }
    }
    return l1;
}

static vader_string_t vader_comptime_canonical_type_key(vader_box_t l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    vader_string_t l2, l6;
    size_t l3;
    int64_t l5;
    vader_string_t t0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l4, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 916u) {
        l1 = l0.payload.obj;
        l2 = ((vader_struct_vader_types_PrimitiveType_t*) l1)->f_name;
        t0 = concat_2(686u, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 918u) {
        l1 = l0.payload.obj;
        l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_StructType_t*) l1)->f_args);
        l3 = vader_host_std_core_byte_len(l2);
        l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(24) + l3));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l4, l3, 732u);
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l1)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        l3 = std_core_write_string_at(l4, l3, 299u);
        l3 = std_core_write_string_at(l4, l3, l2);
        l3 = std_core_write_string_at(l4, l3, 337u);
        t0 = std_core_finish_buffer(l4, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 909u) {
        l1 = l0.payload.obj;
        l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(22));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l4, l3, 588u);
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) l1)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        t0 = std_core_finish_buffer(l4, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 908u) {
        t2 = l0.payload.obj;
        t0 = vader_comptime_canonical_type_key(((vader_struct_vader_types_DistinctType_t*) t2)->f_backing);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 919u) {
        l1 = l0.payload.obj;
        l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_TraitType_t*) l1)->f_args);
        l3 = vader_host_std_core_byte_len(l2);
        l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(24) + l3));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l4, l3, 810u);
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) l1)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        l3 = std_core_write_string_at(l4, l3, 299u);
        l3 = std_core_write_string_at(l4, l3, l2);
        l3 = std_core_write_string_at(l4, l3, 337u);
        t0 = std_core_finish_buffer(l4, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 907u) {
        l1 = l0.payload.obj;
        l2 = vader_comptime_canonical_type_key(((vader_struct_vader_types_ArrayType_t*) l1)->f_element);
        t0 = concat_2(538u, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 920u) {
        l1 = l0.payload.obj;
        l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_TupleType_t*) l1)->f_elements);
        t0 = concat_3(815u, l2, 337u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 910u) {
        l1 = l0.payload.obj;
        l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_FnType_t*) l1)->f_params);
        l6 = vader_comptime_canonical_type_key(((vader_struct_vader_types_FnType_t*) l1)->f_return_type);
        t0 = concat_4(593u, l2, 358u, l6);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 922u) {
        l1 = l0.payload.obj;
        l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(22));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l4, l3, 837u);
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) l1)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        t0 = std_core_finish_buffer(l4, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 923u) {
        l1 = l0.payload.obj;
        l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_UnionType_t*) l1)->f_variants);
        t0 = concat_3(651u, l2, 337u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 921u) {
        { vader_gc_top = gc_frame.prev; return 645u; }
    }
    if (l0.tag == 917u) {
        { vader_gc_top = gc_frame.prev; return 735u; }
    }
    if (l0.tag == 924u) {
        { vader_gc_top = gc_frame.prev; return 819u; }
    }
    if (l0.tag == 913u) {
        { vader_gc_top = gc_frame.prev; return 600u; }
    }
    if (l0.tag == 911u) {
        { vader_gc_top = gc_frame.prev; return 598u; }
    }
    if (l0.tag == 912u) {
        { vader_gc_top = gc_frame.prev; return 599u; }
    }
    if (l0.tag == 914u) {
        { vader_gc_top = gc_frame.prev; return 656u; }
    }
    if (l0.tag == 906u) {
        { vader_gc_top = gc_frame.prev; return 838u; }
    }
    vader_unreachable("unreachable return in vader_comptime$canonical_type_key");
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_collect_block_deps(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    size_t l6, l7;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l7 < l6)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
                vader_comptime_collect_stmt_deps(t0, l1, l2, l3, l4);
                t1 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t1;
                goto loop_7;
            } else {
            }
        }
    }
    if (!(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1, l2, l3, l4);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_collect_expr_deps(vader_box_t l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    uint64_t l7;
    vader_box_t l8 = vader_box_null();
    size_t l9, l11, l12;
    int32_t l10;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l0, &l8, &t0 };
    void** gc_raw_roots[7] = { &l1, &l2, &l3, &l4, &l5, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 421u) {
        l5 = l0.payload.obj;
        l6 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved)->f_idents;
        l7 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l5)->f_span);
        l8 = std_collections_get__u64__Any(l6, l7);
        if (l8.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l5 = l8.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) l5)->f_kind != INT32_C(6)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l6 = ((vader_struct_vader_comptime_Nodes_t*) l2)->f_by_symbol;
        l10 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l5)->f_id;
        l8 = std_collections_get__i32__usize(l6, l10);
        if (l8.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l9 = ((size_t) l8.payload.i);
        t0 = std_collections_get__usize__bool(l3, l9);
        if (t0.tag == 160u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        std_collections_put__usize__bool(l3, l9, true);
        vader_array_push_i64((vader_array_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l4)->f_dependency_ids, (int64_t) (size_t) l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 397u) {
        l5 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_CallExpr_t*) l5)->f_callee, l1, l2, l3, l4);
        l5 = ((vader_struct_toolchain_ast_CallExpr_t*) l5)->f_args;
        l9 = ((vader_array_t*) l5)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_80: {
                if ((l11 < l9)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l11 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l11);
                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_CallArg_t*) t1)->f_value, l1, l2, l3, l4);
                    t2 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t2;
                    goto loop_80;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 414u) {
        t1 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_FieldExpr_t*) t1)->f_target, l1, l2, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 429u) {
        l5 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_IndexExpr_t*) l5)->f_target, l1, l2, l3, l4);
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_IndexExpr_t*) l5)->f_index, l1, l2, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 470u) {
        t1 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_UnaryExpr_t*) t1)->f_operand, l1, l2, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 391u) {
        l5 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_BinaryExpr_t*) l5)->f_left, l1, l2, l3, l4);
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_BinaryExpr_t*) l5)->f_right, l1, l2, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 424u) {
        l5 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_IfExpr_t*) l5)->f_cond, l1, l2, l3, l4);
        vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_IfExpr_t*) l5)->f_then_block, l1, l2, l3, l4);
        l8 = ((vader_struct_toolchain_ast_IfExpr_t*) l5)->f_else_branch;
        if (l8.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l8.tag == 423u) {
            t1 = l8.payload.obj;
            vader_comptime_collect_expr_deps(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t1)->f_branch), l1, l2, l3, l4);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l8.tag == 422u) {
            t1 = l8.payload.obj;
            vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_IfElseBlock_t*) t1)->f_block, l1, l2, l3, l4);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 438u) {
        l5 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_MatchExpr_t*) l5)->f_scrutinee, l1, l2, l3, l4);
        l5 = ((vader_struct_toolchain_ast_MatchExpr_t*) l5)->f_arms;
        l9 = ((vader_array_t*) l5)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_242: {
                if ((l11 < l9)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l11 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
                    if (!(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_guard.tag == 0u)) {
                        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_guard, l1, l2, l3, l4);
                    } else {
                    }
                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_body, l1, l2, l3, l4);
                    t2 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t2;
                    goto loop_242;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 393u) {
        t1 = l0.payload.obj;
        vader_comptime_collect_block_deps(t1, l1, l2, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 460u) {
        l5 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StructLitExpr_t*) l5)->f_type_name, l1, l2, l3, l4);
        l5 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l5)->f_items;
        l9 = ((vader_array_t*) l5)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_311: {
                if ((l11 < l9)) {
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l11 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
                    if (l8.tag == 461u) {
                        t1 = l8.payload.obj;
                        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StructLitField_t*) t1)->f_value, l1, l2, l3, l4);
                        l12 = (size_t) (int64_t) INT64_C(1);
                        t2 = (l11 + l12);
                        l11 = (size_t) (int64_t) t2;
                        goto loop_311;
                    }
                    if (l8.tag == 462u) {
                        t1 = l8.payload.obj;
                        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StructLitSpread_t*) t1)->f_expr, l1, l2, l3, l4);
                        l12 = (size_t) (int64_t) INT64_C(1);
                        t2 = (l11 + l12);
                        l11 = (size_t) (int64_t) t2;
                        goto loop_311;
                    }
                    { vader_gc_top = gc_frame.prev; return; }
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 453u) {
        t1 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t1)->f_elements;
        l9 = ((vader_array_t*) l5)->length;
        l11 = (size_t) (int64_t) INT64_C(0);
        {
            loop_376: {
                if ((l11 < l9)) {
                    vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                    if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                    if ((size_t) l11 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
                    vader_comptime_collect_expr_deps(t0, l1, l2, l3, l4);
                    t2 = (l11 + INT64_C(1));
                    l11 = (size_t) (int64_t) t2;
                    goto loop_376;
                } else {
                }
            }
        }
    } else {
        if (l0.tag == 449u) {
            l5 = l0.payload.obj;
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_RangeExpr_t*) l5)->f_lower, l1, l2, l3, l4);
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_RangeExpr_t*) l5)->f_upper, l1, l2, l3, l4);
        } else {
            if (l0.tag == 390u) {
                t1 = l0.payload.obj;
                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_AwaitExpr_t*) t1)->f_inner, l1, l2, l3, l4);
            } else {
                if (l0.tag == 398u) {
                    t1 = l0.payload.obj;
                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_CastExpr_t*) t1)->f_value, l1, l2, l3, l4);
                } else {
                    if (l0.tag == 434u) {
                        t1 = l0.payload.obj;
                        vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_LambdaExpr_t*) t1)->f_body, l1, l2, l3, l4);
                    } else {
                        if (l0.tag == 432u) {
                            t1 = l0.payload.obj;
                            l5 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t1)->f_args;
                            l9 = ((vader_array_t*) l5)->length;
                            l11 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_466: {
                                    if ((l11 < l9)) {
                                        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                                        if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                        if ((size_t) l11 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                        t0 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l11);
                                        vader_comptime_collect_expr_deps(t0, l1, l2, l3, l4);
                                        t2 = (l11 + INT64_C(1));
                                        l11 = (size_t) (int64_t) t2;
                                        goto loop_466;
                                    } else {
                                    }
                                }
                            }
                        } else {
                            if (l0.tag == 420u) {
                                t1 = l0.payload.obj;
                                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_GenericInstExpr_t*) t1)->f_callee, l1, l2, l3, l4);
                            } else {
                                if (l0.tag == 455u) {
                                    t1 = l0.payload.obj;
                                    l5 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t1)->f_parts;
                                    l9 = ((vader_array_t*) l5)->length;
                                    l11 = (size_t) (int64_t) INT64_C(0);
                                    {
                                        loop_513: {
                                            if ((l11 < l9)) {
                                                vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
                                                if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                                if ((size_t) l11 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                                l8 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
                                                if (l8.tag == 456u) {
                                                    t1 = l8.payload.obj;
                                                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StringLitInterp_t*) t1)->f_expr, l1, l2, l3, l4);
                                                } else {
                                                }
                                                t2 = (l11 + INT64_C(1));
                                                l11 = (size_t) (int64_t) t2;
                                                goto loop_513;
                                            } else {
                                            }
                                        }
                                    }
                                } else {
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_collect_file_intrinsics(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    size_t l4, l5, l6;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 416u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body;
        if (l2.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l2.tag == 393u) {
            t0 = l2.payload.obj;
            vader_comptime_collect_in_block(t0, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 425u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_members;
        l4 = ((vader_array_t*) l3)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_34: {
                if ((l5 < l4)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                    l2 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body;
                    if (l2.tag == 0u) {
                        l6 = (size_t) (int64_t) INT64_C(1);
                        t1 = (l5 + l6);
                        l5 = (size_t) (int64_t) t1;
                        goto loop_34;
                    }
                    if (l2.tag == 393u) {
                        t0 = l2.payload.obj;
                        vader_comptime_collect_in_block(t0, l1);
                        l6 = (size_t) (int64_t) INT64_C(1);
                        t1 = (l5 + l6);
                        l5 = (size_t) (int64_t) t1;
                        goto loop_34;
                    }
                    { vader_gc_top = gc_frame.prev; return; }
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 400u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_value, l1);
    } else {
        if (l0.tag == 388u) {
            t0 = l0.payload.obj;
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_condition, l1);
        } else {
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_collect_in_block(void* l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
                vader_comptime_collect_in_stmt(t0, l1);
                t1 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t1;
                goto loop_7;
            } else {
            }
        }
    }
    if (!(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1);
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_collect_in_expr(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    bool l3;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_string_t t0;
    size_t t1;
    void* t2 = NULL;
    int64_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l6, &t4 };
    void** gc_raw_roots[3] = { &l1, &l2, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 432u) {
        l2 = l0.payload.obj;
        t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_name;
        if (t0 == 1547u) {
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l2)->f_args)->length;
            l3 = t1 == INT64_C(1);
        } else {
            l3 = false;
        }
        if (l3) {
            vader_array_push((vader_array_t*) l1, vader_ref_box(l2));
        } else {
        }
    } else {
    }
    if (l0.tag == 393u) {
        t2 = l0.payload.obj;
        vader_comptime_collect_in_block(t2, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 397u) {
        l2 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_callee, l1);
        l2 = ((vader_struct_toolchain_ast_CallExpr_t*) l2)->f_args;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_54: {
                if ((l5 < l4)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    t2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                    vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_CallArg_t*) t2)->f_value, l1);
                    t3 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t3;
                    goto loop_54;
                } else {
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 414u) {
        t2 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_FieldExpr_t*) t2)->f_target, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 429u) {
        l2 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_target, l1);
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_IndexExpr_t*) l2)->f_index, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 470u) {
        t2 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_UnaryExpr_t*) t2)->f_operand, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 391u) {
        l2 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_left, l1);
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) l2)->f_right, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 424u) {
        l2 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_cond, l1);
        vader_comptime_collect_in_block(((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_then_block, l1);
        l6 = ((vader_struct_toolchain_ast_IfExpr_t*) l2)->f_else_branch;
        if (l6.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l6.tag == 422u) {
            t2 = l6.payload.obj;
            vader_comptime_collect_in_block(((vader_struct_toolchain_ast_IfElseBlock_t*) t2)->f_block, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l6.tag == 423u) {
            t2 = l6.payload.obj;
            vader_comptime_collect_in_expr(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t2)->f_branch), l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 432u) {
        t2 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t2)->f_args;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) (int64_t) INT64_C(0);
        {
            loop_176: {
                if ((l5 < l4)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                    vader_comptime_collect_in_expr(t4, l1);
                    t3 = (l5 + INT64_C(1));
                    l5 = (size_t) (int64_t) t3;
                    goto loop_176;
                } else {
                }
            }
        }
    } else {
        if (l0.tag == 455u) {
            t2 = l0.payload.obj;
            l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t2)->f_parts;
            l4 = ((vader_array_t*) l2)->length;
            l5 = (size_t) (int64_t) INT64_C(0);
            {
                loop_208: {
                    if ((l5 < l4)) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                        if (l6.tag == 456u) {
                            t2 = l6.payload.obj;
                            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_StringLitInterp_t*) t2)->f_expr, l1);
                        } else {
                        }
                        t3 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t3;
                        goto loop_208;
                    } else {
                    }
                }
            }
        } else {
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_collect_in_stmt(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 435u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 389u) {
        l2 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_target, l1);
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_AssignStmt_t*) l2)->f_value, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 413u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 452u) {
        l2 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_value.tag == 0u)) {
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) l2)->f_value, l1);
        } else {
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 419u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_form;
        if (l3.tag == 471u) {
            t0 = l3.payload.obj;
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
        } else {
            if (l3.tag == 428u) {
                t0 = l3.payload.obj;
                vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1);
            } else {
            }
        }
        vader_comptime_collect_in_block(((vader_struct_toolchain_ast_ForStmt_t*) l2)->f_body, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 404u) {
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_DeferStmt_t*) t0)->f_body;
        if (l3.tag == 405u) {
            t0 = l3.payload.obj;
            vader_comptime_collect_in_stmt(((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (l3.tag == 403u) {
            t0 = l3.payload.obj;
            vader_comptime_collect_in_block(((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block, l1);
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_collect_nodes(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    size_t l6, l7, l9, l12, l13;
    vader_box_t l8 = vader_box_null();
    bool t0;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(14u, 0u, 4u, 171u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 172u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 165u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__usize__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__usize__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__Any_t));
    vader_obj_header_init(_a3_obj, 368u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(14u, 0u, 4u, 171u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 165u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 4u, 171u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 165u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i32__usize_t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__usize_t));
    vader_obj_header_init(_a8_obj, 314u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a8_obj;
    vader_struct_vader_comptime_Nodes_t* _a9_obj = (vader_struct_vader_comptime_Nodes_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_Nodes_t));
    vader_obj_header_init(_a9_obj, 685u);
    _a9_obj->f_by_id = l1;
    _a9_obj->f_order = l2;
    _a9_obj->f_by_symbol = l3;
    l1 = (void*) _a9_obj;
    l2 = l0;
    l6 = ((vader_array_t*) l2)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_42: {
            if ((l7 < l6)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
                if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                if ((size_t) l7 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l7);
                if (l8.tag == 400u) {
                    l3 = l8.payload.obj;
                    t0 = vader_comptime_has_comptime_decorator(l3);
                    if (!(t0)) {
                        t1 = (l7 + INT64_C(1));
                        l7 = (size_t) (int64_t) t1;
                        goto loop_42;
                    }
                    vader_array_t* _a11_arr = vader_array_new(14u, 0u, 4u, 171u);
                    l4 = (void*) _a11_arr;
                    l5 = ((vader_struct_vader_comptime_Nodes_t*) l1)->f_by_id;
                    l9 = ((vader_struct_toolchain_ast_ConstDecl_t*) l3)->f_id;
                    vader_struct_vader_comptime_NodeRecord_t* _a12_obj = (vader_struct_vader_comptime_NodeRecord_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_NodeRecord_t));
                    vader_obj_header_init(_a12_obj, 684u);
                    _a12_obj->f_decl = l3;
                    _a12_obj->f_dependency_ids = l4;
                    l10 = (void*) _a12_obj;
                    std_collections_put__usize__Any(l5, l9, vader_ref_box(l10));
                    l11 = ((vader_struct_vader_comptime_Nodes_t*) l1)->f_order;
                    l12 = ((vader_struct_toolchain_ast_ConstDecl_t*) l3)->f_id;
                    vader_array_push_i64((vader_array_t*) l11, (int64_t) (size_t) l12);
                    l13 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l7 + l13);
                    l7 = (size_t) (int64_t) t1;
                    goto loop_42;
                }
                l13 = (size_t) (int64_t) INT64_C(1);
                t1 = (l7 + l13);
                l7 = (size_t) (int64_t) t1;
                goto loop_42;
            } else {
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_collect_stmt_deps(vader_box_t l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l6 };
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 435u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value, l1, l2, l3, l4);
    } else {
        if (l0.tag == 413u) {
            t0 = l0.payload.obj;
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1, l2, l3, l4);
        } else {
            if (l0.tag == 452u) {
                l5 = l0.payload.obj;
                if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) l5)->f_value.tag == 0u)) {
                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_ReturnStmt_t*) l5)->f_value, l1, l2, l3, l4);
                } else {
                }
            } else {
                if (l0.tag == 389u) {
                    l5 = l0.payload.obj;
                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_AssignStmt_t*) l5)->f_target, l1, l2, l3, l4);
                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_AssignStmt_t*) l5)->f_value, l1, l2, l3, l4);
                } else {
                    if (l0.tag == 419u) {
                        l5 = l0.payload.obj;
                        l6 = ((vader_struct_toolchain_ast_ForStmt_t*) l5)->f_form;
                        if (l6.tag == 471u) {
                            t0 = l6.payload.obj;
                            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1, l2, l3, l4);
                        } else {
                            if (l6.tag == 428u) {
                                t0 = l6.payload.obj;
                                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1, l2, l3, l4);
                            } else {
                            }
                        }
                        vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_ForStmt_t*) l5)->f_body, l1, l2, l3, l4);
                    } else {
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_combine_binary(void* l0, vader_box_t l1, vader_box_t l2) {
    uint8_t l3;
    void* l4 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op;
    if (l3 == INT32_C(0)) {
        l4 = (void*) &vader_fn_static_1054;
        t0 = vader_comptime_arithmetic_or_concat(l0, l1, l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(1)) {
        l4 = (void*) &vader_fn_static_1052;
        t0 = vader_comptime_arithmetic(l0, l1, l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(2)) {
        l4 = (void*) &vader_fn_static_1051;
        t0 = vader_comptime_arithmetic(l0, l1, l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(3)) {
        l4 = (void*) &vader_fn_static_1049;
        t0 = vader_comptime_int_div_check(l0, l1, l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(4)) {
        l4 = (void*) &vader_fn_static_1047;
        t0 = vader_comptime_int_mod_check(l0, l1, l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(5)) {
        l4 = (void*) &vader_fn_static_1045;
        t0 = vader_comptime_arithmetic_int(l0, l1, l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(6)) {
        l4 = (void*) &vader_fn_static_1044;
        t0 = vader_comptime_arithmetic_int(l0, l1, l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(7)) {
        l4 = (void*) &vader_fn_static_1043;
        t0 = vader_comptime_arithmetic_int(l0, l1, l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(8)) {
        l4 = (void*) &vader_fn_static_1042;
        t0 = vader_comptime_arithmetic_int(l0, l1, l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(9)) {
        l4 = (void*) &vader_fn_static_1041;
        t0 = vader_comptime_arithmetic_int(l0, l1, l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(10)) {
        l4 = (void*) &vader_fn_static_1039;
        t0 = vader_comptime_bool_op(l0, l1, l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(11)) {
        l4 = (void*) &vader_fn_static_1038;
        t0 = vader_comptime_bool_op(l0, l1, l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(12)) {
        t0 = vader_comptime_compare(l0, l1, l2, (uint8_t) (int32_t) INT32_C(0));
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(13)) {
        t0 = vader_comptime_compare(l0, l1, l2, (uint8_t) (int32_t) INT32_C(1));
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(14)) {
        t0 = vader_comptime_compare(l0, l1, l2, (uint8_t) (int32_t) INT32_C(2));
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(15)) {
        t0 = vader_comptime_compare(l0, l1, l2, (uint8_t) (int32_t) INT32_C(3));
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(16)) {
        t0 = vader_comptime_compare(l0, l1, l2, (uint8_t) (int32_t) INT32_C(4));
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(17)) {
        t0 = vader_comptime_compare(l0, l1, l2, (uint8_t) (int32_t) INT32_C(5));
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(18)) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 549u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(19)) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 548u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3 == INT32_C(20)) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 550u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_comptime$combine_binary");
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_compare(void* l0, vader_box_t l1, vader_box_t l2, uint8_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    int64_t l6, l7;
    double l8, l9;
    bool l10, l11;
    vader_string_t l12, l13, l14;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l2, &t1 };
    void** gc_raw_roots[4] = { &l0, &l4, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 682u) {
        l4 = l1.payload.obj;
        if (l2.tag == 682u) {
            l5 = l2.payload.obj;
            l6 = ((vader_struct_vader_comptime_IntValue_t*) l4)->f_value;
            l7 = ((vader_struct_vader_comptime_IntValue_t*) l5)->f_value;
            t0 = vader_comptime_int_compare(l6, l7, l3);
            t1 = vader_comptime_bool_value(t0);
            t2 = vader_comptime_ok(t1);
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l14 = 1337u;
        t2 = vader_comptime_type_mismatch(l0, l14);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 679u) {
        l4 = l1.payload.obj;
        if (l2.tag == 679u) {
            l5 = l2.payload.obj;
            l8 = ((vader_struct_vader_comptime_FloatValue_t*) l4)->f_value;
            l9 = ((vader_struct_vader_comptime_FloatValue_t*) l5)->f_value;
            t0 = vader_comptime_float_compare(l8, l9, l3);
            t1 = vader_comptime_bool_value(t0);
            t2 = vader_comptime_ok(t1);
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l14 = 1337u;
        t2 = vader_comptime_type_mismatch(l0, l14);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 672u) {
        l4 = l1.payload.obj;
        if (l2.tag == 672u) {
            l5 = l2.payload.obj;
            l10 = ((vader_struct_vader_comptime_BoolValue_t*) l4)->f_value;
            l11 = ((vader_struct_vader_comptime_BoolValue_t*) l5)->f_value;
            l10 = l10 == l11;
            t2 = vader_comptime_equality_only(l0, l10, l3, 1231u);
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l14 = 1337u;
        t2 = vader_comptime_type_mismatch(l0, l14);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 687u) {
        l4 = l1.payload.obj;
        if (l2.tag == 687u) {
            l5 = l2.payload.obj;
            l12 = ((vader_struct_vader_comptime_StringValue_t*) l4)->f_value;
            l13 = ((vader_struct_vader_comptime_StringValue_t*) l5)->f_value;
            l10 = l12 == l13;
            t2 = vader_comptime_equality_only(l0, l10, l3, 2089u);
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l14 = 1337u;
        t2 = vader_comptime_type_mismatch(l0, l14);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l14 = 1337u;
    t2 = vader_comptime_type_mismatch(l0, l14);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_cycle_names(size_t l0, size_t l1, void* l2, size_t l3, void* l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    size_t l6, l9;
    vader_box_t l10 = vader_box_null();
    vader_string_t l11, l12;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l10, &t2 };
    void** gc_raw_roots[6] = { &l2, &l4, &l5, &l7, &l8, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 162u);
    l5 = (void*) _a0_arr;
    l6 = l0;
    {
        loop_5: {
            if ((l6 < l1)) {
                l8 = ((vader_struct_vader_comptime_Nodes_t*) l4)->f_by_id;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
                l9 = (size_t) (int64_t) t0;
                l10 = std_collections_get__usize__Any(l8, l9);
                if (l10.tag == 0u) {
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_5;
                }
                l7 = l10.payload.obj;
                l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l7)->f_decl)->f_name;
                vader_array_push((vader_array_t*) l5, vader_box_string(162u, l11));
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_5;
            } else {
            }
        }
    }
    l10 = std_collections_get__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l4)->f_by_id, l3);
    if (!(l10.tag == 0u)) {
        t1 = l10.payload.obj;
        l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) t1)->f_decl)->f_name;
        vader_array_push((vader_array_t*) l5, vader_box_string(162u, l11));
    } else {
    }
    l11 = 0u;
    l6 = ((vader_array_t*) l5)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_73: {
            if ((l9 < l6)) {
                if ((l9 > INT64_C(0))) {
                    l11 = concat_2(l11, 241u);
                } else {
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l9];
                l12 = t2.payload.s;
                l11 = concat_2(l11, l12);
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                goto loop_73;
            } else {
            }
        }
    }
    { vader_string_t __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_diag_sink(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(50u, 0u, 13u, 693u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_display_value(vader_box_t l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    vader_string_t l2, l6;
    size_t l3;
    int64_t l5;
    bool l7;
    vader_string_t t0;
    double t1;
    uint32_t t2;
    void* t3 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l4, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 682u) {
        l1 = l0.payload.obj;
        l2 = ((vader_struct_vader_comptime_IntValue_t*) l1)->f_type_name;
        l3 = vader_host_std_core_byte_len(l2);
        l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l3));
        l3 = (size_t) (int64_t) INT64_C(0);
        l5 = ((vader_struct_vader_comptime_IntValue_t*) l1)->f_value;
        l3 = std_core_write_int(l4, l3, l5);
        l3 = std_core_write_string_at(l4, l3, 858u);
        l3 = std_core_write_string_at(l4, l3, l2);
        t0 = std_core_finish_buffer(l4, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 679u) {
        l1 = l0.payload.obj;
        t1 = ((vader_struct_vader_comptime_FloatValue_t*) l1)->f_value;
        l2 = std_core_format_f64(t1);
        l6 = ((vader_struct_vader_comptime_FloatValue_t*) l1)->f_type_name;
        t0 = concat_3(l2, 858u, l6);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 672u) {
        l1 = l0.payload.obj;
        l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(5));
        l3 = (size_t) (int64_t) INT64_C(0);
        l7 = ((vader_struct_vader_comptime_BoolValue_t*) l1)->f_value;
        l3 = std_core_write_bool(l4, l3, l7);
        t0 = std_core_finish_buffer(l4, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 673u) {
        l1 = l0.payload.obj;
        t2 = ((vader_struct_vader_comptime_CharValue_t*) l1)->f_value;
        t0 = std_numbers_to_hex((uint64_t) (int64_t) ((int64_t) (uint32_t) t2));
        l2 = std_string_pad_start(t0, (size_t) (int64_t) INT64_C(4), 48u);
        t0 = concat_3(298u, l2, 283u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 687u) {
        l1 = l0.payload.obj;
        l2 = ((vader_struct_vader_comptime_StringValue_t*) l1)->f_value;
        t0 = concat_3(246u, l2, 246u);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 686u) {
        { vader_gc_top = gc_frame.prev; return 1862u; }
    }
    if (l0.tag == 691u) {
        { vader_gc_top = gc_frame.prev; return 2389u; }
    }
    if (l0.tag == 671u) {
        t3 = l0.payload.obj;
        t0 = vader_comptime_render_array(t3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 688u) {
        t3 = l0.payload.obj;
        t0 = vader_comptime_render_struct(t3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 689u) {
        t3 = l0.payload.obj;
        t0 = vader_types_display_type_key(((vader_struct_vader_comptime_TypeValue_t*) t3)->f_value);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_comptime$display_value");
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_division_by_zero(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span;
    t0 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(4), l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_emit_cycle(size_t l0, void* l1, size_t l2, void* l3, void* l4, void* l5) {
    size_t l6, l7;
    vader_string_t l8;
    vader_box_t l9 = vader_box_null();
    void* l10 = NULL;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[6] = { &l1, &l3, &l4, &l5, &l10, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l6 = l2;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_5: {
            if ((l7 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l7];
                if (t0 == l0) {
                    l6 = l7;
                } else {
                    t0 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t0;
                    goto loop_5;
                }
            } else {
            }
        }
    }
    l8 = vader_comptime_cycle_names(l6, l2, l1, l0, l3);
    l9 = std_collections_get__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l3)->f_by_id, l0);
    if (!(l9.tag == 0u)) {
        t1 = l9.payload.obj;
        l10 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) t1)->f_decl)->f_span;
        l10 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(8), l10, l8);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l10));
    } else {
    }
    {
        loop_59: {
            if ((l6 < l2)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
                l7 = (size_t) (int64_t) t0;
                std_collections_put__usize__bool(l4, l7, true);
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_59;
            } else {
            }
        }
    }
    std_collections_put__usize__bool(l4, l0, true);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_equality_only(void* l0, bool l1, uint8_t l2, vader_string_t l3) {
    vader_string_t l4;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(0)) {
        t0 = vader_comptime_bool_value(l1);
        t1 = vader_comptime_ok(t0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2 == INT32_C(1)) {
        t0 = vader_comptime_bool_value(!(l1));
        t1 = vader_comptime_ok(t0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = concat_3(915u, l3, 998u);
    t1 = vader_comptime_type_mismatch(l0, l4);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_evaluate_assert_decls(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l16 = NULL;
    size_t l6, l7, l17;
    vader_box_t l8 = vader_box_null(), l11 = vader_box_null();
    uint8_t l13;
    vader_string_t l15;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_string_t t3;
    vader_box_t* gc_roots[2] = { &l8, &l11 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l10, &l12, &l14, &l16, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_ComptimeContext_t* _a0_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a0_obj, 674u);
    _a0_obj->f_typed = l1;
    _a0_obj->f_bindings = l2;
    _a0_obj->f_depth = INT64_C(0);
    l4 = (void*) _a0_obj;
    l5 = l0;
    l6 = ((vader_array_t*) l5)->length;
    l7 = (size_t) (int64_t) INT64_C(0);
    {
        loop_12: {
            if ((l7 < l6)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l7 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                if (l8.tag == 388u) {
                    l9 = l8.payload.obj;
                    l10 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_AssertDecl_t*) l9)->f_condition, l4);
                    l11 = ((vader_struct_vader_comptime_EvalResult_t*) l10)->f_diag;
                    if (l11.tag == 0u) {
                        if (((vader_struct_vader_comptime_EvalResult_t*) l10)->f_value.tag == 672u) {
                            t0 = ((vader_struct_vader_comptime_EvalResult_t*) l10)->f_value.payload.obj;
                            t1 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
                            if (!(t1)) {
                                l13 = (uint8_t) (int32_t) INT32_C(14);
                                l14 = ((vader_struct_toolchain_ast_AssertDecl_t*) l9)->f_span;
                                l15 = vader_comptime_assert_message(l9);
                                l16 = vader_diagnostics_comptime_error(l13, l14, l15);
                                vader_array_push((vader_array_t*) l3, vader_ref_box(l16));
                            } else {
                            }
                        } else {
                        }
                        l17 = (size_t) (int64_t) INT64_C(1);
                        t2 = (l7 + l17);
                        l7 = (size_t) (int64_t) t2;
                        goto loop_12;
                    }
                    if (l11.tag == 693u) {
                        l12 = l11.payload.obj;
                        t3 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l12)->f_code)->f_id;
                        if (t3 != 554u) {
                            vader_array_push((vader_array_t*) l3, vader_ref_box(l12));
                        } else {
                        }
                        if (((vader_struct_vader_comptime_EvalResult_t*) l10)->f_value.tag == 672u) {
                            t0 = ((vader_struct_vader_comptime_EvalResult_t*) l10)->f_value.payload.obj;
                            t1 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
                            if (!(t1)) {
                                l13 = (uint8_t) (int32_t) INT32_C(14);
                                l14 = ((vader_struct_toolchain_ast_AssertDecl_t*) l9)->f_span;
                                l15 = vader_comptime_assert_message(l9);
                                l16 = vader_diagnostics_comptime_error(l13, l14, l15);
                                vader_array_push((vader_array_t*) l3, vader_ref_box(l16));
                            } else {
                            }
                        } else {
                        }
                        l17 = (size_t) (int64_t) INT64_C(1);
                        t2 = (l7 + l17);
                        l7 = (size_t) (int64_t) t2;
                        goto loop_12;
                    }
                    { vader_gc_top = gc_frame.prev; return; }
                }
                l17 = (size_t) (int64_t) INT64_C(1);
                t2 = (l7 + l17);
                l7 = (size_t) (int64_t) t2;
                goto loop_12;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_binary_expr(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5;
    vader_string_t l6;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null();
    bool l8;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l7, &l9, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_left, vader_ref_box(l1));
    l3 = t0.payload.obj;
    if (((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value.tag == 0u) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_right, vader_ref_box(l1));
    l4 = t0.payload.obj;
    if (((vader_struct_vader_comptime_EvalResult_t*) l4)->f_value.tag == 0u) {
        { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_id;
    l6 = vader_comptime_resolved_int_name(l1, l5);
    if (((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(5)) {
        l8 = true;
    } else {
        l8 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(6);
    }
    if (l8) {
        l7 = vader_comptime_mask_shift_amount(((vader_struct_vader_comptime_EvalResult_t*) l4)->f_value, l6);
    } else {
        l7 = ((vader_struct_vader_comptime_EvalResult_t*) l4)->f_value;
    }
    l9 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
    t1 = vader_comptime_combine_binary(l0, l9, l7);
    t2 = vader_comptime_normalize_int_result(t1, l6);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_bool_lit(void* l0) {
    bool t0;
    void* t1 = NULL;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l0, &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_BoolLitExpr_t*) l0)->f_value;
    if (t0) {
        vader_struct_vader_comptime_BoolValue_t* _a0_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
        vader_obj_header_init(_a0_obj, 672u);
        _a0_obj->f_value = true;
        t1 = (void*) _a0_obj;
        t2 = vader_comptime_ok(vader_ref_box(t1));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_comptime_BoolValue_t* _a1_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
    vader_obj_header_init(_a1_obj, 672u);
    _a1_obj->f_value = false;
    t1 = (void*) _a1_obj;
    t2 = vader_comptime_ok(vader_ref_box(t1));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_call_expr(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    void* l13 = NULL;
    void* l17 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l33 = NULL;
    void* l39 = NULL;
    void* l40 = NULL;
    void* l41 = NULL;
    void* l44 = NULL;
    void* l49 = NULL;
    void* l50 = NULL;
    void* l51 = NULL;
    void* l52 = NULL;
    bool l4;
    vader_box_t l6 = vader_box_null(), l12 = vader_box_null(), l32 = vader_box_null(), l35 = vader_box_null(), l43 = vader_box_null(), l47 = vader_box_null();
    int64_t l7;
    vader_string_t l8, l14, l18, l45;
    uint64_t l9, l42;
    int32_t l11, l31, l34, l46;
    size_t l15, l16, l22, l23, l24, l29, l30, l36, l37, l38, l48;
    void* t0 = NULL;
    void* t4 = NULL;
    vader_box_t t1 = vader_box_null();
    size_t t2;
    vader_string_t t3;
    int64_t t5;
    vader_box_t* gc_roots[7] = { &l6, &l12, &l32, &l35, &l43, &l47, &t1 };
    void** gc_raw_roots[26] = { &l0, &l1, &l2, &l3, &l5, &l10, &l13, &l17, &l19, &l20, &l21, &l25, &l26, &l27, &l28, &l33, &l39, &l40, &l41, &l44, &l49, &l50, &l51, &l52, &t0, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 7u, 26u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_callee.tag == 421u)) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 578u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_callee;
    l2 = t1.payload.obj;
    if (((vader_obj_header_t*) l2)->type_index == 421u) {
        l3 = l2;
        t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
        if (t2 == INT64_C(1)) {
            t3 = ((vader_struct_toolchain_ast_IdentExpr_t*) l3)->f_name;
            l4 = vader_comptime_is_primitive_int_name(t3);
        } else {
            l4 = false;
        }
        if (l4) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
            l5 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1);
            if (((vader_struct_vader_comptime_EvalResult_t*) l5)->f_value.tag == 0u) {
                { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l6 = ((vader_struct_vader_comptime_EvalResult_t*) l5)->f_value;
            if (l6.tag == 682u) {
                t0 = l6.payload.obj;
                l7 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
                l8 = ((vader_struct_toolchain_ast_IdentExpr_t*) l3)->f_name;
                vader_struct_vader_comptime_IntValue_t* _a1_obj = (vader_struct_vader_comptime_IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_IntValue_t));
                vader_obj_header_init(_a1_obj, 682u);
                _a1_obj->f_value = l7;
                _a1_obj->f_type_name = l8;
                t0 = (void*) _a1_obj;
                t4 = vader_comptime_ok(vader_ref_box(t0));
                { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l3 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
            l9 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_span);
            l6 = std_collections_get__u64__Any(l3, l9);
            if (l6.tag == 0u) {
                l5 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
                l8 = 576u;
                t0 = vader_comptime_vm_required(l5, l8);
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l10 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_fn_decls;
            t0 = l6.payload.obj;
            l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
            l12 = std_collections_get__i32__Any(l10, l11);
            if (l12.tag == 0u) {
                l13 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
                l14 = 577u;
                t0 = vader_comptime_vm_required(l13, l14);
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = l12.payload.obj;
            l15 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params)->length;
            l16 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
            if (l15 != l16) {
                l17 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
                l18 = 572u;
                t0 = vader_comptime_vm_required(l17, l18);
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 165u);
            l19 = (void*) _a2_arr;
            vader_array_t* _a3_arr = vader_array_new(15u, 0u, 0u, 172u);
            l20 = (void*) _a3_arr;
            vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 165u);
            l21 = (void*) _a4_arr;
            l22 = (size_t) (int64_t) INT64_C(0);
            l23 = (size_t) (int64_t) INT64_C(0);
            l24 = (size_t) (int64_t) INT64_C(0);
            vader_struct_std_collections_MutableMap__i32__Any_t* _a5_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
            vader_obj_header_init(_a5_obj, 281u);
            _a5_obj->f_ekeys = l19;
            _a5_obj->f_evals = l20;
            _a5_obj->f_index = l21;
            _a5_obj->f_mask = l22;
            _a5_obj->f_size = l23;
            _a5_obj->f_tombs = l24;
            l25 = (void*) _a5_obj;
            l26 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_bindings;
            l27 = ((vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l26)->f_ekeys;
            l28 = ((vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l26)->f_evals;
            l29 = ((vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l26)->f_size;
            l30 = (size_t) (int64_t) INT64_C(0);
            {
                loop_159: {
                    if ((l30 >= l29)) {
                    } else {
                        vader_array_t* _a6_slotarr = ((vader_array_t*) l27);
                        if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                        if ((size_t) l30 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                        l31 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l30];
                        vader_array_t* _a7_slotarr = ((vader_array_t*) l28);
                        if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                        if ((size_t) l30 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                        l32 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l30);
                        vader_struct___Tuple_1218_t* _a8_obj = (vader_struct___Tuple_1218_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1218_t));
                        vader_obj_header_init(_a8_obj, 216u);
                        _a8_obj->f__0 = l31;
                        _a8_obj->f__1 = l32;
                        l33 = (void*) _a8_obj;
                        l34 = ((vader_struct___Tuple_1218_t*) l33)->f__0;
                        l35 = ((vader_struct___Tuple_1218_t*) l33)->f__1;
                        l36 = (size_t) (int64_t) INT64_C(1);
                        t5 = (l30 + l36);
                        l30 = (size_t) (int64_t) t5;
                        std_collections_put__i32__Any(l25, l34, l35);
                        goto loop_159;
                    }
                }
            }
            l37 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
            l38 = (size_t) (int64_t) INT64_C(0);
            {
                loop_202: {
                    if ((l38 < l37)) {
                        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args);
                        if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                        if ((size_t) l38 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                        t0 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l38);
                        l39 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1);
                        if (((vader_struct_vader_comptime_EvalResult_t*) l39)->f_value.tag == 0u) {
                            { void* __vret = l39; vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        t0 = l12.payload.obj;
                        vader_array_t* _a10_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params);
                        if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                        if ((size_t) l38 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                        l40 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l38);
                        l41 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
                        l42 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l40)->f_span);
                        l43 = std_collections_get__u64__Any(l41, l42);
                        if (l43.tag == 0u) {
                            l44 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
                            l45 = 579u;
                            t0 = vader_comptime_vm_required(l44, l45);
                            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        t0 = l43.payload.obj;
                        l46 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
                        l47 = ((vader_struct_vader_comptime_EvalResult_t*) l39)->f_value;
                        std_collections_put__i32__Any(l25, l46, l47);
                        l48 = (size_t) (int64_t) INT64_C(1);
                        t5 = (l38 + l48);
                        l38 = (size_t) (int64_t) t5;
                        goto loop_202;
                    } else {
                    }
                }
            }
            l49 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed;
            l7 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
            vader_struct_vader_comptime_ComptimeContext_t* _a11_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
            vader_obj_header_init(_a11_obj, 674u);
            _a11_obj->f_typed = l49;
            _a11_obj->f_bindings = l25;
            _a11_obj->f_depth = l7;
            l50 = (void*) _a11_obj;
            l51 = l12.payload.obj;
            l52 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
            t0 = vader_comptime_evaluate_fn_body(l51, l50, l52);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
        l9 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_span);
        l6 = std_collections_get__u64__Any(l3, l9);
        if (l6.tag == 0u) {
            l5 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
            l8 = 576u;
            t0 = vader_comptime_vm_required(l5, l8);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l10 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_fn_decls;
        t0 = l6.payload.obj;
        l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
        l12 = std_collections_get__i32__Any(l10, l11);
        if (l12.tag == 0u) {
            l13 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
            l14 = 577u;
            t0 = vader_comptime_vm_required(l13, l14);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l12.payload.obj;
        l15 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params)->length;
        l16 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
        if (l15 != l16) {
            l17 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
            l18 = 572u;
            t0 = vader_comptime_vm_required(l17, l18);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_array_t* _a12_arr = vader_array_new(9u, 0u, 7u, 165u);
        l19 = (void*) _a12_arr;
        vader_array_t* _a13_arr = vader_array_new(15u, 0u, 0u, 172u);
        l20 = (void*) _a13_arr;
        vader_array_t* _a14_arr = vader_array_new(9u, 0u, 7u, 165u);
        l21 = (void*) _a14_arr;
        l22 = (size_t) (int64_t) INT64_C(0);
        l23 = (size_t) (int64_t) INT64_C(0);
        l24 = (size_t) (int64_t) INT64_C(0);
        vader_struct_std_collections_MutableMap__i32__Any_t* _a15_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
        vader_obj_header_init(_a15_obj, 281u);
        _a15_obj->f_ekeys = l19;
        _a15_obj->f_evals = l20;
        _a15_obj->f_index = l21;
        _a15_obj->f_mask = l22;
        _a15_obj->f_size = l23;
        _a15_obj->f_tombs = l24;
        l25 = (void*) _a15_obj;
        l26 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_bindings;
        l27 = ((vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l26)->f_ekeys;
        l28 = ((vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l26)->f_evals;
        l29 = ((vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l26)->f_size;
        l30 = (size_t) (int64_t) INT64_C(0);
        {
            loop_389: {
                if ((l30 >= l29)) {
                } else {
                    vader_array_t* _a16_slotarr = ((vader_array_t*) l27);
                    if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                    if ((size_t) l30 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                    l31 = ((int32_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l30];
                    vader_array_t* _a17_slotarr = ((vader_array_t*) l28);
                    if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                    if ((size_t) l30 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                    l32 = vader_array_ref_load_box(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l30);
                    vader_struct___Tuple_1218_t* _a18_obj = (vader_struct___Tuple_1218_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1218_t));
                    vader_obj_header_init(_a18_obj, 216u);
                    _a18_obj->f__0 = l31;
                    _a18_obj->f__1 = l32;
                    l33 = (void*) _a18_obj;
                    l34 = ((vader_struct___Tuple_1218_t*) l33)->f__0;
                    l35 = ((vader_struct___Tuple_1218_t*) l33)->f__1;
                    l36 = (size_t) (int64_t) INT64_C(1);
                    t5 = (l30 + l36);
                    l30 = (size_t) (int64_t) t5;
                    std_collections_put__i32__Any(l25, l34, l35);
                    goto loop_389;
                }
            }
        }
        l37 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
        l38 = (size_t) (int64_t) INT64_C(0);
        {
            loop_432: {
                if ((l38 < l37)) {
                    vader_array_t* _a19_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args);
                    if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                    if ((size_t) l38 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l38);
                    l39 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1);
                    if (((vader_struct_vader_comptime_EvalResult_t*) l39)->f_value.tag == 0u) {
                        { void* __vret = l39; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    t0 = l12.payload.obj;
                    vader_array_t* _a20_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params);
                    if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                    if ((size_t) l38 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                    l40 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l38);
                    l41 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
                    l42 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l40)->f_span);
                    l43 = std_collections_get__u64__Any(l41, l42);
                    if (l43.tag == 0u) {
                        l44 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
                        l45 = 579u;
                        t0 = vader_comptime_vm_required(l44, l45);
                        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    t0 = l43.payload.obj;
                    l46 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
                    l47 = ((vader_struct_vader_comptime_EvalResult_t*) l39)->f_value;
                    std_collections_put__i32__Any(l25, l46, l47);
                    l48 = (size_t) (int64_t) INT64_C(1);
                    t5 = (l38 + l48);
                    l38 = (size_t) (int64_t) t5;
                    goto loop_432;
                } else {
                }
            }
        }
        l49 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed;
        l7 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
        vader_struct_vader_comptime_ComptimeContext_t* _a21_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
        vader_obj_header_init(_a21_obj, 674u);
        _a21_obj->f_typed = l49;
        _a21_obj->f_bindings = l25;
        _a21_obj->f_depth = l7;
        l50 = (void*) _a21_obj;
        l51 = l12.payload.obj;
        l52 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
        t0 = vader_comptime_evaluate_fn_body(l51, l50, l52);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
    l9 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_span);
    l6 = std_collections_get__u64__Any(l3, l9);
    if (l6.tag == 0u) {
        l5 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
        l8 = 576u;
        t0 = vader_comptime_vm_required(l5, l8);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_fn_decls;
    t0 = l6.payload.obj;
    l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
    l12 = std_collections_get__i32__Any(l10, l11);
    if (l12.tag == 0u) {
        l13 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
        l14 = 577u;
        t0 = vader_comptime_vm_required(l13, l14);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l12.payload.obj;
    l15 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params)->length;
    l16 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
    if (l15 != l16) {
        l17 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
        l18 = 572u;
        t0 = vader_comptime_vm_required(l17, l18);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a22_arr = vader_array_new(9u, 0u, 7u, 165u);
    l19 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_new(15u, 0u, 0u, 172u);
    l20 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(9u, 0u, 7u, 165u);
    l21 = (void*) _a24_arr;
    l22 = (size_t) (int64_t) INT64_C(0);
    l23 = (size_t) (int64_t) INT64_C(0);
    l24 = (size_t) (int64_t) INT64_C(0);
    vader_struct_std_collections_MutableMap__i32__Any_t* _a25_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a25_obj, 281u);
    _a25_obj->f_ekeys = l19;
    _a25_obj->f_evals = l20;
    _a25_obj->f_index = l21;
    _a25_obj->f_mask = l22;
    _a25_obj->f_size = l23;
    _a25_obj->f_tombs = l24;
    l25 = (void*) _a25_obj;
    l26 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_bindings;
    l27 = ((vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l26)->f_ekeys;
    l28 = ((vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l26)->f_evals;
    l29 = ((vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l26)->f_size;
    l30 = (size_t) (int64_t) INT64_C(0);
    {
        loop_619: {
            if ((l30 >= l29)) {
            } else {
                vader_array_t* _a26_slotarr = ((vader_array_t*) l27);
                if (_a26_slotarr->buf != NULL && _a26_slotarr->buf->header.forward != NULL) { _a26_slotarr->buf = vader_array_buf_forward(_a26_slotarr->buf); }
                if ((size_t) l30 >= _a26_slotarr->length) { vader_trap("array index out of bounds"); }
                l31 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l30];
                vader_array_t* _a27_slotarr = ((vader_array_t*) l28);
                if (_a27_slotarr->buf != NULL && _a27_slotarr->buf->header.forward != NULL) { _a27_slotarr->buf = vader_array_buf_forward(_a27_slotarr->buf); }
                if ((size_t) l30 >= _a27_slotarr->length) { vader_trap("array index out of bounds"); }
                l32 = vader_array_ref_load_box(_a27_slotarr->buf, _a27_slotarr->offset + (size_t) l30);
                vader_struct___Tuple_1218_t* _a28_obj = (vader_struct___Tuple_1218_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1218_t));
                vader_obj_header_init(_a28_obj, 216u);
                _a28_obj->f__0 = l31;
                _a28_obj->f__1 = l32;
                l33 = (void*) _a28_obj;
                l34 = ((vader_struct___Tuple_1218_t*) l33)->f__0;
                l35 = ((vader_struct___Tuple_1218_t*) l33)->f__1;
                l36 = (size_t) (int64_t) INT64_C(1);
                t5 = (l30 + l36);
                l30 = (size_t) (int64_t) t5;
                std_collections_put__i32__Any(l25, l34, l35);
                goto loop_619;
            }
        }
    }
    l37 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
    l38 = (size_t) (int64_t) INT64_C(0);
    {
        loop_662: {
            if ((l38 < l37)) {
                vader_array_t* _a29_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args);
                if (_a29_slotarr->buf != NULL && _a29_slotarr->buf->header.forward != NULL) { _a29_slotarr->buf = vader_array_buf_forward(_a29_slotarr->buf); }
                if ((size_t) l38 >= _a29_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a29_slotarr->buf, _a29_slotarr->offset + (size_t) l38);
                l39 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1);
                if (((vader_struct_vader_comptime_EvalResult_t*) l39)->f_value.tag == 0u) {
                    { void* __vret = l39; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t0 = l12.payload.obj;
                vader_array_t* _a30_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params);
                if (_a30_slotarr->buf != NULL && _a30_slotarr->buf->header.forward != NULL) { _a30_slotarr->buf = vader_array_buf_forward(_a30_slotarr->buf); }
                if ((size_t) l38 >= _a30_slotarr->length) { vader_trap("array index out of bounds"); }
                l40 = vader_array_ref_load_obj(_a30_slotarr->buf, _a30_slotarr->offset + (size_t) l38);
                l41 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
                l42 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l40)->f_span);
                l43 = std_collections_get__u64__Any(l41, l42);
                if (l43.tag == 0u) {
                    l44 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
                    l45 = 579u;
                    t0 = vader_comptime_vm_required(l44, l45);
                    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t0 = l43.payload.obj;
                l46 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
                l47 = ((vader_struct_vader_comptime_EvalResult_t*) l39)->f_value;
                std_collections_put__i32__Any(l25, l46, l47);
                l48 = (size_t) (int64_t) INT64_C(1);
                t5 = (l38 + l48);
                l38 = (size_t) (int64_t) t5;
                goto loop_662;
            } else {
            }
        }
    }
    l49 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed;
    l7 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    vader_struct_vader_comptime_ComptimeContext_t* _a31_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a31_obj, 674u);
    _a31_obj->f_typed = l49;
    _a31_obj->f_bindings = l25;
    _a31_obj->f_depth = l7;
    l50 = (void*) _a31_obj;
    l51 = l12.payload.obj;
    l52 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
    t0 = vader_comptime_evaluate_fn_body(l51, l50, l52);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_char_lit(void* l0) {
    uint32_t t0;
    void* t1 = NULL;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l0, &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_CharLitExpr_t*) l0)->f_value;
    vader_struct_vader_comptime_CharValue_t* _a0_obj = (vader_struct_vader_comptime_CharValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_CharValue_t));
    vader_obj_header_init(_a0_obj, 673u);
    _a0_obj->f_value = t0;
    t1 = (void*) _a0_obj;
    t2 = vader_comptime_ok(vader_ref_box(t1));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_comptime_evaluate_expr(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    size_t l4;
    vader_string_t l5;
    int64_t l6;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l7, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    if ((t0 >= INT64_C(2000))) {
        l2 = vader_comptime_span_of(l0);
        l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(93));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l3, l4, 1122u);
        l4 = std_core_write_int(l3, l4, INT64_C(2000));
        l4 = std_core_write_string_at(l3, l4, 133u);
        l5 = std_core_finish_buffer(l3, l4);
        t1 = vader_comptime_vm_required(l2, l5);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    l6 = (t0 + INT64_C(1));
    ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_comptime_ComptimeContext_t*) l1);
    if (l0.tag == 431u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_int_lit(t1);
    } else {
        if (l0.tag == 415u) {
            t1 = l0.payload.obj;
            l2 = vader_comptime_evaluate_float_lit(t1);
        } else {
            if (l0.tag == 394u) {
                t1 = l0.payload.obj;
                l2 = vader_comptime_evaluate_bool_lit(t1);
            } else {
                if (l0.tag == 399u) {
                    t1 = l0.payload.obj;
                    l2 = vader_comptime_evaluate_char_lit(t1);
                } else {
                    if (l0.tag == 444u) {
                        t1 = l0.payload.obj;
                        l2 = vader_comptime_evaluate_null_lit(t1);
                    } else {
                        if (l0.tag == 455u) {
                            l3 = l0.payload.obj;
                            l7 = (void*) &vader_fn_static_956;
                            l2 = vader_comptime_evaluate_string_lit(l3, l1, l7);
                        } else {
                            if (l0.tag == 421u) {
                                t1 = l0.payload.obj;
                                l2 = vader_comptime_evaluate_ident(t1, l1);
                            } else {
                                if (l0.tag == 391u) {
                                    l3 = l0.payload.obj;
                                    l7 = (void*) &vader_fn_static_956;
                                    l2 = vader_comptime_evaluate_binary_expr(l3, l1, l7);
                                } else {
                                    if (l0.tag == 470u) {
                                        l3 = l0.payload.obj;
                                        l7 = (void*) &vader_fn_static_956;
                                        l2 = vader_comptime_evaluate_unary_expr(l3, l1, l7);
                                    } else {
                                        if (l0.tag == 432u) {
                                            t1 = l0.payload.obj;
                                            l2 = vader_comptime_evaluate_intrinsic_call(t1, l1);
                                        } else {
                                            if (l0.tag == 397u) {
                                                t1 = l0.payload.obj;
                                                l2 = vader_comptime_evaluate_call_expr(t1, l1);
                                            } else {
                                                if (l0.tag == 453u) {
                                                    l3 = l0.payload.obj;
                                                    l7 = (void*) &vader_fn_static_956;
                                                    l2 = vader_comptime_evaluate_seq_lit(l3, l1, l7);
                                                } else {
                                                    l3 = vader_comptime_span_of(l0);
                                                    l5 = vader_comptime_expr_kind_label(l0);
                                                    l2 = vader_comptime_vm_required(l3, l5);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    t0 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    l6 = (t0 - INT64_C(1));
    ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth = l6;
    VADER_WRITE_BARRIER((vader_struct_vader_comptime_ComptimeContext_t*) l1);
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_float_lit(void* l0) {
    double t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_FloatLitExpr_t*) l0)->f_value;
    t1 = vader_comptime_float_val(t0);
    t2 = vader_comptime_ok(t1);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_fn_body(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_string_t l5;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    size_t t2;
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body.tag == 0u) {
        t0 = vader_comptime_vm_required(l2, 575u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body;
    l3 = t1.payload.obj;
    if (!(((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_trailing.tag == 0u)) {
        t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_stmts)->length;
        if (t2 == INT64_C(0)) {
            t0 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_trailing, l1);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_comptime_vm_required(l2, 573u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_stmts)->length;
    if (t2 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_stmts);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        if (l4.tag == 452u) {
            l3 = l4.payload.obj;
            if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) l3)->f_value.tag == 0u)) {
                t0 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) l3)->f_value, l1);
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l5 = 574u;
            t0 = vader_comptime_vm_required(l2, l5);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = 574u;
        t0 = vader_comptime_vm_required(l2, l5);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = 574u;
    t0 = vader_comptime_vm_required(l2, l5);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_ident(void* l0, void* l1) {
    void* l2 = NULL;
    uint64_t l3;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    int32_t l5;
    vader_string_t l7, l8, l9, l10;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l6, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
    l3 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span);
    l4 = std_collections_get__u64__Any(l2, l3);
    if (l4.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span, 614u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_bindings;
    t0 = l4.payload.obj;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
    l6 = std_collections_get__i32__Any(l2, l5);
    if (!(l6.tag == 0u)) {
        t0 = vader_comptime_ok(l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l4.payload.obj;
    t1 = vader_comptime_is_type_symbol_kind(((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_kind);
    if (t1) {
        l6 = vader_comptime_type_from_expr_safe(l0, l1);
        if (!(l6.tag == 0u)) {
            t2 = vader_comptime_type_val(l6);
            t0 = vader_comptime_ok(t2);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = ((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span;
        l7 = 613u;
        t0 = l4.payload.obj;
        l8 = vader_resolver_symbol_kind_name(((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_kind);
        l9 = 337u;
        l10 = concat_3(l7, l8, l9);
        t0 = vader_comptime_vm_required(l2, l10);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span;
    l7 = 613u;
    t0 = l4.payload.obj;
    l8 = vader_resolver_symbol_kind_name(((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_kind);
    l9 = 337u;
    l10 = concat_3(l7, l8, l9);
    t0 = vader_comptime_vm_required(l2, l10);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_int_lit(void* l0) {
    uint64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_IntLitExpr_t*) l0)->f_value;
    t1 = vader_comptime_int_val(((int64_t) (uint64_t) t0));
    t2 = vader_comptime_ok(t1);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_intrinsic_call(void* l0, void* l1) {
    void* l2 = NULL;
    vader_string_t l3;
    vader_string_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1964u) {
        t1 = vader_comptime_intrinsic_size_of(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1140u) {
        t1 = vader_comptime_intrinsic_align_of(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2189u) {
        t1 = vader_comptime_intrinsic_type_name(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2187u) {
        t1 = vader_comptime_intrinsic_type_kind(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1539u) {
        t1 = vader_comptime_intrinsic_field_count(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2385u) {
        t1 = vader_comptime_intrinsic_variant_count(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1541u) {
        t1 = vader_comptime_intrinsic_field_index(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
    l3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    l3 = concat_2(528u, l3);
    t1 = vader_comptime_vm_required(l2, l3);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_evaluate_module_decls(void* l0, void* l1, void* l2, void* l3, vader_string_t l4, void* l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    size_t l8, l9, l17;
    vader_box_t l12 = vader_box_null(), l14 = vader_box_null(), l18 = vader_box_null(), l21 = vader_box_null();
    int32_t l20, l23;
    int64_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[5] = { &l12, &l14, &l18, &l21, &t2 };
    void** gc_raw_roots[15] = { &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l10, &l11, &l13, &l15, &l16, &l19, &l22, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 15u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l6 = vader_comptime_sort_comptime_decls(l0, l1);
    l7 = ((vader_struct_vader_comptime_ComptimeOrder_t*) l6)->f_cycle_diags;
    l8 = ((vader_array_t*) l7)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_11: {
            if ((l9 < l8)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l9 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
                vader_array_push((vader_array_t*) l5, vader_ref_box(l10));
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                goto loop_11;
            } else {
            }
        }
    }
    l7 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
    vader_struct_vader_comptime_ComptimeContext_t* _a1_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a1_obj, 674u);
    _a1_obj->f_typed = l1;
    _a1_obj->f_bindings = l7;
    _a1_obj->f_depth = INT64_C(0);
    l7 = (void*) _a1_obj;
    l6 = ((vader_struct_vader_comptime_ComptimeOrder_t*) l6)->f_order;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_46: {
            if ((l9 < l8)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                l11 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ConstDecl_t*) l10)->f_value, l7);
                t1 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_vm_required;
                if (t1) {
                    l12 = vader_typecheck_lookup_const_symbol(l10, l1);
                    if (l12.tag == 881u) {
                        l13 = l12.payload.obj;
                        l14 = vader_comptime_build_vm_required(l10, l13, l1, l4);
                        if (l14.tag == 690u) {
                            l15 = l14.payload.obj;
                            vader_array_push((vader_array_t*) ((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_vm_required, vader_ref_box(l15));
                            t0 = (l9 + INT64_C(1));
                            l9 = (size_t) (int64_t) t0;
                            goto loop_46;
                        }
                        if (!(((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag.tag == 0u)) {
                            t2 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag;
                            l16 = t2.payload.obj;
                            vader_array_push((vader_array_t*) l5, vader_ref_box(l16));
                        } else {
                        }
                        l17 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l9 + l17);
                        l9 = (size_t) (int64_t) t0;
                        goto loop_46;
                    }
                    if (!(((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag.tag == 0u)) {
                        t2 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag;
                        l16 = t2.payload.obj;
                        vader_array_push((vader_array_t*) l5, vader_ref_box(l16));
                    } else {
                    }
                    l17 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l9 + l17);
                    l9 = (size_t) (int64_t) t0;
                    goto loop_46;
                }
                if (!(((vader_struct_vader_comptime_EvalResult_t*) l11)->f_value.tag == 0u)) {
                    l18 = vader_typecheck_lookup_const_symbol(l10, l1);
                    if (!(l18.tag == 0u)) {
                        l19 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
                        t3 = l18.payload.obj;
                        l20 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t3)->f_id;
                        l21 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_value;
                        std_collections_put__i32__Any(l19, l20, l21);
                    } else {
                    }
                } else {
                }
                if (!(((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag.tag == 0u)) {
                    t2 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag;
                    l22 = t2.payload.obj;
                    vader_array_push((vader_array_t*) l5, vader_ref_box(l22));
                } else {
                }
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                goto loop_46;
            } else {
            }
        }
    }
    l6 = l0;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_184: {
            if ((l9 < l8)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l9 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
                if (l12.tag == 400u) {
                    l10 = l12.payload.obj;
                    t1 = vader_comptime_has_comptime_decorator(l10);
                    if (t1) {
                        t0 = (l9 + INT64_C(1));
                        l9 = (size_t) (int64_t) t0;
                        goto loop_184;
                    }
                    l14 = vader_typecheck_lookup_const_symbol(l10, l1);
                    if (l14.tag == 0u) {
                        t0 = (l9 + INT64_C(1));
                        l9 = (size_t) (int64_t) t0;
                        goto loop_184;
                    }
                    l11 = l14.payload.obj;
                    if (((vader_obj_header_t*) l11)->type_index == 881u) {
                        l13 = l11;
                        l15 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
                        l20 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l13)->f_id;
                        t2 = std_collections_get__i32__Any(l15, l20);
                        if (!(t2.tag == 0u)) {
                            t0 = (l9 + INT64_C(1));
                            l9 = (size_t) (int64_t) t0;
                            goto loop_184;
                        }
                        l16 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ConstDecl_t*) l10)->f_value, l7);
                        if (!(((vader_struct_vader_comptime_EvalResult_t*) l16)->f_value.tag == 0u)) {
                            l19 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
                            l23 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l13)->f_id;
                            l18 = ((vader_struct_vader_comptime_EvalResult_t*) l16)->f_value;
                            std_collections_put__i32__Any(l19, l23, l18);
                        } else {
                        }
                        l17 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l9 + l17);
                        l9 = (size_t) (int64_t) t0;
                        goto loop_184;
                    }
                    l17 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l9 + l17);
                    l9 = (size_t) (int64_t) t0;
                    goto loop_184;
                }
                l17 = (size_t) (int64_t) INT64_C(1);
                t0 = (l9 + l17);
                l9 = (size_t) (int64_t) t0;
                goto loop_184;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_null_lit(void* l0) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_NullValue_t* _a0_obj = (vader_struct_vader_comptime_NullValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_NullValue_t));
    vader_obj_header_init(_a0_obj, 686u);
    t0 = (void*) _a0_obj;
    t1 = vader_comptime_ok(vader_ref_box(t0));
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_comptime_evaluate_project(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    size_t l7, l8;
    vader_string_t l9, l11;
    vader_box_t l14 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l14, &t0 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l10, &l12, &l13, &l15, &l16, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 13u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_comptime_new_evaluated_project(l1);
    l4 = ((vader_struct_vader_typecheck_TypedProject_t*) l1)->f_modules;
    l5 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l4)->f_evals;
    l7 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l4)->f_size;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_15: {
            if ((l8 >= l7)) {
            } else {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l8 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l8];
                l9 = t0.payload.s;
                vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l8 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
                vader_struct___Tuple_1149_t* _a2_obj = (vader_struct___Tuple_1149_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1149_t));
                vader_obj_header_init(_a2_obj, 199u);
                _a2_obj->f__0 = l9;
                _a2_obj->f__1 = l4;
                l10 = (void*) _a2_obj;
                l11 = ((vader_struct___Tuple_1149_t*) l10)->f__0;
                l12 = ((vader_struct___Tuple_1149_t*) l10)->f__1;
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                l13 = vader_comptime_new_evaluated_program(l12);
                l14 = vader_comptime_lookup_module_decls(l0, l11);
                if (!(l14.tag == 0u)) {
                    t2 = l14.payload.obj;
                    vader_comptime_evaluate_module_decls(t2, l12, l13, l3, l11, l2);
                    l15 = l14.payload.obj;
                    l16 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l13)->f_comptime_decls;
                    vader_comptime_evaluate_assert_decls(l15, l12, l16, l2);
                    t2 = l14.payload.obj;
                    vader_comptime_bake_file_exprs(t2, l12, l3, l13, l2);
                } else {
                }
                std_collections_put__string__Any(((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_modules, l11, vader_ref_box(l13));
                goto loop_15;
            }
        }
    }
    l4 = vader_comptime_harvest_instances(l1);
    ((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_instances = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_comptime_EvaluatedProject_t*) l3);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_seq_lit(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    size_t l5, l6, l10;
    vader_box_t l8 = vader_box_null(), l13 = vader_box_null();
    uint64_t l11;
    vader_string_t l12;
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    int64_t t2;
    void* t3 = NULL;
    void* t5 = NULL;
    vader_string_t t4;
    vader_box_t* gc_roots[4] = { &l8, &l13, &t0, &t1 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l7, &l9, &t3, &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(122u, 0u, 13u, 1112u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l0)->f_elements;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l6 < l5)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                vader_fn_t* _a2_fnobj = (vader_fn_t*) l2;
                t1 = ((vader_fn_erased_sig_2_t) _a2_fnobj->code)(_a2_fnobj->env, t0, vader_ref_box(l1));
                l7 = t1.payload.obj;
                if (((vader_struct_vader_comptime_EvalResult_t*) l7)->f_value.tag == 0u) {
                    { void* __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l8 = ((vader_struct_vader_comptime_EvalResult_t*) l7)->f_value;
                vader_array_push((vader_array_t*) l3, l8);
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_9;
            } else {
            }
        }
    }
    l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_expr_types;
    l5 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l0)->f_id;
    l8 = std_collections_get__usize__Any(l4, l5);
    if (l8.tag == 920u) {
        vader_array_t* _a3_arr = vader_array_new(8u, 0u, 0u, 162u);
        l4 = (void*) _a3_arr;
        vader_array_t* _a4_arr = vader_array_new(15u, 0u, 0u, 172u);
        l7 = (void*) _a4_arr;
        vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 165u);
        l9 = (void*) _a5_arr;
        vader_struct_std_collections_MutableMap__string__Any_t* _a6_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
        vader_obj_header_init(_a6_obj, 318u);
        _a6_obj->f_ekeys = l4;
        _a6_obj->f_evals = l7;
        _a6_obj->f_index = l9;
        _a6_obj->f_mask = (size_t) (int64_t) INT64_C(0);
        _a6_obj->f_size = (size_t) (int64_t) INT64_C(0);
        _a6_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
        l4 = (void*) _a6_obj;
        l5 = ((vader_array_t*) l3)->length;
        l6 = (size_t) (int64_t) INT64_C(0);
        {
            loop_73: {
                if ((l6 < l5)) {
                    l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                    l10 = (size_t) (int64_t) INT64_C(0);
                    l10 = std_core_write_string_at(l7, l10, 858u);
                    t2 = ((int64_t) (size_t) l6);
                    l11 = (uint64_t) (int64_t) t2;
                    l10 = std_core_write_unsigned(l7, l10, l11);
                    l12 = std_core_finish_buffer(l7, l10);
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                    if ((size_t) l6 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                    l13 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l6);
                    std_collections_put__string__Any(l4, l12, l13);
                    t2 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    goto loop_73;
                } else {
                }
            }
        }
        t3 = l8.payload.obj;
        t4 = vader_types_display_type_key(vader_ref_box(t3));
        vader_struct_vader_comptime_StructValue_t* _a8_obj = (vader_struct_vader_comptime_StructValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_StructValue_t));
        vader_obj_header_init(_a8_obj, 688u);
        _a8_obj->f_type_name = t4;
        _a8_obj->f_fields = l4;
        t3 = (void*) _a8_obj;
        t5 = vader_comptime_ok(vader_ref_box(t3));
        { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l12 = 0u;
    if (l8.tag == 907u) {
        t3 = l8.payload.obj;
        l12 = vader_types_display_type_key(((vader_struct_vader_types_ArrayType_t*) t3)->f_element);
    } else {
    }
    vader_struct_vader_comptime_ArrayValue_t* _a9_obj = (vader_struct_vader_comptime_ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ArrayValue_t));
    vader_obj_header_init(_a9_obj, 671u);
    _a9_obj->f_elements = l3;
    _a9_obj->f_element_type_name = l12;
    t3 = (void*) _a9_obj;
    t5 = vader_comptime_ok(vader_ref_box(t3));
    { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_string_lit(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l9 = NULL;
    size_t l5, l6, l11;
    vader_box_t l7 = vader_box_null();
    vader_string_t l8, l10;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3;
    vader_box_t* gc_roots[2] = { &l7, &t2 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 162u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 386u);
    _a1_obj->f_parts = t0;
    l3 = (void*) _a1_obj;
    l4 = ((vader_struct_toolchain_ast_StringLitExpr_t*) l0)->f_parts;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_10: {
            if ((l6 < l5)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                if (l7.tag == 457u) {
                    t0 = l7.payload.obj;
                    l8 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_value;
                    std_string_builder_append(l3, l8);
                    l11 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l6 + l11);
                    l6 = (size_t) (int64_t) t1;
                    goto loop_10;
                }
                if (l7.tag == 456u) {
                    t0 = l7.payload.obj;
                    vader_fn_t* _a3_fnobj = (vader_fn_t*) l2;
                    t2 = ((vader_fn_erased_sig_2_t) _a3_fnobj->code)(_a3_fnobj->env, ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, vader_ref_box(l1));
                    l9 = t2.payload.obj;
                    if (((vader_struct_vader_comptime_EvalResult_t*) l9)->f_value.tag == 0u) {
                        { void* __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l10 = vader_comptime_interp_value(((vader_struct_vader_comptime_EvalResult_t*) l9)->f_value);
                    std_string_builder_append(l3, l10);
                    l11 = (size_t) (int64_t) INT64_C(1);
                    t1 = (l6 + l11);
                    l6 = (size_t) (int64_t) t1;
                    goto loop_10;
                }
                vader_unreachable("unreachable return in vader_comptime$evaluate_string_lit");
            } else {
            }
        }
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l3);
    t2 = vader_comptime_string_val(t3);
    t0 = vader_comptime_ok(t2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_unary_expr(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    size_t l4;
    vader_string_t l5;
    uint8_t l6;
    vader_box_t l7 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l7, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_operand, vader_ref_box(l1));
    l3 = t0.payload.obj;
    if (((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value.tag == 0u) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_id;
    l5 = vader_comptime_resolved_int_name(l1, l4);
    l6 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_op;
    if (l6 == INT32_C(0)) {
        l7 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
        t1 = vader_comptime_unary_neg(l0, l7);
        t2 = vader_comptime_normalize_int_result(t1, l5);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(1)) {
        l7 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
        t1 = vader_comptime_unary_not(l0, l7);
        t2 = vader_comptime_normalize_int_result(t1, l5);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(2)) {
        l7 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
        t1 = vader_comptime_unary_bit_not(l0, l7);
        t2 = vader_comptime_normalize_int_result(t1, l5);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_comptime$evaluate_unary_expr");
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_expr_kind_label(vader_box_t l0) {
    vader_string_t l1;
    if (l0.tag == 397u) {
        l1 = 571u;
    } else {
        if (l0.tag == 414u) {
            l1 = 602u;
        } else {
            if (l0.tag == 429u) {
                l1 = 617u;
            } else {
                if (l0.tag == 424u) {
                    l1 = 615u;
                } else {
                    if (l0.tag == 438u) {
                        l1 = 646u;
                    } else {
                        if (l0.tag == 393u) {
                            l1 = 551u;
                        } else {
                            if (l0.tag == 434u) {
                                l1 = 634u;
                            } else {
                                if (l0.tag == 460u) {
                                    l1 = 738u;
                                } else {
                                    if (l0.tag == 453u) {
                                        l1 = 734u;
                                    } else {
                                        if (l0.tag == 449u) {
                                            l1 = 729u;
                                        } else {
                                            if (l0.tag == 398u) {
                                                l1 = 580u;
                                            } else {
                                                if (l0.tag == 420u) {
                                                    l1 = 606u;
                                                } else {
                                                    if (l0.tag == 432u) {
                                                        l1 = 621u;
                                                    } else {
                                                        if (l0.tag == 409u) {
                                                            l1 = 587u;
                                                        } else {
                                                            if (l0.tag == 418u) {
                                                                l1 = 605u;
                                                            } else {
                                                                if (l0.tag == 387u) {
                                                                    l1 = 544u;
                                                                } else {
                                                                    if (l0.tag == 440u) {
                                                                        l1 = 650u;
                                                                    } else {
                                                                        l1 = 592u;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return l1;
}

static void* vader_comptime_fail(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_EvalResult_t* _a0_obj = (vader_struct_vader_comptime_EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvalResult_t));
    vader_obj_header_init(_a0_obj, 676u);
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    _a0_obj->f_diag = vader_ref_box(l0);
    _a0_obj->f_vm_required = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static double vader_comptime_float_arith(uint8_t l0, double l1, double l2) {
    double l3;
    if (l0 == INT32_C(0)) {
        l3 = (l1 + l2);
    } else {
        if (l0 == INT32_C(1)) {
            l3 = (l1 - l2);
        } else {
            if (l0 == INT32_C(2)) {
                l3 = (l1 * l2);
            } else {
                if (l0 == INT32_C(3)) {
                    l3 = l1 / l2;
                } else {
                    l3 = 0.0;
                }
            }
        }
    }
    return l3;
}

static bool vader_comptime_float_compare(double l0, double l1, uint8_t l2) {
    if (l2 == INT32_C(0)) {
        return l0 == l1;
    }
    if (l2 == INT32_C(1)) {
        return l0 != l1;
    }
    if (l2 == INT32_C(2)) {
        return (l0 < l1);
    }
    if (l2 == INT32_C(3)) {
        return (l0 <= l1);
    }
    if (l2 == INT32_C(4)) {
        return (l0 > l1);
    }
    if (l2 == INT32_C(5)) {
        return (l0 >= l1);
    }
    vader_unreachable("unreachable return in vader_comptime$float_compare");
}

static vader_box_t vader_comptime_float_val(double l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_FloatValue_t* _a0_obj = (vader_struct_vader_comptime_FloatValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_FloatValue_t));
    vader_obj_header_init(_a0_obj, 679u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = 1500u;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_comptime_float_val_typed(double l0, vader_string_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_FloatValue_t* _a0_obj = (vader_struct_vader_comptime_FloatValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_FloatValue_t));
    vader_obj_header_init(_a0_obj, 679u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_harvest_instances(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l35 = NULL;
    void* l41 = NULL;
    void* l42 = NULL;
    void* l43 = NULL;
    void* l49 = NULL;
    void* l50 = NULL;
    void* l51 = NULL;
    void* l55 = NULL;
    void* l56 = NULL;
    void* l58 = NULL;
    void* l59 = NULL;
    void* l60 = NULL;
    size_t l5, l6, l12, l13, l20, l21, l22, l28, l29, l36, l37, l44, l45, l52, l53, l61, l62;
    vader_string_t l7, l54;
    int32_t l14;
    vader_box_t l15 = vader_box_null(), l16 = vader_box_null(), l23 = vader_box_null(), l24 = vader_box_null(), l31 = vader_box_null(), l32 = vader_box_null(), l39 = vader_box_null(), l40 = vader_box_null(), l47 = vader_box_null(), l48 = vader_box_null(), l57 = vader_box_null(), l64 = vader_box_null(), l65 = vader_box_null();
    uint64_t l30, l38, l46, l63;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[14] = { &l15, &l16, &l23, &l24, &l31, &l32, &l39, &l40, &l47, &l48, &l57, &l64, &l65, &t0 };
    void** gc_raw_roots[30] = { &l0, &l1, &l2, &l3, &l4, &l8, &l9, &l10, &l11, &l17, &l18, &l19, &l25, &l26, &l27, &l33, &l34, &l35, &l41, &l42, &l43, &l49, &l50, &l51, &l55, &l56, &l58, &l59, &l60, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 14u, 30u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 162u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 172u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 165u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 318u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(48u, 0u, 13u, 680u);
    l2 = (void*) _a4_arr;
    vader_struct_vader_comptime_InstanceRegistry_t* _a5_obj = (vader_struct_vader_comptime_InstanceRegistry_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_InstanceRegistry_t));
    vader_obj_header_init(_a5_obj, 681u);
    _a5_obj->f_by_key = l1;
    _a5_obj->f_order = l2;
    l1 = (void*) _a5_obj;
    l2 = ((vader_struct_vader_typecheck_TypedProject_t*) l0)->f_modules;
    l3 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l2)->f_evals;
    l5 = ((vader_struct_std_collections_MutableMap__string__TypedProgram_t*) l2)->f_size;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_32: {
            if ((l6 >= l5)) {
            } else {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l6 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l6];
                l7 = t0.payload.s;
                vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l6 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                l2 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l6);
                vader_struct___Tuple_1149_t* _a8_obj = (vader_struct___Tuple_1149_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1149_t));
                vader_obj_header_init(_a8_obj, 199u);
                _a8_obj->f__0 = l7;
                _a8_obj->f__1 = l2;
                t1 = (void*) _a8_obj;
                l8 = ((vader_struct___Tuple_1149_t*) t1)->f__1;
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                l9 = ((vader_struct_vader_typecheck_TypedProgram_t*) l8)->f_decl_types;
                l10 = ((vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l9)->f_ekeys;
                l11 = ((vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l9)->f_evals;
                l12 = ((vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l9)->f_size;
                l13 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_68: {
                        if ((l13 >= l12)) {
                        } else {
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l10);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            if ((size_t) l13 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                            l14 = ((int32_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l13];
                            vader_array_t* _a10_slotarr = ((vader_array_t*) l11);
                            if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                            if ((size_t) l13 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                            l15 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l13);
                            vader_struct___Tuple_1150_t* _a11_obj = (vader_struct___Tuple_1150_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1150_t));
                            vader_obj_header_init(_a11_obj, 200u);
                            _a11_obj->f__0 = l14;
                            _a11_obj->f__1 = l15;
                            t1 = (void*) _a11_obj;
                            l16 = ((vader_struct___Tuple_1150_t*) t1)->f__1;
                            t2 = (l13 + INT64_C(1));
                            l13 = (size_t) (int64_t) t2;
                            vader_comptime_observe(l1, l16);
                            goto loop_68;
                        }
                    }
                }
                l17 = ((vader_struct_vader_typecheck_TypedProgram_t*) l8)->f_expr_types;
                l18 = ((vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l17)->f_ekeys;
                l19 = ((vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l17)->f_evals;
                l20 = ((vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l17)->f_size;
                l21 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_110: {
                        if ((l21 >= l20)) {
                        } else {
                            vader_array_t* _a12_slotarr = ((vader_array_t*) l18);
                            if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                            if ((size_t) l21 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = ((int64_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l21];
                            l22 = (size_t) (int64_t) t2;
                            vader_array_t* _a13_slotarr = ((vader_array_t*) l19);
                            if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                            if ((size_t) l21 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                            l23 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l21);
                            vader_struct___Tuple_1213_t* _a14_obj = (vader_struct___Tuple_1213_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1213_t));
                            vader_obj_header_init(_a14_obj, 213u);
                            _a14_obj->f__0 = l22;
                            _a14_obj->f__1 = l23;
                            t1 = (void*) _a14_obj;
                            l24 = ((vader_struct___Tuple_1213_t*) t1)->f__1;
                            t2 = (l21 + INT64_C(1));
                            l21 = (size_t) (int64_t) t2;
                            vader_comptime_observe(l1, l24);
                            goto loop_110;
                        }
                    }
                }
                l25 = ((vader_struct_vader_typecheck_TypedProgram_t*) l8)->f_local_types;
                l26 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l25)->f_ekeys;
                l27 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l25)->f_evals;
                l28 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l25)->f_size;
                l29 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_152: {
                        if ((l29 >= l28)) {
                        } else {
                            vader_array_t* _a15_slotarr = ((vader_array_t*) l26);
                            if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                            if ((size_t) l29 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = ((int64_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l29];
                            l30 = (uint64_t) (int64_t) t2;
                            vader_array_t* _a16_slotarr = ((vader_array_t*) l27);
                            if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                            if ((size_t) l29 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                            l31 = vader_array_ref_load_box(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l29);
                            vader_struct___Tuple_1214_t* _a17_obj = (vader_struct___Tuple_1214_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1214_t));
                            vader_obj_header_init(_a17_obj, 214u);
                            _a17_obj->f__0 = l30;
                            _a17_obj->f__1 = l31;
                            t1 = (void*) _a17_obj;
                            l32 = ((vader_struct___Tuple_1214_t*) t1)->f__1;
                            t2 = (l29 + INT64_C(1));
                            l29 = (size_t) (int64_t) t2;
                            vader_comptime_observe(l1, l32);
                            goto loop_152;
                        }
                    }
                }
                l33 = ((vader_struct_vader_typecheck_TypedProgram_t*) l8)->f_param_types;
                l34 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l33)->f_ekeys;
                l35 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l33)->f_evals;
                l36 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l33)->f_size;
                l37 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_194: {
                        if ((l37 >= l36)) {
                        } else {
                            vader_array_t* _a18_slotarr = ((vader_array_t*) l34);
                            if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                            if ((size_t) l37 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = ((int64_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l37];
                            l38 = (uint64_t) (int64_t) t2;
                            vader_array_t* _a19_slotarr = ((vader_array_t*) l35);
                            if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                            if ((size_t) l37 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                            l39 = vader_array_ref_load_box(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l37);
                            vader_struct___Tuple_1214_t* _a20_obj = (vader_struct___Tuple_1214_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1214_t));
                            vader_obj_header_init(_a20_obj, 214u);
                            _a20_obj->f__0 = l38;
                            _a20_obj->f__1 = l39;
                            t1 = (void*) _a20_obj;
                            l40 = ((vader_struct___Tuple_1214_t*) t1)->f__1;
                            t2 = (l37 + INT64_C(1));
                            l37 = (size_t) (int64_t) t2;
                            vader_comptime_observe(l1, l40);
                            goto loop_194;
                        }
                    }
                }
                l41 = ((vader_struct_vader_typecheck_TypedProgram_t*) l8)->f_type_expr_types;
                l42 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l41)->f_ekeys;
                l43 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l41)->f_evals;
                l44 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l41)->f_size;
                l45 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_236: {
                        if ((l45 >= l44)) {
                        } else {
                            vader_array_t* _a21_slotarr = ((vader_array_t*) l42);
                            if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                            if ((size_t) l45 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = ((int64_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l45];
                            l46 = (uint64_t) (int64_t) t2;
                            vader_array_t* _a22_slotarr = ((vader_array_t*) l43);
                            if (_a22_slotarr->buf != NULL && _a22_slotarr->buf->header.forward != NULL) { _a22_slotarr->buf = vader_array_buf_forward(_a22_slotarr->buf); }
                            if ((size_t) l45 >= _a22_slotarr->length) { vader_trap("array index out of bounds"); }
                            l47 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l45);
                            vader_struct___Tuple_1214_t* _a23_obj = (vader_struct___Tuple_1214_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1214_t));
                            vader_obj_header_init(_a23_obj, 214u);
                            _a23_obj->f__0 = l46;
                            _a23_obj->f__1 = l47;
                            t1 = (void*) _a23_obj;
                            l48 = ((vader_struct___Tuple_1214_t*) t1)->f__1;
                            t2 = (l45 + INT64_C(1));
                            l45 = (size_t) (int64_t) t2;
                            vader_comptime_observe(l1, l48);
                            goto loop_236;
                        }
                    }
                }
                l49 = ((vader_struct_vader_typecheck_TypedProgram_t*) l8)->f_impl_methods;
                l50 = ((vader_struct_std_collections_MutableMap__string__ImplMethod_t*) l49)->f_ekeys;
                l51 = ((vader_struct_std_collections_MutableMap__string__ImplMethod_t*) l49)->f_evals;
                l52 = ((vader_struct_std_collections_MutableMap__string__ImplMethod_t*) l49)->f_size;
                l53 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_278: {
                        if ((l53 >= l52)) {
                        } else {
                            vader_array_t* _a24_slotarr = ((vader_array_t*) l50);
                            if (_a24_slotarr->buf != NULL && _a24_slotarr->buf->header.forward != NULL) { _a24_slotarr->buf = vader_array_buf_forward(_a24_slotarr->buf); }
                            if ((size_t) l53 >= _a24_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = vader_array_box_slots(_a24_slotarr->buf)[_a24_slotarr->offset + (size_t) l53];
                            l54 = t0.payload.s;
                            vader_array_t* _a25_slotarr = ((vader_array_t*) l51);
                            if (_a25_slotarr->buf != NULL && _a25_slotarr->buf->header.forward != NULL) { _a25_slotarr->buf = vader_array_buf_forward(_a25_slotarr->buf); }
                            if ((size_t) l53 >= _a25_slotarr->length) { vader_trap("array index out of bounds"); }
                            l55 = vader_array_ref_load_obj(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l53);
                            vader_struct___Tuple_1216_t* _a26_obj = (vader_struct___Tuple_1216_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1216_t));
                            vader_obj_header_init(_a26_obj, 215u);
                            _a26_obj->f__0 = l54;
                            _a26_obj->f__1 = l55;
                            t1 = (void*) _a26_obj;
                            l56 = ((vader_struct___Tuple_1216_t*) t1)->f__1;
                            t2 = (l53 + INT64_C(1));
                            l53 = (size_t) (int64_t) t2;
                            l57 = ((vader_struct_vader_typecheck_ImplMethod_t*) l56)->f_ty;
                            vader_comptime_observe(l1, l57);
                            goto loop_278;
                        }
                    }
                }
                l58 = ((vader_struct_vader_typecheck_TypedProgram_t*) l8)->f_impl_method_decl_types;
                l59 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l58)->f_ekeys;
                l60 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l58)->f_evals;
                l61 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l58)->f_size;
                l62 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_323: {
                        if ((l62 >= l61)) {
                        } else {
                            vader_array_t* _a27_slotarr = ((vader_array_t*) l59);
                            if (_a27_slotarr->buf != NULL && _a27_slotarr->buf->header.forward != NULL) { _a27_slotarr->buf = vader_array_buf_forward(_a27_slotarr->buf); }
                            if ((size_t) l62 >= _a27_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = ((int64_t*) _a27_slotarr->buf->slots)[_a27_slotarr->offset + (size_t) l62];
                            l63 = (uint64_t) (int64_t) t2;
                            vader_array_t* _a28_slotarr = ((vader_array_t*) l60);
                            if (_a28_slotarr->buf != NULL && _a28_slotarr->buf->header.forward != NULL) { _a28_slotarr->buf = vader_array_buf_forward(_a28_slotarr->buf); }
                            if ((size_t) l62 >= _a28_slotarr->length) { vader_trap("array index out of bounds"); }
                            l64 = vader_array_ref_load_box(_a28_slotarr->buf, _a28_slotarr->offset + (size_t) l62);
                            vader_struct___Tuple_1214_t* _a29_obj = (vader_struct___Tuple_1214_t*) vader_gc_alloc(sizeof(vader_struct___Tuple_1214_t));
                            vader_obj_header_init(_a29_obj, 214u);
                            _a29_obj->f__0 = l63;
                            _a29_obj->f__1 = l64;
                            t1 = (void*) _a29_obj;
                            l65 = ((vader_struct___Tuple_1214_t*) t1)->f__1;
                            t2 = (l62 + INT64_C(1));
                            l62 = (size_t) (int64_t) t2;
                            vader_comptime_observe(l1, l65);
                            goto loop_323;
                        }
                    }
                }
                goto loop_32;
            }
        }
    }
    t1 = vader_comptime_sorted_instances(l1);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_comptime_has_comptime_decorator(void* l0) {
    void* l1;
    size_t l2, l3;
    void* t0;
    vader_string_t t1;
    int64_t t2;
    l1 = ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_decorators;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l3 < l2)) {
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                t1 = ((vader_struct_toolchain_ast_Decorator_t*) t0)->f_name;
                if (t1 == 1340u) {
                    return true;
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_7;
            } else {
            }
        }
    }
    return false;
}

static vader_string_t vader_comptime_instance_args_key(void* l0) {
    vader_string_t l1, l4;
    size_t l2, l3;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = 0u;
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l3 < l2)) {
                if ((l3 > INT64_C(0))) {
                    l1 = concat_2(l1, 375u);
                } else {
                }
                vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l3 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
                l4 = vader_comptime_canonical_type_key(t0);
                l1 = concat_2(l1, l4);
                t1 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t1;
                goto loop_8;
            } else {
            }
        }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_comptime_int_compare(int64_t l0, int64_t l1, uint8_t l2) {
    if (l2 == INT32_C(0)) {
        return l0 == l1;
    }
    if (l2 == INT32_C(1)) {
        return l0 != l1;
    }
    if (l2 == INT32_C(2)) {
        return (l0 < l1);
    }
    if (l2 == INT32_C(3)) {
        return (l0 <= l1);
    }
    if (l2 == INT32_C(4)) {
        return (l0 > l1);
    }
    if (l2 == INT32_C(5)) {
        return (l0 >= l1);
    }
    vader_unreachable("unreachable return in vader_comptime$int_compare");
}

static void* vader_comptime_int_div_check(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 682u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        if (t1 == INT64_C(0)) {
            t0 = vader_comptime_division_by_zero(l0, 438u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_comptime_arithmetic(l0, l1, l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_arithmetic(l0, l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_int_mod_check(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 682u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        if (t1 == INT64_C(0)) {
            t0 = vader_comptime_division_by_zero(l0, 276u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_comptime_arithmetic_int(l0, l1, l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_arithmetic_int(l0, l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_int_val(int64_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_IntValue_t* _a0_obj = (vader_struct_vader_comptime_IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_IntValue_t));
    vader_obj_header_init(_a0_obj, 682u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = 1602u;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_comptime_int_val_typed(int64_t l0, vader_string_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_IntValue_t* _a0_obj = (vader_struct_vader_comptime_IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_IntValue_t));
    vader_obj_header_init(_a0_obj, 682u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_interp_value(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    size_t l3;
    int64_t l4;
    bool l5;
    vader_string_t t0;
    void* t1 = NULL;
    double t2;
    uint32_t t3;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 682u) {
        l1 = l0.payload.obj;
        l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(20));
        l3 = (size_t) (int64_t) INT64_C(0);
        l4 = ((vader_struct_vader_comptime_IntValue_t*) l1)->f_value;
        l3 = std_core_write_int(l2, l3, l4);
        t0 = std_core_finish_buffer(l2, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 679u) {
        t1 = l0.payload.obj;
        t2 = ((vader_struct_vader_comptime_FloatValue_t*) t1)->f_value;
        t0 = std_core_format_f64(t2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 672u) {
        l1 = l0.payload.obj;
        l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(5));
        l3 = (size_t) (int64_t) INT64_C(0);
        l5 = ((vader_struct_vader_comptime_BoolValue_t*) l1)->f_value;
        l3 = std_core_write_bool(l2, l3, l5);
        t0 = std_core_finish_buffer(l2, l3);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 687u) {
        t1 = l0.payload.obj;
        t0 = ((vader_struct_vader_comptime_StringValue_t*) t1)->f_value;
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 673u) {
        t1 = l0.payload.obj;
        t3 = ((vader_struct_vader_comptime_CharValue_t*) t1)->f_value;
        t1 = std_core_utf8_encode(((uint32_t) (uint32_t) t3));
        t0 = vader_host_std_core_bytes_to_string(t1);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 686u) {
        { vader_gc_top = gc_frame.prev; return 1862u; }
    }
    if (l0.tag == 691u) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    if (l0.tag == 671u) {
        t1 = l0.payload.obj;
        t0 = vader_comptime_display_value(vader_ref_box(t1));
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 688u) {
        t1 = l0.payload.obj;
        t0 = vader_comptime_display_value(vader_ref_box(t1));
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 689u) {
        t1 = l0.payload.obj;
        t0 = vader_comptime_display_value(vader_ref_box(t1));
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_unreachable("unreachable return in vader_comptime$interp_value");
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_intrinsic_align_of(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 1140u, (size_t) (int64_t) INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1141u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_comptime_byte_align(l2);
    t2 = vader_comptime_int_val_typed(t3, 2292u);
    t1 = vader_comptime_ok(t2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_intrinsic_field_count(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 1539u, (size_t) (int64_t) INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1540u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_comptime_type_field_count(l2, l1);
    t2 = vader_comptime_int_val_typed(t3, 2292u);
    t1 = vader_comptime_ok(t2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_intrinsic_field_index(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l7 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    int32_t l6;
    size_t l8, l9;
    vader_string_t l10, l11;
    size_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l7, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(2)) {
        t1 = vader_comptime_arg_count_error(l0, 1541u, (size_t) (int64_t) INT64_C(2));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1544u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) INT32_C(1) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(1));
    l3 = vader_comptime_static_string_arg(t2);
    if (l3.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1543u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 918u) {
        l4 = l2.payload.obj;
        l5 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_struct_decls;
        l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l4)->f_symbol)->f_id;
        l7 = std_collections_get__i32__Any(l5, l6);
        if (l7.tag == 458u) {
            l4 = l7.payload.obj;
            l8 = ((vader_array_t*) ((vader_struct_toolchain_ast_StructDecl_t*) l4)->f_fields)->length;
            l9 = (size_t) (int64_t) INT64_C(0);
            {
                loop_64: {
                    if ((l9 < l8)) {
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StructDecl_t*) l4)->f_fields);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                        l10 = ((vader_struct_toolchain_ast_StructField_t*) t1)->f_name;
                        l11 = l3.payload.s;
                        if (l10 == l11) {
                            t2 = vader_comptime_int_val_typed(((int64_t) (size_t) l9), 2292u);
                            t1 = vader_comptime_ok(t2);
                            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        t3 = (l9 + INT64_C(1));
                        l9 = (size_t) (int64_t) t3;
                        goto loop_64;
                    } else {
                    }
                }
            }
            t1 = l2.payload.obj;
            l10 = vader_types_display_type(vader_ref_box(t1));
            l11 = l3.payload.s;
            l10 = concat_5(1542u, l10, 945u, l11, 915u);
            t1 = vader_comptime_arg_error(l0, l10);
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = l2.payload.obj;
        l10 = vader_types_display_type(vader_ref_box(t1));
        l10 = concat_3(1545u, l10, 987u);
        t1 = vader_comptime_arg_error(l0, l10);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = vader_types_display_type(l2);
    l10 = concat_3(1542u, l10, 968u);
    t1 = vader_comptime_arg_error(l0, l10);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_intrinsic_size_of(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 1964u, (size_t) (int64_t) INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1966u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_comptime_byte_size(l2);
    t2 = vader_comptime_int_val_typed(t3, 2292u);
    t1 = vader_comptime_ok(t2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_intrinsic_type_kind(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3;
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 2187u, (size_t) (int64_t) INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 2188u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_comptime_type_kind_label(l2);
    t2 = vader_comptime_string_val(t3);
    t1 = vader_comptime_ok(t2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_intrinsic_type_name(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3;
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 2189u, (size_t) (int64_t) INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 2190u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_types_display_type_key(l2);
    t2 = vader_comptime_string_val(t3);
    t1 = vader_comptime_ok(t2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_intrinsic_variant_count(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 2385u, (size_t) (int64_t) INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 2386u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_comptime_type_variant_count(l2);
    t2 = vader_comptime_int_val_typed(t3, 2292u);
    t1 = vader_comptime_ok(t2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_comptime_is_concrete_enough(vader_box_t l0) {
    if ((l0.tag == 911u || l0.tag == 912u || l0.tag == 913u || l0.tag == 917u || l0.tag == 924u)) {
        return false;
    }
    return true;
}

static bool vader_comptime_is_primitive_int_name(vader_string_t l0) {
    bool t0;
    t0 = vader_types_is_int_name(l0);
    return t0;
}

static bool vader_comptime_is_resolved(vader_box_t l0) {
    if (l0.tag == 924u) {
        return false;
    }
    return true;
}

static bool vader_comptime_is_type_symbol_kind(int32_t l0) {
    bool l1;
    if (l0 == INT32_C(1)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(2);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(3);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(5);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(12);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(9);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = false;
    }
    return l1;
}

static vader_box_t vader_comptime_lookup_module_decls(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    size_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = std_collections_get__string__Any(((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules, l1);
    if (l3.tag == 0u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l2 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l2)->f_module)->f_files;
    t1 = ((vader_array_t*) l2)->length;
    if (t1 == INT64_C(0)) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_resolver_concat_file_decls(l2);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_comptime_mangle_type_arg(vader_box_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_string_t t1, t2;
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_types_strip_distinct(l0);
    t1 = vader_types_display_type_key(t0);
    t2 = vader_comptime_sanitise_ident(t1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_mask_shift_amount(vader_box_t l0, vader_string_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_string_t l5;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    void** gc_raw_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 682u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_comptime_IntValue_t*) l2)->f_value;
        l4 = vader_comptime_shift_amount_mask(l1);
        l3 = (l3 & l4);
        l5 = ((vader_struct_vader_comptime_IntValue_t*) l2)->f_type_name;
        t0 = vader_comptime_int_val_typed(l3, l5);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_new_evaluated_program(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 165u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 172u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 165u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 281u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_struct_vader_comptime_EvaluatedProgram_t* _a4_obj = (vader_struct_vader_comptime_EvaluatedProgram_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvaluatedProgram_t));
    vader_obj_header_init(_a4_obj, 677u);
    _a4_obj->f_typed = l0;
    _a4_obj->f_comptime_decls = l1;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_new_evaluated_project(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 162u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(15u, 0u, 0u, 172u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 165u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 318u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 165u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(15u, 0u, 0u, 172u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 165u);
    l4 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a7_obj, 281u);
    _a7_obj->f_ekeys = l2;
    _a7_obj->f_evals = l3;
    _a7_obj->f_index = l4;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(14u, 0u, 4u, 171u);
    l3 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(8u, 0u, 0u, 162u);
    l4 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 165u);
    l5 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__usize__string_t* _a11_obj = (vader_struct_std_collections_MutableMap__usize__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__string_t));
    vader_obj_header_init(_a11_obj, 374u);
    _a11_obj->f_ekeys = l3;
    _a11_obj->f_evals = l4;
    _a11_obj->f_index = l5;
    _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(48u, 0u, 13u, 680u);
    l4 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(49u, 0u, 13u, 690u);
    l5 = (void*) _a13_arr;
    vader_struct_vader_comptime_EvaluatedProject_t* _a14_obj = (vader_struct_vader_comptime_EvaluatedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvaluatedProject_t));
    vader_obj_header_init(_a14_obj, 678u);
    _a14_obj->f_typed = l0;
    _a14_obj->f_modules = l1;
    _a14_obj->f_file_baked_consts = l2;
    _a14_obj->f_file_exprs = l3;
    _a14_obj->f_instances = l4;
    _a14_obj->f_vm_required = l5;
    t0 = (void*) _a14_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_normalize_int_result(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    int64_t l3;
    vader_string_t l4;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_comptime_EvalResult_t*) l0)->f_value.tag == 682u) {
        l2 = ((vader_struct_vader_comptime_EvalResult_t*) l0)->f_value.payload.obj;
        t0 = ((vader_struct_vader_comptime_IntValue_t*) l2)->f_value;
        l3 = vader_comptime_wrap_to_width(t0, l1);
        l4 = ((vader_struct_vader_comptime_IntValue_t*) l2)->f_type_name;
        t1 = vader_comptime_int_val_typed(l3, l4);
        t2 = vader_comptime_ok(t1);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_observe(void* l0, vader_box_t l1) {
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_comptime_walk_type(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_ok(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_EvalResult_t* _a0_obj = (vader_struct_vader_comptime_EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvalResult_t));
    vader_obj_header_init(_a0_obj, 676u);
    _a0_obj->f_value = l0;
    _a0_obj->f_diag = vader_box_obj(0u, NULL);
    _a0_obj->f_vm_required = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

int64_t vader_comptime_op_add(int64_t l0, int64_t l1) {
    return (l0 + l1);
}

bool vader_comptime_op_and(bool l0, bool l1) {
    bool l2;
    if (l0) {
        l2 = l1;
    } else {
        l2 = false;
    }
    return l2;
}

int64_t vader_comptime_op_bit_and(int64_t l0, int64_t l1) {
    return (l0 & l1);
}

int64_t vader_comptime_op_bit_or(int64_t l0, int64_t l1) {
    return (l0 | l1);
}

int64_t vader_comptime_op_bit_xor(int64_t l0, int64_t l1) {
    return (l0 ^ l1);
}

int64_t vader_comptime_op_div(int64_t l0, int64_t l1) {
    int64_t t0;
    t0 = vader_div_i64(l0, l1);
    return t0;
}

int64_t vader_comptime_op_mod(int64_t l0, int64_t l1) {
    int64_t t0;
    t0 = vader_mod_i64(l0, l1);
    return t0;
}

int64_t vader_comptime_op_mul(int64_t l0, int64_t l1) {
    return (l0 * l1);
}

bool vader_comptime_op_or(bool l0, bool l1) {
    bool l2;
    if (l0) {
        l2 = true;
    } else {
        l2 = l1;
    }
    return l2;
}

int64_t vader_comptime_op_shl(int64_t l0, int64_t l1) {
    return (l0 << l1);
}

int64_t vader_comptime_op_shr(int64_t l0, int64_t l1) {
    return (l0 >> l1);
}

int64_t vader_comptime_op_sub(int64_t l0, int64_t l1) {
    return (l0 - l1);
}

static void vader_comptime_populate_deps(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    size_t l3, l4, l5;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null();
    int32_t l11;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l7, &l9 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l6, &l8, &l10, &l12, &l13 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_7: {
            if ((l4 < l3)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
                l5 = (size_t) (int64_t) t0;
                l7 = std_collections_get__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_id, l5);
                if (l7.tag == 0u) {
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_7;
                }
                l6 = l7.payload.obj;
                l9 = vader_typecheck_lookup_const_symbol(((vader_struct_vader_comptime_NodeRecord_t*) l6)->f_decl, l1);
                if (l9.tag == 0u) {
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_7;
                }
                l8 = l9.payload.obj;
                l10 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_symbol;
                l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l8)->f_id;
                std_collections_put__i32__usize(l10, l11, l5);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_7;
            } else {
            }
        }
    }
    l2 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_71: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l5 = (size_t) (int64_t) t0;
                l7 = std_collections_get__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_id, l5);
                if (l7.tag == 0u) {
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_71;
                }
                l6 = l7.payload.obj;
                vader_array_t* _a2_arr = vader_array_new(14u, 0u, 4u, 171u);
                l8 = (void*) _a2_arr;
                vader_array_t* _a3_arr = vader_array_new(6u, 0u, 12u, 160u);
                l10 = (void*) _a3_arr;
                vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 165u);
                l12 = (void*) _a4_arr;
                vader_struct_std_collections_MutableMap__usize__bool_t* _a5_obj = (vader_struct_std_collections_MutableMap__usize__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__bool_t));
                vader_obj_header_init(_a5_obj, 372u);
                _a5_obj->f_ekeys = l8;
                _a5_obj->f_evals = l10;
                _a5_obj->f_index = l12;
                _a5_obj->f_mask = (size_t) (int64_t) INT64_C(0);
                _a5_obj->f_size = (size_t) (int64_t) INT64_C(0);
                _a5_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
                l13 = (void*) _a5_obj;
                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l6)->f_decl)->f_value, l1, l0, l13, l6);
                std_collections_put__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_id, l5, vader_ref_box(l6));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_71;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_read_relative_file(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_string_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_string_starts_with(l0, 438u);
    if (t0) {
        l2 = l0;
    } else {
        if (l1 == 0u) {
            l2 = l0;
        } else {
            l2 = concat_3(l1, 438u, l0);
        }
    }
    l3 = std_io_read_file_string(l2);
    if (l3.tag == 162u) {
        t1 = l3.payload.s;
        t2 = vader_box_string(162u, t1);
        { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_render_array(void* l0) {
    void* l1 = NULL;
    void* l7 = NULL;
    size_t l2, l3, l5;
    bool l4;
    vader_string_t l6;
    uint64_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 162u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 386u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string_builder_append_char(l1, 91u);
    l2 = ((vader_array_t*) ((vader_struct_vader_comptime_ArrayValue_t*) l0)->f_elements)->length;
    t1 = ((int64_t) (int32_t) INT32_C(16));
    l3 = (size_t) (int64_t) t1;
    l4 = (l2 > l3);
    if (l4) {
        t1 = ((int64_t) (int32_t) INT32_C(8));
        l3 = (size_t) (int64_t) t1;
    } else {
        l3 = l2;
    }
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_26: {
            if ((l5 < l3)) {
                if ((l5 > INT64_C(0))) {
                    std_string_builder_append(l1, 376u);
                } else {
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_comptime_ArrayValue_t*) l0)->f_elements);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                l6 = vader_comptime_display_value(t2);
                std_string_builder_append(l1, l6);
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_26;
            } else {
            }
        }
    }
    if (l4) {
        l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(35));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l7, l3, 381u);
        t1 = ((int64_t) (size_t) l2);
        l8 = (uint64_t) (int64_t) t1;
        l3 = std_core_write_unsigned(l7, l3, l8);
        l3 = std_core_write_string_at(l7, l3, 103u);
        l6 = std_core_finish_buffer(l7, l3);
        std_string_builder_append(l1, l6);
    } else {
    }
    std_string_builder_append_char(l1, 93u);
    t3 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_render_struct(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_string_t l2, l9;
    size_t l5, l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3;
    vader_box_t* gc_roots[3] = { &l7, &l8, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 162u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 386u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = ((vader_struct_vader_comptime_StructValue_t*) l0)->f_type_name;
    std_string_builder_append(l1, l2);
    std_string_builder_append(l1, 164u);
    l3 = std_collections_keys__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue(((vader_struct_vader_comptime_StructValue_t*) l0)->f_fields);
    vader_struct___lambda_env_5362_t* _a2_obj = (vader_struct___lambda_env_5362_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_5362_t));
    vader_obj_header_init(_a2_obj, 271u);
    t0 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 136u);
    _a3_closure->code = (void*) &vader_fn_lift_1074;
    _a3_closure->env = t0;
    l4 = (void*) _a3_closure;
    l3 = std_sort_sort__string(l3, l4);
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_27: {
            if ((l6 < l5)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l6];
                l2 = t1.payload.s;
                l8 = std_collections_get__string__Any(((vader_struct_vader_comptime_StructValue_t*) l0)->f_fields, l2);
                if (l8.tag == 0u) {
                    t2 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    goto loop_27;
                }
                l7 = l8;
                if ((l6 > INT64_C(0))) {
                    std_string_builder_append(l1, 376u);
                } else {
                }
                std_string_builder_append_char(l1, 46u);
                std_string_builder_append(l1, l2);
                std_string_builder_append(l1, 58u);
                l9 = vader_comptime_display_value(l7);
                std_string_builder_append(l1, l9);
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_27;
            } else {
            }
        }
    }
    std_string_builder_append(l1, 225u);
    t3 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_resolve_type_arg(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l4, &t0 };
    void** gc_raw_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved;
    l3 = vader_comptime_diag_sink();
    l4 = vader_typecheck_type_from_expr(l0, l2, l3);
    if (l4.tag == 924u) {
        t0 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_resolved_int_name(void* l0, size_t l1) {
    vader_box_t l2;
    void* t0;
    vader_string_t t1;
    l2 = std_collections_get__usize__Any(((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l0)->f_typed)->f_expr_types, l1);
    if (l2.tag == 916u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        return t1;
    }
    if (l2.tag == 913u) {
        return 1602u;
    }
    return 0u;
}

static vader_string_t vader_comptime_sanitise_ident(vader_string_t l0) {
    void* l1 = NULL;
    size_t l2, l3;
    uint8_t l4;
    uint32_t l5;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_string_t t3;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 162u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 386u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_9: {
            if ((l3 < l2)) {
                l4 = vader_host_std_core_byte_at(l0, l3);
                t1 = vader_text_is_ident_byte(l4);
                if (t1) {
                    l5 = ((uint32_t) (int32_t) ((int32_t) (uint8_t) l4));
                    std_string_builder_append_char(l1, l5);
                } else {
                    std_string_builder_append_char(l1, 95u);
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_9;
            } else {
            }
        }
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int64_t vader_comptime_shift_amount_mask(vader_string_t l0) {
    bool l1;
    int64_t l2;
    if (l0 == 1646u) {
        l1 = true;
    } else {
        l1 = l0 == 2248u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1601u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2229u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1602u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2230u;
    }
    if (l1) {
        l2 = INT64_C(31);
    } else {
        l2 = INT64_C(63);
    }
    return l2;
}

static int64_t vader_comptime_sign_extend_32(int64_t l0) {
    int64_t l1;
    l1 = (l0 & INT64_C(4294967295));
    if ((l1 & INT64_C(2147483648)) != INT64_C(0)) {
        return (l1 - INT64_C(4294967296));
    }
    return l1;
}

static void* vader_comptime_sort_comptime_decls(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_comptime_collect_nodes(l0);
    vader_comptime_populate_deps(l2, l1);
    t0 = vader_comptime_topo_sort(l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_sorted_instances(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_order;
    vader_struct___lambda_env_2245_t* _a0_obj = (vader_struct___lambda_env_2245_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_2245_t));
    vader_obj_header_init(_a0_obj, 244u);
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 146u);
    _a1_closure->code = (void*) &vader_fn_lift_965;
    _a1_closure->env = t0;
    l2 = (void*) _a1_closure;
    t0 = std_sort_sort__GenericInstance(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_comptime_span_of(vader_box_t l0) {
    void* t0;
    if (l0.tag == 431u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_IntLitExpr_t*) t0)->f_span;
    }
    if (l0.tag == 443u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_span;
    }
    if (l0.tag == 415u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_FloatLitExpr_t*) t0)->f_span;
    }
    if (l0.tag == 394u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_BoolLitExpr_t*) t0)->f_span;
    }
    if (l0.tag == 444u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_NullLitExpr_t*) t0)->f_span;
    }
    if (l0.tag == 399u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_CharLitExpr_t*) t0)->f_span;
    }
    if (l0.tag == 455u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_span;
    }
    if (l0.tag == 421u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span;
    }
    if (l0.tag == 397u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_span;
    }
    if (l0.tag == 414u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_span;
    }
    if (l0.tag == 429u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_span;
    }
    if (l0.tag == 470u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_span;
    }
    if (l0.tag == 391u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_span;
    }
    if (l0.tag == 424u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_span;
    }
    if (l0.tag == 438u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_span;
    }
    if (l0.tag == 393u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_BlockExpr_t*) t0)->f_span;
    }
    if (l0.tag == 434u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_span;
    }
    if (l0.tag == 460u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_span;
    }
    if (l0.tag == 453u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_span;
    }
    if (l0.tag == 449u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_span;
    }
    if (l0.tag == 390u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_span;
    }
    if (l0.tag == 398u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_span;
    }
    if (l0.tag == 420u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_span;
    }
    if (l0.tag == 432u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_span;
    }
    if (l0.tag == 409u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_span;
    }
    if (l0.tag == 418u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_span;
    }
    if (l0.tag == 387u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
    }
    if (l0.tag == 440u) {
        t0 = l0.payload.obj;
        return ((vader_struct_toolchain_ast_MutableTypeExpr_t*) t0)->f_span;
    }
    vader_unreachable("unreachable return in vader_comptime$span_of");
}

static vader_box_t vader_comptime_static_string_arg(vader_box_t l0) {
    void* l1;
    size_t t0;
    vader_box_t t1;
    void* t2;
    vader_string_t t3;
    if (l0.tag == 455u) {
        l1 = l0.payload.obj;
        t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) l1)->f_parts)->length;
        if (t0 == INT64_C(1)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) l1)->f_parts);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
            if (t1.tag == 457u) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) l1)->f_parts);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t1 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                t2 = t1.payload.obj;
                t3 = ((vader_struct_toolchain_ast_StringLitText_t*) t2)->f_value;
                t1 = vader_box_string(162u, t3);
                return t1;
            }
            t1 = vader_box_obj(0u, NULL);
            return t1;
        }
        t1 = vader_box_obj(0u, NULL);
        return t1;
    }
    t1 = vader_box_obj(0u, NULL);
    return t1;
}

vader_box_t vader_comptime_string_val(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_StringValue_t* _a0_obj = (vader_struct_vader_comptime_StringValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_StringValue_t));
    vader_obj_header_init(_a0_obj, 687u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_comptime_symbol_defines_span(void* l0, void* l1) {
    void* l2;
    size_t l3, l4;
    bool l5;
    vader_string_t l6, l7;
    if (((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_defined_at.tag == 477u) {
        l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_defined_at.payload.obj;
        l3 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l2)->f_start)->f_offset;
        l4 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l1)->f_start)->f_offset;
        if (l3 == l4) {
            l6 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l2)->f_start)->f_file;
            l7 = ((vader_struct_toolchain_span_Position_t*) ((vader_struct_toolchain_span_Span_t*) l1)->f_start)->f_file;
            l5 = l6 == l7;
        } else {
            l5 = false;
        }
        return l5;
    }
    return false;
}

vader_box_t vader_comptime_symbol_for_decl(vader_box_t l0, void* l1) {
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2;
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 416u) {
        t0 = l0.payload.obj;
        t1 = vader_comptime_symbol_for_fn(t0, l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 458u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_name;
        t1 = vader_comptime_symbol_for_kind(t2, INT32_C(1), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 400u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_name;
        t1 = vader_comptime_symbol_for_kind(t2, INT32_C(6), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 410u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_name;
        t1 = vader_comptime_symbol_for_kind(t2, INT32_C(2), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 465u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_name;
        t1 = vader_comptime_symbol_for_kind(t2, INT32_C(3), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 468u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_name;
        t1 = vader_comptime_symbol_for_kind(t2, INT32_C(5), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 425u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l0.tag == 388u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l0.tag == 426u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_unreachable("unreachable return in vader_comptime$symbol_for_decl");
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_symbol_for_fn(void* l0, void* l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l3;
    vader_box_t l4 = vader_box_null();
    size_t l5, l6;
    vader_string_t t0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    int64_t t3;
    size_t t4;
    void* t5 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l7, &l8, &t5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved)->f_fn_overloads;
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
    l4 = std_collections_get__string__Any(l2, l3);
    if (l4.tag == 0u) {
        t0 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
        t1 = vader_comptime_symbol_for_kind(t0, INT32_C(0), l1);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l4.payload.obj;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l5 = ((vader_array_t*) l2)->length;
    l6 = (size_t) (int64_t) INT64_C(0);
    {
        loop_27: {
            if ((l6 < l5)) {
                if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l7 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                l8 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name_span;
                t2 = vader_comptime_symbol_defines_span(l7, l8);
                if (t2) {
                    { vader_box_t __vret = vader_ref_box(l7); vader_gc_top = gc_frame.prev; return __vret; }
                }
                t3 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t3;
                goto loop_27;
            } else {
            }
        }
    }
    t4 = ((vader_array_t*) l2)->length;
    if ((t4 > INT64_C(0))) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
        t5 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
        { vader_box_t __vret = vader_ref_box(t5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_symbol_for_kind(vader_string_t l0, int32_t l1, void* l2) {
    void* l3;
    void* l6;
    size_t l4, l5;
    bool l7;
    vader_string_t t0;
    int64_t t1;
    vader_box_t t2;
    l3 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_resolved)->f_symbols;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    l4 = ((vader_array_t*) l3)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l5 < l4)) {
                if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l6)->f_name;
                if (t0 == l0) {
                    l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l6)->f_kind == l1;
                } else {
                    l7 = false;
                }
                if (l7) {
                    return vader_ref_box(l6);
                }
                t1 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t1;
                goto loop_8;
            } else {
            }
        }
    }
    t2 = vader_box_obj(0u, NULL);
    return t2;
}

static void* vader_comptime_topo_sort(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    size_t l7, l8, l9;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(20u, 0u, 13u, 400u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(50u, 0u, 13u, 693u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(14u, 0u, 4u, 171u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 165u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 165u);
    l5 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__usize__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__usize__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__i32_t));
    vader_obj_header_init(_a5_obj, 373u);
    _a5_obj->f_ekeys = l3;
    _a5_obj->f_evals = l4;
    _a5_obj->f_index = l5;
    _a5_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(14u, 0u, 4u, 171u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(6u, 0u, 12u, 160u);
    l5 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 165u);
    l6 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__usize__bool_t* _a9_obj = (vader_struct_std_collections_MutableMap__usize__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__bool_t));
    vader_obj_header_init(_a9_obj, 372u);
    _a9_obj->f_ekeys = l4;
    _a9_obj->f_evals = l5;
    _a9_obj->f_index = l6;
    _a9_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a9_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a9_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l4 = (void*) _a9_obj;
    l5 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_39: {
            if ((l8 < l7)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
                if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                if ((size_t) l8 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l8];
                l9 = (size_t) (int64_t) t0;
                std_collections_put__usize__i32(l3, l9, INT32_C(0));
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                goto loop_39;
            } else {
            }
        }
    }
    vader_array_t* _a11_arr = vader_array_new(14u, 0u, 4u, 171u);
    l5 = (void*) _a11_arr;
    l6 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_70: {
            if ((l8 < l7)) {
                vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
                if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                if ((size_t) l8 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l8];
                vader_comptime_visit((size_t) (int64_t) t0, l0, l3, l4, l5, (size_t) (int64_t) INT64_C(0), l1, l2);
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                goto loop_70;
            } else {
            }
        }
    }
    vader_struct_vader_comptime_ComptimeOrder_t* _a13_obj = (vader_struct_vader_comptime_ComptimeOrder_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeOrder_t));
    vader_obj_header_init(_a13_obj, 675u);
    _a13_obj->f_order = l1;
    _a13_obj->f_cycle_diags = l2;
    t1 = (void*) _a13_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int64_t vader_comptime_type_field_count(vader_box_t l0, void* l1) {
    void* l2;
    void* l3;
    int32_t l4;
    vader_box_t l5;
    void* t0;
    size_t t1;
    if (l0.tag == 918u) {
        l2 = l0.payload.obj;
        l3 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_struct_decls;
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) l2)->f_symbol)->f_id;
        l5 = std_collections_get__i32__Any(l3, l4);
        if (l5.tag == 458u) {
            t0 = l5.payload.obj;
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_fields)->length;
            return ((int64_t) (size_t) t1);
        }
        return INT64_C(0);
    }
    if (l0.tag == 920u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_types_TupleType_t*) t0)->f_elements)->length;
        return ((int64_t) (size_t) t1);
    }
    return INT64_C(0);
}

static vader_box_t vader_comptime_type_from_expr_safe(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved;
    l3 = vader_comptime_diag_sink();
    l4 = vader_typecheck_type_from_expr(vader_ref_box(l0), l2, l3);
    t0 = vader_comptime_is_resolved(l4);
    if (!(t0)) {
        t1 = vader_box_obj(0u, NULL);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_type_kind_label(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (l0.tag == 916u) {
        return 1897u;
    }
    if (l0.tag == 908u) {
        t0 = l0.payload.obj;
        t1 = vader_comptime_type_kind_label(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        return t1;
    }
    if (l0.tag == 918u) {
        return 2106u;
    }
    if (l0.tag == 909u) {
        return 1436u;
    }
    if (l0.tag == 923u) {
        return 2264u;
    }
    if (l0.tag == 907u) {
        return 1161u;
    }
    if (l0.tag == 920u) {
        return 2164u;
    }
    if (l0.tag == 910u) {
        return 1554u;
    }
    if (l0.tag == 919u) {
        return 2156u;
    }
    if (l0.tag == 921u) {
        return 2168u;
    }
    if (l0.tag == 922u) {
        return 2265u;
    }
    if (l0.tag == 917u) {
        return 2265u;
    }
    if (l0.tag == 924u) {
        return 2265u;
    }
    if (l0.tag == 913u) {
        return 2265u;
    }
    if (l0.tag == 911u) {
        return 2265u;
    }
    if (l0.tag == 912u) {
        return 2265u;
    }
    if (l0.tag == 914u) {
        return 2265u;
    }
    if (l0.tag == 906u) {
        return 1155u;
    }
    vader_unreachable("unreachable return in vader_comptime$type_kind_label");
}

static void* vader_comptime_type_mismatch(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span;
    t0 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(6), l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_type_val(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_TypeValue_t* _a0_obj = (vader_struct_vader_comptime_TypeValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_TypeValue_t));
    vader_obj_header_init(_a0_obj, 689u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int64_t vader_comptime_type_variant_count(vader_box_t l0) {
    void* t0;
    size_t t1;
    if (l0.tag == 923u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_types_UnionType_t*) t0)->f_variants)->length;
        return ((int64_t) (size_t) t1);
    }
    if (l0.tag == 909u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_std_collections_MutableMap__string__i64_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_indices)->f_size;
        return ((int64_t) (size_t) t1);
    }
    return INT64_C(0);
}

static void* vader_comptime_unary_bit_not(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    int64_t l3;
    vader_string_t l4;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 682u) {
        l2 = l1.payload.obj;
        t0 = ((vader_struct_vader_comptime_IntValue_t*) l2)->f_value;
        l3 = vader_comptime_bit_not_i64(t0);
        l4 = ((vader_struct_vader_comptime_IntValue_t*) l2)->f_type_name;
        t1 = vader_comptime_int_val_typed(l3, l4);
        t2 = vader_comptime_ok(t1);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_comptime_unary_type_mismatch(l0, 1116u);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_unary_neg(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    int64_t l3;
    vader_string_t l4;
    double l5;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    double t3;
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 682u) {
        l2 = l1.payload.obj;
        t0 = ((vader_struct_vader_comptime_IntValue_t*) l2)->f_value;
        l3 = -(t0);
        l4 = ((vader_struct_vader_comptime_IntValue_t*) l2)->f_type_name;
        t1 = vader_comptime_int_val_typed(l3, l4);
        t2 = vader_comptime_ok(t1);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 679u) {
        l2 = l1.payload.obj;
        t3 = ((vader_struct_vader_comptime_FloatValue_t*) l2)->f_value;
        l5 = -(t3);
        l4 = ((vader_struct_vader_comptime_FloatValue_t*) l2)->f_type_name;
        t1 = vader_comptime_float_val_typed(l5, l4);
        t2 = vader_comptime_ok(t1);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_comptime_unary_type_mismatch(l0, 1040u);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_unary_not(void* l0, vader_box_t l1) {
    void* t0 = NULL;
    void* t2 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 672u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
        if (t1) {
            vader_struct_vader_comptime_BoolValue_t* _a0_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
            vader_obj_header_init(_a0_obj, 672u);
            _a0_obj->f_value = false;
            t0 = (void*) _a0_obj;
            t2 = vader_comptime_ok(vader_ref_box(t0));
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_comptime_BoolValue_t* _a1_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
        vader_obj_header_init(_a1_obj, 672u);
        _a1_obj->f_value = true;
        t0 = (void*) _a1_obj;
        t2 = vader_comptime_ok(vader_ref_box(t0));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_unary_type_mismatch(l0, 1018u);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_unary_type_mismatch(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_span;
    t0 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(6), l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_comptime_uniq(void* l0, vader_string_t l1) {
    int32_t l2;
    vader_string_t l3, l4;
    size_t l5, l7;
    void* l6 = NULL;
    int64_t l8;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_collections_get__string__bool(l0, l1);
    if (t0.tag == 0u) {
        std_collections_put__string__bool(l0, l1, true);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = INT32_C(1);
    {
        loop_15: {
            if ((l2 < INT32_C(1000000))) {
                l4 = l1;
                l5 = vader_host_std_core_byte_len(l4);
                l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l5));
                l7 = (size_t) (int64_t) INT64_C(0);
                l7 = std_core_write_string_at(l6, l7, l4);
                l7 = std_core_write_string_at(l6, l7, 858u);
                l8 = ((int64_t) (int32_t) l2);
                l7 = std_core_write_int(l6, l7, l8);
                l3 = std_core_finish_buffer(l6, l7);
                t0 = std_collections_get__string__bool(l0, l3);
                if (t0.tag == 0u) {
                    std_collections_put__string__bool(l0, l3, true);
                    { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l2 = (l2 + INT32_C(1));
                goto loop_15;
            } else {
            }
        }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_visit(size_t l0, void* l1, void* l2, void* l3, void* l4, size_t l5, void* l6, void* l7) {
    int32_t l8;
    vader_box_t l9 = vader_box_null();
    size_t l10, l12, l13, l14;
    void* l11 = NULL;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t2 };
    void** gc_raw_roots[8] = { &l1, &l2, &l3, &l4, &l6, &l7, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l9 = std_collections_get__usize__i32(l2, l0);
    if (l9.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = ((int32_t) l9.payload.i);
    if (l8 == INT32_C(2)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l8 == INT32_C(1)) {
        vader_comptime_emit_cycle(l0, l4, l5, l1, l3, l7);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_collections_put__usize__i32(l2, l0, INT32_C(1));
    l10 = ((vader_array_t*) l4)->length;
    if ((l5 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5] = (int64_t) (int64_t) (size_t) l0;
    } else {
        vader_array_push_i64((vader_array_t*) l4, (int64_t) (size_t) l0);
    }
    l9 = std_collections_get__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l1)->f_by_id, l0);
    if (!(l9.tag == 0u)) {
        t0 = l9.payload.obj;
        l11 = ((vader_struct_vader_comptime_NodeRecord_t*) t0)->f_dependency_ids;
        l10 = ((vader_array_t*) l11)->length;
        l12 = (size_t) (int64_t) INT64_C(0);
        {
            loop_65: {
                if ((l12 < l10)) {
                    vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
                    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                    if ((size_t) l12 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                    t1 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l12];
                    l13 = (size_t) (int64_t) t1;
                    t1 = (l5 + INT64_C(1));
                    l14 = (size_t) (int64_t) t1;
                    vader_comptime_visit(l13, l1, l2, l3, l4, l14, l6, l7);
                    t1 = (l12 + INT64_C(1));
                    l12 = (size_t) (int64_t) t1;
                    goto loop_65;
                } else {
                }
            }
        }
    } else {
    }
    std_collections_put__usize__i32(l2, l0, INT32_C(2));
    t2 = std_collections_get__usize__bool(l3, l0);
    if (t2.tag == 0u) {
        l9 = std_collections_get__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l1)->f_by_id, l0);
        if (!(l9.tag == 0u)) {
            t0 = l9.payload.obj;
            l11 = ((vader_struct_vader_comptime_NodeRecord_t*) t0)->f_decl;
            vader_array_push((vader_array_t*) l6, vader_ref_box(l11));
        } else {
        }
    } else {
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_vm_required(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(0), l0, l1);
    vader_struct_vader_comptime_EvalResult_t* _a0_obj = (vader_struct_vader_comptime_EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvalResult_t));
    vader_obj_header_init(_a0_obj, 676u);
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    _a0_obj->f_diag = vader_ref_box(l2);
    _a0_obj->f_vm_required = true;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_walk_type(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    bool l3;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null();
    size_t t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l8 };
    void** gc_raw_roots[5] = { &l0, &l2, &l4, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 918u) {
        l2 = l1.payload.obj;
        t0 = ((vader_array_t*) ((vader_struct_vader_types_StructType_t*) l2)->f_args)->length;
        if ((t0 > INT64_C(0))) {
            l3 = vader_comptime_all_concrete_enough(((vader_struct_vader_types_StructType_t*) l2)->f_args);
        } else {
            l3 = false;
        }
        if (l3) {
            l4 = ((vader_struct_vader_types_StructType_t*) l2)->f_symbol;
            l5 = ((vader_struct_vader_types_StructType_t*) l2)->f_args;
            vader_comptime_add(l0, l4, l5);
        } else {
        }
        l2 = ((vader_struct_vader_types_StructType_t*) l2)->f_args;
        l6 = ((vader_array_t*) l2)->length;
        l7 = (size_t) (int64_t) INT64_C(0);
        {
            loop_38: {
                if ((l7 < l6)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l7 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    l8 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
                    vader_comptime_walk_type(l0, l8);
                    t1 = (l7 + INT64_C(1));
                    l7 = (size_t) (int64_t) t1;
                    goto loop_38;
                } else {
                }
            }
        }
    } else {
        if (l1.tag == 909u) {
        } else {
            if (l1.tag == 919u) {
                l2 = l1.payload.obj;
                t0 = ((vader_array_t*) ((vader_struct_vader_types_TraitType_t*) l2)->f_args)->length;
                if ((t0 > INT64_C(0))) {
                    l3 = vader_comptime_all_concrete_enough(((vader_struct_vader_types_TraitType_t*) l2)->f_args);
                } else {
                    l3 = false;
                }
                if (l3) {
                    l4 = ((vader_struct_vader_types_TraitType_t*) l2)->f_symbol;
                    l5 = ((vader_struct_vader_types_TraitType_t*) l2)->f_args;
                    vader_comptime_add(l0, l4, l5);
                } else {
                }
                l2 = ((vader_struct_vader_types_TraitType_t*) l2)->f_args;
                l6 = ((vader_array_t*) l2)->length;
                l7 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_102: {
                        if ((l7 < l6)) {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l7 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
                            vader_comptime_walk_type(l0, l8);
                            t1 = (l7 + INT64_C(1));
                            l7 = (size_t) (int64_t) t1;
                            goto loop_102;
                        } else {
                        }
                    }
                }
            } else {
                if (l1.tag == 907u) {
                    t2 = l1.payload.obj;
                    l8 = ((vader_struct_vader_types_ArrayType_t*) t2)->f_element;
                    vader_comptime_walk_type(l0, l8);
                } else {
                    if (l1.tag == 920u) {
                        t2 = l1.payload.obj;
                        l2 = ((vader_struct_vader_types_TupleType_t*) t2)->f_elements;
                        l6 = ((vader_array_t*) l2)->length;
                        l7 = (size_t) (int64_t) INT64_C(0);
                        {
                            loop_147: {
                                if ((l7 < l6)) {
                                    vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                                    if ((size_t) l7 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                                    l8 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
                                    vader_comptime_walk_type(l0, l8);
                                    t1 = (l7 + INT64_C(1));
                                    l7 = (size_t) (int64_t) t1;
                                    goto loop_147;
                                } else {
                                }
                            }
                        }
                    } else {
                        if (l1.tag == 923u) {
                            t2 = l1.payload.obj;
                            l2 = ((vader_struct_vader_types_UnionType_t*) t2)->f_variants;
                            l6 = ((vader_array_t*) l2)->length;
                            l7 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_181: {
                                    if ((l7 < l6)) {
                                        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                                        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                                        if ((size_t) l7 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l8 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l7);
                                        vader_comptime_walk_type(l0, l8);
                                        t1 = (l7 + INT64_C(1));
                                        l7 = (size_t) (int64_t) t1;
                                        goto loop_181;
                                    } else {
                                    }
                                }
                            }
                        } else {
                            if (l1.tag == 910u) {
                                l2 = l1.payload.obj;
                                l4 = ((vader_struct_vader_types_FnType_t*) l2)->f_params;
                                l6 = ((vader_array_t*) l4)->length;
                                l7 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_216: {
                                        if ((l7 < l6)) {
                                            vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
                                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                            if ((size_t) l7 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                            l8 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
                                            vader_comptime_walk_type(l0, l8);
                                            t1 = (l7 + INT64_C(1));
                                            l7 = (size_t) (int64_t) t1;
                                            goto loop_216;
                                        } else {
                                        }
                                    }
                                }
                                l8 = ((vader_struct_vader_types_FnType_t*) l2)->f_return_type;
                                vader_comptime_walk_type(l0, l8);
                            } else {
                            }
                        }
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static int64_t vader_comptime_wrap_to_width(int64_t l0, vader_string_t l1) {
    bool l2;
    int64_t l3;
    if (l1 == 1646u) {
        l2 = true;
    } else {
        l2 = l1 == 2248u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 1601u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 2229u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 1602u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 2230u;
    }
    if (l2) {
        l3 = vader_comptime_sign_extend_32(l0);
    } else {
        l3 = l0;
    }
    return l3;
}

