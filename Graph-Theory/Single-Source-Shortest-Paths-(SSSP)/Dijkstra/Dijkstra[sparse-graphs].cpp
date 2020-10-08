/** Dijkstra on sparse graphs
    complexity : O(nlogn + m)
**/

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

void Dijkstra(int src)
{
    memset(dis, 0x3f, sizeof dis);
    memset(Par, -1, sizeof Par);

    priority_queue <pair <ll, int>,
                   vector <pair <ll, int> >,
                   greater <pair <ll, int> > > Q;

    dis[src] = 0;
    Q.push({dis[src], src});

    int node;
    ll cost;
    while(Q.size())
    {
        tie(cost, node) = Q.top(); Q.pop();
        if(cost != dis[node]) continue;

        for(int i = Head[node]; i; i = Next[i]) if(dis[node] + Cost[i] < dis[To[i]]) {
            dis[To[i]] = dis[node] + Cost[i];
            Q.push({dis[To[i]], To[i]});
            Par[To[i]] = node;
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

    Dijkstra(st);

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

