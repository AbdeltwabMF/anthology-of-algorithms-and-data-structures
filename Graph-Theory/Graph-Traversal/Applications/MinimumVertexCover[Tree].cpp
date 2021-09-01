const int N = 1e5 + 9;

int Head[N], Next[N << 1], To[N << 1], ne, u, v, n, MVC;

void addEdge(int from, int to) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  To[ne] = to;
}

bool DFS(int node, int par = -1) {
  bool black = false;
  for(int e = Head[node]; e; e = Next[e])
    if(To[e] != par)
      black |= DFS(To[e], node);

  MVC += black;
  return !black;
}

int main() {
  cin >> n;
  while(--n) {
    cin >> u >> v;
    addEdge(u, v);
    addEdge(v, u);
  }

  DFS(1);
  cout << MVC << endl;
}

