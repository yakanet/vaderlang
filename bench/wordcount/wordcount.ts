// TypeScript peer of bench/wordcount.vader. The text is encoded to a
// Uint8Array once, then the same whitespace state machine scans it PASSES
// times. Byte codes 32 (' ') and 10 ('\n') are compared numerically.

const LINE = "the quick brown fox jumps over the lazy dog\n";
const REPS = 40_000;
const PASSES = 15;

const text = LINE.repeat(REPS);
const data = new TextEncoder().encode(text);
const nb = data.length;

let words = 0, lines = 0, total = 0;
for (let p = 0; p < PASSES; p++) {
  let w = 0, ln = 0;
  let inWord = false;
  for (let i = 0; i < nb; i++) {
    const b = data[i]!;
    if (b === 10) ln++;
    const isSpace = b === 32 || b === 10;
    if (isSpace) {
      inWord = false;
    } else {
      if (!inWord) w++;
      inWord = true;
    }
  }
  words = w;
  lines = ln;
  total += w;
}
console.log(`wordcount bytes=${nb} words=${words} lines=${lines} total=${total}`);
