/**
   Bubble sort consists of n rounds. On each round, the algorithm iterates
   through the elements of the array. Whenever two consecutive elements are found
   that are not in correct order, the algorithm swaps them. The algorithm can be
   implemented as follows:
**/

template <class T>
void bubble_sort(T _begin, T _end, int round) {
  const int sz = _end - _begin;
  int localArray[sz];

  __typeof(_begin) k = _begin;
  for(int j = 0; k != _end; ++k, ++j)
    localArray[j] = *k;

  round = min(round, sz);
  for(int i = 0; i < round; ++i) /* n rounds -> n_th element **/
    for(int j = 0; j < sz - 1; ++j) if(localArray[j] > localArray[j + 1])
				      swap(localArray[j], localArray[j + 1]);

  k = _begin;
  for(int j = 0; k != _end; ++k, ++j)
    *k = localArray[j];
}

/**
   After the first round of the algorithm, the largest element will be in the correct
   position, and in general, after k rounds, the k largest elements will be in the
   correct positions.
**/
