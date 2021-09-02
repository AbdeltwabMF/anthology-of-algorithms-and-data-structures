/*
  Constraints:
  1 <= n <= 1e7
  2 <= a <= 1e{14}
	
  Time Complexity:
  linear_sieve takes O(n)
  Factorization takes O(n / (ln(n) - 1.08))
	
  Space Complexity:
  O(MaxN + n / (ln(n) - 1.08)
*/

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

vector<pair<ll, int>> Factorization(ll a) {
  vector<pair<ll, int> > ret;
  ll p;
  for (int i = 0, cnt; i < pnx && (p = Primes[i], true) && p * p <= a; ++i) {
    if (a % p) continue;
    cnt = 0;
    while (a % p == 0) a /= p, ++cnt;
    ret.emplace_back(p, cnt);
  }
  if (a > 1) ret.emplace_back(a, 1);
  return ret;
}
