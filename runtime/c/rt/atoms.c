/* rt/atoms.c: the atom table. A string is an index into it.
 *
 * Interning, slices of an atom, the hash, and the C-string views. */

#include "internal.h"

static vader_atom_table_t g_atoms = {0};

/* The entries array itself lives OUTSIDE the table struct, as a public global,
 * so `vader.h` can define the lookup helpers `static inline`: every `s[i]` in
 * emitted code reads them, so they must inline at the call site rather than
 * cost an out-of-line cross-TU call.
 *
 * The only pointer to the entries: a copy kept in the table struct would go
 * stale on the next realloc. */
vader_atom_entry_t* vader_atom_entries = NULL;

/* With several workers: the lock over the ids (`count`, the free list, the
 * growth of the entries), and the entries, which then never move, since emitted
 * code reads them with no lock (`vader.h`). The reservation holds
 * `g_atom_reserved` entries, committed as the table grows. */
static vader_os_lock_t* g_atom_guard = NULL;

/* The pool runs: the shards take their spin locks, and an index a shard leaves
 * stays until the next sweep. */
static int vader_atom_pooled(void) {
    return g_atom_guard != NULL;
}
static vader_u32_t g_atom_reserved = 0;
#define VADER_ATOM_RESERVED_ENTRIES (1u << 28)
static int  g_atoms_initialized = 0;
static int  g_atom_profile = 0;

/* Initial table capacities, grown by doubling. A module that carries a
 * comptime atom count raises both to fit it:
 * `vader_atom_init_with_comptime`. */
#define VADER_ATOM_INITIAL_CAPACITY    256u
#define VADER_ATOM_INITIAL_SLOTS       1024u   /* over all shards: a power of two */

/* The ids a thread takes from the table at once, so that creating an atom takes
 * the lock over the ids once per batch. */
#define VADER_ATOM_ID_BATCH 256u
static _Thread_local vader_u32_t t_atom_ids[VADER_ATOM_ID_BATCH];
static _Thread_local vader_u32_t t_atom_ids_len = 0;

/* Forward decls: implementations below cluster by concern. */
static void        vader_atom_install_empty(void);
static uint64_t    vader_atom_hash64(const char* data, size_t len);
static void        vader_atom_profile_dump(void);
static vader_atom_index_t* vader_atom_index_new(vader_u32_t capacity);
static uintptr_t   vader_atom_index_word(const vader_atom_index_t* index);
static void        vader_atom_shard_add(vader_u32_t shard, vader_atom_t a, uint64_t hash);

