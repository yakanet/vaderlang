#include "bootstrap.split.h"

static void* vader_comptime_add(void* l0, void* l1, void* l2);
static bool vader_comptime_all_concrete_enough(void* l0);
static void* vader_comptime_arg_count_error(void* l0, vader_string_t l1, int64_t l2);
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
static vader_box_t vader_comptime_build_vm_required(void* l0, void* l1, void* l2, vader_string_t l3);
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
static vader_string_t vader_comptime_cycle_names(int64_t l0, int64_t l1, void* l2, int64_t l3, void* l4);
static void* vader_comptime_diag_sink(void);
static void* vader_comptime_display_enum(void* l0, vader_box_t l1, void* l2);
static vader_string_t vader_comptime_display_value(vader_box_t l0);
static void* vader_comptime_division_by_zero(void* l0, vader_string_t l1);
static void vader_comptime_emit_cycle(int64_t l0, void* l1, int64_t l2, void* l3, void* l4, void* l5);
static void* vader_comptime_evaluate_aggregate(vader_box_t l0, void* l1);
static void vader_comptime_evaluate_assert_decls(void* l0, void* l1, void* l2);
static void* vader_comptime_evaluate_binary_expr(void* l0, void* l1);
static void* vader_comptime_evaluate_bool_lit(void* l0);
static void* vader_comptime_evaluate_call_expr(void* l0, void* l1);
static void* vader_comptime_evaluate_char_lit(void* l0);
static void* vader_comptime_evaluate_dot_variant(void* l0, void* l1);
static void* vader_comptime_evaluate_expr(vader_box_t l0, void* l1);
static void vader_comptime_evaluate_extern_libraries(void* l0, void* l1, void* l2);
static void* vader_comptime_evaluate_field(void* l0, void* l1);
static void* vader_comptime_evaluate_float_lit(void* l0);
static void* vader_comptime_evaluate_fn_body(void* l0, void* l1, void* l2);
static void* vader_comptime_evaluate_ident(void* l0, void* l1);
static void* vader_comptime_evaluate_int_lit(void* l0, void* l1);
static void* vader_comptime_evaluate_intrinsic_call(void* l0, void* l1);
static vader_box_t vader_comptime_evaluate_library(void* l0, void* l1, void* l2);
static void* vader_comptime_evaluate_match(void* l0, void* l1);
static void vader_comptime_evaluate_module_decls(void* l0, void* l1, void* l2, void* l3, vader_string_t l4, void* l5);
static void* vader_comptime_evaluate_null_lit(void* l0);
static vader_box_t vader_comptime_evaluate_project_const(void* l0, void* l1, void* l2);
static void* vader_comptime_evaluate_seq_lit(void* l0, void* l1);
static void* vader_comptime_evaluate_string_lit(void* l0, void* l1);
static void* vader_comptime_evaluate_struct_lit(void* l0, void* l1, void* l2);
static void* vader_comptime_evaluate_unary_expr(void* l0, void* l1);
static void* vader_comptime_evaluate_with_arguments(void* l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_comptime_fail(void* l0);
static void* vader_comptime_file_constants(void* l0);
static double vader_comptime_float_arith(uint8_t l0, double l1, double l2);
static bool vader_comptime_float_compare(double l0, double l1, uint8_t l2);
static vader_box_t vader_comptime_float_val(double l0);
static vader_string_t vader_comptime_folder_beside(vader_string_t l0, vader_string_t l1);
static void* vader_comptime_harvest_instances(void* l0, vader_string_t l1);
static bool vader_comptime_has_comptime_decorator(void* l0);
static bool vader_comptime_has_union_operand(void* l0, void* l1);
static int64_t vader_comptime_int_bits_of(vader_string_t l0);
static bool vader_comptime_int_compare(int64_t l0, int64_t l1, uint8_t l2);
static vader_string_t vader_comptime_int_digits(void* l0);
static void* vader_comptime_int_div_check(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
static void* vader_comptime_int_mod_check(void* l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_comptime_int_val(int64_t l0);
static vader_string_t vader_comptime_interp_value(vader_box_t l0);
static void* vader_comptime_intrinsic_align_of(void* l0, void* l1);
static void* vader_comptime_intrinsic_field_count(void* l0, void* l1);
static void* vader_comptime_intrinsic_field_index(void* l0, void* l1);
static void* vader_comptime_intrinsic_integer_bound(void* l0, void* l1);
static void* vader_comptime_intrinsic_satisfies(void* l0, void* l1);
static void* vader_comptime_intrinsic_size_of(void* l0, void* l1);
static void* vader_comptime_intrinsic_type_kind(void* l0, void* l1);
static void* vader_comptime_intrinsic_type_name(void* l0, void* l1);
static void* vader_comptime_intrinsic_variant_count(void* l0, void* l1);
static bool vader_comptime_is_concrete_enough(vader_box_t l0);
static bool vader_comptime_is_primitive_int_name(vader_string_t l0);
static bool vader_comptime_is_resolved(vader_box_t l0);
static vader_box_t vader_comptime_lookup_module_decls(void* l0, vader_string_t l1);
static vader_box_t vader_comptime_mask_shift_amount(vader_box_t l0, vader_string_t l1);
static vader_box_t vader_comptime_native_library(vader_box_t l0, vader_string_t l1);
static void* vader_comptime_new_evaluated_program(void* l0);
static void* vader_comptime_new_evaluated_project(void* l0);
static void* vader_comptime_normalize_int_result(void* l0, vader_string_t l1);
static void vader_comptime_observe(void* l0, vader_box_t l1);
static void* vader_comptime_ok(vader_box_t l0);
static int64_t vader_comptime_op_div(int64_t l0, int64_t l1);
static vader_box_t vader_comptime_pattern_holds(vader_box_t l0, vader_box_t l1);
static void vader_comptime_populate_deps(void* l0, void* l1);
static vader_box_t vader_comptime_read_relative_file(vader_string_t l0, vader_string_t l1);
static vader_string_t vader_comptime_render_array(void* l0);
static vader_string_t vader_comptime_render_struct(void* l0);
static vader_box_t vader_comptime_resolve_type_arg(vader_box_t l0, void* l1);
static vader_string_t vader_comptime_resolved_int_name(void* l0, int64_t l1);
static vader_string_t vader_comptime_result_type_name(void* l0, vader_string_t l1);
static bool vader_comptime_same_kind(vader_box_t l0, vader_box_t l1);
static int64_t vader_comptime_shift_amount_mask(vader_string_t l0);
static int64_t vader_comptime_sign_extend(int64_t l0, int64_t l1);
static void* vader_comptime_sort_comptime_decls(void* l0, void* l1);
static void* vader_comptime_sorted_instances(void* l0);
static vader_box_t vader_comptime_string_field(void* l0, vader_string_t l1);
static vader_box_t vader_comptime_strings_field(void* l0, vader_string_t l1);
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
static void* vader_comptime_variant_value(void* l0, vader_string_t l1, void* l2);
static void vader_comptime_visit(int64_t l0, void* l1, void* l2, void* l3, void* l4, int64_t l5, void* l6, void* l7);
static void* vader_comptime_vm_required(void* l0, vader_string_t l1);
static void vader_comptime_walk_type(void* l0, vader_box_t l1);

static void* vader_comptime_add(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    vader_string_t l4 = 0;
    int64_t l5, l7;
    vader_box_t l8 = vader_box_null();
    int32_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l6, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_types_strip_distinct_each(l2);
    l4 = vader_types_canonical_args_key(l3);
    l5 = vader_host_std_core_byte_len(l4);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(22) + l5));
    l5 = INT64_C(0);
    t0 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
    l7 = ((int64_t) (int32_t) t0);
    l5 = std_core_write_int(l6, l5, l7);
    l5 = std_core_write_string_at(l6, l5, 264u);
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 281u);
    l4 = std_core_finish_buffer(l6, l5);
    l8 = std_collections_MutableMap_std_core_Index_at__string__Any(((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_by_key, l4);
    if (!(l8.tag == 935u)) {
        vader_struct_vader_comptime_GenericInstance_t* _a0_obj = (vader_struct_vader_comptime_GenericInstance_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_GenericInstance_t));
        vader_obj_header_init(_a0_obj, 935u);
        _a0_obj->f_symbol = l1;
        _a0_obj->f_args = l3;
        _a0_obj->f_display_key = l4;
        l3 = (void*) _a0_obj;
        std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_by_key, l4, vader_ref_box(l3));
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l8.payload.obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_comptime_all_concrete_enough(void* l0) {
    void* l1;
    int64_t l2, l3;
    vader_box_t t0;
    bool t1;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = vader_comptime_is_concrete_enough(t0);
        if (!(t1)) {
            return false;
        }
        l3 = (l3 + INT64_C(1));
    }
    return true;
}

static void* vader_comptime_arg_count_error(void* l0, vader_string_t l1, int64_t l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    vader_string_t l4 = 0;
    int64_t l5, l7;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[5] = { &l0, &l3, &l6, &t0, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
    l4 = l1;
    l5 = vader_host_std_core_byte_len(l4);
    l6 = (void*) vader_buffer_new((size_t) (INT64_C(68) + l5));
    l5 = INT64_C(0);
    l5 = std_core_write_string_at(l6, l5, 478u);
    l5 = std_core_write_string_at(l6, l5, l4);
    l5 = std_core_write_string_at(l6, l5, 90u);
    l5 = std_core_write_int(l6, l5, l2);
    l5 = std_core_write_string_at(l6, l5, 71u);
    l7 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    l5 = std_core_write_int(l6, l5, l7);
    l4 = std_core_finish_buffer(l6, l5);
    t0 = vader_diagnostics_comptime_error((uint8_t) 7, l3, l4);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    t0 = vader_diagnostics_comptime_error((uint8_t) 7, l2, l1);
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
    if (l1.tag == 937u) {
        if (l2.tag == 937u) {
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
    if (l1.tag == 934u) {
        if (l2.tag == 934u) {
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
        l6 = 2306u;
        t0 = vader_comptime_type_mismatch(l0, l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = 2306u;
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
    if (l1.tag == 937u) {
        if (l2.tag == 937u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
            t1 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(320u, l4), vader_box_i64(320u, l5));
            l4 = ((int64_t) t1.payload.i);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
            t1 = vader_comptime_int_val_typed(l4, l6);
            t0 = vader_comptime_ok(t1);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = 2307u;
        t0 = vader_comptime_type_mismatch(l0, l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = 2307u;
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
    if (!(l1.tag == 944u)) {
        l6 = l1;
        t0 = vader_comptime_arithmetic(l0, l6, l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 944u)) {
        t0 = vader_comptime_type_mismatch(l0, 2512u);
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
    if (!(l0.tag == 925u)) {
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
    int64_t l5, l6, l9;
    vader_box_t l10 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l10, &t0 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(46u, 0u, 13u, 617u);
    l3 = (void*) _a0_arr;
    l4 = l0;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        vader_comptime_collect_file_intrinsics(t0, l3);
        l6 = (l6 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_typed;
    l7 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
    vader_struct_vader_comptime_ComptimeContext_t* _a2_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a2_obj, 927u);
    _a2_obj->f_typed = l4;
    _a2_obj->f_bindings = l7;
    _a2_obj->f_depth = INT64_C(0);
    _a2_obj->f_project = vader_box_obj(0u, NULL);
    l4 = (void*) _a2_obj;
    l7 = vader_comptime_file_constants(l0);
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l6)
        l8 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l9 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l8)->f_id;
        l10 = std_collections_MutableMap_std_core_Index_at__i64__Any(l7, l9);
        vader_comptime_bake_one_file_expr(l8, l10, l4, l1, l2);
        l6 = (l6 + INT64_C(1));
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
    int64_t l9;
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
    if (!(((vader_struct_vader_comptime_EvalResult_t*) l5)->f_value.tag == 944u)) {
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
    std_collections_MutableMap_std_core_IndexSet_set_at__i64__string(l5, l9, l7);
    l5 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l4)->f_file_reads;
    l10 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
    l9 = vader_host_std_core_byte_len(l7);
    l8 = vader_comptime_constant_name(l1);
    vader_struct_vader_comptime_FileRead_t* _a1_obj = (vader_struct_vader_comptime_FileRead_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_FileRead_t));
    vader_obj_header_init(_a1_obj, 933u);
    _a1_obj->f_span = l10;
    _a1_obj->f_path = l6;
    _a1_obj->f_bytes = l9;
    _a1_obj->f_name = l8;
    l10 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l5, l10);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_EvaluatedProgram_t*) l4)->f_typed)->f_into_coercions;
    t1 = l1.payload.obj;
    l9 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, ((vader_struct_toolchain_ast_ConstDecl_t*) t1)->f_value.payload.obj);
    t0 = std_collections_MutableMap_std_core_Index_at__i64__Any(l5, l9);
    if (t0.tag == 0u) {
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
        t1 = vader_comptime_type_mismatch(l0, 1313u);
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
    if (l1.tag == 925u) {
        if (l2.tag == 925u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
            vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
            t1 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_bool(314u, l4), vader_box_bool(314u, l5));
            t2 = t1.payload.b;
            if (!(t2)) {
                t0 = (void*) &vader_data_37;
                vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
                t3 = vader_comptime_ok(vader_ref_box(t0));
                { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = (void*) &vader_data_36;
            vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
            t3 = vader_comptime_ok(vader_ref_box(t0));
            { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = 2164u;
        t0 = vader_comptime_type_mismatch(l0, l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = 2164u;
    t0 = vader_comptime_type_mismatch(l0, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_bool_value(bool l0) {
    void* t0;
    if (!(l0)) {
        t0 = (void*) &vader_data_37;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    t0 = (void*) &vader_data_36;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t0);
}

static vader_box_t vader_comptime_build_vm_required(void* l0, void* l1, void* l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    void* l6 = NULL;
    int32_t l7;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_value;
    if (l4.tag == 581u) {
        t0 = l4.payload.obj;
        l5 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee;
        if (l5.tag == 606u) {
            t0 = l4.payload.obj;
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args)->length;
            if (t1 == INT64_C(0)) {
                l6 = ((vader_struct_vader_typecheck_TypedProgram_t*) l2)->f_decl_types;
                l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
                l4 = std_collections_MutableMap_std_core_Index_at__i32__Any(l6, l7);
                if (!(l4.tag == 0u)) {
                    l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l1)->f_id;
                    t0 = l5.payload.obj;
                    l8 = ((vader_struct_toolchain_ast_IdentExpr_t*) t0)->f_name;
                    l6 = ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_span;
                    vader_struct_vader_comptime_VmRequiredDecl_t* _a0_obj = (vader_struct_vader_comptime_VmRequiredDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_VmRequiredDecl_t));
                    vader_obj_header_init(_a0_obj, 947u);
                    _a0_obj->f_symbol_id = l7;
                    _a0_obj->f_module_id = l3;
                    _a0_obj->f_callee_name = l8;
                    _a0_obj->f_decl_type = l4;
                    _a0_obj->f_span = l6;
                    t0 = (void*) _a0_obj;
                    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    l3 = concat_3(2581u, l2, 981u);
    t2 = vader_diagnostics_comptime_error((uint8_t) 11, l0, l3);
    t3 = vader_comptime_fail(t2);
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_comptime_collect_block_deps(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    int64_t l6, l7;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        vader_comptime_collect_stmt_deps(t0, l1, l2, l3, l4);
        l7 = (l7 + INT64_C(1));
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
    int64_t l8, l11;
    int32_t l10;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l7, &l12, &t1 };
    void** gc_raw_roots[7] = { &l1, &l2, &l3, &l4, &l5, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 606u) {
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
        l7 = std_collections_MutableMap_std_core_Index_at__i32__i64(l9, l10);
        if (l7.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l8 = ((int64_t) l7.payload.i);
        t1 = std_collections_MutableMap_std_core_Index_at__i64__bool(l3, l8);
        if (t1.tag == 314u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        std_collections_MutableMap_std_core_IndexSet_set_at__i64__bool(l3, l8, true);
        vader_array_push_i64((vader_array_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l4)->f_dependency_ids, l8);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 581u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
        l8 = ((vader_array_t*) l5)->length;
        l11 = INT64_C(0);
        while ((l11 < l8)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l11);
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1, l2, l3, l4);
            l11 = (l11 + INT64_C(1));
        }
    } else if (l0.tag == 599u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target, l1, l2, l3, l4);
    } else if (l0.tag == 614u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index, l1, l2, l3, l4);
    } else if (l0.tag == 655u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand, l1, l2, l3, l4);
    } else if (l0.tag == 576u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1, l2, l3, l4);
    } else if (l0.tag == 609u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_cond, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_then_block, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        l7 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_else_branch;
        l12 = l7;
        if (!(l7.tag == 0u)) {
            if (l7.tag == 608u) {
                t0 = l12.payload.obj;
                vader_comptime_collect_expr_deps(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1, l2, l3, l4);
            } else {
                if (!(l7.tag == 607u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l12.payload.obj;
                vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1, l2, l3, l4);
            }
        }
    } else if (l0.tag == 623u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_scrutinee, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_MatchExpr_t*) t0)->f_arms;
        l8 = ((vader_array_t*) l5)->length;
        l11 = INT64_C(0);
        while ((l11 < l8)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l9 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l11);
            if (!(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_guard.tag == 0u)) {
                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_guard, l1, l2, l3, l4);
            }
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_MatchArm_t*) l9)->f_body, l1, l2, l3, l4);
            l11 = (l11 + INT64_C(1));
        }
    } else if (l0.tag == 577u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_block_deps(t0, l1, l2, l3, l4);
    } else if (l0.tag == 646u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_type_name, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_StructLitExpr_t*) t0)->f_items;
        l8 = ((vader_array_t*) l5)->length;
        l11 = INT64_C(0);
        while ((l11 < l8)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l7 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l11);
            if (l7.tag == 647u) {
                t0 = l7.payload.obj;
                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value, l1, l2, l3, l4);
            } else {
                if (!(l7.tag == 648u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l7.payload.obj;
                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_expr, l1, l2, l3, l4);
            }
            l11 = (l11 + INT64_C(1));
        }
    } else if (l0.tag == 639u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) t0)->f_elements;
        l8 = ((vader_array_t*) l5)->length;
        l11 = INT64_C(0);
        while ((l11 < l8)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            t1 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l11);
            vader_comptime_collect_expr_deps(t1, l1, l2, l3, l4);
            l11 = (l11 + INT64_C(1));
        }
    } else if (l0.tag == 634u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_lower, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_RangeExpr_t*) t0)->f_upper, l1, l2, l3, l4);
    } else if (l0.tag == 575u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_AwaitExpr_t*) t0)->f_inner, l1, l2, l3, l4);
    } else if (l0.tag == 582u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_CastExpr_t*) t0)->f_value, l1, l2, l3, l4);
    } else if (l0.tag == 619u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_LambdaExpr_t*) t0)->f_body, l1, l2, l3, l4);
    } else if (l0.tag == 617u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
        l8 = ((vader_array_t*) l5)->length;
        l11 = INT64_C(0);
        while ((l11 < l8)) {
            vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            t1 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l11);
            vader_comptime_collect_expr_deps(t1, l1, l2, l3, l4);
            l11 = (l11 + INT64_C(1));
        }
    } else if (l0.tag == 605u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_GenericInstExpr_t*) t0)->f_callee, l1, l2, l3, l4);
    } else if (l0.tag == 641u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
        l8 = ((vader_array_t*) l5)->length;
        l11 = INT64_C(0);
        while ((l11 < l8)) {
            vader_array_t* _a5_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            l7 = vader_array_ref_load_box(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l11);
            if (l7.tag == 642u) {
                t0 = l7.payload.obj;
                vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1, l2, l3, l4);
            } else if (!(l7.tag == 643u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l11 = (l11 + INT64_C(1));
        }
    } else if (l0.tag == 627u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_left, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        l7 = toolchain_ast_coalesce_fallback_expr(((vader_struct_toolchain_ast_NullCoalesceExpr_t*) t0)->f_fallback);
        if (!(l7.tag == 0u)) {
            vader_comptime_collect_expr_deps(l7, l1, l2, l3, l4);
        }
    } else if (!((l0.tag == 578u || l0.tag == 583u || l0.tag == 594u || l0.tag == 600u || l0.tag == 616u || l0.tag == 628u))) {
        if (!((l0.tag == 572u || l0.tag == 603u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_comptime_collect_file_intrinsics(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    int64_t l5, l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l0, &l2, &l3 };
    void** gc_raw_roots[3] = { &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 601u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body;
        l3 = l2;
        if (!(l2.tag == 0u)) {
            if (!(l2.tag == 577u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l3.payload.obj;
            vader_comptime_collect_in_block(t0, l1);
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 610u) {
        t0 = l0.payload.obj;
        l4 = ((vader_struct_toolchain_ast_ImplDecl_t*) t0)->f_members;
        l5 = ((vader_array_t*) l4)->length;
        l6 = INT64_C(0);
        while ((l6 < l5)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
            l2 = ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_body;
            l3 = l2;
            if (!(l2.tag == 0u)) {
                if (!(l2.tag == 577u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l3.payload.obj;
                vader_comptime_collect_in_block(t0, l1);
            }
            l6 = (l6 + INT64_C(1));
        }
    } else if (l0.tag == 584u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_value, l1);
    } else if (l0.tag == 573u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_condition, l1);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_comptime_collect_in_block(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_stmts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        vader_comptime_collect_in_stmt(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    if (((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_BlockExpr_t*) l0)->f_trailing, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_comptime_collect_in_expr(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int64_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l5, &l6, &t3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 617u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_name;
        if (t1 == 1892u) {
            t0 = l0.payload.obj;
            t2 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args)->length;
            if (t2 == INT64_C(1)) {
                l2 = l0.payload.obj;
                vader_array_push_ref((vader_array_t*) l1, l2);
            }
        }
    }
    if (l0.tag == 577u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_block(t0, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 581u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_callee, l1);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_CallExpr_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 599u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_FieldExpr_t*) t0)->f_target, l1);
    } else if (l0.tag == 614u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_IndexExpr_t*) t0)->f_index, l1);
    } else if (l0.tag == 655u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_UnaryExpr_t*) t0)->f_operand, l1);
    } else if (l0.tag == 576u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_left, l1);
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) t0)->f_right, l1);
    } else if (l0.tag == 609u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_cond, l1);
        t0 = l0.payload.obj;
        vader_comptime_collect_in_block(((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_then_block, l1);
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_IfExpr_t*) t0)->f_else_branch;
        l6 = l5;
        if (!(l5.tag == 0u)) {
            if (l5.tag == 607u) {
                t0 = l6.payload.obj;
                vader_comptime_collect_in_block(((vader_struct_toolchain_ast_IfElseBlock_t*) t0)->f_block, l1);
            } else {
                if (!(l5.tag == 608u)) {
                    vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                }
                t0 = l6.payload.obj;
                vader_comptime_collect_in_expr(vader_ref_box(((vader_struct_toolchain_ast_IfElseIf_t*) t0)->f_branch), l1);
            }
        }
    } else if (l0.tag == 617u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_args;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t3 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
            vader_comptime_collect_in_expr(t3, l1);
            l4 = (l4 + INT64_C(1));
        }
    } else if (l0.tag == 641u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast_StringLitExpr_t*) t0)->f_parts;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            l5 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            if (l5.tag == 642u) {
                t0 = l5.payload.obj;
                vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1);
            }
            l4 = (l4 + INT64_C(1));
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_comptime_collect_in_stmt(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l5, &l6, &t1 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 620u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 574u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target, l1);
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 590u) {
        t0 = l0.payload.obj;
        l2 = toolchain_ast_assign_places(t0);
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
            vader_comptime_collect_in_expr(t1, l1);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_value, l1);
    } else if (l0.tag == 598u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1);
    } else if (l0.tag == 638u) {
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
        }
    } else if (l0.tag == 604u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form;
        l6 = l5;
        if (l5.tag == 656u) {
            t0 = l6.payload.obj;
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1);
        } else if (l5.tag == 613u) {
            t0 = l6.payload.obj;
            vader_comptime_collect_in_expr(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1);
        }
        t0 = l0.payload.obj;
        vader_comptime_collect_in_block(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_body, l1);
    } else if (l0.tag == 588u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_toolchain_ast_DeferStmt_t*) t0)->f_body;
        l6 = l5;
        if (l5.tag == 589u) {
            t0 = l6.payload.obj;
            vader_comptime_collect_in_stmt(((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt, l1);
        } else {
            if (!(l5.tag == 587u)) {
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
    int64_t l6, l7, l9, l11;
    vader_box_t l8 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l8 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 8u, 320u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 327u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 319u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i64__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__Any_t));
    vader_obj_header_init(_a3_obj, 461u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(23u, 0u, 8u, 320u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 7u, 319u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 8u, 320u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 319u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i32__i64_t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__i64_t));
    vader_obj_header_init(_a8_obj, 424u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a8_obj;
    vader_struct_vader_comptime_Nodes_t* _a9_obj = (vader_struct_vader_comptime_Nodes_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_Nodes_t));
    vader_obj_header_init(_a9_obj, 941u);
    _a9_obj->f_by_id = l1;
    _a9_obj->f_order = l2;
    _a9_obj->f_by_symbol = l3;
    l1 = (void*) _a9_obj;
    l2 = l0;
    l6 = ((vader_array_t*) l2)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l8 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l7);
        if (l8.tag == 584u) {
            t0 = l8.payload.obj;
            t1 = vader_comptime_has_comptime_decorator(t0);
            if (t1) {
                vader_array_t* _a11_arr = vader_array_new(23u, 0u, 8u, 320u);
                l3 = (void*) _a11_arr;
                l4 = ((vader_struct_vader_comptime_Nodes_t*) l1)->f_by_id;
                t0 = l8.payload.obj;
                l9 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_id;
                t0 = l8.payload.obj;
                vader_struct_vader_comptime_NodeRecord_t* _a12_obj = (vader_struct_vader_comptime_NodeRecord_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_NodeRecord_t));
                vader_obj_header_init(_a12_obj, 940u);
                _a12_obj->f_decl = t0;
                _a12_obj->f_dependency_ids = l3;
                l5 = (void*) _a12_obj;
                std_collections_MutableMap_std_core_IndexSet_set_at__i64__Any(l4, l9, vader_ref_box(l5));
                l10 = ((vader_struct_vader_comptime_Nodes_t*) l1)->f_order;
                t0 = l8.payload.obj;
                l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_id;
                vader_array_push_i64((vader_array_t*) l10, l11);
            } else {
                l7 = (l7 + INT64_C(1));
                continue;
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_comptime_collect_stmt_deps(vader_box_t l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    int64_t l6, l7;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l0, &l8, &l9, &t1 };
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 6u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 620u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_LetStmt_t*) t0)->f_value, l1, l2, l3, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 598u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_ExprStmt_t*) t0)->f_expr, l1, l2, l3, l4);
    } else if (l0.tag == 638u) {
        t0 = l0.payload.obj;
        if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
            t0 = l0.payload.obj;
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1, l2, l3, l4);
        }
    } else if (l0.tag == 574u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_target, l1, l2, l3, l4);
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_AssignStmt_t*) t0)->f_value, l1, l2, l3, l4);
    } else if (l0.tag == 590u) {
        t0 = l0.payload.obj;
        l5 = toolchain_ast_assign_places(t0);
        l6 = ((vader_array_t*) l5)->length;
        l7 = INT64_C(0);
        while ((l7 < l6)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
            vader_comptime_collect_expr_deps(t1, l1, l2, l3, l4);
            l7 = (l7 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_DestructureAssignStmt_t*) t0)->f_value, l1, l2, l3, l4);
    } else if (l0.tag == 604u) {
        t0 = l0.payload.obj;
        l8 = ((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_form;
        l9 = l8;
        if (l8.tag == 656u) {
            t0 = l9.payload.obj;
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_WhileFor_t*) t0)->f_cond, l1, l2, l3, l4);
        } else if (l8.tag == 613u) {
            t0 = l9.payload.obj;
            vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_InFor_t*) t0)->f_iter, l1, l2, l3, l4);
        } else if (!(l8.tag == 615u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_ForStmt_t*) t0)->f_body, l1, l2, l3, l4);
    } else if (l0.tag == 661u) {
        t0 = l0.payload.obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_YieldStmt_t*) t0)->f_value, l1, l2, l3, l4);
    } else if (l0.tag == 588u) {
        t0 = l0.payload.obj;
        l8 = ((vader_struct_toolchain_ast_DeferStmt_t*) t0)->f_body;
        l9 = l8;
        if (l8.tag == 589u) {
            t0 = l9.payload.obj;
            vader_comptime_collect_stmt_deps(((vader_struct_toolchain_ast_DeferStmtBody_t*) t0)->f_stmt, l1, l2, l3, l4);
        } else {
            if (!(l8.tag == 587u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l9.payload.obj;
            vader_comptime_collect_block_deps(((vader_struct_toolchain_ast_DeferBlockBody_t*) t0)->f_block, l1, l2, l3, l4);
        }
    } else if (!((l0.tag == 579u || l0.tag == 585u))) {
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
        l5 = vader_comptime_int_mod_check(l0, l1, l2);
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
        l5 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 538u);
    } else if (l4 == INT32_C(19)) {
        l5 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 537u);
    } else if (l4 == INT32_C(20)) {
        l5 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 539u);
    } else if (l4 == INT32_C(21)) {
        l5 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 541u);
    } else if (l4 == INT32_C(22)) {
        l5 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 540u);
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
    if (l1.tag == 937u) {
        if (l2.tag == 937u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
            t1 = vader_comptime_int_compare(l4, l5, l3);
            t2 = vader_comptime_bool_value(t1);
            t0 = vader_comptime_ok(t2);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l1.tag == 934u) {
        if (l2.tag == 934u) {
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l7 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
            t1 = vader_comptime_float_compare(l6, l7, l3);
            t2 = vader_comptime_bool_value(t1);
            t0 = vader_comptime_ok(t2);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l1.tag == 925u) {
        if (l2.tag == 925u) {
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
            l8 = l8 == l9;
            t0 = vader_comptime_bool_equality_only(l0, l8, l3);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l1.tag == 944u) {
        if (l2.tag == 944u) {
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
    if (!(l1.tag == 923u)) {
        if (!(l1.tag == 945u)) {
            l10 = 1674u;
            t0 = vader_comptime_type_mismatch(l0, l10);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t1 = vader_comptime_same_kind(l1, l2);
    if (t1) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_span, 1673u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = 1674u;
    t0 = vader_comptime_type_mismatch(l0, l10);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_constant_name(vader_box_t l0) {
    void* t0;
    vader_string_t t1;
    if (!(l0.tag == 0u)) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_name;
        return vader_box_string(316u, t1);
    }
    return vader_box_obj(0u, NULL);
}

static vader_string_t vader_comptime_cycle_names(int64_t l0, int64_t l1, void* l2, int64_t l3, void* l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l6, l9;
    vader_box_t l10 = vader_box_null();
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l10, &t1 };
    void** gc_raw_roots[6] = { &l2, &l4, &l5, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l11, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 316u);
    l5 = (void*) _a0_arr;
    l6 = l0;
    while ((l6 < l1)) {
        l8 = ((vader_struct_vader_comptime_Nodes_t*) l4)->f_by_id;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l9 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
        l10 = std_collections_MutableMap_std_core_Index_at__i64__Any(l8, l9);
        if (l10.tag == 0u) {
            l6 = (l6 + INT64_C(1));
            continue;
        }
        l7 = l10.payload.obj;
        l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l7)->f_decl)->f_name;
        vader_array_push_scalar((vader_array_t*) l5, vader_box_string(316u, l11));
        l6 = (l6 + INT64_C(1));
    }
    l10 = std_collections_MutableMap_std_core_Index_at__i64__Any(((vader_struct_vader_comptime_Nodes_t*) l4)->f_by_id, l3);
    if (!(l10.tag == 0u)) {
        t0 = l10.payload.obj;
        l11 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) t0)->f_decl)->f_name;
        vader_array_push_scalar((vader_array_t*) l5, vader_box_string(316u, l11));
    }
    l11 = 0u;
    l6 = INT64_C(0);
    l9 = ((vader_array_t*) l5)->length;
    while ((l6 < l9)) {
        if ((l6 > INT64_C(0))) {
            l11 = concat_2(l11, 207u);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l6];
        l12 = t1.payload.s;
        l11 = concat_2(l11, l12);
        l6 = (l6 + INT64_C(1));
    }
    { vader_string_t __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_diag_sink(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(91u, 0u, 13u, 951u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_display_enum(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null();
    int64_t l6;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l1, &l4, &l8 };
    void** gc_raw_roots[8] = { &l0, &l2, &l3, &l5, &l9, &l10, &l11, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_comptime_ComptimeContext_t*) l2)->f_project;
    if (l4.tag == 0u) {
        t0 = vader_comptime_vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj), 1777u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l4.payload.obj;
    l5 = vader_typecheck_sites_of(((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l2)->f_typed)->f_call_sites, (uint8_t) 7);
    l6 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l1.payload.obj);
    l4 = std_collections_MutableMap_std_core_Index_at__i64__Any(l5, l6);
    if (!(l4.tag == 1251u)) {
        t0 = vader_comptime_vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj), 1782u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_typecheck_TypedProject_t*) ((vader_struct_vader_comptime_ProjectConstants_t*) l3)->f_typed)->f_modules;
    l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) ((vader_struct_vader_comptime_EnumValue_t*) l0)->f_enum_type)->f_symbol)->f_module;
    l8 = std_collections_MutableMap_std_core_Index_at__string__Any(l5, l7);
    if (l8.tag == 0u) {
        t0 = vader_comptime_vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj), 1778u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l8.payload.obj;
    l5 = l2;
    l9 = ((vader_struct_vader_comptime_ComptimeContext_t*) l5)->f_bindings;
    l6 = ((vader_struct_vader_comptime_ComptimeContext_t*) l5)->f_depth;
    l8 = ((vader_struct_vader_comptime_ComptimeContext_t*) l5)->f_project;
    vader_struct_vader_comptime_ComptimeContext_t* _a0_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a0_obj, 927u);
    _a0_obj->f_typed = l3;
    _a0_obj->f_bindings = l9;
    _a0_obj->f_depth = l6;
    _a0_obj->f_project = l8;
    l3 = (void*) _a0_obj;
    vader_array_t* _a1_arr = vader_array_new(22u, 0u, 7u, 319u);
    l5 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(28u, 0u, 0u, 327u);
    l9 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 319u);
    l10 = (void*) _a3_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a4_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a4_obj, 419u);
    _a4_obj->f_ekeys = l5;
    _a4_obj->f_evals = l9;
    _a4_obj->f_index = l10;
    _a4_obj->f_mask = INT64_C(0);
    _a4_obj->f_grow_at = INT64_C(0);
    _a4_obj->f_size = INT64_C(0);
    _a4_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a4_obj;
    t0 = l4.payload.obj;
    l9 = ((vader_struct_vader_typecheck_DirectFn_t*) t0)->f_decl;
    vader_array_t* _a5_arr = vader_array_new(246u, 1u, 13u, 1699u);
    ((void**) _a5_arr->buf->slots)[_a5_arr->offset + 0u] = l0;
    l10 = (void*) _a5_arr;
    l11 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj);
    l3 = vader_comptime_evaluate_with_arguments(l9, l10, l5, l3, l11);
    l4 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
    if (l4.tag == 0u) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l4.tag == 944u)) {
        t0 = vader_comptime_vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l1.payload.obj), 1775u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_comptime_display_key_before(void* l0, void* l1) {
    vader_string_t l2, l3;
    bool t0;
    l2 = ((vader_struct_vader_comptime_GenericInstance_t*) l0)->f_display_key;
    l3 = ((vader_struct_vader_comptime_GenericInstance_t*) l1)->f_display_key;
    t0 = std_string_compare_ascending(l2, l3);
    return t0;
}

