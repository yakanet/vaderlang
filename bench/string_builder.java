// Java peer of bench/string_builder.vader. Uses `java.lang.StringBuilder`,
// the stdlib's pre-allocated-buffer concatenator — closest analogue to
// Vader's `StringBuilder`.

public class string_builder {
    static final int N = 50_000;
    static final String FRAGMENT = "The quick brown fox jumps over the lazy dog.\n";

    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(FRAGMENT);
        }
        String result = sb.toString();
        System.out.printf("string_builder N=%d len=%d%n", N, result.length());
    }
}
