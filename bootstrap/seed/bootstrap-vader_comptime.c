#include "bootstrap.split.h"

static void* vader_comptime_add(void* l0, void* l1, void* l2);
static bool vader_comptime_all_concrete_enough(void* l0);
static void* vader_comptime_arg_count_error(void* l0, vader_string_t l1, size_t l2);
static void* vader_comptime_arg_error(void* l0, vader_string_t l1);
static void* vader_comptime_arithmetic(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
static void* vader_comptime_arithmetic_int(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static void* vader_comptime_arithmetic_or_concat(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
static uint8_t vader_comptime_assert_verdict(vader_box_t l0);
static void vader_comptime_bake_file_exprs(void* l0, void* l1, void* l2);
static void vader_comptime_bake_one_file_expr(void* l0, vader_box_t l1, void* l2, void* l3, void* l4);
static int64_t vader_comptime_bit_not_i64(int64_t l0);
static void* vader_comptime_bool_equality_only(void* l0, bool l1, uint8_t l2);
static void* vader_comptime_bool_op(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static vader_box_t vader_comptime_bool_value(bool l0);
static vader_string_t vader_comptime_build_display_key(void* l0, void* l1);
static vader_box_t vader_comptime_build_vm_required(void* l0, void* l1, void* l2, vader_string_t l3);
static vader_string_t vader_comptime_canonical_type_key(vader_box_t l0);
static void* vader_comptime_checked_int(void* l0, void* l1, void* l2, vader_string_t l3);
static vader_box_t vader_comptime_checked_int_op(uint8_t l0, int64_t l1, bool l2, int64_t l3, int64_t l4);
static void* vader_comptime_checked_result(void* l0, vader_box_t l1, vader_string_t l2);
static void vader_comptime_collect_block_deps(void* l0, void* l1, void* l2, void* l3, void* l4);
static void vader_comptime_collect_expr_deps(vader_box_t l0, void* l1, void* l2, void* l3, void* l4);
static void vader_comptime_collect_file_intrinsics(vader_box_t l0, void* l1);
static void vader_comptime_collect_in_block(void* l0, void* l1);
static void vader_comptime_collect_in_expr(vader_box_t l0, void* l1);
static void vader_comptime_collect_in_stmt(vader_box_t l0, void* l1);
static void* vader_comptime_collect_nodes(void* l0);
static void vader_comptime_collect_stmt_deps(vader_box_t l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_comptime_combine_binary(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
static void* vader_comptime_compare(void* l0, vader_box_t l1, vader_box_t l2, uint8_t l3);
static vader_box_t vader_comptime_constant_name(vader_box_t l0);
static vader_string_t vader_comptime_cycle_names(size_t l0, size_t l1, void* l2, size_t l3, void* l4);
static void* vader_comptime_diag_sink(void);
static vader_string_t vader_comptime_display_value(vader_box_t l0);
static void* vader_comptime_division_by_zero(void* l0, vader_string_t l1);
static void vader_comptime_emit_cycle(size_t l0, void* l1, size_t l2, void* l3, void* l4, void* l5);
static void vader_comptime_evaluate_assert_decls(void* l0, void* l1, void* l2);
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
static void* vader_comptime_file_constants(void* l0);
static double vader_comptime_float_arith(uint8_t l0, double l1, double l2);
static bool vader_comptime_float_compare(double l0, double l1, uint8_t l2);
static vader_box_t vader_comptime_float_val(double l0);
static void* vader_comptime_harvest_instances(void* l0);
static bool vader_comptime_has_comptime_decorator(void* l0);
static bool vader_comptime_has_union_operand(void* l0, void* l1);
static vader_string_t vader_comptime_instance_args_key(void* l0);
static int64_t vader_comptime_int_bits_of(vader_string_t l0);
static bool vader_comptime_int_compare(int64_t l0, int64_t l1, uint8_t l2);
static void* vader_comptime_int_div_check(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
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
static bool vader_comptime_is_type_symbol_kind(uint8_t l0);
static vader_box_t vader_comptime_lookup_module_decls(void* l0, vader_string_t l1);
static vader_box_t vader_comptime_mask_shift_amount(vader_box_t l0, vader_string_t l1);
static void* vader_comptime_new_evaluated_program(void* l0);
static void* vader_comptime_new_evaluated_project(void* l0);
static void* vader_comptime_normalize_int_result(void* l0, vader_string_t l1);
static void vader_comptime_observe(void* l0, vader_box_t l1);
static void* vader_comptime_ok(vader_box_t l0);
static int64_t vader_comptime_op_div(int64_t l0, int64_t l1);
static void vader_comptime_populate_deps(void* l0, void* l1);
static vader_box_t vader_comptime_read_relative_file(vader_string_t l0, vader_string_t l1);
static vader_string_t vader_comptime_render_array(void* l0);
static vader_string_t vader_comptime_render_struct(void* l0);
static vader_box_t vader_comptime_resolve_type_arg(vader_box_t l0, void* l1);
static vader_string_t vader_comptime_resolved_int_name(void* l0, size_t l1);
static vader_string_t vader_comptime_result_type_name(void* l0, vader_string_t l1);
static bool vader_comptime_same_kind(vader_box_t l0, vader_box_t l1);
static vader_string_t vader_comptime_sanitise_ident(vader_string_t l0);
static int64_t vader_comptime_shift_amount_mask(vader_string_t l0);
static int64_t vader_comptime_sign_extend(int64_t l0, int64_t l1);
static void* vader_comptime_sort_comptime_decls(void* l0, void* l1);
static void* vader_comptime_sorted_instances(void* l0);
static void* vader_comptime_topo_sort(void* l0);
static int64_t vader_comptime_type_field_count(vader_box_t l0, void* l1);
static vader_box_t vader_comptime_type_from_expr_safe(void* l0, void* l1);
static void* vader_comptime_type_mismatch(void* l0, vader_string_t l1);
static vader_box_t vader_comptime_type_val(vader_box_t l0);
static int64_t vader_comptime_type_variant_count(vader_box_t l0);
static void* vader_comptime_unary_bit_not(void* l0, vader_box_t l1);
static void* vader_comptime_unary_neg(void* l0, vader_box_t l1, vader_string_t l2);
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_types_strip_distinct_each(l2);
    l4 = vader_comptime_build_display_key(l1, l3);
    l5 = std_collections_MutableMap_std_core_Index_at__string__Any(((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_by_key, l4);
    if (!(l5.tag == 877u)) {
        vader_struct_vader_comptime_GenericInstance_t* _a0_obj = (vader_struct_vader_comptime_GenericInstance_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_GenericInstance_t));
        vader_obj_header_init(_a0_obj, 877u);
        _a0_obj->f_symbol = l1;
        _a0_obj->f_args = l3;
        _a0_obj->f_display_key = l4;
        l3 = (void*) _a0_obj;
        std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_by_key, l4, vader_ref_box(l3));
        vader_array_push((vader_array_t*) ((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_order, vader_ref_box(l3));
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l5.payload.obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_comptime_all_concrete_enough(void* l0) {
    void* l1;
    size_t l2, l3;
    vader_box_t t0;
    bool t1;
    int64_t t2;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = vader_comptime_is_concrete_enough(t0);
        if (!(t1)) {
            return false;
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
    l4 = l1;
    l5 = vader_host_std_core_byte_len(l4);
    l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(68) + l5));
    l5 = (size_t) 0;
    l5 = std_core_write_string_at(l6, l5, 436u);
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 71u);
    t0 = ((int64_t) (size_t) l2);
    l7 = (uint64_t) (int64_t) t0;
    l5 = std_core_write_unsigned(l6, l5, l7);
    l5 = std_core_write_string_at(l6, l5, 54u);
    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    t0 = ((int64_t) (size_t) t1);
    l7 = (uint64_t) (int64_t) t0;
    l5 = std_core_write_unsigned(l6, l5, l7);
    l4 = std_core_finish_buffer(l6, l5);
    t2 = vader_diagnostics_comptime_error((uint8_t) 10, l3, l4);
    t3 = vader_comptime_fail(t2);
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_arg_error(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
    t0 = vader_diagnostics_comptime_error((uint8_t) 10, l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_arithmetic(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3) {
    int64_t l4, l5;
    vader_string_t l6 = 0;
    void* l7 = NULL;
    void* l8 = NULL;
    uint8_t l9;
    double l10, l11;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t1 };
    void** gc_raw_roots[4] = { &l0, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 879u) {
        if (l2.tag == 879u) {
            if (!(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(3))) {
                l7 = l1.payload.obj;
                l8 = l2.payload.obj;
                t0 = vader_comptime_checked_int(l0, l7, l8, l3);
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            l4 = vader_comptime_op_div(l4, l5);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
            t1 = vader_comptime_int_val_typed(l4, l6);
            t0 = vader_comptime_ok(t1);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1.tag == 876u) {
        if (l2.tag == 876u) {
            l9 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op;
            t0 = l1.payload.obj;
            l10 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l11 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
            l10 = vader_comptime_float_arith(l9, l10, l11);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_type_name;
            t1 = vader_comptime_float_val_typed(l10, l6);
            t0 = vader_comptime_ok(t1);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = 2116u;
        t0 = vader_comptime_type_mismatch(l0, l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = 2116u;
    t0 = vader_comptime_type_mismatch(l0, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_arithmetic_int(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    int64_t l4, l5;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t1 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 879u) {
        if (l2.tag == 879u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
            t1 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(286u, l4), vader_box_i64(286u, l5));
            l4 = ((int64_t) t1.payload.i);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
            t1 = vader_comptime_int_val_typed(l4, l6);
            t0 = vader_comptime_ok(t1);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = 2117u;
        t0 = vader_comptime_type_mismatch(l0, l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = 2117u;
    t0 = vader_comptime_type_mismatch(l0, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_arithmetic_or_concat(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3) {
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l1, &l2, &l6, &t2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l4, &l5, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 884u)) {
        l6 = l1;
        t0 = vader_comptime_arithmetic(l0, l6, l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 884u)) {
        t0 = vader_comptime_type_mismatch(l0, 2319u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    l4 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
    t0 = l2.payload.obj;
    l5 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
    t1 = concat_2(l4, l5);
    t2 = vader_comptime_string_val(t1);
    t0 = vader_comptime_ok(t2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_comptime_assert_verdict(vader_box_t l0) {
    void* t0;
    bool t1;
    if (!(l0.tag == 868u)) {
        return (uint8_t) 2;
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
    if (!(t1)) {
        return (uint8_t) 1;
    }
    return (uint8_t) 0;
}

static void vader_comptime_bake_file_exprs(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    size_t l5, l6, l9;
    vader_box_t l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l10, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(40u, 0u, 13u, 564u);
    l3 = (void*) _a0_arr;
    l4 = l0;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        vader_comptime_collect_file_intrinsics(t0, l3);
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    l4 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_typed;
    l7 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
    vader_struct_vader_comptime_ComptimeContext_t* _a2_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a2_obj, 870u);
    _a2_obj->f_typed = l4;
    _a2_obj->f_bindings = l7;
    _a2_obj->f_depth = INT64_C(0);
    l4 = (void*) _a2_obj;
    l7 = vader_comptime_file_constants(l0);
    l5 = ((vader_array_t*) l3)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l8 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l9 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l8)->f_id;
        l10 = std_collections_MutableMap_std_core_Index_at__usize__Any(l7, l9);
        vader_comptime_bake_one_file_expr(l8, l10, l4, l1, l2);
        t1 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t1;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_comptime_bake_one_file_expr(void* l0, vader_box_t l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    vader_box_t l8 = vader_box_null();
    size_t l9;
    int32_t l12;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l8, &t0 };
    void** gc_raw_roots[8] = { &l0, &l2, &l3, &l4, &l5, &l10, &l11, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l5 = vader_comptime_evaluate_expr(t0, l2);
    if (!(((vader_struct_vader_comptime_EvalResult_t*) l5)->f_value.tag == 884u)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((vader_struct_vader_comptime_StringValue_t*) ((vader_struct_vader_comptime_EvalResult_t*) l5)->f_value.payload.obj)->f_value;
    l7 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_EvaluatedProgram_t*) l4)->f_typed)->f_resolved)->f_path;
    l8 = vader_comptime_read_relative_file(l6, l7);
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = l8.payload.s;
    l5 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_file_exprs;
    l9 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_id;
    std_collections_MutableMap_std_core_IndexSet_set_at__usize__string(l5, l9, l7);
    l5 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l4)->f_file_reads;
    l10 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
    l9 = vader_host_std_core_byte_len(l7);
    l8 = vader_comptime_constant_name(l1);
    vader_struct_vader_comptime_FileRead_t* _a1_obj = (vader_struct_vader_comptime_FileRead_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_FileRead_t));
    vader_obj_header_init(_a1_obj, 875u);
    _a1_obj->f_span = l10;
    _a1_obj->f_path = l6;
    _a1_obj->f_bytes = l9;
    _a1_obj->f_name = l8;
    l10 = (void*) _a1_obj;
    vader_array_push((vader_array_t*) l5, vader_ref_box(l10));
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l10 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_EvaluatedProgram_t*) l4)->f_typed)->f_resolved;
    t1 = l1.payload.obj;
    l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) t1)->f_name_span;
    l8 = vader_resolver_symbol_declared_at(l10, l11);
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l8.payload.obj;
    l10 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_file_baked_consts;
    l12 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l5)->f_id;
    l8 = vader_comptime_string_val(l7);
    std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l10, l12, l8);
    { vader_gc_top = gc_frame.prev; return; }
}

static int64_t vader_comptime_bit_not_i64(int64_t l0) {
    return (l0 ^ INT64_C(-1));
}

static void* vader_comptime_bool_equality_only(void* l0, bool l1, uint8_t l2) {
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
    if (!(l2 == INT32_C(1))) {
        t1 = vader_comptime_type_mismatch(l0, 1167u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_bool_value(!(l1));
    t1 = vader_comptime_ok(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_bool_op(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    bool l4, l5;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    void* t3 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[3] = { &l1, &l2, &t1 };
    void** gc_raw_roots[4] = { &l0, &l3, &t0, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 868u) {
        if (l2.tag == 868u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
            vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
            t1 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_bool(280u, l4), vader_box_bool(280u, l5));
            t2 = t1.payload.b;
            if (!(t2)) {
                t0 = (void*) &vader_data_33;
                vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
                t3 = vader_comptime_ok(vader_ref_box(t0));
                { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = (void*) &vader_data_32;
            vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
            t3 = vader_comptime_ok(vader_ref_box(t0));
            { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = 1986u;
        t0 = vader_comptime_type_mismatch(l0, l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = 1986u;
    t0 = vader_comptime_type_mismatch(l0, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_bool_value(bool l0) {
    void* t0;
    if (!(l0)) {
        t0 = (void*) &vader_data_33;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    t0 = (void*) &vader_data_32;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t0);
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_comptime_instance_args_key(l1);
    l3 = vader_host_std_core_byte_len(l2);
    l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(22) + l3));
    l3 = (size_t) 0;
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l5 = ((int64_t) (int32_t) t0);
    l3 = std_core_write_int(l4, l3, l5);
    l3 = std_core_write_string_at(l4, l3, 236u);
    l3 = std_core_write_string_at(l4, l3, l2);
    l3 = std_core_write_string_at(l4, l3, 252u);
    t1 = std_core_finish_buffer(l4, l3);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_build_vm_required(void* l0, void* l1, void* l2, vader_string_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    int32_t l6;
    vader_box_t l7 = vader_box_null();
    vader_string_t l8 = 0;
    size_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l4, &l5, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_value.tag == 528u) {
        l4 = ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_value.payload.obj;
        if (((vader_struct_toolchain_ast_CallExpr_t*) l4)->f_callee.tag == 553u) {
            l5 = ((vader_struct_toolchain_ast_CallExpr_t*) l4)->f_callee.payload.obj;
            t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l4)->f_args)->length;
            if (t0 == INT64_C(0)) {
                l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_decl_types;
                l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
                l7 = std_collections_MutableMap_std_core_Index_at__i32__Any(l4, l6);
                if (!(l7.tag == 0u)) {
                    l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
                    l8 = ((vader_struct_toolchain_ast_IdentExpr_t*) l5)->f_name;
                    l4 = ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_span;
                    vader_struct_vader_comptime_VmRequiredDecl_t* _a0_obj = (vader_struct_vader_comptime_VmRequiredDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_VmRequiredDecl_t));
                    vader_obj_header_init(_a0_obj, 887u);
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
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1228u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        l1 = concat_2(624u, l1);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1230u) {
        t0 = l0.payload.obj;
        l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_StructType_t*) t0)->f_args);
        l3 = vader_host_std_core_byte_len(l2);
        l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(24) + l3));
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l4, l3, 671u);
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        l3 = std_core_write_string_at(l4, l3, 236u);
        l3 = std_core_write_string_at(l4, l3, l2);
        l3 = std_core_write_string_at(l4, l3, 252u);
        l1 = std_core_finish_buffer(l4, l3);
    } else if (l0.tag == 1220u) {
        l4 = std_core_new_byte_buffer((size_t) 22);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l4, l3, 505u);
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) t0)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        l1 = std_core_finish_buffer(l4, l3);
    } else if (l0.tag == 1219u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_canonical_type_key(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1231u) {
        t0 = l0.payload.obj;
        l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_TraitType_t*) t0)->f_args);
        l3 = vader_host_std_core_byte_len(l2);
        l4 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(24) + l3));
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l4, l3, 771u);
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        l3 = std_core_write_string_at(l4, l3, 236u);
        l3 = std_core_write_string_at(l4, l3, l2);
        l3 = std_core_write_string_at(l4, l3, 252u);
        l1 = std_core_finish_buffer(l4, l3);
    } else if (l0.tag == 1218u) {
        t0 = l0.payload.obj;
        l2 = vader_comptime_canonical_type_key(((vader_struct_vader_types_ArrayType_t*) t0)->f_element);
        l1 = concat_2(444u, l2);
    } else if (l0.tag == 1232u) {
        t0 = l0.payload.obj;
        l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_TupleType_t*) t0)->f_elements);
        l1 = concat_3(776u, l2, 252u);
    } else if (l0.tag == 1221u) {
        t0 = l0.payload.obj;
        l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_FnType_t*) t0)->f_params);
        t0 = l0.payload.obj;
        l6 = vader_comptime_canonical_type_key(((vader_struct_vader_types_FnType_t*) t0)->f_return_type);
        l1 = concat_4(509u, l2, 272u, l6);
    } else if (l0.tag == 1234u) {
        l4 = std_core_new_byte_buffer((size_t) 22);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l4, l3, 818u);
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_TypeParamType_t*) t0)->f_symbol)->f_id;
        l5 = ((int64_t) (int32_t) t1);
        l3 = std_core_write_int(l4, l3, l5);
        l1 = std_core_finish_buffer(l4, l3);
    } else if (l0.tag == 1225u) {
        t0 = l0.payload.obj;
        vader_types_leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 1235u) {
        t0 = l0.payload.obj;
        l2 = vader_comptime_instance_args_key(((vader_struct_vader_types_UnionType_t*) t0)->f_variants);
        l1 = concat_3(585u, l2, 252u);
    } else if (l0.tag == 1233u) {
        l1 = 582u;
    } else if (l0.tag == 1229u) {
        l1 = 674u;
    } else if (l0.tag == 1236u) {
        l1 = 781u;
    } else if (l0.tag == 1224u) {
        l1 = 517u;
    } else if (l0.tag == 1222u) {
        l1 = 515u;
    } else if (l0.tag == 1223u) {
        l1 = 516u;
    } else if (l0.tag == 1226u) {
        l1 = 590u;
    } else {
        if (!(l0.tag == 1217u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 819u;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_checked_int(void* l0, void* l1, void* l2, vader_string_t l3) {
    vader_string_t l4 = 0;
    int64_t l5, l8, l9;
    uint8_t l6;
    bool l7;
    vader_box_t l10 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_comptime_result_type_name(l1, l3);
    l5 = vader_comptime_int_bits_of(l4);
    l6 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op;
    l7 = vader_types_is_unsigned_int_name(l4);
    l8 = ((vader_struct_vader_comptime_IntValue_t*) l1)->f_value;
    l9 = ((vader_struct_vader_comptime_IntValue_t*) l2)->f_value;
    l10 = vader_comptime_checked_int_op(l6, l5, l7, l8, l9);
    t0 = vader_comptime_checked_result(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, l10, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_checked_int_op(uint8_t l0, int64_t l1, bool l2, int64_t l3, int64_t l4) {
    vader_box_t t0;
    if (l0 == INT32_C(0)) {
        t0 = vader_integer_checked_add(l1, l2, l3, l4);
        return t0;
    }
    if (!(l0 == INT32_C(1))) {
        t0 = vader_integer_checked_mul(l1, l2, l3, l4);
        return t0;
    }
    t0 = vader_integer_checked_sub(l1, l2, l3, l4);
    return t0;
}

static void* vader_comptime_checked_result(void* l0, vader_box_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    void* t3 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &t1 };
    void** gc_raw_roots[3] = { &l0, &t2, &t3 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 0u)) {
        t0 = ((int64_t) l1.payload.i);
        t1 = vader_comptime_int_val_typed(t0, l2);
        t2 = vader_comptime_ok(t1);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_3(2378u, l2, 887u);
    t2 = vader_diagnostics_comptime_error((uint8_t) 16, l0, l3);
    t3 = vader_comptime_fail(t2);
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        vader_comptime_collect_stmt_deps(t0, l1, l2, l3, l4);
        t1 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t1;
    }
    if (((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1, l2, l3, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_comptime_collect_expr_deps(vader_box_t l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l9 = NULL;
    uint64_t l6;
    vader_box_t l7 = vader_box_null(), l12 = vader_box_null();
    size_t l8, l11;
    int32_t l10;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l0, &l7, &l12, &t1 };
    void** gc_raw_roots[7] = { &l1, &l2, &l3, &l4, &l5, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 553u) {
        l5 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved)->f_idents;
        t0 = l0.payload.obj;
        l6 = toolchain_span_Span_std_core_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span);
        l7 = std_collections_MutableMap_std_core_Index_at__u64__Any(l5, l6);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l5 = l7.payload.obj;
        if (((vader_struct_vader_resolver_symbol_Symbol_t*) l5)->f_kind != INT32_C(6)) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l9 = ((vader_struct_vader_comptime_Nodes_t*) l2)->f_by_symbol;
        l10 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l5)->f_id;
        l7 = std_collections_MutableMap_std_core_Index_at__i32__usize(l9, l10);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l8 = ((size_t) l7.payload.i);
        t1 = std_collections_MutableMap_std_core_Index_at__usize__bool(l3, l8);
        if (t1.tag == 280u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        std_collections_MutableMap_std_core_IndexSet_set_at__usize__bool(l3, l8, true);
        vader_array_push_i64((vader_array_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l4)->f_dependency_ids, (int64_t) (size_t) l8);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 528u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
        l8 = ((vader_array_t*) l5)->length;
        l11 = (size_t) 0;
        while ((l11 < l8)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l11);
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1, l2, l3, l4);
            t2 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 546u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target, l1, l2, l3, l4);
    } else if (l0.tag == 561u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index, l1, l2, l3, l4);
    } else if (l0.tag == 602u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand, l1, l2, l3, l4);
    } else if (l0.tag == 523u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1, l2, l3, l4);
    } else if (l0.tag == 556u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_cond, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_then_block, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_else_branch;
        l12 = l7;
        if (!(l7.tag == 0u)) {
            if (l7.tag == 555u) {
                t0 = l12.payload.obj;
                vader_comptime_collect_expr_deps(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1, l2, l3, l4);
            } else {
                if (!(l7.tag == 554u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l12.payload.obj;
                vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1, l2, l3, l4);
            }
        }
    } else if (l0.tag == 570u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_scrutinee, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_arms;
        l8 = ((vader_array_t*) l5)->length;
        l11 = (size_t) 0;
        while ((l11 < l8)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l9 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
            if (!(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_guard.tag == 0u)) {
                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_guard, l1, l2, l3, l4);
            }
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_body, l1, l2, l3, l4);
            t2 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 524u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_block_deps(t0, l1, l2, l3, l4);
    } else if (l0.tag == 593u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_type_name, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_items;
        l8 = ((vader_array_t*) l5)->length;
        l11 = (size_t) 0;
        while ((l11 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
            if (l7.tag == 594u) {
                t0 = l7.payload.obj;
                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value, l1, l2, l3, l4);
            } else {
                if (!(l7.tag == 595u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l7.payload.obj;
                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr, l1, l2, l3, l4);
            }
            t2 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 586u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l8 = ((vader_array_t*) l5)->length;
        l11 = (size_t) 0;
        while ((l11 < l8)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
            vader_comptime_collect_expr_deps(t1, l1, l2, l3, l4);
            t2 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 581u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_lower, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_upper, l1, l2, l3, l4);
    } else if (l0.tag == 522u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner, l1, l2, l3, l4);
    } else if (l0.tag == 529u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value, l1, l2, l3, l4);
    } else if (l0.tag == 566u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_body, l1, l2, l3, l4);
    } else if (l0.tag == 564u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
        l8 = ((vader_array_t*) l5)->length;
        l11 = (size_t) 0;
        while ((l11 < l8)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l11);
            vader_comptime_collect_expr_deps(t1, l1, l2, l3, l4);
            t2 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 552u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee, l1, l2, l3, l4);
    } else if (l0.tag == 588u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
        l8 = ((vader_array_t*) l5)->length;
        l11 = (size_t) 0;
        while ((l11 < l8)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l7 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
            if (l7.tag == 589u) {
                t0 = l7.payload.obj;
                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1, l2, l3, l4);
            } else if (!(l7.tag == 590u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t2 = (l11 + INT64_C(1));
            l11 = (size_t) (int64_t) t2;
        }
    } else if (l0.tag == 574u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_left, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        l7 = toolchain_ast_coalesce_fallback_expr(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_fallback);
        if (!(l7.tag == 0u)) {
            vader_comptime_collect_expr_deps(l7, l1, l2, l3, l4);
        }
    } else if (!((l0.tag == 525u || l0.tag == 530u || l0.tag == 541u || l0.tag == 547u || l0.tag == 563u || l0.tag == 575u))) {
        if (!((l0.tag == 518u || l0.tag == 550u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_comptime_collect_file_intrinsics(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    size_t l5, l6;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l0, &l2, &l3 };
    void** gc_raw_roots[3] = { &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 548u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body;
        l3 = l2;
        if (!(l2.tag == 0u)) {
            if (!(l2.tag == 524u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l3.payload.obj;
            vader_comptime_collect_in_block(t0, l1);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 557u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_members;
        l5 = ((vader_array_t*) l4)->length;
        l6 = (size_t) 0;
        while ((l6 < l5)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
            l2 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body;
            l3 = l2;
            if (!(l2.tag == 0u)) {
                if (!(l2.tag == 524u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l3.payload.obj;
                vader_comptime_collect_in_block(t0, l1);
            }
            t1 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t1;
        }
    } else if (l0.tag == 531u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_value, l1);
    } else if (l0.tag == 520u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_condition, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
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
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_comptime_collect_in_stmt(t0, l1);
        t1 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t1;
    }
    if (((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_comptime_collect_in_expr(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    size_t t2;
    int64_t t3;
    vader_box_t t4 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l5, &l6, &t4 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 564u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_name;
        if (t1 == 1717u) {
            t0 = l0.payload.obj;
            t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args)->length;
            if (t2 == INT64_C(1)) {
                l2 = l0.payload.obj;
                vader_array_push((vader_array_t*) l1, vader_ref_box(l2));
            }
        }
    }
    if (l0.tag == 524u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_block(t0, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 528u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1);
            t3 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t3;
        }
    } else if (l0.tag == 546u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target, l1);
    } else if (l0.tag == 561u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index, l1);
    } else if (l0.tag == 602u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand, l1);
    } else if (l0.tag == 523u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
    } else if (l0.tag == 556u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_cond, l1);
        t0 = l0.payload.obj;
        vader_comptime_collect_in_block(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_then_block, l1);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_else_branch;
        l6 = l5;
        if (!(l5.tag == 0u)) {
            if (l5.tag == 554u) {
                t0 = l6.payload.obj;
                vader_comptime_collect_in_block(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1);
            } else {
                if (!(l5.tag == 555u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l6.payload.obj;
                vader_comptime_collect_in_expr(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1);
            }
        }
    } else if (l0.tag == 564u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t4 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_comptime_collect_in_expr(t4, l1);
            t3 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t3;
        }
    } else if (l0.tag == 588u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l5 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            if (l5.tag == 589u) {
                t0 = l5.payload.obj;
                vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1);
            }
            t3 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t3;
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_comptime_collect_in_stmt(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    size_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l0, &l5, &l6, &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 567u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 521u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 537u) {
        t0 = l0.payload.obj;
        l2 = toolchain_ast_assign_places(t0);
        l3 = ((vader_array_t*) l2)->length;
        l4 = (size_t) 0;
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_comptime_collect_in_expr(t1, l1);
            t2 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 545u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1);
    } else if (l0.tag == 585u) {
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
        }
    } else if (l0.tag == 551u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form;
        l6 = l5;
        if (l5.tag == 603u) {
            t0 = l6.payload.obj;
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
        } else if (l5.tag == 560u) {
            t0 = l6.payload.obj;
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1);
        }
        t0 = l0.payload.obj;
        vader_comptime_collect_in_block(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_body, l1);
    } else if (l0.tag == 535u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_DeferStmt_t*) t0)->f_body;
        l6 = l5;
        if (l5.tag == 536u) {
            t0 = l6.payload.obj;
            vader_comptime_collect_in_stmt(((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt, l1);
        } else {
            if (!(l5.tag == 534u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l6.payload.obj;
            vader_comptime_collect_in_block(((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block, l1);
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_comptime_collect_nodes(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    size_t l6, l7, l9, l11;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 4u, 292u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 0u, 293u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__usize__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__usize__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__Any_t));
    vader_obj_header_init(_a3_obj, 479u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 4u, 292u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(16u, 0u, 7u, 285u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 4u, 292u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(16u, 0u, 7u, 285u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i32__usize_t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__usize_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__usize_t));
    vader_obj_header_init(_a8_obj, 386u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = (size_t) 0;
    _a8_obj->f_size = (size_t) 0;
    _a8_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a8_obj;
    vader_struct_vader_comptime_Nodes_t* _a9_obj = (vader_struct_vader_comptime_Nodes_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_Nodes_t));
    vader_obj_header_init(_a9_obj, 882u);
    _a9_obj->f_by_id = l1;
    _a9_obj->f_order = l2;
    _a9_obj->f_by_symbol = l3;
    l1 = (void*) _a9_obj;
    l2 = l0;
    l6 = ((vader_array_t*) l2)->length;
    l7 = (size_t) 0;
    while ((l7 < l6)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l8 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l7);
        if (l8.tag == 531u) {
            t0 = l8.payload.obj;
            t1 = vader_comptime_has_comptime_decorator(t0);
            if (t1) {
                vader_array_t* _a11_arr = vader_array_new(22u, 0u, 4u, 292u);
                l3 = (void*) _a11_arr;
                l4 = ((vader_struct_vader_comptime_Nodes_t*) l1)->f_by_id;
                t0 = l8.payload.obj;
                l9 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_id;
                t0 = l8.payload.obj;
                vader_struct_vader_comptime_NodeRecord_t* _a12_obj = (vader_struct_vader_comptime_NodeRecord_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_NodeRecord_t));
                vader_obj_header_init(_a12_obj, 881u);
                _a12_obj->f_decl = t0;
                _a12_obj->f_dependency_ids = l3;
                l5 = (void*) _a12_obj;
                std_collections_MutableMap_std_core_IndexSet_set_at__usize__Any(l4, l9, vader_ref_box(l5));
                l10 = ((vader_struct_vader_comptime_Nodes_t*) l1)->f_order;
                t0 = l8.payload.obj;
                l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_id;
                vader_array_push_i64((vader_array_t*) l10, (int64_t) (size_t) l11);
            } else {
                t2 = (l7 + INT64_C(1));
                l7 = (size_t) (int64_t) t2;
                continue;
            }
        }
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_comptime_collect_stmt_deps(vader_box_t l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    size_t l6, l7;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l0, &l8, &l9, &t1 };
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 567u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value, l1, l2, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 545u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1, l2, l3, l4);
    } else if (l0.tag == 585u) {
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1, l2, l3, l4);
        }
    } else if (l0.tag == 521u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value, l1, l2, l3, l4);
    } else if (l0.tag == 537u) {
        t0 = l0.payload.obj;
        l5 = toolchain_ast_assign_places(t0);
        l6 = ((vader_array_t*) l5)->length;
        l7 = (size_t) 0;
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
            vader_comptime_collect_expr_deps(t1, l1, l2, l3, l4);
            t2 = (l7 + INT64_C(1));
            l7 = (size_t) (int64_t) t2;
        }
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_value, l1, l2, l3, l4);
    } else if (l0.tag == 551u) {
        t0 = l0.payload.obj;
        l8 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form;
        l9 = l8;
        if (l8.tag == 603u) {
            t0 = l9.payload.obj;
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1, l2, l3, l4);
        } else if (l8.tag == 560u) {
            t0 = l9.payload.obj;
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1, l2, l3, l4);
        } else if (!(l8.tag == 562u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_body, l1, l2, l3, l4);
    } else if (l0.tag == 608u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_YieldStmt_t*) t0)->f_value, l1, l2, l3, l4);
    } else if (l0.tag == 535u) {
        t0 = l0.payload.obj;
        l8 = ((vader_struct_toolchain_ast_DeferStmt_t*) t0)->f_body;
        l9 = l8;
        if (l8.tag == 536u) {
            t0 = l9.payload.obj;
            vader_comptime_collect_stmt_deps(((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt, l1, l2, l3, l4);
        } else {
            if (!(l8.tag == 534u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l9.payload.obj;
            vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block, l1, l2, l3, l4);
        }
    } else if (!((l0.tag == 526u || l0.tag == 532u))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_comptime_combine_binary(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3) {
    uint8_t l4;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l5, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op;
    if (l4 == INT32_C(0)) {
        l5 = vader_comptime_arithmetic_or_concat(l0, l1, l2, l3);
        { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(1)) {
        l5 = vader_comptime_arithmetic(l0, l1, l2, l3);
    } else if (l4 == INT32_C(2)) {
        l5 = vader_comptime_arithmetic(l0, l1, l2, l3);
    } else if (l4 == INT32_C(3)) {
        l5 = vader_comptime_int_div_check(l0, l1, l2, l3);
    } else if (l4 == INT32_C(4)) {
        l6 = (void*) &vader_fn_static_vader_comptime_op_mod;
        l5 = vader_comptime_int_mod_check(l0, l1, l2, l6);
    } else if (l4 == INT32_C(5)) {
        l6 = (void*) &vader_fn_static_vader_comptime_op_shl;
        l5 = vader_comptime_arithmetic_int(l0, l1, l2, l6);
    } else if (l4 == INT32_C(6)) {
        l6 = (void*) &vader_fn_static_vader_comptime_op_shr;
        l5 = vader_comptime_arithmetic_int(l0, l1, l2, l6);
    } else if (l4 == INT32_C(7)) {
        l6 = (void*) &vader_fn_static_vader_comptime_op_bit_and;
        l5 = vader_comptime_arithmetic_int(l0, l1, l2, l6);
    } else if (l4 == INT32_C(8)) {
        l6 = (void*) &vader_fn_static_vader_comptime_op_bit_or;
        l5 = vader_comptime_arithmetic_int(l0, l1, l2, l6);
    } else if (l4 == INT32_C(9)) {
        l6 = (void*) &vader_fn_static_vader_comptime_op_bit_xor;
        l5 = vader_comptime_arithmetic_int(l0, l1, l2, l6);
    } else if (l4 == INT32_C(10)) {
        l6 = (void*) &vader_fn_static_vader_comptime_op_and;
        l5 = vader_comptime_bool_op(l0, l1, l2, l6);
    } else if (l4 == INT32_C(11)) {
        l6 = (void*) &vader_fn_static_vader_comptime_op_or;
        l5 = vader_comptime_bool_op(l0, l1, l2, l6);
    } else if (l4 == INT32_C(12)) {
        l5 = vader_comptime_compare(l0, l1, l2, (uint8_t) 0);
    } else if (l4 == INT32_C(13)) {
        l5 = vader_comptime_compare(l0, l1, l2, (uint8_t) 1);
    } else if (l4 == INT32_C(14)) {
        l5 = vader_comptime_compare(l0, l1, l2, (uint8_t) 2);
    } else if (l4 == INT32_C(15)) {
        l5 = vader_comptime_compare(l0, l1, l2, (uint8_t) 3);
    } else if (l4 == INT32_C(16)) {
        l5 = vader_comptime_compare(l0, l1, l2, (uint8_t) 4);
    } else if (l4 == INT32_C(17)) {
        l5 = vader_comptime_compare(l0, l1, l2, (uint8_t) 5);
    } else if (l4 == INT32_C(18)) {
        l5 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 456u);
    } else if (l4 == INT32_C(19)) {
        l5 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 455u);
    } else if (l4 == INT32_C(20)) {
        l5 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 457u);
    } else if (l4 == INT32_C(21)) {
        l5 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 459u);
    } else if (l4 == INT32_C(22)) {
        l5 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 458u);
    } else if (l4 == INT32_C(23)) {
        l6 = (void*) &vader_fn_static_vader_comptime_op_add;
        l5 = vader_comptime_arithmetic_int(l0, l1, l2, l6);
    } else if (l4 == INT32_C(24)) {
        l6 = (void*) &vader_fn_static_vader_comptime_op_sub;
        l5 = vader_comptime_arithmetic_int(l0, l1, l2, l6);
    } else {
        if (!(l4 == INT32_C(25))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l6 = (void*) &vader_fn_static_vader_comptime_op_mul;
        l5 = vader_comptime_arithmetic_int(l0, l1, l2, l6);
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 879u) {
        if (l2.tag == 879u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            t1 = vader_comptime_int_compare(l4, l5, l3);
            t2 = vader_comptime_bool_value(t1);
            t0 = vader_comptime_ok(t2);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l1.tag == 876u) {
        if (l2.tag == 876u) {
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l7 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
            t1 = vader_comptime_float_compare(l6, l7, l3);
            t2 = vader_comptime_bool_value(t1);
            t0 = vader_comptime_ok(t2);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l1.tag == 868u) {
        if (l2.tag == 868u) {
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
            l8 = l8 == l9;
            t0 = vader_comptime_bool_equality_only(l0, l8, l3);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l1.tag == 884u) {
        if (l2.tag == 884u) {
            t0 = l1.payload.obj;
            l10 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l11 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
            t1 = vader_comptime_int_compare(((int64_t) (int32_t) vader_string_compare(l10, l11)), INT64_C(0), l3);
            t2 = vader_comptime_bool_value(t1);
            t0 = vader_comptime_ok(t2);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (!(l1.tag == 866u)) {
        if (!(l1.tag == 885u)) {
            l10 = 1501u;
            t0 = vader_comptime_type_mismatch(l0, l10);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t1 = vader_comptime_same_kind(l1, l2);
    if (t1) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 1500u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = 1501u;
    t0 = vader_comptime_type_mismatch(l0, l10);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_constant_name(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    vader_box_t t2;
    if (!(l0.tag == 0u)) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_name;
        t2 = vader_box_string(282u, t1);
        return t2;
    }
    return vader_box_obj(0u, NULL);
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    l5 = (void*) _a0_arr;
    l6 = l0;
    while ((l6 < l1)) {
        l8 = ((vader_struct_vader_comptime_Nodes_t*) l4)->f_by_id;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
        l9 = (size_t) (int64_t) t0;
        l10 = std_collections_MutableMap_std_core_Index_at__usize__Any(l8, l9);
        if (l10.tag == 0u) {
            t0 = (l6 + INT64_C(1));
            l6 = (size_t) (int64_t) t0;
            continue;
        }
        l7 = l10.payload.obj;
        l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l7)->f_decl)->f_name;
        vader_array_push((vader_array_t*) l5, vader_box_string(282u, l11));
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    l10 = std_collections_MutableMap_std_core_Index_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l4)->f_by_id, l3);
    if (!(l10.tag == 0u)) {
        t1 = l10.payload.obj;
        l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) t1)->f_decl)->f_name;
        vader_array_push((vader_array_t*) l5, vader_box_string(282u, l11));
    }
    l11 = 0u;
    l6 = (size_t) 0;
    l9 = ((vader_array_t*) l5)->length;
    while ((l6 < l9)) {
        if ((l6 > INT64_C(0))) {
            l11 = concat_2(l11, 179u);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t2 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
        l12 = t2.payload.s;
        l11 = concat_2(l11, l12);
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    { vader_string_t __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_diag_sink(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(84u, 0u, 13u, 891u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 879u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
        l2 = vader_host_std_core_byte_len(l1);
        l3 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l2));
        l2 = (size_t) 0;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        l2 = std_core_write_int(l3, l2, l4);
        l2 = std_core_write_string_at(l3, l2, 830u);
        l2 = std_core_write_string_at(l3, l2, l1);
        l1 = std_core_finish_buffer(l3, l2);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 876u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
        l5 = std_core_f64_Display_to_string(t1);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_type_name;
        l1 = concat_3(l5, 830u, l6);
    } else if (l0.tag == 868u) {
        l3 = std_core_new_byte_buffer((size_t) 5);
        l2 = (size_t) 0;
        t0 = l0.payload.obj;
        l7 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
        l2 = std_core_write_bool(l3, l2, l7);
        l1 = std_core_finish_buffer(l3, l2);
    } else if (l0.tag == 869u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_comptime_CharValue_t*) t0)->f_value;
        t3 = std_numbers_to_hex((uint64_t) (int64_t) ((int64_t) (uint32_t) t2));
        l5 = std_string_pad_start(t3, (size_t) 4, 48u);
        l1 = concat_3(235u, l5, 218u);
    } else if (l0.tag == 884u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
        l1 = concat_3(185u, l5, 185u);
    } else if (l0.tag == 883u) {
        l1 = 2103u;
    } else if (l0.tag == 888u) {
        l1 = 2655u;
    } else if (l0.tag == 866u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_render_array(t0);
    } else if (l0.tag == 885u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_render_struct(t0);
    } else {
        if (!(l0.tag == 886u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(((vader_struct_vader_comptime_TypeValue_t*) t0)->f_value);
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_division_by_zero(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span;
    t0 = vader_diagnostics_comptime_error((uint8_t) 4, l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = l2;
    l7 = (size_t) 0;
    while ((l7 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l7];
        if (t0 == l0) {
            l6 = l7;
            break;
        }
        t0 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t0;
    }
    l8 = vader_comptime_cycle_names(l6, l2, l1, l0, l3);
    l9 = std_collections_MutableMap_std_core_Index_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l3)->f_by_id, l0);
    if (!(l9.tag == 0u)) {
        t1 = l9.payload.obj;
        l10 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) t1)->f_decl)->f_span;
        l10 = vader_diagnostics_comptime_error((uint8_t) 8, l10, l8);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l10));
    }
    while ((l6 < l2)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
        l7 = (size_t) (int64_t) t0;
        std_collections_MutableMap_std_core_IndexSet_set_at__usize__bool(l4, l7, true);
        t0 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t0;
    }
    std_collections_MutableMap_std_core_IndexSet_set_at__usize__bool(l4, l0, true);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_comptime_evaluate_assert_decls(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l17 = NULL;
    size_t l5, l6;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null(), l13 = vader_box_null();
    uint8_t l11;
    vader_string_t l14 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[3] = { &l7, &l9, &l13 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l8, &l10, &l12, &l15, &l16, &l17, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l14, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l1)->f_typed;
    l4 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l1)->f_comptime_decls;
    vader_struct_vader_comptime_ComptimeContext_t* _a0_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a0_obj, 870u);
    _a0_obj->f_typed = l3;
    _a0_obj->f_bindings = l4;
    _a0_obj->f_depth = INT64_C(0);
    l3 = (void*) _a0_obj;
    l4 = l0;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        if (l7.tag == 520u) {
            t0 = l7.payload.obj;
            l8 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_condition, l3);
            l9 = ((vader_struct_vader_comptime_EvalResult_t*) l8)->f_diag;
            if (!(l9.tag == 0u)) {
                t0 = l9.payload.obj;
                t1 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) t0)->f_code)->f_id;
                if (t1 != 465u) {
                    l10 = l9.payload.obj;
                    vader_array_push((vader_array_t*) l2, vader_ref_box(l10));
                }
            }
            l11 = vader_comptime_assert_verdict(((vader_struct_vader_comptime_EvalResult_t*) l8)->f_value);
            if (l11 == INT32_C(1)) {
                t0 = l7.payload.obj;
                l12 = ((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_span;
                t0 = l7.payload.obj;
                l13 = ((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_message;
                if (l13.tag == 0u) {
                    l14 = 0u;
                } else {
                    l14 = l13.payload.s;
                }
                l15 = vader_diagnostics_comptime_error((uint8_t) 14, l12, l14);
                vader_array_push((vader_array_t*) l2, vader_ref_box(l15));
            }
            l16 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l1)->f_asserts;
            t0 = l7.payload.obj;
            vader_struct_vader_comptime_AssertCheck_t* _a2_obj = (vader_struct_vader_comptime_AssertCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_AssertCheck_t));
            vader_obj_header_init(_a2_obj, 867u);
            _a2_obj->f_span = ((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_span;
            _a2_obj->f_verdict = l11;
            l17 = (void*) _a2_obj;
            vader_array_push((vader_array_t*) l16, vader_ref_box(l17));
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_comptime_evaluate_binary_expr(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null(), l8 = vader_box_null();
    size_t l6;
    vader_string_t l7 = 0;
    bool l9, l10;
    vader_box_t t0 = vader_box_null();
    bool t1;
    void* t2 = NULL;
    void* t3 = NULL;
    vader_box_t* gc_roots[4] = { &l4, &l5, &l8, &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &t2, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_left, vader_ref_box(l1));
    l3 = t0.payload.obj;
    l4 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
    if (l4.tag == 0u) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_fn_t* _a1_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_2_t) _a1_fnobj->code)(_a1_fnobj->env, ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_right, vader_ref_box(l1));
    l3 = t0.payload.obj;
    l5 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
    if (l5.tag == 0u) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_id;
    l7 = vader_comptime_resolved_int_name(l1, l6);
    if (((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(5)) {
        l9 = true;
    } else {
        l9 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(6);
    }
    if (l9) {
        l8 = vader_comptime_mask_shift_amount(l5, l7);
    } else {
        l8 = l5;
    }
    if (((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(12)) {
        l9 = true;
    } else {
        l9 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(13);
    }
    if (l9) {
        t1 = vader_comptime_same_kind(l4, l8);
        l9 = !(t1);
        {
            if (!(l9)) {
                if (!(l4.tag == 883u)) {
                    goto end_72;
                }
            }
            t1 = vader_comptime_has_union_operand(l1, l0);
            if (t1) {
                l10 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(13);
                t0 = vader_comptime_bool_value(l9 == l10);
                t2 = vader_comptime_ok(t0);
                { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
        } end_72: ;
    }
    t2 = vader_comptime_combine_binary(l0, l4, l8, l7);
    t3 = vader_comptime_normalize_int_result(t2, l7);
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_bool_lit(void* l0) {
    bool t0;
    void* t1 = NULL;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l0, &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_BoolLitExpr_t*) l0)->f_value;
    if (!(t0)) {
        t1 = (void*) &vader_data_33;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        t2 = vader_comptime_ok(vader_ref_box(t1));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = (void*) &vader_data_32;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    t2 = vader_comptime_ok(vader_ref_box(t1));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_call_expr(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    vader_box_t l4 = vader_box_null(), l13 = vader_box_null(), l15 = vader_box_null(), l16 = vader_box_null();
    int64_t l5;
    vader_string_t l6 = 0;
    uint64_t l7;
    int32_t l8, l14;
    size_t l9, l10;
    void* t0 = NULL;
    void* t5 = NULL;
    vader_box_t t1 = vader_box_null();
    size_t t2;
    vader_string_t t3 = 0;
    bool t4;
    int64_t t6;
    vader_box_t* gc_roots[5] = { &l4, &l13, &l15, &l16, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l11, &l12, &t0, &t5 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_callee.tag == 553u)) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 491u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_callee;
    l2 = t1.payload.obj;
    if (((vader_obj_header_t*) l2)->type_index == 553u) {
        t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
        if (t2 == INT64_C(1)) {
            t3 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_name;
            t4 = vader_comptime_is_primitive_int_name(t3);
            if (t4) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
                t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
                l3 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1);
                if (((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value.tag == 0u) {
                    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l4 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
                if (l4.tag == 879u) {
                    t0 = l4.payload.obj;
                    l5 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
                    l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_name;
                    l5 = vader_comptime_wrap_to_width(l5, l6);
                    l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_name;
                    vader_struct_vader_comptime_IntValue_t* _a1_obj = (vader_struct_vader_comptime_IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_IntValue_t));
                    vader_obj_header_init(_a1_obj, 879u);
                    _a1_obj->f_value = l5;
                    _a1_obj->f_type_name = l6;
                    t0 = (void*) _a1_obj;
                    t5 = vader_comptime_ok(vader_ref_box(t0));
                    { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
        }
    }
    l3 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
    l7 = toolchain_span_Span_std_core_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_span);
    l4 = std_collections_MutableMap_std_core_Index_at__u64__Any(l3, l7);
    if (l4.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 489u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_fn_decls;
    t0 = l4.payload.obj;
    l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
    l4 = std_collections_MutableMap_std_core_Index_at__i32__Any(l3, l8);
    if (l4.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 490u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l4.payload.obj;
    t4 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators, 2235u);
    if (t4) {
        l3 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
        l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_name;
        l6 = concat_3(887u, l6, 887u);
        t0 = vader_diagnostics_comptime_error((uint8_t) 17, l3, l6);
        t5 = vader_comptime_fail(t0);
        { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l4.payload.obj;
    l9 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params)->length;
    l10 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
    if (l9 != l10) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 485u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(23u, 0u, 0u, 293u);
    l3 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(16u, 0u, 7u, 285u);
    l11 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a5_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a5_obj, 368u);
    _a5_obj->f_ekeys = l2;
    _a5_obj->f_evals = l3;
    _a5_obj->f_index = l11;
    _a5_obj->f_mask = (size_t) 0;
    _a5_obj->f_size = (size_t) 0;
    _a5_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a5_obj;
    l3 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_bindings;
    l11 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ArrayValue___vader_comptime_BoolValue___vader_comptime_CharValue___vader_comptime_FloatValue___vader_comptime_IntValue___vader_comptime_NullValue___vader_comptime_StringValue___vader_comptime_StructValue___vader_comptime_TypeValue___vader_comptime_VoidValue_t*) l3)->f_ekeys;
    l12 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ArrayValue___vader_comptime_BoolValue___vader_comptime_CharValue___vader_comptime_FloatValue___vader_comptime_IntValue___vader_comptime_NullValue___vader_comptime_StringValue___vader_comptime_StructValue___vader_comptime_TypeValue___vader_comptime_VoidValue_t*) l3)->f_evals;
    l9 = (size_t) 0;
    l10 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ArrayValue___vader_comptime_BoolValue___vader_comptime_CharValue___vader_comptime_FloatValue___vader_comptime_IntValue___vader_comptime_NullValue___vader_comptime_StringValue___vader_comptime_StructValue___vader_comptime_TypeValue___vader_comptime_VoidValue_t*) l3)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l9)
        l8 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l9];
        vader_array_t* _a7_slotarr = ((vader_array_t*) l12);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
        l13 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9);
        l14 = l8;
        l15 = l13;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l2, l14, l15);
        t6 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t6;
    }
    l9 = (size_t) 0;
    l10 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
    while ((l9 < l10)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l9)
        t0 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l9);
        l3 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1);
        l15 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
        if (l15.tag == 0u) {
            { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l13 = l15;
        t0 = l4.payload.obj;
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
        l11 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l9);
        l12 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
        l7 = toolchain_span_Span_std_core_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) l11)->f_span);
        l16 = std_collections_MutableMap_std_core_Index_at__u64__Any(l12, l7);
        if (l16.tag == 0u) {
            t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 492u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l16.payload.obj;
        l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l2, l8, l13);
        t6 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t6;
    }
    l3 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed;
    l5 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    vader_struct_vader_comptime_ComptimeContext_t* _a10_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a10_obj, 870u);
    _a10_obj->f_typed = l3;
    _a10_obj->f_bindings = l2;
    _a10_obj->f_depth = l5;
    l2 = (void*) _a10_obj;
    l3 = l4.payload.obj;
    l11 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
    t0 = vader_comptime_evaluate_fn_body(l3, l2, l11);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_obj_header_init(_a0_obj, 869u);
    _a0_obj->f_value = t0;
    t1 = (void*) _a0_obj;
    t2 = vader_comptime_ok(vader_ref_box(t1));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    if ((t0 >= INT64_C(2000))) {
        l2 = vader_comptime_span_of(l0);
        l3 = std_core_new_byte_buffer((size_t) 93);
        l4 = (size_t) 0;
        l4 = std_core_write_string_at(l3, l4, 1221u);
        l4 = std_core_write_int(l3, l4, INT64_C(2000));
        l4 = std_core_write_string_at(l3, l4, 114u);
        l5 = std_core_finish_buffer(l3, l4);
        t1 = vader_comptime_vm_required(l2, l5);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    l6 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth = l6;
    if (l0.tag == 563u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_int_lit(t1);
    } else if (l0.tag == 547u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_float_lit(t1);
    } else if (l0.tag == 525u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_bool_lit(t1);
    } else if (l0.tag == 530u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_char_lit(t1);
    } else if (l0.tag == 575u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_null_lit(t1);
    } else if (l0.tag == 588u) {
        l3 = l0.payload.obj;
        l7 = (void*) &vader_fn_static_vader_comptime_evaluate_expr;
        l2 = vader_comptime_evaluate_string_lit(l3, l1, l7);
    } else if (l0.tag == 553u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_ident(t1, l1);
    } else if (l0.tag == 523u) {
        l3 = l0.payload.obj;
        l7 = (void*) &vader_fn_static_vader_comptime_evaluate_expr;
        l2 = vader_comptime_evaluate_binary_expr(l3, l1, l7);
    } else if (l0.tag == 602u) {
        l3 = l0.payload.obj;
        l7 = (void*) &vader_fn_static_vader_comptime_evaluate_expr;
        l2 = vader_comptime_evaluate_unary_expr(l3, l1, l7);
    } else if (l0.tag == 564u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_intrinsic_call(t1, l1);
    } else if (l0.tag == 528u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_call_expr(t1, l1);
    } else if (l0.tag == 586u) {
        l3 = l0.payload.obj;
        l7 = (void*) &vader_fn_static_vader_comptime_evaluate_expr;
        l2 = vader_comptime_evaluate_seq_lit(l3, l1, l7);
    } else {
        l3 = vader_comptime_span_of(l0);
        l5 = vader_typecheck_expr_kind_name(l0);
        l2 = vader_comptime_vm_required(l3, l5);
    }
    t0 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    l6 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth = l6;
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
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
}

