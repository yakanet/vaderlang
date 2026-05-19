/* Erased map — models what the post-erasure lowered IR would emit.
 *
 * One struct, one function set, indirect dispatch on key operations
 * through a per-key-type vtable. Keys and values are passed as
 * `vader_box_t` (the runtime universal pointer). The vtable carries
 * the concrete `hash` / `equals` implementations.
 *
 * Vtable layout: external table indexed by tag. The vtable pointer is
 * stored on the map struct (one per map, shared by all keys). The
 * alternative — in-box vtable pointer growing `vader_box_t` from 24 to
 * 32 bytes — is not implemented in this POC (deferred per
 * `docs/STDLIB_GENERIC_COLLAPSE_POC.md` §5 criterion #5).
 */

#ifndef POC_ERASED_MAP_H
#define POC_ERASED_MAP_H

#include "shared.h"

typedef struct {
    uint64_t (*hash)(vader_box_t);
    bool     (*equals)(vader_box_t, vader_box_t);
} erased_vtable_t;

typedef struct erased_entry_s {
    vader_box_t            key;
    vader_box_t            value;
    struct erased_entry_s* next;
} erased_entry_t;

typedef struct {
    erased_entry_t*  buckets[POC_NUM_BUCKETS];
    size_t           size;
    erased_vtable_t* key_vt;
} erased_map_t;

void erased_map_init(erased_map_t* m, erased_vtable_t* key_vt);
void erased_map_put(erased_map_t* m, vader_box_t key, vader_box_t value);
bool erased_map_get(erased_map_t* m, vader_box_t key, vader_box_t* out);

void erased_map_each(
    erased_map_t* m,
    int (*callback)(vader_box_t key, vader_box_t value, void* ctx),
    void* ctx
);

/* Box helpers — model what the lower would emit at boundaries.
 *
 * Strings inline (fat-ptr fits in the 16-byte string slot of the box
 * union → already inline today, no extra alloc).
 *
 * User payloads do NOT fit in 8 bytes → boxing allocates a heap copy.
 * Extra alloc per box, exactly the issue Phase 1 (inline-box
 * generalisation) targets.
 *
 * i64 inlines (fits in `payload.i`). */
vader_box_t box_string(vader_string_t s);
vader_box_t box_user(user_t u);
vader_box_t box_i64(int64_t v);

vader_string_t unbox_string(vader_box_t b);
user_t         unbox_user(vader_box_t b);
int64_t        unbox_i64(vader_box_t b);

/* Pre-baked vtables for the bench. */
extern erased_vtable_t string_key_vtable;

/* Tag constants — emitter would generate these per BcType. We pick fixed
 * indices for the POC. */
#define POC_TAG_STRING 1u
#define POC_TAG_USER   2u
#define POC_TAG_I64    3u

#endif
