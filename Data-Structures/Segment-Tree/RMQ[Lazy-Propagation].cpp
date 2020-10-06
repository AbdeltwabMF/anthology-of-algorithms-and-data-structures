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

class SegmentTree
{
    #define left(p)   (p << 1)
    #define right(p)  (p << 1) | 1
    #define mid(l, r) (l + ((r - l) >> 1))

    vector <int> segTree;
    vector <int> localArr;
    vector <int> lazyTree;
    const int oo = 0x3f3f3f3f;
    int N; /** the number of elements in the array as a power of 2 **/

  public :
    template <class T>
    SegmentTree(T _begin, T _end) {
        N = 1;
        int n = _end - _begin;
        while(N < n) N <<= 1;

        segTree.assign(N << 1, 0);
        lazyTree.assign(N << 1, 0);
        localArr.assign(N + 1, 0);

        __typeof(_begin) i = _begin;
        for(int j = 1; i != _end; i++, ++j)
            localArr[j] = *i;

        build(1, N, 1);
    }

    void build(int l, int r, int p) {
        if(l == r) {
            segTree[p] = localArr[l];
            return;
        }

        build(l, mid(l, r), left(p));
        build(mid(l, r) + 1, r, right(p));

        segTree[p] = min(segTree[left(p)], segTree[right(p)]);
    }

    void update_point(int inx, int delta) {
        inx += N - 1;
        segTree[inx] = delta;

        while(inx > 1) {
            inx >>= 1;
            segTree[inx] = min(segTree[left(inx)], segTree[right(inx)]);
        }
    }

    void update_range(int ul, int ur, int delta) {
        update_range(ul, ur, delta, 1, N, 1);
    }

    int query(int ql, int qr) {
        return query(ql, qr, 1, N, 1);
    }

  private :
    void update_range(int ul, int ur, int delta, int l, int r, int p) {
        if(ul > r || ur < l) return;

        if(ul <= l && ur >= r) {
            segTree[p] += delta;
            if(l != r) {
                lazyTree[left(p)] += delta;
                lazyTree[right(p)] += delta;
            }
            return;
        }

        update_range(ul, ur, delta, l,      mid(l, r), left(p));
        update_range(ul, ur, delta, mid(l, r) + 1, r, right(p));

        segTree[p] = min(segTree[left(p)], segTree[right(p)]);
    }

    int query(int ql, int qr, int l, int r, int p) {
        if(ql > r || qr < l) return oo;

        if(lazyTree[p]) {
            segTree[p] += lazyTree[p];
            if(l != r) {
                lazyTree[left(p)] += lazyTree[p];
                lazyTree[right(p)] += lazyTree[p];
            }
            lazyTree[p] = 0;
        }

        if(ql <= l && qr >= r)
            return segTree[p];

        return min(query(ql, qr, l,      mid(l, r), left(p)),
                   query(ql, qr, mid(l, r) + 1, r, right(p)));
    }
};

int n, q, x, y;
char query;
vector <int> a;

void Solve()
{
    cin >> n >> q;

    a.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    SegmentTree st(a.begin(), a.end());

    while(q--) {
        cin >> query >> x >> y;
        if(query == 'q')
            cout << st.query(x, y) << endl;
        else
            st.update_point(x, y);
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i) Solve();
}

