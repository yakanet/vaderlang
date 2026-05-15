// TypeScript peer of bench/map_iter.vader. JS `Map` keyed by i32 ;
// repeated iteration via `for...of map`. Bun's V8 inlines the iterator
// protocol well — closest match to Vader's fused for-in dispatch path.

const INNER_KEYS = 1_000;
const OUTER_LOOPS = 1_000;

const m = new Map<number, number>();
for (let i = 0; i < INNER_KEYS; i++) m.set(i, i);

let total = 0n;
for (let outer = 0; outer < OUTER_LOOPS; outer++) {
  for (const [, value] of m) {
    total += BigInt(value);
  }
}
console.log(`map_iter inner=${INNER_KEYS} outer=${OUTER_LOOPS} total=${total}`);
