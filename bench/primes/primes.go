// Go peer of bench/primes.vader. Same algorithm (trial division), same N,
// same checksum.

package main

import "fmt"

const N = 1_000_000

func isPrime(n int32) bool {
	if n < 2 {
		return false
	}
	if n < 4 {
		return true
	}
	if n%2 == 0 {
		return false
	}
	for d := int32(3); d*d <= n; d += 2 {
		if n%d == 0 {
			return false
		}
	}
	return true
}

func main() {
	var count int64
	var sum int64
	for n := int32(2); n <= N; n++ {
		if isPrime(n) {
			count++
			sum += int64(n)
		}
	}
	fmt.Printf("primes N=%d count=%d sum=%d\n", int32(N), count, sum)
}
