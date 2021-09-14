template <class T, class F = function <T(const T&, const T&)> >
class SparseTable {
  int _N;
  int _LOG;
  vector <T> _A;
  vector < vector <T> > ST;
  vector <int> Log;
  F func;

public :
  SparseTable() = default;

  template <class iter>
  SparseTable(iter _begin, iter _end, const F _func = less <T>()) : func(_func) {
    _N = distance(_begin, _end);
    Log.assign(_N + 1, 0);
    for(int i = 2; i <= _N; ++i)
      Log[i] = Log[i >> 1] + 1;

    _LOG = Log[_N];

    _A.assign(_N + 1, 0);
    ST.assign(_N + 1, vector <T> (_LOG + 1, 0));

    __typeof(_begin) i = _begin;
    for(int j = 1; i != _end; ++i, ++j)
      _A[j] = *i;

    build();
  }

  void build() {
    for(int i = 1; i <= _N; ++i)
      ST[i][0] = i;

    for(int j = 1, k, d; j <= _LOG; ++j) {
      k = (1 << j);
      d = (k >> 1);

      for(int i = 1; i + k - 1 <= _N; ++i) {
	T const & x = ST[i][j - 1];
	T const & y = ST[i + d][j - 1];

	ST[i][j] = func(_A[x], _A[y]) ? x : y;
      }
    }
  }

  T query(int l, int r) {
    int d = r - l + 1;
    T const & x = ST[l][Log[d]];
    T const & y = ST[l + d - (1 << Log[d])][Log[d]];

    return func(_A[x], _A[y]) ? x : y;
  }
};

const int N = 1e5 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], To[M], Next[M], Cost[M];
int ne, n, m, u, v, w, q;

int Last[N], First[N], euler_tour[N << 1];
int  Height[N << 1];
int euler_timer;

void addEdge(int from, int to, int cost = 1) {
  Next[++ne] = Head[from];
  Head[from] = ne;
  Cost[ne] = cost;
  To[ne] = to;
}

void _clear() {
  memset(Head,  0, sizeof(Head[0])  * (n + 2));
  memset(Last,  0, sizeof(Last[0])  * (n + 2));
  memset(First, 0, sizeof(First[0]) * (n + 2));
  ne = euler_timer = 0;
}

void EulerianTour(int node, int depth = 0) {
  euler_tour[++euler_timer] = node;
  Height[euler_timer] = depth;
  First[node] = euler_timer;

  for(int i = Head[node]; i; i = Next[i])
    if(First[To[i]] == 0) {
      EulerianTour(To[i], depth + Cost[i]);

      euler_tour[++euler_timer] = node;
      Height[euler_timer] = depth;
    }

  Last[node] = euler_timer;
}

int main() {
  cin >> n >> m;
  _clear();

  while(m--) {
    cin >> u >> v;
    addEdge(u, v);
    addEdge(v, u);
  }

  EulerianTour(1);

  SparseTable <int> st(Height + 1, Height + euler_timer + 1, [&](int a, int b) { return a <= b; });

  int l, r; cin >> q;
  while(q--) {
    cin >> l >> r;

    int left = Last[l];
    int right = Last[r];
    if(left > right) swap(left, right);

    cout << euler_tour[ st.query(left, right) ] << endl;
  }
}

