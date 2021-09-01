/*
  Constraints:
  1 <= n <= 1e7
	
  Time Complexity:
  linear_sieve takes O(n)
  Factorization takes O(log(n))
	
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

vector<pair<int, int>> Factorization(int n) {
  vector<pair<int, int>> ret;
  while (n > 1) {
    int p = leastPrime[n], cnt = 0;
    while (n % p == 0) n /= p, ++cnt;
    ret.emplace_back(p, cnt);
  }
  return ret;
}
