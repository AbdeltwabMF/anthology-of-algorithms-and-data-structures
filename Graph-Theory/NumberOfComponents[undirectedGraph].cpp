#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 1e6 + 9;

int Head[N], Next[M], To[M], ne, u, v, n, m, numberOfComponents;
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
        ++numberOfComponents;
        DFS(node);
    }

    cout << numberOfComponents << endl;
}

/** Sample Input **
	10 9
	1 2
	2 3
	3 4
	3 5
	1 6
	6 7
	6 10
	7 8
	7 9
** Sample Output **
	1
**/