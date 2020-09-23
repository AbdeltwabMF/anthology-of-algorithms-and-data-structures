#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 1e6 + 9;

int Head[N], Next[M], To[M], ne, n, m, u, v;
bool vis[N];
vector <int> t_sort;

void DFS(int node)
{
    vis[node] = true;

    for(int i = Head[node]; i; i = Next[i]) if(!vis[To[i]])
        DFS(To[i]);

    t_sort.push_back(node);
}

vector <int> topological_sort(int n)
{
    t_sort.clear();

    for(int i = 1; i <= n; ++i) if(!vis[i])
        DFS(i);

    reverse(t_sort.begin(), t_sort.end());

    return t_sort;
}

void addEdge(int from, int to)
{
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

int main()
{
    cin >> n >> m;

    while(m--)
    {
        cin >> u >> v;
        addEdge(u, v);
    }

    vector <int> v = topological_sort(n);

    for(int i : v)
        cout << i << ' ';
}
