/* rt/virtual_threads.c: virtual threads: the stacks, the switch, and what the
 * collector reads of a thread that is not running.
 *
 * Each thread runs on a stack of its own, reserved whole and committed as it
 * is written, with a guard zone at its low end. A switch stores the
 * callee-saved registers on the stack it leaves and notes the stack pointer
 * there, so a thread that is not running is its stack alone: the collector
 * walks its shadow-stack frames and its defers precisely, and scans
 * [saved sp, top) conservatively, the saved registers included.
 *
 * Which thread runs is rt/scheduler.c's to decide. One thread is set apart,
 * the scheduler's, which runs `vader_scheduler_loop`: a thread that ends
 * switches to it, and the stack it leaves is freed there, since a stack cannot
 * be freed while it runs.
 *
 * Darwin and Linux switch on arm64 and x86_64, Windows through fibers;
 * elsewhere the primitives trap. */

#include "internal.h"

int vader_foreign_depth = 0;

#if defined(_WIN32)
#  define VADER_VIRTUAL_THREAD_SUPPORTED 1
#  define VADER_VIRTUAL_THREAD_FIBERS 1
#  include <windows.h>
#elif defined(__aarch64__) || defined(__x86_64__)
#  define VADER_VIRTUAL_THREAD_SUPPORTED 1
#  define VADER_VIRTUAL_THREAD_FIBERS 0
#  include <sys/mman.h>
#else
#  define VADER_VIRTUAL_THREAD_SUPPORTED 0
#  define VADER_VIRTUAL_THREAD_FIBERS 0
#endif

/* Linux charges a writable mapping against the commit limit unless told not
 * to: a stack reserves its size, it does not commit it. */
#if defined(MAP_NORESERVE)
#  define VADER_VIRTUAL_THREAD_MAP_FLAGS (MAP_PRIVATE | MAP_ANON | MAP_NORESERVE)
#else
#  define VADER_VIRTUAL_THREAD_MAP_FLAGS (MAP_PRIVATE | MAP_ANON)
#endif

/* A record waits in a free list, then runs its entry, then waits for the
 * scheduler to free its stack. */
#define VADER_VIRTUAL_THREAD_FREE  0u
#define VADER_VIRTUAL_THREAD_LIVE  1u
#define VADER_VIRTUAL_THREAD_ENDED 2u

/* Reserved per stack: what the main thread gets on Darwin and Linux, so that a
 * thread runs what `main` runs. Only the pages written are resident. The part
 * at the low end is never writable: wide enough that no frame steps over it. */
#define VADER_VIRTUAL_THREAD_STACK_BYTES (8u * 1024u * 1024u)
#define VADER_VIRTUAL_THREAD_GUARD_BYTES (64u * 1024u)

/* Stacks kept warm for the next threads, their pages left resident: handing
 * pages back walks the whole reservation on Darwin, whatever was written. A
 * stack freed past this many keeps its reservation and hands back the pages of
 * its top, where a thread writes; the scheduler gives the reservation back
 * once no thread is ready (`vader_virtual_thread_give_back_cold`), since
 * giving it back costs more than a thread's whole run. */
#define VADER_VIRTUAL_THREAD_WARM_STACKS 64u
#define VADER_VIRTUAL_THREAD_DISCARD_BYTES (256u * 1024u)

/* The bytes `vader_virtual_thread_swap` stores below the stack pointer it
 * notes. x86_64: mxcsr and the x87 control word, r15-r12, rbx, rbp, then the
 * return address. arm64: x19-x28, fp, lr, then d8-d15. */
#if defined(__x86_64__)
#  define VADER_VIRTUAL_THREAD_SWITCH_FRAME 64u
#else
#  define VADER_VIRTUAL_THREAD_SWITCH_FRAME 160u
#endif

