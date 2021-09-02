template <class T>
void selection_sort(T _begin, T _end, int round) {
  const int sz = _end - _begin;
  int localArray[sz];

  __typeof(_begin) k = _begin;
  for(int i = 0; k != _end; ++i, ++k)
    localArray[i] = *k;

  int MnInx;
  round = min(sz, round);
  for(int i = 0; i < round; ++i) {
    MnInx = i;
    for(int j = i + 1; j < sz; ++j)
      if(localArray[j] < localArray[MnInx])
	MnInx = j;
    swap(localArray[MnInx], localArray[i]);
  }

  k = _begin;
  for(int i = 0; k != _end; ++i, ++k)
    *k = localArray[i];
}
