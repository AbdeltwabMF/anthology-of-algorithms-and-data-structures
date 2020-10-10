#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 9, M = 4e5 + 9;

int Head[N], Next[M], To[M], Cost[M], dis[N], ne, n, m, u, v, w, start, target;

void addEdge(int from, int to, int cost) 
{
    Next[++ne] = Head[from];
    To[ne] = to;
    Cost[ne] = cost;
    Head[from] = ne;
}

int BFS(int src, int trg) 
{
    memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
    
    deque <int> Q;
    Q.push_front(src);
    dis[src] = 0;

    int node;
    while(Q.size()) 
    {
        node = Q.front(); Q.pop_front();
        if(node == trg) return dis[node]; // single source single destination
        
        for(int i = Head[node]; i; i = Next[i]) if(dis[node] + Cost[i] < dis[To[i]]) {
            dis[To[i]] = dis[node] + Cost[i];
            if(Cost[i]) Q.push_back(To[i]);
            else Q.push_front(To[i]);
        }
    }
    return -1;
}

int main() {

    cin >> n >> m >> start >> target;

    while(m--) {
        cin >> u >> v >> w;
        addEdge(u, v, w), addEdge(v, u, w);
    }

    cout << BFS(start, target) << endl;
}

