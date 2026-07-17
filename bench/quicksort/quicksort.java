// Java peer of bench/quicksort.vader. Same median-of-three Lomuto quicksort
// over an int[], tail-recursion eliminated on the larger side.

static final int N = 1_000_000;
static final long STRIDE = 999983;
static final long N_MOD = 1_000_000;

static void qsort(int[] a, int lo, int hi) {
    int l = lo, h = hi;
    while (h - l > 1) {
        int mid = l + (h - l) / 2;
        int hh = h - 1;
        if (a[l] > a[mid]) { int t = a[l]; a[l] = a[mid]; a[mid] = t; }
        if (a[l] > a[hh]) { int t = a[l]; a[l] = a[hh]; a[hh] = t; }
        if (a[mid] < a[hh]) { int t = a[mid]; a[mid] = a[hh]; a[hh] = t; }
        int pivot = a[hh];
        int i = l;
        for (int j = l; j < hh; j++) {
            if (a[j] < pivot) { int t = a[i]; a[i] = a[j]; a[j] = t; i++; }
        }
        { int t = a[i]; a[i] = a[hh]; a[hh] = t; }
        if (i - l < h - (i + 1)) { qsort(a, l, i); l = i + 1; }
        else { qsort(a, i + 1, h); h = i; }
    }
}

void main() {
    int[] a = new int[N];
    for (int i = 0; i < N; i++) a[i] = (int) (((long) i * STRIDE) % N_MOD);
    qsort(a, 0, N);
    long chk = 0;
    for (int i = 0; i < N; i++) chk = (chk * 31 + a[i]) % 2147483648L;
    IO.println("quicksort n=%d chk=%d".formatted(N, chk));
}
