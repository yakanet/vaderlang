// Go peer of bench/iter_chain.vader. Go 1.23+ has range-over-func iterators
// (used in bench/arr_map.go), but for iter_chain we deliberately keep a direct
// for-loop as the strict lower bound — no chain abstraction, no per-item alloc ;
// Vader's lazy chain vs Go's direct loop measures the cost of the chain
// abstraction itself.

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
