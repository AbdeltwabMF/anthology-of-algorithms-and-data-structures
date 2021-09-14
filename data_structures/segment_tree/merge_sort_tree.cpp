/** https://www.spoj.com/problems/KQUERY/
 **/

class SegmentTree {
  vector <vector <int> > sTree;
  vector <int> localArr;
  int NP2, oo = 0x3f3f3f3f;

public :
  template <class T>
  SegmentTree(T _begin, T _end) {
    NP2 = 1;
    int n = _end - _begin;
    while(NP2 < n) NP2 <<= 1;

    sTree.assign(NP2 << 1, vector <int> ());
    localArr.assign(NP2 + 1, 0);

    __typeof(_begin) i = _begin;
    for(int j = 1; i != _end; i++, ++j)
      localArr[j] = *i;

    build(1, 1, NP2);
  }

  void build(int p, int l, int r) {
    if(l == r) {
      sTree[p].push_back(localArr[l]);
      return;
    }

    build(left(p),  l,     mid(l, r));
    build(right(p), mid(l, r) + 1, r);

    merge(p);
  }

  int query(int ql, int qr, int k) {
    return query(ql, qr, k, 1, 1, NP2);
  }

private :
  int query(int ql, int qr, int k, int p, int l, int r) {
    if(isOutside(ql, qr, l, r))
      return 0;

    if(isInside(ql, qr, l, r)) {
      return sTree[p].end() - upper_bound(sTree[p].begin(), sTree[p].end(), k);
    }

    return query(ql, qr, k, left(p),  l,     mid(l, r)) + query(ql, qr, k, right(p), mid(l, r) + 1, r);
  }

  void merge(int p) {
    vector <int> & L = sTree[left(p)];
    vector <int> & R = sTree[right(p)];

    int l_size = L.size();
    int r_size = R.size();
    int p_size = l_size + r_size;

    L.push_back(INT_MAX);
    R.push_back(INT_MAX);

    sTree[p].resize(p_size);

    for(int k = 0, i = 0, j = 0; k < p_size; ++k)
      if(L[i] <= R[j])
	sTree[p][k] = L[i], i += (L[i] != INT_MAX);
      else
	sTree[p][k] = R[j], j += (R[j] != INT_MAX);

    L.pop_back();
    R.pop_back();
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
