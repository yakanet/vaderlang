// Java peer of bench/tasks_compute.vader. A virtual thread is the task: it writes
// its result to its slot, which its `join` makes visible. The property
// `jdk.virtualThreadScheduler.parallelism` sets the cores, as VADER_THREADS does
// for Vader.

static final int TASKS = 16;
static final long CHUNK = 125_000;

static long longestChain(long lo, long hi) {
    long best = 0;
    for (long n = lo; n < hi; n++) {
        long x = n;
        long steps = 0;
        while (x != 1) {
            if (x % 2 == 0) {
                x = x / 2;
            } else {
                x = 3 * x + 1;
            }
            steps++;
        }
        if (steps > best) {
            best = steps;
        }
    }
    return best;
}

void main() throws InterruptedException {
    long[] results = new long[TASKS];
    Thread[] tasks = new Thread[TASKS];
    for (int k = 0; k < TASKS; k++) {
        final int slot = k;
        final long lo = 1 + k * CHUNK;
        tasks[k] = Thread.ofVirtual().start(() -> results[slot] = longestChain(lo, lo + CHUNK));
    }
    long best = 0;
    for (int k = 0; k < TASKS; k++) {
        tasks[k].join();
        best = Math.max(best, results[k]);
    }
    System.out.println("tasks_compute best=" + best);
}
