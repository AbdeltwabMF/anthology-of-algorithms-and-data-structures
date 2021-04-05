/**
   - Output Random Number in the predefined range [a, b];
   - a and b may be int or long long or unsigned int or unsigned long long
   - 1. to use it just modify the value of a and b
   - 2. enter the number of Integers(n) you want.
**/

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7; 

void fast() {			
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T myRand(T a, T b) {
  return uniform_int_distribution <T> (a, b)(rng);
}

int main() { 
  fast();
  freopen("output.out", "w", stdout);

  int n;
  cin >> n;
  
  for(int i = 0; i < n; ++i) {
    cout << myRand(0ll, 1000000000000000000ll) << endl;
  }
}
