// TypeScript peer of bench/matmul.vader. An array of arrays, and the row is
// hoisted the same way, so the comparison is of the indexing and not of the
// loop shape. Values stay well inside an f64 mantissa.

const SIZE = 260;

function build(modulus: number): number[][] {
  const out: number[][] = [];
  for (let row = 0; row < SIZE; row++) {
    const line: number[] = [];
    for (let column = 0; column < SIZE; column++) {
      line.push((row + column) % modulus);
    }
    out.push(line);
  }
  return out;
}

const left = build(7);
const right = build(5);
let total = 0;
for (let row = 0; row < SIZE; row++) {
  const leftRow = left[row]!;
  for (let column = 0; column < SIZE; column++) {
    let cell = 0;
    for (let k = 0; k < SIZE; k++) {
      cell += leftRow[k]! * right[k]![column]!;
    }
    total += cell;
  }
}
console.log(`matmul size=${SIZE} total=${total}`);
