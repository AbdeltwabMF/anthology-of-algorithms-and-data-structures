int leastPrime[N];
int Primes[664580], pnx;

void linear_sieve(int x) { // O(n)
    for (int i = 2; i <= x; ++i) {
        if (leastPrime[i] == 0) {
            leastPrime[i] = Primes[pnx++] = i;
        }
        for (int j = 0, lp = leastPrime[i], comp = 0; j < pnx && Primes[j] <= lp && (comp = i * Primes[j]) <= x; ++j) {
            leastPrime[comp] = Primes[j];
        }
    }
}