void vader_atom_init_with_comptime(const vader_atom_entry_t* comptime_table,
                                   vader_u32_t count) {
    /* The emitted `main` calls atom-init first, so this is the one place every
     * C-emitted binary passes through at start: the process-wide settings of
     * the standard streams and of SIGPIPE go here. */
    vader_os_ensure_stdio_binary();
    vader_os_catch_broken_pipes();
    if (g_atoms_initialized) return;
    g_atoms_initialized = 1;

    const char* prof_env = getenv("VADER_ATOM_PROFILE");
    if (prof_env != NULL && prof_env[0] != '\0' && prof_env[0] != '0') {
        g_atom_profile = 1;
        /* `vader_atom_shutdown` dumps the profile before tearing down,
         * so no atexit hook is needed here: atexit's LIFO order would
         * fire the dump *after* shutdown has zeroed the table. */
    }

    /* Pick a capacity that absorbs the comptime atoms plus headroom for
     * the first wave of dynamic interns without an immediate grow. */
    vader_u32_t initial_cap = VADER_ATOM_INITIAL_CAPACITY;
    if (count > 0u) {
        /* count + 1 for the empty sentinel at index 0, then doubled for
         * runtime headroom. Never below the default capacity, so a very
         * small module still gets a usable starting table. */
        vader_u32_t want = (count + 1u) * 2u;
        if (want > initial_cap) initial_cap = want;
    }
    vader_atom_entries = (vader_atom_entry_t*)
        malloc(initial_cap * sizeof(vader_atom_entry_t));
    if (vader_atom_entries == NULL) vader_trap("vader_atom_init_with_comptime: entries malloc failed");
    g_atoms.capacity = initial_cap;
    g_atoms.count    = 0;

    /* Bucket capacity scales with comptime count for the same reason:
     * a freshly initialised table should not immediately rehash on the
     * first user interns. Round up to a power of two >= 4 * (count + 1). */
    vader_u32_t want_slots = VADER_ATOM_INITIAL_SLOTS;
    if (count > 0u) {
        vader_u32_t target = (count + 1u) * 4u;
        while (want_slots < target) want_slots *= 2u;
    }
    vader_u32_t shard_slots = want_slots / VADER_ATOM_SHARDS;
    if (shard_slots < 16u) shard_slots = 16u;
    for (vader_u32_t i = 0; i < VADER_ATOM_SHARDS; i++) {
        g_atoms.indexes[i] = vader_atom_index_word(vader_atom_index_new(shard_slots));
        g_atoms.writers[i].busy = 0;
        g_atoms.writers[i].used = 0;
    }

    g_atoms.free_list     = NULL;
    g_atoms.free_count    = 0;
    g_atoms.free_capacity = 0;

    vader_atom_install_empty();

    /* Comptime atoms come in PERM, never freed, rodata-backed. Their
     * `data` pointer is owned by the binary's `.rodata` section, so the
     * shutdown path must skip the `free(data)` step on these entries. */
    if (count > 0u && comptime_table != NULL) {
        memcpy(&vader_atom_entries[1], comptime_table,
               count * sizeof(vader_atom_entry_t));
        g_atoms.count = 1u + count;
        /* Force PERM on every comptime entry: the codegen-emitted
         * table sets it too, but enforcing here keeps the runtime
         * invariant local. */
        for (vader_u32_t i = 1; i < g_atoms.count; ++i) {
            vader_atom_entries[i].flags |= VADER_ATOM_FLAG_PERM;
        }
        /* Index the comptime atoms where the memcpy put them: emitted
         * code names each one by its position in the table. */
        for (vader_u32_t i = 1; i < g_atoms.count; ++i) {
            vader_atom_entry_t* e = &vader_atom_entries[i];
            /* Codegen's positional comptime-table literals omit `hash` (it
             * zero-fills) and the ASCII flag: derive both here so comptime
             * atoms read like any interned string. */
            e->hash   = vader_atom_hash64(e->data, e->len);
            e->flags |= vader_atom_ascii_flag(e->data, e->len);
            vader_atom_shard_add(vader_atom_shard_of(e->hash), i, e->hash);
        }
    }
}

/* Install VADER_ATOM_EMPTY at index 0 with PERM flag. No bucket entry:
 * the empty string is reached by direct `a == 0` checks, never via hash
 * probe : every intern entrypoint short-circuits `len == 0`. */
static void vader_atom_install_empty(void) {
    vader_atom_entry_t* e = &vader_atom_entries[0];
    e->parent        = 0;
    e->parent_offset = 0;
    e->len           = 0;
    e->flags         = VADER_ATOM_FLAG_PERM | VADER_ATOM_FLAG_ASCII;
    e->_pad          = 0;
    e->data          = "";
    e->hash          = vader_atom_hash64("", 0);
    g_atoms.count    = 1;
}

void vader_atom_shutdown(void) {
    if (!g_atoms_initialized) return;
    /* Dump the profile before tearing down: the table is still live here. */
    if (g_atom_profile) vader_atom_profile_dump();
    for (vader_u32_t i = 1; i < g_atoms.count; ++i) {
        vader_atom_entry_t* e = &vader_atom_entries[i];
        /* Free owner buffers from dynamic intern only: PERM entries
         * carry rodata pointers we must NOT free. Slice atoms borrow
         * from their parent ; no free either. The static empty-string
         * at index 0 is excluded by the loop bound. */
        if (e->parent == 0 && e->data != NULL && e->len > 0
            && (e->flags & VADER_ATOM_FLAG_PERM) == 0) {
            free((void*) e->data);
        }
    }
    if (g_atom_reserved == 0u) free(vader_atom_entries);
    for (vader_u32_t i = 0; i < VADER_ATOM_SHARDS; i++) {
        vader_atom_index_free(vader_atom_index_of(i));
        g_atoms.indexes[i] = 0;
    }
    free(g_atoms.free_list);
    vader_atom_entries      = NULL;
    g_atoms.free_list       = NULL;
    g_atoms.count           = 0;
    g_atoms.capacity        = 0;
    g_atoms.free_count      = 0;
    g_atoms.free_capacity   = 0;
    g_atoms_initialized     = 0;
}

