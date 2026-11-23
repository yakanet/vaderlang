#include "bootstrap.split.h"

static void std_task$cancel__Any(void* l0);
static vader_box_t std_task$join__Any(void* l0);
static int64_t std_task$next_ended(void* l0);
static vader_box_t std_task$outcome__Any(void* l0);
static vader_box_t std_task$outcome__vader_front_resolver_ParsedFile____(void* l0);
static int64_t std_task$start_thread(void* l0);
static void* std_task$started(void);
static void* std_task$started$singleton(void);
static void* std_task$watch__vader_front_resolver_ParsedFile____(void* l0);

bool std_task$Task$std_core$Equals$equals__Any(void* l0, void* l1) {
    return l0 == l1;
}

static void std_task$cancel__Any(void* l0) {
    void* t0 = NULL;
    bool t1;
    int64_t t2;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_runtime_scheduler$monitor_enter();
    t0 = (void*) &vader_data_113;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 507u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_std_task_10;
    _a1_closure->env = t0;
    t0 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t0));
    t1 = ((vader_struct_std_task$Task__Any_t*) l0)->f_ended;
    if (!(t1)) {
        t2 = ((vader_struct_std_task$Task__Any_t*) l0)->f_thread;
        vader_host_std_core$Intrinsic$cancel_thread(t2);
        vader_defer_pop_exec(1u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_defer_pop_exec(1u);
    { vader_gc_top = gc_frame.prev; return; }
}

void std_task$cancel_and_wait__vader_front_resolver_ParsedFile____(void* l0) {
    void* l1 = NULL;
    int64_t l2, l3;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = l0;
    l2 = vader_array_length(((vader_array_t*) l1));
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
        std_task$cancel__Any(t0);
        l3 = (l3 + INT64_C(1));
    }
    l1 = l0;
    l2 = vader_array_length(((vader_array_t*) l1));
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a1_slotarr, l3)
        t0 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) l3);
        std_task$join__Any(t0);
        l3 = (l3 + INT64_C(1));
    }
    { vader_gc_top = gc_frame.prev; return; }
}

void std_task$end__Any(void* l0) {
    void* l1 = NULL;
    void* l4 = NULL;
    void* l6 = NULL;
    int64_t l2, l3, l7;
    vader_box_t l5 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[1] = { &l5 };
    void** gc_raw_roots[5] = { &l0, &l1, &l4, &l6, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_runtime_scheduler$monitor_enter_to_publish();
    vader_host_std_core$Intrinsic$task_ended();
    ((vader_struct_std_task$Task__Any_t*) l0)->f_ended = true;
    l1 = ((vader_struct_std_task$Task__Any_t*) l0)->f_waiters;
    l2 = vader_array_length(((vader_array_t*) l1));
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        l4 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
        l5 = ((vader_struct_std_task$Waiter_t*) l4)->f_group;
        if (!(l5.tag == 0u)) {
            t0 = l5.payload.obj;
            l6 = ((vader_struct_std_task$Group_t*) t0)->f_ended;
            l7 = ((vader_struct_std_task$Waiter_t*) l4)->f_index;
            vader_array_push_i64((vader_array_t*) l6, l7);
        }
        t1 = ((vader_struct_std_task$Waiter_t*) l4)->f_thread;
        vader_host_std_core$Intrinsic$wake(t1);
        l3 = (l3 + INT64_C(1));
    }
    vader_host_std_core$Intrinsic$monitor_exit();
    { vader_gc_top = gc_frame.prev; return; }
}

