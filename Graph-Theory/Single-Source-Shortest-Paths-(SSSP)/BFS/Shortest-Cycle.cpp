#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

using namespace std;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int N = 500 + 9, M = 4e4 + 9, oo = 0x3f3f3f3f;

int Head[N], Next[M], To[M], dis[N], Par[N], ne, n, m, u, v;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    To[ne] = to;
    Head[from] = ne;
}

int BFS(int src)
{
    memset(dis, 0x3f, (n + 3) * sizeof(int));
    memset(Par, 0, (n + 3) * sizeof(int));
    queue <int> Q;
    Q.push(src);
    dis[src] = 0;

    int node, ret = oo;
    while(Q.size())
    {
        node = Q.front(); Q.pop();
        for(int i = Head[node]; i; i = Next[i])
        {
            if(dis[To[i]] != oo) {
                if(Par[node] != To[i]) {
                    if(dis[node] + 1 + dis[To[i]] < ret)
                        ret = dis[node] + 1 + dis[To[i]];
                }
                continue;
            }

            dis[To[i]] = dis[node] + 1;
            Par[To[i]] = node;
            Q.push(To[i]);
        }
    }
    return ret;
}

void _clear() {
    memset(Head, 0, (n + 3) * sizeof(int));
    ne = 0;
}

void Solve()
{
    cin >> n >> m;
    _clear();

    while(m--)
    {
        cin >> u >> v;
        ++u, ++v;
        addEdge(u, v);
        addEdge(v, u);
    }

    int ans = oo;
    for(int i = 1; i <= n; ++i) {
        int cost = BFS(i);
        if(cost < ans) ans = cost;
    }

    if(ans == oo)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
    {
        cout << "Case " << i << ": ";
        Solve();
    }
}


