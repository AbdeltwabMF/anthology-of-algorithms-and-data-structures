#include <bits/stdc++.h>
using namespace std;
typedef int64_t    ll;

const int N = 3e5 + 9, M = 6e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Next[M], To[M], Par[N];
int sbtree_size[N];
int ne, n, m, u, v, w;

void addEdge(int from, int to) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  To[ne] = to;
}

void _clear() {
  memset(Head, 0, sizeof(Head[0]) * (n + 2));
  memset(Par, -1, sizeof(Par[0])  * (n + 2));
  ne = 0;
}

void dfs(int node, int par = -1) {
  sbtree_size[node] = 1;
  for(int i = Head[node]; i; i = Next[i]) if(To[i] != par) {
      dfs(To[i], node);
      sbtree_size[node] += sbtree_size[To[i]];
    }
}

int main()
{
  cin >> n;
  _clear();

  for(int i = 2; i <= n; ++i) {
    cin >> u;
    addEdge(u, i);
  }

  dfs(1);
  for(int i = 1; i <= n; ++i)
    cout << sbtree_size[i] - 1 << " \n"[i == n];
}

