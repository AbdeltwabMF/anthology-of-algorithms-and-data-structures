template <class _T>
class SparseTable
{
    int _N;
    int _LOG;
    vector <_T> _A;
    vector < vector <_T> > ST;

  public :
    template <class T>
    SparseTable(T _begin, T _end)
    {
        _N = _end - _begin;
        _LOG = log2(_N);
        _A.assign(_N + 1, 0);

        __typeof(_begin) i = _begin;
        for(int j = 1; i != _end; i++, ++j)
            _A[j] = *i;

        ST.assign(_N + 1, vector <_T> (_LOG + 1, 0));
        build();
    }

    void build()
    {
        for(int i = 1; i <= _N; ++i)
            ST[i][0] = i;

        for(int j = 1, k, d; j <= _LOG; ++j) // the two nested loops below have overall time complexity = O(n log n)
        {
            k = (1 << j);
            d = (k >> 1);

            for(int i = 1; i + k <= _N + 1; ++i)
            {
                if(_A[ST[i + d][j - 1]] >= _A[ST[i][j - 1]])
                    ST[i][j] = ST[i + d][j - 1]; // starting subarray at index = i     with length = d
                else
                    ST[i][j] = ST[i][j - 1];     // starting subarray at index = i + d with length = d
            }
        }
    }

    int query(int l, int r) // this query is O(1)
    {
        int range = r - l + 1;
        int lg = log2(range);
        int k = (1 << lg);

        if(_A[ST[l + range - k][lg]] >= _A[ST[l][lg]])
            return ST[l + range - k][lg];
        else
            return ST[l][lg];
    }
};

