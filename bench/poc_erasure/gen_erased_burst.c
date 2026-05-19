/* Erased-side equivalent of `gen_mono_burst.c` — one shared erased body
 * (reused from `erased_map.c`) + N vtables, one per concrete key type.
 *
 * The key insight: regardless of `BURST_N`, the heavy code (`put`,
 * `get`, chain walks) is emitted exactly once. Each "instantiation"
 * adds only a vtable struct (~50 bytes of code per entry).
 *
 * `BURST_N` is set at compile time via `-DBURST_N=<n>`.
 */

#include "erased_map.h"
#include <string.h>

#ifndef BURST_N
#define BURST_N 16
#endif

/* Each "instantiation" is just a vtable + thin shim. The shim variants
 * differ only in the underlying key-hash function. For the POC we reuse
 * string hashing across all N — what matters is the *count* of vtables
 * the compiler has to lay out, not their diversity. */

#define DEFINE_ERASED_VT(N) \
static uint64_t burst_vt_##N##_hash(vader_box_t b) { \
    return vader_string_hash(b.payload.s) + (uint64_t)(N); \
} \
static bool burst_vt_##N##_equals(vader_box_t a, vader_box_t b) { \
    return vader_string_eq(a.payload.s, b.payload.s); \
} \
erased_vtable_t burst_vt_##N = { \
    .hash   = burst_vt_##N##_hash, \
    .equals = burst_vt_##N##_equals, \
};

#define R1   DEFINE_ERASED_VT(0)
#define R2   R1   DEFINE_ERASED_VT(1)
#define R4   R2   DEFINE_ERASED_VT(2)  DEFINE_ERASED_VT(3)
#define R8   R4   DEFINE_ERASED_VT(4)  DEFINE_ERASED_VT(5)  DEFINE_ERASED_VT(6)  DEFINE_ERASED_VT(7)
#define R16  R8   DEFINE_ERASED_VT(8)  DEFINE_ERASED_VT(9)  DEFINE_ERASED_VT(10) DEFINE_ERASED_VT(11) \
                  DEFINE_ERASED_VT(12) DEFINE_ERASED_VT(13) DEFINE_ERASED_VT(14) DEFINE_ERASED_VT(15)
#define R32  R16  DEFINE_ERASED_VT(16) DEFINE_ERASED_VT(17) DEFINE_ERASED_VT(18) DEFINE_ERASED_VT(19) \
                  DEFINE_ERASED_VT(20) DEFINE_ERASED_VT(21) DEFINE_ERASED_VT(22) DEFINE_ERASED_VT(23) \
                  DEFINE_ERASED_VT(24) DEFINE_ERASED_VT(25) DEFINE_ERASED_VT(26) DEFINE_ERASED_VT(27) \
                  DEFINE_ERASED_VT(28) DEFINE_ERASED_VT(29) DEFINE_ERASED_VT(30) DEFINE_ERASED_VT(31)
#define R45  R32  DEFINE_ERASED_VT(32) DEFINE_ERASED_VT(33) DEFINE_ERASED_VT(34) DEFINE_ERASED_VT(35) \
                  DEFINE_ERASED_VT(36) DEFINE_ERASED_VT(37) DEFINE_ERASED_VT(38) DEFINE_ERASED_VT(39) \
                  DEFINE_ERASED_VT(40) DEFINE_ERASED_VT(41) DEFINE_ERASED_VT(42) DEFINE_ERASED_VT(43) \
                  DEFINE_ERASED_VT(44)

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
