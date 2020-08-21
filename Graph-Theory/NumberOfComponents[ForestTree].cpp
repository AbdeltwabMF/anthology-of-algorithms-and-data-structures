#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;

int Head[N], Next[N << 1], To[N << 1], ne, u, v, n, numberOfComponents;
bool visited[N];

void addEdge(int _from, int _to)
{
    Next[++ne] = Head[_from];
    Head[_from] = ne;
    To[ne] = _to;
}

void DFS(int _node, int parent)
{
    visited[_node] = true;
    for (int e = Head[_node]; e; e = Next[e]) if(To[e] != parent)
        DFS(To[e], _node);
}

int main()
{
    cin >> n;

    while(--n)
    {
        cin >> u >> v;
        addEdge(u, v); addEdge(v, u);
    }

    for (int node = 1; node <= n; ++node) if(!visited[node])
    {
        ++numberOfComponents;
        DFS(node, -1);
    }

    cout << numberOfComponents << endl;
}
