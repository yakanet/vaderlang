#include "bootstrap.split.h"

static vader_string_t vader_target_arch_variant(uint8_t l0);
static vader_string_t vader_target_os_variant(uint8_t l0);

static vader_string_t vader_target_arch_variant(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 796u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 429u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 793u;
    }
    return l1;
}

vader_string_t vader_target_baked_module_source(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    void* t0 = NULL;
    vader_string_t t1 = 0;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t1 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = vader_target_os_variant(((vader_struct_vader_target_Target_t*) l0)->f_os);
    l1 = concat_2(1622u, l1);
    l2 = vader_target_arch_variant(((vader_struct_vader_target_Target_t*) l0)->f_arch);
    l2 = concat_2(1621u, l2);
    vader_array_t* _a0_arr = vader_array_new(13u, 14u, 0u, 243u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 13u] = vader_box_string(243u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 12u] = vader_box_string(243u, l2);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 11u] = vader_box_string(243u, 341u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 10u] = vader_box_string(243u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 9u] = vader_box_string(243u, l1);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 8u] = vader_box_string(243u, 342u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 7u] = vader_box_string(243u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 6u] = vader_box_string(243u, 1820u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 5u] = vader_box_string(243u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 4u] = vader_box_string(243u, 2015u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 3u] = vader_box_string(243u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 2u] = vader_box_string(243u, 340u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = vader_box_string(243u, 339u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(243u, 338u);
    t0 = (void*) _a0_arr;
    t1 = std_string_join(t0, 1u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
}

vader_string_t vader_target_display_target(void* l0) {
    vader_string_t l1 = 0;
    vader_string_t l2 = 0;
    vader_string_t t0 = 0;
    void** gc_raw_roots[1] = { &l0 };
    vader_string_t* gc_atom_roots[3] = { &l1, &l2, &t0 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    l1 = std_target_Os_Display_to_string(((vader_struct_vader_target_Target_t*) l0)->f_os);
    l2 = std_target_Arch_Display_to_string(((vader_struct_vader_target_Target_t*) l0)->f_arch);
    t0 = concat_3(l1, 294u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

void* vader_target_host_target(void) {
    uint8_t l0, l1;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l0 = vader_host_std_target_current_os();
    l1 = vader_host_std_target_current_arch();
    vader_struct_vader_target_Target_t* _a0_obj = (vader_struct_vader_target_Target_t*) vader_gc_alloc(sizeof(vader_struct_vader_target_Target_t));
    vader_obj_header_init(_a0_obj, 1026u);
    _a0_obj->f_os = l0;
    _a0_obj->f_arch = l1;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_target_os_variant(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 794u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 546u;
    } else if (l0 == INT32_C(2)) {
        l1 = 478u;
    } else if (l0 == INT32_C(3)) {
        l1 = 792u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 442u;
    }
    return l1;
}

vader_box_t vader_target_parse_os(vader_string_t l0) {
    vader_box_t l1;
    if (l0 == 2639u) {
        l1 = vader_box_i32(249u, INT32_C(0));
        return l1;
    }
    if (l0 == 1940u) {
        l1 = vader_box_i32(249u, INT32_C(1));
    } else if (l0 == 1513u) {
        l1 = vader_box_i32(249u, INT32_C(2));
    } else if (l0 == 2629u) {
        l1 = vader_box_i32(249u, INT32_C(3));
    } else if (l0 == 1363u) {
        l1 = vader_box_i32(249u, INT32_C(4));
    } else {
        l1 = vader_box_obj(0u, NULL);
    }
    return l1;
}
