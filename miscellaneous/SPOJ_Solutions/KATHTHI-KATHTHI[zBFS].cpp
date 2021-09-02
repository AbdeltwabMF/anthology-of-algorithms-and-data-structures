#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl    '\n'

using namespace std;

typedef int64_t  ll;

void Fast() {
  cin.sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
}

const int dr []     = {-1, 0, 1, 0};
const int dc []     = {0, 1, 0, -1};
const char dir []   = {'U', 'R', 'D', 'L'};
map <char, int> inv = { {'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

const int N = 1e3 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

char grid[N][N], tmp[N][N];
int dis[N][N], n, m;
char Par[N][N];

vector <pair <int, int> > restorePath(int sr, int sc, int tr, int tc) {
  vector <pair <int, int> > ret;
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
  return r > 0 && r <= n && c > 0 && c <= m;
}

void zBFS(int sr, int sc)
{
  memset(dis, 0x3f, sizeof dis);

  deque <pair <int, int> > Q;
  Q.push_back({sr, sc});
  dis[sr][sc] = 0;

  int r, c, nr, nc, ncost;
  while(Q.size())
    {
      tie(r, c) = Q.front(); Q.pop_front();
      if(r == n && c == m) return;

      for(int i = 0; i < 4; ++i)
        {
	  nr = r + dr[i];
	  nc = c + dc[i];

	  if(!valid(nr, nc)) continue;
	  ncost = (grid[nr][nc] != grid[r][c]);

	  if(dis[r][c] + ncost < dis[nr][nc])
            {
	      dis[nr][nc] = dis[r][c] + ncost;
	      Par[nr][nc] = dir[i ^ 2];

	      if(ncost)
		Q.push_back({nr, nc});
	      else
		Q.push_front({nr, nc});
            }
        }
    }
}

void Solve()
{
  cin >> n >> m;

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      cin >> grid[i][j];

  zBFS(1, 1);
  cout << dis[n][m] << endl;
}

int main()
{
  Fast();

  int tc = 1; cin >> tc;
  while(tc--) Solve();
}

