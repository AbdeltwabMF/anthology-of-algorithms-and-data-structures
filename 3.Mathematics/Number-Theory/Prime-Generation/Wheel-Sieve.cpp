#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t  ll;

const int N = 1e9;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

bitset <N + 9> isPrime;
int inx[30100];
vector <int> Primes;

vector <int> coPrimes(int n) {
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

    isPrime.set();
    inx[1] = sz - 2;
    int inc [sz - 1];

    for(int i = 1; i < sz; ++i)
        inc[i - 1] = wheel[i] - wheel[i - 1];

    Primes = {2, 3, 5, 7, 11, 13};

    int i = 0;
    for(ll d = 17; d <= n; d += inc[i++])
    {
        if(isPrime[d]) {
            Primes.push_back(d);
            int c = inx[d % 30030];
            for(ll j = d * d; j <= n; j += d * inc[c++])
            {
                isPrime.reset(j);
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

    for(int i = 0; i < Primes.size(); i += 500)
        cout << Primes[i] << endl;
}

