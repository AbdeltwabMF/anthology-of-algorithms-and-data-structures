#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef long long  ll;

const int N = 1e9;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

bitset <N + 9> isComposite;
int inx[30100], primesCnt;
vector <int> Primes;

vector <int> coPrimes(int n)
{
    int basis [5] = {3, 5, 7, 11, 13};

    vector <int> ret;
    bitset <30100> isCoprime;
    isCoprime.set();

    for(int p : basis)
        for(int d = p * p; d <= n; d += p << 1)
            isCoprime.reset(d);

    for(int i = 17; i <= n; i += 2)
        if(isCoprime[i]) ret.push_back(i);

    ret.push_back(n + 1);
    ret.push_back(n + 17);

    return ret;
}

void wheel_sieve(int n)
{
    int basis [6] = {2, 3, 5, 7, 11, 13};
    vector <int> wheel = coPrimes(2 * 3 * 5 * 7 * 11 * 13);
    int sz = wheel.size();

    for(int k = 0; k < sz; ++k)
        inx[wheel[k]] = k;

    int inc [sz - 1];

    for(int i = 1; i < sz; ++i)
        inc[i - 1] = wheel[i] - wheel[i - 1];

    Primes.push_back(2);
    primesCnt = 6;

    int i = 0;
    for(ll d = 17; d <= n; d += inc[i++]) {
        if(!isComposite[d]) {
            if(++primesCnt == 501)
                Primes.push_back(d), primesCnt = 1;

            int md = d % 30030;
            if(md == 1) md += 30030;

            int c = inx[md];
            for(ll j = d * d; j <= n; j += d * inc[c++]) {
                isComposite.set(j);
                if(c == sz - 1) c = 0;
            }
        }
        if(i == sz - 1) i = 0;
    }
}

int main()
{
    Fast();
    wheel_sieve(1'000'000'000);

    for(int i = 0; i < Primes.size(); ++i)
        cout << Primes[i] << endl;
}