/* ---- intern internals ---------------------------------------------------- */

/* The pieces the atom hash is built from: unaligned reads in the host's byte
 * order, and the 64 x 64 -> 128-bit multiply, taken from `__uint128_t`: only a
 * 64-bit GCC or clang builds this file. */
static inline uint64_t vader_wy_read8(const uint8_t* p) { uint64_t v; memcpy(&v, p, 8); return v; }
static inline uint64_t vader_wy_read4(const uint8_t* p) { uint32_t v; memcpy(&v, p, 4); return v; }
static inline uint64_t vader_wy_read3(const uint8_t* p, size_t k) {
    return (((uint64_t) p[0]) << 16) | (((uint64_t) p[k >> 1]) << 8) | p[k - 1];
}
static inline void vader_wy_mum(uint64_t* a, uint64_t* b) {
    __uint128_t r = (__uint128_t) *a * *b;
    *a = (uint64_t) r;
    *b = (uint64_t) (r >> 64);
}
static inline uint64_t vader_wy_mix(uint64_t a, uint64_t b) {
    vader_wy_mum(&a, &b);
    return a ^ b;
}

/* The atom table's ONE hash, with the structure of wyhash (final version 4,
 * public domain): eight bytes at a time, each block folded through a 128-bit
 * multiply. Computed once at insert: cached on the entry (returned O(1) by
 * `vader_string_hash` for `string`'s `Hash` trait), its top bits pick the shard
 * of the table and its low 32 bits the slot, which keeps them, so the probe
 * passes over other atoms without reading their entries. Both ends must stay
 * well mixed. The VM reads the same cached value, so the native and
 * VM backends agree on every string's `hash()`. Every target must also compute
 * the same value from the same bytes: a value the compiler computes reaches the
 * program through `@comptime` data, and `content.hash()` names generated files
 * (`lib/toolchain/build/generate.vader`). */
static uint64_t vader_atom_hash64(const char* data, size_t len) {
    static const uint64_t s0 = 0x2d358dccaa6c78a5ull, s1 = 0x8bb84b93962eacc9ull,
                          s2 = 0x4b33a62ed433d4a3ull, s3 = 0x4d5a2da51de1aa47ull;
    const uint8_t* p = (const uint8_t*) data;
    uint64_t seed = 0xca813bf4c7abf0a9ull;    /* vader_wy_mix(s0, s1) */
    uint64_t a, b;
    if (len <= 16) {
        if (len >= 4) {
            a = (vader_wy_read4(p) << 32) | vader_wy_read4(p + ((len >> 3) << 2));
            b = (vader_wy_read4(p + len - 4) << 32) | vader_wy_read4(p + len - 4 - ((len >> 3) << 2));
        } else if (len > 0) {
            a = vader_wy_read3(p, len);
            b = 0;
        } else {
            a = b = 0;
        }
    } else {
        size_t i = len;
        if (i > 48) {
            uint64_t see1 = seed, see2 = seed;
            do {
                seed = vader_wy_mix(vader_wy_read8(p) ^ s1, vader_wy_read8(p + 8) ^ seed);
                see1 = vader_wy_mix(vader_wy_read8(p + 16) ^ s2, vader_wy_read8(p + 24) ^ see1);
                see2 = vader_wy_mix(vader_wy_read8(p + 32) ^ s3, vader_wy_read8(p + 40) ^ see2);
                p += 48;
                i -= 48;
            } while (i > 48);
            seed ^= see1 ^ see2;
        }
        while (i > 16) {
            seed = vader_wy_mix(vader_wy_read8(p) ^ s1, vader_wy_read8(p + 8) ^ seed);
            i -= 16;
            p += 16;
        }
        /* The last 16 bytes, overlapping the blocks above when `len` is not a
         * multiple of 16: the read stays inside the string, whose length passed 16. */
        a = vader_wy_read8(p + i - 16);
        b = vader_wy_read8(p + i - 8);
    }
    a ^= s1;
    b ^= seed;
    vader_wy_mum(&a, &b);
    return vader_wy_mix(a ^ s0 ^ len, b ^ s1);
}

