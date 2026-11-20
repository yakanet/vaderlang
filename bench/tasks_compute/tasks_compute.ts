// TypeScript peer of bench/tasks_compute.vader. JavaScript shares no memory
// between threads: a task is a job handed to a pool of workers
// (`node:worker_threads`), one per core. BENCH_THREADS sets the count, every
// core by default, as VADER_THREADS does for Vader.

import { availableParallelism } from "node:os";
import { isMainThread, parentPort, Worker } from "node:worker_threads";

const TASKS = 16;
const CHUNK = 125_000;

function longestChain(lo: number, hi: number): number {
  let best = 0;
  for (let n = lo; n < hi; n++) {
    let x = n;
    let steps = 0;
    while (x !== 1) {
      if (x % 2 === 0) x = x / 2;
      else x = 3 * x + 1;
      steps++;
    }
    if (steps > best) best = steps;
  }
  return best;
}

// Hand the jobs `0..<jobs` to the pool, one at a time to each idle worker.
function runJobs(jobs: number, onResult: (result: number) => void): Promise<void> {
  const threads = Number(process.env.BENCH_THREADS ?? availableParallelism());
  const pool = Array.from({ length: threads }, () => new Worker(import.meta.path));
  let next = 0;
  let pending = jobs;
  return new Promise((resolve) => {
    for (const worker of pool) {
      const give = () => {
        if (next < jobs) worker.postMessage(next++);
      };
      worker.on("message", (result: number) => {
        onResult(result);
        pending--;
        if (pending === 0) {
          for (const w of pool) w.terminate();
          resolve();
        } else give();
      });
      give();
    }
  });
}

if (isMainThread) {
  let best = 0;
  await runJobs(TASKS, (steps) => {
    if (steps > best) best = steps;
  });
  console.log(`tasks_compute best=${best}`);
} else {
  parentPort!.on("message", (k: number) => {
    const lo = 1 + k * CHUNK;
    parentPort!.postMessage(longestChain(lo, lo + CHUNK));
  });
}
