#include <bits/stdc++.h>

using namespace std;

class UnionFind {
  private:
    vector <int> par;
    vector <int> siz;
    int num_sets;
    size_t sz;

  public:
    UnionFind(int n) : par(n + 5, -1), siz(n + 5, 1), num_sets(n), sz(n) {}

    int find_set(int u) {
        int leader;
        for(leader = u; ~par[leader]; leader = par[leader]);

        for(int next = par[u]; u != leader; next = par[next]) {
            par[u] = leader;
            u = next;
        }
        return leader;
    }

    bool same_set(int u, int v) {
        return find_set(u) == find_set(v);
    }

    bool union_set(int u, int v) {
        if(same_set(u, v)) return false;

        int x = find_set(u);
        int y = find_set(v);

        if(siz[x] < siz[y]) swap(x, y);

        par[y] = x;
        siz[x] += siz[y];

        --num_sets;
        return true;
    }

    int sets() {
        return num_sets;
    }

    int s_size(int u) {
        return siz[find_set(u)];
    }

    size_t size() {
        return sz;
    }

    vector < vector <int> > all_sets(int st) {
        map < int, vector <int> > tmp;
        vector < vector <int> > ret;

        for(size_t i = st; i < sz + st; ++i)
            tmp[find_set(i)].push_back(i);

        for(auto i : tmp)
            ret.push_back(i.second);
        return ret;
    }
};

int main() {

    int n, q, a, u, v;
    cin >> n >> q;

    UnionFind uf(n);

    while(q--) {
        cin >> a >> u >> v;
        if(a)
            cout << uf.same_set(u, v) << endl;
        else
            uf.union_set(u, v);
    }

    vector < vector <int> > Cs = uf.all_sets(0);

    for(int i = 0; i < (int)Cs.size(); ++i) {
        int compSize = Cs[i].size();
        for(int j = 0; j < compSize; ++j)
            cout << Cs[i][j] << " \n"[j == compSize - 1];
    }
}

