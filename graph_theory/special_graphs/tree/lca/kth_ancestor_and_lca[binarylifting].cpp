const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const int LOG = 20;

int Head[N], To[M], Next[M], Par[N];
int up[N][LOG + 1];
int Log[N], Level[N];
int ne, n, u, v, q;

void addEdge(int from, int to) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  To[ne] = to;
}

void _clear() {
  memset(Head,  0, sizeof(Head[0])   * (n + 2));
  memset(Par,   0, sizeof(Par[0])    * (n + 2));
  memset(Level, 0, sizeof(Level[0])  * (n + 2));
  ne = 0;
}

int lastBit(int a) {
  return (a & -a);
}

void logCalc() {
  Log[1] = 0;
  for(int i = 2; i < N; ++i)
    Log[i] = Log[i >> 1] + 1;
}

void DFS(int node, int depth = 0) {
  Level[node] = depth;
  up[node][0] = Par[node];  // Par[root] = root

  for(int i = 1; i <= LOG; ++i) {
    up[node][i] = up[up[node][i - 1]][i - 1];
  }

  for(int i = Head[node]; i; i = Next[i])
    if(To[i] != Par[node]) {
      Par[To[i]] = node;
      DFS(To[i], depth + 1);
    }
}

int KthAncestor(int u, int k) {
  if(k > Level[u]) return -1;

  for(int i = lastBit(k); k; k -= lastBit(k), i = lastBit(k))
    u = up[u][Log[i]];

  return u;
}

int LCA(int u, int v) {
  if(Level[u] < Level[v]) swap(u, v);
  int k = Level[u] - Level[v];

  u = KthAncestor(u, k);
  if(u == v) return u;

  for(int i = LOG; i >= 0; --i)
    if(up[u][i] ^ up[v][i])
      {
	u = up[u][i];
	v = up[v][i];
      }

  return up[u][0];
}

int main() {
  cin >> n;
  _clear();

  for(int i = 1; i < n; ++i) {
    cin >> u >> v;
    addEdge(u, v);
    addEdge(v, u);
  }

  logCalc();
  for(int i = 1; i <= n; ++i) if(Par[i] == 0) {
      Par[i] = i;
      DFS(i);
    }

  cin >> q;
  while(q--) {
    cin >> u >> v;
    cout << LCA(u, v) << endl;
  }
}

