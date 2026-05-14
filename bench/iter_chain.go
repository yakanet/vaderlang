// Go peer of bench/iter_chain.vader. Go's stdlib doesn't ship lazy iterator
// chains, so we use a direct for-loop — the idiomatic shape. This makes Go
// the strict lower bound for the workload (no chain abstraction, no
// per-item alloc) ; Vader's lazy chain vs Go's direct loop measures the
// cost of the chain abstraction itself.

package main

import "fmt"

const N = 1_000_000

func main() {
	var total int64
	for i := int32(0); i < N; i++ {
		if i%2 == 0 {
			total += int64(i) * int64(i)
		}
	}
	fmt.Printf("iter_chain N=%d total=%d\n", int32(N), total)
}
