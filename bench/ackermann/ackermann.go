// Go peer of bench/ackermann.vader. Plain recursive function ; goroutine
// stacks grow on demand so the ~2 k-deep A(3,9) call needs no tuning.

package main

import "fmt"

const hi = 9

func ackermann(m, n int32) int64 {
	if m == 0 {
		return int64(n) + 1
	}
	if n == 0 {
		return ackermann(m-1, 1)
	}
	return ackermann(m-1, int32(ackermann(m, n-1)))
}

func main() {
	var total int64
	for n := int32(0); n <= hi; n++ {
		total += ackermann(3, n)
	}
	fmt.Printf("ackermann hi=%d total=%d\n", hi, total)
}
