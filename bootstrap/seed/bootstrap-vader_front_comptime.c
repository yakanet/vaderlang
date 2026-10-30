#include "bootstrap.split.h"

static void vader_front_comptime$add_dependency(void* l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_front_comptime$arg_error(void* l0, vader_string_t l1);
static void* vader_front_comptime$arithmetic(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
static void* vader_front_comptime$arithmetic_int(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static void* vader_front_comptime$arithmetic_or_concat(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
static uint8_t vader_front_comptime$assert_verdict(vader_box_t l0);
static int64_t vader_front_comptime$bit_not_i64(int64_t l0);
static void* vader_front_comptime$bool_equality_only(void* l0, bool l1, uint8_t l2);
static void* vader_front_comptime$bool_op(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static vader_box_t vader_front_comptime$bool_value(bool l0);
static vader_box_t vader_front_comptime$build_vm_required(void* l0, void* l1, void* l2, vader_string_t l3);
static void* vader_front_comptime$checked_int(void* l0, void* l1, void* l2, vader_string_t l3);
static vader_box_t vader_front_comptime$checked_int_op(uint8_t l0, int64_t l1, bool l2, int64_t l3, int64_t l4);
static void* vader_front_comptime$checked_result(void* l0, vader_box_t l1, vader_string_t l2);
static void* vader_front_comptime$collect_nodes(void* l0);
static void* vader_front_comptime$combine_binary(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
static void* vader_front_comptime$compare(void* l0, vader_box_t l1, vader_box_t l2, uint8_t l3);
static vader_box_t vader_front_comptime$context_declaring(void* l0, void* l1);
static vader_box_t vader_front_comptime$cycle_closed_by(void* l0, void* l1);
static vader_string_t vader_front_comptime$cycle_names(int64_t l0, void* l1, int64_t l2, void* l3);
static vader_box_t vader_front_comptime$declaring_context(vader_string_t l0, void* l1);
static void* vader_front_comptime$diag_sink(void);
static void* vader_front_comptime$display_enum(void* l0, vader_box_t l1, void* l2);
static vader_string_t vader_front_comptime$display_value(vader_box_t l0);
static void* vader_front_comptime$division_by_zero(void* l0, vader_string_t l1);
static void vader_front_comptime$emit_cycle(int64_t l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_front_comptime$evaluate_aggregate(vader_box_t l0, void* l1);
static void vader_front_comptime$evaluate_assert_decls(void* l0, void* l1, void* l2);
static void* vader_front_comptime$evaluate_binary_expr(void* l0, void* l1);
static void* vader_front_comptime$evaluate_bool_lit(void* l0);
static void* vader_front_comptime$evaluate_call_expr(void* l0, void* l1);
static void* vader_front_comptime$evaluate_char_lit(void* l0);
static void* vader_front_comptime$evaluate_dot_variant(void* l0, void* l1);
static void* vader_front_comptime$evaluate_expr(vader_box_t l0, void* l1);
static void vader_front_comptime$evaluate_extern_libraries(void* l0, void* l1, void* l2);
static void* vader_front_comptime$evaluate_field(void* l0, void* l1);
static void* vader_front_comptime$evaluate_float_lit(void* l0);
static void* vader_front_comptime$evaluate_fn_body(void* l0, void* l1, void* l2);
static void* vader_front_comptime$evaluate_ident(void* l0, void* l1);
static void* vader_front_comptime$evaluate_int_lit(void* l0, void* l1);
static void* vader_front_comptime$evaluate_intrinsic_call(void* l0, void* l1);
static vader_box_t vader_front_comptime$evaluate_library(void* l0, void* l1, void* l2);
static void* vader_front_comptime$evaluate_match(void* l0, void* l1);
static void vader_front_comptime$evaluate_module_decls(void* l0, void* l1, void* l2, void* l3, vader_string_t l4, void* l5);
static void* vader_front_comptime$evaluate_null_lit(void* l0);
static vader_box_t vader_front_comptime$evaluate_project_const(void* l0, void* l1, void* l2);
static void* vader_front_comptime$evaluate_seq_lit(void* l0, void* l1);
static void* vader_front_comptime$evaluate_string_lit(void* l0, void* l1);
static void* vader_front_comptime$evaluate_struct_lit(void* l0, void* l1);
static void* vader_front_comptime$evaluate_unary_expr(void* l0, void* l1);
static void* vader_front_comptime$evaluate_with_arguments(void* l0, void* l1, void* l2, void* l3, void* l4);
static void* vader_front_comptime$fail(void* l0);
static double vader_front_comptime$float_arith(uint8_t l0, double l1, double l2);
static bool vader_front_comptime$float_compare(double l0, double l1, uint8_t l2);
static vader_box_t vader_front_comptime$float_val(double l0);
static vader_string_t vader_front_comptime$folder_beside(vader_string_t l0, vader_string_t l1);
static bool vader_front_comptime$has_union_operand(void* l0, void* l1);
static int64_t vader_front_comptime$int_bits_of(vader_string_t l0);
static bool vader_front_comptime$int_compare(int64_t l0, int64_t l1, uint8_t l2);
static vader_string_t vader_front_comptime$int_digits(void* l0);
static void* vader_front_comptime$int_div_check(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3);
static void* vader_front_comptime$int_mod_check(void* l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_front_comptime$int_val(int64_t l0);
static vader_string_t vader_front_comptime$interp_value(vader_box_t l0);
static void* vader_front_comptime$intrinsic_align_of(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_field_count(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_field_index(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_integer_bound(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_satisfies(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_size_of(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_type_kind(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_type_name(void* l0, void* l1);
static void* vader_front_comptime$intrinsic_variant_count(void* l0, void* l1);
static bool vader_front_comptime$is_arithmetic(uint8_t l0);
static bool vader_front_comptime$is_resolved(vader_box_t l0);
static vader_box_t vader_front_comptime$lookup_module_decls(void* l0, vader_string_t l1);
static vader_box_t vader_front_comptime$mask_shift_amount(vader_box_t l0, vader_string_t l1);
static void* vader_front_comptime$new_evaluated_program(void* l0);
static void* vader_front_comptime$new_evaluated_project(void* l0);
static void* vader_front_comptime$normalize_int_result(void* l0, vader_string_t l1);
static bool vader_front_comptime$numbers_of_two_types(vader_box_t l0, vader_box_t l1);
static void* vader_front_comptime$ok(vader_box_t l0);
static int64_t vader_front_comptime$op_div(int64_t l0, int64_t l1);
static vader_box_t vader_front_comptime$pattern_holds(vader_box_t l0, vader_box_t l1);
static void vader_front_comptime$populate_deps(void* l0, void* l1);
static vader_string_t vader_front_comptime$render_array(void* l0);
static vader_string_t vader_front_comptime$render_struct(void* l0);
static vader_box_t vader_front_comptime$resolve_type_arg(vader_box_t l0, void* l1);
static vader_string_t vader_front_comptime$resolved_int_name(void* l0, int64_t l1);
static vader_box_t vader_front_comptime$resolved_library(vader_box_t l0, vader_string_t l1);
static vader_string_t vader_front_comptime$result_type_name(void* l0, vader_string_t l1);
static bool vader_front_comptime$runs_an_impl(void* l0, void* l1);
static bool vader_front_comptime$same_kind(vader_box_t l0, vader_box_t l1);
static bool vader_front_comptime$settles_alone(uint8_t l0, vader_box_t l1);
static int64_t vader_front_comptime$shift_amount_mask(vader_string_t l0);
static int64_t vader_front_comptime$sign_extend(int64_t l0, int64_t l1);
static void* vader_front_comptime$sort_comptime_decls(void* l0, void* l1);
static vader_box_t vader_front_comptime$string_field(void* l0, vader_string_t l1);
static vader_box_t vader_front_comptime$strings_field(void* l0, vader_string_t l1);
static void* vader_front_comptime$topo_sort(void* l0);
static int64_t vader_front_comptime$type_field_count(vader_box_t l0, void* l1);
static vader_box_t vader_front_comptime$type_from_expr_safe(void* l0, void* l1);
static void* vader_front_comptime$type_mismatch(void* l0, vader_string_t l1);
static vader_box_t vader_front_comptime$type_val(vader_box_t l0);
static int64_t vader_front_comptime$type_variant_count(vader_box_t l0);
static void* vader_front_comptime$unary_bit_not(void* l0, vader_box_t l1);
static void* vader_front_comptime$unary_neg(void* l0, vader_box_t l1, vader_string_t l2);
static void* vader_front_comptime$unary_not(void* l0, vader_box_t l1);
static void* vader_front_comptime$unary_type_mismatch(void* l0, vader_string_t l1);
static void* vader_front_comptime$variant_value(void* l0, vader_string_t l1, void* l2);
static void vader_front_comptime$visit(int64_t l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6);
static void* vader_front_comptime$vm_required(void* l0, vader_string_t l1);

static void vader_front_comptime$add_dependency(void* l0, void* l1, void* l2, void* l3, void* l4) {
    void* l5 = NULL;
    void* l9 = NULL;
    uint64_t l6;
    vader_box_t l7 = vader_box_null();
    int64_t l8;
    int32_t l10;
    bool t0;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &l9 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) l1)->f_resolved)->f_idents;
    l6 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) l0)->f_span);
    l7 = std_collections$MutableMap$std_core$Index$at__u64__Any(l5, l6);
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l7.payload.obj;
    if (((vader_struct_vader_core_symbol$Symbol_t*) l5)->f_kind != INT32_C(6)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l9 = ((vader_struct_vader_front_comptime$Nodes_t*) l2)->f_by_symbol;
    l10 = ((vader_struct_vader_core_symbol$Symbol_t*) l5)->f_id;
    l7 = std_collections$MutableMap$std_core$Index$at__i32__i64(l9, l10);
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l8 = ((int64_t) l7.payload.i);
    t0 = std_collections$add__i64(l3, l8);
    if (t0) {
        vader_array_push_i64((vader_array_t*) ((vader_struct_vader_front_comptime$NodeRecord_t*) l4)->f_dependency_ids, l8);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_comptime$arg_error(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_span;
    t0 = vader_support_diagnostics$comptime_error((uint8_t) 6, l2, l1);
    t1 = vader_front_comptime$fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$arithmetic(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3) {
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
    if (l1.tag == 1024u) {
        if (l2.tag == 1024u) {
            if (!(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(3))) {
                l7 = l1.payload.obj;
                l8 = l2.payload.obj;
                t0 = vader_front_comptime$checked_int(l0, l7, l8, l3);
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
            l4 = vader_front_comptime$op_div(l4, l5);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
            t1 = vader_front_comptime$int_val_typed(l4, l6);
            t0 = vader_front_comptime$ok(t1);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l1.tag == 1023u) {
        if (l2.tag == 1023u) {
            l9 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op;
            t0 = l1.payload.obj;
            l10 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l11 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
            l10 = vader_front_comptime$float_arith(l9, l10, l11);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_type_name;
            t1 = vader_front_comptime$float_val_typed(l10, l6);
            t0 = vader_front_comptime$ok(t1);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = 2424u;
        t0 = vader_front_comptime$type_mismatch(l0, l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = 2424u;
    t0 = vader_front_comptime$type_mismatch(l0, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$arithmetic_int(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
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
    if (l1.tag == 1024u) {
        if (l2.tag == 1024u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
            vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
            t1 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(339u, l4), vader_box_i64(339u, l5));
            l4 = ((int64_t) t1.payload.i);
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
            t1 = vader_front_comptime$int_val_typed(l4, l6);
            t0 = vader_front_comptime$ok(t1);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = 2425u;
        t0 = vader_front_comptime$type_mismatch(l0, l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = 2425u;
    t0 = vader_front_comptime$type_mismatch(l0, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$arithmetic_or_concat(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3) {
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
    if (!(l1.tag == 1029u)) {
        l6 = l1;
        t0 = vader_front_comptime$arithmetic(l0, l6, l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 1029u)) {
        t0 = vader_front_comptime$type_mismatch(l0, 2639u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    l4 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
    t0 = l2.payload.obj;
    l5 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
    t1 = concat_2(l4, l5);
    t2 = vader_front_comptime$string_val(t1);
    t0 = vader_front_comptime$ok(t2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint8_t vader_front_comptime$assert_verdict(vader_box_t l0) {
    void* t0;
    bool t1;
    if (!(l0.tag == 1015u)) {
        return (uint8_t) 2;
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
    if (!(t1)) {
        return (uint8_t) 1;
    }
    return (uint8_t) 0;
}

static int64_t vader_front_comptime$bit_not_i64(int64_t l0) {
    return (l0 ^ INT64_C(-1));
}

static void* vader_front_comptime$bool_equality_only(void* l0, bool l1, uint8_t l2) {
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2 == INT32_C(0)) {
        t0 = vader_front_comptime$bool_value(l1);
        t1 = vader_front_comptime$ok(t0);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2 == INT32_C(1))) {
        t1 = vader_front_comptime$type_mismatch(l0, 1377u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_comptime$bool_value(!(l1));
    t1 = vader_front_comptime$ok(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$bool_op(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
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
    if (l1.tag == 1015u) {
        if (l2.tag == 1015u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
            vader_fn_t* _a0_fnobj = (vader_fn_t*) l3;
            t1 = ((vader_fn_erased_sig_2_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_bool(333u, l4), vader_box_bool(333u, l5));
            t2 = t1.payload.b;
            if (!(t2)) {
                t0 = (void*) &vader_data_44;
                vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
                t3 = vader_front_comptime$ok(vader_ref_box(t0));
                { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            t0 = (void*) &vader_data_43;
            vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
            t3 = vader_front_comptime$ok(vader_ref_box(t0));
            { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = 2284u;
        t0 = vader_front_comptime$type_mismatch(l0, l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = 2284u;
    t0 = vader_front_comptime$type_mismatch(l0, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$bool_value(bool l0) {
    void* t0;
    if (!(l0)) {
        t0 = (void*) &vader_data_44;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        return vader_ref_box(t0);
    }
    t0 = (void*) &vader_data_43;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    return vader_ref_box(t0);
}

static vader_box_t vader_front_comptime$build_vm_required(void* l0, void* l1, void* l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null(), l7 = vader_box_null();
    void* l5 = NULL;
    int32_t l6;
    int64_t l8;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l4, &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_value;
    if (l4.tag == 636u) {
        t0 = l4.payload.obj;
        if (((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_callee.tag == 663u) {
            t0 = l4.payload.obj;
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_args)->length;
            if (t1 == INT64_C(0)) {
                l5 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l2)->f_decl_types;
                l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
                l7 = std_collections$MutableMap$std_core$Index$at__i32__Any(l5, l6);
                l5 = vader_front_typecheck$sites_of(((vader_struct_vader_front_typecheck$TypedProgram_t*) l2)->f_call_sites, (uint8_t) 0);
                t0 = l4.payload.obj;
                l8 = ((vader_struct_toolchain_ast$CallExpr_t*) t0)->f_id;
                l4 = std_collections$MutableMap$std_core$Index$at__i64__Any(l5, l8);
                if (!(l7.tag == 0u)) {
                    if (l4.tag == 1136u) {
                        l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
                        l9 = ((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_name;
                        t0 = l4.payload.obj;
                        l8 = ((vader_struct_toolchain_ast$FnDecl_t*) ((vader_struct_vader_front_typecheck$DirectFn_t*) t0)->f_decl)->f_id;
                        l4 = l7;
                        l5 = ((vader_struct_toolchain_ast$ConstDecl_t*) l0)->f_span;
                        vader_struct_vader_front_comptime$VmRequiredDecl_t* _a0_obj = (vader_struct_vader_front_comptime$VmRequiredDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$VmRequiredDecl_t));
                        vader_obj_header_init(_a0_obj, 1032u);
                        _a0_obj->f_symbol_id = l6;
                        _a0_obj->f_name = l9;
                        _a0_obj->f_module_id = l3;
                        _a0_obj->f_callee_decl_id = l8;
                        _a0_obj->f_decl_type = l4;
                        _a0_obj->f_span = l5;
                        t0 = (void*) _a0_obj;
                        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
                    }
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

int64_t vader_front_comptime$byte_align(vader_box_t l0) {
    int64_t t0;
    t0 = vader_core_types$slot_byte_align(l0);
    return t0;
}

int64_t vader_front_comptime$byte_size(vader_box_t l0) {
    int64_t t0;
    t0 = vader_core_types$slot_byte_size(l0);
    return t0;
}

static void* vader_front_comptime$checked_int(void* l0, void* l1, void* l2, vader_string_t l3) {
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
    l4 = vader_front_comptime$result_type_name(l1, l3);
    l5 = vader_front_comptime$int_bits_of(l4);
    l6 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op;
    l7 = vader_core_types$is_unsigned_int_name(l4);
    l8 = ((vader_struct_vader_front_comptime$IntValue_t*) l1)->f_value;
    l9 = ((vader_struct_vader_front_comptime$IntValue_t*) l2)->f_value;
    l10 = vader_front_comptime$checked_int_op(l6, l5, l7, l8, l9);
    t0 = vader_front_comptime$checked_result(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, l10, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$checked_int_op(uint8_t l0, int64_t l1, bool l2, int64_t l3, int64_t l4) {
    vader_box_t t0;
    if (l0 == INT32_C(0)) {
        t0 = vader_support_integer$checked_add(l1, l2, l3, l4);
        return t0;
    }
    if (!(l0 == INT32_C(1))) {
        t0 = vader_support_integer$checked_mul(l1, l2, l3, l4);
        return t0;
    }
    t0 = vader_support_integer$checked_sub(l1, l2, l3, l4);
    return t0;
}

static void* vader_front_comptime$checked_result(void* l0, vader_box_t l1, vader_string_t l2) {
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
        t1 = vader_front_comptime$int_val_typed(t0, l2);
        t2 = vader_front_comptime$ok(t1);
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = concat_3(2714u, l2, 1035u);
    t2 = vader_support_diagnostics$comptime_error((uint8_t) 9, l0, l3);
    t3 = vader_front_comptime$fail(t2);
    { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$collect_nodes(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(24u, 0u, 8u, 339u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i64__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__Any_t));
    vader_obj_header_init(_a3_obj, 514u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(24u, 0u, 8u, 339u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(24u, 0u, 8u, 339u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections$MutableMap__i32__i64_t* _a8_obj = (vader_struct_std_collections$MutableMap__i32__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i64_t));
    vader_obj_header_init(_a8_obj, 473u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a8_obj;
    vader_struct_vader_front_comptime$Nodes_t* _a9_obj = (vader_struct_vader_front_comptime$Nodes_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$Nodes_t));
    vader_obj_header_init(_a9_obj, 1026u);
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
        if (l8.tag == 639u) {
            t0 = l8.payload.obj;
            t1 = toolchain_ast$decorators_have(((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_decorators, 1773u);
            if (t1) {
                vader_array_t* _a11_arr = vader_array_new(24u, 0u, 8u, 339u);
                l3 = (void*) _a11_arr;
                l4 = ((vader_struct_vader_front_comptime$Nodes_t*) l1)->f_by_id;
                t0 = l8.payload.obj;
                l9 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_id;
                t0 = l8.payload.obj;
                vader_struct_vader_front_comptime$NodeRecord_t* _a12_obj = (vader_struct_vader_front_comptime$NodeRecord_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$NodeRecord_t));
                vader_obj_header_init(_a12_obj, 1025u);
                _a12_obj->f_decl = t0;
                _a12_obj->f_dependency_ids = l3;
                l5 = (void*) _a12_obj;
                std_collections$MutableMap$std_core$IndexSet$set_at__i64__Any(l4, l9, vader_ref_box(l5));
                l10 = ((vader_struct_vader_front_comptime$Nodes_t*) l1)->f_order;
                t0 = l8.payload.obj;
                l11 = ((vader_struct_toolchain_ast$ConstDecl_t*) t0)->f_id;
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

static void* vader_front_comptime$combine_binary(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3) {
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
    l4 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op;
    if (l4 == INT32_C(0)) {
        l5 = vader_front_comptime$arithmetic_or_concat(l0, l1, l2, l3);
        { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l4 == INT32_C(1)) {
        l5 = vader_front_comptime$arithmetic(l0, l1, l2, l3);
    } else if (l4 == INT32_C(2)) {
        l5 = vader_front_comptime$arithmetic(l0, l1, l2, l3);
    } else if (l4 == INT32_C(3)) {
        l5 = vader_front_comptime$int_div_check(l0, l1, l2, l3);
    } else if (l4 == INT32_C(4)) {
        l5 = vader_front_comptime$int_mod_check(l0, l1, l2);
    } else if (l4 == INT32_C(5)) {
        l6 = (void*) &vader_fn_static_vader_front_comptime$op_shl;
        l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
    } else if (l4 == INT32_C(6)) {
        l6 = (void*) &vader_fn_static_vader_front_comptime$op_shr;
        l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
    } else if (l4 == INT32_C(7)) {
        l6 = (void*) &vader_fn_static_vader_front_comptime$op_bit_and;
        l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
    } else if (l4 == INT32_C(8)) {
        l6 = (void*) &vader_fn_static_vader_front_comptime$op_bit_or;
        l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
    } else if (l4 == INT32_C(9)) {
        l6 = (void*) &vader_fn_static_vader_front_comptime$op_bit_xor;
        l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
    } else if (l4 == INT32_C(10)) {
        l6 = (void*) &vader_fn_static_vader_front_comptime$op_and;
        l5 = vader_front_comptime$bool_op(l0, l1, l2, l6);
    } else if (l4 == INT32_C(11)) {
        l6 = (void*) &vader_fn_static_vader_front_comptime$op_or;
        l5 = vader_front_comptime$bool_op(l0, l1, l2, l6);
    } else if (l4 == INT32_C(12)) {
        l5 = vader_front_comptime$compare(l0, l1, l2, (uint8_t) 0);
    } else if (l4 == INT32_C(13)) {
        l5 = vader_front_comptime$compare(l0, l1, l2, (uint8_t) 1);
    } else if (l4 == INT32_C(14)) {
        l5 = vader_front_comptime$compare(l0, l1, l2, (uint8_t) 2);
    } else if (l4 == INT32_C(15)) {
        l5 = vader_front_comptime$compare(l0, l1, l2, (uint8_t) 3);
    } else if (l4 == INT32_C(16)) {
        l5 = vader_front_comptime$compare(l0, l1, l2, (uint8_t) 4);
    } else if (l4 == INT32_C(17)) {
        l5 = vader_front_comptime$compare(l0, l1, l2, (uint8_t) 5);
    } else if (l4 == INT32_C(18)) {
        l5 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 588u);
    } else if (l4 == INT32_C(19)) {
        l5 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 587u);
    } else if (l4 == INT32_C(20)) {
        l5 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 589u);
    } else if (l4 == INT32_C(21)) {
        l5 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 591u);
    } else if (l4 == INT32_C(22)) {
        l5 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 590u);
    } else if (l4 == INT32_C(23)) {
        l6 = (void*) &vader_fn_static_vader_front_comptime$op_add;
        l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
    } else if (l4 == INT32_C(24)) {
        l6 = (void*) &vader_fn_static_vader_front_comptime$op_sub;
        l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
    } else {
        if (!(l4 == INT32_C(25))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l6 = (void*) &vader_fn_static_vader_front_comptime$op_mul;
        l5 = vader_front_comptime$arithmetic_int(l0, l1, l2, l6);
    }
    { void* __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$compare(void* l0, vader_box_t l1, vader_box_t l2, uint8_t l3) {
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
    if (l1.tag == 1024u) {
        if (l2.tag == 1024u) {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l5 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
            t1 = vader_front_comptime$int_compare(l4, l5, l3);
            t2 = vader_front_comptime$bool_value(t1);
            t0 = vader_front_comptime$ok(t2);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l1.tag == 1023u) {
        if (l2.tag == 1023u) {
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l7 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
            t1 = vader_front_comptime$float_compare(l6, l7, l3);
            t2 = vader_front_comptime$bool_value(t1);
            t0 = vader_front_comptime$ok(t2);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l1.tag == 1015u) {
        if (l2.tag == 1015u) {
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l9 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
            l8 = l8 == l9;
            t0 = vader_front_comptime$bool_equality_only(l0, l8, l3);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    } else if (l1.tag == 1029u) {
        if (l2.tag == 1029u) {
            t0 = l1.payload.obj;
            l10 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
            t0 = l2.payload.obj;
            l11 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
            t1 = vader_front_comptime$int_compare(((int64_t) (int32_t) vader_string_compare(l10, l11)), INT64_C(0), l3);
            t2 = vader_front_comptime$bool_value(t1);
            t0 = vader_front_comptime$ok(t2);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (!(l1.tag == 1013u)) {
        if (!(l1.tag == 1030u)) {
            l10 = 1769u;
            t0 = vader_front_comptime$type_mismatch(l0, l10);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t1 = vader_front_comptime$same_kind(l1, l2);
    if (t1) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 1768u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l10 = 1769u;
    t0 = vader_front_comptime$type_mismatch(l0, l10);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$context_declaring(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l6, l7;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_resolver$decl_symbol(((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_resolved, vader_ref_box(l0));
    if (!(t0.tag == 0u)) {
        { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_project;
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.obj;
    l2 = ((vader_struct_vader_front_typecheck$TypedProject_t*) ((vader_struct_vader_front_comptime$ProjectConstants_t*) l2)->f_typed)->f_modules;
    l4 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l2)->f_ekeys;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l2)->f_evals;
    l6 = INT64_C(0);
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l2)->f_size;
    while ((l6 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l6];
        l8 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l9 = l8;
        t0 = vader_front_resolver$decl_symbol(((vader_struct_vader_front_typecheck$TypedProgram_t*) l2)->f_resolved, vader_ref_box(l0));
        if (!(t0.tag == 0u)) {
            t0 = vader_front_comptime$declaring_context(l9, l1);
            { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_front_comptime$cycle_closed_by(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    int64_t l4, l5;
    bool l7;
    int32_t l8, l9;
    vader_string_t l10 = 0;
    int64_t t0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    l3 = l0;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l6 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t0 = ((vader_array_t*) l2)->length;
        if ((t0 > INT64_C(0))) {
            l7 = true;
        } else {
            l8 = ((vader_struct_vader_core_symbol$Symbol_t*) l6)->f_id;
            l9 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
            l7 = l8 == l9;
        }
        if (l7) {
            l10 = ((vader_struct_vader_core_symbol$Symbol_t*) l6)->f_name;
            vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l10));
        }
        l5 = (l5 + INT64_C(1));
    }
    t0 = ((vader_array_t*) l2)->length;
    if (!(t0 == INT64_C(0))) {
        l10 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_name;
        vader_array_push_scalar((vader_array_t*) l2, vader_box_string(335u, l10));
        { vader_box_t __vret = vader_ref_box(l2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_string_t vader_front_comptime$cycle_names(int64_t l0, void* l1, int64_t l2, void* l3) {
    void* l4 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int64_t l5, l6, l9;
    vader_box_t l10 = vader_box_null();
    vader_string_t l11 = 0;
    vader_string_t t0 = 0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[6] = { &l1, &l3, &l4, &l7, &l8, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l11, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l4 = (void*) _a0_arr;
    l5 = l0;
    l6 = ((vader_array_t*) l1)->length;
    while ((l5 < l6)) {
        l8 = ((vader_struct_vader_front_comptime$Nodes_t*) l3)->f_by_id;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        l9 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l5];
        l10 = std_collections$MutableMap$std_core$Index$at__i64__Any(l8, l9);
        if (l10.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l7 = l10.payload.obj;
        l11 = ((vader_struct_toolchain_ast$ConstDecl_t*) ((vader_struct_vader_front_comptime$NodeRecord_t*) l7)->f_decl)->f_name;
        vader_array_push_scalar((vader_array_t*) l4, vader_box_string(335u, l11));
        l5 = (l5 + INT64_C(1));
    }
    l10 = std_collections$MutableMap$std_core$Index$at__i64__Any(((vader_struct_vader_front_comptime$Nodes_t*) l3)->f_by_id, l2);
    if (l10.tag == 0u) {
        t0 = vader_front_comptime$display_cycle(l4);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l10.payload.obj;
    l11 = ((vader_struct_toolchain_ast$ConstDecl_t*) ((vader_struct_vader_front_comptime$NodeRecord_t*) t1)->f_decl)->f_name;
    vader_array_push_scalar((vader_array_t*) l4, vader_box_string(335u, l11));
    t0 = vader_front_comptime$display_cycle(l4);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$declaring_context(vader_string_t l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    vader_box_t l3 = vader_box_null();
    int64_t l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[7] = { &l1, &l2, &l4, &l5, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_project;
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.obj;
    l3 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_typecheck$TypedProject_t*) ((vader_struct_vader_front_comptime$ProjectConstants_t*) l2)->f_typed)->f_modules, l0);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.obj;
    l4 = l1;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 467u);
    _a3_obj->f_ekeys = l5;
    _a3_obj->f_evals = l6;
    _a3_obj->f_index = l7;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a3_obj;
    l8 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l4)->f_depth;
    l3 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l4)->f_project;
    vader_struct_vader_front_comptime$ComptimeContext_t* _a4_obj = (vader_struct_vader_front_comptime$ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ComptimeContext_t));
    vader_obj_header_init(_a4_obj, 1017u);
    _a4_obj->f_typed = l2;
    _a4_obj->f_bindings = l5;
    _a4_obj->f_depth = l8;
    _a4_obj->f_project = l3;
    t0 = (void*) _a4_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

uint8_t vader_front_comptime$dependency_step(vader_box_t l0, void* l1, void* l2, void* l3, void* l4) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[5] = { &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 663u) {
        t0 = l0.payload.obj;
        vader_front_comptime$add_dependency(t0, l1, l2, l3, l4);
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
}

static void* vader_front_comptime$diag_sink(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(216u, 0u, 13u, 1410u);
    t0 = (void*) _a0_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_front_comptime$display_cycle(void* l0) {
    vader_string_t t0;
    t0 = std_string$join(l0, 63u);
    return t0;
}

static void* vader_front_comptime$display_enum(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    int64_t l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[3] = { &l1, &l5, &l6 };
    void** gc_raw_roots[8] = { &l0, &l2, &l3, &l7, &l8, &l9, &l10, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_front_comptime$ComptimeContext_t*) l2)->f_project.tag == 0u) {
        t0 = vader_front_comptime$vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj), 1886u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_front_typecheck$sites_of(((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l2)->f_typed)->f_call_sites, (uint8_t) 7);
    l4 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_id, l1.payload.obj);
    l5 = std_collections$MutableMap$std_core$Index$at__i64__Any(l3, l4);
    if (!(l5.tag == 1136u)) {
        t0 = vader_front_comptime$vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj), 1891u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$EnumType_t*) ((vader_struct_vader_front_comptime$EnumValue_t*) l0)->f_enum_type)->f_symbol)->f_module;
    l6 = vader_front_comptime$declaring_context(t1, l2);
    if (l6.tag == 0u) {
        t0 = vader_front_comptime$vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj), 1887u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l6.payload.obj;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l8 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l9 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 467u);
    _a3_obj->f_ekeys = l7;
    _a3_obj->f_evals = l8;
    _a3_obj->f_index = l9;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a3_obj;
    t0 = l5.payload.obj;
    l8 = ((vader_struct_vader_front_typecheck$DirectFn_t*) t0)->f_decl;
    vader_array_t* _a4_arr = vader_array_new(258u, 1u, 13u, 1953u);
    ((void**) _a4_arr->buf->slots)[_a4_arr->offset + 0u] = l0;
    l9 = (void*) _a4_arr;
    l10 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj);
    l3 = vader_front_comptime$evaluate_with_arguments(l8, l9, l7, l3, l10);
    l5 = ((vader_struct_vader_front_comptime$EvalResult_t*) l3)->f_value;
    if (l5.tag == 0u) {
        { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l5.tag == 1029u)) {
        t0 = vader_front_comptime$vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l1.payload.obj), 1884u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_comptime$display_value(vader_box_t l0) {
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
    if (l0.tag == 1024u) {
        t0 = l0.payload.obj;
        l1 = vader_front_comptime$int_digits(t0);
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
        l1 = concat_3(l1, 976u, l2);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1023u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
        l2 = std_core$f64$Display$to_string(t1);
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_type_name;
        l1 = concat_3(l2, 976u, l3);
    } else if (l0.tag == 1015u) {
        l4 = (void*) vader_buffer_new((size_t) INT64_C(5));
        l5 = INT64_C(0);
        t0 = l0.payload.obj;
        l6 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
        l5 = std_core$write_bool(l4, l5, l6);
        l1 = std_core$finish_buffer(l4, l5);
    } else if (l0.tag == 1016u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_front_comptime$CharValue_t*) t0)->f_value;
        t3 = std_numbers$to_hex((uint64_t) (int64_t) ((int64_t) (uint32_t) t2));
        l2 = std_string$pad_start(t3, INT64_C(4), 48u);
        l1 = concat_3(304u, l2, 288u);
    } else if (l0.tag == 1029u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
        l1 = concat_3(249u, l2, 249u);
    } else if (l0.tag == 1027u) {
        l1 = 2408u;
    } else if (l0.tag == 1033u) {
        l1 = 3005u;
    } else if (l0.tag == 1013u) {
        t0 = l0.payload.obj;
        l1 = vader_front_comptime$render_array(t0);
    } else if (l0.tag == 1030u) {
        t0 = l0.payload.obj;
        l1 = vader_front_comptime$render_struct(t0);
    } else if (l0.tag == 1031u) {
        t0 = l0.payload.obj;
        l1 = vader_core_types$display_type(((vader_struct_vader_front_comptime$TypeValue_t*) t0)->f_value);
    } else {
        if (!(l0.tag == 1019u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$EnumType_t*) ((vader_struct_vader_front_comptime$EnumValue_t*) t0)->f_enum_type)->f_symbol)->f_name;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_front_comptime$EnumValue_t*) t0)->f_variant;
        l1 = concat_3(l2, 399u, l3);
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$division_by_zero(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span;
    t0 = vader_support_diagnostics$comptime_error((uint8_t) 3, l2, l1);
    t1 = vader_front_comptime$fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_comptime$emit_cycle(int64_t l0, void* l1, void* l2, void* l3, void* l4) {
    int64_t l5, l6, l7;
    vader_string_t l8 = 0;
    vader_box_t l9 = vader_box_null();
    void* l10 = NULL;
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l9 };
    void** gc_raw_roots[6] = { &l1, &l2, &l3, &l4, &l10, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_array_t*) l1)->length;
    l6 = l5;
    l7 = INT64_C(0);
    while ((l7 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l7];
        if (t0 == l0) {
            l6 = l7;
            break;
        }
        l7 = (l7 + INT64_C(1));
    }
    l8 = vader_front_comptime$cycle_names(l6, l1, l0, l2);
    l9 = std_collections$MutableMap$std_core$Index$at__i64__Any(((vader_struct_vader_front_comptime$Nodes_t*) l2)->f_by_id, l0);
    if (!(l9.tag == 0u)) {
        t1 = l9.payload.obj;
        l10 = ((vader_struct_toolchain_ast$ConstDecl_t*) ((vader_struct_vader_front_comptime$NodeRecord_t*) t1)->f_decl)->f_span;
        l10 = vader_support_diagnostics$comptime_error((uint8_t) 5, l10, l8);
        vader_array_push_ref((vader_array_t*) l4, l10);
    }
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l6];
        std_collections$add__i64(l3, l7);
        l6 = (l6 + INT64_C(1));
    }
    std_collections$add__i64(l3, l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_comptime$evaluate_aggregate(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    void* t0 = NULL;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[4] = { &l1, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_project.tag == 0u) {
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l0.payload.obj);
        l3 = vader_front_typecheck$expr_kind_name(l0);
        t0 = vader_front_comptime$vm_required(l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 703u) {
        t0 = l0.payload.obj;
        t1 = vader_front_comptime$evaluate_struct_lit(t0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 651u) {
        t0 = l0.payload.obj;
        t1 = vader_front_comptime$evaluate_dot_variant(t0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 656u) {
        t0 = l0.payload.obj;
        t1 = vader_front_comptime$evaluate_field(t0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 680u)) {
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l0.payload.obj);
        l3 = vader_front_typecheck$expr_kind_name(l0);
        t0 = vader_front_comptime$vm_required(l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t1 = vader_front_comptime$evaluate_match(t0, l1);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_comptime$evaluate_assert_decls(void* l0, void* l1, void* l2) {
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
    l3 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_typed;
    l4 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_comptime_decls;
    vader_struct_vader_front_comptime$ComptimeContext_t* _a0_obj = (vader_struct_vader_front_comptime$ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ComptimeContext_t));
    vader_obj_header_init(_a0_obj, 1017u);
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
        if (l7.tag == 628u) {
            t0 = l7.payload.obj;
            l8 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$AssertDecl_t*) t0)->f_condition, l3);
            l9 = ((vader_struct_vader_front_comptime$EvalResult_t*) l8)->f_diag;
            if (!(l9.tag == 0u)) {
                t0 = l9.payload.obj;
                t1 = ((vader_struct_vader_support_diagnostics$CodeInfo_t*) ((vader_struct_vader_support_diagnostics$Diagnostic_t*) t0)->f_code)->f_id;
                if (t1 != 597u) {
                    l10 = l9.payload.obj;
                    vader_array_push_ref((vader_array_t*) l2, l10);
                }
            }
            l11 = vader_front_comptime$assert_verdict(((vader_struct_vader_front_comptime$EvalResult_t*) l8)->f_value);
            if (l11 == INT32_C(1)) {
                t0 = l7.payload.obj;
                l12 = ((vader_struct_toolchain_ast$AssertDecl_t*) t0)->f_span;
                t0 = l7.payload.obj;
                l13 = ((vader_struct_toolchain_ast$AssertDecl_t*) t0)->f_message;
                if (l13.tag == 0u) {
                    l14 = 0u;
                } else {
                    l14 = l13.payload.s;
                }
                l15 = vader_support_diagnostics$comptime_error((uint8_t) 7, l12, l14);
                vader_array_push_ref((vader_array_t*) l2, l15);
            }
            l16 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l1)->f_asserts;
            t0 = l7.payload.obj;
            vader_struct_vader_front_comptime$AssertCheck_t* _a2_obj = (vader_struct_vader_front_comptime$AssertCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$AssertCheck_t));
            vader_obj_header_init(_a2_obj, 1014u);
            _a2_obj->f_span = ((vader_struct_toolchain_ast$AssertDecl_t*) t0)->f_span;
            _a2_obj->f_verdict = l11;
            l17 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l16, l17);
        }
        l6 = (l6 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_comptime$evaluate_binary_expr(void* l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l7 = vader_box_null();
    int64_t l5;
    vader_string_t l6 = 0;
    bool l8, l9;
    bool t0;
    void* t1 = NULL;
    void* t2 = NULL;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l3, &l4, &l7, &t3 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &t1, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_front_comptime$runs_an_impl(l0, l1);
    if (t0) {
        t1 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 2432u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_left, l1);
    l3 = ((vader_struct_vader_front_comptime$EvalResult_t*) l2)->f_value;
    if (l3.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_comptime$settles_alone(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op, l3);
    if (t0) {
        t1 = l3.payload.obj;
        t2 = vader_front_comptime$ok(vader_ref_box(t1));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_right, l1);
    l4 = ((vader_struct_vader_front_comptime$EvalResult_t*) l2)->f_value;
    if (l4.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_id;
    l6 = vader_front_comptime$resolved_int_name(l1, l5);
    if (((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(5)) {
        l8 = true;
    } else {
        l8 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(6);
    }
    if (l8) {
        l7 = vader_front_comptime$mask_shift_amount(l4, l6);
    } else {
        l7 = l4;
    }
    if (((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(12)) {
        l8 = true;
    } else {
        l8 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(13);
    }
    if (l8) {
        l8 = vader_front_comptime$has_union_operand(l1, l0);
        if (l8) {
            t0 = vader_front_comptime$numbers_of_two_types(l3, l7);
            if (t0) {
                t1 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span, 2410u);
                { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
        t0 = vader_front_comptime$same_kind(l3, l7);
        l9 = !(t0);
        {
            if (!(l9)) {
                if (!(l3.tag == 1027u)) {
                    goto end_103;
                }
            }
            if (l8) {
                l8 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op == INT32_C(13);
                t3 = vader_front_comptime$bool_value(l9 == l8);
                t1 = vader_front_comptime$ok(t3);
                { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
        } end_103: ;
    }
    t1 = vader_front_comptime$combine_binary(l0, l3, l7, l6);
    t2 = vader_front_comptime$normalize_int_result(t1, l6);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_bool_lit(void* l0) {
    bool t0;
    void* t1 = NULL;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l0, &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast$BoolLitExpr_t*) l0)->f_value;
    if (!(t0)) {
        t1 = (void*) &vader_data_44;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        t2 = vader_front_comptime$ok(vader_ref_box(t1));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = (void*) &vader_data_43;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    t2 = vader_front_comptime$ok(vader_ref_box(t1));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_call_expr(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    vader_box_t l4 = vader_box_null(), l14 = vader_box_null();
    int64_t l5, l9;
    vader_string_t l6 = 0;
    int32_t l12, l13;
    void* t0 = NULL;
    void* t5 = NULL;
    vader_box_t t1 = vader_box_null();
    int64_t t2;
    vader_string_t t3 = 0;
    bool t4;
    vader_box_t* gc_roots[3] = { &l4, &l14, &t1 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l7, &l8, &l10, &l11, &t0, &t5 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_callee.tag == 663u)) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span, 618u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_callee;
    l2 = t1.payload.obj;
    t2 = ((vader_array_t*) ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_args)->length;
    if (t2 == INT64_C(1)) {
        t3 = ((vader_struct_toolchain_ast$IdentExpr_t*) l2)->f_name;
        t4 = vader_core_types$is_int_name(t3);
        if (t4) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_args);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
            t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
            l3 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$CallArg_t*) t0)->f_value, l1);
            l4 = ((vader_struct_vader_front_comptime$EvalResult_t*) l3)->f_value;
            if (l4.tag == 0u) {
                { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            if (l4.tag == 1024u) {
                t0 = l4.payload.obj;
                l5 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
                l6 = ((vader_struct_toolchain_ast$IdentExpr_t*) l2)->f_name;
                l5 = vader_front_comptime$wrap_to_width(l5, l6);
                l6 = ((vader_struct_toolchain_ast$IdentExpr_t*) l2)->f_name;
                vader_struct_vader_front_comptime$IntValue_t* _a1_obj = (vader_struct_vader_front_comptime$IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$IntValue_t));
                vader_obj_header_init(_a1_obj, 1024u);
                _a1_obj->f_value = l5;
                _a1_obj->f_type_name = l6;
                t0 = (void*) _a1_obj;
                t5 = vader_front_comptime$ok(vader_ref_box(t0));
                { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    l3 = vader_front_typecheck$sites_of(((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_call_sites, (uint8_t) 0);
    l5 = ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_id;
    l4 = std_collections$MutableMap$std_core$Index$at__i64__Any(l3, l5);
    if (!(l4.tag == 1136u)) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span, 615u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l4.payload.obj;
    if (!(((vader_struct_vader_front_typecheck$DirectFn_t*) t0)->f_bindings.tag == 0u)) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span, 617u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l4.payload.obj;
    l3 = ((vader_struct_vader_front_typecheck$DirectFn_t*) t0)->f_decl;
    l4 = vader_front_comptime$context_declaring(l3, l1);
    if (l4.tag == 0u) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span, 616u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = l4.payload.obj;
    t4 = toolchain_ast$decorators_have(((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_decorators, 2555u);
    if (t4) {
        l8 = ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span;
        l6 = ((vader_struct_toolchain_ast$IdentExpr_t*) l2)->f_name;
        l6 = concat_3(1035u, l6, 1035u);
        t0 = vader_support_diagnostics$comptime_error((uint8_t) 10, l8, l6);
        t5 = vader_front_comptime$fail(t0);
        { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l3)->f_params)->length;
    l9 = ((vader_array_t*) ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_args)->length;
    if (l5 != l9) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span, 611u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l2 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(29u, 0u, 0u, 346u);
    l8 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(23u, 0u, 7u, 338u);
    l10 = (void*) _a4_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a5_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a5_obj, 467u);
    _a5_obj->f_ekeys = l2;
    _a5_obj->f_evals = l8;
    _a5_obj->f_index = l10;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a5_obj;
    l8 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_bindings;
    l10 = ((vader_struct_std_collections$MutableMap__i32__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l8)->f_ekeys;
    l11 = ((vader_struct_std_collections$MutableMap__i32__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l8)->f_evals;
    l5 = INT64_C(0);
    l9 = ((vader_struct_std_collections$MutableMap__i32__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue_t*) l8)->f_size;
    while ((l5 < l9)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        l12 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l5];
        vader_array_t* _a7_slotarr = ((vader_array_t*) l11);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l5)
        l4 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l5);
        l13 = l12;
        l14 = l4;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l2, l13, l14);
        l5 = (l5 + INT64_C(1));
    }
    vader_array_t* _a8_arr = vader_array_new(258u, 0u, 13u, 1953u);
    l8 = (void*) _a8_arr;
    l10 = ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_args;
    l5 = ((vader_array_t*) l10)->length;
    l9 = INT64_C(0);
    while ((l9 < l5)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l10);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l9)
        t0 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l9);
        l11 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$CallArg_t*) t0)->f_value, l1);
        l14 = ((vader_struct_vader_front_comptime$EvalResult_t*) l11)->f_value;
        if (l14.tag == 0u) {
            { void* __vret = l11; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l4 = l14;
        vader_array_push_ref((vader_array_t*) l8, l4.payload.obj);
        l9 = (l9 + INT64_C(1));
    }
    l10 = ((vader_struct_toolchain_ast$CallExpr_t*) l0)->f_span;
    t0 = vader_front_comptime$evaluate_with_arguments(l3, l8, l2, l7, l10);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_char_lit(void* l0) {
    uint32_t t0;
    void* t1 = NULL;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l0, &t1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast$CharLitExpr_t*) l0)->f_value;
    vader_struct_vader_front_comptime$CharValue_t* _a0_obj = (vader_struct_vader_front_comptime$CharValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$CharValue_t));
    vader_obj_header_init(_a0_obj, 1016u);
    _a0_obj->f_value = t0;
    t1 = (void*) _a0_obj;
    t2 = vader_front_comptime$ok(vader_ref_box(t1));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_dot_variant(void* l0, void* l1) {
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
    l3 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_expr_types;
    l4 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) l0)->f_id;
    l2 = std_collections$MutableMap$std_core$Index$at__i64__Any(l3, l4);
    if (l2.tag == 0u) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$DotVariantExpr_t*) l0)->f_span, 1889u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 906u)) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$DotVariantExpr_t*) l0)->f_span, 2996u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l2.payload.obj;
    l5 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) l0)->f_variant;
    l6 = ((vader_struct_toolchain_ast$DotVariantExpr_t*) l0)->f_span;
    t0 = vader_front_comptime$variant_value(l3, l5, l6);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_expr(vader_box_t l0, void* l1) {
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
    t0 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_depth;
    if ((t0 >= INT64_C(2000))) {
        l2 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l0.payload.obj);
        l3 = (void*) vader_buffer_new((size_t) INT64_C(93));
        l4 = INT64_C(0);
        l4 = std_core$write_string_at(l3, l4, 1440u);
        l4 = std_core$write_int(l3, l4, INT64_C(2000));
        l4 = std_core$write_string_at(l3, l4, 180u);
        l5 = std_core$finish_buffer(l3, l4);
        t1 = vader_front_comptime$vm_required(l2, l5);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_into_coercions;
    l4 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_id, l0.payload.obj);
    t2 = std_collections$MutableMap$std_core$Index$at__i64__Any(l2, l4);
    if (!(t2.tag == 0u)) {
        t1 = vader_front_comptime$vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l0.payload.obj), 1493u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_depth;
    l4 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_depth = l4;
    if (l0.tag == 673u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_int_lit(t1, l1);
    } else if (l0.tag == 657u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_float_lit(t1);
    } else if (l0.tag == 633u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_bool_lit(t1);
    } else if (l0.tag == 638u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_char_lit(t1);
    } else if (l0.tag == 685u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_null_lit(t1);
    } else if (l0.tag == 698u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_string_lit(t1, l1);
    } else if (l0.tag == 663u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_ident(t1, l1);
    } else if (l0.tag == 631u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_binary_expr(t1, l1);
    } else if (l0.tag == 712u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_unary_expr(t1, l1);
    } else if (l0.tag == 674u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_intrinsic_call(t1, l1);
    } else if (l0.tag == 636u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_call_expr(t1, l1);
    } else if (l0.tag == 696u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_seq_lit(t1, l1);
    } else if (l0.tag == 703u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_aggregate(vader_ref_box(t1), l1);
    } else if (l0.tag == 651u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_aggregate(vader_ref_box(t1), l1);
    } else if (l0.tag == 656u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_aggregate(vader_ref_box(t1), l1);
    } else if (l0.tag == 680u) {
        t1 = l0.payload.obj;
        l2 = vader_front_comptime$evaluate_aggregate(vader_ref_box(t1), l1);
    } else {
        l3 = VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, l0.payload.obj);
        l5 = vader_front_typecheck$expr_kind_name(l0);
        l2 = vader_front_comptime$vm_required(l3, l5);
    }
    t0 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_depth;
    l4 = vader_chk_sub(i64, t0, INT64_C(1));
    ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_depth = l4;
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_comptime$evaluate_extern_libraries(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l16 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l29 = NULL;
    int64_t l9, l10, l13, l14, l15, l17;
    int32_t l19, l23, l25, l26;
    vader_box_t l20 = vader_box_null(), l24 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    bool t3;
    vader_box_t* gc_roots[3] = { &l20, &l24, &t1 };
    void** gc_raw_roots[19] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l11, &l12, &l16, &l18, &l21, &l22, &l27, &l28,
        &l29, &t0,
    };
    vader_string_t* gc_atom_roots[1] = { &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 467u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(69u, 0u, 13u, 900u);
    l4 = (void*) _a4_arr;
    vader_struct_vader_front_comptime$ProjectConstants_t* _a5_obj = (vader_struct_vader_front_comptime$ProjectConstants_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ProjectConstants_t));
    vader_obj_header_init(_a5_obj, 1028u);
    _a5_obj->f_typed = l0;
    _a5_obj->f_values = l3;
    _a5_obj->f_evaluating = l4;
    l3 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 7u, 338u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(29u, 0u, 0u, 346u);
    l5 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a8_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a9_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a9_obj, 467u);
    _a9_obj->f_ekeys = l4;
    _a9_obj->f_evals = l5;
    _a9_obj->f_index = l6;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_grow_at = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(20u, 0u, 12u, 333u);
    l6 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a12_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a13_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a13_obj, 470u);
    _a13_obj->f_ekeys = l5;
    _a13_obj->f_evals = l6;
    _a13_obj->f_index = l7;
    _a13_obj->f_mask = INT64_C(0);
    _a13_obj->f_grow_at = INT64_C(0);
    _a13_obj->f_size = INT64_C(0);
    _a13_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a13_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a14_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a14_obj, 613u);
    _a14_obj->f_inner = t0;
    l5 = (void*) _a14_obj;
    l6 = ((vader_struct_vader_front_typecheck$TypedProject_t*) l0)->f_modules;
    l7 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l6)->f_ekeys;
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l6)->f_evals;
    l9 = INT64_C(0);
    l10 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l6)->f_size;
    while ((l9 < l10)) {
        vader_array_t* _a15_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l9)
        t1 = vader_array_box_slots(_a15_slotarr->buf)[_a15_slotarr->offset + (size_t) l9];
        t2 = t1.payload.s;
        vader_array_t* _a16_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a16_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a16_slotarr, l9)
        t0 = vader_array_ref_load_obj(_a16_slotarr->buf, _a16_slotarr->offset + (size_t) l9);
        l6 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) t0)->f_extern_libraries;
        l11 = ((vader_struct_std_collections$MutableMap__i64__vader_core_symbol_Symbol_t*) l6)->f_ekeys;
        l12 = ((vader_struct_std_collections$MutableMap__i64__vader_core_symbol_Symbol_t*) l6)->f_evals;
        l13 = INT64_C(0);
        l14 = ((vader_struct_std_collections$MutableMap__i64__vader_core_symbol_Symbol_t*) l6)->f_size;
        while ((l13 < l14)) {
            vader_array_t* _a17_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a17_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a17_slotarr, l13)
            l15 = ((int64_t*) _a17_slotarr->buf->slots)[_a17_slotarr->offset + (size_t) l13];
            vader_array_t* _a18_slotarr = ((vader_array_t*) l12);
            VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a18_slotarr, l13)
            l16 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l13);
            l17 = l15;
            l18 = l16;
            l19 = ((vader_struct_vader_core_symbol$Symbol_t*) l18)->f_id;
            l20 = std_collections$MutableMap$std_core$Index$at__i32__Any(l4, l19);
            if (l20.tag == 0u) {
                l23 = ((vader_struct_vader_core_symbol$Symbol_t*) l18)->f_id;
                t3 = std_collections$MutableSet$std_core$Contains$contains__i32(l5, l23);
                if (!(t3)) {
                    l24 = vader_front_comptime$evaluate_library(l18, l3, l2);
                    if (l24.tag == 0u) {
                        l25 = ((vader_struct_vader_core_symbol$Symbol_t*) l18)->f_id;
                        std_collections$add__i32(l5, l25);
                    } else {
                        l26 = ((vader_struct_vader_core_symbol$Symbol_t*) l18)->f_id;
                        l27 = l24.payload.obj;
                        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l4, l26, vader_ref_box(l27));
                        l28 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l1)->f_libraries;
                        l29 = l24.payload.obj;
                        std_collections$MutableMap$std_core$IndexSet$set_at__i64__Any(l28, l17, vader_ref_box(l29));
                    }
                }
            } else {
                l21 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l1)->f_libraries;
                l22 = l20.payload.obj;
                std_collections$MutableMap$std_core$IndexSet$set_at__i64__Any(l21, l17, vader_ref_box(l22));
            }
            l13 = (l13 + INT64_C(1));
        }
        l9 = (l9 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_comptime$evaluate_field(void* l0, void* l1) {
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
    l2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_target, l1);
    l3 = ((vader_struct_vader_front_comptime$EvalResult_t*) l2)->f_value;
    if (l3.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l3.tag == 1031u) {
        t0 = l3.payload.obj;
        if (!(((vader_struct_vader_front_comptime$TypeValue_t*) t0)->f_value.tag == 906u)) {
            t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_span, 1986u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l3.payload.obj;
        t1 = ((vader_struct_vader_front_comptime$TypeValue_t*) t0)->f_value;
        l2 = t1.payload.obj;
        l4 = ((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_field;
        l5 = ((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_span;
        t0 = vader_front_comptime$variant_value(l2, l4, l5);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l3.tag == 1030u)) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_span, 1987u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l3.payload.obj;
    l2 = ((vader_struct_vader_front_comptime$StructValue_t*) t0)->f_fields;
    l4 = ((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_field;
    l3 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l4);
    if (l3.tag == 0u) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$FieldExpr_t*) l0)->f_span, 2816u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_comptime$ok(l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_float_lit(void* l0) {
    double t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[2] = { &l0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_toolchain_ast$FloatLitExpr_t*) l0)->f_value;
    t1 = vader_front_comptime$float_val(t0);
    t2 = vader_front_comptime$ok(t1);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_fn_body(void* l0, void* l1, void* l2) {
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
    l4 = ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_body;
    if (l4.tag == 0u) {
        t0 = vader_front_comptime$vm_required(l2, 614u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l4.payload.obj;
    l4 = ((vader_struct_toolchain_ast$BlockExpr_t*) l3)->f_trailing;
    if (l4.tag == 0u) {
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l3)->f_stmts)->length;
        if (t1 == INT64_C(1)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l3)->f_stmts);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
            l5 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
            if (l5.tag == 695u) {
                t0 = l5.payload.obj;
                if (!(((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value.tag == 0u)) {
                    t0 = l5.payload.obj;
                    t2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$ReturnStmt_t*) t0)->f_value, l1);
                    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            l6 = 613u;
            t0 = vader_front_comptime$vm_required(l2, l6);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l6 = 613u;
        t0 = vader_front_comptime$vm_required(l2, l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_array_t*) ((vader_struct_toolchain_ast$BlockExpr_t*) l3)->f_stmts)->length;
    if (!(t1 == INT64_C(0))) {
        t0 = vader_front_comptime$vm_required(l2, 612u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_comptime$evaluate_expr(l4, l1);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_ident(void* l0, void* l1) {
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
    l2 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_resolved)->f_idents;
    l3 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$IdentExpr_t*) l0)->f_span);
    l4 = std_collections$MutableMap$std_core$Index$at__u64__Any(l2, l3);
    if (l4.tag == 0u) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$IdentExpr_t*) l0)->f_span, 679u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_bindings;
    t0 = l4.payload.obj;
    l5 = ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_id;
    l6 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l5);
    if (!(l6.tag == 0u)) {
        t0 = vader_front_comptime$ok(l6);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l4.payload.obj;
    l7 = ((vader_struct_toolchain_ast$IdentExpr_t*) l0)->f_span;
    l6 = vader_front_comptime$evaluate_project_const(l2, l1, l7);
    if (!(l6.tag == 0u)) {
        t0 = l6.payload.obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l6 = vader_front_comptime$type_from_expr_safe(l0, l1);
    if (!(l6.tag == 0u)) {
        t1 = vader_front_comptime$type_val(l6);
        t0 = vader_front_comptime$ok(t1);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_toolchain_ast$IdentExpr_t*) l0)->f_span;
    l7 = (void*) &vader_data_45;
    t0 = l4.payload.obj;
    l8 = ((int64_t) (uint8_t) ((vader_struct_vader_core_symbol$Symbol_t*) t0)->f_kind);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
    l9 = ((vader_struct_vader_core_symbol$SymbolKindInfo_t*) t0)->f_label;
    l9 = concat_3(678u, l9, 323u);
    t0 = vader_front_comptime$vm_required(l2, l9);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_int_lit(void* l0, void* l1) {
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
    t0 = toolchain_ast$int_literal_value(l0);
    t1 = vader_front_comptime$int_val(t0);
    l2 = vader_front_comptime$ok(t1);
    l3 = ((vader_struct_toolchain_ast$IntLitExpr_t*) l0)->f_id;
    l4 = vader_front_comptime$resolved_int_name(l1, l3);
    t2 = vader_front_comptime$normalize_int_result(l2, l4);
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_intrinsic_call(void* l0, void* l1) {
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
    t0 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2557u) {
        t1 = vader_front_comptime$intrinsic_size_of(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1511u) {
        t1 = vader_front_comptime$intrinsic_align_of(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2761u) {
        t1 = vader_front_comptime$intrinsic_type_name(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2759u) {
        t1 = vader_front_comptime$intrinsic_type_kind(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1989u) {
        t1 = vader_front_comptime$intrinsic_field_count(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2998u) {
        t1 = vader_front_comptime$intrinsic_variant_count(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 1991u) {
        t1 = vader_front_comptime$intrinsic_field_index(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2533u) {
        t1 = vader_front_comptime$intrinsic_satisfies(l0, l1);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
    if (t0 == 2338u) {
        l2 = true;
    } else {
        t0 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
        l2 = t0 == 2314u;
    }
    if (!(l2)) {
        l3 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_span;
        l4 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
        l4 = concat_2(531u, l4);
        t1 = vader_front_comptime$vm_required(l3, l4);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_comptime$intrinsic_integer_bound(l0, l1);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$evaluate_library(void* l0, void* l1, void* l2) {
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
    l3 = ((vader_struct_vader_front_typecheck$TypedProject_t*) ((vader_struct_vader_front_comptime$ProjectConstants_t*) l1)->f_typed)->f_modules;
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module;
    l5 = std_collections$MutableMap$std_core$Index$at__string__Any(l3, l4);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l5.payload.obj;
    l6 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l3)->f_const_decls;
    l7 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    l5 = std_collections$MutableMap$std_core$Index$at__i32__Any(l6, l7);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l6 = l5.payload.obj;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l8 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l9 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l10 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 467u);
    _a3_obj->f_ekeys = l8;
    _a3_obj->f_evals = l9;
    _a3_obj->f_index = l10;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l8 = (void*) _a3_obj;
    vader_struct_vader_front_comptime$ComptimeContext_t* _a4_obj = (vader_struct_vader_front_comptime$ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ComptimeContext_t));
    vader_obj_header_init(_a4_obj, 1017u);
    _a4_obj->f_typed = l3;
    _a4_obj->f_bindings = l8;
    _a4_obj->f_depth = INT64_C(0);
    _a4_obj->f_project = vader_ref_box(l1);
    l3 = (void*) _a4_obj;
    l8 = ((vader_struct_toolchain_ast$ConstDecl_t*) l6)->f_span;
    l5 = vader_front_comptime$evaluate_project_const(l0, l3, l8);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l5.payload.obj;
    l5 = ((vader_struct_vader_front_comptime$EvalResult_t*) l3)->f_value;
    if (l5.tag == 0u) {
        if (((vader_struct_vader_front_comptime$EvalResult_t*) l3)->f_diag.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t0 = ((vader_struct_vader_front_comptime$EvalResult_t*) l3)->f_diag;
        l3 = t0.payload.obj;
        vader_array_push_ref((vader_array_t*) l2, l3);
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module;
    l5 = vader_front_comptime$resolved_library(l5, l4);
    if (l5.tag == 0u) {
        l4 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
        l4 = concat_3(1035u, l4, 1122u);
        l3 = ((vader_struct_toolchain_ast$ConstDecl_t*) l6)->f_span;
        l3 = vader_support_diagnostics$comptime_error((uint8_t) 0, l3, l4);
        vader_array_push_ref((vader_array_t*) l2, l3);
        { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_match(void* l0, void* l1) {
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
    if (!(((vader_struct_toolchain_ast$MatchExpr_t*) l0)->f_binding.tag == 0u)) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$MatchExpr_t*) l0)->f_span, 2309u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$MatchExpr_t*) l0)->f_scrutinee, l1);
    l3 = ((vader_struct_vader_front_comptime$EvalResult_t*) l2)->f_value;
    if (l3.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_toolchain_ast$MatchExpr_t*) l0)->f_arms;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (!(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_guard.tag == 0u)) {
            t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_span, 2308u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = vader_front_comptime$pattern_holds(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_pattern, l3);
        if (l7.tag == 0u) {
            t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_span, 2311u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t1 = l7.payload.b;
        if (t1) {
            t0 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$MatchArm_t*) l6)->f_body, l1);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = (l5 + INT64_C(1));
    }
    t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$MatchExpr_t*) l0)->f_span, 2312u);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_comptime$evaluate_module_decls(void* l0, void* l1, void* l2, void* l3, vader_string_t l4, void* l5) {
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
    l6 = vader_front_comptime$sort_comptime_decls(l0, l1);
    l7 = ((vader_struct_vader_front_comptime$ComptimeOrder_t*) l6)->f_cycle_diags;
    l8 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l10 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        vader_array_push_ref((vader_array_t*) l5, l10);
        l9 = (l9 + INT64_C(1));
    }
    l7 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l2)->f_comptime_decls;
    vader_struct_vader_front_comptime$ComptimeContext_t* _a1_obj = (vader_struct_vader_front_comptime$ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ComptimeContext_t));
    vader_obj_header_init(_a1_obj, 1017u);
    _a1_obj->f_typed = l1;
    _a1_obj->f_bindings = l7;
    _a1_obj->f_depth = INT64_C(0);
    _a1_obj->f_project = vader_box_obj(0u, NULL);
    l7 = (void*) _a1_obj;
    l6 = ((vader_struct_vader_front_comptime$ComptimeOrder_t*) l6)->f_order;
    l8 = ((vader_array_t*) l6)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
        l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
        l11 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$ConstDecl_t*) l10)->f_value, l7);
        t0 = ((vader_struct_vader_front_comptime$EvalResult_t*) l11)->f_vm_required;
        if (t0) {
            l12 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l1)->f_resolved;
            l13 = ((vader_struct_toolchain_ast$ConstDecl_t*) l10)->f_name_span;
            l14 = vader_front_resolver$symbol_declared_at(l12, l13);
            if (!(l14.tag == 0u)) {
                l15 = l14.payload.obj;
                l16 = vader_front_comptime$build_vm_required(l10, l15, l1, l4);
                if (l16.tag == 1032u) {
                    l17 = ((vader_struct_vader_front_comptime$EvaluatedProject_t*) l3)->f_vm_required;
                    l18 = l16.payload.obj;
                    vader_array_push_ref((vader_array_t*) l17, l18);
                    l9 = (l9 + INT64_C(1));
                    continue;
                }
            }
            if (!(((vader_struct_vader_front_comptime$EvalResult_t*) l11)->f_diag.tag == 0u)) {
                t1 = ((vader_struct_vader_front_comptime$EvalResult_t*) l11)->f_diag;
                l19 = t1.payload.obj;
                vader_array_push_ref((vader_array_t*) l5, l19);
            }
            l9 = (l9 + INT64_C(1));
            continue;
        }
        l20 = ((vader_struct_vader_front_comptime$EvalResult_t*) l11)->f_value;
        if (!(l20.tag == 0u)) {
            l21 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l1)->f_resolved;
            l22 = ((vader_struct_toolchain_ast$ConstDecl_t*) l10)->f_name_span;
            l23 = vader_front_resolver$symbol_declared_at(l21, l22);
            if (!(l23.tag == 0u)) {
                l24 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l2)->f_comptime_decls;
                t2 = l23.payload.obj;
                l25 = ((vader_struct_vader_core_symbol$Symbol_t*) t2)->f_id;
                l26 = l20;
                std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l24, l25, l26);
                l27 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l2)->f_routes;
                t2 = l23.payload.obj;
                l28 = ((vader_struct_vader_core_symbol$Symbol_t*) t2)->f_id;
                std_collections$MutableMap$std_core$IndexSet$set_at__i32__vader_front_comptime_ComptimeRoute(l27, l28, (uint8_t) 0);
            }
        }
        if (!(((vader_struct_vader_front_comptime$EvalResult_t*) l11)->f_diag.tag == 0u)) {
            t1 = ((vader_struct_vader_front_comptime$EvalResult_t*) l11)->f_diag;
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
        if (l14.tag == 639u) {
            t2 = l14.payload.obj;
            t0 = toolchain_ast$decorators_have(((vader_struct_toolchain_ast$ConstDecl_t*) t2)->f_decorators, 1773u);
            if (t0) {
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l11 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l1)->f_resolved;
            t2 = l14.payload.obj;
            l12 = ((vader_struct_toolchain_ast$ConstDecl_t*) t2)->f_name_span;
            l16 = vader_front_resolver$symbol_declared_at(l11, l12);
            if (l16.tag == 0u) {
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l10 = l16.payload.obj;
            l13 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l2)->f_comptime_decls;
            l25 = ((vader_struct_vader_core_symbol$Symbol_t*) l10)->f_id;
            t1 = std_collections$MutableMap$std_core$Index$at__i32__Any(l13, l25);
            if (t1.tag == 0u) {
                t2 = l14.payload.obj;
                l15 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$ConstDecl_t*) t2)->f_value, l7);
                if (!(((vader_struct_vader_front_comptime$EvalResult_t*) l15)->f_value.tag == 0u)) {
                    l17 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l2)->f_comptime_decls;
                    l28 = ((vader_struct_vader_core_symbol$Symbol_t*) l10)->f_id;
                    l20 = ((vader_struct_vader_front_comptime$EvalResult_t*) l15)->f_value;
                    std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l17, l28, l20);
                    l18 = ((vader_struct_vader_front_comptime$EvaluatedProgram_t*) l2)->f_routes;
                    l30 = ((vader_struct_vader_core_symbol$Symbol_t*) l10)->f_id;
                    std_collections$MutableMap$std_core$IndexSet$set_at__i32__vader_front_comptime_ComptimeRoute(l18, l30, (uint8_t) 2);
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

static void* vader_front_comptime$evaluate_null_lit(void* l0) {
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[3] = { &l0, &t0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = (void*) &vader_data_42;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    t1 = vader_front_comptime$ok(vader_ref_box(t0));
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_front_comptime$evaluate_project(void* l0, void* l1, void* l2) {
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
    l3 = vader_front_comptime$new_evaluated_project(l1);
    l4 = ((vader_struct_vader_front_typecheck$TypedProject_t*) l1)->f_modules;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_front_typecheck_TypedProgram_t*) l4)->f_size;
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
        l12 = vader_front_comptime$new_evaluated_program(l11);
        l13 = vader_front_comptime$lookup_module_decls(l0, l10);
        if (!(l13.tag == 0u)) {
            t1 = l13.payload.obj;
            vader_front_comptime$evaluate_module_decls(t1, l11, l12, l3, l10, l2);
            t1 = l13.payload.obj;
            vader_front_comptime$evaluate_assert_decls(t1, l12, l2);
        }
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(((vader_struct_vader_front_comptime$EvaluatedProject_t*) l3)->f_modules, l10, vader_ref_box(l12));
        l7 = (l7 + INT64_C(1));
    }
    vader_front_comptime$evaluate_extern_libraries(l1, l3, l2);
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$evaluate_project_const(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_box_t l4 = vader_box_null();
    int32_t l6;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    void* t2 = NULL;
    vader_string_t t1 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l4, &t3 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l5, &l7, &l8, &t0, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l9, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_project;
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l4.payload.obj;
    l5 = ((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_values;
    l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    l4 = std_collections$MutableMap$std_core$Index$at__i32__Any(l5, l6);
    if (!(l4.tag == 0u)) {
        t0 = vader_front_comptime$ok(l4);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_module;
    l4 = vader_front_comptime$declaring_context(t1, l1);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = l4.payload.obj;
    l7 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l5)->f_typed)->f_const_decls;
    l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    l4 = std_collections$MutableMap$std_core$Index$at__i32__Any(l7, l6);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l7 = l4.payload.obj;
    l4 = vader_front_comptime$cycle_closed_by(((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_evaluating, l0);
    if (!(l4.tag == 0u)) {
        l8 = ((vader_struct_toolchain_ast$ConstDecl_t*) l7)->f_span;
        t0 = l4.payload.obj;
        l9 = vader_front_comptime$display_cycle(t0);
        t0 = vader_support_diagnostics$comptime_error((uint8_t) 5, l8, l9);
        t2 = vader_front_comptime$fail(t0);
        { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_evaluating, l0);
    l5 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$ConstDecl_t*) l7)->f_value, l5);
    t3 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_evaluating);
    if (((vader_struct_vader_front_comptime$EvalResult_t*) l5)->f_value.tag == 0u) {
        { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((vader_struct_vader_front_comptime$ProjectConstants_t*) l3)->f_values;
    l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_id;
    l4 = ((vader_struct_vader_front_comptime$EvalResult_t*) l5)->f_value;
    std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l3, l6, l4);
    { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_seq_lit(void* l0, void* l1) {
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
    vader_box_t* gc_roots[3] = { &l7, &l8, &t0 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l6, &l9, &t1, &t2 };
    vader_string_t* gc_atom_roots[1] = { &l11 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(258u, 0u, 13u, 1953u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) l0)->f_elements;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l6 = vader_front_comptime$evaluate_expr(t0, l1);
        l8 = ((vader_struct_vader_front_comptime$EvalResult_t*) l6)->f_value;
        if (l8.tag == 0u) {
            { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = l8;
        vader_array_push_ref((vader_array_t*) l2, l7.payload.obj);
        l5 = (l5 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_expr_types;
    l4 = ((vader_struct_toolchain_ast$SeqLitExpr_t*) l0)->f_id;
    l8 = std_collections$MutableMap$std_core$Index$at__i64__Any(l3, l4);
    if (l8.tag == 0u) {
        t1 = (void*) &vader_data_22;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t1 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        l7 = vader_ref_box(t1);
    } else {
        l7 = l8;
    }
    t0 = vader_core_types$tuple_backing(l7);
    if (t0.tag == 0u) {
        l11 = 0u;
        if (l7.tag == 904u) {
            t1 = l7.payload.obj;
            l11 = vader_core_types$display_type(((vader_struct_vader_core_types$ArrayType_t*) t1)->f_element);
            vader_struct_vader_front_comptime$ArrayValue_t* _a3_obj = (vader_struct_vader_front_comptime$ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ArrayValue_t));
            vader_obj_header_init(_a3_obj, 1013u);
            _a3_obj->f_elements = l2;
            _a3_obj->f_element_type_name = l11;
            t1 = (void*) _a3_obj;
            t2 = vader_front_comptime$ok(vader_ref_box(t1));
            { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        vader_struct_vader_front_comptime$ArrayValue_t* _a4_obj = (vader_struct_vader_front_comptime$ArrayValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ArrayValue_t));
        vader_obj_header_init(_a4_obj, 1013u);
        _a4_obj->f_elements = l2;
        _a4_obj->f_element_type_name = l11;
        t1 = (void*) _a4_obj;
        t2 = vader_front_comptime$ok(vader_ref_box(t1));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a5_arr = vader_array_new(22u, 0u, 0u, 335u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(29u, 0u, 0u, 346u);
    l6 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 338u);
    l9 = (void*) _a7_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a8_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a8_obj, 541u);
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
        l10 = std_core$write_string_at(l6, l10, 976u);
        l10 = std_core$write_int(l6, l10, l4);
        l11 = std_core$finish_buffer(l6, l10);
        vader_array_t* _a9_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        l8 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l4);
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l3, l11, l8);
        l4 = (l4 + INT64_C(1));
    }
    vader_struct_vader_front_comptime$StructValue_t* _a10_obj = (vader_struct_vader_front_comptime$StructValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$StructValue_t));
    vader_obj_header_init(_a10_obj, 1030u);
    _a10_obj->f_type = l7;
    _a10_obj->f_fields = l3;
    t1 = (void*) _a10_obj;
    t2 = vader_front_comptime$ok(vader_ref_box(t1));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_string_lit(void* l0, void* l1) {
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
    void* t1 = NULL;
    vader_string_t t2 = 0;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[6] = { &l6, &l9, &l10, &l12, &l14, &t3 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l8, &l11, &l13, &t0, &t1 };
    vader_string_t* gc_atom_roots[4] = { &l7, &l15, &l16, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 6u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 626u);
    _a1_obj->f_parts = t0;
    l2 = (void*) _a1_obj;
    l3 = ((vader_struct_toolchain_ast$StringLitExpr_t*) l0)->f_parts;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l6 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        if (l6.tag == 700u) {
            t0 = l6.payload.obj;
            l7 = ((vader_struct_toolchain_ast$StringLitText_t*) t0)->f_value;
            std_string__builder$append(l2, l7);
        } else {
            if (!(l6.tag == 699u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            t0 = l6.payload.obj;
            l8 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$StringLitInterp_t*) t0)->f_expr, l1);
            l10 = ((vader_struct_vader_front_comptime$EvalResult_t*) l8)->f_value;
            if (l10.tag == 0u) {
                { void* __vret = l8; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l9 = l10;
            if (l9.tag == 1019u) {
                l11 = l9.payload.obj;
                t0 = l6.payload.obj;
                l12 = ((vader_struct_toolchain_ast$StringLitInterp_t*) t0)->f_expr;
                l13 = vader_front_comptime$display_enum(l11, l12, l1);
                l14 = ((vader_struct_vader_front_comptime$EvalResult_t*) l13)->f_value;
                if (l14.tag == 0u) {
                    { void* __vret = l13; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l15 = vader_front_comptime$interp_value(l14);
                std_string__builder$append(l2, l15);
                l5 = (l5 + INT64_C(1));
                continue;
            }
            if ((l9.tag == 1013u || l9.tag == 1030u)) {
                t0 = l6.payload.obj;
                t1 = vader_front_comptime$vm_required(VADER_UNION_FIELD(void*, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_span, ((vader_struct_toolchain_ast$StringLitInterp_t*) t0)->f_expr.payload.obj), 1559u);
                { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l16 = vader_front_comptime$interp_value(l9);
            std_string__builder$append(l2, l16);
        }
        l5 = (l5 + INT64_C(1));
    }
    t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l2);
    t3 = vader_front_comptime$string_val(t2);
    t0 = vader_front_comptime$ok(t3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_struct_lit(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    int64_t l5, l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null(), l14 = vader_box_null();
    vader_string_t l10 = 0;
    vader_string_t l15 = 0;
    int32_t l12;
    void* t0 = NULL;
    void* t1 = NULL;
    vader_string_t t2 = 0;
    bool t3;
    vader_box_t* gc_roots[4] = { &l7, &l8, &l9, &l14 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l11, &l13, &t0, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l10, &l15, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 541u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    l3 = ((vader_struct_toolchain_ast$StructLitExpr_t*) l0)->f_items;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        l7 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
        if (l7.tag == 705u) {
            t0 = l7.payload.obj;
            t1 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$StructLitSpread_t*) t0)->f_span, 2656u);
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = l7.payload.obj;
        l4 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_value, l1);
        l9 = ((vader_struct_vader_front_comptime$EvalResult_t*) l4)->f_value;
        if (l9.tag == 0u) {
            { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l8 = l9;
        t0 = l7.payload.obj;
        l10 = ((vader_struct_toolchain_ast$StructLitField_t*) t0)->f_name;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l2, l10, l8);
        l6 = (l6 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_expr_types;
    l5 = ((vader_struct_toolchain_ast$StructLitExpr_t*) l0)->f_id;
    l8 = std_collections$MutableMap$std_core$Index$at__i64__Any(l3, l5);
    if (l8.tag == 0u) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$StructLitExpr_t*) l0)->f_span, 2659u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = l8;
    if (!(l7.tag == 918u)) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$StructLitExpr_t*) l0)->f_span, 2655u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l7.payload.obj;
    t2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_module;
    l8 = vader_front_comptime$declaring_context(t2, l1);
    if (l8.tag == 0u) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$StructLitExpr_t*) l0)->f_span, 2658u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l8.payload.obj;
    l11 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l3)->f_typed)->f_struct_decls;
    t0 = l7.payload.obj;
    l12 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
    l8 = std_collections$MutableMap$std_core$Index$at__i32__Any(l11, l12);
    if (l8.tag == 0u) {
        t0 = vader_front_comptime$vm_required(((vader_struct_toolchain_ast$StructLitExpr_t*) l0)->f_span, 2657u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l8.payload.obj;
    l4 = ((vader_struct_toolchain_ast$StructDecl_t*) l4)->f_fields;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l11 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l8 = ((vader_struct_toolchain_ast$StructField_t*) l11)->f_default;
        l10 = ((vader_struct_toolchain_ast$StructField_t*) l11)->f_name;
        t3 = std_collections$MutableMap$std_core$Contains$contains__string__Any(l2, l10);
        if (!(t3)) {
            if (!(l8.tag == 0u)) {
                l13 = vader_front_comptime$evaluate_expr(l8, l3);
                l14 = ((vader_struct_vader_front_comptime$EvalResult_t*) l13)->f_value;
                if (l14.tag == 0u) {
                    { void* __vret = l13; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l9 = l14;
                l15 = ((vader_struct_toolchain_ast$StructField_t*) l11)->f_name;
                std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l2, l15, l9);
                l6 = (l6 + INT64_C(1));
                continue;
            }
        }
        l6 = (l6 + INT64_C(1));
    }
    t0 = l7.payload.obj;
    vader_struct_vader_front_comptime$StructValue_t* _a6_obj = (vader_struct_vader_front_comptime$StructValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$StructValue_t));
    vader_obj_header_init(_a6_obj, 1030u);
    _a6_obj->f_type = vader_ref_box(t0);
    _a6_obj->f_fields = l2;
    t0 = (void*) _a6_obj;
    t1 = vader_front_comptime$ok(vader_ref_box(t0));
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_unary_expr(void* l0, void* l1) {
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
    l2 = vader_front_comptime$evaluate_expr(((vader_struct_toolchain_ast$UnaryExpr_t*) l0)->f_operand, l1);
    l3 = ((vader_struct_vader_front_comptime$EvalResult_t*) l2)->f_value;
    if (l3.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_toolchain_ast$UnaryExpr_t*) l0)->f_id;
    l5 = vader_front_comptime$resolved_int_name(l1, l4);
    l6 = ((vader_struct_toolchain_ast$UnaryExpr_t*) l0)->f_op;
    if (l6 == INT32_C(0)) {
        l2 = vader_front_comptime$unary_neg(l0, l3, l5);
        t0 = vader_front_comptime$normalize_int_result(l2, l5);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l6 == INT32_C(1)) {
        l2 = vader_front_comptime$unary_not(l0, l3);
    } else {
        if (!(l6 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = vader_front_comptime$unary_bit_not(l0, l3);
    }
    t0 = vader_front_comptime$normalize_int_result(l2, l5);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$evaluate_with_arguments(void* l0, void* l1, void* l2, void* l3, void* l4) {
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
        l8 = ((vader_struct_vader_front_resolver$ResolvedModule_t*) ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l3)->f_typed)->f_resolved)->f_idents;
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$FnDecl_t*) l0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        l9 = toolchain_span$Span$std_core$Hash$hash(((vader_struct_toolchain_ast$FnParam_t*) t0)->f_span);
        l10 = std_collections$MutableMap$std_core$Index$at__u64__Any(l8, l9);
        if (l10.tag == 0u) {
            t0 = vader_front_comptime$vm_required(l4, 619u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = l10.payload.obj;
        l11 = ((vader_struct_vader_core_symbol$Symbol_t*) l7)->f_id;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l12 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l2, l11, l12);
        l5 = (l5 + INT64_C(1));
    }
    l8 = l3;
    l13 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l8)->f_typed;
    l5 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l8)->f_depth;
    l10 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l8)->f_project;
    vader_struct_vader_front_comptime$ComptimeContext_t* _a2_obj = (vader_struct_vader_front_comptime$ComptimeContext_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ComptimeContext_t));
    vader_obj_header_init(_a2_obj, 1017u);
    _a2_obj->f_typed = l13;
    _a2_obj->f_bindings = l2;
    _a2_obj->f_depth = l5;
    _a2_obj->f_project = l10;
    l7 = (void*) _a2_obj;
    t0 = vader_front_comptime$evaluate_fn_body(l0, l7, l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$fail(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
    vader_obj_header_init(_a0_obj, 1020u);
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    _a0_obj->f_diag = vader_ref_box(l0);
    _a0_obj->f_vm_required = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static double vader_front_comptime$float_arith(uint8_t l0, double l1, double l2) {
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

static bool vader_front_comptime$float_compare(double l0, double l1, uint8_t l2) {
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

static vader_box_t vader_front_comptime$float_val(double l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_comptime$FloatValue_t* _a0_obj = (vader_struct_vader_front_comptime$FloatValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$FloatValue_t));
    vader_obj_header_init(_a0_obj, 1023u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = 1952u;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_front_comptime$float_val_typed(double l0, vader_string_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_comptime$FloatValue_t* _a0_obj = (vader_struct_vader_front_comptime$FloatValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$FloatValue_t));
    vader_obj_header_init(_a0_obj, 1023u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_comptime$folder_beside(vader_string_t l0, vader_string_t l1) {
    vader_string_t t0 = 0;
    vader_string_t* gc_atom_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 0u, NULL, NULL, 0u, NULL, 3u, gc_atom_roots };
    vader_gc_top = &gc_frame;
    if (!(l1 == 0u)) {
        t0 = vader_front_resolver$join_path(l0, l1);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
}

static bool vader_front_comptime$has_union_operand(void* l0, void* l1) {
    void* l2;
    int64_t l3;
    vader_box_t t0;
    l2 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l0)->f_typed)->f_expr_types;
    l3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_id, ((vader_struct_toolchain_ast$BinaryExpr_t*) l1)->f_left.payload.obj);
    t0 = std_collections$MutableMap$std_core$Index$at__i64__Any(l2, l3);
    if (t0.tag == 926u) {
        return true;
    }
    l2 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l0)->f_typed)->f_expr_types;
    l3 = VADER_UNION_FIELD(int64_t, vader_struct_toolchain_ast$ArrayTypeExpr_t, f_id, ((vader_struct_toolchain_ast$BinaryExpr_t*) l1)->f_right.payload.obj);
    t0 = std_collections$MutableMap$std_core$Index$at__i64__Any(l2, l3);
    return t0.tag == 926u;
}

static int64_t vader_front_comptime$int_bits_of(vader_string_t l0) {
    void* l1;
    vader_box_t l2;
    int64_t t0;
    l2 = vader_support_integer$machine_integer_named(l0);
    if (l2.tag == 0u) {
        return INT64_C(64);
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_bits;
    return t0;
}

static bool vader_front_comptime$int_compare(int64_t l0, int64_t l1, uint8_t l2) {
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

static vader_string_t vader_front_comptime$int_digits(void* l0) {
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
    t0 = ((vader_struct_vader_front_comptime$IntValue_t*) l0)->f_type_name;
    t1 = vader_core_types$is_unsigned_int_name(t0);
    if (!(t1)) {
        l1 = (void*) vader_buffer_new((size_t) INT64_C(20));
        l2 = INT64_C(0);
        l4 = ((vader_struct_vader_front_comptime$IntValue_t*) l0)->f_value;
        l2 = std_core$write_int(l1, l2, l4);
        t0 = std_core$finish_buffer(l1, l2);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (void*) vader_buffer_new((size_t) INT64_C(20));
    l2 = INT64_C(0);
    t2 = ((vader_struct_vader_front_comptime$IntValue_t*) l0)->f_value;
    t3 = t2;
    l3 = (uint64_t) (int64_t) t3;
    l2 = std_core$write_unsigned(l1, l2, l3);
    t0 = std_core$finish_buffer(l1, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$int_div_check(void* l0, vader_box_t l1, vader_box_t l2, vader_string_t l3) {
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l2.tag == 1024u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
        if (t1 == INT64_C(0)) {
            t0 = vader_front_comptime$division_by_zero(l0, 440u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        t0 = vader_front_comptime$arithmetic(l0, l1, l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = vader_front_comptime$arithmetic(l0, l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$int_mod_check(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 1024u) {
        t0 = l2.payload.obj;
        t1 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
        if (t1 == INT64_C(0)) {
            t0 = vader_front_comptime$division_by_zero(l0, 284u);
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = (void*) &vader_fn_static_vader_front_comptime$op_mod;
        t0 = vader_front_comptime$arithmetic_int(l0, l1, l2, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = (void*) &vader_fn_static_vader_front_comptime$op_mod;
    t0 = vader_front_comptime$arithmetic_int(l0, l1, l2, l3);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$int_val(int64_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_comptime$IntValue_t* _a0_obj = (vader_struct_vader_front_comptime$IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$IntValue_t));
    vader_obj_header_init(_a0_obj, 1024u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = 2075u;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_front_comptime$int_val_typed(int64_t l0, vader_string_t l1) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_comptime$IntValue_t* _a0_obj = (vader_struct_vader_front_comptime$IntValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$IntValue_t));
    vader_obj_header_init(_a0_obj, 1024u);
    _a0_obj->f_value = l0;
    _a0_obj->f_type_name = l1;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_comptime$interp_value(vader_box_t l0) {
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
    if (l0.tag == 1024u) {
        t0 = l0.payload.obj;
        l1 = vader_front_comptime$int_digits(t0);
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1023u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
        l1 = std_core$f64$Display$to_string(t1);
    } else if (l0.tag == 1015u) {
        l2 = (void*) vader_buffer_new((size_t) INT64_C(5));
        l3 = INT64_C(0);
        t0 = l0.payload.obj;
        l4 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
        l3 = std_core$write_bool(l2, l3, l4);
        l1 = std_core$finish_buffer(l2, l3);
    } else if (l0.tag == 1029u) {
        t0 = l0.payload.obj;
        l1 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
    } else if (l0.tag == 1016u) {
        t0 = l0.payload.obj;
        l5 = ((vader_struct_vader_front_comptime$CharValue_t*) t0)->f_value;
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
        l1 = std_core$char$Display$to_string(((uint32_t) (uint32_t) l5));
    } else if (l0.tag == 1027u) {
        l1 = 2408u;
    } else if (l0.tag == 1033u) {
        l1 = 0u;
    } else if (l0.tag == 1031u) {
        t0 = l0.payload.obj;
        l1 = vader_front_comptime$display_value(vader_ref_box(t0));
    } else {
        if (!((l0.tag == 1013u || l0.tag == 1019u || l0.tag == 1030u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = vader_front_comptime$display_value(l0);
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_align_of(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
        vader_obj_header_init(_a0_obj, 1020u);
        _a0_obj->f_value = vader_box_obj(0u, NULL);
        _a0_obj->f_diag = vader_box_obj(0u, NULL);
        _a0_obj->f_vm_required = false;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_front_comptime$resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t0 = vader_front_comptime$byte_align(l2);
        t2 = vader_front_comptime$int_val_typed(t0, 2097u);
        t1 = vader_front_comptime$ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_comptime$arg_error(l0, 1512u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_field_count(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
        vader_obj_header_init(_a0_obj, 1020u);
        _a0_obj->f_value = vader_box_obj(0u, NULL);
        _a0_obj->f_diag = vader_box_obj(0u, NULL);
        _a0_obj->f_vm_required = false;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_front_comptime$resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t0 = vader_front_comptime$type_field_count(l2, l1);
        t2 = vader_front_comptime$int_val_typed(t0, 2097u);
        t1 = vader_front_comptime$ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_comptime$arg_error(l0, 1990u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_field_index(void* l0, void* l1) {
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
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(2)) {
        vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
        vader_obj_header_init(_a0_obj, 1020u);
        _a0_obj->f_value = vader_box_obj(0u, NULL);
        _a0_obj->f_diag = vader_box_obj(0u, NULL);
        _a0_obj->f_vm_required = false;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_front_comptime$resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_front_comptime$arg_error(l0, 1993u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(1))
    t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(1));
    l3 = toolchain_ast$string_literal_text(t2);
    if (l3.tag == 0u) {
        t1 = vader_front_comptime$arg_error(l0, 1992u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l2.tag == 918u)) {
        vader_struct_vader_front_comptime$EvalResult_t* _a3_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
        vader_obj_header_init(_a3_obj, 1020u);
        _a3_obj->f_value = vader_box_obj(0u, NULL);
        _a3_obj->f_diag = vader_box_obj(0u, NULL);
        _a3_obj->f_vm_required = false;
        t1 = (void*) _a3_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_struct_decls;
    t1 = l2.payload.obj;
    l5 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t1)->f_symbol)->f_id;
    l6 = std_collections$MutableMap$std_core$Index$at__i32__Any(l4, l5);
    if (!(l6.tag == 701u)) {
        t1 = l2.payload.obj;
        l9 = vader_core_types$display_type(vader_ref_box(t1));
        l10 = concat_3(1994u, l9, 1206u);
        t1 = vader_front_comptime$arg_error(l0, l10);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l7 = INT64_C(0);
    t1 = l6.payload.obj;
    l8 = ((vader_array_t*) ((vader_struct_toolchain_ast$StructDecl_t*) t1)->f_fields)->length;
    while ((l7 < l8)) {
        t1 = l6.payload.obj;
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$StructDecl_t*) t1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        t1 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_toolchain_ast$StructField_t*) t1)->f_name;
        l10 = l3.payload.s;
        if (l9 == l10) {
            t2 = vader_front_comptime$int_val_typed(l7, 2097u);
            t1 = vader_front_comptime$ok(t2);
            { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l7 = (l7 + INT64_C(1));
    }
    vader_struct_vader_front_comptime$EvalResult_t* _a5_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
    vader_obj_header_init(_a5_obj, 1020u);
    _a5_obj->f_value = vader_box_obj(0u, NULL);
    _a5_obj->f_diag = vader_box_obj(0u, NULL);
    _a5_obj->f_vm_required = false;
    t1 = (void*) _a5_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_integer_bound(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l3 = 0;
    vader_string_t l6 = 0;
    void* l4 = NULL;
    bool l7;
    int64_t l8;
    int64_t t0;
    void* t1 = NULL;
    void* t5 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_string_t t3 = 0;
    bool t4;
    vader_box_t* gc_roots[3] = { &l2, &l5, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &t1, &t5 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l6, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
        vader_obj_header_init(_a0_obj, 1020u);
        _a0_obj->f_value = vader_box_obj(0u, NULL);
        _a0_obj->f_diag = vader_box_obj(0u, NULL);
        _a0_obj->f_vm_required = false;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_front_comptime$resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t3 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
        l3 = concat_2(t3, 468u);
        t1 = vader_front_comptime$arg_error(l0, l3);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l2.tag == 906u) {
        l4 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_span;
        l3 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
        l3 = concat_3(531u, l3, 187u);
        t1 = vader_front_comptime$vm_required(l4, l3);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = vader_core_types$type_bounds(l2);
    if (l5.tag == 0u) {
        l3 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
        l6 = vader_core_types$display_type(l2);
        l3 = concat_4(l3, 464u, l6, 1108u);
        t1 = vader_front_comptime$arg_error(l0, l3);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = l5.payload.obj;
    t3 = ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_name;
    l7 = t3 == 2314u;
    l8 = vader_core_types$integer_bound(l4, l7);
    t4 = vader_core_types$is_char(l2);
    if (!(t4)) {
        l3 = vader_core_types$representation_name(l2);
        t2 = vader_front_comptime$int_val_typed(l8, l3);
        t1 = vader_front_comptime$ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_front_comptime$CharValue_t* _a2_obj = (vader_struct_vader_front_comptime$CharValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$CharValue_t));
    vader_obj_header_init(_a2_obj, 1016u);
    _a2_obj->f_value = (uint32_t) (int32_t) ((int32_t) (int64_t) l8);
    t1 = (void*) _a2_obj;
    t5 = vader_front_comptime$ok(vader_ref_box(t1));
    { void* __vret = t5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_satisfies(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    void* l4 = NULL;
    int64_t t0;
    void* t1 = NULL;
    void* t3 = NULL;
    vader_box_t t2 = vader_box_null();
    bool t4;
    vader_box_t* gc_roots[3] = { &l2, &l3, &t2 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &t1, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(2)) {
        vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
        vader_obj_header_init(_a0_obj, 1020u);
        _a0_obj->f_value = vader_box_obj(0u, NULL);
        _a0_obj->f_diag = vader_box_obj(0u, NULL);
        _a0_obj->f_vm_required = false;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_front_comptime$resolve_type_arg(t2, l1);
    if (l2.tag == 0u) {
        t1 = vader_front_comptime$arg_error(l0, 2534u);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, INT32_C(1))
    t2 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT32_C(1));
    l3 = vader_front_comptime$resolve_type_arg(t2, l1);
    if (l3.tag == 0u) {
        t1 = (void*) &vader_data_44;
        vader_array_t* _a3_slotarr = ((vader_array_t*) t1);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t1 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) INT64_C(0));
        t3 = vader_front_comptime$ok(vader_ref_box(t1));
        { void* __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed;
    t4 = vader_front_typecheck$satisfies_trait(l2, l3, l4);
    t2 = vader_front_comptime$bool_value(t4);
    t1 = vader_front_comptime$ok(t2);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_size_of(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
        vader_obj_header_init(_a0_obj, 1020u);
        _a0_obj->f_value = vader_box_obj(0u, NULL);
        _a0_obj->f_diag = vader_box_obj(0u, NULL);
        _a0_obj->f_vm_required = false;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_front_comptime$resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t0 = vader_front_comptime$byte_size(l2);
        t2 = vader_front_comptime$int_val_typed(t0, 2097u);
        t1 = vader_front_comptime$ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_comptime$arg_error(l0, 2559u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_type_kind(void* l0, void* l1) {
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
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
        vader_obj_header_init(_a0_obj, 1020u);
        _a0_obj->f_value = vader_box_obj(0u, NULL);
        _a0_obj->f_diag = vader_box_obj(0u, NULL);
        _a0_obj->f_vm_required = false;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_front_comptime$resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t3 = vader_front_comptime$type_kind_label(l2);
        t2 = vader_front_comptime$string_val(t3);
        t1 = vader_front_comptime$ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_comptime$arg_error(l0, 2760u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_type_name(void* l0, void* l1) {
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
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
        vader_obj_header_init(_a0_obj, 1020u);
        _a0_obj->f_value = vader_box_obj(0u, NULL);
        _a0_obj->f_diag = vader_box_obj(0u, NULL);
        _a0_obj->f_vm_required = false;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_front_comptime$resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t3 = vader_core_types$display_type(l2);
        t2 = vader_front_comptime$string_val(t3);
        t1 = vader_front_comptime$ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_comptime$arg_error(l0, 2762u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$intrinsic_variant_count(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args)->length;
    if (t0 != INT64_C(1)) {
        vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
        vader_obj_header_init(_a0_obj, 1020u);
        _a0_obj->f_value = vader_box_obj(0u, NULL);
        _a0_obj->f_diag = vader_box_obj(0u, NULL);
        _a0_obj->f_vm_required = false;
        t1 = (void*) _a0_obj;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$IntrinsicCallExpr_t*) l0)->f_args);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
    t2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
    l2 = vader_front_comptime$resolve_type_arg(t2, l1);
    if (!(l2.tag == 0u)) {
        t0 = vader_front_comptime$type_variant_count(l2);
        t2 = vader_front_comptime$int_val_typed(t0, 2097u);
        t1 = vader_front_comptime$ok(t2);
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_front_comptime$arg_error(l0, 2999u);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_comptime$is_arithmetic(uint8_t l0) {
    bool l1, l2;
    if (l0 == INT32_C(0)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(1);
    }
    if (l1) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(2);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(3);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(4);
    }
    if (l2) {
        l1 = true;
        return l1;
    }
    if (l0 == INT32_C(5)) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(6);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(7);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(8);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(9);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(23);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(24);
    }
    if (l2) {
        l2 = true;
    } else {
        l2 = l0 == INT32_C(25);
    }
    if (l2) {
        l1 = false;
    } else {
        if (l0 == INT32_C(10)) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(11);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(12);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(13);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(14);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(15);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(16);
        }
        if (l2) {
            l2 = true;
        } else {
            l2 = l0 == INT32_C(17);
        }
        if (l2) {
            l1 = false;
        } else {
            if (l0 == INT32_C(18)) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(19);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(20);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(21);
            }
            if (l2) {
                l2 = true;
            } else {
                l2 = l0 == INT32_C(22);
            }
            if (!(l2)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l1 = false;
        }
    }
    return l1;
}

static bool vader_front_comptime$is_resolved(vader_box_t l0) {
    if (!(l0.tag == 927u)) {
        return true;
    }
    return false;
}

static vader_box_t vader_front_comptime$lookup_module_decls(void* l0, vader_string_t l1) {
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
    l3 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_resolver$LoadedProject_t*) l0)->f_modules, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.obj;
    l2 = ((vader_struct_vader_front_resolver$Module_t*) ((vader_struct_vader_front_resolver$LoadedModule_t*) l2)->f_module)->f_files;
    t0 = ((vader_array_t*) l2)->length;
    if (!(t0 == INT64_C(0))) {
        t1 = vader_front_resolver$concat_file_decls(l2);
        { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

vader_string_t vader_front_comptime$mangle_type_arg(vader_box_t l0) {
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_string_t t2 = 0;
    vader_box_t* gc_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[2] = { &t1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 0u, gc_roots, NULL, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$strip_distinct(l0);
    t1 = vader_core_types$qualified_display_type(t0);
    t2 = vader_support_text$sanitise_ident(t1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$mask_shift_amount(vader_box_t l0, vader_string_t l1) {
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
    if (!(l0.tag == 1024u)) {
        { vader_box_t __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
    l3 = vader_front_comptime$shift_amount_mask(l1);
    l2 = (l2 & l3);
    t0 = l0.payload.obj;
    l4 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
    t1 = vader_front_comptime$int_val_typed(l2, l4);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$new_evaluated_program(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[6] = { &l0, &l1, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any_t));
    vader_obj_header_init(_a3_obj, 467u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(23u, 0u, 7u, 338u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(25u, 0u, 1u, 340u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 7u, 338u);
    l4 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__i32__vader_front_comptime_ComptimeRoute_t* _a7_obj = (vader_struct_std_collections$MutableMap__i32__vader_front_comptime_ComptimeRoute_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__vader_front_comptime_ComptimeRoute_t));
    vader_obj_header_init(_a7_obj, 497u);
    _a7_obj->f_ekeys = l2;
    _a7_obj->f_evals = l3;
    _a7_obj->f_index = l4;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(106u, 0u, 13u, 1014u);
    l3 = (void*) _a8_arr;
    vader_struct_vader_front_comptime$EvaluatedProgram_t* _a9_obj = (vader_struct_vader_front_comptime$EvaluatedProgram_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvaluatedProgram_t));
    vader_obj_header_init(_a9_obj, 1021u);
    _a9_obj->f_typed = l0;
    _a9_obj->f_comptime_decls = l1;
    _a9_obj->f_routes = l2;
    _a9_obj->f_asserts = l3;
    t0 = (void*) _a9_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$new_evaluated_project(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 541u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(110u, 0u, 13u, 1032u);
    l2 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(24u, 0u, 8u, 339u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(29u, 0u, 0u, 346u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections$MutableMap__i64__Any_t* _a8_obj = (vader_struct_std_collections$MutableMap__i64__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__Any_t));
    vader_obj_header_init(_a8_obj, 514u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a8_obj;
    vader_struct_vader_front_comptime$EvaluatedProject_t* _a9_obj = (vader_struct_vader_front_comptime$EvaluatedProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvaluatedProject_t));
    vader_obj_header_init(_a9_obj, 1022u);
    _a9_obj->f_typed = l0;
    _a9_obj->f_modules = l1;
    _a9_obj->f_vm_required = l2;
    _a9_obj->f_libraries = l3;
    t0 = (void*) _a9_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$normalize_int_result(void* l0, vader_string_t l1) {
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
    l2 = ((vader_struct_vader_front_comptime$EvalResult_t*) l0)->f_value;
    if (!(l2.tag == 1024u)) {
        { void* __vret = l0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l2.payload.obj;
    t1 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
    l3 = vader_front_comptime$wrap_to_width(t1, l1);
    t0 = l2.payload.obj;
    l4 = vader_front_comptime$result_type_name(t0, l1);
    t2 = vader_front_comptime$int_val_typed(l3, l4);
    t0 = vader_front_comptime$ok(t2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_front_comptime$numbers_of_two_types(vader_box_t l0, vader_box_t l1) {
    vader_string_t l2, l3;
    void* t0;
    vader_string_t t1;
    if (l0.tag == 1024u) {
        if (l1.tag == 1024u) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
            if (t1 == 0u) {
                return true;
            }
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
            return l2 != l3;
        }
    }
    if (l0.tag == 1023u) {
        if (l1.tag == 1023u) {
            t0 = l0.payload.obj;
            t1 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_type_name;
            if (t1 == 0u) {
                return true;
            }
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_type_name;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_type_name;
            return l2 != l3;
        }
        return false;
    }
    return false;
}

static void* vader_front_comptime$ok(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
    vader_obj_header_init(_a0_obj, 1020u);
    _a0_obj->f_value = l0;
    _a0_obj->f_diag = vader_box_obj(0u, NULL);
    _a0_obj->f_vm_required = false;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t vader_front_comptime$op_add(int64_t l0, int64_t l1) {
    return (l0 + l1);
}

bool vader_front_comptime$op_and(bool l0, bool l1) {
    if (l0) {
        return l1;
    }
    return false;
}

int64_t vader_front_comptime$op_bit_and(int64_t l0, int64_t l1) {
    return (l0 & l1);
}

int64_t vader_front_comptime$op_bit_or(int64_t l0, int64_t l1) {
    return (l0 | l1);
}

int64_t vader_front_comptime$op_bit_xor(int64_t l0, int64_t l1) {
    return (l0 ^ l1);
}

static int64_t vader_front_comptime$op_div(int64_t l0, int64_t l1) {
    int64_t t0;
    t0 = vader_div_i64(l0, l1);
    return t0;
}

int64_t vader_front_comptime$op_mod(int64_t l0, int64_t l1) {
    int64_t t0;
    t0 = vader_mod_i64(l0, l1);
    return t0;
}

int64_t vader_front_comptime$op_mul(int64_t l0, int64_t l1) {
    return (l0 * l1);
}

bool vader_front_comptime$op_or(bool l0, bool l1) {
    if (l0) {
        return true;
    }
    return l1;
}

int64_t vader_front_comptime$op_shl(int64_t l0, int64_t l1) {
    return (l0 << (l1 & 63));
}

int64_t vader_front_comptime$op_shr(int64_t l0, int64_t l1) {
    return (l0 >> (l1 & 63));
}

int64_t vader_front_comptime$op_sub(int64_t l0, int64_t l1) {
    return (l0 - l1);
}

static vader_box_t vader_front_comptime$pattern_holds(vader_box_t l0, vader_box_t l1) {
    vader_string_t l2, l3;
    void* l4;
    int64_t l5, l6;
    vader_box_t l7;
    void* t0;
    vader_box_t t1;
    bool t2;
    if (l0.tag == 716u) {
        return vader_box_bool(333u, true);
    }
    if (l0.tag == 654u) {
        if (!(l1.tag == 1019u)) {
            return vader_box_obj(0u, NULL);
        }
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_front_comptime$EnumValue_t*) t0)->f_variant;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_toolchain_ast$EnumVariantPattern_t*) t0)->f_variant;
        return vader_box_bool(333u, l2 == l3);
    }
    if (!(l0.tag == 686u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    l4 = ((vader_struct_toolchain_ast$OrPattern_t*) t0)->f_patterns;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
        l7 = vader_front_comptime$pattern_holds(t1, l1);
        if (l7.tag == 0u) {
            return vader_box_obj(0u, NULL);
        }
        t2 = l7.payload.b;
        if (t2) {
            return vader_box_bool(333u, true);
        }
        l6 = (l6 + INT64_C(1));
    }
    return vader_box_bool(333u, false);
}

static void vader_front_comptime$populate_deps(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    int64_t l3, l4, l5;
    vader_box_t l7 = vader_box_null(), l11 = vader_box_null(), l14 = vader_box_null();
    int32_t l13;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l7, &l11, &l14 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l6, &l8, &l9, &l10, &l12, &l15, &l16, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_order;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        l7 = std_collections$MutableMap$std_core$Index$at__i64__Any(((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_by_id, l5);
        if (l7.tag == 0u) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l6 = l7.payload.obj;
        l9 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) l1)->f_resolved;
        l10 = ((vader_struct_toolchain_ast$ConstDecl_t*) ((vader_struct_vader_front_comptime$NodeRecord_t*) l6)->f_decl)->f_name_span;
        l11 = vader_front_resolver$symbol_declared_at(l9, l10);
        if (l11.tag == 0u) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l8 = l11.payload.obj;
        l12 = ((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_by_symbol;
        l13 = ((vader_struct_vader_core_symbol$Symbol_t*) l8)->f_id;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__i64(l12, l13, l5);
        l4 = (l4 + INT64_C(1));
    }
    l2 = ((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_order;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l5 = ((int64_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
        l7 = std_collections$MutableMap$std_core$Index$at__i64__Any(((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_by_id, l5);
        if (l7.tag == 0u) {
            l4 = (l4 + INT64_C(1));
            continue;
        }
        l6 = l7.payload.obj;
        vader_array_t* _a2_arr = vader_array_new(24u, 0u, 8u, 339u);
        l8 = (void*) _a2_arr;
        vader_array_t* _a3_arr = vader_array_new(20u, 0u, 12u, 333u);
        l9 = (void*) _a3_arr;
        vader_array_t* _a4_arr = vader_array_new(23u, 0u, 7u, 338u);
        l10 = (void*) _a4_arr;
        vader_struct_std_collections$MutableMap__i64__bool_t* _a5_obj = (vader_struct_std_collections$MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__bool_t));
        vader_obj_header_init(_a5_obj, 516u);
        _a5_obj->f_ekeys = l8;
        _a5_obj->f_evals = l9;
        _a5_obj->f_index = l10;
        _a5_obj->f_mask = INT64_C(0);
        _a5_obj->f_grow_at = INT64_C(0);
        _a5_obj->f_size = INT64_C(0);
        _a5_obj->f_tombs = INT64_C(0);
        t0 = (void*) _a5_obj;
        vader_struct_std_collections$MutableSet__i64_t* _a6_obj = (vader_struct_std_collections$MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i64_t));
        vader_obj_header_init(_a6_obj, 614u);
        _a6_obj->f_inner = t0;
        l12 = (void*) _a6_obj;
        l14 = ((vader_struct_toolchain_ast$ConstDecl_t*) ((vader_struct_vader_front_comptime$NodeRecord_t*) l6)->f_decl)->f_comptime_body;
        if (l14.tag == 0u) {
            l11 = ((vader_struct_toolchain_ast$ConstDecl_t*) ((vader_struct_vader_front_comptime$NodeRecord_t*) l6)->f_decl)->f_value;
        } else {
            l11 = l14;
        }
        vader_struct___lambda_env_vader_front_comptime_1_t* _a7_obj = (vader_struct___lambda_env_vader_front_comptime_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_comptime_1_t));
        vader_obj_header_init(_a7_obj, 372u);
        _a7_obj->f_cap_0 = l1;
        _a7_obj->f_cap_1 = l0;
        _a7_obj->f_cap_2 = l12;
        _a7_obj->f_cap_3 = l6;
        t0 = (void*) _a7_obj;
        vader_fn_t* _a8_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
        vader_obj_header_init(_a8_closure, 324u);
        _a8_closure->code = (void*) &vader_fn_lift___lambda_vader_front_comptime_0;
        _a8_closure->env = t0;
        l15 = (void*) _a8_closure;
        l16 = (void*) &vader_fn_static_toolchain_ast$ignore_node;
        toolchain_ast$inspect(l11, l15, l16);
        std_collections$MutableMap$std_core$IndexSet$set_at__i64__Any(((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_by_id, l5, vader_ref_box(l6));
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_string_t vader_front_comptime$render_array(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 626u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    std_string__builder$append_char(l1, 91u);
    l2 = ((vader_array_t*) ((vader_struct_vader_front_comptime$ArrayValue_t*) l0)->f_elements)->length;
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
            std_string__builder$append(l1, 362u);
        }
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_front_comptime$ArrayValue_t*) l0)->f_elements);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t1 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l6 = vader_front_comptime$display_value(t1);
        std_string__builder$append(l1, l6);
        l5 = (l5 + INT64_C(1));
    }
    if (l4) {
        l7 = (void*) vader_buffer_new((size_t) INT64_C(35));
        l3 = INT64_C(0);
        l3 = std_core$write_string_at(l7, l3, 364u);
        l3 = std_core$write_int(l7, l3, l2);
        l3 = std_core$write_string_at(l7, l3, 114u);
        l6 = std_core$finish_buffer(l7, l3);
        std_string__builder$append(l1, l6);
    }
    std_string__builder$append_char(l1, 93u);
    t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_comptime$render_struct(void* l0) {
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
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 626u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = vader_core_types$display_type(((vader_struct_vader_front_comptime$StructValue_t*) l0)->f_type);
    std_string__builder$append(l1, l2);
    std_string__builder$append(l1, 237u);
    l3 = std_collections$keys__string__vader_front_comptime_ArrayValue___vader_front_comptime_BoolValue___vader_front_comptime_CharValue___vader_front_comptime_EnumValue___vader_front_comptime_FloatValue___vader_front_comptime_IntValue___vader_front_comptime_NullValue___vader_front_comptime_StringValue___vader_front_comptime_StructValue___vader_front_comptime_TypeValue___vader_front_comptime_VoidValue(((vader_struct_vader_front_comptime$StructValue_t*) l0)->f_fields);
    l4 = (void*) &vader_fn_static___lambda_vader_front_comptime_2;
    l3 = std_sort$sort__string(l3, l4);
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) l3)->length;
    while ((l5 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        t1 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l5];
        l2 = t1.payload.s;
        l8 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_comptime$StructValue_t*) l0)->f_fields, l2);
        if (l8.tag == 0u) {
            l5 = (l5 + INT64_C(1));
            continue;
        }
        l7 = l8;
        if ((l5 > INT64_C(0))) {
            std_string__builder$append(l1, 362u);
        }
        std_string__builder$append_char(l1, 46u);
        std_string__builder$append(l1, l2);
        std_string__builder$append(l1, 81u);
        l9 = vader_front_comptime$display_value(l7);
        std_string__builder$append(l1, l9);
        l5 = (l5 + INT64_C(1));
    }
    std_string__builder$append(l1, 240u);
    t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$resolve_type_arg(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l0, &l4 };
    void** gc_raw_roots[3] = { &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_resolved;
    l3 = vader_front_comptime$diag_sink();
    l4 = vader_front_typecheck$type_from_expr(l0, l2, l3);
    if (!(l4.tag == 927u)) {
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_string_t vader_front_comptime$resolved_int_name(void* l0, int64_t l1) {
    vader_box_t l2;
    vader_string_t l3;
    l2 = std_collections$MutableMap$std_core$Index$at__i64__Any(((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l0)->f_typed)->f_expr_types, l1);
    l3 = vader_core_types$primitive_name(l2);
    if (l3 != 0u) {
        return l3;
    }
    if (!(l2.tag == 910u)) {
        return 0u;
    }
    return 2075u;
}

static vader_box_t vader_front_comptime$resolved_library(vader_box_t l0, vader_string_t l1) {
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
    if (!(l0.tag == 1030u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l0.payload.obj;
    l3 = vader_front_comptime$string_field(t0, 2358u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l3.payload.s;
    t0 = l0.payload.obj;
    l3 = vader_front_comptime$string_field(t0, 2069u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = l3.payload.s;
    t0 = l0.payload.obj;
    l3 = vader_front_comptime$string_field(t0, 2148u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = l3.payload.s;
    t0 = l0.payload.obj;
    l3 = vader_front_comptime$strings_field(t0, 1546u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l6 = l3.payload.obj;
    t0 = l0.payload.obj;
    l3 = vader_front_comptime$strings_field(t0, 2684u);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l7 = l3.payload.obj;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
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
        l12 = vader_front_resolver$join_path(l1, l11);
        vader_array_push_scalar((vader_array_t*) l8, vader_box_string(335u, l12));
        l10 = (l10 + INT64_C(1));
    }
    l5 = vader_front_comptime$folder_beside(l1, l5);
    vader_struct_std_ffi$CLibrary_t* _a3_obj = (vader_struct_std_ffi$CLibrary_t*) vader_gc_alloc(sizeof(vader_struct_std_ffi$CLibrary_t));
    vader_obj_header_init(_a3_obj, 623u);
    _a3_obj->f_name = l2;
    _a3_obj->f_header = l4;
    _a3_obj->f_include = l5;
    _a3_obj->f_archives = l8;
    _a3_obj->f_system = l7;
    t0 = (void*) _a3_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_front_comptime$result_type_name(void* l0, vader_string_t l1) {
    vader_string_t t0;
    if (!(l1 != 0u)) {
        t0 = ((vader_struct_vader_front_comptime$IntValue_t*) l0)->f_type_name;
        return t0;
    }
    return l1;
}

static bool vader_front_comptime$runs_an_impl(void* l0, void* l1) {
    void* l2;
    int64_t l3;
    bool t0;
    vader_box_t t1;
    t0 = vader_front_comptime$is_arithmetic(((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_op);
    if (!(t0)) {
        return false;
    }
    l2 = vader_front_typecheck$sites_of(((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_call_sites, (uint8_t) 1);
    l3 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_id;
    t1 = std_collections$MutableMap$std_core$Index$at__i64__Any(l2, l3);
    return (t1.tag == 1124u || t1.tag == 1136u || t1.tag == 1138u || t1.tag == 1174u);
}

static bool vader_front_comptime$same_kind(vader_box_t l0, vader_box_t l1) {
    bool l2;
    if (l0.tag == 1024u) {
        l2 = l1.tag == 1024u;
        return l2;
    }
    if (l0.tag == 1023u) {
        l2 = l1.tag == 1023u;
    } else if (l0.tag == 1015u) {
        l2 = l1.tag == 1015u;
    } else if (l0.tag == 1016u) {
        l2 = l1.tag == 1016u;
    } else if (l0.tag == 1029u) {
        l2 = l1.tag == 1029u;
    } else if (l0.tag == 1027u) {
        l2 = l1.tag == 1027u;
    } else if (l0.tag == 1033u) {
        l2 = l1.tag == 1033u;
    } else if (l0.tag == 1013u) {
        l2 = l1.tag == 1013u;
    } else if (l0.tag == 1030u) {
        l2 = l1.tag == 1030u;
    } else if (l0.tag == 1031u) {
        l2 = l1.tag == 1031u;
    } else {
        if (!(l0.tag == 1019u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l2 = l1.tag == 1019u;
    }
    return l2;
}

static bool vader_front_comptime$settles_alone(uint8_t l0, vader_box_t l1) {
    bool l2, l3;
    void* t0;
    bool t1;
    if (l1.tag == 1015u) {
        if (l0 == INT32_C(10)) {
            t0 = l1.payload.obj;
            t1 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
            l2 = !(t1);
        } else {
            l2 = false;
        }
        if (l2) {
            l2 = true;
        } else {
            if (l0 == INT32_C(11)) {
                t0 = l1.payload.obj;
                l3 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
            } else {
                l3 = false;
            }
            l2 = l3;
        }
        return l2;
    }
    return false;
}

static int64_t vader_front_comptime$shift_amount_mask(vader_string_t l0) {
    void* l1;
    vader_box_t l2;
    int64_t t0;
    l2 = vader_support_integer$machine_integer_named(l0);
    if (l2.tag == 0u) {
        return INT64_C(63);
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_bits;
    if (!((t0 <= INT64_C(32)))) {
        return INT64_C(63);
    }
    return INT64_C(31);
}

static int64_t vader_front_comptime$sign_extend(int64_t l0, int64_t l1) {
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

static void* vader_front_comptime$sort_comptime_decls(void* l0, void* l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_front_comptime$collect_nodes(l0);
    vader_front_comptime$populate_deps(l2, l1);
    t0 = vader_front_comptime$topo_sort(l2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$string_field(void* l0, vader_string_t l1) {
    vader_box_t l2;
    void* t0;
    vader_string_t t1;
    l2 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_comptime$StructValue_t*) l0)->f_fields, l1);
    if (l2.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    if (!(l2.tag == 1029u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l2.payload.obj;
    t1 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
    return vader_box_string(335u, t1);
}

vader_box_t vader_front_comptime$string_val(vader_string_t l0) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_comptime$StringValue_t* _a0_obj = (vader_struct_vader_front_comptime$StringValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$StringValue_t));
    vader_obj_header_init(_a0_obj, 1029u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$strings_field(void* l0, vader_string_t l1) {
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
    l2 = std_collections$MutableMap$std_core$Index$at__string__Any(((vader_struct_vader_front_comptime$StructValue_t*) l0)->f_fields, l1);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(l2.tag == 1013u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l3 = (void*) _a0_arr;
    t0 = l2.payload.obj;
    l4 = ((vader_struct_vader_front_comptime$ArrayValue_t*) t0)->f_elements;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l2 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        if (!(l2.tag == 1029u)) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t0 = l2.payload.obj;
        l7 = ((vader_struct_vader_front_comptime$StringValue_t*) t0)->f_value;
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(335u, l7));
        l6 = (l6 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$topo_sort(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t l7, l8, l9;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 8u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(41u, 0u, 13u, 639u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(216u, 0u, 13u, 1410u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(24u, 0u, 8u, 339u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(23u, 0u, 7u, 338u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a4_arr;
    vader_struct_std_collections$MutableMap__i64__i32_t* _a5_obj = (vader_struct_std_collections$MutableMap__i64__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__i32_t));
    vader_obj_header_init(_a5_obj, 517u);
    _a5_obj->f_ekeys = l3;
    _a5_obj->f_evals = l4;
    _a5_obj->f_index = l5;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(24u, 0u, 8u, 339u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(20u, 0u, 12u, 333u);
    l5 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a8_arr;
    vader_struct_std_collections$MutableMap__i64__bool_t* _a9_obj = (vader_struct_std_collections$MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__bool_t));
    vader_obj_header_init(_a9_obj, 516u);
    _a9_obj->f_ekeys = l4;
    _a9_obj->f_evals = l5;
    _a9_obj->f_index = l6;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_grow_at = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a9_obj;
    vader_struct_std_collections$MutableSet__i64_t* _a10_obj = (vader_struct_std_collections$MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i64_t));
    vader_obj_header_init(_a10_obj, 614u);
    _a10_obj->f_inner = t0;
    l4 = (void*) _a10_obj;
    l5 = ((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_order;
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a11_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
        l9 = ((int64_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l8];
        std_collections$MutableMap$std_core$IndexSet$set_at__i64__i32(l3, l9, INT32_C(0));
        l8 = (l8 + INT64_C(1));
    }
    vader_array_t* _a12_arr = vader_array_new(24u, 0u, 8u, 339u);
    l5 = (void*) _a12_arr;
    l6 = ((vader_struct_vader_front_comptime$Nodes_t*) l0)->f_order;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a13_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a13_slotarr, l8)
        t1 = ((int64_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l8];
        vader_front_comptime$visit(t1, l0, l3, l4, l5, l1, l2);
        l8 = (l8 + INT64_C(1));
    }
    vader_struct_vader_front_comptime$ComptimeOrder_t* _a14_obj = (vader_struct_vader_front_comptime$ComptimeOrder_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$ComptimeOrder_t));
    vader_obj_header_init(_a14_obj, 1018u);
    _a14_obj->f_order = l1;
    _a14_obj->f_cycle_diags = l2;
    t0 = (void*) _a14_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_front_comptime$type_field_count(vader_box_t l0, void* l1) {
    void* l2;
    int32_t l3;
    vader_box_t l4;
    void* t0;
    int64_t t1;
    if (l0.tag == 918u) {
        l2 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_struct_decls;
        t0 = l0.payload.obj;
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
        l4 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l3);
        if (!(l4.tag == 701u)) {
            return INT64_C(0);
        }
        t0 = l4.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_toolchain_ast$StructDecl_t*) t0)->f_fields)->length;
        return t1;
    }
    if (!(l0.tag == 921u)) {
        return INT64_C(0);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_array_t*) ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements)->length;
    return t1;
}

static vader_box_t vader_front_comptime$type_from_expr_safe(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_front_typecheck$TypedProgram_t*) ((vader_struct_vader_front_comptime$ComptimeContext_t*) l1)->f_typed)->f_resolved;
    l3 = vader_front_comptime$diag_sink();
    l4 = vader_front_typecheck$type_from_expr(vader_ref_box(l0), l2, l3);
    t0 = vader_front_comptime$is_resolved(l4);
    if (!(t0)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_front_comptime$type_kind_label(vader_box_t l0) {
    vader_string_t l1 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if ((l0.tag == 915u || l0.tag == 916u)) {
        l1 = 2471u;
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 905u) {
        t0 = l0.payload.obj;
        l1 = vader_front_comptime$type_kind_label(((vader_struct_vader_core_types$DistinctType_t*) t0)->f_backing);
    } else if (l0.tag == 918u) {
        l1 = 2650u;
    } else if (l0.tag == 906u) {
        l1 = 1882u;
    } else if (l0.tag == 926u) {
        l1 = 2808u;
    } else if (l0.tag == 904u) {
        l1 = 1556u;
    } else if (l0.tag == 921u) {
        l1 = 2740u;
    } else if (l0.tag == 907u) {
        l1 = 2003u;
    } else if (l0.tag == 920u) {
        l1 = 2732u;
    } else if (l0.tag == 922u) {
        l1 = 2743u;
    } else if (l0.tag == 923u) {
        l1 = 2811u;
    } else if (l0.tag == 911u) {
        t0 = l0.payload.obj;
        vader_core_types$leaked_infer_var(t0);
        vader_unreachable("a no-return call returned");
    } else if (l0.tag == 917u) {
        l1 = 2811u;
    } else if (l0.tag == 927u) {
        l1 = 2811u;
    } else if (l0.tag == 910u) {
        l1 = 2811u;
    } else if (l0.tag == 908u) {
        l1 = 2811u;
    } else if (l0.tag == 909u) {
        l1 = 2811u;
    } else if (l0.tag == 913u) {
        l1 = 2811u;
    } else {
        if (!(l0.tag == 903u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1544u;
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$type_mismatch(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$BinaryExpr_t*) l0)->f_span;
    t0 = vader_support_diagnostics$comptime_error((uint8_t) 4, l2, l1);
    t1 = vader_front_comptime$fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_front_comptime$type_val(vader_box_t l0) {
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_vader_front_comptime$TypeValue_t* _a0_obj = (vader_struct_vader_front_comptime$TypeValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$TypeValue_t));
    vader_obj_header_init(_a0_obj, 1031u);
    _a0_obj->f_value = l0;
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_front_comptime$type_variant_count(vader_box_t l0) {
    void* t0;
    int64_t t1;
    if (l0.tag == 926u) {
        t0 = l0.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants)->length;
        return t1;
    }
    if (!(l0.tag == 906u)) {
        return INT64_C(0);
    }
    t0 = l0.payload.obj;
    t1 = std_collections$len__string__i64(((vader_struct_vader_core_types$EnumType_t*) t0)->f_indices);
    return t1;
}

static void* vader_front_comptime$unary_bit_not(void* l0, vader_box_t l1) {
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
    if (!(l1.tag == 1024u)) {
        t0 = vader_front_comptime$unary_type_mismatch(l0, 1414u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
    l2 = vader_front_comptime$bit_not_i64(t1);
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_type_name;
    t2 = vader_front_comptime$int_val_typed(l2, l3);
    t0 = vader_front_comptime$ok(t2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$unary_neg(void* l0, vader_box_t l1, vader_string_t l2) {
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
    if (l1.tag == 1024u) {
        t0 = l1.payload.obj;
        l3 = vader_front_comptime$result_type_name(t0, l2);
        l4 = vader_front_comptime$int_bits_of(l3);
        l5 = vader_core_types$is_unsigned_int_name(l3);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_front_comptime$IntValue_t*) t0)->f_value;
        l7 = vader_support_integer$checked_negation(l4, l5, l6);
        t0 = vader_front_comptime$checked_result(((vader_struct_toolchain_ast$UnaryExpr_t*) l0)->f_span, l7, l3);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 1023u)) {
        t0 = vader_front_comptime$unary_type_mismatch(l0, 1306u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_value;
    l8 = -(t1);
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_front_comptime$FloatValue_t*) t0)->f_type_name;
    t2 = vader_front_comptime$float_val_typed(l8, l3);
    t0 = vader_front_comptime$ok(t2);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$unary_not(void* l0, vader_box_t l1) {
    void* t0 = NULL;
    void* t2 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 1015u)) {
        t0 = vader_front_comptime$unary_type_mismatch(l0, 1264u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    t1 = ((vader_struct_vader_front_comptime$BoolValue_t*) t0)->f_value;
    if (!(t1)) {
        t0 = (void*) &vader_data_43;
        vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
        t2 = vader_front_comptime$ok(vader_ref_box(t0));
        { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = (void*) &vader_data_44;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    t2 = vader_front_comptime$ok(vader_ref_box(t0));
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$unary_type_mismatch(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void* t1 = NULL;
    void** gc_raw_roots[4] = { &l0, &l2, &t0, &t1 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_toolchain_ast$UnaryExpr_t*) l0)->f_span;
    t0 = vader_support_diagnostics$comptime_error((uint8_t) 4, l2, l1);
    t1 = vader_front_comptime$fail(t0);
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_front_comptime$uniq(void* l0, vader_string_t l1) {
    int32_t l2;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    int64_t l5, l7, l8;
    void* l6 = NULL;
    bool t0;
    void** gc_raw_roots[2] = { &l0, &l6 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = std_collections$add__string(l0, l1);
    if (t0) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = INT32_C(1);
    while ((l2 < INT32_C(1000000))) {
        l4 = l1;
        l5 = vader_host_std_core$byte_len(l4);
        l6 = (void*) vader_buffer_new((size_t) (INT64_C(21) + l5));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l6, l7, l4);
        l7 = std_core$write_string_at(l6, l7, 976u);
        l8 = ((int64_t) (int32_t) l2);
        l7 = std_core$write_int(l6, l7, l8);
        l3 = std_core$finish_buffer(l6, l7);
        t0 = std_collections$add__string(l0, l3);
        if (t0) {
            { vader_string_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = vader_chk_add(i32, l2, INT32_C(1));
    }
    { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_front_comptime$variant_value(void* l0, vader_string_t l1, void* l2) {
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
    if (!(((vader_struct_vader_core_types$EnumType_t*) l0)->f_data.tag == 0u)) {
        t0 = vader_front_comptime$vm_required(l2, 2997u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = std_collections$MutableMap$std_core$Index$at__string__i64(((vader_struct_vader_core_types$EnumType_t*) l0)->f_indices, l1);
    if (l4.tag == 0u) {
        t0 = vader_front_comptime$vm_required(l2, 2813u);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int64_t) l4.payload.i);
    vader_struct_vader_front_comptime$EnumValue_t* _a0_obj = (vader_struct_vader_front_comptime$EnumValue_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EnumValue_t));
    vader_obj_header_init(_a0_obj, 1019u);
    _a0_obj->f_enum_type = l0;
    _a0_obj->f_variant = l1;
    _a0_obj->f_value = l3;
    t0 = (void*) _a0_obj;
    t1 = vader_front_comptime$ok(vader_ref_box(t0));
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_front_comptime$visit(int64_t l0, void* l1, void* l2, void* l3, void* l4, void* l5, void* l6) {
    int32_t l7;
    vader_box_t l8 = vader_box_null();
    void* l9 = NULL;
    int64_t l10, l11;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[2] = { &l8, &t2 };
    void** gc_raw_roots[8] = { &l1, &l2, &l3, &l4, &l5, &l6, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l8 = std_collections$MutableMap$std_core$Index$at__i64__i32(l2, l0);
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = ((int32_t) l8.payload.i);
    if (l7 == INT32_C(2)) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l7 == INT32_C(1)) {
        vader_front_comptime$emit_cycle(l0, l4, l1, l3, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_collections$MutableMap$std_core$IndexSet$set_at__i64__i32(l2, l0, INT32_C(1));
    vader_array_push_i64((vader_array_t*) l4, l0);
    l8 = std_collections$MutableMap$std_core$Index$at__i64__Any(((vader_struct_vader_front_comptime$Nodes_t*) l1)->f_by_id, l0);
    if (!(l8.tag == 0u)) {
        t0 = l8.payload.obj;
        l9 = ((vader_struct_vader_front_comptime$NodeRecord_t*) t0)->f_dependency_ids;
        l10 = ((vader_array_t*) l9)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l11)
            t1 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l11];
            vader_front_comptime$visit(t1, l1, l2, l3, l4, l5, l6);
            l11 = (l11 + INT64_C(1));
        }
    }
    t2 = vader_array_remove_last((vader_array_t*) l4);
    std_collections$MutableMap$std_core$IndexSet$set_at__i64__i32(l2, l0, INT32_C(2));
    t3 = std_collections$MutableSet$std_core$Contains$contains__i64(l3, l0);
    if (t3) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = l8.payload.obj;
    l9 = ((vader_struct_vader_front_comptime$NodeRecord_t*) t0)->f_decl;
    vader_array_push_ref((vader_array_t*) l5, l9);
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_front_comptime$vm_required(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_support_diagnostics$comptime_error((uint8_t) 0, l0, l1);
    vader_struct_vader_front_comptime$EvalResult_t* _a0_obj = (vader_struct_vader_front_comptime$EvalResult_t*) vader_gc_alloc(sizeof(vader_struct_vader_front_comptime$EvalResult_t));
    vader_obj_header_init(_a0_obj, 1020u);
    _a0_obj->f_value = vader_box_obj(0u, NULL);
    _a0_obj->f_diag = vader_ref_box(l2);
    _a0_obj->f_vm_required = true;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t vader_front_comptime$wrap_to_width(int64_t l0, vader_string_t l1) {
    void* l2;
    vader_box_t l3;
    int64_t l4, l5;
    int64_t t0;
    bool t1;
    l3 = vader_support_integer$machine_integer_named(l1);
    if (l3.tag == 0u) {
        return l0;
    }
    l2 = l3.payload.obj;
    t0 = ((vader_struct_vader_support_integer$MachineInteger_t*) l2)->f_bits;
    if (t0 == INT64_C(64)) {
        return l0;
    }
    t1 = ((vader_struct_vader_support_integer$MachineInteger_t*) l2)->f_is_signed;
    if (!(t1)) {
        l4 = ((vader_struct_vader_support_integer$MachineInteger_t*) l2)->f_bits;
        l5 = vader_chk_sub(i64, (INT64_C(1) << (l4 & 63)), INT64_C(1));
        return (l0 & l5);
    }
    l4 = ((vader_struct_vader_support_integer$MachineInteger_t*) l2)->f_bits;
    t0 = vader_front_comptime$sign_extend(l0, l4);
    return t0;
}
