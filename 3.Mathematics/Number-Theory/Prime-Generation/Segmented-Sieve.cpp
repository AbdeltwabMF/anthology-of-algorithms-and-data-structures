/**
	constraints:
	1 <= l, r <= 1e{14}
	1 <= r - l + 1 <= 1e7

	Time complexity of this approach is : O((r − l + 1)lnln(r) + √r lnln r^{1/4})
**/

#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t  ll;

const int N = 1e6;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

vector <int> Primes;
bitset <N + 9> isPrime;

vector <int> simple_sieve(int n)
{
    int basis [] = {2, 3, 5};
    int inc [] = {4, 2, 4, 2, 4, 6, 2, 6};
    int inx [30] = {0};
    inx[1] = 7, inx[7] = 0, inx[11] = 1, inx[13] = 2,
    inx[17] = 3, inx[19] = 4, inx[23] = 5, inx[29] = 6;

    isPrime.set();
    vector <int> ret;
    for(int i : basis) if(n >= i)
            ret.push_back(i);

    int i = 0;
    for(ll d = 7; d <= n; d += inc[i++])
    {
        if(isPrime[d]) {
            ret.push_back(d);
            int c = inx[d % 30];
            for(ll j = d * d; j <= n; j += d * inc[c++])
            {
                isPrime.reset(j);
                if(c == 8) c = 0;
            }
        }
        if(i == 8) i = 0;
    }
    return ret;
}

vector <ll> segmented_sieve(ll l, ll r)
{
    l += l == 1;
    int limit = r - l + 1;
    vector <ll> ret;
    isPrime.set();

    for(int i = 0; i < (int)Primes.size(); ++i) {
        ll p = Primes[i];
        for(ll j = max(p * p, (l / p) * p); j <= r; j += Primes[i])
            isPrime.reset(j - l);
    }

    for(int i = 0; i < limit; ++i)
        if(isPrime[i])
            ret.push_back(i + l);
    return ret;
}

void Solve()
{
    ll l, r;
    cin >> l >> r;

    vector <ll> P = segmented_sieve(l, r);
    int sz = P.size();

    for(int i = 0; i < sz; ++i)
        cout << P[i] << "\n";

    cout << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    Primes = simple_sieve(1'000'000);

    for(int i = 1; i <= tc; ++i)
        Solve();
}

