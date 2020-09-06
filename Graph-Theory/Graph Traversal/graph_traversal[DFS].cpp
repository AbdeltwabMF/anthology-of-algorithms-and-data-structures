#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 1e6 + 9;

int Head[N], Next[M << 1], To[M << 1], ne, n, m, u, v;
bool vis[N];

void addEdge(int from, int to)
{
	Next[++ne] = Head[from];
	Head[from] = ne;
	To[ne] = to;
}

void DFS(int node)
{
	vis[node] = true;
	
	for(int i = Head[node]; i; i = Next[i]) if(!vis[To[i]])
		DFS(To[i]);
}

int main()
{
	cin >> n >> m;
	
	while(m--)
	{
		cin >> u >> v;
		addEdge(u, v); addEdge(v, u);
	}
	
	int src = 1;
	DFS(src);
}