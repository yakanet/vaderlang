// TypeScript peer of bench/arr_set/arr_set.vader. Same algorithm (indexed
// read-modify-write bounded by a.length, 100 000 passes), same checksum.

const N = 1024;

const a: number[] = [];
for (let i = 0; i < N; i++) a[i] = i;

let sum = 0;
for (let pass = 0; pass < 100_000; pass++) {
  for (let i = 0; i < a.length; i++) {
    a[i] = a[i]! + 1;
    sum += a[i]!;
  }
}
console.log(`arr_set ${sum}`);