static vader_box_t std_task$join__Any(void* l0) {
    int64_t l1;
    void* l2 = NULL;
    void* l3 = NULL;
    vader_box_t l4 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l4 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_runtime_scheduler$monitor_enter();
    t0 = (void*) &vader_data_111;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 507u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_std_task_12;
    _a1_closure->env = t0;
    t0 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t0));
    t1 = ((vader_struct_std_task$Task__Any_t*) l0)->f_ended;
    if (!(t1)) {
        l1 = vader_host_std_core$Intrinsic$current_thread();
        l2 = ((vader_struct_std_task$Task__Any_t*) l0)->f_waiters;
        vader_struct_std_task$Waiter_t* _a2_obj = (vader_struct_std_task$Waiter_t*) vader_gc_alloc(sizeof(vader_struct_std_task$Waiter_t));
        vader_obj_header_init(_a2_obj, 1066u);
        _a2_obj->f_thread = l1;
        _a2_obj->f_group = vader_box_obj(0u, NULL);
        _a2_obj->f_index = INT64_C(0);
        l3 = (void*) _a2_obj;
        vader_array_push_ref((vader_array_t*) l2, l3);
        vader_struct___defer_env_std_task_15_t* _a3_obj = (vader_struct___defer_env_std_task_15_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_task_15_t));
        vader_obj_header_init(_a3_obj, 639u);
        _a3_obj->f_cap_0 = l0;
        _a3_obj->f_cap_1 = l1;
        t0 = (void*) _a3_obj;
        vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
        vader_obj_header_init(_a4_closure, 507u);
        _a4_closure->code = (void*) &vader_fn_lift___defer_std_task_14;
        _a4_closure->env = t0;
        t0 = (void*) _a4_closure;
        vader_defer_push(vader_ref_box(t0));
        for (;;) {
            t1 = ((vader_struct_std_task$Task__Any_t*) l0)->f_ended;
            if (!(t1)) {
                vader_host_std_core$Intrinsic$park();
                continue;
            }
            break;
        }
        vader_defer_pop_exec(1u);
    }
    l4 = std_task$outcome__Any(l0);
    vader_defer_pop_exec(1u);
    { vader_box_t __vret = l4; vader_gc_top = gc_frame.prev; return __vret; }
}

void* std_task$launch__vader_front_resolver_ParsedFile____(void* l0) {
    void* l1 = NULL;
    void* l3 = NULL;
    int64_t l2;
    int32_t t0;
    int64_t t1;
    void* t2 = NULL;
    void** gc_raw_roots[4] = { &l0, &l1, &l3, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 4u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_runtime_scheduler$monitor_enter_to_publish();
    t0 = vader_global_27;
    if (t0 == INT32_C(2)) {
        l1 = vader_global_28;
    } else {
        l1 = std_task$started();
    }
    t1 = ((vader_struct_std_task$Started_t*) l1)->f_count;
    l2 = vader_chk_add(i64, t1, INT64_C(1));
    vader_array_t* _a0_arr = vader_array_new(35u, 0u, 0u, 614u);
    l1 = (void*) _a0_arr;
    vader_array_t* _a1_arr = vader_array_new(60u, 0u, 13u, 1066u);
    l3 = (void*) _a1_arr;
    vader_struct_std_task$Task__Any_t* _a2_obj = (vader_struct_std_task$Task__Any_t*) vader_gc_alloc(sizeof(vader_struct_std_task$Task__Any_t));
    vader_obj_header_init(_a2_obj, 1064u);
    _a2_obj->f_number = l2;
    _a2_obj->f_thread = INT64_C(-1);
    _a2_obj->f_ended = false;
    _a2_obj->f_result = l1;
    _a2_obj->f_waiters = l3;
    l1 = (void*) _a2_obj;
    vader_struct___lambda_env_std_task_1_t* _a3_obj = (vader_struct___lambda_env_std_task_1_t*) vader_gc_alloc(sizeof(vader_struct___lambda_env_std_task_1_t));
    vader_obj_header_init(_a3_obj, 646u);
    _a3_obj->f_cap_0 = l1;
    _a3_obj->f_cap_1 = l0;
    t2 = (void*) _a3_obj;
    vader_fn_t* _a4_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a4_closure, 507u);
    _a4_closure->code = (void*) &vader_fn_lift___lambda_std_task_0;
    _a4_closure->env = t2;
    t2 = (void*) _a4_closure;
    l2 = std_task$start_thread(t2);
    ((vader_struct_std_task$Task__Any_t*) l1)->f_thread = l2;
    vader_host_std_core$Intrinsic$monitor_exit();
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}

