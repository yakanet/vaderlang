// TypeScript peer of bench/interp/interp.vader. Same algorithm (format three
// integers into a string via interpolation, 200 000 times), same checksum.
// The payload carries a leading `🚀` (a supplementary-plane codepoint), so the
// checksum counts CODEPOINTS (`[...s].length` iterates by codepoint), matching
// Vader's s.len() — plain `s.length` counts UTF-16 code units (🚀 = 2) and would
// diverge.

let total = 0;
for (let i = 0; i < 200_000; i++) {
  const s = `🚀 val=${i} x=${i * 2} y=${i - 1}`;
  total += [...s].length;
}
console.log(`interp ${total}`);
