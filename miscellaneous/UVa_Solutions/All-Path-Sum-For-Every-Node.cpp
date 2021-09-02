#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
  cin.sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
}

void File() {
  freopen("input.in",  "r", stdin);
  freopen("output.out", "w", stdout);
}

const int N = 2e5 + 9, M = 4e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Next[M], To[M];
int ne, u, v, n, m;
int subtree_size[N], level[N];
ll dis[N];

void addEdge(int from, int to) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  To[ne] = to;
}

void dfs(int node, int par = -1) {
  subtree_size[node] = 1;
  for(int i = Head[node]; i; i = Next[i]) if(To[i] != par) {
      level[To[i]] = level[node] + 1;
      dfs(To[i], node);
      subtree_size[node] += subtree_size[To[i]];
    }
}

void reRoot(int node, ll pd, int par = -1) {
  dis[node] = pd;
  for(int i = Head[node]; i; i = Next[i]) if(To[i] != par) {
      reRoot(To[i], pd - subtree_size[To[i]] + (n - subtree_size[To[i]]), node);
    }
}

void Solve()
{
  cin >> n;
  for(int i = 1; i < n; ++i) {
    cin >> u >> v;
    addEdge(u, v);
    addEdge(v, u);
  }

  dfs(1);

  ll pd = 0;
  for(int i = 1; i <= n; ++i)
    pd += level[i];

  reRoot(1, pd);

  for(int i = 1; i <= n; ++i)
    cout << dis[i] << " \n"[i == n];
}

int main()
{
  Fast();

  int tc = 1;
  for(int i = 1; i <= tc; ++i)
    Solve();
}

