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

const int N = 500 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int Par[N][N], n, m, u, v, tax;
ll adj[N][N], dis[N][N];

vector <int> restorePath(int sr, int sc)
{
    vector <int> path;
    if(dis[sr][sc] == INF) return path;

    for(int i = sc; sr ^ i; i = Par[sr][i])
        path.push_back(i);

    path.push_back(sr);
    reverse(path.begin(), path.end());
    return path;
}

void Floyd_Warshall()
{
    for(int u = 1; u <= n; ++u)
        for(int v = 1; v <= n; ++v)
            Par[u][v] = u;

    for(int k = 1; k <= n; ++k)
        for(int u = 1; u <= n; ++u)
            for(int v = 1; v <= n; ++v)
                if(dis[u][k] + dis[k][v] < dis[u][v]) {
                    dis[u][v] = dis[u][k] + dis[k][v];
                    Par[u][v] = Par[k][v];
                }
}

void Solve()
{
    cin >> n >> m;
    memset(adj, 0x3f, sizeof adj);

    while(m--) {
        cin >> u >> v >> tax;
        adj[u][v] = tax;
    }

    for(int i = 1; i <= n; ++i)
        adj[i][i] = 0;

//    for(int i = 1; i <= n; ++i)
//        for(int j = 1; j <= n; ++j)
//            cin >> adj[i][j];

    memcpy(dis, adj, sizeof adj);
    Floyd_Warshall();

    for(int u = 1; u <= n; ++u)
        for(int v = 1; v <= n; ++v)
            cout << dis[u][v] << " \n"[v == n];

    vector <int> path = restorePath(1, 2);
    for(int i : path)
        cout << i << " ";
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

