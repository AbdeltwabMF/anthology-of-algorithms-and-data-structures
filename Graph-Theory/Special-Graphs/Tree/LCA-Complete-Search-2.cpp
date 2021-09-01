#include <bits/stdc++.h>
using namespace std;
typedef int64_t    ll;

const int N = 1e5 + 9, M = 2e6 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], To[M], Next[M], Cost[M], Par[N];
int level[N];
bool vis[N];
int ne, n, m, u, v, w, q;

void addEdge(int from, int to, int cost = 1) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  Cost[ne] = cost;
  To[ne] = to;
}

void _clear() {
  memset(Head,  0, sizeof(Head[0])  * (n + 2));
  memset(vis,   0, sizeof(vis[0])   * (n + 2));
  memset(Par,  -1, sizeof(Par[0])   * (n + 2));
  memset(level, 0, sizeof(level[0]) * (n + 2));
  ne = 0;
}

void DFS(int node, int depth = 0) {
  vis[node] = true;
  level[node] = depth;

  for(int i = Head[node]; i; i = Next[i]) if(!vis[To[i]]) {
      Par[To[i]] = node;
      DFS(To[i], depth + Cost[i]);
    }
}

int LCA(int u, int v)
{
  if(level[u] < level[v]) swap(u, v);
  int d = level[u] - level[v];

  while(d--)
    u = Par[u];

  if(u == v) return v;

  while(Par[u] ^ Par[v])
    {
      u = Par[u];
      v = Par[v];
    }

  return Par[v];
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

  DFS(1);

  cin >> q;
  while(q--)
    {
      cin >> u >> v;
      cout <<  LCA(u, v) << endl;
    }
}

