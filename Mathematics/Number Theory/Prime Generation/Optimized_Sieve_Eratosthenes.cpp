vector <int> sieve(int n)
{
    bitset <1000000009> isPrime; isPrime.set();
    vector <int> Primes;

    if(n >= 2) Primes.push_back(2);
    if(n >= 3) Primes.push_back(3);

    int _sqrt = sqrtl(n);
    for(int i = 5; i <= _sqrt; i += 6)
    {
        if(isPrime[i]) for (int j = i * i; j <= n; j += i + i) isPrime.reset(j); i += 2;
        if(isPrime[i]) for (int j = i * i; j <= n; j += i + i) isPrime.reset(j); i -= 2;
    }

    for (int i = 5; i <= n; i += 6)
    {
        if(isPrime[i]) Primes.push_back(i); i += 2;
        if(isPrime[i]) Primes.push_back(i); i -= 2;
    }
    return Primes;
}
