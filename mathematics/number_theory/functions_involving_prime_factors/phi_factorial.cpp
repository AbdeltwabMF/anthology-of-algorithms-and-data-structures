/** 
    Constraints:
    1 <= x <= 1e7
    2 <= n <= 1e7
    
    Time Complexity:
    linear_sieve takes O(x)
    phi_factorial takes O(n)
	
    Space Complexity:
    O(MaxN + n / (ln(n) - 1.08))
*/

int lp[N], Primes[664580], pnx; /** number of primes = n / (ln(n) - 1.08) **/

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

ll phi_factorial(int n) {
  ll ret = 1;
  for (int i = 2; i <= n; ++i) {
    ret = ret * (lp[i] == i ? i - 1 : i);
  }
  return ret;
}

