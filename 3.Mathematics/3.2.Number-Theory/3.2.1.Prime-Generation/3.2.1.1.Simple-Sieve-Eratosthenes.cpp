/**
	constraints:
	
	1 <= n <= 1e8
	Time complexity of this approach is : n lnln √n + O(n)
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
