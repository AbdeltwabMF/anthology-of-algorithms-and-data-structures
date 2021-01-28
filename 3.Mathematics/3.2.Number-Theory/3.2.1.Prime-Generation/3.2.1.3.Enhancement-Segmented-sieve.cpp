const int L1D_CACHE_SIZE = 32768;
vector<int> Primes;

void segmented_sieve(ll limit) {
    int sqrt = sqrtl(limit);
    int segment_size = max(L1D_CACHE_SIZE, sqrt);

    int basis[3] = {2, 3, 5};
    int wheel[8] = {7, 11, 13, 17, 19, 23, 29, 1};
    int inc[8] = {4, 2, 4, 2, 4, 6, 2, 6};
    int inx[31];

    bool sieve[segment_size];
    bool isPrime[sqrt + 1];

    vector<int> primes;
    vector<ll> multiples;

    memset(inx, 0, sizeof(inx));
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 0; i < 8; ++i) {
        inx[wheel[i]] = i;
    }

    for (int prime : basis) {
        Primes.emplace_back(prime);
    }

    ll i = 7, n = 7, s = 7;
    int d = 0, k = 0, g = 0;

    for (ll low = 0; low <= limit; low += segment_size) {
        memset(sieve, true, sizeof(sieve));
        ll high = min(low + segment_size - 1, limit);

        for (; i * i <= high; i += inc[k++]) {
            if (isPrime[i]) {
                int f = inx[i % 30];
                for (ll j = i * i; j <= sqrt; j += inc[f++] * i) {
                    isPrime[j] = false;
                    if (f == 8) f = 0;
                }
            }
            if (k == 8) k = 0;
        }

        for (; s * s <= high; s += inc[g++]) {
            if (isPrime[s]) {
                primes.push_back(s);
                multiples.push_back(s * s - low);
            }
            if (g == 8) g = 0;
        }

        for (size_t i = 0; i < primes.size(); ++i) {
            ll j = multiples[i];
            for (ll k = primes[i] * 2ll; j < segment_size; j += k)
                sieve[j] = false;
            multiples[i] = j - segment_size;
        }

        for (; n <= high; n += inc[d++]) {
            if (sieve[n - low])
                Primes.push_back(n);
            if (d == 8) d = 0;
        }
    }
}

