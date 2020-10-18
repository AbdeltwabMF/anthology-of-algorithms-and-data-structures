#include <bits/stdc++.h>
using namespace std;
typedef int64_t  ll;
int main() {}

/**	Bellman-Ford Algorithm :
    - In programming contests, the slowness of Bellman Ford’s and its negative cycle detection feature
	causes it to be used only to solve the SSSP problem on small graph
	which is not guaranteed to be free from negative weight cycle.
**/

const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Par[N], Next[M], To[M], Cost[M], ne, n, m, u, v, st, tr, tax;
ll dis[N];

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

bool hasNC() {
    for(int i = 1; i <= n; ++i)
        for(int j = Head[i]; j; j = Next[j])
            if(dis[i] < INF && dis[i] + Cost[j] < dis[To[j]])
                return true;

    return false;
}

bool Bellman_Ford(int src)
{
    memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
    memset(Par,   -1, sizeof(Par[0]) * (n + 2));

    dis[src] = 0;
    bool newRelaxation = true;

    for(int i = 2; i <= n && newRelaxation; ++i)
    {
        newRelaxation = false;
        for(int i = 1; i <= n; ++i)
            for(int j = Head[i]; j; j = Next[j])
                if(dis[i] < INF && dis[i] + Cost[j] < dis[To[j]])
                {
                    dis[To[j]] = dis[i] + Cost[j];
                    Par[To[j]] = i;
                    newRelaxation = true;
                }
    }
    return hasNC();
}

