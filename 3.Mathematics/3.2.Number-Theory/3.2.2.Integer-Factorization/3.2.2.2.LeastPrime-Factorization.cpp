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

vector<pair<int, int>> Factorization(int n) {  // O(log(n))
    vector<pair<int, int>> ret;
    while (n > 1) {
        int p = leastPrime[n], cnt = 0;
        while (n % p == 0) n /= p, ++cnt;
        ret.emplace_back(p, cnt);
    }
    return ret;
}
