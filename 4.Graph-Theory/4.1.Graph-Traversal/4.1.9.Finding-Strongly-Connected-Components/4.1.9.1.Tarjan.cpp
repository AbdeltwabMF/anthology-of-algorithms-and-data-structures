#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'
#define Min(a, b)   (((a) < (b)) ? (a) : (b));

using namespace std;

typedef int64_t  ll;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("input.in",  "r", stdin);
    freopen("output.out", "w", stdout);
}

const int N = 1e5 + 9, M = 2e6 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], To[M], Next[M], dfs_num[N], dfs_low[N], n, m, u, v, tax;
int dfs_timer, component, top, ne;
int Stack[N];
bool in_stack[N];

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void _clear() {
    memset(Head,    0, sizeof(Head[0])    * (n + 2));
    memset(dfs_num, 0, sizeof(dfs_num[0]) * (n + 2));
    ne = dfs_timer = component = top = 0;
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
        ++component;
        for(int cur = -1; cur ^ node; in_stack[cur = Stack[--top]] = false) {}
    }
}

void Solve()
{
    cin >> n >> m;
    _clear();

    while(m--) {
        cin >> u >> v;
        addEdge(u, v);
    }

    for(int i = 1; i <= n; ++i) if(dfs_num[i] == 0)
        Tarjan(i);

    cout << component << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

