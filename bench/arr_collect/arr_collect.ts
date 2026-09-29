// TypeScript peer of bench/arr_collect.vader. Uses the idiomatic eager
// `a.filter(isOdd).map(square)` — two fresh arrays per pass, the natural JS
// shape — vs Vader's fused filter + map collected into one array.

const N = 1024;
const a: number[] = new Array(N);
for (let i = 0; i < N; i++) a[i] = i;

const isOdd = (x: number): boolean => x % 2 === 1;
const square = (x: number): number => x * x;

let total = 0;
for (let pass = 0; pass < 40_000; pass++) {
  const out = a.filter(isOdd).map(square);
  total += out.length + out[out.length - 1]!;
}
console.log(`arr_collect ${total}`);
