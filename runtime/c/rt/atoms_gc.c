/* rt/atoms_gc.c: the atoms' own mark and sweep, run by every major.
 *
 * An atom stays while a root, a live object or the C stack still names it. */

#include "internal.h"

/* The atom GC runs inside the major collection. `vader_atom_mark_roots` walks FIVE
 * channels, and none is redundant : an atom only one of them reaches is freed
 * while still live if that channel goes :
 *   - frame `ptrs[]` boxes (conservative : the lower 4 bytes of every box
 *     payload are treated as a candidate atom id)
 *   - frame `stack_objs[]`, off-arena so the heap walk cannot reach them
 *   - frame `atoms[]`: the only PRECISE atom root ; a `vader_string_t` is an
 *     id, not a pointer, so nothing else can see a bare string local
 *   - defer stack
 *   - `vader_atom_mark_cstack_conservative` : what the precise rooting misses
 * Unmarked non-PERM atoms have their data buffer freed and the slot
 * tombstoned ; the bucket index is rebuilt in one pass. */

static void vader_atom_mark(vader_atom_t a) {
    if (a == VADER_ATOM_EMPTY || a >= g_atoms.count) return;
    vader_atom_entry_t* e = &vader_atom_entries[a];
    if (e->flags & (VADER_ATOM_FLAG_PERM | VADER_ATOM_FLAG_MARK)) return;
    e->flags |= VADER_ATOM_FLAG_MARK;
    /* Slice → owner : keep the parent alive too. Chain depth is at
     * most 1 (the slice ctor flattens), so no recursion needed. */
    if (e->parent != 0 && e->parent < g_atoms.count) {
        vader_atom_entry_t* p = &vader_atom_entries[e->parent];
        if ((p->flags & VADER_ATOM_FLAG_PERM) == 0) {
            p->flags |= VADER_ATOM_FLAG_MARK;
        }
    }
}

static void vader_atom_mark_box(const vader_box_t* bp) {
    if (bp == NULL) return;
    /* Conservatively treat the lower 4 bytes of `payload.s` as an atom
     * id. False positives keep extra atoms alive ; no correctness
     * impact. The 8-byte `payload.i` alias is read once to avoid
     * union-field type-punning warnings. */
    vader_atom_mark((vader_atom_t) (uint32_t) bp->payload.i);
}

/* Conservatively mark atoms reachable only from a C local / register. A
 * `vader_string_t` is a bare `u32` atom id, so unlike object refs it never
 * appears in the shadow stack or as a heap pointer: held in a C local it is
 * invisible to the precise roots and the heap walk. Flush registers (setjmp),
 * then read every 4-byte-aligned stack word as a candidate atom id and mark it
 * (`vader_atom_mark` bounds-checks; false positives only retain a small atom).
 * The non-moving old gen reuses freed slots eagerly, so (as for objects) a
 * live atom held only in a C local must be found here or its bytes get reclaimed
 * under a still-live `bytes()` view. Scanned 4-byte-aligned because a u32
 * local need not be 8-aligned. */
static void vader_atom_mark_cstack_conservative(void) {
    jmp_buf regs;
    (void) setjmp(regs);
    char* base = vader_cstack_base();
    if (base == NULL) return;
    char* lo = (char*) ((uintptr_t) &regs & ~(uintptr_t)3u);
    if (lo >= base) return;
    for (char* p = lo; p + sizeof(uint32_t) <= base; p += sizeof(uint32_t)) {
        vader_atom_mark((vader_atom_t) *(uint32_t volatile*) p);
    }
}

/* Forward decl: the stack-object root walk below needs it, and its definition
 * sits after this function so the heap walk reads top-down. */
static void vader_atom_mark_object(char* scan, uint32_t type_index, void* ctx);

static void vader_atom_mark_roots(void) {
    for (vader_gc_frame_t* fr = vader_gc_top; fr != NULL; fr = fr->prev) {
        if (fr->ptrs != NULL) {
            for (uint32_t i = 0; i < fr->nrefs; i++) {
                vader_atom_mark_box(fr->ptrs[i]);
            }
        }
        /* Stack objects are OFF-ARENA, so `vader_atom_mark_heap` (young
         * from-space plus the live old slots) never reaches them. Redundant
         * with `vader_atom_mark_cstack_conservative`, since their fields do sit
         * on the C stack.
         *
         * Guard each list on its own, NOT the frame: a frame carrying stack
         * objects and no box roots must not be skipped whole. */
        if (fr->stack_objs != NULL) {
            for (uint32_t i = 0; i < fr->nstack; i++) {
                char* o = (char*) fr->stack_objs[i];
                if (o != NULL) {
                    vader_atom_mark_object(o, ((vader_obj_header_t*) o)->type_index, NULL);
                }
            }
        }
        /* String locals. A `vader_string_t` is an atom ID, not a pointer, so it
         * cannot appear in `ptrs` or `raw`: this list is the only PRECISE root
         * an atom has. */
        if (fr->atoms != NULL) {
            for (uint32_t i = 0; i < fr->natoms; i++) {
                if (fr->atoms[i] != NULL) {
                    vader_atom_mark(*fr->atoms[i]);
                }
            }
        }
    }
    for (size_t i = 0; i < g_defer_len; i++) {
        vader_atom_mark_box(&g_defer_stack[i]);
    }
    vader_atom_mark_cstack_conservative();
}

