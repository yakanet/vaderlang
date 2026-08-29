#include "bootstrap.split.h"

vader_string_t std_string_builder_StringBuilder_Display_to_string(void* l0) {
    size_t l1, l3, l4, l5, l8;
    void* l2 = NULL;
    void* l6 = NULL;
    vader_string_t l7;
    vader_box_t t0 = vader_box_null();
    vader_string_t t1;
    int64_t t2;
    vader_box_t* gc_roots[1] = { &t0 };
    void** gc_raw_roots[3] = { &l0, &l2, &l6 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 1u, 3u, gc_roots, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l1 = ((vader_array_t*) ((vader_struct_std_string_builder_StringBuilder_t*) l0)->f_parts)->length;
    if (l1 == INT64_C(0)) {
        { vader_gc_top = gc_frame.prev; return 0u; }
    }
    if (l1 == INT64_C(1)) {
        vader_array_t* _a0_slotarr = ((vader_array_t*) ((vader_struct_std_string_builder_StringBuilder_t*) l0)->f_parts);
        if (_a0_slotarr->buf != NULL && _a0_slotarr->buf->header.forward != NULL) { _a0_slotarr->buf = vader_array_buf_forward(_a0_slotarr->buf); }
        if ((size_t) INT32_C(0) >= _a0_slotarr->length) { vader_trap("array index out of bounds"); }
        t0 = vader_array_box_slots(_a0_slotarr->buf)[_a0_slotarr->offset + (size_t) INT32_C(0)];
        t1 = t0.payload.s;
        { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    }
    l1 = (size_t) (int64_t) INT64_C(0);
    l2 = ((vader_struct_std_string_builder_StringBuilder_t*) l0)->f_parts;
    l3 = ((vader_array_t*) l2)->length;
    l4 = (size_t) (int64_t) INT64_C(0);
    {
        loop_27: {
            if ((l4 < l3)) {
                vader_array_t* _a1_slotarr = ((vader_array_t*) l2);
                if (_a1_slotarr->buf != NULL && _a1_slotarr->buf->header.forward != NULL) { _a1_slotarr->buf = vader_array_buf_forward(_a1_slotarr->buf); }
                if ((size_t) l4 >= _a1_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a1_slotarr->buf)[_a1_slotarr->offset + (size_t) l4];
                t1 = t0.payload.s;
                l5 = vader_import_0(t1);
                t2 = (l1 + l5);
                l1 = (size_t) (int64_t) t2;
                t2 = (l4 + INT64_C(1));
                l4 = (size_t) (int64_t) t2;
                goto loop_27;
            } else {
            }
        }
    }
    l2 = std_core_usize_BufferAlloc_new_buffer_vt(l1);
    l3 = (size_t) (int64_t) INT64_C(0);
    l6 = ((vader_struct_std_string_builder_StringBuilder_t*) l0)->f_parts;
    l4 = ((vader_array_t*) l6)->length;
    l5 = (size_t) (int64_t) INT64_C(0);
    {
        loop_63: {
            if ((l5 < l4)) {
                vader_array_t* _a2_slotarr = ((vader_array_t*) l6);
                if (_a2_slotarr->buf != NULL && _a2_slotarr->buf->header.forward != NULL) { _a2_slotarr->buf = vader_array_buf_forward(_a2_slotarr->buf); }
                if ((size_t) l5 >= _a2_slotarr->length) { vader_trap("array index out of bounds"); }
                t0 = vader_array_box_slots(_a2_slotarr->buf)[_a2_slotarr->offset + (size_t) l5];
                l7 = t0.payload.s;
                std_core_Buffer_ByteAccess_write_string_vt(l2, l3, l7);
                l8 = vader_import_0(l7);
                t2 = (l3 + l8);
                l3 = (size_t) (int64_t) t2;
                t2 = (l5 + INT64_C(1));
                l5 = (size_t) (int64_t) t2;
                goto loop_63;
            } else {
            }
        }
    }
    t1 = std_core_Buffer_ByteAccess_intern_string_vt(l2, l1);
    { vader_string_t __vret = t1; vader_gc_top = gc_frame.prev; return __vret; }
    vader_gc_top = gc_frame.prev;
}

void std_string_builder_append(void* l0, vader_string_t l1) {
    void** gc_raw_roots[1] = { &l0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 1u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    vader_array_push((vader_array_t*) ((vader_struct_std_string_builder_StringBuilder_t*) l0)->f_parts, vader_box_string(2u, l1));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_string_builder_append_char(void* l0, uint32_t l1) {
    void* l2 = NULL;
    vader_string_t l3;
    void* t0 = NULL;
    void** gc_raw_roots[3] = { &l0, &l2, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 3u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    l2 = ((vader_struct_std_string_builder_StringBuilder_t*) l0)->f_parts;
    t0 = std_core_utf8_encode(l1);
    l3 = vader_import_2(t0);
    vader_array_push((vader_array_t*) l2, vader_box_string(2u, l3));
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

void std_string_builder_append_repeated(void* l0, uint32_t l1, int32_t l2) {
    vader_string_t l3;
    int32_t l4;
    void* t0 = NULL;
    void** gc_raw_roots[2] = { &l0, &t0 };
    vader_gc_frame_t gc_frame = { vader_gc_top, 0u, 2u, NULL, gc_raw_roots, 0u, NULL };
    vader_gc_top = &gc_frame;
    t0 = std_core_utf8_encode(l1);
    l3 = vader_import_2(t0);
    l4 = INT32_C(0);
    {
        loop_7: {
            if ((l4 < l2)) {
                vader_array_push((vader_array_t*) ((vader_struct_std_string_builder_StringBuilder_t*) l0)->f_parts, vader_box_string(2u, l3));
                l4 = (l4 + INT32_C(1));
                goto loop_7;
            } else {
            }
        }
    }
    { vader_gc_top = gc_frame.prev; return; }
    vader_gc_top = gc_frame.prev;
}

