#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("input.in",  "r", stdin);
    freopen("output.out", "w", stdout);
}

const int N = 3e5 + 9, M = 6e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Next[M], To[M], Par[N];
int toLeaf[N], maxLength[N];
int ne, n, m, u, v, w;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void _clear() {
    memset(Head, 0, sizeof(Head[0]) * (n + 2));
    memset(Par, -1, sizeof(Par[0])  * (n + 2));
    ne = 0;
}

void dfs_toLeaf(int node, int par = -1)
{
    toLeaf[node] = 0;
    for(int i = Head[node]; i; i = Next[i]) if(To[i] != par) {
            dfs_toLeaf(To[i], node);
            if(toLeaf[To[i]] + 1 > toLeaf[node])
                toLeaf[node] = toLeaf[To[i]] + 1;
        }
}

void dfs_maxLength(int node, int par = -1)
{
    int firstMax = -1;
    int secondMax = -1;
    for(int i = Head[node]; i; i = Next[i]) if(To[i] != par) {
            dfs_maxLength(To[i], node);

            if(toLeaf[To[i]] > firstMax) {
                if(firstMax > secondMax)
                    secondMax = firstMax;
                firstMax = toLeaf[To[i]];
            } else if(toLeaf[To[i]] > secondMax)
                secondMax = toLeaf[To[i]];
        }
    maxLength[node] = firstMax + secondMax + 2;
}

void Solve()
{
    cin >> n;
    _clear();

    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs_toLeaf(1);
    dfs_maxLength(1);

    int diameter = 0;
    for(int i = 1; i <= n; ++i)
        if(maxLength[i] > diameter)
            diameter = maxLength[i];

    cout << diameter << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

