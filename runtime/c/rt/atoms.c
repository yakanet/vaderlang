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
static int  g_atoms_initialized = 0;
static int  g_atom_profile = 0;

/* Initial table capacities, grown by doubling. A module that carries a
 * comptime atom count raises both to fit it:
 * `vader_atom_init_with_comptime`. */
#define VADER_ATOM_INITIAL_CAPACITY    256u
#define VADER_ATOM_INITIAL_BUCKETS     1024u   /* must be power of two */

/* Forward decls: implementations below cluster by concern. */
static void        vader_atom_install_empty(void);
static uint64_t    vader_atom_hash64(const char* data, size_t len);
static void        vader_atom_profile_dump(void);

void vader_atom_init_with_comptime(const vader_atom_entry_t* comptime_table,
                                   vader_u32_t count) {
    /* Program-startup stdio setup : the emitted `main` calls atom-init first,
     * so this is the one place every C-emitted binary passes through at start.
     * On Windows the CRT defaults stdout to TEXT mode, which translates every
     * `\n` to `\r\n`: that corrupts `dump` / `build` / `fmt` output (LF on
     * disk, CRLF on the wire) and every snapshot comparison. Force binary here,
     * not just lazily on the first stdin read. */
    vader_ensure_stdio_binary();
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
    vader_u32_t want_buckets = VADER_ATOM_INITIAL_BUCKETS;
    if (count > 0u) {
        vader_u32_t target = (count + 1u) * 4u;
        while (want_buckets < target) want_buckets *= 2u;
    }
    g_atoms.buckets = (uint64_t*) calloc(want_buckets, sizeof(uint64_t));
    if (g_atoms.buckets == NULL) vader_trap("vader_atom_init_with_comptime: buckets calloc failed");
    g_atoms.bucket_capacity = want_buckets;
    g_atoms.bucket_count    = 0;

    g_atoms.free_list     = NULL;
    g_atoms.free_count    = 0;
    g_atoms.free_capacity = 0;
    g_atoms.owner_bytes   = 0;

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
            vader_atom_bucket_install(i);
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
    free(vader_atom_entries);
    free(g_atoms.buckets);
    free(g_atoms.free_list);
    vader_atom_entries      = NULL;
    g_atoms.buckets         = NULL;
    g_atoms.free_list       = NULL;
    g_atoms.count           = 0;
    g_atoms.capacity        = 0;
    g_atoms.bucket_capacity = 0;
    g_atoms.bucket_count    = 0;
    g_atoms.free_count      = 0;
    g_atoms.free_capacity   = 0;
    g_atoms.owner_bytes     = 0;
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
 * `vader_string_hash` for `string`'s `Hash` trait), its low bits index the
 * open-addressing bucket table and its high 32 bits tag the bucket, so the
 * probe passes over other atoms without reading their entries. Both halves
 * must stay well mixed. The VM reads the same cached value, so the native and
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

/* Bucket probe: returns the matching atom id or VADER_ATOM_EMPTY (0)
 * on miss. Callers short-circuit len==0 before reaching this : the empty
 * atom has no bucket. `bucket_capacity` is a power of two: mask trick
 * replaces a modulo. The low bits of the hash pick the slot and its high
 * 32 bits sit in the bucket, so a slot holding another hash is passed over
 * without reading `entries[]`. */
static vader_atom_t vader_atom_lookup(const char* data, size_t len, uint64_t hash) {
    const vader_u32_t mask = g_atoms.bucket_capacity - 1u;
    vader_u32_t idx = (vader_u32_t) hash & mask;
    for (;;) {
        uint64_t slot = g_atoms.buckets[idx];
        if (slot == 0) return VADER_ATOM_EMPTY;
        vader_atom_t a = (vader_atom_t) slot;
        const vader_atom_entry_t* e = &vader_atom_entries[a];
        if ((slot ^ hash) >> 32 == 0 && e->len == len && memcmp(e->data, data, len) == 0) {
            return a;
        }
        idx = (idx + 1u) & mask;
    }
}

/* Install atom `a` at its canonical bucket slot, under the hash its entry
 * caches: every caller fills `e->hash` first. Assumes free room :
 * `vader_atom_bucket_add` grows the table past a 0.75 load after each new
 * atom. */
static void vader_atom_bucket_install(vader_atom_t a) {
    const uint64_t hash = vader_atom_entries[a].hash;
    const vader_u32_t mask = g_atoms.bucket_capacity - 1u;
    vader_u32_t idx = (vader_u32_t) hash & mask;
    while (g_atoms.buckets[idx] != 0) {
        idx = (idx + 1u) & mask;
    }
    g_atoms.buckets[idx] = (hash >> 32 << 32) | a;
    g_atoms.bucket_count++;
}

/* Bucket grow: double capacity, rehash every live atom. Called when
 * the load factor would exceed 0.75 after the most recent install. */
static void vader_atom_grow_buckets(void) {
    free(g_atoms.buckets);
    g_atoms.bucket_capacity *= 2u;
    g_atoms.buckets = (uint64_t*) calloc(g_atoms.bucket_capacity, sizeof(uint64_t));
    if (g_atoms.buckets == NULL) vader_trap("vader_atom_grow_buckets: calloc failed");
    g_atoms.bucket_count = 0;
    /* Reinsert every LIVE atom except the empty sentinel at index 0. `data ==
     * NULL` is a tombstone the major sweep left behind: it clears every field
     * but `hash`, so a stale id would otherwise reinstall at its old position,
     * inflate `bucket_count` (driving further growths) and, once the free list
     * recycles that id, occupy two buckets at once. Same test the sweep's own
     * rebuild makes. */
    for (vader_u32_t i = 1; i < g_atoms.count; ++i) {
        const vader_atom_entry_t* e = &vader_atom_entries[i];
        if (e->data == NULL) continue;
        vader_atom_bucket_install(i);
    }
}

/* Index a freshly minted atom, growing the table past a 0.75 load. The grow
 * comes after the install so the new atom rehashes with the rest. */
static void vader_atom_bucket_add(vader_atom_t a) {
    vader_atom_bucket_install(a);
    if (g_atoms.bucket_count * 4u > g_atoms.bucket_capacity * 3u) {
        vader_atom_grow_buckets();
    }
}

/* Entries grow: double capacity, realloc in place. Pointers into the
 * array are NOT stable across calls ; every reader rederefs through
 * `vader_atom_entries`, so a realloc that relocates the array is safe. */
static void vader_atom_grow_entries(void) {
    g_atoms.capacity *= 2u;
    vader_atom_entry_t* p = (vader_atom_entry_t*)
        realloc(vader_atom_entries, g_atoms.capacity * sizeof(vader_atom_entry_t));
    if (p == NULL) vader_trap("vader_atom_grow_entries: realloc failed");
    vader_atom_entries = p;
}

/* Allocate a fresh atom slot: reuses a tombstoned id from the free
 * list when available, else grows `entries[]`. The entry is
 * left uninitialised ; the caller fills the fields. */
static vader_atom_t vader_atom_alloc_slot(void) {
    if (g_atoms.free_count > 0) {
        return g_atoms.free_list[--g_atoms.free_count];
    }
    if (g_atoms.count >= g_atoms.capacity) {
        vader_atom_grow_entries();
    }
    return g_atoms.count++;
}

/* Miss-path install : claim a slot, point it at `buf` (a heap buffer the
 * table takes over, its NUL at `buf[len]` already written), bucket-install,
 * grow buckets if load factor crossed. `hash` is the hash of `buf`, and the
 * caller's lookup for these bytes missed. */
static vader_atom_t vader_atom_install_owner(char* buf, size_t len, uint64_t hash) {
    vader_atom_t a = vader_atom_alloc_slot();
    vader_atom_entry_t* e = &vader_atom_entries[a];
    e->parent        = 0;
    e->parent_offset = 0;
    e->len           = (vader_u32_t) len;
    e->flags         = vader_atom_ascii_flag(buf, len);
    e->_pad          = 0;
    e->data          = buf;
    e->hash          = hash;
    g_atoms.owner_bytes += len;

    vader_atom_bucket_add(a);
    return a;
}

/* ---- public intern API --------------------------------------------------- */

vader_atom_t vader_atom_intern(const char* data, size_t len) {
    if (len == 0) return VADER_ATOM_EMPTY;

    uint64_t hash = vader_atom_hash64(data, len);
    vader_atom_t found = vader_atom_lookup(data, len, hash);
    if (found != VADER_ATOM_EMPTY) return found;

    char* buf = (char*) malloc(len + 1u);
    if (buf == NULL) vader_trap("vader_atom_intern: buffer malloc failed");
    memcpy(buf, data, len);
    buf[len] = '\0';
    return vader_atom_install_owner(buf, len, hash);
}

vader_atom_t vader_atom_slice(vader_atom_t parent, size_t offset, size_t len) {
    if (len == 0) return VADER_ATOM_EMPTY;

    /* Bounds validation against the parent's logical bytes. Invalid
     * arguments are a runtime contract violation: trap rather than
     * silently produce a corrupted slice. */
    if (parent >= g_atoms.count) {
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
    vader_atom_t found    = vader_atom_lookup(candidate, len, hash);
    if (found != VADER_ATOM_EMPTY) return found;

    /* Miss: install as slice atom borrowing from the root owner. No
     * allocation. NUL-term at data[len] is NOT guaranteed (the byte
     * past the slice belongs to the parent buffer and may be any
     * value): `vader_atom_to_cstr` handles slice atoms by duplicating
     * to a heap NUL-term copy. A slice of ASCII bytes is ASCII. */
    vader_u16_t ascii = vader_atom_entries[parent].flags & VADER_ATOM_FLAG_ASCII;
    if (ascii == 0) ascii = vader_atom_ascii_flag(candidate, len);
    vader_atom_t a = vader_atom_alloc_slot();
    vader_atom_entry_t* e = &vader_atom_entries[a];
    e->parent        = root;
    e->parent_offset = (vader_u32_t) root_offset;
    e->len           = (vader_u32_t) len;
    e->flags         = ascii;
    e->_pad          = 0;
    e->data          = candidate;
    e->hash          = hash;

    vader_atom_bucket_add(a);
    return a;
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

/* One line on stderr with the atom count, the capacity, the bucket load, the
 * owner bytes and the free slots. `vader_atom_shutdown` calls it when
 * `VADER_ATOM_PROFILE=1` was set at program start. */
static void vader_atom_profile_dump(void) {
    fprintf(stderr, "[atom-profile] count=%u capacity=%u bucket_load=%.2f%% "
                    "owner_bytes=%zu free_count=%u\n",
            g_atoms.count, g_atoms.capacity,
            g_atoms.bucket_capacity == 0 ? 0.0
                : 100.0 * (double) g_atoms.bucket_count / (double) g_atoms.bucket_capacity,
            g_atoms.owner_bytes, g_atoms.free_count);
}
