// Java peer of bench/tasks_alloc.vader. A virtual thread is the task: it writes
// its result to its slot, which its `join` makes visible. The property
// `jdk.virtualThreadScheduler.parallelism` sets the cores, as VADER_THREADS does
// for Vader.

import java.util.ArrayList;

static final int TASKS = 16;
static final int ROUNDS = 30_000;

static long churn(int seed) {
    long total = 0;
    for (int i = 0; i < ROUNDS; i++) {
        var parts = new ArrayList<String>();
        for (int j = 0; j < 4; j++) {
            parts.add(seed + "-" + i + "-" + j);
        }
        total += String.join(",", parts).length();
    }
    return total;
}

void main() throws InterruptedException {
    long[] results = new long[TASKS];
    Thread[] tasks = new Thread[TASKS];
    for (int k = 0; k < TASKS; k++) {
        final int seed = k;
        tasks[k] = Thread.ofVirtual().start(() -> results[seed] = churn(seed));
    }
    long total = 0;
    for (int k = 0; k < TASKS; k++) {
        tasks[k].join();
        total += results[k];
    }
    System.out.println("tasks_alloc total=" + total);
}
