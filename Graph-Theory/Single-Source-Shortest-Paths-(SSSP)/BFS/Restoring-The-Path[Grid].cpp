#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
}

const int N = 80 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;

const int dr []     = {-1, 0, 1, 0};
const int dc []     = {0, 1, 0, -1};
const char dir [] = {'U', 'R', 'D', 'L'};
map <char, int> inv = { {'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

int n, m, si, sj, ti, tj, dis[N][N];
bool mat[N][N];
char par[N][N];

bool valid(int r, int c) {
    return r > 0 && r <= n && c > 0 && c <= m && !mat[r][c] && dis[r][c] == oo;
}

void BFS(int sr, int sc)
{
    memset(dis, 0x3f, sizeof dis);
    memset(par,   -1, sizeof par);

    queue <pair <int, int> > Q;
    dis[sr][sc] = 0;
    Q.push({sr, sc});

    int r, c, nr, nc;
    while(Q.size())
    {
        tie(r, c) = Q.front(); Q.pop();
        for(int i = 0; i < 4; ++i)
        {
            nr = r + dr[i];
            nc = c + dc[i];

            if(!valid(nr, nc)) continue;

            dis[nr][nc] = dis[r][c] + 1;
            Q.push({nr, nc});
            par[nr][nc] = dir[i ^ 2];
        }
    }
}

string restorePath(int si, int sj, int fi, int fj)
{
    int ei = fi, ej = fj;
    string s;
    if(par[ei][ej] == -1) return s;

    for(char i = par[fi][fj]; (si ^ fi) || (sj ^ fj); i = par[fi][fj])
    {
        s += dir[inv[i] ^ 2];
        fi += dr[inv[i]];
        fj += dc[inv[i]];
    }
    reverse(s.begin(), s.end());
    return s;
}

void _clear() {
    memset(mat, 0, sizeof mat);
}

void Solve()
{
    _clear();

    cin >> n >> m >> si >> sj >> ti >> tj;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> mat[i][j];

    if(mat[ti][tj]) mat[ti][tj] ^= 1;
    BFS(si, sj);

    string s = restorePath(si, sj, ti, tj);

    if(dis[ti][tj] != oo)
        cout << s << "\n" << s.size() << endl;
    else
        cout << "impossible." << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

