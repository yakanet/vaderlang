// Java peer of bench/sort_by.vader. A comparator sort needs boxed elements —
// `Arrays.sort(long[])` takes no comparator — so `Long[]` is what Java code
// writes here, and the boxing is part of what the row compares. TimSort is
// stable, which the checksum depends on.

import java.util.Arrays;
import java.util.Comparator;

static final int ITEM_COUNT = 20_000;
static final int PASS_COUNT = 24;
static final long STRIDE = 1103515245L;

static Long[] buildItems() {
    Long[] out = new Long[ITEM_COUNT];
    for (int index = 0; index < ITEM_COUNT; index++) {
        out[index] = (long) index * STRIDE % 1000003L;
    }
    return out;
}

void main() {
    long checksum = 0;
    for (int pass = 0; pass < PASS_COUNT; pass++) {
        Long[] items = buildItems();
        Arrays.sort(items, Comparator.comparingLong(v -> v % 1000));
        for (int index = 0; index < items.length; index++) {
            checksum += (long) (index + 1) * (items[index] % 97);
        }
    }
    IO.println("sort_by items=%d passes=%d checksum=%d".formatted(ITEM_COUNT, PASS_COUNT, checksum));
}
