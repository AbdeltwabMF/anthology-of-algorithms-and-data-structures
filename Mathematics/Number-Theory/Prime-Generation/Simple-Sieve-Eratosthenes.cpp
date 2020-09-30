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

const int N = 1e6;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

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
    for(ll d = 7; d <= n; d += inc[i++]) {
        if(isPrime[d])
        {
            ret.push_back(d);
            int c = inx[d % 30];
            for(ll j = d * d; j <= n; j += d * inc[c++]) {
                isPrime.reset(j);
                if(c == 8) c = 0;
            }
        }
        if(i == 8) i = 0;
    }
    return ret;
}

int main()
{
    Fast();
    vector <int> Primes = simple_sieve(1'000'000);

    for(int i = 0; i < Primes.size(); i += 500)
        cout << Primes[i] << "\n";

    cout << Primes.size() << endl;
}


