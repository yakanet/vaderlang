#include "bootstrap.split.h"

vader_string_t vader_resolver_symbol_kind_name(int32_t l0) {
    if (l0 == INT32_C(0)) {
        return 1566u;
    }
    if (l0 == INT32_C(1)) {
        return 2118u;
    }
    if (l0 == INT32_C(2)) {
        return 1447u;
    }
    if (l0 == INT32_C(3)) {
        return 2169u;
    }
    if (l0 == INT32_C(4)) {
        return 1671u;
    }
    if (l0 == INT32_C(5)) {
        return 2188u;
    }
    if (l0 == INT32_C(6)) {
        return 1368u;
    }
    if (l0 == INT32_C(7)) {
        return 1679u;
    }
    if (l0 == INT32_C(8)) {
        return 1896u;
    }
    if (l0 == INT32_C(9)) {
        return 2189u;
    }
    if (l0 == INT32_C(10)) {
        return 1785u;
    }
    if (l0 == INT32_C(11)) {
        return 1229u;
    }
    if (l0 == INT32_C(12)) {
        return 1278u;
    }
    if (l0 == INT32_C(13)) {
        return 1277u;
    }
    if (l0 == INT32_C(14)) {
        return 2137u;
    }
    vader_unreachable("unreachable return in vader_resolver_symbol$kind_name");
}

void* vader_resolver_symbol_make(void* l0, int32_t l1, vader_string_t l2, vader_string_t l3, uint8_t l4, vader_box_t l5) {
    int32_t l6, l7;
    void* t0 = NULL;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l6 = ((vader_struct_vader_resolver_symbol_SymbolFactory_t*) l0)->f_next;
    l7 = (l6 + INT32_C(1));
    ((vader_struct_vader_resolver_symbol_SymbolFactory_t*) l0)->f_next = l7;
    VADER_WRITE_BARRIER((vader_struct_vader_resolver_symbol_SymbolFactory_t*) l0);
    vader_struct_vader_resolver_symbol_Symbol_t* _a0_obj = (vader_struct_vader_resolver_symbol_Symbol_t*) vader_gc_alloc(sizeof(vader_struct_vader_resolver_symbol_Symbol_t));
    vader_obj_header_init(_a0_obj, 882u);
    _a0_obj->f_id = l6;
    _a0_obj->f_kind = l1;
    _a0_obj->f_name = l2;
    _a0_obj->f_module = l3;
    _a0_obj->f_visibility = l4;
    _a0_obj->f_defined_at = l5;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

