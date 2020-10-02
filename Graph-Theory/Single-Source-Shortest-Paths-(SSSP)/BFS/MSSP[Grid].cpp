#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 9, oo = 0x3f3f3f3f;

char ar[N][N], a;
int n, m, dis[N][N];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};
queue < array <int, 2> > Q;

bool valid(int r, int c) {
    return r >= 1 && r <= n && c >= 1 && c <= m && dis[r][c] == oo;
}

void BFS() {
    int r, c, nr, nc;
    while(Q.size())
    {
        r = Q.front()[0];
        c = Q.front()[1];
        Q.pop();

        for(int i = 0; i < 4; ++i) {
            nr = r + dr[i];
            nc = c + dc[i];
            if(!valid(nr, nc)) continue;
            dis[nr][nc] = dis[r][c] + 1;
            Q.push({nr, nc});
        }
    }
}

void Solve() {

    cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);
    // do not use this shit again in xD arrays memset(dis, 0x3f, n * m * 4);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a;
            if(a == '1') {
                Q.push({i, j});
                dis[i][j] = 0;
            }
        }
    }

    BFS();

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            cout << dis[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}