typedef struct vader_virtual_thread {
    char*  sp;              /* while it does not run: the switch frame */
    void*  fiber;           /* Windows: the fiber that runs it */
    char*  hi;              /* top of the stack: the scans stop there */
    vader_gc_frame_t* gc_top;
    vader_box_t* defer_stack;
    size_t defer_len;
    size_t defer_cap;
    int    unwinding;       /* its own trap runs its defers, once */
    /* The function it runs. `entry_frame` roots it, at the bottom of the
     * thread's shadow stack, until the thread ends. */
    vader_fn_t* entry;
    void** entry_slot[1];
    vader_gc_frame_t entry_frame;
    /* A handle is the generation in the high half and the index in the low
     * one: a record outlives its thread, and a reuse bumps the generation. */
    uint32_t index;         /* in `g_virtual_thread_records` */
    uint32_t generation;
    size_t   live_slot;     /* in `g_virtual_thread_live`, while not free */
    uint8_t  state;
    /* Windows: whether its fiber can run the next thread, which it does from
     * where the last one ended. One that ended deep in its stack cannot. */
    uint8_t  reusable;
} vader_virtual_thread_t;

static vader_virtual_thread_t  g_virtual_thread_main;
static vader_virtual_thread_t* g_virtual_thread_cur = NULL;
static vader_virtual_thread_t* g_virtual_thread_scheduler = NULL;
/* Every record ever made, never freed, so a handle always reads one. */
static vader_virtual_thread_t** g_virtual_thread_records = NULL;
static size_t g_virtual_thread_record_count = 0;
static size_t g_virtual_thread_record_cap = 0;
/* Every thread that is not free, whatever it does. */
static vader_virtual_thread_t** g_virtual_thread_live = NULL;
static size_t g_virtual_thread_live_count = 0;
static size_t g_virtual_thread_live_cap = 0;
/* Free records: with a warm stack, with a stack whose pages went back, and
 * with no stack. */
static vader_virtual_thread_t** g_virtual_thread_warm = NULL;
static size_t g_virtual_thread_warm_len = 0;
static size_t g_virtual_thread_warm_cap = 0;
static vader_virtual_thread_t** g_virtual_thread_cold = NULL;
static size_t g_virtual_thread_cold_len = 0;
static size_t g_virtual_thread_cold_cap = 0;
static vader_virtual_thread_t** g_virtual_thread_bare = NULL;
static size_t g_virtual_thread_bare_len = 0;
static size_t g_virtual_thread_bare_cap = 0;
/* A thread whose entry returned, whose stack the scheduler frees on arrival. */
static vader_virtual_thread_t* g_virtual_thread_ended = NULL;
/* The threads `vader_virtual_thread_create` started that have not ended. */
static size_t g_virtual_thread_count = 0;

static void vader_virtual_thread_push(vader_virtual_thread_t*** items, size_t* len, size_t* cap,
                                      vader_virtual_thread_t* t) {
    if (*len == *cap) {
        size_t new_cap = 64u;
        if (*cap != 0u) new_cap = *cap * 2u;
        vader_virtual_thread_t** grown = (vader_virtual_thread_t**) realloc(
            *items, new_cap * sizeof(vader_virtual_thread_t*));
        if (grown == NULL) vader_trap("virtual threads: out of memory");
        *items = grown;
        *cap = new_cap;
    }
    (*items)[(*len)++] = t;
}

static int64_t vader_virtual_thread_handle(const vader_virtual_thread_t* t) {
    return (int64_t) (((uint64_t) t->generation << 32) | (uint64_t) t->index);
}

static uint32_t vader_virtual_thread_index(int64_t handle) {
    return (uint32_t) ((uint64_t) handle & 0xFFFFFFFFu);
}

/* The thread `handle` names, or NULL once it has ended. */
static vader_virtual_thread_t* vader_virtual_thread_of(int64_t handle) {
    uint32_t index = vader_virtual_thread_index(handle);
    if (index >= g_virtual_thread_record_count) return NULL;
    vader_virtual_thread_t* t = g_virtual_thread_records[index];
    if (t->generation != (uint32_t) ((uint64_t) handle >> 32) || t->state != VADER_VIRTUAL_THREAD_LIVE) return NULL;
    return t;
}

/* ---- the switch ------------------------------------------------------------ */

#if VADER_VIRTUAL_THREAD_FIBERS
#  define VADER_VIRTUAL_THREAD_RUN_LINKAGE static
#else
/* `vader_virtual_thread_boot` reaches it from assembly. */
#  define VADER_VIRTUAL_THREAD_RUN_LINKAGE __attribute__((used, visibility("hidden")))
#endif

VADER_VIRTUAL_THREAD_RUN_LINKAGE void vader_virtual_thread_run(vader_virtual_thread_t* t);

#if VADER_VIRTUAL_THREAD_FIBERS

/* An address below every frame of its caller, the registers that caller's
 * prologue saved included. */
