/** https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/help-ashu-1/description/
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
ll INF = 0x3f3f3f3f3f3f3f3f;

class SegmentTree
{
    #define mid(l, r)  (l + ((r - l) >> 1))
    #define left(p)    ((p << 1))
    #define right(p)   ((p << 1) | 1)

    vector <pair <int, int> > sTree;
    vector <int> localArr;
    int N, oo = 0x3f3f3f3f;

  public :
    template <class T>
    SegmentTree(T _begin, T _end)
    {
        N = 1;
        int n = _end - _begin;
        while(N < n) N <<= 1;

        sTree.assign(N << 1, {0, 0});
        localArr.assign(N + 1, 0);

        __typeof(_begin) i = _begin;
        for(int j = 1; i != _end; i++, ++j)
            localArr[j] = *i;

        build(1, 1, N);
    }

    void build(int p, int l, int r)
    {
        if(l == r) {
            if(localArr[l] & 1)
                sTree[p] = {1, 0};
            else
                sTree[p] = {0, 1};
            return;
        }

        build(left(p), l, mid(l, r));
        build(right(p), mid(l, r) + 1, r);

        sTree[p] = {sTree[left(p)].first + sTree[right(p)].first,
                    sTree[left(p)].second + sTree[right(p)].second};
    }

    void update_point(int inx, int val)
    {
        inx += N - 1;
        if(val & 1) {
            if(sTree[inx].second)
                sTree[inx] = {1, 0};
        } else {
            if(sTree[inx].first)
                sTree[inx] = {0, 1};
        }

        while(inx > 1) {
            inx >>= 1;
            sTree[inx] = {sTree[left(inx)].first + sTree[right(inx)].first,
                          sTree[left(inx)].second + sTree[right(inx)].second};
        }
    }

    int query(int ql, int qr, int type) {
        return query(ql, qr, 1, 1, N, type);
    }

  private :
    int query(int ql, int qr, int p, int l, int r, int type)
    {
        if(ql > r || qr < l) return 0;

        if(ql <= l && qr >= r) {
            if(type == 1)
                return sTree[p].second;
            else
                return sTree[p].first;
        }

        return query(ql, qr, left(p), l, mid(l, r), type) +
               query(ql, qr, right(p), mid(l, r) + 1, r, type);
    }
};

int n, q, l, r, type, x, y;
vector <int> a;

void Solve()
{
    cin >> n;

    a.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    SegmentTree st(a.begin(), a.end());

    cin >> q;
    while(q--)
    {
        cin >> type >> x >> y;

        if(type == 0)
            st.update_point(x, y);
        else if(type == 1)
            cout << st.query(x, y, 1) << endl;
        else
            cout << st.query(x, y, 2) << endl;
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

