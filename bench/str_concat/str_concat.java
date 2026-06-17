// Java peer of bench/str_concat/str_concat.vader. Same algorithm (build a
// 13-byte string by repeated +, 300 000 times), same checksum. `s` is not
// final, so each `s + "..."` is a runtime concat (not constant-folded). For
// this ASCII payload String.length() equals Vader's bytes().len().

public class str_concat {
    public static void main(String[] args) {
        long total = 0;
        for (int i = 0; i < 300_000; i++) {
            String s = "a";
            s = s + "bcd";
            s = s + "efgh";
            s = s + "ijklm";
            total += s.length();
        }
        System.out.printf("str_concat %d%n", total);
    }
}