static void* vader_comptime_evaluate_fn_body(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l6 = 0;
    void* t0 = NULL;
    void* t2 = NULL;
    size_t t1;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &t0, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body;
    if (l4.tag == 0u) {
        t0 = vader_comptime_vm_required(l2, 488u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l4.payload.obj;
    l4 = ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_trailing;
    if (l4.tag == 0u) {
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_stmts)->length;
        if (t1 == INT64_C(1)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_stmts);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
            if (l5.tag == 585u) {
                t0 = l5.payload.obj;
                if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
                    t0 = l5.payload.obj;
                    t2 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
                    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            l6 = 487u;
            t0 = vader_comptime_vm_required(l2, l6);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = 487u;
        t0 = vader_comptime_vm_required(l2, l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_stmts)->length;
    if (!(t1 == INT64_C(0))) {
        t0 = vader_comptime_vm_required(l2, 486u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_evaluate_expr(l4, l1);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_ident(void* l0, void* l1) {
    void* l2 = NULL;
    void* l7 = NULL;
    uint64_t l3;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    int32_t l5;
    int64_t l8;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l6, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
    l3 = toolchain_span_Span_std_core_Hash_hash(((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span);
    l4 = std_collections_MutableMap_std_core_Index_at__u64__Any(l2, l3);
    if (l4.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span, 548u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_bindings;
    t0 = l4.payload.obj;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
    l6 = std_collections_MutableMap_std_core_Index_at__i32__Any(l2, l5);
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
    l7 = (void*) &vader_data_41;
    t0 = l4.payload.obj;
    l8 = ((int64_t) (uint8_t) ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_kind);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
    l9 = ((vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) t0)->f_label;
    l9 = concat_3(547u, l9, 252u);
    t0 = vader_comptime_vm_required(l2, l9);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_int_lit(void* l0) {
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_int_literal_value(l0);
    t1 = vader_comptime_int_val(t0);
    t2 = vader_comptime_ok(t1);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_intrinsic_call(void* l0, void* l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l3, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2237u) {
        t1 = vader_comptime_intrinsic_size_of(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1273u) {
        t1 = vader_comptime_intrinsic_align_of(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2431u) {
        t1 = vader_comptime_intrinsic_type_name(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2429u) {
        t1 = vader_comptime_intrinsic_type_kind(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1709u) {
        t1 = vader_comptime_intrinsic_field_count(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2649u) {
        t1 = vader_comptime_intrinsic_variant_count(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (!(t0 == 1711u)) {
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
        l3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
        l3 = concat_2(436u, l3);
        t1 = vader_comptime_vm_required(l2, l3);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_comptime_intrinsic_field_index(l0, l1);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_comptime_evaluate_module_decls(void* l0, void* l1, void* l2, void* l3, vader_string_t l4, void* l5) {
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l18 = NULL;
    void* l19 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l24 = NULL;
    void* l27 = NULL;
    void* l29 = NULL;
    size_t l8, l9;
    vader_box_t l14 = vader_box_null(), l16 = vader_box_null(), l20 = vader_box_null(), l23 = vader_box_null(), l26 = vader_box_null();
    int32_t l25, l28, l30;
    int64_t t0;
    bool t1;
    vader_box_t t2 = vader_box_null();
    void* t3 = NULL;
    vader_box_t* gc_roots[6] = { &l14, &l16, &l20, &l23, &l26, &t2 };
    void** gc_raw_roots[21] = {
        &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l10, &l11, &l12, &l13, &l15, &l17, &l18, &l19, &l21,
        &l22, &l24, &l27, &l29, &t3,
    };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 21u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = vader_comptime_sort_comptime_decls(l0, l1);
    l7 = ((vader_struct_vader_comptime_ComptimeOrder_t*) l6)->f_cycle_diags;
    l8 = ((vader_array_t*) l7)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l10 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        vader_array_push((vader_array_t*) l5, vader_ref_box(l10));
        t0 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t0;
    }
    l7 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
    vader_struct_vader_comptime_ComptimeContext_t* _a1_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a1_obj, 870u);
    _a1_obj->f_typed = l1;
    _a1_obj->f_bindings = l7;
    _a1_obj->f_depth = INT64_C(0);
    l7 = (void*) _a1_obj;
    l6 = ((vader_struct_vader_comptime_ComptimeOrder_t*) l6)->f_order;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
        l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
        l11 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ConstDecl_t*) l10)->f_value, l7);
        t1 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_vm_required;
        if (t1) {
            l12 = ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved;
            l13 = ((vader_struct_toolchain_ast_ConstDecl_t*) l10)->f_name_span;
            l14 = vader_resolver_symbol_declared_at(l12, l13);
            if (!(l14.tag == 0u)) {
                l15 = l14.payload.obj;
                l16 = vader_comptime_build_vm_required(l10, l15, l1, l4);
                if (l16.tag == 887u) {
                    l17 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_vm_required;
                    l18 = l16.payload.obj;
                    vader_array_push((vader_array_t*) l17, vader_ref_box(l18));
                    t0 = (l9 + INT64_C(1));
                    l9 = (size_t) (int64_t) t0;
                    continue;
                }
            }
            if (!(((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag.tag == 0u)) {
                t2 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag;
                l19 = t2.payload.obj;
                vader_array_push((vader_array_t*) l5, vader_ref_box(l19));
            }
            t0 = (l9 + INT64_C(1));
            l9 = (size_t) (int64_t) t0;
            continue;
        }
        l20 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_value;
        if (!(l20.tag == 0u)) {
            l21 = ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved;
            l22 = ((vader_struct_toolchain_ast_ConstDecl_t*) l10)->f_name_span;
            l23 = vader_resolver_symbol_declared_at(l21, l22);
            if (!(l23.tag == 0u)) {
                l24 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
                t3 = l23.payload.obj;
                l25 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t3)->f_id;
                l26 = l20;
                std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l24, l25, l26);
                l27 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_routes;
                t3 = l23.payload.obj;
                l28 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t3)->f_id;
                std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l27, l28, vader_box_i32(285u, INT32_C(0)));
            }
        }
        if (!(((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag.tag == 0u)) {
            t2 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag;
            l29 = t2.payload.obj;
            vader_array_push((vader_array_t*) l5, vader_ref_box(l29));
        }
        t0 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t0;
    }
    l6 = l0;
    l8 = ((vader_array_t*) l6)->length;
    l9 = (size_t) 0;
    while ((l9 < l8)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
        l14 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
        if (l14.tag == 531u) {
            t3 = l14.payload.obj;
            t1 = vader_comptime_has_comptime_decorator(t3);
            if (t1) {
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                continue;
            }
            l11 = ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved;
            t3 = l14.payload.obj;
            l12 = ((vader_struct_toolchain_ast_ConstDecl_t*) t3)->f_name_span;
            l16 = vader_resolver_symbol_declared_at(l11, l12);
            if (l16.tag == 0u) {
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                continue;
            }
            l10 = l16.payload.obj;
            l13 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
            l25 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_id;
            t2 = std_collections_MutableMap_std_core_Index_at__i32__Any(l13, l25);
            if (t2.tag == 0u) {
                t3 = l14.payload.obj;
                l15 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ConstDecl_t*) t3)->f_value, l7);
                if (!(((vader_struct_vader_comptime_EvalResult_t*) l15)->f_value.tag == 0u)) {
                    l17 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
                    l28 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_id;
                    l20 = ((vader_struct_vader_comptime_EvalResult_t*) l15)->f_value;
                    std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l17, l28, l20);
                    l18 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_routes;
                    l30 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_id;
                    std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l18, l30, vader_box_i32(285u, INT32_C(2)));
                }
            } else {
                t0 = (l9 + INT64_C(1));
                l9 = (size_t) (int64_t) t0;
                continue;
            }
        }
        t0 = (l9 + INT64_C(1));
        l9 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_comptime_evaluate_null_lit(void* l0) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_31;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t1 = vader_comptime_ok(vader_ref_box(t0));
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_comptime_evaluate_project(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    size_t l7, l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_box_t l13 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    int64_t t2;
    vader_box_t* gc_roots[2] = { &l13, &t0 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l11, &l12, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_comptime_new_evaluated_project(l1);
    l4 = ((vader_struct_vader_typecheck_TypedProject_t*) l1)->f_modules;
    l5 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l4)->f_evals;
    l7 = (size_t) 0;
    l8 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l4)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l7];
        l9 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        l10 = l9;
        l11 = l4;
        l12 = vader_comptime_new_evaluated_program(l11);
        l13 = vader_comptime_lookup_module_decls(l0, l10);
        if (!(l13.tag == 0u)) {
            t1 = l13.payload.obj;
            vader_comptime_evaluate_module_decls(t1, l11, l12, l3, l10, l2);
            t1 = l13.payload.obj;
            vader_comptime_evaluate_assert_decls(t1, l12, l2);
            t1 = l13.payload.obj;
            vader_comptime_bake_file_exprs(t1, l3, l12);
        }
        std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_modules, l10, vader_ref_box(l12));
        t2 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t2;
    }
    l4 = vader_comptime_harvest_instances(l1);
    ((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_instances = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_comptime_EvaluatedProject_t*) l3);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(228u, 0u, 13u, 1583u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l0)->f_elements;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
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
    }
    l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_expr_types;
    l5 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l0)->f_id;
    l8 = std_collections_MutableMap_std_core_Index_at__usize__Any(l4, l5);
    if (l8.tag == 1232u) {
        vader_array_t* _a3_arr = vader_array_new(15u, 0u, 0u, 282u);
        l4 = (void*) _a3_arr;
        vader_array_t* _a4_arr = vader_array_new(23u, 0u, 0u, 293u);
        l7 = (void*) _a4_arr;
        vader_array_t* _a5_arr = vader_array_new(16u, 0u, 7u, 285u);
        l9 = (void*) _a5_arr;
        vader_struct_std_collections_MutableMap__string__Any_t* _a6_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
        vader_obj_header_init(_a6_obj, 410u);
        _a6_obj->f_ekeys = l4;
        _a6_obj->f_evals = l7;
        _a6_obj->f_index = l9;
        _a6_obj->f_mask = (size_t) 0;
        _a6_obj->f_size = (size_t) 0;
        _a6_obj->f_tombs = (size_t) 0;
        l4 = (void*) _a6_obj;
        l5 = (size_t) 0;
        l6 = ((vader_array_t*) l3)->length;
        while ((l5 < l6)) {
            l7 = std_core_new_byte_buffer((size_t) 21);
            l10 = (size_t) 0;
            l10 = std_core_write_string_at(l7, l10, 830u);
            t2 = ((int64_t) (size_t) l5);
            l11 = (uint64_t) (int64_t) t2;
            l10 = std_core_write_unsigned(l7, l10, l11);
            l12 = std_core_finish_buffer(l7, l10);
            vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l13 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
            std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(l4, l12, l13);
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
        }
        t3 = l8.payload.obj;
        t4 = vader_types_display_type(vader_ref_box(t3));
        vader_struct_vader_comptime_StructValue_t* _a8_obj = (vader_struct_vader_comptime_StructValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_StructValue_t));
        vader_obj_header_init(_a8_obj, 885u);
        _a8_obj->f_type_name = t4;
        _a8_obj->f_fields = l4;
        t3 = (void*) _a8_obj;
        t5 = vader_comptime_ok(vader_ref_box(t3));
        { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l12 = 0u;
    if (l8.tag == 1218u) {
        t3 = l8.payload.obj;
        l12 = vader_types_display_type(((vader_struct_vader_types_ArrayType_t*) t3)->f_element);
        vader_struct_vader_comptime_ArrayValue_t* _a9_obj = (vader_struct_vader_comptime_ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ArrayValue_t));
        vader_obj_header_init(_a9_obj, 866u);
        _a9_obj->f_elements = l3;
        _a9_obj->f_element_type_name = l12;
        t3 = (void*) _a9_obj;
        t5 = vader_comptime_ok(vader_ref_box(t3));
        { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_comptime_ArrayValue_t* _a10_obj = (vader_struct_vader_comptime_ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ArrayValue_t));
    vader_obj_header_init(_a10_obj, 866u);
    _a10_obj->f_elements = l3;
    _a10_obj->f_element_type_name = l12;
    t3 = (void*) _a10_obj;
    t5 = vader_comptime_ok(vader_ref_box(t3));
    { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 517u);
    _a1_obj->f_parts = t0;
    l3 = (void*) _a1_obj;
    l4 = ((vader_struct_toolchain_ast_StringLitExpr_t*) l0)->f_parts;
    l5 = ((vader_array_t*) l4)->length;
    l6 = (size_t) 0;
    while ((l6 < l5)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l6)
        l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l6);
        if (l7.tag == 590u) {
            t0 = l7.payload.obj;
            l8 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_value;
            std_string_builder_append(l3, l8);
        } else {
            if (!(l7.tag == 589u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l7.payload.obj;
            vader_fn_t* _a3_fnobj = (vader_fn_t*) l2;
            t1 = ((vader_fn_erased_sig_2_t) _a3_fnobj->code)(_a3_fnobj->env, ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, vader_ref_box(l1));
            l9 = t1.payload.obj;
            if (((vader_struct_vader_comptime_EvalResult_t*) l9)->f_value.tag == 0u) {
                { void* __vret = l9; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l10 = vader_comptime_interp_value(((vader_struct_vader_comptime_EvalResult_t*) l9)->f_value);
            std_string_builder_append(l3, l10);
        }
        t2 = (l6 + INT64_C(1));
        l6 = (size_t) (int64_t) t2;
    }
    t3 = std_string_builder_StringBuilder_std_core_Display_to_string(l3);
    t1 = vader_comptime_string_val(t3);
    t0 = vader_comptime_ok(t1);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_unary_expr(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    size_t l5;
    vader_string_t l6 = 0;
    uint8_t l7;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l4, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
    t0 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_operand, vader_ref_box(l1));
    l3 = t0.payload.obj;
    l4 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
    if (l4.tag == 0u) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_id;
    l6 = vader_comptime_resolved_int_name(l1, l5);
    l7 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_op;
    if (l7 == INT32_C(0)) {
        l3 = vader_comptime_unary_neg(l0, l4, l6);
        t1 = vader_comptime_normalize_int_result(l3, l6);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l7 == INT32_C(1)) {
        l3 = vader_comptime_unary_not(l0, l4);
    } else {
        if (!(l7 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = vader_comptime_unary_bit_not(l0, l4);
    }
    t1 = vader_comptime_normalize_int_result(l3, l6);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_fail(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_EvalResult_t* _a0_obj = (vader_struct_vader_comptime_EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvalResult_t));
    vader_obj_header_init(_a0_obj, 872u);
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    _a0_obj->f_diag = vader_ref_box(l0);
    _a0_obj->f_vm_required = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_file_constants(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l8 = NULL;
    size_t l4, l5, l7;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 4u, 292u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 0u, 293u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__usize__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__usize__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__Any_t));
    vader_obj_header_init(_a3_obj, 479u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    l2 = l0;
    l4 = ((vader_array_t*) l2)->length;
    l5 = (size_t) 0;
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l6 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
        if (l6.tag == 531u) {
            t0 = l6.payload.obj;
            if (((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_value.tag == 564u) {
                t0 = l6.payload.obj;
                l3 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_value.payload.obj;
                t1 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l3)->f_name;
                if (t1 == 1717u) {
                    l7 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l3)->f_id;
                    l8 = l6.payload.obj;
                    std_collections_MutableMap_std_core_IndexSet_set_at__usize__Any(l1, l7, vader_ref_box(l8));
                }
            }
        }
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static double vader_comptime_float_arith(uint8_t l0, double l1, double l2) {
    double l3;
    if (l0 == INT32_C(0)) {
        l3 = (l1 + l2);
        return l3;
    }
    if (l0 == INT32_C(1)) {
        l3 = (l1 - l2);
    } else if (l0 == INT32_C(2)) {
        l3 = (l1 * l2);
    } else if (l0 == INT32_C(3)) {
        l3 = l1 / l2;
    } else {
        l3 = 0.0;
    }
    return l3;
}

static bool vader_comptime_float_compare(double l0, double l1, uint8_t l2) {
    bool l3;
    if (l2 == INT32_C(0)) {
        l3 = l0 == l1;
        return l3;
    }
    if (l2 == INT32_C(1)) {
        l3 = l0 != l1;
    } else if (l2 == INT32_C(2)) {
        l3 = (l0 < l1);
    } else if (l2 == INT32_C(3)) {
        l3 = (l0 <= l1);
    } else if (l2 == INT32_C(4)) {
        l3 = (l0 > l1);
    } else {
        if (!(l2 == INT32_C(5))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = (l0 >= l1);
    }
    return l3;
}

static vader_box_t vader_comptime_float_val(double l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_FloatValue_t* _a0_obj = (vader_struct_vader_comptime_FloatValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_FloatValue_t));
    vader_obj_header_init(_a0_obj, 876u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = 1671u;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_comptime_float_val_typed(double l0, vader_string_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_FloatValue_t* _a0_obj = (vader_struct_vader_comptime_FloatValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_FloatValue_t));
    vader_obj_header_init(_a0_obj, 876u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    void* l46 = NULL;
    void* l47 = NULL;
    void* l48 = NULL;
    size_t l5, l6, l10, l11, l16, l17, l22, l23, l28, l29, l34, l35, l40, l41, l43, l44, l49, l50;
    vader_box_t l12 = vader_box_null(), l18 = vader_box_null(), l24 = vader_box_null(), l30 = vader_box_null(), l36 = vader_box_null(), l45 = vader_box_null(), l51 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    int32_t t2;
    int64_t t3;
    void* t4 = NULL;
    vader_box_t* gc_roots[8] = { &l12, &l18, &l24, &l30, &l36, &l45, &l51, &t0 };
    void** gc_raw_roots[28] = {
        &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l9, &l13, &l14, &l15, &l19, &l20, &l21, &l25, &l26,
        &l27, &l31, &l32, &l33, &l37, &l38, &l39, &l42, &l46, &l47, &l48, &t4,
    };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 8u, 28u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 0u, 293u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 410u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(80u, 0u, 13u, 877u);
    l2 = (void*) _a4_arr;
    vader_struct_vader_comptime_InstanceRegistry_t* _a5_obj = (vader_struct_vader_comptime_InstanceRegistry_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_InstanceRegistry_t));
    vader_obj_header_init(_a5_obj, 878u);
    _a5_obj->f_by_key = l1;
    _a5_obj->f_order = l2;
    l1 = (void*) _a5_obj;
    l2 = ((vader_struct_vader_typecheck_TypedProject_t*) l0)->f_modules;
    l3 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l2)->f_ekeys;
    l4 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l2)->f_evals;
    l5 = (size_t) 0;
    l6 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l2)->f_size;
    while ((l5 < l6)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        t0 = vader_array_box_slots(_a6_slotarr->buf)[_a6_slotarr->offset + (size_t) l5];
        t1 = t0.payload.s;
        vader_array_t* _a7_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        l2 = vader_array_ref_load_obj(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_decl_types;
        l8 = ((vader_struct_std_collections_MutableMap__i32__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l7)->f_ekeys;
        l9 = ((vader_struct_std_collections_MutableMap__i32__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l7)->f_evals;
        l10 = (size_t) 0;
        l11 = ((vader_struct_std_collections_MutableMap__i32__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l7)->f_size;
        while ((l10 < l11)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l10)
            t2 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l10];
            vader_array_t* _a9_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l10)
            l12 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l10);
            vader_comptime_observe(l1, l12);
            t3 = (l10 + INT64_C(1));
            l10 = (size_t) (int64_t) t3;
        }
        l13 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_expr_types;
        l14 = ((vader_struct_std_collections_MutableMap__usize__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l13)->f_ekeys;
        l15 = ((vader_struct_std_collections_MutableMap__usize__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l13)->f_evals;
        l16 = (size_t) 0;
        l17 = ((vader_struct_std_collections_MutableMap__usize__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l13)->f_size;
        while ((l16 < l17)) {
            vader_array_t* _a10_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l16)
            t3 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l16];
            vader_array_t* _a11_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l16)
            l18 = vader_array_ref_load_box(_a11_slotarr->buf, _a11_slotarr->offset + (size_t) l16);
            vader_comptime_observe(l1, l18);
            t3 = (l16 + INT64_C(1));
            l16 = (size_t) (int64_t) t3;
        }
        l19 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_local_types;
        l20 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l19)->f_ekeys;
        l21 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l19)->f_evals;
        l22 = (size_t) 0;
        l23 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l19)->f_size;
        while ((l22 < l23)) {
            vader_array_t* _a12_slotarr = ((vader_array_t*) l20);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l22)
            t3 = ((int64_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l22];
            vader_array_t* _a13_slotarr = ((vader_array_t*) l21);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l22)
            l24 = vader_array_ref_load_box(_a13_slotarr->buf, _a13_slotarr->offset + (size_t) l22);
            vader_comptime_observe(l1, l24);
            t3 = (l22 + INT64_C(1));
            l22 = (size_t) (int64_t) t3;
        }
        l25 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_param_types;
        l26 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l25)->f_ekeys;
        l27 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l25)->f_evals;
        l28 = (size_t) 0;
        l29 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l25)->f_size;
        while ((l28 < l29)) {
            vader_array_t* _a14_slotarr = ((vader_array_t*) l26);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l28)
            t3 = ((int64_t*) _a14_slotarr->buf->slots)[_a14_slotarr->offset + (size_t) l28];
            vader_array_t* _a15_slotarr = ((vader_array_t*) l27);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l28)
            l30 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l28);
            vader_comptime_observe(l1, l30);
            t3 = (l28 + INT64_C(1));
            l28 = (size_t) (int64_t) t3;
        }
        l31 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_type_expr_types;
        l32 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l31)->f_ekeys;
        l33 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l31)->f_evals;
        l34 = (size_t) 0;
        l35 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l31)->f_size;
        while ((l34 < l35)) {
            vader_array_t* _a16_slotarr = ((vader_array_t*) l32);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l34)
            t3 = ((int64_t*) _a16_slotarr->buf->slots)[_a16_slotarr->offset + (size_t) l34];
            vader_array_t* _a17_slotarr = ((vader_array_t*) l33);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l34)
            l36 = vader_array_ref_load_box(_a17_slotarr->buf, _a17_slotarr->offset + (size_t) l34);
            vader_comptime_observe(l1, l36);
            t3 = (l34 + INT64_C(1));
            l34 = (size_t) (int64_t) t3;
        }
        l37 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_impl_methods;
        l38 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_ImplMethod___t*) l37)->f_ekeys;
        l39 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_ImplMethod___t*) l37)->f_evals;
        l40 = (size_t) 0;
        l41 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_ImplMethod___t*) l37)->f_size;
        while ((l40 < l41)) {
            vader_array_t* _a18_slotarr = ((vader_array_t*) l38);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l40)
            t0 = vader_array_box_slots(_a18_slotarr->buf)[_a18_slotarr->offset + (size_t) l40];
            t1 = t0.payload.s;
            vader_array_t* _a19_slotarr = ((vader_array_t*) l39);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l40)
            l42 = vader_array_ref_load_obj(_a19_slotarr->buf, _a19_slotarr->offset + (size_t) l40);
            l43 = ((vader_array_t*) l42)->length;
            l44 = (size_t) 0;
            while ((l44 < l43)) {
                vader_array_t* _a20_slotarr = ((vader_array_t*) l42);
                VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
                t4 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l44);
                l45 = ((vader_struct_vader_typecheck_ImplMethod_t*) t4)->f_ty;
                vader_comptime_observe(l1, l45);
                t3 = (l44 + INT64_C(1));
                l44 = (size_t) (int64_t) t3;
            }
            t3 = (l40 + INT64_C(1));
            l40 = (size_t) (int64_t) t3;
        }
        l46 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_impl_method_decl_types;
        l47 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l46)->f_ekeys;
        l48 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l46)->f_evals;
        l49 = (size_t) 0;
        l50 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l46)->f_size;
        while ((l49 < l50)) {
            vader_array_t* _a21_slotarr = ((vader_array_t*) l47);
            VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l49)
            t3 = ((int64_t*) _a21_slotarr->buf->slots)[_a21_slotarr->offset + (size_t) l49];
            vader_array_t* _a22_slotarr = ((vader_array_t*) l48);
            VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l49)
            l51 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l49);
            vader_comptime_observe(l1, l51);
            t3 = (l49 + INT64_C(1));
            l49 = (size_t) (int64_t) t3;
        }
        t3 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t3;
    }
    t4 = vader_comptime_sorted_instances(l1);
    { void* __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_comptime_has_comptime_decorator(void* l0) {
    void* l1;
    size_t l2, l3;
    void* t0;
    vader_string_t t1;
    int64_t t2;
    l1 = ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_decorators;
    l2 = ((vader_array_t*) l1)->length;
    l3 = (size_t) 0;
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = ((vader_struct_toolchain_ast_Decorator_t*) t0)->f_name;
        if (t1 == 1505u) {
            return true;
        }
        t2 = (l3 + INT64_C(1));
        l3 = (size_t) (int64_t) t2;
    }
    return false;
}

