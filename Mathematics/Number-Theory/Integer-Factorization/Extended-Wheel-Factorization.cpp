#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef long long  ll;

const int N = 1e6;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

vector <int> primes;
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

vector <pair <ll, int> > Factorization(ll n)
{
    vector <pair <ll, int> > ret;

    for(int prime : primes)
    {
        if((ll)prime * prime > n) break;
        if(n % prime) continue;

        int cnt = 0;
        while(n % prime == 0)
            ++cnt, n /= prime;

        ret.push_back({prime, cnt});
    }
    if(n > 1)
        ret.push_back({n, 1});
    return ret;
}

int main()
{
    Fast();

    ll n; cin >> n;

    primes = simple_sieve(1'000'000);
    vector <pair <ll, int> > factors = Factorization(n);

    for(auto i : factors)
        cout << i.first << " " << i.second << endl;
}

