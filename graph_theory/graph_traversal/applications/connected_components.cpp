const int N = 1e5 + 9, M = 1e6 + 9;

int Head[N], Next[M], To[M], ne, u, v, n, m, CCs;
bool visited[N];

void addEdge(int from, int to) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  To[ne] = to;
}

void DFS(int node) {
  visited[node] = true;
  for(int e = Head[node]; e; e = Next[e])
    if(!visited[To[e]])
      DFS(To[e]);
}

int main() {
  cin >> n >> m;
  while(m--) {
    cin >> u >> v;
    addEdge(u, v);
    addEdge(v, u);
  }

  for(int node = 1; node <= n; ++node) if(!visited[node])
					 ++CCs, DFS(node);

  cout << CCs << endl;
}

