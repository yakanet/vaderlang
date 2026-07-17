// TypeScript peer of bench/hashmap.vader. JS `Map` keyed by i32, driven
// through the same insert / lookup / delete / probe rounds. The key
// generator stays under 2^53 so plain `number` is exact — no BigInt in the
// hot path, matching the Vader i64 semantics without penalising the runtime.

const N = 100_000;
const ROUNDS = 8;
const STRIDE = 131101;
const KEYSPACE = 200003;

const m = new Map<number, number>();
let chk = 0;
for (let r = 0; r < ROUNDS; r++) {
  for (let i = 0; i < N; i++) {
    const k = (i * STRIDE) % KEYSPACE;
    m.set(k, k + r);
  }
  for (let i = 0; i < N; i++) {
    const k = (i * STRIDE) % KEYSPACE;
    const v = m.get(k);
    if (v !== undefined) chk += v;
  }
  for (let i = 0; i < N; i++) {
    if (i % 2 === 0) {
      const k = (i * STRIDE) % KEYSPACE;
      m.delete(k);
    }
  }
  for (let i = 0; i < N; i++) {
    const k = (i * STRIDE) % KEYSPACE;
    if (m.has(k)) chk += 1;
  }
}
console.log(`hashmap rounds=${ROUNDS} n=${N} size=${m.size} chk=${chk}`);
