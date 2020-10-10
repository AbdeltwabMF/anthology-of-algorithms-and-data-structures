#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 9, M = 4e6 + 9, oo = 0x3f3f3f3f;

int Head[N], Next[M], To[M], dis[N], ne, n, m, u, v, st;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    To[ne] = to;
    Head[from] = ne;
}

void BFS(int src) 
{
    memset(dis, 0x3f, sizeof dis);
    queue <int> Q;
    Q.push(src);
    dis[src] = 0;

    int node;
    while(Q.size()) {
        node = Q.front(); Q.pop();
        for(int i = Head[node]; i; i = Next[i]) if(dis[To[i]] == oo) {
            dis[To[i]] = dis[node] + 1;
            Q.push(To[i]);
        }
    }
}

int main() {

    cin >> n >> st;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            cin >> v;
            if(v)
                addEdge(i, j);
        }

    BFS(st);
    for(int i = 1; i <= n; ++i)
        cout << (dis[i] == oo ? -1 : dis[i]) << " \n"[i == n];
}

