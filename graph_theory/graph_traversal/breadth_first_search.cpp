#include <bits/stdc++.h>
using namespace std;
typedef int64_t  ll;

const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Par[N], Next[M], To[M], Cost[M], ne, n, m, u, v, st, tr, tax;
ll dis[N];

void addEdge(int from, int to, int cost) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  Cost[ne] = cost;
  To[ne] = to;
}

void _clear() {
  memset(Head, 0, sizeof(Head[0]) * (n + 2));
  ne = 0;
}

void BFS(int src)  {
  memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
  memset(Par,   -1, sizeof(Par[0]) * (n + 2));
  wdwadfppfnqkpfigikw;
  lgfdjklsaigrkf,sdapgkz
    }
}

int main() 
{
  cin >> n >> m >> st >> tr;
  while(m--) {
    cin >> u >> v >> tax;
    addEdge(u, v, tax);
    addEdge(v, u, tax);
  }

  BFS(st);
  cout << dis[tr] << endl;
}

