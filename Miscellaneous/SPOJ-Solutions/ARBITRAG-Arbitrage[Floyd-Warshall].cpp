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

const int N = 33 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;
const double INF = 1e18, eps = 1e-9;

int n, m;
double tax, dis[N][N], adj[N][N];
map <string, int> inv;
string u, v;

bool definitelyLessThan(double a, double b, double epsilon) {
  return (b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool definitelyGreaterThan(double a, double b, double epsilon) {
  return (a - b) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool Floyd_Warshall()
{
  for(int via = 1; via <= n; ++via)
    {
      for(int i = 1; i <= n; ++i)
	for(int j = 1; j <= n; ++j)
	  if(dis[i][via] * dis[via][j] > dis[i][j]) {
	    dis[i][j] = dis[i][via] * dis[via][j];
	  }
    }

  for(int i = 1; i <= n; ++i)
    if(dis[i][i] > 1.0)
      return true;

  return false;
}

void Solve()
{
  inv.clear();

  for(int i = 1; i <= n; ++i) {
    cin >> u;
    inv[u] = i;
  }

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      adj[i][j] = (i == j) * 1.0;

  cin >> m;
  for(int i = 1; i <= m; ++i) {
    cin >> u >> tax >> v;
    adj[inv[u]][inv[v]] = tax;
  }

  memcpy(dis, adj, sizeof dis);
  cout << (Floyd_Warshall() ? "Yes" : "No") << endl;
}

int main()
{
  Fast();

  int tc = 1;
  for(int i = 1; cin >> n && n != 0; ++i) {
    cout << "Case " << i << ": ";
    Solve();
  }
}

