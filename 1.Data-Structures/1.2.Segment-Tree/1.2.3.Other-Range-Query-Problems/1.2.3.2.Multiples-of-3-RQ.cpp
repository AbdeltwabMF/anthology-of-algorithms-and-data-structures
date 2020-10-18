/** https://www.codechef.com/problems/MULTQ3
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
    vector <int> lazyTree;
    vector <int> localArr;
    int N, oo = 0x3f3f3f3f;

  public :
    template <class T>
    SegmentTree(T _begin, T _end)
    {
        N = 1;
        int n = _end - _begin;
        while(N < n) N <<= 1;

        sTree.assign(N << 1, vector <int> (3, 0));
        lazyTree.assign(N << 1, 0);
        localArr.assign(N + 1, 0);

        __typeof(_begin) i = _begin;
        for(int j = 1; i != _end; i++, ++j)
            localArr[j] = *i;

        build(1, 1, N);
    }

    void build(int p, int l, int r)
    {
        if(l == r) {
            sTree[p][localArr[l] % 3]++;
            return;
        }

        build(left(p), l, mid(l, r));
        build(right(p), mid(l, r) + 1, r);

        for(int i = 0; i < 3; ++i)
            sTree[p][i] = sTree[left(p)][i] + sTree[right(p)][i];
    }

    void update_point(int inx, int val)
    {
        inx += N - 1;
        sTree[inx] = {0, 0, 0};
        sTree[inx][val % 3]++;

        while(inx > 1) {
            inx >>= 1;
            for(int i = 0; i < 3; ++i)
                sTree[inx][i] = sTree[left(inx)][i] + sTree[right(inx)][i];
        }
    }

    int query(int ql, int qr) {
        return query(ql, qr, 1, 1, N);
    }

    void update_range(int ul, int ur) {
        update_range(ul, ur, 1, 1, N);
    }

  private :
    void propagate(int p, int l, int r)
    {
        if(lazyTree[p] != 0)
        {
            for(int i = 0, add = (lazyTree[p] % 3); i < add; ++i)
            {
                swap(sTree[left(p)][0], sTree[left(p)][2]);
                swap(sTree[left(p)][1], sTree[left(p)][2]);
                swap(sTree[right(p)][0], sTree[right(p)][2]);
                swap(sTree[right(p)][1], sTree[right(p)][2]);
            }
            if(l != r) {
                lazyTree[left(p)] += lazyTree[p];
                lazyTree[right(p)] += lazyTree[p];
            }
            lazyTree[p] = 0;
        }
    }

    void update_range(int ul, int ur, int p, int l, int r)
    {
        if(ul > r || ur < l)
            return;

        if(ul <= l && r <= ur) {
            swap(sTree[p][0], sTree[p][2]);
            swap(sTree[p][1], sTree[p][2]);
            ++lazyTree[p];
            return;
        }

        propagate(p, l, r);

        update_range(ul, ur, left(p), l, mid(l, r));
        update_range(ul, ur, right(p), mid(l, r) + 1, r);

        for(int i = 0; i < 3; ++i)
            sTree[p][i] = sTree[left(p)][i] + sTree[right(p)][i];
    }

    int query(int ql, int qr, int p, int l, int r)
    {
        if(ql > r || qr < l)
            return 0;

        if(ql <= l && r <= qr)
            return sTree[p][0];

        propagate(p, l, r);

        return query(ql, qr, left(p), l, mid(l, r)) +
               query(ql, qr, right(p), mid(l, r) + 1, r);
    }
};

int n, q, l, r, type, x, y;
vector <int> a;

void Solve()
{
    cin >> n >> q;

    a.resize(n, 0);
    SegmentTree st(a.begin(), a.end());

    while(q--)
    {
        cin >> type >> x >> y;

        if(type == 0)
            st.update_range(x + 1, y + 1);
        else
            cout << st.query(x + 1, y + 1) << endl;
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

