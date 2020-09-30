/** https://www.e-olymp.com/en/problems/10116 **/
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

using namespace std;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 2e5 + 9, M = 4e5 + 9, oo = 0x3f3f3f3f;

int Head[N], Next[M], To[M], dis[N], dis_s[N], dis_t[N], ne, n, m, u, v, st, tr;

void addEdge(int from, int to)
{
    Next[++ne] = Head[from];
    To[ne] = to;
    Head[from] = ne;
}

void BFS(int src, bool asp = false)
{
    memset(dis, 0x3f, sizeof dis);
    queue <int> Q;
    Q.push(src);
    dis[src] = 0;

    int node;
    while(Q.size()) {
        node = Q.front(); Q.pop();
        for(int i = Head[node]; i; i = Next[i]) if(dis[To[i]] == oo) {
            if(asp && dis_s[node] + 1 + dis_t[To[i]] == dis_s[tr]) continue;
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
        addEdge(u, v);
        addEdge(v, u);
    }

    BFS(st);
    memcpy(dis_s, dis, sizeof dis);
    BFS(tr);
    memcpy(dis_t, dis, sizeof dis);
    BFS(st, true);

    cout << (dis[tr] == oo ? -1 : dis[tr]) << endl;
}

