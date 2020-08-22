#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 1e6 + 9;

int Head[N], Next[M], To[M], ne, u, v, n, m, CCs;
bool visited[N];

void addEdge(int _from, int _to)
{
    Next[++ne] = Head[_from];
    Head[_from] = ne;
    To[ne] = _to;
}

void DFS(int _node)
{
    visited[_node] = true;
    for (int e = Head[_node]; e; e = Next[e]) if(!visited[To[e]])
        DFS(To[e]);
}

int main()
{
    cin >> n >> m;

    while(m--)
    {
        cin >> u >> v;
        addEdge(u, v); addEdge(v, u);
    }

    for (int node = 1; node <= n; ++node) if(!visited[node])
    {
        ++CCs;
        DFS(node);
    }

    cout << CCs << endl;
}