static bool vader_comptime_has_union_operand(void* l0, void* l1) {
    void* l2;
    size_t l3;
    void* t0;
    vader_box_t t1;
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l0)->f_typed)->f_expr_types;
    t0 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_left.payload.obj;
    l3 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_id;
    t1 = std_collections_MutableMap_std_core_Index_at__usize__Any(l2, l3);
    if (t1.tag == 1235u) {
        return true;
    }
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l0)->f_typed)->f_expr_types;
    t0 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_right.payload.obj;
    l3 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_id;
    t1 = std_collections_MutableMap_std_core_Index_at__usize__Any(l2, l3);
    return t1.tag == 1235u;
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = 0u;
    l2 = (size_t) 0;
    l3 = ((vader_array_t*) l0)->length;
    while ((l2 < l3)) {
        if ((l2 > INT64_C(0))) {
            l1 = concat_2(l1, 285u);
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
        l4 = vader_comptime_canonical_type_key(t0);
        l1 = concat_2(l1, l4);
        t1 = (l2 + INT64_C(1));
        l2 = (size_t) (int64_t) t1;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_comptime_int_bits_of(vader_string_t l0) {
    bool t0;
    int64_t t1, t2;
    t0 = vader_types_is_int_name(l0);
    if (!(t0)) {
        return INT64_C(64);
    }
    t1 = vader_types_primitive_size(l0);
    t2 = vader_chk_mul(i64, t1, INT64_C(8));
    return t2;
}

static bool vader_comptime_int_compare(int64_t l0, int64_t l1, uint8_t l2) {
    bool l3;
    if (l2 == INT32_C(0)) {
        l3 = l0 == l1;
        return l3;
    }
    if (l2 == INT32_C(1)) {
        l3 = l0 != l1;
    } else if (l2 == INT32_C(2)) {
        l3 = (l0 < l1);
    } else if (l2 == INT32_C(3)) {
        l3 = (l0 <= l1);
    } else if (l2 == INT32_C(4)) {
        l3 = (l0 > l1);
    } else {
        if (!(l2 == INT32_C(5))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l3 = (l0 >= l1);
    }
    return l3;
}

static void* vader_comptime_int_div_check(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3) {
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 879u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        if (t1 == INT64_C(0)) {
            t0 = vader_comptime_division_by_zero(l0, 356u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_comptime_arithmetic(l0, l1, l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_arithmetic(l0, l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_int_mod_check(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 879u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        if (t1 == INT64_C(0)) {
            t0 = vader_comptime_division_by_zero(l0, 214u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_comptime_arithmetic_int(l0, l1, l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_arithmetic_int(l0, l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_int_val(int64_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_IntValue_t* _a0_obj = (vader_struct_vader_comptime_IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_IntValue_t));
    vader_obj_header_init(_a0_obj, 879u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = 1794u;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_comptime_int_val_typed(int64_t l0, vader_string_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_IntValue_t* _a0_obj = (vader_struct_vader_comptime_IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_IntValue_t));
    vader_obj_header_init(_a0_obj, 879u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 879u) {
        l2 = std_core_new_byte_buffer((size_t) 20);
        l3 = (size_t) 0;
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        l3 = std_core_write_int(l2, l3, l4);
        l1 = std_core_finish_buffer(l2, l3);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 876u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
        l1 = std_core_f64_Display_to_string(t1);
    } else if (l0.tag == 868u) {
        l2 = std_core_new_byte_buffer((size_t) 5);
        l3 = (size_t) 0;
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
        l3 = std_core_write_bool(l2, l3, l5);
        l1 = std_core_finish_buffer(l2, l3);
    } else if (l0.tag == 884u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
    } else if (l0.tag == 869u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_comptime_CharValue_t*) t0)->f_value;
        l1 = std_core_char_Display_to_string(((uint32_t) (uint32_t) t2));
    } else if (l0.tag == 883u) {
        l1 = 2103u;
    } else if (l0.tag == 888u) {
        l1 = 0u;
    } else if (l0.tag == 866u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_display_value(vader_ref_box(t0));
    } else if (l0.tag == 885u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_display_value(vader_ref_box(t0));
    } else {
        if (!(l0.tag == 886u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = vader_comptime_display_value(vader_ref_box(t0));
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
        t1 = vader_comptime_arg_count_error(l0, 1273u, (size_t) 1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t3 = vader_comptime_byte_align(l2);
        t2 = vader_comptime_int_val_typed(t3, 2509u);
        t1 = vader_comptime_ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_comptime_arg_error(l0, 1274u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
        t1 = vader_comptime_arg_count_error(l0, 1709u, (size_t) 1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t3 = vader_comptime_type_field_count(l2, l1);
        t2 = vader_comptime_int_val_typed(t3, 2509u);
        t1 = vader_comptime_ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_comptime_arg_error(l0, 1710u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(2)) {
        t1 = vader_comptime_arg_count_error(l0, 1711u, (size_t) 2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1714u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(1))
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(1));
    l3 = toolchain_ast_string_literal_text(t2);
    if (l3.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1713u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 1230u)) {
        l9 = vader_types_display_type(l2);
        l10 = concat_3(1712u, l9, 986u);
        t1 = vader_comptime_arg_error(l0, l10);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_struct_decls;
    t1 = l2.payload.obj;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t1)->f_symbol)->f_id;
    l6 = std_collections_MutableMap_std_core_Index_at__i32__Any(l4, l5);
    if (!(l6.tag == 591u)) {
        t1 = l2.payload.obj;
        l9 = vader_types_display_type(vader_ref_box(t1));
        l10 = concat_3(1715u, l9, 1016u);
        t1 = vader_comptime_arg_error(l0, l10);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = (size_t) 0;
    t1 = l6.payload.obj;
    l8 = ((vader_array_t*) ((vader_struct_toolchain_ast_StructDecl_t*) t1)->f_fields)->length;
    while ((l7 < l8)) {
        t1 = l6.payload.obj;
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_StructDecl_t*) t1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l7)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_toolchain_ast_StructField_t*) t1)->f_name;
        l10 = l3.payload.s;
        if (l9 == l10) {
            t2 = vader_comptime_int_val_typed(((int64_t) (size_t) l7), 2509u);
            t1 = vader_comptime_ok(t2);
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t3 = (l7 + INT64_C(1));
        l7 = (size_t) (int64_t) t3;
    }
    t1 = l2.payload.obj;
    l9 = vader_types_display_type(vader_ref_box(t1));
    l10 = l3.payload.s;
    l9 = concat_5(1712u, l9, 944u, l10, 887u);
    t1 = vader_comptime_arg_error(l0, l9);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
        t1 = vader_comptime_arg_count_error(l0, 2237u, (size_t) 1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t3 = vader_comptime_byte_size(l2);
        t2 = vader_comptime_int_val_typed(t3, 2509u);
        t1 = vader_comptime_ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_comptime_arg_error(l0, 2239u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 2429u, (size_t) 1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t3 = vader_comptime_type_kind_label(l2);
        t2 = vader_comptime_string_val(t3);
        t1 = vader_comptime_ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_comptime_arg_error(l0, 2430u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 2431u, (size_t) 1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t3 = vader_types_display_type(l2);
        t2 = vader_comptime_string_val(t3);
        t1 = vader_comptime_ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_comptime_arg_error(l0, 2432u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
        t1 = vader_comptime_arg_count_error(l0, 2649u, (size_t) 1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t3 = vader_comptime_type_variant_count(l2);
        t2 = vader_comptime_int_val_typed(t3, 2509u);
        t1 = vader_comptime_ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_comptime_arg_error(l0, 2650u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_comptime_is_concrete_enough(vader_box_t l0) {
    if (!((l0.tag == 1222u || l0.tag == 1223u || l0.tag == 1224u || l0.tag == 1229u || l0.tag == 1236u))) {
        return true;
    }
    return false;
}

static bool vader_comptime_is_primitive_int_name(vader_string_t l0) {
    bool t0;
    t0 = vader_types_is_int_name(l0);
    return t0;
}

static bool vader_comptime_is_resolved(vader_box_t l0) {
    if (!(l0.tag == 1236u)) {
        return true;
    }
    return false;
}

static bool vader_comptime_is_type_symbol_kind(uint8_t l0) {
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
        return true;
    }
    return false;
}

static vader_box_t vader_comptime_lookup_module_decls(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    size_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l2, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = std_collections_MutableMap_std_core_Index_at__string__Any(((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_modules, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.obj;
    l2 = ((vader_struct_vader_resolver_Module_t*) ((vader_struct_vader_resolver_LoadedModule_t*) l2)->f_module)->f_files;
    t0 = ((vader_array_t*) l2)->length;
    if (!(t0 == INT64_C(0))) {
        t1 = vader_resolver_concat_file_decls(l2);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_string_t vader_comptime_mangle_type_arg(vader_box_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_types_strip_distinct(l0);
    t1 = vader_types_qualified_display_type(t0);
    t2 = vader_comptime_sanitise_ident(t1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_mask_shift_amount(vader_box_t l0, vader_string_t l1) {
    int64_t l2, l3;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t1 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 879u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
    l3 = vader_comptime_shift_amount_mask(l1);
    l2 = (l2 & l3);
    t0 = l0.payload.obj;
    l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
    t1 = vader_comptime_int_val_typed(l2, l4);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_new_evaluated_program(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(16u, 0u, 7u, 285u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 0u, 293u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 368u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(16u, 0u, 7u, 285u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 0u, 293u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(16u, 0u, 7u, 285u);
    l4 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a7_obj, 368u);
    _a7_obj->f_ekeys = l2;
    _a7_obj->f_evals = l3;
    _a7_obj->f_index = l4;
    _a7_obj->f_mask = (size_t) 0;
    _a7_obj->f_size = (size_t) 0;
    _a7_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(79u, 0u, 13u, 875u);
    l3 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(76u, 0u, 13u, 867u);
    l4 = (void*) _a9_arr;
    vader_struct_vader_comptime_EvaluatedProgram_t* _a10_obj = (vader_struct_vader_comptime_EvaluatedProgram_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvaluatedProgram_t));
    vader_obj_header_init(_a10_obj, 873u);
    _a10_obj->f_typed = l0;
    _a10_obj->f_comptime_decls = l1;
    _a10_obj->f_routes = l2;
    _a10_obj->f_file_reads = l3;
    _a10_obj->f_asserts = l4;
    t0 = (void*) _a10_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 0u, 293u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(16u, 0u, 7u, 285u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 410u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = (size_t) 0;
    _a3_obj->f_size = (size_t) 0;
    _a3_obj->f_tombs = (size_t) 0;
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(16u, 0u, 7u, 285u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 0u, 293u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(16u, 0u, 7u, 285u);
    l4 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a7_obj, 368u);
    _a7_obj->f_ekeys = l2;
    _a7_obj->f_evals = l3;
    _a7_obj->f_index = l4;
    _a7_obj->f_mask = (size_t) 0;
    _a7_obj->f_size = (size_t) 0;
    _a7_obj->f_tombs = (size_t) 0;
    l2 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 4u, 292u);
    l3 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(15u, 0u, 0u, 282u);
    l4 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(16u, 0u, 7u, 285u);
    l5 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__usize__string_t* _a11_obj = (vader_struct_std_collections_MutableMap__usize__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__string_t));
    vader_obj_header_init(_a11_obj, 483u);
    _a11_obj->f_ekeys = l3;
    _a11_obj->f_evals = l4;
    _a11_obj->f_index = l5;
    _a11_obj->f_mask = (size_t) 0;
    _a11_obj->f_size = (size_t) 0;
    _a11_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(80u, 0u, 13u, 877u);
    l4 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(82u, 0u, 13u, 887u);
    l5 = (void*) _a13_arr;
    vader_struct_vader_comptime_EvaluatedProject_t* _a14_obj = (vader_struct_vader_comptime_EvaluatedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvaluatedProject_t));
    vader_obj_header_init(_a14_obj, 874u);
    _a14_obj->f_typed = l0;
    _a14_obj->f_modules = l1;
    _a14_obj->f_file_baked_consts = l2;
    _a14_obj->f_file_exprs = l3;
    _a14_obj->f_instances = l4;
    _a14_obj->f_vm_required = l5;
    t0 = (void*) _a14_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_comptime_EvalResult_t*) l0)->f_value.tag == 879u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_comptime_EvalResult_t*) l0)->f_value.payload.obj;
    t0 = ((vader_struct_vader_comptime_IntValue_t*) l2)->f_value;
    l3 = vader_comptime_wrap_to_width(t0, l1);
    l4 = vader_comptime_result_type_name(l2, l1);
    t1 = vader_comptime_int_val_typed(l3, l4);
    t2 = vader_comptime_ok(t1);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_comptime_observe(void* l0, vader_box_t l1) {
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_comptime_walk_type(l0, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_comptime_ok(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_EvalResult_t* _a0_obj = (vader_struct_vader_comptime_EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvalResult_t));
    vader_obj_header_init(_a0_obj, 872u);
    _a0_obj->f_value = l0;
    _a0_obj->f_diag = vader_box_obj(0u, NULL);
    _a0_obj->f_vm_required = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t vader_comptime_op_add(int64_t l0, int64_t l1) {
    return (l0 + l1);
}

bool vader_comptime_op_and(bool l0, bool l1) {
    if (l0) {
        return l1;
    }
    return false;
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

static int64_t vader_comptime_op_div(int64_t l0, int64_t l1) {
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
    if (l0) {
        return true;
    }
    return l1;
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
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    size_t l3, l4, l5;
    vader_box_t l7 = vader_box_null(), l11 = vader_box_null();
    int32_t l13;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l7, &l11 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l6, &l8, &l9, &l10, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        l5 = (size_t) (int64_t) t0;
        l7 = std_collections_MutableMap_std_core_Index_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_id, l5);
        if (l7.tag == 0u) {
            t0 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t0;
            continue;
        }
        l6 = l7.payload.obj;
        l9 = ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved;
        l10 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l6)->f_decl)->f_name_span;
        l11 = vader_resolver_symbol_declared_at(l9, l10);
        if (l11.tag == 0u) {
            t0 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t0;
            continue;
        }
        l8 = l11.payload.obj;
        l12 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_symbol;
        l13 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l8)->f_id;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__usize(l12, l13, l5);
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    l2 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) 0;
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
        l5 = (size_t) (int64_t) t0;
        l7 = std_collections_MutableMap_std_core_Index_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_id, l5);
        if (l7.tag == 0u) {
            t0 = (l4 + INT64_C(1));
            l4 = (size_t) (int64_t) t0;
            continue;
        }
        l6 = l7.payload.obj;
        vader_array_t* _a2_arr = vader_array_new(22u, 0u, 4u, 292u);
        l8 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(13u, 0u, 12u, 280u);
        l9 = (void*) _a3_arr;
        vader_array_t* _a4_arr = vader_array_new(16u, 0u, 7u, 285u);
        l10 = (void*) _a4_arr;
        vader_struct_std_collections_MutableMap__usize__bool_t* _a5_obj = (vader_struct_std_collections_MutableMap__usize__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__bool_t));
        vader_obj_header_init(_a5_obj, 481u);
        _a5_obj->f_ekeys = l8;
        _a5_obj->f_evals = l9;
        _a5_obj->f_index = l10;
        _a5_obj->f_mask = (size_t) 0;
        _a5_obj->f_size = (size_t) 0;
        _a5_obj->f_tombs = (size_t) 0;
        l12 = (void*) _a5_obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l6)->f_decl)->f_value, l1, l0, l12, l6);
        std_collections_MutableMap_std_core_IndexSet_set_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_id, l5, vader_ref_box(l6));
        t0 = (l4 + INT64_C(1));
        l4 = (size_t) (int64_t) t0;
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_comptime_read_relative_file(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t2 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_starts_with(l0, 356u);
    if (t0) {
        l2 = l0;
    } else if (l1 == 0u) {
        l2 = l0;
    } else {
        l2 = concat_3(l1, 356u, l0);
    }
    l3 = std_io_read_file_string(l2, (size_t) 16777216);
    if (!(l3.tag == 282u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = l3.payload.s;
    t2 = vader_box_string(282u, t1);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 517u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string_builder_append_char(l1, 91u);
    l2 = ((vader_array_t*) ((vader_struct_vader_comptime_ArrayValue_t*) l0)->f_elements)->length;
    t1 = ((int64_t) 16);
    l3 = (size_t) (int64_t) t1;
    l4 = (l2 > l3);
    if (l4) {
        t1 = ((int64_t) 8);
        l3 = (size_t) (int64_t) t1;
    } else {
        l3 = l2;
    }
    l5 = (size_t) 0;
    while ((l5 < l3)) {
        if ((l5 > INT64_C(0))) {
            std_string_builder_append(l1, 287u);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_comptime_ArrayValue_t*) l0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l6 = vader_comptime_display_value(t2);
        std_string_builder_append(l1, l6);
        t1 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t1;
    }
    if (l4) {
        l7 = std_core_new_byte_buffer((size_t) 35);
        l3 = (size_t) 0;
        l3 = std_core_write_string_at(l7, l3, 289u);
        t1 = ((int64_t) (size_t) l2);
        l8 = (uint64_t) (int64_t) t1;
        l3 = std_core_write_unsigned(l7, l3, l8);
        l3 = std_core_write_string_at(l7, l3, 66u);
        l6 = std_core_finish_buffer(l7, l3);
        std_string_builder_append(l1, l6);
    }
    std_string_builder_append_char(l1, 93u);
    t3 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 517u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = ((vader_struct_vader_comptime_StructValue_t*) l0)->f_type_name;
    std_string_builder_append(l1, l2);
    std_string_builder_append(l1, 164u);
    l3 = std_collections_keys__string__vader_comptime_ArrayValue___vader_comptime_BoolValue___vader_comptime_CharValue___vader_comptime_FloatValue___vader_comptime_IntValue___vader_comptime_NullValue___vader_comptime_StringValue___vader_comptime_StructValue___vader_comptime_TypeValue___vader_comptime_VoidValue(((vader_struct_vader_comptime_StructValue_t*) l0)->f_fields);
    l4 = (void*) &vader_fn_static___lambda_vader_comptime_1;
    l3 = std_sort_sort__string(l3, l4);
    l5 = (size_t) 0;
    l6 = ((vader_array_t*) l3)->length;
    while ((l5 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l5];
        l2 = t1.payload.s;
        l8 = std_collections_MutableMap_std_core_Index_at__string__Any(((vader_struct_vader_comptime_StructValue_t*) l0)->f_fields, l2);
        if (l8.tag == 0u) {
            t2 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t2;
            continue;
        }
        l7 = l8;
        if ((l5 > INT64_C(0))) {
            std_string_builder_append(l1, 287u);
        }
        std_string_builder_append_char(l1, 46u);
        std_string_builder_append(l1, l2);
        std_string_builder_append(l1, 46u);
        l9 = vader_comptime_display_value(l7);
        std_string_builder_append(l1, l9);
        t2 = (l5 + INT64_C(1));
        l5 = (size_t) (int64_t) t2;
    }
    std_string_builder_append(l1, 167u);
    t3 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_resolve_type_arg(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &l4 };
    void** gc_raw_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved;
    l3 = vader_comptime_diag_sink();
    l4 = vader_typecheck_type_from_expr(l0, l2, l3);
    if (!(l4.tag == 1236u)) {
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_string_t vader_comptime_resolved_int_name(void* l0, size_t l1) {
    vader_box_t l2;
    void* t0;
    vader_string_t t1;
    l2 = std_collections_MutableMap_std_core_Index_at__usize__Any(((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l0)->f_typed)->f_expr_types, l1);
    if (l2.tag == 1228u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_types_PrimitiveType_t*) t0)->f_name;
        return t1;
    }
    if (!(l2.tag == 1224u)) {
        return 0u;
    }
    return 1794u;
}

static vader_string_t vader_comptime_result_type_name(void* l0, vader_string_t l1) {
    vader_string_t t0;
    if (!(l1 != 0u)) {
        t0 = ((vader_struct_vader_comptime_IntValue_t*) l0)->f_type_name;
        return t0;
    }
    return l1;
}

static bool vader_comptime_same_kind(vader_box_t l0, vader_box_t l1) {
    bool l2;
    if (l0.tag == 879u) {
        l2 = l1.tag == 879u;
        return l2;
    }
    if (l0.tag == 876u) {
        l2 = l1.tag == 876u;
    } else if (l0.tag == 868u) {
        l2 = l1.tag == 868u;
    } else if (l0.tag == 869u) {
        l2 = l1.tag == 869u;
    } else if (l0.tag == 884u) {
        l2 = l1.tag == 884u;
    } else if (l0.tag == 883u) {
        l2 = l1.tag == 883u;
    } else if (l0.tag == 888u) {
        l2 = l1.tag == 888u;
    } else if (l0.tag == 866u) {
        l2 = l1.tag == 866u;
    } else if (l0.tag == 885u) {
        l2 = l1.tag == 885u;
    } else {
        if (!(l0.tag == 886u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l1.tag == 886u;
    }
    return l2;
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(15u, 0u, 0u, 282u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 517u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = (size_t) 0;
    while ((l3 < l2)) {
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
    }
    t3 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_comptime_shift_amount_mask(vader_string_t l0) {
    bool l1;
    if (l0 == 1838u) {
        l1 = true;
    } else {
        l1 = l0 == 2464u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1793u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2443u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 1794u;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == 2444u;
    }
    if (l1) {
        return INT64_C(31);
    }
    return INT64_C(63);
}

static int64_t vader_comptime_sign_extend(int64_t l0, int64_t l1) {
    int64_t l2, l3, l4;
    int64_t t0;
    l2 = (INT64_C(1) << l1);
    l3 = vader_chk_sub(i64, l2, INT64_C(1));
    l3 = (l0 & l3);
    l4 = (l2 >> INT64_C(1));
    if (!((l3 & l4) != INT64_C(0))) {
        return l3;
    }
    t0 = vader_chk_sub(i64, l3, l2);
    return t0;
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
}

static void* vader_comptime_sorted_instances(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_order;
    l2 = (void*) &vader_fn_static___lambda_vader_comptime_0;
    t0 = std_sort_sort__vader_comptime_GenericInstance(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_comptime_span_of(vader_box_t l0) {
    void* l1;
    void* t0;
    if (l0.tag == 563u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_IntLitExpr_t*) t0)->f_span;
        return l1;
    }
    if (l0.tag == 574u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_span;
    } else if (l0.tag == 547u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_FloatLitExpr_t*) t0)->f_span;
    } else if (l0.tag == 525u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_BoolLitExpr_t*) t0)->f_span;
    } else if (l0.tag == 575u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_NullLitExpr_t*) t0)->f_span;
    } else if (l0.tag == 530u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_CharLitExpr_t*) t0)->f_span;
    } else if (l0.tag == 588u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_span;
    } else if (l0.tag == 553u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_span;
    } else if (l0.tag == 528u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_span;
    } else if (l0.tag == 546u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_span;
    } else if (l0.tag == 561u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_span;
    } else if (l0.tag == 602u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_span;
    } else if (l0.tag == 523u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_span;
    } else if (l0.tag == 556u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_span;
    } else if (l0.tag == 570u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_span;
    } else if (l0.tag == 524u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_BlockExpr_t*) t0)->f_span;
    } else if (l0.tag == 566u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_span;
    } else if (l0.tag == 593u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_span;
    } else if (l0.tag == 586u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_span;
    } else if (l0.tag == 581u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_span;
    } else if (l0.tag == 522u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_span;
    } else if (l0.tag == 529u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_span;
    } else if (l0.tag == 552u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_span;
    } else if (l0.tag == 564u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_span;
    } else if (l0.tag == 541u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) t0)->f_span;
    } else if (l0.tag == 550u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_FnTypeExpr_t*) t0)->f_span;
    } else {
        if (!(l0.tag == 518u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = ((vader_struct_toolchain_ast_ArrayTypeExpr_t*) t0)->f_span;
    }
    return l1;
}

vader_box_t vader_comptime_string_val(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_StringValue_t* _a0_obj = (vader_struct_vader_comptime_StringValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_StringValue_t));
    vader_obj_header_init(_a0_obj, 884u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(33u, 0u, 13u, 531u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(84u, 0u, 13u, 891u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 4u, 292u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(16u, 0u, 7u, 285u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(16u, 0u, 7u, 285u);
    l5 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__usize__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__usize__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__i32_t));
    vader_obj_header_init(_a5_obj, 482u);
    _a5_obj->f_ekeys = l3;
    _a5_obj->f_evals = l4;
    _a5_obj->f_index = l5;
    _a5_obj->f_mask = (size_t) 0;
    _a5_obj->f_size = (size_t) 0;
    _a5_obj->f_tombs = (size_t) 0;
    l3 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 4u, 292u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(13u, 0u, 12u, 280u);
    l5 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(16u, 0u, 7u, 285u);
    l6 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__usize__bool_t* _a9_obj = (vader_struct_std_collections_MutableMap__usize__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__usize__bool_t));
    vader_obj_header_init(_a9_obj, 481u);
    _a9_obj->f_ekeys = l4;
    _a9_obj->f_evals = l5;
    _a9_obj->f_index = l6;
    _a9_obj->f_mask = (size_t) 0;
    _a9_obj->f_size = (size_t) 0;
    _a9_obj->f_tombs = (size_t) 0;
    l4 = (void*) _a9_obj;
    l5 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l7 = ((vader_array_t*) l5)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        t0 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l8];
        l9 = (size_t) (int64_t) t0;
        std_collections_MutableMap_std_core_IndexSet_set_at__usize__i32(l3, l9, INT32_C(0));
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    vader_array_t* _a11_arr = vader_array_new(22u, 0u, 4u, 292u);
    l5 = (void*) _a11_arr;
    l6 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l7 = ((vader_array_t*) l6)->length;
    l8 = (size_t) 0;
    while ((l8 < l7)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        t0 = ((int64_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l8];
        vader_comptime_visit((size_t) (int64_t) t0, l0, l3, l4, l5, (size_t) 0, l1, l2);
        t0 = (l8 + INT64_C(1));
        l8 = (size_t) (int64_t) t0;
    }
    vader_struct_vader_comptime_ComptimeOrder_t* _a13_obj = (vader_struct_vader_comptime_ComptimeOrder_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeOrder_t));
    vader_obj_header_init(_a13_obj, 871u);
    _a13_obj->f_order = l1;
    _a13_obj->f_cycle_diags = l2;
    t1 = (void*) _a13_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_comptime_type_field_count(vader_box_t l0, void* l1) {
    void* l2;
    int32_t l3;
    vader_box_t l4;
    void* t0;
    size_t t1;
    if (l0.tag == 1230u) {
        l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_struct_decls;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
        l4 = std_collections_MutableMap_std_core_Index_at__i32__Any(l2, l3);
        if (!(l4.tag == 591u)) {
            return INT64_C(0);
        }
        t0 = l4.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_fields)->length;
        return ((int64_t) (size_t) t1);
    }
    if (!(l0.tag == 1232u)) {
        return INT64_C(0);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_array_t*) ((vader_struct_vader_types_TupleType_t*) t0)->f_elements)->length;
    return ((int64_t) (size_t) t1);
}

static vader_box_t vader_comptime_type_from_expr_safe(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_resolved;
    l3 = vader_comptime_diag_sink();
    l4 = vader_typecheck_type_from_expr(vader_ref_box(l0), l2, l3);
    t0 = vader_comptime_is_resolved(l4);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_comptime_type_kind_label(vader_box_t l0) {
    vader_string_t l1 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1228u) {
        l1 = 2159u;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1219u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_type_kind_label(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1230u) {
        l1 = 2330u;
    } else if (l0.tag == 1220u) {
        l1 = 1599u;
    } else if (l0.tag == 1235u) {
        l1 = 2479u;
    } else if (l0.tag == 1218u) {
        l1 = 1313u;
    } else if (l0.tag == 1232u) {
        l1 = 2406u;
    } else if (l0.tag == 1221u) {
        l1 = 1725u;
    } else if (l0.tag == 1231u) {
        l1 = 2398u;
    } else if (l0.tag == 1233u) {
        l1 = 2409u;
    } else if (l0.tag == 1234u) {
        l1 = 2480u;
    } else if (l0.tag == 1225u) {
        t0 = l0.payload.obj;
        vader_types_leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 1229u) {
        l1 = 2480u;
    } else if (l0.tag == 1236u) {
        l1 = 2480u;
    } else if (l0.tag == 1224u) {
        l1 = 2480u;
    } else if (l0.tag == 1222u) {
        l1 = 2480u;
    } else if (l0.tag == 1223u) {
        l1 = 2480u;
    } else if (l0.tag == 1226u) {
        l1 = 2480u;
    } else {
        if (!(l0.tag == 1217u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1302u;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_type_mismatch(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span;
    t0 = vader_diagnostics_comptime_error((uint8_t) 6, l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_type_val(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_TypeValue_t* _a0_obj = (vader_struct_vader_comptime_TypeValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_TypeValue_t));
    vader_obj_header_init(_a0_obj, 886u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_comptime_type_variant_count(vader_box_t l0) {
    void* t0;
    size_t t1;
    if (l0.tag == 1235u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_types_UnionType_t*) t0)->f_variants)->length;
        return ((int64_t) (size_t) t1);
    }
    if (!(l0.tag == 1220u)) {
        return INT64_C(0);
    }
    t0 = l0.payload.obj;
    t1 = std_collections_len__string__i64(((vader_struct_vader_types_EnumType_t*) t0)->f_indices);
    return ((int64_t) (size_t) t1);
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 879u)) {
        t0 = vader_comptime_unary_type_mismatch(l0, 1202u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
    l2 = vader_comptime_bit_not_i64(t1);
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
    t2 = vader_comptime_int_val_typed(l2, l3);
    t0 = vader_comptime_ok(t2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_unary_neg(void* l0, vader_box_t l1, vader_string_t l2) {
    vader_string_t l3 = 0;
    int64_t l4, l6;
    bool l5;
    vader_box_t l7 = vader_box_null();
    double l8;
    void* t0 = NULL;
    double t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l7, &t2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 879u) {
        t0 = l1.payload.obj;
        l3 = vader_comptime_result_type_name(t0, l2);
        l4 = vader_comptime_int_bits_of(l3);
        l5 = vader_types_is_unsigned_int_name(l3);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        l7 = vader_integer_checked_negation(l4, l5, l6);
        t0 = vader_comptime_checked_result(((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_span, l7, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 876u)) {
        t0 = vader_comptime_unary_type_mismatch(l0, 1108u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
    l8 = -(t1);
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_type_name;
    t2 = vader_comptime_float_val_typed(l8, l3);
    t0 = vader_comptime_ok(t2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_unary_not(void* l0, vader_box_t l1) {
    void* t0 = NULL;
    void* t2 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 868u)) {
        t0 = vader_comptime_unary_type_mismatch(l0, 1075u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
    if (!(t1)) {
        t0 = (void*) &vader_data_32;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        t2 = vader_comptime_ok(vader_ref_box(t0));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = (void*) &vader_data_33;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    t2 = vader_comptime_ok(vader_ref_box(t0));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_unary_type_mismatch(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_span;
    t0 = vader_diagnostics_comptime_error((uint8_t) 6, l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_collections_MutableMap_std_core_Index_at__string__bool(l0, l1);
    if (t0.tag == 0u) {
        std_collections_MutableMap_std_core_IndexSet_set_at__string__bool(l0, l1, true);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = INT32_C(1);
    while ((l2 < INT32_C(1000000))) {
        l4 = l1;
        l5 = vader_host_std_core_byte_len(l4);
        l6 = std_core_new_byte_buffer((size_t) (int64_t) (INT64_C(21) + l5));
        l7 = (size_t) 0;
        l7 = std_core_write_string_at(l6, l7, l4);
        l7 = std_core_write_string_at(l6, l7, 830u);
        l8 = ((int64_t) (int32_t) l2);
        l7 = std_core_write_int(l6, l7, l8);
        l3 = std_core_finish_buffer(l6, l7);
        t0 = std_collections_MutableMap_std_core_Index_at__string__bool(l0, l3);
        if (t0.tag == 0u) {
            std_collections_MutableMap_std_core_IndexSet_set_at__string__bool(l0, l3, true);
            { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = vader_chk_add(i32, l2, INT32_C(1));
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
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
    l9 = std_collections_MutableMap_std_core_Index_at__usize__i32(l2, l0);
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
    std_collections_MutableMap_std_core_IndexSet_set_at__usize__i32(l2, l0, INT32_C(1));
    l10 = ((vader_array_t*) l4)->length;
    if ((l5 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5] = (int64_t) (int64_t) (size_t) l0;
    } else {
        vader_array_push_i64((vader_array_t*) l4, (int64_t) (size_t) l0);
    }
    l9 = std_collections_MutableMap_std_core_Index_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l1)->f_by_id, l0);
    if (!(l9.tag == 0u)) {
        t0 = l9.payload.obj;
        l11 = ((vader_struct_vader_comptime_NodeRecord_t*) t0)->f_dependency_ids;
        l10 = ((vader_array_t*) l11)->length;
        l12 = (size_t) 0;
        while ((l12 < l10)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t1 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l12];
            l13 = (size_t) (int64_t) t1;
            t1 = vader_chk_add(usize, l5, INT64_C(1));
            l14 = (size_t) (int64_t) t1;
            vader_comptime_visit(l13, l1, l2, l3, l4, l14, l6, l7);
            t1 = (l12 + INT64_C(1));
            l12 = (size_t) (int64_t) t1;
        }
    }
    std_collections_MutableMap_std_core_IndexSet_set_at__usize__i32(l2, l0, INT32_C(2));
    t2 = std_collections_MutableMap_std_core_Index_at__usize__bool(l3, l0);
    if (t2.tag == 0u) {
        l9 = std_collections_MutableMap_std_core_Index_at__usize__Any(((vader_struct_vader_comptime_Nodes_t*) l1)->f_by_id, l0);
        if (!(l9.tag == 0u)) {
            t0 = l9.payload.obj;
            l11 = ((vader_struct_vader_comptime_NodeRecord_t*) t0)->f_decl;
            vader_array_push((vader_array_t*) l6, vader_ref_box(l11));
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_comptime_vm_required(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_diagnostics_comptime_error((uint8_t) 0, l0, l1);
    vader_struct_vader_comptime_EvalResult_t* _a0_obj = (vader_struct_vader_comptime_EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvalResult_t));
    vader_obj_header_init(_a0_obj, 872u);
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    _a0_obj->f_diag = vader_ref_box(l2);
    _a0_obj->f_vm_required = true;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_comptime_walk_type(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    size_t l4, l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    size_t t1;
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1230u) {
        t0 = l1.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_args)->length;
        if ((t1 > INT64_C(0))) {
            t0 = l1.payload.obj;
            t2 = vader_comptime_all_concrete_enough(((vader_struct_vader_types_StructType_t*) t0)->f_args);
            if (t2) {
                t0 = l1.payload.obj;
                l2 = ((vader_struct_vader_types_StructType_t*) t0)->f_symbol;
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
                vader_comptime_add(l0, l2, l3);
            }
        }
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_types_StructType_t*) t0)->f_args;
        l4 = ((vader_array_t*) l2)->length;
        l5 = (size_t) 0;
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_comptime_walk_type(l0, l6);
            t3 = (l5 + INT64_C(1));
            l5 = (size_t) (int64_t) t3;
        }
    } else if (!(l1.tag == 1220u)) {
        if (l1.tag == 1231u) {
            t0 = l1.payload.obj;
            t1 = ((vader_array_t*) ((vader_struct_vader_types_TraitType_t*) t0)->f_args)->length;
            if ((t1 > INT64_C(0))) {
                t0 = l1.payload.obj;
                t2 = vader_comptime_all_concrete_enough(((vader_struct_vader_types_TraitType_t*) t0)->f_args);
                if (t2) {
                    t0 = l1.payload.obj;
                    l2 = ((vader_struct_vader_types_TraitType_t*) t0)->f_symbol;
                    t0 = l1.payload.obj;
                    l3 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
                    vader_comptime_add(l0, l2, l3);
                }
            }
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_types_TraitType_t*) t0)->f_args;
            l4 = ((vader_array_t*) l2)->length;
            l5 = (size_t) 0;
            while ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                vader_comptime_walk_type(l0, l6);
                t3 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t3;
            }
        } else if (l1.tag == 1218u) {
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
            vader_comptime_walk_type(l0, l6);
        } else if (l1.tag == 1232u) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
            l4 = ((vader_array_t*) l2)->length;
            l5 = (size_t) 0;
            while ((l5 < l4)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                vader_comptime_walk_type(l0, l6);
                t3 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t3;
            }
        } else if (l1.tag == 1235u) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            l4 = ((vader_array_t*) l2)->length;
            l5 = (size_t) 0;
            while ((l5 < l4)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                l6 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
                vader_comptime_walk_type(l0, l6);
                t3 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t3;
            }
        } else if (l1.tag == 1221u) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
            l4 = ((vader_array_t*) l2)->length;
            l5 = (size_t) 0;
            while ((l5 < l4)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                l6 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                vader_comptime_walk_type(l0, l6);
                t3 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t3;
            }
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_types_FnType_t*) t0)->f_return_type;
            vader_comptime_walk_type(l0, l6);
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int64_t vader_comptime_wrap_to_width(int64_t l0, vader_string_t l1) {
    int64_t l2;
    if (l1 == 1838u) {
        l2 = vader_comptime_sign_extend(l0, INT64_C(8));
        return l2;
    }
    if (l1 == 2464u) {
        l2 = (l0 & INT64_C(255));
    } else if (l1 == 1793u) {
        l2 = vader_comptime_sign_extend(l0, INT64_C(16));
    } else if (l1 == 2443u) {
        l2 = (l0 & INT64_C(65535));
    } else if (l1 == 1794u) {
        l2 = vader_comptime_sign_extend(l0, INT64_C(32));
    } else if (l1 == 2444u) {
        l2 = (l0 & INT64_C(4294967295));
    } else {
        l2 = l0;
    }
    return l2;
}
