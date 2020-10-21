/**
	constraints:
	1 <= n <= 1e8

	Time complexity of this approach is : n lnln √n + O(n)
**/

#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t  ll;

const int N = 1e6 + 9;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

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

int main()
{
    Fast();
    sieve(1000000);

    for(int i = 0; i < primes.size(); i += 500)
        cout << primes[i] << "\n";

    cout << primes.size() << endl;
}

