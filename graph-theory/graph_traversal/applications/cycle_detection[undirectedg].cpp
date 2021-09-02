const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Par[N], Next[M], To[M], Cost[M], ne, n, m, u, v, st, tr, tax;
ll dis[N];
bool visited[N], hasCycle;

void addEdge(int from, int to) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  To[ne] = to;
}

void DFS(int node, int parent = -1) {
  if(hasCycle |= visited[node])
    return;
  visited[node] = true;

  for(int i = Head[node]; i; i = Next[i])
    if(To[i] != parent)
      DFS(To[i], node);
}

int main() {
  cin >> n >> m;
  while(m--) {
    cin >> u >> v;
    addEdge(u, v);
    addEdge(v, u);
  }

  for(int i = 1; i <= n; ++i)
    if(!visited[i])
      DFS(i);

  cout << (hasCycle ? "YES" : "NO") << endl;
}

