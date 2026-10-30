#include "bootstrap.split.h"

vader_box_t vader_core_mono$stub_decl_for(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    vader_string_t l2 = 0;
    void* t0 = NULL;
    void** gc_raw_roots[7] = { &l0, &l1, &l3, &l4, &l5, &l6, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 7u, NULL, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (!(((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_kind == INT32_C(1))) {
        l1 = toolchain_span$empty_span();
        l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
        l3 = toolchain_span$empty_span();
        vader_array_t* _a0_arr = vader_array_new(56u, 0u, 13u, 711u);
        l4 = (void*) _a0_arr;
        vader_array_t* _a1_arr = vader_array_new(46u, 0u, 13u, 659u);
        l5 = (void*) _a1_arr;
        vader_array_t* _a2_arr = vader_array_new(42u, 0u, 13u, 641u);
        l6 = (void*) _a2_arr;
        vader_struct_toolchain_ast$FnDecl_t* _a3_obj = (vader_struct_toolchain_ast$FnDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$FnDecl_t));
        vader_obj_header_init(_a3_obj, 658u);
        _a3_obj->f_span = l1;
        _a3_obj->f_id = INT64_C(0);
        _a3_obj->f_name = l2;
        _a3_obj->f_name_span = l3;
        _a3_obj->f_visibility = (uint8_t) 1;
        _a3_obj->f_type_params = l4;
        _a3_obj->f_params = l5;
        _a3_obj->f_return_type = vader_box_obj(0u, NULL);
        _a3_obj->f_body = vader_box_obj(0u, NULL);
        _a3_obj->f_decorators = l6;
        _a3_obj->f_sam_synthetic = false;
        _a3_obj->f_is_expression_bodied = false;
        _a3_obj->f_materialized = false;
        _a3_obj->f_comptime_synthetic = false;
        _a3_obj->f_trailing_comma = false;
        _a3_obj->f_doc = vader_box_obj(0u, NULL);
        _a3_obj->f_inherits = vader_box_obj(0u, NULL);
        t0 = (void*) _a3_obj;
        { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = toolchain_span$empty_span();
    l2 = ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_name;
    l3 = toolchain_span$empty_span();
    vader_array_t* _a4_arr = vader_array_new(56u, 0u, 13u, 711u);
    l4 = (void*) _a4_arr;
    vader_array_t* _a5_arr = vader_array_new(52u, 0u, 13u, 702u);
    l5 = (void*) _a5_arr;
    vader_array_t* _a6_arr = vader_array_new(42u, 0u, 13u, 641u);
    l6 = (void*) _a6_arr;
    vader_struct_toolchain_ast$StructDecl_t* _a7_obj = (vader_struct_toolchain_ast$StructDecl_t*) vader_gc_alloc(sizeof(vader_struct_toolchain_ast$StructDecl_t));
    vader_obj_header_init(_a7_obj, 701u);
    _a7_obj->f_span = l1;
    _a7_obj->f_id = INT64_C(0);
    _a7_obj->f_name = l2;
    _a7_obj->f_name_span = l3;
    _a7_obj->f_visibility = (uint8_t) 1;
    _a7_obj->f_type_params = l4;
    _a7_obj->f_fields = l5;
    _a7_obj->f_decorators = l6;
    _a7_obj->f_doc = vader_box_obj(0u, NULL);
    t0 = (void*) _a7_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}
