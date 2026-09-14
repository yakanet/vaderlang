// Go peer of bench/parse_float.vader. `strconv.ParseFloat` is correctly rounded,
// which is the property the checksum pins.

package main

import (
	"fmt"
	"math"
	"strconv"
)

const (
	inputCount = 4096
	passCount  = 160
)

var fractions = []string{"5", "25", "125", "0625", "1", "7", "142857", "33333333"}
var exponents = []string{"", "e3", "e-3", "e17", "e-17"}

func buildInputs() []string {
	out := make([]string, 0, inputCount)
	for index := 0; index < inputCount; index++ {
		mantissa := int64(index) * 1103515245 % 1000003
		out = append(out, fmt.Sprintf("%d.%s%s", mantissa, fractions[index%8], exponents[index%5]))
	}
	return out
}

func main() {
	inputs := buildInputs()
	var high, low int64
	for pass := 0; pass < passCount; pass++ {
		for _, text := range inputs {
			parsed, err := strconv.ParseFloat(text, 64)
			if err == nil {
				bits := math.Float64bits(parsed)
				high += int64(bits >> 32)
				low += int64(bits & 0xFFFFFFFF)
			}
		}
	}
	fmt.Printf("parse_float inputs=%d passes=%d high=%d low=%d\n", inputCount, passCount, high, low)
}
