const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Next[M], To[M];
int Par[N], dfs_num[N], dfs_low[N];
int ne, n, m, u, v;
int root, rootChildren, dfs_timer;
int Stack[N], top, ID;
bool Art[N];
vector < vector <int> > BiCCs(N), BiCCIDs(N);

void addEdge(int from, int to) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  To[ne] = to;
}

void _clear() {
  memset(Head,       0, sizeof(Head[0])       * (n + 2));
  memset(dfs_num,    0, sizeof(dfs_num[0])    * (n + 2));
  memset(Par,       -1, sizeof(Par[0])        * (n + 2));
  memset(Art,        0, sizeof(Art[0])        * (n + 2));
  ne = dfs_timer = top = ID = 0;
  BiCCs = BiCCIDs = vector < vector <int> > (N);
}

void Tarjan(int node) {
  dfs_num[node] = dfs_low[node] = ++dfs_timer;
  Stack[top++] = node;

  for(int i = Head[node]; i; i = Next[i]) {
    if(dfs_num[To[i]] == 0) {
      if(node == root) ++rootChildren;

      Par[To[i]] = node;
      Tarjan(To[i]);

      dfs_low[node] = Min(dfs_low[node], dfs_low[To[i]]);

      if(dfs_low[To[i]] >= dfs_num[node]) {
	Art[node] = true;
	++ID;
	for(int x = -1; x ^ To[i];) {
	  x = Stack[--top];
	  BiCCIDs[x].emplace_back(ID);
	  BiCCs[ID].emplace_back(x);
	}
	BiCCIDs[node].emplace_back(ID);
	BiCCs[ID].emplace_back(node);
      }
    }
    else if(To[i] != Par[node])
      dfs_low[node] = Min(dfs_low[node], dfs_num[To[i]]);
  }
}

int main() {
  cin >> n >> m;
  _clear();

  while(m--) {
    cin >> u >> v;
    addEdge(u, v);
    addEdge(v, u);
  }

  for(int i = 1; i <= n; ++i)
    if(dfs_num[i] == 0) { // O(n + m)
      root = i;
      rootChildren = 0;
      Tarjan(i);
      Art[root] = (rootChildren > 1);
    }

  for(int i = 1; i <= ID; ++i) {
    cout << "Component : " << i << " contains : ";
    for(int j = 0; j < (int)BiCCs[i].size(); ++j)
      cout << BiCCs[i][j] << " \n"[j == BiCCs[i].size() - 1];
  }
}

