/**         In the name of Allah, the Gracious, the Merciful.
*                 Praise be to Allah, Lord of the Worlds.
*                 **************************************
*
*      I have not failed, I have just found 1000 WAYS that won't work.
*
*        © كُودٌ قد حَوى دررًا بعينِ الحسنِ ملحوظة .. لِهذا قُلتُ تنبيهًا حقوقُ النقلِ محفوظة
*
*                   __________________________________
*                    @Author : Abd El-Twab  M. Fakhry
*                   __________________________________
*/

#pragma GCC optimize ("Ofast")

#if __cplusplus >= 201402L
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#endif
#include "bits/stdc++.h"

#define  rforeach(_it, c)    for(__typeof((c).rbegin()) _it = (c).rbegin(); _it != (c).rend(); ++_it)
#define  foreach(_it, c)     for(__typeof((c).begin()) _it = (c).begin(); _it != (c).end(); ++_it)
#define  print(_a, _l, _r)   for(int _i = (_l); _i < (_r); cout << _a[_i++] << " \n"[_i == (_r)])
#define  read(_a, _l, _r)    for(int _i = (_l); _i < (_r); cin >> _a[_i++])
#define  dbg(x)              cerr << #x << " = " << x << endl;
#define  repr(i, r, l)       for (int i = (r); i > (l); --i)
#define  rep(i, l, r)        for (int i = (l); i < (r); ++i)
#define  isPowerOfTwo(x)     ((x) && !((x) & ((x) - 1)))
#define  all(a)              (a).begin(), (a).end()
#define  get(n)              find_by_order((n))
#define  indexOf(n)          order_of_key((n))
#define  pow(a, b)           powl((a), (b))
#define  sz(a)               (int)a.size()
#define  lsb(x)              ((x) & -(x))
#define  sqrt(n)             sqrtl((n))
#define  endl                '\n'

using namespace std;
#if __cplusplus >= 201402L
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#endif

typedef unsigned long long  ull;
typedef long double         lld;
typedef __uint128_t        ulll;
typedef long long            ll;
typedef __int128            lll;

/**---------------------->>  Constants  <<-----------------------**/

const double    Pi      = 2 * acos(0.0),    Euler = 2.71828182845904523536;
const double    Epsln   = 1e-9,           GoldenR = (1 + sqrtl(5.0)) / 2;

const int       N       = (int)1e5 + 9,         M = (int)1e6 + 6;
const int       Mod     = (int)1e9 + 7,        oo = 0x3f3f3f3f;

/**---------------->>  Functions & Shortcuts  <<-----------------**/

#if __cplusplus >= 201402L
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T> T Rand(T a, T b) { return uniform_int_distribution <ll> (a, b)(rng); /** [a, b] **/}

template <class T> string to_string(T x)
{
    int sn = 1; if(x < 0) sn = -1, x *= sn; string s = "";
    do { s = "0123456789"[x % 10] + s, x /= 10; } while(x);
    return (sn == -1 ? "-" : "") + s;
}

auto str_to_int(string x)
{
    ulll ret = (x[0] == '-' ? 0 : x[0] - '0');
    for(int i = 1; i < sz(x); ++i) ret = ret * 10 + (x[i] - '0');
    return (x[0] == '-' ? -1 * (lll)ret : ret);
}

istream & operator >> (istream & in, lll & i) noexcept { string s; in >> s; i = str_to_int(s); return in; }
ostream & operator << (ostream & os, const lll i) noexcept { os << to_string(i); return os; }
istream & operator >> (istream & in, ulll & i) noexcept { string s; in >> s; i = str_to_int(s); return in; }
ostream & operator << (ostream & os, const ulll i) noexcept { os << to_string(i); return os; }

template <class T> T Unique(T v) { return v.erase(unique(all(v)), v.end()), v; }
template <class T> T ExGcd(T a, T b, T & x, T & y)
{
    if(!a) { x = 0, y = 1; return b; }
    T xx, yy, g = ExGcd(b % a, a, xx, yy);
    x = yy - b / (lll)a * xx; y = xx;
    return g;
}

/** Phi(a * b) = Phi(a) * Phi(b) where a and b Prime Factors and k their power **/
template <class T> auto Phi(T a, int k) { return (lll)pow(a, k - 1) * (a - 1); }
template <class T> T    Normal(T n) { n %= Mod; (n < 0) && (n += Mod); return n; }
template <class T> T    ModMulInv(T a) { T x, y; assert(ExGcd(a, Mod, x, y) == 1); return Normal(x); }
template <class T> T    Gcd(T a, T b) { return b ? Gcd(b, a % b) : a; }
template <class T> auto Lcm(T a, T b) { return a / (lll)Gcd(a, b) * b; }