static __attribute__((noinline)) char* vader_virtual_thread_below_caller(void) {
    return (char*) __builtin_frame_address(0);
}

/* Store the callee-saved registers on the running stack and note its pointer
 * below them, then leave for `next`: a fiber keeps its registers in a context
 * the collector does not read. */
static __attribute__((noinline)) void vader_virtual_thread_fiber_swap(
    vader_virtual_thread_t* cur, vader_virtual_thread_t* next) {
    jmp_buf regs;
    (void) setjmp(regs);
    cur->sp = vader_virtual_thread_below_caller();
    SwitchToFiber(next->fiber);
}

/* Where a fiber starts, which bounds its stack from then on. It runs one
 * thread after another: a warm fiber resumes in the switch that ended its
 * last thread, and runs the record's next entry. */
static VOID CALLBACK vader_virtual_thread_fiber_main(LPVOID param) {
    vader_virtual_thread_t* t = (vader_virtual_thread_t*) param;
    t->hi = vader_os_stack_base();
    for (;;) vader_virtual_thread_run(t);
}

#elif VADER_VIRTUAL_THREAD_SUPPORTED

#  if defined(__APPLE__)
#    define VADER_VIRTUAL_THREAD_SYM(name) "_" name
#    define VADER_VIRTUAL_THREAD_HIDE ".private_extern "
#  else
#    define VADER_VIRTUAL_THREAD_SYM(name) name
#    define VADER_VIRTUAL_THREAD_HIDE ".hidden "
#  endif

/* Store the callee-saved registers on the running stack, note its pointer in
 * `*save`, then load the ones `load` noted and return on that stack. */
void vader_virtual_thread_swap(char** save, char* load);
/* Where a new stack starts: rbx (x86_64) or x19 (arm64) holds its thread. */
void vader_virtual_thread_boot(void);

#  if defined(__x86_64__)

__asm__(
    ".text\n"
    ".p2align 4\n"
    ".globl " VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_swap") "\n"
    VADER_VIRTUAL_THREAD_HIDE VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_swap") "\n"
    VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_swap") ":\n"
    "    pushq %rbp\n"
    "    pushq %rbx\n"
    "    pushq %r12\n"
    "    pushq %r13\n"
    "    pushq %r14\n"
    "    pushq %r15\n"
    "    subq  $8, %rsp\n"
    "    stmxcsr (%rsp)\n"
    "    fnstcw  4(%rsp)\n"
    "    movq  %rsp, (%rdi)\n"
    "    movq  %rsi, %rsp\n"
    "    ldmxcsr (%rsp)\n"
    "    fldcw   4(%rsp)\n"
    "    addq  $8, %rsp\n"
    "    popq  %r15\n"
    "    popq  %r14\n"
    "    popq  %r13\n"
    "    popq  %r12\n"
    "    popq  %rbx\n"
    "    popq  %rbp\n"
    "    ret\n"
    ".p2align 4\n"
    ".globl " VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_boot") "\n"
    VADER_VIRTUAL_THREAD_HIDE VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_boot") "\n"
    VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_boot") ":\n"
    "    movq  %rbx, %rdi\n"
    "    xorl  %ebp, %ebp\n"
    "    call  " VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_run") "\n"
    "    ud2\n"
);

#  else

__asm__(
    ".text\n"
    ".p2align 2\n"
    ".globl " VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_swap") "\n"
    VADER_VIRTUAL_THREAD_HIDE VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_swap") "\n"
    VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_swap") ":\n"
    "    sub  sp, sp, #160\n"
    "    stp  x19, x20, [sp, #0]\n"
    "    stp  x21, x22, [sp, #16]\n"
    "    stp  x23, x24, [sp, #32]\n"
    "    stp  x25, x26, [sp, #48]\n"
    "    stp  x27, x28, [sp, #64]\n"
    "    stp  x29, x30, [sp, #80]\n"
    "    stp  d8,  d9,  [sp, #96]\n"
    "    stp  d10, d11, [sp, #112]\n"
    "    stp  d12, d13, [sp, #128]\n"
    "    stp  d14, d15, [sp, #144]\n"
    "    mov  x9, sp\n"
    "    str  x9, [x0]\n"
    "    mov  sp, x1\n"
    "    ldp  x19, x20, [sp, #0]\n"
    "    ldp  x21, x22, [sp, #16]\n"
    "    ldp  x23, x24, [sp, #32]\n"
    "    ldp  x25, x26, [sp, #48]\n"
    "    ldp  x27, x28, [sp, #64]\n"
    "    ldp  x29, x30, [sp, #80]\n"
    "    ldp  d8,  d9,  [sp, #96]\n"
    "    ldp  d10, d11, [sp, #112]\n"
    "    ldp  d12, d13, [sp, #128]\n"
    "    ldp  d14, d15, [sp, #144]\n"
    "    add  sp, sp, #160\n"
    "    ret\n"
    ".p2align 2\n"
    ".globl " VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_boot") "\n"
    VADER_VIRTUAL_THREAD_HIDE VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_boot") "\n"
    VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_boot") ":\n"
    "    mov  x0, x19\n"
    "    mov  x29, #0\n"
    "    bl   " VADER_VIRTUAL_THREAD_SYM("vader_virtual_thread_run") "\n"
    "    brk  #0\n"
);

