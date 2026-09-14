// TypeScript peer of bench/parse_float.vader. `Number(text)` is correctly
// rounded, and a Float64Array viewed as Uint32Array gives the bit halves
// without BigInt.

const INPUT_COUNT = 4096;
const PASS_COUNT = 160;

const FRACTIONS = ["5", "25", "125", "0625", "1", "7", "142857", "33333333"];
const EXPONENTS = ["", "e3", "e-3", "e17", "e-17"];

function buildInputs(): string[] {
  const out: string[] = [];
  for (let index = 0; index < INPUT_COUNT; index++) {
    const mantissa = (index * 1103515245) % 1000003;
    out.push(`${mantissa}.${FRACTIONS[index % 8]}${EXPONENTS[index % 5]}`);
  }
  return out;
}

const inputs = buildInputs();
const view = new Float64Array(1);
const halves = new Uint32Array(view.buffer);
let high = 0;
let low = 0;
for (let pass = 0; pass < PASS_COUNT; pass++) {
  for (let i = 0; i < inputs.length; i++) {
    const parsed = Number(inputs[i]!);
    if (!Number.isNaN(parsed)) {
      view[0] = parsed;
      high += halves[1]!;
      low += halves[0]!;
    }
  }
}
console.log(`parse_float inputs=${INPUT_COUNT} passes=${PASS_COUNT} high=${high} low=${low}`);
