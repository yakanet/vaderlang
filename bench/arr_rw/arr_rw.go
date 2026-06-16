// Go peer of bench/arr_rw/arr_rw.vader. Same algorithm (read-modify-write
// over a fixed i32 buffer, 100 000 passes), same checksum.

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
		for i := 0; i < n; i++ {
			a[i] = a[i] + 1
			sum += int64(a[i])
		}
	}
	fmt.Printf("arr_rw %d\n", sum)
}