static vader_string_t vader_comptime_display_value(vader_box_t l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t l3 = 0;
    void* l4 = NULL;
    int64_t l5;
    bool l6;
    void* t0 = NULL;
    double t1;
    uint32_t t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l4, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l1, &l2, &l3, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 937u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_int_digits(t0);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_type_name;
        l1 = concat_3(l1, 920u, l2);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 934u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
        l2 = std_core_f64_Display_to_string(t1);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_type_name;
        l1 = concat_3(l2, 920u, l3);
    } else if (l0.tag == 925u) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(5));
        l5 = INT64_C(0);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
        l5 = std_core_write_bool(l4, l5, l6);
        l1 = std_core_finish_buffer(l4, l5);
    } else if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_comptime_CharValue_t*) t0)->f_value;
        t3 = std_numbers_to_hex((uint64_t) (int64_t) ((int64_t) (uint32_t) t2));
        l2 = std_string_pad_start(t3, INT64_C(4), 48u);
        l1 = concat_3(263u, l2, 246u);
    } else if (l0.tag == 944u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
        l1 = concat_3(213u, l2, 213u);
    } else if (l0.tag == 942u) {
        l1 = 2291u;
    } else if (l0.tag == 948u) {
        l1 = 2865u;
    } else if (l0.tag == 923u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_render_array(t0);
    } else if (l0.tag == 945u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_render_struct(t0);
    } else if (l0.tag == 946u) {
        t0 = l0.payload.obj;
        l1 = vader_types_display_type(((vader_struct_vader_comptime_TypeValue_t*) t0)->f_value);
    } else {
        if (!(l0.tag == 929u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_EnumType_t*) ((vader_struct_vader_comptime_EnumValue_t*) t0)->f_enum_type)->f_symbol)->f_name;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_comptime_EnumValue_t*) t0)->f_variant;
        l1 = concat_3(l2, 348u, l3);
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
    t0 = vader_diagnostics_comptime_error((uint8_t) 3, l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_comptime_emit_cycle(int64_t l0, void* l1, int64_t l2, void* l3, void* l4, void* l5) {
    int64_t l6, l7;
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
    l7 = INT64_C(0);
    while ((l7 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l7];
        if (t0 == l0) {
            l6 = l7;
            break;
        }
        l7 = (l7 + INT64_C(1));
    }
    l8 = vader_comptime_cycle_names(l6, l2, l1, l0, l3);
    l9 = std_collections_MutableMap_std_core_Index_at__i64__Any(((vader_struct_vader_comptime_Nodes_t*) l3)->f_by_id, l0);
    if (!(l9.tag == 0u)) {
        t1 = l9.payload.obj;
        l10 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) t1)->f_decl)->f_span;
        l10 = vader_diagnostics_comptime_error((uint8_t) 6, l10, l8);
        vader_array_push_ref((vader_array_t*) l5, l10);
    }
    while ((l6 < l2)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
        std_collections_MutableMap_std_core_IndexSet_set_at__i64__bool(l4, l7, true);
        l6 = (l6 + INT64_C(1));
    }
    std_collections_MutableMap_std_core_IndexSet_set_at__i64__bool(l4, l0, true);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_comptime_evaluate_aggregate(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l3 };
    void** gc_raw_roots[4] = { &l1, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_project;
    if (l3.tag == 0u) {
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l0.payload.obj);
        l4 = vader_typecheck_expr_kind_name(l0);
        t0 = vader_comptime_vm_required(l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    if (l0.tag == 646u) {
        t0 = l0.payload.obj;
        t1 = vader_comptime_evaluate_struct_lit(t0, l2, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 594u) {
        t0 = l0.payload.obj;
        t1 = vader_comptime_evaluate_dot_variant(t0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 599u) {
        t0 = l0.payload.obj;
        t1 = vader_comptime_evaluate_field(t0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 623u)) {
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l0.payload.obj);
        l4 = vader_typecheck_expr_kind_name(l0);
        t0 = vader_comptime_vm_required(l2, l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t1 = vader_comptime_evaluate_match(t0, l1);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
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
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null(), l9 = vader_box_null(), l13 = vader_box_null();
    uint8_t l11;
    vader_string_t l14 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
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
    vader_obj_header_init(_a0_obj, 927u);
    _a0_obj->f_typed = l3;
    _a0_obj->f_bindings = l4;
    _a0_obj->f_depth = INT64_C(0);
    _a0_obj->f_project = vader_box_obj(0u, NULL);
    l3 = (void*) _a0_obj;
    l4 = l0;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        if (l7.tag == 573u) {
            t0 = l7.payload.obj;
            l8 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_condition, l3);
            l9 = ((vader_struct_vader_comptime_EvalResult_t*) l8)->f_diag;
            if (!(l9.tag == 0u)) {
                t0 = l9.payload.obj;
                t1 = ((vader_struct_vader_diagnostics_CodeInfo_t*) ((vader_struct_vader_diagnostics_Diagnostic_t*) t0)->f_code)->f_id;
                if (t1 != 547u) {
                    l10 = l9.payload.obj;
                    vader_array_push_ref((vader_array_t*) l2, l10);
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
                l15 = vader_diagnostics_comptime_error((uint8_t) 9, l12, l14);
                vader_array_push_ref((vader_array_t*) l2, l15);
            }
            l16 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l1)->f_asserts;
            t0 = l7.payload.obj;
            vader_struct_vader_comptime_AssertCheck_t* _a2_obj = (vader_struct_vader_comptime_AssertCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_AssertCheck_t));
            vader_obj_header_init(_a2_obj, 924u);
            _a2_obj->f_span = ((vader_struct_toolchain_ast_AssertDecl_t*) t0)->f_span;
            _a2_obj->f_verdict = l11;
            l17 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l16, l17);
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_comptime_evaluate_binary_expr(void* l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l7 = vader_box_null();
    int64_t l5;
    vader_string_t l6 = 0;
    bool l8, l9;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    void* t3 = NULL;
    vader_box_t* gc_roots[4] = { &l3, &l4, &l7, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &t2, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_left, l1);
    l3 = ((vader_struct_vader_comptime_EvalResult_t*) l2)->f_value;
    if (l3.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_right, l1);
    l4 = ((vader_struct_vader_comptime_EvalResult_t*) l2)->f_value;
    if (l4.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_id;
    l6 = vader_comptime_resolved_int_name(l1, l5);
    if (((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(5)) {
        l8 = true;
    } else {
        l8 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(6);
    }
    if (l8) {
        l7 = vader_comptime_mask_shift_amount(l4, l6);
    } else {
        l7 = l4;
    }
    if (((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(12)) {
        l8 = true;
    } else {
        l8 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(13);
    }
    if (l8) {
        t0 = vader_comptime_same_kind(l3, l7);
        l8 = !(t0);
        {
            if (!(l8)) {
                if (!(l3.tag == 942u)) {
                    goto end_70;
                }
            }
            t0 = vader_comptime_has_union_operand(l1, l0);
            if (t0) {
                l9 = ((vader_struct_toolchain_ast_BinaryExpr_t*) l0)->f_op == INT32_C(13);
                t1 = vader_comptime_bool_value(l8 == l9);
                t2 = vader_comptime_ok(t1);
                { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
            }
        } end_70: ;
    }
    t2 = vader_comptime_combine_binary(l0, l3, l7, l6);
    t3 = vader_comptime_normalize_int_result(t2, l6);
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
        t1 = (void*) &vader_data_37;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        t2 = vader_comptime_ok(vader_ref_box(t1));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = (void*) &vader_data_36;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    t2 = vader_comptime_ok(vader_ref_box(t1));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_call_expr(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    vader_box_t l4 = vader_box_null(), l12 = vader_box_null(), l14 = vader_box_null();
    int64_t l5, l9;
    vader_string_t l6 = 0;
    uint64_t l7;
    int32_t l8, l13;
    void* t0 = NULL;
    void* t5 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    bool t4;
    vader_box_t* gc_roots[4] = { &l4, &l12, &l14, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l10, &l11, &t0, &t5 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_callee.tag == 606u)) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 569u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_callee;
    l2 = t1.payload.obj;
    if (((vader_obj_header_t*) l2)->type_index == 606u) {
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
                if (l4.tag == 937u) {
                    t0 = l4.payload.obj;
                    l5 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
                    l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_name;
                    l5 = vader_comptime_wrap_to_width(l5, l6);
                    l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_name;
                    vader_struct_vader_comptime_IntValue_t* _a1_obj = (vader_struct_vader_comptime_IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_IntValue_t));
                    vader_obj_header_init(_a1_obj, 937u);
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
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 567u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_fn_decls;
    t0 = l4.payload.obj;
    l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_id;
    l4 = std_collections_MutableMap_std_core_Index_at__i32__Any(l3, l8);
    if (l4.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 568u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l4.payload.obj;
    t4 = toolchain_ast_decorators_have(((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_decorators, 2427u);
    if (t4) {
        l3 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
        l6 = ((vader_struct_toolchain_ast_IdentExpr_t*) l2)->f_name;
        l6 = concat_3(981u, l6, 981u);
        t0 = vader_diagnostics_comptime_error((uint8_t) 12, l3, l6);
        t5 = vader_comptime_fail(t0);
        { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l4.payload.obj;
    l5 = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) t0)->f_params)->length;
    l9 = ((vader_array_t*) ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args)->length;
    if (l5 != l9) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span, 563u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 319u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(28u, 0u, 0u, 327u);
    l3 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 319u);
    l10 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a5_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a5_obj, 419u);
    _a5_obj->f_ekeys = l2;
    _a5_obj->f_evals = l3;
    _a5_obj->f_index = l10;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a5_obj;
    l3 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_bindings;
    l10 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ArrayValue___vader_comptime_BoolValue___vader_comptime_CharValue___vader_comptime_EnumValue___vader_comptime_FloatValue___vader_comptime_IntValue___vader_comptime_NullValue___vader_comptime_StringValue___vader_comptime_StructValue___vader_comptime_TypeValue___vader_comptime_VoidValue_t*) l3)->f_ekeys;
    l11 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ArrayValue___vader_comptime_BoolValue___vader_comptime_CharValue___vader_comptime_EnumValue___vader_comptime_FloatValue___vader_comptime_IntValue___vader_comptime_NullValue___vader_comptime_StringValue___vader_comptime_StructValue___vader_comptime_TypeValue___vader_comptime_VoidValue_t*) l3)->f_evals;
    l5 = INT64_C(0);
    l9 = ((vader_struct_std_collections_MutableMap__i32__vader_comptime_ArrayValue___vader_comptime_BoolValue___vader_comptime_CharValue___vader_comptime_EnumValue___vader_comptime_FloatValue___vader_comptime_IntValue___vader_comptime_NullValue___vader_comptime_StringValue___vader_comptime_StructValue___vader_comptime_TypeValue___vader_comptime_VoidValue_t*) l3)->f_size;
    while ((l5 < l9)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        l8 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l5];
        vader_array_t* _a7_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        l12 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
        l13 = l8;
        l14 = l12;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l2, l13, l14);
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a8_arr = vader_array_new(246u, 0u, 13u, 1699u);
    l3 = (void*) _a8_arr;
    l10 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_args;
    l5 = ((vader_array_t*) l10)->length;
    l9 = INT64_C(0);
    while ((l9 < l5)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
        t0 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l9);
        l11 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_CallArg_t*) t0)->f_value, l1);
        l14 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_value;
        if (l14.tag == 0u) {
            { void* __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l12 = l14;
        vader_array_push_ref((vader_array_t*) l3, l12.payload.obj);
        l9 = (l9 + INT64_C(1));
    }
    l10 = l4.payload.obj;
    l11 = ((vader_struct_toolchain_ast_CallExpr_t*) l0)->f_span;
    t0 = vader_comptime_evaluate_with_arguments(l10, l3, l2, l1, l11);
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
    vader_obj_header_init(_a0_obj, 926u);
    _a0_obj->f_value = t0;
    t1 = (void*) _a0_obj;
    t2 = vader_comptime_ok(vader_ref_box(t1));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_dot_variant(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4;
    vader_string_t l5 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_expr_types;
    l4 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) l0)->f_id;
    l2 = std_collections_MutableMap_std_core_Index_at__i64__Any(l3, l4);
    if (l2.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_DotVariantExpr_t*) l0)->f_span, 1780u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 1307u)) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_DotVariantExpr_t*) l0)->f_span, 2857u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l2.payload.obj;
    l5 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) l0)->f_variant;
    l6 = ((vader_struct_toolchain_ast_DotVariantExpr_t*) l0)->f_span;
    t0 = vader_comptime_variant_value(l3, l5, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_expr(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4;
    vader_string_t l5 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &t2 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    if ((t0 >= INT64_C(2000))) {
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l0.payload.obj);
        l3 = (void*) vader_buffer_new((size_t) INT64_C(93));
        l4 = INT64_C(0);
        l4 = std_core_write_string_at(l3, l4, 1375u);
        l4 = std_core_write_int(l3, l4, INT64_C(2000));
        l4 = std_core_write_string_at(l3, l4, 140u);
        l5 = std_core_finish_buffer(l3, l4);
        t1 = vader_comptime_vm_required(l2, l5);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_into_coercions;
    l4 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, l0.payload.obj);
    t2 = std_collections_MutableMap_std_core_Index_at__i64__Any(l2, l4);
    if (!(t2.tag == 0u)) {
        t1 = vader_comptime_vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l0.payload.obj), 1424u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    l4 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth = l4;
    if (l0.tag == 616u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_int_lit(t1, l1);
    } else if (l0.tag == 600u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_float_lit(t1);
    } else if (l0.tag == 578u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_bool_lit(t1);
    } else if (l0.tag == 583u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_char_lit(t1);
    } else if (l0.tag == 628u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_null_lit(t1);
    } else if (l0.tag == 641u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_string_lit(t1, l1);
    } else if (l0.tag == 606u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_ident(t1, l1);
    } else if (l0.tag == 576u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_binary_expr(t1, l1);
    } else if (l0.tag == 655u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_unary_expr(t1, l1);
    } else if (l0.tag == 617u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_intrinsic_call(t1, l1);
    } else if (l0.tag == 581u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_call_expr(t1, l1);
    } else if (l0.tag == 639u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_seq_lit(t1, l1);
    } else if (l0.tag == 646u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_aggregate(vader_ref_box(t1), l1);
    } else if (l0.tag == 594u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_aggregate(vader_ref_box(t1), l1);
    } else if (l0.tag == 599u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_aggregate(vader_ref_box(t1), l1);
    } else if (l0.tag == 623u) {
        t1 = l0.payload.obj;
        l2 = vader_comptime_evaluate_aggregate(vader_ref_box(t1), l1);
    } else {
        l3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_span, l0.payload.obj);
        l5 = vader_typecheck_expr_kind_name(l0);
        l2 = vader_comptime_vm_required(l3, l5);
    }
    t0 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth;
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_depth = l4;
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_comptime_evaluate_extern_libraries(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l15 = NULL;
    void* l17 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    int64_t l8, l9, l12, l13, l14, l16;
    int32_t l18, l20;
    vader_box_t l19 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    bool t3;
    vader_box_t* gc_roots[2] = { &l19, &t1 };
    void** gc_raw_roots[15] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l10, &l11, &l15, &l17, &l21, &l22, &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 15u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 319u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 327u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 319u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 419u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 319u);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(19u, 0u, 12u, 314u);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 319u);
    l6 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a7_obj, 421u);
    _a7_obj->f_ekeys = l4;
    _a7_obj->f_evals = l5;
    _a7_obj->f_index = l6;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a7_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a8_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a8_obj, 559u);
    _a8_obj->f_inner = t0;
    l4 = (void*) _a8_obj;
    vader_struct_vader_comptime_ProjectConstants_t* _a9_obj = (vader_struct_vader_comptime_ProjectConstants_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ProjectConstants_t));
    vader_obj_header_init(_a9_obj, 943u);
    _a9_obj->f_typed = l0;
    _a9_obj->f_values = l3;
    _a9_obj->f_pending = l4;
    l3 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(22u, 0u, 7u, 319u);
    l4 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(19u, 0u, 12u, 314u);
    l5 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(22u, 0u, 7u, 319u);
    l6 = (void*) _a12_arr;
    vader_struct_std_collections_MutableMap__i32__bool_t* _a13_obj = (vader_struct_std_collections_MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__bool_t));
    vader_obj_header_init(_a13_obj, 421u);
    _a13_obj->f_ekeys = l4;
    _a13_obj->f_evals = l5;
    _a13_obj->f_index = l6;
    _a13_obj->f_mask = INT64_C(0);
    _a13_obj->f_grow_at = INT64_C(0);
    _a13_obj->f_size = INT64_C(0);
    _a13_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a13_obj;
    vader_struct_std_collections_MutableSet__i32_t* _a14_obj = (vader_struct_std_collections_MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableSet__i32_t));
    vader_obj_header_init(_a14_obj, 559u);
    _a14_obj->f_inner = t0;
    l4 = (void*) _a14_obj;
    l5 = ((vader_struct_vader_typecheck_TypedProject_t*) l0)->f_modules;
    l6 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l5)->f_ekeys;
    l7 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l5)->f_evals;
    l8 = INT64_C(0);
    l9 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l5)->f_size;
    while ((l8 < l9)) {
        vader_array_t* _a15_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l8)
        t1 = vader_array_box_slots(_a15_slotarr->buf)[_a15_slotarr->offset + (size_t) l8];
        t2 = t1.payload.s;
        vader_array_t* _a16_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l8)
        t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l8);
        l5 = ((vader_struct_vader_typecheck_TypedProgram_t*) t0)->f_extern_libraries;
        l10 = ((vader_struct_std_collections_MutableMap__i64__vader_resolver_symbol_Symbol_t*) l5)->f_ekeys;
        l11 = ((vader_struct_std_collections_MutableMap__i64__vader_resolver_symbol_Symbol_t*) l5)->f_evals;
        l12 = INT64_C(0);
        l13 = ((vader_struct_std_collections_MutableMap__i64__vader_resolver_symbol_Symbol_t*) l5)->f_size;
        while ((l12 < l13)) {
            vader_array_t* _a17_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l12)
            l14 = ((int64_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l12];
            vader_array_t* _a18_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l12)
            l15 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l12);
            l16 = l14;
            l17 = l15;
            l18 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l17)->f_id;
            t3 = std_collections_MutableSet_std_core_Contains_contains__i32(l4, l18);
            if (!(t3)) {
                l19 = vader_comptime_evaluate_library(l17, l3, l2);
                if (l19.tag == 0u) {
                    l20 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l17)->f_id;
                    std_collections_add__i32(l4, l20);
                } else {
                    l21 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l1)->f_libraries;
                    l22 = l19.payload.obj;
                    std_collections_MutableMap_std_core_IndexSet_set_at__i64__Any(l21, l16, vader_ref_box(l22));
                }
            }
            l12 = (l12 + INT64_C(1));
        }
        l8 = (l8 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_comptime_evaluate_field(void* l0, void* l1) {
    void* l2 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_string_t l4 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_FieldExpr_t*) l0)->f_target, l1);
    l3 = ((vader_struct_vader_comptime_EvalResult_t*) l2)->f_value;
    if (l3.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3.tag == 946u) {
        t0 = l3.payload.obj;
        if (!(((vader_struct_vader_comptime_TypeValue_t*) t0)->f_value.tag == 1307u)) {
            t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_FieldExpr_t*) l0)->f_span, 1881u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        t1 = ((vader_struct_vader_comptime_TypeValue_t*) t0)->f_value;
        l2 = t1.payload.obj;
        l4 = ((vader_struct_toolchain_ast_FieldExpr_t*) l0)->f_field;
        l5 = ((vader_struct_toolchain_ast_FieldExpr_t*) l0)->f_span;
        t0 = vader_comptime_variant_value(l2, l4, l5);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l3.tag == 945u)) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_FieldExpr_t*) l0)->f_span, 1882u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l3.payload.obj;
    l2 = ((vader_struct_vader_comptime_StructValue_t*) t0)->f_fields;
    l4 = ((vader_struct_toolchain_ast_FieldExpr_t*) l0)->f_field;
    l3 = std_collections_MutableMap_std_core_Index_at__string__Any(l2, l4);
    if (l3.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_FieldExpr_t*) l0)->f_span, 2686u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_ok(l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &t0, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_body;
    if (l4.tag == 0u) {
        t0 = vader_comptime_vm_required(l2, 566u);
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
            if (l5.tag == 638u) {
                t0 = l5.payload.obj;
                if (!(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value.tag == 0u)) {
                    t0 = l5.payload.obj;
                    t2 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ReturnStmt_t*) t0)->f_value, l1);
                    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            l6 = 565u;
            t0 = vader_comptime_vm_required(l2, l6);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = 565u;
        t0 = vader_comptime_vm_required(l2, l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_BlockExpr_t*) l3)->f_stmts)->length;
    if (!(t1 == INT64_C(0))) {
        t0 = vader_comptime_vm_required(l2, 564u);
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
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l4, &l6, &t1 };
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
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span, 630u);
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
    l2 = l4.payload.obj;
    l7 = ((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span;
    l6 = vader_comptime_evaluate_project_const(l2, l1, l7);
    if (!(l6.tag == 0u)) {
        t0 = l6.payload.obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_comptime_type_from_expr_safe(l0, l1);
    if (!(l6.tag == 0u)) {
        t1 = vader_comptime_type_val(l6);
        t0 = vader_comptime_ok(t1);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_toolchain_ast_IdentExpr_t*) l0)->f_span;
    l7 = (void*) &vader_data_46;
    t0 = l4.payload.obj;
    l8 = ((int64_t) (uint8_t) ((vader_struct_vader_resolver_symbol_Symbol_t*) t0)->f_kind);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
    l9 = ((vader_struct_vader_resolver_symbol_SymbolKindInfo_t*) t0)->f_label;
    l9 = concat_3(629u, l9, 281u);
    t0 = vader_comptime_vm_required(l2, l9);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_int_lit(void* l0, void* l1) {
    void* l2 = NULL;
    int64_t l3;
    vader_string_t l4 = 0;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = toolchain_ast_int_literal_value(l0);
    t1 = vader_comptime_int_val(t0);
    l2 = vader_comptime_ok(t1);
    l3 = ((vader_struct_toolchain_ast_IntLitExpr_t*) l0)->f_id;
    l4 = vader_comptime_resolved_int_name(l1, l3);
    t2 = vader_comptime_normalize_int_result(l2, l4);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_intrinsic_call(void* l0, void* l1) {
    bool l2;
    void* l3 = NULL;
    vader_string_t l4 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l4, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2429u) {
        t1 = vader_comptime_intrinsic_size_of(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1439u) {
        t1 = vader_comptime_intrinsic_align_of(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2631u) {
        t1 = vader_comptime_intrinsic_type_name(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2629u) {
        t1 = vader_comptime_intrinsic_type_kind(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1884u) {
        t1 = vader_comptime_intrinsic_field_count(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2859u) {
        t1 = vader_comptime_intrinsic_variant_count(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1886u) {
        t1 = vader_comptime_intrinsic_field_index(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2407u) {
        t1 = vader_comptime_intrinsic_satisfies(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2223u) {
        l2 = true;
    } else {
        t0 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
        l2 = t0 == 2191u;
    }
    if (!(l2)) {
        l3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_span;
        l4 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
        l4 = concat_2(478u, l4);
        t1 = vader_comptime_vm_required(l3, l4);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_comptime_intrinsic_integer_bound(l0, l1);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_evaluate_library(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null();
    int32_t l7;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l5, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l8, &l9, &l10 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_typecheck_TypedProject_t*) ((vader_struct_vader_comptime_ProjectConstants_t*) l1)->f_typed)->f_modules;
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module;
    l5 = std_collections_MutableMap_std_core_Index_at__string__Any(l3, l4);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l5.payload.obj;
    l6 = ((vader_struct_vader_typecheck_TypedProgram_t*) l3)->f_const_decls;
    l7 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l5 = std_collections_MutableMap_std_core_Index_at__i32__Any(l6, l7);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l6 = l5.payload.obj;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 319u);
    l8 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 327u);
    l9 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 319u);
    l10 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 419u);
    _a3_obj->f_ekeys = l8;
    _a3_obj->f_evals = l9;
    _a3_obj->f_index = l10;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l8 = (void*) _a3_obj;
    vader_struct_vader_comptime_ComptimeContext_t* _a4_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a4_obj, 927u);
    _a4_obj->f_typed = l3;
    _a4_obj->f_bindings = l8;
    _a4_obj->f_depth = INT64_C(0);
    _a4_obj->f_project = vader_ref_box(l1);
    l3 = (void*) _a4_obj;
    l8 = ((vader_struct_toolchain_ast_ConstDecl_t*) l6)->f_span;
    l5 = vader_comptime_evaluate_project_const(l0, l3, l8);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l5.payload.obj;
    l5 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_value;
    if (l5.tag == 0u) {
        if (((vader_struct_vader_comptime_EvalResult_t*) l3)->f_diag.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t0 = ((vader_struct_vader_comptime_EvalResult_t*) l3)->f_diag;
        l3 = t0.payload.obj;
        vader_array_push_ref((vader_array_t*) l2, l3);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module;
    l5 = vader_comptime_native_library(l5, l4);
    if (l5.tag == 0u) {
        l4 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_name;
        l4 = concat_3(981u, l4, 1059u);
        l3 = ((vader_struct_toolchain_ast_ConstDecl_t*) l6)->f_span;
        l3 = vader_diagnostics_comptime_error((uint8_t) 0, l3, l4);
        vader_array_push_ref((vader_array_t*) l2, l3);
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_match(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    int64_t l4, l5;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l3, &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_toolchain_ast_MatchExpr_t*) l0)->f_binding.tag == 0u)) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_MatchExpr_t*) l0)->f_span, 2186u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_MatchExpr_t*) l0)->f_scrutinee, l1);
    l3 = ((vader_struct_vader_comptime_EvalResult_t*) l2)->f_value;
    if (l3.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_toolchain_ast_MatchExpr_t*) l0)->f_arms;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (!(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_guard.tag == 0u)) {
            t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_span, 2185u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = vader_comptime_pattern_holds(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_pattern, l3);
        if (l7.tag == 0u) {
            t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_span, 2188u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = l7.payload.b;
        if (t1) {
            t0 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_MatchArm_t*) l6)->f_body, l1);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = (l5 + INT64_C(1));
    }
    t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_MatchExpr_t*) l0)->f_span, 2189u);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    int64_t l8, l9;
    vader_box_t l14 = vader_box_null(), l16 = vader_box_null(), l20 = vader_box_null(), l23 = vader_box_null(), l26 = vader_box_null();
    int32_t l25, l28, l30;
    bool t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[6] = { &l14, &l16, &l20, &l23, &l26, &t1 };
    void** gc_raw_roots[21] = {
        &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l10, &l11, &l12, &l13, &l15, &l17, &l18, &l19, &l21,
        &l22, &l24, &l27, &l29, &t2,
    };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 21u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = vader_comptime_sort_comptime_decls(l0, l1);
    l7 = ((vader_struct_vader_comptime_ComptimeOrder_t*) l6)->f_cycle_diags;
    l8 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l10 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        vader_array_push_ref((vader_array_t*) l5, l10);
        l9 = (l9 + INT64_C(1));
    }
    l7 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
    vader_struct_vader_comptime_ComptimeContext_t* _a1_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a1_obj, 927u);
    _a1_obj->f_typed = l1;
    _a1_obj->f_bindings = l7;
    _a1_obj->f_depth = INT64_C(0);
    _a1_obj->f_project = vader_box_obj(0u, NULL);
    l7 = (void*) _a1_obj;
    l6 = ((vader_struct_vader_comptime_ComptimeOrder_t*) l6)->f_order;
    l8 = ((vader_array_t*) l6)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
        l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
        l11 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ConstDecl_t*) l10)->f_value, l7);
        t0 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_vm_required;
        if (t0) {
            l12 = ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved;
            l13 = ((vader_struct_toolchain_ast_ConstDecl_t*) l10)->f_name_span;
            l14 = vader_resolver_symbol_declared_at(l12, l13);
            if (!(l14.tag == 0u)) {
                l15 = l14.payload.obj;
                l16 = vader_comptime_build_vm_required(l10, l15, l1, l4);
                if (l16.tag == 947u) {
                    l17 = ((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_vm_required;
                    l18 = l16.payload.obj;
                    vader_array_push_ref((vader_array_t*) l17, l18);
                    l9 = (l9 + INT64_C(1));
                    continue;
                }
            }
            if (!(((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag.tag == 0u)) {
                t1 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag;
                l19 = t1.payload.obj;
                vader_array_push_ref((vader_array_t*) l5, l19);
            }
            l9 = (l9 + INT64_C(1));
            continue;
        }
        l20 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_value;
        if (!(l20.tag == 0u)) {
            l21 = ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved;
            l22 = ((vader_struct_toolchain_ast_ConstDecl_t*) l10)->f_name_span;
            l23 = vader_resolver_symbol_declared_at(l21, l22);
            if (!(l23.tag == 0u)) {
                l24 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
                t2 = l23.payload.obj;
                l25 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t2)->f_id;
                l26 = l20;
                std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l24, l25, l26);
                l27 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_routes;
                t2 = l23.payload.obj;
                l28 = ((vader_struct_vader_resolver_symbol_Symbol_t*) t2)->f_id;
                std_collections_MutableMap_std_core_IndexSet_set_at__i32__vader_comptime_ComptimeRoute(l27, l28, (uint8_t) 0);
            }
        }
        if (!(((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag.tag == 0u)) {
            t1 = ((vader_struct_vader_comptime_EvalResult_t*) l11)->f_diag;
            l29 = t1.payload.obj;
            vader_array_push_ref((vader_array_t*) l5, l29);
        }
        l9 = (l9 + INT64_C(1));
    }
    l6 = l0;
    l8 = ((vader_array_t*) l6)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l9)
        l14 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l9);
        if (l14.tag == 584u) {
            t2 = l14.payload.obj;
            t0 = vader_comptime_has_comptime_decorator(t2);
            if (t0) {
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l11 = ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved;
            t2 = l14.payload.obj;
            l12 = ((vader_struct_toolchain_ast_ConstDecl_t*) t2)->f_name_span;
            l16 = vader_resolver_symbol_declared_at(l11, l12);
            if (l16.tag == 0u) {
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l10 = l16.payload.obj;
            l13 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
            l25 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_id;
            t1 = std_collections_MutableMap_std_core_Index_at__i32__Any(l13, l25);
            if (t1.tag == 0u) {
                t2 = l14.payload.obj;
                l15 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ConstDecl_t*) t2)->f_value, l7);
                if (!(((vader_struct_vader_comptime_EvalResult_t*) l15)->f_value.tag == 0u)) {
                    l17 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_comptime_decls;
                    l28 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_id;
                    l20 = ((vader_struct_vader_comptime_EvalResult_t*) l15)->f_value;
                    std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l17, l28, l20);
                    l18 = ((vader_struct_vader_comptime_EvaluatedProgram_t*) l2)->f_routes;
                    l30 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l10)->f_id;
                    std_collections_MutableMap_std_core_IndexSet_set_at__i32__vader_comptime_ComptimeRoute(l18, l30, (uint8_t) 2);
                }
            } else {
                l9 = (l9 + INT64_C(1));
                continue;
            }
        }
        l9 = (l9 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_comptime_evaluate_null_lit(void* l0) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_35;
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
    int64_t l7, l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_box_t l13 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
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
    l7 = INT64_C(0);
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
        l7 = (l7 + INT64_C(1));
    }
    vader_comptime_evaluate_extern_libraries(l1, l3, l2);
    l9 = ((vader_struct_vader_resolver_LoadedProject_t*) l0)->f_entry;
    l4 = vader_comptime_harvest_instances(l1, l9);
    ((vader_struct_vader_comptime_EvaluatedProject_t*) l3)->f_instances = l4;
    VADER_WRITE_BARRIER((vader_struct_vader_comptime_EvaluatedProject_t*) l3);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_evaluate_project_const(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    vader_box_t l4 = vader_box_null();
    int32_t l6;
    vader_string_t l8 = 0;
    int64_t l13;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l3, &l5, &l7, &l9, &l10, &l11, &l12, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_project;
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l4.payload.obj;
    l5 = ((vader_struct_vader_comptime_ProjectConstants_t*) l3)->f_values;
    l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l4 = std_collections_MutableMap_std_core_Index_at__i32__Any(l5, l6);
    if (!(l4.tag == 0u)) {
        t0 = vader_comptime_ok(l4);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = ((vader_struct_vader_typecheck_TypedProject_t*) ((vader_struct_vader_comptime_ProjectConstants_t*) l3)->f_typed)->f_modules;
    l8 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_module;
    l4 = std_collections_MutableMap_std_core_Index_at__string__Any(l7, l8);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = l4.payload.obj;
    l9 = ((vader_struct_vader_typecheck_TypedProgram_t*) l5)->f_const_decls;
    l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l4 = std_collections_MutableMap_std_core_Index_at__i32__Any(l9, l6);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l7 = l4.payload.obj;
    l9 = ((vader_struct_vader_comptime_ProjectConstants_t*) l3)->f_pending;
    l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    t1 = std_collections_add__i32(l9, l6);
    if (!(t1)) {
        t0 = vader_comptime_vm_required(l2, 1698u);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = l1;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 319u);
    l10 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 327u);
    l11 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 319u);
    l12 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 419u);
    _a3_obj->f_ekeys = l10;
    _a3_obj->f_evals = l11;
    _a3_obj->f_index = l12;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l10 = (void*) _a3_obj;
    l13 = ((vader_struct_vader_comptime_ComptimeContext_t*) l9)->f_depth;
    l4 = ((vader_struct_vader_comptime_ComptimeContext_t*) l9)->f_project;
    vader_struct_vader_comptime_ComptimeContext_t* _a4_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a4_obj, 927u);
    _a4_obj->f_typed = l5;
    _a4_obj->f_bindings = l10;
    _a4_obj->f_depth = l13;
    _a4_obj->f_project = l4;
    l5 = (void*) _a4_obj;
    l5 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_ConstDecl_t*) l7)->f_value, l5);
    l7 = ((vader_struct_vader_comptime_ProjectConstants_t*) l3)->f_pending;
    l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    std_collections_remove__i32(l7, l6);
    if (((vader_struct_vader_comptime_EvalResult_t*) l5)->f_value.tag == 0u) {
        { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_comptime_ProjectConstants_t*) l3)->f_values;
    l6 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l0)->f_id;
    l4 = ((vader_struct_vader_comptime_EvalResult_t*) l5)->f_value;
    std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l3, l6, l4);
    { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_seq_lit(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    int64_t l4, l5, l10;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    vader_string_t l11 = 0;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    void* t2 = NULL;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[3] = { &l7, &l8, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l9, &t1, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l11, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(246u, 0u, 13u, 1699u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l0)->f_elements;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l6 = vader_comptime_evaluate_expr(t0, l1);
        l8 = ((vader_struct_vader_comptime_EvalResult_t*) l6)->f_value;
        if (l8.tag == 0u) {
            { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = l8;
        vader_array_push_ref((vader_array_t*) l2, l7.payload.obj);
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_expr_types;
    l4 = ((vader_struct_toolchain_ast_SeqLitExpr_t*) l0)->f_id;
    l8 = std_collections_MutableMap_std_core_Index_at__i64__Any(l3, l4);
    if (l8.tag == 0u) {
        t1 = (void*) &vader_data_22;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        l7 = vader_ref_box(t1);
    } else {
        l7 = l8;
    }
    t0 = vader_types_tuple_backing(l7);
    if (t0.tag == 0u) {
        l11 = 0u;
        if (l7.tag == 1305u) {
            t1 = l7.payload.obj;
            l11 = vader_types_display_type(((vader_struct_vader_types_ArrayType_t*) t1)->f_element);
            vader_struct_vader_comptime_ArrayValue_t* _a3_obj = (vader_struct_vader_comptime_ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ArrayValue_t));
            vader_obj_header_init(_a3_obj, 923u);
            _a3_obj->f_elements = l2;
            _a3_obj->f_element_type_name = l11;
            t1 = (void*) _a3_obj;
            t2 = vader_comptime_ok(vader_ref_box(t1));
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_comptime_ArrayValue_t* _a4_obj = (vader_struct_vader_comptime_ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ArrayValue_t));
        vader_obj_header_init(_a4_obj, 923u);
        _a4_obj->f_elements = l2;
        _a4_obj->f_element_type_name = l11;
        t1 = (void*) _a4_obj;
        t2 = vader_comptime_ok(vader_ref_box(t1));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a5_arr = vader_array_new(21u, 0u, 0u, 316u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(28u, 0u, 0u, 327u);
    l6 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 319u);
    l9 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a8_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a8_obj, 489u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l6;
    _a8_obj->f_index = l9;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a8_obj;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l2)->length;
    while ((l4 < l5)) {
        l6 = (void*) vader_buffer_new((size_t) INT64_C(21));
        l10 = INT64_C(0);
        l10 = std_core_write_string_at(l6, l10, 920u);
        l10 = std_core_write_int(l6, l10, l4);
        l11 = std_core_finish_buffer(l6, l10);
        vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l8 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l4);
        std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(l3, l11, l8);
        l4 = (l4 + INT64_C(1));
    }
    t3 = vader_types_display_type(l7);
    vader_struct_vader_comptime_StructValue_t* _a10_obj = (vader_struct_vader_comptime_StructValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_StructValue_t));
    vader_obj_header_init(_a10_obj, 945u);
    _a10_obj->f_type_name = t3;
    _a10_obj->f_fields = l3;
    t1 = (void*) _a10_obj;
    t2 = vader_comptime_ok(vader_ref_box(t1));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_string_lit(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null(), l14 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t l15 = 0;
    vader_string_t l16 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l6, &l9, &l10, &l12, &l14, &t2 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l8, &l11, &l13, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l7, &l15, &l16, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 316u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 571u);
    _a1_obj->f_parts = t0;
    l2 = (void*) _a1_obj;
    l3 = ((vader_struct_toolchain_ast_StringLitExpr_t*) l0)->f_parts;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        if (l6.tag == 643u) {
            t0 = l6.payload.obj;
            l7 = ((vader_struct_toolchain_ast_StringLitText_t*) t0)->f_value;
            std_string_builder_append(l2, l7);
        } else {
            if (!(l6.tag == 642u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l6.payload.obj;
            l8 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr, l1);
            l10 = ((vader_struct_vader_comptime_EvalResult_t*) l8)->f_value;
            if (l10.tag == 0u) {
                { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l9 = l10;
            if (l9.tag == 929u) {
                l11 = l9.payload.obj;
                t0 = l6.payload.obj;
                l12 = ((vader_struct_toolchain_ast_StringLitInterp_t*) t0)->f_expr;
                l13 = vader_comptime_display_enum(l11, l12, l1);
                l14 = ((vader_struct_vader_comptime_EvalResult_t*) l13)->f_value;
                if (l14.tag == 0u) {
                    { void* __vret = l13; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l15 = vader_comptime_interp_value(l14);
                std_string_builder_append(l2, l15);
                l5 = (l5 + INT64_C(1));
                continue;
            }
            l16 = vader_comptime_interp_value(l9);
            std_string_builder_append(l2, l16);
        }
        l5 = (l5 + INT64_C(1));
    }
    t1 = std_string_builder_StringBuilder_std_core_Display_to_string(l2);
    t2 = vader_comptime_string_val(t1);
    t0 = vader_comptime_ok(t2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_struct_lit(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l12 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    int64_t l6, l7;
    vader_box_t l8 = vader_box_null(), l9 = vader_box_null(), l10 = vader_box_null(), l17 = vader_box_null();
    vader_string_t l11 = 0;
    vader_string_t l18 = 0;
    int32_t l13;
    void* t0 = NULL;
    void* t1 = NULL;
    bool t2;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[4] = { &l8, &l9, &l10, &l17 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l12, &l14, &l15, &l16, &t0, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l18, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 316u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 327u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 319u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 489u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    l4 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l0)->f_items;
    l6 = ((vader_array_t*) l4)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        l8 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
        if (l8.tag == 648u) {
            t0 = l8.payload.obj;
            t1 = vader_comptime_vm_required(((vader_struct_toolchain_ast_StructLitSpread_t*) t0)->f_span, 2529u);
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l8.payload.obj;
        l5 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_value, l2);
        l10 = ((vader_struct_vader_comptime_EvalResult_t*) l5)->f_value;
        if (l10.tag == 0u) {
            { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l9 = l10;
        t0 = l8.payload.obj;
        l11 = ((vader_struct_toolchain_ast_StructLitField_t*) t0)->f_name;
        std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(l3, l11, l9);
        l7 = (l7 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l2)->f_typed)->f_expr_types;
    l6 = ((vader_struct_toolchain_ast_StructLitExpr_t*) l0)->f_id;
    l9 = std_collections_MutableMap_std_core_Index_at__i64__Any(l4, l6);
    if (l9.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_StructLitExpr_t*) l0)->f_span, 2532u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l8 = l9;
    if (!(l8.tag == 1318u)) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_StructLitExpr_t*) l0)->f_span, 2528u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_vader_typecheck_TypedProject_t*) ((vader_struct_vader_comptime_ProjectConstants_t*) l1)->f_typed)->f_modules;
    t0 = l8.payload.obj;
    l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_module;
    l9 = std_collections_MutableMap_std_core_Index_at__string__Any(l5, l11);
    if (l9.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_StructLitExpr_t*) l0)->f_span, 2531u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l9.payload.obj;
    l12 = ((vader_struct_vader_typecheck_TypedProgram_t*) l4)->f_struct_decls;
    t0 = l8.payload.obj;
    l13 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
    l9 = std_collections_MutableMap_std_core_Index_at__i32__Any(l12, l13);
    if (l9.tag == 0u) {
        t0 = vader_comptime_vm_required(((vader_struct_toolchain_ast_StructLitExpr_t*) l0)->f_span, 2530u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l9.payload.obj;
    l12 = l2;
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 7u, 319u);
    l14 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(28u, 0u, 0u, 327u);
    l15 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(22u, 0u, 7u, 319u);
    l16 = (void*) _a7_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a8_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a8_obj, 419u);
    _a8_obj->f_ekeys = l14;
    _a8_obj->f_evals = l15;
    _a8_obj->f_index = l16;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    l14 = (void*) _a8_obj;
    l6 = ((vader_struct_vader_comptime_ComptimeContext_t*) l12)->f_depth;
    l9 = ((vader_struct_vader_comptime_ComptimeContext_t*) l12)->f_project;
    vader_struct_vader_comptime_ComptimeContext_t* _a9_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a9_obj, 927u);
    _a9_obj->f_typed = l4;
    _a9_obj->f_bindings = l14;
    _a9_obj->f_depth = l6;
    _a9_obj->f_project = l9;
    l4 = (void*) _a9_obj;
    l5 = ((vader_struct_toolchain_ast_StructDecl_t*) l5)->f_fields;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l7)
        l12 = vader_array_ref_load_obj(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_toolchain_ast_StructField_t*) l12)->f_default_v;
        l11 = ((vader_struct_toolchain_ast_StructField_t*) l12)->f_name;
        t2 = std_collections_MutableMap_std_core_Contains_contains__string__Any(l3, l11);
        if (!(t2)) {
            if (!(l9.tag == 0u)) {
                l14 = vader_comptime_evaluate_expr(l9, l4);
                l17 = ((vader_struct_vader_comptime_EvalResult_t*) l14)->f_value;
                if (l17.tag == 0u) {
                    { void* __vret = l14; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l10 = l17;
                l18 = ((vader_struct_toolchain_ast_StructField_t*) l12)->f_name;
                std_collections_MutableMap_std_core_IndexSet_set_at__string__Any(l3, l18, l10);
                l7 = (l7 + INT64_C(1));
                continue;
            }
        }
        l7 = (l7 + INT64_C(1));
    }
    t0 = l8.payload.obj;
    t3 = vader_types_display_type(vader_ref_box(t0));
    vader_struct_vader_comptime_StructValue_t* _a11_obj = (vader_struct_vader_comptime_StructValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_StructValue_t));
    vader_obj_header_init(_a11_obj, 945u);
    _a11_obj->f_type_name = t3;
    _a11_obj->f_fields = l3;
    t0 = (void*) _a11_obj;
    t1 = vader_comptime_ok(vader_ref_box(t0));
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_unary_expr(void* l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l4;
    vader_string_t l5 = 0;
    uint8_t l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_comptime_evaluate_expr(((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_operand, l1);
    l3 = ((vader_struct_vader_comptime_EvalResult_t*) l2)->f_value;
    if (l3.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_id;
    l5 = vader_comptime_resolved_int_name(l1, l4);
    l6 = ((vader_struct_toolchain_ast_UnaryExpr_t*) l0)->f_op;
    if (l6 == INT32_C(0)) {
        l2 = vader_comptime_unary_neg(l0, l3, l5);
        t0 = vader_comptime_normalize_int_result(l2, l5);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(1)) {
        l2 = vader_comptime_unary_not(l0, l3);
    } else {
        if (!(l6 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_comptime_unary_bit_not(l0, l3);
    }
    t0 = vader_comptime_normalize_int_result(l2, l5);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_evaluate_with_arguments(void* l0, void* l1, void* l2, void* l3, void* l4) {
    int64_t l5, l6;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    uint64_t l9;
    vader_box_t l10 = vader_box_null(), l12 = vader_box_null();
    int32_t l11;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l10, &l12 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l7, &l8, &l13, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) l1)->length;
    while ((l5 < l6)) {
        l8 = ((vader_struct_vader_resolver_ResolvedModule_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l3)->f_typed)->f_resolved)->f_idents;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_FnDecl_t*) l0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l9 = toolchain_span_Span_std_core_Hash_hash(((vader_struct_toolchain_ast_FnParam_t*) t0)->f_span);
        l10 = std_collections_MutableMap_std_core_Index_at__u64__Any(l8, l9);
        if (l10.tag == 0u) {
            t0 = vader_comptime_vm_required(l4, 570u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = l10.payload.obj;
        l11 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l7)->f_id;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l12 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__Any(l2, l11, l12);
        l5 = (l5 + INT64_C(1));
    }
    l8 = l3;
    l13 = ((vader_struct_vader_comptime_ComptimeContext_t*) l8)->f_typed;
    l5 = ((vader_struct_vader_comptime_ComptimeContext_t*) l8)->f_depth;
    l10 = ((vader_struct_vader_comptime_ComptimeContext_t*) l8)->f_project;
    vader_struct_vader_comptime_ComptimeContext_t* _a2_obj = (vader_struct_vader_comptime_ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeContext_t));
    vader_obj_header_init(_a2_obj, 927u);
    _a2_obj->f_typed = l13;
    _a2_obj->f_bindings = l2;
    _a2_obj->f_depth = l5;
    _a2_obj->f_project = l10;
    l7 = (void*) _a2_obj;
    t0 = vader_comptime_evaluate_fn_body(l0, l7, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_fail(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_EvalResult_t* _a0_obj = (vader_struct_vader_comptime_EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvalResult_t));
    vader_obj_header_init(_a0_obj, 930u);
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
    int64_t l4, l5, l8;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l6, &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 8u, 320u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 327u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 319u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i64__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__Any_t));
    vader_obj_header_init(_a3_obj, 461u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    l2 = l0;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        l6 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
        if (l6.tag == 584u) {
            t0 = l6.payload.obj;
            l7 = ((vader_struct_toolchain_ast_ConstDecl_t*) t0)->f_value;
            if (l7.tag == 617u) {
                t0 = l7.payload.obj;
                t1 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_name;
                if (t1 == 1892u) {
                    t0 = l7.payload.obj;
                    l8 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) t0)->f_id;
                    l3 = l6.payload.obj;
                    std_collections_MutableMap_std_core_IndexSet_set_at__i64__Any(l1, l8, vader_ref_box(l3));
                }
            }
        }
        l5 = (l5 + INT64_C(1));
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
    vader_obj_header_init(_a0_obj, 934u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = 1844u;
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
    vader_obj_header_init(_a0_obj, 934u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_comptime_folder_beside(vader_string_t l0, vader_string_t l1) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (!(l1 == 0u)) {
        t0 = vader_resolver_join_path(l0, l1);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

static void* vader_comptime_harvest_instances(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l32 = NULL;
    void* l33 = NULL;
    void* l34 = NULL;
    void* l38 = NULL;
    void* l39 = NULL;
    void* l40 = NULL;
    int64_t l6, l7, l11, l12, l17, l18, l23, l24, l29, l30, l35, l36, l41, l42;
    vader_box_t l13 = vader_box_null(), l19 = vader_box_null(), l25 = vader_box_null(), l31 = vader_box_null(), l37 = vader_box_null(), l43 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    int32_t t3;
    int64_t t4;
    vader_box_t* gc_roots[7] = { &l13, &l19, &l25, &l31, &l37, &l43, &t1 };
    void** gc_raw_roots[24] = {
        &l0, &l2, &l3, &l4, &l5, &l8, &l9, &l10, &l14, &l15, &l16, &l20, &l21, &l22, &l26, &l27,
        &l28, &l32, &l33, &l34, &l38, &l39, &l40, &t0,
    };
    vader_string_t* gc_atom_roots[2] = { &l1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 7u, 24u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 316u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 327u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 319u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 489u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_vader_comptime_InstanceRegistry_t* _a4_obj = (vader_struct_vader_comptime_InstanceRegistry_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_InstanceRegistry_t));
    vader_obj_header_init(_a4_obj, 936u);
    _a4_obj->f_by_key = t0;
    l2 = (void*) _a4_obj;
    l3 = ((vader_struct_vader_typecheck_TypedProject_t*) l0)->f_modules;
    l4 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l3)->f_ekeys;
    l5 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l3)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_TypedProgram_t*) l3)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        t1 = vader_array_box_slots(_a5_slotarr->buf)[_a5_slotarr->offset + (size_t) l6];
        t2 = t1.payload.s;
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l6)
        l3 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_vader_typecheck_TypedProgram_t*) l3)->f_decl_types;
        l9 = ((vader_struct_std_collections_MutableMap__i32__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l8)->f_ekeys;
        l10 = ((vader_struct_std_collections_MutableMap__i32__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l8)->f_evals;
        l11 = INT64_C(0);
        l12 = ((vader_struct_std_collections_MutableMap__i32__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l8)->f_size;
        while ((l11 < l12)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l11)
            t3 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l11];
            vader_array_t* _a8_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l11)
            l13 = vader_array_ref_load_box(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l11);
            vader_comptime_observe(l2, l13);
            l11 = (l11 + INT64_C(1));
        }
        l14 = ((vader_struct_vader_typecheck_TypedProgram_t*) l3)->f_expr_types;
        l15 = ((vader_struct_std_collections_MutableMap__i64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l14)->f_ekeys;
        l16 = ((vader_struct_std_collections_MutableMap__i64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l14)->f_evals;
        l17 = INT64_C(0);
        l18 = ((vader_struct_std_collections_MutableMap__i64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l14)->f_size;
        while ((l17 < l18)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l17)
            t4 = ((int64_t*) _a9_slotarr->buf->slots)[_a9_slotarr->offset + (size_t) l17];
            vader_array_t* _a10_slotarr = ((vader_array_t*) l16);
            VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l17)
            l19 = vader_array_ref_load_box(_a10_slotarr->buf, _a10_slotarr->offset + (size_t) l17);
            vader_comptime_observe(l2, l19);
            l17 = (l17 + INT64_C(1));
        }
        l20 = ((vader_struct_vader_typecheck_TypedProgram_t*) l3)->f_local_types;
        l21 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l20)->f_ekeys;
        l22 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l20)->f_evals;
        l23 = INT64_C(0);
        l24 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l20)->f_size;
        while ((l23 < l24)) {
            vader_array_t* _a11_slotarr = ((vader_array_t*) l21);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a11_slotarr, l23)
            t4 = ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l23];
            vader_array_t* _a12_slotarr = ((vader_array_t*) l22);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l23)
            l25 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l23);
            vader_comptime_observe(l2, l25);
            l23 = (l23 + INT64_C(1));
        }
        l26 = ((vader_struct_vader_typecheck_TypedProgram_t*) l3)->f_param_types;
        l27 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l26)->f_ekeys;
        l28 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l26)->f_evals;
        l29 = INT64_C(0);
        l30 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l26)->f_size;
        while ((l29 < l30)) {
            vader_array_t* _a13_slotarr = ((vader_array_t*) l27);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l29)
            t4 = ((int64_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l29];
            vader_array_t* _a14_slotarr = ((vader_array_t*) l28);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l29)
            l31 = vader_array_ref_load_box(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l29);
            vader_comptime_observe(l2, l31);
            l29 = (l29 + INT64_C(1));
        }
        l32 = ((vader_struct_vader_typecheck_TypedProgram_t*) l3)->f_type_expr_types;
        l33 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l32)->f_ekeys;
        l34 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l32)->f_evals;
        l35 = INT64_C(0);
        l36 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l32)->f_size;
        while ((l35 < l36)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l33);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l35)
            t4 = ((int64_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l35];
            vader_array_t* _a16_slotarr = ((vader_array_t*) l34);
            VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l35)
            l37 = vader_array_ref_load_box(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l35);
            vader_comptime_observe(l2, l37);
            l35 = (l35 + INT64_C(1));
        }
        l38 = ((vader_struct_vader_typecheck_TypedProgram_t*) l3)->f_impl_method_decl_types;
        l39 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l38)->f_ekeys;
        l40 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l38)->f_evals;
        l41 = INT64_C(0);
        l42 = ((vader_struct_std_collections_MutableMap__u64__vader_types_AnyType___vader_types_ArrayType___vader_types_DistinctType___vader_types_EnumType___vader_types_FnType___vader_types_FreeCharType___vader_types_FreeFloatType___vader_types_FreeIntType___vader_types_InferVar___vader_types_NeverType___vader_types_PrimitiveType___vader_types_RangeType___vader_types_SelfType___vader_types_StructType___vader_types_TraitType___vader_types_TupleType___vader_types_TypeMetaType___vader_types_TypeParamType___vader_types_UnionType___vader_types_UnresolvedType_t*) l38)->f_size;
        while ((l41 < l42)) {
            vader_array_t* _a17_slotarr = ((vader_array_t*) l39);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l41)
            t4 = ((int64_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l41];
            vader_array_t* _a18_slotarr = ((vader_array_t*) l40);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l41)
            l43 = vader_array_ref_load_box(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l41);
            vader_comptime_observe(l2, l43);
            l41 = (l41 + INT64_C(1));
        }
        l6 = (l6 + INT64_C(1));
    }
    l13 = std_collections_MutableMap_std_core_Index_at__string__Any(((vader_struct_vader_typecheck_TypedProject_t*) l0)->f_modules, l1);
    if (!(l13.tag == 0u)) {
        t0 = l13.payload.obj;
        l3 = ((vader_struct_vader_typecheck_ImplTables_t*) ((vader_struct_vader_typecheck_TypedProgram_t*) t0)->f_impl_tables)->f_impl_methods;
        l4 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_ImplMethod___t*) l3)->f_ekeys;
        l5 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_ImplMethod___t*) l3)->f_evals;
        l6 = INT64_C(0);
        l7 = ((vader_struct_std_collections_MutableMap__string__vader_typecheck_ImplMethod___t*) l3)->f_size;
        while ((l6 < l7)) {
            vader_array_t* _a19_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a19_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a19_slotarr, l6)
            t1 = vader_array_box_slots(_a19_slotarr->buf)[_a19_slotarr->offset + (size_t) l6];
            t2 = t1.payload.s;
            vader_array_t* _a20_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a20_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a20_slotarr, l6)
            l3 = vader_array_ref_load_obj(_a20_slotarr->buf, _a20_slotarr->offset + (size_t) l6);
            l11 = ((vader_array_t*) l3)->length;
            l12 = INT64_C(0);
            while ((l12 < l11)) {
                vader_array_t* _a21_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
                t0 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l12);
                l13 = ((vader_struct_vader_typecheck_ImplMethod_t*) t0)->f_ty;
                vader_comptime_observe(l2, l13);
                l12 = (l12 + INT64_C(1));
            }
            l6 = (l6 + INT64_C(1));
        }
    }
    t0 = vader_comptime_sorted_instances(l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_comptime_has_comptime_decorator(void* l0) {
    void* l1;
    int64_t l2, l3;
    void* t0;
    vader_string_t t1;
    l1 = ((vader_struct_toolchain_ast_ConstDecl_t*) l0)->f_decorators;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = ((vader_struct_toolchain_ast_Decorator_t*) t0)->f_name;
        if (t1 == 1678u) {
            return true;
        }
        l3 = (l3 + INT64_C(1));
    }
    return false;
}

