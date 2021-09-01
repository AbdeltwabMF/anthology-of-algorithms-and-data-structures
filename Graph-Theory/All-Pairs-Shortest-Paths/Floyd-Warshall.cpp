/**	-The graph has a 'negative cycle' if at the end of the algorithm,
	the distance from a vertex v to itself is negative.

	- before k-th phase the value of d[i][j] is equal to the length of
	the shortest path from vertex i to the vertex j,
	if this path is allowed to enter only the vertex with numbers smaller than k
	(the beginning and end of the path are not restricted by this property).
**/

const int N = 500 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
const i64 INF = 0x3f3f3f3f3f3f3f3f;

int Par[N][N], n, m, u, v, tax;
i64 adj[N][N], dis[N][N];

vector <int> restorePath(int st, int tr) {
  vector <int> path;
  if(dis[st][tr] == INF) return path;

  for(int i = tr; st ^ i; i = Par[st][i])
    path.push_back(i);

  path.push_back(st);
  reverse(path.begin(), path.end());
  return path;
}

void Floyd_Warshall() {
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      Par[i][j] = i;

  for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
	if(dis[i][k] + dis[k][j] < dis[i][j]) {
	  dis[i][j] = dis[i][k] + dis[k][j];
	  Par[i][j] = Par[k][j];
	}
}

