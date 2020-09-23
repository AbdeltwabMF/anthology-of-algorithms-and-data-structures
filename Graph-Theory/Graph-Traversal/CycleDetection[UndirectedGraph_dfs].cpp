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
	if(hasCycle |= visited[_node]) return;
    	visited[_node] = true;
	
    	for (int e = Head[_node]; e; e = Next[e]) if(To[e] != parent)
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

    	for (int node = 1; node <= n; ++node) if(!visited[node])
        	DFS(node, -1); 
	
	cout << (hasCycle ? "YES" : "NO") << endl;
}
