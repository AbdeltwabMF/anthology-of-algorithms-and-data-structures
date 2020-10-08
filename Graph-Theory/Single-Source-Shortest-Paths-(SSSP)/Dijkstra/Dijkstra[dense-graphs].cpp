/** Dijkstra on dense graphs
    complexity : O(n^2 + m)
**/

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>


using namespace std;
#define endl      '\n'

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Par[N], Next[M], To[M], Cost[M], ne, n, m, u, v, st, tr, tax;
ll dis[N];

void addEdge(int from, int to, int cost)
{
    Next[++ne] = Head[from];
    To[ne] = to;
    Cost[ne] = cost;
    Head[from] = ne;
}

void Dijkstra(int src, int V)
{
    memset(Par, -1, sizeof Par);
    memset(dis, 0x3f, sizeof dis);
    vector <bool> mark(V + 1, false);

    dis[src] = 0;
    for(int i = 1; i <= V; ++i) {

        int node = 0;
        for(int j = 1; j <= V; ++j)
            if(!mark[j] && dis[j] < dis[node])
                node = j;

        if(dis[node] == INF) break;

        mark[node] = true;
        for(int e = Head[node]; e; e = Next[e]) if(dis[node] + Cost[e] < dis[To[e]]) {
            dis[To[e]] = dis[node] + Cost[e];
            Par[To[e]] = node;
        }
    }
}

vector <int> restorePath(int dest)
{
    vector <int> path;
    if(dis[dest] == INF) return path;

    for(int i = dest; ~i; i = Par[i])
        path.push_back(i);

    reverse(path.begin(), path.end());
    return path;
}

void _clear() {
    memset(Head, 0, sizeof Head);
    ne = 0;
}

void Solve()
{
    _clear();

    cin >> n >> m >> st >> tr;
    while(m--) {
        cin >> u >> v >> tax;
        addEdge(u, v, tax);
        addEdge(v, u, tax);
    }

    Dijkstra(st, n);
    vector <int> path = restorePath(tr);

    if(dis[tr] == INF)
        cout << "NONE" << endl;
    else
        cout << dis[tr] << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

