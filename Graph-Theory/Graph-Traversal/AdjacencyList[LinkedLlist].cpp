#include <bits/stdc++.h>
using namespace std;
typedef int64_t  ll;

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

int main()
{
    cin >> n >> m;
    while(m--) {
        cin >> u >> v >> tax;
        addEdge(u, v, tax);
    }

    for(int i = 1; i <= n; ++i) {
        cout << "Neighbours of " << i << " : ";
        for(int j = Head[i]; j; j = Next[j])
            cout << To[j] << " ";
        cout << endl;
    }
}

