/* Shared types and helpers for the erasure POC.
 *
 * - `user_t`           — value type stored in the map (representative of a
 *                       small user struct: string + i32, 24-byte payload).
 * - Workload constants — same for both mono and erased implementations.
 * - Key/value generators with fixed seeds for cross-impl determinism.
 */

#ifndef POC_SHARED_H
#define POC_SHARED_H

#include "vader.h"

typedef struct {
    vader_string_t name;
    int32_t        age;
} user_t;

/* Workload sizing. Matches the existing bench/map_iter pattern (1k unique
 * keys, 100k ops) so apples-to-apples comparison to baseline. */
#define POC_NUM_KEYS    1000
#define POC_NUM_OPS     100000
#define POC_NUM_BUCKETS 16

/* Deterministic key + value generators. `idx` is in [0, POC_NUM_KEYS). The
 * returned `vader_string_t` points into a static pool so callers never own
 * the buffer — sufficient for a bench, NOT a general-purpose allocator. */
vader_string_t poc_key(int idx);
user_t         poc_value(int idx);

/* Allocation counter — increments on every `poc_alloc` call. Used to
 * verify criterion #1 (zero allocs per put beyond the entry node). */
extern size_t poc_alloc_count;
void*  poc_alloc(size_t n);
void   poc_reset_alloc_count(void);

#endif
