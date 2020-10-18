#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define  endl    '\n'

using namespace std;

typedef int64_t ll;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int L1D_CACHE_SIZE = 32768;
vector <int> Primes;

void segmented_sieve(ll limit)
{
    int sqrt = sqrtl(limit);
    int segment_size = L1D_CACHE_SIZE;
    if(segment_size < sqrt) segment_size = sqrt;

    Primes = {2, 3, 5};
    ll i = 7, n = 7, s = 7;

    int basis [] = {2, 3, 5};
    int inc [] = {4, 2, 4, 2, 4, 6, 2, 6};
    int inx [30] = {0};
    inx[1] = 7, inx[7] = 0, inx[11] = 1, inx[13] = 2,
    inx[17] = 3, inx[19] = 4, inx[23] = 5, inx[29] = 6;
    int d = 0, k = 0, g = 0;

    bool sieve[segment_size];
    bool is_prime[sqrt + 1];
    fill(is_prime, is_prime + sqrt + 1, true);
    vector <int> primes;
    vector <ll> multiples;

    for (ll low = 0; low <= limit; low += segment_size)
    {
        fill(sieve, sieve + segment_size, true);
        ll high = low + segment_size - 1;
        if(high > limit) high = limit;

        for(; i * i <= high; i += inc[k++])
        {
            if(is_prime[i])
            {
                int f =  inx[i % 30];
                for (ll j = i * i; j <= sqrt; j += inc[f++] * i)
                {
                    is_prime[j] = false;
                    if(f == 8) f = 0;
                }
            }
            if(k == 8) k = 0;
        }

        for (; s * s <= high; s += inc[g++])
        {
            if (is_prime[s]) {
                primes.push_back(s);
                multiples.push_back(s * s - low);
            }
            if(g == 8) g = 0;
        }

        for(size_t i = 0; i < primes.size(); ++i)
        {
            ll j = multiples[i];
            for(ll k = primes[i] * 2ll; j < segment_size; j += k)
                sieve[j] = false;
            multiples[i] = j - segment_size;
        }

        for(; n <= high; n += inc[d++])
        {
            if(sieve[n - low])
                Primes.push_back(n);
            if(d == 8) d = 0;
        }
    }
}

int main()
{
    Fast();
    segmented_sieve(1'000'000'000);
    cout << Primes.size() << endl;
}

