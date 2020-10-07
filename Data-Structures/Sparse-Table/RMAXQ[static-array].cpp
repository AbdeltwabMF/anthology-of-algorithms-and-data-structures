#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

/**----------------->>  Quality Over Quantity  <<----------------**/

class SparseTable
{
    #define power(p)  ((1 << (p)))

    int N;
    int LOG;
    vector <int> arr;
    vector < vector <int> > spTable;

  public :
    template <class T>
    SparseTable(T _begin, T _end)
    {
        N = _end - _begin;
        LOG = log2(N);
        arr.assign(N + 1, 0);

        __typeof(_begin) i = _begin;
        for(int j = 0; i != _end; i++, ++j)
            arr[j] = *i;

        spTable.assign(N + 1, vector <int> (LOG, 0));
        build();
    }

    void build()
    {
        for(int i = 1; i <= N; ++i)
            spTable[i][0] = i;

        for(int j = 1; j <= LOG; ++j)
            for(int i = 0; i + power(j) <= N; ++i) {
                if(arr[spTable[i + power(j - 1)][j - 1]] >= arr[spTable[i][j - 1]])
                    spTable[i][j] = spTable[i + power(j - 1)][j - 1];
                else
                    spTable[i][j] = spTable[i][j - 1];
            }
    }

    int query(int l, int r) {
        int range = r - l + 1;
        int lg = log2(range);

        if(arr[spTable[l + range - power(lg)][lg]] >= arr[spTable[l][lg]])
            return spTable[l + range - power(lg)][lg];
        else
            return spTable[l][lg];
    }
};

int n, q, x, y, query;
vector <int> a;

void Solve()
{
    cin >> n >> q;
    a.resize(n);

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    SparseTable sp(a.begin(), a.end());

    while(q--) {
        cin >> x >> y;
        cout << sp.query(x, y) << endl;
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i) Solve();
}

