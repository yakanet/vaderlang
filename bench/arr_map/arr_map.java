// Java peer of bench/arr_map.vader. Uses the Stream API — a fresh
// Arrays.stream(a).mapToLong(f).sum() per pass — mirroring Vader's
// `a.map(square)` iterator (lazy, one element at a time through the pipeline),
// the same way bench/iter_chain.java mirrors the range→filter→map chain.

import java.util.Arrays;

void main() {
    final int n = 1024;
    int[] a = new int[n];
    for (int i = 0; i < n; i++) a[i] = i;

    long sum = 0;
    for (int pass = 0; pass < 300_000; pass++) {
        sum += Arrays.stream(a).mapToLong(x -> (long) x * x).sum();
    }
    IO.println("arr_map %d".formatted(sum));
}