/* `VADER_ATOM_FLAG_ASCII` when every byte of `data[0..len]` is below 0x80, else 0.
 * Run when an atom is created, never on a lookup that finds one. Without an early
 * exit, the C compiler vectorises the loop. */
static vader_u16_t vader_atom_ascii_flag(const char* data, size_t len) {
    vader_u8_t bits = 0;
    for (size_t i = 0; i < len; ++i) {
        bits |= (vader_u8_t) data[i];
    }
    if (bits >= 0x80u) return 0;
    return VADER_ATOM_FLAG_ASCII;
}

/* The shard of the atoms whose hash is `hash`: its top bits, which the slot
 * index of a shard, taken from the low bits, leaves well mixed. */
static vader_u32_t vader_atom_shard_of(uint64_t hash) {
    return (vader_u32_t) (hash >> (64u - VADER_ATOM_SHARD_BITS));
}

#define VADER_ATOM_INDEX_ALIGN 64u

static vader_atom_index_t* vader_atom_index_new(vader_u32_t capacity) {
    size_t bytes = sizeof(vader_atom_index_t) + (size_t) capacity * sizeof(uint64_t);
    char* block = (char*) calloc(1, bytes + VADER_ATOM_INDEX_ALIGN);
    if (block == NULL) vader_trap("vader_atom_index_new: calloc failed");
    uintptr_t at = ((uintptr_t) block + VADER_ATOM_INDEX_ALIGN - 1u) & ~(uintptr_t) (VADER_ATOM_INDEX_ALIGN - 1u);
    vader_atom_index_t* index = (vader_atom_index_t*) at;
    index->block = block;
    index->capacity = capacity;
    return index;
}

/* Free `index` and the indexes it replaced. */
static void vader_atom_index_free(vader_atom_index_t* index) {
    while (index != NULL) {
        vader_atom_index_t* retired = index->retired;
        free(index->block);
        index = retired;
    }
}

/* The word a reader loads for `index`: its address and the log2 of its
 * capacity. */
static uintptr_t vader_atom_index_word(const vader_atom_index_t* index) {
    uintptr_t log2 = 0;
    while (((vader_u32_t) 1u << log2) < index->capacity) log2++;
    return (uintptr_t) index | log2;
}

static vader_atom_index_t* vader_atom_index_in(uintptr_t word) {
    return (vader_atom_index_t*) (word & ~(uintptr_t) (VADER_ATOM_INDEX_ALIGN - 1u));
}

/* The index of `shard`, for its writers or while no reader runs. */
static vader_atom_index_t* vader_atom_index_of(vader_u32_t shard) {
    return vader_atom_index_in(g_atoms.indexes[shard]);
}

/* Probe the index of `shard`: the matching atom id, or VADER_ATOM_EMPTY (0) on
 * a miss. Callers short-circuit len==0 before reaching this: the empty atom has
 * no slot. The low 32 bits of the hash pick the slot and sit in it, so a slot
 * holding another hash is passed over without reading `entries[]`.
 *
 * Runs without a lock: an index is published once it is whole, and a slot once
 * its entry is, so each is read past an acquire fence, which one worker, alone
 * to write, does without. An atom installed meanwhile, or in an index that
 * replaced this one, is found again under the lock of the shard. */
