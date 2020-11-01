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

class SegmentTree
{
    vector <vector <int> > sTree;
    vector <int> localArr;
    int NP2, oo = 0x3f3f3f3f;

  public :
    template <class T>
    SegmentTree(T _begin, T _end)
    {
        NP2 = 1;
        int n = _end - _begin;
        while(NP2 < n) NP2 <<= 1;

        sTree.assign(NP2 << 1, vector <int> ());
        localArr.assign(NP2 + 1, 0);

        __typeof(_begin) i = _begin;
        for(int j = 1; i != _end; i++, ++j)
            localArr[j] = *i;

        build(1, 1, NP2);
    }

    void build(int p, int l, int r)
    {
        if(l == r) {
            sTree[p].push_back(localArr[l]);
            return;
        }

        build(left(p),  l,     mid(l, r));
        build(right(p), mid(l, r) + 1, r);

        merge(p);
    }

    int query(int ql, int qr, int k) {
        return query(ql, qr, k, 1, 1, NP2);
    }

  private :
    int query(int ql, int qr, int k, int p, int l, int r)
    {
        if(isOutside(ql, qr, l, r))
            return 0;

        if(isInside(ql, qr, l, r)) {
            return sTree[p].end() - upper_bound(sTree[p].begin(), sTree[p].end(), k);
        }

        return query(ql, qr, k, left(p),  l,     mid(l, r)) +
               query(ql, qr, k, right(p), mid(l, r) + 1, r);
    }

    void merge(int p)
    {
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

    inline bool isInside(int ql, int qr, int sl, int sr) {
        return (ql <= sl && sr <= qr);
    }

    inline bool isOutside(int ql, int qr, int sl, int sr) {
        return (sr < ql || qr < sl);
    }

    inline int mid (int l, int r) {
        return ((l + r) >> 1);
    }

    inline int left(int p) {
        return (p << 1);
    }

    inline int right(int p) {
        return ((p << 1) | 1);
    }
};

const int N = 1e2 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;

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
    while(q--)
    {
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

