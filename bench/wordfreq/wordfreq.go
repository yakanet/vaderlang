// Go peer of bench/wordfreq.vader. The corpus is a []byte, and each token is
// turned into a string with `string(corpus[start:end])` — the conversion Go
// tokenizers write, which allocates and copies the bytes before the map hashes
// them.

package main

import "fmt"

const (
	vocabularySize     = 4096
	tokenCount         = 300_000
	wordLength         = 6
	scrambleMultiplier = 2654435761
	vocabularyStride   = 2731
	vocabularySpace    = 308_915_776
)

func appendWord(out []byte, index int32) []byte {
	scrambled := int64(index) * scrambleMultiplier % vocabularySpace
	for position := 0; position < wordLength; position++ {
		out = append(out, byte('a'+scrambled%26))
		scrambled = scrambled / 26
	}
	return out
}

func vocabularyWord(index int32) string {
	return string(appendWord(make([]byte, 0, wordLength), index))
}

func main() {
	corpus := make([]byte, 0, tokenCount*(wordLength+1))
	for tokenIndex := 0; tokenIndex < tokenCount; tokenIndex++ {
		wordIndex := int32(int64(tokenIndex) * vocabularyStride % vocabularySize)
		corpus = appendWord(corpus, wordIndex)
		corpus = append(corpus, ' ')
	}

	counts := make(map[string]int32)
	for tokenIndex := 0; tokenIndex < tokenCount; tokenIndex++ {
		start := tokenIndex * (wordLength + 1)
		token := string(corpus[start : start+wordLength])
		counts[token] = counts[token] + 1
	}

	var checksum int64
	for index := 0; index < vocabularySize; index++ {
		if seen, ok := counts[vocabularyWord(int32(index))]; ok {
			checksum += int64(seen) * int64(index+1)
		}
	}
	fmt.Printf("wordfreq vocabulary=%d tokens=%d distinct=%d checksum=%d\n",
		vocabularySize, tokenCount, len(counts), checksum)
}
