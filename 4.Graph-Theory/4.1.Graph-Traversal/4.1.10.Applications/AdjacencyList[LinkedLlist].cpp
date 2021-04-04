class Graph {
public:
  vector <int> _head, _next, _to, _cost;
  int edge_number;
  bool isDirected;

  Graph() = default;
  Graph(int V, int E, bool isDirec) {
    isDirected = isDirec;
    _head.assign(V + 9, 0);
    _next.assign(isDirected ? E + 9 : E * 2 + 9, 0);
    _to.assign(isDirected ? E + 9 : E * 2 + 9, 0);
    // _cost.assign(isDirected ? E + 9 : E * 2 + 9, 0);
    edge_number = 0;
  }

  void addEdge(int u, int v, int w = 0) {
    _next[++edge_number] = _head[u];
    _to[edge_number] = v;
    // _cost[edge_number] = w;
    _head[u] = edge_number;
  }

  void addBiEdge(int u, int v, int w = 0) {
    addEdge(u, v, w);
    addEdge(v, u, w);
  }

  void dfs(int node) {
    vis[node] = true;
    for(int i = _head[node]; i; i = _next[i]) if(!vis[_to[i]]) {
	dfs(_to[i]);
      }
  }
};
