// Java peer of bench/split_join.vader. `String.split` takes a regex, but the
// single-character fast path skips the engine — which is what Java code writes
// for a separator this simple.

import java.util.ArrayList;
import java.util.List;

static final int FIELD_COUNT = 20_000;
static final int PASS_COUNT = 24;
static final String SEPARATOR = ",";
static final long STRIDE = 1103515245L;

static String buildText() {
    List<String> parts = new ArrayList<>(FIELD_COUNT);
    for (int index = 0; index < FIELD_COUNT; index++) {
        parts.add(Long.toString((long) index * STRIDE % 1000003L));
    }
    return String.join(SEPARATOR, parts);
}

void main() {
    String text = buildText();
    long pieces = 0, joinedLength = 0;
    for (int pass = 0; pass < PASS_COUNT; pass++) {
        String[] parts = text.split(SEPARATOR);
        List<String> kept = new ArrayList<>(parts.length);
        for (String part : parts) {
            if (part.length() % 2 == 1) kept.add(part);
        }
        pieces += kept.size();
        joinedLength += String.join(SEPARATOR, kept).length();
    }
    IO.println("split_join fields=%d passes=%d pieces=%d length=%d"
        .formatted(FIELD_COUNT, PASS_COUNT, pieces, joinedLength));
}
