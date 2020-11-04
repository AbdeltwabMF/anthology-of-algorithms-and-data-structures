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
            ST[i][0] = _A[i];

        for(int j = 1, k, d; j <= _LOG; ++j)
        {
            k = (1 << j);
            d = (k >> 1);

            for(int i = 1; i + k <= _N + 1; ++i)
                ST[i][j] = ST[i][j - 1] + ST[i + d][j - 1];
        }
    }

    ll query(int l, int r)
    {
        int d = r - l + 1;
        ll sum = 0;
        
        for(int j = _LOG, k; ~j; --j) {
            k = (1 << j);
            if(k <= d) {
                sum += SP[l][j];
                l += k;
            }
        }
        return sum;
    }
};
