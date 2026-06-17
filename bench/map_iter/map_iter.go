// Go peer of bench/map_iter.vader. `map[int32]int32` iterated with the
// built-in `for k, v := range m` loop — Go's most idiomatic shape and
// the closest analogue to Vader's `for entry in m`.

package main

import "fmt"

const (
	innerKeys  = 1_000
	outerLoops = 1_000
)

func main() {
	m := make(map[int32]int32, innerKeys)
	for i := int32(0); i < innerKeys; i++ {
		m[i] = i
	}
	var total int64
	for outer := 0; outer < outerLoops; outer++ {
		for _, v := range m {
			total += int64(v)
		}
	}
	fmt.Printf("map_iter inner=%d outer=%d total=%d\n", innerKeys, outerLoops, total)
}