#  endif

/* Lay at the top of `t`'s stack the frame the first switch to it pops: its
 * return address is `vader_virtual_thread_boot`, and the register boot reads
 * holds `t`. */
static void vader_virtual_thread_first_frame(vader_virtual_thread_t* t) {
    uintptr_t* frame = (uintptr_t*) (t->hi - VADER_VIRTUAL_THREAD_SWITCH_FRAME);
    memset(frame, 0, VADER_VIRTUAL_THREAD_SWITCH_FRAME);
#  if defined(__x86_64__)
    /* The thread starts with the floating-point modes of the one that creates
     * it: a zero mxcsr would unmask every exception. */
    uint32_t mxcsr = 0;
    uint16_t x87 = 0;
    __asm__ volatile("stmxcsr %0" : "=m"(mxcsr));
    __asm__ volatile("fnstcw %0" : "=m"(x87));
    frame[0] = (uintptr_t) mxcsr | ((uintptr_t) x87 << 32);
    frame[5] = (uintptr_t) t;
    frame[7] = (uintptr_t) &vader_virtual_thread_boot;
#  else
    frame[0] = (uintptr_t) t;
    frame[11] = (uintptr_t) &vader_virtual_thread_boot;
#  endif
    t->sp = (char*) frame;
}

#endif

#if VADER_VIRTUAL_THREAD_SUPPORTED

/* ---- the stacks ------------------------------------------------------------ */

#  if VADER_VIRTUAL_THREAD_FIBERS

/* A fiber to run `t`, which bounds its stack when it first runs. */
static void vader_virtual_thread_reserve(vader_virtual_thread_t* t) {
    t->fiber = CreateFiberEx(0, VADER_VIRTUAL_THREAD_STACK_BYTES, FIBER_FLAG_FLOAT_SWITCH,
                             vader_virtual_thread_fiber_main, t);
    if (t->fiber == NULL) vader_trap("virtual threads: no room for a fiber");
    t->sp = NULL;
    t->hi = NULL;
}

static void vader_virtual_thread_give_back(vader_virtual_thread_t* t) {
    DeleteFiber(t->fiber);
    t->fiber = NULL;
}

/* A fiber's pages stay: Windows commits a fiber's stack for good. */
static void vader_virtual_thread_discard(vader_virtual_thread_t* t) {
    (void) t;
}

/* A warm fiber resumes where its last thread ended, and runs the new entry
 * from there. */
static void vader_virtual_thread_prepare(vader_virtual_thread_t* t) {
    (void) t;
}

static void vader_virtual_thread_init_main(void) {
    if (IsThreadAFiber()) {
        g_virtual_thread_main.fiber = GetCurrentFiber();
    } else {
        g_virtual_thread_main.fiber = ConvertThreadToFiberEx(NULL, FIBER_FLAG_FLOAT_SWITCH);
    }
    if (g_virtual_thread_main.fiber == NULL) {
        vader_trap("virtual threads: the main thread cannot become a fiber");
    }
}

#  else

