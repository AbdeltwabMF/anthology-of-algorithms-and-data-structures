#include <bits/stdc++.h>
#define Min(a, b)   (((a) < (b)) ? (a) : (b))
#define Max(a, b)   (((a) > (b)) ? (a) : (b))
using namespace std;
typedef int64_t  ll;
int main() {}

const int N = 1e5 + 9, M = 2e6 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], To[M], Next[M], Cost[M];
int dfs_num[N], dfs_low[N];
int Stack[N], compID[N], compSize[N];
int ne, n, m, u, v, w;
int dfs_timer, top, ID;
bool in_stack[N];

void addEdge(int from, int to, int cost = 0) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    Cost[ne] = cost;
    To[ne] = to;
}

void _clear() {
    memset(Head,     0, sizeof(Head[0])     * (n + 2));
    memset(dfs_num,  0, sizeof(dfs_num[0])  * (n + 2));
    memset(compID,   0, sizeof(compID[0])   * (n + 2));
    memset(compSize, 0, sizeof(compSize[0]) * (n + 2));
    ne = dfs_timer = top = ID = 0;
}

void Tarjan(int node)
{
    dfs_num[node] = dfs_low[node] = ++dfs_timer;
    in_stack[Stack[top++] = node] = true;

    for(int i = Head[node]; i; i = Next[i])
    {
        if(dfs_num[To[i]] == 0)
            Tarjan(To[i]);

        if(in_stack[To[i]])
            dfs_low[node] = Min(dfs_low[node], dfs_low[To[i]]);
    }

    if(dfs_num[node] == dfs_low[node])
    {
        ++ID;
        for(int cur = -1; cur ^ node;) {
            in_stack[cur = Stack[--top]] = false;
            compID[cur] = ID;
            ++compSize[ID];
        }
    }
}

void Tarjan() {
    for(int i = 1; i <= n; ++i) if(dfs_num[i] == 0)
        Tarjan(i);
}

