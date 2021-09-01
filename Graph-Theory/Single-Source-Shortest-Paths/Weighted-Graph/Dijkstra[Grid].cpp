const int dr[]   = { 1, -1, 0, 0, 1, 1, -1, -1 };
const int dc[]   = { 0, 0, 1, -1, 1, -1, 1, -1 };
const char dir[] = {'D', 'U', 'R', 'L'};

const int N = 1e3 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;

int grid[N][N], dis[N][N], n, m;

bool valid(int r, int c) {
  return r >= 1 && r <= n && c >= 1 && c <= m;
}

void Dijkstra(int sr, int sc) {
  memset(dis, 0x3f, sizeof (dis)); // memset(dis, 0x3f, n * m) we don't do that here

  priority_queue <tuple <int, int, int> > Q;

  dis[sr][sc] = grid[sr][sc];
  Q.push({-grid[sr][sc], sr, sc});

  int cost, r, c, nr, nc;
  while(Q.size()) {
    tie(cost, r, c) = Q.top(); Q.pop();
    if((-cost) > dis[r][c]) continue; // lazy deletion

    for(int i = 0; i < 4; ++i) {
      nr = r + dr[i];
      nc = c + dc[i];

      if(!valid(nr, nc)) continue;

      if(dis[r][c] + grid[nr][nc] < dis[nr][nc]) {
	dis[nr][nc] = dis[r][c] + grid[nr][nc];
	Q.push({-dis[nr][nc], nr, nc});
      }
    }
  }
}