static void vader_virtual_thread_reserve(vader_virtual_thread_t* t) {
    char* lo = (char*) mmap(NULL, VADER_VIRTUAL_THREAD_STACK_BYTES, PROT_READ | PROT_WRITE,
                            VADER_VIRTUAL_THREAD_MAP_FLAGS, -1, 0);
    if (lo == (char*) MAP_FAILED) vader_trap("virtual threads: no room for a stack");
    if (mprotect(lo, VADER_VIRTUAL_THREAD_GUARD_BYTES, PROT_NONE) != 0) {
        vader_trap("virtual threads: the guard zone was refused");
    }
#    if defined(MADV_NOHUGEPAGE)
    /* Linux may back the first write with a huge page, which leaves the whole
     * 2 MiB around it resident for a thread that uses a few KiB. */
    madvise(lo, VADER_VIRTUAL_THREAD_STACK_BYTES, MADV_NOHUGEPAGE);
#    endif
    t->hi = lo + VADER_VIRTUAL_THREAD_STACK_BYTES;
}

static void vader_virtual_thread_give_back(vader_virtual_thread_t* t) {
    vader_os_release(t->hi - VADER_VIRTUAL_THREAD_STACK_BYTES, VADER_VIRTUAL_THREAD_STACK_BYTES);
    t->hi = NULL;
}

static void vader_virtual_thread_discard(vader_virtual_thread_t* t) {
    vader_os_discard(t->hi - VADER_VIRTUAL_THREAD_DISCARD_BYTES, t->hi);
}

static void vader_virtual_thread_prepare(vader_virtual_thread_t* t) {
    vader_virtual_thread_first_frame(t);
}

static void vader_virtual_thread_init_main(void) {
}

#  endif

static void vader_virtual_thread_init(void) {
    if (g_virtual_thread_cur != NULL) return;
    vader_virtual_thread_init_main();
    g_virtual_thread_main.hi = vader_os_stack_base();
    g_virtual_thread_main.state = VADER_VIRTUAL_THREAD_LIVE;
    g_virtual_thread_main.index = (uint32_t) g_virtual_thread_record_count;
    vader_virtual_thread_push(&g_virtual_thread_records, &g_virtual_thread_record_count,
            &g_virtual_thread_record_cap, &g_virtual_thread_main);
    g_virtual_thread_main.live_slot = g_virtual_thread_live_count;
    vader_virtual_thread_push(&g_virtual_thread_live, &g_virtual_thread_live_count,
            &g_virtual_thread_live_cap, &g_virtual_thread_main);
    g_virtual_thread_cur = &g_virtual_thread_main;
}

/* A record with a stack, ready to run `entry`: a warm one, a cold one, a bare
 * one given a stack again, or a new one. */
static vader_virtual_thread_t* vader_virtual_thread_take(vader_fn_t* entry) {
    vader_virtual_thread_t* t = NULL;
    if (g_virtual_thread_warm_len > 0u) {
        t = g_virtual_thread_warm[--g_virtual_thread_warm_len];
    } else if (g_virtual_thread_cold_len > 0u) {
        t = g_virtual_thread_cold[--g_virtual_thread_cold_len];
    } else if (g_virtual_thread_bare_len > 0u) {
        t = g_virtual_thread_bare[--g_virtual_thread_bare_len];
        vader_virtual_thread_reserve(t);
    } else {
        t = (vader_virtual_thread_t*) calloc(1, sizeof(vader_virtual_thread_t));
        if (t == NULL) vader_trap("virtual threads: out of memory");
        t->index = (uint32_t) g_virtual_thread_record_count;
        t->entry_slot[0] = (void**) &t->entry;
        t->entry_frame = (vader_gc_frame_t) { NULL, 0u, 1u, NULL, t->entry_slot };
        vader_virtual_thread_push(&g_virtual_thread_records, &g_virtual_thread_record_count,
                &g_virtual_thread_record_cap, t);
        vader_virtual_thread_reserve(t);
    }
    t->entry = entry;
    t->gc_top = &t->entry_frame;
    t->state = VADER_VIRTUAL_THREAD_LIVE;
    t->reusable = 1;
    t->live_slot = g_virtual_thread_live_count;
    vader_virtual_thread_push(&g_virtual_thread_live, &g_virtual_thread_live_count,
            &g_virtual_thread_live_cap, t);
    vader_virtual_thread_prepare(t);
    return t;
}

