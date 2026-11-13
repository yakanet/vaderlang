/* rt/copy.c: `deep_copy`, a copy of every object a value reaches.
 *
 * A Cheney walk, as a minor collection is one: an object is copied on first
 * sight and its copy queued, then each queued copy has its references replaced
 * by the copies of what they reach. A table from source address to copy keeps
 * two references to one object on one copy, and a cycle a cycle. A struct marked
 * `VADER_TYPE_FLAG_SHARED` is kept, not copied: tasks share it by design.
 *
 * Nothing may collect during the walk: a collection would move the sources the
 * table names by address. So the copies are carved straight from the old
 * generation, which never collects to make room, and a reservation exhausted at
 * its cap traps. A copy is born marked for the current epoch, as a promoted
 * object is, and a reference it keeps to a young object (a kept shared struct)
 * marks its card, as the write barrier would. */

#include "internal.h"

typedef struct {
    /* Source address -> copy, open addressing on a power-of-two capacity ; a
     * NULL key is a free slot. */
    void**  from;
    void**  to;
    size_t  capacity;
    size_t  count;
    /* Copies whose references still point at sources. */
    void**  pending;
    size_t  pending_len;
    size_t  pending_cap;
} vader_copy_t;

static void* vader_copy_calloc(size_t count, size_t size) {
    void* p = calloc(count, size);
    if (p == NULL) vader_trap("deep_copy: out of memory for the copy table");
    return p;
}

/* The table slot of `key`: its own, or the free one it would take. The address
 * is mixed first: objects sit on 16-byte boundaries, so the low bits alone would
 * crowd a few slots. */
static size_t vader_copy_slot(const vader_copy_t* c, const void* key) {
    uint64_t h = (uint64_t) (uintptr_t) key;
    h ^= h >> 33;
    h *= UINT64_C(0xff51afd7ed558ccd);
    h ^= h >> 33;
    size_t mask = c->capacity - 1u;
    size_t i = (size_t) h & mask;
    while (c->from[i] != NULL && c->from[i] != key) i = (i + 1u) & mask;
    return i;
}

static void vader_copy_grow(vader_copy_t* c) {
    void** old_from = c->from;
    void** old_to = c->to;
    size_t old_capacity = c->capacity;
    c->capacity = old_capacity * 2u;
    c->from = (void**) vader_copy_calloc(c->capacity, sizeof(void*));
    c->to = (void**) vader_copy_calloc(c->capacity, sizeof(void*));
    for (size_t i = 0; i < old_capacity; i++) {
        if (old_from[i] == NULL) continue;
        size_t j = vader_copy_slot(c, old_from[i]);
        c->from[j] = old_from[i];
        c->to[j] = old_to[i];
    }
    free(old_from);
    free(old_to);
}

/* Note that `source` is copied as `copy`, and queue the copy for its references. */
static void vader_copy_note(vader_copy_t* c, void* source, void* copy) {
    if ((c->count + 1u) * 2u > c->capacity) vader_copy_grow(c);
    size_t i = vader_copy_slot(c, source);
    c->from[i] = source;
    c->to[i] = copy;
    c->count++;
    if (c->pending_len == c->pending_cap) {
        c->pending_cap *= 2u;
        c->pending = (void**) realloc(c->pending, c->pending_cap * sizeof(void*));
        if (c->pending == NULL) vader_trap("deep_copy: out of memory for the copy queue");
    }
    c->pending[c->pending_len++] = copy;
}

/* `bytes` of old-generation storage, carved without collecting. */
static void* vader_copy_carve(size_t bytes) {
    void* p = vader_old_alloc(bytes);
    if (p == NULL) vader_trap("deep_copy: old reservation exhausted at cap (VADER_GC_OLD_MAX)");
    return p;
}

/* The header of a copy: live in the current old epoch, as a promoted object. */
static void vader_copy_header(void* copy, uint32_t type_index) {
    vader_obj_header_init(copy, type_index);
    ((vader_obj_header_t*) copy)->mark = g_mark_value;
}

/* A copy of the object `obj` of `bytes`, its references still the source's. */
static void* vader_copy_raw(vader_copy_t* c, void* obj, size_t bytes) {
    void* copy = vader_copy_carve(bytes);
    memcpy(copy, obj, bytes);
    vader_copy_header(copy, ((vader_obj_header_t*) obj)->type_index);
    vader_copy_note(c, obj, copy);
    return copy;
}

/* A copy of the array `a`: an array of its own over the elements it shows, a
 * view's included, its references still the source's. */
static void* vader_copy_array(vader_copy_t* c, vader_array_t* a) {
    vader_array_t* source = a;
    a = vader_array_resolve(a);
    uint8_t kind;
    uint32_t tag;
    size_t element_size;
    const uint8_t* data = vader_array_src_region(a, 0, &kind, &tag, &element_size);
    size_t length = vader_array_length(a);
    size_t capacity = length;
    if (capacity < 4u) capacity = 4u;
    size_t buf_bytes = vader_array_buf_bytes(capacity, kind);
    vader_array_buf_t* buf = (vader_array_buf_t*) vader_copy_carve(buf_bytes);
    vader_copy_header(buf, VADER_TYPE_INDEX_ARRAY_BUF);
    buf->capacity = capacity;
    buf->length = length;
    buf->element_kind = kind;
    buf->element_tag = tag;
    if (length > 0u) memcpy(buf->slots, data, length * element_size);
    vader_array_t* copy = (vader_array_t*) vader_copy_carve(sizeof(vader_array_t));
    vader_copy_header(copy, a->header.type_index);
    vader_array_set_extent(copy, length, capacity);
    copy->offset = 0;
    copy->buf = buf;
    vader_copy_note(c, source, copy);
    return copy;
}

