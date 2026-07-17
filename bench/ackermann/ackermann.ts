// TypeScript peer of bench/ackermann.vader. Plain recursive function ; every
// intermediate value fits in a double exactly, so `number` matches the Vader
// i64 result bit-for-bit.

const HI = 9;

function ackermann(m: number, n: number): number {
  if (m === 0) return n + 1;
  if (n === 0) return ackermann(m - 1, 1);
  return ackermann(m - 1, ackermann(m, n - 1));
}

let total = 0;
for (let n = 0; n <= HI; n++) total += ackermann(3, n);
console.log(`ackermann hi=${HI} total=${total}`);
