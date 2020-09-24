#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;

int Head[N], Next[N << 1], To[N << 1], ne, u, v, n, CCs;
bool visited[N];

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void DFS(int node, int par = -1) {
    visited[node] = true;
    for (int e = Head[node]; e; e = Next[e]) if(To[e] != par)
            DFS(To[e], node);
}

int main() {

    cin >> n;

    while(--n) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for(int node = 1; node <= n; ++node) if(!visited[node])
        ++CCs, DFS(node);

    cout << CCs << endl;
}

