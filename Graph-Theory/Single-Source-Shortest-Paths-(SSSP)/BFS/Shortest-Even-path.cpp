#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

using namespace std;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5 + 9, M = 4e5 + 9, oo = 0x3f3f3f3f;

int Head[N], Next[M], To[M], dis[N], ne, n, m, u, v, st, tr;

void addEdge(int from, int to)
{
    Next[++ne] = Head[from];
    To[ne] = to;
    Head[from] = ne;
}

void BFS(int src)
{
    memset(dis, 0xff, sizeof dis);
    queue <int> Q;
    Q.push(src);
    dis[src] = 0;

    int node;
    while(Q.size()) {
        node = Q.front(); Q.pop();
        for(int i = Head[node]; i; i = Next[i]) if(dis[To[i]] == -1) {
            dis[To[i]] = dis[node] + 1;
            Q.push(To[i]);
        }
    }
}

int main()
{
    Fast();
    cin >> n >> m >> st >> tr;

    while(m--) {
        cin >> u >> v;
        addEdge(u, v + n);
        addEdge(v + n, u);
        addEdge(u + n, v);
        addEdge(v, u + n);
    }

    BFS(st);
    cout << dis[tr] << endl;
}

