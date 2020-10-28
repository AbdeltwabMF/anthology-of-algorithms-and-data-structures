#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

using namespace std;

typedef int64_t  ll;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Next[M], To[M], Par[N], dfs_num[N], dfs_low[N], ne, n, m, u, v, dfs_timer;
vector < pair <int, int> > bridges;
int root, rootChildren;
bool articulation[N];

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void _clear() {
    memset(Par,         -1, sizeof(Par[0])          * (n + 2));
    memset(Head,         0, sizeof(Head[0])         * (n + 2));
    memset(dfs_num,      0, sizeof(dfs_num[0])      * (n + 2));
    memset(articulation, 0, sizeof(articulation[0]) * (n + 2));
    bridges.clear();
    dfs_timer = 0;
    ne = 0;
}

void DFS(int node)
{
    dfs_num[node] = dfs_low[node] = ++dfs_timer;

    for(int i = Head[node]; i; i = Next[i])
    {
        if(dfs_num[To[i]] == 0) {
            if(node == root) rootChildren++;

            Par[To[i]] = node;
            DFS(To[i]);

            if(dfs_low[To[i]] < dfs_low[node])
                dfs_low[node] = dfs_low[To[i]];

            if(dfs_low[To[i]] > dfs_num[node])
                bridges.push_back({node, To[i]});

            if(dfs_low[To[i]] >= dfs_num[node])
                articulation[node] = true;
        }
        else if(Par[node] != To[i])
            if(dfs_num[To[i]] < dfs_low[node])
                dfs_low[node] = dfs_num[To[i]];
    }
}

void Solve()
{
    cin >> n >> m;
    _clear();

    while(m--) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for(int i = 1; i <= n; ++i) if(!dfs_num[i])
    {
        root = i;
        rootChildren = 0;

        DFS(i);
        articulation[root] = (rootChildren > 1);
    }

    cout << "Cut Points :\n";
    for(int i = 1; i <= n; ++i) if(articulation[i])
            cout << i << " ";

    cout << "\nBridges :\n";
    for(pair <int, int> bridge : bridges)
        cout << bridge.first << " <--> " << bridge.second << endl;
}

int main()
{
    Fast();

    int tc = 1;
    while(tc--) Solve();
}

