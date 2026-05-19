/* Multi-instantiation cc -O3 stress — informs criterion #3.
 *
 * Generates N copies of the monomorphised map body (one per unique
 * value type), each as a distinct struct + put/get/each function set.
 * Models what the compiler emits today for N different (K, V) pairs.
 *
 * `BURST_N` is set at compile time via `-DBURST_N=<n>`. Default 16.
 */

#include "shared.h"
#include <string.h>

#ifndef BURST_N
#define BURST_N 16
#endif

/* Each instantiation gets a unique value payload type. To keep this
 * representative of real generics, the value is a 24-byte struct (same
 * as `user_t` baseline) so the layout matches the mono baseline. */

#define DEFINE_MONO(N) \
typedef struct { \
    vader_string_t s; \
    int32_t        a; \
    int32_t        b; \
} val##N##_t; \
typedef struct burst_entry_##N##_s { \
    vader_string_t              key; \
    val##N##_t                  value; \
    struct burst_entry_##N##_s* next; \
} burst_entry_##N##_t; \
typedef struct { \
    burst_entry_##N##_t* buckets[POC_NUM_BUCKETS]; \
    size_t               size; \
} burst_map_##N##_t; \
__attribute__((noinline)) \
void burst_put_##N(burst_map_##N##_t* m, vader_string_t k, val##N##_t v) { \
    uint64_t h = vader_string_hash(k); \
    int idx = (int)(h % POC_NUM_BUCKETS); \
    for (burst_entry_##N##_t* cur = m->buckets[idx]; cur; cur = cur->next) { \
        if (vader_string_eq(cur->key, k)) { cur->value = v; return; } \
    } \
    burst_entry_##N##_t* node = (burst_entry_##N##_t*)poc_alloc(sizeof *node); \
    node->key = k; node->value = v; node->next = m->buckets[idx]; \
    m->buckets[idx] = node; m->size++; \
} \
__attribute__((noinline)) \
bool burst_get_##N(burst_map_##N##_t* m, vader_string_t k, val##N##_t* o) { \
    uint64_t h = vader_string_hash(k); \
    int idx = (int)(h % POC_NUM_BUCKETS); \
    for (burst_entry_##N##_t* cur = m->buckets[idx]; cur; cur = cur->next) { \
        if (vader_string_eq(cur->key, k)) { *o = cur->value; return true; } \
    } \
    return false; \
}

/* Roll out BURST_N copies by hand-listing IDs — preprocessor can't loop. */
#define R1   DEFINE_MONO(0)
#define R2   R1   DEFINE_MONO(1)
#define R4   R2   DEFINE_MONO(2)  DEFINE_MONO(3)
#define R8   R4   DEFINE_MONO(4)  DEFINE_MONO(5)  DEFINE_MONO(6)  DEFINE_MONO(7)
#define R16  R8   DEFINE_MONO(8)  DEFINE_MONO(9)  DEFINE_MONO(10) DEFINE_MONO(11) \
                  DEFINE_MONO(12) DEFINE_MONO(13) DEFINE_MONO(14) DEFINE_MONO(15)
#define R32  R16  DEFINE_MONO(16) DEFINE_MONO(17) DEFINE_MONO(18) DEFINE_MONO(19) \
                  DEFINE_MONO(20) DEFINE_MONO(21) DEFINE_MONO(22) DEFINE_MONO(23) \
                  DEFINE_MONO(24) DEFINE_MONO(25) DEFINE_MONO(26) DEFINE_MONO(27) \
                  DEFINE_MONO(28) DEFINE_MONO(29) DEFINE_MONO(30) DEFINE_MONO(31)
#define R45  R32  DEFINE_MONO(32) DEFINE_MONO(33) DEFINE_MONO(34) DEFINE_MONO(35) \
                  DEFINE_MONO(36) DEFINE_MONO(37) DEFINE_MONO(38) DEFINE_MONO(39) \
                  DEFINE_MONO(40) DEFINE_MONO(41) DEFINE_MONO(42) DEFINE_MONO(43) \
                  DEFINE_MONO(44)

#if   BURST_N == 1
R1
#elif BURST_N == 2
R2
#elif BURST_N == 4
R4
#elif BURST_N == 8
R8
#elif BURST_N == 16
R16
#elif BURST_N == 32
R32
#elif BURST_N == 45
R45
#else
#  error "Pick BURST_N in {1,2,4,8,16,32,45}"
#endif
