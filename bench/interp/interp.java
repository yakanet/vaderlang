// Java peer of bench/interp/interp.vader. Same algorithm (format three
// integers into a string via interpolation, 200 000 times), same checksum.
// Java has no string interpolation ; idiomatic concatenation builds the same
// bytes, and String.length() equals Vader's bytes().len() for ASCII.

public class interp {
    public static void main(String[] args) {
        long total = 0;
        for (int i = 0; i < 200_000; i++) {
            String s = "val=" + i + " x=" + (i * 2) + " y=" + (i - 1);
            total += s.length();
        }
        System.out.printf("interp %d%n", total);
    }
}