static bool vader_comptime_has_union_operand(void* l0, void* l1) {
    void* l2;
    int64_t l3;
    vader_box_t t0;
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l0)->f_typed)->f_expr_types;
    l3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_left.payload.obj);
    t0 = std_collections_MutableMap_std_core_Index_at__i64__Any(l2, l3);
    if (t0.tag == 1323u) {
        return true;
    }
    l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l0)->f_typed)->f_expr_types;
    l3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast_ArrayTypeExpr_t, f_id, ((vader_struct_toolchain_ast_BinaryExpr_t*) l1)->f_right.payload.obj);
    t0 = std_collections_MutableMap_std_core_Index_at__i64__Any(l2, l3);
    return t0.tag == 1323u;
}

static int64_t vader_comptime_int_bits_of(vader_string_t l0) {
    void* l1;
    vader_box_t l2;
    int64_t t0;
    l2 = vader_integer_machine_integer_named(l0);
    if (l2.tag == 0u) {
        return INT64_C(64);
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_vader_integer_MachineInteger_t*) l1)->f_bits;
    return t0;
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

static vader_string_t vader_comptime_int_digits(void* l0) {
    void* l1 = NULL;
    int64_t l2, l4;
    uint64_t l3;
    vader_string_t t0 = 0;
    bool t1;
    int64_t t2, t3;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_comptime_IntValue_t*) l0)->f_type_name;
    t1 = vader_types_is_unsigned_int_name(t0);
    if (!(t1)) {
        l1 = (void*) vader_buffer_new((size_t) INT64_C(20));
        l2 = INT64_C(0);
        l4 = ((vader_struct_vader_comptime_IntValue_t*) l0)->f_value;
        l2 = std_core_write_int(l1, l2, l4);
        t0 = std_core_finish_buffer(l1, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(20));
    l2 = INT64_C(0);
    t2 = ((vader_struct_vader_comptime_IntValue_t*) l0)->f_value;
    t3 = t2;
    l3 = (uint64_t) (int64_t) t3;
    l2 = std_core_write_unsigned(l1, l2, l3);
    t0 = std_core_finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (l2.tag == 937u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        if (t1 == INT64_C(0)) {
            t0 = vader_comptime_division_by_zero(l0, 389u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_comptime_arithmetic(l0, l1, l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_comptime_arithmetic(l0, l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_int_mod_check(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 937u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
        if (t1 == INT64_C(0)) {
            t0 = vader_comptime_division_by_zero(l0, 242u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = (void*) &vader_fn_static_vader_comptime_op_mod;
        t0 = vader_comptime_arithmetic_int(l0, l1, l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = (void*) &vader_fn_static_vader_comptime_op_mod;
    t0 = vader_comptime_arithmetic_int(l0, l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_int_val(int64_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_IntValue_t* _a0_obj = (vader_struct_vader_comptime_IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_IntValue_t));
    vader_obj_header_init(_a0_obj, 937u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = 1968u;
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
    vader_obj_header_init(_a0_obj, 937u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_comptime_interp_value(vader_box_t l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    int64_t l3;
    bool l4;
    uint32_t l5;
    void* t0 = NULL;
    double t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 937u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_int_digits(t0);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 934u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_comptime_FloatValue_t*) t0)->f_value;
        l1 = std_core_f64_Display_to_string(t1);
    } else if (l0.tag == 925u) {
        l2 = (void*) vader_buffer_new((size_t) INT64_C(5));
        l3 = INT64_C(0);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
        l3 = std_core_write_bool(l2, l3, l4);
        l1 = std_core_finish_buffer(l2, l3);
    } else if (l0.tag == 944u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
    } else if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_comptime_CharValue_t*) t0)->f_value;
        if ((l5 > INT32_C(55295))) {
            if ((l5 < INT32_C(57344))) {
                l4 = true;
            } else {
                l4 = (l5 > INT32_C(1114111));
            }
            if (l4) {
                vader_unreachable("value out of range: no Unicode scalar value");
            }
        }
        l1 = std_core_char_Display_to_string(((uint32_t) (uint32_t) l5));
    } else if (l0.tag == 942u) {
        l1 = 2291u;
    } else if (l0.tag == 948u) {
        l1 = 0u;
    } else if (l0.tag == 923u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_display_value(vader_ref_box(t0));
    } else if (l0.tag == 945u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_display_value(vader_ref_box(t0));
    } else if (l0.tag == 946u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_display_value(vader_ref_box(t0));
    } else {
        if (!(l0.tag == 929u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l1 = vader_comptime_display_value(vader_ref_box(t0));
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_intrinsic_align_of(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 1439u, INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t0 = vader_comptime_byte_align(l2);
        t2 = vader_comptime_int_val_typed(t0, 1990u);
        t1 = vader_comptime_ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_comptime_arg_error(l0, 1440u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_intrinsic_field_count(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 1884u, INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t0 = vader_comptime_type_field_count(l2, l1);
        t2 = vader_comptime_int_val_typed(t0, 1990u);
        t1 = vader_comptime_ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_comptime_arg_error(l0, 1885u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_intrinsic_field_index(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l6 = vader_box_null();
    void* l4 = NULL;
    int32_t l5;
    int64_t l7, l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l6, &t2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(2)) {
        t1 = vader_comptime_arg_count_error(l0, 1886u, INT64_C(2));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1889u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(1))
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(1));
    l3 = toolchain_ast_string_literal_text(t2);
    if (l3.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 1888u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 1318u)) {
        l9 = vader_types_display_type(l2);
        l10 = concat_3(1887u, l9, 1105u);
        t1 = vader_comptime_arg_error(l0, l10);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_struct_decls;
    t1 = l2.payload.obj;
    l5 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t1)->f_symbol)->f_id;
    l6 = std_collections_MutableMap_std_core_Index_at__i32__Any(l4, l5);
    if (!(l6.tag == 644u)) {
        t1 = l2.payload.obj;
        l9 = vader_types_display_type(vader_ref_box(t1));
        l10 = concat_3(1890u, l9, 1141u);
        t1 = vader_comptime_arg_error(l0, l10);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = INT64_C(0);
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
            t2 = vader_comptime_int_val_typed(l7, 1990u);
            t1 = vader_comptime_ok(t2);
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = (l7 + INT64_C(1));
    }
    t1 = l2.payload.obj;
    l9 = vader_types_display_type(vader_ref_box(t1));
    l10 = l3.payload.s;
    l9 = concat_5(1887u, l9, 1049u, l10, 981u);
    t1 = vader_comptime_arg_error(l0, l9);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_intrinsic_integer_bound(void* l0, void* l1) {
    vader_string_t l2 = 0;
    vader_string_t l5 = 0;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l6 = NULL;
    bool l7;
    int64_t l8;
    int64_t t0;
    void* t1 = NULL;
    void* t5 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    bool t4;
    vader_box_t* gc_roots[3] = { &l3, &l4, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l6, &t1, &t5 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l5, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
        t1 = vader_comptime_arg_count_error(l0, l2, INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l3 = vader_comptime_resolve_type_arg(t2, l1);
    if (l3.tag == 0u) {
        t3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
        l2 = concat_2(t3, 416u);
        t1 = vader_comptime_arg_error(l0, l2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_typecheck_type_bounds(l3);
    if (l4.tag == 0u) {
        l2 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
        l5 = vader_types_display_type(l3);
        l2 = concat_4(l2, 412u, l5, 1047u);
        t1 = vader_comptime_arg_error(l0, l2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = l4.payload.obj;
    t3 = ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_name;
    l7 = t3 == 2191u;
    l8 = vader_types_integer_bound(l6, l7);
    t4 = vader_types_is_char(l3);
    if (!(t4)) {
        l2 = vader_types_representation_name(l3);
        t2 = vader_comptime_int_val_typed(l8, l2);
        t1 = vader_comptime_ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_comptime_CharValue_t* _a1_obj = (vader_struct_vader_comptime_CharValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_CharValue_t));
    vader_obj_header_init(_a1_obj, 926u);
    _a1_obj->f_value = (uint32_t) (int32_t) ((int32_t) (int64_t) l8);
    t1 = (void*) _a1_obj;
    t5 = vader_comptime_ok(vader_ref_box(t1));
    { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_intrinsic_satisfies(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_string_t l4 = 0;
    void* l5 = NULL;
    int64_t t0;
    void* t1 = NULL;
    void* t3 = NULL;
    vader_box_t t2 = vader_box_null();
    bool t4;
    vader_box_t* gc_roots[3] = { &l2, &l3, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &t1, &t3 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(2)) {
        t1 = vader_comptime_arg_count_error(l0, 2407u, INT64_C(2));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_comptime_arg_error(l0, 2408u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(1))
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(1));
    l3 = vader_comptime_resolve_type_arg(t2, l1);
    if (!(l3.tag == 1319u)) {
        t1 = (void*) &vader_data_37;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        t3 = vader_comptime_ok(vader_ref_box(t1));
        { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l3.payload.obj;
    l4 = vader_types_trait_key_of(((vader_struct_vader_types_TraitType_t*) t1)->f_symbol);
    l5 = ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed;
    t4 = vader_typecheck_struct_implements_trait(l2, l4, l5);
    t2 = vader_comptime_bool_value(t4);
    t1 = vader_comptime_ok(t2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_intrinsic_size_of(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 2429u, INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t0 = vader_comptime_byte_size(l2);
        t2 = vader_comptime_int_val_typed(t0, 1990u);
        t1 = vader_comptime_ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_comptime_arg_error(l0, 2431u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_intrinsic_type_kind(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int64_t t0;
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
        t1 = vader_comptime_arg_count_error(l0, 2629u, INT64_C(1));
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
    t1 = vader_comptime_arg_error(l0, 2630u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_intrinsic_type_name(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int64_t t0;
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
        t1 = vader_comptime_arg_count_error(l0, 2631u, INT64_C(1));
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
    t1 = vader_comptime_arg_error(l0, 2632u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_intrinsic_variant_count(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        t1 = vader_comptime_arg_count_error(l0, 2859u, INT64_C(1));
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast_IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_comptime_resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t0 = vader_comptime_type_variant_count(l2);
        t2 = vader_comptime_int_val_typed(t0, 1990u);
        t1 = vader_comptime_ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_comptime_arg_error(l0, 2860u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_comptime_is_concrete_enough(vader_box_t l0) {
    if (!((l0.tag == 1309u || l0.tag == 1310u || l0.tag == 1311u || l0.tag == 1317u || l0.tag == 1324u))) {
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
    if (!(l0.tag == 1324u)) {
        return true;
    }
    return false;
}

static vader_box_t vader_comptime_lookup_module_decls(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t t0;
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
    if (!(l0.tag == 937u)) {
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

static vader_box_t vader_comptime_native_library(vader_box_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_box_t l3 = vader_box_null();
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l9, l10;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l3, &t1 };
    void** gc_raw_roots[4] = { &l6, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[6] = { &l1, &l2, &l4, &l5, &l11, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 6u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 945u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l0.payload.obj;
    l3 = vader_comptime_string_field(t0, 2243u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.s;
    t0 = l0.payload.obj;
    l3 = vader_comptime_string_field(t0, 1962u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = l3.payload.s;
    t0 = l0.payload.obj;
    l3 = vader_comptime_string_field(t0, 2042u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = l3.payload.s;
    t0 = l0.payload.obj;
    l3 = vader_comptime_strings_field(t0, 1471u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l6 = l3.payload.obj;
    t0 = l0.payload.obj;
    l3 = vader_comptime_strings_field(t0, 2556u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l7 = l3.payload.obj;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 316u);
    l8 = (void*) _a0_arr;
    l9 = ((vader_array_t*) l6)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l8, (int64_t) l9);
    l8 = (void*) _a1_arr;
    l9 = ((vader_array_t*) l6)->length;
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l10];
        l11 = t1.payload.s;
        l12 = vader_resolver_join_path(l1, l11);
        vader_array_push_scalar((vader_array_t*) l8, vader_box_string(316u, l12));
        l10 = (l10 + INT64_C(1));
    }
    l5 = vader_comptime_folder_beside(l1, l5);
    vader_struct_vader_comptime_NativeLibrary_t* _a3_obj = (vader_struct_vader_comptime_NativeLibrary_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_NativeLibrary_t));
    vader_obj_header_init(_a3_obj, 939u);
    _a3_obj->f_name = l2;
    _a3_obj->f_header = l4;
    _a3_obj->f_include = l5;
    _a3_obj->f_archives = l8;
    _a3_obj->f_system = l7;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 319u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 327u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 319u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 419u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 319u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(24u, 0u, 1u, 321u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 319u);
    l4 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__vader_comptime_ComptimeRoute_t));
    vader_obj_header_init(_a7_obj, 440u);
    _a7_obj->f_ekeys = l2;
    _a7_obj->f_evals = l3;
    _a7_obj->f_index = l4;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(86u, 0u, 13u, 933u);
    l3 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(83u, 0u, 13u, 924u);
    l4 = (void*) _a9_arr;
    vader_struct_vader_comptime_EvaluatedProgram_t* _a10_obj = (vader_struct_vader_comptime_EvaluatedProgram_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvaluatedProgram_t));
    vader_obj_header_init(_a10_obj, 931u);
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
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 10u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 316u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(28u, 0u, 0u, 327u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 7u, 319u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections_MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections_MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 489u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 319u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(28u, 0u, 0u, 327u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(22u, 0u, 7u, 319u);
    l4 = (void*) _a6_arr;
    vader_struct_std_collections_MutableMap__i32__Any_t* _a7_obj = (vader_struct_std_collections_MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i32__Any_t));
    vader_obj_header_init(_a7_obj, 419u);
    _a7_obj->f_ekeys = l2;
    _a7_obj->f_evals = l3;
    _a7_obj->f_index = l4;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(23u, 0u, 8u, 320u);
    l3 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(21u, 0u, 0u, 316u);
    l4 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(22u, 0u, 7u, 319u);
    l5 = (void*) _a10_arr;
    vader_struct_std_collections_MutableMap__i64__string_t* _a11_obj = (vader_struct_std_collections_MutableMap__i64__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__string_t));
    vader_obj_header_init(_a11_obj, 467u);
    _a11_obj->f_ekeys = l3;
    _a11_obj->f_evals = l4;
    _a11_obj->f_index = l5;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(87u, 0u, 13u, 935u);
    l4 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(89u, 0u, 13u, 947u);
    l5 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(23u, 0u, 8u, 320u);
    l6 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(28u, 0u, 0u, 327u);
    l7 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(22u, 0u, 7u, 319u);
    l8 = (void*) _a16_arr;
    vader_struct_std_collections_MutableMap__i64__Any_t* _a17_obj = (vader_struct_std_collections_MutableMap__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__Any_t));
    vader_obj_header_init(_a17_obj, 461u);
    _a17_obj->f_ekeys = l6;
    _a17_obj->f_evals = l7;
    _a17_obj->f_index = l8;
    _a17_obj->f_mask = INT64_C(0);
    _a17_obj->f_grow_at = INT64_C(0);
    _a17_obj->f_size = INT64_C(0);
    _a17_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a17_obj;
    vader_struct_vader_comptime_EvaluatedProject_t* _a18_obj = (vader_struct_vader_comptime_EvaluatedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvaluatedProject_t));
    vader_obj_header_init(_a18_obj, 932u);
    _a18_obj->f_typed = l0;
    _a18_obj->f_modules = l1;
    _a18_obj->f_file_baked_consts = l2;
    _a18_obj->f_file_exprs = l3;
    _a18_obj->f_instances = l4;
    _a18_obj->f_vm_required = l5;
    _a18_obj->f_libraries = l6;
    t0 = (void*) _a18_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_normalize_int_result(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    int64_t l3;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_comptime_EvalResult_t*) l0)->f_value;
    if (!(l2.tag == 937u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    t1 = ((vader_struct_vader_comptime_IntValue_t*) t0)->f_value;
    l3 = vader_comptime_wrap_to_width(t1, l1);
    t0 = l2.payload.obj;
    l4 = vader_comptime_result_type_name(t0, l1);
    t2 = vader_comptime_int_val_typed(l3, l4);
    t0 = vader_comptime_ok(t2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_comptime_observe(void* l0, vader_box_t l1) {
    vader_comptime_walk_type(l0, l1);
    return;
}

static void* vader_comptime_ok(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_comptime_EvalResult_t* _a0_obj = (vader_struct_vader_comptime_EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EvalResult_t));
    vader_obj_header_init(_a0_obj, 930u);
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
    return (l0 << (l1 & 63));
}

int64_t vader_comptime_op_shr(int64_t l0, int64_t l1) {
    return (l0 >> (l1 & 63));
}

int64_t vader_comptime_op_sub(int64_t l0, int64_t l1) {
    return (l0 - l1);
}

static vader_box_t vader_comptime_pattern_holds(vader_box_t l0, vader_box_t l1) {
    vader_string_t l2, l3;
    void* l4;
    int64_t l5, l6;
    vader_box_t l7;
    void* t0;
    vader_box_t t1;
    bool t2;
    if (l0.tag == 659u) {
        return vader_box_bool(314u, true);
    }
    if (l0.tag == 597u) {
        if (!(l1.tag == 929u)) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_comptime_EnumValue_t*) t0)->f_variant;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast_EnumVariantPattern_t*) t0)->f_variant;
        return vader_box_bool(314u, l2 == l3);
    }
    if (!(l0.tag == 629u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    l4 = ((vader_struct_toolchain_ast_OrPattern_t*) t0)->f_patterns;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l7 = vader_comptime_pattern_holds(t1, l1);
        if (l7.tag == 0u) {
            return vader_box_obj(0u, NULL);
        }
        t2 = l7.payload.b;
        if (t2) {
            return vader_box_bool(314u, true);
        }
        l6 = (l6 + INT64_C(1));
    }
    return vader_box_bool(314u, false);
}

static void vader_comptime_populate_deps(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    int64_t l3, l4, l5;
    vader_box_t l7 = vader_box_null(), l11 = vader_box_null();
    int32_t l13;
    vader_box_t* gc_roots[2] = { &l7, &l11 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l6, &l8, &l9, &l10, &l12 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        l7 = std_collections_MutableMap_std_core_Index_at__i64__Any(((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_id, l5);
        if (l7.tag == 0u) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l6 = l7.payload.obj;
        l9 = ((vader_struct_vader_typecheck_TypedProgram_t*) l1)->f_resolved;
        l10 = ((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l6)->f_decl)->f_name_span;
        l11 = vader_resolver_symbol_declared_at(l9, l10);
        if (l11.tag == 0u) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l8 = l11.payload.obj;
        l12 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_symbol;
        l13 = ((vader_struct_vader_resolver_symbol_Symbol_t*) l8)->f_id;
        std_collections_MutableMap_std_core_IndexSet_set_at__i32__i64(l12, l13, l5);
        l4 = (l4 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
        l7 = std_collections_MutableMap_std_core_Index_at__i64__Any(((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_id, l5);
        if (l7.tag == 0u) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l6 = l7.payload.obj;
        vader_array_t* _a2_arr = vader_array_new(23u, 0u, 8u, 320u);
        l8 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(19u, 0u, 12u, 314u);
        l9 = (void*) _a3_arr;
        vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 319u);
        l10 = (void*) _a4_arr;
        vader_struct_std_collections_MutableMap__i64__bool_t* _a5_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
        vader_obj_header_init(_a5_obj, 463u);
        _a5_obj->f_ekeys = l8;
        _a5_obj->f_evals = l9;
        _a5_obj->f_index = l10;
        _a5_obj->f_mask = INT64_C(0);
        _a5_obj->f_grow_at = INT64_C(0);
        _a5_obj->f_size = INT64_C(0);
        _a5_obj->f_tombs = INT64_C(0);
        l12 = (void*) _a5_obj;
        vader_comptime_collect_expr_deps(((vader_struct_toolchain_ast_ConstDecl_t*) ((vader_struct_vader_comptime_NodeRecord_t*) l6)->f_decl)->f_value, l1, l0, l12, l6);
        std_collections_MutableMap_std_core_IndexSet_set_at__i64__Any(((vader_struct_vader_comptime_Nodes_t*) l0)->f_by_id, l5, vader_ref_box(l6));
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_comptime_read_relative_file(vader_string_t l0, vader_string_t l1) {
    vader_string_t l2 = 0;
    vader_box_t l3 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    vader_string_t* gc_atom_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_string_starts_with(l0, 389u);
    if (t0) {
        l2 = l0;
    } else if (l1 == 0u) {
        l2 = l0;
    } else {
        l2 = concat_3(l1, 389u, l0);
    }
    l3 = std_io_read_file_string(l2, INT64_C(16777216));
    if (!(l3.tag == 316u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t1 = l3.payload.s;
    { vader_box_t __vret = vader_box_string(316u, t1); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_comptime_render_array(void* l0) {
    void* l1 = NULL;
    void* l7 = NULL;
    int64_t l2, l3, l5;
    bool l4;
    vader_string_t l6 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l1, &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 316u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 571u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string_builder_append_char(l1, 91u);
    l2 = ((vader_array_t*) ((vader_struct_vader_comptime_ArrayValue_t*) l0)->f_elements)->length;
    l3 = ((int64_t) 16);
    l4 = (l2 > l3);
    if (l4) {
        l3 = ((int64_t) 8);
    } else {
        l3 = l2;
    }
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        if ((l5 > INT64_C(0))) {
            std_string_builder_append(l1, 317u);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_comptime_ArrayValue_t*) l0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l6 = vader_comptime_display_value(t1);
        std_string_builder_append(l1, l6);
        l5 = (l5 + INT64_C(1));
    }
    if (l4) {
        l7 = (void*) vader_buffer_new((size_t) INT64_C(35));
        l3 = INT64_C(0);
        l3 = std_core_write_string_at(l7, l3, 319u);
        l3 = std_core_write_int(l7, l3, l2);
        l3 = std_core_write_string_at(l7, l3, 85u);
        l6 = std_core_finish_buffer(l7, l3);
        std_string_builder_append(l1, l6);
    }
    std_string_builder_append_char(l1, 93u);
    t2 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_comptime_render_struct(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_string_t l2 = 0;
    vader_string_t l9 = 0;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[3] = { &l7, &l8, &t1 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l9, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 316u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 571u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = ((vader_struct_vader_comptime_StructValue_t*) l0)->f_type_name;
    std_string_builder_append(l1, l2);
    std_string_builder_append(l1, 192u);
    l3 = std_collections_keys__string__vader_comptime_ArrayValue___vader_comptime_BoolValue___vader_comptime_CharValue___vader_comptime_EnumValue___vader_comptime_FloatValue___vader_comptime_IntValue___vader_comptime_NullValue___vader_comptime_StringValue___vader_comptime_StructValue___vader_comptime_TypeValue___vader_comptime_VoidValue(((vader_struct_vader_comptime_StructValue_t*) l0)->f_fields);
    l4 = (void*) &vader_fn_static___lambda_vader_comptime_0;
    l3 = std_sort_sort__string(l3, l4);
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) l3)->length;
    while ((l5 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l5];
        l2 = t1.payload.s;
        l8 = std_collections_MutableMap_std_core_Index_at__string__Any(((vader_struct_vader_comptime_StructValue_t*) l0)->f_fields, l2);
        if (l8.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l7 = l8;
        if ((l5 > INT64_C(0))) {
            std_string_builder_append(l1, 317u);
        }
        std_string_builder_append_char(l1, 46u);
        std_string_builder_append(l1, l2);
        std_string_builder_append(l1, 61u);
        l9 = vader_comptime_display_value(l7);
        std_string_builder_append(l1, l9);
        l5 = (l5 + INT64_C(1));
    }
    std_string_builder_append(l1, 195u);
    t2 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
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
    if (!(l4.tag == 1324u)) {
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_string_t vader_comptime_resolved_int_name(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_string_t l3;
    l2 = std_collections_MutableMap_std_core_Index_at__i64__Any(((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l0)->f_typed)->f_expr_types, l1);
    l3 = vader_types_primitive_name(l2);
    if (l3 != 0u) {
        return l3;
    }
    if (!(l2.tag == 1311u)) {
        return 0u;
    }
    return 1968u;
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
    if (l0.tag == 937u) {
        l2 = l1.tag == 937u;
        return l2;
    }
    if (l0.tag == 934u) {
        l2 = l1.tag == 934u;
    } else if (l0.tag == 925u) {
        l2 = l1.tag == 925u;
    } else if (l0.tag == 926u) {
        l2 = l1.tag == 926u;
    } else if (l0.tag == 944u) {
        l2 = l1.tag == 944u;
    } else if (l0.tag == 942u) {
        l2 = l1.tag == 942u;
    } else if (l0.tag == 948u) {
        l2 = l1.tag == 948u;
    } else if (l0.tag == 923u) {
        l2 = l1.tag == 923u;
    } else if (l0.tag == 945u) {
        l2 = l1.tag == 945u;
    } else if (l0.tag == 946u) {
        l2 = l1.tag == 946u;
    } else {
        if (!(l0.tag == 929u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l1.tag == 929u;
    }
    return l2;
}

vader_string_t vader_comptime_sanitise_ident(vader_string_t l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    uint8_t l4;
    uint32_t l5;
    void* t0 = NULL;
    bool t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 316u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string_builder_StringBuilder_t* _a1_obj = (vader_struct_std_string_builder_StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string_builder_StringBuilder_t));
    vader_obj_header_init(_a1_obj, 571u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = vader_host_std_core_byte_len(l0);
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        l4 = vader_host_std_core_byte_at(l0, l3);
        t1 = vader_text_is_ident_byte(l4);
        if (t1) {
            l5 = ((uint32_t) (int32_t) ((int32_t) (uint8_t) l4));
            std_string_builder_append_char(l1, l5);
        } else {
            std_string_builder_append_char(l1, 95u);
        }
        l3 = (l3 + INT64_C(1));
    }
    t2 = std_string_builder_StringBuilder_std_core_Display_to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_comptime_shift_amount_mask(vader_string_t l0) {
    void* l1;
    vader_box_t l2;
    int64_t t0;
    l2 = vader_integer_machine_integer_named(l0);
    if (l2.tag == 0u) {
        return INT64_C(63);
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_vader_integer_MachineInteger_t*) l1)->f_bits;
    if (!((t0 <= INT64_C(32)))) {
        return INT64_C(63);
    }
    return INT64_C(31);
}

static int64_t vader_comptime_sign_extend(int64_t l0, int64_t l1) {
    int64_t l2, l3, l4;
    int64_t t0;
    l2 = (INT64_C(1) << (l1 & 63));
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
    l1 = std_collections_values__string__vader_comptime_GenericInstance(((vader_struct_vader_comptime_InstanceRegistry_t*) l0)->f_by_key);
    l2 = (void*) &vader_fn_static_vader_comptime_display_key_before;
    t0 = std_sort_sort__vader_comptime_GenericInstance(l1, l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_string_field(void* l0, vader_string_t l1) {
    vader_box_t l2;
    void* t0;
    vader_string_t t1;
    l2 = std_collections_MutableMap_std_core_Index_at__string__Any(((vader_struct_vader_comptime_StructValue_t*) l0)->f_fields, l1);
    if (l2.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    if (!(l2.tag == 944u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l2.payload.obj;
    t1 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
    return vader_box_string(316u, t1);
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
    vader_obj_header_init(_a0_obj, 944u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_comptime_strings_field(void* l0, vader_string_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = std_collections_MutableMap_std_core_Index_at__string__Any(((vader_struct_vader_comptime_StructValue_t*) l0)->f_fields, l1);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(l2.tag == 923u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 316u);
    l3 = (void*) _a0_arr;
    t0 = l2.payload.obj;
    l4 = ((vader_struct_vader_comptime_ArrayValue_t*) t0)->f_elements;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        if (!(l2.tag == 944u)) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_comptime_StringValue_t*) t0)->f_value;
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(316u, l7));
        l6 = (l6 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_comptime_topo_sort(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t l7, l8, l9;
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(39u, 0u, 13u, 584u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(91u, 0u, 13u, 951u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 8u, 320u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(22u, 0u, 7u, 319u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 7u, 319u);
    l5 = (void*) _a4_arr;
    vader_struct_std_collections_MutableMap__i64__i32_t* _a5_obj = (vader_struct_std_collections_MutableMap__i64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__i32_t));
    vader_obj_header_init(_a5_obj, 464u);
    _a5_obj->f_ekeys = l3;
    _a5_obj->f_evals = l4;
    _a5_obj->f_index = l5;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 8u, 320u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(19u, 0u, 12u, 314u);
    l5 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(22u, 0u, 7u, 319u);
    l6 = (void*) _a8_arr;
    vader_struct_std_collections_MutableMap__i64__bool_t* _a9_obj = (vader_struct_std_collections_MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections_MutableMap__i64__bool_t));
    vader_obj_header_init(_a9_obj, 463u);
    _a9_obj->f_ekeys = l4;
    _a9_obj->f_evals = l5;
    _a9_obj->f_index = l6;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_grow_at = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a9_obj;
    l5 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a10_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
        l9 = ((int64_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l8];
        std_collections_MutableMap_std_core_IndexSet_set_at__i64__i32(l3, l9, INT32_C(0));
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a11_arr = vader_array_new(23u, 0u, 8u, 320u);
    l5 = (void*) _a11_arr;
    l6 = ((vader_struct_vader_comptime_Nodes_t*) l0)->f_order;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a12_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
        t0 = ((int64_t*) _a12_slotarr->buf->slots)[_a12_slotarr->offset + (size_t) l8];
        vader_comptime_visit(t0, l0, l3, l4, l5, INT64_C(0), l1, l2);
        l8 = (l8 + INT64_C(1));
    }
    vader_struct_vader_comptime_ComptimeOrder_t* _a13_obj = (vader_struct_vader_comptime_ComptimeOrder_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_ComptimeOrder_t));
    vader_obj_header_init(_a13_obj, 928u);
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
    int64_t t1;
    if (l0.tag == 1318u) {
        l2 = ((vader_struct_vader_typecheck_TypedProgram_t*) ((vader_struct_vader_comptime_ComptimeContext_t*) l1)->f_typed)->f_struct_decls;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_resolver_symbol_Symbol_t*) ((vader_struct_vader_types_StructType_t*) t0)->f_symbol)->f_id;
        l4 = std_collections_MutableMap_std_core_Index_at__i32__Any(l2, l3);
        if (!(l4.tag == 644u)) {
            return INT64_C(0);
        }
        t0 = l4.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast_StructDecl_t*) t0)->f_fields)->length;
        return t1;
    }
    if (!(l0.tag == 1320u)) {
        return INT64_C(0);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_array_t*) ((vader_struct_vader_types_TupleType_t*) t0)->f_elements)->length;
    return t1;
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
    if ((l0.tag == 1315u || l0.tag == 1316u)) {
        l1 = 2349u;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1306u) {
        t0 = l0.payload.obj;
        l1 = vader_comptime_type_kind_label(((vader_struct_vader_types_DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 1318u) {
        l1 = 2523u;
    } else if (l0.tag == 1307u) {
        l1 = 1773u;
    } else if (l0.tag == 1323u) {
        l1 = 2678u;
    } else if (l0.tag == 1305u) {
        l1 = 1481u;
    } else if (l0.tag == 1320u) {
        l1 = 2608u;
    } else if (l0.tag == 1308u) {
        l1 = 1900u;
    } else if (l0.tag == 1319u) {
        l1 = 2600u;
    } else if (l0.tag == 1321u) {
        l1 = 2610u;
    } else if (l0.tag == 1322u) {
        l1 = 2681u;
    } else if (l0.tag == 1312u) {
        t0 = l0.payload.obj;
        vader_types_leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 1317u) {
        l1 = 2681u;
    } else if (l0.tag == 1324u) {
        l1 = 2681u;
    } else if (l0.tag == 1311u) {
        l1 = 2681u;
    } else if (l0.tag == 1309u) {
        l1 = 2681u;
    } else if (l0.tag == 1310u) {
        l1 = 2681u;
    } else if (l0.tag == 1313u) {
        l1 = 2681u;
    } else {
        if (!(l0.tag == 1304u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1469u;
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
    t0 = vader_diagnostics_comptime_error((uint8_t) 5, l2, l1);
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
    vader_obj_header_init(_a0_obj, 946u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_comptime_type_variant_count(vader_box_t l0) {
    void* t0;
    int64_t t1;
    if (l0.tag == 1323u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_types_UnionType_t*) t0)->f_variants)->length;
        return t1;
    }
    if (!(l0.tag == 1307u)) {
        return INT64_C(0);
    }
    t0 = l0.payload.obj;
    t1 = std_collections_len__string__i64(((vader_struct_vader_types_EnumType_t*) t0)->f_indices);
    return t1;
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
    if (!(l1.tag == 937u)) {
        t0 = vader_comptime_unary_type_mismatch(l0, 1350u);
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
    if (l1.tag == 937u) {
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
    if (!(l1.tag == 934u)) {
        t0 = vader_comptime_unary_type_mismatch(l0, 1244u);
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
    if (!(l1.tag == 925u)) {
        t0 = vader_comptime_unary_type_mismatch(l0, 1208u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = ((vader_struct_vader_comptime_BoolValue_t*) t0)->f_value;
    if (!(t1)) {
        t0 = (void*) &vader_data_36;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        t2 = vader_comptime_ok(vader_ref_box(t0));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = (void*) &vader_data_37;
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
    t0 = vader_diagnostics_comptime_error((uint8_t) 5, l2, l1);
    t1 = vader_comptime_fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_comptime_uniq(void* l0, vader_string_t l1) {
    int32_t l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    int64_t l5, l7, l8;
    void* l6 = NULL;
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
        l6 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l5));
        l7 = INT64_C(0);
        l7 = std_core_write_string_at(l6, l7, l4);
        l7 = std_core_write_string_at(l6, l7, 920u);
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

static void* vader_comptime_variant_value(void* l0, vader_string_t l1, void* l2) {
    int64_t l3;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_types_EnumType_t*) l0)->f_data.tag == 0u)) {
        t0 = vader_comptime_vm_required(l2, 2858u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_collections_MutableMap_std_core_Index_at__string__i64(((vader_struct_vader_types_EnumType_t*) l0)->f_indices, l1);
    if (l4.tag == 0u) {
        t0 = vader_comptime_vm_required(l2, 2683u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int64_t) l4.payload.i);
    vader_struct_vader_comptime_EnumValue_t* _a0_obj = (vader_struct_vader_comptime_EnumValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_comptime_EnumValue_t));
    vader_obj_header_init(_a0_obj, 929u);
    _a0_obj->f_enum_type = l0;
    _a0_obj->f_variant = l1;
    _a0_obj->f_value = l3;
    t0 = (void*) _a0_obj;
    t1 = vader_comptime_ok(vader_ref_box(t0));
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_comptime_visit(int64_t l0, void* l1, void* l2, void* l3, void* l4, int64_t l5, void* l6, void* l7) {
    int32_t l8;
    vader_box_t l9 = vader_box_null();
    int64_t l10, l12, l13, l14;
    void* l11 = NULL;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l9, &t1 };
    void** gc_raw_roots[8] = { &l1, &l2, &l3, &l4, &l6, &l7, &l11, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l9 = std_collections_MutableMap_std_core_Index_at__i64__i32(l2, l0);
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
    std_collections_MutableMap_std_core_IndexSet_set_at__i64__i32(l2, l0, INT32_C(1));
    l10 = ((vader_array_t*) l4)->length;
    if ((l5 < l10)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l5] = (int64_t) l0;
    } else {
        vader_array_push_i64((vader_array_t*) l4, l0);
    }
    l9 = std_collections_MutableMap_std_core_Index_at__i64__Any(((vader_struct_vader_comptime_Nodes_t*) l1)->f_by_id, l0);
    if (!(l9.tag == 0u)) {
        t0 = l9.payload.obj;
        l11 = ((vader_struct_vader_comptime_NodeRecord_t*) t0)->f_dependency_ids;
        l10 = ((vader_array_t*) l11)->length;
        l12 = INT64_C(0);
        while ((l12 < l10)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l13 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l12];
            l14 = vader_chk_add(i64, l5, INT64_C(1));
            vader_comptime_visit(l13, l1, l2, l3, l4, l14, l6, l7);
            l12 = (l12 + INT64_C(1));
        }
    }
    std_collections_MutableMap_std_core_IndexSet_set_at__i64__i32(l2, l0, INT32_C(2));
    t1 = std_collections_MutableMap_std_core_Index_at__i64__bool(l3, l0);
    if (t1.tag == 0u) {
        l9 = std_collections_MutableMap_std_core_Index_at__i64__Any(((vader_struct_vader_comptime_Nodes_t*) l1)->f_by_id, l0);
        if (!(l9.tag == 0u)) {
            t0 = l9.payload.obj;
            l11 = ((vader_struct_vader_comptime_NodeRecord_t*) t0)->f_decl;
            vader_array_push_ref((vader_array_t*) l6, l11);
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
    vader_obj_header_init(_a0_obj, 930u);
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    _a0_obj->f_diag = vader_ref_box(l2);
    _a0_obj->f_vm_required = true;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_comptime_walk_type(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1318u) {
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
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
            vader_comptime_walk_type(l0, l6);
            l5 = (l5 + INT64_C(1));
        }
    } else if (!(l1.tag == 1307u)) {
        if (l1.tag == 1319u) {
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
            l5 = INT64_C(0);
            while ((l5 < l4)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l6 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
                vader_comptime_walk_type(l0, l6);
                l5 = (l5 + INT64_C(1));
            }
        } else if (l1.tag == 1305u) {
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_types_ArrayType_t*) t0)->f_element;
            vader_comptime_walk_type(l0, l6);
        } else if (l1.tag == 1320u) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_types_TupleType_t*) t0)->f_elements;
            l4 = ((vader_array_t*) l2)->length;
            l5 = INT64_C(0);
            while ((l5 < l4)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
                vader_comptime_walk_type(l0, l6);
                l5 = (l5 + INT64_C(1));
            }
        } else if (l1.tag == 1323u) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_types_UnionType_t*) t0)->f_variants;
            l4 = ((vader_array_t*) l2)->length;
            l5 = INT64_C(0);
            while ((l5 < l4)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                l6 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l5);
                vader_comptime_walk_type(l0, l6);
                l5 = (l5 + INT64_C(1));
            }
        } else if (l1.tag == 1308u) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_types_FnType_t*) t0)->f_params;
            l4 = ((vader_array_t*) l2)->length;
            l5 = INT64_C(0);
            while ((l5 < l4)) {
                vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                l6 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l5);
                vader_comptime_walk_type(l0, l6);
                l5 = (l5 + INT64_C(1));
            }
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_types_FnType_t*) t0)->f_return_type;
            vader_comptime_walk_type(l0, l6);
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

int64_t vader_comptime_wrap_to_width(int64_t l0, vader_string_t l1) {
    void* l2;
    vader_box_t l3;
    int64_t l4, l5;
    int64_t t0;
    bool t1;
    l3 = vader_integer_machine_integer_named(l1);
    if (l3.tag == 0u) {
        return l0;
    }
    l2 = l3.payload.obj;
    t0 = ((vader_struct_vader_integer_MachineInteger_t*) l2)->f_bits;
    if (t0 == INT64_C(64)) {
        return l0;
    }
    t1 = ((vader_struct_vader_integer_MachineInteger_t*) l2)->f_is_signed;
    if (!(t1)) {
        l4 = ((vader_struct_vader_integer_MachineInteger_t*) l2)->f_bits;
        l5 = vader_chk_sub(i64, (INT64_C(1) << (l4 & 63)), INT64_C(1));
        return (l0 & l5);
    }
    l4 = ((vader_struct_vader_integer_MachineInteger_t*) l2)->f_bits;
    t0 = vader_comptime_sign_extend(l0, l4);
    return t0;
}
