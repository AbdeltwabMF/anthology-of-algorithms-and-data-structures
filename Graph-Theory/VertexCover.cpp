#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;

int Head[N], Next[N << 1], To[N << 1], ne, u, v, n, minNumberOfBlack;

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
	
	minNumberOfBlack += black;
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
	
	cout << minNumberOfBlack << endl;
}


/** Sample Input **
	10
	1 2
	2 3
	3 4
	3 5
	1 6
	6 7
	6 10
	7 8
	7 9

** 	Sample output **
 	4
**/