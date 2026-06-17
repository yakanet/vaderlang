// TypeScript peer of bench/interp/interp.vader. Same algorithm (format three
// integers into a string via interpolation, 200 000 times), same checksum.
// The Vader checksum sums bytes().len() ; for this ASCII payload that equals
// the JS string length.

let total = 0;
for (let i = 0; i < 200_000; i++) {
  const s = `val=${i} x=${i * 2} y=${i - 1}`;
  total += s.length;
}
console.log(`interp ${total}`);