static vader_atom_t vader_atom_lookup(vader_u32_t shard, const char* data, size_t len,
                                      uint64_t hash) {
    const int pooled = vader_atom_pooled();
    uintptr_t word = __atomic_load_n(&g_atoms.indexes[shard], __ATOMIC_RELAXED);
    if (pooled) __atomic_thread_fence(__ATOMIC_ACQUIRE);
    const vader_atom_index_t* index = vader_atom_index_in(word);
    const vader_u32_t mask = ((vader_u32_t) 1u << (word & (VADER_ATOM_INDEX_ALIGN - 1u))) - 1u;
    /* The entries move only before the pool starts, when no other thread runs. */
    const vader_atom_entry_t* entries = vader_atom_entries;
    vader_u32_t i = (vader_u32_t) hash & mask;
    for (;;) {
        uint64_t slot = __atomic_load_n(&index->slots[i], __ATOMIC_RELAXED);
        if (slot == 0) return VADER_ATOM_EMPTY;
        if ((slot >> 32) == (vader_u32_t) hash) {
            if (pooled) __atomic_thread_fence(__ATOMIC_ACQUIRE);
            vader_atom_t a = (vader_atom_t) slot;
            const vader_atom_entry_t* e = &entries[a];
            if (e->len == len && memcmp(e->data, data, len) == 0) return a;
        }
        i = (i + 1u) & mask;
    }
}

/* The free slot of `index` for an atom whose hash is `hash`, and what the slot
 * holds once atom `a` takes it: only the low 32 bits of `hash` count. */
static uint64_t* vader_atom_index_room(vader_atom_index_t* index, uint64_t hash) {
    const vader_u32_t mask = index->capacity - 1u;
    vader_u32_t i = (vader_u32_t) hash & mask;
    while (index->slots[i] != 0) {
        i = (i + 1u) & mask;
    }
    return &index->slots[i];
}

static uint64_t vader_atom_slot_value(vader_atom_t a, uint64_t hash) {
    return ((uint64_t) (vader_u32_t) hash << 32) | a;
}

/* Install atom `a` in `index`, which no reader sees yet, or while none runs. */
static void vader_atom_index_put(vader_atom_index_t* index, vader_atom_t a, uint64_t hash) {
    *vader_atom_index_room(index, hash) = vader_atom_slot_value(a, hash);
}

/* Index a freshly minted atom in `shard`, whose writers' lock the caller holds.
 * Past a 0.75 load the shard moves to an index twice as large; a reader may
 * still probe the old one, which is kept until the next sweep, or freed at once
 * while no other worker runs. */
static void vader_atom_shard_add(vader_u32_t shard, vader_atom_t a, uint64_t hash) {
    vader_atom_index_t* index = vader_atom_index_of(shard);
    vader_atom_writer_t* writer = &g_atoms.writers[shard];
    __atomic_store_n(vader_atom_index_room(index, hash), vader_atom_slot_value(a, hash),
                     __ATOMIC_RELEASE);
    writer->used++;
    if (writer->used * 4u <= index->capacity * 3u) return;
    vader_atom_index_t* grown = vader_atom_index_new(index->capacity * 2u);
    for (vader_u32_t i = 0; i < index->capacity; i++) {
        uint64_t slot = index->slots[i];
        if (slot != 0u) vader_atom_index_put(grown, (vader_atom_t) slot, slot >> 32);
    }
    if (!vader_atom_pooled()) {
        grown->retired = index->retired;
        index->retired = NULL;
        vader_atom_index_free(index);
    } else {
        grown->retired = index;
    }
    __atomic_store_n(&g_atoms.indexes[shard], vader_atom_index_word(grown), __ATOMIC_RELEASE);
}

/* Entries grow: double capacity, realloc in place. Pointers into the
 * array are NOT stable across calls ; every reader rederefs through
 * `vader_atom_entries`, so a realloc that relocates the array is safe. */
static void vader_atom_grow_entries(void) {
    if (g_atom_reserved != 0u) {
        if (g_atoms.capacity >= g_atom_reserved) vader_trap("vader_atom_grow_entries: too many strings");
        vader_u32_t cap = g_atoms.capacity * 2u;
        if (cap > g_atom_reserved) cap = g_atom_reserved;
        if (!vader_os_commit((char*) vader_atom_entries, (size_t) cap * sizeof(vader_atom_entry_t))) {
            vader_trap("vader_atom_grow_entries: commit failed");
        }
        g_atoms.capacity = cap;
        return;
    }
    g_atoms.capacity *= 2u;
    vader_atom_entry_t* p = (vader_atom_entry_t*)
        realloc(vader_atom_entries, g_atoms.capacity * sizeof(vader_atom_entry_t));
    if (p == NULL) vader_trap("vader_atom_grow_entries: realloc failed");
    vader_atom_entries = p;
}

