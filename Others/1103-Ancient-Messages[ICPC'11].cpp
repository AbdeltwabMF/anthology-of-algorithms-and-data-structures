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
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
}

/**------------------>>  Initialization gap  <<------------------**/

int image[210][210], H, W, CCs, id = 1;
string _in, _table = "WAKJSD";
set <int> neighbours;
char IDs[40010];

map <char, string> Hex_Bin =  {{'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
							   {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
							   {'8', "1000"}, {'9', "1001"}, {'a', "1010"}, {'b', "1011"},
                               {'c', "1100"}, {'d', "1101"}, {'e', "1110"}, {'f', "1111"}};

void ___clear()
{
    CCs = 0; id = 1;
    memset(IDs, 0, sizeof(IDs));
}

bool valid_1(int r, int c)
{
    return r != -1 && c != -1 && r != H && c != W && image[r][c] == 1;
}

bool valid_0(int r, int c)
{
    if(r == -1 || r == H || c == -1 || c == W) // zero beside edges does not belong to a cycle
    {
        neighbours.insert(-1);
        return false;
    }

    if(image[r][c] == -2) return false; // visited
    if(image[r][c] != 0)
    {
        neighbours.insert(image[r][c]); // its neighbour is neither boarder nor -2 so, add it to set
        return false;
    }
    return true;
}

void FloodFill(int r, int c, int _01)
{
	if(_01 == 1)
	{
		if(!valid_1(r, c)) return;
	}
	else
	{
		if(!valid_0(r, c)) return;
	}

    image[r][c] = id;

    for(int i = 0; i < 4; ++i)
        FloodFill(r + dx[i], c + dy[i], _01);
}

void decode(int row, int st, char ch)
{
    string _s = Hex_Bin[ch];
    int idx = 0;

    for(int i = st; i < st + 4; ++i)
        image[row][i] = _s[idx++] - '0';
}

void Solve()
{
    for(int i = 0; i < H; ++i)
    {
        cin >> _in;
        for(int j = 0; j < W; ++j)
            decode(i, j * 4, _in[j]); // Converts each Hex character to its binary equivalent
    }

    W *= 4;

    for(int i = 0; i < H; ++i)
    for(int j = 0; j < W; ++j)
    {
        if(image[i][j] == 1)  // Label each hieroglyph character with a unique color
        {
            ++id; ++CCs;
            FloodFill(i, j, 1);
        }
    }

    id = -2;

    for(int i = 0; i < H; ++i)
    for(int j = 0; j < W; ++j)
        if(image[i][j] == 0)  // if this connected area belongs to one id and only, then increase that id by one
        {
            neighbours.clear();

            FloodFill(i, j, 0);

            if(sz(neighbours) > 1)
                continue;
            else
                IDs[*neighbours.begin()]++;
        }

    string ret = "";

    for(int i = 0; i < 40000; ++i)
        if(IDs[i] > 0)
            ret.push_back(_table[(int)IDs[i]]); // each id is an integer [0, 5] that denotes one of the six hieroglyph characters

    for(int i = sz(ret); i < CCs; ++i)
        ret.push_back('W'); // If the number of hieroglyph characters is less than the actual number, then the number of 'W'  = CCs - ret.size()

    sort(all(ret));
    cout << ret << endl;
}

void MultiTest()
{
    int _tc = 1;

    while(cin >> H >> W && (H || W))
    {
        cout << "Case " << _tc++ << ": ";

        Solve();
        ___clear();
    }
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast(); File(); MultiTest();
}
