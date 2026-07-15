// Java peer of bench/string_builder.vader. Uses `java.lang.StringBuilder`,
// the stdlib's pre-allocated-buffer concatenator — closest analogue to
// Vader's `StringBuilder`.

static final int N = 80_000;
static final String FRAGMENT = "The quick brown fox jumps over the lazy dog.\n";

void main() {
    var sb = new StringBuilder();
    for (int i = 0; i < N; i++) {
        sb.append(FRAGMENT);
    }
    var result = sb.toString();
    IO.println("string_builder N=%d len=%d".formatted(N, result.length()));
}
