#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 1e6 + 9;

int Head[N], Next[M], To[M], ne, u, v, n, m;
bool hasCycle;
char visited[N];

void addEdge(int _from, int _to)
{
    Next[++ne] = Head[_from];
    Head[_from] = ne;
    To[ne] = _to;
}

void DFS(int _node)
{
	/** Oops, revisiting active node **/
	if(hasCycle |= visited[_node] == 1) return; 
    
	/** current node legend mode has been activated **/
	visited[_node] = 1; 
	
    for (int e = Head[_node]; e; e = Next[e]) if(visited[To[e]] != 2)
        DFS(To[e]);
		
	/** done with this node and mark it as visited **/
	visited[node] = 2; 
}

int main()
{
    cin >> n >> m;

    while(m--)
    {
        cin >> u >> v;
        addEdge(u, v);
    }

    for (int node = 1; node <= n; ++node) if(!visited[node])
        DFS(node);
	
	cout << (hasCycle ? "YES" : "NO") << endl;
}
