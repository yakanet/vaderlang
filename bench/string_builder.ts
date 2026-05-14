// TypeScript peer of bench/string_builder.vader. Idiomatic JS uses an
// array of fragments + final .join(""), mirroring Vader's StringBuilder
// which keeps parts in a string[] and flushes once.

const N = 50_000;
const FRAGMENT = "The quick brown fox jumps over the lazy dog.\n";

const parts: string[] = [];
for (let i = 0; i < N; i++) {
  parts.push(FRAGMENT);
}
const result = parts.join("");
console.log(`string_builder N=${N} len=${result.length}`);
