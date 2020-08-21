/** other ways to detect a cycle in undirected graph : Topological sort, Disjoint-set Union **/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 1e6 + 9;

int Head[N], Next[M], To[M], ne, u, v, n, m;
bool visited[N], hasCycle;

void addEdge(int _from, int _to)
{
    Next[++ne] = Head[_from];
    Head[_from] = ne;
    To[ne] = _to;
}

void DFS(int _node, int parent)
{
	/** if any node has been visited more than once then graph has a cycle **/
	if(hasCycle |= visited[_node]) return;
    visited[_node] = true;
	
    for (int e = Head[_node]; e; e = Next[e]) if(To[e] != parent) /** if neighbour is not parent -> dfs **/
        DFS(To[e], _node);
}

int main()
{
    cin >> n >> m;

    while(m--)
    {
        cin >> u >> v;
        addEdge(u, v); addEdge(v, u);
    }

    for (int node = 1; node <= n; ++node) if(!visited[node]) /** go to the next component it may have a cycle **/
        DFS(node, -1);
	
	cout << (hasCycle ? "YES" : "NO") << endl;
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
	8 1
** Sample Output **
	YES
**/