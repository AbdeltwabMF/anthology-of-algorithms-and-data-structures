#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;
typedef long double ld;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("input.in",   "r", stdin);
    freopen("output.out", "w", stdout);
}

const int N = 3e5 + 9, M = N << 1, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ld eps = 1e-9;

template <class T>
class Graph
{
    #define neig(G, u, e, w, v) \
    for(int e = G.Head[u], w, v; e && (v = G.To[e], true) && (w = G.Cost[e], true); e = G.Next[e])

  public :
    vector <int> Head, To, Next;
    vector <T> Cost;
    int ne;

  public:
    Graph() = default;
    Graph(int V, int E) {
        Head.assign(V + 1, 0);
        To.resize(E + 1);
        Next.resize(E + 1);
        Cost.resize(E + 1);
        ne = 0;
    }

    void addEdge(int from, int to, T cost = 0) {
        Next[++ne] = Head[from];
        To[ne] = to;
        Cost[ne] = cost;
        Head[from] = ne;
    }

    void addBiEdge(int u, int v, T cost = 0) {
        addEdge(u, v, cost);
        addEdge(v, u, cost);
    }

    void clear() {
        fill(Head.begin(), Head.end(), 0);
        ne = 0;
    }
};

int n, u, v, diameter;
int toLeaf[N];

void dfs(Graph <int> & G, int node, int par = 0) {
    neig(G, node, e, w, v) {
        if(v != par) {
            dfs(G, v, node);
            diameter = max(diameter, toLeaf[node] + 1 + toLeaf[v]);
            toLeaf[node] = max(toLeaf[node], toLeaf[v] + 1);
        }
    }
}

void Solve()
{
    cin >> n;
    Graph <int> G(n, n << 1);

    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        G.addBiEdge(u, v);
    }

    dfs(G, 1);
    cout << 3 * diameter << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

