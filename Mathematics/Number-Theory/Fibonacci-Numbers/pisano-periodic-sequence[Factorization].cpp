/**	constraints:
	1 ⩽ n ⩽ 10^{18}
	--------------
	problem statement:
	For any integer n, the sequence of Fibonacci numbers F_i taken mod n is periodic.
	define K(n) = the length of the period of the Fibonacci sequence reduced mod n.
	The task is to print the length of the period of this sequence K(n).
**/

#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'

using namespace std;

typedef long long     ll;
typedef __int128    i128;
typedef __int128_t ui128;

template <class T> string to_string(T x)
{
    int sn = 1; if(x < 0) sn = -1, x *= sn; string s = "";
    do { s = "0123456789"[x % 10] + s, x /= 10; } while(x);
    return (sn == -1 ? "-" : "") + s;
}

auto str_to_int(string x)
{
    ui128 ret = (x[0] == '-' ? 0 : x[0] - '0');
    for(int i = 1; i < (int)x.size(); ++i) ret = ret * 10 + (x[i] - '0');
    return (x[0] == '-' ? -1 * (i128)ret : ret);
}

istream & operator >> (istream & in, i128 & i) noexcept { string s; in >> s; i = str_to_int(s); return in; }
ostream & operator << (ostream & os, const i128 i) noexcept { os << to_string(i); return os; }

void Fast()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

ll n;
i128 temp[2][2];
vector <int> primes;
vector < vector <ll> > fib_matrix(2);

i128 gcd(i128 a, i128 b)
{
    while (a && b)
        a > b ? a %= b : b %= a;
    return a + b;
}

i128 lcm(i128 a, i128 b)
{
    return a / gcd(a, b) * b;
}

vector < pair <ll, ll> > fact(ll x)
{
    vector < pair <ll, ll> > ret;
    for(int i = 0; 1ll * primes[i] * primes[i] <= x; ++i)
    {
        if(x % primes[i]) continue;

        int cnt = 0;
        while (x % primes[i] == 0)
        {
            cnt++;
            x /= primes[i];
        }
        ret.push_back({primes[i], cnt});
    }

    if(x > 1) ret.push_back({x, 1});
    return ret;
}

vector < vector <ll> > mult(vector <vector <ll> > a, vector < vector <ll> > b, ll mod)
{
    vector < vector < ll> > ret = a;

    for(int i = 0; i <= 1; i++)
        for(int j = 0; j <= 1; j++)
            temp[i][j] = 0;

    for(int k = 0; k <= 1; k++)
        for(int i = 0; i <= 1; i++)
            for(int j = 0; j <= 1; j++)
                temp[i][j] = (temp[i][j] + (i128) a[i][k] * b[k][j]);

    for(int i = 0; i <= 1; i++)
        for(int j = 0; j <= 1; j++)
            ret[i][j] = temp[i][j] % mod;

    return ret;
}

vector < vector <ll> > pw(vector < vector <ll> > a, ll b, ll mod)
{
    if(b == 1) return a;
    if(b % 2) return mult(a, pw(a, b - 1, mod), mod);
    return pw(mult(a, a, mod), b / 2, mod);
}

ll get_fib(ll ps, ll mod)
{
    vector < vector <ll> > V = pw(fib_matrix, ps, mod);
    return V[0][1];
}

bool is_period(ll ps, ll mod)
{
    return get_fib(ps, mod) == 0 && get_fib(ps + 1, mod) == 1;
}

ll solver(ll x, ll mod)
{
    vector < pair <ll, ll> > factorization = fact(x);
    for(int i = 0; i < (int)factorization.size(); i++)
    {
        while(x % factorization[i].first == 0 && is_period(x / factorization[i].first, mod))
            x /= factorization[i].first;
    }
    return x;
}

ll pisano_prime(ll val)
{
    if(val == 2) return 3;
    if(val == 5) return 20;
    if(val % 10 == 1 || val % 10 == 9)
        return solver(val - 1, val);

    return solver(2 * (val + 1), val);
}

const int N = 1e6 + 9;
bitset <N> isPrime;

void Precomputation_Sieve()
{
    isPrime.set();
    int _sqrt = sqrtl(N);

    for(int i = 5; i <= _sqrt; i += 6)
    {
        if(isPrime[i]) for (int j = i * i; j < N; j += i + i) isPrime.reset(j); i += 2;
        if(isPrime[i]) for (int j = i * i; j < N; j += i + i) isPrime.reset(j); i -= 2;
    }
}

vector <int> Primes(int n)
{
    vector <int> _Primes;

    if(n >= 2) _Primes.push_back(2);
    if(n >= 3) _Primes.push_back(3);

    for (int i = 5; i <= n; i += 6)
    {
        if(isPrime[i]) _Primes.push_back(i); i += 2;
        if(isPrime[i]) _Primes.push_back(i); i -= 2;
    }
    return _Primes;
}

void initialize()
{
    fib_matrix = {{1, 1}, {1, 0}};
    Precomputation_Sieve();
    primes = Primes(N);
}

void Solve()
{
    cin >> n;
    vector < pair <ll, ll> > factorization = fact(n);

    i128 ans = 1;
    for (int i = 0; i < (int)factorization.size(); i++)
    {
        i128 here = pisano_prime(factorization[i].first);
        for (int j = 1; j < factorization[i].second; j++)
            here *= factorization[i].first;

        ans = lcm(ans, here);
    }
    cout << ans << endl;
}

void MultiTest(bool Tests = 0)
{
    int tc = 1; (Tests) && (cin >> tc);
    for(int i = 1; i <= tc; ++i)
        Solve();
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast(); initialize(); MultiTest(1);
}

