// Go peer of bench/arr_map.vader. Uses a range-over-func iterator (Go 1.23+
// `iter.Seq`) — the language's lazy map abstraction, one element at a time
// through the yield closure — mirroring Vader's fused `a.map(square)`.

package main

import (
	"fmt"
	"iter"
)

func mapped[T, U any](s []T, f func(T) U) iter.Seq[U] {
	return func(yield func(U) bool) {
		for _, x := range s {
			if !yield(f(x)) {
				return
			}
		}
	}
}

func square(x int32) int64 { return int64(x) * int64(x) }

func main() {
	const n = 1024
	a := make([]int32, n)
	for i := 0; i < n; i++ {
		a[i] = int32(i)
	}
	var sum int64
	for pass := 0; pass < 300000; pass++ {
		for x := range mapped(a, square) {
			sum += x
		}
	}
	fmt.Printf("arr_map %d\n", sum)
}
