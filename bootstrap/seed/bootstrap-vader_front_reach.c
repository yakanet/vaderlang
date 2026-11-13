#include "bootstrap.split.h"

void* vader_front_reach$bfs_reachable(void* l0, void* l1, void* l2) {
    void* l3 = NULL;
    void* l4 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l8, l9, l12, l13;
    vader_string_t l10 = 0;
    vader_string_t l14 = 0;
    vader_box_t l11 = vader_box_null();
    void* t0 = NULL;
    vader_box_t t1 = vader_box_null();
    bool t2;
    vader_box_t* gc_roots[2] = { &l11, &t1 };
    void** gc_raw_roots[9] = { &l0, &l1, &l2, &l3, &l4, &l5, &l6, &l7, &t0 };
    vader_string_t* gc_atom_roots[2] = { &l10, &l14 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 9u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(26u, 0u, 0u, 499u);
    l3 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(24u, 0u, 12u, 497u);
    l4 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(27u, 0u, 7u, 502u);
    l5 = (void*) _a2_arr;
    vader_struct_std_collections$Map__string__bool_t* _a3_obj = (vader_struct_std_collections$Map__string__bool_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Map__string__bool_t));
    vader_obj_header_init(_a3_obj, 779u);
    _a3_obj->f_ekeys = l3;
    _a3_obj->f_evals = l4;
    _a3_obj->f_index = l5;
    _a3_obj->f_mask = INT64_C(0);
    _a3_obj->f_grow_at = INT64_C(0);
    _a3_obj->f_size = INT64_C(0);
    _a3_obj->f_tombs = INT64_C(0);
    t0 = (void*) _a3_obj;
    vader_struct_std_collections$Set__string_t* _a4_obj = (vader_struct_std_collections$Set__string_t*) vader_gc_alloc(sizeof(vader_struct_std_collections$Set__string_t));
    vader_obj_header_init(_a4_obj, 861u);
    _a4_obj->f_inner = t0;
    l3 = (void*) _a4_obj;
    l5 = l0;
    l6 = l1;
    vader_array_t* _a5_arr = vader_array_new(26u, 0u, 0u, 499u);
    l7 = (void*) _a5_arr;
    l8 = vader_array_length(((vader_array_t*) l5));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a6_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        t1 = vader_array_box_slots(_a6_slotarr->buf)[vader_array_offset(_a6_slotarr) + (size_t) l9];
        l10 = t1.payload.s;
        vader_array_push_scalar((vader_array_t*) l7, vader_box_string(499u, l10));
        l9 = (l9 + INT64_C(1));
    }
    l8 = vader_array_length(((vader_array_t*) l6));
    l9 = INT64_C(0);
    while ((l9 < l8)) {
        vader_array_t* _a7_slotarr = ((vader_array_t*) l6);
        VADER_ARRAY_RESOLVE_BUF(_a7_slotarr)
        t1 = vader_array_box_slots(_a7_slotarr->buf)[vader_array_offset(_a7_slotarr) + (size_t) l9];
        l10 = t1.payload.s;
        vader_array_push_scalar((vader_array_t*) l7, vader_box_string(499u, l10));
        l9 = (l9 + INT64_C(1));
    }
    l4 = l7;
    l8 = INT64_C(0);
    for (;;) {
        l9 = vader_array_length(((vader_array_t*) l4));
        if ((l8 < l9)) {
            vader_array_t* _a8_slotarr = ((vader_array_t*) l4);
            VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
            t1 = vader_array_box_slots(_a8_slotarr->buf)[vader_array_offset(_a8_slotarr) + (size_t) l8];
            l10 = t1.payload.s;
            l8 = vader_chk_add(i64, l8, INT64_C(1));
            t2 = std_collections$add__string(l3, l10);
            if (!(t2)) {
                continue;
            }
            l11 = std_collections$Map$std_core$Index$at__string__string__(l2, l10);
            if (l11.tag == 0u) {
                continue;
            }
            l5 = l11.payload.obj;
            l12 = vader_array_length(((vader_array_t*) l5));
            l13 = INT64_C(0);
            while ((l13 < l12)) {
                vader_array_t* _a9_slotarr = ((vader_array_t*) l5);
                VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
                t1 = vader_array_box_slots(_a9_slotarr->buf)[vader_array_offset(_a9_slotarr) + (size_t) l13];
                l14 = t1.payload.s;
                vader_array_push_scalar((vader_array_t*) l4, vader_box_string(499u, l14));
                l13 = (l13 + INT64_C(1));
            }
            continue;
        }
        break;
    }
    { void* __vret = l3; vader_gc_top = gc_frame.prev; return __vret; }
}

