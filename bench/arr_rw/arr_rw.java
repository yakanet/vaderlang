// Java peer of bench/arr_rw/arr_rw.vader. Same algorithm (read-modify-write
// over a fixed i32 buffer, 100 000 passes), same checksum.

public class arr_rw {
    public static void main(String[] args) {
        final int n = 1024;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = i;

        long sum = 0;
        for (int pass = 0; pass < 100_000; pass++) {
            for (int i = 0; i < n; i++) {
                a[i] = a[i] + 1;
                sum += a[i];
            }
        }
        System.out.printf("arr_rw %d%n", sum);
    }
}
