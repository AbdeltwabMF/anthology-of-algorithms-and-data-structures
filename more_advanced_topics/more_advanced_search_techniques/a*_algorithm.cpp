const int dr []     = {-1, 0, 1, 0};
const int dc []     = {0, 1, 0, -1};
const char dir []   = {'U', 'R', 'D', 'L'};
map <char, int> inv = { {'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

const int N = 1e3 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

char grid[N][N], Par[N][N];
int dis[N][N], n, m, si, sj, ti, tj;

vector < pair <int, int> > restorePath(int sr, int sc, int tr, int tc) {
  vector < pair <int, int> > ret;
  if(dis[tr][tc] == oo) return ret;

  for(char i = Par[tr][tc]; (sr ^ tr) || (sc ^ tc); i = Par[tr][tc]) {
    ret.push_back({tr, tc});
    tr += dr[inv[i]];
    tc += dc[inv[i]];
  }

  ret.push_back({sr, sc});
  reverse(ret.begin(), ret.end());
  return ret;
}

bool valid(int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] != '%';
}

/** admissible heuristic **/
int manhattanDistance(int x1, int y1, int x2, int y2) {
  return (abs(x1 - x2) + abs(y1 - y2));
}

int Astar(int sr, int sc, int tr, int tc) {
  memset(dis, 0x3f, sizeof (dis));
  memset(Par,   -1, sizeof (Par));

  priority_queue <tuple <int, int, int> > Q;

  dis[sr][sc] = 0;
  Q.push({-manhattanDistance(sr, sc, tr, tc), sr, sc});

  int hcost, r, c, nr, nc;
  while(Q.size()) {
    tie(hcost, r, c) = Q.top(); Q.pop();
    if(r == tr && c == tc) return dis[r][c];

    for(int i = 0; i < 4; ++i) {
      nr = r + dr[i];
      nc = c + dc[i];

      if(!valid(nr, nc)) continue;

      if(dis[r][c] + 1 < dis[nr][nc]) {
	dis[nr][nc] = dis[r][c] + 1;
	Par[nr][nc] = dir[i ^ 2];
	Q.push({-dis[nr][nc] -manhattanDistance(nr, nc, tr, tc), nr, nc});
      }
    }
  }
  return -1;
}

void Solve() {
  cin >> si >> sj >> ti >> tj >> n >> m;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      cin >> grid[i][j];

  cout << Astar(si, sj, ti, tj) << endl;
  vector < pair <int, int> > path = restorePath(si, sj, ti, tj);

  for(auto point : path)
    cout << point.first << " " << point.second << endl;
}
