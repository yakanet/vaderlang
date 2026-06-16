// Java peer of bench/primes.vader. Same algorithm (trial division), same
// N, same checksum.

public class primes {
    static final int N = 1_000_000;

    static boolean isPrime(int n) {
        if (n < 2) return false;
        if (n < 4) return true;
        if (n % 2 == 0) return false;
        for (int d = 3; (long) d * d <= n; d += 2) {
            if (n % d == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        long count = 0;
        long sum = 0;
        for (int n = 2; n <= N; n++) {
            if (isPrime(n)) {
                count++;
                sum += n;
            }
        }
        System.out.printf("primes N=%d count=%d sum=%d%n", N, count, sum);
    }
}
