#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;

int Head[N], Next[N << 1], To[N << 1], ne, u, v, n, minBlackNds;

void addEdge(int _from, int _to)
{
    Next[++ne] = Head[_from];
    Head[_from] = ne;
    To[ne] = _to;
}

bool DFS(int _node, int parent)
{
	bool black = false;
    for (int e = Head[_node]; e; e = Next[e]) if(To[e] != parent)
        black |= DFS(To[e], _node);
	
	minBlackNds += black;
	return !black;
}

int main()
{
	cin >> n;

    while(--n)
    {
		cin >> u >> v;
		addEdge(u, v); addEdge(v, u);
    }
	
	DFS(1, -1);
	cout << minBlackNds << endl;
}
