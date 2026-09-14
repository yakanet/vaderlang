// TypeScript peer of bench/async_await.vader. `await` on a value that is
// already settled is the same thing: a hop through the state machine the
// compiler built, with no scheduler wait behind it.

const COUNT = 3_000_000;

async function step(x: number): Promise<number> {
  return x + 1;
}

async function run(): Promise<number> {
  let total = 0;
  for (let i = 0; i < COUNT; i++) {
    total = await step(total);
  }
  return total;
}

const total = await run();
console.log(`async_await count=${COUNT} total=${total}`);