/* Free the thread that ended, now that its stack no longer runs. */
static void vader_virtual_thread_release_ended(void) {
    vader_virtual_thread_t* t = g_virtual_thread_ended;
    if (t == NULL) return;
    g_virtual_thread_ended = NULL;
    vader_virtual_thread_t* last = g_virtual_thread_live[--g_virtual_thread_live_count];
    g_virtual_thread_live[t->live_slot] = last;
    last->live_slot = t->live_slot;
    free(t->defer_stack);
    t->defer_stack = NULL;
    t->defer_len = 0u;
    t->defer_cap = 0u;
    t->unwinding = 0;
    t->entry = NULL;
    t->state = VADER_VIRTUAL_THREAD_FREE;
    t->generation++;
    if (!t->reusable) {
        vader_virtual_thread_give_back(t);
        vader_virtual_thread_push(&g_virtual_thread_bare, &g_virtual_thread_bare_len,
                &g_virtual_thread_bare_cap, t);
        return;
    }
    if (g_virtual_thread_warm_len < VADER_VIRTUAL_THREAD_WARM_STACKS) {
        vader_virtual_thread_push(&g_virtual_thread_warm, &g_virtual_thread_warm_len,
                &g_virtual_thread_warm_cap, t);
        return;
    }
    vader_virtual_thread_discard(t);
    vader_virtual_thread_push(&g_virtual_thread_cold, &g_virtual_thread_cold_len,
            &g_virtual_thread_cold_cap, t);
}

/* Leave the running thread for `next`; back here when something switches to
 * it again. */
static void vader_virtual_thread_switch_to(vader_virtual_thread_t* next) {
    vader_virtual_thread_t* cur = g_virtual_thread_cur;
    if (next == cur) return;
    /* Another thread would run over the C frames below. */
    if (vader_foreign_depth > 0) vader_trap("virtual threads: a switch inside a call to C");
    if (g_gc_stress_switch) vader_major_collect();
    cur->gc_top = vader_gc_top;
    cur->defer_stack = g_defer_stack;
    cur->defer_len = g_defer_len;
    cur->defer_cap = g_defer_cap;
    cur->unwinding = g_unwinding;
    g_virtual_thread_cur = next;
    vader_gc_top = next->gc_top;
    g_defer_stack = next->defer_stack;
    g_defer_len = next->defer_len;
    g_defer_cap = next->defer_cap;
    g_unwinding = next->unwinding;
#  if VADER_VIRTUAL_THREAD_FIBERS
    vader_virtual_thread_fiber_swap(cur, next);
#  else
    vader_virtual_thread_swap(&cur->sp, next->sp);
#  endif
    vader_virtual_thread_release_ended();
}

/* End the running thread `t`: the scheduler frees its stack. */
static void vader_virtual_thread_finish(vader_virtual_thread_t* t) {
    vader_scheduler_ending();
    t->state = VADER_VIRTUAL_THREAD_ENDED;
    g_virtual_thread_count--;
    g_virtual_thread_ended = t;
    vader_virtual_thread_switch_to(g_virtual_thread_scheduler);
}

/* A thread's body, on its own stack: run the entry, then leave for the
 * scheduler for good. The scheduler's thread runs the scheduler instead. */
VADER_VIRTUAL_THREAD_RUN_LINKAGE void vader_virtual_thread_run(vader_virtual_thread_t* t) {
    vader_virtual_thread_release_ended();
    if (t == g_virtual_thread_scheduler) vader_scheduler_loop();
    ((vader_box_t (*)(void*)) t->entry->code)(t->entry->env);
    vader_virtual_thread_finish(t);
#  if !VADER_VIRTUAL_THREAD_FIBERS
    vader_trap("virtual threads: an ended thread was resumed");
#  endif
}

/* ---- what the scheduler drives --------------------------------------------- */

static void vader_virtual_thread_start_scheduler(void) {
    vader_virtual_thread_init();
    if (g_virtual_thread_scheduler == NULL) {
        g_virtual_thread_scheduler = vader_virtual_thread_take(NULL);
    }
}

static int64_t vader_virtual_thread_create(vader_fn_t* entry) {
    vader_virtual_thread_init();
    g_virtual_thread_count++;
    return vader_virtual_thread_handle(vader_virtual_thread_take(entry));
}

static void vader_virtual_thread_switch(int64_t to) {
    vader_virtual_thread_t* next = vader_virtual_thread_of(to);
    if (next == NULL) vader_trap("virtual threads: a switch to a thread that has ended");
    vader_virtual_thread_switch_to(next);
}

