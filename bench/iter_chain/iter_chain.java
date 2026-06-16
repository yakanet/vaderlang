// Java peer of bench/iter_chain.vader. Uses the Stream API — lazy by
// default, dispatches one element at a time through the pipeline,
// mirroring Vader's MapIterator + FilterIterator chain.

import java.util.stream.IntStream;

public class iter_chain {
    static final int N = 1_000_000;

    public static void main(String[] args) {
        long total = IntStream.range(0, N)
            .filter(x -> x % 2 == 0)
            .mapToLong(x -> (long) x * (long) x)
            .sum();
        System.out.printf("iter_chain N=%d total=%d%n", N, total);
    }
}
