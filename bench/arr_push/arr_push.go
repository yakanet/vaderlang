// Go peer of bench/arr_push/arr_push.vader. Same algorithm (build then discard
// a fresh i32 slice via append, 200 × 100 000 = 20 M pushes), same checksum.
// `append` on a []int32 is exactly a typed store + amortised-doubling grow.

package main

import "fmt"

func main() {
	var total int64
	for pass := 0; pass < 200; pass++ {
		a := []int32{}
		for i := 0; i < 100000; i++ {
			a = append(a, int32(i))
		}
		total += int64(len(a))
	}
	fmt.Printf("arr_push %d\n", total)
}
