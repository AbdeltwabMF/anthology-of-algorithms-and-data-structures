/** Euler Totient Function (Phi):
    Time Complexity: O(sqrt(n))
    2 <= n <= 10 ^ {12}
    - Phi(n) = n * ((p1 - 1) / p1) * ((p2 - 1) / p2) *...* ((pk - 1) / pk)
**/

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e6 + 9, M = 1e6 + 9, oo = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll n;
vector <int> primes;
bool isPrime[N];

void sieve(ll x)
{
    int basis [3] = {2, 3, 5};
    int wheel [8] = {7, 11, 13, 17, 19, 23, 29, 1};
    int inc   [8] = {4, 2, 4, 2, 4, 6, 2, 6};
    int inx[31];

    memset(inx,        -1, sizeof inx);
    memset(isPrime, true, sizeof isPrime);

    for(int i : basis) if(x >= i)
            primes.push_back(i);

    for(int i = 0; i < 8; ++i)
        inx[wheel[i]] = i;

    int c = 0;
    for(ll i = 7; i <= x; i += inc[c++])
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            int d = inx[i % 30];

            for(ll j = i * i; j <= x; j += i * inc[d++])
            {
                isPrime[j] = false;
                if(d == 8) d = 0;
            }
        }
        if(c == 8) c = 0;
    }
}

ll Phi(ll a)
{
    ll ret = a;

    for(int prime : primes)
    {
        if(prime * 1ll * prime > a) break;
        if(a % prime) continue;

        ret /= prime;
        ret *= (prime - 1);

        while(a % prime == 0)
            a /= prime;
    }

    if(a > 1) {
        ret /= a;
        ret *= (a - 1);
    }
    return ret;
}

void Solve()
{
    cin >> n;
    cout << Phi(n) << endl;
}

int main()
{
    Fast();
    sieve(1000000);

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

