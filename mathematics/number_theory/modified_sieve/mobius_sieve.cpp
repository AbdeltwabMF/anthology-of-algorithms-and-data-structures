/*
  Constraints:
  1 <= n <= 1e7
	
  Time Complexity:
  mu_sieve takes O(n)
	
  Space Complexity:
  O(MaxN)
*/

int mu[N], lp[N], Primes[78522], pnx;

void mu_sieve(int n) {
  mu[1] = 1;
  fill(mu, mu + N, 1);
  for (int i = 2; i <= n; ++i) {
    if (lp[i] == 0) {
      lp[i] = Primes[pnx++] = i;
      mu[i] = -1;
    }
    for (int j = 0, nxt; j < pnx && Primes[j] <= lp[i] && (nxt = i * Primes[j]) <= n; ++j) {
      lp[nxt] = Primes[j];
      mu[nxt] = (lp[i] == Primes[j] ? 0 : -mu[i]);
    }
  }
}
