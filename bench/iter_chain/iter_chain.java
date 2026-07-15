// Java peer of bench/iter_chain.vader. Uses the Stream API — lazy by
// default, dispatches one element at a time through the pipeline,
// mirroring Vader's MapIterator + FilterIterator chain.

static final int N = 1_000_000;

void main() {
    long total = IntStream.range(0, N)
        .filter(x -> x % 2 == 0)
        .mapToLong(x -> (long) x * (long) x)
        .sum();
    IO.println("iter_chain N=%d total=%d".formatted(N, total));
}
