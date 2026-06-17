// Java peer of bench/map_iter.vader. HashMap<Integer, Integer>
// iterated via entrySet() — the canonical entry iteration shape.

import java.util.HashMap;
import java.util.Map;

public class map_iter {
    static final int INNER_KEYS = 1_000;
    static final int OUTER_LOOPS = 1_000;

    public static void main(String[] args) {
        HashMap<Integer, Integer> m = new HashMap<>(INNER_KEYS);
        for (int i = 0; i < INNER_KEYS; i++) m.put(i, i);
        long total = 0;
        for (int outer = 0; outer < OUTER_LOOPS; outer++) {
            for (Map.Entry<Integer, Integer> e : m.entrySet()) {
                total += (long) e.getValue();
            }
        }
        System.out.printf("map_iter inner=%d outer=%d total=%d%n", INNER_KEYS, OUTER_LOOPS, total);
    }
}
