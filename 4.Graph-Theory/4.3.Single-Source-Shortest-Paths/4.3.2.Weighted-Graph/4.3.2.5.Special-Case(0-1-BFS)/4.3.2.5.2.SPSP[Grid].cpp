#include <bits/stdc++.h>
using namespace std;
typedef int64_t  ll;
int main() {}

const int dr[]   = { -1, -1, 0, 1, 1,  1,  0, -1 };
const int dc[]   = {  0,  1, 1, 1, 0, -1, -1, -1 };
const char dir[] = {'D', 'U', 'R', 'L'};

const int N = 1e3 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;

int dis[N][N], n, m, si, sj, ti, tj;
char grid[N][N];

bool valid(int r, int c) {
    return r >= 1 && r <= n && c >= 1 && c <= m;
}

/**
7 0 1
 \|/
6-*-2
 /|\
5 4 3
**/

int ZBFS(int sr, int sc, int tr, int tc)
{
    memset(dis, 0x3f, sizeof (dis)); // memset(dis, 0x3f, n * m) we don't do that here

    deque <pair <int, int> > Q;

    dis[sr][sc] = 0;
    Q.push_front({sr, sc});

    int r, c, nr, nc, ncost;
    while(Q.size())
    {
        tie(r, c) = Q.front(); Q.pop_front();
        if(r == tr && c == tc) return dis[r][c];

        for(int i = 0; i < 8; ++i)
        {
            nr = r + dr[i];
            nc = c + dc[i];

            if(!valid(nr, nc)) continue;
            ncost = (i != grid[r][c]);

            if(dis[r][c] + ncost < dis[nr][nc])
            {
                dis[nr][nc] = dis[r][c] + ncost;

                if(ncost)
                    Q.push_back({nr, nc});
                else
                    Q.push_front({nr, nc});
            }
        }
    }
    return oo;
}

