// Java peer of bench/wordfreq.vader. The corpus is a byte[], and each token is
// turned into a String with the offset/length constructor — the conversion a
// Java tokenizer writes, which copies the bytes before the map hashes them.

import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;

static final int VOCABULARY_SIZE = 4096;
static final int TOKEN_COUNT = 300_000;
static final int WORD_LENGTH = 6;
static final long SCRAMBLE_MULTIPLIER = 2654435761L;
static final long VOCABULARY_STRIDE = 2731L;
static final long VOCABULARY_SPACE = 308_915_776L;

static int appendWord(byte[] out, int at, int index) {
    long scrambled = index * SCRAMBLE_MULTIPLIER % VOCABULARY_SPACE;
    for (int position = 0; position < WORD_LENGTH; position++) {
        out[at + position] = (byte) ('a' + scrambled % 26);
        scrambled = scrambled / 26;
    }
    return at + WORD_LENGTH;
}

static String vocabularyWord(int index) {
    byte[] out = new byte[WORD_LENGTH];
    appendWord(out, 0, index);
    return new String(out, StandardCharsets.US_ASCII);
}

void main() {
    byte[] corpus = new byte[TOKEN_COUNT * (WORD_LENGTH + 1)];
    for (int tokenIndex = 0; tokenIndex < TOKEN_COUNT; tokenIndex++) {
        int wordIndex = (int) (tokenIndex * VOCABULARY_STRIDE % VOCABULARY_SIZE);
        int at = appendWord(corpus, tokenIndex * (WORD_LENGTH + 1), wordIndex);
        corpus[at] = ' ';
    }

    Map<String, Integer> counts = new HashMap<>();
    for (int tokenIndex = 0; tokenIndex < TOKEN_COUNT; tokenIndex++) {
        String token = new String(
            corpus, tokenIndex * (WORD_LENGTH + 1), WORD_LENGTH, StandardCharsets.US_ASCII);
        counts.merge(token, 1, Integer::sum);
    }

    long checksum = 0;
    for (int index = 0; index < VOCABULARY_SIZE; index++) {
        Integer seen = counts.get(vocabularyWord(index));
        if (seen != null) checksum += (long) seen * (index + 1);
    }
    IO.println("wordfreq vocabulary=%d tokens=%d distinct=%d checksum=%d"
        .formatted(VOCABULARY_SIZE, TOKEN_COUNT, counts.size(), checksum));
}
