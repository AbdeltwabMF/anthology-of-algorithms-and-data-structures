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

typedef long long  ll;

const int N = 1e6;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

vector <int> Primes;
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

vector <ll> segmented_sieve(ll l, ll r)
{
    l += l == 1;
    int limit = r - l + 1;
    vector <ll> ret;
    isComposite.reset();

    for(int i = 0; i < (int)Primes.size(); ++i)
    {
        ll p = Primes[i];
        ll st = (l / p) * p;
        if(st < l) st += p;
        st = max(st, p * p);
        if(st > r) break;

        for(int j = st; j <= r; j += Primes[i])
            isComposite.set(j - l);
    }

    for(int i = 0; i < limit; ++i)
        if(!isComposite[i])
            ret.push_back(i + l);
    return ret;
}

void Solve()
{
    ll l, r;
    cin >> l >> r;

    vector <ll> PrimesLR = segmented_sieve(l, r);
    int sz = PrimesLR.size();

    for(int i = 0; i < sz; ++i)
        cout << PrimesLR[i] << "\n";

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

