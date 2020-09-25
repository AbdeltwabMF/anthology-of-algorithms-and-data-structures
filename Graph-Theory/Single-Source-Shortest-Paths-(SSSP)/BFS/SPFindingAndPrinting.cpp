#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 9, M = 4e6 + 9, oo = 0x3f3f3f3f;

int Head[N], Next[M], To[M], dis[N], Par[N], ne, n, m, u, v, st, tr;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    To[ne] = to;
    Head[from] = ne;
}

void BFS(int src) {
    memset(dis, 0x3f, sizeof dis);
    queue <int> Q; Q.push(src);
    dis[src] = 0;

    int node;	
    while(Q.size()) {
        node = Q.front(); Q.pop();
        for(int i = Head[node]; i; i = Next[i]) if(dis[To[i]] == oo) {
            dis[To[i]] = dis[node] + 1;
            Q.push(To[i]);
            Par[To[i]] = node;
        }
    }
}

void printPath(int s) {
    if(s == 0) return;
    printPath(Par[s]);
    cout << s << " ";
}

int main() {

    cin >> n >> m >> st >> tr;

    while(m--) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    BFS(st);
    if(dis[tr] == oo) cout << -1 << endl;
    else {
        cout << dis[tr] << endl;
        printPath(tr);
        cout << endl;
    }
}

