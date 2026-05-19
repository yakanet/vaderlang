#include "shared.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Stubs — `vader_runtime.c`'s GC scanner expects these symbols, normally
 * emitted by the C codegen per module (one entry per `BcType`). The POC
 * uses `malloc` rather than `vader_gc_alloc`, so the scanner never runs;
 * empty values satisfy the linker. Types must match the `extern`
 * declarations in `vader.h` (~ line 407). */
const vader_type_info_t vader_type_info_table[1] = {{ 0 }};
const size_t            vader_type_info_count    = 0;

size_t poc_alloc_count = 0;

void* poc_alloc(size_t n) {
    poc_alloc_count++;
    void* p = malloc(n);
    if (!p) { fprintf(stderr, "poc_alloc OOM\n"); exit(1); }
    return p;
}

void poc_reset_alloc_count(void) {
    poc_alloc_count = 0;
}

/* Pre-baked key pool — `POC_NUM_KEYS` deterministic strings of the form
 * "key_NNNN". Each `vader_string_t` returned by `poc_key` is a fat-ptr
 * into the static buffer, never freed during the bench. */
static char            key_buf[POC_NUM_KEYS][16];
static vader_string_t  keys[POC_NUM_KEYS];
static int             keys_initialised = 0;

static void init_keys(void) {
    for (int i = 0; i < POC_NUM_KEYS; i++) {
        int n = snprintf(key_buf[i], sizeof key_buf[i], "key_%04d", i);
        keys[i].ptr = key_buf[i];
        keys[i].len = (size_t)n;
    }
    keys_initialised = 1;
}

vader_string_t poc_key(int idx) {
    if (!keys_initialised) init_keys();
    return keys[idx % POC_NUM_KEYS];
}

/* Names are reused from the key pool to avoid per-value allocation in
 * the bench loop — perf measurement should not be polluted by string
 * construction cost. */
user_t poc_value(int idx) {
    user_t u;
    u.name = poc_key(idx);
    u.age  = (int32_t)(20 + (idx % 60));
    return u;
}
