// TypeScript peer of bench/split_join.vader. `String.prototype.split` and
// `Array.prototype.join` are the idiomatic pair.

const FIELD_COUNT = 20_000;
const PASS_COUNT = 24;
const SEPARATOR = ",";
const STRIDE = 1103515245;

function buildText(): string {
  const parts: string[] = [];
  for (let index = 0; index < FIELD_COUNT; index++) {
    parts.push(String((index * STRIDE) % 1000003));
  }
  return parts.join(SEPARATOR);
}

const text = buildText();
let pieces = 0;
let joinedLength = 0;
for (let pass = 0; pass < PASS_COUNT; pass++) {
  const parts = text.split(SEPARATOR);
  const kept: string[] = [];
  for (let i = 0; i < parts.length; i++) {
    if (parts[i]!.length % 2 === 1) kept.push(parts[i]!);
  }
  pieces += kept.length;
  joinedLength += kept.join(SEPARATOR).length;
}
console.log(
  `split_join fields=${FIELD_COUNT} passes=${PASS_COUNT} pieces=${pieces} length=${joinedLength}`,
);
