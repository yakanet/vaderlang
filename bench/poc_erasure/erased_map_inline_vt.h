/* Variant of `erased_map.h` with the vtable function pointers stored
 * inline on the map struct rather than referenced through a vtable
 * pointer. Saves one memory load per dispatch — sometimes enough to
 * close the criterion #2 regression gap.
 *
 * The trade-off: each map is 16 bytes larger (2 pointers in-line vs
 * 1 vtable pointer). For maps that live in the long tail (caches,
 * lookup tables) this is negligible; for many short-lived maps the
 * cost adds up.
 */

#ifndef POC_ERASED_MAP_INLINE_VT_H
#define POC_ERASED_MAP_INLINE_VT_H

#include "erased_map.h"

typedef struct erased_inline_entry_s {
    vader_box_t                  key;
    vader_box_t                  value;
    struct erased_inline_entry_s* next;
} erased_inline_entry_t;

typedef struct {
    erased_inline_entry_t* buckets[POC_NUM_BUCKETS];
    size_t                 size;
    /* Inline dispatch slots. */
    uint64_t (*hash)(vader_box_t);
    bool     (*equals)(vader_box_t, vader_box_t);
} erased_inline_map_t;

void erased_inline_map_init(erased_inline_map_t* m, erased_vtable_t* key_vt);
void erased_inline_map_put(erased_inline_map_t* m, vader_box_t k, vader_box_t v);
bool erased_inline_map_get(erased_inline_map_t* m, vader_box_t k, vader_box_t* o);

#endif
