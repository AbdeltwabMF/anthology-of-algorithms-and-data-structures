/** https://www.codechef.com/problems/MULTQ3
 **/

class SegmentTree
{
  vector <vector <int> > sTree;
  vector <int> lazyTree;
  vector <int> localArr;
  int NP2, oo = 0x3f3f3f3f;

public :
  template <class T>
  SegmentTree(T _begin, T _end)
  {
    NP2 = 1;
    int n = _end - _begin;
    while(NP2 < n) NP2 <<= 1;

    sTree.assign(NP2 << 1, vector <int> (3, 0));
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
      sTree[p][localArr[l] % 3]++;
      return;
    }

    build(left(p),  l,     mid(l, r));
    build(right(p), mid(l, r) + 1, r);

    for(int i = 0; i < 3; ++i)
      sTree[p][i] = sTree[left(p)][i] + sTree[right(p)][i];
  }

  void update_point(int inx, int val)
  {
    inx += NP2 - 1;
    sTree[inx] = {0, 0, 0};
    sTree[inx][val % 3]++;

    while(inx > 1) {
      inx >>= 1;
      for(int i = 0; i < 3; ++i)
	sTree[inx][i] = sTree[left(inx)][i] + sTree[right(inx)][i];
    }
  }

  int query(int ql, int qr) {
    return query(ql, qr, 1, 1, NP2);
  }

  void update_range(int ul, int ur) {
    update_range(ul, ur, 1, 1, NP2);
  }

private :
  void update_range(int ul, int ur, int p, int l, int r)
  {
    if(isOutside(ul, ur, l, r))
      return;

    if(isInside(ul, ur, l, r)) {
      swap(sTree[p][0], sTree[p][2]);
      swap(sTree[p][1], sTree[p][2]);
      ++lazyTree[p];
      return;
    }

    propagate(p, l, r);

    update_range(ul, ur,  left(p),     l, mid(l, r));
    update_range(ul, ur, right(p), mid(l, r) + 1, r);

    for(int i = 0; i < 3; ++i)
      sTree[p][i] = sTree[left(p)][i] + sTree[right(p)][i];
  }

  int query(int ql, int qr, int p, int l, int r)
  {
    if(isOutside(ql, qr, l, r))
      return 0;

    if(isInside(ql, qr, l, r))
      return sTree[p][0];

    propagate(p, l, r);

    return query(ql, qr, left(p),      l, mid(l, r)) +
      query(ql, qr, right(p), mid(l, r) + 1, r);
  }

  void propagate(int p, int l, int r)
  {
    if(lazyTree[p]) {
      for(int i = 0, add = (lazyTree[p] % 3); i < add; ++i) {
	swap(sTree[left(p)][0], sTree[left(p)][2]);
	swap(sTree[left(p)][1], sTree[left(p)][2]);
	swap(sTree[right(p)][0], sTree[right(p)][2]);
	swap(sTree[right(p)][1], sTree[right(p)][2]);
      }
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
