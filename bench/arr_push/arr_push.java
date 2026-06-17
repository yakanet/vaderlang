// Java peer of bench/arr_push/arr_push.vader. Same algorithm (build then
// discard a fresh i32 array via push, 200 × 100 000 = 20 M pushes), same
// checksum. Vader's `i32[]` push is a typed store + amortised-doubling grow ;
// the faithful Java analog is a manual growable int[] (an ArrayList<Integer>
// would box every element, a different cost profile), so we open-code the
// doubling here.

public class arr_push {
    public static void main(String[] args) {
        long total = 0;
        for (int pass = 0; pass < 200; pass++) {
            int[] a = new int[0];
            int len = 0;
            for (int i = 0; i < 100_000; i++) {
                if (len == a.length) {
                    int cap = a.length == 0 ? 1 : a.length * 2;
                    int[] grown = new int[cap];
                    System.arraycopy(a, 0, grown, 0, len);
                    a = grown;
                }
                a[len++] = i;
            }
            total += len;
        }
        System.out.printf("arr_push %d%n", total);
    }
}
