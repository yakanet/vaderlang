// Go peer of bench/arr_collect.vader. Uses range-over-func iterators (Go 1.23+
// `iter.Seq`) for the lazy filter + map and `slices.Collect` to build the
// result — the language's lazy pipeline drained into a slice, mirroring
// Vader's fused `a.filter(is_odd).map(square).collect()`.

package main

import (
	"fmt"
	"iter"
	"slices"
)

func filtered[T any](s []T, keep func(T) bool) iter.Seq[T] {
	return func(yield func(T) bool) {
		for _, x := range s {
			if keep(x) && !yield(x) {
				return
			}
		}
	}
}

func mapped[T, U any](seq iter.Seq[T], f func(T) U) iter.Seq[U] {
	return func(yield func(U) bool) {
		for x := range seq {
			if !yield(f(x)) {
				return
			}
		}
	}
}

func isOdd(x int32) bool { return x%2 == 1 }

func square(x int32) int64 { return int64(x) * int64(x) }

func main() {
	const n = 1024
	a := make([]int32, n)
	for i := 0; i < n; i++ {
		a[i] = int32(i)
	}
	var total int64
	for pass := 0; pass < 40000; pass++ {
		out := slices.Collect(mapped(filtered(a, isOdd), square))
		total += int64(len(out)) + out[len(out)-1]
	}
	fmt.Printf("arr_collect %d\n", total)
}
