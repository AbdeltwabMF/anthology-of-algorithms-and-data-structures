/**
	constraints:
	
	1 <= n <= 1e9
	Used: 3150 ms, 517536 KB
**/

bitset<N> isPrime;
int32_t inx[30100];
vector<int> Primes;

vector<int> coPrimes(int n) {
    int basis[5] = {3, 5, 7, 11, 13};

    vector<int> ret;
    bitset<30100> isCoprime;
    isCoprime.set();

    for (int b : basis)
        for (int d = b * b; d <= n; d += b << 1)
            isCoprime.reset(d);

    for (int i = 17; i <= n; i += 2)
        if (isCoprime[i]) ret.push_back(i);

    ret.push_back(n + 1);
    ret.push_back(n + 17);

    return ret;
}

void wheel_sieve(int n) {
    int basis[6] = {2, 3, 5, 7, 11, 13};
    vector<int> wheel = coPrimes(2 * 3 * 5 * 7 * 11 * 13);
    int sz = wheel.size();

    for (int k = 0; k < sz; ++k)
        inx[wheel[k]] = k;

    isPrime.set();
    inx[1] = sz - 2;
    int inc[sz - 1];

    for (int i = 1; i < sz; ++i)
        inc[i - 1] = wheel[i] - wheel[i - 1];

    for (int prime : basis) {
        if (n >= prime)
            Primes.emplace_back(prime);
    }

    int c = 0;
    for (ll i = 17; i <= n; i += inc[c++]) {
        if (isPrime[i]) {
            Primes.emplace_back(i);
            int d = inx[i % 30030];
            for (ll j = i * i; j <= n; j += i * inc[d++]) {
                isPrime.reset(j);
                if (d == sz - 1) d = 0;
            }
        }
        if (c == sz - 1) c = 0;
    }
}
