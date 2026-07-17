// TypeScript peer of bench/quicksort.vader. Same median-of-three Lomuto
// quicksort over an Int32Array (mirrors i32[]). The rolling-hash checksum
// stays below 2^53, so plain `number` is exact — no BigInt.

const N = 1_000_000;
const STRIDE = 999983;
const N_MOD = 1_000_000;

function qsort(a: Int32Array, lo: number, hi: number): void {
  let l = lo, h = hi;
  while (h - l > 1) {
    const mid = l + ((h - l) >> 1);
    const hh = h - 1;
    if (a[l]! > a[mid]!) { const t = a[l]!; a[l] = a[mid]!; a[mid] = t; }
    if (a[l]! > a[hh]!) { const t = a[l]!; a[l] = a[hh]!; a[hh] = t; }
    if (a[mid]! < a[hh]!) { const t = a[mid]!; a[mid] = a[hh]!; a[hh] = t; }
    const pivot = a[hh]!;
    let i = l;
    for (let j = l; j < hh; j++) {
      if (a[j]! < pivot) { const t = a[i]!; a[i] = a[j]!; a[j] = t; i++; }
    }
    { const t = a[i]!; a[i] = a[hh]!; a[hh] = t; }
    if (i - l < h - (i + 1)) { qsort(a, l, i); l = i + 1; }
    else { qsort(a, i + 1, h); h = i; }
  }
}

const a = new Int32Array(N);
for (let i = 0; i < N; i++) a[i] = (i * STRIDE) % N_MOD;
qsort(a, 0, N);
let chk = 0;
for (let i = 0; i < N; i++) chk = (chk * 31 + a[i]!) % 2147483648;
console.log(`quicksort n=${N} chk=${chk}`);
