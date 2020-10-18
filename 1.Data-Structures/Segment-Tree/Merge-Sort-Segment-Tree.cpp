/** https://www.spoj.com/problems/KQUERY/
**/
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

const int N = 1e2 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;

class SegmentTree
{
    #define mid(l, r)  (l + ((r - l) >> 1))
    #define left(p)    ((p << 1))
    #define right(p)   ((p << 1) | 1)

    vector <vector <int> > sTree;
    vector <int> localArr;
    int N, oo = 0x3f3f3f3f;

  public :
    template <class T>
    SegmentTree(T _begin, T _end)
    {
        N = 1;
        int n = _end - _begin;
        while(N < n) N <<= 1;

        sTree.assign(N << 1, vector <int> ());
        localArr.assign(N + 1, 0);

        __typeof(_begin) i = _begin;
        for(int j = 1; i != _end; i++, ++j)
            localArr[j] = *i;

        build(1, 1, N);
    }

    void build(int p, int l, int r)
    {
        if(l == r) {
            sTree[p].push_back(localArr[l]);
            return;
        }

        build(left(p), l, mid(l, r));
        build(right(p), mid(l, r) + 1, r);

        auto & lf = sTree[left(p)];
        auto & ri = sTree[right(p)];
        int i, j, k, lSize = lf.size(), rSize = ri.size();
        sTree[p].resize(lSize + rSize);

        for(i = 0, j = 0, k = 0; i < lSize && j < rSize;) {
            if(lf[i] <= ri[j])
                sTree[p][k++] = lf[i++];
            else
                sTree[p][k++] = ri[j++];
        }

        for(; i < lSize; ++i)
            sTree[p][k++] = lf[i];

        for(; j < rSize; ++j)
            sTree[p][k++] = ri[j];
    }

    int query(int ql, int qr, int val) {
        return query(ql, qr, val, 1, 1, N);
    }

  private :
    int query(int ql, int qr, int val, int p, int l, int r)
    {
        if(ql > r || qr < l)
            return 0;

        if(ql <= l && r <= qr) {
            return sTree[p].end() - upper_bound(sTree[p].begin(), sTree[p].end(), val);
        }

        return query(ql, qr, val, left(p), l, mid(l, r)) +
               query(ql, qr, val, right(p), mid(l, r) + 1, r);
    }
};

int n, q, l, r, k, x, y;
vector <int> a;

void Solve()
{
    cin >> n;

    a.resize(n, 0);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    SegmentTree st(a.begin(), a.end());

    cin >> q;
    while(q--) {
        cin >> x >> y >> k;
        cout << st.query(x, y, k) << endl;
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

