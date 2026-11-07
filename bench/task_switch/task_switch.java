// Java peer of bench/task_switch.vader. A virtual thread is the task: it writes
// its result to its slot, which its `join` makes visible. Two blocking queues of
// capacity 1 carry the round trip, boxing each value as a Java queue does; the
// echo stops on a value no trip sends. The work runs on a virtual thread, as
// Vader's `main` runs as a task: a platform thread would park in the OS at
// every wait. The virtual threads share one carrier, as Vader's tasks share
// one OS thread: on several, a wake would also cost a wake of another carrier.

import java.util.concurrent.ArrayBlockingQueue;

static final int BATCH = 1_000;
static final int BATCHES = 10;
static final long TRIPS = 300_000;
static final long STOP = -1;

static long launchAndJoin() throws InterruptedException {
    long total = 0;
    for (int b = 0; b < BATCHES; b++) {
        long[] results = new long[BATCH];
        Thread[] tasks = new Thread[BATCH];
        for (int i = 0; i < BATCH; i++) {
            final int slot = i;
            final long n = (long) b * BATCH + i;
            tasks[i] = Thread.ofVirtual().start(() -> results[slot] = n + 1);
        }
        for (int i = 0; i < BATCH; i++) {
            tasks[i].join();
            total += results[i];
        }
    }
    return total;
}

static long echo(ArrayBlockingQueue<Long> ping, ArrayBlockingQueue<Long> pong)
        throws InterruptedException {
    long echoed = 0;
    for (long value = ping.take(); value != STOP; value = ping.take()) {
        pong.put(value + 1);
        echoed++;
    }
    return echoed;
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

static String pingPong() throws InterruptedException {
    var ping = new ArrayBlockingQueue<Long>(1);
    var pong = new ArrayBlockingQueue<Long>(1);
    long[] echoed = { 0 };
    Thread echoer = startVirtual(() -> echoed[0] = echo(ping, pong));
    long total = 0;
    for (long i = 0; i < TRIPS; i++) {
        ping.put(i);
        total += pong.take();
    }
    ping.put(STOP);
    echoer.join();
    return "traded=" + total + " echoed=" + echoed[0];
}

void main() throws InterruptedException {
    // Set before the first virtual thread starts: the scheduler reads it then.
    System.setProperty("jdk.virtualThreadScheduler.parallelism", "1");
    startVirtual(() -> {
        long launched = launchAndJoin();
        System.out.println("task_switch launched=" + launched + " " + pingPong());
    }).join();
}