static int64_t std_task$next_ended(void* l0) {
    int64_t l1, l2;
    void* l3 = NULL;
    int64_t t0;
    void** gc_raw_roots[2] = { &l0, &l3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        l1 = ((vader_struct_std_task$Group_t*) l0)->f_taken;
        l2 = vader_array_length(((vader_array_t*) ((vader_struct_std_task$Group_t*) l0)->f_ended));
        if (l1 == l2) {
            vader_host_std_core$Intrinsic$park();
            continue;
        }
        break;
    }
    t0 = ((vader_struct_std_task$Group_t*) l0)->f_taken;
    l1 = vader_chk_add(i64, t0, INT64_C(1));
    ((vader_struct_std_task$Group_t*) l0)->f_taken = l1;
    l3 = ((vader_struct_std_task$Group_t*) l0)->f_ended;
    t0 = ((vader_struct_std_task$Group_t*) l0)->f_taken;
    l1 = vader_chk_sub(i64, t0, INT64_C(1));
    vader_array_t* _a0_slotarr = ((vader_array_t*) l3);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l1)
    t0 = ((int64_t*) _a0_slotarr->buf->slots)[vader_array_offset(_a0_slotarr) + (size_t) l1];
    { int64_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_box_t std_task$outcome__Any(void* l0) {
    int64_t t0;
    vader_box_t t1;
    void* t2;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_std_task$Task__Any_t*) l0)->f_result));
    if (!(t0 == INT64_C(0))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_task$Task__Any_t*) l0)->f_result);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_box(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
        return t1;
    }
    t2 = (void*) &vader_data_112;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t2);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    return vader_ref_box(t2);
}

static vader_box_t std_task$outcome__vader_front_resolver_ParsedFile____(void* l0) {
    int64_t t0;
    void* t1;
    t0 = vader_array_length(((vader_array_t*) ((vader_struct_std_task$Task__vader_front_resolver_ParsedFile_____t*) l0)->f_result));
    if (!(t0 == INT64_C(0))) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_task$Task__vader_front_resolver_ParsedFile_____t*) l0)->f_result);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, INT32_C(0))
        t1 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT32_C(0));
        return vader_ref_box(t1);
    }
    t1 = (void*) &vader_data_112;
    vader_array_t* _a1_slotarr = ((vader_array_t*) t1);
    VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
    t1 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
    return vader_ref_box(t1);
}

void std_task$run__Any(void* l0, void* l1) {
    void* l2 = NULL;
    vader_box_t l3 = vader_box_null();
    void* t0 = NULL;
    bool t1;
    vader_box_t* gc_roots[1] = { &l3 };
    void** gc_raw_roots[4] = { &l0, &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct___defer_env_std_task_9_t* _a0_obj = (vader_struct___defer_env_std_task_9_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_task_9_t));
    vader_obj_header_init(_a0_obj, 643u);
    _a0_obj->f_cap_0 = l0;
    t0 = (void*) _a0_obj;
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 507u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_std_task_8;
    _a1_closure->env = t0;
    t0 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t0));
    t1 = vader_host_std_core$Intrinsic$is_cancelled();
    if (!(t1)) {
        l2 = ((vader_struct_std_task$Task__Any_t*) l0)->f_result;
        vader_fn_t* _a2_fnobj = (vader_fn_t*) l1;
        l3 = ((vader_fn_erased_sig_0_t) _a2_fnobj->code)(_a2_fnobj->env);
        vader_array_push((vader_array_t*) l2, l3);
        vader_defer_pop_exec(1u);
        { vader_gc_top = gc_frame.prev; return; }
    }
    vader_defer_pop_exec(1u);
    { vader_gc_top = gc_frame.prev; return; }
}

