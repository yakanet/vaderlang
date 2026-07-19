// Java peer of bench/arr_set/arr_set.vader. Same algorithm (indexed read-modify-
// write bounded by a.length, 100 000 passes), same checksum as arr_rw.

void main() {
    final int n = 1024;
    int[] a = new int[n];
    for (int i = 0; i < n; i++) a[i] = i;

    long sum = 0;
    for (int pass = 0; pass < 100_000; pass++) {
        for (int i = 0; i < a.length; i++) {
            a[i] = a[i] + 1;
            sum += a[i];
        }
    }
    IO.println("arr_set %d".formatted(sum));
}
