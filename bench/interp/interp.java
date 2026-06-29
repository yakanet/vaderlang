// Java peer of bench/interp/interp.vader. Same algorithm (format three
// integers into a string via interpolation, 200 000 times), same checksum.
// Java has no string interpolation ; idiomatic concatenation builds the same
// string. The payload carries a leading `🚀` (a supplementary-plane codepoint),
// so the checksum counts CODEPOINTS (codePointCount), matching Vader's s.len() —
// String.length() counts UTF-16 code units (🚀 = 2) and would diverge.

public class interp {
    public static void main(String[] args) {
        long total = 0;
        for (int i = 0; i < 200_000; i++) {
            String s = "🚀 val=" + i + " x=" + (i * 2) + " y=" + (i - 1);
            total += s.codePointCount(0, s.length());
        }
        System.out.printf("interp %d%n", total);
    }
}
