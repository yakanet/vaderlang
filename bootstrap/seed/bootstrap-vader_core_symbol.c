#include "bootstrap.split.h"

bool vader_core_symbol$is_frozen_const(void* l0) {
    return ((vader_struct_vader_core_symbol$Symbol_t*) l0)->f_kind == INT32_C(6);
}

bool vader_core_symbol$is_local_binding(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(8)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(10);
    }
    if (l1) {
        return true;
    }
    return l0 == INT32_C(11);
}

bool vader_core_symbol$is_type_kind(uint8_t l0) {
    bool l1;
    if (l0 == INT32_C(1)) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(3);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(2);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(5);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(9);
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(12);
    }
    if (l1) {
        return true;
    }
    return false;
}

void* vader_core_symbol$make(void* l0, uint8_t l1, vader_string_t l2, vader_string_t l3, vader_string_t l4, uint8_t l5, vader_box_t l6) {
    int32_t l7, l8;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l6 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l2, &l3, &l4 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l7 = ((vader_struct_vader_core_symbol$SymbolFactory_t*) l0)->f_next;
    l8 = vader_chk_add(i32, l7, INT32_C(1));
    ((vader_struct_vader_core_symbol$SymbolFactory_t*) l0)->f_next = l8;
    vader_struct_vader_core_symbol$Symbol_t* _a0_obj = (vader_struct_vader_core_symbol$Symbol_t*) vader_gc_alloc(sizeof(vader_struct_vader_core_symbol$Symbol_t));
    vader_obj_header_init(_a0_obj, 892u);
    _a0_obj->f_id = l7;
    _a0_obj->f_kind = l1;
    _a0_obj->f_name = l2;
    _a0_obj->f_module = l3;
    _a0_obj->f_module_name = l4;
    _a0_obj->f_visibility = l5;
    _a0_obj->f_defined_at = l6;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}