static void vader_atom_pool_start(void) {
    if (!g_atoms_initialized) vader_trap("vader_atom_pool_start: the table is not initialised");
    char* reserved = vader_os_reserve((size_t) VADER_ATOM_RESERVED_ENTRIES * sizeof(vader_atom_entry_t));
    size_t used = (size_t) g_atoms.capacity * sizeof(vader_atom_entry_t);
    if (reserved == NULL || !vader_os_commit(reserved, used)) {
        vader_trap("vader_atom_pool_start: no room for the strings");
    }
    memcpy(reserved, vader_atom_entries, (size_t) g_atoms.count * sizeof(vader_atom_entry_t));
    free(vader_atom_entries);
    vader_atom_entries = (vader_atom_entry_t*) reserved;
    g_atom_reserved = VADER_ATOM_RESERVED_ENTRIES;
    g_atom_guard = vader_os_lock_new();
}

/* How many times a shard's lock is tried before its thread gives the processor
 * away: a holder that the OS took off its core holds it for a while. */
#define VADER_ATOM_SPINS 128u

static void vader_atom_shard_lock(vader_u32_t shard) {
    vader_u32_t* busy = &g_atoms.writers[shard].busy;
    vader_u32_t spins = 0;
    while (__atomic_exchange_n(busy, 1u, __ATOMIC_ACQUIRE) != 0u) {
        while (__atomic_load_n(busy, __ATOMIC_RELAXED) != 0u) {
            if (++spins < VADER_ATOM_SPINS) {
                vader_os_spin_pause();
            } else {
                spins = 0;
                vader_os_yield();
            }
        }
    }
}

static void vader_atom_shard_unlock(vader_u32_t shard) {
    if (vader_atom_pooled()) __atomic_store_n(&g_atoms.writers[shard].busy, 0u, __ATOMIC_RELEASE);
}

/* Fill the ids of this thread, with several workers: tombstones from the free
 * list first, else fresh ids past `count`. Those are tombstones already, which
 * the sweep passes over: the reservation is zero there, and nothing writes an
 * entry past `count`. */
static void vader_atom_take_ids(void) {
    vader_os_lock(g_atom_guard);
    while (g_atoms.free_count > 0u && t_atom_ids_len < VADER_ATOM_ID_BATCH) {
        t_atom_ids[t_atom_ids_len++] = g_atoms.free_list[--g_atoms.free_count];
    }
    if (t_atom_ids_len == 0u) {
        while (g_atoms.count + VADER_ATOM_ID_BATCH > g_atoms.capacity) {
            vader_atom_grow_entries();
        }
        vader_u32_t first = g_atoms.count;
        for (vader_u32_t i = VADER_ATOM_ID_BATCH; i > 0u; i--) {
            t_atom_ids[t_atom_ids_len++] = first + i - 1u;
        }
        __atomic_store_n(&g_atoms.count, first + VADER_ATOM_ID_BATCH, __ATOMIC_RELEASE);
    }
    vader_os_unlock(g_atom_guard);
}

/* An id for a fresh atom: with several workers, from this thread's ids, else a
 * tombstone of the free list, else the next past `count`. The entry is a
 * tombstone; the caller fills the fields. */
static vader_atom_t vader_atom_alloc_slot(void) {
    if (vader_atom_pooled()) {
        if (t_atom_ids_len == 0u) vader_atom_take_ids();
        return t_atom_ids[--t_atom_ids_len];
    }
    if (g_atoms.free_count > 0) return g_atoms.free_list[--g_atoms.free_count];
    if (g_atoms.count >= g_atoms.capacity) vader_atom_grow_entries();
    return g_atoms.count++;
}

/* Begin installing the atom of `data[0..len]`, which a look without a lock
 * missed: an id for it into `*id`, then, with several workers, the lock of
 * `shard`, under which a second look catches an atom another worker installed
 * meanwhile. That atom then, with the id given back and the lock let go; else
 * VADER_ATOM_EMPTY, the caller installing the atom and letting the lock go. The
 * id comes first, since a refill of this thread's ids takes another lock. */
