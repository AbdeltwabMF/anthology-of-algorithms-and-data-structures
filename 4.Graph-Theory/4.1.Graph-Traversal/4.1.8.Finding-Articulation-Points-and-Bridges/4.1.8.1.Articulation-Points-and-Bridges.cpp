#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

using namespace std;

typedef int64_t  ll;

const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Next[M], To[M], Par[N], in_time[N], Low[N], ne, n, m, u, v, dfs_timer;
int root, rootChildren;
vector < pair <int, int> > bridges;
bool articulation[N];

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void DFS(int node)
{
    in_time[node] = Low[node] = ++dfs_timer;

    for(int i = Head[node]; i; i = Next[i])
    {
        if(in_time[To[i]] == 0)
        {
            if(node == root) rootChildren++;

            Par[To[i]] = node;
            DFS(To[i]);

            Low[node] = min(Low[node], Low[To[i]]);

            if(Low[To[i]] > in_time[node])
                bridges.push_back({node, To[i]});

            if(Low[To[i]] >= in_time[node])
                articulation[node] = true;
        }
        else if(Par[node] != To[i])
            Low[node] = min(Low[node], in_time[To[i]]);
    }
}

int main()
{
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for(int i = 1; i <= n; ++i) if(!in_time[i])
    {
        root = i;
        rootChildren = 0;

        DFS(i);

        articulation[i] = rootChildren > 1;
    }

    cout << "Cut Points : ";
    for(int i = 1; i <= n; ++i) if(articulation[i])
        cout << i << " ";

    cout << "\nBridges : ";
    for(pair <int, int> bridge : bridges)
        cout << bridge.first << " <--> " << bridge.second << endl;
}


