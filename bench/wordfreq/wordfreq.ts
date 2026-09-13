// TypeScript peer of bench/wordfreq.vader. The corpus is decoded once to a
// string and each token is taken with `corpus.slice()` — what a JS tokenizer
// does, rather than running a TextDecoder per token. The payload is ASCII so a
// string index is a byte index.

const VOCABULARY_SIZE = 4096;
const TOKEN_COUNT = 300_000;
const WORD_LENGTH = 6;
const SCRAMBLE_MULTIPLIER = 2654435761;
const VOCABULARY_STRIDE = 2731;
const VOCABULARY_SPACE = 308_915_776;

function appendWord(out: number[], index: number): void {
  let scrambled = (index * SCRAMBLE_MULTIPLIER) % VOCABULARY_SPACE;
  for (let position = 0; position < WORD_LENGTH; position++) {
    out.push(97 + (scrambled % 26));
    scrambled = Math.floor(scrambled / 26);
  }
}

function vocabularyWord(index: number): string {
  const out: number[] = [];
  appendWord(out, index);
  return String.fromCharCode(...out);
}

const corpusBytes: number[] = [];
for (let tokenIndex = 0; tokenIndex < TOKEN_COUNT; tokenIndex++) {
  appendWord(corpusBytes, (tokenIndex * VOCABULARY_STRIDE) % VOCABULARY_SIZE);
  corpusBytes.push(32);
}
const corpus = new TextDecoder().decode(new Uint8Array(corpusBytes));

const counts = new Map<string, number>();
for (let tokenIndex = 0; tokenIndex < TOKEN_COUNT; tokenIndex++) {
  const start = tokenIndex * (WORD_LENGTH + 1);
  const token = corpus.slice(start, start + WORD_LENGTH);
  counts.set(token, (counts.get(token) ?? 0) + 1);
}

let checksum = 0;
for (let index = 0; index < VOCABULARY_SIZE; index++) {
  const seen = counts.get(vocabularyWord(index));
  if (seen !== undefined) checksum += seen * (index + 1);
}
console.log(
  `wordfreq vocabulary=${VOCABULARY_SIZE} tokens=${TOKEN_COUNT} distinct=${counts.size} checksum=${checksum}`,
);