static vader_atom_t vader_atom_claim(vader_u32_t shard, const char* data, size_t len,
                                     uint64_t hash, vader_atom_t* id) {
    *id = vader_atom_alloc_slot();
    if (!vader_atom_pooled()) return VADER_ATOM_EMPTY;
    vader_atom_shard_lock(shard);
    vader_atom_t found = vader_atom_lookup(shard, data, len, hash);
    if (found != VADER_ATOM_EMPTY) {
        vader_atom_shard_unlock(shard);
        t_atom_ids[t_atom_ids_len++] = *id;
    }
    return found;
}

/* ---- public intern API --------------------------------------------------- */

/* Install the atom of `data[0..len]`, whose hash is `hash`, which a look
 * without a lock missed. Out of line, so that a lookup that finds its atom, by
 * far the most frequent, saves no more registers than it needs. */
static VADER_NOINLINE vader_atom_t vader_atom_intern_missed(vader_u32_t shard, const char* data,
                                                            size_t len, uint64_t hash) {
    char* buf = (char*) malloc(len + 1u);
    if (buf == NULL) vader_trap("vader_atom_intern: buffer malloc failed");
    memcpy(buf, data, len);
    buf[len] = '\0';
    vader_atom_t a = VADER_ATOM_EMPTY;
    vader_atom_t found = vader_atom_claim(shard, data, len, hash, &a);
    if (found != VADER_ATOM_EMPTY) {
        free(buf);
        return found;
    }
    vader_atom_entry_t* e = &vader_atom_entries[a];
    e->parent        = 0;
    e->parent_offset = 0;
    e->len           = (vader_u32_t) len;
    e->flags         = vader_atom_ascii_flag(buf, len);
    e->_pad          = 0;
    e->data          = buf;
    e->hash          = hash;
    vader_atom_shard_add(shard, a, hash);
    vader_atom_shard_unlock(shard);
    return a;
}

vader_atom_t vader_atom_intern(const char* data, size_t len) {
    if (len == 0) return VADER_ATOM_EMPTY;

    uint64_t hash = vader_atom_hash64(data, len);
    vader_u32_t shard = vader_atom_shard_of(hash);
    vader_atom_t found = vader_atom_lookup(shard, data, len, hash);
    if (found != VADER_ATOM_EMPTY) return found;
    return vader_atom_intern_missed(shard, data, len, hash);
}

/* Install the slice `[root_offset, root_offset + len)` of owner `root`, taken
 * through `parent`, whose hash is `hash`, which a look without a lock missed.
 * Out of line for the reason `vader_atom_intern_missed` is. */
static VADER_NOINLINE vader_atom_t vader_atom_slice_missed(vader_u32_t shard, vader_atom_t parent,
                                                           vader_atom_t root, size_t root_offset,
                                                           size_t len, uint64_t hash) {
    const char* candidate = vader_atom_entries[root].data + root_offset;
    vader_atom_t a = VADER_ATOM_EMPTY;
    vader_atom_t found = vader_atom_claim(shard, candidate, len, hash, &a);
    if (found != VADER_ATOM_EMPTY) return found;

    /* Miss: install as slice atom borrowing from the root owner. No
     * allocation. NUL-term at data[len] is NOT guaranteed (the byte
     * past the slice belongs to the parent buffer and may be any
     * value): `vader_atom_to_cstr` handles slice atoms by duplicating
     * to a heap NUL-term copy. A slice of ASCII bytes is ASCII. */
    vader_u16_t ascii = vader_atom_entries[parent].flags & VADER_ATOM_FLAG_ASCII;
    if (ascii == 0) ascii = vader_atom_ascii_flag(candidate, len);
    vader_atom_entry_t* e = &vader_atom_entries[a];
    e->parent        = root;
    e->parent_offset = (vader_u32_t) root_offset;
    e->len           = (vader_u32_t) len;
    e->flags         = ascii;
    e->_pad          = 0;
    e->data          = candidate;
    e->hash          = hash;

    vader_atom_shard_add(shard, a, hash);
    vader_atom_shard_unlock(shard);
    return a;
}


