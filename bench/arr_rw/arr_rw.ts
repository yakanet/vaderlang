// TypeScript peer of bench/arr_rw/arr_rw.vader. Same algorithm (read-modify-
// write over a fixed i32 buffer, 100 000 passes), same checksum. Int32Array
// mirrors Vader's `i32[]` element semantics.

const N = 1024;

const a = new Int32Array(N);
for (let i = 0; i < N; i++) a[i] = i;

let sum = 0;
for (let pass = 0; pass < 100_000; pass++) {
  for (let i = 0; i < N; i++) {
    a[i] = a[i] + 1;
    sum += a[i];
  }
}
console.log(`arr_rw ${sum}`);
