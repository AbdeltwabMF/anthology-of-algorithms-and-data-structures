/**	Bellman-Ford Algorithm :
    - In programming contests, the slowness of Bellman Ford’s and its negative cycle detection feature
	causes it to be used only to solve the SSSP problem on small graph
	which is not guaranteed to be free from negative weight cycle.
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

void addEdge(int from, int to, int cost) {
    Next[++ne] = Head[from];
    To[ne] = to;
    Cost[ne] = cost;
    Head[from] = ne;
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
    memset(Head, 0, sizeof(Head[0]) * (n + 2));
    ne = 0;
}

bool hasNC()
{
    for(int u = 1; u <= n; ++u)
        for(int e = Head[u]; e; e = Next[e])
            if(dis[u] + Cost[e] < dis[To[e]])
                return true;

    return false;
}

vector <int> getCycle()
{
    int start = -1;
    for(int i = 2; i <= n; ++i) {
        for(int u = 1; u <= n; ++u)
            for(int e = Head[u]; e; e = Next[e]) if(dis[u] + Cost[e] < dis[To[e]]) {
                    dis[To[e]] = -INF;
                    start = To[e];
                    Par[To[e]] = u;
                }
    }

    vector <int> ret;
    if(start == -1) return ret;
    set <int> cycle;

    for(int i = start; !cycle.count(i); i = Par[i])
        cycle.insert(i);

    start = *cycle.rbegin();

    for(int i = Par[start]; i ^ start; i = Par[i])
        ret.push_back(i);

    ret.push_back(start);
    reverse(ret.begin(), ret.end());
    return ret;
}

bool Bellman_Ford(int src)
{
    memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
    memset(Par, -1, sizeof(Par[0]) * (n + 2));

    dis[src] = 0;
    bool newRelaxation = true;
    for(int i = 2; i <= n && newRelaxation; ++i) {
        newRelaxation = false;
        for(int u = 1; u <= n; ++u)
            for(int e = Head[u]; e; e = Next[e]) if(dis[u] + Cost[e] < dis[To[e]]) {
                    dis[To[e]] = dis[u] + Cost[e];
                    Par[To[e]] = u;
                    newRelaxation = true;
                }
    }
    return hasNC();
}

void Solve()
{
    _clear();

    cin >> n >> m >> st >> tr;
    while(m--) {
        cin >> u >> v >> tax;
        addEdge(u, v, tax);
    }

    bool hasNegativeCycle = Bellman_Ford(st);
    cout << (hasNegativeCycle ? "YES" : "NO") << endl;

    vector <int> v = getCycle();
    for(auto i : v)
        cout << i << " ";
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

