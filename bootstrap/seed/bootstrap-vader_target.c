#include "bootstrap.split.h"

static vader_string_t vader_target_arch_variant(uint8_t l0);
static vader_string_t vader_target_os_variant(uint8_t l0);

static vader_string_t vader_target_arch_variant(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 802u;
    }
    if (l0 == INT32_C(1)) {
        return 509u;
    }
    if (l0 == INT32_C(2)) {
        return 800u;
    }
    vader_unreachable("unreachable return in vader_target$arch_variant");
}

vader_string_t vader_target_baked_module_source(void* l0) {
    vader_string_t l1, l2, l3;
    void* t0 = NULL;
    vader_string_t t1;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = concat_3(1771u, 1941u, 235u);
    l2 = vader_target_os_variant(((vader_struct_vader_target_Target_t*) l0)->f_os);
    l2 = concat_2(1432u, l2);
    l3 = vader_target_arch_variant(((vader_struct_vader_target_Target_t*) l0)->f_arch);
    l3 = concat_2(1431u, l3);
    vader_array_t* _a0_arr = vader_array_new(8u, 14u, 0u, 162u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 13u] = vader_box_string(162u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 12u] = vader_box_string(162u, l3);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 11u] = vader_box_string(162u, 425u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 10u] = vader_box_string(162u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 9u] = vader_box_string(162u, l2);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 8u] = vader_box_string(162u, 426u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 7u] = vader_box_string(162u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 6u] = vader_box_string(162u, 1603u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 5u] = vader_box_string(162u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 4u] = vader_box_string(162u, l1);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 3u] = vader_box_string(162u, 0u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 2u] = vader_box_string(162u, 424u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 1u] = vader_box_string(162u, 422u);
    vader_array_box_slots(_a0_arr->buf)[_a0_arr->offset + 0u] = vader_box_string(162u, 421u);
    t0 = (void*) _a0_arr;
    t1 = std_string_join(t0, 1u);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

vader_string_t vader_target_display_target(void* l0) {
    vader_string_t l1, l2;
    vader_string_t t0;
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = std_target_Os_Display_to_string(((vader_struct_vader_target_Target_t*) l0)->f_os);
    l2 = std_target_Arch_Display_to_string(((vader_struct_vader_target_Target_t*) l0)->f_arch);
    t0 = concat_3(l1, 374u, l2);
    { vader_string_t __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void* vader_target_host_target(void) {
    uint8_t l0, l1;
    void* t0 = NULL;
    void** gc_raw_roots[1] = { &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l0 = vader_import_30();
    l1 = vader_import_31();
    vader_struct_vader_target_Target_t* _a0_obj = (vader_struct_vader_target_Target_t*) vader_gc_alloc(sizeof(vader_struct_vader_target_Target_t));
    vader_obj_header_init(_a0_obj, 883u);
    _a0_obj->f_os = l0;
    _a0_obj->f_arch = l1;
    t0 = (void*) _a0_obj;
    { void* __vret = t0; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

static vader_string_t vader_target_os_variant(uint8_t l0) {
    if (l0 == INT32_C(0)) {
        return 801u;
    }
    if (l0 == INT32_C(1)) {
        return 602u;
    }
    if (l0 == INT32_C(2)) {
        return 551u;
    }
    if (l0 == INT32_C(3)) {
        return 799u;
    }
    if (l0 == INT32_C(4)) {
        return 521u;
    }
    vader_unreachable("unreachable return in vader_target$os_variant");
}

vader_box_t vader_target_parse_os(vader_string_t l0) {
    vader_box_t l1;
    if (l0 == 2327u) {
        l1 = vader_box_i32(164u, INT32_C(0));
    } else {
        if (l0 == 1704u) {
            l1 = vader_box_i32(164u, INT32_C(1));
        } else {
            if (l0 == 1341u) {
                l1 = vader_box_i32(164u, INT32_C(2));
            } else {
                if (l0 == 2321u) {
                    l1 = vader_box_i32(164u, INT32_C(3));
                } else {
                    if (l0 == 1205u) {
                        l1 = vader_box_i32(164u, INT32_C(4));
                    } else {
                        l1 = vader_box_obj(0u, NULL);
                    }
                }
            }
        }
    }
    return l1;
}