static int64_t std_task$start_thread(void* l0) {
    void* l1 = NULL;
    int64_t l2;
    int32_t t0;
    int64_t t1;
    void** gc_raw_roots[2] = { &l0, &l1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_27;
    if (t0 == INT32_C(2)) {
        l1 = vader_global_28;
    } else {
        l1 = std_task$started();
    }
    t1 = ((vader_struct_std_task$Started_t*) l1)->f_count;
    l2 = vader_chk_add(i64, t1, INT64_C(1));
    ((vader_struct_std_task$Started_t*) l1)->f_count = l2;
    l2 = ((vader_struct_std_task$Started_t*) l1)->f_count;
    t1 = vader_host_std_core$Intrinsic$spawn_thread(l0, l2);
    { int64_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_task$started(void) {
    void* l0 = NULL;
    void* l1 = NULL;
    int32_t t0;
    void* t1 = NULL;
    vader_box_t t2 = vader_box_null();
    bool t3;
    vader_box_t* gc_roots[1] = { &t2 };
    void** gc_raw_roots[3] = { &l0, &l1, &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_27;
    if (t0 == INT32_C(2)) {
        t1 = vader_global_28;
        { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    std_runtime_scheduler$monitor_enter_to_publish();
    t2 = vader_global_29;
    l0 = std_runtime_scheduler$gate_or_new(t2);
    vader_global_29 = vader_ref_box(l0);
    l1 = (void*) &vader_fn_static_std_task$started$keep;
    t3 = std_runtime_scheduler$run_gated(l0, l1);
    if (!(t3)) {
        vader_unreachable("singleton `started` called while it initialises");
    }
    t1 = vader_global_28;
    { void* __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

void std_task$started$keep(void) {
    int32_t t0;
    void* t1 = NULL;
    void** gc_raw_roots[1] = { &t1 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = vader_global_27;
    if (!(t0 == INT32_C(2))) {
        t1 = std_task$started$singleton();
        vader_global_28 = t1;
        vader_global_27 = INT32_C(2);
        { vader_gc_top = gc_frame.prev; return; }
    }
    { vader_gc_top = gc_frame.prev; return; }
}

static void* std_task$started$singleton(void) {
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_struct_std_task$Started_t* _a0_obj = (vader_struct_std_task$Started_t*) vader_gc_alloc(sizeof(vader_struct_std_task$Started_t));
    vader_obj_header_init(_a0_obj, 1063u);
    _a0_obj->f_count = INT64_C(0);
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void std_task$stop_waiting__Any(void* l0, int64_t l1) {
    void* l2;
    void* l6;
    int64_t l3, l4, l5;
    void* t0;
    int64_t t1;
    vader_box_t t2;
    l2 = ((vader_struct_std_task$Task__Any_t*) l0)->f_waiters;
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l2));
    while ((l3 < l4)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3);
        t1 = ((vader_struct_std_task$Waiter_t*) t0)->f_thread;
        if (t1 == l1) {
            t1 = vader_array_length(((vader_array_t*) l2));
            l5 = vader_chk_sub(i64, t1, INT64_C(1));
            l6 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l5);
            vader_array_ref_store(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l3, l6);
            VADER_WRITE_BARRIER(_a0_slotarr->buf);
            t2 = vader_array_remove_last((vader_array_t*) l2);
            return;
        }
        l3 = (l3 + INT64_C(1));
    }
    return;
}

void std_task$stop_waiting_all__vader_front_resolver_ParsedFile____(void* l0) {
    int64_t l1, l3, l4;
    void* l2;
    void* t0;
    l1 = vader_host_std_core$Intrinsic$current_thread();
    l2 = l0;
    l3 = vader_array_length(((vader_array_t*) l2));
    l4 = INT64_C(0);
    while ((l4 < l3)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) l2);
        VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a0_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) l4);
        std_task$stop_waiting__Any(t0, l1);
        l4 = (l4 + INT64_C(1));
    }
    return;
}

vader_box_t std_task$try_join_all__vader_front_resolver_ParsedFile____(void* l0) {
    void* l1 = NULL;
    void* l8 = NULL;
    void* l9 = NULL;
    int64_t l2, l3, l4;
    vader_box_t l5 = vader_box_null(), l6 = vader_box_null(), l7 = vader_box_null();
    void* t0 = NULL;
    int64_t t1;
    vader_box_t* gc_roots[3] = { &l5, &l6, &l7 };
    void** gc_raw_roots[5] = { &l0, &l1, &l8, &l9, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 3u, 5u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    std_runtime_scheduler$monitor_enter();
    t0 = (void*) &vader_data_114;
    vader_array_t* _a0_slotarr = ((vader_array_t*) t0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t0 = vader_array_ref_load_obj(_a0_slotarr->buf, vader_array_offset(_a0_slotarr) + (size_t) INT64_C(0));
    vader_fn_t* _a1_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a1_closure, 507u);
    _a1_closure->code = (void*) &vader_fn_lift___defer_std_task_2;
    _a1_closure->env = t0;
    t0 = (void*) _a1_closure;
    vader_defer_push(vader_ref_box(t0));
    vader_struct___defer_env_std_task_5_t* _a2_obj = (vader_struct___defer_env_std_task_5_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_task_5_t));
    vader_obj_header_init(_a2_obj, 641u);
    _a2_obj->f_cap_0 = l0;
    t0 = (void*) _a2_obj;
    vader_fn_t* _a3_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a3_closure, 507u);
    _a3_closure->code = (void*) &vader_fn_lift___defer_std_task_4;
    _a3_closure->env = t0;
    t0 = (void*) _a3_closure;
    vader_defer_push(vader_ref_box(t0));
    l1 = std_task$watch__vader_front_resolver_ParsedFile____(l0);
    vader_struct___defer_env_std_task_7_t* _a4_obj = (vader_struct___defer_env_std_task_7_t*) vader_gc_alloc(sizeof(vader_struct___defer_env_std_task_7_t));
    vader_obj_header_init(_a4_obj, 642u);
    _a4_obj->f_cap_0 = l0;
    t0 = (void*) _a4_obj;
    vader_fn_t* _a5_closure = (vader_fn_t*) vader_gc_alloc(sizeof(vader_fn_t));
    vader_obj_header_init(_a5_closure, 507u);
    _a5_closure->code = (void*) &vader_fn_lift___defer_std_task_6;
    _a5_closure->env = t0;
    t0 = (void*) _a5_closure;
    vader_defer_push(vader_ref_box(t0));
    l2 = INT64_C(0);
    l3 = vader_array_length(((vader_array_t*) l0));
    while ((l2 < l3)) {
        l4 = std_task$next_ended(l1);
        vader_array_t* _a6_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a6_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a6_slotarr, l4)
        t0 = vader_array_ref_load_obj(_a6_slotarr->buf, vader_array_offset(_a6_slotarr) + (size_t) l4);
        l5 = std_task$outcome__vader_front_resolver_ParsedFile____(t0);
        l6 = l5;
        if ((l5.tag == 617u) || (l5.tag == 1054u) || (l5.tag == 848u) || (l5.tag == 1043u) || (l5.tag == 1059u) || (l5.tag == 1204u) || (l5.tag == 1218u) || (l5.tag == 2038u) || (l5.tag == 2035u) || (l5.tag == 1598u)) {
            l7 = l6;
            vader_defer_pop_exec(3u);
            { vader_box_t __vret = l7; vader_gc_top = gc_frame.prev; return __vret; }
        }
        l2 = (l2 + INT64_C(1));
    }
    t1 = vader_array_length(((vader_array_t*) l0));
    vader_array_t* _a7_arr = vader_array_reserve(1u, (int64_t) t1, 13u, 15u);
    l1 = (void*) _a7_arr;
    l8 = l0;
    l2 = vader_array_length(((vader_array_t*) l8));
    l3 = INT64_C(0);
    while ((l3 < l2)) {
        vader_array_t* _a8_slotarr = ((vader_array_t*) l8);
        VADER_ARRAY_RESOLVE_BUF(_a8_slotarr)
        t0 = vader_array_ref_load_obj(_a8_slotarr->buf, vader_array_offset(_a8_slotarr) + (size_t) l3);
        vader_array_t* _a9_slotarr = ((vader_array_t*) ((vader_struct_std_task$Task__vader_front_resolver_ParsedFile_____t*) t0)->f_result);
        VADER_ARRAY_RESOLVE_BUF(_a9_slotarr)
        VADER_ARRAY_CHECK_INDEX(_a9_slotarr, INT32_C(0))
        l9 = vader_array_ref_load_obj(_a9_slotarr->buf, vader_array_offset(_a9_slotarr) + (size_t) INT32_C(0));
        vader_array_push_ref((vader_array_t*) l1, l9);
        l3 = (l3 + INT64_C(1));
    }
    vader_defer_pop_exec(3u);
    { vader_box_t __vret = vader_ref_box(l1); vader_gc_top = gc_frame.prev; return __vret; }
}

