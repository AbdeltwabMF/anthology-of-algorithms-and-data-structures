#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define UNVISITED  0
#define EXPLORED   1
#define VISITED    2

using namespace std;

typedef int64_t  ll;

const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Next[M], To[M], Par[N], in_time[N], ne, n, m, u, v, dfs_timer;
char dfs_num[N];

void addEdge(int from, int to) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  To[ne] = to;
}

void edgeClassification(int node) {
  dfs_num[node] = EXPLORED;
  in_time[node] = ++dfs_timer;

  for(int i = Head[node]; i; i = Next[i]) {
    if(dfs_num[To[i]] == UNVISITED) {
      cout << "Tree Edge : " << node << " -> " << To[i] << endl;

      Par[To[i]] = node;
      edgeClassification(To[i]);
    }
    else if(dfs_num[To[i]] == VISITED) {
      /** Cross Edges only occur in directed graph */
      if(in_time[To[i]] < in_time[node])
	cout << "Cross Edge : " << node << " -> " << To[i] << endl;
      else
	cout << "Forward Edge : " << node << " -> " << To[i] << endl;
    }
    else if(dfs_num[To[i]] == EXPLORED) {
      if(Par[node] == To[i])
	cout << "Bi-Directional Edge : " << node << " -> " << To[i] << endl;
      else
	cout << "Backward Edge : " << node << " -> " << To[i] << " (Cycle)" << endl;
    }
  }

  dfs_num[node] = VISITED;
}

int main() {
  cin >> n >> m;
  while(m--) {
    cin >> u >> v;
    addEdge(u, v);
  }

  for(int i = 1; i <= n; ++i)
    if(!dfs_num[i])
      edgeClassification(i);
}

