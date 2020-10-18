#include <bits/stdc++.h>

#define  endl   '\n'

using namespace std;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int N = 1e3 + 9;

/**----------------->>  Quality Over Quantity  <<----------------**/

int pref[N][N], order[N][N], Next[N], wife[N], husband[N], n, u;
queue <int> Q;

void engage(int man, int woman)
{
    int ex = wife[man];
    husband[woman] = man;
    wife[man] = woman;
    if(ex) Q.push(ex);
}

void _clear() {
    memset(husband, 0, (n + 2) << 2);
    memset(wife, 0, (n + 4) << 2);
    memset(Next, 0, (n + 4) << 2);
    Q = queue <int> ();
}

void Solve() {
    /** Ladies' Choice, the best possible choice for the girls. **/
    cin >> n;
    _clear();

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) cin >> pref[i][j];
        Q.push(i);
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> u, order[i][u] = j;

    int man, woman;
    while(Q.size()) {
        woman = Q.front(); Q.pop();
        man = pref[woman][++Next[woman]];

        if(!wife[man] || order[man][woman] < order[man][wife[man]])
            engage(man, woman);
        else
            Q.push(woman);
    }

    for(int i = 1; i <= n; ++i)
        cout << husband[i] << endl; /** the i-th woman's husband */
}

void MultiTest(bool Tests = 0)
{
    int tc = 1; (Tests) && (cin >> tc);
    for(int i = 1; i <= tc; ++i) {
        if(i > 1) cout << endl;
        Solve();
    }
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast(); MultiTest(1);
}

