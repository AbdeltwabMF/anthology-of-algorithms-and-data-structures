#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 9, M = 4e6 + 9, oo = 0x3f3f3f3f;

int Head[N], Next[M], To[M], dis[N], ne, n, m, u, v, k;
queue <int> Q;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    To[ne] = to;
    Head[from] = ne;
}

void BFS() 
{
    int node;
    while(Q.size()) 
    {
        node = Q.front(); Q.pop();
        for(int i = Head[node]; i; i = Next[i]) if(dis[To[i]] == oo) {
            dis[To[i]] = dis[node] + 1;
            Q.push(To[i]);
        }
    }
}

array <int, 2> Furthest(int n) 
{
    BFS();
    array <int, 2> ret =  {0, oo};
    for(int i = 1; i <= n; ++i) if(dis[i] >= ret[0])
    {
        if(ret[0] == dis[i])
            ret[1] = min(ret[1], i);
        else
            ret = {dis[i], i};
    }
    return ret;
}

int main() 
{
    cin >> n >> m;

    while(m--) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    memset(dis, 0x3f, sizeof dis);

    cin >> k;
    int node;
    while(k--)
    {
        cin >> node;
        Q.push(node); dis[node] = 0;
    }

    array <int, 2> ans = Furthest(n);
    cout <<  ans[0] << "\n" << ans[1] << endl;
}

