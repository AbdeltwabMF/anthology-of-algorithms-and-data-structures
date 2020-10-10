/** Shortest Path Faster Algorithm :
	- This algorithm runs in O(kE) where k is a number depending on the graph. 
	- The maximum k can be V (which is the same as the time complexity of Bellman Ford’s).
	- However, in practice SPFA (which uses a queue) is as fast as Dijkstra’s (which uses a priority queue).
	- SPFA can deal with negative weight edge. If the graph has no negative cycle, SPFA runs well on it. 
	- If the graph has negative cycle(s), SPFA can also detect it as there must be some vertex (those on the negative cycle) 
	that enters the queue for over V − 1 times.
**/

#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Par[N], Next[M], To[M], Cost[M], freq[N], ne, n, m, u, v, st, tr, tax;
ll dis[N];
bool in_queue[N];

void addEdge(int from, int to, int cost) {
    Next[++ne] = Head[from];
    To[ne] = to;
    Cost[ne] = cost;
    Head[from] = ne;
}

vector <int> restorePath(int dest) {
    vector <int> path;
    if(dis[dest] == INF) return path;

    for(int i = dest; ~i; i = Par[i])
        path.push_back(i);

    reverse(path.begin(), path.end());
    return path;
}

void _clear() {
    memset(Head, 0, sizeof(Head[0]) * (n + 2));
    ne = 0;
}

bool SPFA(int src)
{
    memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
    memset(Par, -1, sizeof(Par[0]) * (n + 2));
    memset(freq, 0, sizeof(freq[0]) * (n + 2));
    memset(in_queue, false, sizeof(in_queue[0]) * (n + 2));

    queue <int> Q;
    Q.push(src);
    dis[src] = 0;
    freq[src] = 1;
    in_queue[src] = true;

    int node;
    while(Q.size())
    {
        node = Q.front(); Q.pop(); in_queue[node] = false;

        for(int i = Head[node]; i; i = Next[i]) if(dis[node] + Cost[i] < dis[To[i]]) {
            dis[To[i]] = dis[node] + Cost[i];
            Par[To[i]] = node;

            if(!in_queue[To[i]])
            {
                if(++freq[To[i]] == n)
                    return true;
                Q.push(To[i]);
                in_queue[To[i]] = true;
            }
        }
    }
    return false;
}

void Solve() 
{
    _clear();

    cin >> n >> m >> st >> tr;
    while(m--) {
        cin >> u >> v >> tax;
        addEdge(u, v, tax);
        addEdge(v, u, tax);
    }

    bool hasNegativeCycle = SPFA(st);
    cout << (hasNegativeCycle ? "YES" : "NO") << endl;
}

int main() 
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