/** Modular Calculations **/
template <class T> auto _add(T a, T b, T Mod) { return (lll)a + b >= Mod ? (lll)a + b - Mod : a + b; }
template <class T> T    _sub(T a, T b) { return a - b < 0 ? a - b + Mod : a - b; }
template <class T> T    _mul(T a, T b) { return T((lll)a * b % Mod); }
template <class T> T    _div(T a, T b) { return _mul(a, ModMulInv(b)); }
template <class T> T    ModExp(T a, T n)
{
    a %= Mod; T result = 1;
    while(n) { if(n & 1) result = _mul(result, a); a = _mul(a, a);  n >>= 1; }
    return result;
}

template <class T> using indexed_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update >;
template <class T> using min_heap = priority_queue < T, vector <T>, greater <T> >;
template <class T> using matrix = vector < vector <T> >;

template <typename F, typename S>
ostream & operator << (ostream & os, const pair <F, S> & p)
{ return os << "(" << p.first << ", " << p.second << ")"; }

template <typename F, typename S>
ostream & operator << (ostream & os, const map <F, S> & _mp)
{ os << "["; foreach(it, _mp) { if(it != _mp.begin()) os << ", "; os << it->first << " = " << it->second; } return os << "]"; }

template <typename T>
ostream & operator << (ostream & os, const vector <T> & _v)
{ os << "{"; foreach(it, _v) { if(it != _v.begin()) os << ", "; os << *it; } return os << "}"; }

template <typename T>
ostream & operator << (ostream & os, const set <T> & _st)
{ os << "["; foreach(it, _st) { if(it != _st.begin() ) os << ", "; os << *it; } return os << "]"; }

template <typename T>
ostream & operator << (ostream & os, const indexed_set <T> & _ist)
{ os << "["; foreach(it, _ist) { if(it != _ist.begin() ) os << ", "; os << "(" << _ist.indexOf(*it) << ", " << *it << ")"; } return os << "]"; }

void shandomRuffleSort(int arr [], int l, int r)
{ for (int i = l; i < r; ++i) swap(arr[i], arr[Rand(l, r - 1)]); sort(arr + l, arr + r); }
#endif

int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void Fast() { cin.sync_with_stdio(0); cin.tie(0); cout.tie(0); }
void File()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
}

/**------------------>>  Initialization gap  <<------------------**/

int Head[209], Next[409], To[409], ne, n, ans, number_of_enemies, enemy, _0, _1;
bool vis[209], color[209];

bool DFS(int node, int par = 0)
{
    if(vis[node])
        return color[par] != color[node];

    vis[node] = 1;
    color[node] = 1 ^ color[par];
    _0 += color[node];
    _1 += !color[node];

    bool isBiPartite = true;
    for(int i = Head[node]; i; i = Next[i]) if(To[i] != par)
        isBiPartite &= DFS(To[i], node);

    return isBiPartite;
}

void addEdge(int from, int to)
{
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

bool exist(int u, int v)
{
    for(int i = Head[u]; i; i = Next[i]) if(To[i] == v) return true;
    return false;
}

bool not_bad(int u, int v)
{
    return u > 0 && u <= n && v > 0 && v <= n;
}

void _clear()
{
    memset(Head, 0, sizeof Head);
    memset(color, 0, sizeof color);
    memset(vis, 0, sizeof vis);
    ne = ans = 0;
}

void Solve()
{
    cin >> n; _clear();

    for(int i = 1; i <= n; ++i)
    {
        cin >> number_of_enemies;
        while(number_of_enemies--)
        {
            cin >> enemy;
            if(!exist(i, enemy) && not_bad(i, enemy))
            {
                addEdge(i, enemy);
                addEdge(enemy, i);
            }
        }
    }

    for(int i = 1; i <= n; ++i) if(!vis[i])
    {
        _0 = _1 = 0;
        if(DFS(i))
            ans += max(_0, _1);
    }

    cout << ans << endl;
}

void MultiTest(bool Tests)
{
    int _tc = 1; (Tests) && (cin >> _tc); while(_tc--) Solve();
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast(); File(); MultiTest(1);
}
