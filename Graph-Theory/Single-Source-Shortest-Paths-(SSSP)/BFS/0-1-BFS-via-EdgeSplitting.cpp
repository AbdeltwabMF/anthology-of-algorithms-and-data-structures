/** 	resources:
        1. https://onlinejudge.org/board/viewtopic.php?t=7281&start=15
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 9, M = 4e5 + 9;

int Head[N], Next[M], To[M], Cost[M], dis[N], ne, n, m, u, v, w, start, target, edge;

void addEdge(int from, int to, int cost) {
    Next[++ne] = Head[from];
    To[ne] = to;
    Cost[ne] = cost;
    Head[from] = ne;
}

void splitEdge(int u, int v, int w, int & edge) {
    addEdge(u, edge, 1);
    addEdge(edge, u, 1);

    for(int next = edge; next - edge + 2 < w; ++next) {
        addEdge(next, next + 1, 1);
        addEdge(next + 1, next, 1);
    }

    edge += w - 2;
    addEdge(v, edge, 1);
    addEdge(edge, v, 1);
    ++edge;
}

void BFS(int src) {
    memset(dis, 0x3f, sizeof dis);
    deque <int> Q;
    Q.push_front(src);
    dis[src] = 0;

    int node;
    while(Q.size()) {
        node = Q.front(); Q.pop_front();
        for(int i = Head[node]; i; i = Next[i]) if(dis[node] + Cost[i] < dis[To[i]]) {
            dis[To[i]] = dis[node] + Cost[i];
            if(Cost[i]) Q.push_back(To[i]);
            else Q.push_front(To[i]);
        }
    }
}

int main() {

    cin >> n >> m >> start >> target;
    edge = n + 1;

    while(m--) {
        cin >> u >> v >> w;
        if(w > 1)
            splitEdge(u, v, w, edge);
        else
            addEdge(u, v, w), addEdge(v, u, w);
    }

    BFS(start);
    cout << dis[target] << endl;
}

