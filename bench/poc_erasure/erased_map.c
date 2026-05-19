#include "erased_map.h"
#include <string.h>

static inline int bucket_index(uint64_t h) {
    return (int)(h % (uint64_t)POC_NUM_BUCKETS);
}

void erased_map_init(erased_map_t* m, erased_vtable_t* key_vt) {
    memset(m->buckets, 0, sizeof m->buckets);
    m->size   = 0;
    m->key_vt = key_vt;
}

void erased_map_put(erased_map_t* m, vader_box_t key, vader_box_t value) {
    uint64_t h   = m->key_vt->hash(key);             /* indirect dispatch */
    int      idx = bucket_index(h);

    for (erased_entry_t* cur = m->buckets[idx]; cur; cur = cur->next) {
        if (m->key_vt->equals(cur->key, key)) {       /* indirect dispatch */
            cur->value = value;
            return;
        }
    }

    erased_entry_t* node = (erased_entry_t*)poc_alloc(sizeof *node);
    node->key   = key;
    node->value = value;
    node->next  = m->buckets[idx];
    m->buckets[idx] = node;
    m->size++;
}

bool erased_map_get(erased_map_t* m, vader_box_t key, vader_box_t* out) {
    uint64_t h   = m->key_vt->hash(key);
    int      idx = bucket_index(h);

    for (erased_entry_t* cur = m->buckets[idx]; cur; cur = cur->next) {
        if (m->key_vt->equals(cur->key, key)) {
            *out = cur->value;
            return true;
        }
    }
    return false;
}

void erased_map_each(
    erased_map_t* m,
    int (*callback)(vader_box_t, vader_box_t, void*),
    void* ctx
) {
    for (int i = 0; i < POC_NUM_BUCKETS; i++) {
        for (erased_entry_t* cur = m->buckets[i]; cur; cur = cur->next) {
            if (callback(cur->key, cur->value, ctx) != 0) return;
        }
    }
}

/* ---- Boxing ---- */

vader_box_t box_string(vader_string_t s) {
    return vader_box_string(POC_TAG_STRING, s);
}

vader_box_t box_user(user_t u) {
    /* `user_t` does not fit in `payload.obj` (24 bytes payload, 8 bytes
     * available). Heap-copy the value and box the pointer — the
     * pre-Phase-1 baseline, one extra alloc per box.
     *
     * Phase 1 (inline-box generalisation) would pack the 16-byte
     * `vader_string_t` + `int32_t age` into a 32-byte box with no
     * extra alloc. Not modelled in this POC. */
    user_t* heap = (user_t*)poc_alloc(sizeof *heap);
    *heap = u;
    return vader_box_obj(POC_TAG_USER, heap);
}

vader_box_t box_i64(int64_t v) {
    /* `i64` fits in `payload.i` → no allocation. Matches what the box
     * does today for primitive ≤ 8-byte payloads. */
    return vader_box_i64(POC_TAG_I64, v);
}

vader_string_t unbox_string(vader_box_t b) { return b.payload.s; }
user_t         unbox_user(vader_box_t b)   { return *(user_t*)b.payload.obj; }
int64_t        unbox_i64(vader_box_t b)    { return b.payload.i; }

/* ---- Vtable: string keys ---- */

static uint64_t vt_string_hash(vader_box_t b) {
    return vader_string_hash(b.payload.s);
}

static bool vt_string_equals(vader_box_t a, vader_box_t b) {
    return vader_string_eq(a.payload.s, b.payload.s);
}

erased_vtable_t string_key_vtable = {
    .hash   = vt_string_hash,
    .equals = vt_string_equals,
};
