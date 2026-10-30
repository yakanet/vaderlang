#include "bootstrap.split.h"

static void* vader_midir$all_blocks(void* l0);
static vader_string_t vader_midir$array_element_name(vader_box_t l0);
static uint64_t vader_midir$bc_value_bits(vader_box_t l0, vader_string_t l1);
static bool vader_midir$binary_may_trap(void* l0);
static vader_box_t vader_midir$binary_width(void* l0, void* l1);
static bool vader_midir$body_shrinks_by_itself(void* l0);
static void* vader_midir$branch_on_cond(void* l0, vader_box_t l1, int32_t l2, int32_t l3, bool l4);
static vader_box_t vader_midir$build_args(void* l0, void* l1, void* l2);
static vader_box_t vader_midir$build_array_len(void* l0, void* l1);
static vader_box_t vader_midir$build_array_lit(void* l0, void* l1);
static vader_box_t vader_midir$build_array_push(void* l0, void* l1);
static vader_box_t vader_midir$build_array_slice(void* l0, void* l1);
static void vader_midir$build_assign(void* l0, void* l1);
static void vader_midir$build_back_edge(void* l0, void* l1, void* l2);
static vader_box_t vader_midir$build_binary(void* l0, void* l1);
static vader_box_t vader_midir$build_block_body(void* l0, void* l1);
static void vader_midir$build_block_into(void* l0, void* l1, int32_t l2);
static vader_box_t vader_midir$build_block_value(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_midir$build_call(void* l0, void* l1);
static void* vader_midir$build_call_graph(void* l0);
static vader_box_t vader_midir$build_cast(void* l0, void* l1);
static vader_box_t vader_midir$build_cast_source(void* l0, void* l1);
static vader_box_t vader_midir$build_cell_get(void* l0, void* l1);
static vader_box_t vader_midir$build_cell_new(void* l0, void* l1);
static void* vader_midir$build_cfg_resolution(void* l0);
static vader_box_t vader_midir$build_data_const(void* l0, void* l1);
static vader_box_t vader_midir$build_expr(void* l0, vader_box_t l1);
static void vader_midir$build_expr_into(void* l0, vader_box_t l1, int32_t l2);
static vader_box_t vader_midir$build_extern_args(void* l0, void* l1, void* l2, void* l3, vader_string_t l4);
static vader_box_t vader_midir$build_field_access(void* l0, void* l1);
static vader_box_t vader_midir$build_global_get(void* l0, void* l1);
static vader_box_t vader_midir$build_held(void* l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_midir$build_ident(void* l0, void* l1);
static vader_box_t vader_midir$build_if(void* l0, void* l1, vader_box_t l2);
static void vader_midir$build_if_arm(void* l0, void* l1, vader_box_t l2);
static vader_box_t vader_midir$build_index(void* l0, void* l1);
static vader_box_t vader_midir$build_intrinsic_call(void* l0, void* l1);
static void vader_midir$build_labelled_block(void* l0, void* l1);
static void vader_midir$build_loop(void* l0, void* l1);
static vader_box_t vader_midir$build_make_closure(void* l0, void* l1);
static vader_box_t vader_midir$build_module_ident(void* l0, void* l1);
static vader_box_t vader_midir$build_short_circuit(void* l0, void* l1, vader_box_t l2);
static void vader_midir$build_stmt(void* l0, vader_box_t l1);
static vader_box_t vader_midir$build_stored(void* l0, vader_box_t l1);
static vader_box_t vader_midir$build_struct_lit(void* l0, void* l1);
static vader_box_t vader_midir$build_type_check(void* l0, void* l1);
static vader_box_t vader_midir$build_type_const(void* l0, void* l1);
static vader_box_t vader_midir$build_unary(void* l0, void* l1);
static vader_box_t vader_midir$build_union_field(void* l0, void* l1);
static vader_box_t vader_midir$build_unreachable_type(void* l0, vader_box_t l1, void* l2, vader_string_t l3);
static vader_box_t vader_midir$build_virtual_call(void* l0, void* l1);
static int32_t vader_midir$c_variadic_fixed_of(void* l0);
static bool vader_midir$callee_resolves(void* l0, void* l1);
static int32_t vader_midir$cast_local(void* l0, int32_t l1, vader_box_t l2, vader_string_t l3, void* l4);
static void vader_midir$check_instruction_storage(void* l0, vader_box_t l1);
static void vader_midir$check_operation(void* l0, int32_t l1, vader_box_t l2, vader_box_t l3, void* l4);
static void vader_midir$check_return_storage(void* l0, void* l1);
static void vader_midir$check_same_integer(void* l0, void* l1, vader_box_t l2, vader_string_t l3, void* l4);
static void vader_midir$check_slot(void* l0, int32_t l1, vader_box_t l2, void* l3);
static void vader_midir$check_values(void* l0, void* l1, void* l2, void* l3);
static vader_box_t vader_midir$computation_integer(vader_box_t l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_midir$computation_width(vader_box_t l0, vader_box_t l1, vader_box_t l2);
static vader_box_t vader_midir$computed_type(vader_box_t l0, vader_box_t l1);
static vader_box_t vader_midir$const_accessor(void* l0, void* l1);
static void* vader_midir$convert_data_pool(void* l0);
static vader_box_t vader_midir$convert_function(void* l0, void* l1);
static int64_t vader_midir$count_where(int64_t l0, void* l1);
static int32_t vader_midir$declare_local(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3);
static vader_box_t vader_midir$element_slot(vader_box_t l0);
static void vader_midir$emit(void* l0, vader_box_t l1);
static int32_t vader_midir$emit_const(void* l0, vader_box_t l1, vader_box_t l2, void* l3);
static vader_box_t vader_midir$end_after_no_return(void* l0, void* l1, vader_box_t l2);
static bool vader_midir$extern_shrinks_by_itself(void* l0);
static vader_box_t vader_midir$field_read_type(void* l0, int32_t l1, vader_box_t l2);
static vader_box_t vader_midir$field_slot(void* l0, vader_box_t l1, vader_string_t l2);
static void* vader_midir$fn_metadata(void* l0);
static vader_string_t vader_midir$fn_value_kind(vader_box_t l0);
static void* vader_midir$freeze_block(void* l0);
static int32_t vader_midir$fresh_tmp(void* l0, vader_string_t l1, vader_box_t l2);
static vader_box_t vader_midir$function_called(void* l0, void* l1);
static vader_string_t vader_midir$header_of(void* l0, vader_box_t l1);
static int32_t vader_midir$held_in(void* l0, int32_t l1, vader_box_t l2, void* l3);
static int32_t vader_midir$held_use_in(void* l0, int32_t l1, vader_box_t l2, vader_box_t l3, void* l4);
static bool vader_midir$holds_integer(void* l0, int32_t l1);
static void* vader_midir$implicit_return_values(vader_box_t l0, vader_box_t l1);
static vader_box_t vader_midir$import_called(void* l0, void* l1);
static void vader_midir$index_by_name(void* l0, void* l1, vader_string_t l2, vader_box_t l3, int32_t l4);
static void vader_midir$index_function(void* l0, vader_string_t l1, vader_box_t l2, int32_t l3);
static void vader_midir$index_import(void* l0, vader_string_t l1, vader_box_t l2, int32_t l3);
static vader_box_t vader_midir$integer_member(vader_box_t l0, void* l1);
static int32_t vader_midir$intern_string_pool(void* l0, vader_string_t l1);
static int32_t vader_midir$intersect_dom_tree(int32_t l0, int32_t l1, void* l2);
static bool vader_midir$intrinsic_shortens_array(vader_string_t l0);
static bool vader_midir$is_dest_passing_shape(vader_box_t l0);
static bool vader_midir$is_short_circuit_op(uint8_t l0);
static vader_box_t vader_midir$laid_out_fields(void* l0, vader_box_t l1);
static vader_box_t vader_midir$library_of(void* l0, void* l1);
static void* vader_midir$literal_slots(void* l0, vader_box_t l1);
static vader_box_t vader_midir$local_type(void* l0, int32_t l1);
static vader_box_t vader_midir$lowered_to_bc_value(vader_box_t l0);
static void* vader_midir$make_extern_decl(void* l0, void* l1);
static void* vader_midir$make_struct_decl(void* l0);
static void* vader_midir$mangles_reached(void* l0, vader_box_t l1);
static vader_box_t vader_midir$narrowed_local_width(void* l0, vader_box_t l1, vader_box_t l2);
static bool vader_midir$narrowed_read(vader_box_t l0, vader_box_t l1);
static bool vader_midir$narrower(void* l0, vader_box_t l1);
static int32_t vader_midir$new_block(void* l0, void* l1);
static void* vader_midir$new_project_ctx(void* l0, void* l1);
static void* vader_midir$node_callees(void* l0, vader_box_t l1, void* l2);
static void* vader_midir$nodes_of(void* l0);
static void vader_midir$note_params(void* l0, vader_string_t l1, vader_box_t l2, void* l3, bool l4);
static void vader_midir$note_slot_types(void* l0, vader_box_t l1);
static void vader_midir$note_struct_fields(void* l0, void* l1);
static void vader_midir$note_taken(void* l0, vader_box_t l1, void* l2);
static bool vader_midir$only_leaves(void* l0);
static void* vader_midir$operand_edges(vader_box_t l0);
static vader_box_t vader_midir$operand_width(vader_box_t l0, void* l1);
static void* vader_midir$param_types(void* l0);
static void* vader_midir$params_of(void* l0, void* l1);
static vader_box_t vader_midir$place_slot(void* l0, vader_box_t l1, vader_box_t l2);
static void* vader_midir$reachable_blocks(void* l0);
static int32_t vader_midir$read_as(void* l0, int32_t l1, vader_box_t l2, void* l3);
static vader_box_t vader_midir$read_type(vader_box_t l0, vader_box_t l1);
static void* vader_midir$resolve_loop_frame(void* l0, vader_box_t l1);
static bool vader_midir$returns_only_never(void* l0, void* l1);
static bool vader_midir$same_bounds(void* l0, vader_box_t l1);
static bool vader_midir$sets_equal(void* l0, void* l1);
static vader_box_t vader_midir$stored_cell(void* l0, void* l1);
static vader_box_t vader_midir$stored_conversion(vader_box_t l0, vader_box_t l1);
static vader_box_t vader_midir$stored_field(void* l0, void* l1);
static vader_box_t vader_midir$stored_ident(void* l0, void* l1);
static vader_string_t vader_midir$stored_name(vader_box_t l0);
static int32_t vader_midir$stored_slot(void* l0, int32_t l1, void* l2);
static vader_box_t vader_midir$stored_test(void* l0, void* l1);
static vader_box_t vader_midir$stored_union_field(void* l0, void* l1);
static int32_t vader_midir$struct_symbol_id(vader_box_t l0);
static int32_t vader_midir$taken_node(void* l0, void* l1);
static void vader_midir$terminate(void* l0, vader_box_t l1);
static vader_box_t vader_midir$type_at(void* l0, int64_t l1);
static bool vader_midir$verify_block_ids(void* l0, vader_string_t l1, void* l2);
static void vader_midir$verify_cfg_function(void* l0, void* l1, vader_string_t l2, void* l3);
static void vader_midir$verify_fn_references(void* l0, void* l1, void* l2, vader_string_t l3, void* l4);
static void vader_midir$verify_locals(void* l0, void* l1, vader_string_t l2, void* l3);
static void vader_midir$verify_return_arity(void* l0, void* l1, vader_string_t l2, void* l3);
static void vader_midir$verify_storage(void* l0, void* l1, void* l2, vader_string_t l3, void* l4);
static void* vader_midir$virtual_callees(void* l0, void* l1);
static void vader_midir$walk_rpo(void* l0, int32_t l1, void* l2, void* l3);

bool vader_midir$BlockId$std_core$Equals$equals(int32_t l0, int32_t l1) {
    int32_t l2, l3;
    l2 = l0;
    l3 = l1;
    return l2 == l3;
}

uint64_t vader_midir$BlockId$std_core$Hash$hash(int32_t l0) {
    uint64_t t0;
    t0 = std_core$i32$Hash$hash(l0);
    return t0;
}

bool vader_midir$LocalId$std_core$Equals$equals(int32_t l0, int32_t l1) {
    int32_t l2, l3;
    l2 = l0;
    l3 = l1;
    return l2 == l3;
}

uint64_t vader_midir$LocalId$std_core$Hash$hash(int32_t l0) {
    uint64_t t0;
    t0 = std_core$i32$Hash$hash(l0);
    return t0;
}

static void* vader_midir$all_blocks(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    int32_t l6;
    void* t0 = NULL;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 333u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 470u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 613u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    l2 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t0 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l5);
        l6 = ((vader_struct_vader_midir$BasicBlock_t*) t0)->f_id;
        std_collections$add__vader_midir$BlockId(l1, l6);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir$array_element_name(vader_box_t l0) {
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l0.tag == 904u)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    t0 = l0.payload.obj;
    t1 = vader_core_types$representation_name(((vader_struct_vader_core_types$ArrayType_t*) t0)->f_element);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static uint64_t vader_midir$bc_value_bits(vader_box_t l0, vader_string_t l1) {
    void* t0 = NULL;
    int64_t t1;
    uint32_t t2;
    bool t3;
    double t4;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1282u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_lower_ir$LoweredIntLit_t*) t0)->f_value;
        { uint64_t __vret = (uint64_t) (int64_t) t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1267u) {
        t0 = l0.payload.obj;
        t2 = ((vader_struct_vader_lower_ir$LoweredCharLit_t*) t0)->f_value;
        { uint64_t __vret = (uint64_t) (int64_t) ((int64_t) (uint32_t) t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1260u) {
        t0 = l0.payload.obj;
        t3 = ((vader_struct_vader_lower_ir$LoweredBoolLit_t*) t0)->f_value;
        if (t3) {
            { vader_gc_top = gc_frame.prev; return (uint64_t) 1; }
        }
        { vader_gc_top = gc_frame.prev; return (uint64_t) 0; }
    }
    if (!(l0.tag == 1275u)) {
        vader_host_std_abort$panic(2337u);
        vader_unreachable("a no-return call returned");
    }
    if (!(l1 == 1950u)) {
        t0 = l0.payload.obj;
        t4 = ((vader_struct_vader_lower_ir$LoweredFloatLit_t*) t0)->f_value;
        { uint64_t __vret = (uint64_t) (int64_t) (int64_t)(((union { double __vd; uint64_t __vu; }){ .__vd = t4 }).__vu); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l0.payload.obj;
    t4 = ((vader_struct_vader_lower_ir$LoweredFloatLit_t*) t0)->f_value;
    { uint64_t __vret = (uint64_t) (int64_t) ((int64_t) (uint32_t) (int32_t)(((union { float __vf; uint32_t __vb; }){ .__vf = t4 }).__vb)); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir$binary_may_trap(void* l0) {
    uint8_t l1;
    bool l2, l3;
    uint8_t t0;
    bool t1;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_midir$InstrBinOp_t*) l0)->f_op;
    if (l1 == INT32_C(3)) {
        l2 = true;
    } else {
        l2 = l1 == INT32_C(4);
    }
    if (l2) {
        t0 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$InstrBinOp_t*) l0)->f_type);
        t1 = vader_core_bytecode$is_float_val(t0);
        l2 = !(t1);
        { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1 == INT32_C(18)) {
        l3 = true;
    } else {
        l3 = l1 == INT32_C(19);
    }
    if (l3) {
        l3 = true;
    } else {
        l3 = l1 == INT32_C(20);
    }
    if (l3) {
        t0 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$InstrBinOp_t*) l0)->f_type);
        l2 = vader_core_bytecode$is_integer_val(t0);
    } else {
        if (l1 == INT32_C(0)) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(1);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(2);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(5);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(6);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(7);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(8);
        }
        if (l3) {
            l3 = true;
        } else {
            l3 = l1 == INT32_C(9);
        }
        if (l3) {
            l2 = false;
        } else {
            if (l1 == INT32_C(10)) {
                l3 = true;
            } else {
                l3 = l1 == INT32_C(11);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l1 == INT32_C(12);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l1 == INT32_C(13);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l1 == INT32_C(14);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l1 == INT32_C(15);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l1 == INT32_C(16);
            }
            if (l3) {
                l3 = true;
            } else {
                l3 = l1 == INT32_C(17);
            }
            if (!(l3)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l2 = false;
        }
    }
    { bool __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$binary_width(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    bool t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$is_stored_as_integer(((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_type);
    if (!(t0)) {
        l2 = vader_midir$stored_test(l0, l1);
        if (!(l2.tag == 0u)) {
            t1 = l2.payload.obj;
            { vader_box_t __vret = vader_ref_box(t1); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l2 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_left.payload.obj);
    l3 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_right.payload.obj);
    l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_type;
    t2 = vader_midir$computation_width(l2, l3, l4);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir$body_shrinks_by_itself(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t1 = __lambda_vader_midir_26(t0);
        if (t1) {
            { vader_gc_top = gc_frame.prev; return true; }
        }
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static void* vader_midir$branch_on_cond(void* l0, vader_box_t l1, int32_t l2, int32_t l3, bool l4) {
    vader_box_t l5 = vader_box_null();
    void* l6 = NULL;
    void* l10 = NULL;
    bool l7, l8;
    int32_t l9;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[2] = { &l1, &l5 };
    void** gc_raw_roots[4] = { &l0, &l6, &l10, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1300u) {
        t0 = l1.payload.obj;
        if (((vader_struct_vader_lower_ir$LoweredUnary_t*) t0)->f_op == INT32_C(1)) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_lower_ir$LoweredUnary_t*) t0)->f_operand;
            l6 = vader_midir$branch_on_cond(l0, l5, l3, l2, l4);
            l7 = ((vader_struct_vader_midir$CondReach_t*) l6)->f_on_false;
            l8 = ((vader_struct_vader_midir$CondReach_t*) l6)->f_on_true;
            vader_struct_vader_midir$CondReach_t* _a0_obj = (vader_struct_vader_midir$CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CondReach_t));
            vader_obj_header_init(_a0_obj, 1327u);
            _a0_obj->f_on_true = l7;
            _a0_obj->f_on_false = l8;
            t0 = (void*) _a0_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l4) {
        if (l1.tag == 1258u) {
            t0 = l1.payload.obj;
            t1 = vader_midir$is_short_circuit_op(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_op);
            if (t1) {
                t0 = l1.payload.obj;
                l6 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_span, ((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_right.payload.obj);
                l9 = vader_midir$new_block(l0, l6);
                t0 = l1.payload.obj;
                if (((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_op == INT32_C(10)) {
                    t0 = l1.payload.obj;
                    l5 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_left;
                    l6 = vader_midir$branch_on_cond(l0, l5, l9, l3, l4);
                    t1 = ((vader_struct_vader_midir$CondReach_t*) l6)->f_on_true;
                    if (!(t1)) {
                        { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l9);
                    VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
                    t0 = l1.payload.obj;
                    l5 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_right;
                    l10 = vader_midir$branch_on_cond(l0, l5, l2, l3, l4);
                    l7 = ((vader_struct_vader_midir$CondReach_t*) l10)->f_on_true;
                    t1 = ((vader_struct_vader_midir$CondReach_t*) l6)->f_on_false;
                    if (t1) {
                        l8 = true;
                        vader_struct_vader_midir$CondReach_t* _a1_obj = (vader_struct_vader_midir$CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CondReach_t));
                        vader_obj_header_init(_a1_obj, 1327u);
                        _a1_obj->f_on_true = l7;
                        _a1_obj->f_on_false = l8;
                        t0 = (void*) _a1_obj;
                        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                    }
                    l8 = ((vader_struct_vader_midir$CondReach_t*) l10)->f_on_false;
                    vader_struct_vader_midir$CondReach_t* _a2_obj = (vader_struct_vader_midir$CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CondReach_t));
                    vader_obj_header_init(_a2_obj, 1327u);
                    _a2_obj->f_on_true = l7;
                    _a2_obj->f_on_false = l8;
                    t0 = (void*) _a2_obj;
                    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t0 = l1.payload.obj;
                l5 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_left;
                l6 = vader_midir$branch_on_cond(l0, l5, l2, l9, l4);
                t1 = ((vader_struct_vader_midir$CondReach_t*) l6)->f_on_false;
                if (!(t1)) {
                    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
                }
                ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l9);
                VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
                t0 = l1.payload.obj;
                l5 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_right;
                l10 = vader_midir$branch_on_cond(l0, l5, l2, l3, l4);
                t1 = ((vader_struct_vader_midir$CondReach_t*) l6)->f_on_true;
                if (t1) {
                    l7 = true;
                    l8 = ((vader_struct_vader_midir$CondReach_t*) l10)->f_on_false;
                    vader_struct_vader_midir$CondReach_t* _a3_obj = (vader_struct_vader_midir$CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CondReach_t));
                    vader_obj_header_init(_a3_obj, 1327u);
                    _a3_obj->f_on_true = l7;
                    _a3_obj->f_on_false = l8;
                    t0 = (void*) _a3_obj;
                    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
                }
                l7 = ((vader_struct_vader_midir$CondReach_t*) l10)->f_on_true;
                l8 = ((vader_struct_vader_midir$CondReach_t*) l10)->f_on_false;
                vader_struct_vader_midir$CondReach_t* _a4_obj = (vader_struct_vader_midir$CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CondReach_t));
                vader_obj_header_init(_a4_obj, 1327u);
                _a4_obj->f_on_true = l7;
                _a4_obj->f_on_false = l8;
                t0 = (void*) _a4_obj;
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
        }
    }
    vader_struct_vader_midir$CondReach_t* _a5_obj = (vader_struct_vader_midir$CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CondReach_t));
    vader_obj_header_init(_a5_obj, 1327u);
    _a5_obj->f_on_true = false;
    _a5_obj->f_on_false = false;
    l6 = (void*) _a5_obj;
    l5 = vader_midir$build_expr(l0, l1);
    if (l5.tag == 0u) {
        { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l9 = ((int32_t) l5.payload.i);
    if (!(((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir$TermCondBranch_t* _a6_obj = (vader_struct_vader_midir$TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermCondBranch_t));
        vader_obj_header_init(_a6_obj, 1381u);
        _a6_obj->f_span = VADER_UNION_FIELD(void*, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_span, l1.payload.obj);
        _a6_obj->f_cond = l9;
        _a6_obj->f_then_block = l2;
        _a6_obj->f_else_block = l3;
        l10 = (void*) _a6_obj;
        vader_midir$terminate(l0, vader_ref_box(l10));
        vader_struct_vader_midir$CondReach_t* _a7_obj = (vader_struct_vader_midir$CondReach_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CondReach_t));
        vader_obj_header_init(_a7_obj, 1327u);
        _a7_obj->f_on_true = true;
        _a7_obj->f_on_false = true;
        t0 = (void*) _a7_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { void* __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_args(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    int32_t l6;
    vader_box_t l7 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l7, &l8, &l9 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a0_arr;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l1)->length;
    while ((l4 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        l8 = vader_midir$type_at(l2, l4);
        l9 = vader_midir$build_held(l0, l7, l8);
        if (l9.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l6 = ((int32_t) l9.payload.i);
        vader_array_push_i32((vader_array_t*) l3, l6);
        l4 = (l4 + INT64_C(1));
    }
    { vader_box_t __vret = vader_ref_box(l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_array_len(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredArrayLen_t*) l1)->f_target;
    l3 = vader_midir$build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_ir$LoweredArrayLen_t*) l1)->f_type;
    l4 = vader_midir$fresh_tmp(l0, 2263u, l3);
    vader_struct_vader_midir$InstrArrayLen_t* _a0_obj = (vader_struct_vader_midir$InstrArrayLen_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayLen_t));
    vader_obj_header_init(_a0_obj, 1339u);
    _a0_obj->f_span = ((vader_struct_vader_lower_ir$LoweredArrayLen_t*) l1)->f_span;
    _a0_obj->f_dst = l4;
    _a0_obj->f_target = l2;
    l5 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l5));
    { vader_box_t __vret = vader_box_i32(338u, l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_array_lit(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null(), l9 = vader_box_null();
    int64_t l5, l6;
    int32_t l8, l10;
    int64_t t0;
    vader_box_t* gc_roots[3] = { &l3, &l7, &l9 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    l3 = vader_midir$element_slot(((vader_struct_vader_lower_ir$LoweredArrayLit_t*) l1)->f_type);
    l4 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) l1)->f_elements;
    l5 = ((vader_array_t*) l4)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
        l7 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
        l9 = vader_midir$build_held(l0, l7, l3);
        if (l9.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l8 = ((int32_t) l9.payload.i);
        vader_array_push_i32((vader_array_t*) l2, l8);
        l6 = (l6 + INT64_C(1));
    }
    l3 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) l1)->f_type;
    l8 = vader_midir$fresh_tmp(l0, 1554u, l3);
    l4 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) l1)->f_type;
    t0 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) l1)->f_elements)->length;
    l10 = ((int32_t) (int64_t) t0);
    vader_struct_vader_midir$InstrArrayNew_t* _a2_obj = (vader_struct_vader_midir$InstrArrayNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayNew_t));
    vader_obj_header_init(_a2_obj, 1340u);
    _a2_obj->f_span = l4;
    _a2_obj->f_dst = l8;
    _a2_obj->f_type = l3;
    _a2_obj->f_length = l10;
    _a2_obj->f_elements = l2;
    l2 = (void*) _a2_obj;
    vader_midir$emit(l0, vader_ref_box(l2));
    { vader_box_t __vret = vader_box_i32(338u, l8); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_array_push(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    void* l5 = NULL;
    int32_t l6, l7;
    bool l8;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredArrayPush_t*) l1)->f_target;
    l2 = vader_midir$build_expr(l0, l2);
    l3 = ((vader_struct_vader_lower_ir$LoweredArrayPush_t*) l1)->f_value;
    l4 = vader_midir$element_slot(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_ir$LoweredArrayPush_t*) l1)->f_target.payload.obj));
    l3 = vader_midir$build_held(l0, l3, l4);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(l3.tag == 0u)) {
        l5 = ((vader_struct_vader_lower_ir$LoweredArrayPush_t*) l1)->f_span;
        l6 = ((int32_t) l2.payload.i);
        l7 = ((int32_t) l3.payload.i);
        l8 = ((vader_struct_vader_lower_ir$LoweredArrayPush_t*) l1)->f_cached;
        vader_struct_vader_midir$InstrArrayPush_t* _a0_obj = (vader_struct_vader_midir$InstrArrayPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayPush_t));
        vader_obj_header_init(_a0_obj, 1341u);
        _a0_obj->f_span = l5;
        _a0_obj->f_target = l6;
        _a0_obj->f_value = l7;
        _a0_obj->f_cached = l8;
        l5 = (void*) _a0_obj;
        vader_midir$emit(l0, vader_ref_box(l5));
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_midir$build_array_slice(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l5 = vader_box_null(), l6 = vader_box_null();
    void* l4 = NULL;
    int32_t l7, l8, l9, l10;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l5, &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredArraySlice_t*) l1)->f_target;
    l2 = vader_midir$build_expr(l0, l2);
    l3 = ((vader_struct_vader_lower_ir$LoweredArraySlice_t*) l1)->f_lo;
    t0 = (void*) &vader_data_23;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT64_C(0));
    l3 = vader_midir$build_held(l0, l3, vader_ref_box(l4));
    l5 = ((vader_struct_vader_lower_ir$LoweredArraySlice_t*) l1)->f_hi;
    t0 = (void*) &vader_data_23;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l4 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    l5 = vader_midir$build_held(l0, l5, vader_ref_box(l4));
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(l5.tag == 0u)) {
        l6 = ((vader_struct_vader_lower_ir$LoweredArraySlice_t*) l1)->f_type;
        l7 = vader_midir$fresh_tmp(l0, 2565u, l6);
        l4 = ((vader_struct_vader_lower_ir$LoweredArraySlice_t*) l1)->f_span;
        l6 = ((vader_struct_vader_lower_ir$LoweredArraySlice_t*) l1)->f_type;
        l8 = ((int32_t) l2.payload.i);
        l9 = ((int32_t) l3.payload.i);
        l10 = ((int32_t) l5.payload.i);
        vader_struct_vader_midir$InstrArraySlice_t* _a2_obj = (vader_struct_vader_midir$InstrArraySlice_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArraySlice_t));
        vader_obj_header_init(_a2_obj, 1343u);
        _a2_obj->f_span = l4;
        _a2_obj->f_dst = l7;
        _a2_obj->f_type = l6;
        _a2_obj->f_target = l8;
        _a2_obj->f_lo = l9;
        _a2_obj->f_hi = l10;
        l4 = (void*) _a2_obj;
        vader_midir$emit(l0, vader_ref_box(l4));
        { vader_box_t __vret = vader_box_i32(338u, l7); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void vader_midir$build_assign(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l8 = vader_box_null(), l10 = vader_box_null(), l12 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    int32_t l4, l11, l13;
    vader_string_t l7 = 0;
    int64_t l9;
    bool l14;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_string_t t3 = 0;
    int32_t t2;
    vader_box_t* gc_roots[5] = { &l2, &l5, &l8, &l10, &l12 };
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l6, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l7, &t1, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredAssign_t*) l1)->f_target;
    if (l2.tag == 1279u) {
        l3 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_local_by_sym_id;
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
        l5 = std_collections$MutableMap$std_core$Index$at__i32__i32(l3, l4);
        if (l5.tag == 0u) {
            l3 = ((vader_struct_vader_midir$ProjectCtx_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_project)->f_diags;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_span;
            t0 = l2.payload.obj;
            l7 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_name;
            t1 = concat_3(1035u, l7, 1146u);
            l7 = concat_2(t1, 2717u);
            l6 = vader_support_diagnostics$lower_error((uint8_t) 3, l6, l7);
            vader_array_push_ref((vader_array_t*) l3, l6);
            { vader_gc_top = gc_frame.prev; return; }
        }
        l8 = ((vader_struct_vader_lower_ir$LoweredAssign_t*) l1)->f_value;
        l3 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_locals;
        t2 = ((int32_t) l5.payload.i);
        l9 = ((int64_t) (int32_t) t2);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l9)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l9);
        l10 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
        l8 = vader_midir$build_held(l0, l8, l10);
        if (l8.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        l4 = ((int32_t) l8.payload.i);
        l3 = ((vader_struct_vader_lower_ir$LoweredAssign_t*) l1)->f_span;
        l11 = ((int32_t) l5.payload.i);
        vader_struct_vader_midir$InstrMove_t* _a1_obj = (vader_struct_vader_midir$InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMove_t));
        vader_obj_header_init(_a1_obj, 1363u);
        _a1_obj->f_span = l3;
        _a1_obj->f_dst = l11;
        _a1_obj->f_src = l4;
        l3 = (void*) _a1_obj;
        vader_midir$emit(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 1274u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) t0)->f_target;
        l5 = vader_midir$build_expr(l0, l5);
        l8 = ((vader_struct_vader_lower_ir$LoweredAssign_t*) l1)->f_value;
        l3 = l2.payload.obj;
        l10 = vader_midir$place_slot(l0, l5, vader_ref_box(l3));
        l8 = vader_midir$build_held(l0, l8, l10);
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (!(l8.tag == 0u)) {
            l3 = ((vader_struct_vader_lower_ir$LoweredAssign_t*) l1)->f_span;
            l4 = ((int32_t) l5.payload.i);
            t0 = l2.payload.obj;
            l7 = ((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) t0)->f_field;
            l11 = ((int32_t) l8.payload.i);
            vader_struct_vader_midir$InstrFieldSet_t* _a2_obj = (vader_struct_vader_midir$InstrFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFieldSet_t));
            vader_obj_header_init(_a2_obj, 1356u);
            _a2_obj->f_span = l3;
            _a2_obj->f_target = l4;
            _a2_obj->f_field = l7;
            _a2_obj->f_value = l11;
            _a2_obj->f_barrierless = false;
            l3 = (void*) _a2_obj;
            vader_midir$emit(l0, vader_ref_box(l3));
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l2.tag == 1301u) {
        t0 = l2.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredUnionField_t*) t0)->f_target;
        l5 = vader_midir$build_expr(l0, l5);
        l8 = ((vader_struct_vader_lower_ir$LoweredAssign_t*) l1)->f_value;
        l3 = l2.payload.obj;
        l10 = vader_midir$place_slot(l0, l5, vader_ref_box(l3));
        l8 = vader_midir$build_held(l0, l8, l10);
        if (l5.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        if (!(l8.tag == 0u)) {
            l3 = ((vader_struct_vader_lower_ir$LoweredAssign_t*) l1)->f_span;
            l4 = ((int32_t) l5.payload.i);
            t0 = l2.payload.obj;
            l7 = ((vader_struct_vader_lower_ir$LoweredUnionField_t*) t0)->f_field;
            l11 = ((int32_t) l8.payload.i);
            vader_struct_vader_midir$InstrUnionFieldSet_t* _a3_obj = (vader_struct_vader_midir$InstrUnionFieldSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrUnionFieldSet_t));
            vader_obj_header_init(_a3_obj, 1369u);
            _a3_obj->f_span = l3;
            _a3_obj->f_target = l4;
            _a3_obj->f_field = l7;
            _a3_obj->f_value = l11;
            l3 = (void*) _a3_obj;
            vader_midir$emit(l0, vader_ref_box(l3));
            { vader_gc_top = gc_frame.prev; return; }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l2.tag == 1281u)) {
        l7 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_mangled;
        t1 = concat_3(2335u, l7, 1311u);
        t3 = concat_2(t1, 2764u);
        vader_host_std_abort$panic(t3);
        vader_unreachable("a no-return call returned");
    }
    t0 = l2.payload.obj;
    l5 = ((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_target;
    l5 = vader_midir$build_expr(l0, l5);
    t0 = l2.payload.obj;
    l8 = ((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_index;
    l8 = vader_midir$build_expr(l0, l8);
    l10 = ((vader_struct_vader_lower_ir$LoweredAssign_t*) l1)->f_value;
    l3 = l2.payload.obj;
    l12 = vader_midir$place_slot(l0, l5, vader_ref_box(l3));
    l10 = vader_midir$build_held(l0, l10, l12);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l8.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l10.tag == 0u)) {
        l3 = ((vader_struct_vader_lower_ir$LoweredAssign_t*) l1)->f_span;
        l4 = ((int32_t) l5.payload.i);
        l11 = ((int32_t) l8.payload.i);
        l13 = ((int32_t) l10.payload.i);
        t0 = l2.payload.obj;
        l14 = ((vader_struct_vader_lower_ir$LoweredIndex_t*) t0)->f_bounds_safe;
        vader_struct_vader_midir$InstrArraySet_t* _a4_obj = (vader_struct_vader_midir$InstrArraySet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArraySet_t));
        vader_obj_header_init(_a4_obj, 1342u);
        _a4_obj->f_span = l3;
        _a4_obj->f_target = l4;
        _a4_obj->f_index = l11;
        _a4_obj->f_value = l13;
        _a4_obj->f_bounds_safe = l14;
        l3 = (void*) _a4_obj;
        vader_midir$emit(l0, vader_ref_box(l3));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$build_back_edge(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    int32_t l7;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$LoopFrame_t*) l1)->f_step;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        vader_midir$build_stmt(l0, l6);
        l5 = (l5 + INT64_C(1));
    }
    if (((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l7 = ((vader_struct_vader_midir$LoopFrame_t*) l1)->f_header_id;
    vader_struct_vader_midir$TermBranch_t* _a1_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
    vader_obj_header_init(_a1_obj, 1380u);
    _a1_obj->f_span = l2;
    _a1_obj->f_target = l7;
    l3 = (void*) _a1_obj;
    vader_midir$terminate(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir$build_binary(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null();
    int32_t l3, l5, l7;
    vader_string_t l6 = 0;
    void* l8 = NULL;
    uint8_t l9;
    bool t0;
    vader_box_t t1 = vader_box_null();
    int32_t t2;
    vader_box_t* gc_roots[3] = { &l2, &l4, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &l8 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = vader_midir$is_short_circuit_op(((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_op);
    if (t0) {
        t1 = vader_midir$build_short_circuit(l0, l1, vader_box_obj(0u, NULL));
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_midir$binary_width(l0, l1);
    l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_left;
    l4 = vader_midir$build_held(l0, l4, l2);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((int32_t) l4.payload.i);
    l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_right;
    l4 = vader_midir$build_held(l0, l4, l2);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l5 = ((int32_t) l4.payload.i);
    l2 = vader_midir$computed_type(((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_type, l2);
    l6 = vader_lower_ir$binary_op_name(((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_op);
    l7 = vader_midir$fresh_tmp(l0, l6, l2);
    l8 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_span;
    l9 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_op;
    vader_struct_vader_midir$InstrBinOp_t* _a0_obj = (vader_struct_vader_midir$InstrBinOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrBinOp_t));
    vader_obj_header_init(_a0_obj, 1344u);
    _a0_obj->f_span = l8;
    _a0_obj->f_dst = l7;
    _a0_obj->f_op = l9;
    _a0_obj->f_lhs = l3;
    _a0_obj->f_rhs = l5;
    _a0_obj->f_type = l2;
    l8 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l8));
    l2 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_type;
    l8 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_span;
    t2 = vader_midir$held_in(l0, l7, l2, l8);
    { vader_box_t __vret = vader_box_i32(338u, t2); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_block_body(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_type;
    t0 = vader_midir$build_block_value(l0, l1, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir$build_block_into(void* l0, void* l1, int32_t l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_stmts;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return; }
        }
        vader_midir$build_stmt(l0, l6);
        l5 = (l5 + INT64_C(1));
    }
    if (((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_trailing.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l6 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_trailing;
    vader_midir$build_expr_into(l0, l6, l2);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir$build_block_value(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l6, &t0 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_stmts;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
        l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
        if (((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        vader_midir$build_stmt(l0, l6);
        l5 = (l5 + INT64_C(1));
    }
    if (((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_trailing.tag == 0u)) {
        l6 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l1)->f_trailing;
        t0 = vader_midir$build_held(l0, l6, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_midir$build_call(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null(), l11 = vader_box_null();
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    int32_t l4;
    vader_string_t l9 = 0;
    bool l10;
    void* t0 = NULL;
    bool t1;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l5, &l11, &t3 };
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l6, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_callee;
    if (l2.tag == 1279u) {
        t0 = l2.payload.obj;
        if (((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_kind == INT32_C(0)) {
            l3 = ((vader_struct_vader_midir$ProjectCtx_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_project)->f_extern_callbacks;
            t0 = l2.payload.obj;
            l4 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
            l5 = std_collections$MutableMap$std_core$Index$at__i32__Any(l3, l4);
            l3 = ((vader_struct_vader_midir$ProjectCtx_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_project)->f_slots;
            t0 = l2.payload.obj;
            l6 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol;
            l3 = vader_midir$params_of(l3, l6);
            if (l5.tag == 614u) {
                l7 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_args;
                l8 = l5.payload.obj;
                t0 = l2.payload.obj;
                l9 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_name;
                l5 = vader_midir$build_extern_args(l0, l7, l3, l8, l9);
                if (l5.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                l6 = l5.payload.obj;
            } else {
                l7 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_args;
                l5 = vader_midir$build_args(l0, l7, l3);
                if (l5.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                l6 = l5.payload.obj;
            }
            t1 = vader_core_types$is_void(((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_type);
            if (t1) {
                l10 = true;
            } else {
                l10 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_type.tag == 913u;
            }
            if (l10) {
                l5 = vader_box_obj(0u, NULL);
            } else {
                l11 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_type;
                t2 = vader_midir$fresh_tmp(l0, 1704u, l11);
                l5 = vader_box_i32(338u, t2);
            }
            l3 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_span;
            if (l5.tag == 0u) {
                vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
                l7 = (void*) _a0_arr;
            } else {
                t2 = ((int32_t) l5.payload.i);
                vader_array_t* _a1_arr = vader_array_new(23u, 1u, 7u, 338u);
                ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) t2;
                l7 = (void*) _a1_arr;
            }
            t0 = l2.payload.obj;
            l8 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol;
            l2 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_type;
            vader_struct_vader_midir$InstrCall_t* _a2_obj = (vader_struct_vader_midir$InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCall_t));
            vader_obj_header_init(_a2_obj, 1345u);
            _a2_obj->f_span = l3;
            _a2_obj->f_dsts = l7;
            _a2_obj->f_callee = l8;
            _a2_obj->f_args = l6;
            _a2_obj->f_type = l2;
            l3 = (void*) _a2_obj;
            vader_midir$emit(l0, vader_ref_box(l3));
            t3 = vader_midir$end_after_no_return(l0, l1, l5);
            { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l2 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_callee;
    l2 = vader_midir$build_expr(l0, l2);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = ((int32_t) l2.payload.i);
    l6 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_args;
    l7 = vader_core_types$param_types_of(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_callee.payload.obj));
    l2 = vader_midir$build_args(l0, l6, l7);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l2.payload.obj;
    t1 = vader_core_types$is_void(((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_type);
    if (t1) {
        l10 = true;
    } else {
        l10 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_type.tag == 913u;
    }
    if (l10) {
        l2 = vader_box_obj(0u, NULL);
    } else {
        l5 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_type;
        t2 = vader_midir$fresh_tmp(l0, 1712u, l5);
        l2 = vader_box_i32(338u, t2);
    }
    l6 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_span;
    l5 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_callee.payload.obj);
    l11 = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_type;
    vader_struct_vader_midir$InstrCallIndirect_t* _a3_obj = (vader_struct_vader_midir$InstrCallIndirect_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCallIndirect_t));
    vader_obj_header_init(_a3_obj, 1346u);
    _a3_obj->f_span = l6;
    _a3_obj->f_dst = l2;
    _a3_obj->f_callee = l4;
    _a3_obj->f_args = l3;
    _a3_obj->f_fn_type = l5;
    _a3_obj->f_type = l11;
    l3 = (void*) _a3_obj;
    vader_midir$emit(l0, vader_ref_box(l3));
    t3 = vader_midir$end_after_no_return(l0, l1, l2);
    { vader_box_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir$build_call_graph(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l16 = NULL;
    int32_t l4, l7, l8;
    int64_t l9, l10;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    vader_box_t l17 = vader_box_null();
    int64_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l17 };
    void** gc_raw_roots[10] = { &l0, &l1, &l2, &l3, &l5, &l6, &l14, &l15, &l16, &t1 };
    vader_string_t* gc_atom_roots[3] = { &l11, &l12, &l13 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir$build_cfg_resolution(l0);
    vader_array_t* _a0_arr = vader_array_new(266u, 0u, 13u, 2104u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_midir$CfgResolution_t*) l1)->f_functions;
    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l3);
    l3 = ((vader_struct_vader_midir$CfgResolution_t*) l1)->f_externs;
    vader_array_push_all((vader_array_t*) l2, (vader_array_t*) l3);
    t0 = ((vader_array_t*) l2)->length;
    l4 = ((int32_t) (int64_t) t0);
    vader_struct_vader_midir$IndirectCalls_t* _a1_obj = (vader_struct_vader_midir$IndirectCalls_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$IndirectCalls_t));
    vader_obj_header_init(_a1_obj, 1337u);
    l3 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l2, l3);
    vader_struct_vader_midir$ForeignCallbacks_t* _a2_obj = (vader_struct_vader_midir$ForeignCallbacks_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ForeignCallbacks_t));
    vader_obj_header_init(_a2_obj, 1336u);
    l3 = (void*) _a2_obj;
    vader_array_push_ref((vader_array_t*) l2, l3);
    vader_struct_vader_midir$UnknownCallee_t* _a3_obj = (vader_struct_vader_midir$UnknownCallee_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$UnknownCallee_t));
    vader_obj_header_init(_a3_obj, 1384u);
    l3 = (void*) _a3_obj;
    vader_array_push_ref((vader_array_t*) l2, l3);
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 0u, 335u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(29u, 0u, 0u, 346u);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__string__Any___t* _a7_obj = (vader_struct_std_collections$MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any___t));
    vader_obj_header_init(_a7_obj, 542u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l5;
    _a7_obj->f_index = l6;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a7_obj;
    l7 = vader_chk_add(i32, l4, INT32_C(1));
    l8 = vader_chk_add(i32, l4, INT32_C(2));
    vader_struct_vader_midir$CalleeIndex_t* _a8_obj = (vader_struct_vader_midir$CalleeIndex_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CalleeIndex_t));
    vader_obj_header_init(_a8_obj, 1324u);
    _a8_obj->f_resolution = l1;
    _a8_obj->f_virtual_targets = l3;
    _a8_obj->f_indirect = l4;
    _a8_obj->f_foreign_callbacks = l7;
    _a8_obj->f_unknown = l8;
    l1 = (void*) _a8_obj;
    l3 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_vtable_entries;
    l9 = ((vader_array_t*) l3)->length;
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a9_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l10)
        l5 = vader_array_ref_load_obj(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l10);
        l11 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l5)->f_trait_name;
        l12 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l5)->f_method_name;
        l13 = vader_midir$vtable_key(l11, l12);
        l6 = ((vader_struct_vader_midir$CalleeIndex_t*) l1)->f_virtual_targets;
        l14 = (void*) &vader_fn_static___lambda_vader_midir_10;
        l15 = std_collections$get_or_put_with__string__i32__(l6, l13, l14);
        l16 = ((vader_struct_vader_lower_ir$LoweredVtableEntry_t*) l5)->f_fn_symbol;
        l4 = vader_midir$callee_node(l1, l16);
        vader_array_push_i32((vader_array_t*) l15, l4);
        l10 = (l10 + INT64_C(1));
    }
    vader_array_t* _a10_arr = vader_array_new(3u, 0u, 13u, 23u);
    l3 = (void*) _a10_arr;
    l9 = ((vader_array_t*) l2)->length;
    vader_array_t* _a11_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l9);
    l3 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(20u, 0u, 12u, 333u);
    l6 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(23u, 0u, 7u, 338u);
    l14 = (void*) _a14_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a15_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a15_obj, 470u);
    _a15_obj->f_ekeys = l5;
    _a15_obj->f_evals = l6;
    _a15_obj->f_index = l14;
    _a15_obj->f_mask = INT64_C(0);
    _a15_obj->f_grow_at = INT64_C(0);
    _a15_obj->f_size = INT64_C(0);
    _a15_obj->f_tombs = INT64_C(0);
    t1 = (void*) _a15_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a16_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a16_obj, 613u);
    _a16_obj->f_inner = t1;
    l5 = (void*) _a16_obj;
    vader_array_t* _a17_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(20u, 0u, 12u, 333u);
    l14 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(23u, 0u, 7u, 338u);
    l15 = (void*) _a19_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a20_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a20_obj, 470u);
    _a20_obj->f_ekeys = l6;
    _a20_obj->f_evals = l14;
    _a20_obj->f_index = l15;
    _a20_obj->f_mask = INT64_C(0);
    _a20_obj->f_grow_at = INT64_C(0);
    _a20_obj->f_size = INT64_C(0);
    _a20_obj->f_tombs = INT64_C(0);
    t1 = (void*) _a20_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a21_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a21_obj, 613u);
    _a21_obj->f_inner = t1;
    l6 = (void*) _a21_obj;
    vader_struct_vader_midir$TakenFunctions_t* _a22_obj = (vader_struct_vader_midir$TakenFunctions_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TakenFunctions_t));
    vader_obj_header_init(_a22_obj, 1379u);
    _a22_obj->f_as_values = l5;
    _a22_obj->f_as_addresses = l6;
    l5 = (void*) _a22_obj;
    l6 = l2;
    l9 = ((vader_array_t*) l6)->length;
    l10 = INT64_C(0);
    while ((l10 < l9)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        l17 = vader_array_ref_load_box(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l10);
        l14 = vader_midir$node_callees(l1, l17, l5);
        vader_array_push_ref((vader_array_t*) l3, l14);
        l10 = (l10 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_midir$CalleeIndex_t*) l1)->f_indirect;
    l6 = vader_midir$nodes_of(((vader_struct_vader_midir$TakenFunctions_t*) l5)->f_as_values);
    vader_array_t* _a24_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a24_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a24_slotarr, l4)
    vader_array_ref_store(_a24_slotarr->buf, _a24_slotarr->offset + (size_t) l4, l6);
    VADER_WRITE_BARRIER(_a24_slotarr->buf);
    l4 = ((vader_struct_vader_midir$CalleeIndex_t*) l1)->f_foreign_callbacks;
    l5 = vader_midir$nodes_of(((vader_struct_vader_midir$TakenFunctions_t*) l5)->f_as_addresses);
    vader_array_t* _a25_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a25_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a25_slotarr, l4)
    vader_array_ref_store(_a25_slotarr->buf, _a25_slotarr->offset + (size_t) l4, l5);
    VADER_WRITE_BARRIER(_a25_slotarr->buf);
    vader_struct_vader_support_fixpoint$Graph_t* _a26_obj = (vader_struct_vader_support_fixpoint$Graph_t*) vader_gc_alloc(sizeof(vader_struct_vader_support_fixpoint$Graph_t));
    vader_obj_header_init(_a26_obj, 1411u);
    _a26_obj->f_successors = l3;
    t1 = (void*) _a26_obj;
    vader_struct_vader_midir$CallGraph_t* _a27_obj = (vader_struct_vader_midir$CallGraph_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CallGraph_t));
    vader_obj_header_init(_a27_obj, 1323u);
    _a27_obj->f_graph = t1;
    _a27_obj->f_nodes = l2;
    _a27_obj->f_index = l1;
    t1 = (void*) _a27_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_cast(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir$build_cast_source(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_ir$LoweredCast_t*) l1)->f_type;
    l4 = ((vader_struct_vader_lower_ir$LoweredCast_t*) l1)->f_span;
    t0 = vader_midir$cast_local(l0, l2, l3, 1739u, l4);
    { vader_box_t __vret = vader_box_i32(338u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_cast_source(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l2, &t1 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$is_stored_as_integer(((vader_struct_vader_lower_ir$LoweredCast_t*) l1)->f_type);
    if (!(t0)) {
        l2 = ((vader_struct_vader_lower_ir$LoweredCast_t*) l1)->f_value;
        t1 = vader_midir$build_expr(l0, l2);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = ((vader_struct_vader_lower_ir$LoweredCast_t*) l1)->f_value;
    t1 = vader_midir$build_stored(l0, l2);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_cell_get(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir$stored_cell(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_ir$LoweredCellGet_t*) l1)->f_type;
    l4 = ((vader_struct_vader_lower_ir$LoweredCellGet_t*) l1)->f_span;
    t0 = vader_midir$read_as(l0, l2, l3, l4);
    { vader_box_t __vret = vader_box_i32(338u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_cell_new(void* l0, void* l1) {
    int32_t l2, l5;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l6 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredCellNew_t*) l1)->f_value;
    l4 = ((vader_struct_vader_lower_ir$LoweredCellNew_t*) l1)->f_value_type;
    l3 = vader_midir$build_held(l0, l3, l4);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_ir$LoweredCellNew_t*) l1)->f_type;
    l5 = vader_midir$fresh_tmp(l0, 1740u, l3);
    l6 = ((vader_struct_vader_lower_ir$LoweredCellNew_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_ir$LoweredCellNew_t*) l1)->f_value_type;
    vader_struct_vader_midir$InstrCellNew_t* _a0_obj = (vader_struct_vader_midir$InstrCellNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCellNew_t));
    vader_obj_header_init(_a0_obj, 1349u);
    _a0_obj->f_span = l6;
    _a0_obj->f_dst = l5;
    _a0_obj->f_value = l2;
    _a0_obj->f_value_type = l3;
    l6 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l6));
    { vader_box_t __vret = vader_box_i32(338u, l5); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir$build_cfg_project(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    void* l20 = NULL;
    void* l21 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l27 = NULL;
    int64_t l7, l8, l16, l17;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    vader_string_t l25 = 0;
    vader_string_t l26 = 0;
    vader_box_t l18 = vader_box_null(), l22 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l18, &l22, &t0 };
    void** gc_raw_roots[19] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l11, &l12, &l13, &l14, &l15, &l19, &l20, &l21, &l23,
        &l24, &l27, &t1,
    };
    vader_string_t* gc_atom_roots[4] = { &l9, &l10, &l25, &l26 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 19u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_midir$new_project_ctx(l0, l1);
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__Any_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any_t));
    vader_obj_header_init(_a3_obj, 541u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    l4 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l4)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l7)
        t0 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) l7];
        l9 = t0.payload.s;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l7)
        l4 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l7);
        l10 = l9;
        l11 = l4;
        vader_array_t* _a6_arr = vader_array_new(202u, 0u, 13u, 1316u);
        l12 = (void*) _a6_arr;
        vader_array_t* _a7_arr = vader_array_new(201u, 0u, 13u, 1315u);
        l13 = (void*) _a7_arr;
        vader_array_t* _a8_arr = vader_array_new(206u, 0u, 13u, 1321u);
        l14 = (void*) _a8_arr;
        l15 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l11)->f_decls;
        l16 = ((vader_array_t*) l15)->length;
        l17 = INT64_C(0);
        while ((l17 < l16)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l15);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a9_slotarr, l17)
            l18 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l17);
            if (l18.tag == 1276u) {
                t1 = l18.payload.obj;
                if (((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t1)->f_body.tag == 0u) {
                    l19 = l18.payload.obj;
                    l20 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_libraries;
                    l21 = vader_midir$make_extern_decl(l19, l20);
                    vader_array_push_ref((vader_array_t*) l13, l21);
                } else {
                    t1 = l18.payload.obj;
                    l22 = vader_midir$convert_function(t1, l2);
                    if (!(l22.tag == 0u)) {
                        l23 = l22.payload.obj;
                        vader_array_push_ref((vader_array_t*) l12, l23);
                    }
                }
            } else if (l18.tag == 1294u) {
                t1 = l18.payload.obj;
                l24 = vader_midir$make_struct_decl(t1);
                vader_array_push_ref((vader_array_t*) l14, l24);
            } else if (!(l18.tag == 1268u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            l17 = (l17 + INT64_C(1));
        }
        l25 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l11)->f_module_id;
        l26 = ((vader_struct_vader_lower_ir$LoweredModule_t*) l11)->f_display_path;
        vader_struct_vader_midir$CFGModule_t* _a10_obj = (vader_struct_vader_midir$CFGModule_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGModule_t));
        vader_obj_header_init(_a10_obj, 1318u);
        _a10_obj->f_module_id = l25;
        _a10_obj->f_display_path = l26;
        _a10_obj->f_functions = l12;
        _a10_obj->f_externs = l13;
        _a10_obj->f_struct_decls = l14;
        l27 = (void*) _a10_obj;
        std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l3, l10, vader_ref_box(l27));
        l7 = (l7 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_vtable_entries;
    l2 = ((vader_struct_vader_midir$ProjectCtx_t*) l2)->f_strings;
    l5 = vader_midir$convert_data_pool(((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_data_pool);
    l6 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_globals;
    l11 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_trait_membership;
    vader_struct_vader_midir$CFGProject_t* _a11_obj = (vader_struct_vader_midir$CFGProject_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGProject_t));
    vader_obj_header_init(_a11_obj, 1320u);
    _a11_obj->f_modules = l3;
    _a11_obj->f_vtable_entries = l4;
    _a11_obj->f_strings = l2;
    _a11_obj->f_data_pool = l5;
    _a11_obj->f_globals = l6;
    _a11_obj->f_trait_membership = l11;
    t1 = (void*) _a11_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir$build_cfg_resolution(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l19 = NULL;
    void* l22 = NULL;
    void* l23 = NULL;
    void* l26 = NULL;
    int64_t l11, l12, l13, l14, l17, l18, l24, l25;
    vader_string_t l15 = 0;
    vader_string_t l20 = 0;
    vader_box_t l16 = vader_box_null(), l21 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l16, &l21, &t0 };
    void** gc_raw_roots[16] = {
        &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &l19, &l22, &l23, &l26, &t2,
    };
    vader_string_t* gc_atom_roots[3] = { &l15, &l20, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 16u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(202u, 0u, 13u, 1316u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(201u, 0u, 13u, 1315u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(22u, 0u, 0u, 335u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(29u, 0u, 0u, 346u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a4_arr;
    vader_struct_std_collections$MutableMap__string__Any___t* _a5_obj = (vader_struct_std_collections$MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any___t));
    vader_obj_header_init(_a5_obj, 542u);
    _a5_obj->f_ekeys = l3;
    _a5_obj->f_evals = l4;
    _a5_obj->f_index = l5;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a5_obj;
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 7u, 338u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(29u, 0u, 0u, 346u);
    l5 = (void*) _a7_arr;
    vader_array_t* _a8_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a8_arr;
    vader_struct_std_collections$MutableMap__i32__Any___t* _a9_obj = (vader_struct_std_collections$MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any___t));
    vader_obj_header_init(_a9_obj, 468u);
    _a9_obj->f_ekeys = l4;
    _a9_obj->f_evals = l5;
    _a9_obj->f_index = l6;
    _a9_obj->f_mask = INT64_C(0);
    _a9_obj->f_grow_at = INT64_C(0);
    _a9_obj->f_size = INT64_C(0);
    _a9_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a9_obj;
    vader_array_t* _a10_arr = vader_array_new(22u, 0u, 0u, 335u);
    l5 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a12_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a13_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a13_obj, 548u);
    _a13_obj->f_ekeys = l5;
    _a13_obj->f_evals = l6;
    _a13_obj->f_index = l7;
    _a13_obj->f_mask = INT64_C(0);
    _a13_obj->f_grow_at = INT64_C(0);
    _a13_obj->f_size = INT64_C(0);
    _a13_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a13_obj;
    vader_array_t* _a14_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(23u, 0u, 7u, 338u);
    l8 = (void*) _a16_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a17_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a17_obj, 471u);
    _a17_obj->f_ekeys = l6;
    _a17_obj->f_evals = l7;
    _a17_obj->f_index = l8;
    _a17_obj->f_mask = INT64_C(0);
    _a17_obj->f_grow_at = INT64_C(0);
    _a17_obj->f_size = INT64_C(0);
    _a17_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a17_obj;
    vader_array_t* _a18_arr = vader_array_new(22u, 0u, 0u, 335u);
    l7 = (void*) _a18_arr;
    vader_array_t* _a19_arr = vader_array_new(23u, 0u, 7u, 338u);
    l8 = (void*) _a19_arr;
    vader_array_t* _a20_arr = vader_array_new(23u, 0u, 7u, 338u);
    l9 = (void*) _a20_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a21_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a21_obj, 548u);
    _a21_obj->f_ekeys = l7;
    _a21_obj->f_evals = l8;
    _a21_obj->f_index = l9;
    _a21_obj->f_mask = INT64_C(0);
    _a21_obj->f_grow_at = INT64_C(0);
    _a21_obj->f_size = INT64_C(0);
    _a21_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a21_obj;
    vader_array_t* _a22_arr = vader_array_new(23u, 0u, 7u, 338u);
    l8 = (void*) _a22_arr;
    vader_array_t* _a23_arr = vader_array_new(23u, 0u, 7u, 338u);
    l9 = (void*) _a23_arr;
    vader_array_t* _a24_arr = vader_array_new(23u, 0u, 7u, 338u);
    l10 = (void*) _a24_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a25_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a25_obj, 471u);
    _a25_obj->f_ekeys = l8;
    _a25_obj->f_evals = l9;
    _a25_obj->f_index = l10;
    _a25_obj->f_mask = INT64_C(0);
    _a25_obj->f_grow_at = INT64_C(0);
    _a25_obj->f_size = INT64_C(0);
    _a25_obj->f_tombs = INT64_C(0);
    l8 = (void*) _a25_obj;
    vader_struct_vader_midir$CalleeLookup_t* _a26_obj = (vader_struct_vader_midir$CalleeLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CalleeLookup_t));
    vader_obj_header_init(_a26_obj, 1325u);
    _a26_obj->f_fn_by_mangle = l5;
    _a26_obj->f_fn_by_symbol = l6;
    _a26_obj->f_import_by_mangle = l7;
    _a26_obj->f_import_by_symbol = l8;
    l5 = (void*) _a26_obj;
    vader_array_t* _a27_arr = vader_array_new(18u, 0u, 13u, 251u);
    l6 = (void*) _a27_arr;
    vader_array_t* _a28_arr = vader_array_new(18u, 0u, 13u, 251u);
    l7 = (void*) _a28_arr;
    vader_struct_vader_midir$SlotTypes_t* _a29_obj = (vader_struct_vader_midir$SlotTypes_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$SlotTypes_t));
    vader_obj_header_init(_a29_obj, 1377u);
    _a29_obj->f_fields = l3;
    _a29_obj->f_plain_fields = l4;
    _a29_obj->f_callees = l5;
    _a29_obj->f_function_params = l6;
    _a29_obj->f_import_params = l7;
    l3 = (void*) _a29_obj;
    l4 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l4)->f_evals;
    l11 = INT64_C(0);
    l12 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l4)->f_size;
    while ((l11 < l12)) {
        vader_array_t* _a30_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a30_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a30_slotarr, l11)
        t0 = vader_array_box_slots(_a30_slotarr->buf)[_a30_slotarr->offset + (size_t) l11];
        t1 = t0.payload.s;
        vader_array_t* _a31_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a31_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a31_slotarr, l11)
        l4 = vader_array_ref_load_obj(_a31_slotarr->buf, _a31_slotarr->offset + (size_t) l11);
        l7 = ((vader_struct_vader_midir$CFGModule_t*) l4)->f_functions;
        l13 = ((vader_array_t*) l7)->length;
        l14 = INT64_C(0);
        while ((l14 < l13)) {
            vader_array_t* _a32_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
            l8 = vader_array_ref_load_obj(_a32_slotarr->buf, _a32_slotarr->offset + (size_t) l14);
            l15 = ((vader_struct_vader_midir$CFGFunction_t*) l8)->f_mangled;
            l16 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGFunction_t*) l8)->f_origin)->f_symbol;
            l9 = vader_midir$param_types(((vader_struct_vader_midir$CFGFunction_t*) l8)->f_params);
            vader_midir$note_params(l3, l15, l16, l9, false);
            vader_array_push_ref((vader_array_t*) l1, l8);
            l14 = (l14 + INT64_C(1));
        }
        l10 = ((vader_struct_vader_midir$CFGModule_t*) l4)->f_externs;
        l17 = ((vader_array_t*) l10)->length;
        l18 = INT64_C(0);
        while ((l18 < l17)) {
            vader_array_t* _a33_slotarr = ((vader_array_t*) l10);
            VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
            l19 = vader_array_ref_load_obj(_a33_slotarr->buf, _a33_slotarr->offset + (size_t) l18);
            l20 = ((vader_struct_vader_midir$CFGExternDecl_t*) l19)->f_mangled;
            l21 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGExternDecl_t*) l19)->f_origin)->f_symbol;
            l22 = vader_midir$param_types(((vader_struct_vader_midir$CFGExternDecl_t*) l19)->f_params);
            vader_midir$note_params(l3, l20, l21, l22, true);
            vader_array_push_ref((vader_array_t*) l2, l19);
            l18 = (l18 + INT64_C(1));
        }
        l23 = ((vader_struct_vader_midir$CFGModule_t*) l4)->f_struct_decls;
        l24 = ((vader_array_t*) l23)->length;
        l25 = INT64_C(0);
        while ((l25 < l24)) {
            vader_array_t* _a34_slotarr = ((vader_array_t*) l23);
            VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
            l26 = vader_array_ref_load_obj(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l25);
            vader_midir$note_struct_fields(l3, l26);
            l25 = (l25 + INT64_C(1));
        }
        l11 = (l11 + INT64_C(1));
    }
    vader_struct_vader_midir$CfgResolution_t* _a35_obj = (vader_struct_vader_midir$CfgResolution_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CfgResolution_t));
    vader_obj_header_init(_a35_obj, 1326u);
    _a35_obj->f_functions = l1;
    _a35_obj->f_externs = l2;
    _a35_obj->f_slots = l3;
    t2 = (void*) _a35_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_data_const(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3, l5;
    void* l4 = NULL;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredDataConst_t*) l1)->f_type;
    l3 = vader_midir$fresh_tmp(l0, 1812u, l2);
    l4 = ((vader_struct_vader_lower_ir$LoweredDataConst_t*) l1)->f_span;
    l2 = ((vader_struct_vader_lower_ir$LoweredDataConst_t*) l1)->f_type;
    t0 = ((vader_struct_vader_lower_ir$LoweredDataConst_t*) l1)->f_pool_index;
    l5 = ((int32_t) (int64_t) t0);
    vader_struct_vader_midir$InstrDataConst_t* _a0_obj = (vader_struct_vader_midir$InstrDataConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrDataConst_t));
    vader_obj_header_init(_a0_obj, 1352u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_pool_index = l5;
    l4 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l4));
    { vader_box_t __vret = vader_box_i32(338u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_expr(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    vader_string_t l5 = 0;
    int32_t l6;
    void* t0 = NULL;
    int64_t t1;
    int32_t t2;
    double t3;
    bool t4;
    uint32_t t5;
    vader_box_t t6 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l2, &t6 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l1.tag == 1282u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredIntLit_t*) t0)->f_type;
        t0 = l1.payload.obj;
        t1 = ((vader_struct_vader_lower_ir$LoweredIntLit_t*) t0)->f_value;
        vader_struct_vader_midir$ConstInt_t* _a0_obj = (vader_struct_vader_midir$ConstInt_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstInt_t));
        vader_obj_header_init(_a0_obj, 1331u);
        _a0_obj->f_value = t1;
        l3 = (void*) _a0_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredIntLit_t*) t0)->f_span;
        t2 = vader_midir$emit_const(l0, l2, vader_ref_box(l3), l4);
        { vader_box_t __vret = vader_box_i32(338u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1275u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredFloatLit_t*) t0)->f_type;
        t0 = l1.payload.obj;
        t3 = ((vader_struct_vader_lower_ir$LoweredFloatLit_t*) t0)->f_value;
        vader_struct_vader_midir$ConstFloat_t* _a1_obj = (vader_struct_vader_midir$ConstFloat_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstFloat_t));
        vader_obj_header_init(_a1_obj, 1330u);
        _a1_obj->f_value = t3;
        l3 = (void*) _a1_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredFloatLit_t*) t0)->f_span;
        t2 = vader_midir$emit_const(l0, l2, vader_ref_box(l3), l4);
        { vader_box_t __vret = vader_box_i32(338u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1260u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredBoolLit_t*) t0)->f_type;
        t0 = l1.payload.obj;
        t4 = ((vader_struct_vader_lower_ir$LoweredBoolLit_t*) t0)->f_value;
        vader_struct_vader_midir$ConstBool_t* _a2_obj = (vader_struct_vader_midir$ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstBool_t));
        vader_obj_header_init(_a2_obj, 1328u);
        _a2_obj->f_value = t4;
        l3 = (void*) _a2_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredBoolLit_t*) t0)->f_span;
        t2 = vader_midir$emit_const(l0, l2, vader_ref_box(l3), l4);
        { vader_box_t __vret = vader_box_i32(338u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1289u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredNullLit_t*) t0)->f_type;
        vader_struct_vader_midir$ConstNull_t* _a3_obj = (vader_struct_vader_midir$ConstNull_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstNull_t));
        vader_obj_header_init(_a3_obj, 1332u);
        l3 = (void*) _a3_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredNullLit_t*) t0)->f_span;
        t2 = vader_midir$emit_const(l0, l2, vader_ref_box(l3), l4);
        { vader_box_t __vret = vader_box_i32(338u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1267u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredCharLit_t*) t0)->f_type;
        t0 = l1.payload.obj;
        t5 = ((vader_struct_vader_lower_ir$LoweredCharLit_t*) t0)->f_value;
        vader_struct_vader_midir$ConstChar_t* _a4_obj = (vader_struct_vader_midir$ConstChar_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstChar_t));
        vader_obj_header_init(_a4_obj, 1329u);
        _a4_obj->f_value = ((int32_t) (uint32_t) t5);
        l3 = (void*) _a4_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredCharLit_t*) t0)->f_span;
        t2 = vader_midir$emit_const(l0, l2, vader_ref_box(l3), l4);
        { vader_box_t __vret = vader_box_i32(338u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1293u) {
        l3 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_project;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredStringLit_t*) t0)->f_value;
        l6 = vader_midir$intern_string_pool(l3, l5);
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredStringLit_t*) t0)->f_type;
        vader_struct_vader_midir$ConstString_t* _a5_obj = (vader_struct_vader_midir$ConstString_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstString_t));
        vader_obj_header_init(_a5_obj, 1333u);
        _a5_obj->f_index = l6;
        l3 = (void*) _a5_obj;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredStringLit_t*) t0)->f_span;
        t2 = vader_midir$emit_const(l0, l2, vader_ref_box(l3), l4);
        { vader_box_t __vret = vader_box_i32(338u, t2); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1279u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_ident(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1262u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_call(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1303u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_virtual_call(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1274u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_field_access(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1301u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_union_field(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1281u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_index(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1300u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_unary(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1258u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_binary(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1280u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_if(l0, l3, vader_box_obj(0u, NULL));
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1259u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_block_body(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1296u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_struct_lit(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1253u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_array_lit(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1263u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_cast(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1298u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_type_check(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1302u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredUnreachable_t*) t0)->f_type;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredUnreachable_t*) t0)->f_span;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredUnreachable_t*) t0)->f_reason;
        t6 = vader_midir$build_unreachable_type(l0, l2, l3, l5);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1283u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_intrinsic_call(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1252u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_array_len(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1254u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_array_push(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1255u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_array_slice(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1265u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_cell_new(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1264u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_cell_get(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1287u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_make_closure(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1270u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_data_const(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1277u) {
        l3 = l1.payload.obj;
        t6 = vader_midir$build_global_get(l0, l3);
        { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 1299u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    l3 = l1.payload.obj;
    t6 = vader_midir$build_type_const(l0, l3);
    { vader_box_t __vret = t6; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir$build_expr_into(void* l0, vader_box_t l1, int32_t l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    int64_t l5;
    int32_t l7;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[3] = { &l1, &l4, &l6 };
    void** gc_raw_roots[3] = { &l0, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1280u) {
        l3 = l1.payload.obj;
        vader_midir$build_if(l0, l3, vader_box_i32(338u, l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1259u) {
        l3 = l1.payload.obj;
        vader_midir$build_block_into(l0, l3, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1258u) {
        t0 = l1.payload.obj;
        t1 = vader_midir$is_short_circuit_op(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_op);
        if (t1) {
            l3 = l1.payload.obj;
            vader_midir$build_short_circuit(l0, l3, vader_box_i32(338u, l2));
            { vader_gc_top = gc_frame.prev; return; }
        }
    }
    l4 = l1;
    l3 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_locals;
    l5 = ((int64_t) (int32_t) l2);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l6 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
    l4 = vader_midir$build_held(l0, l4, l6);
    if (((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_span, l1.payload.obj);
    l7 = ((int32_t) l4.payload.i);
    vader_struct_vader_midir$InstrMove_t* _a1_obj = (vader_struct_vader_midir$InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMove_t));
    vader_obj_header_init(_a1_obj, 1363u);
    _a1_obj->f_span = l3;
    _a1_obj->f_dst = l2;
    _a1_obj->f_src = l7;
    l3 = (void*) _a1_obj;
    vader_midir$emit(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir$build_extern_args(void* l0, void* l1, void* l2, void* l3, vader_string_t l4) {
    void* l5 = NULL;
    void* l15 = NULL;
    void* l23 = NULL;
    void* l25 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l30 = NULL;
    int64_t l6, l7, l12, l14, l16, l17, l20, l21, l22, l24;
    vader_box_t l8 = vader_box_null(), l10 = vader_box_null(), l11 = vader_box_null(), l29 = vader_box_null();
    int32_t l9, l26;
    vader_string_t l13 = 0;
    vader_string_t l18 = 0;
    vader_string_t l19 = 0;
    bool t0;
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l8, &l10, &l11, &l29 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l5, &l15, &l23, &l25, &l27, &l28, &l30, &t2 };
    vader_string_t* gc_atom_roots[5] = { &l4, &l13, &l18, &l19, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a0_arr;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) l1)->length;
    for (;;) {
        if ((l6 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l6)
            l8 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l6);
            t0 = std_collections$MutableSet$std_core$Contains$contains__i64(l3, l6);
            if (t0) {
                if (!(l8.tag == 1279u)) {
                    l12 = vader_chk_add(i64, l6, INT64_C(1));
                    l13 = l4;
                    l14 = vader_host_std_core$byte_len(l13);
                    l15 = (void*) vader_buffer_new((size_t) (INT64_C(127) + l14));
                    l16 = INT64_C(0);
                    l16 = std_core$write_string_at(l15, l16, 2334u);
                    l16 = std_core$write_int(l15, l16, l12);
                    l16 = std_core$write_string_at(l15, l16, 186u);
                    l16 = std_core$write_string_at(l15, l16, l13);
                    l16 = std_core$write_string_at(l15, l16, 1135u);
                    t1 = std_core$finish_buffer(l15, l16);
                    vader_host_std_abort$panic(t1);
                    vader_unreachable("a no-return call returned");
                }
                t2 = l8.payload.obj;
                if (((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t2)->f_symbol)->f_kind != INT32_C(0)) {
                    l17 = vader_chk_add(i64, l6, INT64_C(1));
                    l18 = l4;
                    t2 = l8.payload.obj;
                    l19 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t2)->f_symbol)->f_name;
                    l20 = vader_host_std_core$byte_len(l18);
                    l21 = vader_host_std_core$byte_len(l19);
                    l22 = (l20 + l21);
                    l23 = (void*) vader_buffer_new((size_t) (INT64_C(124) + l22));
                    l24 = INT64_C(0);
                    l24 = std_core$write_string_at(l23, l24, 2334u);
                    l24 = std_core$write_int(l23, l24, l17);
                    l24 = std_core$write_string_at(l23, l24, 186u);
                    l24 = std_core$write_string_at(l23, l24, l18);
                    l24 = std_core$write_string_at(l23, l24, 1196u);
                    l24 = std_core$write_string_at(l23, l24, l19);
                    l24 = std_core$write_string_at(l23, l24, 1300u);
                    t1 = std_core$finish_buffer(l23, l24);
                    vader_host_std_abort$panic(t1);
                    vader_unreachable("a no-return call returned");
                } else {
                    t2 = (void*) &vader_data_35;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) t2);
                    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
                    l25 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
                    l26 = vader_midir$fresh_tmp(l0, 2011u, vader_ref_box(l25));
                    t2 = l8.payload.obj;
                    l27 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t2)->f_span;
                    t2 = l8.payload.obj;
                    l28 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t2)->f_symbol;
                    t2 = l8.payload.obj;
                    l29 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t2)->f_type;
                    vader_struct_vader_midir$InstrFnAddr_t* _a3_obj = (vader_struct_vader_midir$InstrFnAddr_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFnAddr_t));
                    vader_obj_header_init(_a3_obj, 1357u);
                    _a3_obj->f_span = l27;
                    _a3_obj->f_dst = l26;
                    _a3_obj->f_fn_symbol = l28;
                    _a3_obj->f_type = l29;
                    l30 = (void*) _a3_obj;
                    vader_midir$emit(l0, vader_ref_box(l30));
                    vader_array_push_i32((vader_array_t*) l5, l26);
                    l6 = (l6 + INT64_C(1));
                    continue;
                }
            } else {
                l10 = vader_midir$type_at(l2, l6);
                l11 = vader_midir$build_held(l0, l8, l10);
                if (l11.tag == 0u) {
                    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
                }
                l9 = ((int32_t) l11.payload.i);
                vader_array_push_i32((vader_array_t*) l5, l9);
                l6 = (l6 + INT64_C(1));
                continue;
            }
        }
        break;
    }
    { vader_box_t __vret = vader_ref_box(l5); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_field_access(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir$stored_field(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) l1)->f_type;
    l4 = ((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) l1)->f_span;
    t0 = vader_midir$read_as(l0, l2, l3, l4);
    { vader_box_t __vret = vader_box_i32(338u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_global_get(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    int32_t l3, l5;
    void* l4 = NULL;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredGlobalGet_t*) l1)->f_type;
    l3 = vader_midir$fresh_tmp(l0, 2056u, l2);
    l4 = ((vader_struct_vader_lower_ir$LoweredGlobalGet_t*) l1)->f_span;
    l2 = ((vader_struct_vader_lower_ir$LoweredGlobalGet_t*) l1)->f_type;
    t0 = ((vader_struct_vader_lower_ir$LoweredGlobalGet_t*) l1)->f_slot;
    l5 = ((int32_t) (int64_t) t0);
    vader_struct_vader_midir$InstrGlobalGet_t* _a0_obj = (vader_struct_vader_midir$InstrGlobalGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrGlobalGet_t));
    vader_obj_header_init(_a0_obj, 1359u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_slot = l5;
    l4 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l4));
    { vader_box_t __vret = vader_box_i32(338u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_held(void* l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null(), l9 = vader_box_null();
    int64_t l6;
    int32_t l8;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    int64_t t3;
    int32_t t4;
    vader_box_t* gc_roots[5] = { &l1, &l2, &l4, &l9, &t1 };
    void** gc_raw_roots[5] = { &l0, &l3, &l5, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 5u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (l1.tag == 1282u) {
        t0 = l1.payload.obj;
        l4 = vader_midir$stored_conversion(((vader_struct_vader_lower_ir$LoweredIntLit_t*) t0)->f_type, l2);
        if (l4.tag == 0u) {
            l3 = l1.payload.obj;
            t1 = vader_midir$build_expr(l0, vader_ref_box(l3));
            { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l3 = l4.payload.obj;
        l5 = ((vader_struct_vader_support_integer$MachineInteger_t*) l3)->f_values;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_lower_ir$LoweredIntLit_t*) t0)->f_value;
        t2 = vader_support_integer$holds_value(l5, l6);
        if (t2) {
            t0 = l1.payload.obj;
            t3 = ((vader_struct_vader_lower_ir$LoweredIntLit_t*) t0)->f_value;
            vader_struct_vader_midir$ConstInt_t* _a0_obj = (vader_struct_vader_midir$ConstInt_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstInt_t));
            vader_obj_header_init(_a0_obj, 1331u);
            _a0_obj->f_value = t3;
            l5 = (void*) _a0_obj;
            l3 = vader_core_types$machine_integer_type(l3);
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_lower_ir$LoweredIntLit_t*) t0)->f_span;
            t4 = vader_midir$emit_const(l0, vader_ref_box(l3), vader_ref_box(l5), l7);
            { vader_box_t __vret = vader_box_i32(338u, t4); vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    t2 = vader_core_types$is_stored_as_integer(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, l1.payload.obj));
    if (t2) {
        l9 = vader_midir$build_stored(l0, l1);
        if (l9.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l8 = ((int32_t) l9.payload.i);
        l9 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, l1.payload.obj);
        l5 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_span, l1.payload.obj);
        t4 = vader_midir$held_use_in(l0, l8, l9, l2, l5);
        { vader_box_t __vret = vader_box_i32(338u, t4); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_midir$build_expr(l0, l1);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l8 = ((int32_t) l4.payload.i);
    l3 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_span, l1.payload.obj);
    t4 = vader_midir$held_in(l0, l8, l2, l3);
    { vader_box_t __vret = vader_box_i32(338u, t4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_ident(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir$stored_ident(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_type;
    l4 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_span;
    t0 = vader_midir$read_as(l0, l2, l3, l4);
    { vader_box_t __vret = vader_box_i32(338u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_if(void* l0, void* l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null(), l11 = vader_box_null();
    void* l5 = NULL;
    void* l12 = NULL;
    int32_t l6, l7, l8;
    bool l9, l10;
    bool t0;
    int32_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &l11 };
    void** gc_raw_roots[5] = { &l0, &l1, &l5, &l12, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 0u) {
        t0 = vader_core_types$is_void(((vader_struct_vader_lower_ir$LoweredIf_t*) l1)->f_type);
        if (t0) {
            l3 = vader_box_obj(0u, NULL);
        } else {
            l4 = ((vader_struct_vader_lower_ir$LoweredIf_t*) l1)->f_type;
            t1 = vader_midir$declare_local(l0, 2128u, l4, vader_box_obj(0u, NULL));
            l3 = vader_box_i32(338u, t1);
        }
    } else {
        t1 = ((int32_t) l2.payload.i);
        l3 = vader_box_i32(338u, t1);
    }
    l4 = ((vader_struct_vader_lower_ir$LoweredIf_t*) l1)->f_else_block;
    l5 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) ((vader_struct_vader_lower_ir$LoweredIf_t*) l1)->f_then_block)->f_span;
    l6 = vader_midir$new_block(l0, l5);
    l5 = ((vader_struct_vader_lower_ir$LoweredIf_t*) l1)->f_span;
    l7 = vader_midir$new_block(l0, l5);
    if (l4.tag == 0u) {
        l8 = l7;
    } else {
        t2 = l4.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) t2)->f_span;
        l8 = vader_midir$new_block(l0, l5);
    }
    l5 = vader_midir$operand_edges(((vader_struct_vader_lower_ir$LoweredIf_t*) l1)->f_cond);
    l9 = vader_midir$only_leaves(((vader_struct_vader_lower_ir$LoweredIf_t*) l1)->f_then_block);
    t1 = ((vader_struct_vader_midir$OperandEdges_t*) l5)->f_on_true;
    if ((t1 < INT32_C(2))) {
        l10 = true;
    } else {
        l10 = l9;
    }
    if (l10) {
        t1 = ((vader_struct_vader_midir$OperandEdges_t*) l5)->f_on_false;
        if ((t1 < INT32_C(2))) {
            l10 = true;
        } else {
            l10 = l4.tag == 0u;
        }
        if (l10) {
            l10 = true;
        } else {
            l10 = l9;
        }
        l9 = l10;
    } else {
        l9 = false;
    }
    l11 = ((vader_struct_vader_lower_ir$LoweredIf_t*) l1)->f_cond;
    l5 = vader_midir$branch_on_cond(l0, l11, l6, l8, l9);
    t0 = ((vader_struct_vader_midir$CondReach_t*) l5)->f_on_true;
    if (!(t0)) {
        t0 = ((vader_struct_vader_midir$CondReach_t*) l5)->f_on_false;
        if (!(t0)) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
    }
    t0 = ((vader_struct_vader_midir$CondReach_t*) l5)->f_on_true;
    if (t0) {
        ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l6);
        VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
        l12 = ((vader_struct_vader_lower_ir$LoweredIf_t*) l1)->f_then_block;
        vader_midir$build_if_arm(l0, l12, l3);
        vader_struct_vader_midir$TermBranch_t* _a0_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
        vader_obj_header_init(_a0_obj, 1380u);
        _a0_obj->f_span = ((vader_struct_vader_lower_ir$LoweredBlock_t*) ((vader_struct_vader_lower_ir$LoweredIf_t*) l1)->f_then_block)->f_span;
        _a0_obj->f_target = l7;
        l12 = (void*) _a0_obj;
        vader_midir$terminate(l0, vader_ref_box(l12));
    }
    if (l4.tag == 0u) {
        ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l7);
        VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = ((vader_struct_vader_midir$CondReach_t*) l5)->f_on_false;
    if (t0) {
        ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l8);
        VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
        l5 = l4.payload.obj;
        vader_midir$build_if_arm(l0, l5, l3);
        t2 = l4.payload.obj;
        vader_struct_vader_midir$TermBranch_t* _a1_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
        vader_obj_header_init(_a1_obj, 1380u);
        _a1_obj->f_span = ((vader_struct_vader_lower_ir$LoweredBlock_t*) t2)->f_span;
        _a1_obj->f_target = l7;
        l5 = (void*) _a1_obj;
        vader_midir$terminate(l0, vader_ref_box(l5));
        ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l7);
        VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
        { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l7);
    VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir$build_if_arm(void* l0, void* l1, vader_box_t l2) {
    int32_t l3;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l2.tag == 0u) {
        vader_midir$build_block_body(l0, l1);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = ((int32_t) l2.payload.i);
    vader_midir$build_block_into(l0, l1, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir$build_index(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    int32_t l5, l7, l8;
    void* l6 = NULL;
    bool l9;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredIndex_t*) l1)->f_target;
    l2 = vader_midir$build_expr(l0, l2);
    l3 = ((vader_struct_vader_lower_ir$LoweredIndex_t*) l1)->f_index;
    l3 = vader_midir$build_expr(l0, l3);
    if (l2.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    if (!(l3.tag == 0u)) {
        l4 = ((vader_struct_vader_lower_ir$LoweredIndex_t*) l1)->f_type;
        l5 = vader_midir$fresh_tmp(l0, 2123u, l4);
        l6 = ((vader_struct_vader_lower_ir$LoweredIndex_t*) l1)->f_span;
        l7 = ((int32_t) l2.payload.i);
        l2 = ((vader_struct_vader_lower_ir$LoweredIndex_t*) l1)->f_type;
        l8 = ((int32_t) l3.payload.i);
        l9 = ((vader_struct_vader_lower_ir$LoweredIndex_t*) l1)->f_bounds_safe;
        vader_struct_vader_midir$InstrArrayGet_t* _a0_obj = (vader_struct_vader_midir$InstrArrayGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrArrayGet_t));
        vader_obj_header_init(_a0_obj, 1338u);
        _a0_obj->f_span = l6;
        _a0_obj->f_dst = l5;
        _a0_obj->f_target = l7;
        _a0_obj->f_type = l2;
        _a0_obj->f_index = l8;
        _a0_obj->f_bounds_safe = l9;
        l6 = (void*) _a0_obj;
        vader_midir$emit(l0, vader_ref_box(l6));
        { vader_box_t __vret = vader_box_i32(338u, l5); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static vader_box_t vader_midir$build_intrinsic_call(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l7 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l6 = 0;
    bool t0;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l4, &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l7 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) l1)->f_args;
    l3 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) l1)->f_param_types;
    l4 = vader_midir$build_args(l0, l2, l3);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = l4.payload.obj;
    t0 = vader_core_types$is_void(((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) l1)->f_type);
    if (t0) {
        l4 = vader_box_obj(0u, NULL);
    } else {
        l5 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) l1)->f_type;
        t1 = vader_midir$fresh_tmp(l0, 2185u, l5);
        l4 = vader_box_i32(338u, t1);
    }
    l3 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) l1)->f_name;
    l7 = ((vader_struct_vader_lower_ir$LoweredIntrinsicCall_t*) l1)->f_param_types;
    vader_struct_vader_midir$InstrIntrinsic_t* _a0_obj = (vader_struct_vader_midir$InstrIntrinsic_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrIntrinsic_t));
    vader_obj_header_init(_a0_obj, 1361u);
    _a0_obj->f_span = l3;
    _a0_obj->f_dst = l4;
    _a0_obj->f_name = l6;
    _a0_obj->f_args = l2;
    _a0_obj->f_param_types = l7;
    l2 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l2));
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir$build_labelled_block(void* l0, void* l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    int32_t l3, l4;
    vader_string_t l5 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l5 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) l1)->f_span;
    l3 = vader_midir$new_block(l0, l2);
    l2 = ((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) l1)->f_span;
    l4 = vader_midir$new_block(l0, l2);
    if (!(((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir$TermBranch_t* _a0_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
        vader_obj_header_init(_a0_obj, 1380u);
        _a0_obj->f_span = ((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) l1)->f_span;
        _a0_obj->f_target = l3;
        l2 = (void*) _a0_obj;
        vader_midir$terminate(l0, vader_ref_box(l2));
    }
    l2 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_loop_stack;
    l5 = ((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) l1)->f_label;
    vader_array_t* _a1_arr = vader_array_new(264u, 0u, 13u, 2059u);
    l6 = (void*) _a1_arr;
    vader_struct_vader_midir$LoopFrame_t* _a2_obj = (vader_struct_vader_midir$LoopFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$LoopFrame_t));
    vader_obj_header_init(_a2_obj, 1372u);
    _a2_obj->f_label = vader_box_string(335u, l5);
    _a2_obj->f_header_id = l4;
    _a2_obj->f_exit_id = l4;
    _a2_obj->f_step = l6;
    _a2_obj->f_block = true;
    l6 = (void*) _a2_obj;
    vader_array_push_ref((vader_array_t*) l2, l6);
    ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l3);
    VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
    l2 = ((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) l1)->f_body;
    vader_midir$build_block_body(l0, l2);
    if (!(((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir$TermBranch_t* _a3_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
        vader_obj_header_init(_a3_obj, 1380u);
        _a3_obj->f_span = ((vader_struct_vader_lower_ir$LoweredLabelledBlock_t*) l1)->f_span;
        _a3_obj->f_target = l4;
        l2 = (void*) _a3_obj;
        vader_midir$terminate(l0, vader_ref_box(l2));
    }
    t0 = vader_array_remove_last((vader_array_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_loop_stack);
    ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l4);
    VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$build_loop(void* l0, void* l1) {
    void* l2 = NULL;
    void* l8 = NULL;
    int32_t l3, l4, l6;
    vader_box_t l5 = vader_box_null();
    bool l7;
    int64_t l9, l10;
    void* t0 = NULL;
    int32_t t1;
    bool t2;
    int64_t t3;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_span;
    l3 = vader_midir$new_block(l0, l2);
    l2 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_span;
    l4 = vader_midir$new_block(l0, l2);
    if (!(((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir$TermBranch_t* _a0_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
        vader_obj_header_init(_a0_obj, 1380u);
        _a0_obj->f_span = ((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_span;
        _a0_obj->f_target = l3;
        l2 = (void*) _a0_obj;
        vader_midir$terminate(l0, vader_ref_box(l2));
    }
    ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l3);
    VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
    l5 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_cond;
    if (!(l5.tag == 0u)) {
        l2 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) ((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_body)->f_span;
        l6 = vader_midir$new_block(l0, l2);
        t0 = vader_midir$operand_edges(l5);
        t1 = ((vader_struct_vader_midir$OperandEdges_t*) t0)->f_on_true;
        l7 = (t1 < INT32_C(2));
        t0 = vader_midir$branch_on_cond(l0, l5, l6, l4, l7);
        t2 = ((vader_struct_vader_midir$CondReach_t*) t0)->f_on_true;
        if (!(t2)) {
            vader_struct_vader_midir$TermBranch_t* _a1_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
            vader_obj_header_init(_a1_obj, 1380u);
            _a1_obj->f_span = ((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_span;
            _a1_obj->f_target = l4;
            l2 = (void*) _a1_obj;
            vader_midir$terminate(l0, vader_ref_box(l2));
        }
        ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l6);
        VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
    }
    l5 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_label;
    l2 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_step;
    vader_struct_vader_midir$LoopFrame_t* _a2_obj = (vader_struct_vader_midir$LoopFrame_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$LoopFrame_t));
    vader_obj_header_init(_a2_obj, 1372u);
    _a2_obj->f_label = l5;
    _a2_obj->f_header_id = l3;
    _a2_obj->f_exit_id = l4;
    _a2_obj->f_step = l2;
    _a2_obj->f_block = false;
    l2 = (void*) _a2_obj;
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_loop_stack, l2);
    l8 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_body;
    vader_midir$build_block_body(l0, l8);
    if (!(((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u)) {
        l8 = ((vader_struct_vader_lower_ir$LoweredLoop_t*) l1)->f_span;
        vader_midir$build_back_edge(l0, l2, l8);
    }
    vader_array_t* _a3_arr = vader_array_new(208u, 0u, 13u, 1372u);
    l2 = (void*) _a3_arr;
    l9 = INT64_C(0);
    t3 = ((vader_array_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_loop_stack)->length;
    l10 = vader_chk_sub(i64, t3, INT64_C(1));
    while ((l9 < l10)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_loop_stack);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l9)
        l8 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l9);
        vader_array_push_ref((vader_array_t*) l2, l8);
        l9 = (l9 + INT64_C(1));
    }
    ((vader_struct_vader_midir$FnCtx_t*) l0)->f_loop_stack = l2;
    VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
    ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l4);
    VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir$build_make_closure(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    void* l6 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l5, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) l1)->f_env;
    l3 = vader_midir$build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) l1)->f_type;
    l4 = vader_midir$fresh_tmp(l0, 1756u, l3);
    l5 = ((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) l1)->f_fn_symbol;
    l3 = ((vader_struct_vader_lower_ir$LoweredMakeClosure_t*) l1)->f_type;
    vader_struct_vader_midir$InstrMakeClosure_t* _a0_obj = (vader_struct_vader_midir$InstrMakeClosure_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMakeClosure_t));
    vader_obj_header_init(_a0_obj, 1362u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_fn_symbol = l6;
    _a0_obj->f_env = l2;
    _a0_obj->f_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l5));
    { vader_box_t __vret = vader_box_i32(338u, l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_module_ident(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l6 = vader_box_null();
    int32_t l3;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    vader_string_t l9 = 0;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l6, &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l4, &l5, &l7, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_symbol)->f_kind == INT32_C(0)) {
        l2 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_type;
        l3 = vader_midir$fresh_tmp(l0, 2012u, l2);
        l4 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_span;
        l5 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_symbol;
        l2 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_type;
        vader_struct_vader_midir$InstrFnRef_t* _a0_obj = (vader_struct_vader_midir$InstrFnRef_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFnRef_t));
        vader_obj_header_init(_a0_obj, 1358u);
        _a0_obj->f_span = l4;
        _a0_obj->f_dst = l3;
        _a0_obj->f_fn_symbol = l5;
        _a0_obj->f_type = l2;
        l4 = (void*) _a0_obj;
        vader_midir$emit(l0, vader_ref_box(l4));
        { vader_box_t __vret = vader_box_i32(338u, l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_midir$const_accessor(l0, l1);
    if (l2.tag == 1247u) {
        t0 = l2.payload.obj;
        l6 = ((vader_struct_vader_lower_ir$ConstFnWrap_t*) t0)->f_call_type;
        l3 = vader_midir$fresh_tmp(l0, 1793u, l6);
        vader_array_t* _a1_arr = vader_array_new(23u, 0u, 7u, 338u);
        l4 = (void*) _a1_arr;
        l5 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_span;
        vader_array_t* _a2_arr = vader_array_new(23u, 1u, 7u, 338u);
        ((int32_t*) _a2_arr->buf->slots)[_a2_arr->offset + 0u] = (int32_t) l3;
        l7 = (void*) _a2_arr;
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_lower_ir$ConstFnWrap_t*) t0)->f_fn_symbol;
        t0 = l2.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$ConstFnWrap_t*) t0)->f_call_type;
        vader_struct_vader_midir$InstrCall_t* _a3_obj = (vader_struct_vader_midir$InstrCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCall_t));
        vader_obj_header_init(_a3_obj, 1345u);
        _a3_obj->f_span = l5;
        _a3_obj->f_dsts = l7;
        _a3_obj->f_callee = l8;
        _a3_obj->f_args = l4;
        _a3_obj->f_type = l2;
        l4 = (void*) _a3_obj;
        vader_midir$emit(l0, vader_ref_box(l4));
        { vader_box_t __vret = vader_box_i32(338u, l3); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_midir$ProjectCtx_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_project)->f_const_inline;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_symbol)->f_id;
    l2 = std_collections$MutableMap$std_core$Index$at__i32__Any(l4, l3);
    if (!(l2.tag == 0u)) {
        t1 = vader_midir$build_expr(l0, l2);
        { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((vader_struct_vader_midir$ProjectCtx_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_project)->f_diags;
    l5 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_span;
    l9 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_symbol)->f_name;
    l9 = concat_3(1035u, l9, 1230u);
    l5 = vader_support_diagnostics$lower_error((uint8_t) 3, l5, l9);
    vader_array_push_ref((vader_array_t*) l4, l5);
    l2 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_type;
    l4 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_span;
    l9 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_symbol)->f_name;
    l9 = concat_2(2827u, l9);
    t1 = vader_midir$build_unreachable_type(l0, l2, l4, l9);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_short_circuit(void* l0, void* l1, vader_box_t l2) {
    int32_t l3, l6, l9, l10, l11;
    vader_box_t l4 = vader_box_null();
    bool l5;
    vader_string_t l7 = 0;
    void* l8 = NULL;
    void* l12 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l4 };
    void** gc_raw_roots[4] = { &l0, &l1, &l8, &l12 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_left;
    l4 = vader_midir$build_expr(l0, l4);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((int32_t) l4.payload.i);
    l5 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_op == INT32_C(10);
    if (l2.tag == 0u) {
        if (l5) {
            l7 = 1542u;
        } else {
            l7 = 2437u;
        }
        l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_type;
        l6 = vader_midir$declare_local(l0, l7, l4, vader_box_obj(0u, NULL));
    } else {
        l6 = ((int32_t) l2.payload.i);
    }
    l8 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_span, ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_right.payload.obj);
    l9 = vader_midir$new_block(l0, l8);
    l8 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_span, ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_right.payload.obj);
    l10 = vader_midir$new_block(l0, l8);
    l8 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_span;
    l11 = vader_midir$new_block(l0, l8);
    vader_struct_vader_midir$TermCondBranch_t* _a0_obj = (vader_struct_vader_midir$TermCondBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermCondBranch_t));
    vader_obj_header_init(_a0_obj, 1381u);
    _a0_obj->f_span = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_span;
    _a0_obj->f_cond = l3;
    _a0_obj->f_then_block = l9;
    _a0_obj->f_else_block = l10;
    l8 = (void*) _a0_obj;
    vader_midir$terminate(l0, vader_ref_box(l8));
    ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l9);
    VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
    if (l5) {
        l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_right;
        l4 = vader_midir$build_expr(l0, l4);
        if (!(l4.tag == 0u)) {
            if (!(((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u)) {
                l8 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_span, ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_right.payload.obj);
                l3 = ((int32_t) l4.payload.i);
                vader_struct_vader_midir$InstrMove_t* _a1_obj = (vader_struct_vader_midir$InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMove_t));
                vader_obj_header_init(_a1_obj, 1363u);
                _a1_obj->f_span = l8;
                _a1_obj->f_dst = l6;
                _a1_obj->f_src = l3;
                l8 = (void*) _a1_obj;
                vader_midir$emit(l0, vader_ref_box(l8));
            }
        }
    } else {
        l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_type;
        l3 = vader_midir$fresh_tmp(l0, 2230u, l4);
        l8 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_span;
        vader_struct_vader_midir$ConstBool_t* _a2_obj = (vader_struct_vader_midir$ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstBool_t));
        vader_obj_header_init(_a2_obj, 1328u);
        _a2_obj->f_value = true;
        l12 = (void*) _a2_obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_type;
        vader_struct_vader_midir$InstrConst_t* _a3_obj = (vader_struct_vader_midir$InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrConst_t));
        vader_obj_header_init(_a3_obj, 1351u);
        _a3_obj->f_span = l8;
        _a3_obj->f_dst = l3;
        _a3_obj->f_value = vader_ref_box(l12);
        _a3_obj->f_type = l4;
        l8 = (void*) _a3_obj;
        vader_midir$emit(l0, vader_ref_box(l8));
        vader_struct_vader_midir$InstrMove_t* _a4_obj = (vader_struct_vader_midir$InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMove_t));
        vader_obj_header_init(_a4_obj, 1363u);
        _a4_obj->f_span = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_span;
        _a4_obj->f_dst = l6;
        _a4_obj->f_src = l3;
        l8 = (void*) _a4_obj;
        vader_midir$emit(l0, vader_ref_box(l8));
    }
    if (!(((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u)) {
        vader_struct_vader_midir$TermBranch_t* _a5_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
        vader_obj_header_init(_a5_obj, 1380u);
        _a5_obj->f_span = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_span;
        _a5_obj->f_target = l11;
        l8 = (void*) _a5_obj;
        vader_midir$terminate(l0, vader_ref_box(l8));
    }
    ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l10);
    VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
    if (l5) {
        l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_type;
        l3 = vader_midir$fresh_tmp(l0, 2230u, l4);
        l8 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_span;
        vader_struct_vader_midir$ConstBool_t* _a6_obj = (vader_struct_vader_midir$ConstBool_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ConstBool_t));
        vader_obj_header_init(_a6_obj, 1328u);
        _a6_obj->f_value = false;
        l12 = (void*) _a6_obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_type;
        vader_struct_vader_midir$InstrConst_t* _a7_obj = (vader_struct_vader_midir$InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrConst_t));
        vader_obj_header_init(_a7_obj, 1351u);
        _a7_obj->f_span = l8;
        _a7_obj->f_dst = l3;
        _a7_obj->f_value = vader_ref_box(l12);
        _a7_obj->f_type = l4;
        l8 = (void*) _a7_obj;
        vader_midir$emit(l0, vader_ref_box(l8));
        vader_struct_vader_midir$InstrMove_t* _a8_obj = (vader_struct_vader_midir$InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMove_t));
        vader_obj_header_init(_a8_obj, 1363u);
        _a8_obj->f_span = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_span;
        _a8_obj->f_dst = l6;
        _a8_obj->f_src = l3;
        l8 = (void*) _a8_obj;
        vader_midir$emit(l0, vader_ref_box(l8));
    } else {
        l4 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_right;
        l4 = vader_midir$build_expr(l0, l4);
        if (!(l4.tag == 0u)) {
            if (!(((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u)) {
                l8 = VADER_UNION_FIELD(void*, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_span, ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_right.payload.obj);
                l3 = ((int32_t) l4.payload.i);
                vader_struct_vader_midir$InstrMove_t* _a9_obj = (vader_struct_vader_midir$InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMove_t));
                vader_obj_header_init(_a9_obj, 1363u);
                _a9_obj->f_span = l8;
                _a9_obj->f_dst = l6;
                _a9_obj->f_src = l3;
                l8 = (void*) _a9_obj;
                vader_midir$emit(l0, vader_ref_box(l8));
            }
        }
    }
    if (((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u) {
        ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l11);
        VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
        { vader_box_t __vret = vader_box_i32(338u, l6); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_midir$TermBranch_t* _a10_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
    vader_obj_header_init(_a10_obj, 1380u);
    _a10_obj->f_span = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_span;
    _a10_obj->f_target = l11;
    l8 = (void*) _a10_obj;
    vader_midir$terminate(l0, vader_ref_box(l8));
    ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = vader_box_i32(338u, l11);
    VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l0);
    { vader_box_t __vret = vader_box_i32(338u, l6); vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir$build_stmt(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null(), l4 = vader_box_null(), l10 = vader_box_null();
    vader_string_t l3 = 0;
    void* l5 = NULL;
    void* l9 = NULL;
    int32_t l6, l7;
    int64_t l8;
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &l10 };
    void** gc_raw_roots[4] = { &l0, &l5, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1285u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_value;
        t1 = vader_midir$is_dest_passing_shape(l2);
        if (t1) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_name;
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_type;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_symbol;
            l6 = vader_midir$declare_local(l0, l3, l4, vader_ref_box(l5));
            l5 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_local_by_sym_id;
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_symbol)->f_id;
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l5, l7, l6);
            if (!(((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u)) {
                vader_midir$build_expr_into(l0, l2, l6);
            }
        } else {
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_type;
            l2 = vader_midir$build_held(l0, l2, l4);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_name;
            t0 = l1.payload.obj;
            l4 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_type;
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_symbol;
            l6 = vader_midir$declare_local(l0, l3, l4, vader_ref_box(l5));
            l5 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_local_by_sym_id;
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_symbol)->f_id;
            std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l5, l7, l6);
            if (!(l2.tag == 0u)) {
                if (!(((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u)) {
                    t0 = l1.payload.obj;
                    l5 = ((vader_struct_vader_lower_ir$LoweredLet_t*) t0)->f_span;
                    l7 = ((int32_t) l2.payload.i);
                    vader_struct_vader_midir$InstrMove_t* _a0_obj = (vader_struct_vader_midir$InstrMove_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrMove_t));
                    vader_obj_header_init(_a0_obj, 1363u);
                    _a0_obj->f_span = l5;
                    _a0_obj->f_dst = l6;
                    _a0_obj->f_src = l7;
                    l5 = (void*) _a0_obj;
                    vader_midir$emit(l0, vader_ref_box(l5));
                }
            }
        }
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1256u) {
        l5 = l1.payload.obj;
        vader_midir$build_assign(l0, l5);
    } else if (l1.tag == 1278u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_value;
        l5 = ((vader_struct_vader_midir$ProjectCtx_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_project)->f_globals;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_slot;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l8)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        l4 = ((vader_struct_vader_lower_ir$GlobalSlot_t*) t0)->f_type;
        l2 = vader_midir$build_held(l0, l2, l4);
        if (!(l2.tag == 0u)) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_span;
            t0 = l1.payload.obj;
            t2 = ((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_slot;
            l6 = ((int32_t) (int64_t) t2);
            l7 = ((int32_t) l2.payload.i);
            l9 = ((vader_struct_vader_midir$ProjectCtx_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_project)->f_globals;
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_lower_ir$LoweredGlobalSet_t*) t0)->f_slot;
            vader_array_t* _a2_slotarr = ((vader_array_t*) l9);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l8)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
            l2 = ((vader_struct_vader_lower_ir$GlobalSlot_t*) t0)->f_type;
            vader_struct_vader_midir$InstrGlobalSet_t* _a3_obj = (vader_struct_vader_midir$InstrGlobalSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrGlobalSet_t));
            vader_obj_header_init(_a3_obj, 1360u);
            _a3_obj->f_span = l5;
            _a3_obj->f_slot = l6;
            _a3_obj->f_value = l7;
            _a3_obj->f_type = l2;
            l5 = (void*) _a3_obj;
            vader_midir$emit(l0, vader_ref_box(l5));
        }
    } else if (l1.tag == 1266u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_target;
        l2 = vader_midir$build_expr(l0, l2);
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l10 = ((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_value_type;
        l4 = vader_midir$build_held(l0, l4, l10);
        if (!(l2.tag == 0u)) {
            if (!(l4.tag == 0u)) {
                t0 = l1.payload.obj;
                l5 = ((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_span;
                l6 = ((int32_t) l2.payload.i);
                l7 = ((int32_t) l4.payload.i);
                t0 = l1.payload.obj;
                l2 = ((vader_struct_vader_lower_ir$LoweredCellSet_t*) t0)->f_value_type;
                vader_struct_vader_midir$InstrCellSet_t* _a4_obj = (vader_struct_vader_midir$InstrCellSet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCellSet_t));
                vader_obj_header_init(_a4_obj, 1350u);
                _a4_obj->f_span = l5;
                _a4_obj->f_cell = l6;
                _a4_obj->f_value = l7;
                _a4_obj->f_value_type = l2;
                l5 = (void*) _a4_obj;
                vader_midir$emit(l0, vader_ref_box(l5));
            }
        }
    } else if (l1.tag == 1272u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredDeferPush_t*) t0)->f_thunk;
        l2 = vader_midir$build_expr(l0, l2);
        if (!(l2.tag == 0u)) {
            t0 = l1.payload.obj;
            l5 = ((vader_struct_vader_lower_ir$LoweredDeferPush_t*) t0)->f_span;
            l6 = ((int32_t) l2.payload.i);
            vader_struct_vader_midir$InstrDeferPush_t* _a5_obj = (vader_struct_vader_midir$InstrDeferPush_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrDeferPush_t));
            vader_obj_header_init(_a5_obj, 1354u);
            _a5_obj->f_span = l5;
            _a5_obj->f_value = l6;
            l5 = (void*) _a5_obj;
            vader_midir$emit(l0, vader_ref_box(l5));
        }
    } else if (l1.tag == 1271u) {
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredDeferPopExec_t*) t0)->f_span;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_lower_ir$LoweredDeferPopExec_t*) t0)->f_count;
        vader_struct_vader_midir$InstrDeferPopExec_t* _a6_obj = (vader_struct_vader_midir$InstrDeferPopExec_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrDeferPopExec_t));
        vader_obj_header_init(_a6_obj, 1353u);
        _a6_obj->f_span = l5;
        _a6_obj->f_count = l6;
        l5 = (void*) _a6_obj;
        vader_midir$emit(l0, vader_ref_box(l5));
    } else if (l1.tag == 1273u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredExprStmt_t*) t0)->f_expr;
        vader_midir$build_expr(l0, l2);
    } else if (l1.tag == 1292u) {
        vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 338u);
        l5 = (void*) _a7_arr;
        t0 = l1.payload.obj;
        if (!(((vader_struct_vader_lower_ir$LoweredReturn_t*) t0)->f_value.tag == 0u)) {
            t0 = l1.payload.obj;
            l2 = ((vader_struct_vader_lower_ir$LoweredReturn_t*) t0)->f_value;
            l4 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_return_type;
            l2 = vader_midir$build_held(l0, l2, l4);
            if (!(l2.tag == 0u)) {
                l6 = ((int32_t) l2.payload.i);
                vader_array_push_i32((vader_array_t*) l5, l6);
            }
        }
        t0 = l1.payload.obj;
        vader_struct_vader_midir$TermReturn_t* _a8_obj = (vader_struct_vader_midir$TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermReturn_t));
        vader_obj_header_init(_a8_obj, 1382u);
        _a8_obj->f_span = ((vader_struct_vader_lower_ir$LoweredReturn_t*) t0)->f_span;
        _a8_obj->f_values = l5;
        l5 = (void*) _a8_obj;
        vader_midir$terminate(l0, vader_ref_box(l5));
    } else if (l1.tag == 1286u) {
        l5 = l1.payload.obj;
        vader_midir$build_loop(l0, l5);
    } else if (l1.tag == 1284u) {
        l5 = l1.payload.obj;
        vader_midir$build_labelled_block(l0, l5);
    } else if (l1.tag == 1261u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredBreak_t*) t0)->f_label;
        l5 = vader_midir$resolve_loop_frame(l0, l2);
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_lower_ir$LoweredBreak_t*) t0)->f_span;
        l6 = ((vader_struct_vader_midir$LoopFrame_t*) l5)->f_exit_id;
        vader_struct_vader_midir$TermBranch_t* _a9_obj = (vader_struct_vader_midir$TermBranch_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermBranch_t));
        vader_obj_header_init(_a9_obj, 1380u);
        _a9_obj->f_span = l9;
        _a9_obj->f_target = l6;
        l5 = (void*) _a9_obj;
        vader_midir$terminate(l0, vader_ref_box(l5));
    } else if (l1.tag == 1269u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredContinue_t*) t0)->f_label;
        l5 = vader_midir$resolve_loop_frame(l0, l2);
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_lower_ir$LoweredContinue_t*) t0)->f_span;
        vader_midir$build_back_edge(l0, l5, l9);
    } else {
        if (!((l1.tag == 1257u || l1.tag == 1305u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_host_std_abort$panic(2336u);
        vader_unreachable("a no-return call returned");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir$build_stored(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1279u) {
        l2 = l1.payload.obj;
        t0 = vader_midir$stored_ident(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1274u) {
        l2 = l1.payload.obj;
        t0 = vader_midir$stored_field(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1301u) {
        l2 = l1.payload.obj;
        t0 = vader_midir$stored_union_field(l0, l2);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 1264u)) {
        l3 = l1;
        t0 = vader_midir$build_expr(l0, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l1.payload.obj;
    t0 = vader_midir$stored_cell(l0, l2);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_struct_lit(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null(), l8 = vader_box_null(), l9 = vader_box_null();
    int64_t l5, l6;
    int32_t l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[3] = { &l4, &l8, &l9 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_struct_vader_midir$ProjectCtx_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_project)->f_slots;
    l4 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) l1)->f_type;
    l3 = vader_midir$literal_slots(l3, l4);
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredStructLit_t*) l1)->f_fields)->length;
    while ((l5 < l6)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredStructLit_t*) l1)->f_fields);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l5)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        l4 = ((vader_struct_vader_lower_ir$LoweredStructLitField_t*) t0)->f_value;
        l8 = vader_midir$type_at(l3, l5);
        l9 = vader_midir$build_held(l0, l4, l8);
        if (l9.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        l7 = ((int32_t) l9.payload.i);
        vader_array_push_i32((vader_array_t*) l2, l7);
        l5 = (l5 + INT64_C(1));
    }
    l4 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) l1)->f_type;
    l7 = vader_midir$fresh_tmp(l0, 2650u, l4);
    l3 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) l1)->f_span;
    l4 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) l1)->f_type;
    vader_struct_vader_midir$InstrStructNew_t* _a2_obj = (vader_struct_vader_midir$InstrStructNew_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrStructNew_t));
    vader_obj_header_init(_a2_obj, 1364u);
    _a2_obj->f_span = l3;
    _a2_obj->f_dst = l7;
    _a2_obj->f_type = l4;
    _a2_obj->f_fields = l2;
    _a2_obj->f_stack = false;
    l2 = (void*) _a2_obj;
    vader_midir$emit(l0, vader_ref_box(l2));
    { vader_box_t __vret = vader_box_i32(338u, l7); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_type_check(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredTypeCheck_t*) l1)->f_value;
    l3 = vader_midir$build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_ir$LoweredTypeCheck_t*) l1)->f_type;
    l4 = vader_midir$fresh_tmp(l0, 2756u, l3);
    l5 = ((vader_struct_vader_lower_ir$LoweredTypeCheck_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_ir$LoweredTypeCheck_t*) l1)->f_check_type;
    vader_struct_vader_midir$InstrTypeCheck_t* _a0_obj = (vader_struct_vader_midir$InstrTypeCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrTypeCheck_t));
    vader_obj_header_init(_a0_obj, 1365u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_check_type = l3;
    l5 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l5));
    { vader_box_t __vret = vader_box_i32(338u, l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_type_const(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l5 = vader_box_null();
    int32_t l3;
    void* l4 = NULL;
    vader_box_t* gc_roots[2] = { &l2, &l5 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_lower_ir$LoweredTypeConst_t*) l1)->f_type;
    l3 = vader_midir$fresh_tmp(l0, 2757u, l2);
    l4 = ((vader_struct_vader_lower_ir$LoweredTypeConst_t*) l1)->f_span;
    l2 = ((vader_struct_vader_lower_ir$LoweredTypeConst_t*) l1)->f_type;
    l5 = ((vader_struct_vader_lower_ir$LoweredTypeConst_t*) l1)->f_value;
    vader_struct_vader_midir$InstrTypeConst_t* _a0_obj = (vader_struct_vader_midir$InstrTypeConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrTypeConst_t));
    vader_obj_header_init(_a0_obj, 1366u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l3;
    _a0_obj->f_type = l2;
    _a0_obj->f_value_type = l5;
    l4 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l4));
    { vader_box_t __vret = vader_box_i32(338u, l3); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_unary(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    int32_t l4, l5;
    void* l6 = NULL;
    uint8_t l7;
    int32_t t0;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, ((vader_struct_vader_lower_ir$LoweredUnary_t*) l1)->f_operand.payload.obj);
    l3 = ((vader_struct_vader_lower_ir$LoweredUnary_t*) l1)->f_type;
    l2 = vader_midir$computation_width(l2, vader_box_obj(0u, NULL), l3);
    l3 = ((vader_struct_vader_lower_ir$LoweredUnary_t*) l1)->f_operand;
    l3 = vader_midir$build_held(l0, l3, l2);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = ((int32_t) l3.payload.i);
    l2 = vader_midir$computed_type(((vader_struct_vader_lower_ir$LoweredUnary_t*) l1)->f_type, l2);
    l5 = vader_midir$fresh_tmp(l0, 2821u, l2);
    l6 = ((vader_struct_vader_lower_ir$LoweredUnary_t*) l1)->f_span;
    l7 = ((vader_struct_vader_lower_ir$LoweredUnary_t*) l1)->f_op;
    vader_struct_vader_midir$InstrUnOp_t* _a0_obj = (vader_struct_vader_midir$InstrUnOp_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrUnOp_t));
    vader_obj_header_init(_a0_obj, 1367u);
    _a0_obj->f_span = l6;
    _a0_obj->f_dst = l5;
    _a0_obj->f_op = l7;
    _a0_obj->f_operand = l4;
    _a0_obj->f_type = l2;
    l6 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l6));
    l2 = ((vader_struct_vader_lower_ir$LoweredUnary_t*) l1)->f_type;
    l6 = ((vader_struct_vader_lower_ir$LoweredUnary_t*) l1)->f_span;
    t0 = vader_midir$held_in(l0, l5, l2, l6);
    { vader_box_t __vret = vader_box_i32(338u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_union_field(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null();
    void* l4 = NULL;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = vader_midir$stored_union_field(l0, l1);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_ir$LoweredUnionField_t*) l1)->f_type;
    l4 = ((vader_struct_vader_lower_ir$LoweredUnionField_t*) l1)->f_span;
    t0 = vader_midir$read_as(l0, l2, l3, l4);
    { vader_box_t __vret = vader_box_i32(338u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_unreachable_type(void* l0, vader_box_t l1, void* l2, vader_string_t l3) {
    vader_box_t l4 = vader_box_null();
    void* l5 = NULL;
    bool t0;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = vader_core_types$is_void(l1);
    if (t0) {
        l4 = vader_box_obj(0u, NULL);
        vader_struct_vader_midir$TermUnreachable_t* _a0_obj = (vader_struct_vader_midir$TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermUnreachable_t));
        vader_obj_header_init(_a0_obj, 1383u);
        _a0_obj->f_span = l2;
        _a0_obj->f_reason = l3;
        l5 = (void*) _a0_obj;
        vader_midir$terminate(l0, vader_ref_box(l5));
        { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = vader_midir$declare_local(l0, 2823u, l1, vader_box_obj(0u, NULL));
    l4 = vader_box_i32(338u, t1);
    vader_struct_vader_midir$TermUnreachable_t* _a1_obj = (vader_struct_vader_midir$TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermUnreachable_t));
    vader_obj_header_init(_a1_obj, 1383u);
    _a1_obj->f_span = l2;
    _a1_obj->f_reason = l3;
    l5 = (void*) _a1_obj;
    vader_midir$terminate(l0, vader_ref_box(l5));
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$build_virtual_call(void* l0, void* l1) {
    int32_t l2;
    vader_box_t l3 = vader_box_null(), l7 = vader_box_null();
    void* l4 = NULL;
    void* l5 = NULL;
    void* l10 = NULL;
    bool l6;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    bool t0;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l3, &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l5, &l10 };
    vader_string_t* gc_atom_roots[2] = { &l8, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) l1)->f_receiver;
    l3 = vader_midir$build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l4 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) l1)->f_args;
    l5 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) l1)->f_param_types;
    l3 = vader_midir$build_args(l0, l4, l5);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = l3.payload.obj;
    t0 = vader_core_types$is_void(((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) l1)->f_type);
    if (t0) {
        l6 = true;
    } else {
        l6 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) l1)->f_type.tag == 913u;
    }
    if (l6) {
        l3 = vader_box_obj(0u, NULL);
    } else {
        l7 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) l1)->f_type;
        t1 = vader_midir$fresh_tmp(l0, 3000u, l7);
        l3 = vader_box_i32(338u, t1);
    }
    l5 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) l1)->f_span;
    l8 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) l1)->f_trait_name;
    l9 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) l1)->f_method;
    l7 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) l1)->f_type;
    l10 = ((vader_struct_vader_lower_ir$LoweredVirtualCall_t*) l1)->f_param_types;
    vader_struct_vader_midir$InstrVirtualCall_t* _a0_obj = (vader_struct_vader_midir$InstrVirtualCall_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrVirtualCall_t));
    vader_obj_header_init(_a0_obj, 1370u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l3;
    _a0_obj->f_trait_name = l8;
    _a0_obj->f_method = l9;
    _a0_obj->f_receiver = l2;
    _a0_obj->f_args = l4;
    _a0_obj->f_type = l7;
    _a0_obj->f_param_types = l10;
    l4 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l4));
    { vader_box_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir$c_variadic_fixed_of(void* l0) {
    void* l1;
    void* l4;
    int64_t l2, l3;
    vader_box_t l5;
    vader_string_t t0;
    int64_t t1;
    void* t2;
    l1 = l0;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l4)->f_name;
        if (t0 == 1703u) {
            t1 = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l4)->f_args)->length;
            if (t1 == INT64_C(1)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_toolchain_ast$Decorator_t*) l4)->f_args);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a1_slotarr, INT32_C(0))
                l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT32_C(0));
                if (l5.tag == 673u) {
                    t2 = l5.payload.obj;
                    t1 = toolchain_ast$int_literal_value(t2);
                    return ((int32_t) (int64_t) t1);
                }
            }
        }
        l3 = (l3 + INT64_C(1));
    }
    return INT32_C(-1);
}

vader_box_t vader_midir$call_single_dst(void* l0) {
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir$InstrCall_t*) l0)->f_dsts)->length;
    if (!(t0 != INT64_C(1))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$InstrCall_t*) l0)->f_dsts);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(338u, t1);
    }
    return vader_box_obj(0u, NULL);
}

int32_t vader_midir$callee_node(void* l0, void* l1) {
    void* l2;
    vader_box_t l3;
    int32_t l4;
    int32_t t0;
    int64_t t1;
    l2 = ((vader_struct_vader_midir$CalleeIndex_t*) l0)->f_resolution;
    l3 = vader_midir$function_called(((vader_struct_vader_midir$SlotTypes_t*) ((vader_struct_vader_midir$CfgResolution_t*) l2)->f_slots)->f_callees, l1);
    if (!(l3.tag == 0u)) {
        t0 = ((int32_t) l3.payload.i);
        return t0;
    }
    l3 = vader_midir$import_called(((vader_struct_vader_midir$SlotTypes_t*) ((vader_struct_vader_midir$CfgResolution_t*) l2)->f_slots)->f_callees, l1);
    if (l3.tag == 0u) {
        t0 = ((vader_struct_vader_midir$CalleeIndex_t*) l0)->f_unknown;
        return t0;
    }
    l4 = ((int32_t) l3.payload.i);
    t1 = ((vader_array_t*) ((vader_struct_vader_midir$CfgResolution_t*) l2)->f_functions)->length;
    t0 = vader_chk_add(i32, ((int32_t) (int64_t) t1), l4);
    return t0;
}

static bool vader_midir$callee_resolves(void* l0, void* l1) {
    void* l2;
    vader_box_t t0;
    l2 = ((vader_struct_vader_midir$SlotTypes_t*) ((vader_struct_vader_midir$CfgResolution_t*) l0)->f_slots)->f_callees;
    t0 = vader_midir$function_called(l2, l1);
    if (!(t0.tag == 0u)) {
        return true;
    }
    t0 = vader_midir$import_called(l2, l1);
    return !(t0.tag == 0u);
}

static int32_t vader_midir$cast_local(void* l0, int32_t l1, vader_box_t l2, vader_string_t l3, void* l4) {
    int32_t l5;
    void* l6 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l4, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = vader_midir$fresh_tmp(l0, l3, l2);
    vader_struct_vader_midir$InstrCast_t* _a0_obj = (vader_struct_vader_midir$InstrCast_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCast_t));
    vader_obj_header_init(_a0_obj, 1347u);
    _a0_obj->f_span = l4;
    _a0_obj->f_dst = l5;
    _a0_obj->f_value = l1;
    _a0_obj->f_type = l2;
    l6 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l6));
    { int32_t __vret = l5; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir$check_instruction_storage(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    int32_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l7 = 0;
    int64_t l10, l11;
    void* t0 = NULL;
    bool t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l1, &l5, &t2 };
    void** gc_raw_roots[6] = { &l0, &l2, &l6, &l8, &l9, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir$StorageCheck_t*) l0)->f_slots;
    if (l1.tag == 1363u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_src;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_dst;
        l5 = vader_midir$local_type(l0, l4);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrMove_t*) t0)->f_span;
        vader_midir$check_slot(l0, l3, l5, l6);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1356u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_value;
        t1 = vader_midir$holds_integer(l0, l3);
        if (t1) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_target;
            l5 = vader_midir$local_type(l0, l3);
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_field;
            l5 = vader_midir$field_slot(l2, l5, l7);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir$InstrFieldSet_t*) t0)->f_span;
            vader_midir$check_slot(l0, l3, l5, l6);
        }
    } else if (l1.tag == 1369u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_value;
        t1 = vader_midir$holds_integer(l0, l3);
        if (t1) {
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_target;
            l5 = vader_midir$local_type(l0, l3);
            t0 = l1.payload.obj;
            l7 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_field;
            l5 = vader_midir$field_slot(l2, l5, l7);
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_value;
            t0 = l1.payload.obj;
            l6 = ((vader_struct_vader_midir$InstrUnionFieldSet_t*) t0)->f_span;
            vader_midir$check_slot(l0, l3, l5, l6);
        }
    } else if (l1.tag == 1342u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_target;
        t2 = vader_midir$local_type(l0, l4);
        l5 = vader_midir$element_slot(t2);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_span;
        vader_midir$check_slot(l0, l3, l5, l6);
    } else if (l1.tag == 1341u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_target;
        t2 = vader_midir$local_type(l0, l4);
        l5 = vader_midir$element_slot(t2);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_span;
        vader_midir$check_slot(l0, l3, l5, l6);
    } else if (l1.tag == 1364u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_fields;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_type;
        l8 = vader_midir$literal_slots(l2, l5);
        t0 = l1.payload.obj;
        l9 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_span;
        vader_midir$check_values(l0, l6, l8, l9);
    } else if (l1.tag == 1340u) {
        t0 = l1.payload.obj;
        l5 = vader_midir$element_slot(((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_type);
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_elements;
        l10 = ((vader_array_t*) l6)->length;
        l11 = INT64_C(0);
        while ((l11 < l10)) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            l3 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l11];
            t0 = l1.payload.obj;
            l8 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_span;
            vader_midir$check_slot(l0, l3, l5, l8);
            l11 = (l11 + INT64_C(1));
        }
    } else if (l1.tag == 1360u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_type;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_span;
        vader_midir$check_slot(l0, l3, l5, l6);
    } else if (l1.tag == 1349u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value_type;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_span;
        vader_midir$check_slot(l0, l3, l5, l6);
    } else if (l1.tag == 1350u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_value;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_value_type;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_span;
        vader_midir$check_slot(l0, l3, l5, l6);
    } else if (l1.tag == 1345u) {
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_callee;
        l2 = vader_midir$params_of(l2, l8);
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_span;
        vader_midir$check_values(l0, l6, l2, l8);
    } else if (l1.tag == 1346u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l6 = vader_core_types$param_types_of(((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_fn_type);
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_span;
        vader_midir$check_values(l0, l2, l6, l8);
    } else if (l1.tag == 1370u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_param_types;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_span;
        vader_midir$check_values(l0, l2, l6, l8);
    } else if (l1.tag == 1361u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_args;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_param_types;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_span;
        vader_midir$check_values(l0, l2, l6, l8);
    } else if (l1.tag == 1343u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_lo;
        t0 = (void*) &vader_data_23;
        vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_span;
        vader_midir$check_slot(l0, l3, vader_ref_box(l2), l6);
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_hi;
        t0 = (void*) &vader_data_23;
        vader_array_t* _a2_slotarr = ((vader_array_t*) t0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) INT64_C(0));
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_span;
        vader_midir$check_slot(l0, l3, vader_ref_box(l2), l6);
    } else if (l1.tag == 1344u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_lhs;
        t0 = l1.payload.obj;
        l4 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_rhs;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_type;
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_span;
        vader_midir$check_operation(l0, l3, vader_box_i32(338u, l4), l5, l2);
    } else if (l1.tag == 1367u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_operand;
        t0 = l1.payload.obj;
        l5 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_type;
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_span;
        vader_midir$check_operation(l0, l3, vader_box_obj(0u, NULL), l5, l2);
    } else if (!((l1.tag == 1338u || l1.tag == 1339u || l1.tag == 1347u || l1.tag == 1348u || l1.tag == 1351u || l1.tag == 1352u || l1.tag == 1353u || l1.tag == 1354u || l1.tag == 1355u || l1.tag == 1357u || l1.tag == 1358u || l1.tag == 1359u || l1.tag == 1362u || l1.tag == 1365u || l1.tag == 1366u || l1.tag == 1368u))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$check_operation(void* l0, int32_t l1, vader_box_t l2, vader_box_t l3, void* l4) {
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null();
    int32_t l7;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l6, &t0 };
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_midir$local_type(l0, l1);
    l6 = vader_core_types$held_integer(t0);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l6.payload.obj;
    if (!(l2.tag == 0u)) {
        l7 = ((int32_t) l2.payload.i);
        t0 = vader_midir$local_type(l0, l7);
        l6 = vader_core_types$held_integer(t0);
        vader_midir$check_same_integer(l0, l5, l6, 2227u, l4);
    }
    l6 = vader_core_types$held_integer(l3);
    vader_midir$check_same_integer(l0, l5, l6, 2226u, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$check_return_storage(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int32_t l5;
    vader_box_t l6 = vader_box_null();
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_midir$StorageCheck_t*) l0)->f_function)->f_scalarised_results;
    t0 = ((vader_array_t*) l2)->length;
    if ((t0 > INT64_C(1))) {
        l3 = ((vader_struct_vader_midir$TermReturn_t*) l1)->f_values;
        l4 = ((vader_struct_vader_midir$TermReturn_t*) l1)->f_span;
        vader_midir$check_values(l0, l3, l2, l4);
        { vader_gc_top = gc_frame.prev; return; }
    }
    t0 = ((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) l1)->f_values)->length;
    if (t0 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) l1)->f_values);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        l6 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_midir$StorageCheck_t*) l0)->f_function)->f_return_type;
        l2 = ((vader_struct_vader_midir$TermReturn_t*) l1)->f_span;
        vader_midir$check_slot(l0, l5, l6, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$check_same_integer(void* l0, void* l1, vader_box_t l2, vader_string_t l3, void* l4) {
    void* l5 = NULL;
    void* l9 = NULL;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_box_t* gc_roots[2] = { &l2, &l6 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l5, &l9 };
    vader_string_t* gc_atom_roots[3] = { &l3, &l7, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = l2;
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l6.payload.obj;
    l7 = ((vader_struct_vader_support_integer$MachineInteger_t*) l5)->f_name;
    l8 = ((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_name;
    if (!(l7 == l8)) {
        l7 = ((vader_struct_vader_midir$StorageCheck_t*) l0)->f_where;
        l8 = ((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_name;
        l7 = concat_4(l7, 466u, l8, 1281u);
        l8 = ((vader_struct_vader_support_integer$MachineInteger_t*) l5)->f_name;
        l8 = concat_4(l3, 144u, l8, 1035u);
        l7 = concat_2(l7, l8);
        l5 = ((vader_struct_vader_midir$StorageCheck_t*) l0)->f_diags;
        l9 = vader_support_diagnostics$internal_error((uint8_t) 11, l4, l7);
        vader_array_push_ref((vader_array_t*) l5, l9);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$check_slot(void* l0, int32_t l1, vader_box_t l2, void* l3) {
    vader_box_t l4 = vader_box_null(), l6 = vader_box_null();
    void* l5 = NULL;
    void* l10 = NULL;
    vader_string_t l7 = 0;
    vader_string_t l8 = 0;
    vader_string_t l9 = 0;
    vader_box_t* gc_roots[3] = { &l2, &l4, &l6 };
    void** gc_raw_roots[4] = { &l0, &l3, &l5, &l10 };
    vader_string_t* gc_atom_roots[3] = { &l7, &l8, &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_midir$local_type(l0, l1);
    l6 = vader_midir$stored_conversion(l4, l2);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l6.payload.obj;
    l7 = ((vader_struct_vader_midir$StorageCheck_t*) l0)->f_where;
    l8 = vader_core_types$display_type(l4);
    l9 = vader_midir$stored_name(l4);
    l7 = concat_6(l7, 464u, l8, 1117u, l9, 1036u);
    l6 = l2;
    if (!(l6.tag == 0u)) {
        l4 = l6;
    }
    l8 = vader_core_types$display_type(l4);
    l9 = ((vader_struct_vader_support_integer$MachineInteger_t*) l5)->f_name;
    l8 = concat_5(2059u, l8, 1117u, l9, 1035u);
    l7 = concat_2(l7, l8);
    l5 = ((vader_struct_vader_midir$StorageCheck_t*) l0)->f_diags;
    l10 = vader_support_diagnostics$internal_error((uint8_t) 11, l3, l7);
    vader_array_push_ref((vader_array_t*) l5, l10);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$check_values(void* l0, void* l1, void* l2, void* l3) {
    int64_t l4, l5;
    int32_t l6;
    vader_box_t l7 = vader_box_null();
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = INT64_C(0);
    l5 = ((vader_array_t*) l1)->length;
    while ((l4 < l5)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        l7 = vader_midir$type_at(l2, l4);
        vader_midir$check_slot(l0, l6, l7, l3);
        l4 = (l4 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t vader_midir$computation_integer(vader_box_t l0, vader_box_t l1, vader_box_t l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    vader_box_t l4 = vader_box_null(), l5 = vader_box_null();
    vader_string_t l6 = 0;
    vader_string_t l7 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[5] = { &l0, &l1, &l2, &l4, &l5 };
    void** gc_raw_roots[3] = { &l3, &l8, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 5u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = vader_core_types$held_integer(l0);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l4.payload.obj;
    l4 = vader_core_types$held_integer(l2);
    l5 = vader_midir$operand_width(l1, l3);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l5.payload.obj;
    l6 = ((vader_struct_vader_support_integer$MachineInteger_t*) t0)->f_name;
    l7 = ((vader_struct_vader_support_integer$MachineInteger_t*) l3)->f_name;
    if (l6 == l7) {
        if (l4.tag == 0u) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
        t0 = l4.payload.obj;
        l6 = ((vader_struct_vader_support_integer$MachineInteger_t*) t0)->f_name;
        l7 = ((vader_struct_vader_support_integer$MachineInteger_t*) l3)->f_name;
        if (l6 == l7) {
            { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
        }
    }
    l3 = ((vader_struct_vader_support_integer$MachineInteger_t*) l3)->f_values;
    t0 = l5.payload.obj;
    l8 = ((vader_struct_vader_support_integer$MachineInteger_t*) t0)->f_values;
    l3 = vader_support_integer$interval_join(l3, l8);
    if (l4.tag == 0u) {
        t0 = vader_support_integer$narrowest_machine_integer(l3);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l4.payload.obj;
    l8 = ((vader_struct_vader_support_integer$MachineInteger_t*) t0)->f_values;
    l3 = vader_support_integer$interval_join(l3, l8);
    t0 = vader_support_integer$narrowest_machine_integer(l3);
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$computation_width(vader_box_t l0, vader_box_t l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    void* t2 = NULL;
    bool t1;
    vader_box_t* gc_roots[4] = { &l0, &l1, &l2, &l3 };
    void** gc_raw_roots[2] = { &t0, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 916u) {
        t0 = l0.payload.obj;
        t1 = vader_midir$same_bounds(t0, l1);
        if (t1) {
            t0 = l0.payload.obj;
            t1 = vader_midir$same_bounds(t0, l2);
            if (t1) {
                { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
            }
        }
    }
    l3 = vader_midir$computation_integer(l0, l1, l2);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = l3.payload.obj;
    t2 = vader_core_types$machine_integer_type(t0);
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir$compute_dominators(void* l0, void* l1) {
    int64_t l2, l9, l13, l14;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    int32_t l4, l5, l10, l11, l15, l16, l17, l18, l19;
    bool l7;
    void* t0 = NULL;
    bool t1;
    int32_t t2;
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l6, &l8, &l12, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 338u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l2);
    l3 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_entry;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_entry;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l4] = (int32_t) l5;
    l6 = vader_midir$reverse_postorder(l0);
    l7 = true;
    while (l7) {
        l7 = false;
        l8 = l6;
        l2 = ((vader_array_t*) l8)->length;
        l9 = INT64_C(0);
        while ((l9 < l2)) {
            vader_array_t* _a3_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
            l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l9];
            l5 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_entry;
            t1 = vader_midir$BlockId$std_core$Equals$equals(l4, l5);
            if (t1) {
                l9 = (l9 + INT64_C(1));
                continue;
            }
            l10 = INT32_C(-1);
            l11 = l4;
            vader_array_t* _a4_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l11)
            l12 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l11);
            l13 = ((vader_array_t*) l12)->length;
            l14 = INT64_C(0);
            while ((l14 < l13)) {
                vader_array_t* _a5_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
                l15 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l14];
                l16 = l15;
                vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l16)
                t2 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l16];
                if (t2 == INT32_C(-1)) {
                    l14 = (l14 + INT64_C(1));
                    continue;
                }
                if (l10 == INT32_C(-1)) {
                    l10 = l15;
                } else {
                    l17 = l10;
                    l10 = vader_midir$intersect_dom_tree(l15, l17, l3);
                }
                l14 = (l14 + INT64_C(1));
            }
            if (l10 != INT32_C(-1)) {
                l18 = l4;
                vader_array_t* _a7_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l18)
                t2 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l18];
                if (t2 != l10) {
                    l19 = l4;
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l3);
                    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a8_slotarr, l19)
                    ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l19] = (int32_t) l10;
                    l7 = true;
                }
            }
            l9 = (l9 + INT64_C(1));
        }
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir$compute_liveness(void* l0) {
    int64_t l1, l4, l15, l16, l21, l22, l29, l30, l32, l33;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l20 = NULL;
    void* l27 = NULL;
    void* l35 = NULL;
    void* l36 = NULL;
    void* l37 = NULL;
    vader_box_t l17 = vader_box_null(), l19 = vader_box_null(), l24 = vader_box_null(), l26 = vader_box_null();
    int32_t l23, l25, l31, l34;
    bool l28;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[4] = { &l17, &l19, &l24, &l26 };
    void** gc_raw_roots[20] = {
        &l0, &l2, &l3, &l5, &l6, &l7, &l8, &l9, &l10, &l11, &l12, &l13, &l14, &l18, &l20, &l27,
        &l35, &l36, &l37, &t0,
    };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 20u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a0_arr = vader_array_new(38u, 0u, 13u, 613u);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(38u, 0u, 13u, 613u);
    t0 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l3 = (void*) _a3_arr;
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
        l5 = vader_array_ref_load_obj(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l4);
        vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 338u);
        l6 = (void*) _a5_arr;
        vader_array_t* _a6_arr = vader_array_new(20u, 0u, 12u, 333u);
        l7 = (void*) _a6_arr;
        vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 338u);
        l8 = (void*) _a7_arr;
        vader_struct_std_collections$MutableMap__i32__bool_t* _a8_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
        vader_obj_header_init(_a8_obj, 470u);
        _a8_obj->f_ekeys = l6;
        _a8_obj->f_evals = l7;
        _a8_obj->f_index = l8;
        _a8_obj->f_mask = INT64_C(0);
        _a8_obj->f_grow_at = INT64_C(0);
        _a8_obj->f_size = INT64_C(0);
        _a8_obj->f_tombs = INT64_C(0);
        t0 = (void*) _a8_obj;
        vader_struct_std_collections$MutableSet__i32_t* _a9_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
        vader_obj_header_init(_a9_obj, 613u);
        _a9_obj->f_inner = t0;
        l9 = (void*) _a9_obj;
        vader_array_t* _a10_arr = vader_array_new(23u, 0u, 7u, 338u);
        l10 = (void*) _a10_arr;
        vader_array_t* _a11_arr = vader_array_new(20u, 0u, 12u, 333u);
        l11 = (void*) _a11_arr;
        vader_array_t* _a12_arr = vader_array_new(23u, 0u, 7u, 338u);
        l12 = (void*) _a12_arr;
        vader_struct_std_collections$MutableMap__i32__bool_t* _a13_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
        vader_obj_header_init(_a13_obj, 470u);
        _a13_obj->f_ekeys = l10;
        _a13_obj->f_evals = l11;
        _a13_obj->f_index = l12;
        _a13_obj->f_mask = INT64_C(0);
        _a13_obj->f_grow_at = INT64_C(0);
        _a13_obj->f_size = INT64_C(0);
        _a13_obj->f_tombs = INT64_C(0);
        t0 = (void*) _a13_obj;
        vader_struct_std_collections$MutableSet__i32_t* _a14_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
        vader_obj_header_init(_a14_obj, 613u);
        _a14_obj->f_inner = t0;
        l13 = (void*) _a14_obj;
        l14 = ((vader_struct_vader_midir$BasicBlock_t*) l5)->f_instructions;
        l15 = ((vader_array_t*) l14)->length;
        l16 = INT64_C(0);
        while ((l16 < l15)) {
            vader_array_t* _a15_slotarr = ((vader_array_t*) l14);
            VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a15_slotarr, l16)
            l17 = vader_array_ref_load_box(_a15_slotarr->buf, _a15_slotarr->offset + (size_t) l16);
            vader_struct___lambda_env_vader_midir_21_t* _a16_obj = (vader_struct___lambda_env_vader_midir_21_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_21_t));
            vader_obj_header_init(_a16_obj, 439u);
            _a16_obj->f_cap_0 = l13;
            _a16_obj->f_cap_1 = l9;
            t0 = (void*) _a16_obj;
            vader_fn_t* _a17_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
            vader_obj_header_init(_a17_closure, 305u);
            _a17_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_20;
            _a17_closure->env = t0;
            l18 = (void*) _a17_closure;
            vader_midir$for_each_read_local(l17, l18);
            l19 = vader_midir$multi_dsts(l17);
            if (l19.tag == 0u) {
                l24 = vader_midir$dst_of(l17);
                if (!(l24.tag == 0u)) {
                    l25 = ((int32_t) l24.payload.i);
                    std_collections$add__vader_midir$LocalId(l13, l25);
                }
            } else {
                l20 = l19.payload.obj;
                l21 = ((vader_array_t*) l20)->length;
                l22 = INT64_C(0);
                while ((l22 < l21)) {
                    vader_array_t* _a18_slotarr = ((vader_array_t*) l20);
                    VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
                    l23 = ((int32_t*) _a18_slotarr->buf->slots)[_a18_slotarr->offset + (size_t) l22];
                    std_collections$add__vader_midir$LocalId(l13, l23);
                    l22 = (l22 + INT64_C(1));
                }
            }
            l16 = (l16 + INT64_C(1));
        }
        l26 = ((vader_struct_vader_midir$BasicBlock_t*) l5)->f_terminator;
        vader_struct___lambda_env_vader_midir_23_t* _a19_obj = (vader_struct___lambda_env_vader_midir_23_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_23_t));
        vader_obj_header_init(_a19_obj, 440u);
        _a19_obj->f_cap_0 = l13;
        _a19_obj->f_cap_1 = l9;
        t0 = (void*) _a19_obj;
        vader_fn_t* _a20_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
        vader_obj_header_init(_a20_closure, 305u);
        _a20_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_22;
        _a20_closure->env = t0;
        l27 = (void*) _a20_closure;
        vader_midir$for_each_read_in_terminator(l26, l27);
        vader_array_push_ref((vader_array_t*) l2, l9);
        vader_array_push_ref((vader_array_t*) l3, l13);
        l4 = (l4 + INT64_C(1));
    }
    vader_array_t* _a21_arr = vader_array_new(3u, 0u, 13u, 23u);
    t0 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l5 = (void*) _a22_arr;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l6)->length;
    l15 = INT64_C(0);
    while ((l15 < l4)) {
        vader_array_t* _a23_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a23_slotarr)
        t0 = vader_array_ref_load_obj(_a23_slotarr->buf, _a23_slotarr->offset + (size_t) l15);
        l7 = vader_midir$successors_of(t0);
        vader_array_push_ref((vader_array_t*) l5, l7);
        l15 = (l15 + INT64_C(1));
    }
    l6 = (void*) &vader_fn_static___lambda_vader_midir_24;
    l6 = std_core$filled__std_collections_MutableSet_i32_(l1, l6);
    l7 = (void*) &vader_fn_static___lambda_vader_midir_25;
    l7 = std_core$filled__std_collections_MutableSet_i32_(l1, l7);
    vader_array_t* _a24_arr = vader_array_new(23u, 0u, 7u, 338u);
    l8 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(20u, 0u, 12u, 333u);
    l9 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(23u, 0u, 7u, 338u);
    l10 = (void*) _a26_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a27_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a27_obj, 470u);
    _a27_obj->f_ekeys = l8;
    _a27_obj->f_evals = l9;
    _a27_obj->f_index = l10;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_grow_at = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a27_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a28_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a28_obj, 613u);
    _a28_obj->f_inner = t0;
    l8 = (void*) _a28_obj;
    vader_array_t* _a29_arr = vader_array_new(23u, 0u, 7u, 338u);
    l9 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(20u, 0u, 12u, 333u);
    l10 = (void*) _a30_arr;
    vader_array_t* _a31_arr = vader_array_new(23u, 0u, 7u, 338u);
    l11 = (void*) _a31_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a32_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a32_obj, 470u);
    _a32_obj->f_ekeys = l9;
    _a32_obj->f_evals = l10;
    _a32_obj->f_index = l11;
    _a32_obj->f_mask = INT64_C(0);
    _a32_obj->f_grow_at = INT64_C(0);
    _a32_obj->f_size = INT64_C(0);
    _a32_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a32_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a33_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a33_obj, 613u);
    _a33_obj->f_inner = t0;
    l9 = (void*) _a33_obj;
    l28 = true;
    while (l28) {
        l28 = false;
        l4 = l1;
        while ((l4 > INT64_C(0))) {
            l4 = vader_chk_sub(i64, l4, INT64_C(1));
            std_collections$clear__vader_midir$LocalId(l8);
            vader_array_t* _a34_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a34_slotarr, l4)
            l10 = vader_array_ref_load_obj(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l4);
            l15 = ((vader_array_t*) l10)->length;
            l16 = INT64_C(0);
            while ((l16 < l15)) {
                vader_array_t* _a35_slotarr = ((vader_array_t*) l10);
                VADER_ARRAY_RESOLVE_BUF(_a35_slotarr)
                l23 = ((int32_t*) _a35_slotarr->buf->slots)[_a35_slotarr->offset + (size_t) l16];
                vader_array_t* _a36_slotarr = ((vader_array_t*) l6);
                VADER_ARRAY_RESOLVE_BUF(_a36_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a36_slotarr, l23)
                l11 = vader_array_ref_load_obj(_a36_slotarr->buf, _a36_slotarr->offset + (size_t) l23);
                l12 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l11)->f_inner)->f_ekeys;
                l21 = INT64_C(0);
                l22 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l11)->f_inner)->f_size;
                while ((l21 < l22)) {
                    vader_array_t* _a37_slotarr = ((vader_array_t*) l12);
                    VADER_ARRAY_RESOLVE_BUF(_a37_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a37_slotarr, l21)
                    l25 = ((int32_t*) _a37_slotarr->buf->slots)[_a37_slotarr->offset + (size_t) l21];
                    std_collections$add__vader_midir$LocalId(l8, l25);
                    l21 = (l21 + INT64_C(1));
                }
                l16 = (l16 + INT64_C(1));
            }
            std_collections$clear__vader_midir$LocalId(l9);
            vader_array_t* _a38_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l4)
            l13 = vader_array_ref_load_obj(_a38_slotarr->buf, _a38_slotarr->offset + (size_t) l4);
            l14 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l13)->f_inner)->f_ekeys;
            l29 = INT64_C(0);
            l30 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l13)->f_inner)->f_size;
            while ((l29 < l30)) {
                vader_array_t* _a39_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a39_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a39_slotarr, l29)
                l31 = ((int32_t*) _a39_slotarr->buf->slots)[_a39_slotarr->offset + (size_t) l29];
                std_collections$add__vader_midir$LocalId(l9, l31);
                l29 = (l29 + INT64_C(1));
            }
            l18 = l8;
            l20 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l18)->f_inner)->f_ekeys;
            l32 = INT64_C(0);
            l33 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l18)->f_inner)->f_size;
            while ((l32 < l33)) {
                vader_array_t* _a40_slotarr = ((vader_array_t*) l20);
                VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l32)
                l34 = ((int32_t*) _a40_slotarr->buf->slots)[_a40_slotarr->offset + (size_t) l32];
                vader_array_t* _a41_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a41_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a41_slotarr, l4)
                t0 = vader_array_ref_load_obj(_a41_slotarr->buf, _a41_slotarr->offset + (size_t) l4);
                t1 = std_collections$MutableSet$std_core$Contains$contains__i32(t0, l34);
                if (!(t1)) {
                    std_collections$add__vader_midir$LocalId(l9, l34);
                }
                l32 = (l32 + INT64_C(1));
            }
            vader_array_t* _a42_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a42_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a42_slotarr, l4)
            l27 = vader_array_ref_load_obj(_a42_slotarr->buf, _a42_slotarr->offset + (size_t) l4);
            t1 = vader_midir$sets_equal(l8, l27);
            if (!(t1)) {
                vader_array_t* _a43_slotarr = ((vader_array_t*) l7);
                VADER_ARRAY_RESOLVE_BUF(_a43_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l4)
                l35 = vader_array_ref_load_obj(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l4);
                VADER_ARRAY_CHECK_INDEX(_a43_slotarr, l4)
                vader_array_ref_store(_a43_slotarr->buf, _a43_slotarr->offset + (size_t) l4, l8);
                VADER_WRITE_BARRIER(_a43_slotarr->buf);
                l8 = l35;
                l28 = true;
            }
            vader_array_t* _a44_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a44_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a44_slotarr, l4)
            l36 = vader_array_ref_load_obj(_a44_slotarr->buf, _a44_slotarr->offset + (size_t) l4);
            t1 = vader_midir$sets_equal(l9, l36);
            if (t1) {
                continue;
            }
            vader_array_t* _a45_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a45_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l4)
            l37 = vader_array_ref_load_obj(_a45_slotarr->buf, _a45_slotarr->offset + (size_t) l4);
            VADER_ARRAY_CHECK_INDEX(_a45_slotarr, l4)
            vader_array_ref_store(_a45_slotarr->buf, _a45_slotarr->offset + (size_t) l4, l9);
            VADER_WRITE_BARRIER(_a45_slotarr->buf);
            l9 = l37;
            l28 = true;
        }
    }
    vader_struct_vader_midir$Liveness_t* _a46_obj = (vader_struct_vader_midir$Liveness_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$Liveness_t));
    vader_obj_header_init(_a46_obj, 1371u);
    _a46_obj->f_live_in = l6;
    _a46_obj->f_live_out = l7;
    t0 = (void*) _a46_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$computed_type(vader_box_t l0, vader_box_t l1) {
    void* l2;
    vader_box_t l3;
    bool t0;
    l3 = l1;
    if (l3.tag == 0u) {
        return l0;
    }
    l2 = l3.payload.obj;
    t0 = vader_core_types$is_stored_as_integer(l0);
    if (!(t0)) {
        return l0;
    }
    return vader_ref_box(l2);
}

static vader_box_t vader_midir$const_accessor(void* l0, void* l1) {
    void* l2;
    int32_t l3;
    vader_box_t l4;
    bool t0;
    void* t1;
    vader_box_t t2;
    t0 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_fresh;
    if (t0) {
        l2 = ((vader_struct_vader_midir$ProjectCtx_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_project)->f_const_fresh_wrap;
        l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_symbol)->f_id;
        l4 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l3);
        if (!(l4.tag == 0u)) {
            t1 = l4.payload.obj;
            return vader_ref_box(t1);
        }
    }
    l2 = ((vader_struct_vader_midir$ProjectCtx_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_project)->f_const_fn_wrap;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_symbol)->f_id;
    t2 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l3);
    return t2;
}

static void* vader_midir$convert_data_pool(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    int64_t l3, l4, l9, l10, l15, l16;
    vader_box_t l5 = vader_box_null(), l17 = vader_box_null();
    uint64_t l11;
    void* t0 = NULL;
    int64_t t1, t2;
    vader_string_t t3 = 0;
    uint8_t t4;
    vader_box_t t5 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l5, &l17, &t5 };
    void** gc_raw_roots[11] = { &l0, &l1, &l2, &l6, &l7, &l8, &l12, &l13, &l14, &l18, &t0 };
    vader_string_t* gc_atom_roots[1] = { &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 11u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(247u, 0u, 13u, 1712u);
    l1 = (void*) _a0_arr;
    l2 = l0;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l5 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l4);
        if (l5.tag == 1309u) {
            t0 = l5.payload.obj;
            vader_struct_vader_core_bytecode$BcStrData_t* _a2_obj = (vader_struct_vader_core_bytecode$BcStrData_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcStrData_t));
            vader_obj_header_init(_a2_obj, 745u);
            _a2_obj->f_values = ((vader_struct_vader_lower_ir$StrDataPoolEntry_t*) t0)->f_values;
            l6 = (void*) _a2_obj;
            vader_array_push_ref((vader_array_t*) l1, l6);
        } else if (l5.tag == 1308u) {
            vader_array_t* _a3_arr = vader_array_new(28u, 0u, 4u, 343u);
            l7 = (void*) _a3_arr;
            t0 = l5.payload.obj;
            l8 = ((vader_struct_vader_lower_ir$PrimDataPoolEntry_t*) t0)->f_items;
            l9 = ((vader_array_t*) l8)->length;
            l10 = INT64_C(0);
            vader_array_t* _pc41_hdr = (vader_array_t*) l7;
            size_t _pc41_len = _pc41_hdr->length;
            size_t _pc41_cap = (_pc41_hdr->offset == 0 && !vader_array_is_borrowed(_pc41_hdr) && _pc41_hdr->length >= _pc41_hdr->buf->length) ? _pc41_hdr->capacity : (size_t) 0;
            void* _pc41_slots = _pc41_hdr->buf->slots;
            for (;;) {
                if ((l10 < l9)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l8);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    t1 = ((int64_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l10];
                    t2 = t1;
                    l11 = (uint64_t) (int64_t) t2;
                    if (VADER_LIKELY(_pc41_len < _pc41_cap)) {
                        ((int64_t*) _pc41_slots)[_pc41_len] = (int64_t) ((int64_t) (uint64_t) l11);
                        _pc41_len += 1;
                    } else {
                        _pc41_hdr->length = _pc41_len;
                        if (_pc41_hdr->buf->length < _pc41_len) {
                            _pc41_hdr->buf->length = _pc41_len;
                        }
                        vader_array_push_i64((vader_array_t*) l7, (int64_t) (uint64_t) l11);
                        _pc41_hdr = (vader_array_t*) l7;
                        _pc41_len = _pc41_hdr->length;
                        _pc41_cap = (_pc41_hdr->offset == 0 && !vader_array_is_borrowed(_pc41_hdr) && _pc41_hdr->length >= _pc41_hdr->buf->length) ? _pc41_hdr->capacity : (size_t) 0;
                        _pc41_slots = _pc41_hdr->buf->slots;
                    }
                    l10 = (l10 + INT64_C(1));
                    continue;
                }
                _pc41_hdr->length = _pc41_len;
                if (_pc41_hdr->buf->length < _pc41_len) {
                    _pc41_hdr->buf->length = _pc41_len;
                }
                break;
            }
            t0 = l5.payload.obj;
            t3 = ((vader_struct_vader_lower_ir$PrimDataPoolEntry_t*) t0)->f_element_type_name;
            t4 = vader_core_bytecode$array_kind_from_name(t3);
            vader_struct_vader_core_bytecode$BcPrimData_t* _a5_obj = (vader_struct_vader_core_bytecode$BcPrimData_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcPrimData_t));
            vader_obj_header_init(_a5_obj, 741u);
            _a5_obj->f_kind = t4;
            _a5_obj->f_items = l7;
            l12 = (void*) _a5_obj;
            vader_array_push_ref((vader_array_t*) l1, l12);
        } else {
            if (!(l5.tag == 1246u)) {
                vader_unreachable("non-exhaustive match (T3013 should have caught this)");
            }
            vader_array_t* _a6_arr = vader_array_new(249u, 0u, 13u, 1723u);
            l13 = (void*) _a6_arr;
            t0 = l5.payload.obj;
            l14 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) ((vader_struct_vader_lower_ir$AggregateDataPoolEntry_t*) t0)->f_literal)->f_elements;
            l15 = ((vader_array_t*) l14)->length;
            l16 = INT64_C(0);
            while ((l16 < l15)) {
                vader_array_t* _a7_slotarr = ((vader_array_t*) l14);
                VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                t5 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l16);
                l17 = vader_midir$lowered_to_bc_value(t5);
                vader_array_push_ref((vader_array_t*) l13, l17.payload.obj);
                l16 = (l16 + INT64_C(1));
            }
            t0 = l5.payload.obj;
            t3 = ((vader_struct_vader_lower_ir$AggregateDataPoolEntry_t*) t0)->f_element_type_name;
            vader_struct_vader_core_bytecode$BcAggregateData_t* _a8_obj = (vader_struct_vader_core_bytecode$BcAggregateData_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcAggregateData_t));
            vader_obj_header_init(_a8_obj, 732u);
            _a8_obj->f_element_type_name = t3;
            _a8_obj->f_elements = l13;
            l18 = (void*) _a8_obj;
            vader_array_push_ref((vader_array_t*) l1, l18);
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$convert_function(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l18 = NULL;
    void* l21 = NULL;
    int64_t l4, l9;
    int32_t l10, l15, l16, l20;
    vader_string_t l11 = 0;
    vader_string_t l17 = 0;
    vader_box_t l12 = vader_box_null(), l19 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[3] = { &l12, &l19, &t0 };
    void** gc_raw_roots[13] = {
        &l0, &l1, &l2, &l3, &l5, &l6, &l7, &l8, &l13, &l14, &l18, &l21, &t2,
    };
    vader_string_t* gc_atom_roots[2] = { &l11, &l17 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_body.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    t0 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_body;
    l2 = t0.payload.obj;
    vader_array_t* _a0_arr = vader_array_new(205u, 0u, 13u, 1319u);
    l3 = (void*) _a0_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l3, (int64_t) l4);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(203u, 0u, 13u, 1317u);
    l5 = (void*) _a2_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_params)->length;
    vader_array_t* _a3_arr = vader_array_repeat((vader_array_t*) l5, (int64_t) l4);
    l5 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 7u, 338u);
    l8 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a7_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a7_obj, 471u);
    _a7_obj->f_ekeys = l6;
    _a7_obj->f_evals = l7;
    _a7_obj->f_index = l8;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a7_obj;
    l7 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_params;
    l4 = ((vader_array_t*) l7)->length;
    l9 = INT64_C(0);
    while ((l9 < l4)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l7);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        l8 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l9);
        t1 = ((vader_array_t*) l5)->length;
        l10 = ((int32_t) (int64_t) t1);
        l11 = ((vader_struct_vader_lower_ir$LoweredParam_t*) l8)->f_name;
        l12 = ((vader_struct_vader_lower_ir$LoweredParam_t*) l8)->f_type;
        l13 = ((vader_struct_vader_lower_ir$LoweredParam_t*) l8)->f_symbol;
        vader_struct_vader_midir$CFGLocal_t* _a9_obj = (vader_struct_vader_midir$CFGLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGLocal_t));
        vader_obj_header_init(_a9_obj, 1317u);
        _a9_obj->f_name = l11;
        _a9_obj->f_type = l12;
        _a9_obj->f_symbol = vader_ref_box(l13);
        l14 = (void*) _a9_obj;
        vader_array_push_ref((vader_array_t*) l5, l14);
        l15 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredParam_t*) l8)->f_symbol)->f_id;
        l16 = l10;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l6, l15, l16);
        l17 = ((vader_struct_vader_lower_ir$LoweredParam_t*) l8)->f_name;
        l18 = ((vader_struct_vader_lower_ir$LoweredParam_t*) l8)->f_symbol;
        l19 = ((vader_struct_vader_lower_ir$LoweredParam_t*) l8)->f_type;
        l20 = l10;
        vader_struct_vader_midir$CFGParam_t* _a10_obj = (vader_struct_vader_midir$CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGParam_t));
        vader_obj_header_init(_a10_obj, 1319u);
        _a10_obj->f_name = l17;
        _a10_obj->f_symbol = l18;
        _a10_obj->f_type = l19;
        _a10_obj->f_local = l20;
        l21 = (void*) _a10_obj;
        vader_array_push_ref((vader_array_t*) l3, l21);
        l9 = (l9 + INT64_C(1));
    }
    l11 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_mangled;
    l7 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_origin;
    l12 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_return_type;
    vader_array_t* _a11_arr = vader_array_new(209u, 0u, 13u, 1373u);
    l8 = (void*) _a11_arr;
    vader_array_t* _a12_arr = vader_array_new(208u, 0u, 13u, 1372u);
    l13 = (void*) _a12_arr;
    vader_struct_vader_midir$FnCtx_t* _a13_obj = (vader_struct_vader_midir$FnCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$FnCtx_t));
    vader_obj_header_init(_a13_obj, 1334u);
    _a13_obj->f_project = l1;
    _a13_obj->f_mangled = l11;
    _a13_obj->f_origin = l7;
    _a13_obj->f_return_type = l12;
    _a13_obj->f_params = l3;
    _a13_obj->f_locals = l5;
    _a13_obj->f_local_by_sym_id = l6;
    _a13_obj->f_blocks = l8;
    _a13_obj->f_loop_stack = l13;
    _a13_obj->f_current = vader_box_obj(0u, NULL);
    l5 = (void*) _a13_obj;
    l6 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l2)->f_span;
    l10 = vader_midir$new_block(l5, l6);
    ((vader_struct_vader_midir$FnCtx_t*) l5)->f_current = vader_box_i32(338u, l10);
    VADER_WRITE_BARRIER((vader_struct_vader_midir$FnCtx_t*) l5);
    l12 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_return_type;
    l12 = vader_midir$build_block_value(l5, l2, l12);
    if (!(((vader_struct_vader_midir$FnCtx_t*) l5)->f_current.tag == 0u)) {
        l6 = ((vader_struct_vader_midir$FnCtx_t*) l5)->f_blocks;
        l4 = ((int64_t) ((vader_struct_vader_midir$FnCtx_t*) l5)->f_current.payload.i);
        vader_array_t* _a14_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l4)
        l6 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l4);
        if (((vader_struct_vader_midir$MutableBlock_t*) l6)->f_terminator.tag == 0u) {
            l2 = ((vader_struct_vader_lower_ir$LoweredBlock_t*) l2)->f_span;
            l19 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_return_type;
            l7 = vader_midir$implicit_return_values(l12, l19);
            vader_struct_vader_midir$TermReturn_t* _a15_obj = (vader_struct_vader_midir$TermReturn_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermReturn_t));
            vader_obj_header_init(_a15_obj, 1382u);
            _a15_obj->f_span = l2;
            _a15_obj->f_values = l7;
            l2 = (void*) _a15_obj;
            ((vader_struct_vader_midir$MutableBlock_t*) l6)->f_terminator = vader_ref_box(l2);
            VADER_WRITE_BARRIER((vader_struct_vader_midir$MutableBlock_t*) l6);
        }
    }
    vader_array_t* _a16_arr = vader_array_new(200u, 0u, 13u, 1314u);
    l2 = (void*) _a16_arr;
    l4 = ((vader_array_t*) ((vader_struct_vader_midir$FnCtx_t*) l5)->f_blocks)->length;
    vader_array_t* _a17_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l4);
    l2 = (void*) _a17_arr;
    l6 = ((vader_struct_vader_midir$FnCtx_t*) l5)->f_blocks;
    l4 = ((vader_array_t*) l6)->length;
    l9 = INT64_C(0);
    while ((l9 < l4)) {
        vader_array_t* _a18_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a18_slotarr)
        t2 = vader_array_ref_load_obj(_a18_slotarr->buf, _a18_slotarr->offset + (size_t) l9);
        l7 = vader_midir$freeze_block(t2);
        vader_array_push_ref((vader_array_t*) l2, l7);
        l9 = (l9 + INT64_C(1));
    }
    l11 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_mangled;
    l12 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_return_type;
    l5 = ((vader_struct_vader_midir$FnCtx_t*) l5)->f_locals;
    l6 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_origin;
    vader_array_t* _a19_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l7 = (void*) _a19_arr;
    vader_struct_vader_midir$CFGFunction_t* _a20_obj = (vader_struct_vader_midir$CFGFunction_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGFunction_t));
    vader_obj_header_init(_a20_obj, 1316u);
    _a20_obj->f_mangled = l11;
    _a20_obj->f_params = l3;
    _a20_obj->f_return_type = l12;
    _a20_obj->f_locals = l5;
    _a20_obj->f_blocks = l2;
    _a20_obj->f_entry = l10;
    _a20_obj->f_origin = l6;
    _a20_obj->f_scalarised_results = l7;
    t2 = (void*) _a20_obj;
    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir$count_uses(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l4, l5, l8, l9;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[7] = { &l0, &l1, &l2, &l3, &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 7u, 338u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a3_obj, 471u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l1 = (void*) _a3_obj;
    vader_struct___lambda_env_vader_midir_13_t* _a4_obj = (vader_struct___lambda_env_vader_midir_13_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_13_t));
    vader_obj_header_init(_a4_obj, 435u);
    _a4_obj->f_cap_0 = l1;
    t0 = (void*) _a4_obj;
    vader_fn_t* _a5_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a5_closure, 305u);
    _a5_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_12;
    _a5_closure->env = t0;
    l2 = (void*) _a5_closure;
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l5)
        l6 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l5);
        l7 = ((vader_struct_vader_midir$BasicBlock_t*) l6)->f_instructions;
        l8 = ((vader_array_t*) l7)->length;
        l9 = INT64_C(0);
        while ((l9 < l8)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l9)
            t1 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l9);
            vader_midir$for_each_read_local(t1, l2);
            l9 = (l9 + INT64_C(1));
        }
        vader_midir$for_each_read_in_terminator(((vader_struct_vader_midir$BasicBlock_t*) l6)->f_terminator, l2);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t vader_midir$count_where(int64_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = l1;
    l3 = INT64_C(0);
    l4 = INT64_C(0);
    while ((l4 < l0)) {
        vader_fn_t* _a0_fnobj = (vader_fn_t*) l2;
        t0 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i64(339u, l4));
        t1 = t0.payload.b;
        if (t1) {
            l3 = vader_chk_add(i64, l3, INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    { int64_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir$declare_local(void* l0, vader_string_t l1, vader_box_t l2, vader_box_t l3) {
    int32_t l4;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t t0;
    vader_box_t* gc_roots[2] = { &l2, &l3 };
    void** gc_raw_roots[3] = { &l0, &l5, &l6 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_locals)->length;
    l4 = ((int32_t) (int64_t) t0);
    l5 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_locals;
    vader_struct_vader_midir$CFGLocal_t* _a0_obj = (vader_struct_vader_midir$CFGLocal_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGLocal_t));
    vader_obj_header_init(_a0_obj, 1317u);
    _a0_obj->f_name = l1;
    _a0_obj->f_type = l2;
    _a0_obj->f_symbol = l3;
    l6 = (void*) _a0_obj;
    vader_array_push_ref((vader_array_t*) l5, l6);
    { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_midir$dominates(void* l0, int32_t l1, int32_t l2) {
    int32_t l3, l4, l5;
    bool t0;
    l3 = l2;
    for (;;) {
        t0 = vader_midir$BlockId$std_core$Equals$equals(l3, INT32_C(-1));
        if (!(t0)) {
            t0 = vader_midir$BlockId$std_core$Equals$equals(l3, l1);
            if (t0) {
                return true;
            }
            l4 = l3;
            vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
            l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
            t0 = vader_midir$BlockId$std_core$Equals$equals(l5, l3);
            if (t0) {
                t0 = vader_midir$BlockId$std_core$Equals$equals(l3, l1);
                return t0;
            }
            l3 = l5;
            continue;
        }
        break;
    }
    return false;
}

vader_box_t vader_midir$dst_of(vader_box_t l0) {
    void* t0;
    vader_box_t t1;
    if (l0.tag == 1351u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrConst_t*) t0)->f_dst);
    }
    if (l0.tag == 1363u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrMove_t*) t0)->f_dst);
    }
    if (l0.tag == 1344u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_dst);
    }
    if (l0.tag == 1367u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_dst);
    }
    if (l0.tag == 1355u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrFieldGet_t*) t0)->f_dst);
    }
    if (l0.tag == 1368u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrUnionFieldGet_t*) t0)->f_dst);
    }
    if (l0.tag == 1338u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_dst);
    }
    if (l0.tag == 1339u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_dst);
    }
    if (l0.tag == 1343u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_dst);
    }
    if (l0.tag == 1364u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_dst);
    }
    if (l0.tag == 1340u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_dst);
    }
    if (l0.tag == 1365u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_dst);
    }
    if (l0.tag == 1366u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrTypeConst_t*) t0)->f_dst);
    }
    if (l0.tag == 1347u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrCast_t*) t0)->f_dst);
    }
    if (l0.tag == 1349u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_dst);
    }
    if (l0.tag == 1348u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_dst);
    }
    if (l0.tag == 1362u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_dst);
    }
    if (l0.tag == 1358u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrFnRef_t*) t0)->f_dst);
    }
    if (l0.tag == 1357u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrFnAddr_t*) t0)->f_dst);
    }
    if (l0.tag == 1352u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrDataConst_t*) t0)->f_dst);
    }
    if (l0.tag == 1359u) {
        t0 = l0.payload.obj;
        return vader_box_i32(338u, ((vader_struct_vader_midir$InstrGlobalGet_t*) t0)->f_dst);
    }
    if (l0.tag == 1345u) {
        t0 = l0.payload.obj;
        t1 = vader_midir$call_single_dst(t0);
        return t1;
    }
    if (l0.tag == 1346u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_dst;
    }
    if (l0.tag == 1370u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_dst;
    }
    if (l0.tag == 1361u) {
        t0 = l0.payload.obj;
        return ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_dst;
    }
    if (l0.tag == 1356u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1369u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1342u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1341u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1350u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1360u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 1354u) {
        return vader_box_obj(0u, NULL);
    }
    if (!(l0.tag == 1353u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_midir$element_slot(vader_box_t l0) {
    void* l1;
    vader_box_t l2;
    l2 = vader_core_types$array_backing(l0);
    if (l2.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l1 = l2.payload.obj;
    return ((vader_struct_vader_core_types$ArrayType_t*) l1)->f_element;
}

static void vader_midir$emit(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    int64_t l3;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u)) {
        l2 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_blocks;
        l3 = ((int64_t) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.payload.i);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
        vader_array_push_ref((vader_array_t*) ((vader_struct_vader_midir$MutableBlock_t*) t0)->f_instructions, l1.payload.obj);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static int32_t vader_midir$emit_const(void* l0, vader_box_t l1, vader_box_t l2, void* l3) {
    int32_t l4;
    void* l5 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &l5 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_midir$fresh_tmp(l0, 2230u, l1);
    vader_struct_vader_midir$InstrConst_t* _a0_obj = (vader_struct_vader_midir$InstrConst_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrConst_t));
    vader_obj_header_init(_a0_obj, 1351u);
    _a0_obj->f_span = l3;
    _a0_obj->f_dst = l4;
    _a0_obj->f_value = l2;
    _a0_obj->f_type = l1;
    l5 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l5));
    { int32_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$end_after_no_return(void* l0, void* l1, vader_box_t l2) {
    void* l3 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l1, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_type.tag == 913u)) {
        { vader_box_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_midir$TermUnreachable_t* _a0_obj = (vader_struct_vader_midir$TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermUnreachable_t));
    vader_obj_header_init(_a0_obj, 1383u);
    _a0_obj->f_span = ((vader_struct_vader_lower_ir$LoweredCall_t*) l1)->f_span;
    _a0_obj->f_reason = 1472u;
    l3 = (void*) _a0_obj;
    vader_midir$terminate(l0, vader_ref_box(l3));
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static bool vader_midir$extern_shrinks_by_itself(void* l0) {
    vader_box_t l1 = vader_box_null();
    bool t0;
    vader_string_t t1 = 0;
    uint8_t t2;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_is_extern;
    if (t0) {
        { vader_gc_top = gc_frame.prev; return false; }
    }
    t1 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_mangled;
    l1 = vader_midir_select$intrinsic_op_for_mangled(t1);
    if (!(l1.tag == 0u)) {
        t0 = vader_core_bytecode$op_shortens_array(l1);
        { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = ((vader_struct_vader_midir$CFGExternDecl_t*) l0)->f_mangled;
    t2 = vader_core_bytecode$intrinsic_id_for(t1);
    t0 = vader_core_bytecode$intrinsic_may_shorten_array(t2);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$field_read_type(void* l0, int32_t l1, vader_box_t l2) {
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    bool t0;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &t1 };
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_core_types$is_stored_as_integer(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredFieldAccess_t, f_type, l2.payload.obj));
    if (!(t0)) {
        { vader_box_t __vret = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredFieldAccess_t, f_type, l2.payload.obj); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = vader_midir$place_slot(l0, vader_box_i32(338u, l1), l2);
    l4 = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredFieldAccess_t, f_type, l2.payload.obj);
    t1 = vader_midir$read_type(l3, l4);
    { vader_box_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$field_slot(void* l0, vader_box_t l1, vader_string_t l2) {
    void* l3 = NULL;
    void* l8 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[3] = { &l1, &l6, &l7 };
    void** gc_raw_roots[4] = { &l0, &l3, &l8, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 926u) {
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        for (;;) {
            if ((l5 < l4)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                l6 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
                l7 = vader_midir$field_slot(l0, l6, l2);
                if (l7.tag == 0u) {
                    l5 = (l5 + INT64_C(1));
                    continue;
                }
                { vader_box_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
            }
            break;
        }
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l6 = l1;
    l6 = vader_midir$laid_out_fields(l0, l6);
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = l6.payload.obj;
    l4 = ((vader_array_t*) l3)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
        t1 = ((vader_struct_vader_midir$CFGStructField_t*) l8)->f_name;
        if (t1 == l2) {
            { vader_box_t __vret = ((vader_struct_vader_midir$CFGStructField_t*) l8)->f_type; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l5 = (l5 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
}

static void* vader_midir$fn_metadata(void* l0) {
    vader_string_t l1 = 0;
    bool l2, l5;
    int32_t l3;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_mangled;
    l2 = false;
    l3 = INT32_C(-1);
    l4 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_origin)->f_decl;
    if (l4.tag == 658u) {
        t0 = l4.payload.obj;
        l1 = toolchain_ast$extern_symbol_of(t0);
        if (((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_body.tag == 0u) {
            t0 = l4.payload.obj;
            l5 = toolchain_ast$decorators_have(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators, 1945u);
        } else {
            l5 = false;
        }
        l2 = l5;
        t0 = l4.payload.obj;
        l3 = vader_midir$c_variadic_fixed_of(((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_decorators);
        vader_struct_vader_midir$FnMetadata_t* _a0_obj = (vader_struct_vader_midir$FnMetadata_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$FnMetadata_t));
        vader_obj_header_init(_a0_obj, 1335u);
        _a0_obj->f_extern_name = l1;
        _a0_obj->f_is_extern = l2;
        _a0_obj->f_c_variadic_fixed = l3;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_struct_vader_midir$FnMetadata_t* _a1_obj = (vader_struct_vader_midir$FnMetadata_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$FnMetadata_t));
    vader_obj_header_init(_a1_obj, 1335u);
    _a1_obj->f_extern_name = l1;
    _a1_obj->f_is_extern = l2;
    _a1_obj->f_c_variadic_fixed = l3;
    t0 = (void*) _a1_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir$fn_span(void* l0) {
    int64_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[2] = { &l0, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    if (!(t0 == INT64_C(0))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        { void* __vret = ((vader_struct_vader_midir$BasicBlock_t*) t1)->f_span; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = toolchain_span$empty_span();
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir$fn_value_kind(vader_box_t l0) {
    vader_string_t l1;
    if (l0.tag == 1358u) {
        l1 = 2007u;
        return l1;
    }
    if (l0.tag == 1357u) {
        l1 = 2006u;
    } else {
        if (!(l0.tag == 1362u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 1757u;
    }
    return l1;
}

void vader_midir$for_each_read_in_terminator(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1381u) {
        t0 = l0.payload.obj;
        vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
        ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_cond));
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l0.tag == 1382u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_midir$TermReturn_t*) t0)->f_values;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
            t1 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4];
            vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
            ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(338u, t1));
            l4 = (l4 + INT64_C(1));
        }
    } else if (!(l0.tag == 1380u)) {
        if (!(l0.tag == 1383u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void vader_midir$for_each_read_local(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1351u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (!(l0.tag == 1358u)) {
        if (!(l0.tag == 1357u)) {
            if (l0.tag == 1363u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrMove_t*) t0)->f_src));
            } else if (l0.tag == 1344u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a1_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a1_fnobj->code)(_a1_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_lhs));
                t0 = l0.payload.obj;
                vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a2_fnobj->code)(_a2_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrBinOp_t*) t0)->f_rhs));
            } else if (l0.tag == 1367u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a3_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a3_fnobj->code)(_a3_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_operand));
            } else if (l0.tag == 1345u) {
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_args;
                l3 = ((vader_array_t*) l2)->length;
                l4 = INT64_C(0);
                while ((l4 < l3)) {
                    vader_array_t* _a4_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l4)
                    t1 = ((int32_t*) _a4_slotarr->buf->slots)[_a4_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a5_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a5_fnobj->code)(_a5_fnobj->env, vader_box_i32(338u, t1));
                    l4 = (l4 + INT64_C(1));
                }
            } else if (l0.tag == 1346u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a6_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a6_fnobj->code)(_a6_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_callee));
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir$InstrCallIndirect_t*) t0)->f_args;
                l3 = ((vader_array_t*) l2)->length;
                l4 = INT64_C(0);
                while ((l4 < l3)) {
                    vader_array_t* _a7_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l4)
                    t1 = ((int32_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a8_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a8_fnobj->code)(_a8_fnobj->env, vader_box_i32(338u, t1));
                    l4 = (l4 + INT64_C(1));
                }
            } else if (l0.tag == 1370u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a9_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a9_fnobj->code)(_a9_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_receiver));
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir$InstrVirtualCall_t*) t0)->f_args;
                l3 = ((vader_array_t*) l2)->length;
                l4 = INT64_C(0);
                while ((l4 < l3)) {
                    vader_array_t* _a10_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a10_slotarr, l4)
                    t1 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a11_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a11_fnobj->code)(_a11_fnobj->env, vader_box_i32(338u, t1));
                    l4 = (l4 + INT64_C(1));
                }
            } else if ((l0.tag == 1355u || l0.tag == 1368u)) {
                vader_fn_t* _a12_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a12_fnobj->code)(_a12_fnobj->env, vader_box_i32(338u, VADER_UNION_FIELD(int32_t, vader_struct_vader_midir$InstrFieldGet_t, f_target, l0.payload.obj)));
            } else if ((l0.tag == 1356u || l0.tag == 1369u)) {
                vader_fn_t* _a13_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a13_fnobj->code)(_a13_fnobj->env, vader_box_i32(338u, VADER_UNION_FIELD(int32_t, vader_struct_vader_midir$InstrFieldSet_t, f_target, l0.payload.obj)));
                vader_fn_t* _a14_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a14_fnobj->code)(_a14_fnobj->env, vader_box_i32(338u, VADER_UNION_FIELD(int32_t, vader_struct_vader_midir$InstrFieldSet_t, f_value, l0.payload.obj)));
            } else if (l0.tag == 1338u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a15_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a15_fnobj->code)(_a15_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a16_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a16_fnobj->code)(_a16_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_index));
            } else if (l0.tag == 1342u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a17_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a17_fnobj->code)(_a17_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a18_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a18_fnobj->code)(_a18_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_index));
                t0 = l0.payload.obj;
                vader_fn_t* _a19_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a19_fnobj->code)(_a19_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_value));
            } else if (l0.tag == 1339u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a20_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a20_fnobj->code)(_a20_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrArrayLen_t*) t0)->f_target));
            } else if (l0.tag == 1341u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a21_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a21_fnobj->code)(_a21_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a22_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a22_fnobj->code)(_a22_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrArrayPush_t*) t0)->f_value));
            } else if (l0.tag == 1343u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a23_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a23_fnobj->code)(_a23_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_target));
                t0 = l0.payload.obj;
                vader_fn_t* _a24_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a24_fnobj->code)(_a24_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_lo));
                t0 = l0.payload.obj;
                vader_fn_t* _a25_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a25_fnobj->code)(_a25_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrArraySlice_t*) t0)->f_hi));
            } else if (l0.tag == 1364u) {
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir$InstrStructNew_t*) t0)->f_fields;
                l3 = ((vader_array_t*) l2)->length;
                l4 = INT64_C(0);
                while ((l4 < l3)) {
                    vader_array_t* _a26_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a26_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a26_slotarr, l4)
                    t1 = ((int32_t*) _a26_slotarr->buf->slots)[_a26_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a27_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a27_fnobj->code)(_a27_fnobj->env, vader_box_i32(338u, t1));
                    l4 = (l4 + INT64_C(1));
                }
            } else if (l0.tag == 1340u) {
                t0 = l0.payload.obj;
                l2 = ((vader_struct_vader_midir$InstrArrayNew_t*) t0)->f_elements;
                l3 = ((vader_array_t*) l2)->length;
                l4 = INT64_C(0);
                while ((l4 < l3)) {
                    vader_array_t* _a28_slotarr = ((vader_array_t*) l2);
                    VADER_ARRAY_RESOLVE_BUF(_a28_slotarr)
                    VADER_ARRAY_CHECK_INDEX(_a28_slotarr, l4)
                    t1 = ((int32_t*) _a28_slotarr->buf->slots)[_a28_slotarr->offset + (size_t) l4];
                    vader_fn_t* _a29_fnobj = (vader_fn_t*) l1;
                    ((vader_fn_erased_sig_1_t) _a29_fnobj->code)(_a29_fnobj->env, vader_box_i32(338u, t1));
                    l4 = (l4 + INT64_C(1));
                }
            } else if (l0.tag == 1365u) {
                t0 = l0.payload.obj;
                vader_fn_t* _a30_fnobj = (vader_fn_t*) l1;
                ((vader_fn_erased_sig_1_t) _a30_fnobj->code)(_a30_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrTypeCheck_t*) t0)->f_value));
            } else if (!(l0.tag == 1366u)) {
                if (!(l0.tag == 1352u)) {
                    if (!(l0.tag == 1359u)) {
                        if (l0.tag == 1360u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a31_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a31_fnobj->code)(_a31_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrGlobalSet_t*) t0)->f_value));
                        } else if (l0.tag == 1347u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a32_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a32_fnobj->code)(_a32_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrCast_t*) t0)->f_value));
                        } else if (l0.tag == 1349u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a33_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a33_fnobj->code)(_a33_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrCellNew_t*) t0)->f_value));
                        } else if (l0.tag == 1348u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a34_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a34_fnobj->code)(_a34_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrCellGet_t*) t0)->f_cell));
                        } else if (l0.tag == 1350u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a35_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a35_fnobj->code)(_a35_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_cell));
                            t0 = l0.payload.obj;
                            vader_fn_t* _a36_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a36_fnobj->code)(_a36_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrCellSet_t*) t0)->f_value));
                        } else if (l0.tag == 1362u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a37_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a37_fnobj->code)(_a37_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrMakeClosure_t*) t0)->f_env));
                        } else if (l0.tag == 1361u) {
                            t0 = l0.payload.obj;
                            l2 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_args;
                            l3 = ((vader_array_t*) l2)->length;
                            l4 = INT64_C(0);
                            while ((l4 < l3)) {
                                vader_array_t* _a38_slotarr = ((vader_array_t*) l2);
                                VADER_ARRAY_RESOLVE_BUF(_a38_slotarr)
                                VADER_ARRAY_CHECK_INDEX(_a38_slotarr, l4)
                                t1 = ((int32_t*) _a38_slotarr->buf->slots)[_a38_slotarr->offset + (size_t) l4];
                                vader_fn_t* _a39_fnobj = (vader_fn_t*) l1;
                                ((vader_fn_erased_sig_1_t) _a39_fnobj->code)(_a39_fnobj->env, vader_box_i32(338u, t1));
                                l4 = (l4 + INT64_C(1));
                            }
                        } else if (l0.tag == 1354u) {
                            t0 = l0.payload.obj;
                            vader_fn_t* _a40_fnobj = (vader_fn_t*) l1;
                            ((vader_fn_erased_sig_1_t) _a40_fnobj->code)(_a40_fnobj->env, vader_box_i32(338u, ((vader_struct_vader_midir$InstrDeferPush_t*) t0)->f_value));
                        } else if (!(l0.tag == 1353u)) {
                            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
                        }
                    }
                }
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_midir$freeze_block(void* l0) {
    int32_t l1;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_midir$MutableBlock_t*) l0)->f_terminator.tag == 0u)) {
        l1 = ((vader_struct_vader_midir$MutableBlock_t*) l0)->f_id;
        l2 = ((vader_struct_vader_midir$MutableBlock_t*) l0)->f_instructions;
        l5 = ((vader_struct_vader_midir$MutableBlock_t*) l0)->f_terminator;
        l3 = ((vader_struct_vader_midir$MutableBlock_t*) l0)->f_span;
        vader_struct_vader_midir$BasicBlock_t* _a0_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
        vader_obj_header_init(_a0_obj, 1314u);
        _a0_obj->f_id = l1;
        _a0_obj->f_instructions = l2;
        _a0_obj->f_terminator = l5;
        _a0_obj->f_span = l3;
        t0 = (void*) _a0_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = ((vader_struct_vader_midir$MutableBlock_t*) l0)->f_id;
    l2 = ((vader_struct_vader_midir$MutableBlock_t*) l0)->f_instructions;
    vader_struct_vader_midir$TermUnreachable_t* _a1_obj = (vader_struct_vader_midir$TermUnreachable_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$TermUnreachable_t));
    vader_obj_header_init(_a1_obj, 1383u);
    _a1_obj->f_span = ((vader_struct_vader_midir$MutableBlock_t*) l0)->f_span;
    _a1_obj->f_reason = 2347u;
    l3 = (void*) _a1_obj;
    l4 = ((vader_struct_vader_midir$MutableBlock_t*) l0)->f_span;
    vader_struct_vader_midir$BasicBlock_t* _a2_obj = (vader_struct_vader_midir$BasicBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$BasicBlock_t));
    vader_obj_header_init(_a2_obj, 1314u);
    _a2_obj->f_id = l1;
    _a2_obj->f_instructions = l2;
    _a2_obj->f_terminator = vader_ref_box(l3);
    _a2_obj->f_span = l4;
    t0 = (void*) _a2_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir$fresh_tmp(void* l0, vader_string_t l1, vader_box_t l2) {
    vader_string_t l3 = 0;
    int64_t l4, l6;
    void* l5 = NULL;
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[2] = { &l0, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = l1;
    l4 = vader_host_std_core$byte_len(l3);
    l5 = (void*) vader_buffer_new((size_t) (INT64_C(22) + l4));
    l4 = INT64_C(0);
    l4 = std_core$write_string_at(l5, l4, 259u);
    l4 = std_core$write_string_at(l5, l4, l3);
    l4 = std_core$write_string_at(l5, l4, 976u);
    l6 = ((vader_array_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_locals)->length;
    l4 = std_core$write_int(l5, l4, l6);
    l3 = std_core$finish_buffer(l5, l4);
    t0 = vader_midir$declare_local(l0, l3, l2, vader_box_obj(0u, NULL));
    { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$function_called(void* l0, void* l1) {
    void* l2;
    vader_string_t l3;
    vader_box_t l4;
    int32_t l5;
    vader_box_t t0;
    int32_t t1;
    l2 = ((vader_struct_vader_midir$CalleeLookup_t*) l0)->f_fn_by_mangle;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_name;
    l4 = std_collections$MutableMap$std_core$Index$at__string__i32(l2, l3);
    if (l4.tag == 0u) {
        l2 = ((vader_struct_vader_midir$CalleeLookup_t*) l0)->f_fn_by_symbol;
        l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
        t0 = std_collections$MutableMap$std_core$Index$at__i32__i32(l2, l5);
        return t0;
    }
    t1 = ((int32_t) l4.payload.i);
    return vader_box_i32(338u, t1);
}

void* vader_midir$functions_run_from(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l11 = NULL;
    int64_t l6, l7;
    vader_box_t l8 = vader_box_null();
    vader_string_t l9 = 0;
    int32_t l10;
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l8, &t1 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l3, &l4, &l5, &l11, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l9 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_midir$build_call_graph(l0);
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 7u, 338u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a3_obj, 548u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_midir$CallGraph_t*) l2)->f_nodes)->length;
    while ((l6 < l7)) {
        vader_array_t* _a4_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$CallGraph_t*) l2)->f_nodes);
        VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a4_slotarr, l6)
        l8 = vader_array_ref_load_box(_a4_slotarr->buf, _a4_slotarr->offset + (size_t) l6);
        if (l8.tag == 1316u) {
            t0 = l8.payload.obj;
            l9 = ((vader_struct_vader_midir$CFGFunction_t*) t0)->f_mangled;
            l10 = ((int32_t) (int64_t) l6);
            std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l3, l9, l10);
        }
        l6 = (l6 + INT64_C(1));
    }
    vader_array_t* _a5_arr = vader_array_new(39u, 0u, 13u, 615u);
    l4 = (void*) _a5_arr;
    l6 = ((vader_array_t*) l1)->length;
    vader_array_t* _a6_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l6);
    l4 = (void*) _a6_arr;
    l5 = l1;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t1 = vader_array_box_slots(_a7_slotarr->buf)[_a7_slotarr->offset + (size_t) l7];
        l9 = t1.payload.s;
        l8 = std_collections$MutableMap$std_core$Index$at__string__i32(l3, l9);
        l11 = vader_midir$mangles_reached(l2, l8);
        vader_array_push_ref((vader_array_t*) l4, l11);
        l7 = (l7 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir$header_of(void* l0, vader_box_t l1) {
    vader_box_t l2;
    void* t0;
    vader_string_t t1;
    l2 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_origin)->f_decl;
    if (!(l2.tag == 658u)) {
        return 0u;
    }
    t0 = l2.payload.obj;
    t1 = toolchain_ast$extern_header(t0, l1);
    return t1;
}

static int32_t vader_midir$held_in(void* l0, int32_t l1, vader_box_t l2, void* l3) {
    void* l4 = NULL;
    int64_t l5;
    vader_box_t l6 = vader_box_null();
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[2] = { &l2, &l6 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_locals;
    l5 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    l6 = vader_midir$stored_conversion(((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type, l2);
    if (l6.tag == 0u) {
        { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l6.payload.obj;
    l4 = vader_core_types$machine_integer_type(t0);
    t1 = vader_midir$cast_local(l0, l1, vader_ref_box(l4), 1739u, l3);
    { int32_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir$held_use_in(void* l0, int32_t l1, vader_box_t l2, vader_box_t l3, void* l4) {
    void* l5 = NULL;
    void* l7 = NULL;
    vader_box_t l6 = vader_box_null();
    int64_t l8;
    vader_string_t l9 = 0;
    vader_string_t l10 = 0;
    int32_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[3] = { &l2, &l3, &l6 };
    void** gc_raw_roots[5] = { &l0, &l4, &l5, &l7, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l9, &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l6 = vader_midir$stored_conversion(l2, l3);
    if (l6.tag == 0u) {
        t0 = vader_midir$read_as(l0, l1, l2, l4);
        { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l5 = l6.payload.obj;
    l7 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_locals;
    l8 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l7);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l8)
    t1 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
    l6 = vader_core_types$held_integer(((vader_struct_vader_midir$CFGLocal_t*) t1)->f_type);
    if (!(l6.tag == 0u)) {
        t1 = l6.payload.obj;
        l9 = ((vader_struct_vader_support_integer$MachineInteger_t*) t1)->f_name;
        l10 = ((vader_struct_vader_support_integer$MachineInteger_t*) l5)->f_name;
        if (l9 == l10) {
            { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l5 = vader_core_types$machine_integer_type(l5);
    t0 = vader_midir$cast_local(l0, l1, vader_ref_box(l5), 1739u, l4);
    { int32_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir$holds_integer(void* l0, int32_t l1) {
    vader_box_t t0, t1;
    t0 = vader_midir$local_type(l0, l1);
    t1 = vader_core_types$held_integer(t0);
    return !(t1.tag == 0u);
}

static void* vader_midir$implicit_return_values(vader_box_t l0, vader_box_t l1) {
    bool l2;
    int32_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 0u) {
        l2 = true;
    } else {
        l2 = vader_core_types$is_void(l1);
    }
    if (!(l2)) {
        t0 = ((int32_t) l0.payload.i);
        vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 338u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) t0;
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a1_arr = vader_array_new(23u, 0u, 7u, 338u);
    t1 = (void*) _a1_arr;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$import_called(void* l0, void* l1) {
    void* l2;
    int32_t l3;
    vader_box_t l4;
    vader_string_t l5;
    vader_box_t t0;
    int32_t t1;
    l2 = ((vader_struct_vader_midir$CalleeLookup_t*) l0)->f_import_by_symbol;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_id;
    l4 = std_collections$MutableMap$std_core$Index$at__i32__i32(l2, l3);
    if (l4.tag == 0u) {
        l2 = ((vader_struct_vader_midir$CalleeLookup_t*) l0)->f_import_by_mangle;
        l5 = ((vader_struct_vader_core_symbol$Symbol_t*) l1)->f_name;
        t0 = std_collections$MutableMap$std_core$Index$at__string__i32(l2, l5);
        return t0;
    }
    t1 = ((int32_t) l4.payload.i);
    return vader_box_i32(338u, t1);
}

static void vader_midir$index_by_name(void* l0, void* l1, vader_string_t l2, vader_box_t l3, int32_t l4) {
    void* l5 = NULL;
    vader_box_t l6 = vader_box_null();
    int32_t l7;
    vader_box_t* gc_roots[2] = { &l3, &l6 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    std_collections$MutableMap$std_core$IndexSet$set_at__string__i32(l0, l2, l4);
    l6 = l3;
    if (l6.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = l6.payload.obj;
    l7 = ((vader_struct_vader_core_symbol$Symbol_t*) l5)->f_id;
    std_collections$MutableMap$std_core$IndexSet$set_at__i32__i32(l1, l7, l4);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$index_function(void* l0, vader_string_t l1, vader_box_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir$CalleeLookup_t*) l0)->f_fn_by_mangle;
    l5 = ((vader_struct_vader_midir$CalleeLookup_t*) l0)->f_fn_by_symbol;
    vader_midir$index_by_name(l4, l5, l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$index_import(void* l0, vader_string_t l1, vader_box_t l2, int32_t l3) {
    void* l4 = NULL;
    void* l5 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l4, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir$CalleeLookup_t*) l0)->f_import_by_mangle;
    l5 = ((vader_struct_vader_midir$CalleeLookup_t*) l0)->f_import_by_symbol;
    vader_midir$index_by_name(l4, l5, l1, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

void* vader_midir$instruction_callees(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    int32_t t1;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1345u) {
        t0 = l1.payload.obj;
        l2 = ((vader_struct_vader_midir$InstrCall_t*) t0)->f_callee;
        t1 = vader_midir$callee_node(l0, l2);
        vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 338u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) t1;
        l2 = (void*) _a0_arr;
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1370u) {
        l3 = l1.payload.obj;
        l2 = vader_midir$virtual_callees(l0, l3);
    } else if ((l1.tag == 1346u || l1.tag == 1353u)) {
        t1 = ((vader_struct_vader_midir$CalleeIndex_t*) l0)->f_indirect;
        vader_array_t* _a1_arr = vader_array_new(23u, 1u, 7u, 338u);
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) t1;
        l2 = (void*) _a1_arr;
    } else if ((l1.tag == 1344u || l1.tag == 1351u || l1.tag == 1355u || l1.tag == 1357u || l1.tag == 1358u || l1.tag == 1367u)) {
        vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
        l2 = (void*) _a2_arr;
    } else if ((l1.tag == 1338u || l1.tag == 1339u || l1.tag == 1341u || l1.tag == 1342u || l1.tag == 1356u)) {
        vader_array_t* _a3_arr = vader_array_new(23u, 0u, 7u, 338u);
        l2 = (void*) _a3_arr;
    } else if ((l1.tag == 1368u || l1.tag == 1369u)) {
        vader_array_t* _a4_arr = vader_array_new(23u, 0u, 7u, 338u);
        l2 = (void*) _a4_arr;
    } else if ((l1.tag == 1340u || l1.tag == 1343u || l1.tag == 1352u || l1.tag == 1364u)) {
        vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 338u);
        l2 = (void*) _a5_arr;
    } else if ((l1.tag == 1347u || l1.tag == 1348u || l1.tag == 1349u || l1.tag == 1365u || l1.tag == 1366u)) {
        vader_array_t* _a6_arr = vader_array_new(23u, 0u, 7u, 338u);
        l2 = (void*) _a6_arr;
    } else if ((l1.tag == 1350u || l1.tag == 1354u || l1.tag == 1361u || l1.tag == 1362u || l1.tag == 1363u)) {
        vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 338u);
        l2 = (void*) _a7_arr;
    } else {
        if (!((l1.tag == 1359u || l1.tag == 1360u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        vader_array_t* _a8_arr = vader_array_new(23u, 0u, 7u, 338u);
        l2 = (void*) _a8_arr;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_midir$instruction_has_side_effect(vader_box_t l0) {
    bool t0;
    t0 = vader_midir$instruction_runs_code(l0);
    if (t0) {
        return true;
    }
    return (l0.tag == 1341u || l0.tag == 1342u || l0.tag == 1350u || l0.tag == 1356u || l0.tag == 1360u || l0.tag == 1369u);
}

bool vader_midir$instruction_may_trap(vader_box_t l0) {
    bool l1;
    void* t0 = NULL;
    bool t1;
    uint8_t t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1338u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_midir$InstrArrayGet_t*) t0)->f_bounds_safe;
        l1 = !(t1);
        { bool __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1342u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_midir$InstrArraySet_t*) t0)->f_bounds_safe;
        l1 = !(t1);
    } else if (l0.tag == 1344u) {
        t0 = l0.payload.obj;
        l1 = vader_midir$binary_may_trap(t0);
    } else if (l0.tag == 1367u) {
        t0 = l0.payload.obj;
        if (((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_op == INT32_C(0)) {
            t0 = l0.payload.obj;
            t2 = vader_midir_select$val_type_of_type(((vader_struct_vader_midir$InstrUnOp_t*) t0)->f_type);
            l1 = vader_core_bytecode$is_integer_val(t2);
        } else {
            l1 = false;
        }
    } else if ((l0.tag == 1345u || l0.tag == 1346u || l0.tag == 1353u || l0.tag == 1361u || l0.tag == 1370u)) {
        l1 = true;
    } else if (l0.tag == 1343u) {
        l1 = false;
    } else if ((l0.tag == 1351u || l0.tag == 1355u || l0.tag == 1356u || l0.tag == 1357u || l0.tag == 1358u)) {
        l1 = false;
    } else if ((l0.tag == 1339u || l0.tag == 1341u || l0.tag == 1368u || l0.tag == 1369u)) {
        l1 = false;
    } else if ((l0.tag == 1340u || l0.tag == 1352u || l0.tag == 1364u || l0.tag == 1365u || l0.tag == 1366u)) {
        l1 = false;
    } else if ((l0.tag == 1347u || l0.tag == 1348u || l0.tag == 1349u || l0.tag == 1350u || l0.tag == 1362u)) {
        l1 = false;
    } else {
        if (!((l0.tag == 1354u || l0.tag == 1359u || l0.tag == 1360u || l0.tag == 1363u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    { bool __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_midir$instruction_runs_code(vader_box_t l0) {
    bool l1;
    if ((l0.tag == 1345u || l0.tag == 1346u || l0.tag == 1353u || l0.tag == 1361u || l0.tag == 1370u)) {
        l1 = true;
        return l1;
    }
    if ((l0.tag == 1344u || l0.tag == 1351u || l0.tag == 1355u || l0.tag == 1357u || l0.tag == 1358u || l0.tag == 1367u)) {
        l1 = false;
    } else if ((l0.tag == 1338u || l0.tag == 1339u || l0.tag == 1341u || l0.tag == 1342u || l0.tag == 1356u)) {
        l1 = false;
    } else if ((l0.tag == 1368u || l0.tag == 1369u)) {
        l1 = false;
    } else if ((l0.tag == 1340u || l0.tag == 1343u || l0.tag == 1352u || l0.tag == 1364u)) {
        l1 = false;
    } else if ((l0.tag == 1347u || l0.tag == 1348u || l0.tag == 1349u || l0.tag == 1365u || l0.tag == 1366u)) {
        l1 = false;
    } else if ((l0.tag == 1350u || l0.tag == 1354u || l0.tag == 1362u || l0.tag == 1363u)) {
        l1 = false;
    } else {
        if (!((l0.tag == 1359u || l0.tag == 1360u))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = false;
    }
    return l1;
}

static vader_box_t vader_midir$integer_member(vader_box_t l0, void* l1) {
    vader_box_t l2, l3, l8;
    void* l4;
    void* l7;
    void* l11;
    void* l12;
    int64_t l5, l6;
    vader_string_t l9, l10;
    void* t0;
    vader_box_t t1;
    bool t2;
    l2 = vader_core_types$held_integer(l0);
    if (l2.tag == 0u) {
        if (l0.tag == 926u) {
            l3 = vader_box_obj(0u, NULL);
            t0 = l0.payload.obj;
            l4 = ((vader_struct_vader_core_types$UnionType_t*) t0)->f_variants;
            l5 = ((vader_array_t*) l4)->length;
            l6 = INT64_C(0);
            while ((l6 < l5)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
                VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
                t1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
                l8 = vader_core_types$held_integer(t1);
                if (l8.tag == 0u) {
                    l6 = (l6 + INT64_C(1));
                    continue;
                }
                l7 = l8.payload.obj;
                l9 = ((vader_struct_vader_support_integer$MachineInteger_t*) l7)->f_name;
                l10 = ((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_name;
                if (l9 == l10) {
                    return vader_ref_box(l7);
                }
                l11 = ((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_values;
                l12 = ((vader_struct_vader_support_integer$MachineInteger_t*) l7)->f_values;
                t2 = vader_support_integer$interval_within(l11, l12);
                if (t2) {
                    t2 = vader_midir$narrower(l7, l3);
                    if (t2) {
                        l3 = vader_ref_box(l7);
                    }
                }
                l6 = (l6 + INT64_C(1));
            }
            return l3;
        }
        return l2;
    }
    return l2;
}

static int32_t vader_midir$intern_string_pool(void* l0, vader_string_t l1) {
    int32_t l2, l3;
    int64_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir$ProjectCtx_t*) l0)->f_strings)->length;
    l2 = ((int32_t) (int64_t) t0);
    l3 = std_collections$get_or_put__string__i32(((vader_struct_vader_midir$ProjectCtx_t*) l0)->f_string_index, l1, l2);
    if (l3 == l2) {
        vader_array_push_scalar((vader_array_t*) ((vader_struct_vader_midir$ProjectCtx_t*) l0)->f_strings, vader_box_string(335u, l1));
        { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir$intersect_dom_tree(int32_t l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    int32_t l6, l7, l8, l9;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[5] = { &l2, &l3, &l4, &l5, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 333u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 470u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 613u);
    _a4_obj->f_inner = t0;
    l3 = (void*) _a4_obj;
    l6 = l0;
    for (;;) {
        t1 = vader_midir$BlockId$std_core$Equals$equals(l6, INT32_C(-1));
        if (!(t1)) {
            l7 = l6;
            t1 = std_collections$add__i32(l3, l7);
            if (!(t1)) {
                break;
            }
            l8 = l6;
            vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l8)
            l9 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l8];
            t1 = vader_midir$BlockId$std_core$Equals$equals(l9, l6);
            if (t1) break;
            l6 = l9;
            continue;
        }
        break;
    }
    l6 = l1;
    for (;;) {
        t1 = vader_midir$BlockId$std_core$Equals$equals(l6, INT32_C(-1));
        if (!(t1)) {
            l7 = l6;
            t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l3, l7);
            if (t1) {
                { int32_t __vret = l6; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l8 = l6;
            vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l8)
            l9 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l8];
            t1 = vader_midir$BlockId$std_core$Equals$equals(l9, l6);
            if (t1) break;
            l6 = l9;
            continue;
        }
        break;
    }
    { vader_gc_top = gc_frame.prev; return INT32_C(-1); }
}

static bool vader_midir$intrinsic_shortens_array(vader_string_t l0) {
    vader_box_t l1 = vader_box_null();
    bool t0;
    vader_box_t* gc_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 0u, gc_roots, NULL, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_midir_select$intrinsic_op_for_name(l0);
    if (l1.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return true; }
    }
    t0 = vader_core_bytecode$op_shortens_array(l1);
    { bool __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir$is_dest_passing_shape(vader_box_t l0) {
    void* t0;
    bool t1;
    if ((l0.tag == 1259u || l0.tag == 1280u)) {
        return true;
    }
    if (!(l0.tag == 1258u)) {
        return false;
    }
    t0 = l0.payload.obj;
    t1 = vader_midir$is_short_circuit_op(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_op);
    return t1;
}

static bool vader_midir$is_short_circuit_op(uint8_t l0) {
    if (l0 == INT32_C(10)) {
        return true;
    }
    return l0 == INT32_C(11);
}

bool vader_midir$is_shrinking_intrinsic(vader_box_t l0) {
    void* t0 = NULL;
    vader_string_t t1 = 0;
    bool t2;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1361u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_midir$InstrIntrinsic_t*) t0)->f_name;
        t2 = vader_midir$intrinsic_shortens_array(t1);
        { bool __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_gc_top = gc_frame.prev; return false; }
}

static vader_box_t vader_midir$laid_out_fields(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    int32_t l3;
    vader_string_t l4 = 0;
    void* t0 = NULL;
    int64_t t1;
    vader_box_t t2 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l1, &t2 };
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 918u) {
        t0 = l1.payload.obj;
        t1 = ((vader_array_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_args)->length;
        if (t1 == INT64_C(0)) {
            l2 = ((vader_struct_vader_midir$SlotTypes_t*) l0)->f_plain_fields;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
            t2 = std_collections$MutableMap$std_core$Index$at__i32__Any(l2, l3);
            { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    l2 = ((vader_struct_vader_midir$SlotTypes_t*) l0)->f_fields;
    l4 = vader_midir_select$type_intern_key(l1);
    t2 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l4);
    { vader_box_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_midir$layout_key(void* l0, vader_string_t l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    vader_box_t l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    vader_box_t* gc_roots[2] = { &l3, &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_core_mono$MonoEntry_t*) l0)->f_symbol;
    if (l3.tag == 0u) {
        { vader_string_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = l3.payload.obj;
    l4 = ((vader_struct_vader_core_mono$MonoEntry_t*) l0)->f_type_arguments;
    t0 = vader_core_types$mk_struct(l2, l4);
    t1 = vader_midir_select$type_intern_key(t0);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$library_of(void* l0, void* l1) {
    vader_box_t l2;
    int64_t l3;
    void* t0;
    vader_box_t t1;
    l2 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_origin)->f_decl;
    if (!(l2.tag == 658u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l2.payload.obj;
    l3 = ((vader_struct_toolchain_ast$FnDecl_t*) t0)->f_id;
    t1 = std_collections$MutableMap$std_core$Index$at__i64__Any(l1, l3);
    return t1;
}

static void* vader_midir$literal_slots(void* l0, vader_box_t l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l5, l6;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_core_types$tuple_backing(l1);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        { void* __vret = ((vader_struct_vader_core_types$TupleType_t*) t0)->f_elements; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_midir$laid_out_fields(l0, l1);
    if (l2.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = l2.payload.obj;
    vader_array_t* _a1_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l4 = (void*) _a1_arr;
    l5 = ((vader_array_t*) l3)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a2_arr;
    l5 = ((vader_array_t*) l3)->length;
    l6 = INT64_C(0);
    while ((l6 < l5)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        t0 = vader_array_ref_load_obj(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l6);
        l2 = ((vader_struct_vader_midir$CFGStructField_t*) t0)->f_type;
        vader_array_push_ref((vader_array_t*) l4, l2.payload.obj);
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$local_type(void* l0, int32_t l1) {
    void* l2;
    int64_t l3;
    void* t0;
    l2 = ((vader_struct_vader_midir$CFGFunction_t*) ((vader_struct_vader_midir$StorageCheck_t*) l0)->f_function)->f_locals;
    l3 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    return ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
}

static vader_box_t vader_midir$lowered_to_bc_value(vader_box_t l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3, l4;
    vader_box_t l5 = vader_box_null();
    vader_string_t l6 = 0;
    uint8_t l7;
    uint64_t l8;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l0, &l5, &t3 };
    void** gc_raw_roots[3] = { &l1, &l2, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l6, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1293u) {
        t0 = l0.payload.obj;
        t1 = ((vader_struct_vader_lower_ir$LoweredStringLit_t*) t0)->f_value;
        vader_struct_vader_core_bytecode$BcValStr_t* _a0_obj = (vader_struct_vader_core_bytecode$BcValStr_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValStr_t));
        vader_obj_header_init(_a0_obj, 750u);
        _a0_obj->f_value = t1;
        t0 = (void*) _a0_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1296u) {
        vader_array_t* _a1_arr = vader_array_new(249u, 0u, 13u, 1723u);
        l1 = (void*) _a1_arr;
        t0 = l0.payload.obj;
        l2 = ((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_fields;
        l3 = ((vader_array_t*) l2)->length;
        l4 = INT64_C(0);
        while ((l4 < l3)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
            l5 = vader_midir$lowered_to_bc_value(((vader_struct_vader_lower_ir$LoweredStructLitField_t*) t0)->f_value);
            vader_array_push_ref((vader_array_t*) l1, l5.payload.obj);
            l4 = (l4 + INT64_C(1));
        }
        t0 = l0.payload.obj;
        t2 = vader_midir$struct_symbol_id(((vader_struct_vader_lower_ir$LoweredStructLit_t*) t0)->f_type);
        vader_struct_vader_core_bytecode$BcValStruct_t* _a3_obj = (vader_struct_vader_core_bytecode$BcValStruct_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValStruct_t));
        vader_obj_header_init(_a3_obj, 751u);
        _a3_obj->f_symbol_id = t2;
        _a3_obj->f_fields = l1;
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l0.tag == 1253u)) {
        l6 = vader_core_types$representation_name(VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredArrayLen_t, f_type, l0.payload.obj));
        l7 = vader_core_bytecode$array_kind_from_name(l6);
        l8 = vader_midir$bc_value_bits(l0, l6);
        vader_struct_vader_core_bytecode$BcValPrim_t* _a4_obj = (vader_struct_vader_core_bytecode$BcValPrim_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValPrim_t));
        vader_obj_header_init(_a4_obj, 749u);
        _a4_obj->f_kind = l7;
        _a4_obj->f_bits = l8;
        t0 = (void*) _a4_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a5_arr = vader_array_new(249u, 0u, 13u, 1723u);
    l1 = (void*) _a5_arr;
    t0 = l0.payload.obj;
    l2 = ((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_elements;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t3 = vader_array_ref_load_box(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l4);
        l5 = vader_midir$lowered_to_bc_value(t3);
        vader_array_push_ref((vader_array_t*) l1, l5.payload.obj);
        l4 = (l4 + INT64_C(1));
    }
    t0 = l0.payload.obj;
    t1 = vader_midir$array_element_name(((vader_struct_vader_lower_ir$LoweredArrayLit_t*) t0)->f_type);
    vader_struct_vader_core_bytecode$BcValArray_t* _a7_obj = (vader_struct_vader_core_bytecode$BcValArray_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_bytecode$BcValArray_t));
    vader_obj_header_init(_a7_obj, 748u);
    _a7_obj->f_element_type_name = t1;
    _a7_obj->f_elements = l1;
    t0 = (void*) _a7_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir$make_extern_decl(void* l0, void* l1) {
    void* l2 = NULL;
    void* l4 = NULL;
    void* l7 = NULL;
    void* l9 = NULL;
    void* l12 = NULL;
    vader_box_t l3 = vader_box_null(), l10 = vader_box_null();
    int64_t l5, l6;
    vader_string_t l8 = 0;
    vader_string_t l13 = 0;
    vader_string_t l15 = 0;
    int32_t l11;
    bool l14;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l10 };
    void** gc_raw_roots[8] = { &l0, &l1, &l2, &l4, &l7, &l9, &l12, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l8, &l13, &l15 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_midir$fn_metadata(l0);
    l3 = vader_midir$library_of(l0, l1);
    vader_array_t* _a0_arr = vader_array_new(205u, 0u, 13u, 1319u);
    l4 = (void*) _a0_arr;
    l5 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_params)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l4, (int64_t) l5);
    l4 = (void*) _a1_arr;
    l5 = INT64_C(0);
    l6 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_params)->length;
    while ((l5 < l6)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_params);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l5)
        l7 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l8 = ((vader_struct_vader_lower_ir$LoweredParam_t*) l7)->f_name;
        l9 = ((vader_struct_vader_lower_ir$LoweredParam_t*) l7)->f_symbol;
        l10 = ((vader_struct_vader_lower_ir$LoweredParam_t*) l7)->f_type;
        l11 = ((int32_t) (int64_t) l5);
        vader_struct_vader_midir$CFGParam_t* _a3_obj = (vader_struct_vader_midir$CFGParam_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGParam_t));
        vader_obj_header_init(_a3_obj, 1319u);
        _a3_obj->f_name = l8;
        _a3_obj->f_symbol = l9;
        _a3_obj->f_type = l10;
        _a3_obj->f_local = l11;
        l12 = (void*) _a3_obj;
        vader_array_push_ref((vader_array_t*) l4, l12);
        l5 = (l5 + INT64_C(1));
    }
    l8 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_mangled;
    l10 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_return_type;
    l7 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) l0)->f_origin;
    l13 = ((vader_struct_vader_midir$FnMetadata_t*) l2)->f_extern_name;
    l14 = ((vader_struct_vader_midir$FnMetadata_t*) l2)->f_is_extern;
    l15 = vader_midir$header_of(l0, l3);
    l11 = ((vader_struct_vader_midir$FnMetadata_t*) l2)->f_c_variadic_fixed;
    vader_struct_vader_midir$CFGExternDecl_t* _a4_obj = (vader_struct_vader_midir$CFGExternDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGExternDecl_t));
    vader_obj_header_init(_a4_obj, 1315u);
    _a4_obj->f_mangled = l8;
    _a4_obj->f_params = l4;
    _a4_obj->f_return_type = l10;
    _a4_obj->f_origin = l7;
    _a4_obj->f_extern_name = l13;
    _a4_obj->f_is_extern = l14;
    _a4_obj->f_c_header = l15;
    _a4_obj->f_c_variadic_fixed = l11;
    _a4_obj->f_library = l3;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir$make_struct_decl(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l2, l4;
    vader_string_t l6 = 0;
    vader_box_t l7 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l7 };
    void** gc_raw_roots[6] = { &l0, &l1, &l3, &l5, &l8, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 6u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(207u, 0u, 13u, 1322u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredStructDecl_t*) l0)->f_fields)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = ((vader_struct_vader_lower_ir$LoweredStructDecl_t*) l0)->f_fields;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l6 = ((vader_struct_vader_lower_ir$LoweredStructField_t*) l5)->f_name;
        l7 = ((vader_struct_vader_lower_ir$LoweredStructField_t*) l5)->f_type;
        vader_struct_vader_midir$CFGStructField_t* _a3_obj = (vader_struct_vader_midir$CFGStructField_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGStructField_t));
        vader_obj_header_init(_a3_obj, 1322u);
        _a3_obj->f_name = l6;
        _a3_obj->f_type = l7;
        l8 = (void*) _a3_obj;
        vader_array_push_ref((vader_array_t*) l1, l8);
        l4 = (l4 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_lower_ir$LoweredStructDecl_t*) l0)->f_mangled;
    l3 = ((vader_struct_vader_lower_ir$LoweredStructDecl_t*) l0)->f_origin;
    vader_struct_vader_midir$CFGStructDecl_t* _a4_obj = (vader_struct_vader_midir$CFGStructDecl_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CFGStructDecl_t));
    vader_obj_header_init(_a4_obj, 1321u);
    _a4_obj->f_mangled = l6;
    _a4_obj->f_fields = l1;
    _a4_obj->f_origin = l3;
    t0 = (void*) _a4_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir$mangles_reached(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l11 = NULL;
    void* l13 = NULL;
    int32_t l6, l12, l16;
    int64_t l7, l8, l14, l15;
    vader_box_t l9 = vader_box_null();
    vader_string_t l10 = 0;
    void* t0 = NULL;
    int32_t t1;
    bool t2;
    vader_box_t* gc_roots[2] = { &l1, &l9 };
    void** gc_raw_roots[8] = { &l0, &l2, &l3, &l4, &l5, &l11, &l13, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l10 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 0u, 335u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 333u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__string__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__bool_t));
    vader_obj_header_init(_a3_obj, 547u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__string_t* _a4_obj = (vader_struct_std_collections$MutableSet__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__string_t));
    vader_obj_header_init(_a4_obj, 615u);
    _a4_obj->f_inner = t0;
    l2 = (void*) _a4_obj;
    if (l1.tag == 0u) {
        { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a5_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(20u, 0u, 12u, 333u);
    l4 = (void*) _a6_arr;
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a7_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a8_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a8_obj, 470u);
    _a8_obj->f_ekeys = l3;
    _a8_obj->f_evals = l4;
    _a8_obj->f_index = l5;
    _a8_obj->f_mask = INT64_C(0);
    _a8_obj->f_grow_at = INT64_C(0);
    _a8_obj->f_size = INT64_C(0);
    _a8_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a8_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a9_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a9_obj, 613u);
    _a9_obj->f_inner = t0;
    l3 = (void*) _a9_obj;
    l6 = ((int32_t) l1.payload.i);
    std_collections$add__i32(l3, l6);
    t1 = ((int32_t) l1.payload.i);
    vader_array_t* _a10_arr = vader_array_new(23u, 1u, 7u, 338u);
    ((int32_t*) _a10_arr->buf->slots)[_a10_arr->offset + 0u] = (int32_t) t1;
    l4 = (void*) _a10_arr;
    l7 = INT64_C(0);
    for (;;) {
        l8 = ((vader_array_t*) l4)->length;
        if ((l7 < l8)) {
            l5 = ((vader_struct_vader_midir$CallGraph_t*) l0)->f_nodes;
            vader_array_t* _a11_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a11_slotarr)
            l6 = ((int32_t*) _a11_slotarr->buf->slots)[_a11_slotarr->offset + (size_t) l7];
            vader_array_t* _a12_slotarr = ((vader_array_t*) l5);
            VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l6)
            l9 = vader_array_ref_load_box(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l6);
            if (l9.tag == 1316u) {
                t0 = l9.payload.obj;
                l10 = ((vader_struct_vader_midir$CFGFunction_t*) t0)->f_mangled;
                std_collections$add__string(l2, l10);
            }
            l11 = ((vader_struct_vader_support_fixpoint$Graph_t*) ((vader_struct_vader_midir$CallGraph_t*) l0)->f_graph)->f_successors;
            vader_array_t* _a13_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
            l12 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l7];
            vader_array_t* _a14_slotarr = ((vader_array_t*) l11);
            VADER_ARRAY_RESOLVE_BUF(_a14_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a14_slotarr, l12)
            l13 = vader_array_ref_load_obj(_a14_slotarr->buf, _a14_slotarr->offset + (size_t) l12);
            l14 = ((vader_array_t*) l13)->length;
            l15 = INT64_C(0);
            while ((l15 < l14)) {
                vader_array_t* _a15_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a15_slotarr)
                l16 = ((int32_t*) _a15_slotarr->buf->slots)[_a15_slotarr->offset + (size_t) l15];
                t2 = std_collections$add__i32(l3, l16);
                if (t2) {
                    vader_array_push_i32((vader_array_t*) l4, l16);
                }
                l15 = (l15 + INT64_C(1));
            }
            l7 = vader_chk_add(i64, l7, INT64_C(1));
            continue;
        }
        break;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_midir$multi_dsts(vader_box_t l0) {
    void* t0;
    if (!(l0.tag == 1345u)) {
        return vader_box_obj(0u, NULL);
    }
    t0 = l0.payload.obj;
    return vader_ref_box(((vader_struct_vader_midir$InstrCall_t*) t0)->f_dsts);
}

static vader_box_t vader_midir$narrowed_local_width(void* l0, vader_box_t l1, vader_box_t l2) {
    int32_t l3;
    void* l4 = NULL;
    void* l8 = NULL;
    vader_box_t l5 = vader_box_null(), l7 = vader_box_null();
    int64_t l6;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l5, &l7 };
    void** gc_raw_roots[4] = { &l0, &l4, &l8, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (!(l1.tag == 1279u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_local_by_sym_id;
    t0 = l1.payload.obj;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_symbol)->f_id;
    l5 = std_collections$MutableMap$std_core$Index$at__i32__i32(l4, l3);
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((int32_t) l5.payload.i);
    l4 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_locals;
    l6 = ((int64_t) (int32_t) l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l5 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
    t0 = l1.payload.obj;
    l7 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) t0)->f_type;
    t1 = vader_midir$narrowed_read(l5, l7);
    if (!(t1)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l7 = vader_core_types$held_integer(l5);
    if (l7.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l4 = l7.payload.obj;
    t0 = (void*) &vader_data_21;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    l8 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) INT64_C(0));
    l5 = vader_midir$computation_width(l5, l2, vader_ref_box(l8));
    if (l5.tag == 0u) {
        t0 = vader_core_types$machine_integer_type(l4);
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l5.payload.obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir$narrowed_read(vader_box_t l0, vader_box_t l1) {
    void* l2;
    void* l3;
    vader_box_t l4;
    vader_string_t l5, l6;
    void* t0;
    bool t1;
    if (l0.tag == 916u) {
        if (l1.tag == 916u) {
            t0 = l0.payload.obj;
            l2 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds;
            t0 = l1.payload.obj;
            l3 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds;
            t1 = vader_support_integer$same_interval(l2, l3);
            if (t1) {
                return false;
            }
        }
    }
    l4 = vader_core_types$held_integer(l0);
    if (l4.tag == 0u) {
        return false;
    }
    l2 = l4.payload.obj;
    l4 = vader_core_types$held_integer(l1);
    if (l4.tag == 0u) {
        return false;
    }
    l3 = l4.payload.obj;
    l5 = ((vader_struct_vader_support_integer$MachineInteger_t*) l2)->f_name;
    l6 = ((vader_struct_vader_support_integer$MachineInteger_t*) l3)->f_name;
    return l5 != l6;
}

static bool vader_midir$narrower(void* l0, vader_box_t l1) {
    int64_t l2, l3;
    void* t0;
    if (!(l1.tag == 0u)) {
        l2 = ((vader_struct_vader_support_integer$MachineInteger_t*) l0)->f_bits;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_support_integer$MachineInteger_t*) t0)->f_bits;
        return (l2 < l3);
    }
    return true;
}

void* vader_midir$natural_loop_bodies(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l12 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l19 = NULL;
    int64_t l6, l7, l9, l10, l20, l21;
    int32_t l8, l11, l16, l18, l22;
    vader_box_t l17 = vader_box_null();
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l17 };
    void** gc_raw_roots[12] = { &l0, &l1, &l2, &l3, &l4, &l5, &l12, &l13, &l14, &l15, &l19, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 12u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_Any__t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_Any__t));
    vader_obj_header_init(_a3_obj, 478u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a3_obj;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    while ((l6 < l7)) {
        l8 = ((int32_t) (int64_t) l6);
        vader_array_t* _a4_arr = vader_array_new(23u, 0u, 7u, 338u);
        l4 = (void*) _a4_arr;
        vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l6)
        l5 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l6);
        l9 = ((vader_array_t*) l5)->length;
        l10 = INT64_C(0);
        vader_array_t* _pc38_hdr = (vader_array_t*) l4;
        size_t _pc38_len = _pc38_hdr->length;
        size_t _pc38_cap = (_pc38_hdr->offset == 0 && !vader_array_is_borrowed(_pc38_hdr) && _pc38_hdr->length >= _pc38_hdr->buf->length) ? _pc38_hdr->capacity : (size_t) 0;
        void* _pc38_slots = _pc38_hdr->buf->slots;
        for (;;) {
            if ((l10 < l9)) {
                vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
                l11 = ((int32_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l10];
                t0 = vader_midir$dominates(l2, l8, l11);
                if (t0) {
                    if (VADER_LIKELY(_pc38_len < _pc38_cap)) {
                        ((int32_t*) _pc38_slots)[_pc38_len] = (int32_t) (l11);
                        _pc38_len += 1;
                    } else {
                        _pc38_hdr->length = _pc38_len;
                        if (_pc38_hdr->buf->length < _pc38_len) {
                            _pc38_hdr->buf->length = _pc38_len;
                        }
                        vader_array_push_i32((vader_array_t*) l4, l11);
                        _pc38_hdr = (vader_array_t*) l4;
                        _pc38_len = _pc38_hdr->length;
                        _pc38_cap = (_pc38_hdr->offset == 0 && !vader_array_is_borrowed(_pc38_hdr) && _pc38_hdr->length >= _pc38_hdr->buf->length) ? _pc38_hdr->capacity : (size_t) 0;
                        _pc38_slots = _pc38_hdr->buf->slots;
                    }
                }
                l10 = (l10 + INT64_C(1));
                continue;
            }
            _pc38_hdr->length = _pc38_len;
            if (_pc38_hdr->buf->length < _pc38_len) {
                _pc38_hdr->buf->length = _pc38_len;
            }
            break;
        }
        t1 = ((vader_array_t*) l4)->length;
        if (t1 == INT64_C(0)) {
            l6 = (l6 + INT64_C(1));
            continue;
        }
        vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 338u);
        l12 = (void*) _a7_arr;
        vader_array_t* _a8_arr = vader_array_new(20u, 0u, 12u, 333u);
        l13 = (void*) _a8_arr;
        vader_array_t* _a9_arr = vader_array_new(23u, 0u, 7u, 338u);
        l14 = (void*) _a9_arr;
        vader_struct_std_collections$MutableMap__i32__bool_t* _a10_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
        vader_obj_header_init(_a10_obj, 470u);
        _a10_obj->f_ekeys = l12;
        _a10_obj->f_evals = l13;
        _a10_obj->f_index = l14;
        _a10_obj->f_mask = INT64_C(0);
        _a10_obj->f_grow_at = INT64_C(0);
        _a10_obj->f_size = INT64_C(0);
        _a10_obj->f_tombs = INT64_C(0);
        t2 = (void*) _a10_obj;
        vader_struct_std_collections$MutableSet__i32_t* _a11_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
        vader_obj_header_init(_a11_obj, 613u);
        _a11_obj->f_inner = t2;
        l15 = (void*) _a11_obj;
        std_collections$add__vader_midir$BlockId(l15, l8);
        for (;;) {
            l17 = vader_array_remove_last((vader_array_t*) l4);
            if (!(l17.tag == 0u)) {
                l16 = ((int32_t) l17.payload.i);
                t0 = std_collections$add__vader_midir$BlockId(l15, l16);
                if (!(t0)) {
                    continue;
                }
                l18 = l16;
                vader_array_t* _a12_slotarr = ((vader_array_t*) l1);
                VADER_ARRAY_RESOLVE_BUF(_a12_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a12_slotarr, l18)
                l19 = vader_array_ref_load_obj(_a12_slotarr->buf, _a12_slotarr->offset + (size_t) l18);
                l20 = ((vader_array_t*) l19)->length;
                l21 = INT64_C(0);
                while ((l21 < l20)) {
                    vader_array_t* _a13_slotarr = ((vader_array_t*) l19);
                    VADER_ARRAY_RESOLVE_BUF(_a13_slotarr)
                    l22 = ((int32_t*) _a13_slotarr->buf->slots)[_a13_slotarr->offset + (size_t) l21];
                    t0 = vader_midir$BlockId$std_core$Equals$equals(l22, l8);
                    if (!(t0)) {
                        vader_array_push_i32((vader_array_t*) l4, l22);
                    }
                    l21 = (l21 + INT64_C(1));
                }
                continue;
            }
            break;
        }
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l3, l8, vader_ref_box(l15));
        l6 = (l6 + INT64_C(1));
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir$new_block(void* l0, void* l1) {
    int32_t l2;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t t0;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_blocks)->length;
    l2 = ((int32_t) (int64_t) t0);
    l3 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_blocks;
    vader_array_t* _a0_arr = vader_array_new(267u, 0u, 13u, 2109u);
    l4 = (void*) _a0_arr;
    vader_struct_vader_midir$MutableBlock_t* _a1_obj = (vader_struct_vader_midir$MutableBlock_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$MutableBlock_t));
    vader_obj_header_init(_a1_obj, 1373u);
    _a1_obj->f_id = l2;
    _a1_obj->f_instructions = l4;
    _a1_obj->f_terminator = vader_box_obj(0u, NULL);
    _a1_obj->f_span = l1;
    l4 = (void*) _a1_obj;
    vader_array_push_ref((vader_array_t*) l3, l4);
    { int32_t __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir$new_project_ctx(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    void* l10 = NULL;
    int64_t l11, l12, l13, l14, l17, l18;
    vader_box_t l15 = vader_box_null(), l16 = vader_box_null();
    int32_t l19;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    void* t3 = NULL;
    bool t4;
    int64_t t5;
    vader_box_t* gc_roots[3] = { &l15, &l16, &t0 };
    void** gc_raw_roots[13] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &l8, &l9, &l10, &t2, &t3 };
    vader_string_t* gc_atom_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 13u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l2 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(29u, 0u, 0u, 346u);
    l3 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l4 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_Any__t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_Any__t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__std_collections_MutableSet_Any__t));
    vader_obj_header_init(_a3_obj, 478u);
    _a3_obj->f_ekeys = l2;
    _a3_obj->f_evals = l3;
    _a3_obj->f_index = l4;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    l2 = (void*) _a3_obj;
    vader_array_t* _a4_arr = vader_array_new(22u, 0u, 0u, 335u);
    l3 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(29u, 0u, 0u, 346u);
    l4 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a6_arr;
    vader_struct_std_collections$MutableMap__string__Any___t* _a7_obj = (vader_struct_std_collections$MutableMap__string__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__Any___t));
    vader_obj_header_init(_a7_obj, 542u);
    _a7_obj->f_ekeys = l3;
    _a7_obj->f_evals = l4;
    _a7_obj->f_index = l5;
    _a7_obj->f_mask = INT64_C(0);
    _a7_obj->f_grow_at = INT64_C(0);
    _a7_obj->f_size = INT64_C(0);
    _a7_obj->f_tombs = INT64_C(0);
    l3 = (void*) _a7_obj;
    vader_array_t* _a8_arr = vader_array_new(23u, 0u, 7u, 338u);
    l4 = (void*) _a8_arr;
    vader_array_t* _a9_arr = vader_array_new(29u, 0u, 0u, 346u);
    l5 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a10_arr;
    vader_struct_std_collections$MutableMap__i32__Any___t* _a11_obj = (vader_struct_std_collections$MutableMap__i32__Any___t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__Any___t));
    vader_obj_header_init(_a11_obj, 468u);
    _a11_obj->f_ekeys = l4;
    _a11_obj->f_evals = l5;
    _a11_obj->f_index = l6;
    _a11_obj->f_mask = INT64_C(0);
    _a11_obj->f_grow_at = INT64_C(0);
    _a11_obj->f_size = INT64_C(0);
    _a11_obj->f_tombs = INT64_C(0);
    l4 = (void*) _a11_obj;
    vader_array_t* _a12_arr = vader_array_new(22u, 0u, 0u, 335u);
    l5 = (void*) _a12_arr;
    vader_array_t* _a13_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a13_arr;
    vader_array_t* _a14_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a14_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a15_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a15_obj, 548u);
    _a15_obj->f_ekeys = l5;
    _a15_obj->f_evals = l6;
    _a15_obj->f_index = l7;
    _a15_obj->f_mask = INT64_C(0);
    _a15_obj->f_grow_at = INT64_C(0);
    _a15_obj->f_size = INT64_C(0);
    _a15_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a15_obj;
    vader_array_t* _a16_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a16_arr;
    vader_array_t* _a17_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a17_arr;
    vader_array_t* _a18_arr = vader_array_new(23u, 0u, 7u, 338u);
    l8 = (void*) _a18_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a19_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a19_obj, 471u);
    _a19_obj->f_ekeys = l6;
    _a19_obj->f_evals = l7;
    _a19_obj->f_index = l8;
    _a19_obj->f_mask = INT64_C(0);
    _a19_obj->f_grow_at = INT64_C(0);
    _a19_obj->f_size = INT64_C(0);
    _a19_obj->f_tombs = INT64_C(0);
    l6 = (void*) _a19_obj;
    vader_array_t* _a20_arr = vader_array_new(22u, 0u, 0u, 335u);
    l7 = (void*) _a20_arr;
    vader_array_t* _a21_arr = vader_array_new(23u, 0u, 7u, 338u);
    l8 = (void*) _a21_arr;
    vader_array_t* _a22_arr = vader_array_new(23u, 0u, 7u, 338u);
    l9 = (void*) _a22_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a23_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a23_obj, 548u);
    _a23_obj->f_ekeys = l7;
    _a23_obj->f_evals = l8;
    _a23_obj->f_index = l9;
    _a23_obj->f_mask = INT64_C(0);
    _a23_obj->f_grow_at = INT64_C(0);
    _a23_obj->f_size = INT64_C(0);
    _a23_obj->f_tombs = INT64_C(0);
    l7 = (void*) _a23_obj;
    vader_array_t* _a24_arr = vader_array_new(23u, 0u, 7u, 338u);
    l8 = (void*) _a24_arr;
    vader_array_t* _a25_arr = vader_array_new(23u, 0u, 7u, 338u);
    l9 = (void*) _a25_arr;
    vader_array_t* _a26_arr = vader_array_new(23u, 0u, 7u, 338u);
    l10 = (void*) _a26_arr;
    vader_struct_std_collections$MutableMap__i32__i32_t* _a27_obj = (vader_struct_std_collections$MutableMap__i32__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__i32_t));
    vader_obj_header_init(_a27_obj, 471u);
    _a27_obj->f_ekeys = l8;
    _a27_obj->f_evals = l9;
    _a27_obj->f_index = l10;
    _a27_obj->f_mask = INT64_C(0);
    _a27_obj->f_grow_at = INT64_C(0);
    _a27_obj->f_size = INT64_C(0);
    _a27_obj->f_tombs = INT64_C(0);
    l8 = (void*) _a27_obj;
    vader_struct_vader_midir$CalleeLookup_t* _a28_obj = (vader_struct_vader_midir$CalleeLookup_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$CalleeLookup_t));
    vader_obj_header_init(_a28_obj, 1325u);
    _a28_obj->f_fn_by_mangle = l5;
    _a28_obj->f_fn_by_symbol = l6;
    _a28_obj->f_import_by_mangle = l7;
    _a28_obj->f_import_by_symbol = l8;
    l5 = (void*) _a28_obj;
    vader_array_t* _a29_arr = vader_array_new(18u, 0u, 13u, 251u);
    l6 = (void*) _a29_arr;
    vader_array_t* _a30_arr = vader_array_new(18u, 0u, 13u, 251u);
    l7 = (void*) _a30_arr;
    vader_struct_vader_midir$SlotTypes_t* _a31_obj = (vader_struct_vader_midir$SlotTypes_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$SlotTypes_t));
    vader_obj_header_init(_a31_obj, 1377u);
    _a31_obj->f_fields = l3;
    _a31_obj->f_plain_fields = l4;
    _a31_obj->f_callees = l5;
    _a31_obj->f_function_params = l6;
    _a31_obj->f_import_params = l7;
    l3 = (void*) _a31_obj;
    l4 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l4)->f_evals;
    l11 = INT64_C(0);
    l12 = ((vader_struct_std_collections$MutableMap__string__vader_lower_ir_LoweredModule_t*) l4)->f_size;
    while ((l11 < l12)) {
        vader_array_t* _a32_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a32_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a32_slotarr, l11)
        t0 = vader_array_box_slots(_a32_slotarr->buf)[_a32_slotarr->offset + (size_t) l11];
        t1 = t0.payload.s;
        vader_array_t* _a33_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a33_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a33_slotarr, l11)
        t2 = vader_array_ref_load_obj(_a33_slotarr->buf, _a33_slotarr->offset + (size_t) l11);
        l4 = ((vader_struct_vader_lower_ir$LoweredModule_t*) t2)->f_decls;
        l13 = ((vader_array_t*) l4)->length;
        l14 = INT64_C(0);
        while ((l14 < l13)) {
            vader_array_t* _a34_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a34_slotarr)
            l15 = vader_array_ref_load_box(_a34_slotarr->buf, _a34_slotarr->offset + (size_t) l14);
            vader_midir$note_slot_types(l3, l15);
            if (l15.tag == 1276u) {
                t2 = l15.payload.obj;
                t3 = vader_midir$fn_metadata(t2);
                t4 = ((vader_struct_vader_midir$FnMetadata_t*) t3)->f_is_extern;
                if (t4) {
                    t2 = l15.payload.obj;
                    l16 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t2)->f_origin)->f_symbol;
                    if (l16.tag == 900u) {
                        vader_array_t* _a35_arr = vader_array_new(24u, 0u, 8u, 339u);
                        l7 = (void*) _a35_arr;
                        vader_array_t* _a36_arr = vader_array_new(20u, 0u, 12u, 333u);
                        l8 = (void*) _a36_arr;
                        vader_array_t* _a37_arr = vader_array_new(23u, 0u, 7u, 338u);
                        l9 = (void*) _a37_arr;
                        vader_struct_std_collections$MutableMap__i64__bool_t* _a38_obj = (vader_struct_std_collections$MutableMap__i64__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i64__bool_t));
                        vader_obj_header_init(_a38_obj, 516u);
                        _a38_obj->f_ekeys = l7;
                        _a38_obj->f_evals = l8;
                        _a38_obj->f_index = l9;
                        _a38_obj->f_mask = INT64_C(0);
                        _a38_obj->f_grow_at = INT64_C(0);
                        _a38_obj->f_size = INT64_C(0);
                        _a38_obj->f_tombs = INT64_C(0);
                        t2 = (void*) _a38_obj;
                        vader_struct_std_collections$MutableSet__i64_t* _a39_obj = (vader_struct_std_collections$MutableSet__i64_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i64_t));
                        vader_obj_header_init(_a39_obj, 614u);
                        _a39_obj->f_inner = t2;
                        l10 = (void*) _a39_obj;
                        l17 = INT64_C(0);
                        t2 = l15.payload.obj;
                        l18 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t2)->f_params)->length;
                        while ((l17 < l18)) {
                            t2 = l15.payload.obj;
                            vader_array_t* _a40_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t2)->f_params);
                            VADER_ARRAY_RESOLVE_BUF(_a40_slotarr)
                            VADER_ARRAY_CHECK_INDEX(_a40_slotarr, l17)
                            t2 = vader_array_ref_load_obj(_a40_slotarr->buf, _a40_slotarr->offset + (size_t) l17);
                            if (((vader_struct_vader_lower_ir$LoweredParam_t*) t2)->f_type.tag == 907u) {
                                std_collections$add__i64(l10, l17);
                            }
                            l17 = (l17 + INT64_C(1));
                        }
                        t5 = std_collections$len__i64(l10);
                        if ((t5 > INT64_C(0))) {
                            t2 = l16.payload.obj;
                            l19 = ((vader_struct_vader_core_symbol$Symbol_t*) t2)->f_id;
                            std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l2, l19, vader_ref_box(l10));
                        }
                    }
                }
            }
            l14 = (l14 + INT64_C(1));
        }
        l11 = (l11 + INT64_C(1));
    }
    vader_array_t* _a41_arr = vader_array_new(22u, 0u, 0u, 335u);
    l4 = (void*) _a41_arr;
    vader_array_t* _a42_arr = vader_array_new(22u, 0u, 0u, 335u);
    l5 = (void*) _a42_arr;
    vader_array_t* _a43_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a43_arr;
    vader_array_t* _a44_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a44_arr;
    vader_struct_std_collections$MutableMap__string__i32_t* _a45_obj = (vader_struct_std_collections$MutableMap__string__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__string__i32_t));
    vader_obj_header_init(_a45_obj, 548u);
    _a45_obj->f_ekeys = l5;
    _a45_obj->f_evals = l6;
    _a45_obj->f_index = l7;
    _a45_obj->f_mask = INT64_C(0);
    _a45_obj->f_grow_at = INT64_C(0);
    _a45_obj->f_size = INT64_C(0);
    _a45_obj->f_tombs = INT64_C(0);
    l5 = (void*) _a45_obj;
    l6 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_const_fn_wrap;
    l7 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_const_inline;
    l8 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_const_fresh_wrap;
    l9 = ((vader_struct_vader_lower_ir$LoweredProject_t*) l0)->f_globals;
    vader_struct_vader_midir$ProjectCtx_t* _a46_obj = (vader_struct_vader_midir$ProjectCtx_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ProjectCtx_t));
    vader_obj_header_init(_a46_obj, 1375u);
    _a46_obj->f_strings = l4;
    _a46_obj->f_string_index = l5;
    _a46_obj->f_const_fn_wrap = l6;
    _a46_obj->f_const_inline = l7;
    _a46_obj->f_const_fresh_wrap = l8;
    _a46_obj->f_extern_callbacks = l2;
    _a46_obj->f_diags = l1;
    _a46_obj->f_globals = l9;
    _a46_obj->f_slots = l3;
    t2 = (void*) _a46_obj;
    { void* __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir$node_callees(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l12 = NULL;
    int64_t l6, l7, l9, l10, l13, l14;
    vader_box_t l11 = vader_box_null();
    int32_t l15;
    int32_t t0;
    void* t1 = NULL;
    bool t2;
    vader_box_t* gc_roots[2] = { &l1, &l11 };
    void** gc_raw_roots[8] = { &l0, &l2, &l3, &l4, &l5, &l8, &l12, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 8u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1315u) {
        t0 = ((vader_struct_vader_midir$CalleeIndex_t*) l0)->f_foreign_callbacks;
        vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 338u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) t0;
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 1316u)) {
        vader_array_t* _a1_arr = vader_array_new(23u, 0u, 7u, 338u);
        t1 = (void*) _a1_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_array_t* _a3_arr = vader_array_new(20u, 0u, 12u, 333u);
    l4 = (void*) _a3_arr;
    vader_array_t* _a4_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a4_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a5_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a5_obj, 470u);
    _a5_obj->f_ekeys = l3;
    _a5_obj->f_evals = l4;
    _a5_obj->f_index = l5;
    _a5_obj->f_mask = INT64_C(0);
    _a5_obj->f_grow_at = INT64_C(0);
    _a5_obj->f_size = INT64_C(0);
    _a5_obj->f_tombs = INT64_C(0);
    t1 = (void*) _a5_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a6_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a6_obj, 613u);
    _a6_obj->f_inner = t1;
    l3 = (void*) _a6_obj;
    vader_array_t* _a7_arr = vader_array_new(23u, 0u, 7u, 338u);
    l4 = (void*) _a7_arr;
    t1 = l1.payload.obj;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) t1)->f_blocks;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t1 = vader_array_ref_load_obj(_a8_slotarr->buf, _a8_slotarr->offset + (size_t) l7);
        l8 = ((vader_struct_vader_midir$BasicBlock_t*) t1)->f_instructions;
        l9 = ((vader_array_t*) l8)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a9_slotarr = ((vader_array_t*) l8);
            VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
            l11 = vader_array_ref_load_box(_a9_slotarr->buf, _a9_slotarr->offset + (size_t) l10);
            l12 = vader_midir$instruction_callees(l0, l11);
            l13 = ((vader_array_t*) l12)->length;
            l14 = INT64_C(0);
            while ((l14 < l13)) {
                vader_array_t* _a10_slotarr = ((vader_array_t*) l12);
                VADER_ARRAY_RESOLVE_BUF(_a10_slotarr)
                l15 = ((int32_t*) _a10_slotarr->buf->slots)[_a10_slotarr->offset + (size_t) l14];
                t2 = std_collections$add__i32(l3, l15);
                if (t2) {
                    vader_array_push_i32((vader_array_t*) l4, l15);
                }
                l14 = (l14 + INT64_C(1));
            }
            vader_midir$note_taken(l0, l11, l2);
            l10 = (l10 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    { void* __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

bool vader_midir$node_shrinks_by_itself(vader_box_t l0) {
    bool l1;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 1u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1316u) {
        t0 = l0.payload.obj;
        l1 = vader_midir$body_shrinks_by_itself(t0);
        { bool __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l0.tag == 1315u) {
        t0 = l0.payload.obj;
        l1 = vader_midir$extern_shrinks_by_itself(t0);
    } else if ((l0.tag == 1336u || l0.tag == 1337u)) {
        l1 = false;
    } else {
        if (!(l0.tag == 1384u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = true;
    }
    { bool __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir$nodes_of(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t l2, l5;
    int32_t l6;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &l4 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l0)->f_inner)->f_size;
    if ((INT64_C(0) < l2)) {
        l2 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l0)->f_inner)->f_size;
    } else {
        l2 = INT64_C(0);
    }
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = l0;
    l4 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l3)->f_inner)->f_ekeys;
    l2 = INT64_C(0);
    l5 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l3)->f_inner)->f_size;
    vader_array_t* _pc33_hdr = (vader_array_t*) l1;
    size_t _pc33_len = _pc33_hdr->length;
    size_t _pc33_cap = (_pc33_hdr->offset == 0 && !vader_array_is_borrowed(_pc33_hdr) && _pc33_hdr->length >= _pc33_hdr->buf->length) ? _pc33_hdr->capacity : (size_t) 0;
    void* _pc33_slots = _pc33_hdr->buf->slots;
    for (;;) {
        if ((l2 < l5)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l2)
            l6 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l2];
            if (VADER_LIKELY(_pc33_len < _pc33_cap)) {
                ((int32_t*) _pc33_slots)[_pc33_len] = (int32_t) (l6);
                _pc33_len += 1;
            } else {
                _pc33_hdr->length = _pc33_len;
                if (_pc33_hdr->buf->length < _pc33_len) {
                    _pc33_hdr->buf->length = _pc33_len;
                }
                vader_array_push_i32((vader_array_t*) l1, l6);
                _pc33_hdr = (vader_array_t*) l1;
                _pc33_len = _pc33_hdr->length;
                _pc33_cap = (_pc33_hdr->offset == 0 && !vader_array_is_borrowed(_pc33_hdr) && _pc33_hdr->length >= _pc33_hdr->buf->length) ? _pc33_hdr->capacity : (size_t) 0;
                _pc33_slots = _pc33_hdr->buf->slots;
            }
            l2 = (l2 + INT64_C(1));
            continue;
        }
        _pc33_hdr->length = _pc33_len;
        if (_pc33_hdr->buf->length < _pc33_len) {
            _pc33_hdr->buf->length = _pc33_len;
        }
        break;
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void vader_midir$note_params(void* l0, vader_string_t l1, vader_box_t l2, void* l3, bool l4) {
    void* l5 = NULL;
    int32_t l6;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[3] = { &l0, &l3, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(l4)) {
        l5 = ((vader_struct_vader_midir$SlotTypes_t*) l0)->f_callees;
        t0 = ((vader_array_t*) ((vader_struct_vader_midir$SlotTypes_t*) l0)->f_function_params)->length;
        l6 = ((int32_t) (int64_t) t0);
        vader_midir$index_function(l5, l1, l2, l6);
        vader_array_push_ref((vader_array_t*) ((vader_struct_vader_midir$SlotTypes_t*) l0)->f_function_params, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    l5 = ((vader_struct_vader_midir$SlotTypes_t*) l0)->f_callees;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir$SlotTypes_t*) l0)->f_import_params)->length;
    l6 = ((int32_t) (int64_t) t0);
    vader_midir$index_import(l5, l1, l2, l6);
    vader_array_push_ref((vader_array_t*) ((vader_struct_vader_midir$SlotTypes_t*) l0)->f_import_params, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$note_slot_types(void* l0, vader_box_t l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    vader_box_t l6 = vader_box_null();
    vader_string_t l7 = 0;
    bool l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l6 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l7 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 1294u) {
        t0 = l1.payload.obj;
        l2 = vader_midir$make_struct_decl(t0);
        vader_midir$note_struct_fields(l0, l2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    if (l1.tag == 1276u) {
        vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
        l2 = (void*) _a0_arr;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_params;
        l4 = ((vader_array_t*) l3)->length;
        l5 = INT64_C(0);
        while ((l5 < l4)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l3);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l5);
            l6 = ((vader_struct_vader_lower_ir$LoweredParam_t*) t0)->f_type;
            vader_array_push_ref((vader_array_t*) l2, l6.payload.obj);
            l5 = (l5 + INT64_C(1));
        }
        t0 = l1.payload.obj;
        l7 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_mangled;
        t0 = l1.payload.obj;
        l6 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_origin)->f_symbol;
        t0 = l1.payload.obj;
        l8 = ((vader_struct_vader_lower_ir$LoweredFnDecl_t*) t0)->f_body.tag == 0u;
        vader_midir$note_params(l0, l7, l6, l2, l8);
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$note_struct_fields(void* l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null();
    int32_t l6;
    int64_t t0;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &l3 };
    vader_string_t* gc_atom_roots[1] = { &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir$SlotTypes_t*) l0)->f_fields;
    l3 = ((vader_struct_vader_midir$CFGStructDecl_t*) l1)->f_origin;
    l4 = ((vader_struct_vader_midir$CFGStructDecl_t*) l1)->f_mangled;
    l4 = vader_midir$layout_key(l3, l4);
    l3 = ((vader_struct_vader_midir$CFGStructDecl_t*) l1)->f_fields;
    std_collections$MutableMap$std_core$IndexSet$set_at__string__Any(l2, l4, vader_ref_box(l3));
    l5 = ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGStructDecl_t*) l1)->f_origin)->f_symbol;
    if (l5.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l2 = l5.payload.obj;
    t0 = ((vader_array_t*) ((vader_struct_vader_core_mono$MonoEntry_t*) ((vader_struct_vader_midir$CFGStructDecl_t*) l1)->f_origin)->f_type_arguments)->length;
    if (t0 == INT64_C(0)) {
        l3 = ((vader_struct_vader_midir$SlotTypes_t*) l0)->f_plain_fields;
        l6 = ((vader_struct_vader_core_symbol$Symbol_t*) l2)->f_id;
        l2 = ((vader_struct_vader_midir$CFGStructDecl_t*) l1)->f_fields;
        std_collections$MutableMap$std_core$IndexSet$set_at__i32__Any(l3, l6, vader_ref_box(l2));
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$note_taken(void* l0, vader_box_t l1, void* l2) {
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    int32_t l5;
    vader_box_t* gc_roots[2] = { &l1, &l4 };
    void** gc_raw_roots[3] = { &l0, &l2, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = vader_midir$taken_function(l1);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l4.payload.obj;
    l5 = vader_midir$taken_node(l0, l3);
    if (!(l1.tag == 1357u)) {
        std_collections$add__i32(((vader_struct_vader_midir$TakenFunctions_t*) l2)->f_as_values, l5);
        { vader_gc_top = gc_frame.prev; return; }
    }
    std_collections$add__i32(((vader_struct_vader_midir$TakenFunctions_t*) l2)->f_as_addresses, l5);
    { vader_gc_top = gc_frame.prev; return; }
}

static bool vader_midir$only_leaves(void* l0) {
    vader_box_t l1;
    int64_t t0;
    void* t1;
    if (((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_trailing.tag == 0u) {
        t0 = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_stmts)->length;
        if (t0 != INT64_C(1)) {
            return false;
        }
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_lower_ir$LoweredBlock_t*) l0)->f_stmts);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        l1 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) INT32_C(0));
        if ((l1.tag == 1261u || l1.tag == 1269u)) {
            return true;
        }
        if (!(l1.tag == 1292u)) {
            return false;
        }
        t1 = l1.payload.obj;
        l1 = ((vader_struct_vader_lower_ir$LoweredReturn_t*) t1)->f_value;
        if (l1.tag == 0u) {
            return true;
        }
        return (l1.tag == 1260u || l1.tag == 1279u || l1.tag == 1282u || l1.tag == 1289u);
    }
    return false;
}

static void* vader_midir$operand_edges(vader_box_t l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    int32_t l2, l3, l5, l6, l7;
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[3] = { &l1, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (l0.tag == 1300u) {
        t0 = l0.payload.obj;
        if (((vader_struct_vader_lower_ir$LoweredUnary_t*) t0)->f_op == INT32_C(1)) {
            t0 = l0.payload.obj;
            l1 = vader_midir$operand_edges(((vader_struct_vader_lower_ir$LoweredUnary_t*) t0)->f_operand);
            l2 = ((vader_struct_vader_midir$OperandEdges_t*) l1)->f_on_false;
            l3 = ((vader_struct_vader_midir$OperandEdges_t*) l1)->f_on_true;
            vader_struct_vader_midir$OperandEdges_t* _a0_obj = (vader_struct_vader_midir$OperandEdges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$OperandEdges_t));
            vader_obj_header_init(_a0_obj, 1374u);
            _a0_obj->f_on_true = l2;
            _a0_obj->f_on_false = l3;
            t0 = (void*) _a0_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    if (l0.tag == 1258u) {
        t0 = l0.payload.obj;
        t1 = vader_midir$is_short_circuit_op(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_op);
        if (t1) {
            t0 = l0.payload.obj;
            l1 = vader_midir$operand_edges(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_left);
            t0 = l0.payload.obj;
            l4 = vader_midir$operand_edges(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_right);
            t0 = l0.payload.obj;
            if (!(((vader_struct_vader_lower_ir$LoweredBinary_t*) t0)->f_op == INT32_C(10))) {
                l5 = ((vader_struct_vader_midir$OperandEdges_t*) l1)->f_on_true;
                l6 = ((vader_struct_vader_midir$OperandEdges_t*) l4)->f_on_true;
                l6 = vader_chk_add(i32, l5, l6);
                l7 = ((vader_struct_vader_midir$OperandEdges_t*) l4)->f_on_false;
                vader_struct_vader_midir$OperandEdges_t* _a1_obj = (vader_struct_vader_midir$OperandEdges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$OperandEdges_t));
                vader_obj_header_init(_a1_obj, 1374u);
                _a1_obj->f_on_true = l6;
                _a1_obj->f_on_false = l7;
                t0 = (void*) _a1_obj;
                { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l2 = ((vader_struct_vader_midir$OperandEdges_t*) l4)->f_on_true;
            l3 = ((vader_struct_vader_midir$OperandEdges_t*) l1)->f_on_false;
            l5 = ((vader_struct_vader_midir$OperandEdges_t*) l4)->f_on_false;
            l3 = vader_chk_add(i32, l3, l5);
            vader_struct_vader_midir$OperandEdges_t* _a2_obj = (vader_struct_vader_midir$OperandEdges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$OperandEdges_t));
            vader_obj_header_init(_a2_obj, 1374u);
            _a2_obj->f_on_true = l2;
            _a2_obj->f_on_false = l3;
            t0 = (void*) _a2_obj;
            { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
        }
    }
    vader_struct_vader_midir$OperandEdges_t* _a3_obj = (vader_struct_vader_midir$OperandEdges_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$OperandEdges_t));
    vader_obj_header_init(_a3_obj, 1374u);
    _a3_obj->f_on_true = INT32_C(1);
    _a3_obj->f_on_false = INT32_C(1);
    t0 = (void*) _a3_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$operand_width(vader_box_t l0, void* l1) {
    vader_box_t t0;
    if (!(l0.tag == 0u)) {
        t0 = vader_core_types$held_integer(l0);
        return t0;
    }
    return vader_ref_box(l1);
}

static void* vader_midir$param_types(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    int64_t l2, l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(251u, 0u, 13u, 1789u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    l3 = l0;
    l2 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l2)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
        l5 = ((vader_struct_vader_midir$CFGParam_t*) t0)->f_type;
        vader_array_push_ref((vader_array_t*) l1, l5.payload.obj);
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir$params_of(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null();
    void* l3 = NULL;
    int32_t l4;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_midir$function_called(((vader_struct_vader_midir$SlotTypes_t*) l0)->f_callees, l1);
    if (!(l2.tag == 0u)) {
        l3 = ((vader_struct_vader_midir$SlotTypes_t*) l0)->f_function_params;
        l4 = ((int32_t) l2.payload.i);
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_midir$import_called(((vader_struct_vader_midir$SlotTypes_t*) l0)->f_callees, l1);
    if (l2.tag == 0u) {
        vader_array_t* _a1_arr = vader_array_new(251u, 0u, 13u, 1789u);
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = ((int32_t) l2.payload.i);
    vader_array_t* _a2_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$SlotTypes_t*) l0)->f_import_params);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    t0 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$place_slot(void* l0, vader_box_t l1, vader_box_t l2) {
    int32_t l3;
    vader_box_t l4 = vader_box_null(), l7 = vader_box_null();
    void* l5 = NULL;
    int64_t l6;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l1, &l2, &l4, &l7 };
    void** gc_raw_roots[3] = { &l0, &l5, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = l1;
    if (l4.tag == 0u) {
        { vader_box_t __vret = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredFieldAccess_t, f_type, l2.payload.obj); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l3 = ((int32_t) l4.payload.i);
    l5 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_locals;
    l6 = ((int64_t) (int32_t) l3);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l6)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l6);
    l4 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
    l5 = ((vader_struct_vader_midir$ProjectCtx_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_project)->f_slots;
    if (l2.tag == 1274u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) t0)->f_field;
        l7 = vader_midir$field_slot(l5, l4, l8);
    } else if (l2.tag == 1301u) {
        t0 = l2.payload.obj;
        l8 = ((vader_struct_vader_lower_ir$LoweredUnionField_t*) t0)->f_field;
        l7 = vader_midir$field_slot(l5, l4, l8);
    } else {
        if (!(l2.tag == 1281u)) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l7 = vader_midir$element_slot(l4);
    }
    l4 = l7;
    if (l4.tag == 0u) {
        { vader_box_t __vret = VADER_UNION_FIELD(vader_box_t, vader_struct_vader_lower_ir$LoweredFieldAccess_t, f_type, l2.payload.obj); vader_gc_top = gc_frame.prev; return __vret; }
    }
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

int64_t vader_midir$pos_key(int32_t l0, int64_t l1) {
    int64_t t0, t1;
    t0 = vader_chk_mul(i64, ((int64_t) (int32_t) l0), INT64_C(1000000));
    t1 = vader_chk_add(i64, t0, l1);
    return t1;
}

void* vader_midir$predecessors_of(void* l0) {
    int64_t l1, l4, l7, l8;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l10 = NULL;
    int32_t l9, l11;
    void** gc_raw_roots[6] = { &l0, &l2, &l3, &l5, &l6, &l10 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    l2 = (void*) &vader_fn_static___lambda_vader_midir_11;
    l2 = std_core$filled__i32__(l1, l2);
    l3 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l1 = ((vader_array_t*) l3)->length;
    l4 = INT64_C(0);
    while ((l4 < l1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
        l6 = vader_midir$successors_of(l5);
        l7 = ((vader_array_t*) l6)->length;
        l8 = INT64_C(0);
        while ((l8 < l7)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l9 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l8];
            vader_array_t* _a2_slotarr = ((vader_array_t*) l2);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l9)
            l10 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l9);
            l11 = ((vader_struct_vader_midir$BasicBlock_t*) l5)->f_id;
            vader_array_push_i32((vader_array_t*) l10, l11);
            l8 = (l8 + INT64_C(1));
        }
        l4 = (l4 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* vader_midir$reachable_blocks(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l3 = NULL;
    int64_t l4, l5;
    int32_t l6;
    void* t0 = NULL;
    int64_t t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 333u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l3 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 470u);
    _a3_obj->f_ekeys = l1;
    _a3_obj->f_evals = l2;
    _a3_obj->f_index = l3;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 613u);
    _a4_obj->f_inner = t0;
    l1 = (void*) _a4_obj;
    t1 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    if (t1 == INT64_C(0)) {
        { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l2 = vader_midir$reverse_postorder(l0);
    l4 = ((vader_array_t*) l2)->length;
    l5 = INT64_C(0);
    while ((l5 < l4)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        l6 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l5];
        std_collections$add__vader_midir$BlockId(l1, l6);
        l5 = (l5 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir$read_as(void* l0, int32_t l1, vader_box_t l2, void* l3) {
    void* l4 = NULL;
    int64_t l5;
    void* t0 = NULL;
    bool t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l2 };
    void** gc_raw_roots[4] = { &l0, &l3, &l4, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_locals;
    l5 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l4);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l5)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l5);
    t1 = vader_midir$narrowed_read(((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type, l2);
    if (!(t1)) {
        { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t2 = vader_midir$cast_local(l0, l1, l2, 1739u, l3);
    { int32_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$read_type(vader_box_t l0, vader_box_t l1) {
    bool t0;
    t0 = vader_midir$narrowed_read(l0, l1);
    if (!(t0)) {
        return l1;
    }
    return l0;
}

static void* vader_midir$resolve_loop_frame(void* l0, vader_box_t l1) {
    int64_t l2;
    void* l3 = NULL;
    vader_string_t l4 = 0;
    vader_string_t l5 = 0;
    int64_t t0;
    bool t1;
    vader_string_t t2 = 0;
    vader_string_t t3 = 0;
    vader_box_t* gc_roots[1] = { &l1 };
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_string_t* gc_atom_roots[4] = { &l4, &l5, &t2, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l1.tag == 0u) {
        t0 = ((vader_array_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_loop_stack)->length;
        l2 = vader_chk_sub(i64, t0, INT64_C(1));
        while ((l2 >= INT64_C(0))) {
            vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_loop_stack);
            VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
            l3 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l2);
            t1 = ((vader_struct_vader_midir$LoopFrame_t*) l3)->f_block;
            if (!(t1)) {
                { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
            }
            l2 = vader_chk_sub(i64, l2, INT64_C(1));
        }
        l4 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_mangled;
        t2 = concat_3(2333u, l4, 1096u);
        vader_host_std_abort$panic(t2);
        vader_unreachable("a no-return call returned");
    } else {
        l4 = l1.payload.s;
        t0 = ((vader_array_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_loop_stack)->length;
        l2 = vader_chk_sub(i64, t0, INT64_C(1));
        while ((l2 >= INT64_C(0))) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_loop_stack);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l2)
            l3 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l2);
            if (!(((vader_struct_vader_midir$LoopFrame_t*) l3)->f_label.tag == 0u)) {
                t2 = ((vader_struct_vader_midir$LoopFrame_t*) l3)->f_label.payload.s;
                if (t2 == l4) {
                    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
                }
            }
            l2 = vader_chk_sub(i64, l2, INT64_C(1));
        }
        l5 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_mangled;
        t2 = concat_5(2333u, l5, 1188u, l4, 1036u);
        t3 = concat_2(t2, 2697u);
        vader_host_std_abort$panic(t3);
        vader_unreachable("a no-return call returned");
    }
    vader_gc_top = gc_frame.prev;
}

static bool vader_midir$returns_only_never(void* l0, void* l1) {
    void* l2;
    void* l9;
    int64_t l3, l4, l6, l8, l10;
    int32_t l5;
    bool l7;
    void* t0;
    l2 = l1;
    l3 = ((vader_array_t*) l2)->length;
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
        l6 = ((int64_t) (int32_t) l5);
        if ((INT64_C(0) <= l6)) {
            l8 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals)->length;
            l7 = (l6 < l8);
        } else {
            l7 = false;
        }
        if (!(l7)) {
            return false;
        }
        l9 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals;
        l10 = ((int64_t) (int32_t) l5);
        vader_array_t* _a1_slotarr = ((vader_array_t*) l9);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l10)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l10);
        if (!(((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type.tag == 913u)) {
            return false;
        }
        l4 = (l4 + INT64_C(1));
    }
    return true;
}

void* vader_midir$reverse_postorder(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    int64_t l3;
    int32_t l4;
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 1u, 12u, 333u);
    ((uint8_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (uint8_t) false;
    l2 = (void*) _a1_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    vader_array_t* _a2_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a2_arr;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_entry;
    vader_midir$walk_rpo(l0, l4, l2, l1);
    vader_array_t* _a3_arr = vader_array_new(23u, 0u, 7u, 338u);
    l2 = (void*) _a3_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _a4_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a4_arr;
    l3 = ((vader_array_t*) l1)->length;
    vader_array_t* _pc31_hdr = (vader_array_t*) l2;
    size_t _pc31_len = _pc31_hdr->length;
    size_t _pc31_cap = (_pc31_hdr->offset == 0 && !vader_array_is_borrowed(_pc31_hdr) && _pc31_hdr->length >= _pc31_hdr->buf->length) ? _pc31_hdr->capacity : (size_t) 0;
    void* _pc31_slots = _pc31_hdr->buf->slots;
    for (;;) {
        if ((l3 > INT64_C(0))) {
            l3 = vader_chk_sub(i64, l3, INT64_C(1));
            vader_array_t* _a5_slotarr = ((vader_array_t*) l1);
            VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a5_slotarr, l3)
            l4 = ((int32_t*) _a5_slotarr->buf->slots)[_a5_slotarr->offset + (size_t) l3];
            if (VADER_LIKELY(_pc31_len < _pc31_cap)) {
                ((int32_t*) _pc31_slots)[_pc31_len] = (int32_t) (l4);
                _pc31_len += 1;
            } else {
                _pc31_hdr->length = _pc31_len;
                if (_pc31_hdr->buf->length < _pc31_len) {
                    _pc31_hdr->buf->length = _pc31_len;
                }
                vader_array_push_i32((vader_array_t*) l2, l4);
                _pc31_hdr = (vader_array_t*) l2;
                _pc31_len = _pc31_hdr->length;
                _pc31_cap = (_pc31_hdr->offset == 0 && !vader_array_is_borrowed(_pc31_hdr) && _pc31_hdr->length >= _pc31_hdr->buf->length) ? _pc31_hdr->capacity : (size_t) 0;
                _pc31_slots = _pc31_hdr->buf->slots;
            }
            continue;
        }
        _pc31_hdr->length = _pc31_len;
        if (_pc31_hdr->buf->length < _pc31_len) {
            _pc31_hdr->buf->length = _pc31_len;
        }
        break;
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir$rpo_positions(void* l0, int64_t l1) {
    void* l2 = NULL;
    int64_t l3, l4;
    int32_t l5, l6;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 338u);
    ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) INT32_C(-1);
    t0 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) t0, (int64_t) l1);
    l2 = (void*) _a1_arr;
    l3 = INT64_C(0);
    l4 = ((vader_array_t*) l0)->length;
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l5 = ((int32_t*) _a2_slotarr->buf->slots)[_a2_slotarr->offset + (size_t) l3];
        l6 = ((int32_t) (int64_t) l3);
        vader_array_t* _a3_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a3_slotarr, l5)
        ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l5] = (int32_t) l6;
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l2; vader_gc_top = gc_frame.prev; return __vret; }
}

static bool vader_midir$same_bounds(void* l0, vader_box_t l1) {
    void* l2;
    void* l3;
    void* t0;
    bool t1;
    if (l1.tag == 916u) {
        l2 = ((vader_struct_vader_core_types$RangeType_t*) l0)->f_bounds;
        t0 = l1.payload.obj;
        l3 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds;
        t1 = vader_support_integer$same_interval(l2, l3);
        return t1;
    }
    if (l1.tag == 0u) {
        return true;
    }
    t1 = vader_core_types$is_stored_as_integer(l1);
    return !(t1);
}

static bool vader_midir$sets_equal(void* l0, void* l1) {
    int64_t l2, l3;
    void* l4;
    void* l5;
    int32_t l6;
    bool t0;
    l2 = std_collections$len__i32(l0);
    l3 = std_collections$len__i32(l1);
    if (l2 != l3) {
        return false;
    }
    l4 = l0;
    l5 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l4)->f_inner)->f_ekeys;
    l2 = INT64_C(0);
    l3 = ((vader_struct_std_collections$MutableMap__i32__bool_t*) ((vader_struct_std_collections$MutableSet__i32_t*) l4)->f_inner)->f_size;
    while ((l2 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l2)
        l6 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l2];
        t0 = std_collections$MutableSet$std_core$Contains$contains__i32(l1, l6);
        if (!(t0)) {
            return false;
        }
        l2 = (l2 + INT64_C(1));
    }
    return true;
}

void* vader_midir$shrink_predicate(void* l0) {
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct___lambda_env_vader_midir_1_t* _a0_obj = (vader_struct___lambda_env_vader_midir_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_1_t));
    vader_obj_header_init(_a0_obj, 434u);
    _a0_obj->f_cap_0 = l0;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 330u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_0;
    _a1_closure->env = t0;
    t0 = (void*) _a1_closure;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_midir$shrink_summary_line(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l5 = NULL;
    int64_t l3, l4, l6, l10;
    int32_t l7;
    bool l8, l9;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    vader_string_t l13 = 0;
    void* t0 = NULL;
    int64_t t1;
    bool t2;
    vader_string_t t3 = 0;
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l5, &t0 };
    vader_string_t* gc_atom_roots[4] = { &l11, &l12, &l13, &t3 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_midir$CallGraph_t*) ((vader_struct_vader_midir$ShrinkSummary_t*) l0)->f_calls)->f_nodes;
    vader_struct___lambda_env_vader_midir_5_t* _a0_obj = (vader_struct___lambda_env_vader_midir_5_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_5_t));
    vader_obj_header_init(_a0_obj, 442u);
    _a0_obj->f_cap_0 = l1;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 310u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_4;
    _a1_closure->env = t0;
    l2 = (void*) _a1_closure;
    t1 = ((vader_array_t*) l1)->length;
    l3 = vader_midir$count_where(t1, l2);
    l4 = ((vader_array_t*) l1)->length;
    vader_struct___lambda_env_vader_midir_7_t* _a2_obj = (vader_struct___lambda_env_vader_midir_7_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_7_t));
    vader_obj_header_init(_a2_obj, 443u);
    _a2_obj->f_cap_0 = l2;
    _a2_obj->f_cap_1 = l0;
    t0 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 310u);
    _a3_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_6;
    _a3_closure->env = t0;
    l5 = (void*) _a3_closure;
    l4 = vader_midir$count_where(l4, l5);
    l6 = ((vader_array_t*) l1)->length;
    vader_struct___lambda_env_vader_midir_9_t* _a4_obj = (vader_struct___lambda_env_vader_midir_9_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_9_t));
    vader_obj_header_init(_a4_obj, 444u);
    _a4_obj->f_cap_0 = l2;
    _a4_obj->f_cap_1 = l1;
    t0 = (void*) _a4_obj;
    vader_fn_t* _a5_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a5_closure, 310u);
    _a5_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_8;
    _a5_closure->env = t0;
    l1 = (void*) _a5_closure;
    l6 = vader_midir$count_where(l6, l1);
    l1 = ((vader_struct_vader_midir$ShrinkSummary_t*) l0)->f_may_shrink;
    l7 = ((vader_struct_vader_midir$CalleeIndex_t*) ((vader_struct_vader_midir$CallGraph_t*) ((vader_struct_vader_midir$ShrinkSummary_t*) l0)->f_calls)->f_index)->f_indirect;
    vader_array_t* _a6_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l7)
    t2 = ((uint8_t*) _a6_slotarr->buf->slots)[_a6_slotarr->offset + (size_t) l7];
    l8 = t2;
    l1 = ((vader_struct_vader_midir$ShrinkSummary_t*) l0)->f_may_shrink;
    l7 = ((vader_struct_vader_midir$CalleeIndex_t*) ((vader_struct_vader_midir$CallGraph_t*) ((vader_struct_vader_midir$ShrinkSummary_t*) l0)->f_calls)->f_index)->f_foreign_callbacks;
    vader_array_t* _a7_slotarr = ((vader_array_t*) l1);
    VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a7_slotarr, l7)
    t2 = ((uint8_t*) _a7_slotarr->buf->slots)[_a7_slotarr->offset + (size_t) l7];
    l9 = t2;
    l1 = (void*) vader_buffer_new((size_t) INT64_C(76));
    l10 = INT64_C(0);
    l10 = std_core$write_int(l1, l10, l4);
    l10 = std_core$write_string_at(l1, l10, 185u);
    l10 = std_core$write_int(l1, l10, l3);
    l10 = std_core$write_string_at(l1, l10, 133u);
    l11 = std_core$finish_buffer(l1, l10);
    l1 = (void*) vader_buffer_new((size_t) INT64_C(72));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l1, l3, 306u);
    l3 = std_core$write_int(l1, l3, l6);
    l3 = std_core$write_string_at(l1, l3, 103u);
    l3 = std_core$write_bool(l1, l3, l8);
    l3 = std_core$write_string_at(l1, l3, 362u);
    l12 = std_core$finish_buffer(l1, l3);
    l1 = (void*) vader_buffer_new((size_t) INT64_C(33));
    l3 = INT64_C(0);
    l3 = std_core$write_string_at(l1, l3, 1434u);
    l3 = std_core$write_bool(l1, l3, l9);
    l13 = std_core$finish_buffer(l1, l3);
    t3 = concat_3(l11, l12, l13);
    { vader_string_t __vret = t3; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$stored_cell(void* l0, void* l1) {
    int32_t l2, l5;
    vader_box_t l3 = vader_box_null(), l4 = vader_box_null();
    void* l6 = NULL;
    vader_box_t* gc_roots[2] = { &l3, &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredCellGet_t*) l1)->f_target;
    l3 = vader_midir$build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = ((vader_struct_vader_lower_ir$LoweredCellGet_t*) l1)->f_value_type;
    l4 = ((vader_struct_vader_lower_ir$LoweredCellGet_t*) l1)->f_type;
    l3 = vader_midir$read_type(l3, l4);
    l5 = vader_midir$fresh_tmp(l0, 1741u, l3);
    l6 = ((vader_struct_vader_lower_ir$LoweredCellGet_t*) l1)->f_span;
    l3 = ((vader_struct_vader_lower_ir$LoweredCellGet_t*) l1)->f_value_type;
    vader_struct_vader_midir$InstrCellGet_t* _a0_obj = (vader_struct_vader_midir$InstrCellGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrCellGet_t));
    vader_obj_header_init(_a0_obj, 1348u);
    _a0_obj->f_span = l6;
    _a0_obj->f_dst = l5;
    _a0_obj->f_cell = l2;
    _a0_obj->f_value_type = l3;
    l6 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l6));
    { vader_box_t __vret = vader_box_i32(338u, l5); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$stored_conversion(vader_box_t l0, vader_box_t l1) {
    vader_box_t l2, l5;
    void* l3;
    void* l4;
    vader_string_t l6, l7;
    void* t0;
    bool t1;
    l2 = l1;
    if (l2.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    if (l0.tag == 916u) {
        if (l2.tag == 916u) {
            t0 = l0.payload.obj;
            l3 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds;
            t0 = l2.payload.obj;
            l4 = ((vader_struct_vader_core_types$RangeType_t*) t0)->f_bounds;
            t1 = vader_support_integer$same_interval(l3, l4);
            if (t1) {
                return vader_box_obj(0u, NULL);
            }
        }
    }
    l5 = vader_core_types$held_integer(l0);
    if (l5.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l3 = l5.payload.obj;
    l2 = vader_midir$integer_member(l2, l3);
    if (l2.tag == 0u) {
        return vader_box_obj(0u, NULL);
    }
    l4 = l2.payload.obj;
    l6 = ((vader_struct_vader_support_integer$MachineInteger_t*) l4)->f_name;
    l7 = ((vader_struct_vader_support_integer$MachineInteger_t*) l3)->f_name;
    if (!(l6 == l7)) {
        return vader_ref_box(l4);
    }
    return vader_box_obj(0u, NULL);
}

static vader_box_t vader_midir$stored_field(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_string_t l6 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) l1)->f_target;
    l3 = vader_midir$build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = vader_midir$field_read_type(l0, l2, vader_ref_box(l1));
    l4 = vader_midir$fresh_tmp(l0, 1976u, l3);
    l5 = ((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_ir$LoweredFieldAccess_t*) l1)->f_field;
    vader_struct_vader_midir$InstrFieldGet_t* _a0_obj = (vader_struct_vader_midir$InstrFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrFieldGet_t));
    vader_obj_header_init(_a0_obj, 1355u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_target = l2;
    _a0_obj->f_type = l3;
    _a0_obj->f_field = l6;
    l5 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l5));
    { vader_box_t __vret = vader_box_i32(338u, l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$stored_ident(void* l0, void* l1) {
    void* l2 = NULL;
    int32_t l3;
    vader_box_t l4 = vader_box_null();
    int32_t t0;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[3] = { &l0, &l1, &l2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_local_by_sym_id;
    l3 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_lower_ir$LoweredIdent_t*) l1)->f_symbol)->f_id;
    l4 = std_collections$MutableMap$std_core$Index$at__i32__i32(l2, l3);
    if (!(l4.tag == 0u)) {
        l3 = ((int32_t) l4.payload.i);
        t0 = vader_midir$stored_slot(l0, l3, l1);
        { vader_box_t __vret = vader_box_i32(338u, t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l4 = vader_midir$build_module_ident(l0, l1);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l3 = ((int32_t) l4.payload.i);
    t0 = vader_midir$stored_slot(l0, l3, l1);
    { vader_box_t __vret = vader_box_i32(338u, t0); vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_midir$stored_name(vader_box_t l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null();
    vader_string_t t0 = 0;
    vader_box_t* gc_roots[2] = { &l0, &l2 };
    void** gc_raw_roots[1] = { &l1 };
    vader_string_t* gc_atom_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 1u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = vader_core_types$held_integer(l0);
    if (l2.tag == 0u) {
        t0 = vader_core_types$display_type(l0);
        { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = l2.payload.obj;
    t0 = ((vader_struct_vader_support_integer$MachineInteger_t*) l1)->f_name;
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir$stored_slot(void* l0, int32_t l1, void* l2) {
    void* l3 = NULL;
    int64_t l4;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    int32_t t2;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_locals;
    l4 = ((int64_t) (int32_t) l1);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l4);
    l5 = ((vader_struct_vader_midir$CFGLocal_t*) t0)->f_type;
    if (l5.tag == 926u) {
        l3 = l5.payload.obj;
        l5 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l2)->f_type;
        t1 = vader_core_types$equals_type(vader_ref_box(l3), l5);
        if (!(t1)) {
            l5 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l2)->f_type;
            l3 = ((vader_struct_vader_lower_ir$LoweredIdent_t*) l2)->f_span;
            t2 = vader_midir$cast_local(l0, l1, l5, 2365u, l3);
            { int32_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
        }
        { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    { int32_t __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$stored_test(void* l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[3] = { &l2, &l3, &t0 };
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    if (((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_right.tag == 1282u) {
        l2 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_left;
        l3 = ((vader_struct_vader_lower_ir$LoweredIntLit_t*) ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_right.payload.obj)->f_type;
        t0 = vader_midir$narrowed_local_width(l0, l2, l3);
        { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_left.tag == 1282u)) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_right;
    l3 = ((vader_struct_vader_lower_ir$LoweredIntLit_t*) ((vader_struct_vader_lower_ir$LoweredBinary_t*) l1)->f_left.payload.obj)->f_type;
    t0 = vader_midir$narrowed_local_width(l0, l2, l3);
    { vader_box_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t vader_midir$stored_union_field(void* l0, void* l1) {
    int32_t l2, l4;
    vader_box_t l3 = vader_box_null();
    void* l5 = NULL;
    vader_string_t l6 = 0;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[3] = { &l0, &l1, &l5 };
    vader_string_t* gc_atom_roots[1] = { &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = ((vader_struct_vader_lower_ir$LoweredUnionField_t*) l1)->f_target;
    l3 = vader_midir$build_expr(l0, l3);
    if (l3.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return vader_box_obj(0u, NULL); }
    }
    l2 = ((int32_t) l3.payload.i);
    l3 = vader_midir$field_read_type(l0, l2, vader_ref_box(l1));
    l4 = vader_midir$fresh_tmp(l0, 1976u, l3);
    l5 = ((vader_struct_vader_lower_ir$LoweredUnionField_t*) l1)->f_span;
    l6 = ((vader_struct_vader_lower_ir$LoweredUnionField_t*) l1)->f_field;
    vader_struct_vader_midir$InstrUnionFieldGet_t* _a0_obj = (vader_struct_vader_midir$InstrUnionFieldGet_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$InstrUnionFieldGet_t));
    vader_obj_header_init(_a0_obj, 1368u);
    _a0_obj->f_span = l5;
    _a0_obj->f_dst = l4;
    _a0_obj->f_target = l2;
    _a0_obj->f_type = l3;
    _a0_obj->f_field = l6;
    l5 = (void*) _a0_obj;
    vader_midir$emit(l0, vader_ref_box(l5));
    { vader_box_t __vret = vader_box_i32(338u, l4); vader_gc_top = gc_frame.prev; return __vret; }
}

static int32_t vader_midir$struct_symbol_id(vader_box_t l0) {
    void* t0;
    int32_t t1;
    if (!(l0.tag == 918u)) {
        return INT32_C(-1);
    }
    t0 = l0.payload.obj;
    t1 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_core_types$StructType_t*) t0)->f_symbol)->f_id;
    return t1;
}

void* vader_midir$successors_of(void* l0) {
    vader_box_t l1 = vader_box_null(), l2 = vader_box_null();
    int32_t l3, l4;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l1, &l2 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_struct_vader_midir$BasicBlock_t*) l0)->f_terminator;
    l2 = l1;
    if (l1.tag == 1380u) {
        t0 = l2.payload.obj;
        vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 338u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) ((vader_struct_vader_midir$TermBranch_t*) t0)->f_target;
        t0 = (void*) _a0_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1381u) {
        t0 = l2.payload.obj;
        l3 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_then_block;
        t0 = l2.payload.obj;
        l4 = ((vader_struct_vader_midir$TermCondBranch_t*) t0)->f_else_block;
        vader_array_t* _a1_arr = vader_array_new(23u, 2u, 7u, 338u);
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 1u] = (int32_t) l4;
        ((int32_t*) _a1_arr->buf->slots)[_a1_arr->offset + 0u] = (int32_t) l3;
        t0 = (void*) _a1_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (l1.tag == 1382u) {
        vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
        t0 = (void*) _a2_arr;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    if (!(l1.tag == 1383u)) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    vader_array_t* _a3_arr = vader_array_new(23u, 0u, 7u, 338u);
    t0 = (void*) _a3_arr;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_midir$summarise_array_shrinking(void* l0) {
    void* l1 = NULL;
    void* l2 = NULL;
    void* l4 = NULL;
    int64_t l3, l5;
    bool l6;
    vader_box_t t0 = vader_box_null();
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[5] = { &l0, &l1, &l2, &l4, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_midir$build_call_graph(l0);
    vader_array_t* _a0_arr = vader_array_new(20u, 0u, 12u, 333u);
    l2 = (void*) _a0_arr;
    l3 = ((vader_array_t*) ((vader_struct_vader_midir$CallGraph_t*) l1)->f_nodes)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l2, (int64_t) l3);
    l2 = (void*) _a1_arr;
    l4 = ((vader_struct_vader_midir$CallGraph_t*) l1)->f_nodes;
    l3 = ((vader_array_t*) l4)->length;
    l5 = INT64_C(0);
    while ((l5 < l3)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        t0 = vader_array_ref_load_box(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l5);
        l6 = vader_midir$node_shrinks_by_itself(t0);
        vader_array_push_bool((vader_array_t*) l2, l6);
        l5 = (l5 + INT64_C(1));
    }
    vader_support_fixpoint$solve_reachability(((vader_struct_vader_midir$CallGraph_t*) l1)->f_graph, l2);
    vader_struct_vader_midir$ShrinkSummary_t* _a3_obj = (vader_struct_vader_midir$ShrinkSummary_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$ShrinkSummary_t));
    vader_obj_header_init(_a3_obj, 1376u);
    _a3_obj->f_calls = l1;
    _a3_obj->f_may_shrink = l2;
    t1 = (void*) _a3_obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_box_t vader_midir$taken_function(vader_box_t l0) {
    if ((l0.tag == 1357u || l0.tag == 1358u || l0.tag == 1362u)) {
        return vader_ref_box(VADER_UNION_FIELD(void*, vader_struct_vader_midir$InstrFnAddr_t, f_fn_symbol, l0.payload.obj));
    }
    if (!((l0.tag == 1338u || l0.tag == 1339u || l0.tag == 1340u || l0.tag == 1341u || l0.tag == 1342u || l0.tag == 1343u || l0.tag == 1344u || l0.tag == 1345u || l0.tag == 1346u || l0.tag == 1347u || l0.tag == 1348u || l0.tag == 1349u || l0.tag == 1350u || l0.tag == 1351u || l0.tag == 1352u || l0.tag == 1353u || l0.tag == 1354u || l0.tag == 1355u || l0.tag == 1356u || l0.tag == 1359u || l0.tag == 1360u || l0.tag == 1361u || l0.tag == 1363u || l0.tag == 1364u || l0.tag == 1365u || l0.tag == 1366u || l0.tag == 1368u || l0.tag == 1369u || l0.tag == 1367u || l0.tag == 1370u))) {
        vader_unreachable("non-exhaustive match (T3013 should have caught this)");
    }
    return vader_box_obj(0u, NULL);
}

static int32_t vader_midir$taken_node(void* l0, void* l1) {
    vader_box_t l2;
    int32_t t0;
    l2 = vader_midir$function_called(((vader_struct_vader_midir$SlotTypes_t*) ((vader_struct_vader_midir$CfgResolution_t*) ((vader_struct_vader_midir$CalleeIndex_t*) l0)->f_resolution)->f_slots)->f_callees, l1);
    if (l2.tag == 0u) {
        t0 = ((vader_struct_vader_midir$CalleeIndex_t*) l0)->f_unknown;
        return t0;
    }
    t0 = ((int32_t) l2.payload.i);
    return t0;
}

vader_box_t vader_midir$term_return_single(void* l0) {
    int64_t t0;
    int32_t t1;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) l0)->f_values)->length;
    if (!(t0 != INT64_C(1))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) l0)->f_values);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        return vader_box_i32(338u, t1);
    }
    return vader_box_obj(0u, NULL);
}

static void vader_midir$terminate(void* l0, vader_box_t l1) {
    void* l2;
    int64_t l3;
    vader_box_t l4;
    if (((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.tag == 0u) {
        return;
    }
    l2 = ((vader_struct_vader_midir$FnCtx_t*) l0)->f_blocks;
    l3 = ((int64_t) ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current.payload.i);
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
    l2 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l3);
    if (((vader_struct_vader_midir$MutableBlock_t*) l2)->f_terminator.tag == 0u) {
        ((vader_struct_vader_midir$MutableBlock_t*) l2)->f_terminator = l1;
        VADER_WRITE_BARRIER((vader_struct_vader_midir$MutableBlock_t*) l2);
        l4 = vader_box_obj(0u, NULL);
        ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = l4;
        return;
    }
    l4 = vader_box_obj(0u, NULL);
    ((vader_struct_vader_midir$FnCtx_t*) l0)->f_current = l4;
    return;
}

static vader_box_t vader_midir$type_at(void* l0, int64_t l1) {
    int64_t l2;
    vader_box_t t0;
    l2 = ((vader_array_t*) l0)->length;
    if (!((l1 >= l2))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = vader_array_ref_load_box(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l1);
        return t0;
    }
    return vader_box_obj(0u, NULL);
}

static bool vader_midir$verify_block_ids(void* l0, vader_string_t l1, void* l2) {
    int32_t l3, l11, l12, l25;
    bool l4;
    void* l5 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l16 = NULL;
    void* l21 = NULL;
    void* l22 = NULL;
    void* l26 = NULL;
    void* l29 = NULL;
    void* l35 = NULL;
    int64_t l6, l7, l8, l10, l15, l17, l18, l19, l23, l24, l28, l30, l31, l32, l33;
    vader_string_t l14 = 0;
    vader_string_t l20 = 0;
    vader_string_t l27 = 0;
    vader_string_t l34 = 0;
    int64_t t0;
    bool t1;
    void** gc_raw_roots[11] = { &l0, &l2, &l5, &l9, &l13, &l16, &l21, &l22, &l26, &l29, &l35 };
    vader_string_t* gc_atom_roots[5] = { &l1, &l14, &l20, &l27, &l34 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 11u, NULL, gc_raw_roots, 0u, NULL, 5u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks)->length;
    l3 = ((int32_t) (int64_t) t0);
    l4 = true;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l6 = INT64_C(0);
    l7 = ((vader_array_t*) l5)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l9 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l8);
        l10 = l6;
        l11 = ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_id;
        l12 = ((int32_t) (int64_t) l10);
        t1 = vader_midir$BlockId$std_core$Equals$equals(l11, l12);
        if (!(t1)) {
            l13 = ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_span;
            l14 = l1;
            l15 = vader_host_std_core$byte_len(l14);
            l16 = (void*) vader_buffer_new((size_t) (INT64_C(71) + l15));
            l17 = INT64_C(0);
            l17 = std_core$write_string_at(l16, l17, l14);
            l17 = std_core$write_string_at(l16, l17, 470u);
            l18 = ((int64_t) (int32_t) ((int32_t) (int64_t) l10));
            l17 = std_core$write_int(l16, l17, l18);
            l17 = std_core$write_string_at(l16, l17, 109u);
            l19 = ((int64_t) (int32_t) ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_id);
            l17 = std_core$write_int(l16, l17, l19);
            l20 = std_core$finish_buffer(l16, l17);
            l21 = vader_support_diagnostics$internal_error((uint8_t) 3, l13, l20);
            vader_array_push_ref((vader_array_t*) l2, l21);
            l4 = false;
        }
        l22 = vader_midir$successors_of(l9);
        l23 = ((vader_array_t*) l22)->length;
        l24 = INT64_C(0);
        while ((l24 < l23)) {
            vader_array_t* _a1_slotarr = ((vader_array_t*) l22);
            VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
            l25 = ((int32_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l24];
            if ((l25 >= INT32_C(0))) {
                if ((l25 < l3)) {
                    l24 = (l24 + INT64_C(1));
                    continue;
                }
            }
            l26 = ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_span;
            l27 = l1;
            l28 = vader_host_std_core$byte_len(l27);
            l29 = (void*) vader_buffer_new((size_t) (INT64_C(103) + l28));
            l30 = INT64_C(0);
            l30 = std_core$write_string_at(l29, l30, l27);
            l30 = std_core$write_string_at(l29, l30, 469u);
            l31 = ((int64_t) (int32_t) ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_id);
            l30 = std_core$write_int(l29, l30, l31);
            l30 = std_core$write_string_at(l29, l30, 99u);
            l32 = ((int64_t) (int32_t) l25);
            l30 = std_core$write_int(l29, l30, l32);
            l30 = std_core$write_string_at(l29, l30, 370u);
            l33 = ((int64_t) (int32_t) l3);
            l30 = std_core$write_int(l29, l30, l33);
            l30 = std_core$write_string_at(l29, l30, 98u);
            l34 = std_core$finish_buffer(l29, l30);
            l35 = vader_support_diagnostics$internal_error((uint8_t) 3, l26, l34);
            vader_array_push_ref((vader_array_t*) l2, l35);
            l4 = false;
            l24 = (l24 + INT64_C(1));
        }
        l6 = vader_chk_add(i64, l6, INT64_C(1));
        l8 = (l8 + INT64_C(1));
    }
    { bool __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_midir$verify_cfg(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    int64_t l7, l8, l9, l10;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1 = 0;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[7] = { &l0, &l2, &l3, &l4, &l5, &l6, &t2 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 7u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l3 = vader_midir$build_cfg_resolution(l0);
    l4 = ((vader_struct_vader_midir$CFGProject_t*) l0)->f_modules;
    l5 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l4)->f_ekeys;
    l6 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l4)->f_evals;
    l7 = INT64_C(0);
    l8 = ((vader_struct_std_collections$MutableMap__string__vader_midir_CFGModule_t*) l4)->f_size;
    while ((l7 < l8)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l7)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) l7];
        t1 = t0.payload.s;
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l7)
        t2 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l7);
        l4 = ((vader_struct_vader_midir$CFGModule_t*) t2)->f_functions;
        l9 = ((vader_array_t*) l4)->length;
        l10 = INT64_C(0);
        while ((l10 < l9)) {
            vader_array_t* _a2_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
            VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l10)
            t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l10);
            vader_midir$verify_cfg_function(t2, l3, l1, l2);
            l10 = (l10 + INT64_C(1));
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$verify_cfg_function(void* l0, void* l1, vader_string_t l2, void* l3) {
    vader_string_t l4 = 0;
    vader_string_t l6 = 0;
    void* l5 = NULL;
    void* l8 = NULL;
    int64_t l7, l9;
    bool l10;
    bool t0;
    int64_t t1;
    void** gc_raw_roots[5] = { &l0, &l1, &l3, &l5, &l8 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l4, &l6 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_mangled;
    l4 = concat_5(1509u, l2, 1288u, l4, 1035u);
    t0 = vader_midir$BlockId$std_core$Equals$equals(((vader_struct_vader_midir$CFGFunction_t*) l0)->f_entry, INT32_C(0));
    if (!(t0)) {
        l5 = vader_midir$fn_span(l0);
        l6 = l4;
        l7 = vader_host_std_core$byte_len(l6);
        l8 = (void*) vader_buffer_new((size_t) (INT64_C(33) + l7));
        l7 = INT64_C(0);
        l7 = std_core$write_string_at(l8, l7, l6);
        l7 = std_core$write_string_at(l8, l7, 475u);
        l9 = ((int64_t) (int32_t) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_entry);
        l7 = std_core$write_int(l8, l7, l9);
        l6 = std_core$finish_buffer(l8, l7);
        l5 = vader_support_diagnostics$internal_error((uint8_t) 6, l5, l6);
        vader_array_push_ref((vader_array_t*) l3, l5);
    }
    t0 = vader_midir$verify_block_ids(l0, l4, l3);
    if (t0) {
        l5 = vader_midir$reachable_blocks(l0);
    } else {
        l5 = vader_midir$all_blocks(l0);
    }
    l7 = ((vader_array_t*) l3)->length;
    vader_midir$verify_locals(l0, l5, l4, l3);
    t1 = ((vader_array_t*) l3)->length;
    l10 = t1 == l7;
    vader_midir$verify_fn_references(l0, l1, l5, l4, l3);
    vader_midir$verify_return_arity(l0, l5, l4, l3);
    if (l10) {
        vader_midir$verify_storage(l0, l1, l5, l4, l3);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$verify_fn_references(void* l0, void* l1, void* l2, vader_string_t l3, void* l4) {
    void* l5 = NULL;
    void* l8 = NULL;
    void* l10 = NULL;
    void* l14 = NULL;
    void* l15 = NULL;
    void* l21 = NULL;
    void* l25 = NULL;
    void* l26 = NULL;
    void* l27 = NULL;
    void* l28 = NULL;
    void* l37 = NULL;
    void* l41 = NULL;
    int64_t l6, l7, l11, l12, l18, l19, l20, l22, l23, l32, l33, l34, l35, l36, l38, l39;
    int32_t l9;
    vader_box_t l13 = vader_box_null();
    vader_string_t l16 = 0;
    vader_string_t l17 = 0;
    vader_string_t l24 = 0;
    vader_string_t l29 = 0;
    vader_string_t l30 = 0;
    vader_string_t l31 = 0;
    vader_string_t l40 = 0;
    bool t0;
    void* t1 = NULL;
    int32_t t2;
    vader_box_t t3 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l13, &t3 };
    void** gc_raw_roots[17] = {
        &l0, &l1, &l2, &l4, &l5, &l8, &l10, &l14, &l15, &l21, &l25, &l26, &l27, &l28, &l37, &l41,
        &t1,
    };
    vader_string_t* gc_atom_roots[8] = { &l3, &l16, &l17, &l24, &l29, &l30, &l31, &l40 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 17u, gc_roots, gc_raw_roots, 0u, NULL, 8u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_id;
        t0 = std_collections$MutableSet$std_core$Contains$contains__i32(l2, l9);
        if (t0) {
            l10 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_instructions;
            l11 = ((vader_array_t*) l10)->length;
            l12 = INT64_C(0);
            while ((l12 < l11)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l10);
                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                l13 = vader_array_ref_load_box(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l12);
                if (l13.tag == 1345u) {
                    t1 = l13.payload.obj;
                    l14 = ((vader_struct_vader_midir$InstrCall_t*) t1)->f_callee;
                    t0 = vader_midir$callee_resolves(l1, l14);
                    if (t0) {
                        l12 = (l12 + INT64_C(1));
                        continue;
                    }
                    t1 = l13.payload.obj;
                    l15 = ((vader_struct_vader_midir$InstrCall_t*) t1)->f_span;
                    l16 = l3;
                    t1 = l13.payload.obj;
                    l17 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) t1)->f_callee)->f_name;
                    l18 = vader_host_std_core$byte_len(l16);
                    l19 = vader_host_std_core$byte_len(l17);
                    l20 = (l18 + l19);
                    l21 = (void*) vader_buffer_new((size_t) (INT64_C(78) + l20));
                    l22 = INT64_C(0);
                    l22 = std_core$write_string_at(l21, l22, l16);
                    l22 = std_core$write_string_at(l21, l22, 471u);
                    l22 = std_core$write_string_at(l21, l22, l17);
                    l22 = std_core$write_string_at(l21, l22, 1043u);
                    t1 = l13.payload.obj;
                    t2 = ((vader_struct_vader_core_symbol$Symbol_t*) ((vader_struct_vader_midir$InstrCall_t*) t1)->f_callee)->f_id;
                    l23 = ((int64_t) (int32_t) t2);
                    l22 = std_core$write_int(l21, l22, l23);
                    l22 = std_core$write_string_at(l21, l22, 337u);
                    l24 = std_core$finish_buffer(l21, l22);
                    l25 = vader_support_diagnostics$internal_error((uint8_t) 1, l15, l24);
                    vader_array_push_ref((vader_array_t*) l4, l25);
                } else if ((l13.tag == 1357u || l13.tag == 1358u || l13.tag == 1362u)) {
                    l26 = ((vader_struct_vader_midir$SlotTypes_t*) ((vader_struct_vader_midir$CfgResolution_t*) l1)->f_slots)->f_callees;
                    l27 = VADER_UNION_FIELD(void*, vader_struct_vader_midir$InstrFnAddr_t, f_fn_symbol, l13.payload.obj);
                    t3 = vader_midir$function_called(l26, l27);
                    if (t3.tag == 0u) {
                        l28 = VADER_UNION_FIELD(void*, vader_struct_vader_midir$InstrFnAddr_t, f_span, l13.payload.obj);
                        l29 = l3;
                        l30 = vader_midir$fn_value_kind(l13);
                        l31 = ((vader_struct_vader_core_symbol$Symbol_t*) VADER_UNION_FIELD(void*, vader_struct_vader_midir$InstrFnAddr_t, f_fn_symbol, l13.payload.obj))->f_name;
                        l32 = vader_host_std_core$byte_len(l29);
                        l33 = vader_host_std_core$byte_len(l30);
                        l34 = (l32 + l33);
                        l35 = vader_host_std_core$byte_len(l31);
                        l36 = (l34 + l35);
                        l37 = (void*) vader_buffer_new((size_t) (INT64_C(58) + l36));
                        l38 = INT64_C(0);
                        l38 = std_core$write_string_at(l37, l38, l29);
                        l38 = std_core$write_string_at(l37, l38, 462u);
                        l38 = std_core$write_string_at(l37, l38, l30);
                        l38 = std_core$write_string_at(l37, l38, 85u);
                        l38 = std_core$write_string_at(l37, l38, l31);
                        l38 = std_core$write_string_at(l37, l38, 1043u);
                        t2 = ((vader_struct_vader_core_symbol$Symbol_t*) VADER_UNION_FIELD(void*, vader_struct_vader_midir$InstrFnAddr_t, f_fn_symbol, l13.payload.obj))->f_id;
                        l39 = ((int64_t) (int32_t) t2);
                        l38 = std_core$write_int(l37, l38, l39);
                        l38 = std_core$write_string_at(l37, l38, 338u);
                        l40 = std_core$finish_buffer(l37, l38);
                        l41 = vader_support_diagnostics$internal_error((uint8_t) 1, l28, l40);
                        vader_array_push_ref((vader_array_t*) l4, l41);
                    } else {
                        l12 = (l12 + INT64_C(1));
                        continue;
                    }
                }
                l12 = (l12 + INT64_C(1));
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$verify_locals(void* l0, void* l1, vader_string_t l2, void* l3) {
    int32_t l4, l10, l19;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    void* l15 = NULL;
    void* l20 = NULL;
    void* l23 = NULL;
    void* l24 = NULL;
    void* l26 = NULL;
    int64_t l8, l9, l11, l12, l16, l17;
    vader_box_t l13 = vader_box_null(), l14 = vader_box_null(), l18 = vader_box_null();
    bool l21, l22;
    vader_string_t l25 = 0;
    int64_t t0;
    void* t1 = NULL;
    bool t2;
    int32_t t3;
    vader_box_t* gc_roots[3] = { &l13, &l14, &l18 };
    void** gc_raw_roots[12] = { &l0, &l1, &l3, &l5, &l6, &l7, &l15, &l20, &l23, &l24, &l26, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l2, &l25 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 12u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals)->length;
    l4 = ((int32_t) (int64_t) t0);
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 7u, 338u);
    l5 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(20u, 0u, 12u, 333u);
    l6 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a2_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a3_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a3_obj, 470u);
    _a3_obj->f_ekeys = l5;
    _a3_obj->f_evals = l6;
    _a3_obj->f_index = l7;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t1 = (void*) _a3_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a4_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a4_obj, 613u);
    _a4_obj->f_inner = t1;
    l5 = (void*) _a4_obj;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_params;
    l8 = ((vader_array_t*) l6)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a5_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a5_slotarr)
        t1 = vader_array_ref_load_obj(_a5_slotarr->buf, _a5_slotarr->offset + (size_t) l9);
        l10 = ((vader_struct_vader_midir$CFGParam_t*) t1)->f_local;
        std_collections$add__vader_midir$LocalId(l5, l10);
        l9 = (l9 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l8 = ((vader_array_t*) l6)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t1 = vader_array_ref_load_obj(_a6_slotarr->buf, _a6_slotarr->offset + (size_t) l9);
        l7 = ((vader_struct_vader_midir$BasicBlock_t*) t1)->f_instructions;
        l11 = ((vader_array_t*) l7)->length;
        l12 = INT64_C(0);
        while ((l12 < l11)) {
            vader_array_t* _a7_slotarr = ((vader_array_t*) l7);
            VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
            l13 = vader_array_ref_load_box(_a7_slotarr->buf, _a7_slotarr->offset + (size_t) l12);
            l14 = vader_midir$multi_dsts(l13);
            if (l14.tag == 0u) {
                l18 = vader_midir$dst_of(l13);
                if (!(l18.tag == 0u)) {
                    l19 = ((int32_t) l18.payload.i);
                    std_collections$add__vader_midir$LocalId(l5, l19);
                }
            } else {
                l15 = l14.payload.obj;
                l16 = ((vader_array_t*) l15)->length;
                l17 = INT64_C(0);
                while ((l17 < l16)) {
                    vader_array_t* _a8_slotarr = ((vader_array_t*) l15);
                    VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
                    l10 = ((int32_t*) _a8_slotarr->buf->slots)[_a8_slotarr->offset + (size_t) l17];
                    std_collections$add__vader_midir$LocalId(l5, l10);
                    l17 = (l17 + INT64_C(1));
                }
            }
            l12 = (l12 + INT64_C(1));
        }
        l9 = (l9 + INT64_C(1));
    }
    vader_array_t* _a9_arr = vader_array_new(23u, 0u, 7u, 338u);
    l6 = (void*) _a9_arr;
    vader_array_t* _a10_arr = vader_array_new(20u, 0u, 12u, 333u);
    l7 = (void*) _a10_arr;
    vader_array_t* _a11_arr = vader_array_new(23u, 0u, 7u, 338u);
    l15 = (void*) _a11_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a12_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a12_obj, 470u);
    _a12_obj->f_ekeys = l6;
    _a12_obj->f_evals = l7;
    _a12_obj->f_index = l15;
    _a12_obj->f_mask = INT64_C(0);
    _a12_obj->f_grow_at = INT64_C(0);
    _a12_obj->f_size = INT64_C(0);
    _a12_obj->f_tombs = INT64_C(0);
    t1 = (void*) _a12_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a13_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a13_obj, 613u);
    _a13_obj->f_inner = t1;
    l6 = (void*) _a13_obj;
    vader_array_t* _a14_arr = vader_array_new(23u, 0u, 7u, 338u);
    l7 = (void*) _a14_arr;
    vader_array_t* _a15_arr = vader_array_new(20u, 0u, 12u, 333u);
    l15 = (void*) _a15_arr;
    vader_array_t* _a16_arr = vader_array_new(23u, 0u, 7u, 338u);
    l20 = (void*) _a16_arr;
    vader_struct_std_collections$MutableMap__i32__bool_t* _a17_obj = (vader_struct_std_collections$MutableMap__i32__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableMap__i32__bool_t));
    vader_obj_header_init(_a17_obj, 470u);
    _a17_obj->f_ekeys = l7;
    _a17_obj->f_evals = l15;
    _a17_obj->f_index = l20;
    _a17_obj->f_mask = INT64_C(0);
    _a17_obj->f_grow_at = INT64_C(0);
    _a17_obj->f_size = INT64_C(0);
    _a17_obj->f_tombs = INT64_C(0);
    t1 = (void*) _a17_obj;
    vader_struct_std_collections$MutableSet__i32_t* _a18_obj = (vader_struct_std_collections$MutableSet__i32_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$MutableSet__i32_t));
    vader_obj_header_init(_a18_obj, 613u);
    _a18_obj->f_inner = t1;
    l7 = (void*) _a18_obj;
    vader_struct___lambda_env_vader_midir_15_t* _a19_obj = (vader_struct___lambda_env_vader_midir_15_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_15_t));
    vader_obj_header_init(_a19_obj, 436u);
    _a19_obj->f_cap_0 = l4;
    _a19_obj->f_cap_1 = l6;
    _a19_obj->f_cap_2 = l3;
    _a19_obj->f_cap_3 = l2;
    _a19_obj->f_cap_4 = l5;
    _a19_obj->f_cap_5 = l7;
    _a19_obj->f_cap_6 = l0;
    t1 = (void*) _a19_obj;
    vader_fn_t* _a20_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a20_closure, 308u);
    _a20_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_14;
    _a20_closure->env = t1;
    l5 = (void*) _a20_closure;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l8 = ((vader_array_t*) l6)->length;
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a21_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a21_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a21_slotarr, l9)
        l7 = vader_array_ref_load_obj(_a21_slotarr->buf, _a21_slotarr->offset + (size_t) l9);
        l10 = ((vader_struct_vader_midir$BasicBlock_t*) l7)->f_id;
        t2 = std_collections$MutableSet$std_core$Contains$contains__i32(l1, l10);
        if (t2) {
            l15 = ((vader_struct_vader_midir$BasicBlock_t*) l7)->f_instructions;
            l11 = ((vader_array_t*) l15)->length;
            l12 = INT64_C(0);
            while ((l12 < l11)) {
                vader_array_t* _a22_slotarr = ((vader_array_t*) l15);
                VADER_ARRAY_RESOLVE_BUF(_a22_slotarr)
                VADER_ARRAY_CHECK_INDEX(_a22_slotarr, l12)
                l13 = vader_array_ref_load_box(_a22_slotarr->buf, _a22_slotarr->offset + (size_t) l12);
                vader_struct___lambda_env_vader_midir_17_t* _a23_obj = (vader_struct___lambda_env_vader_midir_17_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_17_t));
                vader_obj_header_init(_a23_obj, 437u);
                _a23_obj->f_cap_0 = l5;
                _a23_obj->f_cap_1 = l13;
                _a23_obj->f_cap_2 = l7;
                t1 = (void*) _a23_obj;
                vader_fn_t* _a24_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
                vader_obj_header_init(_a24_closure, 305u);
                _a24_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_16;
                _a24_closure->env = t1;
                l20 = (void*) _a24_closure;
                vader_midir$for_each_read_local(l13, l20);
                l14 = vader_midir$dst_of(l13);
                if (!(l14.tag == 0u)) {
                    t3 = ((int32_t) l14.payload.i);
                    if ((t3 < INT32_C(0))) {
                        l22 = true;
                    } else {
                        t3 = ((int32_t) l14.payload.i);
                        l22 = (t3 >= l4);
                    }
                    l21 = l22;
                } else {
                    l21 = false;
                }
                if (l21) {
                    l19 = ((int32_t) l14.payload.i);
                    l23 = VADER_UNION_FIELD(void*, vader_struct_vader_midir$InstrArrayGet_t, f_span, l13.payload.obj);
                    l24 = (void*) vader_buffer_new((size_t) INT64_C(22));
                    l16 = INT64_C(0);
                    l16 = std_core$write_string_at(l24, l16, 1613u);
                    l17 = ((int64_t) (int32_t) ((vader_struct_vader_midir$BasicBlock_t*) l7)->f_id);
                    l16 = std_core$write_int(l24, l16, l17);
                    l25 = std_core$finish_buffer(l24, l16);
                    vader_fn_t* _a25_fnobj = (vader_fn_t*) l5;
                    ((vader_fn_erased_sig_3_t) _a25_fnobj->code)(_a25_fnobj->env, vader_box_i32(338u, l19), vader_ref_box(l23), vader_box_string(335u, l25));
                }
                l12 = (l12 + INT64_C(1));
            }
            l18 = ((vader_struct_vader_midir$BasicBlock_t*) l7)->f_terminator;
            vader_struct___lambda_env_vader_midir_19_t* _a26_obj = (vader_struct___lambda_env_vader_midir_19_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_midir_19_t));
            vader_obj_header_init(_a26_obj, 438u);
            _a26_obj->f_cap_0 = l5;
            _a26_obj->f_cap_1 = l7;
            t1 = (void*) _a26_obj;
            vader_fn_t* _a27_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
            vader_obj_header_init(_a27_closure, 305u);
            _a27_closure->code = (void*) &vader_fn_lift___lambda_vader_midir_18;
            _a27_closure->env = t1;
            l26 = (void*) _a27_closure;
            vader_midir$for_each_read_in_terminator(l18, l26);
            l9 = (l9 + INT64_C(1));
            continue;
        }
        l9 = (l9 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$verify_return_arity(void* l0, void* l1, vader_string_t l2, void* l3) {
    int64_t l4, l6, l7, l14, l16, l17, l18;
    void* l5 = NULL;
    void* l8 = NULL;
    void* l11 = NULL;
    void* l12 = NULL;
    void* l15 = NULL;
    void* l20 = NULL;
    int32_t l9;
    vader_box_t l10 = vader_box_null();
    vader_string_t l13 = 0;
    vader_string_t l19 = 0;
    int64_t t0;
    bool t1;
    void* t2 = NULL;
    vader_box_t* gc_roots[1] = { &l10 };
    void** gc_raw_roots[10] = { &l0, &l1, &l3, &l5, &l8, &l11, &l12, &l15, &l20, &t2 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l13, &l19 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 10u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_scalarised_results)->length;
    if ((t0 > INT64_C(1))) {
        l4 = ((vader_array_t*) ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_scalarised_results)->length;
    } else {
        t1 = vader_core_types$is_void(((vader_struct_vader_midir$CFGFunction_t*) l0)->f_return_type);
        if (t1) {
            l4 = INT64_C(0);
        } else {
            l4 = INT64_C(1);
        }
    }
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l8 = vader_array_ref_load_obj(_a0_slotarr->buf, _a0_slotarr->offset + (size_t) l7);
        l9 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_id;
        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l1, l9);
        if (t1) {
            l10 = ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_terminator;
            if (l10.tag == 1382u) {
                t2 = l10.payload.obj;
                t0 = ((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) t2)->f_values)->length;
                if (!(t0 == INT64_C(0))) {
                    t2 = l10.payload.obj;
                    t0 = ((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) t2)->f_values)->length;
                    if (!(t0 == l4)) {
                        t2 = l10.payload.obj;
                        l11 = ((vader_struct_vader_midir$TermReturn_t*) t2)->f_values;
                        t1 = vader_midir$returns_only_never(l0, l11);
                        if (t1) {
                            l7 = (l7 + INT64_C(1));
                            continue;
                        }
                        t2 = l10.payload.obj;
                        l12 = ((vader_struct_vader_midir$TermReturn_t*) t2)->f_span;
                        l13 = l2;
                        l14 = vader_host_std_core$byte_len(l13);
                        l15 = (void*) vader_buffer_new((size_t) (INT64_C(107) + l14));
                        l16 = INT64_C(0);
                        l16 = std_core$write_string_at(l15, l16, l13);
                        l16 = std_core$write_string_at(l15, l16, 469u);
                        l17 = ((int64_t) (int32_t) ((vader_struct_vader_midir$BasicBlock_t*) l8)->f_id);
                        l16 = std_core$write_int(l15, l16, l17);
                        l16 = std_core$write_string_at(l15, l16, 210u);
                        t2 = l10.payload.obj;
                        l18 = ((vader_array_t*) ((vader_struct_vader_midir$TermReturn_t*) t2)->f_values)->length;
                        l16 = std_core$write_int(l15, l16, l18);
                        l16 = std_core$write_string_at(l15, l16, 230u);
                        l16 = std_core$write_int(l15, l16, l4);
                        l19 = std_core$finish_buffer(l15, l16);
                        l20 = vader_support_diagnostics$internal_error((uint8_t) 8, l12, l19);
                        vader_array_push_ref((vader_array_t*) l3, l20);
                        l7 = (l7 + INT64_C(1));
                        continue;
                    }
                }
                l7 = (l7 + INT64_C(1));
                continue;
            }
            l7 = (l7 + INT64_C(1));
            continue;
        }
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void vader_midir$verify_storage(void* l0, void* l1, void* l2, vader_string_t l3, void* l4) {
    void* l5 = NULL;
    void* l6 = NULL;
    void* l9 = NULL;
    void* l13 = NULL;
    void* l14 = NULL;
    int64_t l7, l8, l16, l17;
    vader_string_t l10 = 0;
    vader_string_t l11 = 0;
    vader_string_t l12 = 0;
    int32_t l15;
    vader_box_t l18 = vader_box_null(), l19 = vader_box_null();
    vader_box_t t0 = vader_box_null();
    bool t1;
    vader_box_t* gc_roots[3] = { &l18, &l19, &t0 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l4, &l5, &l6, &l9, &l13, &l14 };
    vader_string_t* gc_atom_roots[4] = { &l3, &l10, &l11, &l12 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 3u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 4u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l5 = ((vader_struct_vader_midir$CfgResolution_t*) l1)->f_slots;
    vader_struct_vader_midir$StorageCheck_t* _a0_obj = (vader_struct_vader_midir$StorageCheck_t*) vader_gc_alloc(sizeof(vader_struct_vader_midir$StorageCheck_t));
    vader_obj_header_init(_a0_obj, 1378u);
    _a0_obj->f_function = l0;
    _a0_obj->f_slots = l5;
    _a0_obj->f_where = l3;
    _a0_obj->f_diags = l4;
    l5 = (void*) _a0_obj;
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_locals;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        l9 = vader_array_ref_load_obj(_a1_slotarr->buf, _a1_slotarr->offset + (size_t) l8);
        t0 = vader_core_types$free_member(((vader_struct_vader_midir$CFGLocal_t*) l9)->f_type);
        if (!(t0.tag == 0u)) {
            l10 = ((vader_struct_vader_midir$CFGLocal_t*) l9)->f_name;
            l11 = vader_core_types$display_type(((vader_struct_vader_midir$CFGLocal_t*) l9)->f_type);
            l12 = concat_6(l3, 496u, l10, 1114u, l11, 1035u);
            l13 = vader_midir$fn_span(l0);
            l14 = vader_support_diagnostics$internal_error((uint8_t) 11, l13, l12);
            vader_array_push_ref((vader_array_t*) l4, l14);
        }
        l8 = (l8 + INT64_C(1));
    }
    l6 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l7 = ((vader_array_t*) l6)->length;
    l8 = INT64_C(0);
    while ((l8 < l7)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l9 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l8);
        l15 = ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_id;
        t1 = std_collections$MutableSet$std_core$Contains$contains__i32(l2, l15);
        if (t1) {
            l13 = ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_instructions;
            l16 = ((vader_array_t*) l13)->length;
            l17 = INT64_C(0);
            while ((l17 < l16)) {
                vader_array_t* _a3_slotarr = ((vader_array_t*) l13);
                VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
                l18 = vader_array_ref_load_box(_a3_slotarr->buf, _a3_slotarr->offset + (size_t) l17);
                vader_midir$check_instruction_storage(l5, l18);
                l17 = (l17 + INT64_C(1));
            }
            l19 = ((vader_struct_vader_midir$BasicBlock_t*) l9)->f_terminator;
            if (l19.tag == 1382u) {
                l14 = l19.payload.obj;
                vader_midir$check_return_storage(l5, l14);
            }
            l8 = (l8 + INT64_C(1));
            continue;
        }
        l8 = (l8 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* vader_midir$virtual_callees(void* l0, void* l1) {
    void* l2 = NULL;
    vader_string_t l3 = 0;
    vader_string_t l4 = 0;
    vader_box_t l5 = vader_box_null();
    int32_t t0;
    void* t1 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t1 };
    vader_string_t* gc_atom_roots[2] = { &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_vader_midir$CalleeIndex_t*) l0)->f_virtual_targets;
    l3 = ((vader_struct_vader_midir$InstrVirtualCall_t*) l1)->f_trait_name;
    l4 = ((vader_struct_vader_midir$InstrVirtualCall_t*) l1)->f_method;
    l3 = vader_midir$vtable_key(l3, l4);
    l5 = std_collections$MutableMap$std_core$Index$at__string__Any(l2, l3);
    if (l5.tag == 0u) {
        t0 = ((vader_struct_vader_midir$CalleeIndex_t*) l0)->f_unknown;
        vader_array_t* _a0_arr = vader_array_new(23u, 1u, 7u, 338u);
        ((int32_t*) _a0_arr->buf->slots)[_a0_arr->offset + 0u] = (int32_t) t0;
        t1 = (void*) _a0_arr;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t1 = l5.payload.obj;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_midir$vtable_key(vader_string_t l0, vader_string_t l1) {
    vader_string_t t0;
    t0 = concat_3(l0, 399u, l1);
    return t0;
}

static void vader_midir$walk_rpo(void* l0, int32_t l1, void* l2, void* l3) {
    int32_t l4;
    void* l5 = NULL;
    int64_t l6, l7;
    bool t0, t1;
    void* t2 = NULL;
    void** gc_raw_roots[5] = { &l0, &l2, &l3, &l5, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 5u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l4 = l1;
    vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
    t0 = ((uint8_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l4];
    t1 = t0;
    if (t1) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l4 = l1;
    vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l4)
    ((uint8_t*) _a1_slotarr->buf->slots)[_a1_slotarr->offset + (size_t) l4] = (uint8_t) true;
    l5 = ((vader_struct_vader_midir$CFGFunction_t*) l0)->f_blocks;
    l4 = l1;
    vader_array_t* _a2_slotarr = ((vader_array_t*) l5);
    VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a2_slotarr, l4)
    t2 = vader_array_ref_load_obj(_a2_slotarr->buf, _a2_slotarr->offset + (size_t) l4);
    l5 = vader_midir$successors_of(t2);
    l6 = ((vader_array_t*) l5)->length;
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a3_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a3_slotarr)
        l4 = ((int32_t*) _a3_slotarr->buf->slots)[_a3_slotarr->offset + (size_t) l7];
        vader_midir$walk_rpo(l0, l4, l2, l3);
        l7 = (l7 + INT64_C(1));
    }
    vader_array_push_i32((vader_array_t*) l3, l1);
    { vader_gc_top = gc_frame.prev; return; }
}

bool vader_midir$writes_local(vader_box_t l0, int32_t l1) {
    vader_box_t l2;
    void* t0;
    bool t1;
    int32_t t2;
    l2 = vader_midir$multi_dsts(l0);
    if (!(l2.tag == 0u)) {
        t0 = l2.payload.obj;
        t1 = std_core$$array$Contains$contains__i32(t0, l1);
        return t1;
    }
    l2 = vader_midir$dst_of(l0);
    if (l2.tag == 0u) {
        return false;
    }
    t2 = ((int32_t) l2.payload.i);
    t1 = vader_midir$LocalId$std_core$Equals$equals(t2, l1);
    return t1;
}
