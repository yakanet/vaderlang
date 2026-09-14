// Java peer of bench/closures.vader. Java cannot mutate a captured local, so
// the counter is a one-element array — what Java code writes, and the same
// pointer hop Vader's heap cell costs.

import java.util.function.LongUnaryOperator;

static final int CALLS = 18_000_000;
static final int ADDERS = 500;

static LongUnaryOperator makeAdder(long n) {
    return x -> x + n;
}

void main() {
    long[] counter = { 0 };
    Runnable bump = () -> counter[0] = counter[0] + 1;
    for (int i = 0; i < CALLS; i++) {
        bump.run();
    }

    LongUnaryOperator[] adders = new LongUnaryOperator[ADDERS];
    for (int index = 0; index < ADDERS; index++) {
        adders[index] = makeAdder(index);
    }
    long total = 0;
    for (int pass = 0; pass < CALLS / ADDERS; pass++) {
        for (LongUnaryOperator adder : adders) {
            total = adder.applyAsLong(total);
        }
    }
    IO.println("closures counter=%d total=%d".formatted(counter[0], total));
}
