/** 
    Constraints:
    1 <= n <= 1e9
    2 <= x <= 9700000
    
    Time Complexity:
    wheel_sieve takes O(n / ln(ln(n)))
    coPrimes takes O(x * ln(ln(x)))
	
    Space Complexity:
    O(MaxN / 32 + n / (ln(n) - 1.08) + x)
**/

bitset<N> isPrime;
int inx[30100];
int Primes[50908031], pnx; /** size of Primes = n / (ln(n) - 1.08) */

vector<int> coPrimes(int x) {
  int basis[5] = {3, 5, 7, 11, 13};

  vector<int> ret;
  bitset<30100> isCoprime;
  isCoprime.set();

  for (int b : basis)
    for (int d = b * b; d <= x; d += b << 1)
      isCoprime.reset(d);

  for (int i = 17; i <= x; i += 2)
    if (isCoprime[i]) ret.push_back(i);

  ret.push_back(x + 1);
  ret.push_back(x + 17);
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

  for (int p : basis) {
    if (n >= p)
      Primes[pnx++] = p;
  }

  int c = 0;
  for (ll i = 17; i <= n; i += inc[c++]) {
    if (isPrime[i]) {
      Primes[pnx++] = i;
      int d = inx[i % 30030];
      for (ll j = i * i; j <= n; j += i * inc[d++]) {
	isPrime.reset(j);
	if (d == sz - 1) d = 0;
      }
    }
    if (c == sz - 1) c = 0;
  }
}
