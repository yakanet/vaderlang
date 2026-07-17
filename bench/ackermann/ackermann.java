// Java peer of bench/ackermann.vader. Static recursive method on the primary
// thread (8 MB OS stack), so the ~2 k-deep A(3,9) call stays well clear of
// StackOverflowError.

static final int HI = 9;

static long ackermann(int m, int n) {
    if (m == 0) return (long) n + 1;
    if (n == 0) return ackermann(m - 1, 1);
    return ackermann(m - 1, (int) ackermann(m, n - 1));
}

void main() {
    long total = 0;
    for (int n = 0; n <= HI; n++) total += ackermann(3, n);
    IO.println("ackermann hi=%d total=%d".formatted(HI, total));
}
