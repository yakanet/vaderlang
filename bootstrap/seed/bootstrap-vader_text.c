#include "bootstrap.split.h"

bool vader_text_is_ident_byte(uint8_t l0) {
    bool l1, l2;
    if ((l0 >= INT32_C(65))) {
        l1 = (l0 <= INT32_C(90));
    } else {
        l1 = false;
    }
    if (l1) {
        l1 = true;
    } else {
        if ((l0 >= INT32_C(97))) {
            l2 = (l0 <= INT32_C(122));
        } else {
            l2 = false;
        }
        l1 = l2;
    }
    if (l1) {
        l1 = true;
    } else {
        if ((l0 >= INT32_C(48))) {
            l2 = (l0 <= INT32_C(57));
        } else {
            l2 = false;
        }
        l1 = l2;
    }
    if (l1) {
        l1 = true;
    } else {
        l1 = l0 == INT32_C(95);
    }
    return l1;
}

vader_string_t vader_text_prefix_before_double_underscore(vader_string_t l0) {
    void* l1 = NULL;
    size_t l2, l4, l6;
    int32_t l3;
    bool l5;
    vader_box_t t0 = vader_box_null();
    uint8_t t1;
    int64_t t2;
    void* t3 = NULL;
    vader_string_t t4;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[2] = { &l1, &t3 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 2u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = vader_import_3(l0);
    l2 = ((vader_array_t*) l1)->length;
    if ((l2 < INT64_C(2))) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    l3 = -(INT32_C(1));
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_16: {
            if ((l4 < l2)) {
                vader_array_t* _a0_slotarr = ((vader_array_t*) l1);
                if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
                if ((size_t) l4 >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a0_slotarr, _a0_slotarr->offset + (size_t) l4, 166u);
                t1 = ((uint8_t) t0.payload.i);
                if (t1 == INT32_C(36)) {
                    l3 = ((int32_t) (size_t) l4);
                } else {
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_16;
            } else {
            }
        }
    }
    if ((l3 < INT32_C(0))) {
        l4 = (size_t) (int64_t) INT64_C(0);
    } else {
        t2 = (((int64_t) (int32_t) l3) + INT64_C(1));
        l4 = (size_t) (int64_t) t2;
    }
    {
        loop_56: {
            if (((l4 + INT64_C(1)) < l2)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l1);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_read_u8(_a1_slotarr, _a1_slotarr->offset + (size_t) l4, 166u);
                t1 = ((uint8_t) t0.payload.i);
                if (t1 == INT32_C(95)) {
                    t2 = (l4 + INT64_C(1));
                    l6 = (size_t) (int64_t) t2;
                    vader_array_t* _a2_slotarr = ((vader_array_t*) l1);
                    if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                    if ((size_t) l6 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                    t0 = vader_array_read_u8(_a2_slotarr, _a2_slotarr->offset + (size_t) l6, 166u);
                    t1 = ((uint8_t) t0.payload.i);
                    l5 = t1 == INT32_C(95);
                } else {
                    l5 = false;
                }
                if (l5) {
                    vader_array_t* _a3_arr = vader_array_slice((vader_array_t*) l1, (size_t) INT64_C(0), (size_t) l4);
                    t3 = (void*) _a3_arr;
                    t4 = vader_import_2(t3);
                    { vader_string_t __vret = t4; vader_gc_top = gc_frame.prev; return __vret; }
                }
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_56;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return 0u; }
    vader_gc_top = gc_frame.prev;
}

