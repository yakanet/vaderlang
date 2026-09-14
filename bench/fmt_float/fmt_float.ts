// TypeScript peer of bench/fmt_float.vader. `String(x)` on a number is the
// shortest round-trip decimal, the same answer the other three produce.

const COUNT = 60_000;
const DIVISOR = 7;

let length = 0;
let hash = 0;
for (let i = 1; i < COUNT; i++) {
  if (i % DIVISOR === 0) continue;
  const rendered = String(i / 7);
  length += rendered.length;
  for (let j = 0; j < rendered.length; j++) {
    hash = (hash * 31 + rendered.charCodeAt(j)) % 1_000_000_007;
  }
}
console.log(`fmt_float count=${COUNT} length=${length} hash=${hash}`);
