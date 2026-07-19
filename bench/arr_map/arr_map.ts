// TypeScript peer of bench/arr_map.vader. Uses the idiomatic eager
// `a.map(x => x * x)` — which allocates a fresh result array every pass and
// then reduces it — the natural JS shape, vs Vader's fused (zero-alloc)
// `a.map(square)` iterator.

const N = 1024;
const a: number[] = new Array(N);
for (let i = 0; i < N; i++) a[i] = i;

let sum = 0;
for (let pass = 0; pass < 300_000; pass++) {
  sum += a.map((x) => x * x).reduce((s, x) => s + x, 0);
}
console.log(`arr_map ${sum}`);
