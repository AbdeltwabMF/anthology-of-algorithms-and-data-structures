#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t    ll;

void Fast() {
  cin.sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
}

const int N = 1e5;
int n, k, arr[N];

int SPLTK()
{
  int l = 0, prod = 1, ans = 0;
  for(int r = 0; r < n; ++r) {
    prod *= arr[r];
    for(; l <= r && prod >= k; ++l)
      prod /= arr[l];

    ans += r - l + 1;
  }
  return ans;
}

void Solve()
{
  cin >> n >> k;
  for(int i = 0; i < n; ++i)
    cin >> arr[i];

  cout << SPLTK() << endl;
}

int main()
{
  Fast();

  int tc = 1;
  for(int i = 1; i <= tc; ++i)
    Solve();
}

