// Java peer of bench/arr_collect.vader. Uses the Stream API — a fresh
// Arrays.stream(a).filter(p).mapToLong(f).toArray() per pass — mirroring
// Vader's fused filter + map collected into one array.

import java.util.Arrays;

void main() {
    final int n = 1024;
    int[] a = new int[n];
    for (int i = 0; i < n; i++) a[i] = i;

    long total = 0;
    for (int pass = 0; pass < 40_000; pass++) {
        long[] out = Arrays.stream(a).filter(x -> x % 2 == 1).mapToLong(x -> (long) x * x).toArray();
        total += out.length + out[out.length - 1];
    }
    IO.println("arr_collect %d".formatted(total));
}
