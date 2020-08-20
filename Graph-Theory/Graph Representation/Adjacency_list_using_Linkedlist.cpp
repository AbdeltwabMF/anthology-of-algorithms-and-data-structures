const int N = 1e5 + 5, M = 1e6 + 6; /** N -> Number of nodes, M -> Number of edges **/

int Head[N], Next[M], To[M], From[M], ne; /** ne -> an edge index **/
bool visited[N];

void addEdge(int from, int to)
{
	Next[++ne] = Head[from];
	Head[from] = ne;
	To[ne] = to;
	From[ne] = from;
}

void dfs(int node)
{
	visited[node] = true;
	for(int i = Head[node]; i; i = Next[i]) if(!visited[To[i]])
		dfs(To[i]);
}
