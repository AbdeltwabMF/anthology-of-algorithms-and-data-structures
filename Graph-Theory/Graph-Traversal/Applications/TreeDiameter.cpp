#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;

int Head[N], Next[N << 1], To[N << 1], ne, at, from, to, diameter, u, v, n;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void DFS(int node, int cost, int par = -1) {
    if(cost > diameter) diameter = cost, at = node;
    for (int e = Head[node]; e; e = Next[e]) if(To[e] != par)
            DFS(To[e], cost + 1, node);
}

int main() {

    cin >> n;

    while(--n) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    DFS(1, 0);
    from = at, diameter = 0;
    DFS(from, 0);
    to = at;

    cout << diameter << " " << from << " " << to << endl;
}

