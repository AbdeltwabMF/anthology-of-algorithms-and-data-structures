#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef long long  ll;
typedef __int128 i128;

const int N = 1e6;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

bitset <N + 9> isComposite;

vector <int> simple_sieve(int n)
{
    int basis [] = {2, 3, 5};
    int inc [] = {4, 2, 4, 2, 4, 6, 2, 6};
    int inx [33] = {0};
    inx[7] = 0;
    inx[11] = 1;
    inx[13] = 2;
    inx[17] = 3;
    inx[19] = 4;
    inx[23] = 5;
    inx[29] = 6;
    inx[31] = 7;

    vector <int> ret;
    for(int i : basis) if(n >= i)
            ret.push_back(i);

    int i = 0;
    for(ll d = 7; d <= n; d += inc[i++])
    {
        if(!isComposite[d])
        {
            ret.push_back(d);
            int md = d % 30;
            if(md == 1) md += 30;

            int c = inx[md];
            for(ll j = d * d; j <= n; j += d * inc[c++]) {
                isComposite.set(j);
                if(c == 8) c = 0;
            }
        }
        if(i == 8) i = 0;
    }
    return ret;
}

ll ModExp(ll base, ll e, ll mod)
{
    ll result;
    base %= mod;

    for(result = 1; e; e >>= 1ll) {
        if(e & 1ll)
            result = ((i128)result * base) % mod;
        base = ((i128)base * base) % mod;
    }
    return result;
}

bool CheckComposite(ll n, ll p, ll d, int r)
{
    ll a = ModExp(p, d, n);
    if(a == 1 || a == n - 1)
        return false;

    for(int i = 1; i < r; ++i) {
        a = ((i128)a * a) % n;
        if(a == n - 1)
            return false;
    }
    return true;
}

bool Miller(ll n)
{
    if(n < 2) return false;

    int r; ll d;
    for(r = 0, d = n - 1; (d & 1ll) == 0; d >>= 1ll, ++r);

    for(int p : {2, 3, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if(n == p)
            return true;
        if(CheckComposite(n, p, d, r))
            return false;
    }
    return true;
}

ll Factorization(ll n)
{
    ll divisors = 1;
    vector <int> primes = simple_sieve(1'000'000);

    for(int prime : primes)
    {
        if((ll)prime * prime * prime > 1e18) break;
        if(n % prime) continue;

        int cnt = 0;
        while(n % prime == 0)
            ++cnt, n /= prime;

        divisors *= (cnt + 1);
    }

    if(Miller(n))
        divisors *= (1 + 1);
    else if(Miller((ll)sqrtl(n)))
        divisors *= (2 + 1);
    else if(n > 1)
        divisors *= (1 + 1) * (1 + 1);
    return divisors;
}

int main()
{
    Fast();

    ll n;
    cin >> n;
    cout << Factorization(n) << endl;
}

