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
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = vader_types_strip_distinct_each(l2);
    l4 = vader_comptime_build_display_key(l1, l3);
    l5 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_by_key, l4);
    if (l5.tag == 656u) {
        t0 = l5.payload.obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_comptime_GenericInstance_t* _a0_obj = (vader_struct_vader_comptime_GenericInstance_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_GenericInstance_t));
    vader_obj_header_init(_a0_obj, 656u);
    _a0_obj->f_symbol = l1;
    _a0_obj->f_args = l3;
    _a0_obj->f_display_key = l4;
    l3 = (void*) _a0_obj;
    std_collections_MutableMap_IndexSet_set_at__string__Any(((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_by_key, l4, vader_ref_box(l3));
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
            }
        }
    }
    return true;
}

static void* vader_comptime_arg_count_error(void* l0, vader_string_t l1, size_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    vader_string_t l4 = 0;
    size_t l5;
    uint64_t l7;
    int64_t t0;
    size_t t1;
    void* t2 = NULL;
    void* t3 = NULL;
    void** gc_raw_roots[5] = { &l0, &l3, &l6, &t2, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
    l4 = l1;
    l5 = vader_host_std_core_byte_len(l4);
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(68) + l5));
    l5 = (size_t) (int64_t) INT64_C(0);
    l5 = std_core_write_string_at(l6, l5, 544u);
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 124u);
    t0 = ((int64_t) (size_t) l2);
    l7 = (uint64_t) (int64_t) t0;
    l5 = std_core_write_unsigned(l6, l5, l7);
    l5 = std_core_write_string_at(l6, l5, 113u);
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
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
    t0 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(10), l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_arithmetic(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    int64_t l4, l5;
    vader_string_t l6 = 0;
    uint8_t l7;
    double l8, l9;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t1 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 658u) {
        if (l2.tag == 658u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
            t1 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(180u, l4), vader_box_i64(180u, l5));
            l4 = ((int64_t) t1.payload.i);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
            t1 = vader_comptime_int_val_typed(l4, l6);
            t0 = vader_comptime_ok(t1);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
        if (l1.tag == 655u) {
            if (l2.tag == 655u) {
                l7 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op;
                t0 = l1.payload.obj;
                l8 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
                t0 = l2.payload.obj;
                l9 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
                l8 = vader_comptime_float_arith(l7, l8, l9);
                t0 = l1.payload.obj;
                l6 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_type_name;
                t1 = vader_comptime_float_val_typed(l8, l6);
                t0 = vader_comptime_ok(t1);
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        } else {
        }
    }
    t0 = vader_comptime_type_mismatch(l0, 2004u);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_arithmetic_int(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    int64_t l4, l5;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t1 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 658u) {
        if (l2.tag == 658u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
            t1 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(180u, l4), vader_box_i64(180u, l5));
            l4 = ((int64_t) t1.payload.i);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
            t1 = vader_comptime_int_val_typed(l4, l6);
            t0 = vader_comptime_ok(t1);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
    }
    t0 = vader_comptime_type_mismatch(l0, 2005u);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_arithmetic_or_concat(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &l6, &t2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 663u) {
        if (l2.tag == 663u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
            t1 = concat_2(l4, l5);
            t2 = vader_comptime_string_val(t1);
            t0 = vader_comptime_ok(t2);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_comptime_type_mismatch(l0, 2182u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l1;
    t0 = vader_comptime_arithmetic(l0, l6, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_assert_message(void* l0) {
    vader_box_t l1;
    vader_string_t t0;
    l1 = ((vader_struct_toolchain_ast_AssertDecl_t*) l0)->f_message;
    if (l1.tag == 0u) {
        return 0u;
    }
    if (l1.tag == 176u) {
        t0 = ((vader_struct_toolchain_ast_AssertDecl_t*) l0)->f_message.payload.s;
        return t0;
    }
    vader_unreachable("unreachable return in vader_comptime$assert_message");
}

static void vader_comptime_bake_file_exprs(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    void* l14 = NULL;
    size_t l7, l8, l11;
    vader_box_t l9 = vader_box_null(), l12 = vader_box_null(), l13 = vader_box_null(), l16 = vader_box_null();
    int32_t l15;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[5] = { &l9, &l12, &l13, &l16, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l10, &l14, &t2 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(27u, 0u, 13u, 405u);
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
            }
        }
    }
    l6 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l3)->f_comptime_decls;
    vader_struct_vader_comptime_ComptimeContext_t* _a2_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a2_obj, 650u);
    _a2_obj->f_typed = l1;
    _a2_obj->f_bindings = l6;
    _a2_obj->f_depth = INT64_C(0);
    l6 = (void*) _a2_obj;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_40: {
            if ((l8 < l7)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l8 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l8);
                vader_comptime_bake_one_file_expr(t2, l6, l1, l2, l4);
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                goto loop_40;
            }
        }
    }
    l5 = l0;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_68: {
            if ((l8 < l7)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                if ((size_t) l8 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l8);
                if (l9.tag == 373u) {
                    t2 = l9.payload.obj;
                    if (((vader_struct_toolchain_ast_ConstDecl_t*) t2)->f_value.tag == 405u) {
                        t2 = l9.payload.obj;
                        l6 = ((vader_struct_toolchain_ast_ConstDecl_t*) t2)->f_value.payload.obj;
                        t3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l6)->f_name;
                        if (t3 == 1659u) {
                            l10 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l2)->f_file_exprs;
                            l11 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l6)->f_id;
                            l12 = std_collections_MutableMap_Index_at__usize__string(l10, l11);
                            if (l12.tag == 176u) {
                                t2 = l9.payload.obj;
                                l13 = vader_typecheck_lookup_const_symbol(t2, l1);
                                if (l13.tag == 862u) {
                                    l14 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l2)->f_file_baked_consts;
                                    t2 = l13.payload.obj;
                                    l15 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t2)->f_id;
                                    t3 = l12.payload.s;
                                    l16 = vader_comptime_string_val(t3);
                                    std_collections_MutableMap_IndexSet_set_at__i32__Any(l14, l15, l16);
                                }
                            }
                        }
                    }
                }
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                goto loop_68;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_bake_one_file_expr(void* l0, void* l1, void* l2, void* l3, void* l4) {
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    void* l8 = NULL;
    size_t l9;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l8, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    t1 = vader_comptime_evaluate_expr(t0, l1);
    l5 = ((vader_struct_vader_comptime_EvalResult_t*) t1)->f_value;
    if (l5.tag == 0u) {
    } else {
        if (l5.tag == 663u) {
            t1 = l5.payload.obj;
            l6 = ((vader_struct_vader_comptime_StringValue_t*) t1)->f_value;
            l7 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_resolved)->f_path;
            l5 = vader_comptime_read_relative_file(l6, l7);
            if (l5.tag == 0u) {
            } else {
                if (l5.tag == 176u) {
                    l8 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_file_exprs;
                    l9 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_id;
                    l6 = l5.payload.s;
                    std_collections_MutableMap_IndexSet_set_at__usize__string(l8, l9, l6);
                } else {
                    { vader_gc_top = gc_frame.prev; return; }
                }
            }
        } else {
        }
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
    bool l4, l5;
    void* t0 = NULL;
    void* t3 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[3] = { &l1, &l2, &t1 };
    void** gc_raw_roots[4] = { &l0, &l3, &t0, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 648u) {
        if (l2.tag == 648u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
            vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
            t1 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_bool(174u, l4), vader_box_bool(174u, l5));
            t2 = t1.payload.b;
            if (t2) {
                vader_struct_vader_comptime_BoolValue_t* _a1_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
                vader_obj_header_init(_a1_obj, 648u);
                _a1_obj->f_value = true;
                t0 = (void*) _a1_obj;
                t3 = vader_comptime_ok(vader_ref_box(t0));
                { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            vader_struct_vader_comptime_BoolValue_t* _a2_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
            vader_obj_header_init(_a2_obj, 648u);
            _a2_obj->f_value = false;
            t0 = (void*) _a2_obj;
            t3 = vader_comptime_ok(vader_ref_box(t0));
            { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
    }
    t0 = vader_comptime_type_mismatch(l0, 1906u);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_bool_value(bool l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0) {
        vader_struct_vader_comptime_BoolValue_t* _a0_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
        vader_obj_header_init(_a0_obj, 648u);
        _a0_obj->f_value = true;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_comptime_BoolValue_t* _a1_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
    vader_obj_header_init(_a1_obj, 648u);
    _a1_obj->f_value = false;
    t0 = (void*) _a1_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_build_display_key(void* l0, void* l1) {
    vader_string_t l2 = 0;
    size_t l3;
    void* l4 = NULL;
    int64_t l5;
    int32_t t0;
    vader_string_t t1 = 0;
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_comptime_instance_args_key(l1);
    l3 = vader_host_std_core_byte_len(l2);
    l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l3));
    l3 = (size_t) (int64_t) INT64_C(0);
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l5 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l4, l3, l5);
    l3 = std_core_write_string_at(l4, l3, 303u);
    l3 = std_core_write_string_at(l4, l3, l2);
    l3 = std_core_write_string_at(l4, l3, 344u);
    t1 = std_core_finish_buffer(l4, l3);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_build_vm_required(void* l0, void* l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    int32_t l6;
    vader_box_t l7 = vader_box_null();
    vader_string_t l8 = 0;
    size_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l7, &t2 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l5, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_value.tag == 370u) {
        l4 = ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_value.payload.obj;
        if (((vader_struct_toolchain_ast_CallExpr_t*) l4)->f_callee.tag == 394u) {
            l5 = ((vader_struct_toolchain_ast_CallExpr_t*) l4)->f_callee.payload.obj;
            t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l4)->f_args)->length;
            if (t0 == INT64_C(0)) {
                l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_decl_types;
                l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
                l7 = std_collections_MutableMap_Index_at__i32__Any(l4, l6);
                if (!(l7.tag == 0u)) {
                    l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
                    l8 = ((vader_struct_toolchain_ast_IdentExpr_t*) l5)->f_name;
                    l4 = ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_span;
                    vader_struct_vader_comptime_VmRequiredDecl_t* _a0_obj = (vader_struct_vader_comptime_VmRequiredDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_VmRequiredDecl_t));
                    vader_obj_header_init(_a0_obj, 666u);
                    _a0_obj->f_symbol_id = l6;
                    _a0_obj->f_module_id = l3;
                    _a0_obj->f_callee_name = l8;
                    _a0_obj->f_decl_type = l7;
                    _a0_obj->f_span = l4;
                    t1 = (void*) _a0_obj;
                    { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
        }
    }
    t2 = vader_box_obj(0u, NULL);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

int64_t vader_comptime_byte_align(vader_box_t l0) {
    int64_t t0;
    t0 = vader_types_slot_byte_align(l0);
    return t0;
}

int64_t vader_comptime_byte_size(vader_box_t l0) {
    int64_t t0;
    t0 = vader_types_slot_byte_size(l0);
    return t0;
}

static vader_string_t vader_comptime_canonical_type_key(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t l6 = 0;
    size_t l3;
    void* l4 = NULL;
    int64_t l5;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l4, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 899u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = concat_2(708u, l1);
    } else {
        if (l0.tag == 901u) {
            t0 = l0.payload.obj;
            l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_StructType_t*) t0)->f_args);
            l3 = vader_host_std_core_byte_len(l2);
            l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(24) + l3));
            l3 = (size_t) (int64_t) INT64_C(0);
            l3 = std_core_write_string_at(l4, l3, 754u);
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
            l5 = ((int64_t) (int32_t) t1);
            l3 = std_core_write_int(l4, l3, l5);
            l3 = std_core_write_string_at(l4, l3, 303u);
            l3 = std_core_write_string_at(l4, l3, l2);
            l3 = std_core_write_string_at(l4, l3, 344u);
            l1 = std_core_finish_buffer(l4, l3);
        } else {
            if (l0.tag == 892u) {
                l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(22));
                l3 = (size_t) (int64_t) INT64_C(0);
                l3 = std_core_write_string_at(l4, l3, 605u);
                t0 = l0.payload.obj;
                t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_id;
                l5 = ((int64_t) (int32_t) t1);
                l3 = std_core_write_int(l4, l3, l5);
                l1 = std_core_finish_buffer(l4, l3);
            } else {
                if (l0.tag == 891u) {
                    t0 = l0.payload.obj;
                    l1 = vader_comptime_canonical_type_key(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
                } else {
                    if (l0.tag == 902u) {
                        t0 = l0.payload.obj;
                        l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_TraitType_t*) t0)->f_args);
                        l3 = vader_host_std_core_byte_len(l2);
                        l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(24) + l3));
                        l3 = (size_t) (int64_t) INT64_C(0);
                        l3 = std_core_write_string_at(l4, l3, 837u);
                        t0 = l0.payload.obj;
                        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol)->f_id;
                        l5 = ((int64_t) (int32_t) t1);
                        l3 = std_core_write_int(l4, l3, l5);
                        l3 = std_core_write_string_at(l4, l3, 303u);
                        l3 = std_core_write_string_at(l4, l3, l2);
                        l3 = std_core_write_string_at(l4, l3, 344u);
                        l1 = std_core_finish_buffer(l4, l3);
                    } else {
                        if (l0.tag == 890u) {
                            t0 = l0.payload.obj;
                            l2 = vader_comptime_canonical_type_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
                            l1 = concat_2(554u, l2);
                        } else {
                            if (l0.tag == 903u) {
                                t0 = l0.payload.obj;
                                l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
                                l1 = concat_3(842u, l2, 344u);
                            } else {
                                if (l0.tag == 893u) {
                                    t0 = l0.payload.obj;
                                    l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_FnType_t*) t0)->f_params);
                                    t0 = l0.payload.obj;
                                    l6 = vader_comptime_canonical_type_key(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
                                    l1 = concat_4(609u, l2, 374u, l6);
                                } else {
                                    if (l0.tag == 905u) {
                                        l4 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(22));
                                        l3 = (size_t) (int64_t) INT64_C(0);
                                        l3 = std_core_write_string_at(l4, l3, 871u);
                                        t0 = l0.payload.obj;
                                        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_id;
                                        l5 = ((int64_t) (int32_t) t1);
                                        l3 = std_core_write_int(l4, l3, l5);
                                        l1 = std_core_finish_buffer(l4, l3);
                                    } else {
                                        if (l0.tag == 906u) {
                                            t0 = l0.payload.obj;
                                            l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_UnionType_t*) t0)->f_variants);
                                            l1 = concat_3(670u, l2, 344u);
                                        } else {
                                            if (l0.tag == 904u) {
                                                l1 = 664u;
                                            } else {
                                                if (l0.tag == 900u) {
                                                    l1 = 757u;
                                                } else {
                                                    if (l0.tag == 907u) {
                                                        l1 = 846u;
                                                    } else {
                                                        if (l0.tag == 896u) {
                                                            l1 = 616u;
                                                        } else {
                                                            if (l0.tag == 894u) {
                                                                l1 = 614u;
                                                            } else {
                                                                if (l0.tag == 895u) {
                                                                    l1 = 615u;
                                                                } else {
                                                                    if (l0.tag == 897u) {
                                                                        l1 = 675u;
                                                                    } else {
                                                                        if (l0.tag == 889u) {
                                                                            l1 = 872u;
                                                                        } else {
                                                                            vader_unreachable("unreachable return in vader_comptime$canonical_type_key");
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
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
            }
        }
    }
    if (!(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1, l2, l3, l4);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_collect_expr_deps(vader_box_t l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l9 = NULL;
    uint64_t l6;
    vader_box_t l7 = vader_box_null();
    size_t l8, l11;
    int32_t l10;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l0, &l7, &t1 };
    void** gc_raw_roots[7] = { &l1, &l2, &l3, &l4, &l5, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 394u) {
        l5 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved)->f_idents;
        t0 = l0.payload.obj;
        l6 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span);
        l7 = std_collections_MutableMap_Index_at__u64__Any(l5, l6);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l5 = l7.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) l5)->f_kind != INT32_C(6)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l9 = ((vader_struct_vader_comptime_Nodes_t*) l2)->f_by_symbol;
        l10 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l5)->f_id;
        l7 = std_collections_MutableMap_Index_at__i32__usize(l9, l10);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l8 = ((size_t) l7.payload.i);
        t1 = std_collections_MutableMap_Index_at__usize__bool(l3, l8);
        if (t1.tag == 174u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        std_collections_MutableMap_IndexSet_set_at__usize__bool(l3, l8, true);
        vader_array_push_i64((vader_array_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l4)->f_dependency_ids, (int64_t) (size_t) l8);
    } else {
        if (l0.tag == 370u) {
            t0 = l0.payload.obj;
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee, l1, l2, l3, l4);
            t0 = l0.payload.obj;
            l5 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
            l8 = ((vader_array_t*) l5)->length;
            l11 = (size_t) (int64_t) INT64_C(0);
            {
                loop_79: {
                    if ((l11 < l8)) {
                        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
                        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                        if ((size_t) l11 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l11);
                        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1, l2, l3, l4);
                        t2 = (l11 + INT64_C(1));
                        l11 = (size_t) (int64_t) t2;
                        goto loop_79;
                    }
                }
            }
        } else {
            if (l0.tag == 387u) {
                t0 = l0.payload.obj;
                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target, l1, l2, l3, l4);
            } else {
                if (l0.tag == 402u) {
                    t0 = l0.payload.obj;
                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target, l1, l2, l3, l4);
                    t0 = l0.payload.obj;
                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index, l1, l2, l3, l4);
                } else {
                    if (l0.tag == 443u) {
                        t0 = l0.payload.obj;
                        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand, l1, l2, l3, l4);
                    } else {
                        if (l0.tag == 364u) {
                            t0 = l0.payload.obj;
                            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1, l2, l3, l4);
                            t0 = l0.payload.obj;
                            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1, l2, l3, l4);
                        } else {
                            if (l0.tag == 397u) {
                                t0 = l0.payload.obj;
                                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_cond, l1, l2, l3, l4);
                                t0 = l0.payload.obj;
                                vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_then_block, l1, l2, l3, l4);
                                t0 = l0.payload.obj;
                                l7 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_else_branch;
                                if (l7.tag == 0u) {
                                } else {
                                    if (l7.tag == 396u) {
                                        t0 = l7.payload.obj;
                                        vader_comptime_collect_expr_deps(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1, l2, l3, l4);
                                    } else {
                                        if (l7.tag == 395u) {
                                            t0 = l7.payload.obj;
                                            vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1, l2, l3, l4);
                                        } else {
                                            { vader_gc_top = gc_frame.prev; return; }
                                        }
                                    }
                                }
                            } else {
                                if (l0.tag == 411u) {
                                    t0 = l0.payload.obj;
                                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_scrutinee, l1, l2, l3, l4);
                                    t0 = l0.payload.obj;
                                    l5 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_arms;
                                    l8 = ((vader_array_t*) l5)->length;
                                    l11 = (size_t) (int64_t) INT64_C(0);
                                    {
                                        loop_241: {
                                            if ((l11 < l8)) {
                                                vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
                                                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                                                if ((size_t) l11 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                                                l9 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
                                                if (!(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_guard.tag == 0u)) {
                                                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_guard, l1, l2, l3, l4);
                                                }
                                                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_body, l1, l2, l3, l4);
                                                t2 = (l11 + INT64_C(1));
                                                l11 = (size_t) (int64_t) t2;
                                                goto loop_241;
                                            }
                                        }
                                    }
                                } else {
                                    if (l0.tag == 366u) {
                                        t0 = l0.payload.obj;
                                        vader_comptime_collect_block_deps(t0, l1, l2, l3, l4);
                                    } else {
                                        if (l0.tag == 433u) {
                                            t0 = l0.payload.obj;
                                            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_type_name, l1, l2, l3, l4);
                                            t0 = l0.payload.obj;
                                            l5 = ((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_items;
                                            l8 = ((vader_array_t*) l5)->length;
                                            l11 = (size_t) (int64_t) INT64_C(0);
                                            {
                                                loop_307: {
                                                    if ((l11 < l8)) {
                                                        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                                                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                                                        if ((size_t) l11 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                                                        l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
                                                        if (l7.tag == 434u) {
                                                            t0 = l7.payload.obj;
                                                            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value, l1, l2, l3, l4);
                                                        } else {
                                                            if (l7.tag == 435u) {
                                                                t0 = l7.payload.obj;
                                                                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr, l1, l2, l3, l4);
                                                            } else {
                                                                { vader_gc_top = gc_frame.prev; return; }
                                                            }
                                                        }
                                                        t2 = (l11 + INT64_C(1));
                                                        l11 = (size_t) (int64_t) t2;
                                                        goto loop_307;
                                                    }
                                                }
                                            }
                                        } else {
                                            if (l0.tag == 426u) {
                                                t0 = l0.payload.obj;
                                                l5 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
                                                l8 = ((vader_array_t*) l5)->length;
                                                l11 = (size_t) (int64_t) INT64_C(0);
                                                {
                                                    loop_363: {
                                                        if ((l11 < l8)) {
                                                            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
                                                            if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                                                            if ((size_t) l11 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                                                            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
                                                            vader_comptime_collect_expr_deps(t1, l1, l2, l3, l4);
                                                            t2 = (l11 + INT64_C(1));
                                                            l11 = (size_t) (int64_t) t2;
                                                            goto loop_363;
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (l0.tag == 422u) {
                                                    t0 = l0.payload.obj;
                                                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_lower, l1, l2, l3, l4);
                                                    t0 = l0.payload.obj;
                                                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_upper, l1, l2, l3, l4);
                                                } else {
                                                    if (l0.tag == 363u) {
                                                        t0 = l0.payload.obj;
                                                        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner, l1, l2, l3, l4);
                                                    } else {
                                                        if (l0.tag == 371u) {
                                                            t0 = l0.payload.obj;
                                                            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value, l1, l2, l3, l4);
                                                        } else {
                                                            if (l0.tag == 407u) {
                                                                t0 = l0.payload.obj;
                                                                vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_body, l1, l2, l3, l4);
                                                            } else {
                                                                if (l0.tag == 405u) {
                                                                    t0 = l0.payload.obj;
                                                                    l5 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
                                                                    l8 = ((vader_array_t*) l5)->length;
                                                                    l11 = (size_t) (int64_t) INT64_C(0);
                                                                    {
                                                                        loop_453: {
                                                                            if ((l11 < l8)) {
                                                                                vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
                                                                                if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                                                                if ((size_t) l11 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l11);
                                                                                vader_comptime_collect_expr_deps(t1, l1, l2, l3, l4);
                                                                                t2 = (l11 + INT64_C(1));
                                                                                l11 = (size_t) (int64_t) t2;
                                                                                goto loop_453;
                                                                            }
                                                                        }
                                                                    }
                                                                } else {
                                                                    if (l0.tag == 393u) {
                                                                        t0 = l0.payload.obj;
                                                                        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee, l1, l2, l3, l4);
                                                                    } else {
                                                                        if (l0.tag == 428u) {
                                                                            t0 = l0.payload.obj;
                                                                            l5 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
                                                                            l8 = ((vader_array_t*) l5)->length;
                                                                            l11 = (size_t) (int64_t) INT64_C(0);
                                                                            {
                                                                                loop_499: {
                                                                                    if ((l11 < l8)) {
                                                                                        vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
                                                                                        if (_a5_slotarr->buf != NULL && _a5_slotarr->buf->header.forward != NULL) { _a5_slotarr->buf = vader_array_buf_forward(_a5_slotarr->buf); }
                                                                                        if ((size_t) l11 >= _a5_slotarr->length) { vader_trap("array index out of bounds"); }
                                                                                        l7 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
                                                                                        if (l7.tag == 429u) {
                                                                                            t0 = l7.payload.obj;
                                                                                            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1, l2, l3, l4);
                                                                                        } else {
                                                                                            if (l7.tag == 430u) {
                                                                                            } else {
                                                                                                { vader_gc_top = gc_frame.prev; return; }
                                                                                            }
                                                                                        }
                                                                                        t2 = (l11 + INT64_C(1));
                                                                                        l11 = (size_t) (int64_t) t2;
                                                                                        goto loop_499;
                                                                                    }
                                                                                }
                                                                            }
                                                                        } else {
                                                                            if (l0.tag == 416u) {
                                                                                t0 = l0.payload.obj;
                                                                                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_left, l1, l2, l3, l4);
                                                                                t0 = l0.payload.obj;
                                                                                l7 = toolchain_ast_coalesce_fallback_expr(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_fallback);
                                                                                if (!(l7.tag == 0u)) {
                                                                                    vader_comptime_collect_expr_deps(l7, l1, l2, l3, l4);
                                                                                }
                                                                            } else {
                                                                                if ((l0.tag == 367u || l0.tag == 372u || l0.tag == 382u || l0.tag == 388u || l0.tag == 404u || l0.tag == 417u)) {
                                                                                } else {
                                                                                    if ((l0.tag == 360u || l0.tag == 391u || l0.tag == 413u)) {
                                                                                    } else {
                                                                                        { vader_gc_top = gc_frame.prev; return; }
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
    size_t l4, l5;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 389u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body;
        if (l2.tag == 0u) {
        } else {
            if (l2.tag == 366u) {
                t0 = l2.payload.obj;
                vader_comptime_collect_in_block(t0, l1);
            } else {
                { vader_gc_top = gc_frame.prev; return; }
            }
        }
    } else {
        if (l0.tag == 398u) {
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
                        } else {
                            if (l2.tag == 366u) {
                                t0 = l2.payload.obj;
                                vader_comptime_collect_in_block(t0, l1);
                            } else {
                                { vader_gc_top = gc_frame.prev; return; }
                            }
                        }
                        t1 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t1;
                        goto loop_34;
                    }
                }
            }
        } else {
            if (l0.tag == 373u) {
                t0 = l0.payload.obj;
                vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_value, l1);
            } else {
                if (l0.tag == 361u) {
                    t0 = l0.payload.obj;
                    vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_condition, l1);
                } else {
                }
            }
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
            }
        }
    }
    if (!(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u)) {
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_collect_in_expr(vader_box_t l0, void* l1) {
    bool l2;
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    size_t t2;
    int64_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l6, &t4 };
    void** gc_raw_roots[3] = { &l1, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 405u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_name;
        if (t1 == 1659u) {
            t0 = l0.payload.obj;
            t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args)->length;
            l2 = t2 == INT64_C(1);
        } else {
            l2 = false;
        }
        if (l2) {
            l3 = l0.payload.obj;
            vader_array_push((vader_array_t*) l1, vader_ref_box(l3));
        }
    }
    if (l0.tag == 366u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_block(t0, l1);
    } else {
        if (l0.tag == 370u) {
            t0 = l0.payload.obj;
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee, l1);
            t0 = l0.payload.obj;
            l3 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
            l4 = ((vader_array_t*) l3)->length;
            l5 = (size_t) (int64_t) INT64_C(0);
            {
                loop_56: {
                    if ((l5 < l4)) {
                        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                        if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1);
                        t3 = (l5 + INT64_C(1));
                        l5 = (size_t) (int64_t) t3;
                        goto loop_56;
                    }
                }
            }
        } else {
            if (l0.tag == 387u) {
                t0 = l0.payload.obj;
                vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target, l1);
            } else {
                if (l0.tag == 402u) {
                    t0 = l0.payload.obj;
                    vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target, l1);
                    t0 = l0.payload.obj;
                    vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index, l1);
                } else {
                    if (l0.tag == 443u) {
                        t0 = l0.payload.obj;
                        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand, l1);
                    } else {
                        if (l0.tag == 364u) {
                            t0 = l0.payload.obj;
                            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
                            t0 = l0.payload.obj;
                            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
                        } else {
                            if (l0.tag == 397u) {
                                t0 = l0.payload.obj;
                                vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_cond, l1);
                                t0 = l0.payload.obj;
                                vader_comptime_collect_in_block(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_then_block, l1);
                                t0 = l0.payload.obj;
                                l6 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_else_branch;
                                if (l6.tag == 0u) {
                                } else {
                                    if (l6.tag == 395u) {
                                        t0 = l6.payload.obj;
                                        vader_comptime_collect_in_block(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1);
                                    } else {
                                        if (l6.tag == 396u) {
                                            t0 = l6.payload.obj;
                                            vader_comptime_collect_in_expr(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1);
                                        } else {
                                            { vader_gc_top = gc_frame.prev; return; }
                                        }
                                    }
                                }
                            } else {
                                if (l0.tag == 405u) {
                                    t0 = l0.payload.obj;
                                    l3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
                                    l4 = ((vader_array_t*) l3)->length;
                                    l5 = (size_t) (int64_t) INT64_C(0);
                                    {
                                        loop_177: {
                                            if ((l5 < l4)) {
                                                vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                                                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                                                if ((size_t) l5 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                                                t4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                                                vader_comptime_collect_in_expr(t4, l1);
                                                t3 = (l5 + INT64_C(1));
                                                l5 = (size_t) (int64_t) t3;
                                                goto loop_177;
                                            }
                                        }
                                    }
                                } else {
                                    if (l0.tag == 428u) {
                                        t0 = l0.payload.obj;
                                        l3 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
                                        l4 = ((vader_array_t*) l3)->length;
                                        l5 = (size_t) (int64_t) INT64_C(0);
                                        {
                                            loop_208: {
                                                if ((l5 < l4)) {
                                                    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                                                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                                                    if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                                                    l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                                                    if (l6.tag == 429u) {
                                                        t0 = l6.payload.obj;
                                                        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1);
                                                    }
                                                    t3 = (l5 + INT64_C(1));
                                                    l5 = (size_t) (int64_t) t3;
                                                    goto loop_208;
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
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_collect_in_stmt(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 408u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value, l1);
    } else {
        if (l0.tag == 362u) {
            t0 = l0.payload.obj;
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target, l1);
            t0 = l0.payload.obj;
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value, l1);
        } else {
            if (l0.tag == 386u) {
                t0 = l0.payload.obj;
                vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1);
            } else {
                if (l0.tag == 425u) {
                    t0 = l0.payload.obj;
                    if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
                        t0 = l0.payload.obj;
                        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
                    }
                } else {
                    if (l0.tag == 392u) {
                        t0 = l0.payload.obj;
                        l2 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form;
                        if (l2.tag == 444u) {
                            t0 = l2.payload.obj;
                            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
                        } else {
                            if (l2.tag == 401u) {
                                t0 = l2.payload.obj;
                                vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1);
                            } else {
                            }
                        }
                        t0 = l0.payload.obj;
                        vader_comptime_collect_in_block(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_body, l1);
                    } else {
                        if (l0.tag == 377u) {
                            t0 = l0.payload.obj;
                            l2 = ((vader_struct_toolchain_ast_DeferStmt_t*) t0)->f_body;
                            if (l2.tag == 378u) {
                                t0 = l2.payload.obj;
                                vader_comptime_collect_in_stmt(((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt, l1);
                            } else {
                                if (l2.tag == 376u) {
                                    t0 = l2.payload.obj;
                                    vader_comptime_collect_in_block(((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block, l1);
                                } else {
                                    { vader_gc_top = gc_frame.prev; return; }
                                }
                            }
                        } else {
                        }
                    }
                }
            }
        }
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
    size_t l6, l7, l9, l11, l12;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 4u, 186u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 187u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__usize__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__usize__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__Any_t));
    vader_obj_header_init(_a3_obj, 339u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(15u, 0u, 4u, 186u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(15u, 0u, 4u, 186u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i32__usize_t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__usize_t));
    vader_obj_header_init(_a8_obj, 285u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a8_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a8_obj;
    vader_struct_vader_comptime_Nodes_t* _a9_obj = (vader_struct_vader_comptime_Nodes_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_Nodes_t));
    vader_obj_header_init(_a9_obj, 661u);
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
                if (l8.tag == 373u) {
                    t0 = l8.payload.obj;
                    t1 = vader_comptime_has_comptime_decorator(t0);
                    if (!(t1)) {
                        t2 = (l7 + INT64_C(1));
                        l7 = (size_t) (int64_t) t2;
                        goto loop_42;
                    }
                    vader_array_t* _a11_arr = vader_array_new(15u, 0u, 4u, 186u);
                    l3 = (void*) _a11_arr;
                    l4 = ((vader_struct_vader_comptime_Nodes_t*) l1)->f_by_id;
                    t0 = l8.payload.obj;
                    l9 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_id;
                    t0 = l8.payload.obj;
                    vader_struct_vader_comptime_NodeRecord_t* _a12_obj = (vader_struct_vader_comptime_NodeRecord_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_NodeRecord_t));
                    vader_obj_header_init(_a12_obj, 660u);
                    _a12_obj->f_decl = t0;
                    _a12_obj->f_dependency_ids = l3;
                    l5 = (void*) _a12_obj;
                    std_collections_MutableMap_IndexSet_set_at__usize__Any(l4, l9, vader_ref_box(l5));
                    l10 = ((vader_struct_vader_comptime_Nodes_t*) l1)->f_order;
                    t0 = l8.payload.obj;
                    l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_id;
                    vader_array_push_i64((vader_array_t*) l10, (int64_t) (size_t) l11);
                    l12 = (size_t) (int64_t) INT64_C(1);
                    t2 = (l7 + l12);
                    l7 = (size_t) (int64_t) t2;
                    goto loop_42;
                }
                l12 = (size_t) (int64_t) INT64_C(1);
                t2 = (l7 + l12);
                l7 = (size_t) (int64_t) t2;
                goto loop_42;
            }
        }
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_collect_stmt_deps(vader_box_t l0, void* l1, void* l2, void* l3, void* l4) {
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l5 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 408u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value, l1, l2, l3, l4);
    } else {
        if (l0.tag == 386u) {
            t0 = l0.payload.obj;
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1, l2, l3, l4);
        } else {
            if (l0.tag == 425u) {
                t0 = l0.payload.obj;
                if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
                    t0 = l0.payload.obj;
                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1, l2, l3, l4);
                }
            } else {
                if (l0.tag == 362u) {
                    t0 = l0.payload.obj;
                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target, l1, l2, l3, l4);
                    t0 = l0.payload.obj;
                    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value, l1, l2, l3, l4);
                } else {
                    if (l0.tag == 392u) {
                        t0 = l0.payload.obj;
                        l5 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form;
                        if (l5.tag == 444u) {
                            t0 = l5.payload.obj;
                            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1, l2, l3, l4);
                        } else {
                            if (l5.tag == 401u) {
                                t0 = l5.payload.obj;
                                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1, l2, l3, l4);
                            } else {
                                if (l5.tag == 403u) {
                                } else {
                                    { vader_gc_top = gc_frame.prev; return; }
                                }
                            }
                        }
                        t0 = l0.payload.obj;
                        vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_body, l1, l2, l3, l4);
                    } else {
                        if (l0.tag == 448u) {
                            t0 = l0.payload.obj;
                            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_YieldStmt_t*) t0)->f_value, l1, l2, l3, l4);
                        } else {
                            if (l0.tag == 377u) {
                                t0 = l0.payload.obj;
                                l5 = ((vader_struct_toolchain_ast_DeferStmt_t*) t0)->f_body;
                                if (l5.tag == 378u) {
                                    t0 = l5.payload.obj;
                                    vader_comptime_collect_stmt_deps(((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt, l1, l2, l3, l4);
                                } else {
                                    if (l5.tag == 376u) {
                                        t0 = l5.payload.obj;
                                        vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block, l1, l2, l3, l4);
                                    } else {
                                        { vader_gc_top = gc_frame.prev; return; }
                                    }
                                }
                            } else {
                                if ((l0.tag == 368u || l0.tag == 374u)) {
                                } else {
                                    { vader_gc_top = gc_frame.prev; return; }
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

static void* vader_comptime_combine_binary(void* l0, vader_box_t l1, vader_box_t l2) {
    uint8_t l3;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op;
    if (l3 == INT32_C(0)) {
        l4 = (void*) &vader_fn_static_vader_comptime_op_add;
        l4 = vader_comptime_arithmetic_or_concat(l0, l1, l2, l4);
    } else {
        if (l3 == INT32_C(1)) {
            l5 = (void*) &vader_fn_static_vader_comptime_op_sub;
            l4 = vader_comptime_arithmetic(l0, l1, l2, l5);
        } else {
            if (l3 == INT32_C(2)) {
                l5 = (void*) &vader_fn_static_vader_comptime_op_mul;
                l4 = vader_comptime_arithmetic(l0, l1, l2, l5);
            } else {
                if (l3 == INT32_C(3)) {
                    l5 = (void*) &vader_fn_static_vader_comptime_op_div;
                    l4 = vader_comptime_int_div_check(l0, l1, l2, l5);
                } else {
                    if (l3 == INT32_C(4)) {
                        l5 = (void*) &vader_fn_static_vader_comptime_op_mod;
                        l4 = vader_comptime_int_mod_check(l0, l1, l2, l5);
                    } else {
                        if (l3 == INT32_C(5)) {
                            l5 = (void*) &vader_fn_static_vader_comptime_op_shl;
                            l4 = vader_comptime_arithmetic_int(l0, l1, l2, l5);
                        } else {
                            if (l3 == INT32_C(6)) {
                                l5 = (void*) &vader_fn_static_vader_comptime_op_shr;
                                l4 = vader_comptime_arithmetic_int(l0, l1, l2, l5);
                            } else {
                                if (l3 == INT32_C(7)) {
                                    l5 = (void*) &vader_fn_static_vader_comptime_op_bit_and;
                                    l4 = vader_comptime_arithmetic_int(l0, l1, l2, l5);
                                } else {
                                    if (l3 == INT32_C(8)) {
                                        l5 = (void*) &vader_fn_static_vader_comptime_op_bit_or;
                                        l4 = vader_comptime_arithmetic_int(l0, l1, l2, l5);
                                    } else {
                                        if (l3 == INT32_C(9)) {
                                            l5 = (void*) &vader_fn_static_vader_comptime_op_bit_xor;
                                            l4 = vader_comptime_arithmetic_int(l0, l1, l2, l5);
                                        } else {
                                            if (l3 == INT32_C(10)) {
                                                l5 = (void*) &vader_fn_static_vader_comptime_op_and;
                                                l4 = vader_comptime_bool_op(l0, l1, l2, l5);
                                            } else {
                                                if (l3 == INT32_C(11)) {
                                                    l5 = (void*) &vader_fn_static_vader_comptime_op_or;
                                                    l4 = vader_comptime_bool_op(l0, l1, l2, l5);
                                                } else {
                                                    if (l3 == INT32_C(12)) {
                                                        l4 = vader_comptime_compare(l0, l1, l2, (uint8_t) (int32_t) INT32_C(0));
                                                    } else {
                                                        if (l3 == INT32_C(13)) {
                                                            l4 = vader_comptime_compare(l0, l1, l2, (uint8_t) (int32_t) INT32_C(1));
                                                        } else {
                                                            if (l3 == INT32_C(14)) {
                                                                l4 = vader_comptime_compare(l0, l1, l2, (uint8_t) (int32_t) INT32_C(2));
                                                            } else {
                                                                if (l3 == INT32_C(15)) {
                                                                    l4 = vader_comptime_compare(l0, l1, l2, (uint8_t) (int32_t) INT32_C(3));
                                                                } else {
                                                                    if (l3 == INT32_C(16)) {
                                                                        l4 = vader_comptime_compare(l0, l1, l2, (uint8_t) (int32_t) INT32_C(4));
                                                                    } else {
                                                                        if (l3 == INT32_C(17)) {
                                                                            l4 = vader_comptime_compare(l0, l1, l2, (uint8_t) (int32_t) INT32_C(5));
                                                                        } else {
                                                                            if (l3 == INT32_C(18)) {
                                                                                l4 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 564u);
                                                                            } else {
                                                                                if (l3 == INT32_C(19)) {
                                                                                    l4 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 563u);
                                                                                } else {
                                                                                    if (l3 == INT32_C(20)) {
                                                                                        l4 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 565u);
                                                                                    } else {
                                                                                        vader_unreachable("unreachable return in vader_comptime$combine_binary");
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
                }
            }
        }
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_compare(void* l0, vader_box_t l1, vader_box_t l2, uint8_t l3) {
    int64_t l4, l5;
    double l6, l7;
    bool l8, l9;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l10, &l11 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 658u) {
        if (l2.tag == 658u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            t1 = vader_comptime_int_compare(l4, l5, l3);
            t2 = vader_comptime_bool_value(t1);
            t0 = vader_comptime_ok(t2);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else {
        if (l1.tag == 655u) {
            if (l2.tag == 655u) {
                t0 = l1.payload.obj;
                l6 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
                t0 = l2.payload.obj;
                l7 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
                t1 = vader_comptime_float_compare(l6, l7, l3);
                t2 = vader_comptime_bool_value(t1);
                t0 = vader_comptime_ok(t2);
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        } else {
            if (l1.tag == 648u) {
                if (l2.tag == 648u) {
                    t0 = l1.payload.obj;
                    l8 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
                    t0 = l2.payload.obj;
                    l9 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
                    l8 = l8 == l9;
                    t0 = vader_comptime_equality_only(l0, l8, l3, 1332u);
                    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
            } else {
                if (l1.tag == 663u) {
                    if (l2.tag == 663u) {
                        t0 = l1.payload.obj;
                        l10 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
                        t0 = l2.payload.obj;
                        l11 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
                        l8 = l10 == l11;
                        t0 = vader_comptime_equality_only(l0, l8, l3, 2181u);
                        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                } else {
                }
            }
        }
    }
    t0 = vader_comptime_type_mismatch(l0, 1448u);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_cycle_names(size_t l0, size_t l1, void* l2, size_t l3, void* l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    size_t l6, l9;
    vader_box_t l10 = vader_box_null();
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l10, &t2 };
    void** gc_raw_roots[6] = { &l2, &l4, &l5, &l7, &l8, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l11, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
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
                l10 = std_collections_MutableMap_Index_at__usize__Any(l8, l9);
                if (l10.tag == 0u) {
                    t0 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t0;
                    goto loop_5;
                }
                l7 = l10.payload.obj;
                l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l7)->f_decl)->f_name;
                vader_array_push((vader_array_t*) l5, vader_box_string(176u, l11));
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_5;
            }
        }
    }
    l10 = std_collections_MutableMap_Index_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l4)->f_by_id, l3);
    if (!(l10.tag == 0u)) {
        t1 = l10.payload.obj;
        l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) t1)->f_decl)->f_name;
        vader_array_push((vader_array_t*) l5, vader_box_string(176u, l11));
    }
    l11 = 0u;
    l6 = ((vader_array_t*) l5)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_71: {
            if ((l9 < l6)) {
                if ((l9 > INT64_C(0))) {
                    l11 = concat_2(l11, 239u);
                }
                vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l9];
                l12 = t2.payload.s;
                l11 = concat_2(l11, l12);
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                goto loop_71;
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
    vader_array_t* _a0_arr = vader_array_new(52u, 0u, 13u, 669u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_display_value(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l5 = 0;
    vader_string_t l6 = 0;
    size_t l2;
    void* l3 = NULL;
    int64_t l4;
    bool l7;
    void* t0 = NULL;
    double t1;
    uint32_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l3, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l5, &l6, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 658u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
        l2 = vader_host_std_core_byte_len(l1);
        l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l2));
        l2 = (size_t) (int64_t) INT64_C(0);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        l2 = std_core_write_int(l3, l2, l4);
        l2 = std_core_write_string_at(l3, l2, 892u);
        l2 = std_core_write_string_at(l3, l2, l1);
        l1 = std_core_finish_buffer(l3, l2);
    } else {
        if (l0.tag == 655u) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
            l5 = std_core_f64_Display_to_string(t1);
            t0 = l0.payload.obj;
            l6 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_type_name;
            l1 = concat_3(l5, 892u, l6);
        } else {
            if (l0.tag == 648u) {
                l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(5));
                l2 = (size_t) (int64_t) INT64_C(0);
                t0 = l0.payload.obj;
                l7 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
                l2 = std_core_write_bool(l3, l2, l7);
                l1 = std_core_finish_buffer(l3, l2);
            } else {
                if (l0.tag == 649u) {
                    t0 = l0.payload.obj;
                    t2 = ((vader_struct_vader_comptime_CharValue_t*) t0)->f_value;
                    t3 = std_numbers_to_hex((uint64_t) (int64_t) ((int64_t) (uint32_t) t2));
                    l5 = std_string_pad_start(t3, (size_t) (int64_t) INT64_C(4), 48u);
                    l1 = concat_3(302u, l5, 286u);
                } else {
                    if (l0.tag == 663u) {
                        t0 = l0.payload.obj;
                        l5 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
                        l1 = concat_3(244u, l5, 244u);
                    } else {
                        if (l0.tag == 662u) {
                            l1 = 1996u;
                        } else {
                            if (l0.tag == 667u) {
                                l1 = 2484u;
                            } else {
                                if (l0.tag == 647u) {
                                    t0 = l0.payload.obj;
                                    l1 = vader_comptime_render_array(t0);
                                } else {
                                    if (l0.tag == 664u) {
                                        t0 = l0.payload.obj;
                                        l1 = vader_comptime_render_struct(t0);
                                    } else {
                                        if (l0.tag == 665u) {
                                            t0 = l0.payload.obj;
                                            l1 = vader_types_display_type_key(((vader_struct_vader_comptime_TypeValue_t*) t0)->f_value);
                                        } else {
                                            vader_unreachable("unreachable return in vader_comptime$display_value");
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
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_division_by_zero(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span;
    t0 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(4), l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_emit_cycle(size_t l0, void* l1, size_t l2, void* l3, void* l4, void* l5) {
    size_t l6, l7;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null();
    void* l10 = NULL;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[6] = { &l1, &l3, &l4, &l5, &l10, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
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
            }
        }
    }
    l8 = vader_comptime_cycle_names(l6, l2, l1, l0, l3);
    l9 = std_collections_MutableMap_Index_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l3)->f_by_id, l0);
    if (!(l9.tag == 0u)) {
        t1 = l9.payload.obj;
        l10 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) t1)->f_decl)->f_span;
        l10 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(8), l10, l8);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l10));
    }
    {
        loop_57: {
            if ((l6 < l2)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
                l7 = (size_t) (int64_t) t0;
                std_collections_MutableMap_IndexSet_set_at__usize__bool(l4, l7, true);
                t0 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t0;
                goto loop_57;
            }
        }
    }
    std_collections_MutableMap_IndexSet_set_at__usize__bool(l4, l0, true);
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_equality_only(void* l0, bool l1, uint8_t l2, vader_string_t l3) {
    vader_string_t l4 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
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
    l4 = concat_3(977u, l3, 1082u);
    t1 = vader_comptime_type_mismatch(l0, l4);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_evaluate_assert_decls(void* l0, void* l1, void* l2, void* l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l13 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l8, &l10 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l4, &l5, &l9, &l11, &l12, &l14, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l13, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_ComptimeContext_t* _a0_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a0_obj, 650u);
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
                if (l8.tag == 361u) {
                    t0 = l8.payload.obj;
                    l9 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_condition, l4);
                    l10 = ((vader_struct_vader_comptime_EvalResult_t*) l9)->f_diag;
                    if (l10.tag == 0u) {
                    } else {
                        if (l10.tag == 669u) {
                            l11 = l10.payload.obj;
                            t1 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) l11)->f_code)->f_id;
                            if (t1 != 569u) {
                                vader_array_push((vader_array_t*) l3, vader_ref_box(l11));
                            }
                        } else {
                            { vader_gc_top = gc_frame.prev; return; }
                        }
                    }
                    if (((vader_struct_vader_comptime_EvalResult_t*) l9)->f_value.tag == 648u) {
                        t0 = ((vader_struct_vader_comptime_EvalResult_t*) l9)->f_value.payload.obj;
                        t2 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
                        if (!(t2)) {
                            t0 = l8.payload.obj;
                            l12 = ((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_span;
                            t0 = l8.payload.obj;
                            l13 = vader_comptime_assert_message(t0);
                            l14 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(14), l12, l13);
                            vader_array_push((vader_array_t*) l3, vader_ref_box(l14));
                        }
                    }
                }
                t3 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t3;
                goto loop_12;
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
    vader_string_t l6 = 0;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null();
    bool l8;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l7, &l9, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &t1, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
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
        vader_obj_header_init(_a0_obj, 648u);
        _a0_obj->f_value = true;
        t1 = (void*) _a0_obj;
        t2 = vader_comptime_ok(vader_ref_box(t1));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_comptime_BoolValue_t* _a1_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
    vader_obj_header_init(_a1_obj, 648u);
    _a1_obj->f_value = false;
    t1 = (void*) _a1_obj;
    t2 = vader_comptime_ok(vader_ref_box(t1));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_call_expr(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    bool l3;
    vader_box_t l5 = vader_box_null(), l14 = vader_box_null(), l16 = vader_box_null();
    int64_t l6;
    vader_string_t l7 = 0;
    uint64_t l8;
    int32_t l9, l15;
    size_t l10, l11;
    void* t0 = NULL;
    void* t4 = NULL;
    vader_box_t t1 = vader_box_null();
    size_t t2;
    vader_string_t t3 = 0;
    int64_t t5;
    vader_box_t* gc_roots[4] = { &l5, &l14, &l16, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l4, &l12, &l13, &t0, &t4 };
    vader_string_t* gc_atom_roots[2] = { &l7, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_callee.tag == 394u)) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 593u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_callee;
    l2 = t1.payload.obj;
    if (((vader_obj_header_t*) l2)->type_index == 394u) {
        t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
        if (t2 == INT64_C(1)) {
            t3 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_name;
            l3 = vader_comptime_is_primitive_int_name(t3);
        } else {
            l3 = false;
        }
        if (l3) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
            l4 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1);
            if (((vader_struct_vader_comptime_EvalResult_t*) l4)->f_value.tag == 0u) {
                { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l5 = ((vader_struct_vader_comptime_EvalResult_t*) l4)->f_value;
            if (l5.tag == 658u) {
                t0 = l5.payload.obj;
                l6 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
                l7 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_name;
                vader_struct_vader_comptime_IntValue_t* _a1_obj = (vader_struct_vader_comptime_IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_IntValue_t));
                vader_obj_header_init(_a1_obj, 658u);
                _a1_obj->f_value = l6;
                _a1_obj->f_type_name = l7;
                t0 = (void*) _a1_obj;
                t4 = vader_comptime_ok(vader_ref_box(t0));
                { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l4 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
    l8 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_span);
    l5 = std_collections_MutableMap_Index_at__u64__Any(l4, l8);
    if (l5.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 591u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_fn_decls;
    t0 = l5.payload.obj;
    l9 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
    l5 = std_collections_MutableMap_Index_at__i32__Any(l2, l9);
    if (l5.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 592u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l5.payload.obj;
    l10 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params)->length;
    l11 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
    if (l10 != l11) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 587u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(16u, 0u, 0u, 187u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 179u);
    l12 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a5_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a5_obj, 250u);
    _a5_obj->f_ekeys = l2;
    _a5_obj->f_evals = l4;
    _a5_obj->f_index = l12;
    _a5_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a5_obj;
    l4 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_bindings;
    l12 = ((vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l4)->f_ekeys;
    l13 = ((vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l4)->f_evals;
    l10 = ((vader_struct_std_collections_MutableMap__i32__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue_t*) l4)->f_size;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_141: {
            if ((l11 >= l10)) {
            } else {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l12);
                if (_a6_slotarr->buf != NULL && _a6_slotarr->buf->header.forward != NULL) { _a6_slotarr->buf = vader_array_buf_forward(_a6_slotarr->buf); }
                if ((size_t) l11 >= _a6_slotarr->length) { vader_trap("array index out of bounds"); }
                l9 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l11];
                vader_array_t* _a7_slotarr = ((vader_array_t*) l13);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l11 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                l14 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l11);
                l15 = l9;
                l16 = l14;
                t5 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t5;
                std_collections_MutableMap_IndexSet_set_at__i32__Any(l2, l15, l16);
                goto loop_141;
            }
        }
    }
    l10 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
    l11 = (size_t) (int64_t) INT64_C(0);
    {
        loop_177: {
            if ((l11 < l10)) {
                vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args);
                if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                if ((size_t) l11 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l11);
                l4 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1);
                if (((vader_struct_vader_comptime_EvalResult_t*) l4)->f_value.tag == 0u) {
                    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t0 = l5.payload.obj;
                vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params);
                if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                if ((size_t) l11 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l11);
                l13 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
                l8 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l12)->f_span);
                l14 = std_collections_MutableMap_Index_at__u64__Any(l13, l8);
                if (l14.tag == 0u) {
                    t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 594u);
                    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t0 = l14.payload.obj;
                l9 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
                l16 = ((vader_struct_vader_comptime_EvalResult_t*) l4)->f_value;
                std_collections_MutableMap_IndexSet_set_at__i32__Any(l2, l9, l16);
                t5 = (l11 + INT64_C(1));
                l11 = (size_t) (int64_t) t5;
                goto loop_177;
            }
        }
    }
    l4 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed;
    l6 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    vader_struct_vader_comptime_ComptimeContext_t* _a10_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a10_obj, 650u);
    _a10_obj->f_typed = l4;
    _a10_obj->f_bindings = l2;
    _a10_obj->f_depth = l6;
    l2 = (void*) _a10_obj;
    l4 = l5.payload.obj;
    l12 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
    t0 = vader_comptime_evaluate_fn_body(l4, l2, l12);
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
    vader_obj_header_init(_a0_obj, 649u);
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
    vader_string_t l5 = 0;
    int64_t l6;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l7, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    if ((t0 >= INT64_C(2000))) {
        l2 = vader_comptime_span_of(l0);
        l3 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(93));
        l4 = (size_t) (int64_t) INT64_C(0);
        l4 = std_core_write_string_at(l3, l4, 1214u);
        l4 = std_core_write_int(l3, l4, INT64_C(2000));
        l4 = std_core_write_string_at(l3, l4, 158u);
        l5 = std_core_finish_buffer(l3, l4);
        t1 = vader_comptime_vm_required(l2, l5);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    l6 = (t0 + INT64_C(1));
    ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth = l6;
    if (l0.tag == 404u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_int_lit(t1);
    } else {
        if (l0.tag == 388u) {
            t1 = l0.payload.obj;
            l2 = vader_comptime_evaluate_float_lit(t1);
        } else {
            if (l0.tag == 367u) {
                t1 = l0.payload.obj;
                l2 = vader_comptime_evaluate_bool_lit(t1);
            } else {
                if (l0.tag == 372u) {
                    t1 = l0.payload.obj;
                    l2 = vader_comptime_evaluate_char_lit(t1);
                } else {
                    if (l0.tag == 417u) {
                        t1 = l0.payload.obj;
                        l2 = vader_comptime_evaluate_null_lit(t1);
                    } else {
                        if (l0.tag == 428u) {
                            l3 = l0.payload.obj;
                            l7 = (void*) &vader_fn_static_vader_comptime_evaluate_expr;
                            l2 = vader_comptime_evaluate_string_lit(l3, l1, l7);
                        } else {
                            if (l0.tag == 394u) {
                                t1 = l0.payload.obj;
                                l2 = vader_comptime_evaluate_ident(t1, l1);
                            } else {
                                if (l0.tag == 364u) {
                                    l3 = l0.payload.obj;
                                    l7 = (void*) &vader_fn_static_vader_comptime_evaluate_expr;
                                    l2 = vader_comptime_evaluate_binary_expr(l3, l1, l7);
                                } else {
                                    if (l0.tag == 443u) {
                                        l3 = l0.payload.obj;
                                        l7 = (void*) &vader_fn_static_vader_comptime_evaluate_expr;
                                        l2 = vader_comptime_evaluate_unary_expr(l3, l1, l7);
                                    } else {
                                        if (l0.tag == 405u) {
                                            t1 = l0.payload.obj;
                                            l2 = vader_comptime_evaluate_intrinsic_call(t1, l1);
                                        } else {
                                            if (l0.tag == 370u) {
                                                t1 = l0.payload.obj;
                                                l2 = vader_comptime_evaluate_call_expr(t1, l1);
                                            } else {
                                                if (l0.tag == 426u) {
                                                    l3 = l0.payload.obj;
                                                    l7 = (void*) &vader_fn_static_vader_comptime_evaluate_expr;
                                                    l2 = vader_comptime_evaluate_seq_lit(l3, l1, l7);
                                                } else {
                                                    l3 = vader_comptime_span_of(l0);
                                                    l5 = vader_typecheck_expr_kind_name(l0);
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
    void* t0 = NULL;
    void* t3 = NULL;
    vader_box_t t1 = vader_box_null();
    size_t t2;
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &t0, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body.tag == 0u) {
        t0 = vader_comptime_vm_required(l2, 590u);
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
        t0 = vader_comptime_vm_required(l2, 588u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_stmts)->length;
    if (t2 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_stmts);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        l4 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        if (l4.tag == 425u) {
            t0 = l4.payload.obj;
            if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
                t0 = l4.payload.obj;
                t3 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
                { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    t0 = vader_comptime_vm_required(l2, 589u);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_ident(void* l0, void* l1) {
    void* l2 = NULL;
    uint64_t l3;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    int32_t l5;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l6, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
    l3 = toolchain_span_Span_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span);
    l4 = std_collections_MutableMap_Index_at__u64__Any(l2, l3);
    if (l4.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span, 632u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_bindings;
    t0 = l4.payload.obj;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
    l6 = std_collections_MutableMap_Index_at__i32__Any(l2, l5);
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
    }
    l2 = ((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span;
    t0 = l4.payload.obj;
    l7 = vader_resolver_symbol_kind_name(((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_kind);
    l7 = concat_3(631u, l7, 344u);
    t0 = vader_comptime_vm_required(l2, l7);
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
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2100u) {
        t1 = vader_comptime_intrinsic_size_of(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1236u) {
        t1 = vader_comptime_intrinsic_align_of(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2290u) {
        t1 = vader_comptime_intrinsic_type_name(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2288u) {
        t1 = vader_comptime_intrinsic_type_kind(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1651u) {
        t1 = vader_comptime_intrinsic_field_count(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2480u) {
        t1 = vader_comptime_intrinsic_variant_count(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1653u) {
        t1 = vader_comptime_intrinsic_field_index(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
    l3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    l3 = concat_2(544u, l3);
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
    void* l17 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    size_t l8, l9, l18;
    vader_box_t l12 = vader_box_null(), l14 = vader_box_null(), l19 = vader_box_null(), l22 = vader_box_null();
    int32_t l21, l24;
    int64_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[5] = { &l12, &l14, &l19, &l22, &t2 };
    void** gc_raw_roots[16] = { &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l10, &l11, &l13, &l15, &l16, &l17, &l20, &l23, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
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
            }
        }
    }
    l7 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
    vader_struct_vader_comptime_ComptimeContext_t* _a1_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a1_obj, 650u);
    _a1_obj->f_typed = l1;
    _a1_obj->f_bindings = l7;
    _a1_obj->f_depth = INT64_C(0);
    l7 = (void*) _a1_obj;
    l6 = ((vader_struct_vader_comptime_ComptimeOrder_t*) l6)->f_order;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_45: {
            if ((l9 < l8)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l9 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
                l11 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ConstDecl_t*) l10)->f_value, l7);
                t1 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_vm_required;
                if (t1) {
                    l12 = vader_typecheck_lookup_const_symbol(l10, l1);
                    if (l12.tag == 862u) {
                        l13 = l12.payload.obj;
                        l14 = vader_comptime_build_vm_required(l10, l13, l1, l4);
                        if (l14.tag == 666u) {
                            l15 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_vm_required;
                            l16 = l14.payload.obj;
                            vader_array_push((vader_array_t*) l15, vader_ref_box(l16));
                            t0 = (l9 + INT64_C(1));
                            l9 = (size_t) (int64_t) t0;
                            goto loop_45;
                        }
                        if (!(((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag.tag == 0u)) {
                            t2 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag;
                            l17 = t2.payload.obj;
                            vader_array_push((vader_array_t*) l5, vader_ref_box(l17));
                        }
                        l18 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l9 + l18);
                        l9 = (size_t) (int64_t) t0;
                        goto loop_45;
                    }
                    if (!(((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag.tag == 0u)) {
                        t2 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag;
                        l17 = t2.payload.obj;
                        vader_array_push((vader_array_t*) l5, vader_ref_box(l17));
                    }
                    l18 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l9 + l18);
                    l9 = (size_t) (int64_t) t0;
                    goto loop_45;
                }
                if (!(((vader_struct_vader_comptime_EvalResult_t*) l11)->f_value.tag == 0u)) {
                    l19 = vader_typecheck_lookup_const_symbol(l10, l1);
                    if (!(l19.tag == 0u)) {
                        l20 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
                        t3 = l19.payload.obj;
                        l21 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t3)->f_id;
                        l22 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_value;
                        std_collections_MutableMap_IndexSet_set_at__i32__Any(l20, l21, l22);
                    }
                }
                if (!(((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag.tag == 0u)) {
                    t2 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag;
                    l23 = t2.payload.obj;
                    vader_array_push((vader_array_t*) l5, vader_ref_box(l23));
                }
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                goto loop_45;
            }
        }
    }
    l6 = l0;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) (int64_t) INT64_C(0);
    {
        loop_179: {
            if ((l9 < l8)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
                if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                if ((size_t) l9 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                l12 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
                if (l12.tag == 373u) {
                    t3 = l12.payload.obj;
                    t1 = vader_comptime_has_comptime_decorator(t3);
                    if (t1) {
                        t0 = (l9 + INT64_C(1));
                        l9 = (size_t) (int64_t) t0;
                        goto loop_179;
                    }
                    t3 = l12.payload.obj;
                    l14 = vader_typecheck_lookup_const_symbol(t3, l1);
                    if (l14.tag == 0u) {
                        t0 = (l9 + INT64_C(1));
                        l9 = (size_t) (int64_t) t0;
                        goto loop_179;
                    }
                    l10 = l14.payload.obj;
                    if (((vader_obj_header_t*) l10)->type_index == 862u) {
                        l11 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
                        l21 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_id;
                        t2 = std_collections_MutableMap_Index_at__i32__Any(l11, l21);
                        if (!(t2.tag == 0u)) {
                            t0 = (l9 + INT64_C(1));
                            l9 = (size_t) (int64_t) t0;
                            goto loop_179;
                        }
                        t3 = l12.payload.obj;
                        l13 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ConstDecl_t*) t3)->f_value, l7);
                        if (!(((vader_struct_vader_comptime_EvalResult_t*) l13)->f_value.tag == 0u)) {
                            l15 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
                            l24 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_id;
                            l19 = ((vader_struct_vader_comptime_EvalResult_t*) l13)->f_value;
                            std_collections_MutableMap_IndexSet_set_at__i32__Any(l15, l24, l19);
                        }
                        l18 = (size_t) (int64_t) INT64_C(1);
                        t0 = (l9 + l18);
                        l9 = (size_t) (int64_t) t0;
                        goto loop_179;
                    }
                    l18 = (size_t) (int64_t) INT64_C(1);
                    t0 = (l9 + l18);
                    l9 = (size_t) (int64_t) t0;
                    goto loop_179;
                }
                l18 = (size_t) (int64_t) INT64_C(1);
                t0 = (l9 + l18);
                l9 = (size_t) (int64_t) t0;
                goto loop_179;
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
    vader_obj_header_init(_a0_obj, 662u);
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
    void* l11 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    size_t l7, l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_box_t l13 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[2] = { &l13, &t0 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l11, &l12, &l14, &l15, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
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
                l10 = l9;
                l11 = l4;
                t1 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t1;
                l12 = vader_comptime_new_evaluated_program(l11);
                l13 = vader_comptime_lookup_module_decls(l0, l10);
                if (!(l13.tag == 0u)) {
                    t2 = l13.payload.obj;
                    vader_comptime_evaluate_module_decls(t2, l11, l12, l3, l10, l2);
                    l14 = l13.payload.obj;
                    l15 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l12)->f_comptime_decls;
                    vader_comptime_evaluate_assert_decls(l14, l11, l15, l2);
                    t2 = l13.payload.obj;
                    vader_comptime_bake_file_exprs(t2, l11, l3, l12, l2);
                }
                std_collections_MutableMap_IndexSet_set_at__string__Any(((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_modules, l10, vader_ref_box(l12));
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
    vader_string_t l12 = 0;
    vader_box_t t0 = vader_box_null(), t1 = vader_box_null();
    int64_t t2;
    void* t3 = NULL;
    void* t5 = NULL;
    vader_string_t t4 = 0;
    vader_box_t* gc_roots[4] = { &l8, &l13, &t0, &t1 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l7, &l9, &t3, &t5 };
    vader_string_t* gc_atom_roots[2] = { &l12, &t4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(136u, 0u, 13u, 1130u);
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
            }
        }
    }
    l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_expr_types;
    l5 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l0)->f_id;
    l8 = std_collections_MutableMap_Index_at__usize__Any(l4, l5);
    if (l8.tag == 903u) {
        vader_array_t* _a3_arr = vader_array_new(8u, 0u, 0u, 176u);
        l4 = (void*) _a3_arr;
        vader_array_t* _a4_arr = vader_array_new(16u, 0u, 0u, 187u);
        l7 = (void*) _a4_arr;
        vader_array_t* _a5_arr = vader_array_new(9u, 0u, 7u, 179u);
        l9 = (void*) _a5_arr;
        vader_struct_std_collections_MutableMap__string__Any_t* _a6_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
        vader_obj_header_init(_a6_obj, 289u);
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
            loop_72: {
                if ((l6 < l5)) {
                    l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(21));
                    l10 = (size_t) (int64_t) INT64_C(0);
                    l10 = std_core_write_string_at(l7, l10, 892u);
                    t2 = ((int64_t) (size_t) l6);
                    l11 = (uint64_t) (int64_t) t2;
                    l10 = std_core_write_unsigned(l7, l10, l11);
                    l12 = std_core_finish_buffer(l7, l10);
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                    if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                    if ((size_t) l6 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                    l13 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l6);
                    std_collections_MutableMap_IndexSet_set_at__string__Any(l4, l12, l13);
                    t2 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    goto loop_72;
                }
            }
        }
        t3 = l8.payload.obj;
        t4 = vader_types_display_type_key(vader_ref_box(t3));
        vader_struct_vader_comptime_StructValue_t* _a8_obj = (vader_struct_vader_comptime_StructValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_StructValue_t));
        vader_obj_header_init(_a8_obj, 664u);
        _a8_obj->f_type_name = t4;
        _a8_obj->f_fields = l4;
        t3 = (void*) _a8_obj;
        t5 = vader_comptime_ok(vader_ref_box(t3));
        { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l12 = 0u;
    if (l8.tag == 890u) {
        t3 = l8.payload.obj;
        l12 = vader_types_display_type_key(((vader_struct_vader_types_ArrayType_t*) t3)->f_element);
    }
    vader_struct_vader_comptime_ArrayValue_t* _a9_obj = (vader_struct_vader_comptime_ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ArrayValue_t));
    vader_obj_header_init(_a9_obj, 647u);
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
    size_t l5, l6;
    vader_box_t l7 = vader_box_null();
    vader_string_t l8 = 0;
    vader_string_t l10 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l7, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l9, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l10, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 359u);
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
                if (l7.tag == 430u) {
                    t0 = l7.payload.obj;
                    l8 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_value;
                    std_string_builder_append(l3, l8);
                } else {
                    if (l7.tag == 429u) {
                        t0 = l7.payload.obj;
                        vader_fn_t* _a3_fnobj = (vader_fn_t*) l2;
                        t1 = ((vader_fn_erased_sig_2_t) _a3_fnobj->code)(_a3_fnobj->env, ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, vader_ref_box(l1));
                        l9 = t1.payload.obj;
                        if (((vader_struct_vader_comptime_EvalResult_t*) l9)->f_value.tag == 0u) {
                            { void* __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        l10 = vader_comptime_interp_value(((vader_struct_vader_comptime_EvalResult_t*) l9)->f_value);
                        std_string_builder_append(l3, l10);
                    } else {
                        vader_unreachable("unreachable return in vader_comptime$evaluate_string_lit");
                    }
                }
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_10;
            }
        }
    }
    t3 = std_string_builder_StringBuilder_Display_to_string(l3);
    t1 = vader_comptime_string_val(t3);
    t0 = vader_comptime_ok(t1);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_evaluate_unary_expr(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    size_t l4;
    vader_string_t l5 = 0;
    uint8_t l7;
    vader_box_t l8 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l8, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_operand, vader_ref_box(l1));
    l3 = t0.payload.obj;
    if (((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value.tag == 0u) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_id;
    l5 = vader_comptime_resolved_int_name(l1, l4);
    l7 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_op;
    if (l7 == INT32_C(0)) {
        l8 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
        l6 = vader_comptime_unary_neg(l0, l8);
    } else {
        if (l7 == INT32_C(1)) {
            l8 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
            l6 = vader_comptime_unary_not(l0, l8);
        } else {
            if (l7 == INT32_C(2)) {
                l8 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
                l6 = vader_comptime_unary_bit_not(l0, l8);
            } else {
                vader_unreachable("unreachable return in vader_comptime$evaluate_unary_expr");
            }
        }
    }
    t1 = vader_comptime_normalize_int_result(l6, l5);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_fail(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_EvalResult_t* _a0_obj = (vader_struct_vader_comptime_EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvalResult_t));
    vader_obj_header_init(_a0_obj, 652u);
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
    bool l3;
    if (l2 == INT32_C(0)) {
        l3 = l0 == l1;
    } else {
        if (l2 == INT32_C(1)) {
            l3 = l0 != l1;
        } else {
            if (l2 == INT32_C(2)) {
                l3 = (l0 < l1);
            } else {
                if (l2 == INT32_C(3)) {
                    l3 = (l0 <= l1);
                } else {
                    if (l2 == INT32_C(4)) {
                        l3 = (l0 > l1);
                    } else {
                        if (l2 == INT32_C(5)) {
                            l3 = (l0 >= l1);
                        } else {
                            vader_unreachable("unreachable return in vader_comptime$float_compare");
                        }
                    }
                }
            }
        }
    }
    return l3;
}

static vader_box_t vader_comptime_float_val(double l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_FloatValue_t* _a0_obj = (vader_struct_vader_comptime_FloatValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_FloatValue_t));
    vader_obj_header_init(_a0_obj, 655u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = 1616u;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_comptime_float_val_typed(double l0, vader_string_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_FloatValue_t* _a0_obj = (vader_struct_vader_comptime_FloatValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_FloatValue_t));
    vader_obj_header_init(_a0_obj, 655u);
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
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l31 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l37 = NULL;
    void* l38 = NULL;
    void* l39 = NULL;
    void* l42 = NULL;
    void* l44 = NULL;
    void* l45 = NULL;
    void* l46 = NULL;
    size_t l5, l6, l10, l11, l16, l17, l22, l23, l28, l29, l34, l35, l40, l41, l47, l48;
    vader_box_t l12 = vader_box_null(), l18 = vader_box_null(), l24 = vader_box_null(), l30 = vader_box_null(), l36 = vader_box_null(), l43 = vader_box_null(), l49 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int64_t t2;
    int32_t t3;
    void* t4 = NULL;
    vader_box_t* gc_roots[8] = { &l12, &l18, &l24, &l30, &l36, &l43, &l49, &t0 };
    void** gc_raw_roots[28] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l9, &l13, &l14, &l15, &l19, &l20, &l21, &l25, &l26, &l27, &l31, &l32, &l33, &l37, &l38, &l39, &l42, &l44, &l45, &l46, &t4 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 8u, 28u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 187u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 289u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(50u, 0u, 13u, 656u);
    l2 = (void*) _a4_arr;
    vader_struct_vader_comptime_InstanceRegistry_t* _a5_obj = (vader_struct_vader_comptime_InstanceRegistry_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_InstanceRegistry_t));
    vader_obj_header_init(_a5_obj, 657u);
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
                t1 = t0.payload.s;
                vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
                if (_a7_slotarr->buf != NULL && _a7_slotarr->buf->header.forward != NULL) { _a7_slotarr->buf = vader_array_buf_forward(_a7_slotarr->buf); }
                if ((size_t) l6 >= _a7_slotarr->length) { vader_trap("array index out of bounds"); }
                l2 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l6);
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                l7 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_decl_types;
                l8 = ((vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l7)->f_ekeys;
                l9 = ((vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l7)->f_evals;
                l10 = ((vader_struct_std_collections_MutableMap__i32__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l7)->f_size;
                l11 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_63: {
                        if ((l11 >= l10)) {
                        } else {
                            vader_array_t* _a8_slotarr = ((vader_array_t*) l8);
                            if (_a8_slotarr->buf != NULL && _a8_slotarr->buf->header.forward != NULL) { _a8_slotarr->buf = vader_array_buf_forward(_a8_slotarr->buf); }
                            if ((size_t) l11 >= _a8_slotarr->length) { vader_trap("array index out of bounds"); }
                            t3 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l11];
                            vader_array_t* _a9_slotarr = ((vader_array_t*) l9);
                            if (_a9_slotarr->buf != NULL && _a9_slotarr->buf->header.forward != NULL) { _a9_slotarr->buf = vader_array_buf_forward(_a9_slotarr->buf); }
                            if ((size_t) l11 >= _a9_slotarr->length) { vader_trap("array index out of bounds"); }
                            l12 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l11);
                            t2 = (l11 + INT64_C(1));
                            l11 = (size_t) (int64_t) t2;
                            vader_comptime_observe(l1, l12);
                            goto loop_63;
                        }
                    }
                }
                l13 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_expr_types;
                l14 = ((vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l13)->f_ekeys;
                l15 = ((vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l13)->f_evals;
                l16 = ((vader_struct_std_collections_MutableMap__usize__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l13)->f_size;
                l17 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_100: {
                        if ((l17 >= l16)) {
                        } else {
                            vader_array_t* _a10_slotarr = ((vader_array_t*) l14);
                            if (_a10_slotarr->buf != NULL && _a10_slotarr->buf->header.forward != NULL) { _a10_slotarr->buf = vader_array_buf_forward(_a10_slotarr->buf); }
                            if ((size_t) l17 >= _a10_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l17];
                            vader_array_t* _a11_slotarr = ((vader_array_t*) l15);
                            if (_a11_slotarr->buf != NULL && _a11_slotarr->buf->header.forward != NULL) { _a11_slotarr->buf = vader_array_buf_forward(_a11_slotarr->buf); }
                            if ((size_t) l17 >= _a11_slotarr->length) { vader_trap("array index out of bounds"); }
                            l18 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l17);
                            t2 = (l17 + INT64_C(1));
                            l17 = (size_t) (int64_t) t2;
                            vader_comptime_observe(l1, l18);
                            goto loop_100;
                        }
                    }
                }
                l19 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_local_types;
                l20 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l19)->f_ekeys;
                l21 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l19)->f_evals;
                l22 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l19)->f_size;
                l23 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_137: {
                        if ((l23 >= l22)) {
                        } else {
                            vader_array_t* _a12_slotarr = ((vader_array_t*) l20);
                            if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                            if ((size_t) l23 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = ((int64_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l23];
                            vader_array_t* _a13_slotarr = ((vader_array_t*) l21);
                            if (_a13_slotarr->buf != NULL && _a13_slotarr->buf->header.forward != NULL) { _a13_slotarr->buf = vader_array_buf_forward(_a13_slotarr->buf); }
                            if ((size_t) l23 >= _a13_slotarr->length) { vader_trap("array index out of bounds"); }
                            l24 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l23);
                            t2 = (l23 + INT64_C(1));
                            l23 = (size_t) (int64_t) t2;
                            vader_comptime_observe(l1, l24);
                            goto loop_137;
                        }
                    }
                }
                l25 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_param_types;
                l26 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l25)->f_ekeys;
                l27 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l25)->f_evals;
                l28 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l25)->f_size;
                l29 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_174: {
                        if ((l29 >= l28)) {
                        } else {
                            vader_array_t* _a14_slotarr = ((vader_array_t*) l26);
                            if (_a14_slotarr->buf != NULL && _a14_slotarr->buf->header.forward != NULL) { _a14_slotarr->buf = vader_array_buf_forward(_a14_slotarr->buf); }
                            if ((size_t) l29 >= _a14_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = ((int64_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l29];
                            vader_array_t* _a15_slotarr = ((vader_array_t*) l27);
                            if (_a15_slotarr->buf != NULL && _a15_slotarr->buf->header.forward != NULL) { _a15_slotarr->buf = vader_array_buf_forward(_a15_slotarr->buf); }
                            if ((size_t) l29 >= _a15_slotarr->length) { vader_trap("array index out of bounds"); }
                            l30 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l29);
                            t2 = (l29 + INT64_C(1));
                            l29 = (size_t) (int64_t) t2;
                            vader_comptime_observe(l1, l30);
                            goto loop_174;
                        }
                    }
                }
                l31 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_type_expr_types;
                l32 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l31)->f_ekeys;
                l33 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l31)->f_evals;
                l34 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l31)->f_size;
                l35 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_211: {
                        if ((l35 >= l34)) {
                        } else {
                            vader_array_t* _a16_slotarr = ((vader_array_t*) l32);
                            if (_a16_slotarr->buf != NULL && _a16_slotarr->buf->header.forward != NULL) { _a16_slotarr->buf = vader_array_buf_forward(_a16_slotarr->buf); }
                            if ((size_t) l35 >= _a16_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = ((int64_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l35];
                            vader_array_t* _a17_slotarr = ((vader_array_t*) l33);
                            if (_a17_slotarr->buf != NULL && _a17_slotarr->buf->header.forward != NULL) { _a17_slotarr->buf = vader_array_buf_forward(_a17_slotarr->buf); }
                            if ((size_t) l35 >= _a17_slotarr->length) { vader_trap("array index out of bounds"); }
                            l36 = vader_array_ref_load_box(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l35);
                            t2 = (l35 + INT64_C(1));
                            l35 = (size_t) (int64_t) t2;
                            vader_comptime_observe(l1, l36);
                            goto loop_211;
                        }
                    }
                }
                l37 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_impl_methods;
                l38 = ((vader_struct_std_collections_MutableMap__string__ImplMethod_t*) l37)->f_ekeys;
                l39 = ((vader_struct_std_collections_MutableMap__string__ImplMethod_t*) l37)->f_evals;
                l40 = ((vader_struct_std_collections_MutableMap__string__ImplMethod_t*) l37)->f_size;
                l41 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_248: {
                        if ((l41 >= l40)) {
                        } else {
                            vader_array_t* _a18_slotarr = ((vader_array_t*) l38);
                            if (_a18_slotarr->buf != NULL && _a18_slotarr->buf->header.forward != NULL) { _a18_slotarr->buf = vader_array_buf_forward(_a18_slotarr->buf); }
                            if ((size_t) l41 >= _a18_slotarr->length) { vader_trap("array index out of bounds"); }
                            t0 = vader_array_box_slots(_a18_slotarr->buf)[_a18_slotarr->offset + (size_t) l41];
                            t1 = t0.payload.s;
                            vader_array_t* _a19_slotarr = ((vader_array_t*) l39);
                            if (_a19_slotarr->buf != NULL && _a19_slotarr->buf->header.forward != NULL) { _a19_slotarr->buf = vader_array_buf_forward(_a19_slotarr->buf); }
                            if ((size_t) l41 >= _a19_slotarr->length) { vader_trap("array index out of bounds"); }
                            l42 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l41);
                            t2 = (l41 + INT64_C(1));
                            l41 = (size_t) (int64_t) t2;
                            l43 = ((vader_struct_vader_typecheck_ImplMethod_t*) l42)->f_ty;
                            vader_comptime_observe(l1, l43);
                            goto loop_248;
                        }
                    }
                }
                l44 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_impl_method_decl_types;
                l45 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l44)->f_ekeys;
                l46 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l44)->f_evals;
                l47 = ((vader_struct_std_collections_MutableMap__u64__AnyType___ArrayType___DistinctType___EnumType___FnType___FreeCharType___FreeFloatType___FreeIntType___NeverType___PrimitiveType___SelfType___StructType___TraitType___TupleType___TypeMetaType___TypeParamType___UnionType___UnresolvedType_t*) l44)->f_size;
                l48 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_288: {
                        if ((l48 >= l47)) {
                        } else {
                            vader_array_t* _a20_slotarr = ((vader_array_t*) l45);
                            if (_a20_slotarr->buf != NULL && _a20_slotarr->buf->header.forward != NULL) { _a20_slotarr->buf = vader_array_buf_forward(_a20_slotarr->buf); }
                            if ((size_t) l48 >= _a20_slotarr->length) { vader_trap("array index out of bounds"); }
                            t2 = ((int64_t*) _a20_slotarr->buf->slots)[_a20_slotarr->offset + (size_t) l48];
                            vader_array_t* _a21_slotarr = ((vader_array_t*) l46);
                            if (_a21_slotarr->buf != NULL && _a21_slotarr->buf->header.forward != NULL) { _a21_slotarr->buf = vader_array_buf_forward(_a21_slotarr->buf); }
                            if ((size_t) l48 >= _a21_slotarr->length) { vader_trap("array index out of bounds"); }
                            l49 = vader_array_ref_load_box(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l48);
                            t2 = (l48 + INT64_C(1));
                            l48 = (size_t) (int64_t) t2;
                            vader_comptime_observe(l1, l49);
                            goto loop_288;
                        }
                    }
                }
                goto loop_32;
            }
        }
    }
    t4 = vader_comptime_sorted_instances(l1);
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
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
                if (t1 == 1452u) {
                    return true;
                }
                t2 = (l3 + INT64_C(1));
                l3 = (size_t) (int64_t) t2;
                goto loop_7;
            }
        }
    }
    return false;
}

static vader_string_t vader_comptime_instance_args_key(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l4 = 0;
    size_t l2, l3;
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l1 = 0u;
    l2 = ((vader_array_t*) l0)->length;
    l3 = (size_t) (int64_t) INT64_C(0);
    {
        loop_8: {
            if ((l3 < l2)) {
                if ((l3 > INT64_C(0))) {
                    l1 = concat_2(l1, 393u);
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
            }
        }
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_comptime_int_compare(int64_t l0, int64_t l1, uint8_t l2) {
    bool l3;
    if (l2 == INT32_C(0)) {
        l3 = l0 == l1;
    } else {
        if (l2 == INT32_C(1)) {
            l3 = l0 != l1;
        } else {
            if (l2 == INT32_C(2)) {
                l3 = (l0 < l1);
            } else {
                if (l2 == INT32_C(3)) {
                    l3 = (l0 <= l1);
                } else {
                    if (l2 == INT32_C(4)) {
                        l3 = (l0 > l1);
                    } else {
                        if (l2 == INT32_C(5)) {
                            l3 = (l0 >= l1);
                        } else {
                            vader_unreachable("unreachable return in vader_comptime$int_compare");
                        }
                    }
                }
            }
        }
    }
    return l3;
}

static void* vader_comptime_int_div_check(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 658u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        if (t1 == INT64_C(0)) {
            t0 = vader_comptime_division_by_zero(l0, 459u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
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
    if (l2.tag == 658u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        if (t1 == INT64_C(0)) {
            t0 = vader_comptime_division_by_zero(l0, 278u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
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
    vader_obj_header_init(_a0_obj, 658u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = 1718u;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_box_t vader_comptime_int_val_typed(int64_t l0, vader_string_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_IntValue_t* _a0_obj = (vader_struct_vader_comptime_IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_IntValue_t));
    vader_obj_header_init(_a0_obj, 658u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_comptime_interp_value(vader_box_t l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    size_t l3;
    int64_t l4;
    bool l5;
    void* t0 = NULL;
    double t1;
    uint32_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 658u) {
        l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(20));
        l3 = (size_t) (int64_t) INT64_C(0);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        l3 = std_core_write_int(l2, l3, l4);
        l1 = std_core_finish_buffer(l2, l3);
    } else {
        if (l0.tag == 655u) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
            l1 = std_core_f64_Display_to_string(t1);
        } else {
            if (l0.tag == 648u) {
                l2 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(5));
                l3 = (size_t) (int64_t) INT64_C(0);
                t0 = l0.payload.obj;
                l5 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
                l3 = std_core_write_bool(l2, l3, l5);
                l1 = std_core_finish_buffer(l2, l3);
            } else {
                if (l0.tag == 663u) {
                    t0 = l0.payload.obj;
                    l1 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
                } else {
                    if (l0.tag == 649u) {
                        t0 = l0.payload.obj;
                        t2 = ((vader_struct_vader_comptime_CharValue_t*) t0)->f_value;
                        l1 = std_core_char_Display_to_string(((uint32_t) (uint32_t) t2));
                    } else {
                        if (l0.tag == 662u) {
                            l1 = 1996u;
                        } else {
                            if (l0.tag == 667u) {
                                l1 = 0u;
                            } else {
                                if (l0.tag == 647u) {
                                    t0 = l0.payload.obj;
                                    l1 = vader_comptime_display_value(vader_ref_box(t0));
                                } else {
                                    if (l0.tag == 664u) {
                                        t0 = l0.payload.obj;
                                        l1 = vader_comptime_display_value(vader_ref_box(t0));
                                    } else {
                                        if (l0.tag == 665u) {
                                            t0 = l0.payload.obj;
                                            l1 = vader_comptime_display_value(vader_ref_box(t0));
                                        } else {
                                            vader_unreachable("unreachable return in vader_comptime$interp_value");
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
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
        t1 = vader_comptime_arg_count_error(l0, 1236u, (size_t) (int64_t) INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1237u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_comptime_byte_align(l2);
    t2 = vader_comptime_int_val_typed(t3, 2391u);
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
        t1 = vader_comptime_arg_count_error(l0, 1651u, (size_t) (int64_t) INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1652u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_comptime_type_field_count(l2, l1);
    t2 = vader_comptime_int_val_typed(t3, 2391u);
    t1 = vader_comptime_ok(t2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_intrinsic_field_index(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l6 = vader_box_null();
    void* l4 = NULL;
    int32_t l5;
    size_t l7, l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    size_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    int64_t t3;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l6, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(2)) {
        t1 = vader_comptime_arg_count_error(l0, 1653u, (size_t) (int64_t) INT64_C(2));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1656u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
    if ((size_t) INT32_C(1) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(1));
    l3 = vader_comptime_static_string_arg(t2);
    if (l3.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1655u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 901u) {
        l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_struct_decls;
        t1 = l2.payload.obj;
        l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t1)->f_symbol)->f_id;
        l6 = std_collections_MutableMap_Index_at__i32__Any(l4, l5);
        if (l6.tag == 431u) {
            t1 = l6.payload.obj;
            l7 = ((vader_array_t*) ((vader_struct_toolchain_ast_StructDecl_t*) t1)->f_fields)->length;
            l8 = (size_t) (int64_t) INT64_C(0);
            {
                loop_62: {
                    if ((l8 < l7)) {
                        t1 = l6.payload.obj;
                        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StructDecl_t*) t1)->f_fields);
                        if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                        if ((size_t) l8 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
                        l9 = ((vader_struct_toolchain_ast_StructField_t*) t1)->f_name;
                        l10 = l3.payload.s;
                        if (l9 == l10) {
                            t2 = vader_comptime_int_val_typed(((int64_t) (size_t) l8), 2391u);
                            t1 = vader_comptime_ok(t2);
                            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
                        }
                        t3 = (l8 + INT64_C(1));
                        l8 = (size_t) (int64_t) t3;
                        goto loop_62;
                    }
                }
            }
            t1 = l2.payload.obj;
            l9 = vader_types_display_type(vader_ref_box(t1));
            l10 = l3.payload.s;
            l9 = concat_5(1654u, l9, 1014u, l10, 977u);
            t1 = vader_comptime_arg_error(l0, l9);
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = l2.payload.obj;
        l9 = vader_types_display_type(vader_ref_box(t1));
        l9 = concat_3(1657u, l9, 1065u);
        t1 = vader_comptime_arg_error(l0, l9);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = vader_types_display_type(l2);
    l9 = concat_3(1654u, l9, 1044u);
    t1 = vader_comptime_arg_error(l0, l9);
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
        t1 = vader_comptime_arg_count_error(l0, 2100u, (size_t) (int64_t) INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 2102u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_comptime_byte_size(l2);
    t2 = vader_comptime_int_val_typed(t3, 2391u);
    t1 = vader_comptime_ok(t2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_intrinsic_type_kind(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 2288u, (size_t) (int64_t) INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 2289u);
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
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 2290u, (size_t) (int64_t) INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 2291u);
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
        t1 = vader_comptime_arg_count_error(l0, 2480u, (size_t) (int64_t) INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
    if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 2481u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t3 = vader_comptime_type_variant_count(l2);
    t2 = vader_comptime_int_val_typed(t3, 2391u);
    t1 = vader_comptime_ok(t2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static bool vader_comptime_is_concrete_enough(vader_box_t l0) {
    if ((l0.tag == 894u || l0.tag == 895u || l0.tag == 896u || l0.tag == 900u || l0.tag == 907u)) {
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
    if (l0.tag == 907u) {
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
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l3 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules, l1);
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
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = vader_types_strip_distinct(l0);
    t1 = vader_types_display_type_key(t0);
    t2 = vader_comptime_sanitise_ident(t1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_mask_shift_amount(vader_box_t l0, vader_string_t l1) {
    int64_t l2, l3;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 658u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        l3 = vader_comptime_shift_amount_mask(l1);
        l2 = (l2 & l3);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
        t1 = vader_comptime_int_val_typed(l2, l4);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(9u, 0u, 7u, 179u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 187u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 250u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_struct_vader_comptime_EvaluatedProgram_t* _a4_obj = (vader_struct_vader_comptime_EvaluatedProgram_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvaluatedProgram_t));
    vader_obj_header_init(_a4_obj, 653u);
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
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(16u, 0u, 0u, 187u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(9u, 0u, 7u, 179u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 289u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a3_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 179u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 0u, 187u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(9u, 0u, 7u, 179u);
    l4 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a7_obj, 250u);
    _a7_obj->f_ekeys = l2;
    _a7_obj->f_evals = l3;
    _a7_obj->f_index = l4;
    _a7_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a7_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l2 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(15u, 0u, 4u, 186u);
    l3 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(8u, 0u, 0u, 176u);
    l4 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__usize__string_t* _a11_obj = (vader_struct_std_collections_MutableMap__usize__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__string_t));
    vader_obj_header_init(_a11_obj, 346u);
    _a11_obj->f_ekeys = l3;
    _a11_obj->f_evals = l4;
    _a11_obj->f_index = l5;
    _a11_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a11_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(50u, 0u, 13u, 656u);
    l4 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(51u, 0u, 13u, 666u);
    l5 = (void*) _a13_arr;
    vader_struct_vader_comptime_EvaluatedProject_t* _a14_obj = (vader_struct_vader_comptime_EvaluatedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvaluatedProject_t));
    vader_obj_header_init(_a14_obj, 654u);
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
    vader_string_t l4 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_comptime_EvalResult_t*) l0)->f_value.tag == 658u) {
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
    vader_obj_header_init(_a0_obj, 652u);
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
                l7 = std_collections_MutableMap_Index_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_id, l5);
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
                std_collections_MutableMap_IndexSet_set_at__i32__usize(l10, l11, l5);
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_7;
            }
        }
    }
    l2 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_70: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
                l5 = (size_t) (int64_t) t0;
                l7 = std_collections_MutableMap_Index_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_id, l5);
                if (l7.tag == 0u) {
                    t0 = (l4 + INT64_C(1));
                    l4 = (size_t) (int64_t) t0;
                    goto loop_70;
                }
                l6 = l7.payload.obj;
                vader_array_t* _a2_arr = vader_array_new(15u, 0u, 4u, 186u);
                l8 = (void*) _a2_arr;
                vader_array_t* _a3_arr = vader_array_new(6u, 0u, 12u, 174u);
                l10 = (void*) _a3_arr;
                vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 179u);
                l12 = (void*) _a4_arr;
                vader_struct_std_collections_MutableMap__usize__bool_t* _a5_obj = (vader_struct_std_collections_MutableMap__usize__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__bool_t));
                vader_obj_header_init(_a5_obj, 344u);
                _a5_obj->f_ekeys = l8;
                _a5_obj->f_evals = l10;
                _a5_obj->f_index = l12;
                _a5_obj->f_mask = (size_t) (int64_t) INT64_C(0);
                _a5_obj->f_size = (size_t) (int64_t) INT64_C(0);
                _a5_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
                l13 = (void*) _a5_obj;
                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l6)->f_decl)->f_value, l1, l0, l13, l6);
                std_collections_MutableMap_IndexSet_set_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_id, l5, vader_ref_box(l6));
                t0 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t0;
                goto loop_70;
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_read_relative_file(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_string_starts_with(l0, 459u);
    if (t0) {
        l2 = l0;
    } else {
        if (l1 == 0u) {
            l2 = l0;
        } else {
            l2 = concat_3(l1, 459u, l0);
        }
    }
    l3 = std_io_read_file_string(l2, (size_t) (int64_t) INT64_C(16777216));
    if (l3.tag == 176u) {
        t1 = l3.payload.s;
        t2 = vader_box_string(176u, t1);
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
    vader_string_t l6 = 0;
    uint64_t l8;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 359u);
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
                    std_string_builder_append(l1, 394u);
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
            }
        }
    }
    if (l4) {
        l7 = std_core_new_byte_buffer((size_t) (int64_t) INT64_C(35));
        l3 = (size_t) (int64_t) INT64_C(0);
        l3 = std_core_write_string_at(l7, l3, 401u);
        t1 = ((int64_t) (size_t) l2);
        l8 = (uint64_t) (int64_t) t1;
        l3 = std_core_write_unsigned(l7, l3, l8);
        l3 = std_core_write_string_at(l7, l3, 122u);
        l6 = std_core_finish_buffer(l7, l3);
        std_string_builder_append(l1, l6);
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
    vader_string_t l2 = 0;
    vader_string_t l9 = 0;
    size_t l5, l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[3] = { &l7, &l8, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l9, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 359u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = ((vader_struct_vader_comptime_StructValue_t*) l0)->f_type_name;
    std_string_builder_append(l1, l2);
    std_string_builder_append(l1, 194u);
    l3 = std_collections_keys__string__ArrayValue___BoolValue___CharValue___FloatValue___IntValue___NullValue___StringValue___StructValue___TypeValue___VoidValue(((vader_struct_vader_comptime_StructValue_t*) l0)->f_fields);
    vader_struct___lambda_env_vader_comptime_3_t* _a2_obj = (vader_struct___lambda_env_vader_comptime_3_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_comptime_3_t));
    vader_obj_header_init(_a2_obj, 217u);
    t0 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 149u);
    _a3_closure->code = (void*) &vader_fn_lift___lambda_vader_comptime_2;
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
                l8 = std_collections_MutableMap_Index_at__string__Any(((vader_struct_vader_comptime_StructValue_t*) l0)->f_fields, l2);
                if (l8.tag == 0u) {
                    t2 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    goto loop_27;
                }
                l7 = l8;
                if ((l6 > INT64_C(0))) {
                    std_string_builder_append(l1, 394u);
                }
                std_string_builder_append_char(l1, 46u);
                std_string_builder_append(l1, l2);
                std_string_builder_append(l1, 73u);
                l9 = vader_comptime_display_value(l7);
                std_string_builder_append(l1, l9);
                t2 = (l6 + INT64_C(1));
                l6 = (size_t) (int64_t) t2;
                goto loop_27;
            }
        }
    }
    std_string_builder_append(l1, 219u);
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
    if (l4.tag == 907u) {
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
    l2 = std_collections_MutableMap_Index_at__usize__Any(((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l0)->f_typed)->f_expr_types, l1);
    if (l2.tag == 899u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        return t1;
    }
    if (l2.tag == 896u) {
        return 1718u;
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
    vader_string_t t3 = 0;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(8u, 0u, 0u, 176u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 359u);
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
    if (l0 == 1762u) {
        l1 = true;
    } else {
        l1 = l0 == 2347u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1717u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2328u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1718u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2329u;
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
    vader_struct___lambda_env_vader_comptime_1_t* _a0_obj = (vader_struct___lambda_env_vader_comptime_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_comptime_1_t));
    vader_obj_header_init(_a0_obj, 216u);
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 159u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_comptime_0;
    _a1_closure->env = t0;
    l2 = (void*) _a1_closure;
    t0 = std_sort_sort__GenericInstance(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_comptime_span_of(vader_box_t l0) {
    void* l1;
    void* t0;
    if (l0.tag == 404u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_IntLitExpr_t*) t0)->f_span;
    } else {
        if (l0.tag == 416u) {
            t0 = l0.payload.obj;
            l1 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_span;
        } else {
            if (l0.tag == 388u) {
                t0 = l0.payload.obj;
                l1 = ((vader_struct_toolchain_ast_FloatLitExpr_t*) t0)->f_span;
            } else {
                if (l0.tag == 367u) {
                    t0 = l0.payload.obj;
                    l1 = ((vader_struct_toolchain_ast_BoolLitExpr_t*) t0)->f_span;
                } else {
                    if (l0.tag == 417u) {
                        t0 = l0.payload.obj;
                        l1 = ((vader_struct_toolchain_ast_NullLitExpr_t*) t0)->f_span;
                    } else {
                        if (l0.tag == 372u) {
                            t0 = l0.payload.obj;
                            l1 = ((vader_struct_toolchain_ast_CharLitExpr_t*) t0)->f_span;
                        } else {
                            if (l0.tag == 428u) {
                                t0 = l0.payload.obj;
                                l1 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_span;
                            } else {
                                if (l0.tag == 394u) {
                                    t0 = l0.payload.obj;
                                    l1 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span;
                                } else {
                                    if (l0.tag == 370u) {
                                        t0 = l0.payload.obj;
                                        l1 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_span;
                                    } else {
                                        if (l0.tag == 387u) {
                                            t0 = l0.payload.obj;
                                            l1 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_span;
                                        } else {
                                            if (l0.tag == 402u) {
                                                t0 = l0.payload.obj;
                                                l1 = ((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_span;
                                            } else {
                                                if (l0.tag == 443u) {
                                                    t0 = l0.payload.obj;
                                                    l1 = ((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_span;
                                                } else {
                                                    if (l0.tag == 364u) {
                                                        t0 = l0.payload.obj;
                                                        l1 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_span;
                                                    } else {
                                                        if (l0.tag == 397u) {
                                                            t0 = l0.payload.obj;
                                                            l1 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_span;
                                                        } else {
                                                            if (l0.tag == 411u) {
                                                                t0 = l0.payload.obj;
                                                                l1 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_span;
                                                            } else {
                                                                if (l0.tag == 366u) {
                                                                    t0 = l0.payload.obj;
                                                                    l1 = ((vader_struct_toolchain_ast_BlockExpr_t*) t0)->f_span;
                                                                } else {
                                                                    if (l0.tag == 407u) {
                                                                        t0 = l0.payload.obj;
                                                                        l1 = ((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_span;
                                                                    } else {
                                                                        if (l0.tag == 433u) {
                                                                            t0 = l0.payload.obj;
                                                                            l1 = ((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_span;
                                                                        } else {
                                                                            if (l0.tag == 426u) {
                                                                                t0 = l0.payload.obj;
                                                                                l1 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_span;
                                                                            } else {
                                                                                if (l0.tag == 422u) {
                                                                                    t0 = l0.payload.obj;
                                                                                    l1 = ((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_span;
                                                                                } else {
                                                                                    if (l0.tag == 363u) {
                                                                                        t0 = l0.payload.obj;
                                                                                        l1 = ((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_span;
                                                                                    } else {
                                                                                        if (l0.tag == 371u) {
                                                                                            t0 = l0.payload.obj;
                                                                                            l1 = ((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_span;
                                                                                        } else {
                                                                                            if (l0.tag == 393u) {
                                                                                                t0 = l0.payload.obj;
                                                                                                l1 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_span;
                                                                                            } else {
                                                                                                if (l0.tag == 405u) {
                                                                                                    t0 = l0.payload.obj;
                                                                                                    l1 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_span;
                                                                                                } else {
                                                                                                    if (l0.tag == 382u) {
                                                                                                        t0 = l0.payload.obj;
                                                                                                        l1 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_span;
                                                                                                    } else {
                                                                                                        if (l0.tag == 391u) {
                                                                                                            t0 = l0.payload.obj;
                                                                                                            l1 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_span;
                                                                                                        } else {
                                                                                                            if (l0.tag == 360u) {
                                                                                                                t0 = l0.payload.obj;
                                                                                                                l1 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
                                                                                                            } else {
                                                                                                                if (l0.tag == 413u) {
                                                                                                                    t0 = l0.payload.obj;
                                                                                                                    l1 = ((vader_struct_toolchain_ast_MutableTypeExpr_t*) t0)->f_span;
                                                                                                                } else {
                                                                                                                    vader_unreachable("unreachable return in vader_comptime$span_of");
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

static vader_box_t vader_comptime_static_string_arg(vader_box_t l0) {
    void* t0;
    size_t t1;
    vader_box_t t2;
    vader_string_t t3;
    if (l0.tag == 428u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts)->length;
        if (t1 == INT64_C(1)) {
            t0 = l0.payload.obj;
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts);
            if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
            if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
            t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
            if (t2.tag == 430u) {
                t0 = l0.payload.obj;
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) INT32_C(0) >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                t0 = t2.payload.obj;
                t3 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_value;
                t2 = vader_box_string(176u, t3);
                return t2;
            }
        }
    }
    t2 = vader_box_obj(0u, NULL);
    return t2;
}

vader_box_t vader_comptime_string_val(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_StringValue_t* _a0_obj = (vader_struct_vader_comptime_StringValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_StringValue_t));
    vader_obj_header_init(_a0_obj, 663u);
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
    if (((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_defined_at.tag == 450u) {
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
    vader_box_t l2 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l0.tag == 389u) {
        t0 = l0.payload.obj;
        l2 = vader_comptime_symbol_for_fn(t0, l1);
    } else {
        if (l0.tag == 431u) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_name;
            l2 = vader_comptime_symbol_for_kind(t1, INT32_C(1), l1);
        } else {
            if (l0.tag == 373u) {
                t0 = l0.payload.obj;
                t1 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_name;
                l2 = vader_comptime_symbol_for_kind(t1, INT32_C(6), l1);
            } else {
                if (l0.tag == 383u) {
                    t0 = l0.payload.obj;
                    t1 = ((vader_struct_toolchain_ast_EnumDecl_t*) t0)->f_name;
                    l2 = vader_comptime_symbol_for_kind(t1, INT32_C(2), l1);
                } else {
                    if (l0.tag == 438u) {
                        t0 = l0.payload.obj;
                        t1 = ((vader_struct_toolchain_ast_TraitDecl_t*) t0)->f_name;
                        l2 = vader_comptime_symbol_for_kind(t1, INT32_C(3), l1);
                    } else {
                        if (l0.tag == 441u) {
                            t0 = l0.payload.obj;
                            t1 = ((vader_struct_toolchain_ast_TypeAliasDecl_t*) t0)->f_name;
                            l2 = vader_comptime_symbol_for_kind(t1, INT32_C(5), l1);
                        } else {
                            if (l0.tag == 398u) {
                                l2 = vader_box_obj(0u, NULL);
                            } else {
                                if (l0.tag == 361u) {
                                    l2 = vader_box_obj(0u, NULL);
                                } else {
                                    if (l0.tag == 399u) {
                                        l2 = vader_box_obj(0u, NULL);
                                    } else {
                                        vader_unreachable("unreachable return in vader_comptime$symbol_for_decl");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_box_t vader_comptime_symbol_for_fn(void* l0, void* l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l3 = 0;
    vader_box_t l4 = vader_box_null();
    size_t l5, l6;
    vader_string_t t0 = 0;
    vader_box_t t1 = vader_box_null();
    bool t2;
    int64_t t3;
    size_t t4;
    void* t5 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &t1 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l7, &l8, &t5 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved)->f_fn_overloads;
    l3 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_name;
    l4 = std_collections_MutableMap_Index_at__string__Any(l2, l3);
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
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 13u, 373u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(52u, 0u, 13u, 669u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(15u, 0u, 4u, 186u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(9u, 0u, 7u, 179u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(9u, 0u, 7u, 179u);
    l5 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__usize__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__usize__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__i32_t));
    vader_obj_header_init(_a5_obj, 345u);
    _a5_obj->f_ekeys = l3;
    _a5_obj->f_evals = l4;
    _a5_obj->f_index = l5;
    _a5_obj->f_mask = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_size = (size_t) (int64_t) INT64_C(0);
    _a5_obj->f_tombs = (size_t) (int64_t) INT64_C(0);
    l3 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(15u, 0u, 4u, 186u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(6u, 0u, 12u, 174u);
    l5 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(9u, 0u, 7u, 179u);
    l6 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__usize__bool_t* _a9_obj = (vader_struct_std_collections_MutableMap__usize__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__bool_t));
    vader_obj_header_init(_a9_obj, 344u);
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
                std_collections_MutableMap_IndexSet_set_at__usize__i32(l3, l9, INT32_C(0));
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                goto loop_39;
            }
        }
    }
    vader_array_t* _a11_arr = vader_array_new(15u, 0u, 4u, 186u);
    l5 = (void*) _a11_arr;
    l6 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) (int64_t) INT64_C(0);
    {
        loop_69: {
            if ((l8 < l7)) {
                vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
                if (_a12_slotarr->buf != NULL && _a12_slotarr->buf->header.forward != NULL) { _a12_slotarr->buf = vader_array_buf_forward(_a12_slotarr->buf); }
                if ((size_t) l8 >= _a12_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = ((int64_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l8];
                vader_comptime_visit((size_t) (int64_t) t0, l0, l3, l4, l5, (size_t) (int64_t) INT64_C(0), l1, l2);
                t0 = (l8 + INT64_C(1));
                l8 = (size_t) (int64_t) t0;
                goto loop_69;
            }
        }
    }
    vader_struct_vader_comptime_ComptimeOrder_t* _a13_obj = (vader_struct_vader_comptime_ComptimeOrder_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeOrder_t));
    vader_obj_header_init(_a13_obj, 651u);
    _a13_obj->f_order = l1;
    _a13_obj->f_cycle_diags = l2;
    t1 = (void*) _a13_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int64_t vader_comptime_type_field_count(vader_box_t l0, void* l1) {
    void* l2;
    int32_t l3;
    vader_box_t l4;
    void* t0;
    size_t t1;
    if (l0.tag == 901u) {
        l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_struct_decls;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
        l4 = std_collections_MutableMap_Index_at__i32__Any(l2, l3);
        if (l4.tag == 431u) {
            t0 = l4.payload.obj;
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_fields)->length;
            return ((int64_t) (size_t) t1);
        }
        return INT64_C(0);
    }
    if (l0.tag == 903u) {
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

vader_string_t vader_comptime_type_kind_label(vader_box_t l0) {
    vader_string_t l1;
    void* t0;
    if (l0.tag == 899u) {
        l1 = 2034u;
    } else {
        if (l0.tag == 891u) {
            t0 = l0.payload.obj;
            l1 = vader_comptime_type_kind_label(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
        } else {
            if (l0.tag == 901u) {
                l1 = 2198u;
            } else {
                if (l0.tag == 892u) {
                    l1 = 1549u;
                } else {
                    if (l0.tag == 906u) {
                        l1 = 2363u;
                    } else {
                        if (l0.tag == 890u) {
                            l1 = 1260u;
                        } else {
                            if (l0.tag == 903u) {
                                l1 = 2263u;
                            } else {
                                if (l0.tag == 893u) {
                                    l1 = 1667u;
                                } else {
                                    if (l0.tag == 902u) {
                                        l1 = 2255u;
                                    } else {
                                        if (l0.tag == 904u) {
                                            l1 = 2269u;
                                        } else {
                                            if (l0.tag == 905u) {
                                                l1 = 2364u;
                                            } else {
                                                if (l0.tag == 900u) {
                                                    l1 = 2364u;
                                                } else {
                                                    if (l0.tag == 907u) {
                                                        l1 = 2364u;
                                                    } else {
                                                        if (l0.tag == 896u) {
                                                            l1 = 2364u;
                                                        } else {
                                                            if (l0.tag == 894u) {
                                                                l1 = 2364u;
                                                            } else {
                                                                if (l0.tag == 895u) {
                                                                    l1 = 2364u;
                                                                } else {
                                                                    if (l0.tag == 897u) {
                                                                        l1 = 2364u;
                                                                    } else {
                                                                        if (l0.tag == 889u) {
                                                                            l1 = 1253u;
                                                                        } else {
                                                                            vader_unreachable("unreachable return in vader_comptime$type_kind_label");
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
    }
    return l1;
}

static void* vader_comptime_type_mismatch(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
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
    vader_obj_header_init(_a0_obj, 665u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static int64_t vader_comptime_type_variant_count(vader_box_t l0) {
    void* t0;
    size_t t1;
    if (l0.tag == 906u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_types_UnionType_t*) t0)->f_variants)->length;
        return ((int64_t) (size_t) t1);
    }
    if (l0.tag == 892u) {
        t0 = l0.payload.obj;
        t1 = std_collections_len__string__i64(((vader_struct_vader_types_EnumType_t*) t0)->f_indices);
        return ((int64_t) (size_t) t1);
    }
    return INT64_C(0);
}

static void* vader_comptime_unary_bit_not(void* l0, vader_box_t l1) {
    int64_t l2;
    vader_string_t l3 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 658u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        l2 = vader_comptime_bit_not_i64(t1);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
        t2 = vader_comptime_int_val_typed(l2, l3);
        t0 = vader_comptime_ok(t2);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_unary_type_mismatch(l0, 1208u);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_unary_neg(void* l0, vader_box_t l1) {
    int64_t l2;
    vader_string_t l3 = 0;
    double l4;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    double t3;
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (l1.tag == 658u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        l2 = -(t1);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
        t2 = vader_comptime_int_val_typed(l2, l3);
        t0 = vader_comptime_ok(t2);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 655u) {
        t0 = l1.payload.obj;
        t3 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
        l4 = -(t3);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_type_name;
        t2 = vader_comptime_float_val_typed(l4, l3);
        t0 = vader_comptime_ok(t2);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_unary_type_mismatch(l0, 1128u);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l1.tag == 648u) {
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
        if (t1) {
            vader_struct_vader_comptime_BoolValue_t* _a0_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
            vader_obj_header_init(_a0_obj, 648u);
            _a0_obj->f_value = false;
            t0 = (void*) _a0_obj;
            t2 = vader_comptime_ok(vader_ref_box(t0));
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_comptime_BoolValue_t* _a1_obj = (vader_struct_vader_comptime_BoolValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_BoolValue_t));
        vader_obj_header_init(_a1_obj, 648u);
        _a1_obj->f_value = true;
        t0 = (void*) _a1_obj;
        t2 = vader_comptime_ok(vader_ref_box(t0));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_unary_type_mismatch(l0, 1103u);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_unary_type_mismatch(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_span;
    t0 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(6), l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_comptime_uniq(void* l0, vader_string_t l1) {
    int32_t l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    size_t l5, l7;
    void* l6 = NULL;
    int64_t l8;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableMap_Index_at__string__bool(l0, l1);
    if (t0.tag == 0u) {
        std_collections_MutableMap_IndexSet_set_at__string__bool(l0, l1, true);
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
                l7 = std_core_write_string_at(l6, l7, 892u);
                l8 = ((int64_t) (int32_t) l2);
                l7 = std_core_write_int(l6, l7, l8);
                l3 = std_core_finish_buffer(l6, l7);
                t0 = std_collections_MutableMap_Index_at__string__bool(l0, l3);
                if (t0.tag == 0u) {
                    std_collections_MutableMap_IndexSet_set_at__string__bool(l0, l3, true);
                    { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l2 = (l2 + INT32_C(1));
                goto loop_15;
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
    l9 = std_collections_MutableMap_Index_at__usize__i32(l2, l0);
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
    std_collections_MutableMap_IndexSet_set_at__usize__i32(l2, l0, INT32_C(1));
    l10 = ((vader_array_t*) l4)->length;
    if ((l5 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) l5 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5] = (int64_t) (int64_t) (size_t) l0;
    } else {
        vader_array_push_i64((vader_array_t*) l4, (int64_t) (size_t) l0);
    }
    l9 = std_collections_MutableMap_Index_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l1)->f_by_id, l0);
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
                }
            }
        }
    }
    std_collections_MutableMap_IndexSet_set_at__usize__i32(l2, l0, INT32_C(2));
    t2 = std_collections_MutableMap_Index_at__usize__bool(l3, l0);
    if (t2.tag == 0u) {
        l9 = std_collections_MutableMap_Index_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l1)->f_by_id, l0);
        if (!(l9.tag == 0u)) {
            t0 = l9.payload.obj;
            l11 = ((vader_struct_vader_comptime_NodeRecord_t*) t0)->f_decl;
            vader_array_push((vader_array_t*) l6, vader_ref_box(l11));
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

static void* vader_comptime_vm_required(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    l2 = vader_diagnostics_comptime_error((uint8_t) (int32_t) INT32_C(0), l0, l1);
    vader_struct_vader_comptime_EvalResult_t* _a0_obj = (vader_struct_vader_comptime_EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvalResult_t));
    vader_obj_header_init(_a0_obj, 652u);
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    _a0_obj->f_diag = vader_ref_box(l2);
    _a0_obj->f_vm_required = true;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static void vader_comptime_walk_type(void* l0, vader_box_t l1) {
    bool l2;
    void* l3 = NULL;
    void* l4 = NULL;
    size_t l5, l6;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    size_t t1;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l1, &l7 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 901u) {
        t0 = l1.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_args)->length;
        if ((t1 > INT64_C(0))) {
            t0 = l1.payload.obj;
            l2 = vader_comptime_all_concrete_enough(((vader_struct_vader_types_StructType_t*) t0)->f_args);
        } else {
            l2 = false;
        }
        if (l2) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_types_StructType_t*) t0)->f_symbol;
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
            vader_comptime_add(l0, l3, l4);
        }
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        l5 = ((vader_array_t*) l3)->length;
        l6 = (size_t) (int64_t) INT64_C(0);
        {
            loop_44: {
                if ((l6 < l5)) {
                    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                    if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                    if ((size_t) l6 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                    l7 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                    vader_comptime_walk_type(l0, l7);
                    t2 = (l6 + INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    goto loop_44;
                }
            }
        }
    } else {
        if (l1.tag == 892u) {
        } else {
            if (l1.tag == 902u) {
                t0 = l1.payload.obj;
                t1 = ((vader_array_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_args)->length;
                if ((t1 > INT64_C(0))) {
                    t0 = l1.payload.obj;
                    l2 = vader_comptime_all_concrete_enough(((vader_struct_vader_types_TraitType_t*) t0)->f_args);
                } else {
                    l2 = false;
                }
                if (l2) {
                    t0 = l1.payload.obj;
                    l3 = ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol;
                    t0 = l1.payload.obj;
                    l4 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
                    vader_comptime_add(l0, l3, l4);
                }
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
                l5 = ((vader_array_t*) l3)->length;
                l6 = (size_t) (int64_t) INT64_C(0);
                {
                    loop_113: {
                        if ((l6 < l5)) {
                            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
                            if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                            if ((size_t) l6 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                            l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
                            vader_comptime_walk_type(l0, l7);
                            t2 = (l6 + INT64_C(1));
                            l6 = (size_t) (int64_t) t2;
                            goto loop_113;
                        }
                    }
                }
            } else {
                if (l1.tag == 890u) {
                    t0 = l1.payload.obj;
                    l7 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
                    vader_comptime_walk_type(l0, l7);
                } else {
                    if (l1.tag == 903u) {
                        t0 = l1.payload.obj;
                        l3 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
                        l5 = ((vader_array_t*) l3)->length;
                        l6 = (size_t) (int64_t) INT64_C(0);
                        {
                            loop_157: {
                                if ((l6 < l5)) {
                                    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
                                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                                    if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                                    l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
                                    vader_comptime_walk_type(l0, l7);
                                    t2 = (l6 + INT64_C(1));
                                    l6 = (size_t) (int64_t) t2;
                                    goto loop_157;
                                }
                            }
                        }
                    } else {
                        if (l1.tag == 906u) {
                            t0 = l1.payload.obj;
                            l3 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
                            l5 = ((vader_array_t*) l3)->length;
                            l6 = (size_t) (int64_t) INT64_C(0);
                            {
                                loop_190: {
                                    if ((l6 < l5)) {
                                        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
                                        if (_a3_slotarr->buf != NULL && _a3_slotarr->buf->header.forward != NULL) { _a3_slotarr->buf = vader_array_buf_forward(_a3_slotarr->buf); }
                                        if ((size_t) l6 >= _a3_slotarr->length) { vader_trap("array index out of bounds"); }
                                        l7 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
                                        vader_comptime_walk_type(l0, l7);
                                        t2 = (l6 + INT64_C(1));
                                        l6 = (size_t) (int64_t) t2;
                                        goto loop_190;
                                    }
                                }
                            }
                        } else {
                            if (l1.tag == 893u) {
                                t0 = l1.payload.obj;
                                l3 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
                                l5 = ((vader_array_t*) l3)->length;
                                l6 = (size_t) (int64_t) INT64_C(0);
                                {
                                    loop_223: {
                                        if ((l6 < l5)) {
                                            vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
                                            if (_a4_slotarr->buf != NULL && _a4_slotarr->buf->header.forward != NULL) { _a4_slotarr->buf = vader_array_buf_forward(_a4_slotarr->buf); }
                                            if ((size_t) l6 >= _a4_slotarr->length) { vader_trap("array index out of bounds"); }
                                            l7 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
                                            vader_comptime_walk_type(l0, l7);
                                            t2 = (l6 + INT64_C(1));
                                            l6 = (size_t) (int64_t) t2;
                                            goto loop_223;
                                        }
                                    }
                                }
                                t0 = l1.payload.obj;
                                l7 = ((vader_struct_vader_types_FnType_t*) t0)->f_return_type;
                                vader_comptime_walk_type(l0, l7);
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
    if (l1 == 1762u) {
        l2 = true;
    } else {
        l2 = l1 == 2347u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 1717u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 2328u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 1718u;
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l1 == 2329u;
    }
    if (l2) {
        l3 = vader_comptime_sign_extend_32(l0);
    } else {
        l3 = l0;
    }
    return l3;
}

