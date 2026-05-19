/* POC bench driver — runs identical workload on the monomorphised and
 * the erased implementations, prints timings + alloc counts.
 *
 * Workload: 100k put ops cycling through 1000 unique string keys (90 %
 * updates, 10 % fresh inserts on the first pass), 100k get ops, 100k
 * iteration visits (split as 100 outer × ~1000 entry visits).
 *
 * Wall-time via `clock_gettime(CLOCK_MONOTONIC)`. Outputs nanoseconds-
 * per-op so the two implementations can be compared at a glance.
 */

#include "mono_map.h"
#include "erased_map.h"
#include "erased_map_inline_vt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>

static double now_ns(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec * 1e9 + (double)ts.tv_nsec;
}

/* ===================================================================
 *  Workload — mono
 * =================================================================== */

static int mono_each_sink(vader_string_t k, user_t v, void* ctx) {
    (void)k;
    int64_t* sink = (int64_t*)ctx;
    *sink += (int64_t)v.age;
    return 0;
}

static void run_mono(void) {
    mono_map_t m;
    mono_map_init(&m);

    /* PUT */
    poc_reset_alloc_count();
    double t0 = now_ns();
    for (int i = 0; i < POC_NUM_OPS; i++) {
        mono_map_put(&m, poc_key(i), poc_value(i));
    }
    double t_put     = now_ns() - t0;
    size_t put_allocs = poc_alloc_count;

    /* GET */
    int64_t getsum = 0;
    poc_reset_alloc_count();
    t0 = now_ns();
    for (int i = 0; i < POC_NUM_OPS; i++) {
        user_t out;
        if (mono_map_get(&m, poc_key(i), &out)) {
            getsum += (int64_t)out.age;
        }
    }
    double t_get      = now_ns() - t0;
    size_t get_allocs = poc_alloc_count;

    /* ITER — 100 outer × full traversal of `m` (≈ POC_NUM_KEYS entries). */
    int64_t itersum = 0;
    poc_reset_alloc_count();
    t0 = now_ns();
    for (int i = 0; i < 100; i++) {
        mono_map_each(&m, mono_each_sink, &itersum);
    }
    double t_iter      = now_ns() - t0;
    size_t iter_allocs = poc_alloc_count;

    printf("mono    put: %8.1f ns/op  (%zu allocs total)\n", t_put / POC_NUM_OPS, put_allocs);
    printf("mono    get: %8.1f ns/op  (%zu allocs total)\n", t_get / POC_NUM_OPS, get_allocs);
    printf("mono   iter: %8.1f ns/visit (%zu allocs, getsum=%" PRId64 " itersum=%" PRId64 ")\n",
        t_iter / (100.0 * (double)m.size), iter_allocs, getsum, itersum);
}

/* ===================================================================
 *  Workload — erased
 * =================================================================== */

static int erased_each_sink(vader_box_t k, vader_box_t v, void* ctx) {
    (void)k;
    int64_t* sink = (int64_t*)ctx;
    *sink += (int64_t)unbox_user(v).age;
    return 0;
}

static void run_erased(void) {
    erased_map_t m;
    erased_map_init(&m, &string_key_vtable);

    /* PUT */
    poc_reset_alloc_count();
    double t0 = now_ns();
    for (int i = 0; i < POC_NUM_OPS; i++) {
        erased_map_put(&m, box_string(poc_key(i)), box_user(poc_value(i)));
    }
    double t_put      = now_ns() - t0;
    size_t put_allocs = poc_alloc_count;

    /* GET */
    int64_t getsum = 0;
    poc_reset_alloc_count();
    t0 = now_ns();
    for (int i = 0; i < POC_NUM_OPS; i++) {
        vader_box_t out;
        if (erased_map_get(&m, box_string(poc_key(i)), &out)) {
            getsum += (int64_t)unbox_user(out).age;
        }
    }
    double t_get      = now_ns() - t0;
    size_t get_allocs = poc_alloc_count;

    /* ITER */
    int64_t itersum = 0;
    poc_reset_alloc_count();
    t0 = now_ns();
    for (int i = 0; i < 100; i++) {
        erased_map_each(&m, erased_each_sink, &itersum);
    }
    double t_iter      = now_ns() - t0;
    size_t iter_allocs = poc_alloc_count;

    printf("erased  put: %8.1f ns/op  (%zu allocs total)\n", t_put / POC_NUM_OPS, put_allocs);
    printf("erased  get: %8.1f ns/op  (%zu allocs total)\n", t_get / POC_NUM_OPS, get_allocs);
    printf("erased iter: %8.1f ns/visit (%zu allocs, getsum=%" PRId64 " itersum=%" PRId64 ")\n",
        t_iter / (100.0 * (double)m.size), iter_allocs, getsum, itersum);
}

