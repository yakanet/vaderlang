#include "bootstrap.split.h"

int64_t vader_core_wit$enum_case_bits(int64_t l0) {
    if ((l0 <= INT64_C(256))) {
        return INT64_C(8);
    }
    if (!((l0 <= INT64_C(65536)))) {
        return INT64_C(32);
    }
    return INT64_C(16);
}

vader_string_t vader_core_wit$wit_name(vader_string_t l0) {
    void* l1 = NULL;
    int64_t l2, l3, l7;
    uint8_t l4;
    bool l5;
    uint32_t l6;
    vader_string_t l8 = 0;
    void* t0 = NULL;
    uint8_t t1;
    vader_string_t t2 = 0;
    void** gc_raw_roots[2] = { &l1, &t0 };
    vader_string_t* gc_atom_roots[3] = { &l0, &l8, &t2 };
    vader_gc_frame_t gc_frame = {
        vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL, 3u, gc_atom_roots,
    };
    vader_gc_top = &gc_frame;
    vader_array_t* _a0_arr = vader_array_new(28u, 0u, 0u, 603u);
    t0 = (void*) _a0_arr;
    vader_struct_std_string__builder$StringBuilder_t* _a1_obj = (vader_struct_std_string__builder$StringBuilder_t*) vader_gc_alloc(sizeof(vader_struct_std_string__builder$StringBuilder_t));
    vader_obj_header_init(_a1_obj, 1061u);
    _a1_obj->f_parts = t0;
    l1 = (void*) _a1_obj;
    l2 = INT64_C(0);
    l3 = vader_host_std_core$Intrinsic$byte_len(l0);
    while ((l2 < l3)) {
        l4 = vader_host_std_core$Intrinsic$byte_at(l0, l2);
        if (l4 == INT32_C(95)) {
            std_string__builder$append(l1, 459u);
        } else {
            if ((l4 >= INT32_C(65))) {
                l5 = (l4 <= INT32_C(90));
            } else {
                l5 = false;
            }
            if (l5) {
                if ((l2 > INT64_C(0))) {
                    std_string__builder$append(l1, 459u);
                }
                t1 = std_ascii$to_lower_byte(l4);
                l6 = ((uint32_t) (uint8_t) t1);
                std_string__builder$append_char(l1, l6);
            } else {
                l7 = vader_chk_add(i64, l2, INT64_C(1));
                l8 = vader_host_std_core$Intrinsic$byte_slice(l0, l2, l7);
                std_string__builder$append(l1, l8);
            }
        }
        l2 = (l2 + INT64_C(1));
    }
    t2 = std_string__builder$StringBuilder$std_core$Display$to_string(l1);
    { vader_string_t __vret = t2; vader_gc_top = gc_frame.prev; return __vret; }
}
