#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;
long long oo = 0x3f3f3f3f3f3f3f3f;

int Head[N], Next[N << 1], To[N << 1], Cost[N << 1], ne, u, v, w, n;
long long dis[N], diameter;

void addEdge(int from, int to, int cost) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    Cost[ne] = cost;
    To[ne] = to;
}

void BFS(int src) {
    memset(dis, 0x3f, sizeof dis);
    queue <int> Q;
    Q.push(src);
    dis[src] = 0;

    int node;
    while(Q.size()) {
        node = Q.front();
        Q.pop();
        for(int e = Head[node]; e; e = Next[e]) if(dis[To[e]] == oo) {
            dis[To[e]] = dis[node] + Cost[e];
            Q.push(To[e]);
        }
    }
}

int furthest() {
    long long ret = -1;
    int node = 1;
    for(int i = 1; i <= n; ++i) if(dis[i] != oo && dis[i] > ret)
        ret = dis[i], node = i;

    diameter = ret;
    return node;
}

int main() {

    cin >> n;

    for(int i = 1; i < n; ++i) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    BFS(1);
    BFS(furthest());
    furthest();

    cout << diameter << endl;
}

