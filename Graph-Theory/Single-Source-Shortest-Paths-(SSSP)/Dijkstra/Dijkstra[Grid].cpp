#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t    ll;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int dr[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
const int dc[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
const char dir[] = {'D', 'U', 'R', 'L'};

const int N = 1e3 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;

int grid[N][N], dis[N][N], n, m;

bool valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void BFS(int sr, int sc)
{
    memset(dis, 0x3f, sizeof dis);
    priority_queue <tuple <int, int, int>,
                   vector <tuple <int, int, int> >,
                   greater <tuple <int, int, int> > > Q;

    dis[sr][sc] = grid[sr][sc];
    Q.push({grid[sr][sc], sr, sc});

    int r, c, cost, nr, nc;
    while(Q.size())
    {
        tie(cost, r, c) = Q.top(); Q.pop();
        if(cost != dis[r][c]) continue;

        for(int i = 0; i < 4; ++i)
        {
            nr = r + dr[i];
            nc = c + dc[i];

            if(!valid(nr, nc)) continue;

            if(dis[r][c] + grid[nr][nc] < dis[nr][nc]) {
                dis[nr][nc] = dis[r][c] + grid[nr][nc];
                Q.push({dis[nr][nc], nr, nc});
            }
        }
    }
}

void Solve()
{
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> grid[i][j];

    BFS(0, 0);
    cout << dis[n - 1][m - 1] << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

