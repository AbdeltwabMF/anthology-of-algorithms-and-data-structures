/** Constraints :
	1 ⩽ n ⩽ CR
	Where CR stands for your computing resources. In my case,
	CR ≈ 100,000,000
	----------------
	The algorithm is constructed around the ideas that a Pisano sequence always starts with 0 and 1, and that this sequence of Fibonacci 		numbers taken modulo n can be constructed for each number by adding the previous remainders and taking into account the modulo n.
	----------------

	definition:
	The sequence of Fibonacci numbers {F_n} is periodic modulo any modulus m (Wall 1960), and the period (mod m)
	is the known as the Pisano period pi(m) (Wrench 1969). For m=1, 2, ..., the values of pi(m) are
	1, 3, 8, 6, 20, 24, 16, 12, 24, 60, 10, ... (OEIS A001175).

	Since pi(10)=60, the last digit of F_n repeats with period 60, as first noted by Lagrange in 1774 (Livio 2002, p. 105).
	The last two digits repeat with a period of 300, and the last three with a period of 1500.
	In 1963, Geller found that the last four digits have a period of 15000 and the last five a period of 150000.
	Jarden subsequently showed that for d>=3, the last d digits have a period of 15·10^(d-1) (Livio 2002, pp. 105-106).
	The sequence of Pisano periods for n=1, 10, 100, 1000, ... are therefore 60, 300, 1500, 15000, 150000, 1500000, ... (OEIS A096363).
	pi(m) is even if m>2 (Wall 1960). pi(m)=m iff m=24·5^(k-1) for some integer k>1 (Fulton and Morris 1969, Wrench 1969).

	resources :
	1. https://webbox.lafayette.edu/~reiterc/nt/qr_fib_ec_preprint.pdf
	2. https://www.youtube.com/watch?v=Nu-lW-Ifyec&ab_channel=Numberphile
	3. https://www.youtube.com/watch?v=o1eLKODSCqw&list=WL&index=3&ab_channel=JacobYatsko
	4. http://webspace.ship.edu/msrenault/fibonacci/fib.htm
	5. https://www.theoremoftheday.org/Binomial/PeriodicFib/TotDPeriodic.pdf
	6. https://www.hackerearth.com/problem/algorithm/mozart-numbers/editorial/
	7. http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibmaths.html#fibmod
	8. http://webspace.ship.edu/msrenault/fibonacci/FibThesis.pdf
	9. https://www.fq.math.ca/Scanned/1-2/vinson.pdf
**/

#pragma  GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define  endl    '\n'

using namespace std;

typedef long long ll;

void Fast()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

/**----------------->>  Quality Over Quantity  <<----------------**/

int n;

vector <int> pisano_periodic_sequence(int n)
{
    vector <int> period;

    int current = 0, next = 1;
    period.push_back(current);

    if (n < 2) return period;
    current = (next += current) - current;

    while (current != 0 || next != 1)
    {
        period.push_back(current);
        current = current + next >= n ? (next += current - n) + (n - current) : (next += current) - current;
    }
    return period;
}

void Solve()
{
    cin >> n;
    cout << pisano_periodic_sequence(n).size() << endl;
}

void MultiTest(bool Tests = 0)
{
    int tc = 1; (Tests) && (cin >> tc);
    for(int i = 1; i <= tc; ++i)
        Solve();
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast(); MultiTest();
}