/* Mark every atom referenced by one heap object's slots (string fields, borrowed
 * byte-view owner, conservative box payloads). Shared by the young contiguous
 * walk and the old region walk. */
static void vader_atom_mark_object(char* scan, uint32_t type_index, void* ctx) {
    (void) ctx;
    if (type_index == VADER_TYPE_INDEX_ARRAY_BUF) {
        vader_array_buf_t* buf = (vader_array_buf_t*) scan;
        if (buf->element_kind == VADER_ARRAY_KIND_BOXED) {
            vader_box_t* slots = vader_array_box_slots(buf);
            for (size_t i = 0; i < buf->length; i++) {
                vader_atom_mark_box(&slots[i]);
            }
        }
    } else if (type_index < vader_type_info_count) {
        const vader_type_info_t* info = &vader_type_info_table[type_index];
        /* Precise : string fields from the type_info table. */
        for (uint16_t i = 0; i < info->string_count; i++) {
            vader_string_t* sp = (vader_string_t*) (scan + info->string_offsets[i]);
            vader_atom_mark(*sp);
        }
        /* Borrowed `const u8[]` byte view (`vader_string_bytes_view`) : the array
         * header carries no string field, but its `capacity` low 32 bits hold the
         * owner atom id whose interned bytes the view aliases. Mark it so the
         * bytes aren't swept under us. */
        if (info->kind == VADER_TYPE_KIND_ARRAY) {
            vader_array_t* arr = (vader_array_t*) scan;
            if (vader_array_is_borrowed(arr)) {
                vader_atom_mark(vader_array_borrowed_owner(arr));
            }
        }
        /* Conservative : box fields. The payload's lower 4 bytes may be an atom
         * (for string-tagged variants) or any other primitive ; conservativeness
         * keeps the latter from accidentally collecting a live atom. */
        for (uint16_t i = 0; i < info->ptr_count; i++) {
            vader_atom_mark_box((vader_box_t*) (scan + info->ptr_offsets[i]));
        }
    }
}

static void vader_atom_mark_heap(void) {
    vader_young_foreach(vader_atom_mark_object, NULL);
    vader_old_foreach_live(vader_atom_mark_object, NULL);
}

static void vader_atom_free_list_push(vader_u32_t id) {
    if (g_atoms.free_count >= g_atoms.free_capacity) {
        size_t new_cap = g_atoms.free_capacity == 0 ? 64u : (size_t) g_atoms.free_capacity * 2u;
        vader_u32_t* p = (vader_u32_t*) realloc(g_atoms.free_list, new_cap * sizeof(vader_u32_t));
        if (p == NULL) vader_trap("vader_atom_free_list_push: realloc failed");
        g_atoms.free_list = p;
        g_atoms.free_capacity = (vader_u32_t) new_cap;
    }
    g_atoms.free_list[g_atoms.free_count++] = id;
}

static void vader_atom_sweep(void) {
    size_t freed_bytes = 0;
    for (vader_u32_t i = 1; i < g_atoms.count; i++) {
        vader_atom_entry_t* e = &vader_atom_entries[i];
        if (e->flags & VADER_ATOM_FLAG_PERM) continue;
        /* Skip already-tombstoned slots (data NULL means reclaimed in a
         * previous sweep ; they live in the free list). */
        if (e->data == NULL && e->len == 0 && e->parent == 0) continue;
        if (e->flags & VADER_ATOM_FLAG_MARK) {
            e->flags &= ~VADER_ATOM_FLAG_MARK;
            continue;
        }
        if (e->parent == 0 && e->data != NULL && e->len > 0) {
            freed_bytes += e->len;
            free((void*) e->data);
        }
        e->parent        = 0;
        e->parent_offset = 0;
        e->len           = 0;
        e->flags         = 0;
        e->data          = NULL;
        vader_atom_free_list_push(i);
    }
    if (freed_bytes > g_atoms.owner_bytes) g_atoms.owner_bytes = 0;
    else g_atoms.owner_bytes -= freed_bytes;

    /* Rebuild the hash index. Bucket clears + linear reinsert keeps the
     * implementation simple ; incremental updates would need to track
     * each tombstone's original hash to clear specifically. */
    memset(g_atoms.buckets, 0, g_atoms.bucket_capacity * sizeof(uint64_t));
    g_atoms.bucket_count = 0;
    for (vader_u32_t i = 1; i < g_atoms.count; i++) {
        const vader_atom_entry_t* e = &vader_atom_entries[i];
        if (e->data == NULL) continue;
        vader_atom_bucket_install(i);
    }
}

void vader_atom_gc_collect(void) {
    if (!g_atoms_initialized) return;
    vader_atom_mark_roots();
    vader_atom_mark_heap();
    vader_atom_sweep();
}
