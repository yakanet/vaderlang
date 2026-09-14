// TypeScript peer of bench/fmt_float.vader. `String(x)` on a number is the
// shortest round-trip decimal, the same answer the other three produce.

const COUNT = 60_000;
const DIVISOR = 7;

let length = 0;
let hash = 0;
for (let i = 1; i < COUNT; i++) {
  if (i % DIVISOR === 0) continue;
  const rendered = String(i / DIVISOR);
  length += rendered.length;
  for (let position = 0; position < rendered.length; position++) {
    hash += (position + 1) * rendered.charCodeAt(position);
  }
}
console.log(`fmt_float count=${COUNT} length=${length} hash=${hash}`);
