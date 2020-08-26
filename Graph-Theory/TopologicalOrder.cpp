#include <bits/stdc++.h>

using namespace std;

const int N = 10000 + 9, M = 100000 + 9;

int Head[N], Next[M], To[M], ne, n, m, u, v;
bool vis[N];

void _clear()
{
	memset(Head, -1, sizeof Head);
	ne = 0;
}

vector <int> ready;
queue <int> topoList_in;
stack <int> topoList_dfs;

void DFS(int node)
{
    vis[node] = true;
	
    for(int i = Head[node]; ~i; i = Next[i]) if(!vis[To[i]])
        DFS(To[i]);

    topoList_dfs.push(node);
}

void addEdge(int _from, int _to)
{
    Next[ne] = Head[_from];
    Head[_from] = ne;
    To[ne++] = _to;
}

int main()
{
    cin >> n >> m;
    _clear();

    while(m--)
    {
        cin >> u >> v;
        addEdge(u, v);
		++in[v];
    }

    /** Topological Order usig DFS **/
	for(int i = 0; i < n; ++i) if(!vis[i])
        DFS(i);

    while(!topoList_dfs.empty())
        cout << topoList_dfs.top() << ' ', topoList_dfs.pop();
	
	/**----------------------------------------------------**/
	
	/** Topological Order usig inDegree method **/
	for(int i = 0; i < n; ++i) if(!in[i])
        ready.push_back(i);
	
    while(!ready.empty())
    {
        int tmp = ready.back(); ready.pop_back();
        
		topoList_in.push(tmp);

        for(int i = Head[tmp]; ~i; i = Next[i])
        {
            if(--in[To[i]] == 0) ready.push_back(To[i]);
        }
    }

    while(!topoList_in.empty())
        cout << topoList_in.front() << ' ', topoList_in.pop();
}
