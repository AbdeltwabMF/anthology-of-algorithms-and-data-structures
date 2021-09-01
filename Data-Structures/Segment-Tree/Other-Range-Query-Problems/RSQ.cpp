/**	https://www.spoj.com/problems/HORRIBLE/
 **/

class SegmentTree
{
  vector <ll> sTree;
  vector <ll> lazyTree;
  vector <int> localArr;
  int NP2, oo = 0x3f3f3f3f;
  ll INF = 0x3f3f3f3f3f3f3f3f;

public :
  template <class T>
  SegmentTree(T _begin, T _end)
  {
    NP2 = 1;
    int n = _end - _begin;
    while(NP2 < n) NP2 <<= 1;

    sTree.assign(NP2 << 1, 0);
    lazyTree.assign(NP2 << 1, 0);
    localArr.assign(NP2 + 1, 0);

    __typeof(_begin) i = _begin;
    for(int j = 1; i != _end; i++, ++j)
      localArr[j] = *i;

    build(1, 1, NP2);
  }

  void build(int p, int l, int r)
  {
    if(l == r) {
      sTree[p] = localArr[l];
      return;
    }

    build(left(p),  l,     mid(l, r));
    build(right(p), mid(l, r) + 1, r);

    sTree[p] = sTree[left(p)] + sTree[right(p)];
  }

  void update_point(int inx, int delta)
  {
    inx += NP2 - 1;
    sTree[inx] += delta;

    while(inx > 1) {
      inx >>= 1;
      sTree[inx] = sTree[left(inx)] + sTree[right(inx)];
    }
  }

  void update_range(int ul, int ur, int delta) {
    update_range(ul, ur, delta, 1, 1, NP2);
  }

  ll query(int ql, int qr) {
    return query(ql, qr, 1, 1, NP2);
  }

private :
  void update_range(int ul, int ur, int delta, int p, int l, int r)
  {
    if(isOutside(ul, ur, l, r))
      return;

    if(isInside(ul, ur, l, r)) {
      sTree[p] += (r - l + 1) * 1ll * delta;
      lazyTree[p] += delta;
      return;
    }

    propagate(p, l, r);

    update_range(ul, ur, delta, left(p),  l,     mid(l, r));
    update_range(ul, ur, delta, right(p), mid(l, r) + 1, r);

    sTree[p] = sTree[left(p)] + sTree[right(p)];
  }

  ll query(int ql, int qr, int p, int l, int r)
  {
    if(isOutside(ql, qr, l, r))
      return 0;

    if(isInside(ql, qr, l, r)) {
      return sTree[p];
    }

    propagate(p, l, r);

    return query(ql, qr, left(p),  l,     mid(l, r)) +
      query(ql, qr, right(p), mid(l, r) + 1, r);
  }

  void propagate(int p, int l, int r)
  {
    if(lazyTree[p]) {
      sTree[left(p)]  += (mid(l, r) - l + 1) * 1ll * lazyTree[p];
      sTree[right(p)] += (r - mid(l, r)) * 1ll * lazyTree[p];

      if(l != r) {
	lazyTree[left(p)]  += lazyTree[p];
	lazyTree[right(p)] += lazyTree[p];
      }
      lazyTree[p] = 0;
    }
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
