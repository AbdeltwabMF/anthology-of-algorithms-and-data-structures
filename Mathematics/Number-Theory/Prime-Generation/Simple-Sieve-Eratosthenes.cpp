/**
	constraints:
	1 <= n <= 1e8

	Time complexity of this approach is : n lnln √n + O(n)
**/

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

vector <int> simple_sieve(int n)
{
    int basis [] = {2, 3, 5};
    int inc [] = {4, 2, 4, 2, 4, 6, 2, 6};
    int inx [] = {-1,-1,-1,-1,-1,-1,-1,0,-1,-1,-1,1,-1,2,-1,-1,-1,3,-1,4,-1,-1,-1,5,-1,-1,-1,-1,-1,6,-1,7};

    vector <int> ret;
    for(int i : basis) if(n >= i)
            ret.push_back(i);

    int i = 0;
    for(ll d = 7; d <= n; d += inc[i++]) {
        if(!isComposite[d])
        {
            ret.push_back(d);
            int md = d % 30;
            if(md == 1) md += 30;
            int c = inx[md];

            for(ll j = d * d; j <= n; j += d * inc[c++])
            {
                isComposite.set(j);
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
    vector <int> Primes = simple_sieve(1'000'000'000);

    for(int i = 0; i < Primes.size(); i += 500)
        cout << Primes[i] << "\n";

    cout << Primes.size() << endl;
}


