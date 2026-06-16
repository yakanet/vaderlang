// Go peer of bench/str_concat/str_concat.vader. Same algorithm (build a
// 13-byte string by repeated +, 300 000 times), same checksum. `len(s)` is the
// byte length, matching Vader's bytes().len().

package main

import "fmt"

func main() {
	var total int64
	for i := 0; i < 300000; i++ {
		s := "a"
		s = s + "bcd"
		s = s + "efgh"
		s = s + "ijklm"
		total += int64(len(s))
	}
	fmt.Printf("str_concat %d\n", total)
}
