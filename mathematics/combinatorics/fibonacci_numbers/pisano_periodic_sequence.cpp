/** Algorithm 1: **/

/** Constraints :
    1 ⩽ n ⩽ CR
    Where CR stands for your computing resources. In my case,
    CR ≈ 100,000,000
    ----------------
    The algorithm is constructed around the ideas that a Pisano sequence always starts with 0 and 1, and that this sequence of Fibonacci
    numbers taken modulo n can be constructed for each number by adding the previous remainders and taking into account the modulo n.
    ----------------

    definition:
    The sequence of Fibonacci numbers {F_n} is periodic modulo any modulus m (Wall 1960), and the period (mod m)
    is the known as the Pisano period pi(m) (Wrench 1969). For m=1, 2, ..., the values of pi(m) are
    1, 3, 8, 6, 20, 24, 16, 12, 24, 60, 10, ... (OEIS A001175).

    Since pi(10)=60, the last digit of F_n repeats with period 60, as first noted by Lagrange in 1774 (Livio 2002, p. 105).
    The last two digits repeat with a period of 300, and the last three with a period of 1500.
    In 1963, Geller found that the last four digits have a period of 15000 and the last five a period of 150000.
    Jarden subsequently showed that for d>=3, the last d digits have a period of 15·10^(d-1) (Livio 2002, pp. 105-106).
    The sequence of Pisano periods for n=1, 10, 100, 1000, ... are therefore 60, 300, 1500, 15000, 150000, 1500000, ... (OEIS A096363).
    pi(m) is even if m>2 (Wall 1960). pi(m)=m iff m=24·5^(k-1) for some integer k>1 (Fulton and Morris 1969, Wrench 1969).

    resources :
    1. https://webbox.lafayette.edu/~reiterc/nt/qr_fib_ec_preprint.pdf
    2. https://www.youtube.com/watch?v=Nu-lW-Ifyec&ab_channel=Numberphile
    4. http://webspace.ship.edu/msrenault/fibonacci/fib.htm
    5. https://www.theoremoftheday.org/Binomial/PeriodicFib/TotDPeriodic.pdf
    7. http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibmaths.html#fibmod
    8. http://webspace.ship.edu/msrenault/fibonacci/FibThesis.pdf
    9. https://www.fq.math.ca/Scanned/1-2/vinson.pdf
**/

vector <int> pisano_periodic_sequence(int n) {
  vector <int> period;

  int current = 0, next = 1;
  period.push_back(current);

  if(n < 2) return period;
  current = (next += current) - current;

  while(current != 0 || next != 1) {
    period.push_back(current);
    current = current + next >= n ? (next += current - n) + (n - current) : (next += current) - current;
  }
  return period;
}

/** ************************************************************************************** **/
/** Algorithm 2: **/

/**	constraints:
	1 <= n <= 10^{18}
	--------------
	problem statement (https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4479):
	For any integer n, the sequence of Fibonacci numbers F_i taken mod n is periodic.
	define K(n) = the length of the period of the Fibonacci sequence reduced mod n.
	The task is to print the length of the period of this sequence K(n).
	--------------
	Definition:
	The Pisano period  π(n)  is a multiplicative function, that is if  a  and  b  are coprime than  π(ab) = π(a) * π(b).
	So we need only concern ourselves with the value of  π(p^k) for prime  p.
	(Factoring even a large number is still better than brute force periodicity search.)

	It is hypothesized that  π(p^k) = p^{k − 1} * π(p) and since no counterexamples are known to exist,
	you might as well use that in your algorithm.

	So, how to calculate  π(p)  efficiently? There are two special cases and two general cases

	π(2^k) = 3⋅2^{k − 1}
	π(5^k) = 4⋅5^k

	If  p ≡ 1  or  p ≡ 9 (mod10)  then  π(p) ∣ p − 1
	If  p ≡ 3  or  p ≡ 7 (mod10)  then  π(p) ∣ 2 * (p + 1) , and by an odd divisor too.

	The last two statements give us a relatively small number of cases to try (after factoring  p − 1  or  2*(p + 1) .)
	Now use your favorite formula to calculate large values of the Fibonacci numbers  F(x) (mod p).
	[See Michal Forišek's answer to What's a fast algorithm to find the remainder of the division of a huge Fibonacci number by some big integer?](https://www.quora.com/Whats-a-fast-algorithm-to-find-the-remainder-of-the-division-of-a-huge-Fibonacci-number-by-some-big-integer/answer/Michal-Fori%C5%A1ek) .
	To test a candidate period  R , calculate  F(R) (mod p)  and  F(R + 1) (mod p).
	If these are equal to  F(0) = 0  and  F(1) = 1 , then  π(p) ∣ R.

	It might be that  p − 1  or  2*(p + 1)  have a lot of divisors, but we don’t need to try them all.
	Suppose  q^k ∣ R  for some prime q.
	Then test  R/q . If that doesn’t produce a cycle, then  π(p)  must have factor  q^k ,
	and we can leave it in and go on to other factors.
	Otherwise, we can use  R/q  as our new starting point and repeat the process.
	Thus we have to do a number of checks proportional to  Ω(2*(p + 1)) , not  d(2*(p + 1)).

	------------
	Donald Wall proved several other properties, some of which you may find interesting:
	• If m > 2, k(m) is even.
	• For any even integer n > 2, there exists m such that k(m) = n.
	• k(m) ≤ (m^2) − 1
	• k(2^n) = 3 ∗ 2^{n − 1}
	• k(5^n) = 4 ∗ 5^n
	• If n > 2, k(10^n) = 15 ∗ 10^{n − 1}
	• k(2 ∗ 5^n) = 6n
**/

