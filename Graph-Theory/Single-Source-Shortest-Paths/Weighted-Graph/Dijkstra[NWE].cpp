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

void Dijkstra(int src) {
  memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
  memset(Par,   -1, sizeof(Par[0]) * (n + 2));

  priority_queue <pair <ll, int> > Q;

  dis[src] = 0;
  Q.push({-dis[src], src});

  int node;
  ll cost;
  while(Q.size()) {
    tie(cost, node) = Q.top(); Q.pop();
    if((-cost) > dis[node]) continue;

    for(int i = Head[node]; i; i = Next[i])
      if(dis[node] + Cost[i] < dis[To[i]]) {
	dis[To[i]] = dis[node] + Cost[i];
	Q.push({-dis[To[i]], To[i]});
	Par[To[i]] = node;
      }
  }
}


