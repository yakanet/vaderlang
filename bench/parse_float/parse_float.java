// Java peer of bench/parse_float.vader. `Double.parseDouble` is correctly
// rounded, and `doubleToLongBits` gives the pattern the checksum sums.

static final int INPUT_COUNT = 4096;
static final int PASS_COUNT = 160;

static final String[] FRACTIONS = { "5", "25", "125", "0625", "1", "7", "142857", "33333333" };
static final String[] EXPONENTS = { "", "e3", "e-3", "e17", "e-17" };

static String[] buildInputs() {
    String[] out = new String[INPUT_COUNT];
    for (int index = 0; index < INPUT_COUNT; index++) {
        long mantissa = (long) index * 1103515245L % 1000003L;
        out[index] = mantissa + "." + FRACTIONS[index % 8] + EXPONENTS[index % 5];
    }
    return out;
}

void main() {
    String[] inputs = buildInputs();
    long high = 0, low = 0;
    for (int pass = 0; pass < PASS_COUNT; pass++) {
        for (String text : inputs) {
            double parsed = Double.parseDouble(text);
            long bits = Double.doubleToLongBits(parsed);
            high += bits >>> 32;
            low += bits & 0xFFFFFFFFL;
        }
    }
    IO.println("parse_float inputs=%d passes=%d high=%d low=%d"
        .formatted(INPUT_COUNT, PASS_COUNT, high, low));
}
