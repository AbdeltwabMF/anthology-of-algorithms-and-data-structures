#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 1e6 + 9;

int Head[N], Next[M], To[M], in[N], ne, n, m, u, v;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

vector <int> kahn(int n) {
    vector <int> ready, ret;

    for(int i = 1; i <= n; ++i) if(!in[i])
        ready.push_back(i);

    int tmp;
    while(!ready.empty()) {
        tmp = ready.back(); ready.pop_back();

        ret.push_back(tmp);
        for(int i = Head[tmp]; i; i = Next[i]) if(--in[To[i]] == 0)
            ready.push_back(To[i]);
    }
    return ret;
}

int main() {

    cin >> n >> m;

    while(m--) {
        cin >> u >> v;
        addEdge(u, v);
        ++in[v];
    }

    vector <int> v = kahn(n);
    if((int)v.size() == n) for(int i : v)
            cout << i << ' ';
    else
        cout << "not a DAG!" << endl;
}

