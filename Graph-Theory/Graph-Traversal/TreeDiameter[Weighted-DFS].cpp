#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;

int Head[N], Next[N << 1], To[N << 1], Cost[N << 1], ne, at, from, to, u, v, w, n;
long long diameter;

void addEdge(int from, int to, int cost) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    Cost[ne] = cost;
    To[ne] = to;
}

void DFS(int node, long long cost, int par = -1) {
    if(cost > diameter) diameter = cost, at = node;
    for (int e = Head[node]; e; e = Next[e]) if(To[e] != par)
            DFS(To[e], cost + Cost[e], node);
}

int main() {

    cin >> n;

    while(--n) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    DFS(1, 0ll);
    from = at, diameter = 0;
    DFS(from, 0ll);
    to = at;

    cout << diameter << endl;
}

