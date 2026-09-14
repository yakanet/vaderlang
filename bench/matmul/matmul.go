// Go peer of bench/matmul.vader. A [][]int64 is a slice of slices, so the row
// lookup is the same shape as Vader's array of arrays.

package main

import "fmt"

const size = 260

func build(modulus int64) [][]int64 {
	out := make([][]int64, 0, size)
	for row := 0; row < size; row++ {
		line := make([]int64, 0, size)
		for column := 0; column < size; column++ {
			line = append(line, int64(row+column)%modulus)
		}
		out = append(out, line)
	}
	return out
}

func main() {
	left := build(7)
	right := build(5)
	var total int64
	for row := 0; row < size; row++ {
		leftRow := left[row]
		for column := 0; column < size; column++ {
			var cell int64
			for k := 0; k < size; k++ {
				cell += leftRow[k] * right[k][column]
			}
			total += cell
		}
	}
	fmt.Printf("matmul size=%d total=%d\n", size, total)
}
