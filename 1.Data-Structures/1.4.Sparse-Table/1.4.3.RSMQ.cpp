template <class _T>
class SparseTable
{
    int _N;
    int _LOG;
    vector <_T> _A;
    vector < vector <_T> > ST;
    vector <int> Log;

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

        Log.assign(_N + 1, 0);
        for(int i = 2; i <= _N; ++i)
            Log[i] = Log[(i >> 1)] + 1;

        ST.assign(_N + 1, vector <_T> (_LOG + 1, 0));
        build();
    }

    void build()
    {
        for(int i = 1; i <= _N; ++i)
            ST[i][0] = _A[i];

        for(int j = 1, k, d; j <= _LOG; ++j)
        {
            k = (1 << j);
            d = (k >> 1);

            for(int i = 1; i + k <= _N + 1; ++i)
                ST[i][j] = ST[i][j - 1] + ST[i + d][j - 1];
        }
    }

    /** any interval can be uniquely represented as a union of intervals with lengths that are decreasing powers of two. 
    	E.g. [2, 14] = [2, 9] ∪ [10, 13] ∪ [14, 14]
    **/
    
    ll query(int l, int r)
    {
        int d = r - l + 1;
        ll sum = 0;
        for(int i = l; d; i += lastBit(d), d -= lastBit(d))
            sum += ST[i][Log[lastBit(d)]];
        return sum;
    }

    int lastBit(int a) {
        return (a & -a);
    }
};


