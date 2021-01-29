int leastPrime[N];
int Primes[664580], pnx;

void linear_sieve(int x) { // O(n)
    for (int i = 2; i <= x; ++i) {
        if (leastPrime[i] == 0) {
            leastPrime[i] = i;
            Primes[pnx++] = i;
        }
        for (int j = 0; j < pnx && Primes[j] <= leastPrime[i] && i * Primes[j] <= x; ++j) {
            leastPrime[i * Primes[j]] = Primes[j];
        }
    }
}
