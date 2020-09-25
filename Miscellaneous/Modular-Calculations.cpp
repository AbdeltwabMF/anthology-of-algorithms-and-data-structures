#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef long long  ll;
typedef __int128 i128;

const int N = 1e6, Mod = 1'000'000'007;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

/*
    1. Modular Exponentiation
*/
ll ModExp(ll base, ll e, ll mod)
{
    ll result;
    base %= mod;

    for(result = 1; e; e >>= 1ll)
    {
        if(e & 1ll)
            result = ((i128)result * base) % mod;
        base = ((i128)base * base) % mod;
    }
    return result;
}

int main()
{
    Fast();

    ll n, e;
    cin >> n >> e;
    cout << ModExp(n, e, Mod) << endl;
}

