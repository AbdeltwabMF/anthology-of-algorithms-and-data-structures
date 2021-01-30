/**
	constraints:
	1 <= l, r <= 1e{14}
	1 <= r - l + 1 <= 1e7
	2 <= x <= 1e7
	
	Time complexity:
	segmented_sieve takes O((r − l + 1) * ln(ln(r)))
	sieve takes O( + √r * ln(ln(r^{1/4})))
	
	Space Complexity:
	O(MaxN + n / (ln(n) - 1.08))
**/

bool isPrime[N];
int Primes[664580], pnx; /** size of Primes = n / (ln(n) - 1.08) */

void sieve(int x) {
    int basis[3] = {2, 3, 5};
    int wheel[8] = {7, 11, 13, 17, 19, 23, 29, 1};
    int inc[8] = {4, 2, 4, 2, 4, 6, 2, 6};
    int inx[31];

    memset(inx, 0, sizeof(inx));
    memset(isPrime, true, sizeof(isPrime));

    for (int p : basis) if (x > p) Primes[pnx++] = p;
    for (int i = 0; i < 8; ++i) inx[wheel[i]] = i;

    int c = 0;
    for (int i = 7; i <= x; i += inc[c++]) {
        if (isPrime[i]) {
            Primes[pnx++] = i;
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

    for (int p : Primes) {
        for (ll j = max(p * 1ll * p, (l + p - 1) * 1ll / p * p); j <= r; j += p)
            isPrime[j - l] = false;
    }

    for (int i = 0; i < limit; ++i)
        if (isPrime[i])
            ret.emplace_back(i + l);
    return ret;
}