vader_atom_t vader_atom_slice(vader_atom_t parent, size_t offset, size_t len) {
    if (len == 0) return VADER_ATOM_EMPTY;

    /* Bounds validation against the parent's logical bytes. Invalid
     * arguments are a runtime contract violation: trap rather than
     * silently produce a corrupted slice. */
    if (parent >= __atomic_load_n(&g_atoms.count, __ATOMIC_ACQUIRE)) {
        vader_trap("vader_atom_slice: parent atom id out of range");
    }
    const vader_atom_entry_t* pe = &vader_atom_entries[parent];
    if (offset > pe->len || len > pe->len - offset) {
        vader_trap("vader_atom_slice: range overflows parent length");
    }
    /* An atom is the only one with its bytes: a slice covering it is itself. */
    if (offset == 0 && len == pe->len) return parent;

    /* Flatten one hop : every slice atom enforces `parent.parent == 0`
     * at insert time (we never link a slice to another slice), so the
     * deepest chain we ever see is parent -> owner. Keeps the GC mark
     * trivial (one hop, never recursive). */
    vader_atom_t root        = parent;
    size_t       root_offset = offset;
    if (vader_atom_entries[root].parent != 0) {
        root_offset += vader_atom_entries[root].parent_offset;
        root         = vader_atom_entries[root].parent;
    }

    /* Hash on the candidate bytes ; dedupe regardless of where the
     * canonical representative lives (might be owner, might be slice
     * sharing different bytes that happen to compare equal). */
    const char* candidate = vader_atom_entries[root].data + root_offset;
    uint64_t hash         = vader_atom_hash64(candidate, len);
    vader_u32_t shard     = vader_atom_shard_of(hash);
    vader_atom_t found    = vader_atom_lookup(shard, candidate, len, hash);
    if (found != VADER_ATOM_EMPTY) return found;
    return vader_atom_slice_missed(shard, parent, root, root_offset, len, hash);
}

const char* vader_atom_to_cstr(vader_atom_t a) {
    const vader_atom_entry_t* e = &vader_atom_entries[a];
    if (e->parent == 0) {
        return e->data;     /* owner : NUL-term inline at data[len] */
    }
    /* Slice : duplicate for NUL termination. Caller frees via
     * `vader_cstr_free_for`. */
    char* dup = (char*) malloc(e->len + 1u);
    if (dup == NULL) vader_trap("vader_atom_to_cstr: dup malloc failed");
    memcpy(dup, e->data, e->len);
    dup[e->len] = '\0';
    return dup;
}

/* Release what `vader_atom_to_cstr` returned for `s`: owner atoms hand out
 * their table-owned bytes (nothing to free), slice atoms were dup'd. */
void vader_cstr_free_for(vader_string_t s, const char* p) {
    if (p == NULL) return;
    if (vader_atom_entries[s].parent == 0) return;  /* owner : table-owned */
    free((void*) p);
}

/* One line on stderr with the atom count, the capacity, the slot load, the
 * owner bytes and the free slots. `vader_atom_shutdown` calls it when
 * `VADER_ATOM_PROFILE=1` was set at program start. */
static void vader_atom_profile_dump(void) {
    size_t used = 0;
    size_t slots = 0;
    for (vader_u32_t i = 0; i < VADER_ATOM_SHARDS; i++) {
        used += g_atoms.writers[i].used;
        slots += vader_atom_index_of(i)->capacity;
    }
    size_t owner_bytes = 0;
    for (vader_u32_t i = 1; i < g_atoms.count; i++) {
        const vader_atom_entry_t* e = &vader_atom_entries[i];
        if (e->parent == 0 && e->data != NULL) owner_bytes += e->len;
    }
    fprintf(stderr, "[atom-profile] count=%u capacity=%u slot_load=%.2f%% "
                    "owner_bytes=%zu free_count=%u\n",
            g_atoms.count, g_atoms.capacity, 100.0 * (double) used / (double) slots,
            owner_bytes, g_atoms.free_count);
}
