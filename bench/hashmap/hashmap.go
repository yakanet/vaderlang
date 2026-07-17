// Go peer of bench/hashmap.vader. `map[int32]int32` driven through the same
// insert / lookup / delete / probe rounds — Go's built-in map is the direct
// analogue of Vader's compact-dict MutableMap.

package main

import "fmt"

const (
	n        = 100_000
	rounds   = 8
	stride   = 131101
	keyspace = 200003
)

func main() {
	m := make(map[int32]int32) // grow from empty — no port pre-sizes, so all measure the grow path
	var chk int64
	for r := int32(0); r < rounds; r++ {
		for i := 0; i < n; i++ {
			k := int32((int64(i) * stride) % keyspace)
			m[k] = k + r
		}
		for i := 0; i < n; i++ {
			k := int32((int64(i) * stride) % keyspace)
			if v, ok := m[k]; ok {
				chk += int64(v)
			}
		}
		for i := 0; i < n; i++ {
			if i%2 == 0 {
				k := int32((int64(i) * stride) % keyspace)
				delete(m, k)
			}
		}
		for i := 0; i < n; i++ {
			k := int32((int64(i) * stride) % keyspace)
			if _, ok := m[k]; ok {
				chk++
			}
		}
	}
	fmt.Printf("hashmap rounds=%d n=%d size=%d chk=%d\n", rounds, n, len(m), chk)
}