/* The copy of the object `obj`: the one already made, or a new one. */
static void* vader_copy_ref(vader_copy_t* c, void* obj) {
    if (obj == NULL) return NULL;
    size_t i = vader_copy_slot(c, obj);
    if (c->from[i] == obj) return c->to[i];
    uint32_t type_index = ((vader_obj_header_t*) obj)->type_index;
    if (type_index == VADER_TYPE_INDEX_BUFFER) {
        size_t bytes = sizeof(vader_buffer_t) + ((vader_buffer_t*) obj)->byte_count;
        return vader_copy_raw(c, obj, bytes);
    }
    if (type_index >= vader_type_info_count) {
        vader_trap("deep_copy: reached an object of unknown type");
    }
    const vader_type_info_t* info = &vader_type_info_table[type_index];
    switch (info->kind) {
        case VADER_TYPE_KIND_STRUCT:
            if ((info->flags & VADER_TYPE_FLAG_SHARED) != 0u) return obj;
            return vader_copy_raw(c, obj, vader_obj_bytes(info->size));
        case VADER_TYPE_KIND_ARRAY:
            return vader_copy_array(c, (vader_array_t*) obj);
        case VADER_TYPE_KIND_FN:
            vader_trap("deep_copy: a function value cannot be copied");
        case VADER_TYPE_KIND_NONE:
            return obj;
    }
    return obj;
}

/* Whether a boxed value holds an object: a buffer, or a value of a heap kind. */
static int vader_copy_holds_object(vader_box_t value) {
    if (value.tag == VADER_TYPE_INDEX_BUFFER) return 1;
    if (value.tag >= vader_type_info_count) return 0;
    return vader_type_info_table[value.tag].kind != VADER_TYPE_KIND_NONE;
}

/* The copy of a boxed value: its object's copy, or the value itself when it
 * holds no object. */
static vader_box_t vader_copy_box(vader_copy_t* c, vader_box_t value) {
    if (vader_copy_holds_object(value)) value.payload.obj = vader_copy_ref(c, value.payload.obj);
    return value;
}

/* Point the reference at `slot` of a copy at the copy of its referent. */
static void vader_copy_ref_slot(vader_copy_t* c, void** slot) {
    *slot = vader_copy_ref(c, *slot);
    if (*slot != NULL && vader_in_young(*slot)) VADER_WRITE_BARRIER(slot);
}

static void vader_copy_box_slot(vader_copy_t* c, vader_box_t* slot) {
    *slot = vader_copy_box(c, *slot);
    if (vader_copy_holds_object(*slot) && vader_in_young(slot->payload.obj)) {
        VADER_WRITE_BARRIER(slot);
    }
}

/* Point the references of the copy `copy` at copies. */
static void vader_copy_references(vader_copy_t* c, char* copy) {
    uint32_t type_index = ((vader_obj_header_t*) copy)->type_index;
    if (type_index == VADER_TYPE_INDEX_BUFFER) return;
    const vader_type_info_t* info = &vader_type_info_table[type_index];
    if (info->kind == VADER_TYPE_KIND_ARRAY) {
        vader_array_buf_t* buf = ((vader_array_t*) copy)->buf;
        if (buf->element_kind == VADER_ARRAY_KIND_BOXED) {
            vader_box_t* slots = vader_array_box_slots(buf);
            for (size_t i = 0; i < buf->length; i++) vader_copy_box_slot(c, &slots[i]);
        } else if (buf->element_kind == VADER_ARRAY_KIND_REF) {
            void** slots = (void**) buf->slots;
            for (size_t i = 0; i < buf->length; i++) vader_copy_ref_slot(c, &slots[i]);
        }
        return;
    }
    for (uint16_t i = 0; i < info->ptr_count; i++) {
        vader_copy_box_slot(c, (vader_box_t*) (copy + info->ptr_offsets[i]));
    }
    for (uint16_t i = 0; i < info->ref_count; i++) {
        vader_copy_ref_slot(c, (void**) (copy + info->ref_offsets[i]));
    }
}

static void vader_copy_open(vader_copy_t* c) {
    if (VADER_UNLIKELY(!g_gc_initialized)) vader_gc_init();
    c->capacity = 64u;
    c->count = 0;
    c->from = (void**) vader_copy_calloc(c->capacity, sizeof(void*));
    c->to = (void**) vader_copy_calloc(c->capacity, sizeof(void*));
    c->pending_cap = 64u;
    c->pending_len = 0;
    c->pending = (void**) vader_copy_calloc(c->pending_cap, sizeof(void*));
}

/* Copy what the queued copies reach, then free the table. */
static void vader_copy_close(vader_copy_t* c) {
    while (c->pending_len > 0u) {
        vader_copy_references(c, (char*) c->pending[--c->pending_len]);
    }
    free(c->from);
    free(c->to);
    free(c->pending);
}

void* vader_deep_copy_ref(void* obj) {
    if (obj == NULL) return NULL;
    vader_copy_t c;
    vader_copy_open(&c);
    void* copy = vader_copy_ref(&c, obj);
    vader_copy_close(&c);
    return copy;
}

vader_box_t vader_deep_copy_box(vader_box_t value) {
    vader_copy_t c;
    vader_copy_open(&c);
    vader_box_t copy = vader_copy_box(&c, value);
    vader_copy_close(&c);
    return copy;
}