static void vader_virtual_thread_switch_to_scheduler(void) {
    vader_virtual_thread_switch_to(g_virtual_thread_scheduler);
}

static void vader_virtual_thread_end(void) {
#  if VADER_VIRTUAL_THREAD_FIBERS
    g_virtual_thread_cur->reusable = 0;
#  endif
    vader_virtual_thread_finish(g_virtual_thread_cur);
    vader_trap("virtual threads: an ended thread was resumed");
}

static int64_t vader_virtual_thread_current(void) {
    vader_virtual_thread_init();
    return vader_virtual_thread_handle(g_virtual_thread_cur);
}

static int64_t vader_virtual_thread_main(void) {
    vader_virtual_thread_init();
    return vader_virtual_thread_handle(&g_virtual_thread_main);
}

static int vader_virtual_thread_is_live(int64_t handle) {
    return vader_virtual_thread_of(handle) != NULL;
}

static size_t vader_virtual_thread_count(void) {
    return g_virtual_thread_count;
}

/* In no set order: the end of a thread moves the last one into its place. */
static void vader_virtual_thread_each_live(void (*fn)(int64_t handle)) {
    for (size_t i = 0; i < g_virtual_thread_live_count; i++) {
        vader_virtual_thread_t* t = g_virtual_thread_live[i];
        if (t == g_virtual_thread_scheduler || t->state != VADER_VIRTUAL_THREAD_LIVE) continue;
        fn(vader_virtual_thread_handle(t));
    }
}

static void vader_virtual_thread_give_back_cold(void) {
    while (g_virtual_thread_cold_len > 0u) {
        vader_virtual_thread_t* t = g_virtual_thread_cold[--g_virtual_thread_cold_len];
        vader_virtual_thread_give_back(t);
        vader_virtual_thread_push(&g_virtual_thread_bare, &g_virtual_thread_bare_len,
                &g_virtual_thread_bare_cap, t);
    }
}

/* ---- what the collector reads ---------------------------------------------- */

static char* vader_virtual_thread_stack_top(void) {
    if (g_virtual_thread_cur == NULL) return vader_os_stack_base();
    return g_virtual_thread_cur->hi;
}

static void vader_virtual_thread_roots_of(const vader_virtual_thread_t* t,
                                          vader_virtual_thread_roots_t* r) {
    r->top = t->gc_top;
    r->defers = t->defer_stack;
    r->ndefers = t->defer_len;
    r->sp = t->sp;
    r->hi = t->hi;
}

static void vader_virtual_thread_each_waiting(void (*fn)(const vader_virtual_thread_roots_t*)) {
    vader_virtual_thread_roots_t r;
    for (size_t i = 0; i < g_virtual_thread_live_count; i++) {
        vader_virtual_thread_t* t = g_virtual_thread_live[i];
        if (t == g_virtual_thread_cur || t->state != VADER_VIRTUAL_THREAD_LIVE) continue;
        vader_virtual_thread_roots_of(t, &r);
        fn(&r);
    }
}

#else

static void vader_virtual_thread_start_scheduler(void) {
    vader_trap("virtual threads: no stack switch on this target");
}

static int64_t vader_virtual_thread_create(vader_fn_t* entry) {
    (void) entry;
    vader_trap("virtual threads: no stack switch on this target");
}

static void vader_virtual_thread_switch(int64_t to) {
    (void) to;
    vader_trap("virtual threads: no stack switch on this target");
}

static void vader_virtual_thread_switch_to_scheduler(void) {
    vader_trap("virtual threads: no stack switch on this target");
}

static void vader_virtual_thread_end(void) {
    vader_trap("virtual threads: no stack switch on this target");
}

static int64_t vader_virtual_thread_current(void) {
    return 0;
}

static int64_t vader_virtual_thread_main(void) {
    return 0;
}

static int vader_virtual_thread_is_live(int64_t handle) {
    return handle == 0;
}

static size_t vader_virtual_thread_count(void) {
    return 0;
}

static void vader_virtual_thread_each_live(void (*fn)(int64_t handle)) {
    (void) fn;
}

static void vader_virtual_thread_give_back_cold(void) {
}

static char* vader_virtual_thread_stack_top(void) {
    return vader_os_stack_base();
}

static void vader_virtual_thread_each_waiting(void (*fn)(const vader_virtual_thread_roots_t*)) {
    (void) fn;
}

#endif
