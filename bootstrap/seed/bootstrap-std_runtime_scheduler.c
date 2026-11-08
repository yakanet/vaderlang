#include "bootstrap.split.h"

static void std_runtime_scheduler$await_gate(void* l0, int64_t l1);

static void std_runtime_scheduler$await_gate(void* l0, int64_t l1) {
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push_i64((vader_array_t*) ((vader_struct_std_runtime_scheduler$InitGate_t*) l0)->f_waiters, l1);
    vader_struct___defer_env_std_runtime_scheduler_3_t* _a0_obj = (vader_struct___defer_env_std_runtime_scheduler_3_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_runtime_scheduler_3_t));
    vader_obj_header_init(_a0_obj, 520u);
    _a0_obj->f_cap_0 = l0;
    _a0_obj->f_cap_1 = l1;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 436u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_std_runtime_scheduler_2;
    _a1_closure->env = t0;
    t0 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t0));
    for (;;) {
        t1 = ((vader_struct_std_runtime_scheduler$InitGate_t*) l0)->f_held;
        if (t1) {
            vader_host_std_runtime_scheduler$park();
            continue;
        }
        break;
    }
    vader_defer_pop_exec(1u);
    { vader_gc_top = gc_frame.prev; return; }
}

void* std_runtime_scheduler$gate_or_new(vader_box_t l0) {
    vader_box_t l1 = vader_box_null();
    void* l2 = NULL;
    void* t0 = NULL;
    vader_box_t* gc_roots[2] = { &l0, &l1 };
    void** gc_raw_roots[2] = { &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 2u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = l0;
    if (l1.tag == 0u) {
        vader_array_t* _a0_arr = vader_array_new(28u, 0u, 8u, 498u);
        l2 = (void*) _a0_arr;
        vader_struct_std_runtime_scheduler$InitGate_t* _a1_obj = (vader_struct_std_runtime_scheduler$InitGate_t*) vader_gc_alloc(sizeof(vader_struct_std_runtime_scheduler$InitGate_t));
        vader_obj_header_init(_a1_obj, 858u);
        _a1_obj->f_held = false;
        _a1_obj->f_owner = INT64_C(0);
        _a1_obj->f_waiters = l2;
        t0 = (void*) _a1_obj;
        { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    }
    t0 = l1.payload.obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void std_runtime_scheduler$let_go(void* l0) {
    void* l1;
    int64_t l2, l3;
    int64_t t0;
    ((vader_struct_std_runtime_scheduler$InitGate_t*) l0)->f_held = false;
    l1 = ((vader_struct_std_runtime_scheduler$InitGate_t*) l0)->f_waiters;
    l2 = ((vader_array_t*) l1)->length;
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = ((int64_t*) _a0_slotarr->buf->slots)[_a0_slotarr->offset + (size_t) l3];
        vader_host_std_runtime_scheduler$wake(t0);
        l3 = (l3 + INT64_C(1));
    }
    return;
}

bool std_runtime_scheduler$run_gated(void* l0, void* l1) {
    int64_t l2;
    bool t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_host_std_runtime_scheduler$current_thread();
    t0 = ((vader_struct_std_runtime_scheduler$InitGate_t*) l0)->f_held;
    if (t0) {
        t1 = ((vader_struct_std_runtime_scheduler$InitGate_t*) l0)->f_owner;
        if (t1 == l2) {
            { vader_gc_top = gc_frame.prev; return false; }
        }
    }
    t0 = ((vader_struct_std_runtime_scheduler$InitGate_t*) l0)->f_held;
    if (t0) {
        std_runtime_scheduler$await_gate(l0, l2);
    }
    ((vader_struct_std_runtime_scheduler$InitGate_t*) l0)->f_held = true;
    ((vader_struct_std_runtime_scheduler$InitGate_t*) l0)->f_owner = l2;
    vader_struct___defer_env_std_runtime_scheduler_1_t* _a0_obj = (vader_struct___defer_env_std_runtime_scheduler_1_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_runtime_scheduler_1_t));
    vader_obj_header_init(_a0_obj, 519u);
    _a0_obj->f_cap_0 = l0;
    t2 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 436u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_std_runtime_scheduler_0;
    _a1_closure->env = t2;
    t2 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t2));
    vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
    ((vader_fn_erased_sig_0_t) _a2_fnobj->code)(_a2_fnobj->env);
    vader_defer_pop_exec(1u);
    { vader_gc_top = gc_frame.prev; return true; }
}
