// Java peer of bench/matmul.vader. A long[][] is an array of row objects, the
// same indirection Vader and Go both pay, and the row is hoisted alike.

static final int SIZE = 260;

static long[][] build(long modulus) {
    long[][] out = new long[SIZE][SIZE];
    for (int row = 0; row < SIZE; row++) {
        for (int column = 0; column < SIZE; column++) {
            out[row][column] = (row + column) % modulus;
        }
    }
    return out;
}

void main() {
    long[][] left = build(7);
    long[][] right = build(5);
    long total = 0;
    for (int row = 0; row < SIZE; row++) {
        long[] leftRow = left[row];
        for (int column = 0; column < SIZE; column++) {
            long cell = 0;
            for (int k = 0; k < SIZE; k++) {
                cell += leftRow[k] * right[k][column];
            }
            total += cell;
        }
    }
    IO.println("matmul size=%d total=%d".formatted(SIZE, total));
}
