#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl '\n'
#define read(a, n)  for(int i = 0; i < n; cin >> a[i++]);

#define debug(args ...) {			\
    string _s = #args;				\
    replace(_s.begin(), _s.end(), ',', ' ');	\
    stringstream _ss(_s);			\
    istream_iterator<string> _it(_ss);		\
    err(_it, args);				\
  } 

using namespace std;

using i128 = __int128_t;
using i64 = int64_t;
using i32 = int32_t;

using u128 = __uint128_t;
using u64 = uint64_t;
using u32 = uint32_t;
using ld = long double;

const int N = 2e5 + 9, M = 3e7 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7; 
const ld eps = 1e-9;

void err(istream_iterator<string> it) {}
template<typename T, typename ... Args>
void err(istream_iterator<string> it, T a, Args ... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args ...);
}

void fast() {			
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

void file() {
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

void Solve() {
  
}

int main() { 
  fast();
  // file();
  
  int t = 1; // cin >> t;
  for(int i = 1; i <= t; ++i) {
    Solve();
  }
}
