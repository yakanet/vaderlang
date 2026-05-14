// TypeScript peer of bench/iter_chain.vader. Uses generator functions for
// a lazy chain that mirrors Vader's MapIterator + FilterIterator + Range —
// per-item allocation of the yielded {value, done} pair, three-level
// dispatch through `for…of`.

const N = 1_000_000;

function* range(n: number): Generator<number> {
  for (let i = 0; i < n; i++) yield i;
}

function* filterGen<T>(it: Iterable<T>, pred: (x: T) => boolean): Generator<T> {
  for (const x of it) if (pred(x)) yield x;
}

function* mapGen<T, U>(it: Iterable<T>, f: (x: T) => U): Generator<U> {
  for (const x of it) yield f(x);
}

const isEven = (x: number): boolean => x % 2 === 0;
const squareI64 = (x: number): bigint => BigInt(x) * BigInt(x);

let total = 0n;
for (const x of mapGen(filterGen(range(N), isEven), squareI64)) {
  total += x;
}
console.log(`iter_chain N=${N} total=${total}`);
