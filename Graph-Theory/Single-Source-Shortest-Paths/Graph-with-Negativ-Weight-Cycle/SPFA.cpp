#include <bits/stdc++.h>
using namespace std;
typedef int64_t  ll;
int main() {}

/** Shortest Path Faster Algorithm :
	- This algorithm runs in O(kE) where k is a number depending on the graph.
	- The maximum k can be V (which is the same as the time complexity of Bellman Ford’s).
	- However, in practice SPFA (which uses a queue) is as fast as Dijkstra’s (which uses a priority queue).
	- SPFA can deal with negative weight edge. If the graph has no negative cycle, SPFA runs well on it.
	- If the graph has negative cycle(s), SPFA can also detect it as there must be some vertex (those on the negative cycle)
	that enters the queue for over V − 1 times.
**/

const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;
ll mINF = 0xc0c0c0c0c0c0c0c0;

int Head[N], Par[N], Next[M], To[M], Cost[M], Cnt[N], ne, n, m, u, v, st, tax;
ll dis[N];
bool Inq[N];

void addEdge(int from, int to, int cost) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    Cost[ne] = cost;
    To[ne] = to;
}

void _clear() {
    memset(Head, 0, sizeof(Head[0]) * (n + 2));
    ne = 0;
}

void _set() {
    memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
    memset(Par,   -1, sizeof(Par[0]) * (n + 2));
    memset(Cnt,    0, sizeof(Cnt[0]) * (n + 2));
    memset(Inq,    0, sizeof(Inq[0]) * (n + 2));
}

bool SPFA(int src)
{
    _set();

    deque <int> Q;
    Q.push_front(src);

    dis[src] = 0;
    Cnt[src] = 1;
    Inq[src] = 1;

    int node;
    while(Q.size())
    {
        node = Q.front(); Q.pop_front(); Inq[node] = 0;

        for(int i = Head[node]; i; i = Next[i])
            if(dis[node] + Cost[i] < dis[To[i]])
            {
                dis[To[i]] = dis[node] + Cost[i];
                Par[To[i]] = node;

                if(!Inq[To[i]])
                {
                    if(++Cnt[To[i]] == n)
                        return true; // graph has a negative weight cycle

                    if(Q.size() && dis[To[i]] > dis[Q.front()])
                        Q.push_back(To[i]);
                    else
                        Q.push_front(To[i]);

                    Inq[To[i]] = true;
                }
            }
    }
    return false;
}

