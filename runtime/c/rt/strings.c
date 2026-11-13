/* rt/strings.c: strings over atoms, and their bytes viewed as an array. */

#include "internal.h"

vader_string_t vader_string_new(const char* p, size_t n) {
    return vader_atom_intern(p, n);
}

const char* vader_string_to_cstr(vader_string_t s) {
    return vader_atom_to_cstr(s);
}

/* Zero-copy `const u8[]` view over `s`'s interned bytes, see the header
 * decl. Allocates only the array header ; `buf` stays NULL and reads route
 * through `vader_atom_data(s)` (`vader_array_read_u8` / `_slice`). `capacity`
 * holds the id of the owner atom, which `vader_atom_mark_heap` recovers. The
 * view is flagged VADER_ARRAY_FLAG_BORROWED. A byte read as a box takes the
 * tag the type `arr_type` gives its elements, which `elem_tag` repeats.
 *
 * `s` needs no extra rooting across the alloc : it is an atom id (a value,
 * not a heap pointer) and the caller holds the source string live on the
 * shadow stack, so any major cycle inside `vader_gc_alloc` keeps the atom
 * marked. No allocation runs between the alloc and the field writes, so
 * `view` cannot move before it is populated. */
vader_array_t* vader_string_bytes_view(vader_string_t s, uint32_t arr_type, uint32_t elem_tag) {
    (void) elem_tag;
    vader_array_t* view = (vader_array_t*) vader_gc_alloc(vader_gc_align(sizeof(vader_array_t)));
    vader_obj_header_init(view, arr_type);
    view->offset = 0;
    view->buf    = NULL;
    vader_array_make_borrowed(view, s, vader_atom_len(s));
    return view;
}

/* Inverse of `vader_string_bytes_view`, see the header. A borrowed view
 * aliases `owner[offset .. offset+len]`, so `vader_atom_slice` reinterprets
 * those bytes as a string atom in O(1) (intern-deduped, no copy of the byte
 * storage). A materialised `u8[]` (e.g. a built array) is interned straight
 * from its slots. Bytes are taken verbatim ; no UTF-8 validation. */
vader_string_t vader_string_as_string(vader_array_t* a) {
    a = vader_array_resolve(a);
    size_t len = vader_array_length(a);
    if (len == 0) return VADER_ATOM_EMPTY;
    if (vader_array_is_borrowed(a)) {
        return vader_atom_slice(vader_array_borrowed_owner(a), a->offset, len);
    }
    /* Materialised KIND_U8 buffer : interning allocates nothing on the Vader
     * heap (its copy on a miss is `malloc`), so the resolved slots stay put
     * while it reads them. */
    vader_array_resolve_buf(a);
    const char* src = (const char*) a->buf->slots;
    return vader_atom_intern(src + a->offset, len);
}
