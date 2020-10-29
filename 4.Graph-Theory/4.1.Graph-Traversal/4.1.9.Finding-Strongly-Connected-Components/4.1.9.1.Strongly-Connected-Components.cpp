#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl    '\n'

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

const int N = 1e3 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Next[M], To[M], dfs_num[N], dfs_low[N], ne, n, m, u, v, dfs_timer;
stack <int> stk;
bool in_stk[N];
vector< vector <int> > SCCs;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void _clear() {
    memset(Head,         0, sizeof(Head[0])         * (n + 2));
    memset(dfs_num,      0, sizeof(dfs_num[0])      * (n + 2));
    memset(in_stk,       0, sizeof(in_stk[0])       * (n + 2));
    SCCs = vector < vector <int> > ();
    dfs_timer = 0;
    ne = 0;
}

void Tarjan(int node)
{
    dfs_num[node] = dfs_low[node] = ++dfs_timer;
    stk.push(node);
    in_stk[node] = true;

    for(int i = Head[node]; i; i = Next[i])
    {
        if(dfs_num[To[i]] == 0) {
            Tarjan(To[i]);

            if(dfs_low[To[i]] < dfs_low[node])
                dfs_low[node] = dfs_low[To[i]];
        }
        else if(in_stk[To[i]])
            if(dfs_num[To[i]] < dfs_low[node])
                dfs_low[node] = dfs_num[To[i]];
    }

    if(dfs_low[node] == dfs_num[node])
    {
        SCCs.push_back(vector <int> ());

        int cur = -1;
        while(cur ^ node)
        {
            cur = stk.top(); stk.pop(); in_stk[cur] = false;
            SCCs.back().push_back(cur);
        }
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

    for(int i = 1; i <= n; ++i) if(!dfs_num[i])
        Tarjan(i);

    for(vector <int> CC : SCCs)
    {
        cout << "Component : ";

        for(int i = 0; i < CC.size(); ++i)
            cout << CC[i] << " \n"[i == CC.size() - 1];
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i) Solve();
}

