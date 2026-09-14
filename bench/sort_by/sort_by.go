// Go peer of bench/sort_by.vader. `slices.SortStableFunc` takes the elements and
// returns an ordering, which is the closest shape to the other three — and it
// must be the STABLE variant, since equal keys are common here and the checksum
// reads their order.

package main

import (
	"cmp"
	"fmt"
	"slices"
)

const (
	itemCount = 20_000
	passCount = 24
	stride    = 1103515245
)

func buildItems() []int64 {
	out := make([]int64, 0, itemCount)
	for index := 0; index < itemCount; index++ {
		out = append(out, int64(index)*stride%1000003)
	}
	return out
}

func main() {
	var checksum int64
	for pass := 0; pass < passCount; pass++ {
		items := buildItems()
		slices.SortStableFunc(items, func(a, b int64) int { return cmp.Compare(a%1000, b%1000) })
		for index, value := range items {
			checksum += int64(index+1) * (value % 97)
		}
	}
	fmt.Printf("sort_by items=%d passes=%d checksum=%d\n", itemCount, passCount, checksum)
}
