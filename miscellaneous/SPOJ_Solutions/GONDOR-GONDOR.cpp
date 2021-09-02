/** Dijkstra on dense graphs
    complexity : O(n^2 + m)
**/

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

const int N = 1e2 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;
long double INF = 1e18, eps = 1e-9;

int Head[N], Par[N], Next[M], To[M], ne, n, m, u, v, st, tr, tax;
long double dis[N];
long double Cost[M];
pair <int, int> cor[N];
int arrow[N];
vector <int> adj[N];

bool approximatelyEqual(double a, double b, double epsilon) {
  return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool definitelyLessThan(double a, double b, double epsilon) {
  return (b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

void addEdge(int from, int to, long double cost) {
  Next[++ne] = Head[from];
  To[ne] = to;
  Cost[ne] = cost;
  Head[from] = ne;
}

vector <int> restorePath(int dest)
{
  vector <int> path;
  if(dis[dest] == INF) return path;

  for(int i = dest; ~i; i = Par[i])
    path.push_back(i);

  reverse(path.begin(), path.end());
  return path;
}

void _clear() {
  memset(Head, 0, sizeof Head);
  ne = 0;
}

void Dijkstra(int src, int V)
{
  memset(Par, -1, sizeof Par);
  for(int i = 0; i <= V; ++i) dis[i] = 1e18;
  vector <bool> mark(V + 1, false); // dont use it in case of negative weights

  dis[src] = 0.0;
  for(int i = 1; i <= V; ++i) {

    int node = 0;
    for(int j = 1; j <= V; ++j)
      if(!mark[j] && definitelyLessThan(dis[j], dis[node], eps))
	node = j;

    if(approximatelyEqual(dis[node], INF, eps)) break;
    int arrows = arrow[node];
    mark[node] = true;

    for(int e = Head[node]; e && arrows; e = Next[e]) if(!mark[To[e]]) {
	if(definitelyLessThan(dis[node] + Cost[e], dis[To[e]], eps)) {
	  dis[To[e]] = dis[node] + Cost[e];
	  Par[To[e]] = node;
	}
	--arrows;
      }
  }
}

void Solve()
{
  _clear();

  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> cor[i].first >> cor[i].second >> arrow[i];

    adj[i].resize(n - 1);
    for(int j = 0; j + 1 < n; ++j)
      cin >> adj[i][j];

    reverse(adj[i].begin(), adj[i].end());
  }

  for(int i = 1; i <= n; ++i)
    {
      for(int j = 0; j + 1 < n; ++j)
        {
	  int xDif = cor[i].first - cor[adj[i][j]].first;
	  int yDif = cor[i].second - cor[adj[i][j]].second;

	  long double cost = sqrtl(xDif * 1.0 * xDif + yDif * 1.0 * yDif);
	  addEdge(i, adj[i][j], cost);
        }
    }

  //    for(int i = 1; i <= n; ++i)
  //    {
  //        cout << "from : " << i << " to : " << endl;
  //        for(int j = Head[i]; j; j = Next[j])
  //            cout << To[j] << " Cost = " << Cost[j] << "\n";
  //        cout << endl;
  //    }

  Dijkstra(1, n);

  for(int i = 1; i <= n; ++i)
    cout << dis[i] << endl;
}

int main()
{
  Fast();

  cout << fixed << setprecision(6);

  int tc = 1;
  for(int i = 1; i <= tc; ++i)
    Solve();
}

