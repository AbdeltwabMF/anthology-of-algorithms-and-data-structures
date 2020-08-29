#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 1e6 + 9;

int Head[N], Next[M], To[M], in_time[N], out_time[N], ne, n, m, u, v, dfs_timer;
bool vis[N];

void addEdge(int from, int to)
{
	Next[++ne] = Head[from];
	Head[from] = ne;
	To[ne] = to;
}

void edgeClassification(int node, int par = -1)
{
	if(vis[node])
	{
		if(in_time[par] > in_time[node] && !out_time[node]) /** Ancestor **/
			cout << "Edge from " << par << " to " << node << " is a Back Edge 'Cycle' " << endl;
		if(in_time[par] < in_time[node] && out_time[node])  /** child **/
			cout << "Edge from " << par << " to " << node << " is a Forward Edge" << endl;
		if(in_time[par] > in_time[node] && out_time[node])  /** neither Ancestor nor child. cross edges only occur in directed graph **/
			cout << "Edge from " << par << " to " << node << " is a Cross Edge" << endl;

		return;
	}
	else cout << "Edge from " << par << " to " << node << " is a Tree Edge" << endl;

	in_time[node] = dfs_timer++;

	vis[node] = true;

	for(int i = Head[node]; i; i = Next[i]) if(To[i] != par)
		edgeClassification(To[i], node);

	out_time[node] = dfs_timer++;
}

int main()
{
	cin >> n >> m;

	while(m--)
	{
		cin >> u >> v;
		addEdge(u, v); addEdge(v, u);
	}

	for(int i = 1; i <= n; ++i) if(!vis[i])
		edgeClassification(i);
}
