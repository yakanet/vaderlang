// Go peer of bench/fmt_float.vader. `%v` on a float64 is strconv's shortest
// round-trip, the same answer Vader's Ryū produces.

package main

import "fmt"

const (
	count   = 60_000
	divisor = 7
)

func main() {
	var length, hash int64
	for i := 1; i < count; i++ {
		if i%divisor == 0 {
			continue
		}
		rendered := fmt.Sprintf("%v", float64(i)/float64(divisor))
		length += int64(len(rendered))
		for position, b := range []byte(rendered) {
			hash += int64(position+1) * int64(b)
		}
	}
	fmt.Printf("fmt_float count=%d length=%d hash=%d\n", count, length, hash)
}
