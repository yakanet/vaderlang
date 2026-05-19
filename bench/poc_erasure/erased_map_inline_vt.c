#include "erased_map_inline_vt.h"
#include <string.h>

static inline int bucket_index(uint64_t h) {
    return (int)(h % (uint64_t)POC_NUM_BUCKETS);
}

void erased_inline_map_init(erased_inline_map_t* m, erased_vtable_t* key_vt) {
    memset(m->buckets, 0, sizeof m->buckets);
    m->size   = 0;
    m->hash   = key_vt->hash;
    m->equals = key_vt->equals;
}

void erased_inline_map_put(erased_inline_map_t* m, vader_box_t key, vader_box_t value) {
    uint64_t h   = m->hash(key);                    /* one load fewer than external vt */
    int      idx = bucket_index(h);

    for (erased_inline_entry_t* cur = m->buckets[idx]; cur; cur = cur->next) {
        if (m->equals(cur->key, key)) {
            cur->value = value;
            return;
        }
    }

    erased_inline_entry_t* node = (erased_inline_entry_t*)poc_alloc(sizeof *node);
    node->key   = key;
    node->value = value;
    node->next  = m->buckets[idx];
    m->buckets[idx] = node;
    m->size++;
}

bool erased_inline_map_get(erased_inline_map_t* m, vader_box_t key, vader_box_t* out) {
    uint64_t h   = m->hash(key);
    int      idx = bucket_index(h);

    for (erased_inline_entry_t* cur = m->buckets[idx]; cur; cur = cur->next) {
        if (m->equals(cur->key, key)) {
            *out = cur->value;
            return true;
        }
    }
    return false;
}
