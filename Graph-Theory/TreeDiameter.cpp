#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;

int Head[N], Next[N << 1], To[N << 1], ne, at, from, to, diameter, u, v, n;

void addEdge(int _from, int _to)
{
    	Next[++ne] = Head[_from];
    	Head[_from] = ne;
    	To[ne] = _to;
}

void DFS(int _node, int parent, int cost)
{
    	if(cost > diameter) diameter = cost, at = _node; 

    	for (int e = Head[_node]; e; e = Next[e]) if(To[e] != parent)
        	DFS(To[e], _node, cost + 1);              
}

int main()
{
	cin >> n;
	while(--n)
	{
       		cin >> u >> v;
       		addEdge(u, v); addEdge(v, u);
	}

    	DFS(1, -1, 0);    from = at, diameter = 0; 
	DFS(from, -1, 0);   to = at;          
	
    	cout << diameter << " " << from << " " << to << endl;
}
