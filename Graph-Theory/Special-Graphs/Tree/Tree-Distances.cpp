#include <bits/stdc++.h>
using namespace std;
typedef int64_t    ll;

const int N = 2e5 + 9, M = 4e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int LOG = 20;

int Head[N], Next[M], To[M], Par[N];
int ne, n, m, u, v;
int diameter, At, From;

int E[N << 1], H[N << 1], F[N], L[N], timer;
int SP[N << 1][LOG + 1];
int Log[N << 1];

void addEdge(int from, int to) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  To[ne] = to;
}

void _clear() {
  memset(Head, 0, sizeof(Head[0]) * (n + 2));
  memset(Par, -1, sizeof(Par[0])  * (n + 2));
  ne = 0;
  timer = 0;
}

void EulerTour(int node, int depth = 0, int par = -1) {
  E[++timer] = node;
  H[timer] = depth;
  F[node] = timer;

  for(int i = Head[node]; i; i = Next[i]) if(To[i] != par) {
      EulerTour(To[i], depth + 1, node);

      E[++timer] = node;
      H[timer] = depth;
    }

  L[node] = timer;
}

void dfs(int node, int depth = 0, int par = -1) {
  if(depth > diameter) diameter = depth, At = node;
  for(int i = Head[node]; i; i = Next[i]) if(To[i] != par)
					    dfs(To[i], depth + 1, node);
}

void bulid()
{
  EulerTour(1);
  dfs(1); From = At; diameter = 0; dfs(From);

  Log[1] = 0;
  for(int i = 2; i <= (n << 1); ++i)
    Log[i] = Log[i >> 1] + 1;

  for(int i = 1; i < (n << 1); ++i)
    SP[i][0] = i;

  int MaxLog = Log[(n << 1)];
  for(int j = 1, k, h; j <= MaxLog; ++j) {
    k = (1 << j);
    h = (k >> 1);
    for(int i = 1; i + k - 1 < (n << 1); ++i)
      {
	const int & x = SP[i][j - 1];
	const int & y = SP[i + h][j - 1];

	SP[i][j] = H[x] <= H[y] ? x : y;
      }
  }
}

int query(int l, int r)
{
  int d = r - l + 1;
  int lg = Log[d];
  int k = (1 << lg);

  const int & x = SP[l][lg];
  const int & y = SP[l + d - k][lg];

  return (H[x] <= H[y] ? x : y);
}

int LCA(int u, int v) {
  return query(u, v);
}

int distance(int u, int v) {
  int l = F[u];
  int r = F[v];
  if(l > r) swap(l, r);

  int ix = LCA(l, r);
  return (H[l] + H[r] - H[ix] - H[ix]);
}

int main()
{
  cin >> n;
  _clear();

  for(int i = 1; i < n; ++i) {
    cin >> u >> v;
    addEdge(u, v);
    addEdge(v, u);
  }

  bulid();
  for(int i = 1; i <= n; ++i)
    cout << max(distance(i, At), distance(i, From)) << " \n"[i == n];
}

