// TypeScript peer of bench/tasks_pool.vader. JavaScript shares no memory
// between threads: the pool is one worker (`node:worker_threads`) per core, and
// a message carries each job and each result, a few jobs in flight per worker as
// a channel keeps the workers of the peers fed. BENCH_THREADS sets the count,
// every core by default, as VADER_THREADS does for Vader.

import { availableParallelism } from "node:os";
import { isMainThread, parentPort, Worker } from "node:worker_threads";

const JOBS = 20_000;
const STEPS = 5_000;
const MODULUS = 1_000_000_007;
const IN_FLIGHT = 4;

function work(n: number): number {
  let acc = n;
  for (let i = 0; i < STEPS; i++) acc = (acc * 31 + i) % MODULUS;
  return acc;
}

// Hand the jobs `0..<jobs` to the pool, `IN_FLIGHT` at a time to each worker.
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
      for (let i = 0; i < IN_FLIGHT; i++) give();
    }
  });
}

if (isMainThread) {
  let sum = 0;
  await runJobs(JOBS, (result) => {
    sum = (sum + result) % MODULUS;
  });
  console.log(`tasks_pool done=${JOBS} sum=${sum}`);
} else {
  parentPort!.on("message", (n: number) => parentPort!.postMessage(work(n)));
}
