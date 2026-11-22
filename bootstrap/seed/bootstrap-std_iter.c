#include "bootstrap.split.h"

vader_box_t std_iter$__gen_state_std_iter_0$Iterator$next(void* l0) {
    void* l1 = NULL;
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    int32_t t0;
    vader_box_t t1 = vader_box_null();
    void* t2 = NULL;
    vader_box_t* gc_roots[4] = { &l2, &l3, &l4, &t1 };
    void** gc_raw_roots[3] = { &l0, &l1, &t2 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    for (;;) {
        t0 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state;
        if (t0 == INT32_C(0)) {
            ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(-1);
            continue;
        }
        t0 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state;
        if (t0 == INT32_C(1)) {
            ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(0);
        } else {
            t0 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state;
            if (t0 == INT32_C(2)) {
                ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(10);
            } else {
                t0 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state;
                if (t0 == INT32_C(3)) {
                    ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(2);
                } else {
                    t0 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state;
                    if (t0 == INT32_C(4)) {
                        ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(3);
                    } else {
                        t0 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state;
                        if (t0 == INT32_C(5)) {
                            ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(1);
                        } else {
                            t0 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state;
                            if (t0 == INT32_C(6)) {
                                ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(3);
                            } else {
                                t0 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state;
                                if (t0 == INT32_C(7)) {
                                    ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(6);
                                    l1 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_s1;
                                    vader_fn_t* _a0_fnobj = (vader_fn_t*) l1;
                                    t1 = ((vader_fn_erased_sig_1_t) _a0_fnobj->code)(_a0_fnobj->env, ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_s4);
                                    t2 = t1.payload.obj;
                                    { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                                }
                                t0 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state;
                                if (t0 == INT32_C(8)) {
                                    l2 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_s3;
                                    ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_s4 = l2;
                                    VADER_WRITE_BARRIER((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0);
                                    ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(7);
                                } else {
                                    t0 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state;
                                    if (t0 == INT32_C(9)) {
                                        if (((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_s3.tag == 1031u) {
                                            ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(5);
                                        } else {
                                            ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(8);
                                        }
                                    } else {
                                        t0 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state;
                                        if (t0 == INT32_C(10)) {
                                            l3 = std_core$Iterator$next$$dispatch(((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_s2);
                                            ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_s3 = l3;
                                            VADER_WRITE_BARRIER((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0);
                                            ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(9);
                                        } else {
                                            t0 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state;
                                            if (!(t0 == INT32_C(11))) {
                                                t2 = (void*) &vader_data_72;
                                                vader_array_t* _a1_slotarr = ((vader_array_t*) t2);
                                                VADER_ARRAY_RESOLVE_BUF(_a1_slotarr)
                                                t2 = vader_array_ref_load_obj(_a1_slotarr->buf, vader_array_offset(_a1_slotarr) + (size_t) INT64_C(0));
                                                { vader_box_t __vret = vader_ref_box(t2); vader_gc_top = gc_frame.prev; return __vret; }
                                            }
                                            l4 = ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_s0;
                                            ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_s2 = l4;
                                            VADER_WRITE_BARRIER((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0);
                                            ((vader_struct_std_iter$__gen_state_std_iter_0_t*) l0)->f_state = INT32_C(2);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        continue;
    }
    vader_gc_top = gc_frame.prev;
}

vader_box_t std_iter$map__Any__string__(vader_box_t l0, void* l1) {
    vader_box_t l2 = vader_box_null(), l3 = vader_box_null(), l4 = vader_box_null();
    void* t0 = NULL;
    vader_box_t* gc_roots[4] = { &l0, &l2, &l3, &l4 };
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 4u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = vader_box_obj(0u, NULL);
    l3 = vader_box_obj(0u, NULL);
    l4 = vader_box_obj(0u, NULL);
    vader_struct_std_iter$__gen_state_std_iter_0_t* _a0_obj = (vader_struct_std_iter$__gen_state_std_iter_0_t*) vader_gc_alloc(sizeof(vader_struct_std_iter$__gen_state_std_iter_0_t));
    vader_obj_header_init(_a0_obj, 1037u);
    _a0_obj->f_s0 = l0;
    _a0_obj->f_s1 = l1;
    _a0_obj->f_s2 = l2;
    _a0_obj->f_s3 = l3;
    _a0_obj->f_s4 = l4;
    _a0_obj->f_state = INT32_C(11);
    t0 = (void*) _a0_obj;
    { vader_box_t __vret = vader_ref_box(t0); vader_gc_top = gc_frame.prev; return __vret; }
}
