/**
	constraints:
	
	1 <= l, r <= 1e{14}
	1 <= r - l + 1 <= 1e7
	Time complexity of this approach is : O((r − l + 1)lnln(r) + √r lnln r^{1/4})
**/

bool isPrime[N];
vector<int> Primes;

void sieve(int x) {
    int basis[3] = {2, 3, 5};
    int wheel[8] = {7, 11, 13, 17, 19, 23, 29, 1};
    int inc[8] = {4, 2, 4, 2, 4, 6, 2, 6};
    int inx[31];

    memset(inx, 0, sizeof(inx));
    memset(isPrime, true, sizeof(isPrime));

    for (int prime : basis) {
        if (x > prime)
            Primes.emplace_back(prime);
    }

    for (int i = 0; i < 8; ++i) {
        inx[wheel[i]] = i;
    }

    int c = 0;
    for (int i = 7; i <= x; i += inc[c++]) {
        if (isPrime[i]) {
            Primes.emplace_back(i);
            int d = inx[i % 30];
            for (ll j = i * 1ll * i; j <= x; j += i * inc[d++]) {
                isPrime[j] = false;
                if (d == 8) d = 0;
            }
        }
        if (c == 8) c = 0;
    }
}

vector<ll> segmented_sieve(ll l, ll r) {
    l += l == 1;
    int limit = r - l + 1;
    vector<ll> ret;
    memset(isPrime, true, sizeof(isPrime));

    for (int prime : Primes) {
        for (ll j = max(prime * 1ll * prime, (l + prime - 1) * 1ll / prime * prime); j <= r; j += prime)
            isPrime[j - l] = false;
    }

    for (int i = 0; i < limit; ++i)
        if (isPrime[i])
            ret.emplace_back(i + l);
    return ret;
}
