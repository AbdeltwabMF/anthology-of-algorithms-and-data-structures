#define  rforeach(_it, c)    for(__typeof((c).rbegin()) _it = (c).rbegin(); _it != (c).rend(); ++_it)
#define  foreach(_it, c)     for(__typeof((c).begin()) _it = (c).begin(); _it != (c).end(); ++_it)
#define  all(a)              (a).begin(), (a).end()
#define  sz(a)               (int)a.size()
#define  endl                '\n'

typedef int64_t  ll;

#if __cplusplus >= 201402L

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T> T rnd_in_rng(T a, T b)
{ return uniform_int_distribution <ll> (a, b)(rng); /** [a, b] **/}

template <typename F, typename S>
ostream & operator << (ostream & os, const pair <F, S> & p)
{ return os << "(" << p.first << ", " << p.second << ")"; }

template <typename F, typename S>
ostream & operator << (ostream & os, const map <F, S> & _mp)
{ os << "["; foreach(it, _mp) { if(it != _mp.begin()) os << ", "; os << it->first << " = " << it->second; } return os << "]"; }

template <typename T>
ostream & operator << (ostream & os, const vector <T> & _v)
{ os << "["; foreach(it, _v) { if(it != _v.begin()) os << ", "; os << *it; } return os << "]"; }

template <typename T>
ostream & operator << (ostream & os, const set <T> & _st)
{ os << "["; foreach(it, _st) { if(it != _st.begin() ) os << ", "; os << *it; } return os << "]"; }

template <typename T, size_t S>
ostream & operator << (ostream & os, const array <T, S> & _ar)
{ os << "["; foreach(it, _ar) { if(it != _ar.begin() ) os << ", "; os << *it; } return os << "]"; }

template <typename T> void write(T _begin, T _end)
{ for(auto i = _begin; i != _end; ++i) cout << (*i) << ' '; cout << endl; }

template <typename T> void read(T _begin, T _end)
{ for(auto i = _begin; i != _end; ++i) cin >> (*i); }

#endif

clock_t start_time;
string run_time()
{ return to_string((clock() - (double)start_time) / CLOCKS_PER_SEC) + " sec"; }

#ifndef ONLINE_JUDGE
#include <sys/resource.h>
void resize_stack()
{
  rlimit rlim;
  getrlimit(RLIMIT_STACK, &rlim);
  rlim.rlim_cur = (1 << 28);
  setrlimit(RLIMIT_STACK, &rlim);
}
#else
void resize_stack() {};
#endif



