#include <bits/stdc++.h>
using namespace std;
typedef int64_t  ll;
int main() {}

const int N = 500 + 9, M = 4e4 + 9, oo = 0x3f3f3f3f;

int Head[N], dis[N], Par[N], Next[M], To[M], ne, n, m, u, v;
ll INF = 0x3f3f3f3f3f3f3f3f;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void _clear() {
    memset(Head, 0, sizeof(Head[0]) * (n + 2));
    ne = 0;
}

/** for each node run BFS and minmize the cycle length
**/

int BFS(int src)
{
    memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
    memset(Par,   -1, sizeof(Par[0]) * (n + 2));

    queue <int> Q;
    Q.push(src);
    dis[src] = 0;

    int node, ret = oo;
    while(Q.size())
    {
        node = Q.front(); Q.pop();
        for(int i = Head[node]; i; i = Next[i])
        {
            if(dis[To[i]] != oo) {
                if(Par[node] != To[i]) {
                    if(dis[node] + 1 + dis[To[i]] < ret)
                        ret = dis[node] + 1 + dis[To[i]];
                }
                continue;
            }

            dis[To[i]] = dis[node] + 1;
            Par[To[i]] = node;
            Q.push(To[i]);
        }
    }
    return ret;
}

