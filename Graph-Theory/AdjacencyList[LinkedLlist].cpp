#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 1e6 + 6;

int Head[N], Next[M], To[M], ne, n, m, u, v; /** ne -> an edge index **/

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
		addEdge(u, v); addEdge(v, u); /** Undirected Graph **/
	}
	
	for(int node = 1; node <= n; ++node)
	{
		cout << "Neighbours of " << node << " : ";
		
		for(int e = Head[node]; e; e = Next[e])
			cout << To[e] << " \n"[Next[e] ? 0 : 1]; 
	}
}
