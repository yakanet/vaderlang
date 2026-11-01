/* Vader native runtime: implementation. See `vader.h` for the public API.
 *
 * Memory model: generational GC, a copying (Cheney) young generation and a
 * NON-MOVING mark-sweep old generation. Young is a pair of semi-spaces;
 * `vader_gc_alloc` bumps the young from-space; on overflow, `vader_minor_collect`
 * promotes the young survivors whose `age` reaches the tenure threshold into the
 * old slab (a single lazily-committed reservation carved into size-class
 * regions, see rt/gc_heap.c) and copies the others to young to-space. A
 * `vader_major_collect` drains young, then marks the live old set (roots + young
 * survivors + a conservative C-stack scan) and sweeps the dead in place: old
 * objects never move. `vader_old_maybe_major` fires a major once dead old
 * accumulates past a headroom factor. Cross-generation references are tracked by
 * a card table written from the C-emit-issued `VADER_WRITE_BARRIER` macro and
 * consumed as additional roots by minor.
 */

/* The runtime builds as ONE translation unit: this file includes its parts, so
 * everything internal to it stays `static` (inlined, merged, never seen by the
 * linker). What one part uses from another is declared in rt/internal.h.
 * No include goes above the first part: rt/internal.h defines `_DEFAULT_SOURCE`,
 * which only counts ahead of the first system header. */

#include "rt/defer_traps.c"
#include "rt/gc_heap.c"
#include "rt/gc_collect.c"
#include "rt/gc_diag.c"
#include "rt/atoms.c"
#include "rt/atoms_gc.c"
#include "rt/strings.c"
#include "rt/arrays.c"
#include "rt/host.c"
#include "rt/ffi.c"
