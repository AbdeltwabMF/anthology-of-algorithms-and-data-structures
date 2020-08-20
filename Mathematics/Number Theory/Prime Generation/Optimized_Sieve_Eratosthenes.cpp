const int N = 1e9 + 9; /** MAX N **/

bitset <N> isPrime;

void Precomputation_Sieve()
{
    isPrime.set();
    int _sqrt = sqrtl(N);
    
	for(int i = 5; i <= _sqrt; i += 6)
    {
        if(isPrime[i]) for (int j = i * i; j < N; j += i + i) isPrime.reset(j); i += 2;
        if(isPrime[i]) for (int j = i * i; j < N; j += i + i) isPrime.reset(j); i -= 2;
    }
}

vector <int> Primes(int n)  /** Primes up to n **/
{
	vector <int> _Primes;
	
	if(n >= 2) _Primes.push_back(2);
    if(n >= 3) _Primes.push_back(3);
	
	for (int i = 5; i <= n; i += 6)
    {
        if(isPrime[i]) _Primes.push_back(i); i += 2;
        if(isPrime[i]) _Primes.push_back(i); i -= 2;
    }
    return _Primes;
}
