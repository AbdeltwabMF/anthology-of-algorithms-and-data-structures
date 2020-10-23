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

const int N = 2e5 + 9, M = 1e6 + 9, oo = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int BLK = 256;

int n, q, a[N], l, r, cnt[M];
tuple <int, int, int> queries[N];
ll answers[N], current_ans;

void process(int item, int delta) {
    current_ans -= 1ll * cnt[item] * cnt[item] * item;
    cnt[item] += delta;
    current_ans += 1ll * cnt[item] * cnt[item] * item;
}

void add(int inx, int delta = 1) {
    process(a[inx], delta);
}

void remove(int inx, int delta = -1) {
    process(a[inx], delta);
}

bool MoComp(const tuple <int, int, int> & A, const tuple <int, int, int> & B) {
    int AL, AR, AIX;
    int BL, BR, BIX;

    tie(AL, AR, AIX) = A;
    tie(BL, BR, BIX) = B;

    if(AL / BLK != BL / BLK)
        return AL < BL;
    return ((AL / BLK) & 1) ? (AR < BR) : (AR > BR);
}

void Solve ()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    int l, r;
    for(int i = 0; i < q; ++i) {
        cin >> l >> r;
        queries[i] = make_tuple(l, r, i);
    }

    sort(queries, queries + q, MoComp);

    int ql, qr, ix;
    l = 1, r = 0;
    for(int i = 0; i < q; ++i)
    {
        tie(ql, qr, ix) = queries[i];

        while(l < ql) remove(l++);
        while(l > ql) add(--l);
        while(r < qr) add(++r);
        while(r > qr) remove(r--);

        answers[ix] = current_ans;
    }

    for(int i = 0; i < q; ++i)
        cout << answers[i] << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