static void* std_task$watch__vader_front_resolver_ParsedFile____(void* l0) {
    void* l1 = NULL;
    void* l5 = NULL;
    void* l6 = NULL;
    void* l7 = NULL;
    int64_t l2, l3, l4;
    void* t0 = NULL;
    bool t1;
    void** gc_raw_roots[6] = { &l0, &l1, &l5, &l6, &l7, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 6u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(30u, 0u, 8u, 607u);
    t0 = (void*) _a0_arr;
    vader_struct_std_task$Group_t* _a1_obj = (vader_struct_std_task$Group_t*) vader_gc_alloc(sizeof(vader_struct_std_task$Group_t));
    vader_obj_header_init(_a1_obj, 1062u);
    _a1_obj->f_ended = t0;
    _a1_obj->f_taken = INT64_C(0);
    l1 = (void*) _a1_obj;
    l2 = vader_host_std_core$Intrinsic$current_thread();
    l3 = INT64_C(0);
    l4 = vader_array_length(((vader_array_t*) l0));
    while ((l3 < l4)) {
        vader_array_t* _a2_slotarr = ((vader_array_t*) l0);
        VADER_ARRAY_RESOLVE_BUF(_a2_slotarr)
        l5 = vader_array_ref_load_obj(_a2_slotarr->buf, vader_array_offset(_a2_slotarr) + (size_t) l3);
        t1 = ((vader_struct_std_task$Task__vader_front_resolver_ParsedFile_____t*) l5)->f_ended;
        if (t1) {
            vader_array_push_i64((vader_array_t*) ((vader_struct_std_task$Group_t*) l1)->f_ended, l3);
        } else {
            l6 = ((vader_struct_std_task$Task__vader_front_resolver_ParsedFile_____t*) l5)->f_waiters;
            vader_struct_std_task$Waiter_t* _a3_obj = (vader_struct_std_task$Waiter_t*) vader_gc_alloc(sizeof(vader_struct_std_task$Waiter_t));
            vader_obj_header_init(_a3_obj, 1066u);
            _a3_obj->f_thread = l2;
            _a3_obj->f_group = vader_ref_box(l1);
            _a3_obj->f_index = l3;
            l7 = (void*) _a3_obj;
            vader_array_push_ref((vader_array_t*) l6, l7);
        }
        l3 = (l3 + INT64_C(1));
    }
    { void* __vret = l1; vader_gc_top = gc_frame.prev; return __vret; }
}