/* ===================================================================
 *  Workload — i64-valued maps (criterion #1: inline-fittable value
 *  payloads should have 0 boxing alloc per put on the erased path)
 * =================================================================== */

static void run_i64(void) {
    mono_i64_map_t mono;
    mono_i64_map_init(&mono);

    erased_map_t erased;
    erased_map_init(&erased, &string_key_vtable);

    /* Mono */
    poc_reset_alloc_count();
    double t0 = now_ns();
    for (int i = 0; i < POC_NUM_OPS; i++) {
        mono_i64_map_put(&mono, poc_key(i), (int64_t)i);
    }
    double t_mono_put     = now_ns() - t0;
    size_t mono_put_allocs = poc_alloc_count;

    /* Erased — value boxed as i64 (fits inline in payload.i, no extra alloc) */
    poc_reset_alloc_count();
    t0 = now_ns();
    for (int i = 0; i < POC_NUM_OPS; i++) {
        erased_map_put(&erased, box_string(poc_key(i)), box_i64((int64_t)i));
    }
    double t_erased_put     = now_ns() - t0;
    size_t erased_put_allocs = poc_alloc_count;

    /* Get sums to keep the optimiser honest. */
    int64_t mono_sum = 0;
    t0 = now_ns();
    for (int i = 0; i < POC_NUM_OPS; i++) {
        int64_t out;
        if (mono_i64_map_get(&mono, poc_key(i), &out)) mono_sum += out;
    }
    double t_mono_get = now_ns() - t0;

    int64_t erased_sum = 0;
    t0 = now_ns();
    for (int i = 0; i < POC_NUM_OPS; i++) {
        vader_box_t out;
        if (erased_map_get(&erased, box_string(poc_key(i)), &out)) erased_sum += unbox_i64(out);
    }
    double t_erased_get = now_ns() - t0;

    printf("string->i64 mono   put: %6.1f ns/op  (%zu allocs)  get: %6.1f ns/op  sum=%" PRId64 "\n",
        t_mono_put / POC_NUM_OPS, mono_put_allocs, t_mono_get / POC_NUM_OPS, mono_sum);
    printf("string->i64 erased put: %6.1f ns/op  (%zu allocs)  get: %6.1f ns/op  sum=%" PRId64 "\n",
        t_erased_put / POC_NUM_OPS, erased_put_allocs, t_erased_get / POC_NUM_OPS, erased_sum);
}

/* ===================================================================
 *  Box-layout reports — informs criterion #5
 * =================================================================== */

static void report_layouts(void) {
    printf("\n[layout]\n");
    printf("  sizeof(vader_box_t)    = %zu\n", sizeof(vader_box_t));
    printf("  sizeof(user_t)         = %zu\n", sizeof(user_t));
    printf("  sizeof(mono_entry_t)   = %zu\n", sizeof(mono_entry_t));
    printf("  sizeof(erased_entry_t) = %zu\n", sizeof(erased_entry_t));
    printf("  sizeof(mono_map_t)     = %zu\n", sizeof(mono_map_t));
    printf("  sizeof(erased_map_t)   = %zu\n", sizeof(erased_map_t));
}

int main(int argc, char** argv) {
    /* Warm-up runs filter scheduler noise off the first measurement. */
    int runs = argc > 1 ? atoi(argv[1]) : 3;
    if (runs < 1) runs = 1;

    printf("=== POC erasure bench (%d run(s), %d ops, %d unique keys) ===\n",
        runs, POC_NUM_OPS, POC_NUM_KEYS);

    for (int r = 0; r < runs; r++) {
        printf("\n--- run %d ---\n", r + 1);
        run_mono();
        printf("\n");
        run_erased();
    }

    printf("\n--- string->i64 (criterion #1: zero box alloc when value inlines) ---\n");
    run_i64();

    /* Variant: inline vtable on map struct — saves one load on dispatch. */
    printf("\n--- inline-vt variant (criterion #2 optimisation) ---\n");
    {
        erased_inline_map_t mi;
        erased_inline_map_init(&mi, &string_key_vtable);

        double t0 = now_ns();
        for (int i = 0; i < POC_NUM_OPS; i++) {
            erased_inline_map_put(&mi, box_string(poc_key(i)), box_i64((int64_t)i));
        }
        double t_put = now_ns() - t0;

        int64_t sum = 0;
        t0 = now_ns();
        for (int i = 0; i < POC_NUM_OPS; i++) {
            vader_box_t out;
            if (erased_inline_map_get(&mi, box_string(poc_key(i)), &out)) sum += unbox_i64(out);
        }
        double t_get = now_ns() - t0;

        printf("inline-vt string->i64 put: %6.1f ns/op   get: %6.1f ns/op   sum=%" PRId64 "\n",
            t_put / POC_NUM_OPS, t_get / POC_NUM_OPS, sum);
    }

    report_layouts();
    return 0;
}
