const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Par[N], Next[M], To[M], Cost[M], ne, n, m, u, v, st, tr, tax;
ll dis[N];
bool hasCycle;
char visited[N];

void addEdge(int from, int to) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  To[ne] = to;
}

void DFS(int node) {
  if(hasCycle |= visited[node] == 1)
    return; /** Oops, revisiting active node **/
  visited[node] = 1; /** current node legend mode has been activated **/

  for(int i = Head[node]; i; i = Next[i])
    if(visited[To[i]] != 2)
      DFS(To[i]);

  visited[node] = 2; /** done with this node and mark it as visited **/
}

int main() {
  cin >> n >> m;
  while(m--) {
    cin >> u >> v;
    addEdge(u, v);
  }

  for(int i = 1; i <= n; ++i)
    if(!visited[i])
      DFS(i);

  cout << (hasCycle ? "YES" : "NO") << endl;
}

