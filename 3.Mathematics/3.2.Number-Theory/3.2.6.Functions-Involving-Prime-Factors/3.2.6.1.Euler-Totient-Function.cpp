/** 
	Constraints:
	1 <= n <= 1e7
	2 <= a <= 10^{14}
    
	Time Complexity:
	linear_sieve takes O(n)
	Phi takes O(n / (ln(n) - 1.08))
	
	Space Complexity:
	O(MaxN + n / (ln(n) - 1.08))
	
	Explanation:
	Phi(n) = n * ((p1 - 1) / p1) * ((p2 - 1) / p2) *...* ((pk - 1) / pk)
	Phi(n) = n * (1 - (1 / p1)) * (1 - (1 / p2)) *...* (1 - (1 / pk))
**/

int lp[N];
int Primes[664580], pnx; /** size of Primes = n / (ln(n) - 1.08) */

void linear_sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = Primes[pnx++] = i;
        }
        for (int j = 0, comp; j < pnx && Primes[j] <= lp[i] && (comp = i * Primes[j]) <= n; ++j) {
            lp[comp] = Primes[j];
        }
    }
}

ll Phi(ll a) { // for Queries
    ll ret = a, p;
    for (int i = 0; i < pnx && (p = Primes[i], true); ++i) {
        if (p * p > a) break;
        if (a % p) continue;
        ret -= ret / p;
        while (a % p == 0) a /= p;
    }
    if (a > 1) ret -= ret / a;
    return ret;
}
