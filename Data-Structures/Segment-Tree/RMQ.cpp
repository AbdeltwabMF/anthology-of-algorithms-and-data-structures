/** resources:
    1. https://codeforces.com/blog/entry/15729
    2. https://codeforces.com/blog/entry/15890
    3. https://codeforces.com/blog/entry/18051
    4. https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/range-minimum-query/description/
**/

template <class T, class F = function <T(const T &, const T &)> >
class SegmentTree {
  vector <T> _A;
  vector <T> ST;
  vector <T> LT;
  F func;
  int _N;

public :
  template <class iter>
  SegmentTree(iter _begin, iter _end, const F _func = [](T a, T b) {return a <= b ? a : b;}) : func(_func) {
    _N = distance(_begin, _end);
    _N = (1 << (int)ceil(log2(_N)));

    _A.assign(_N + 1,  0);
    ST.assign(_N << 1, 0);
    LT.assign(_N << 1, 0);

    __typeof(_begin) i = _begin;
    for(int j = 1; i != _end; ++i, ++j)
      _A[j] = *i;

    build(1, 1, _N);
  }

  void build(int p, int l, int r) {
    if(l == r) {
      ST[p] = _A[l];
      return;
    }

    int mid = (l + r) >> 1;

    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);

    const T & x = ST[p + p];
    const T & y = ST[p + p + 1];

    ST[p] = func(x, y);
  }

  void update_range(int ul, int ur, int delta) {
    update_range(ul, ur, delta, 1, 1, _N);
  }

  T query(int ql, int qr) {
    return query(ql, qr, 1, 1, _N);
  }

  void update_point(int inx, int delta) {
    inx += _N - 1;
    ST[inx] = delta;

    while(inx > 1) {
      inx >>= 1;

      const T & x = ST[inx + inx];
      const T & y = ST[inx + inx + 1];

      ST[inx] = func(x, y);
    }
  }

private :
  void update_range(int ul, int ur, int delta, int p, int l, int r) {
    if(r < ul || ur < l)
      return;

    if(ul <= l && r <= ur) {
      ST[p] += delta;
      LT[p] += delta;
      return;
    }

    propagate(p);

    int mid = (l + r) >> 1;

    update_range(ul, ur, delta, p + p, l, mid);
    update_range(ul, ur, delta, p + p + 1, mid + 1, r);

    const T & x = ST[p + p];
    const T & y = ST[p + p + 1];

    ST[p] = func(x, y);
  }

  T query(int ql, int qr, int p, int l, int r) {
    if(r < ql || qr < l)
      return INT_MAX;

    if(ql <= l && r <= qr)
      return ST[p];

    propagate(p);

    int mid = (l + r) >> 1;

    const T & x = query(ql, qr, p + p, l, mid);
    const T & y = query(ql, qr, p + p + 1, mid + 1, r);

    return  func(x, y);
  }

  void propagate(int p) {
    if(LT[p]) {
      ST[p + p]     += LT[p];
      ST[p + p + 1] += LT[p];
      LT[p + p]     += LT[p];
      LT[p + p + 1] += LT[p];
      LT[p] = 0;
    }
  }
};

