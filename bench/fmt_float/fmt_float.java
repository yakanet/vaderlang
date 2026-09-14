// Java peer of bench/fmt_float.vader. Since JDK 19 `Double.toString` is the
// shortest round-trip decimal, so it agrees with the other three.

static final int COUNT = 60_000;
static final int DIVISOR = 7;

void main() {
    long length = 0, hash = 0;
    for (int i = 1; i < COUNT; i++) {
        if (i % DIVISOR == 0) continue;
        String rendered = Double.toString((double) i / 7.0);
        length += rendered.length();
        for (int j = 0; j < rendered.length(); j++) {
            hash = (hash * 31 + rendered.charAt(j)) % 1_000_000_007;
        }
    }
    IO.println("fmt_float count=%d length=%d hash=%d".formatted(COUNT, length, hash));
}
