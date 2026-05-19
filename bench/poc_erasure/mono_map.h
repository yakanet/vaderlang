/* Monomorphised map for `MutableMap<string, user_t>`.
 *
 * Representative of what the Vader compiler emits today for one (K, V)
 * instantiation: a dedicated struct, dedicated put/get functions, direct
 * calls to `vader_string_hash` / `vader_string_eq`. No vtable, no
 * indirection.
 *
 * Bucket count is fixed (no resize) — matches `std/collections.vader`
 * MVP. Chaining for collisions.
 */

#ifndef POC_MONO_MAP_H
#define POC_MONO_MAP_H

#include "shared.h"

typedef struct mono_entry_s {
    vader_string_t       key;
    user_t               value;
    struct mono_entry_s* next;
} mono_entry_t;

typedef struct {
    mono_entry_t* buckets[POC_NUM_BUCKETS];
    size_t        size;
} mono_map_t;

void mono_map_init(mono_map_t* m);
void mono_map_put(mono_map_t* m, vader_string_t key, user_t value);
bool mono_map_get(mono_map_t* m, vader_string_t key, user_t* out);

/* Iterator: visits every entry in insertion-independent bucket order. The
 * `callback` returns 0 to continue, non-zero to abort early. `ctx` is
 * passed through opaque. */
void mono_map_each(
    mono_map_t* m,
    int (*callback)(vader_string_t key, user_t value, void* ctx),
    void* ctx
);

/* ---- Second instantiation: MutableMap<string, i64> ----
 * Used to measure cc -O3 cost on multi-instantiation (criterion #3) and
 * to verify criterion #1 (i64 fits inline in vader_box_t.payload.i, so
 * the erased equivalent should have zero extra alloc per put). */

typedef struct mono_i64_entry_s {
    vader_string_t           key;
    int64_t                  value;
    struct mono_i64_entry_s* next;
} mono_i64_entry_t;

typedef struct {
    mono_i64_entry_t* buckets[POC_NUM_BUCKETS];
    size_t            size;
} mono_i64_map_t;

void mono_i64_map_init(mono_i64_map_t* m);
void mono_i64_map_put(mono_i64_map_t* m, vader_string_t key, int64_t value);
bool mono_i64_map_get(mono_i64_map_t* m, vader_string_t key, int64_t* out);

#endif