void vader_front_reach$collect_names(vader_box_t l0, void* l1) {
    void* l2 = NULL;
    void* l3 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[4] = { &l1, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct___lambda_env_vader_front_reach_1_t* _a0_obj = (vader_struct___lambda_env_vader_front_reach_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_vader_front_reach_1_t));
    vader_obj_header_init(_a0_obj, 615u);
    _a0_obj->f_cap_0 = l1;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 488u);
    _a1_closure->code = (void*) &vader_fn_lift___lambda_vader_front_reach_0;
    _a1_closure->env = t0;
    l2 = (void*) _a1_closure;
    l3 = (void*) &vader_fn_static_toolchain_ast$ignore_node;
    toolchain_ast$inspect(l0, l2, l3);
    { vader_gc_top = gc_frame.prev; return; }
}

bool vader_front_reach$is_wired_root(void* l0, vader_string_t l1) {
    void* l2;
    void* l5;
    int64_t l3, l4;
    vader_string_t t0;
    if (l1 == 2456u) {
        return true;
    }
    l2 = l0;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l5 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 2896u) {
            return true;
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 2085u) {
            return true;
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 2331u) {
            return true;
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 2072u) {
            return true;
        }
        t0 = ((vader_struct_toolchain_ast$Decorator_t*) l5)->f_name;
        if (t0 == 1634u) {
            return true;
        }
        l4 = (l4 + INT64_C(1));
    }
    return false;
}

uint8_t vader_front_reach$referenced_name(vader_box_t l0, void* l1) {
    vader_string_t l2 = 0;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l0 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[1] = { &l2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 1u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    if (l0.tag == 912u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$IdentExpr_t*) t0)->f_name;
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(499u, l2));
        { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
    }
    if (l0.tag == 905u) {
        t0 = l0.payload.obj;
        l2 = ((vader_struct_toolchain_ast$FieldExpr_t*) t0)->f_field;
        vader_array_push_scalar((vader_array_t*) l1, vader_box_string(499u, l2));
    }
    { vader_gc_top = gc_frame.prev; return (uint8_t) 0; }
}

void vader_front_reach$register_refs(void* l0, vader_string_t l1, void* l2) {
    void* l3 = NULL;
    void* l5 = NULL;
    vader_box_t l4 = vader_box_null();
    int64_t l6, l7;
    vader_string_t l8 = 0;
    vader_box_t t0 = vader_box_null();
    vader_box_t* gc_roots[2] = { &l4, &t0 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l5 };
    vader_string_t* gc_atom_roots[2] = { &l1, &l8 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 2u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l4 = std_collections$put_absent__string__string__(l0, l1, l2);
    if (l4.tag == 0u) {
        { vader_gc_top = gc_frame.prev; return; }
    }
    l3 = l4.payload.obj;
    l5 = l2;
    l6 = vader_array_length(((vader_array_t*) l5));
    l7 = INT64_C(0);
    while ((l7 < l6)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l5);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_box_slots(_a0_slotarr->buf)[vader_array_offset(_a0_slotarr) + (size_t) l7];
        l8 = t0.payload.s;
        vader_array_push_scalar((vader_array_t*) l3, vader_box_string(499u, l8));
        l7 = (l7 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}
