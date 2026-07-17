// Go peer of bench/wordcount.vader. `[]byte(text)` once, then the same
// whitespace state machine scans it PASSES times.

package main

import (
	"fmt"
	"strings"
)

const (
	reps   = 40_000
	passes = 15
)

const line = "the quick brown fox jumps over the lazy dog\n"

func main() {
	text := strings.Repeat(line, reps)
	data := []byte(text)
	nb := len(data)

	var words, lines, total int64
	for p := 0; p < passes; p++ {
		var w, ln int64
		inWord := false
		for i := 0; i < nb; i++ {
			b := data[i]
			if b == '\n' {
				ln++
			}
			isSpace := b == ' ' || b == '\n'
			if isSpace {
				inWord = false
			} else {
				if !inWord {
					w++
				}
				inWord = true
			}
		}
		words = w
		lines = ln
		total += w
	}
	fmt.Printf("wordcount bytes=%d words=%d lines=%d total=%d\n", nb, words, lines, total)
}
