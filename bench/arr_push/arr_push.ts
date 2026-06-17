// TypeScript peer of bench/arr_push/arr_push.vader. Same algorithm (build then
// discard a fresh i32 array via push, 200 × 100 000 = 20 M pushes), same
// checksum. A dense number[] is V8's unboxed-elements analog of Vader's typed
// `i32[]` with amortised-doubling grow.

let total = 0;
for (let pass = 0; pass < 200; pass++) {
  const a: number[] = [];
  for (let i = 0; i < 100_000; i++) a.push(i);
  total += a.length;
}
console.log(`arr_push ${total}`);
