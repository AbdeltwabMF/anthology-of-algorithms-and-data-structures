#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
  cin.sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
}

const int N = 1e5 + 9, M = 1e6 + 9, oo = 0x3f3f3f3f;
int n, q, ar[N], l, r;
int next_smaller[N], prev_smaller[N];

void Solve()
{
  cin >> n >> q;
  for(int i = 1; i <= n; ++i)
    cin >> ar[i];

  next_smaller[n] = prev_smaller[1] = n + 1;
  for(int i = n - 1; i; --i)
    next_smaller[i] = min(next_smaller[i + 1], ar[i + 1]);
  for(int i = 2; i <= n; ++i)
    prev_smaller[i] = min(prev_smaller[i - 1], ar[i - 1]);

  while(q--)
    {
      cin >> l >> r;
      cout << min(next_smaller[r], prev_smaller[l]) << endl;
    }
}

int main()
{
  Fast(); 
    
  int tc = 1;
  cin >> tc;
  while(tc--) Solve();
}

