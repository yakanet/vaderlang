// TypeScript peer of bench/tasks_alloc.vader. JavaScript shares no memory
// between threads: a task is a job handed to a pool of workers
// (`node:worker_threads`), one per core. BENCH_THREADS sets the count, every
// core by default, as VADER_THREADS does for Vader.

import { availableParallelism } from "node:os";
import { isMainThread, parentPort, Worker } from "node:worker_threads";

const TASKS = 16;
const ROUNDS = 30_000;

function churn(seed: number): number {
  let total = 0;
  for (let i = 0; i < ROUNDS; i++) {
    const parts: string[] = [];
    for (let j = 0; j < 4; j++) parts.push(`${seed}-${i}-${j}`);
    total += parts.join(",").length;
  }
  return total;
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
  let total = 0;
  await runJobs(TASKS, (length) => {
    total += length;
  });
  console.log(`tasks_alloc total=${total}`);
} else {
  parentPort!.on("message", (seed: number) => parentPort!.postMessage(churn(seed)));
}
