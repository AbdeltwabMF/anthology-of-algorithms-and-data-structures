#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 1e6 + 9, oo = 0x3f3f3f3f;

int Head[N], Next[M << 1], To[M << 1], dis[N], ne, n, m, u, v, st, tr;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void BFS(int src) {
    memset(dis, 0x3f, sizeof dis);
    queue <int> q;
    q.push(src);
    dis[src] = 0;

    int u;
    while(q.size()) {
        u = q.front(); q.pop();
        for(int i = Head[u]; i; i = Next[i]) if(dis[To[i]] == oo) {
            dis[To[i]] = dis[u] + 1;
            q.push(To[i]);
        }
    }
}

int main() {

    cin >> n >> m >> st << tr;

    while(m--) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    BFS(st);
    cout << dis[tr] << endl;
}

