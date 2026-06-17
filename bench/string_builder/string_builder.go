// Go peer of bench/string_builder.vader. Uses strings.Builder, the
// stdlib's pre-allocated-buffer concatenator — closest analogue to Vader's
// StringBuilder.

package main

import (
	"fmt"
	"strings"
)

const N = 80_000
const FRAGMENT = "The quick brown fox jumps over the lazy dog.\n"

func main() {
	var sb strings.Builder
	for i := 0; i < N; i++ {
		sb.WriteString(FRAGMENT)
	}
	result := sb.String()
	fmt.Printf("string_builder N=%d len=%d\n", N, len(result))
}
