// Java peer of bench/tasks_pool.vader. Virtual threads are the workers, two
// blocking queues of capacity 64 carry the jobs and the results; a worker stops
// on a job no feeder sends. The property `jdk.virtualThreadScheduler.parallelism`
// sets the cores, as VADER_THREADS does for Vader.

import java.util.concurrent.ArrayBlockingQueue;

static final int WORKERS = 8;
static final long JOBS = 20_000;
static final long STEPS = 5_000;
static final long MODULUS = 1_000_000_007;
static final long STOP = -1;

static long work(long n) {
    long acc = n;
    for (long i = 0; i < STEPS; i++) {
        acc = (acc * 31 + i) % MODULUS;
    }
    return acc;
}

// What a virtual thread runs when it may be interrupted while it waits.
interface Waiting {
    void run() throws InterruptedException;
}

static Thread startVirtual(Waiting body) {
    return Thread.ofVirtual().start(() -> {
        try {
            body.run();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    });
}

void main() throws InterruptedException {
    // On a virtual thread, as Vader's `main` runs as a task: a platform thread
    // would park in the OS at every wait.
    startVirtual(() -> {
        var jobs = new ArrayBlockingQueue<Long>(64);
        var results = new ArrayBlockingQueue<Long>(64);
        // Each worker writes its count once, at its end.
        long[] done = new long[WORKERS];
        Thread[] workers = new Thread[WORKERS];
        for (int w = 0; w < WORKERS; w++) {
            final int slot = w;
            workers[w] = startVirtual(() -> {
                long count = 0;
                for (long job = jobs.take(); job != STOP; job = jobs.take()) {
                    results.put(work(job));
                    count++;
                }
                done[slot] = count;
            });
        }
        Thread feeder = startVirtual(() -> {
            for (long n = 0; n < JOBS; n++) {
                jobs.put(n);
            }
            for (int w = 0; w < WORKERS; w++) {
                jobs.put(STOP);
            }
        });
        long sum = 0;
        for (long i = 0; i < JOBS; i++) {
            sum = (sum + results.take()) % MODULUS;
        }
        feeder.join();
        long count = 0;
        for (int w = 0; w < WORKERS; w++) {
            workers[w].join();
            count += done[w];
        }
        System.out.println("tasks_pool done=" + count + " sum=" + sum);
    }).join();
}
