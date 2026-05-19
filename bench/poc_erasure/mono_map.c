#include "mono_map.h"
#include <string.h>

static inline int bucket_index(uint64_t h) {
    return (int)(h % (uint64_t)POC_NUM_BUCKETS);
}

void mono_map_init(mono_map_t* m) {
    memset(m->buckets, 0, sizeof m->buckets);
    m->size = 0;
}

void mono_map_put(mono_map_t* m, vader_string_t key, user_t value) {
    uint64_t h   = vader_string_hash(key);
    int      idx = bucket_index(h);

    /* Walk the chain — update in place if the key already exists. */
    for (mono_entry_t* cur = m->buckets[idx]; cur; cur = cur->next) {
        if (vader_string_eq(cur->key, key)) {
            cur->value = value;
            return;
        }
    }

    /* Prepend a fresh entry. */
    mono_entry_t* node = (mono_entry_t*)poc_alloc(sizeof *node);
    node->key   = key;
    node->value = value;
    node->next  = m->buckets[idx];
    m->buckets[idx] = node;
    m->size++;
}

bool mono_map_get(mono_map_t* m, vader_string_t key, user_t* out) {
    uint64_t h   = vader_string_hash(key);
    int      idx = bucket_index(h);

    for (mono_entry_t* cur = m->buckets[idx]; cur; cur = cur->next) {
        if (vader_string_eq(cur->key, key)) {
            *out = cur->value;
            return true;
        }
    }
    return false;
}

void mono_map_each(
    mono_map_t* m,
    int (*callback)(vader_string_t, user_t, void*),
    void* ctx
) {
    for (int i = 0; i < POC_NUM_BUCKETS; i++) {
        for (mono_entry_t* cur = m->buckets[i]; cur; cur = cur->next) {
            if (callback(cur->key, cur->value, ctx) != 0) return;
        }
    }
}

/* ---- Second instantiation: MutableMap<string, i64> ---- */

void mono_i64_map_init(mono_i64_map_t* m) {
    memset(m->buckets, 0, sizeof m->buckets);
    m->size = 0;
}

void mono_i64_map_put(mono_i64_map_t* m, vader_string_t key, int64_t value) {
    uint64_t h   = vader_string_hash(key);
    int      idx = bucket_index(h);

    for (mono_i64_entry_t* cur = m->buckets[idx]; cur; cur = cur->next) {
        if (vader_string_eq(cur->key, key)) {
            cur->value = value;
            return;
        }
    }

    mono_i64_entry_t* node = (mono_i64_entry_t*)poc_alloc(sizeof *node);
    node->key   = key;
    node->value = value;
    node->next  = m->buckets[idx];
    m->buckets[idx] = node;
    m->size++;
}

bool mono_i64_map_get(mono_i64_map_t* m, vader_string_t key, int64_t* out) {
    uint64_t h   = vader_string_hash(key);
    int      idx = bucket_index(h);

    for (mono_i64_entry_t* cur = m->buckets[idx]; cur; cur = cur->next) {
        if (vader_string_eq(cur->key, key)) {
            *out = cur->value;
            return true;
        }
    }
    return false;
}
