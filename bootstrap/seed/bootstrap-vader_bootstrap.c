#include "bootstrap.split.h"

int32_t vader_bootstrap$main(void* l0) {
    vader_string_t l1 = 0;
    void* l2 = NULL;
    void* l3 = NULL;
    void* l4 = NULL;
    int64_t t0;
    vader_box_t t1 = vader_box_null();
    vader_string_t t2 = 0;
    bool t3;
    int32_t t4;
    vader_box_t* gc_roots[1] = { &t1 };
    void** gc_raw_roots[4] = { &l0, &l2, &l3, &l4 };
    vader_string_t* gc_atom_roots[2] = { &l1, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 1u, 4u, gc_roots, gc_raw_roots, 0u, NULL, 2u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    t0 = ((vader_array_t*) l0)->length;
    if ((t0 < INT64_C(3))) {
        std_io$eprintln__string(2850u);
        { vader_gc_top = gc_frame.prev; return INT32_C(1); }
    }
    vader_array_t* _a0_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a0_slotarr)
    t1 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) INT32_C(1)];
    t2 = t1.payload.s;
    l1 = std_path$to_path(t2);
    vader_array_t* _a1_arr = vader_array_new(21u, 0u, 0u, 335u);
    l2 = (void*) _a1_arr;
    vader_array_t* _a2_arr = vader_array_new(220u, 0u, 13u, 1407u);
    l3 = (void*) _a2_arr;
    vader_struct_vader_pipeline$BuildRequest_t* _a3_obj = (vader_struct_vader_pipeline$BuildRequest_t*) vader_gc_alloc(sizeof(vader_struct_vader_pipeline$BuildRequest_t));
    vader_obj_header_init(_a3_obj, 1392u);
    _a3_obj->f_emit = 1694u;
    _a3_obj->f_out = 0u;
    _a3_obj->f_release = true;
    _a3_obj->f_verify = false;
    _a3_obj->f_cc = 0u;
    _a3_obj->f_ldflags = 0u;
    _a3_obj->f_include_paths = l2;
    _a3_obj->f_target = vader_box_obj(0u, NULL);
    _a3_obj->f_seed_targets = l3;
    _a3_obj->f_no_split = false;
    _a3_obj->f_project_root = vader_box_obj(0u, NULL);
    _a3_obj->f_runtime_root = 0u;
    _a3_obj->f_cc_jobs = INT32_C(0);
    l2 = (void*) _a3_obj;
    l2 = vader_pipeline$prepare_program(l1, l2);
    l3 = ((vader_struct_vader_pipeline$CfgBytecode_t*) l2)->f_pre_diags;
    l4 = ((vader_struct_vader_pipeline$CfgBytecode_t*) l2)->f_lower_diags;
    t3 = vader_pipeline$flush_build_diags(l3, l4);
    if (!(t3)) {
        { vader_gc_top = gc_frame.prev; return INT32_C(1); }
    }
    vader_array_t* _a4_slotarr = ((vader_array_t*) l0);
    VADER_ARRAY_RESOLVE_BUF(_a4_slotarr)
    VADER_ARRAY_CHECK_INDEX(_a4_slotarr, INT32_C(2))
    t1 = vader_array_box_slots(_a4_slotarr->buf)[_a4_slotarr->offset + (size_t) INT32_C(2)];
    t2 = t1.payload.s;
    l1 = std_path$to_path(t2);
    t4 = vader_pipeline$write_split_c(l2, l1);
    { int32_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
}
