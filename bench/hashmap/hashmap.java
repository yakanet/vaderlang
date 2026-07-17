// Java peer of bench/hashmap.vader. HashMap<Integer, Integer> driven through
// the same insert / lookup / delete / probe rounds. Integer keys autobox ;
// the map grows from empty — no port pre-sizes, so all four measure the grow
// path the row advertises.

static final int N = 100_000;
static final int ROUNDS = 8;
static final long STRIDE = 131101;
static final long KEYSPACE = 200003;

void main() {
    HashMap<Integer, Integer> m = new HashMap<>();
    long chk = 0;
    for (int r = 0; r < ROUNDS; r++) {
        for (int i = 0; i < N; i++) {
            int k = (int) (((long) i * STRIDE) % KEYSPACE);
            m.put(k, k + r);
        }
        for (int i = 0; i < N; i++) {
            int k = (int) (((long) i * STRIDE) % KEYSPACE);
            Integer v = m.get(k);
            if (v != null) chk += v;
        }
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                int k = (int) (((long) i * STRIDE) % KEYSPACE);
                m.remove(k);
            }
        }
        for (int i = 0; i < N; i++) {
            int k = (int) (((long) i * STRIDE) % KEYSPACE);
            if (m.containsKey(k)) chk += 1;
        }
    }
    IO.println("hashmap rounds=%d n=%d size=%d chk=%d".formatted(ROUNDS, N, m.size(), chk));
}
