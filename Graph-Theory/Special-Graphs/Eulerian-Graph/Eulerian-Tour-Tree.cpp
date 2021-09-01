int Head[N], To[M], Next[M], Cost[M];
int ne, n, m, u, v, w;

int Last[N], First[N], euler_tour[1 + N << 1];
ll  Height[1 + N << 1];
int euler_timer;

void addEdge(int from, int to, int cost = 0) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  Cost[ne] = cost;
  To[ne] = to;
}

void _clear() {
  memset(Head,       0, sizeof(Head[0])       * (n + 2));
  memset(Last,       0, sizeof(Last[0])       * (n + 2));
  memset(First,      0, sizeof(First[0])      * (n + 2));
  ne = euler_timer = 0;
}

/**
   euler_tour[1 .. n * 2 - 1] = which records the sequence of visited nodes
   Height[1 .. n * 2 - 1]     = which records the depth of each visited node

   First[1 .. n]      = records the index of the first occurrence of node i in euler_tour
   Last[1 .. n]       = records the index of the last  occurrence of node i in euler_tour
**/

void EulerianTour(int node, ll depth = 0) {
  euler_tour[++euler_timer] = node;
  Height[euler_timer] = depth;
  First[node] = euler_timer;

  for(int i = Head[node]; i; i = Next[i])
    if(First[To[i]] == 0) {
      EulerianTour(To[i], depth + Cost[i]);

      euler_tour[++euler_timer] = node;
      Height[euler_timer] = depth;
    }

  Last[node] = euler_timer;
}

void show() {
  for(int i = 1; i < (n << 1); ++i) cout << euler_tour[i] << " ";cout << endl;
  for(int i = 1; i < (n << 1); ++i) cout << Height[i] << " ";    cout << endl;
  for(int i = 1; i <= n; ++i)       cout << First[i] << " ";     cout << endl;
  for(int i = 1; i <= n; ++i)       cout << Last[i] << " ";      cout << endl;
}

int main() {
  cin >> n >> m;
  _clear();

  while(m--) {
    cin >> u >> v >> w;
    addEdge(u, v, w);
    addEdge(v, u, w);
  }

  EulerianTour(1);
  show();
}
