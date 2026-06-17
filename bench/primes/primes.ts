// TypeScript peer of bench/primes.vader. Same algorithm (trial division),
// same N, same checksum.

const N = 1_000_000;

function isPrime(n: number): boolean {
  if (n < 2) return false;
  if (n < 4) return true;
  if (n % 2 === 0) return false;
  let d = 3;
  while (d * d <= n) {
    if (n % d === 0) return false;
    d += 2;
  }
  return true;
}

let count = 0;
let sum = 0;
for (let n = 2; n <= N; n++) {
  if (isPrime(n)) {
    count += 1;
    sum += n;
  }
}
console.log(`primes N=${N} count=${count} sum=${sum}`);
