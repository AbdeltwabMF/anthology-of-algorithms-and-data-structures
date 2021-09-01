const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Par[N], Next[M], To[M], Cost[M], ne, n, m, u, v, st, tr, tax;
ll dis[N];
bool color[N], vis[N];

void addEdge(int from, int to) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  To[ne] = to;
}

bool checkBiPartite(int node, int par = 0) {
  if(vis[node])
    return color[par] != color[node];

  color[node] = color[par] ^ 1;

  vis[node] = true;
  bool ok = true;
  for(int i = Head[node]; i; i = Next[i])
    if(To[i] != par)
      ok &= checkBiPartite(To[i], node);

  return ok;
}

int main() {
  cin >> n >> m;
  while(m--) {
    cin >> u >> v;
    addEdge(u, v);
    addEdge(v, u);
  }

  bool isBiPartite = true;
  for(int i = 1; i <= n; ++i) if(!vis[i])
				isBiPartite &= checkBiPartite(i);

  cout << (isBiPartite ? "YES" : "NO") << endl;
}

