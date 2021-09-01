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

bool CheckComposite(ll n, ll p, ll d, int r)
{
  ll a = ModExp(p, d, n);
  if(a == 1 || a == n - 1)
    return false;

  for(int i = 1; i < r; ++i)
    {
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

  for(int p : {2, 3, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
      if(n == p)
	return true;
      if(CheckComposite(n, p, d, r))
	return false;
    }
  return true;
}

int main()
{
  Fast();

  ll n;
  cin >> n;
  cout << (Miller(n) ? "Yes, it is Prime" : "No, it is not a prime") << endl;
}

