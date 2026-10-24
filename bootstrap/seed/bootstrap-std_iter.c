#include "bootstrap.split.h"

void* std_iter_clone__i32(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(22u, 0u, 7u, 320u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l0);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_iter_clone__i64(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(23u, 0u, 8u, 321u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l0);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_iter_clone__string(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(21u, 0u, 0u, 317u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l0);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_iter_clone__vader_comptime_GenericInstance(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(87u, 0u, 13u, 939u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l0);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_iter_clone__vader_diagnostics_Diagnostic(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(91u, 0u, 13u, 954u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l0);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_iter_clone__vader_lower_PendingFnInstance(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(141u, 0u, 13u, 1107u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l0);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_iter_clone__vader_resolver_symbol_Symbol(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(168u, 0u, 13u, 1233u);
    l1 = (void*) _a0_arr;
    l2 = ((vader_array_t*) l0)->length;
    vader_array_t* _a1_arr = vader_array_repeat((vader_array_t*) l1, (int64_t) l2);
    l1 = (void*) _a1_arr;
    vader_array_push_all((vader_array_t*) l1, (vader_array_t*) l0);
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

bool std_iter_is_empty__i32(void* l0) {
    int64_t t0;
    t0 = ((vader_array_t*) l0)->length;
    return t0 == INT64_C(0);
}

bool std_iter_is_empty__string(void* l0) {
    int64_t t0;
    t0 = ((vader_array_t*) l0)->length;
    return t0 == INT64_C(0);
}

bool std_iter_is_empty__toolchain_ast_AssertDecl___toolchain_ast_ConstDecl___toolchain_ast_EnumDecl___toolchain_ast_FnDecl___toolchain_ast_ImplDecl___toolchain_ast_ImportDecl___toolchain_ast_StructDecl___toolchain_ast_TraitDecl___toolchain_ast_TypeAliasDecl(void* l0) {
    int64_t t0;
    t0 = ((vader_array_t*) l0)->length;
    return t0 == INT64_C(0);
}

vader_box_t std_iter_last__i32(void* l0) {
    int64_t l1;
    int32_t t0;
    l1 = ((vader_array_t*) l0)->length;
    if (!(l1 == INT64_C(0))) {
        l1 = vader_chk_sub(i64, l1, INT64_C(1));
        vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
        t0 = ((int32_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l1];
        return vader_box_i32(320u, t0);
    }
    return vader_box_obj(0u, NULL);
}
