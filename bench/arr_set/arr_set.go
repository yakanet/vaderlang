// Go peer of bench/arr_set/arr_set.vader. Same algorithm (indexed read-modify-
// write bounded by len(a), 100 000 passes), same checksum as arr_rw.

package main

import "fmt"

func main() {
	const n = 1024
	a := make([]int32, n)
	for i := 0; i < n; i++ {
		a[i] = int32(i)
	}
	var sum int64
	for pass := 0; pass < 100000; pass++ {
		for i := 0; i < len(a); i++ {
			a[i] = a[i] + 1
			sum += int64(a[i])
		}
	}
	fmt.Printf("arr_set %d\n", sum)
}
