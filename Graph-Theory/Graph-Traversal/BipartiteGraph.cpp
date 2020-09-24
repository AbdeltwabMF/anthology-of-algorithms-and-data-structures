#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 1e6 + 9;

int Head[N], Next[M], To[M], ne, n, m, u, v;
bool color[N], vis[N];

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

bool checkBiPartite(int node, int par = 0) {
    if(vis[node])
        return color[par] != color[node];

    color[node] = 1 ^ color[par];

    vis[node] = true;
    bool ok = true;
    for(int i = Head[node]; i; i = Next[i]) if(To[i] != par)
            ok &= checkBiPartite(To[i], node);

    return ok;
}

int main() {

    cin >> n >> m;

    while(m--) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    bool isBiPartite = true;

    for(int i = 1; i <= n; ++i) if(!vis[i])
            isBiPartite &= checkBiPartite(i);

    cout << (isBiPartite ? "YES" : "NO") << endl;
}

