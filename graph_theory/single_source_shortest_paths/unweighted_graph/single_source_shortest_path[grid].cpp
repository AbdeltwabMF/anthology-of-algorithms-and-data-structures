const int N = 1e3 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

const int dr []     = {-1, 0, 1, 0};
const int dc []     = {0, 1, 0, -1};
const char dir []   = {'U', 'R', 'D', 'L'};
map <char, int> inv = { {'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

int dis[N][N], n, m;
char Par[N][N];

bool valid(int r, int c) {
  return r >= 1 && r <= n && c >= 1 && c <= m && dis[r][c] == oo;
}

void BFS(int sr, int sc) {
  memset(dis, 0x3f, sizeof(dis));
  memset(Par,   -1, sizeof(Par));

  queue < pair <int, int> > Q;
  dis[sr][sc] = 0;
  Q.push({sr, sc});

  int r, c, nr, nc;
  while(Q.size()) {
    tie(r, c) = Q.front(); Q.pop();

    for(int i = 0; i < 4; ++i) {
      nr = r + dr[i];
      nc = c + dc[i];

      if(!valid(nr, nc)) continue;

      dis[nr][nc] = dis[r][c] + 1;
      Par[nr][nc] = dir[i ^ 2];
      Q.push({nr, nc});
    }
  }
}

