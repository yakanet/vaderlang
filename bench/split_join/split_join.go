// Go peer of bench/split_join.vader. `strings.Split` returns slices sharing the
// original backing array, so Go does no copying here — part of what the row
// compares.

package main

import (
	"fmt"
	"strconv"
	"strings"
)

const (
	fieldCount = 20_000
	passCount  = 24
	separator  = ","
	stride     = 1103515245
)

func buildText() string {
	parts := make([]string, 0, fieldCount)
	for index := 0; index < fieldCount; index++ {
		parts = append(parts, strconv.FormatInt(int64(index)*stride%1000003, 10))
	}
	return strings.Join(parts, separator)
}

func main() {
	text := buildText()
	var pieces, joinedLength int64
	for pass := 0; pass < passCount; pass++ {
		parts := strings.Split(text, separator)
		kept := make([]string, 0, len(parts))
		for _, part := range parts {
			if len(part)%2 == 1 {
				kept = append(kept, part)
			}
		}
		pieces += int64(len(kept))
		joinedLength += int64(len(strings.Join(kept, separator)))
	}
	fmt.Printf("split_join fields=%d passes=%d pieces=%d length=%d\n",
		fieldCount, passCount, pieces, joinedLength)
}