#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'

using namespace std;

typedef long long     ll;
typedef __int128    i128;
typedef __int128_t ui128;

template <class T>
using matrix = vector < vector <T> >;

template <class T> string to_string(T x) {
  int sn = 1;
  if(x < 0) sn = -1, x *= sn;
  string s = "";
  do {
    s = "0123456789"[x % 10] + s, x /= 10;
  } while(x);
  return (sn == -1 ? "-" : "") + s;
}

auto str_to_int(string x) {
  ui128 ret = (x[0] == '-' ? 0 : x[0] - '0');
  for(int i = 1; i < (int)x.size(); ++i) ret = ret * 10 + (x[i] - '0');
  return (x[0] == '-' ? -1 * (i128)ret : ret);
}

istream & operator >> (istream & in, i128 & i) noexcept {
  string s;
  in >> s;
  i = str_to_int(s);
  return in;
}

ostream & operator << (ostream & os, const i128 i) noexcept {
  os << to_string(i);
  return os;
}

void Fast() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

ll n;
vector <int> primes;
matrix <ll> fibMatrix = {{1, 1},
			 {1, 0}
};

i128 gcd(i128 a, i128 b) {
  while (a && b)
    a > b ? a %= b : b %= a;
  return a + b;
}

i128 lcm(i128 a, i128 b) {
  return a / gcd(a, b) * b;
}

vector < array <ll, 2> > factorize(ll x) {
  vector < array <ll, 2> > ret;
  for(int i = 0; 1ll * primes[i] * primes[i] <= x; ++i) {
    if(x % primes[i]) continue;

    int cnt = 0;
    while (x % primes[i] == 0) {
      cnt++;
      x /= primes[i];
    }
    ret.push_back({primes[i], cnt});
  }

  if(x > 1) ret.push_back({x, 1});
  return ret;
}

matrix <ll> MatMul(matrix <ll> A, matrix <ll> B, ll mod) {
  int ra = A.size(), cb = B[0].size(), ca = A[0].size();
  matrix <i128> C(ra, vector <i128> (cb));

  for(int i = 0; i < ra; ++i)
    for (int j = 0; j < cb; ++j) {
      C[i][j] = 0;
      for(int k = 0; k < ca; ++k)
	C[i][j] = (C[i][j] + (i128)A[i][k] * B[k][j]);
    }

  matrix <ll> ret(ra, vector <ll> (cb));
  for(int i = 0; i < ra; ++i)
    for (int j = 0; j < cb; ++j)
      ret[i][j] = C[i][j] % mod;

  return ret;
}

matrix <ll> MatPow(matrix <ll> A, ll p, ll mod) {
  int r = A.size(), c = A[0].size();
  assert(r == c && p);
  matrix <ll> result = A;
  p--;

  while(p) {
    if(p & 1ll) result = MatMul(result, A, mod);
    A = MatMul(A, A, mod);
    p >>= 1ll;
  }
  return result;
}

i128 ModExp(i128 a, ll p) {
  i128 result = 1;
  while(p) {
    if(p & 1ll) result = result * a;
    a *= a;
    p >>= 1ll;
  }
  return result;
}

ll nthFib(ll n, ll mod) {
  return MatPow(fibMatrix, n, mod)[0][1];
}

bool is_period(ll n, ll mod) {
  return nthFib(n, mod) == 0 && nthFib(n + 1, mod) == 1;
}

ll solver(ll x, ll mod) {
  vector < array <ll, 2> > factors = factorize(x);
  for(int i = 0; i < (int)factors.size(); ++i) {
    while(x % factors[i][0] == 0 && is_period(x / factors[i][0], mod))
      x /= factors[i][0];
  }
  return x;
}

ll pisano_prime(ll val) {
  if(val == 2) return 3;
  if(val == 5) return 20;
  if(val % 10 == 1 || val % 10 == 9)
    return solver(val - 1, val);

  return solver(2 * (val + 1), val);
}

const int N = 1e7 + 9;
bitset <N> isPrime;

void Precomputation_Sieve() {
  isPrime.set();
  int _sqrt = sqrtl(N);

  for(int i = 5; i <= _sqrt; i += 6) {
    if(isPrime[i]) for (int j = i * i; j < N; j += i + i) isPrime.reset(j);
    i += 2;
    if(isPrime[i]) for (int j = i * i; j < N; j += i + i) isPrime.reset(j);
    i -= 2;
  }
}

vector <int> Primes(int n) {
  vector <int> _Primes;

  if(n >= 2) _Primes.push_back(2);
  if(n >= 3) _Primes.push_back(3);

  for (int i = 5; i <= n; i += 6) {
    if(isPrime[i]) _Primes.push_back(i);
    i += 2;
    if(isPrime[i]) _Primes.push_back(i);
    i -= 2;
  }
  return _Primes;
}

void initialize()
{
  Precomputation_Sieve();
  primes = Primes(N);
}

void Solve() {
  initialize();
  cin >> n;
  vector < array <ll, 2> > factors = factorize(n);

  i128 ans = 1;
  for (int i = 0; i < (int)factors.size(); ++i) {
    ans = lcm(ans, (i128)pisano_prime(factors[i][0]) * ModExp(factors[i][0], factors[i][1] - 1));
  }
  cout << ans << endl;
}
