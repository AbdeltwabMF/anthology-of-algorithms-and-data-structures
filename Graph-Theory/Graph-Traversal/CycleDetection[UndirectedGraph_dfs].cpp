#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 1e6 + 9;

int Head[N], Next[M], To[M], ne, u, v, n, m;
bool visited[N], hasCycle;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void DFS(int node, int parent = -1) {

    if(hasCycle |= visited[node]) return;
    visited[node] = true;

    for(int e = Head[node]; e; e = Next[e]) if(To[e] != parent)
        DFS(To[e], node);
}

int main() {

    cin >> n >> m;

    while(m--) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for(int node = 1; node <= n; ++node) if(!visited[node])
        DFS(node);

    cout << (hasCycle ? "YES" : "NO") << endl;
}

