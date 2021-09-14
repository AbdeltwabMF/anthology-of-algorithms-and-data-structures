/** 
    Constraints:
    1 <= x <= 1e7
    2 <= n <= 10^{14}
    
    Time Complexity:
    linear_sieve takes O(x)
    mobius takes O(n / (ln(n) - 1.08))
	
    Space Complexity:
    O(MaxN + n / (ln(n) - 1.08))
*/

int lp[N], Primes[664580], pnx; /** size of Primes = n / (ln(n) - 1.08) */

void linear_sieve(int x) {
  for (int i = 2; i <= x; ++i) {
    if (lp[i] == 0) {
      lp[i] = Primes[pnx++] = i;
    }

    for (int j = 0, comp; j < pnx && Primes[j] <= lp[i] && (comp = i * Primes[j]) <= x; ++j) {
      lp[comp] = Primes[j];
    }
  }
}

int mobius(ll n) {
  ll p, pp;
  char mob = 1;
  for (int i = 0; i < pnx && (p = Primes[i], pp = p * p, true); ++i) {
    if (pp > n) break;
    if (n % p) continue;
    if (n % pp == 0) return 0;
    n /= p;
    mob = -mob;
  }
  if (n > 1) mob = -mob;
  return mob;
}
