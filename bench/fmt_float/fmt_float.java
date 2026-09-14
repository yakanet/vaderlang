// Java peer of bench/fmt_float.vader. Since JDK 19 `Double.toString` is the
// shortest round-trip decimal, so it agrees with the other three.

static final int COUNT = 60_000;
static final int DIVISOR = 7;

void main() {
    long length = 0, hash = 0;
    for (int i = 1; i < COUNT; i++) {
        if (i % DIVISOR == 0) continue;
        String rendered = Double.toString((double) i / DIVISOR);
        length += rendered.length();
        for (int position = 0; position < rendered.length(); position++) {
            hash += (long) (position + 1) * rendered.charAt(position);
        }
    }
    IO.println("fmt_float count=%d length=%d hash=%d".formatted(COUNT, length, hash));
}
