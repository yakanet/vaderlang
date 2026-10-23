#include "bootstrap.split.h"

static vader_string_t vader_target_arch_variant(uint8_t l0);
static vader_string_t vader_target_os_variant(uint8_t l0);

static vader_string_t vader_target_arch_variant(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 909u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 530u;
    } else {
        if (!(l0 == INT32_C(2))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 905u;
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
    l1 = concat_2(1827u, l1);
    l2 = vader_target_arch_variant(((vader_struct_vader_target_Target_t*) l0)->f_arch);
    l2 = concat_2(1826u, l2);
    vader_array_t* _a0_arr = vader_array_new(21u, 14u, 0u, 316u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 13u] = vader_box_string(316u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 12u] = vader_box_string(316u, l2);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 11u] = vader_box_string(316u, 396u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 10u] = vader_box_string(316u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 9u] = vader_box_string(316u, l1);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 8u] = vader_box_string(316u, 397u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 7u] = vader_box_string(316u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 6u] = vader_box_string(316u, 2028u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 5u] = vader_box_string(316u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 4u] = vader_box_string(316u, 2236u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 3u] = vader_box_string(316u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 2u] = vader_box_string(316u, 395u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = vader_box_string(316u, 394u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(316u, 393u);
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
    l1 = std_target_Os_std_core_Display_to_string(((vader_struct_vader_target_Target_t*) l0)->f_os);
    l2 = std_target_Arch_std_core_Display_to_string(((vader_struct_vader_target_Target_t*) l0)->f_arch);
    t0 = concat_3(l1, 334u, l2);
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
    vader_obj_header_init(_a0_obj, 1232u);
    _a0_obj->f_os = l0;
    _a0_obj->f_arch = l1;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
}

static vader_string_t vader_target_os_variant(uint8_t l0) {
    vader_string_t l1;
    if (l0 == INT32_C(0)) {
        l1 = 907u;
        return l1;
    }
    if (l0 == INT32_C(1)) {
        l1 = 655u;
    } else if (l0 == INT32_C(2)) {
        l1 = 579u;
    } else if (l0 == INT32_C(3)) {
        l1 = 904u;
    } else {
        if (!(l0 == INT32_C(4))) {
            vader_unreachable("non-exhaustive match (T3013 should have caught this)");
        }
        l1 = 544u;
    }
    return l1;
}

vader_box_t vader_target_parse_os(vader_string_t l0) {
    vader_box_t l1;
    if (l0 == 2884u) {
        l1 = vader_box_i32(321u, INT32_C(0));
        return l1;
    }
    if (l0 == 2146u) {
        l1 = vader_box_i32(321u, INT32_C(1));
    } else if (l0 == 1713u) {
        l1 = vader_box_i32(321u, INT32_C(2));
    } else if (l0 == 2874u) {
        l1 = vader_box_i32(321u, INT32_C(3));
    } else if (l0 == 1565u) {
        l1 = vader_box_i32(321u, INT32_C(4));
    } else {
        l1 = vader_box_obj(0u, NULL);
    }
    return l1;
}
