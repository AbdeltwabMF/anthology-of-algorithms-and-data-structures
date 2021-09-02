const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Par[N], Next[M], To[M], ne, n, m, u, v, st, tr;
ll dis[N];

void addEdge(int from, int to) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  To[ne] = to;
}

void _clear() {
  memset(Head, 0, sizeof(Head[0]) * (n + 2));
  ne = 0;
}

void BFS(int src) {
  memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
  memset(Par,   -1, sizeof(Par[0]) * (n + 2));

  queue <int> Q;
  Q.push(src);
  dis[src] = 0;

  int node;
  while(Q.size()) {
    node = Q.front(); Q.pop();
    for(int i = Head[node]; i; i = Next[i]) if(dis[To[i]] == INF) {
	dis[To[i]] = dis[node] + 1;
	Par[To[i]] = node;
	Q.push(To[i]);
      }
  }
}

