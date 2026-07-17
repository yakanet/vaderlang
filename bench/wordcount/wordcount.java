// Java peer of bench/wordcount.vader. The text is materialised to a byte[]
// once, then the same whitespace state machine scans it PASSES times. The
// payload is ASCII so the signed `byte` never goes negative.

import java.nio.charset.StandardCharsets;

static final String LINE = "the quick brown fox jumps over the lazy dog\n";
static final int REPS = 40_000;
static final int PASSES = 15;

void main() {
    String text = LINE.repeat(REPS);
    byte[] data = text.getBytes(StandardCharsets.UTF_8);
    int nb = data.length;

    long words = 0, lines = 0, total = 0;
    for (int p = 0; p < PASSES; p++) {
        long w = 0, ln = 0;
        boolean inWord = false;
        for (int i = 0; i < nb; i++) {
            byte b = data[i];
            if (b == '\n') ln++;
            boolean isSpace = b == ' ' || b == '\n';
            if (isSpace) {
                inWord = false;
            } else {
                if (!inWord) w++;
                inWord = true;
            }
        }
        words = w;
        lines = ln;
        total += w;
    }
    IO.println("wordcount bytes=%d words=%d lines=%d total=%d".formatted(nb, words, lines, total));
}
